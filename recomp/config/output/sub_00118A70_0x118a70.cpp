#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00118A70
// Address: 0x118a70 - 0x118cf8
void sub_00118A70_0x118a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00118A70_0x118a70");
#endif

    switch (ctx->pc) {
        case 0x118accu: goto label_118acc;
        case 0x118ae4u: goto label_118ae4;
        case 0x118aecu: goto label_118aec;
        case 0x118afcu: goto label_118afc;
        case 0x118b10u: goto label_118b10;
        case 0x118b24u: goto label_118b24;
        case 0x118b58u: goto label_118b58;
        case 0x118be0u: goto label_118be0;
        case 0x118c1cu: goto label_118c1c;
        case 0x118c2cu: goto label_118c2c;
        case 0x118c34u: goto label_118c34;
        case 0x118c48u: goto label_118c48;
        case 0x118c58u: goto label_118c58;
        case 0x118c68u: goto label_118c68;
        case 0x118c70u: goto label_118c70;
        case 0x118c84u: goto label_118c84;
        case 0x118c90u: goto label_118c90;
        case 0x118ca4u: goto label_118ca4;
        case 0x118cc0u: goto label_118cc0;
        default: break;
    }

    ctx->pc = 0x118a70u;

    // 0x118a70: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x118a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x118a74: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x118a74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x118a78: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x118a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x118a7c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x118a7cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118a80: 0xffbe00c0  sd          $fp, 0xC0($sp)
    ctx->pc = 0x118a80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 30));
    // 0x118a84: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x118a84u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118a88: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x118a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x118a8c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x118a8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118a90: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x118a90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x118a94: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x118a94u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
    // 0x118a98: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x118a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x118a9c: 0x27d1ca40  addiu       $s1, $fp, -0x35C0
    ctx->pc = 0x118a9cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 30), 4294953536));
    // 0x118aa0: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x118aa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x118aa4: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x118aa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x118aa8: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x118aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x118aac: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x118aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x118ab0: 0xffa60120  sd          $a2, 0x120($sp)
    ctx->pc = 0x118ab0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 6));
    // 0x118ab4: 0xffa70128  sd          $a3, 0x128($sp)
    ctx->pc = 0x118ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 296), GPR_U64(ctx, 7));
    // 0x118ab8: 0xffa80130  sd          $t0, 0x130($sp)
    ctx->pc = 0x118ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 8));
    // 0x118abc: 0xffa90138  sd          $t1, 0x138($sp)
    ctx->pc = 0x118abcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 312), GPR_U64(ctx, 9));
    // 0x118ac0: 0xffaa0140  sd          $t2, 0x140($sp)
    ctx->pc = 0x118ac0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 320), GPR_U64(ctx, 10));
    // 0x118ac4: 0xc04619c  jal         func_118670
    ctx->pc = 0x118AC4u;
    SET_GPR_U32(ctx, 31, 0x118ACCu);
    ctx->pc = 0x118AC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118AC4u;
            // 0x118ac8: 0xffab0148  sd          $t3, 0x148($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 328), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118ACCu; }
        if (ctx->pc != 0x118ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118ACCu; }
        if (ctx->pc != 0x118ACCu) { return; }
    }
    ctx->pc = 0x118ACCu;
label_118acc:
    // 0x118acc: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x118accu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x118ad0: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x118ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x118ad4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x118AD4u;
    {
        const bool branch_taken_0x118ad4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x118ad4) {
            ctx->pc = 0x118AE4u;
            goto label_118ae4;
        }
    }
    ctx->pc = 0x118ADCu;
    // 0x118adc: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x118ADCu;
    SET_GPR_U32(ctx, 31, 0x118AE4u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118AE4u; }
        if (ctx->pc != 0x118AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118AE4u; }
        if (ctx->pc != 0x118AE4u) { return; }
    }
    ctx->pc = 0x118AE4u;
label_118ae4:
    // 0x118ae4: 0xc04626a  jal         func_1189A8
    ctx->pc = 0x118AE4u;
    SET_GPR_U32(ctx, 31, 0x118AECu);
    ctx->pc = 0x1189A8u;
    if (runtime->hasFunction(0x1189A8u)) {
        auto targetFn = runtime->lookupFunction(0x1189A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118AECu; }
        if (ctx->pc != 0x118AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001189A8_0x1189a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118AECu; }
        if (ctx->pc != 0x118AECu) { return; }
    }
    ctx->pc = 0x118AECu;
