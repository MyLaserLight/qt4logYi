#include "yilog.h"

#include <QTextCodec>
#include "log4qt/loggerrepository.h"
#include <QThread>

using namespace Yibotec;

YiLog::YiLog()
    : _logger(Log4Qt::Logger::rootLogger())
    , _layout(new Log4Qt::TTCCLayout())
    , _appender(new Log4Qt::DailyFileAppender)
{
    _layout->setDateFormat("yyyy-MM-dd hh:mm:ss");
    // 激活选项
    _layout->activateOptions();
    // 设置输出目的地为应用程序目录下的logFile.log
    _appender->setFile(".log");
    // 设置日志文件每天回滚
    _appender->setDatePattern("yyyy-MM");
    // 设置日志为追加方式写入输出文件
    _appender->setAppendFile(true);
    _appender->setLayout(_layout);
    // 设置编码
    _appender->setEncoding(QTextCodec::codecForName("UTF-8"));

    _appender->setImmediateFlush(true);
    // 设置阈值级别为INFO
    _appender->setThreshold(Log4Qt::Level::DEBUG_INT);
    // 激活选项
    _appender->activateOptions();
    _logger->addAppender(_appender);
    // 设置级别为DEBUG
    _logger->setLevel(Log4Qt::Level::DEBUG_INT);
}
YiLog::~YiLog()
{
    _logger->removeAllAppenders();
    _logger->loggerRepository()->shutdown();
}

YiLog * YiLog::getInstance()
{
    static YiLog instance;
    return &instance;
}
