#ifndef PROCESSEXITMANAGER_H
#define PROCESSEXITMANAGER_H


class ProcessExitManager
{
public:
    ProcessExitManager() = default;
    ~ProcessExitManager() = default;

    enum class ExitCodes
    {
        Success = 0,
        MisfireManagerInitializationFailure = 100
    };

    void exit( const ExitCodes code );
};

using ExitCode = ProcessExitManager::ExitCodes;

#endif // PROCESSEXITMANAGER_H
