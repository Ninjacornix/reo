#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C00D0
// Address: 0x1c00d0 - 0x1c02a0
void sub_001C00D0_0x1c00d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C00D0_0x1c00d0");
#endif

    switch (ctx->pc) {
        case 0x1c0118u: goto label_1c0118;
        case 0x1c012cu: goto label_1c012c;
        case 0x1c0144u: goto label_1c0144;
        case 0x1c0188u: goto label_1c0188;
        case 0x1c0190u: goto label_1c0190;
        case 0x1c01b4u: goto label_1c01b4;
        case 0x1c01f4u: goto label_1c01f4;
        case 0x1c0214u: goto label_1c0214;
        case 0x1c0240u: goto label_1c0240;
        case 0x1c025cu: goto label_1c025c;
        default: break;
    }

    ctx->pc = 0x1c00d0u;

    // 0x1c00d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c00d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c00d4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c00d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c00d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c00d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c00dc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c00dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c00e0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1c00e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c00e4: 0x1062005b  beq         $v1, $v0, . + 4 + (0x5B << 2)
    ctx->pc = 0x1C00E4u;
    {
        const bool branch_taken_0x1c00e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C00E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C00E4u;
            // 0x1c00e8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c00e4) {
            ctx->pc = 0x1C0254u;
            goto label_1c0254;
        }
    }
    ctx->pc = 0x1C00ECu;
    // 0x1c00ec: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c00ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c00f0: 0x1062002e  beq         $v1, $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0x1C00F0u;
    {
        const bool branch_taken_0x1c00f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C00F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C00F0u;
            // 0x1c00f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c00f0) {
            ctx->pc = 0x1C01ACu;
            goto label_1c01ac;
        }
    }
    ctx->pc = 0x1C00F8u;
    // 0x1c00f8: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1C00F8u;
    {
        const bool branch_taken_0x1c00f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c00f8) {
            ctx->pc = 0x1C0150u;
            goto label_1c0150;
        }
    }
    ctx->pc = 0x1C0100u;
    // 0x1c0100: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C0100u;
    {
        const bool branch_taken_0x1c0100 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0100) {
            ctx->pc = 0x1C0110u;
            goto label_1c0110;
        }
    }
    ctx->pc = 0x1C0108u;
    // 0x1c0108: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1C0108u;
    {
        const bool branch_taken_0x1c0108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C010Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0108u;
            // 0x1c010c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0108) {
            ctx->pc = 0x1C028Cu;
            goto label_1c028c;
        }
    }
    ctx->pc = 0x1C0110u;
label_1c0110:
    // 0x1c0110: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1C0110u;
    SET_GPR_U32(ctx, 31, 0x1C0118u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0118u; }
        if (ctx->pc != 0x1C0118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0118u; }
        if (ctx->pc != 0x1C0118u) { return; }
    }
    ctx->pc = 0x1C0118u;
label_1c0118:
    // 0x1c0118: 0x440005b  bltz        $v0, . + 4 + (0x5B << 2)
    ctx->pc = 0x1C0118u;
    {
        const bool branch_taken_0x1c0118 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c0118) {
            ctx->pc = 0x1C0288u;
            goto label_1c0288;
        }
    }
    ctx->pc = 0x1C0120u;
    // 0x1c0120: 0x8e02008c  lw          $v0, 0x8C($s0)
    ctx->pc = 0x1c0120u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 140)));
    // 0x1c0124: 0x10400035  beqz        $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x1C0124u;
    {
        const bool branch_taken_0x1c0124 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0124) {
            ctx->pc = 0x1C01FCu;
            goto label_1c01fc;
        }
    }
    ctx->pc = 0x1C012Cu;
label_1c012c:
    // 0x1c012c: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c012cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c0130: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c0130u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c0134: 0x24846b00  addiu       $a0, $a0, 0x6B00
    ctx->pc = 0x1c0134u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27392));
    // 0x1c0138: 0x24a50638  addiu       $a1, $a1, 0x638
    ctx->pc = 0x1c0138u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1592));
    // 0x1c013c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C013Cu;
    SET_GPR_U32(ctx, 31, 0x1C0144u);
    ctx->pc = 0x1C0140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C013Cu;
            // 0x1c0140: 0x26060044  addiu       $a2, $s0, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0144u; }
        if (ctx->pc != 0x1C0144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0144u; }
        if (ctx->pc != 0x1C0144u) { return; }
    }
    ctx->pc = 0x1C0144u;
label_1c0144:
    // 0x1c0144: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1c0144u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c0148: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c0148u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c014c: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1c014cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
