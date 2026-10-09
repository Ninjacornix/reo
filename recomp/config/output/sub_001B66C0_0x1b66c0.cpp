#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B66C0
// Address: 0x1b66c0 - 0x1b67f0
void sub_001B66C0_0x1b66c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B66C0_0x1b66c0");
#endif

    ctx->pc = 0x1b66c0u;

    // 0x1b66c0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1b66c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b66c4: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x1b66c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b66c8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b66c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b66cc: 0x284100c0  slti        $at, $v0, 0xC0
    ctx->pc = 0x1b66ccu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)192) ? 1 : 0);
    // 0x1b66d0: 0x14200042  bnez        $at, . + 4 + (0x42 << 2)
    ctx->pc = 0x1B66D0u;
    {
        const bool branch_taken_0x1b66d0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B66D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B66D0u;
            // 0x1b66d4: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b66d0) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B66D8u;
    // 0x1b66d8: 0x284300c0  slti        $v1, $v0, 0xC0
    ctx->pc = 0x1b66d8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)192) ? 1 : 0);
    // 0x1b66dc: 0x14600017  bnez        $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1B66DCu;
    {
        const bool branch_taken_0x1b66dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B66E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B66DCu;
            // 0x1b66e0: 0x284300e0  slti        $v1, $v0, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b66dc) {
            ctx->pc = 0x1B673Cu;
            goto label_1b673c;
        }
    }
    ctx->pc = 0x1B66E4u;
    // 0x1b66e4: 0x284100e0  slti        $at, $v0, 0xE0
    ctx->pc = 0x1b66e4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)224) ? 1 : 0);
    // 0x1b66e8: 0x10200014  beqz        $at, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B66E8u;
    {
        const bool branch_taken_0x1b66e8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b66e8) {
            ctx->pc = 0x1B673Cu;
            goto label_1b673c;
        }
    }
    ctx->pc = 0x1B66F0u;
    // 0x1b66f0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1b66f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b66f4: 0x90660000  lbu         $a2, 0x0($v1)
    ctx->pc = 0x1b66f4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b66f8: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B66F8u;
    {
        const bool branch_taken_0x1b66f8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B66FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B66F8u;
            // 0x1b66fc: 0x24650001  addiu       $a1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b66f8) {
            ctx->pc = 0x1B6708u;
            goto label_1b6708;
        }
    }
    ctx->pc = 0x1B6700u;
    // 0x1b6700: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1B6700u;
    {
        const bool branch_taken_0x1b6700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6700u;
            // 0x1b6704: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6700) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B6708u;
label_1b6708:
    // 0x1b6708: 0x28c30080  slti        $v1, $a2, 0x80
    ctx->pc = 0x1b6708u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b670c: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B670Cu;
    {
        const bool branch_taken_0x1b670c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B670Cu;
            // 0x1b6710: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b670c) {
            ctx->pc = 0x1B6720u;
            goto label_1b6720;
        }
    }
    ctx->pc = 0x1B6714u;
    // 0x1b6714: 0x28c100c0  slti        $at, $a2, 0xC0
    ctx->pc = 0x1b6714u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)192) ? 1 : 0);
    // 0x1b6718: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6718u;
    {
        const bool branch_taken_0x1b6718 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b6718) {
            ctx->pc = 0x1B6728u;
            goto label_1b6728;
        }
    }
    ctx->pc = 0x1B6720u;
label_1b6720:
    // 0x1b6720: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1B6720u;
    {
        const bool branch_taken_0x1b6720 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6720u;
            // 0x1b6724: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6720) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B6728u;
label_1b6728:
    // 0x1b6728: 0x3042001f  andi        $v0, $v0, 0x1F
    ctx->pc = 0x1b6728u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
    // 0x1b672c: 0x30c3003f  andi        $v1, $a2, 0x3F
    ctx->pc = 0x1b672cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)63);
    // 0x1b6730: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x1b6730u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x1b6734: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1B6734u;
    {
        const bool branch_taken_0x1b6734 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6734u;
            // 0x1b6738: 0x431025  or          $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6734) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B673Cu;
label_1b673c:
    // 0x1b673c: 0x14600026  bnez        $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x1B673Cu;
    {
        const bool branch_taken_0x1b673c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B673Cu;
            // 0x1b6740: 0x284100f0  slti        $at, $v0, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)240) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b673c) {
            ctx->pc = 0x1B67D8u;
            goto label_1b67d8;
        }
    }
    ctx->pc = 0x1B6744u;
    // 0x1b6744: 0x10200024  beqz        $at, . + 4 + (0x24 << 2)
    ctx->pc = 0x1B6744u;
    {
        const bool branch_taken_0x1b6744 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6744) {
            ctx->pc = 0x1B67D8u;
            goto label_1b67d8;
        }
    }
    ctx->pc = 0x1B674Cu;
    // 0x1b674c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1b674cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b6750: 0x90670000  lbu         $a3, 0x0($v1)
    ctx->pc = 0x1b6750u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b6754: 0x14e00003  bnez        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6754u;
    {
        const bool branch_taken_0x1b6754 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6754u;
            // 0x1b6758: 0x24650001  addiu       $a1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6754) {
            ctx->pc = 0x1B6764u;
            goto label_1b6764;
        }
    }
    ctx->pc = 0x1B675Cu;
    // 0x1b675c: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1B675Cu;
    {
        const bool branch_taken_0x1b675c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B675Cu;
            // 0x1b6760: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b675c) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B6764u;
label_1b6764:
    // 0x1b6764: 0x28e30080  slti        $v1, $a3, 0x80
    ctx->pc = 0x1b6764u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b6768: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6768u;
    {
        const bool branch_taken_0x1b6768 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B676Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6768u;
            // 0x1b676c: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6768) {
            ctx->pc = 0x1B677Cu;
            goto label_1b677c;
        }
    }
    ctx->pc = 0x1B6770u;
    // 0x1b6770: 0x28e100c0  slti        $at, $a3, 0xC0
    ctx->pc = 0x1b6770u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)192) ? 1 : 0);
    // 0x1b6774: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B6774u;
    {
        const bool branch_taken_0x1b6774 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b6774) {
            ctx->pc = 0x1B6784u;
            goto label_1b6784;
        }
    }
    ctx->pc = 0x1B677Cu;
