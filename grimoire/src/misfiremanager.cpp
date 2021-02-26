#include "misfiremanager.h"

#include <QDir>

#include "misfire.h"

#define useDebug 1
#if useDebug
#include <QDebug>
#endif

namespace {
    constexpr auto logFolderName = "/logs/";
    const auto logFileFolderPath = QDir::currentPath() + logFolderName;
    namespace LogFile{
        constexpr auto logFileNameSuffix = "_AALogFile.txt";
        constexpr auto maxLogFiles = 5;
    }
}

MisfireManager::MisfireManager()
{
    this->createLogFileFolder();
    this->removeOldLogFiles();
}

bool MisfireManager::initialize()
{
    QDir dir{ logFileFolderPath };
    QString logFileName{};
    const auto& currentDate = QDate::currentDate().toString( Qt::DateFormat::ISODate );
    auto fileInfos = dir.entryInfoList( QDir::Filter::Files, QDir::SortFlag::Name );
    for( auto fileInfo : fileInfos ) {
        const auto& fileName = fileInfo.fileName();
        if( fileName.startsWith( currentDate ) ) {
            logFileName = fileName;
            break;
        }
    }

    if( logFileName.isEmpty() ) {
        logFileName = logFileFolderPath + currentDate + LogFile::logFileNameSuffix;
    }

    this->currentLogFile_.setFileName( logFileName );
#if useDebug
    qDebug() << "Log File Name:" << this->currentLogFile_.fileName();
#endif

    return this->currentLogFile_.open( QIODeviceBase::WriteOnly | QIODeviceBase::Append );
}

void MisfireManager::onMisfire( const Misfire& misfire )
{
    if( this->currentLogFile_.isOpen() ) {
#if useDebug
        QFileInfo fileInfo{ this->currentLogFile_ };
        qDebug() << "Current Log File Path:" << fileInfo.absoluteFilePath();
        qDebug() << "Misfire:" << misfire;
#endif
        QTextStream stream{ this->currentLogFile_ };
    }
}

void MisfireManager::createLogFileFolder()
{
#if useDebug
    qDebug() << "Log File Folder:" << logFileFolderPath;
#endif
    QDir dir{ logFileFolderPath };
    if( !dir.exists() ) {
        dir.mkpath( logFileFolderPath );
    }
}

void MisfireManager::removeOldLogFiles()
{
    QDir dir{ logFileFolderPath };
    const auto& fileInfos = dir.entryInfoList( QDir::Filter::Files, QDir::SortFlag::Name );
    const auto numberToDelete = fileInfos.size() - LogFile::maxLogFiles;
    for( auto index = 0; index < numberToDelete; ++index ) {
        const auto& fileName = fileInfos.at( index ).fileName();
        QFile file{ fileName };
        file.remove();
    }
}

