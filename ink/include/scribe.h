#ifndef SCRIBE_H
#define SCRIBE_H

#include "../src/inkdll_global.h"

#include <memory>

namespace spdlog {
class logger;
}

class INK_EXPORT Scribe
{
private:
    Scribe();
    ~Scribe();

    static Scribe* pInstance;

public:
    static Scribe& instance()
    {
        if( !pInstance ) {
            pInstance = new Scribe();
        }

        return *pInstance;
    }

    enum class Level
    {
        Debug,
        Info,
        Warn,
        Misfire
    };

private:
    std::shared_ptr<spdlog::logger> fileLogger_;

    bool privInitialize();
    void privWrite( const Level level, const QString& type, const QString& msg );

    void logDebug( const QString& type, const QString& msg );
    void logInfo( const QString& type, const QString& msg );
    void logWarn( const QString& type, const QString& msg );
    void logMisfire( const QString& type, const QString& msg );

public:
    static bool initialize() { return instance().privInitialize(); }
    static void write(  const Level level, const QString& type, const QString& msg ) { instance().privWrite( level, type, msg ); }
};

using ScribeLevel = Scribe::Level;

#endif // SCRIBE_H
