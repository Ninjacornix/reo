#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001469A8
// Address: 0x1469a8 - 0x146c60
void sub_001469A8_0x1469a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001469A8_0x1469a8");
#endif

    switch (ctx->pc) {
        case 0x146a90u: goto label_146a90;
        case 0x146aa0u: goto label_146aa0;
        case 0x146aa8u: goto label_146aa8;
        case 0x146aecu: goto label_146aec;
        case 0x146b00u: goto label_146b00;
        case 0x146b24u: goto label_146b24;
        case 0x146b68u: goto label_146b68;
        case 0x146b78u: goto label_146b78;
        case 0x146ba0u: goto label_146ba0;
        case 0x146c38u: goto label_146c38;
        default: break;
    }

    ctx->pc = 0x1469a8u;

    // 0x1469a8: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1469a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1469ac: 0x3c020fff  lui         $v0, 0xFFF
    ctx->pc = 0x1469acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4095 << 16));
    // 0x1469b0: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x1469b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x1469b4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1469b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1469b8: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1469b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1469bc: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x1469bcu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1469c0: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x1469c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x1469c4: 0xffbf00a0  sd          $ra, 0xA0($sp)
    ctx->pc = 0x1469c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x1469c8: 0xffbe0090  sd          $fp, 0x90($sp)
    ctx->pc = 0x1469c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x1469cc: 0xffb70080  sd          $s7, 0x80($sp)
    ctx->pc = 0x1469ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x1469d0: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x1469d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1469d4: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x1469d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x1469d8: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1469d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1469dc: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1469dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1469e0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1469e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1469e4: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x1469e4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1469e8: 0x8ec30000  lw          $v1, 0x0($s6)
    ctx->pc = 0x1469e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1469ec: 0x8c8400f0  lw          $a0, 0xF0($a0)
    ctx->pc = 0x1469ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 240)));
    // 0x1469f0: 0x8cc5018c  lw          $a1, 0x18C($a2)
    ctx->pc = 0x1469f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 396)));
    // 0x1469f4: 0x629024  and         $s2, $v1, $v0
    ctx->pc = 0x1469f4u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1469f8: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x1469f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1469fc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1469fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x146a00: 0x10a30006  beq         $a1, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x146A00u;
    {
        const bool branch_taken_0x146a00 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x146A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146A00u;
            // 0x146a04: 0xafa40008  sw          $a0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146a00) {
            ctx->pc = 0x146A1Cu;
            goto label_146a1c;
        }
    }
    ctx->pc = 0x146A08u;
    // 0x146a08: 0x8cc400f8  lw          $a0, 0xF8($a2)
    ctx->pc = 0x146a08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 248)));
    // 0x146a0c: 0x14800011  bnez        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x146A0Cu;
    {
        const bool branch_taken_0x146a0c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x146A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146A0Cu;
            // 0x146a10: 0x80182d  daddu       $v1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146a0c) {
            ctx->pc = 0x146A54u;
            goto label_146a54;
        }
    }
    ctx->pc = 0x146A14u;
    // 0x146a14: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x146A14u;
    {
        const bool branch_taken_0x146a14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146A14u;
            // 0x146a18: 0x8ec20010  lw          $v0, 0x10($s6) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146a14) {
            ctx->pc = 0x146A28u;
            goto label_146a28;
        }
    }
    ctx->pc = 0x146A1Cu;
label_146a1c:
    // 0x146a1c: 0x8fa70000  lw          $a3, 0x0($sp)
    ctx->pc = 0x146a1cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146a20: 0x8ce300f8  lw          $v1, 0xF8($a3)
    ctx->pc = 0x146a20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 248)));
    // 0x146a24: 0x8ec20010  lw          $v0, 0x10($s6)
    ctx->pc = 0x146a24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 16)));
label_146a28:
    // 0x146a28: 0x24040180  addiu       $a0, $zero, 0x180
    ctx->pc = 0x146a28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
    // 0x146a2c: 0x44a818  mult        $s5, $v0, $a0
    ctx->pc = 0x146a2cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 21, (int32_t)result); }
    // 0x146a30: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x146A30u;
    {
        const bool branch_taken_0x146a30 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x146A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146A30u;
            // 0x146a34: 0x15a103  sra         $s4, $s5, 4 (Delay Slot)
        SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 21), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146a30) {
            ctx->pc = 0x146A44u;
            goto label_146a44;
        }
    }
    ctx->pc = 0x146A38u;
    // 0x146a38: 0x31103  sra         $v0, $v1, 4
    ctx->pc = 0x146a38u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 4));
    // 0x146a3c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x146A3Cu;
    {
        const bool branch_taken_0x146a3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146A3Cu;
            // 0x146a40: 0x44f018  mult        $fp, $v0, $a0 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 30, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x146a3c) {
            ctx->pc = 0x146A48u;
            goto label_146a48;
        }
    }
    ctx->pc = 0x146A44u;
