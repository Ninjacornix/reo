#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013DF98
// Address: 0x13df98 - 0x13e598
void sub_0013DF98_0x13df98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013DF98_0x13df98");
#endif

    switch (ctx->pc) {
        case 0x13dfa8u: goto label_13dfa8;
        case 0x13dfd8u: goto label_13dfd8;
        case 0x13e040u: goto label_13e040;
        case 0x13e1f0u: goto label_13e1f0;
        case 0x13e30cu: goto label_13e30c;
        case 0x13e314u: goto label_13e314;
        case 0x13e31cu: goto label_13e31c;
        case 0x13e324u: goto label_13e324;
        case 0x13e32cu: goto label_13e32c;
        case 0x13e33cu: goto label_13e33c;
        case 0x13e364u: goto label_13e364;
        case 0x13e37cu: goto label_13e37c;
        case 0x13e380u: goto label_13e380;
        case 0x13e3b8u: goto label_13e3b8;
        case 0x13e3e8u: goto label_13e3e8;
        case 0x13e3fcu: goto label_13e3fc;
        case 0x13e400u: goto label_13e400;
        case 0x13e43cu: goto label_13e43c;
        case 0x13e454u: goto label_13e454;
        case 0x13e48cu: goto label_13e48c;
        case 0x13e4a4u: goto label_13e4a4;
        case 0x13e4a8u: goto label_13e4a8;
        case 0x13e4d8u: goto label_13e4d8;
        case 0x13e528u: goto label_13e528;
        case 0x13e58cu: goto label_13e58c;
        default: break;
    }

    ctx->pc = 0x13df98u;

    // 0x13df98: 0x3e00008  jr          $ra
    ctx->pc = 0x13DF98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13DF9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13DF98u;
            // 0x13df9c: 0xa0800000  sb          $zero, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DFA8u: goto label_13dfa8;
            case 0x13DFC8u: goto label_13dfc8;
            case 0x13DFD8u: goto label_13dfd8;
            case 0x13DFF4u: goto label_13dff4;
            case 0x13E040u: goto label_13e040;
            case 0x13E08Cu: goto label_13e08c;
            case 0x13E0C4u: goto label_13e0c4;
            case 0x13E0FCu: goto label_13e0fc;
            case 0x13E138u: goto label_13e138;
            case 0x13E170u: goto label_13e170;
            case 0x13E1B8u: goto label_13e1b8;
            case 0x13E1F0u: goto label_13e1f0;
            case 0x13E234u: goto label_13e234;
            case 0x13E24Cu: goto label_13e24c;
            case 0x13E288u: goto label_13e288;
            case 0x13E294u: goto label_13e294;
            case 0x13E2A4u: goto label_13e2a4;
            case 0x13E2A8u: goto label_13e2a8;
            case 0x13E30Cu: goto label_13e30c;
            case 0x13E314u: goto label_13e314;
            case 0x13E31Cu: goto label_13e31c;
            case 0x13E324u: goto label_13e324;
            case 0x13E32Cu: goto label_13e32c;
            case 0x13E33Cu: goto label_13e33c;
            case 0x13E364u: goto label_13e364;
            case 0x13E37Cu: goto label_13e37c;
            case 0x13E380u: goto label_13e380;
            case 0x13E3A0u: goto label_13e3a0;
            case 0x13E3B8u: goto label_13e3b8;
            case 0x13E3E8u: goto label_13e3e8;
            case 0x13E3FCu: goto label_13e3fc;
            case 0x13E400u: goto label_13e400;
            case 0x13E420u: goto label_13e420;
            case 0x13E43Cu: goto label_13e43c;
            case 0x13E454u: goto label_13e454;
            case 0x13E48Cu: goto label_13e48c;
            case 0x13E4A4u: goto label_13e4a4;
            case 0x13E4A8u: goto label_13e4a8;
            case 0x13E4C8u: goto label_13e4c8;
            case 0x13E4D8u: goto label_13e4d8;
            case 0x13E4E0u: goto label_13e4e0;
            case 0x13E4E8u: goto label_13e4e8;
            case 0x13E528u: goto label_13e528;
            case 0x13E52Cu: goto label_13e52c;
            case 0x13E58Cu: goto label_13e58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13DFA0u;
    // 0x13dfa0: 0x54a00009  bnel        $a1, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x13DFA0u;
    {
        const bool branch_taken_0x13dfa0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x13dfa0) {
            ctx->pc = 0x13DFA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13DFA0u;
            // 0x13dfa4: 0x8ca50000  lw          $a1, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13DFC8u;
            goto label_13dfc8;
        }
    }
    ctx->pc = 0x13DFA8u;
label_13dfa8:
    // 0x13dfa8: 0x0  nop
    ctx->pc = 0x13dfa8u;
    // NOP
    // 0x13dfac: 0x0  nop
    ctx->pc = 0x13dfacu;
    // NOP
    // 0x13dfb0: 0x0  nop
    ctx->pc = 0x13dfb0u;
    // NOP
    // 0x13dfb4: 0x0  nop
    ctx->pc = 0x13dfb4u;
    // NOP
    // 0x13dfb8: 0x0  nop
    ctx->pc = 0x13dfb8u;
    // NOP
    // 0x13dfbc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DFBCu;
    {
        const bool branch_taken_0x13dfbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13dfbc) {
            ctx->pc = 0x13DFA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dfa8;
        }
    }
    ctx->pc = 0x13DFC4u;
    // 0x13dfc4: 0x0  nop
    ctx->pc = 0x13dfc4u;
    // NOP
label_13dfc8:
    // 0x13dfc8: 0x18a0000a  blez        $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x13DFC8u;
    {
        const bool branch_taken_0x13dfc8 = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x13dfc8) {
            ctx->pc = 0x13DFF4u;
            goto label_13dff4;
        }
    }
    ctx->pc = 0x13DFD0u;
    // 0x13dfd0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x13dfd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x13dfd4: 0x0  nop
    ctx->pc = 0x13dfd4u;
    // NOP
label_13dfd8:
    // 0x13dfd8: 0x0  nop
    ctx->pc = 0x13dfd8u;
    // NOP
    // 0x13dfdc: 0x0  nop
    ctx->pc = 0x13dfdcu;
    // NOP
    // 0x13dfe0: 0x0  nop
    ctx->pc = 0x13dfe0u;
    // NOP
    // 0x13dfe4: 0x0  nop
    ctx->pc = 0x13dfe4u;
    // NOP
    // 0x13dfe8: 0x0  nop
    ctx->pc = 0x13dfe8u;
    // NOP
    // 0x13dfec: 0x54a0fffa  bnel        $a1, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13DFECu;
    {
        const bool branch_taken_0x13dfec = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x13dfec) {
            ctx->pc = 0x13DFF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13DFECu;
            // 0x13dff0: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13DFD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13dfd8;
        }
    }
    ctx->pc = 0x13DFF4u;
