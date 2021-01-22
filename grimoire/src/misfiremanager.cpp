#include "misfiremanager.h"

#include <QDir>

#include "misfire.h"

namespace {
    constexpr auto logFolderName = "logs/";
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
        logFileName = logFolderName + currentDate + LogFile::logFileNameSuffix;
    }

    qDebug() << "Log File Name" << logFileName;

    this->currentLogFile_.setFileName( logFileName );

    return this->currentLogFile_.open( QIODeviceBase::ReadWrite | QIODeviceBase::Append );
}

void MisfireManager::onMisfire( const Misfire& misfire )
{
    if( this->currentLogFile_.isOpen() ) {
        QTextStream logText{ &this->currentLogFile_ };
        logText << misfire;
    }
}

void MisfireManager::createLogFileFolder()
{
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

