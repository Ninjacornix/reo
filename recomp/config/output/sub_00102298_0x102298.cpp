#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102298
// Address: 0x102298 - 0x1022c8
void sub_00102298_0x102298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102298_0x102298");
#endif

    ctx->pc = 0x102298u;

    // 0x102298: 0x4843e800  cfc2.ni     $v1, $vi29
    ctx->pc = 0x102298u;
    SET_GPR_U32(ctx, 3, ctx->vu0_top);
    // 0x10229c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x10229cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1022a0: 0x3062000f  andi        $v0, $v1, 0xF
    ctx->pc = 0x1022a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x1022a4: 0x14440003  bne         $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1022A4u;
    {
        const bool branch_taken_0x1022a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1022A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1022A4u;
            // 0x1022a8: 0x30630f00  andi        $v1, $v1, 0xF00 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3840);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1022a4) {
            ctx->pc = 0x1022B4u;
            goto label_1022b4;
        }
    }
    ctx->pc = 0x1022ACu;
    // 0x1022ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1022ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1022B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1022ACu;
            // 0x1022b0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1022B4u: goto label_1022b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1022B4u;
label_1022b4:
    // 0x1022b4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1022b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1022b8: 0x38630100  xori        $v1, $v1, 0x100
    ctx->pc = 0x1022b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)256);
    // 0x1022bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1022BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1022C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1022BCu;
            // 0x1022c0: 0x3100b  movn        $v0, $zero, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1022B4u: goto label_1022b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1022C4u;
    // 0x1022c4: 0x0  nop
    ctx->pc = 0x1022c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
