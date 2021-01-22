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

    operator QString() const;

private:
    Status status_;
    QString type_;
    QString msg_;

    const QString statusToString() const;
};

#endif // MISFIRE_H