label_1c0150:
    // 0x1c0150: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1c0150u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1c0154: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1c0154u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1c0158: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c0158u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c015c: 0x3c080032  lui         $t0, 0x32
    ctx->pc = 0x1c015cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)50 << 16));
    // 0x1c0160: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1c0160u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1c0164: 0x24a56b00  addiu       $a1, $a1, 0x6B00
    ctx->pc = 0x1c0164u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27392));
    // 0x1c0168: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1c0168u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c016c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1c016cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0170: 0x25086ab0  addiu       $t0, $t0, 0x6AB0
    ctx->pc = 0x1c0170u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 27312));
    // 0x1c0174: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c0174u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c0178: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c0178u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c017c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1c017cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c0180: 0xc060558  jal         func_181560
    ctx->pc = 0x1C0180u;
    SET_GPR_U32(ctx, 31, 0x1C0188u);
    ctx->pc = 0x1C0184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0180u;
            // 0x1c0184: 0x2609000c  addiu       $t1, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181560u;
    if (runtime->hasFunction(0x181560u)) {
        auto targetFn = runtime->lookupFunction(0x181560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0188u; }
        if (ctx->pc != 0x1C0188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181560_0x181560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0188u; }
        if (ctx->pc != 0x1C0188u) { return; }
    }
    ctx->pc = 0x1C0188u;
label_1c0188:
    // 0x1c0188: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C0188u;
    {
        const bool branch_taken_0x1c0188 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1c0188) {
            ctx->pc = 0x1C019Cu;
            goto label_1c019c;
        }
    }
    ctx->pc = 0x1C0190u;
label_1c0190:
    // 0x1c0190: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1c0190u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1c0194: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1C0194u;
    {
        const bool branch_taken_0x1c0194 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0194u;
            // 0x1c0198: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0194) {
            ctx->pc = 0x1C028Cu;
            goto label_1c028c;
        }
    }
    ctx->pc = 0x1C019Cu;
label_1c019c:
    // 0x1c019c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1c019cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c01a0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c01a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c01a4: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1C01A4u;
    {
        const bool branch_taken_0x1c01a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C01A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C01A4u;
            // 0x1c01a8: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c01a4) {
            ctx->pc = 0x1C0288u;
            goto label_1c0288;
        }
    }
    ctx->pc = 0x1C01ACu;
label_1c01ac:
    // 0x1c01ac: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1C01ACu;
    SET_GPR_U32(ctx, 31, 0x1C01B4u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C01B4u; }
        if (ctx->pc != 0x1C01B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C01B4u; }
        if (ctx->pc != 0x1C01B4u) { return; }
    }
    ctx->pc = 0x1C01B4u;
label_1c01b4:
    // 0x1c01b4: 0x4400034  bltz        $v0, . + 4 + (0x34 << 2)
    ctx->pc = 0x1C01B4u;
    {
        const bool branch_taken_0x1c01b4 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c01b4) {
            ctx->pc = 0x1C0288u;
            goto label_1c0288;
        }
    }
    ctx->pc = 0x1C01BCu;
    // 0x1c01bc: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1c01bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c01c0: 0x440fff3  bltz        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1C01C0u;
    {
        const bool branch_taken_0x1c01c0 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c01c0) {
            ctx->pc = 0x1C0190u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c0190;
        }
    }
    ctx->pc = 0x1C01C8u;
    // 0x1c01c8: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1c01c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1c01cc: 0x1840000b  blez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1C01CCu;
    {
        const bool branch_taken_0x1c01cc = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1c01cc) {
            ctx->pc = 0x1C01FCu;
            goto label_1c01fc;
        }
    }
    ctx->pc = 0x1C01D4u;
    // 0x1c01d4: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c01d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c01d8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c01d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c01dc: 0x3c070032  lui         $a3, 0x32
    ctx->pc = 0x1c01dcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)50 << 16));
    // 0x1c01e0: 0x24846b00  addiu       $a0, $a0, 0x6B00
    ctx->pc = 0x1c01e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27392));
    // 0x1c01e4: 0x24a50640  addiu       $a1, $a1, 0x640
    ctx->pc = 0x1c01e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1600));
    // 0x1c01e8: 0x26060044  addiu       $a2, $s0, 0x44
    ctx->pc = 0x1c01e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x1c01ec: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C01ECu;
    SET_GPR_U32(ctx, 31, 0x1C01F4u);
    ctx->pc = 0x1C01F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C01ECu;
            // 0x1c01f0: 0x24e76ac8  addiu       $a3, $a3, 0x6AC8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 27336));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C01F4u; }
        if (ctx->pc != 0x1C01F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C01F4u; }
        if (ctx->pc != 0x1C01F4u) { return; }
    }
    ctx->pc = 0x1C01F4u;
label_1c01f4:
    // 0x1c01f4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C01F4u;
    {
        const bool branch_taken_0x1c01f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C01F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C01F4u;
            // 0x1c01f8: 0xae000090  sw          $zero, 0x90($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c01f4) {
            ctx->pc = 0x1C021Cu;
            goto label_1c021c;
        }
    }
    ctx->pc = 0x1C01FCu;
label_1c01fc:
    // 0x1c01fc: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c01fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c0200: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c0200u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c0204: 0x24846b00  addiu       $a0, $a0, 0x6B00
    ctx->pc = 0x1c0204u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27392));
    // 0x1c0208: 0x24a50648  addiu       $a1, $a1, 0x648
    ctx->pc = 0x1c0208u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1608));
    // 0x1c020c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C020Cu;
    SET_GPR_U32(ctx, 31, 0x1C0214u);
    ctx->pc = 0x1C0210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C020Cu;
            // 0x1c0210: 0x26060044  addiu       $a2, $s0, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0214u; }
        if (ctx->pc != 0x1C0214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0214u; }
        if (ctx->pc != 0x1C0214u) { return; }
    }
    ctx->pc = 0x1C0214u;