label_146a44:
    // 0x146a44: 0x2a0f02d  daddu       $fp, $s5, $zero
    ctx->pc = 0x146a44u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_146a48:
    // 0x146a48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x146a48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146a4c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x146A4Cu;
    {
        const bool branch_taken_0x146a4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146A4Cu;
            // 0x146a50: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146a4c) {
            ctx->pc = 0x146A7Cu;
            goto label_146a7c;
        }
    }
    ctx->pc = 0x146A54u;
label_146a54:
    // 0x146a54: 0x8ec20010  lw          $v0, 0x10($s6)
    ctx->pc = 0x146a54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 16)));
    // 0x146a58: 0x24050180  addiu       $a1, $zero, 0x180
    ctx->pc = 0x146a58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
    // 0x146a5c: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x146a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x146a60: 0x42103  sra         $a0, $a0, 4
    ctx->pc = 0x146a60u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x146a64: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x146a64u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x146a68: 0x83f018  mult        $fp, $a0, $v1
    ctx->pc = 0x146a68u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 30, (int32_t)result); }
    // 0x146a6c: 0x7045a818  mult1       $s5, $v0, $a1
    ctx->pc = 0x146a6cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 5); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 21, (int32_t)result); }
    // 0x146a70: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x146a70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x146a74: 0xafa30004  sw          $v1, 0x4($sp)
    ctx->pc = 0x146a74u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x146a78: 0x15a103  sra         $s4, $s5, 4
    ctx->pc = 0x146a78u;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 21), 4));
label_146a7c:
    // 0x146a7c: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x146a7cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x146a80: 0x10c00061  beqz        $a2, . + 4 + (0x61 << 2)
    ctx->pc = 0x146A80u;
    {
        const bool branch_taken_0x146a80 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x146A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146A80u;
            // 0x146a84: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146a80) {
            ctx->pc = 0x146C08u;
            goto label_146c08;
        }
    }
    ctx->pc = 0x146A88u;
    // 0x146a88: 0x8ec6000c  lw          $a2, 0xC($s6)
    ctx->pc = 0x146a88u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x146a8c: 0x0  nop
    ctx->pc = 0x146a8cu;
    // NOP
label_146a90:
    // 0x146a90: 0x8fb10008  lw          $s1, 0x8($sp)
    ctx->pc = 0x146a90u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x146a94: 0x18c0004f  blez        $a2, . + 4 + (0x4F << 2)
    ctx->pc = 0x146A94u;
    {
        const bool branch_taken_0x146a94 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x146A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146A94u;
            // 0x146a98: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146a94) {
            ctx->pc = 0x146BD4u;
            goto label_146bd4;
        }
    }
    ctx->pc = 0x146A9Cu;
    // 0x146a9c: 0x24b70001  addiu       $s7, $a1, 0x1
    ctx->pc = 0x146a9cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_146aa0:
    // 0x146aa0: 0xc047598  jal         func_11D660
    ctx->pc = 0x146AA0u;
    SET_GPR_U32(ctx, 31, 0x146AA8u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146AA8u; }
        if (ctx->pc != 0x146AA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146AA8u; }
        if (ctx->pc != 0x146AA8u) { return; }
    }
    ctx->pc = 0x146AA8u;
