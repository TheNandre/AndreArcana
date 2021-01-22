#include "grimoire.h"

#include "processexitmanager.h"
#include "misfiremanager.h"

Grimoire::Grimoire()
    : processExitManager_( std::make_unique<ProcessExitManager>() ),
      misfireManager_( std::make_unique<MisfireManager>() )
{

}

void Grimoire::initialize()
{
    if( !misfireManager_->initialize() ) {
        processExitManager_->exit( ExitCode::MisfireManagerInitializationFailure );
    }
}
