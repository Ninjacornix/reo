#pragma once
#include "parent_context_lifecycle.h"
#include <array>
#include <memory>
// Internal original helper identity: each syscall TU includes its own genuine
// static helper definition through Helpers/Runtime.h.
static bool rpcInvokeFunction(uint8_t*, R5900Context*, PS2Runtime*, uint32_t, uint32_t, uint32_t,
                              uint32_t, uint32_t, uint32_t*);
namespace reo_parent_natural {
// Controls are the exact rpcInvokeFunction helper arguments and its genuine
// guest stack allocation. This is not a captured numerical Context.
struct RpcCallbackControls {
    uint32_t entry = 0;
    std::array<uint32_t, 4> arguments{};
    uint32_t stackTop = 0, returnSentinel = 0x00fff000u;
};
class RpcCallbackInvocation final {
    friend bool ::rpcInvokeFunction(uint8_t*, R5900Context*, PS2Runtime*, uint32_t, uint32_t,
                                    uint32_t, uint32_t, uint32_t, uint32_t*);
    PS2Runtime* runtime_;
    R5900Context* caller_;
    RpcCallbackControls controls_;
    int32_t task_;
    std::thread::id thread_;
    PS2Runtime::RecompiledFunction function_;
    RpcCallbackInvocation(PS2Runtime& runtime, R5900Context& caller,
                          const RpcCallbackControls& controls)
        : runtime_(&runtime), caller_(&caller), controls_(controls),
          task_(ps2_sched::currentThread()), thread_(std::this_thread::get_id()),
          function_(runtime.lookupFunction(controls.entry)) {
        validateBeforeActualForkOnEe();
    }

  public:
    RpcCallbackInvocation(const RpcCallbackInvocation&) = delete;
    PS2Runtime& runtime() const noexcept {
        return *runtime_;
    }
    R5900Context& caller() const noexcept {
        return *caller_;
    }
    const RpcCallbackControls& controls() const noexcept {
        return controls_;
    }
    int32_t task() const noexcept {
        return task_;
    }
    void validateBeforeActualForkOnEe() const {
        if (currentRuntime() != runtime_ || currentContext() != caller_ ||
            !ps2ActualGuestExecutionDepth(runtime_) || task_ < 1 ||
            ps2_sched::currentThread() != task_ || std::this_thread::get_id() != thread_ ||
            runtime_->isStopRequested() || !controls_.entry ||
            controls_.returnSentinel != 0x00fff000u || !function_ ||
            runtime_->lookupFunction(controls_.entry) != function_)
            throw std::invalid_argument(
                "RPC invocation is not the original actual helper/task/function event");
    }
};
using RpcCallbackInvocationHandle = std::shared_ptr<const RpcCallbackInvocation>;
class CallbackFrame {
  protected:
    CallbackFrame() = default;

  public:
    virtual ~CallbackFrame() = default;
    virtual R5900Context& context() noexcept = 0;
    virtual bool ownsNumericLanes() const noexcept = 0;
    // Only a true scalar-return lease can supply v0; an opaque result is not
    // read from a host shadow. close restores the actual caller's GPU Context.
    virtual uint32_t returnedScalarV0() = 0;
    virtual void closeAfterActualCallbackReturn() = 0;
};
using CallbackFrameHandle = std::shared_ptr<CallbackFrame>;
class CallbackContextTarget {
  public:
    virtual ~CallbackContextTarget() = default;
    virtual CallbackFrameHandle forkActualRpcCallback(const RpcCallbackInvocationHandle&) = 0;
};
// Selection must remain off until source helper controls, callback lifetime,
// complete Context access and real source/graphics retirement are proved.
inline constexpr bool ActualRpcControlSourceClosureImplemented = false;
} // namespace reo_parent_natural