label_13dff4:
    // 0x13dff4: 0x3e00008  jr          $ra
    ctx->pc = 0x13DFF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DFA8u: goto label_13dfa8;
            case 0x13DFC8u: goto label_13dfc8;
            case 0x13DFD8u: goto label_13dfd8;
            case 0x13DFF4u: goto label_13dff4;
            case 0x13E040u: goto label_13e040;
            case 0x13E08Cu: goto label_13e08c;
            case 0x13E0C4u: goto label_13e0c4;
            case 0x13E0FCu: goto label_13e0fc;
            case 0x13E138u: goto label_13e138;
            case 0x13E170u: goto label_13e170;
            case 0x13E1B8u: goto label_13e1b8;
            case 0x13E1F0u: goto label_13e1f0;
            case 0x13E234u: goto label_13e234;
            case 0x13E24Cu: goto label_13e24c;
            case 0x13E288u: goto label_13e288;
            case 0x13E294u: goto label_13e294;
            case 0x13E2A4u: goto label_13e2a4;
            case 0x13E2A8u: goto label_13e2a8;
            case 0x13E30Cu: goto label_13e30c;
            case 0x13E314u: goto label_13e314;
            case 0x13E31Cu: goto label_13e31c;
            case 0x13E324u: goto label_13e324;
            case 0x13E32Cu: goto label_13e32c;
            case 0x13E33Cu: goto label_13e33c;
            case 0x13E364u: goto label_13e364;
            case 0x13E37Cu: goto label_13e37c;
            case 0x13E380u: goto label_13e380;
            case 0x13E3A0u: goto label_13e3a0;
            case 0x13E3B8u: goto label_13e3b8;
            case 0x13E3E8u: goto label_13e3e8;
            case 0x13E3FCu: goto label_13e3fc;
            case 0x13E400u: goto label_13e400;
            case 0x13E420u: goto label_13e420;
            case 0x13E43Cu: goto label_13e43c;
            case 0x13E454u: goto label_13e454;
            case 0x13E48Cu: goto label_13e48c;
            case 0x13E4A4u: goto label_13e4a4;
            case 0x13E4A8u: goto label_13e4a8;
            case 0x13E4C8u: goto label_13e4c8;
            case 0x13E4D8u: goto label_13e4d8;
            case 0x13E4E0u: goto label_13e4e0;
            case 0x13E4E8u: goto label_13e4e8;
            case 0x13E528u: goto label_13e528;
            case 0x13E52Cu: goto label_13e52c;
            case 0x13E58Cu: goto label_13e58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13DFFCu;
    // 0x13dffc: 0x0  nop
    ctx->pc = 0x13dffcu;
    // NOP
    // 0x13e000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13e000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13e004: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13e004u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13e008: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13e008u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13e00c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x13e00cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e010: 0x24423880  addiu       $v0, $v0, 0x3880
    ctx->pc = 0x13e010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14464));
    // 0x13e014: 0x260d0010  addiu       $t5, $s0, 0x10
    ctx->pc = 0x13e014u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x13e018: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13e018u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13e01c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13e01cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13e020: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x13e020u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e024: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x13e024u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e028: 0x24710498  addiu       $s1, $v1, 0x498
    ctx->pc = 0x13e028u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 1176));
    // 0x13e02c: 0x782d  daddu       $t7, $zero, $zero
    ctx->pc = 0x13e02cu;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e030: 0x24190001  addiu       $t9, $zero, 0x1
    ctx->pc = 0x13e030u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e034: 0x24180002  addiu       $t8, $zero, 0x2
    ctx->pc = 0x13e034u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13e038: 0x244e0008  addiu       $t6, $v0, 0x8
    ctx->pc = 0x13e038u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x13e03c: 0x1a0302d  daddu       $a2, $t5, $zero
    ctx->pc = 0x13e03cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
label_13e040:
    // 0x13e040: 0x80e20000  lb          $v0, 0x0($a3)
    ctx->pc = 0x13e040u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x13e044: 0x54590093  bnel        $v0, $t9, . + 4 + (0x93 << 2)
    ctx->pc = 0x13E044u;
    {
        const bool branch_taken_0x13e044 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 25));
        if (branch_taken_0x13e044) {
            ctx->pc = 0x13E048u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E044u;
            // 0x13e048: 0x25ef0001  addiu       $t7, $t7, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E294u;
            goto label_13e294;
        }
    }
    ctx->pc = 0x13E04Cu;
    // 0x13e04c: 0x24080080  addiu       $t0, $zero, 0x80
    ctx->pc = 0x13e04cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x13e050: 0x51480095  beql        $t2, $t0, . + 4 + (0x95 << 2)
    ctx->pc = 0x13E050u;
    {
        const bool branch_taken_0x13e050 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e050) {
            ctx->pc = 0x13E054u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E050u;
            // 0x13e054: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E058u;
    // 0x13e058: 0x80e30053  lb          $v1, 0x53($a3)
    ctx->pc = 0x13e058u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 83)));
    // 0x13e05c: 0x80e20052  lb          $v0, 0x52($a3)
    ctx->pc = 0x13e05cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 82)));
    // 0x13e060: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x13E060u;
    {
        const bool branch_taken_0x13e060 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E060u;
            // 0x13e064: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e060) {
            ctx->pc = 0x13E08Cu;
            goto label_13e08c;
        }
    }
    ctx->pc = 0x13E068u;
    // 0x13e068: 0x8ce30020  lw          $v1, 0x20($a3)
    ctx->pc = 0x13e068u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e06c: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x13e06cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x13e070: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e070u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e074: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x13e074u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x13e078: 0x80e20053  lb          $v0, 0x53($a3)
    ctx->pc = 0x13e078u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 83)));
    // 0x13e07c: 0xacc20008  sw          $v0, 0x8($a2)
    ctx->pc = 0x13e07cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
    // 0x13e080: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e080u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e084: 0x90e20053  lbu         $v0, 0x53($a3)
    ctx->pc = 0x13e084u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 83)));
    // 0x13e088: 0xa0e20052  sb          $v0, 0x52($a3)
    ctx->pc = 0x13e088u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 82), (uint8_t)GPR_U32(ctx, 2));
label_13e08c:
    // 0x13e08c: 0x11480085  beq         $t2, $t0, . + 4 + (0x85 << 2)
    ctx->pc = 0x13E08Cu;
    {
        const bool branch_taken_0x13e08c = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        ctx->pc = 0x13E090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E08Cu;
            // 0x13e090: 0x24020100  addiu       $v0, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e08c) {
            ctx->pc = 0x13E2A4u;
            goto label_13e2a4;
        }
    }
    ctx->pc = 0x13E094u;
    // 0x13e094: 0x94e30024  lhu         $v1, 0x24($a3)
    ctx->pc = 0x13e094u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e098: 0x1462000a  bne         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x13E098u;
    {
        const bool branch_taken_0x13e098 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13e098) {
            ctx->pc = 0x13E0C4u;
            goto label_13e0c4;
        }
    }
    ctx->pc = 0x13E0A0u;
    // 0x13e0a0: 0x8ce20020  lw          $v0, 0x20($a3)
    ctx->pc = 0x13e0a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e0a4: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e0a4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e0a8: 0xa4d80000  sh          $t8, 0x0($a2)
    ctx->pc = 0x13e0a8u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 24));
    // 0x13e0ac: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x13e0acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x13e0b0: 0x80e30024  lb          $v1, 0x24($a3)
    ctx->pc = 0x13e0b0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e0b4: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x13e0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x13e0b8: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e0b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e0bc: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x13e0bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e0c0: 0xa0e20025  sb          $v0, 0x25($a3)
    ctx->pc = 0x13e0c0u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 37), (uint8_t)GPR_U32(ctx, 2));
