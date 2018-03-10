#pragma once

#include "XTaskWrapper.h"
#include <mutex>

class XTaskProcessor
{
private:
    XTaskWrapper _tasks[2];
    uint64_t _taskCount = 0;
    std::string _accountAddress;
    std::string _poolUrl;
    
public:
    XTaskProcessor() {}
    XTaskProcessor(std::string accountAddress, std::string poolUrl) : _accountAddress(accountAddress), _poolUrl(poolUrl) {}
    ~XTaskProcessor();

    const std::string& getAccountAddress() { return _accountAddress; }
    const std::string& getPoolUrl() { return _poolUrl; }
    //TODO: think of better process
    XTaskWrapper* GetNextTask();
    XTaskWrapper* GetCurrentTask();
    void SwitchTask();
    uint64_t GetCount() { return _taskCount; }

    void DumpTasks();
};
