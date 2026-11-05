#pragma once
#include <atomic>
#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <vector>
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
// Exact layout type and lease declaration are generated from the real header.
#include "exact_layout.inc"
class PS2Runtime {
public:
    class ExternalWorker {public:virtual ~ExternalWorker()=default;virtual void requestStop() noexcept=0;virtual bool join() noexcept=0;};
    using ExternalWorkerList=std::vector<std::shared_ptr<ExternalWorker>>;
    std::mutex m_externalWorkersMutex;
    std::shared_ptr<ExternalWorkerList> m_externalWorkers=std::make_shared<ExternalWorkerList>();
    bool m_externalWorkersSealed=false;
    std::condition_variable m_preRunSetupChanged;
    size_t m_preRunSetupCount=0;
    std::atomic<bool> m_stopRequested{false};
#include "exact_lease.inc"
    PreRunSetupLease acquirePreRunSetup() noexcept;
    void releasePreRunSetup() noexcept;
    bool externalWorkerResetAllowed();
    void beginExternalWorkerRun();
    // Registration/stop surroundings and race injection only. These are not
    // offered as an exact full-runtime implementation or a guest lifetime proof.
    bool& sealed=m_externalWorkersSealed;
    bool accept=true;
    std::function<void()> registering,registered;
    ExternalWorkerList& workers=*m_externalWorkers;
    bool registerExternalWorker(std::shared_ptr<ExternalWorker> worker) noexcept {
        if(!worker||!accept)return false;
        try {
            if(registering)registering();
            {std::lock_guard lock(m_externalWorkersMutex);if(m_externalWorkersSealed||m_stopRequested)return false;m_externalWorkers->push_back(std::move(worker));}
            if(registered)registered();
            return true;
        }catch(...){return false;}
    }
    void stop(){
        std::shared_ptr<ExternalWorkerList> snapshot;
        {std::lock_guard lock(m_externalWorkersMutex);if(m_stopRequested.exchange(true))return;m_externalWorkersSealed=true;snapshot=m_externalWorkers;}
        for(const auto& worker:*snapshot)worker->requestStop();
    }
    bool join(){for(const auto& worker:*m_externalWorkers)if(!worker->join())return false;return true;}
};
#include "exact_runtime_methods.inc"