label_13e0c4:
    // 0x13e0c4: 0x51480078  beql        $t2, $t0, . + 4 + (0x78 << 2)
    ctx->pc = 0x13E0C4u;
    {
        const bool branch_taken_0x13e0c4 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e0c4) {
            ctx->pc = 0x13E0C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E0C4u;
            // 0x13e0c8: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E0CCu;
    // 0x13e0cc: 0x8ce30048  lw          $v1, 0x48($a3)
    ctx->pc = 0x13e0ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 72)));
    // 0x13e0d0: 0x8ce2004c  lw          $v0, 0x4C($a3)
    ctx->pc = 0x13e0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 76)));
    // 0x13e0d4: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13E0D4u;
    {
        const bool branch_taken_0x13e0d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E0D4u;
            // 0x13e0d8: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e0d4) {
            ctx->pc = 0x13E0FCu;
            goto label_13e0fc;
        }
    }
    ctx->pc = 0x13E0DCu;
    // 0x13e0dc: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x13e0dcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x13e0e0: 0x8ce40020  lw          $a0, 0x20($a3)
    ctx->pc = 0x13e0e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e0e4: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e0e4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e0e8: 0x8ce30048  lw          $v1, 0x48($a3)
    ctx->pc = 0x13e0e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 72)));
    // 0x13e0ec: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x13e0ecu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x13e0f0: 0xace3004c  sw          $v1, 0x4C($a3)
    ctx->pc = 0x13e0f0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 76), GPR_U32(ctx, 3));
    // 0x13e0f4: 0xacc40004  sw          $a0, 0x4($a2)
    ctx->pc = 0x13e0f4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 4));
    // 0x13e0f8: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e0f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
label_13e0fc:
    // 0x13e0fc: 0x5148006a  beql        $t2, $t0, . + 4 + (0x6A << 2)
    ctx->pc = 0x13E0FCu;
    {
        const bool branch_taken_0x13e0fc = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e0fc) {
            ctx->pc = 0x13E100u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E0FCu;
            // 0x13e100: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E104u;
    // 0x13e104: 0x80e30026  lb          $v1, 0x26($a3)
    ctx->pc = 0x13e104u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e108: 0x80e20027  lb          $v0, 0x27($a3)
    ctx->pc = 0x13e108u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 39)));
    // 0x13e10c: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x13E10Cu;
    {
        const bool branch_taken_0x13e10c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E10Cu;
            // 0x13e110: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e10c) {
            ctx->pc = 0x13E138u;
            goto label_13e138;
        }
    }
    ctx->pc = 0x13E114u;
    // 0x13e114: 0x8ce30020  lw          $v1, 0x20($a3)
    ctx->pc = 0x13e114u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e118: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x13e118u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x13e11c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e11cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e120: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x13e120u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x13e124: 0x80e20026  lb          $v0, 0x26($a3)
    ctx->pc = 0x13e124u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e128: 0xacc20008  sw          $v0, 0x8($a2)
    ctx->pc = 0x13e128u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
    // 0x13e12c: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e12cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e130: 0x90e20026  lbu         $v0, 0x26($a3)
    ctx->pc = 0x13e130u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e134: 0xa0e20027  sb          $v0, 0x27($a3)
    ctx->pc = 0x13e134u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 39), (uint8_t)GPR_U32(ctx, 2));
label_13e138:
    // 0x13e138: 0x5148005b  beql        $t2, $t0, . + 4 + (0x5B << 2)
    ctx->pc = 0x13E138u;
    {
        const bool branch_taken_0x13e138 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e138) {
            ctx->pc = 0x13E13Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E138u;
            // 0x13e13c: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E140u;
    // 0x13e140: 0x8ce30028  lw          $v1, 0x28($a3)
    ctx->pc = 0x13e140u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x13e144: 0x8ce2002c  lw          $v0, 0x2C($a3)
    ctx->pc = 0x13e144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x13e148: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13E148u;
    {
        const bool branch_taken_0x13e148 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E14Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E148u;
            // 0x13e14c: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e148) {
            ctx->pc = 0x13E170u;
            goto label_13e170;
        }
    }
    ctx->pc = 0x13E150u;
    // 0x13e150: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x13e150u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x13e154: 0x8ce40020  lw          $a0, 0x20($a3)
    ctx->pc = 0x13e154u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e158: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e158u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e15c: 0x8ce30028  lw          $v1, 0x28($a3)
    ctx->pc = 0x13e15cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x13e160: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x13e160u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x13e164: 0xace3002c  sw          $v1, 0x2C($a3)
    ctx->pc = 0x13e164u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 44), GPR_U32(ctx, 3));
    // 0x13e168: 0xacc40004  sw          $a0, 0x4($a2)
    ctx->pc = 0x13e168u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 4));
    // 0x13e16c: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e16cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
label_13e170:
    // 0x13e170: 0x5148004d  beql        $t2, $t0, . + 4 + (0x4D << 2)
    ctx->pc = 0x13E170u;
    {
        const bool branch_taken_0x13e170 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x13e170) {
            ctx->pc = 0x13E174u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E170u;
            // 0x13e174: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E178u;
    // 0x13e178: 0x8ce30030  lw          $v1, 0x30($a3)
    ctx->pc = 0x13e178u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x13e17c: 0x8ce20034  lw          $v0, 0x34($a3)
    ctx->pc = 0x13e17cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x13e180: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13E180u;
    {
        const bool branch_taken_0x13e180 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E180u;
            // 0x13e184: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e180) {
            ctx->pc = 0x13E1B8u;
            goto label_13e1b8;
        }
    }
    ctx->pc = 0x13E188u;
    // 0x13e188: 0x8ce50020  lw          $a1, 0x20($a3)
    ctx->pc = 0x13e188u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e18c: 0x2221023  subu        $v0, $s1, $v0
    ctx->pc = 0x13e18cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x13e190: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x13e190u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x13e194: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x13e194u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13e198: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e198u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e19c: 0xacc00008  sw          $zero, 0x8($a2)
    ctx->pc = 0x13e19cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 0));
    // 0x13e1a0: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x13e1a0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x13e1a4: 0xa4c40000  sh          $a0, 0x0($a2)
    ctx->pc = 0x13e1a4u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x13e1a8: 0x8ce20030  lw          $v0, 0x30($a3)
    ctx->pc = 0x13e1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x13e1ac: 0xacc50004  sw          $a1, 0x4($a2)
    ctx->pc = 0x13e1acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 5));
    // 0x13e1b0: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e1b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e1b4: 0xace20034  sw          $v0, 0x34($a3)
    ctx->pc = 0x13e1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 52), GPR_U32(ctx, 2));
label_13e1b8:
    // 0x13e1b8: 0x1148003a  beq         $t2, $t0, . + 4 + (0x3A << 2)
    ctx->pc = 0x13E1B8u;
    {
        const bool branch_taken_0x13e1b8 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        ctx->pc = 0x13E1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E1B8u;
            // 0x13e1bc: 0x2402007f  addiu       $v0, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e1b8) {
            ctx->pc = 0x13E2A4u;
            goto label_13e2a4;
        }
    }
    ctx->pc = 0x13E1C0u;
    // 0x13e1c0: 0x51420039  beql        $t2, $v0, . + 4 + (0x39 << 2)
    ctx->pc = 0x13E1C0u;
    {
        const bool branch_taken_0x13e1c0 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 2));
        if (branch_taken_0x13e1c0) {
            ctx->pc = 0x13E1C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E1C0u;
            // 0x13e1c4: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E1C8u;
    // 0x13e1c8: 0x80e20026  lb          $v0, 0x26($a3)
    ctx->pc = 0x13e1c8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e1cc: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x13e1ccu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e1d0: 0x1840001e  blez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x13E1D0u;
    {
        const bool branch_taken_0x13e1d0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13E1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E1D0u;
            // 0x13e1d4: 0x90e90026  lbu         $t1, 0x26($a3) (Delay Slot)
        SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e1d0) {
            ctx->pc = 0x13E24Cu;
            goto label_13e24c;
        }
    }
    ctx->pc = 0x13E1D8u;
    // 0x13e1d8: 0xa1100  sll         $v0, $t2, 4
    ctx->pc = 0x13e1d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 4));
    // 0x13e1dc: 0x240c0009  addiu       $t4, $zero, 0x9
    ctx->pc = 0x13e1dcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x13e1e0: 0x4d2021  addu        $a0, $v0, $t5
    ctx->pc = 0x13e1e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 13)));
    // 0x13e1e4: 0x24e80040  addiu       $t0, $a3, 0x40
    ctx->pc = 0x13e1e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x13e1e8: 0x25c50030  addiu       $a1, $t6, 0x30
    ctx->pc = 0x13e1e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 14), 48));
    // 0x13e1ec: 0x0  nop
    ctx->pc = 0x13e1ecu;
    // NOP
