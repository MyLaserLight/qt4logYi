#ifndef YILOG_H
#define YILOG_H

#include "log4qt/logger.h"
#include "log4qt/ttcclayout.h"
#include "log4qt/dailyfileappender.h"

#include <string>

namespace Yibotec
{

/*
 * 局部静态单例类
 *
 */
class YiLog
{
public:
    static YiLog * getInstance();

    template<class... T>
    void debug(const char *msg, T... args)
    {
        _logger->debug(msg, args...);
    }
    template<class... T>
    void error(const char *msg, T... args)
    {
        _logger->error(msg, args...);
    }
    template<class... T>
    void info(const char *msg, T... args)
    {
        _logger->info(msg, args...);
    }
    template<class... T>
    void warn(const char *msg, T... args)
    {
        _logger->warn(msg, args...);
    }

    ~YiLog();
private:
    YiLog();
    YiLog(const YiLog &);
    YiLog & operator=(const YiLog &);


private:
    Log4Qt::Logger *_logger;
    Log4Qt::TTCCLayout *_layout;
    Log4Qt::DailyFileAppender *_appender;
};

} // end of namespace Yibotec
#define prefix(msg) std::string("[").append(__FILE__).append(":")\
                    .append(__FUNCTION__).append(":")\
                    .append(std::to_string(__LINE__)).append("]")\
                    .append(msg).c_str()

#define LogWarn(msg, ...) Yibotec::YiLog::getInstance()->warn(prefix(msg), ##__VA_ARGS__)
#define LogError(msg, ...) Yibotec::YiLog::getInstance()->error(prefix(msg), ##__VA_ARGS__)
#define LogInfo(msg, ...) Yibotec::YiLog::getInstance()->info(prefix(msg), ##__VA_ARGS__)
#define LogDebug(msg, ...) Yibotec::YiLog::getInstance()->debug(prefix(msg), ##__VA_ARGS__)

#endif // YILOG_H
