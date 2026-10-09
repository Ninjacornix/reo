#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BFC00
// Address: 0x1bfc00 - 0x1bfd50
void sub_001BFC00_0x1bfc00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BFC00_0x1bfc00");
#endif

    switch (ctx->pc) {
        case 0x1bfc40u: goto label_1bfc40;
        case 0x1bfc68u: goto label_1bfc68;
        case 0x1bfc90u: goto label_1bfc90;
        case 0x1bfcb0u: goto label_1bfcb0;
        case 0x1bfcc4u: goto label_1bfcc4;
        case 0x1bfd00u: goto label_1bfd00;
        case 0x1bfd20u: goto label_1bfd20;
        default: break;
    }

    ctx->pc = 0x1bfc00u;

    // 0x1bfc00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bfc00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bfc04: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1bfc04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bfc08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bfc08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bfc0c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bfc0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bfc10: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1bfc10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bfc14: 0x10620040  beq         $v1, $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x1BFC14u;
    {
        const bool branch_taken_0x1bfc14 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BFC18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFC14u;
            // 0x1bfc18: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfc14) {
            ctx->pc = 0x1BFD18u;
            goto label_1bfd18;
        }
    }
    ctx->pc = 0x1BFC1Cu;
    // 0x1bfc1c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bfc1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bfc20: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1BFC20u;
    {
        const bool branch_taken_0x1bfc20 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1bfc20) {
            ctx->pc = 0x1BFC88u;
            goto label_1bfc88;
        }
    }
    ctx->pc = 0x1BFC28u;
    // 0x1bfc28: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFC28u;
    {
        const bool branch_taken_0x1bfc28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bfc28) {
            ctx->pc = 0x1BFC38u;
            goto label_1bfc38;
        }
    }
    ctx->pc = 0x1BFC30u;
    // 0x1bfc30: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x1BFC30u;
    {
        const bool branch_taken_0x1bfc30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFC34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFC30u;
            // 0x1bfc34: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfc30) {
            ctx->pc = 0x1BFD3Cu;
            goto label_1bfd3c;
        }
    }
    ctx->pc = 0x1BFC38u;
label_1bfc38:
    // 0x1bfc38: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFC38u;
    SET_GPR_U32(ctx, 31, 0x1BFC40u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFC40u; }
        if (ctx->pc != 0x1BFC40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFC40u; }
        if (ctx->pc != 0x1BFC40u) { return; }
    }
    ctx->pc = 0x1BFC40u;
label_1bfc40:
    // 0x1bfc40: 0x440003d  bltz        $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x1BFC40u;
    {
        const bool branch_taken_0x1bfc40 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfc40) {
            ctx->pc = 0x1BFD38u;
            goto label_1bfd38;
        }
    }
    ctx->pc = 0x1BFC48u;
    // 0x1bfc48: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bfc48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bfc4c: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bfc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bfc50: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1bfc50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1bfc54: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bfc54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bfc58: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bfc58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bfc5c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1bfc5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bfc60: 0xc060594  jal         func_181650
    ctx->pc = 0x1BFC60u;
    SET_GPR_U32(ctx, 31, 0x1BFC68u);
    ctx->pc = 0x1BFC64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFC60u;
            // 0x1bfc64: 0x26050044  addiu       $a1, $s0, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181650u;
    if (runtime->hasFunction(0x181650u)) {
        auto targetFn = runtime->lookupFunction(0x181650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFC68u; }
        if (ctx->pc != 0x1BFC68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181650_0x181650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFC68u; }
        if (ctx->pc != 0x1BFC68u) { return; }
    }
    ctx->pc = 0x1BFC68u;
label_1bfc68:
    // 0x1bfc68: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFC68u;
    {
        const bool branch_taken_0x1bfc68 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1bfc68) {
            ctx->pc = 0x1BFC78u;
            goto label_1bfc78;
        }
    }
    ctx->pc = 0x1BFC70u;
    // 0x1bfc70: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1BFC70u;
    {
        const bool branch_taken_0x1bfc70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFC74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFC70u;
            // 0x1bfc74: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfc70) {
            ctx->pc = 0x1BFD3Cu;
            goto label_1bfd3c;
        }
    }
    ctx->pc = 0x1BFC78u;
label_1bfc78:
    // 0x1bfc78: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1bfc78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bfc7c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bfc7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bfc80: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1BFC80u;
    {
        const bool branch_taken_0x1bfc80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFC84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFC80u;
            // 0x1bfc84: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfc80) {
            ctx->pc = 0x1BFD38u;
            goto label_1bfd38;
        }
    }
    ctx->pc = 0x1BFC88u;
label_1bfc88:
    // 0x1bfc88: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFC88u;
    SET_GPR_U32(ctx, 31, 0x1BFC90u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFC90u; }
        if (ctx->pc != 0x1BFC90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFC90u; }
        if (ctx->pc != 0x1BFC90u) { return; }
    }
    ctx->pc = 0x1BFC90u;
label_1bfc90:
    // 0x1bfc90: 0x4400029  bltz        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x1BFC90u;
    {
        const bool branch_taken_0x1bfc90 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfc90) {
            ctx->pc = 0x1BFD38u;
            goto label_1bfd38;
        }
    }
    ctx->pc = 0x1BFC98u;
    // 0x1bfc98: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x1bfc98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bfc9c: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x1bfc9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1bfca0: 0x3083ffff  andi        $v1, $a0, 0xFFFF
    ctx->pc = 0x1bfca0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1bfca4: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BFCA4u;
    {
        const bool branch_taken_0x1bfca4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1bfca4) {
            ctx->pc = 0x1BFCBCu;
            goto label_1bfcbc;
        }
    }
    ctx->pc = 0x1BFCACu;
    // 0x1bfcac: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1bfcacu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
