#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101F60
// Address: 0x101f60 - 0x101fa0
void sub_00101F60_0x101f60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101F60_0x101f60");
#endif

    ctx->pc = 0x101f60u;

    // 0x101f60: 0x4843e800  cfc2.ni     $v1, $vi29
    ctx->pc = 0x101f60u;
    SET_GPR_U32(ctx, 3, ctx->vu0_top);
    // 0x101f64: 0x30620002  andi        $v0, $v1, 0x2
    ctx->pc = 0x101f64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
    // 0x101f68: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101F68u;
    {
        const bool branch_taken_0x101f68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F68u;
            // 0x101f6c: 0x30620004  andi        $v0, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101f68) {
            ctx->pc = 0x101F78u;
            goto label_101f78;
        }
    }
    ctx->pc = 0x101F70u;
    // 0x101f70: 0x3e00008  jr          $ra
    ctx->pc = 0x101F70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F70u;
            // 0x101f74: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101F78u: goto label_101f78;
            case 0x101F88u: goto label_101f88;
            case 0x101F98u: goto label_101f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F78u;
label_101f78:
    // 0x101f78: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101F78u;
    {
        const bool branch_taken_0x101f78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F78u;
            // 0x101f7c: 0x30620008  andi        $v0, $v1, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101f78) {
            ctx->pc = 0x101F88u;
            goto label_101f88;
        }
    }
    ctx->pc = 0x101F80u;
    // 0x101f80: 0x3e00008  jr          $ra
    ctx->pc = 0x101F80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F80u;
            // 0x101f84: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101F78u: goto label_101f78;
            case 0x101F88u: goto label_101f88;
            case 0x101F98u: goto label_101f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F88u;
label_101f88:
    // 0x101f88: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101F88u;
    {
        const bool branch_taken_0x101f88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101F8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F88u;
            // 0x101f8c: 0x30620001  andi        $v0, $v1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x101f88) {
            ctx->pc = 0x101F98u;
            goto label_101f98;
        }
    }
    ctx->pc = 0x101F90u;
    // 0x101f90: 0x3e00008  jr          $ra
    ctx->pc = 0x101F90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F90u;
            // 0x101f94: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101F78u: goto label_101f78;
            case 0x101F88u: goto label_101f88;
            case 0x101F98u: goto label_101f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101F98u;
label_101f98:
    // 0x101f98: 0x3e00008  jr          $ra
    ctx->pc = 0x101F98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F98u;
            // 0x101f9c: 0x21080  sll         $v0, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101F78u: goto label_101f78;
            case 0x101F88u: goto label_101f88;
            case 0x101F98u: goto label_101f98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101FA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
