#ifndef GRIMOIRE_H
#define GRIMOIRE_H

#include <QMainWindow>
#include <QPointer>

#include "processexitmanager.h"
#include "misfiremanager.h"

class Cover;
class Misfire;

#ifdef BUILD_LAB
#include "grimoire_global.h"
class GRIMOIRE_EXPORT Grimoire : public QMainWindow
#else
class Grimoire : public QMainWindow
#endif
{
    Q_OBJECT
public:
    Grimoire();
    virtual ~Grimoire() override = default;

public slots:
    void onMisfire( const Misfire& misfire );

private:
    QPointer<Cover> frontCover_;
    std::unique_ptr<ProcessExitManager> processExitManager_;
    std::unique_ptr<MisfireManager> misfireManager_;

private slots:
    void initialize();
};

#endif // GRIMOIRE_H
