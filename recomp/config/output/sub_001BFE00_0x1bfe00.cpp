#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BFE00
// Address: 0x1bfe00 - 0x1bfec0
void sub_001BFE00_0x1bfe00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BFE00_0x1bfe00");
#endif

    switch (ctx->pc) {
        case 0x1bfe34u: goto label_1bfe34;
        case 0x1bfe68u: goto label_1bfe68;
        case 0x1bfe90u: goto label_1bfe90;
        default: break;
    }

    ctx->pc = 0x1bfe00u;

    // 0x1bfe00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bfe00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bfe04: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bfe04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bfe08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bfe08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bfe0c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bfe0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bfe10: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1bfe10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bfe14: 0x1062001c  beq         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1BFE14u;
    {
        const bool branch_taken_0x1bfe14 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BFE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFE14u;
            // 0x1bfe18: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfe14) {
            ctx->pc = 0x1BFE88u;
            goto label_1bfe88;
        }
    }
    ctx->pc = 0x1BFE1Cu;
    // 0x1bfe1c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFE1Cu;
    {
        const bool branch_taken_0x1bfe1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bfe1c) {
            ctx->pc = 0x1BFE2Cu;
            goto label_1bfe2c;
        }
    }
    ctx->pc = 0x1BFE24u;
    // 0x1bfe24: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1BFE24u;
    {
        const bool branch_taken_0x1bfe24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFE24u;
            // 0x1bfe28: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfe24) {
            ctx->pc = 0x1BFEACu;
            goto label_1bfeac;
        }
    }
    ctx->pc = 0x1BFE2Cu;
label_1bfe2c:
    // 0x1bfe2c: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFE2Cu;
    SET_GPR_U32(ctx, 31, 0x1BFE34u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFE34u; }
        if (ctx->pc != 0x1BFE34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFE34u; }
        if (ctx->pc != 0x1BFE34u) { return; }
    }
    ctx->pc = 0x1BFE34u;
label_1bfe34:
    // 0x1bfe34: 0x440001c  bltz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1BFE34u;
    {
        const bool branch_taken_0x1bfe34 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfe34) {
            ctx->pc = 0x1BFEA8u;
            goto label_1bfea8;
        }
    }
    ctx->pc = 0x1BFE3Cu;
    // 0x1bfe3c: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bfe3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bfe40: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bfe40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bfe44: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1bfe44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1bfe48: 0x8e080088  lw          $t0, 0x88($s0)
    ctx->pc = 0x1bfe48u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 136)));
    // 0x1bfe4c: 0x8e06009c  lw          $a2, 0x9C($s0)
    ctx->pc = 0x1bfe4cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 156)));
    // 0x1bfe50: 0x26050044  addiu       $a1, $s0, 0x44
    ctx->pc = 0x1bfe50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x1bfe54: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bfe54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bfe58: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bfe58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bfe5c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1bfe5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bfe60: 0xc0604c4  jal         func_181310
    ctx->pc = 0x1BFE60u;
    SET_GPR_U32(ctx, 31, 0x1BFE68u);
    ctx->pc = 0x1BFE64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFE60u;
            // 0x1bfe64: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181310u;
    if (runtime->hasFunction(0x181310u)) {
        auto targetFn = runtime->lookupFunction(0x181310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFE68u; }
        if (ctx->pc != 0x1BFE68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181310_0x181310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFE68u; }
        if (ctx->pc != 0x1BFE68u) { return; }
    }
    ctx->pc = 0x1BFE68u;
label_1bfe68:
    // 0x1bfe68: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFE68u;
    {
        const bool branch_taken_0x1bfe68 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1bfe68) {
            ctx->pc = 0x1BFE78u;
            goto label_1bfe78;
        }
    }
    ctx->pc = 0x1BFE70u;
    // 0x1bfe70: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1BFE70u;
    {
        const bool branch_taken_0x1bfe70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFE70u;
            // 0x1bfe74: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfe70) {
            ctx->pc = 0x1BFEACu;
            goto label_1bfeac;
        }
    }
    ctx->pc = 0x1BFE78u;
label_1bfe78:
    // 0x1bfe78: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1bfe78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bfe7c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bfe7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bfe80: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1BFE80u;
    {
        const bool branch_taken_0x1bfe80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFE84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFE80u;
            // 0x1bfe84: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfe80) {
            ctx->pc = 0x1BFEA8u;
            goto label_1bfea8;
        }
    }
    ctx->pc = 0x1BFE88u;
label_1bfe88:
    // 0x1bfe88: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFE88u;
    SET_GPR_U32(ctx, 31, 0x1BFE90u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFE90u; }
        if (ctx->pc != 0x1BFE90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFE90u; }
        if (ctx->pc != 0x1BFE90u) { return; }
    }
    ctx->pc = 0x1BFE90u;
label_1bfe90:
    // 0x1bfe90: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BFE90u;
    {
        const bool branch_taken_0x1bfe90 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfe90) {
            ctx->pc = 0x1BFEA8u;
            goto label_1bfea8;
        }
    }
    ctx->pc = 0x1BFE98u;
    // 0x1bfe98: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bfe98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bfe9c: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1bfe9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bfea0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1BFEA0u;
    {
        const bool branch_taken_0x1bfea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFEA0u;
            // 0x1bfea4: 0x40102a  slt         $v0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfea0) {
            ctx->pc = 0x1BFEACu;
            goto label_1bfeac;
        }
    }
    ctx->pc = 0x1BFEA8u;
label_1bfea8:
    // 0x1bfea8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1bfea8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1bfeac:
    // 0x1bfeac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bfeacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bfeb0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bfeb0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bfeb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1BFEB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BFEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFEB4u;
            // 0x1bfeb8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BFE2Cu: goto label_1bfe2c;
            case 0x1BFE34u: goto label_1bfe34;
            case 0x1BFE68u: goto label_1bfe68;
            case 0x1BFE78u: goto label_1bfe78;
            case 0x1BFE88u: goto label_1bfe88;
            case 0x1BFE90u: goto label_1bfe90;
            case 0x1BFEA8u: goto label_1bfea8;
            case 0x1BFEACu: goto label_1bfeac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BFEBCu;
    // 0x1bfebc: 0x0  nop
    ctx->pc = 0x1bfebcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