label_13e1f0:
    // 0x13e1f0: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x13e1f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13e1f4: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x13e1f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x13e1f8: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x13E1F8u;
    {
        const bool branch_taken_0x13e1f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13E1FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E1F8u;
            // 0x13e1fc: 0x91600  sll         $v0, $t1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e1f8) {
            ctx->pc = 0x13E234u;
            goto label_13e234;
        }
    }
    ctx->pc = 0x13E200u;
    // 0x13e200: 0xac8b0008  sw          $t3, 0x8($a0)
    ctx->pc = 0x13e200u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 11));
    // 0x13e204: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e204u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e208: 0x8ce30020  lw          $v1, 0x20($a3)
    ctx->pc = 0x13e208u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e20c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e20cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e210: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x13e210u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13e214: 0xa48c0000  sh          $t4, 0x0($a0)
    ctx->pc = 0x13e214u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 12));
    // 0x13e218: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x13e218u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x13e21c: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x13e21cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x13e220: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x13e220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x13e224: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x13e224u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13e228: 0xad020000  sw          $v0, 0x0($t0)
    ctx->pc = 0x13e228u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 2));
    // 0x13e22c: 0x90e90026  lbu         $t1, 0x26($a3)
    ctx->pc = 0x13e22cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 38)));
    // 0x13e230: 0x91600  sll         $v0, $t1, 24
    ctx->pc = 0x13e230u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 9), 24));
label_13e234:
    // 0x13e234: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x13e234u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x13e238: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x13e238u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x13e23c: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x13e23cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x13e240: 0x162102a  slt         $v0, $t3, $v0
    ctx->pc = 0x13e240u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 11) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13e244: 0x1440ffea  bnez        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x13E244u;
    {
        const bool branch_taken_0x13e244 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E244u;
            // 0x13e248: 0x24a50004  addiu       $a1, $a1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e244) {
            ctx->pc = 0x13E1F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e1f0;
        }
    }
    ctx->pc = 0x13E24Cu;
label_13e24c:
    // 0x13e24c: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x13e24cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x13e250: 0x51440015  beql        $t2, $a0, . + 4 + (0x15 << 2)
    ctx->pc = 0x13E250u;
    {
        const bool branch_taken_0x13e250 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 4));
        if (branch_taken_0x13e250) {
            ctx->pc = 0x13E254u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E250u;
            // 0x13e254: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E258u;
    // 0x13e258: 0x94e20024  lhu         $v0, 0x24($a3)
    ctx->pc = 0x13e258u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e25c: 0x1459000a  bne         $v0, $t9, . + 4 + (0xA << 2)
    ctx->pc = 0x13E25Cu;
    {
        const bool branch_taken_0x13e25c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 25));
        if (branch_taken_0x13e25c) {
            ctx->pc = 0x13E288u;
            goto label_13e288;
        }
    }
    ctx->pc = 0x13E264u;
    // 0x13e264: 0x8ce20020  lw          $v0, 0x20($a3)
    ctx->pc = 0x13e264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x13e268: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x13e268u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x13e26c: 0xa4d80000  sh          $t8, 0x0($a2)
    ctx->pc = 0x13e26cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 24));
    // 0x13e270: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x13e270u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x13e274: 0x80e30024  lb          $v1, 0x24($a3)
    ctx->pc = 0x13e274u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e278: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x13e278u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x13e27c: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x13e27cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
    // 0x13e280: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x13e280u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x13e284: 0xa0e20025  sb          $v0, 0x25($a3)
    ctx->pc = 0x13e284u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 37), (uint8_t)GPR_U32(ctx, 2));
label_13e288:
    // 0x13e288: 0x51440007  beql        $t2, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13E288u;
    {
        const bool branch_taken_0x13e288 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 4));
        if (branch_taken_0x13e288) {
            ctx->pc = 0x13E28Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E288u;
            // 0x13e28c: 0xae0a0000  sw          $t2, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E2A8u;
            goto label_13e2a8;
        }
    }
    ctx->pc = 0x13E290u;
    // 0x13e290: 0x25ef0001  addiu       $t7, $t7, 0x1
    ctx->pc = 0x13e290u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
label_13e294:
    // 0x13e294: 0x25ce0060  addiu       $t6, $t6, 0x60
    ctx->pc = 0x13e294u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 96));
    // 0x13e298: 0x29e20010  slti        $v0, $t7, 0x10
    ctx->pc = 0x13e298u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 15) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13e29c: 0x1440ff68  bnez        $v0, . + 4 + (-0x98 << 2)
    ctx->pc = 0x13E29Cu;
    {
        const bool branch_taken_0x13e29c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E29Cu;
            // 0x13e2a0: 0x24e70060  addiu       $a3, $a3, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e29c) {
            ctx->pc = 0x13E040u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e040;
        }
    }
    ctx->pc = 0x13E2A4u;
label_13e2a4:
    // 0x13e2a4: 0xae0a0000  sw          $t2, 0x0($s0)
    ctx->pc = 0x13e2a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 10));
