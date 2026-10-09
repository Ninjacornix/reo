#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3E54
// Address: 0x1f3e54 - 0x1f3e90
void sub_001F3E54_0x1f3e54(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3E54_0x1f3e54");
#endif

    switch (ctx->pc) {
        case 0x1f3e74u: goto label_1f3e74;
        default: break;
    }

    ctx->pc = 0x1f3e54u;

    // 0x1f3e54: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f3e54u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f3e58: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f3e58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f3e5c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f3e5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f3e60: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3e60u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3e64: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f3e64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f3e68: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3e68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3e6c: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1F3E6Cu;
    SET_GPR_U32(ctx, 31, 0x1F3E74u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3E74u; }
        if (ctx->pc != 0x1F3E74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3E74u; }
        if (ctx->pc != 0x1F3E74u) { return; }
    }
    ctx->pc = 0x1F3E74u;
label_1f3e74:
    // 0x1f3e74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3e74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3e78: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3e78u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3e7c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f3e7cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3e80: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f3e80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f3e84: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f3e84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f3e88: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3E88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3E74u: goto label_1f3e74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3E90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
