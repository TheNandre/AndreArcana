#include "grimoire.h"

#include "cover.h"
#include "processexitmanager.h"
#include "scribe.h"

Grimoire::Grimoire( QPointer<QWidget> parent )
    : QMainWindow( parent ),
      frontCover_( new Cover{ this } ),
      processExitManager_( std::make_unique<ProcessExitManager>() )
{
#if BUILD_LAB
    frontCover_->setObjectName( "frontCover" );
#endif
    frontCover_->open( this, SLOT( initialize() ) );
}

void Grimoire::initialize()
{
    if( !Scribe::initialize() ) {
        processExitManager_->exit( ExitCode::ScribeInitializationFailure );
    }

    frontCover_->deleteLater();
}