label_13e2a8:
    // 0x13e2a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13e2a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e2ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e2acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e2b0: 0x3e00008  jr          $ra
    ctx->pc = 0x13E2B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E2B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E2B0u;
            // 0x13e2b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DFA8u: goto label_13dfa8;
            case 0x13DFC8u: goto label_13dfc8;
            case 0x13DFD8u: goto label_13dfd8;
            case 0x13DFF4u: goto label_13dff4;
            case 0x13E040u: goto label_13e040;
            case 0x13E08Cu: goto label_13e08c;
            case 0x13E0C4u: goto label_13e0c4;
            case 0x13E0FCu: goto label_13e0fc;
            case 0x13E138u: goto label_13e138;
            case 0x13E170u: goto label_13e170;
            case 0x13E1B8u: goto label_13e1b8;
            case 0x13E1F0u: goto label_13e1f0;
            case 0x13E234u: goto label_13e234;
            case 0x13E24Cu: goto label_13e24c;
            case 0x13E288u: goto label_13e288;
            case 0x13E294u: goto label_13e294;
            case 0x13E2A4u: goto label_13e2a4;
            case 0x13E2A8u: goto label_13e2a8;
            case 0x13E30Cu: goto label_13e30c;
            case 0x13E314u: goto label_13e314;
            case 0x13E31Cu: goto label_13e31c;
            case 0x13E324u: goto label_13e324;
            case 0x13E32Cu: goto label_13e32c;
            case 0x13E33Cu: goto label_13e33c;
            case 0x13E364u: goto label_13e364;
            case 0x13E37Cu: goto label_13e37c;
            case 0x13E380u: goto label_13e380;
            case 0x13E3A0u: goto label_13e3a0;
            case 0x13E3B8u: goto label_13e3b8;
            case 0x13E3E8u: goto label_13e3e8;
            case 0x13E3FCu: goto label_13e3fc;
            case 0x13E400u: goto label_13e400;
            case 0x13E420u: goto label_13e420;
            case 0x13E43Cu: goto label_13e43c;
            case 0x13E454u: goto label_13e454;
            case 0x13E48Cu: goto label_13e48c;
            case 0x13E4A4u: goto label_13e4a4;
            case 0x13E4A8u: goto label_13e4a8;
            case 0x13E4C8u: goto label_13e4c8;
            case 0x13E4D8u: goto label_13e4d8;
            case 0x13E4E0u: goto label_13e4e0;
            case 0x13E4E8u: goto label_13e4e8;
            case 0x13E528u: goto label_13e528;
            case 0x13E52Cu: goto label_13e52c;
            case 0x13E58Cu: goto label_13e58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E2B8u;
    // 0x13e2b8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x13e2b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x13e2bc: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13e2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13e2c0: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x13e2c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x13e2c4: 0x3c170022  lui         $s7, 0x22
    ctx->pc = 0x13e2c4u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)34 << 16));
    // 0x13e2c8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13e2c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13e2cc: 0x24420490  addiu       $v0, $v0, 0x490
    ctx->pc = 0x13e2ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1168));
    // 0x13e2d0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13e2d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13e2d4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x13e2d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x13e2d8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x13e2d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x13e2dc: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x13e2dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x13e2e0: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x13e2e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x13e2e4: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x13e2e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x13e2e8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x13e2e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x13e2ec: 0x8ee3146c  lw          $v1, 0x146C($s7)
    ctx->pc = 0x13e2ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 5228)));
    // 0x13e2f0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x13e2f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13e2f4: 0x5460008d  bnel        $v1, $zero, . + 4 + (0x8D << 2)
    ctx->pc = 0x13E2F4u;
    {
        const bool branch_taken_0x13e2f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x13e2f4) {
            ctx->pc = 0x13E2F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13E2F4u;
            // 0x13e2f8: 0x26e3146c  addiu       $v1, $s7, 0x146C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), 5228));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13E52Cu;
            goto label_13e52c;
        }
    }
    ctx->pc = 0x13E2FCu;
    // 0x13e2fc: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13e2fcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13e300: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x13e300u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x13e304: 0xc0503a2  jal         func_140E88
    ctx->pc = 0x13E304u;
    SET_GPR_U32(ctx, 31, 0x13E30Cu);
    ctx->pc = 0x13E308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E304u;
            // 0x13e308: 0x26103e88  addiu       $s0, $s0, 0x3E88 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16008));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140E88u;
    if (runtime->hasFunction(0x140E88u)) {
        auto targetFn = runtime->lookupFunction(0x140E88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E30Cu; }
        if (ctx->pc != 0x13E30Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140E88_0x140e88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E30Cu; }
        if (ctx->pc != 0x13E30Cu) { return; }
    }
    ctx->pc = 0x13E30Cu;
label_13e30c:
    // 0x13e30c: 0xc0504a0  jal         func_141280
    ctx->pc = 0x13E30Cu;
    SET_GPR_U32(ctx, 31, 0x13E314u);
    ctx->pc = 0x13E310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E30Cu;
            // 0x13e310: 0x26711474  addiu       $s1, $s3, 0x1474 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), 5236));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141280u;
    if (runtime->hasFunction(0x141280u)) {
        auto targetFn = runtime->lookupFunction(0x141280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E314u; }
        if (ctx->pc != 0x13E314u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141280_0x141280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E314u; }
        if (ctx->pc != 0x13E314u) { return; }
    }
    ctx->pc = 0x13E314u;
label_13e314:
    // 0x13e314: 0xc04e4be  jal         func_1392F8
    ctx->pc = 0x13E314u;
    SET_GPR_U32(ctx, 31, 0x13E31Cu);
    ctx->pc = 0x13E318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E314u;
            // 0x13e318: 0x3c140022  lui         $s4, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1392F8u;
    if (runtime->hasFunction(0x1392F8u)) {
        auto targetFn = runtime->lookupFunction(0x1392F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E31Cu; }
        if (ctx->pc != 0x13E31Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001392F8_0x1392f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E31Cu; }
        if (ctx->pc != 0x13E31Cu) { return; }
    }
    ctx->pc = 0x13E31Cu;
label_13e31c:
    // 0x13e31c: 0xc04f966  jal         func_13E598
    ctx->pc = 0x13E31Cu;
    SET_GPR_U32(ctx, 31, 0x13E324u);
    ctx->pc = 0x13E320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E31Cu;
            // 0x13e320: 0x3c120022  lui         $s2, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E598u;
    if (runtime->hasFunction(0x13E598u)) {
        auto targetFn = runtime->lookupFunction(0x13E598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E324u; }
        if (ctx->pc != 0x13E324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013E598_0x13e598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E324u; }
        if (ctx->pc != 0x13E324u) { return; }
    }
    ctx->pc = 0x13E324u;
label_13e324:
    // 0x13e324: 0xc04f6d2  jal         func_13DB48
    ctx->pc = 0x13E324u;
    SET_GPR_U32(ctx, 31, 0x13E32Cu);
    ctx->pc = 0x13DB48u;
    if (runtime->hasFunction(0x13DB48u)) {
        auto targetFn = runtime->lookupFunction(0x13DB48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E32Cu; }
        if (ctx->pc != 0x13E32Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013DB48_0x13db48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E32Cu; }
        if (ctx->pc != 0x13E32Cu) { return; }
    }
    ctx->pc = 0x13E32Cu;
label_13e32c:
    // 0x13e32c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13e32cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e330: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13e330u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e334: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13E334u;
    SET_GPR_U32(ctx, 31, 0x13E33Cu);
    ctx->pc = 0x13E338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E334u;
            // 0x13e338: 0x240608d0  addiu       $a2, $zero, 0x8D0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E33Cu; }
        if (ctx->pc != 0x13E33Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E33Cu; }
        if (ctx->pc != 0x13E33Cu) { return; }
    }
    ctx->pc = 0x13E33Cu;
label_13e33c:
    // 0x13e33c: 0x24040880  addiu       $a0, $zero, 0x880
    ctx->pc = 0x13e33cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2176));
    // 0x13e340: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x13e340u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13e344: 0x26100040  addiu       $s0, $s0, 0x40
    ctx->pc = 0x13e344u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x13e348: 0x2402ffc0  addiu       $v0, $zero, -0x40
    ctx->pc = 0x13e348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x13e34c: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x13e34cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x13e350: 0xae843e84  sw          $a0, 0x3E84($s4)
    ctx->pc = 0x13e350u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 16004), GPR_U32(ctx, 4));
    // 0x13e354: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x13E354u;
    {
        const bool branch_taken_0x13e354 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E354u;
            // 0x13e358: 0xae501470  sw          $s0, 0x1470($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 5232), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e354) {
            ctx->pc = 0x13E3A0u;
            goto label_13e3a0;
        }
    }
    ctx->pc = 0x13E35Cu;
    // 0x13e35c: 0xc046e2c  jal         func_11B8B0
    ctx->pc = 0x13E35Cu;
    SET_GPR_U32(ctx, 31, 0x13E364u);
    ctx->pc = 0x13E360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E35Cu;
            // 0x13e360: 0x240408d0  addiu       $a0, $zero, 0x8D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B8B0u;
    if (runtime->hasFunction(0x11B8B0u)) {
        auto targetFn = runtime->lookupFunction(0x11B8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E364u; }
        if (ctx->pc != 0x13E364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B8B0_0x11b8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E364u; }
        if (ctx->pc != 0x13E364u) { return; }
    }
    ctx->pc = 0x13E364u;
