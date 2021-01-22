#include "processexitmanager.h"

#include <QApplication>

void ProcessExitManager::exit( const ExitCodes code )
{
    QApplication::exit( static_cast<int>( code ) );
}
