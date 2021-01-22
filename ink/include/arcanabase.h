#ifndef ARCANABASE_H
#define ARCANABASE_H

#include <QObject>

class Misfire;

class ArcanaBase : public QObject
{
    Q_OBJECT
public:
    ArcanaBase() = default;
    virtual ~ArcanaBase() = default;

signals:
    void misfire( const Misfire& m );
};

#endif
