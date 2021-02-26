#include "scribe.h"

#include <iostream>

#include <QString>

#include "spdlog/sinks/daily_file_sink.h"

namespace {
    namespace FileLogger {
        constexpr auto name = "daily_file_logger";
        constexpr auto path = "logs/grimoire_output";
        constexpr auto hour = 0;
        constexpr auto minute = 0;
        constexpr auto maxFiles = 7;
    }
}


Scribe* Scribe::pInstance = nullptr;

Scribe::Scribe()
{}

Scribe::~Scribe()
{
    if( pInstance ) {
        delete pInstance;
        pInstance = nullptr;
    }
}

bool Scribe::privInitialize()
{
    auto bSuccess{ true };
    try {
        this->fileLogger_ = spdlog::daily_logger_mt( FileLogger::name, FileLogger::path,
                                                    FileLogger::hour, FileLogger::minute, false, FileLogger::maxFiles );
#ifdef QT_DEBUG
        this->fileLogger_->set_level( spdlog::level::debug );
#endif
    } catch ( const spdlog::spdlog_ex& e ) {
        bSuccess = false;
        std::cerr << "Daily File Logger Initialization Error: " << e.what() << std::endl;
    }

    return bSuccess;
}

void Scribe::privWrite(  const Level level, const QString& type, const QString& msg )
{
    switch( level )
    {
        case Level::Debug:
        {
            logDebug( type, msg );
            break;
        }
        case Level::Info:
        {
            logInfo( type, msg );
            break;
        }
        case Level::Warn:
        {
            logWarn( type, msg );
            break;
        }
        case Level::Misfire:
        {
            logMisfire( type, msg );
            break;
        }
        default:
        {
            // WHY ARE WE HERE????
            assert( false );
            break;
        }
    }
}

void Scribe::logDebug( const QString& type, const QString& msg )
{
    this->fileLogger_->debug( "Type: {} -- Msg: {}", type.toStdString(), msg.toStdString() );
}

void Scribe::logInfo( const QString& type, const QString& msg )
{
    this->fileLogger_->info( "Type: {} -- Msg: {}", type.toStdString(), msg.toStdString() );
}

void Scribe::logWarn( const QString& type, const QString& msg )
{
    this->fileLogger_->warn( "Type: {} -- Msg: {}", type.toStdString(), msg.toStdString() );
}

void Scribe::logMisfire( const QString& type, const QString& msg )
{
    this->fileLogger_->error( "Type: {} -- Msg: {}", type.toStdString(), msg.toStdString() );
}
