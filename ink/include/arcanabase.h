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