label_118aec:
    // 0x118aec: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x118AECu;
    {
        const bool branch_taken_0x118aec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x118aec) {
            ctx->pc = 0x118B08u;
            goto label_118b08;
        }
    }
    ctx->pc = 0x118AF4u;
    // 0x118af4: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118AF4u;
    SET_GPR_U32(ctx, 31, 0x118AFCu);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118AFCu; }
        if (ctx->pc != 0x118AFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118AFCu; }
        if (ctx->pc != 0x118AFCu) { return; }
    }
    ctx->pc = 0x118AFCu;
label_118afc:
    // 0x118afc: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x118afcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x118b00: 0x10000070  b           . + 4 + (0x70 << 2)
    ctx->pc = 0x118B00u;
    {
        const bool branch_taken_0x118b00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118B00u;
            // 0x118b04: 0x3442fffc  ori         $v0, $v0, 0xFFFC (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65532);
        ctx->in_delay_slot = false;
        if (branch_taken_0x118b00) {
            ctx->pc = 0x118CC4u;
            goto label_118cc4;
        }
    }
    ctx->pc = 0x118B08u;
label_118b08:
    // 0x118b08: 0xc04605c  jal         func_118170
    ctx->pc = 0x118B08u;
    SET_GPR_U32(ctx, 31, 0x118B10u);
    ctx->pc = 0x118170u;
    if (runtime->hasFunction(0x118170u)) {
        auto targetFn = runtime->lookupFunction(0x118170u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118B10u; }
        if (ctx->pc != 0x118B10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118170_0x118170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118B10u; }
        if (ctx->pc != 0x118B10u) { return; }
    }
    ctx->pc = 0x118B10u;
label_118b10:
    // 0x118b10: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x118b10u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118b14: 0x56600005  bnel        $s3, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x118B14u;
    {
        const bool branch_taken_0x118b14 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x118b14) {
            ctx->pc = 0x118B18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x118B14u;
            // 0x118b18: 0x92030000  lbu         $v1, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x118B2Cu;
            goto label_118b2c;
        }
    }
    ctx->pc = 0x118B1Cu;
    // 0x118b1c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118B1Cu;
    SET_GPR_U32(ctx, 31, 0x118B24u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118B24u; }
        if (ctx->pc != 0x118B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118B24u; }
        if (ctx->pc != 0x118B24u) { return; }
    }
    ctx->pc = 0x118B24u;
label_118b24:
    // 0x118b24: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x118B24u;
    {
        const bool branch_taken_0x118b24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118B24u;
            // 0x118b28: 0x2402ffed  addiu       $v0, $zero, -0x13 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967277));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118b24) {
            ctx->pc = 0x118CC4u;
            goto label_118cc4;
        }
    }
    ctx->pc = 0x118B2Cu;
label_118b2c:
    // 0x118b2c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x118b2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118b30: 0x8fa70120  lw          $a3, 0x120($sp)
    ctx->pc = 0x118b30u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x118b34: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x118b34u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x118b38: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x118B38u;
    {
        const bool branch_taken_0x118b38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x118B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118B38u;
            // 0x118b3c: 0xa2230014  sb          $v1, 0x14($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 20), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118b38) {
            ctx->pc = 0x118B84u;
            goto label_118b84;
        }
    }
    ctx->pc = 0x118B40u;
    // 0x118b40: 0x3c060026  lui         $a2, 0x26
    ctx->pc = 0x118b40u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)38 << 16));
    // 0x118b44: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x118b44u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x118b48: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x118b48u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x118b4c: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x118b4cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x118b50: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x118b50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x118b54: 0x0  nop
    ctx->pc = 0x118b54u;
    // NOP
label_118b58:
    // 0x118b58: 0x28a20400  slti        $v0, $a1, 0x400
    ctx->pc = 0x118b58u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x118b5c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x118B5Cu;
    {
        const bool branch_taken_0x118b5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x118B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118B5Cu;
            // 0x118b60: 0x2051021  addu        $v0, $s0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118b5c) {
            ctx->pc = 0x118B94u;
            goto label_118b94;
        }
    }
    ctx->pc = 0x118B64u;
    // 0x118b64: 0x2252021  addu        $a0, $s1, $a1
    ctx->pc = 0x118b64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x118b68: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x118b68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x118b6c: 0xa0830014  sb          $v1, 0x14($a0)
    ctx->pc = 0x118b6cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 20), (uint8_t)GPR_U32(ctx, 3));
    // 0x118b70: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x118b70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x118b74: 0x5460fff8  bnel        $v1, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x118B74u;
    {
        const bool branch_taken_0x118b74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x118b74) {
            ctx->pc = 0x118B78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x118B74u;
            // 0x118b78: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x118B58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_118b58;
        }
    }
    ctx->pc = 0x118B7Cu;
    // 0x118b7c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x118B7Cu;
    {
        const bool branch_taken_0x118b7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118B7Cu;
            // 0x118b80: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118b7c) {
            ctx->pc = 0x118B98u;
            goto label_118b98;
        }
    }
    ctx->pc = 0x118B84u;