label_146aa8:
    // 0x146aa8: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x146aa8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x146aac: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x146aacu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x146ab0: 0x3463d480  ori         $v1, $v1, 0xD480
    ctx->pc = 0x146ab0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)54400);
    // 0x146ab4: 0x34a5d410  ori         $a1, $a1, 0xD410
    ctx->pc = 0x146ab4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)54288);
    // 0x146ab8: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x146ab8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x146abc: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x146abcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x146ac0: 0xacb20000  sw          $s2, 0x0($a1)
    ctx->pc = 0x146ac0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 18)); // MMIO: 0x10000000
    // 0x146ac4: 0x3484d420  ori         $a0, $a0, 0xD420
    ctx->pc = 0x146ac4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)54304);
    // 0x146ac8: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x146ac8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x146acc: 0xac940000  sw          $s4, 0x0($a0)
    ctx->pc = 0x146accu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 20)); // MMIO: 0x10000000
    // 0x146ad0: 0x34a5d400  ori         $a1, $a1, 0xD400
    ctx->pc = 0x146ad0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)54272);
    // 0x146ad4: 0x24030101  addiu       $v1, $zero, 0x101
    ctx->pc = 0x146ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x146ad8: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x146ad8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x146adc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x146ADCu;
    {
        const bool branch_taken_0x146adc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146ADCu;
            // 0x146ae0: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146adc) {
            ctx->pc = 0x146AF0u;
            goto label_146af0;
        }
    }
    ctx->pc = 0x146AE4u;
    // 0x146ae4: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x146AE4u;
    SET_GPR_U32(ctx, 31, 0x146AECu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146AECu; }
        if (ctx->pc != 0x146AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146AECu; }
        if (ctx->pc != 0x146AECu) { return; }
    }
    ctx->pc = 0x146AECu;
label_146aec:
    // 0x146aec: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x146aecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
label_146af0:
    // 0x146af0: 0x2559821  addu        $s3, $s2, $s5
    ctx->pc = 0x146af0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 21)));
    // 0x146af4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x146af4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x146af8: 0x23e9021  addu        $s2, $s1, $fp
    ctx->pc = 0x146af8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 30)));
    // 0x146afc: 0x3463d400  ori         $v1, $v1, 0xD400
    ctx->pc = 0x146afcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)54272);
label_146b00:
    // 0x146b00: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x146b00u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x146b04: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x146b04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x146b08: 0x0  nop
    ctx->pc = 0x146b08u;
    // NOP
    // 0x146b0c: 0x0  nop
    ctx->pc = 0x146b0cu;
    // NOP
    // 0x146b10: 0x0  nop
    ctx->pc = 0x146b10u;
    // NOP
    // 0x146b14: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x146B14u;
    {
        const bool branch_taken_0x146b14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x146b14) {
            ctx->pc = 0x146B00u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_146b00;
        }
    }
    ctx->pc = 0x146B1Cu;
    // 0x146b1c: 0xc047598  jal         func_11D660
    ctx->pc = 0x146B1Cu;
    SET_GPR_U32(ctx, 31, 0x146B24u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146B24u; }
        if (ctx->pc != 0x146B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146B24u; }
        if (ctx->pc != 0x146B24u) { return; }
    }
    ctx->pc = 0x146B24u;
label_146b24:
    // 0x146b24: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x146b24u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x146b28: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x146b28u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x146b2c: 0x3463d080  ori         $v1, $v1, 0xD080
    ctx->pc = 0x146b2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)53376);
    // 0x146b30: 0x34a5d010  ori         $a1, $a1, 0xD010
    ctx->pc = 0x146b30u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)53264);
    // 0x146b34: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x146b34u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x146b38: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x146b38u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x146b3c: 0xacb10000  sw          $s1, 0x0($a1)
    ctx->pc = 0x146b3cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 17)); // MMIO: 0x10000000
    // 0x146b40: 0x3484d020  ori         $a0, $a0, 0xD020
    ctx->pc = 0x146b40u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)53280);
    // 0x146b44: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x146b44u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x146b48: 0xac940000  sw          $s4, 0x0($a0)
    ctx->pc = 0x146b48u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 20)); // MMIO: 0x10000000
    // 0x146b4c: 0x34a5d000  ori         $a1, $a1, 0xD000
    ctx->pc = 0x146b4cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)53248);
    // 0x146b50: 0x24030100  addiu       $v1, $zero, 0x100
    ctx->pc = 0x146b50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x146b54: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x146b54u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x146b58: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x146B58u;
    {
        const bool branch_taken_0x146b58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146B58u;
            // 0x146b5c: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146b58) {
            ctx->pc = 0x146B6Cu;
            goto label_146b6c;
        }
    }
    ctx->pc = 0x146B60u;
    // 0x146b60: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x146B60u;
    SET_GPR_U32(ctx, 31, 0x146B68u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146B68u; }
        if (ctx->pc != 0x146B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146B68u; }
        if (ctx->pc != 0x146B68u) { return; }
    }
    ctx->pc = 0x146B68u;
