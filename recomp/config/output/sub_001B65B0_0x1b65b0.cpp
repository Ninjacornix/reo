#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B65B0
// Address: 0x1b65b0 - 0x1b6670
void sub_001B65B0_0x1b65b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B65B0_0x1b65b0");
#endif

    ctx->pc = 0x1b65b0u;

    // 0x1b65b0: 0x308300ff  andi        $v1, $a0, 0xFF
    ctx->pc = 0x1b65b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1b65b4: 0x28610021  slti        $at, $v1, 0x21
    ctx->pc = 0x1b65b4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)33) ? 1 : 0);
    // 0x1b65b8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B65B8u;
    {
        const bool branch_taken_0x1b65b8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B65BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B65B8u;
            // 0x1b65bc: 0x2861007f  slti        $at, $v1, 0x7F (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)127) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b65b8) {
            ctx->pc = 0x1B65C8u;
            goto label_1b65c8;
        }
    }
    ctx->pc = 0x1B65C0u;
    // 0x1b65c0: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1B65C0u;
    {
        const bool branch_taken_0x1b65c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B65C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B65C0u;
            // 0x1b65c4: 0x34028140  ori         $v0, $zero, 0x8140 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33088);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b65c0) {
            ctx->pc = 0x1B665Cu;
            goto label_1b665c;
        }
    }
    ctx->pc = 0x1B65C8u;
label_1b65c8:
    // 0x1b65c8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B65C8u;
    {
        const bool branch_taken_0x1b65c8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B65CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B65C8u;
            // 0x1b65cc: 0x24627fff  addiu       $v0, $v1, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 32767));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b65c8) {
            ctx->pc = 0x1B65D8u;
            goto label_1b65d8;
        }
    }
    ctx->pc = 0x1B65D0u;
    // 0x1b65d0: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1B65D0u;
    {
        const bool branch_taken_0x1b65d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B65D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B65D0u;
            // 0x1b65d4: 0x24426d7f  addiu       $v0, $v0, 0x6D7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28031));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b65d0) {
            ctx->pc = 0x1B665Cu;
            goto label_1b665c;
        }
    }
    ctx->pc = 0x1B65D8u;
label_1b65d8:
    // 0x1b65d8: 0x286100a1  slti        $at, $v1, 0xA1
    ctx->pc = 0x1b65d8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)161) ? 1 : 0);
    // 0x1b65dc: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B65DCu;
    {
        const bool branch_taken_0x1b65dc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B65E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B65DCu;
            // 0x1b65e0: 0x286100a6  slti        $at, $v1, 0xA6 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)166) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b65dc) {
            ctx->pc = 0x1B65ECu;
            goto label_1b65ec;
        }
    }
    ctx->pc = 0x1B65E4u;
    // 0x1b65e4: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1B65E4u;
    {
        const bool branch_taken_0x1b65e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B65E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B65E4u;
            // 0x1b65e8: 0x34028140  ori         $v0, $zero, 0x8140 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33088);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b65e4) {
            ctx->pc = 0x1B665Cu;
            goto label_1b665c;
        }
    }
    ctx->pc = 0x1B65ECu;
label_1b65ec:
    // 0x1b65ec: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B65ECu;
    {
        const bool branch_taken_0x1b65ec = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B65F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B65ECu;
            // 0x1b65f0: 0x240200b0  addiu       $v0, $zero, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 176));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b65ec) {
            ctx->pc = 0x1B6610u;
            goto label_1b6610;
        }
    }
    ctx->pc = 0x1B65F4u;
    // 0x1b65f4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b65f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b65f8: 0x244246ff  addiu       $v0, $v0, 0x46FF
    ctx->pc = 0x1b65f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18175));
    // 0x1b65fc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b65fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b6600: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1b6600u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b6604: 0x24427fff  addiu       $v0, $v0, 0x7FFF
    ctx->pc = 0x1b6604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32767));
    // 0x1b6608: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1B6608u;
    {
        const bool branch_taken_0x1b6608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B660Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6608u;
            // 0x1b660c: 0x24426e01  addiu       $v0, $v0, 0x6E01 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28161));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6608) {
            ctx->pc = 0x1B665Cu;
            goto label_1b665c;
        }
    }
    ctx->pc = 0x1B6610u;