label_1c0214:
    // 0x1c0214: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c0214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c0218: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1c0218u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
label_1c021c:
    // 0x1c021c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1c021cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1c0220: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1c0220u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1c0224: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c0224u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c0228: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1c0228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1c022c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c022cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c0230: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c0230u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c0234: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1c0234u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c0238: 0xc06052a  jal         func_1814A8
    ctx->pc = 0x1C0238u;
    SET_GPR_U32(ctx, 31, 0x1C0240u);
    ctx->pc = 0x1C023Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0238u;
            // 0x1c023c: 0x24a56b00  addiu       $a1, $a1, 0x6B00 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 27392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1814A8u;
    if (runtime->hasFunction(0x1814A8u)) {
        auto targetFn = runtime->lookupFunction(0x1814A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0240u; }
        if (ctx->pc != 0x1C0240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001814A8_0x1814a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C0240u; }
        if (ctx->pc != 0x1C0240u) { return; }
    }
    ctx->pc = 0x1C0240u;
label_1c0240:
    // 0x1c0240: 0x440ffd3  bltz        $v0, . + 4 + (-0x2D << 2)
    ctx->pc = 0x1C0240u;
    {
        const bool branch_taken_0x1c0240 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c0240) {
            ctx->pc = 0x1C0190u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c0190;
        }
    }
    ctx->pc = 0x1C0248u;
    // 0x1c0248: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c0248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c024c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1C024Cu;
    {
        const bool branch_taken_0x1c024c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C024Cu;
            // 0x1c0250: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c024c) {
            ctx->pc = 0x1C0288u;
            goto label_1c0288;
        }
    }
    ctx->pc = 0x1C0254u;
label_1c0254:
    // 0x1c0254: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1C0254u;
    SET_GPR_U32(ctx, 31, 0x1C025Cu);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C025Cu; }
        if (ctx->pc != 0x1C025Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C025Cu; }
        if (ctx->pc != 0x1C025Cu) { return; }
    }
    ctx->pc = 0x1C025Cu;
label_1c025c:
    // 0x1c025c: 0x440000a  bltz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1C025Cu;
    {
        const bool branch_taken_0x1c025c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c025c) {
            ctx->pc = 0x1C0288u;
            goto label_1c0288;
        }
    }
    ctx->pc = 0x1C0264u;
    // 0x1c0264: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1c0264u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1c0268: 0x440ffc9  bltz        $v0, . + 4 + (-0x37 << 2)
    ctx->pc = 0x1C0268u;
    {
        const bool branch_taken_0x1c0268 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1c0268) {
            ctx->pc = 0x1C0190u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c0190;
        }
    }
    ctx->pc = 0x1C0270u;
    // 0x1c0270: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1c0270u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1c0274: 0x8e020090  lw          $v0, 0x90($s0)
    ctx->pc = 0x1c0274u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
    // 0x1c0278: 0x1040ffac  beqz        $v0, . + 4 + (-0x54 << 2)
    ctx->pc = 0x1C0278u;
    {
        const bool branch_taken_0x1c0278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c0278) {
            ctx->pc = 0x1C012Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c012c;
        }
    }
    ctx->pc = 0x1C0280u;
    // 0x1c0280: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C0280u;
    {
        const bool branch_taken_0x1c0280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C0284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0280u;
            // 0x1c0284: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c0280) {
            ctx->pc = 0x1C028Cu;
            goto label_1c028c;
        }
    }
    ctx->pc = 0x1C0288u;
label_1c0288:
    // 0x1c0288: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1c0288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1c028c:
    // 0x1c028c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c028cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c0290: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c0290u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c0294: 0x3e00008  jr          $ra
    ctx->pc = 0x1C0294u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C0298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C0294u;
            // 0x1c0298: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C0110u: goto label_1c0110;
            case 0x1C0118u: goto label_1c0118;
            case 0x1C012Cu: goto label_1c012c;
            case 0x1C0144u: goto label_1c0144;
            case 0x1C0150u: goto label_1c0150;
            case 0x1C0188u: goto label_1c0188;
            case 0x1C0190u: goto label_1c0190;
            case 0x1C019Cu: goto label_1c019c;
            case 0x1C01ACu: goto label_1c01ac;
            case 0x1C01B4u: goto label_1c01b4;
            case 0x1C01F4u: goto label_1c01f4;
            case 0x1C01FCu: goto label_1c01fc;
            case 0x1C0214u: goto label_1c0214;
            case 0x1C021Cu: goto label_1c021c;
            case 0x1C0240u: goto label_1c0240;
            case 0x1C0254u: goto label_1c0254;
            case 0x1C025Cu: goto label_1c025c;
            case 0x1C0288u: goto label_1c0288;
            case 0x1C028Cu: goto label_1c028c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C029Cu;
    // 0x1c029c: 0x0  nop
    ctx->pc = 0x1c029cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
