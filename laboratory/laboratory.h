#ifndef LABORATORY_H
#define LABORATORY_H

#include <QObject>
#include <QPointer>

class Grimoire;

class Laboratory : public QObject
{
    Q_OBJECT
public:
    Laboratory();

private slots:
    void initTestCase();
    void coverTest();
    void misfireTest();
    void cleanupTestCase();

private:
    QPointer<Grimoire> grimoire_;
};

#endif // LABORATORY_H