label_1b6610:
    // 0x1b6610: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6610u;
    {
        const bool branch_taken_0x1b6610 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b6610) {
            ctx->pc = 0x1B6620u;
            goto label_1b6620;
        }
    }
    ctx->pc = 0x1B6618u;
    // 0x1b6618: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1B6618u;
    {
        const bool branch_taken_0x1b6618 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B661Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6618u;
            // 0x1b661c: 0x3402eeba  ori         $v0, $zero, 0xEEBA (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)61114);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6618) {
            ctx->pc = 0x1B665Cu;
            goto label_1b665c;
        }
    }
    ctx->pc = 0x1B6620u;
label_1b6620:
    // 0x1b6620: 0x240200de  addiu       $v0, $zero, 0xDE
    ctx->pc = 0x1b6620u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 222));
    // 0x1b6624: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6624u;
    {
        const bool branch_taken_0x1b6624 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B6628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6624u;
            // 0x1b6628: 0x240200df  addiu       $v0, $zero, 0xDF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 223));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6624) {
            ctx->pc = 0x1B6634u;
            goto label_1b6634;
        }
    }
    ctx->pc = 0x1B662Cu;
    // 0x1b662c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B662Cu;
    {
        const bool branch_taken_0x1b662c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B662Cu;
            // 0x1b6630: 0x3402eeaa  ori         $v0, $zero, 0xEEAA (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)61098);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b662c) {
            ctx->pc = 0x1B665Cu;
            goto label_1b665c;
        }
    }
    ctx->pc = 0x1B6634u;
label_1b6634:
    // 0x1b6634: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6634u;
    {
        const bool branch_taken_0x1b6634 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b6634) {
            ctx->pc = 0x1B6644u;
            goto label_1b6644;
        }
    }
    ctx->pc = 0x1B663Cu;
    // 0x1b663c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B663Cu;
    {
        const bool branch_taken_0x1b663c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B663Cu;
            // 0x1b6640: 0x3402eea9  ori         $v0, $zero, 0xEEA9 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)61097);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b663c) {
            ctx->pc = 0x1B665Cu;
            goto label_1b665c;
        }
    }
    ctx->pc = 0x1B6644u;
label_1b6644:
    // 0x1b6644: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1b6644u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1b6648: 0x2442470a  addiu       $v0, $v0, 0x470A
    ctx->pc = 0x1b6648u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18186));
    // 0x1b664c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b664cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b6650: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1b6650u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b6654: 0x24427fff  addiu       $v0, $v0, 0x7FFF
    ctx->pc = 0x1b6654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32767));
    // 0x1b6658: 0x24426f01  addiu       $v0, $v0, 0x6F01
    ctx->pc = 0x1b6658u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28417));
label_1b665c:
    // 0x1b665c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B665Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B65C8u: goto label_1b65c8;
            case 0x1B65D8u: goto label_1b65d8;
            case 0x1B65ECu: goto label_1b65ec;
            case 0x1B6610u: goto label_1b6610;
            case 0x1B6620u: goto label_1b6620;
            case 0x1B6634u: goto label_1b6634;
            case 0x1B6644u: goto label_1b6644;
            case 0x1B665Cu: goto label_1b665c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B6664u;
    // 0x1b6664: 0x0  nop
    ctx->pc = 0x1b6664u;
    // NOP
    // 0x1b6668: 0x0  nop
    ctx->pc = 0x1b6668u;
    // NOP
    // 0x1b666c: 0x0  nop
    ctx->pc = 0x1b666cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
