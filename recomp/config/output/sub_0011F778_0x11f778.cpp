#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F778
// Address: 0x11f778 - 0x11f7cc
void sub_0011F778_0x11f778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F778_0x11f778");
#endif

    ctx->pc = 0x11f778u;

    // 0x11f778: 0x4830008  bgezl       $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x11F778u;
    {
        const bool branch_taken_0x11f778 = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x11f778) {
            ctx->pc = 0x11F77Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11F778u;
            // 0x11f77c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11F79Cu;
            goto label_11f79c;
        }
    }
    ctx->pc = 0x11F780u;
    // 0x11f780: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x11f780u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x11f784: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x11f784u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x11f788: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11f788u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11f78c: 0x24651d08  addiu       $a1, $v1, 0x1D08
    ctx->pc = 0x11f78cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 7432));
    // 0x11f790: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x11f790u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x11f794: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x11F794u;
    {
        const bool branch_taken_0x11f794 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11F798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F794u;
            // 0x11f798: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f794) {
            ctx->pc = 0x11F7A8u;
            goto label_11f7a8;
        }
    }
    ctx->pc = 0x11F79Cu;
label_11f79c:
    // 0x11f79c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f79cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f7a0: 0x8c45b408  lw          $a1, -0x4BF8($v0)
    ctx->pc = 0x11f7a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294947848)));
    // 0x11f7a4: 0x8c62b40c  lw          $v0, -0x4BF4($v1)
    ctx->pc = 0x11f7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294947852)));
label_11f7a8:
    // 0x11f7a8: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x11f7a8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x11f7ac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11F7ACu;
    {
        const bool branch_taken_0x11f7ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11F7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F7ACu;
            // 0x11f7b0: 0x41900  sll         $v1, $a0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11f7ac) {
            ctx->pc = 0x11F7BCu;
            goto label_11f7bc;
        }
    }
    ctx->pc = 0x11F7B4u;
    // 0x11f7b4: 0x3e00008  jr          $ra
    ctx->pc = 0x11F7B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F7B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F7B4u;
            // 0x11f7b8: 0x2402ff97  addiu       $v0, $zero, -0x69 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967191));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F7BCu;
label_11f7bc:
    // 0x11f7bc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x11f7bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f7c0: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x11f7c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x11f7c4: 0x3e00008  jr          $ra
    ctx->pc = 0x11F7C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11F7C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11F7C4u;
            // 0x11f7c8: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11F79Cu: goto label_11f79c;
            case 0x11F7A8u: goto label_11f7a8;
            case 0x11F7BCu: goto label_11f7bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11F7CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
