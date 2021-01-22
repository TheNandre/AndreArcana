#include "misfire.h"

Misfire::Misfire( const QString& type )
    : status_( Status::Success ), type_( type )
{}

void Misfire::setStatus( const Status status, const QString& msg )
{
    this->status_ = status;
    this->msg_ = msg;
}