label_13e364:
    // 0x13e364: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x13E364u;
    {
        const bool branch_taken_0x13e364 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E364u;
            // 0x13e368: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e364) {
            ctx->pc = 0x13E3A0u;
            goto label_13e3a0;
        }
    }
    ctx->pc = 0x13E36Cu;
    // 0x13e36c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13e36cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13e370: 0x240508d0  addiu       $a1, $zero, 0x8D0
    ctx->pc = 0x13e370u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2256));
    // 0x13e374: 0xc045a12  jal         func_116848
    ctx->pc = 0x13E374u;
    SET_GPR_U32(ctx, 31, 0x13E37Cu);
    ctx->pc = 0x13E378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E374u;
            // 0x13e378: 0x2484d700  addiu       $a0, $a0, -0x2900 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956800));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E37Cu; }
        if (ctx->pc != 0x13E37Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E37Cu; }
        if (ctx->pc != 0x13E37Cu) { return; }
    }
    ctx->pc = 0x13E37Cu;
label_13e37c:
    // 0x13e37c: 0x0  nop
    ctx->pc = 0x13e37cu;
    // NOP
label_13e380:
    // 0x13e380: 0x0  nop
    ctx->pc = 0x13e380u;
    // NOP
    // 0x13e384: 0x0  nop
    ctx->pc = 0x13e384u;
    // NOP
    // 0x13e388: 0x0  nop
    ctx->pc = 0x13e388u;
    // NOP
    // 0x13e38c: 0x0  nop
    ctx->pc = 0x13e38cu;
    // NOP
    // 0x13e390: 0x0  nop
    ctx->pc = 0x13e390u;
    // NOP
    // 0x13e394: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13E394u;
    {
        const bool branch_taken_0x13e394 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13e394) {
            ctx->pc = 0x13E380u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e380;
        }
    }
    ctx->pc = 0x13E39Cu;
    // 0x13e39c: 0x0  nop
    ctx->pc = 0x13e39cu;
    // NOP
label_13e3a0:
    // 0x13e3a0: 0x26701474  addiu       $s0, $s3, 0x1474
    ctx->pc = 0x13e3a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 5236));
    // 0x13e3a4: 0x3c160024  lui         $s6, 0x24
    ctx->pc = 0x13e3a4u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)36 << 16));
    // 0x13e3a8: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x13e3a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e3ac: 0x26c4d5c8  addiu       $a0, $s6, -0x2A38
    ctx->pc = 0x13e3acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294956488));
    // 0x13e3b0: 0xc045a12  jal         func_116848
    ctx->pc = 0x13E3B0u;
    SET_GPR_U32(ctx, 31, 0x13E3B8u);
    ctx->pc = 0x13E3B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E3B0u;
            // 0x13e3b4: 0x240508d0  addiu       $a1, $zero, 0x8D0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E3B8u; }
        if (ctx->pc != 0x13E3B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E3B8u; }
        if (ctx->pc != 0x13E3B8u) { return; }
    }
    ctx->pc = 0x13E3B8u;
label_13e3b8:
    // 0x13e3b8: 0x3c080022  lui         $t0, 0x22
    ctx->pc = 0x13e3b8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)34 << 16));
    // 0x13e3bc: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13e3bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e3c0: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13e3c0u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13e3c4: 0x2403ffc0  addiu       $v1, $zero, -0x40
    ctx->pc = 0x13e3c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x13e3c8: 0x8e451470  lw          $a1, 0x1470($s2)
    ctx->pc = 0x13e3c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 5232)));
    // 0x13e3cc: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x13e3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x13e3d0: 0x8e873e84  lw          $a3, 0x3E84($s4)
    ctx->pc = 0x13e3d0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 16004)));
    // 0x13e3d4: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x13e3d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x13e3d8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x13e3d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e3dc: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x13e3dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e3e0: 0xc04e3de  jal         func_138F78
    ctx->pc = 0x13E3E0u;
    SET_GPR_U32(ctx, 31, 0x13E3E8u);
    ctx->pc = 0x13E3E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E3E0u;
            // 0x13e3e4: 0xad021478  sw          $v0, 0x1478($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 5240), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138F78u;
    if (runtime->hasFunction(0x138F78u)) {
        auto targetFn = runtime->lookupFunction(0x138F78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E3E8u; }
        if (ctx->pc != 0x13E3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138F78_0x138f78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E3E8u; }
        if (ctx->pc != 0x13E3E8u) { return; }
    }
    ctx->pc = 0x13E3E8u;
label_13e3e8:
    // 0x13e3e8: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13E3E8u;
    {
        const bool branch_taken_0x13e3e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E3ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E3E8u;
            // 0x13e3ec: 0xae023e80  sw          $v0, 0x3E80($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16000), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e3e8) {
            ctx->pc = 0x13E420u;
            goto label_13e420;
        }
    }
    ctx->pc = 0x13E3F0u;
    // 0x13e3f0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13e3f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13e3f4: 0xc045a12  jal         func_116848
    ctx->pc = 0x13E3F4u;
    SET_GPR_U32(ctx, 31, 0x13E3FCu);
    ctx->pc = 0x13E3F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E3F4u;
            // 0x13e3f8: 0x2484d748  addiu       $a0, $a0, -0x28B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956872));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E3FCu; }
        if (ctx->pc != 0x13E3FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E3FCu; }
        if (ctx->pc != 0x13E3FCu) { return; }
    }
    ctx->pc = 0x13E3FCu;
label_13e3fc:
    // 0x13e3fc: 0x0  nop
    ctx->pc = 0x13e3fcu;
    // NOP
label_13e400:
    // 0x13e400: 0x0  nop
    ctx->pc = 0x13e400u;
    // NOP
    // 0x13e404: 0x0  nop
    ctx->pc = 0x13e404u;
    // NOP
    // 0x13e408: 0x0  nop
    ctx->pc = 0x13e408u;
    // NOP
    // 0x13e40c: 0x0  nop
    ctx->pc = 0x13e40cu;
    // NOP
    // 0x13e410: 0x0  nop
    ctx->pc = 0x13e410u;
    // NOP
    // 0x13e414: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13E414u;
    {
        const bool branch_taken_0x13e414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13e414) {
            ctx->pc = 0x13E400u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e400;
        }
    }
    ctx->pc = 0x13E41Cu;
    // 0x13e41c: 0x0  nop
    ctx->pc = 0x13e41cu;
    // NOP
