#pragma once
#include <memory>
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
// Refusing registration surroundings only. The legacy source oracle never
// installs a backend, runs a runtime or enters its setup-reset path.
class PS2Runtime {
public:
    class ExternalWorker {
    public:
        virtual ~ExternalWorker() = default;
        virtual void requestStop() noexcept = 0;
        virtual bool join() noexcept = 0;
    };
    struct PreRunSetupLease { explicit operator bool() const noexcept { return false; } };
    PreRunSetupLease acquirePreRunSetup() noexcept { return {}; }
    bool registerExternalWorker(std::shared_ptr<ExternalWorker>) noexcept { return false; }
};
