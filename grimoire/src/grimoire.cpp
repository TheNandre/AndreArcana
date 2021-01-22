#include "grimoire.h"

#include "cover.h"
#include "processexitmanager.h"
#include "misfiremanager.h"

Grimoire::Grimoire()
    : frontCover_( new Cover{ this } ),
      processExitManager_( std::make_unique<ProcessExitManager>() ),
      misfireManager_( std::make_unique<MisfireManager>() )
{
    frontCover_->open( this, SLOT( initialize() ) );
}

void Grimoire::initialize()
{
    if( !misfireManager_->initialize() ) {
        processExitManager_->exit( ExitCode::MisfireManagerInitializationFailure );
    }

    frontCover_->deleteLater();
}
