#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106880
// Address: 0x106880 - 0x1068a8
void sub_00106880_0x106880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106880_0x106880");
#endif

    switch (ctx->pc) {
        case 0x10689cu: goto label_10689c;
        default: break;
    }

    ctx->pc = 0x106880u;

    // 0x106880: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x106880u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x106884: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x106884u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x106888: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x106888u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10688c: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x10688cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x106890: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x106890u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x106894: 0xc041a2a  jal         func_1068A8
    ctx->pc = 0x106894u;
    SET_GPR_U32(ctx, 31, 0x10689Cu);
    ctx->pc = 0x106898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106894u;
            // 0x106898: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1068A8u;
    if (runtime->hasFunction(0x1068A8u)) {
        auto targetFn = runtime->lookupFunction(0x1068A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10689Cu; }
        if (ctx->pc != 0x10689Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001068A8_0x1068a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10689Cu; }
        if (ctx->pc != 0x10689Cu) { return; }
    }
    ctx->pc = 0x10689Cu;
label_10689c:
    // 0x10689c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10689cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1068a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1068A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1068A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1068A0u;
            // 0x1068a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10689Cu: goto label_10689c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1068A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
