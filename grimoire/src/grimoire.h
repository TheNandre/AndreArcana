#ifndef GRIMOIRE_H
#define GRIMOIRE_H

#include <QMainWindow>
#include <QPointer>

#include "processexitmanager.h"

class Cover;

#ifdef BUILD_LAB
#include "grimoire_global.h"
class GRIMOIRE_EXPORT Grimoire : public QMainWindow
#else
class Grimoire : public QMainWindow
#endif
{
    Q_OBJECT
public:
    Grimoire( QPointer<QWidget> parent = nullptr );
    virtual ~Grimoire() override = default;

private:
    QPointer<Cover> frontCover_;
    std::unique_ptr<ProcessExitManager> processExitManager_;

private slots:
    void initialize();
};

#endif // GRIMOIRE_H