label_118b84:
    // 0x118b84: 0x3c060026  lui         $a2, 0x26
    ctx->pc = 0x118b84u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)38 << 16));
    // 0x118b88: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x118b88u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x118b8c: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x118b8cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x118b90: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x118b90u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
label_118b94:
    // 0x118b94: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x118b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_118b98:
    // 0x118b98: 0x50a20001  beql        $a1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x118B98u;
    {
        const bool branch_taken_0x118b98 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x118b98) {
            ctx->pc = 0x118B9Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x118B98u;
            // 0x118b9c: 0xa2200413  sb          $zero, 0x413($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 1043), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x118BA0u;
            goto label_118ba0;
        }
    }
    ctx->pc = 0x118BA0u;
label_118ba0:
    // 0x118ba0: 0x24c2df40  addiu       $v0, $a2, -0x20C0
    ctx->pc = 0x118ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294958912));
    // 0x118ba4: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x118ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x118ba8: 0x2621023  subu        $v0, $s3, $v0
    ctx->pc = 0x118ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x118bac: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x118bacu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x118bb0: 0x2a903  sra         $s5, $v0, 4
    ctx->pc = 0x118bb0u;
    SET_GPR_S32(ctx, 21, SRA32(GPR_S32(ctx, 2), 4));
    // 0x118bb4: 0x2e31824  and         $v1, $s7, $v1
    ctx->pc = 0x118bb4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 23) & GPR_U64(ctx, 3));
    // 0x118bb8: 0xae23000c  sw          $v1, 0xC($s1)
    ctx->pc = 0x118bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 3));
    // 0x118bbc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x118bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x118bc0: 0xae270010  sw          $a3, 0x10($s1)
    ctx->pc = 0x118bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 7));
    // 0x118bc4: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x118bc4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x118bc8: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x118bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x118bcc: 0x2694d680  addiu       $s4, $s4, -0x2980
    ctx->pc = 0x118bccu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294956672));
    // 0x118bd0: 0xae350414  sw          $s5, 0x414($s1)
    ctx->pc = 0x118bd0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 1044), GPR_U32(ctx, 21));
    // 0x118bd4: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x118bd4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x118bd8: 0xc045188  jal         func_114620
    ctx->pc = 0x118BD8u;
    SET_GPR_U32(ctx, 31, 0x118BE0u);
    ctx->pc = 0x118BDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118BD8u;
            // 0x118bdc: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118BE0u; }
        if (ctx->pc != 0x118BE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118BE0u; }
        if (ctx->pc != 0x118BE0u) { return; }
    }
    ctx->pc = 0x118BE0u;
label_118be0:
    // 0x118be0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x118be0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118be4: 0xae320004  sw          $s2, 0x4($s1)
    ctx->pc = 0x118be4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 18));
    // 0x118be8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x118be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x118bec: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x118becu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x118bf0: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x118bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x118bf4: 0x26c4e140  addiu       $a0, $s6, -0x1EC0
    ctx->pc = 0x118bf4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294959424));
    // 0x118bf8: 0x27c7ca40  addiu       $a3, $fp, -0x35C0
    ctx->pc = 0x118bf8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 4294953536));
    // 0x118bfc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x118bfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118c00: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x118c00u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x118c04: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x118c04u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118c08: 0x24080418  addiu       $t0, $zero, 0x418
    ctx->pc = 0x118c08u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1048));
    // 0x118c0c: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x118c0cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118c10: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x118c10u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x118c14: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x118C14u;
    SET_GPR_U32(ctx, 31, 0x118C1Cu);
    ctx->pc = 0x118C18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C14u;
            // 0x118c18: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C1Cu; }
        if (ctx->pc != 0x118C1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C1Cu; }
        if (ctx->pc != 0x118C1Cu) { return; }
    }
    ctx->pc = 0x118C1Cu;
label_118c1c:
    // 0x118c1c: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x118C1Cu;
    {
        const bool branch_taken_0x118c1c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x118C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118C1Cu;
            // 0x118c20: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118c1c) {
            ctx->pc = 0x118C3Cu;
            goto label_118c3c;
        }
    }
    ctx->pc = 0x118C24u;
    // 0x118c24: 0xc04518c  jal         func_114630
    ctx->pc = 0x118C24u;
    SET_GPR_U32(ctx, 31, 0x118C2Cu);
    ctx->pc = 0x118C28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C24u;
            // 0x118c28: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C2Cu; }
        if (ctx->pc != 0x118C2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C2Cu; }
        if (ctx->pc != 0x118C2Cu) { return; }
    }
    ctx->pc = 0x118C2Cu;