label_13e420:
    // 0x13e420: 0x26103e80  addiu       $s0, $s0, 0x3E80
    ctx->pc = 0x13e420u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16000));
    // 0x13e424: 0x3c050014  lui         $a1, 0x14
    ctx->pc = 0x13e424u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20 << 16));
    // 0x13e428: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x13e428u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e42c: 0x24a5dfa0  addiu       $a1, $a1, -0x2060
    ctx->pc = 0x13e42cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959008));
    // 0x13e430: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13e430u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e434: 0xc04e45e  jal         func_139178
    ctx->pc = 0x13E434u;
    SET_GPR_U32(ctx, 31, 0x13E43Cu);
    ctx->pc = 0x13E438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E434u;
            // 0x13e438: 0x3c110022  lui         $s1, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139178u;
    if (runtime->hasFunction(0x139178u)) {
        auto targetFn = runtime->lookupFunction(0x139178u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E43Cu; }
        if (ctx->pc != 0x13E43Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139178_0x139178(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E43Cu; }
        if (ctx->pc != 0x13E43Cu) { return; }
    }
    ctx->pc = 0x13E43Cu;
label_13e43c:
    // 0x13e43c: 0x3c050014  lui         $a1, 0x14
    ctx->pc = 0x13e43cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20 << 16));
    // 0x13e440: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x13e440u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e444: 0x24a5e000  addiu       $a1, $a1, -0x2000
    ctx->pc = 0x13e444u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959104));
    // 0x13e448: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13e448u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e44c: 0xc04e462  jal         func_139188
    ctx->pc = 0x13E44Cu;
    SET_GPR_U32(ctx, 31, 0x13E454u);
    ctx->pc = 0x13E450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E44Cu;
            // 0x13e450: 0x26341454  addiu       $s4, $s1, 0x1454 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 5204));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139188u;
    if (runtime->hasFunction(0x139188u)) {
        auto targetFn = runtime->lookupFunction(0x139188u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E454u; }
        if (ctx->pc != 0x13E454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139188_0x139188(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E454u; }
        if (ctx->pc != 0x13E454u) { return; }
    }
    ctx->pc = 0x13E454u;
label_13e454:
    // 0x13e454: 0x8e820000  lw          $v0, 0x0($s4)
    ctx->pc = 0x13e454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x13e458: 0x14400021  bnez        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x13E458u;
    {
        const bool branch_taken_0x13e458 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E45Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E458u;
            // 0x13e45c: 0x3c130022  lui         $s3, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e458) {
            ctx->pc = 0x13E4E0u;
            goto label_13e4e0;
        }
    }
    ctx->pc = 0x13E460u;
    // 0x13e460: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13e460u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13e464: 0x3c150022  lui         $s5, 0x22
    ctx->pc = 0x13e464u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)34 << 16));
    // 0x13e468: 0x8c431438  lw          $v1, 0x1438($v0)
    ctx->pc = 0x13e468u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 5176)));
    // 0x13e46c: 0x26b01450  addiu       $s0, $s5, 0x1450
    ctx->pc = 0x13e46cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 5200));
    // 0x13e470: 0x2a0902d  daddu       $s2, $s5, $zero
    ctx->pc = 0x13e470u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e474: 0x31280  sll         $v0, $v1, 10
    ctx->pc = 0x13e474u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 10));
    // 0x13e478: 0xae63145c  sw          $v1, 0x145C($s3)
    ctx->pc = 0x13e478u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 5212), GPR_U32(ctx, 3));
    // 0x13e47c: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x13e47cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x13e480: 0x0  nop
    ctx->pc = 0x13e480u;
    // NOP
    // 0x13e484: 0xc046e2c  jal         func_11B8B0
    ctx->pc = 0x13E484u;
    SET_GPR_U32(ctx, 31, 0x13E48Cu);
    ctx->pc = 0x13E488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E484u;
            // 0x13e488: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B8B0u;
    if (runtime->hasFunction(0x11B8B0u)) {
        auto targetFn = runtime->lookupFunction(0x11B8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E48Cu; }
        if (ctx->pc != 0x13E48Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B8B0_0x11b8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E48Cu; }
        if (ctx->pc != 0x13E48Cu) { return; }
    }
    ctx->pc = 0x13E48Cu;
label_13e48c:
    // 0x13e48c: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x13E48Cu;
    {
        const bool branch_taken_0x13e48c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E48Cu;
            // 0x13e490: 0xae820000  sw          $v0, 0x0($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e48c) {
            ctx->pc = 0x13E4C8u;
            goto label_13e4c8;
        }
    }
    ctx->pc = 0x13E494u;
    // 0x13e494: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13e494u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13e498: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x13e498u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e49c: 0xc045a12  jal         func_116848
    ctx->pc = 0x13E49Cu;
    SET_GPR_U32(ctx, 31, 0x13E4A4u);
    ctx->pc = 0x13E4A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E49Cu;
            // 0x13e4a0: 0x2484d770  addiu       $a0, $a0, -0x2890 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956912));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E4A4u; }
        if (ctx->pc != 0x13E4A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E4A4u; }
        if (ctx->pc != 0x13E4A4u) { return; }
    }
    ctx->pc = 0x13E4A4u;
label_13e4a4:
    // 0x13e4a4: 0x0  nop
    ctx->pc = 0x13e4a4u;
    // NOP
label_13e4a8:
    // 0x13e4a8: 0x0  nop
    ctx->pc = 0x13e4a8u;
    // NOP
    // 0x13e4ac: 0x0  nop
    ctx->pc = 0x13e4acu;
    // NOP
    // 0x13e4b0: 0x0  nop
    ctx->pc = 0x13e4b0u;
    // NOP
    // 0x13e4b4: 0x0  nop
    ctx->pc = 0x13e4b4u;
    // NOP
    // 0x13e4b8: 0x0  nop
    ctx->pc = 0x13e4b8u;
    // NOP
    // 0x13e4bc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13E4BCu;
    {
        const bool branch_taken_0x13e4bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13e4bc) {
            ctx->pc = 0x13E4A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13e4a8;
        }
    }
    ctx->pc = 0x13E4C4u;
    // 0x13e4c4: 0x0  nop
    ctx->pc = 0x13e4c4u;
    // NOP
label_13e4c8:
    // 0x13e4c8: 0x8e451450  lw          $a1, 0x1450($s2)
    ctx->pc = 0x13e4c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 5200)));
    // 0x13e4cc: 0x26c4d5c8  addiu       $a0, $s6, -0x2A38
    ctx->pc = 0x13e4ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294956488));
    // 0x13e4d0: 0xc045a12  jal         func_116848
    ctx->pc = 0x13E4D0u;
    SET_GPR_U32(ctx, 31, 0x13E4D8u);
    ctx->pc = 0x13E4D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E4D0u;
            // 0x13e4d4: 0x8e261454  lw          $a2, 0x1454($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 5204)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E4D8u; }
        if (ctx->pc != 0x13E4D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E4D8u; }
        if (ctx->pc != 0x13E4D8u) { return; }
    }
    ctx->pc = 0x13E4D8u;
label_13e4d8:
    // 0x13e4d8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x13E4D8u;
    {
        const bool branch_taken_0x13e4d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E4DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E4D8u;
            // 0x13e4dc: 0x8e221454  lw          $v0, 0x1454($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 5204)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e4d8) {
            ctx->pc = 0x13E4E8u;
            goto label_13e4e8;
        }
    }
    ctx->pc = 0x13E4E0u;
label_13e4e0:
    // 0x13e4e0: 0x3c150022  lui         $s5, 0x22
    ctx->pc = 0x13e4e0u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)34 << 16));
    // 0x13e4e4: 0x8e221454  lw          $v0, 0x1454($s1)
    ctx->pc = 0x13e4e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 5204)));