label_1b677c:
    // 0x1b677c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1B677Cu;
    {
        const bool branch_taken_0x1b677c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B677Cu;
            // 0x1b6780: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b677c) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B6784u;
label_1b6784:
    // 0x1b6784: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1b6784u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b6788: 0x90660000  lbu         $a2, 0x0($v1)
    ctx->pc = 0x1b6788u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b678c: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B678Cu;
    {
        const bool branch_taken_0x1b678c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B678Cu;
            // 0x1b6790: 0x24650001  addiu       $a1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b678c) {
            ctx->pc = 0x1B679Cu;
            goto label_1b679c;
        }
    }
    ctx->pc = 0x1B6794u;
    // 0x1b6794: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B6794u;
    {
        const bool branch_taken_0x1b6794 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6794u;
            // 0x1b6798: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6794) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B679Cu;
label_1b679c:
    // 0x1b679c: 0x28c30080  slti        $v1, $a2, 0x80
    ctx->pc = 0x1b679cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b67a0: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B67A0u;
    {
        const bool branch_taken_0x1b67a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B67A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B67A0u;
            // 0x1b67a4: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b67a0) {
            ctx->pc = 0x1B67B4u;
            goto label_1b67b4;
        }
    }
    ctx->pc = 0x1B67A8u;
    // 0x1b67a8: 0x28c100c0  slti        $at, $a2, 0xC0
    ctx->pc = 0x1b67a8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)192) ? 1 : 0);
    // 0x1b67ac: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B67ACu;
    {
        const bool branch_taken_0x1b67ac = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B67B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B67ACu;
            // 0x1b67b0: 0x30e4003f  andi        $a0, $a3, 0x3F (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)63);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b67ac) {
            ctx->pc = 0x1B67BCu;
            goto label_1b67bc;
        }
    }
    ctx->pc = 0x1B67B4u;
label_1b67b4:
    // 0x1b67b4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B67B4u;
    {
        const bool branch_taken_0x1b67b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B67B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B67B4u;
            // 0x1b67b8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b67b4) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B67BCu;
label_1b67bc:
    // 0x1b67bc: 0x3042000f  andi        $v0, $v0, 0xF
    ctx->pc = 0x1b67bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
    // 0x1b67c0: 0x42180  sll         $a0, $a0, 6
    ctx->pc = 0x1b67c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
    // 0x1b67c4: 0x21300  sll         $v0, $v0, 12
    ctx->pc = 0x1b67c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 12));
    // 0x1b67c8: 0x30c3003f  andi        $v1, $a2, 0x3F
    ctx->pc = 0x1b67c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)63);
    // 0x1b67cc: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1b67ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1b67d0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B67D0u;
    {
        const bool branch_taken_0x1b67d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B67D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B67D0u;
            // 0x1b67d4: 0x621025  or          $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b67d0) {
            ctx->pc = 0x1B67DCu;
            goto label_1b67dc;
        }
    }
    ctx->pc = 0x1B67D8u;
label_1b67d8:
    // 0x1b67d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1b67d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1b67dc:
    // 0x1b67dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B67DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B6708u: goto label_1b6708;
            case 0x1B6720u: goto label_1b6720;
            case 0x1B6728u: goto label_1b6728;
            case 0x1B673Cu: goto label_1b673c;
            case 0x1B6764u: goto label_1b6764;
            case 0x1B677Cu: goto label_1b677c;
            case 0x1B6784u: goto label_1b6784;
            case 0x1B679Cu: goto label_1b679c;
            case 0x1B67B4u: goto label_1b67b4;
            case 0x1B67BCu: goto label_1b67bc;
            case 0x1B67D8u: goto label_1b67d8;
            case 0x1B67DCu: goto label_1b67dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B67E4u;
    // 0x1b67e4: 0x0  nop
    ctx->pc = 0x1b67e4u;
    // NOP
    // 0x1b67e8: 0x0  nop
    ctx->pc = 0x1b67e8u;
    // NOP
    // 0x1b67ec: 0x0  nop
    ctx->pc = 0x1b67ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