label_118c2c:
    // 0x118c2c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118C2Cu;
    SET_GPR_U32(ctx, 31, 0x118C34u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C34u; }
        if (ctx->pc != 0x118C34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C34u; }
        if (ctx->pc != 0x118C34u) { return; }
    }
    ctx->pc = 0x118C34u;
label_118c34:
    // 0x118c34: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x118C34u;
    {
        const bool branch_taken_0x118c34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118C38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118C34u;
            // 0x118c38: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118c34) {
            ctx->pc = 0x118CC4u;
            goto label_118cc4;
        }
    }
    ctx->pc = 0x118C3Cu;
label_118c3c:
    // 0x118c3c: 0x2821025  or          $v0, $s4, $v0
    ctx->pc = 0x118c3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x118c40: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118C40u;
    SET_GPR_U32(ctx, 31, 0x118C48u);
    ctx->pc = 0x118C44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C40u;
            // 0x118c44: 0x8c510000  lw          $s1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C48u; }
        if (ctx->pc != 0x118C48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C48u; }
        if (ctx->pc != 0x118C48u) { return; }
    }
    ctx->pc = 0x118C48u;
label_118c48:
    // 0x118c48: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x118C48u;
    {
        const bool branch_taken_0x118c48 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x118c48) {
            ctx->pc = 0x118C60u;
            goto label_118c60;
        }
    }
    ctx->pc = 0x118C50u;
    // 0x118c50: 0xc04518c  jal         func_114630
    ctx->pc = 0x118C50u;
    SET_GPR_U32(ctx, 31, 0x118C58u);
    ctx->pc = 0x118C54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C50u;
            // 0x118c54: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C58u; }
        if (ctx->pc != 0x118C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C58u; }
        if (ctx->pc != 0x118C58u) { return; }
    }
    ctx->pc = 0x118C58u;
label_118c58:
    // 0x118c58: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x118C58u;
    {
        const bool branch_taken_0x118c58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118C58u;
            // 0x118c5c: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118c58) {
            ctx->pc = 0x118CC4u;
            goto label_118cc4;
        }
    }
    ctx->pc = 0x118C60u;
label_118c60:
    // 0x118c60: 0xc045198  jal         func_114660
    ctx->pc = 0x118C60u;
    SET_GPR_U32(ctx, 31, 0x118C68u);
    ctx->pc = 0x118C64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C60u;
            // 0x118c64: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C68u; }
        if (ctx->pc != 0x118C68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C68u; }
        if (ctx->pc != 0x118C68u) { return; }
    }
    ctx->pc = 0x118C68u;
label_118c68:
    // 0x118c68: 0xc04518c  jal         func_114630
    ctx->pc = 0x118C68u;
    SET_GPR_U32(ctx, 31, 0x118C70u);
    ctx->pc = 0x118C6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C68u;
            // 0x118c6c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C70u; }
        if (ctx->pc != 0x118C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C70u; }
        if (ctx->pc != 0x118C70u) { return; }
    }
    ctx->pc = 0x118C70u;
label_118c70:
    // 0x118c70: 0x8fa30030  lw          $v1, 0x30($sp)
    ctx->pc = 0x118c70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x118c74: 0x4610008  bgez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x118C74u;
    {
        const bool branch_taken_0x118c74 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x118C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118C74u;
            // 0x118c78: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118c74) {
            ctx->pc = 0x118C98u;
            goto label_118c98;
        }
    }
    ctx->pc = 0x118C7Cu;
    // 0x118c7c: 0xc045198  jal         func_114660
    ctx->pc = 0x118C7Cu;
    SET_GPR_U32(ctx, 31, 0x118C84u);
    ctx->pc = 0x118C80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C7Cu;
            // 0x118c80: 0x8e049de8  lw          $a0, -0x6218($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C84u; }
        if (ctx->pc != 0x118C84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C84u; }
        if (ctx->pc != 0x118C84u) { return; }
    }
    ctx->pc = 0x118C84u;
