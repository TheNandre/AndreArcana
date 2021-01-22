#ifndef GRIMOIRE_H
#define GRIMOIRE_H

#include <QMainWindow>
#include <QPointer>

#include "processexitmanager.h"
#include "misfiremanager.h"

class Cover;

class Grimoire : public QMainWindow
{
    Q_OBJECT
public:
    Grimoire();
    virtual ~Grimoire() override = default;

private:
    QPointer<Cover> frontCover_;
    std::unique_ptr<ProcessExitManager> processExitManager_;
    std::unique_ptr<MisfireManager> misfireManager_;

private slots:
    void initialize();
};

#endif // GRIMOIRE_H
