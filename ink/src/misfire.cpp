#include "misfire.h"

namespace {
    constexpr auto conversionString = "%1 -- Type: %2 -- %3";
}

Misfire::Misfire( const QString& type )
    : status_( Status::Success ), type_( type )
{}

Misfire::operator QString() const
{
    return QString{ conversionString }.arg( this->statusToString() ).arg( this->type_ ).arg( this->msg_ );
}

const QString Misfire::statusToString() const
{
    QString status;
    switch( this->status_ )
    {
        case Status::Success:
        {
            status = "SUCCESS";
            break;
        }
        case Status::Warning:
        {
            status = "WARNING";
            break;
        }
        case Status::Error:
        {
            status = "ERROR";
            break;
        }
        default:
        {
            Q_ASSERT( "Need to add case for Misfire Status case" );
            break;
        }
    }

    return status;
}
