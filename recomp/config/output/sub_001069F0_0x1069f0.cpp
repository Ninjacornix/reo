#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001069F0
// Address: 0x1069f0 - 0x106a0c
void sub_001069F0_0x1069f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001069F0_0x1069f0");
#endif

    switch (ctx->pc) {
        case 0x106a00u: goto label_106a00;
        default: break;
    }

    ctx->pc = 0x1069f0u;

    // 0x1069f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1069f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1069f4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1069f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1069f8: 0xc041a2a  jal         func_1068A8
    ctx->pc = 0x1069F8u;
    SET_GPR_U32(ctx, 31, 0x106A00u);
    ctx->pc = 0x1069FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1069F8u;
            // 0x1069fc: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1068A8u;
    if (runtime->hasFunction(0x1068A8u)) {
        auto targetFn = runtime->lookupFunction(0x1068A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A00u; }
        if (ctx->pc != 0x106A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001068A8_0x1068a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106A00u; }
        if (ctx->pc != 0x106A00u) { return; }
    }
    ctx->pc = 0x106A00u;
label_106a00:
    // 0x106a00: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x106a00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106a04: 0x3e00008  jr          $ra
    ctx->pc = 0x106A04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106A04u;
            // 0x106a08: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106A00u: goto label_106a00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106A0Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