label_13e4e8:
    // 0x13e4e8: 0x2403ffc0  addiu       $v1, $zero, -0x40
    ctx->pc = 0x13e4e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x13e4ec: 0x8e65145c  lw          $a1, 0x145C($s3)
    ctx->pc = 0x13e4ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 5212)));
    // 0x13e4f0: 0x3c090022  lui         $t1, 0x22
    ctx->pc = 0x13e4f0u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)34 << 16));
    // 0x13e4f4: 0x2442003f  addiu       $v0, $v0, 0x3F
    ctx->pc = 0x13e4f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x13e4f8: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x13e4f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x13e4fc: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x13e4fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x13e500: 0x8ea31450  lw          $v1, 0x1450($s5)
    ctx->pc = 0x13e500u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 5200)));
    // 0x13e504: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x13e504u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x13e508: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13e508u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e50c: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x13e50cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x13e510: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e510u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e514: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x13e514u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e518: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x13e518u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x13e51c: 0xad221458  sw          $v0, 0x1458($t1)
    ctx->pc = 0x13e51cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 5208), GPR_U32(ctx, 2));
    // 0x13e520: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E520u;
    SET_GPR_U32(ctx, 31, 0x13E528u);
    ctx->pc = 0x13E524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E520u;
            // 0x13e524: 0xafa30008  sw          $v1, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E528u; }
        if (ctx->pc != 0x13E528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E528u; }
        if (ctx->pc != 0x13E528u) { return; }
    }
    ctx->pc = 0x13E528u;
label_13e528:
    // 0x13e528: 0x26e3146c  addiu       $v1, $s7, 0x146C
    ctx->pc = 0x13e528u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), 5228));
label_13e52c:
    // 0x13e52c: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x13e52cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x13e530: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x13e530u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13e534: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13e534u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e538: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13e538u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13e53c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x13e53cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x13e540: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x13e540u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13e544: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x13e544u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13e548: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x13e548u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13e54c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x13e54cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13e550: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x13e550u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x13e554: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x13e554u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x13e558: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x13e558u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x13e55c: 0x3e00008  jr          $ra
    ctx->pc = 0x13E55Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E55Cu;
            // 0x13e560: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DFA8u: goto label_13dfa8;
            case 0x13DFC8u: goto label_13dfc8;
            case 0x13DFD8u: goto label_13dfd8;
            case 0x13DFF4u: goto label_13dff4;
            case 0x13E040u: goto label_13e040;
            case 0x13E08Cu: goto label_13e08c;
            case 0x13E0C4u: goto label_13e0c4;
            case 0x13E0FCu: goto label_13e0fc;
            case 0x13E138u: goto label_13e138;
            case 0x13E170u: goto label_13e170;
            case 0x13E1B8u: goto label_13e1b8;
            case 0x13E1F0u: goto label_13e1f0;
            case 0x13E234u: goto label_13e234;
            case 0x13E24Cu: goto label_13e24c;
            case 0x13E288u: goto label_13e288;
            case 0x13E294u: goto label_13e294;
            case 0x13E2A4u: goto label_13e2a4;
            case 0x13E2A8u: goto label_13e2a8;
            case 0x13E30Cu: goto label_13e30c;
            case 0x13E314u: goto label_13e314;
            case 0x13E31Cu: goto label_13e31c;
            case 0x13E324u: goto label_13e324;
            case 0x13E32Cu: goto label_13e32c;
            case 0x13E33Cu: goto label_13e33c;
            case 0x13E364u: goto label_13e364;
            case 0x13E37Cu: goto label_13e37c;
            case 0x13E380u: goto label_13e380;
            case 0x13E3A0u: goto label_13e3a0;
            case 0x13E3B8u: goto label_13e3b8;
            case 0x13E3E8u: goto label_13e3e8;
            case 0x13E3FCu: goto label_13e3fc;
            case 0x13E400u: goto label_13e400;
            case 0x13E420u: goto label_13e420;
            case 0x13E43Cu: goto label_13e43c;
            case 0x13E454u: goto label_13e454;
            case 0x13E48Cu: goto label_13e48c;
            case 0x13E4A4u: goto label_13e4a4;
            case 0x13E4A8u: goto label_13e4a8;
            case 0x13E4C8u: goto label_13e4c8;
            case 0x13E4D8u: goto label_13e4d8;
            case 0x13E4E0u: goto label_13e4e0;
            case 0x13E4E8u: goto label_13e4e8;
            case 0x13E528u: goto label_13e528;
            case 0x13E52Cu: goto label_13e52c;
            case 0x13E58Cu: goto label_13e58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E564u;
    // 0x13e564: 0x0  nop
    ctx->pc = 0x13e564u;
    // NOP
    // 0x13e568: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13e568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13e56c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x13e56cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e570: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x13e570u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x13e574: 0x2404000b  addiu       $a0, $zero, 0xB
    ctx->pc = 0x13e574u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x13e578: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13e578u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e57c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e57cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e580: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13e580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13e584: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E584u;
    SET_GPR_U32(ctx, 31, 0x13E58Cu);
    ctx->pc = 0x13E588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E584u;
            // 0x13e588: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E58Cu; }
        if (ctx->pc != 0x13E58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E58Cu; }
        if (ctx->pc != 0x13E58Cu) { return; }
    }
    ctx->pc = 0x13E58Cu;
label_13e58c:
    // 0x13e58c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13e58cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e590: 0x3e00008  jr          $ra
    ctx->pc = 0x13E590u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E590u;
            // 0x13e594: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13DFA8u: goto label_13dfa8;
            case 0x13DFC8u: goto label_13dfc8;
            case 0x13DFD8u: goto label_13dfd8;
            case 0x13DFF4u: goto label_13dff4;
            case 0x13E040u: goto label_13e040;
            case 0x13E08Cu: goto label_13e08c;
            case 0x13E0C4u: goto label_13e0c4;
            case 0x13E0FCu: goto label_13e0fc;
            case 0x13E138u: goto label_13e138;
            case 0x13E170u: goto label_13e170;
            case 0x13E1B8u: goto label_13e1b8;
            case 0x13E1F0u: goto label_13e1f0;
            case 0x13E234u: goto label_13e234;
            case 0x13E24Cu: goto label_13e24c;
            case 0x13E288u: goto label_13e288;
            case 0x13E294u: goto label_13e294;
            case 0x13E2A4u: goto label_13e2a4;
            case 0x13E2A8u: goto label_13e2a8;
            case 0x13E30Cu: goto label_13e30c;
            case 0x13E314u: goto label_13e314;
            case 0x13E31Cu: goto label_13e31c;
            case 0x13E324u: goto label_13e324;
            case 0x13E32Cu: goto label_13e32c;
            case 0x13E33Cu: goto label_13e33c;
            case 0x13E364u: goto label_13e364;
            case 0x13E37Cu: goto label_13e37c;
            case 0x13E380u: goto label_13e380;
            case 0x13E3A0u: goto label_13e3a0;
            case 0x13E3B8u: goto label_13e3b8;
            case 0x13E3E8u: goto label_13e3e8;
            case 0x13E3FCu: goto label_13e3fc;
            case 0x13E400u: goto label_13e400;
            case 0x13E420u: goto label_13e420;
            case 0x13E43Cu: goto label_13e43c;
            case 0x13E454u: goto label_13e454;
            case 0x13E48Cu: goto label_13e48c;
            case 0x13E4A4u: goto label_13e4a4;
            case 0x13E4A8u: goto label_13e4a8;
            case 0x13E4C8u: goto label_13e4c8;
            case 0x13E4D8u: goto label_13e4d8;
            case 0x13E4E0u: goto label_13e4e0;
            case 0x13E4E8u: goto label_13e4e8;
            case 0x13E528u: goto label_13e528;
            case 0x13E52Cu: goto label_13e52c;
            case 0x13E58Cu: goto label_13e58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E598u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
