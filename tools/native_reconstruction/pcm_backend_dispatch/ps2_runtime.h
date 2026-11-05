#pragma once
#include <functional>
#include <memory>
#include <vector>
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
// Isolated registration/lifecycle surroundings only, not a real runtime build.
class PS2Runtime {
public:
    class ExternalWorker {public:virtual ~ExternalWorker()=default;virtual void requestStop() noexcept=0;virtual bool join() noexcept=0;};
    bool sealed{},accept=true;
    std::function<void()> registering,registered;
    std::vector<std::shared_ptr<ExternalWorker>> workers;
    bool registerExternalWorker(std::shared_ptr<ExternalWorker> worker) noexcept {
        if(!worker||sealed||!accept)return false;
        try{if(registering)registering();workers.push_back(std::move(worker));if(registered)registered();return true;}catch(...){return false;}
    }
    void stop(){sealed=true;for(const auto& worker:workers)worker->requestStop();}
    bool join(){for(const auto& worker:workers)if(!worker->join())return false;return true;}
};
