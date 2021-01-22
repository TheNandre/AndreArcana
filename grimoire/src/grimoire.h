#ifndef GRIMOIRE_H
#define GRIMOIRE_H

#include <QMainWindow>

#include "processexitmanager.h"
#include "misfiremanager.h"

class Grimoire : public QMainWindow
{
    Q_OBJECT
public:
    Grimoire();
    virtual ~Grimoire() override = default;

private:
    std::unique_ptr<ProcessExitManager> processExitManager_;
    std::unique_ptr<MisfireManager> misfireManager_;

    void initialize();
};

#endif // GRIMOIRE_H
