#ifndef MISFIREMANAGER_H
#define MISFIREMANAGER_H

#include <QFile>

class Misfire;

class MisfireManager
{
public:
    MisfireManager();
    ~MisfireManager() = default;

    bool initialize();

    void onMisfire( const Misfire& misfire );

private:
    QFile currentLogFile_;

    void createLogFileFolder();
    void removeOldLogFiles();
};

#endif // MISFIREMANAGER_H