label_1bfcb0:
    // 0x1bfcb0: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bfcb0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bfcb4: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1BFCB4u;
    {
        const bool branch_taken_0x1bfcb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFCB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFCB4u;
            // 0x1bfcb8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfcb4) {
            ctx->pc = 0x1BFD3Cu;
            goto label_1bfd3c;
        }
    }
    ctx->pc = 0x1BFCBCu;
label_1bfcbc:
    // 0x1bfcbc: 0x4810004  bgez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BFCBCu;
    {
        const bool branch_taken_0x1bfcbc = (GPR_S64(ctx, 4) >= 0);
        if (branch_taken_0x1bfcbc) {
            ctx->pc = 0x1BFCD0u;
            goto label_1bfcd0;
        }
    }
    ctx->pc = 0x1BFCC4u;
label_1bfcc4:
    // 0x1bfcc4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bfcc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bfcc8: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1BFCC8u;
    {
        const bool branch_taken_0x1bfcc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFCCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFCC8u;
            // 0x1bfccc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfcc8) {
            ctx->pc = 0x1BFD3Cu;
            goto label_1bfd3c;
        }
    }
    ctx->pc = 0x1BFCD0u;
label_1bfcd0:
    // 0x1bfcd0: 0x8e020094  lw          $v0, 0x94($s0)
    ctx->pc = 0x1bfcd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1bfcd4: 0x1040fff6  beqz        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1BFCD4u;
    {
        const bool branch_taken_0x1bfcd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bfcd4) {
            ctx->pc = 0x1BFCB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bfcb0;
        }
    }
    ctx->pc = 0x1BFCDCu;
    // 0x1bfcdc: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bfcdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bfce0: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bfce0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bfce4: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1bfce4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1bfce8: 0x26050044  addiu       $a1, $s0, 0x44
    ctx->pc = 0x1bfce8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x1bfcec: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bfcecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bfcf0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bfcf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bfcf4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1bfcf4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bfcf8: 0xc0605f2  jal         func_1817C8
    ctx->pc = 0x1BFCF8u;
    SET_GPR_U32(ctx, 31, 0x1BFD00u);
    ctx->pc = 0x1BFCFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFCF8u;
            // 0x1bfcfc: 0x2406000f  addiu       $a2, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1817C8u;
    if (runtime->hasFunction(0x1817C8u)) {
        auto targetFn = runtime->lookupFunction(0x1817C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFD00u; }
        if (ctx->pc != 0x1BFD00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001817C8_0x1817c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFD00u; }
        if (ctx->pc != 0x1BFD00u) { return; }
    }
    ctx->pc = 0x1BFD00u;
label_1bfd00:
    // 0x1bfd00: 0x440fff0  bltz        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1BFD00u;
    {
        const bool branch_taken_0x1bfd00 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfd00) {
            ctx->pc = 0x1BFCC4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bfcc4;
        }
    }
    ctx->pc = 0x1BFD08u;
    // 0x1bfd08: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1bfd08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bfd0c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bfd0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bfd10: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1BFD10u;
    {
        const bool branch_taken_0x1bfd10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFD14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFD10u;
            // 0x1bfd14: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfd10) {
            ctx->pc = 0x1BFD38u;
            goto label_1bfd38;
        }
    }
    ctx->pc = 0x1BFD18u;
label_1bfd18:
    // 0x1bfd18: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFD18u;
    SET_GPR_U32(ctx, 31, 0x1BFD20u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFD20u; }
        if (ctx->pc != 0x1BFD20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFD20u; }
        if (ctx->pc != 0x1BFD20u) { return; }
    }
    ctx->pc = 0x1BFD20u;
label_1bfd20:
    // 0x1bfd20: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BFD20u;
    {
        const bool branch_taken_0x1bfd20 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfd20) {
            ctx->pc = 0x1BFD38u;
            goto label_1bfd38;
        }
    }
    ctx->pc = 0x1BFD28u;
    // 0x1bfd28: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bfd28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bfd2c: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1bfd2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bfd30: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1BFD30u;
    {
        const bool branch_taken_0x1bfd30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFD34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFD30u;
            // 0x1bfd34: 0x40102a  slt         $v0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfd30) {
            ctx->pc = 0x1BFD3Cu;
            goto label_1bfd3c;
        }
    }
    ctx->pc = 0x1BFD38u;
label_1bfd38:
    // 0x1bfd38: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1bfd38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1bfd3c:
    // 0x1bfd3c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bfd3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bfd40: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bfd40u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bfd44: 0x3e00008  jr          $ra
    ctx->pc = 0x1BFD44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BFD48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFD44u;
            // 0x1bfd48: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BFC38u: goto label_1bfc38;
            case 0x1BFC40u: goto label_1bfc40;
            case 0x1BFC68u: goto label_1bfc68;
            case 0x1BFC78u: goto label_1bfc78;
            case 0x1BFC88u: goto label_1bfc88;
            case 0x1BFC90u: goto label_1bfc90;
            case 0x1BFCB0u: goto label_1bfcb0;
            case 0x1BFCBCu: goto label_1bfcbc;
            case 0x1BFCC4u: goto label_1bfcc4;
            case 0x1BFCD0u: goto label_1bfcd0;
            case 0x1BFD00u: goto label_1bfd00;
            case 0x1BFD18u: goto label_1bfd18;
            case 0x1BFD20u: goto label_1bfd20;
            case 0x1BFD38u: goto label_1bfd38;
            case 0x1BFD3Cu: goto label_1bfd3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BFD4Cu;
    // 0x1bfd4c: 0x0  nop
    ctx->pc = 0x1bfd4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