label_118c84:
    // 0x118c84: 0xae600004  sw          $zero, 0x4($s3)
    ctx->pc = 0x118c84u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 0));
    // 0x118c88: 0xc045190  jal         func_114640
    ctx->pc = 0x118C88u;
    SET_GPR_U32(ctx, 31, 0x118C90u);
    ctx->pc = 0x118C8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C88u;
            // 0x118c8c: 0x8e049de8  lw          $a0, -0x6218($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C90u; }
        if (ctx->pc != 0x118C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118C90u; }
        if (ctx->pc != 0x118C90u) { return; }
    }
    ctx->pc = 0x118C90u;
label_118c90:
    // 0x118c90: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x118C90u;
    {
        const bool branch_taken_0x118c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118C90u;
            // 0x118c94: 0x8fa20030  lw          $v0, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118c90) {
            ctx->pc = 0x118CC4u;
            goto label_118cc4;
        }
    }
    ctx->pc = 0x118C98u;
label_118c98:
    // 0x118c98: 0x2a0882d  daddu       $s1, $s5, $zero
    ctx->pc = 0x118c98u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118c9c: 0xc045198  jal         func_114660
    ctx->pc = 0x118C9Cu;
    SET_GPR_U32(ctx, 31, 0x118CA4u);
    ctx->pc = 0x118CA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118C9Cu;
            // 0x118ca0: 0x8e049de8  lw          $a0, -0x6218($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118CA4u; }
        if (ctx->pc != 0x118CA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118CA4u; }
        if (ctx->pc != 0x118CA4u) { return; }
    }
    ctx->pc = 0x118CA4u;
label_118ca4:
    // 0x118ca4: 0x8e630004  lw          $v1, 0x4($s3)
    ctx->pc = 0x118ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x118ca8: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x118ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x118cac: 0x8e049de8  lw          $a0, -0x6218($s0)
    ctx->pc = 0x118cacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942184)));
    // 0x118cb0: 0x771825  or          $v1, $v1, $s7
    ctx->pc = 0x118cb0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 23));
    // 0x118cb4: 0xae630004  sw          $v1, 0x4($s3)
    ctx->pc = 0x118cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 3));
    // 0x118cb8: 0xc045190  jal         func_114640
    ctx->pc = 0x118CB8u;
    SET_GPR_U32(ctx, 31, 0x118CC0u);
    ctx->pc = 0x118CBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118CB8u;
            // 0x118cbc: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118CC0u; }
        if (ctx->pc != 0x118CC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118CC0u; }
        if (ctx->pc != 0x118CC0u) { return; }
    }
    ctx->pc = 0x118CC0u;
label_118cc0:
    // 0x118cc0: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x118cc0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_118cc4:
    // 0x118cc4: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x118cc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x118cc8: 0xdfbe00c0  ld          $fp, 0xC0($sp)
    ctx->pc = 0x118cc8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x118ccc: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x118cccu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x118cd0: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x118cd0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x118cd4: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x118cd4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x118cd8: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x118cd8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x118cdc: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x118cdcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x118ce0: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x118ce0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x118ce4: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x118ce4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x118ce8: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x118ce8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x118cec: 0x3e00008  jr          $ra
    ctx->pc = 0x118CECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118CECu;
            // 0x118cf0: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118ACCu: goto label_118acc;
            case 0x118AE4u: goto label_118ae4;
            case 0x118AECu: goto label_118aec;
            case 0x118AFCu: goto label_118afc;
            case 0x118B08u: goto label_118b08;
            case 0x118B10u: goto label_118b10;
            case 0x118B24u: goto label_118b24;
            case 0x118B2Cu: goto label_118b2c;
            case 0x118B58u: goto label_118b58;
            case 0x118B84u: goto label_118b84;
            case 0x118B94u: goto label_118b94;
            case 0x118B98u: goto label_118b98;
            case 0x118BA0u: goto label_118ba0;
            case 0x118BE0u: goto label_118be0;
            case 0x118C1Cu: goto label_118c1c;
            case 0x118C2Cu: goto label_118c2c;
            case 0x118C34u: goto label_118c34;
            case 0x118C3Cu: goto label_118c3c;
            case 0x118C48u: goto label_118c48;
            case 0x118C58u: goto label_118c58;
            case 0x118C60u: goto label_118c60;
            case 0x118C68u: goto label_118c68;
            case 0x118C70u: goto label_118c70;
            case 0x118C84u: goto label_118c84;
            case 0x118C90u: goto label_118c90;
            case 0x118C98u: goto label_118c98;
            case 0x118CA4u: goto label_118ca4;
            case 0x118CC0u: goto label_118cc0;
            case 0x118CC4u: goto label_118cc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x118CF4u;
    // 0x118cf4: 0x0  nop
    ctx->pc = 0x118cf4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
