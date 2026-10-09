#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013C9C0
// Address: 0x13c9c0 - 0x13c9e4
void sub_0013C9C0_0x13c9c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013C9C0_0x13c9c0");
#endif

    switch (ctx->pc) {
        case 0x13c9d0u: goto label_13c9d0;
        default: break;
    }

    ctx->pc = 0x13c9c0u;

    // 0x13c9c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13c9c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13c9c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13c9c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13c9c8: 0xc04f1fa  jal         func_13C7E8
    ctx->pc = 0x13C9C8u;
    SET_GPR_U32(ctx, 31, 0x13C9D0u);
    ctx->pc = 0x13C9CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13C9C8u;
            // 0x13c9cc: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C7E8u;
    if (runtime->hasFunction(0x13C7E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C7E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C9D0u; }
        if (ctx->pc != 0x13C9D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C7E8_0x13c7e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C9D0u; }
        if (ctx->pc != 0x13C9D0u) { return; }
    }
    ctx->pc = 0x13C9D0u;
label_13c9d0:
    // 0x13c9d0: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13c9d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13c9d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13c9d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13c9d8: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x13c9d8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x13c9dc: 0x3e00008  jr          $ra
    ctx->pc = 0x13C9DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C9E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13C9DCu;
            // 0x13c9e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C9D0u: goto label_13c9d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C9E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
