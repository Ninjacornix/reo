#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001698E0
// Address: 0x1698e0 - 0x169918
void sub_001698E0_0x1698e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001698E0_0x1698e0");
#endif

    switch (ctx->pc) {
        case 0x1698f4u: goto label_1698f4;
        default: break;
    }

    ctx->pc = 0x1698e0u;

    // 0x1698e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1698e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1698e4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1698e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1698e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1698e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1698ec: 0x40f809  jalr        $v0
    ctx->pc = 0x1698ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1698F4u);
        ctx->pc = 0x1698F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1698ECu;
            // 0x1698f0: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1698F4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1698F4u: goto label_1698f4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1698F4u; }
            if (ctx->pc != 0x1698F4u) { return; }
        }
        }
    }
    ctx->pc = 0x1698F4u;
label_1698f4:
    // 0x1698f4: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1698f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1698f8: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1698f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1698fc: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x1698fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x169900: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x169900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169904: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x169904u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x169908: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x169908u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16990c: 0x3e00008  jr          $ra
    ctx->pc = 0x16990Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16990Cu;
            // 0x169910: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1698F4u: goto label_1698f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169914u;
    // 0x169914: 0x0  nop
    ctx->pc = 0x169914u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