label_146b68:
    // 0x146b68: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x146b68u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
label_146b6c:
    // 0x146b6c: 0x8ec6000c  lw          $a2, 0xC($s6)
    ctx->pc = 0x146b6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x146b70: 0x3463d000  ori         $v1, $v1, 0xD000
    ctx->pc = 0x146b70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)53248);
    // 0x146b74: 0x0  nop
    ctx->pc = 0x146b74u;
    // NOP
label_146b78:
    // 0x146b78: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x146b78u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x146b7c: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x146b7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x146b80: 0x0  nop
    ctx->pc = 0x146b80u;
    // NOP
    // 0x146b84: 0x0  nop
    ctx->pc = 0x146b84u;
    // NOP
    // 0x146b88: 0x0  nop
    ctx->pc = 0x146b88u;
    // NOP
    // 0x146b8c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x146B8Cu;
    {
        const bool branch_taken_0x146b8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x146b8c) {
            ctx->pc = 0x146B78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_146b78;
        }
    }
    ctx->pc = 0x146B94u;
    // 0x146b94: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x146b94u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x146b98: 0x3463d020  ori         $v1, $v1, 0xD020
    ctx->pc = 0x146b98u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)53280);
    // 0x146b9c: 0x0  nop
    ctx->pc = 0x146b9cu;
    // NOP
label_146ba0:
    // 0x146ba0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x146ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x146ba4: 0x0  nop
    ctx->pc = 0x146ba4u;
    // NOP
    // 0x146ba8: 0x0  nop
    ctx->pc = 0x146ba8u;
    // NOP
    // 0x146bac: 0x0  nop
    ctx->pc = 0x146bacu;
    // NOP
    // 0x146bb0: 0x0  nop
    ctx->pc = 0x146bb0u;
    // NOP
    // 0x146bb4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x146BB4u;
    {
        const bool branch_taken_0x146bb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x146bb4) {
            ctx->pc = 0x146BA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_146ba0;
        }
    }
    ctx->pc = 0x146BBCu;
    // 0x146bbc: 0x240882d  daddu       $s1, $s2, $zero
    ctx->pc = 0x146bbcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146bc0: 0x206102a  slt         $v0, $s0, $a2
    ctx->pc = 0x146bc0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x146bc4: 0x1440ffb6  bnez        $v0, . + 4 + (-0x4A << 2)
    ctx->pc = 0x146BC4u;
    {
        const bool branch_taken_0x146bc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x146BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146BC4u;
            // 0x146bc8: 0x260902d  daddu       $s2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146bc4) {
            ctx->pc = 0x146AA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_146aa0;
        }
    }
    ctx->pc = 0x146BCCu;
    // 0x146bcc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x146BCCu;
    {
        const bool branch_taken_0x146bcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146BCCu;
            // 0x146bd0: 0x8fa70000  lw          $a3, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146bcc) {
            ctx->pc = 0x146BDCu;
            goto label_146bdc;
        }
    }
    ctx->pc = 0x146BD4u;
label_146bd4:
    // 0x146bd4: 0x24b70001  addiu       $s7, $a1, 0x1
    ctx->pc = 0x146bd4u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x146bd8: 0x8fa70000  lw          $a3, 0x0($sp)
    ctx->pc = 0x146bd8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_146bdc:
    // 0x146bdc: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x146bdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146be0: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x146be0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x146be4: 0x8ce200fc  lw          $v0, 0xFC($a3)
    ctx->pc = 0x146be4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 252)));
    // 0x146be8: 0x8fa70004  lw          $a3, 0x4($sp)
    ctx->pc = 0x146be8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x146bec: 0xa7202a  slt         $a0, $a1, $a3
    ctx->pc = 0x146becu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x146bf0: 0x8fa70008  lw          $a3, 0x8($sp)
    ctx->pc = 0x146bf0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x146bf4: 0xe00013  mtlo        $a3
    ctx->pc = 0x146bf4u;
    ctx->lo = GPR_U64(ctx, 7);
    // 0x146bf8: 0x70430000  madd        $zero, $v0, $v1
    ctx->pc = 0x146bf8u;
    { uint64_t acc = Ps2HiLoToU64(ctx->hi, ctx->lo); int64_t prod = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); int64_t result = acc + prod; ctx->lo = Ps2SignExt32ToU64((uint32_t)result); ctx->hi = Ps2SignExt32ToU64((uint32_t)(result >> 32)); }
    // 0x146bfc: 0x3812  mflo        $a3
    ctx->pc = 0x146bfcu;
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x146c00: 0x1480ffa3  bnez        $a0, . + 4 + (-0x5D << 2)
    ctx->pc = 0x146C00u;
    {
        const bool branch_taken_0x146c00 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x146C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146C00u;
            // 0x146c04: 0xafa70008  sw          $a3, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146c00) {
            ctx->pc = 0x146A90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_146a90;
        }
    }
    ctx->pc = 0x146C08u;
