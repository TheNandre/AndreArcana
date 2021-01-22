#ifndef MISFIRE_H
#define MISFIRE_H

#include <QString>

class Misfire
{
public:
    Misfire() = delete;
    Misfire( const QString& type );
    ~Misfire() = default;

    enum class Status
    {
        Success,
        Warning,
        Error
    };

    inline Status status() const { return this->status_; }
    inline const QString& type() const { return this->type_; }
    inline const QString& msg() const { return this->msg_; }

    void setStatus( const Status status, const QString& msg = QString{} );

private:
    Status status_;
    QString type_;
    QString msg_;
};

#endif // MISFIRE_H