label_146c08:
    // 0x146c08: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x146c08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x146c0c: 0xdfbe0090  ld          $fp, 0x90($sp)
    ctx->pc = 0x146c0cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x146c10: 0xdfb70080  ld          $s7, 0x80($sp)
    ctx->pc = 0x146c10u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x146c14: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x146c14u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x146c18: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x146c18u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x146c1c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x146c1cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x146c20: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x146c20u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x146c24: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x146c24u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x146c28: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x146c28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x146c2c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x146c2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146c30: 0x3e00008  jr          $ra
    ctx->pc = 0x146C30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146C30u;
            // 0x146c34: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146A1Cu: goto label_146a1c;
            case 0x146A28u: goto label_146a28;
            case 0x146A44u: goto label_146a44;
            case 0x146A48u: goto label_146a48;
            case 0x146A54u: goto label_146a54;
            case 0x146A7Cu: goto label_146a7c;
            case 0x146A90u: goto label_146a90;
            case 0x146AA0u: goto label_146aa0;
            case 0x146AA8u: goto label_146aa8;
            case 0x146AECu: goto label_146aec;
            case 0x146AF0u: goto label_146af0;
            case 0x146B00u: goto label_146b00;
            case 0x146B24u: goto label_146b24;
            case 0x146B68u: goto label_146b68;
            case 0x146B6Cu: goto label_146b6c;
            case 0x146B78u: goto label_146b78;
            case 0x146BA0u: goto label_146ba0;
            case 0x146BD4u: goto label_146bd4;
            case 0x146BDCu: goto label_146bdc;
            case 0x146C08u: goto label_146c08;
            case 0x146C38u: goto label_146c38;
            case 0x146C58u: goto label_146c58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146C38u;
label_146c38:
    // 0x146c38: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x146c38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x146c3c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x146c3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x146c40: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x146C40u;
    {
        const bool branch_taken_0x146c40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x146C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146C40u;
            // 0x146c44: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146c40) {
            ctx->pc = 0x146C58u;
            goto label_146c58;
        }
    }
    ctx->pc = 0x146C48u;
    // 0x146c48: 0x8c820130  lw          $v0, 0x130($a0)
    ctx->pc = 0x146c48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 304)));
    // 0x146c4c: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x146c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x146c50: 0xac8200c4  sw          $v0, 0xC4($a0)
    ctx->pc = 0x146c50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 196), GPR_U32(ctx, 2));
    // 0x146c54: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x146c54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_146c58:
    // 0x146c58: 0x3e00008  jr          $ra
    ctx->pc = 0x146C58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146C58u;
            // 0x146c5c: 0xac820838  sw          $v0, 0x838($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 2104), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146A1Cu: goto label_146a1c;
            case 0x146A28u: goto label_146a28;
            case 0x146A44u: goto label_146a44;
            case 0x146A48u: goto label_146a48;
            case 0x146A54u: goto label_146a54;
            case 0x146A7Cu: goto label_146a7c;
            case 0x146A90u: goto label_146a90;
            case 0x146AA0u: goto label_146aa0;
            case 0x146AA8u: goto label_146aa8;
            case 0x146AECu: goto label_146aec;
            case 0x146AF0u: goto label_146af0;
            case 0x146B00u: goto label_146b00;
            case 0x146B24u: goto label_146b24;
            case 0x146B68u: goto label_146b68;
            case 0x146B6Cu: goto label_146b6c;
            case 0x146B78u: goto label_146b78;
            case 0x146BA0u: goto label_146ba0;
            case 0x146BD4u: goto label_146bd4;
            case 0x146BDCu: goto label_146bdc;
            case 0x146C08u: goto label_146c08;
            case 0x146C38u: goto label_146c38;
            case 0x146C58u: goto label_146c58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146C60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
