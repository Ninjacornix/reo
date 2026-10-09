#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2C00
// Address: 0x1d2c00 - 0x1d2cb0
void sub_001D2C00_0x1d2c00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2C00_0x1d2c00");
#endif

    switch (ctx->pc) {
        case 0x1d2c3cu: goto label_1d2c3c;
        case 0x1d2c44u: goto label_1d2c44;
        case 0x1d2c50u: goto label_1d2c50;
        case 0x1d2c58u: goto label_1d2c58;
        case 0x1d2c64u: goto label_1d2c64;
        case 0x1d2c6cu: goto label_1d2c6c;
        case 0x1d2c94u: goto label_1d2c94;
        default: break;
    }

    ctx->pc = 0x1d2c00u;

    // 0x1d2c00: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d2c00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d2c04: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d2c04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2c08: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d2c08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d2c0c: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1d2c0cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2c10: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d2c10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d2c14: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1d2c14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1d2c18: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d2c18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d2c1c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d2c1cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2c20: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d2c20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d2c24: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d2c24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d2c28: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d2c28u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2c2c: 0x8c910000  lw          $s1, 0x0($a0)
    ctx->pc = 0x1d2c2cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d2c30: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x1d2c30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1d2c34: 0xc074d50  jal         func_1D3540
    ctx->pc = 0x1D2C34u;
    SET_GPR_U32(ctx, 31, 0x1D2C3Cu);
    ctx->pc = 0x1D2C38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2C34u;
            // 0x1d2c38: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3540u;
    if (runtime->hasFunction(0x1D3540u)) {
        auto targetFn = runtime->lookupFunction(0x1D3540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C3Cu; }
        if (ctx->pc != 0x1D2C3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3540_0x1d3540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C3Cu; }
        if (ctx->pc != 0x1D2C3Cu) { return; }
    }
    ctx->pc = 0x1D2C3Cu;
label_1d2c3c:
    // 0x1d2c3c: 0xc064920  jal         func_192480
    ctx->pc = 0x1D2C3Cu;
    SET_GPR_U32(ctx, 31, 0x1D2C44u);
    ctx->pc = 0x1D2C40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2C3Cu;
            // 0x1d2c40: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192480u;
    if (runtime->hasFunction(0x192480u)) {
        auto targetFn = runtime->lookupFunction(0x192480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C44u; }
        if (ctx->pc != 0x1D2C44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192480_0x192480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C44u; }
        if (ctx->pc != 0x1D2C44u) { return; }
    }
    ctx->pc = 0x1D2C44u;
label_1d2c44:
    // 0x1d2c44: 0xae02080c  sw          $v0, 0x80C($s0)
    ctx->pc = 0x1d2c44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2060), GPR_U32(ctx, 2));
    // 0x1d2c48: 0xc06c430  jal         func_1B10C0
    ctx->pc = 0x1D2C48u;
    SET_GPR_U32(ctx, 31, 0x1D2C50u);
    ctx->pc = 0x1D2C4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2C48u;
            // 0x1d2c4c: 0x8e04080c  lw          $a0, 0x80C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B10C0u;
    if (runtime->hasFunction(0x1B10C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B10C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C50u; }
        if (ctx->pc != 0x1D2C50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B10C0_0x1b10c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C50u; }
        if (ctx->pc != 0x1D2C50u) { return; }
    }
    ctx->pc = 0x1D2C50u;
label_1d2c50:
    // 0x1d2c50: 0xc064c00  jal         func_193000
    ctx->pc = 0x1D2C50u;
    SET_GPR_U32(ctx, 31, 0x1D2C58u);
    ctx->pc = 0x1D2C54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2C50u;
            // 0x1d2c54: 0x8e04080c  lw          $a0, 0x80C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193000u;
    if (runtime->hasFunction(0x193000u)) {
        auto targetFn = runtime->lookupFunction(0x193000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C58u; }
        if (ctx->pc != 0x1D2C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193000_0x193000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C58u; }
        if (ctx->pc != 0x1D2C58u) { return; }
    }
    ctx->pc = 0x1D2C58u;
label_1d2c58:
    // 0x1d2c58: 0xa6020816  sh          $v0, 0x816($s0)
    ctx->pc = 0x1d2c58u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2070), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d2c5c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D2C5Cu;
    {
        const bool branch_taken_0x1d2c5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2C5Cu;
            // 0x1d2c60: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2c5c) {
            ctx->pc = 0x1D2C78u;
            goto label_1d2c78;
        }
    }
    ctx->pc = 0x1D2C64u;
label_1d2c64:
    // 0x1d2c64: 0xc06c498  jal         func_1B1260
    ctx->pc = 0x1D2C64u;
    SET_GPR_U32(ctx, 31, 0x1D2C6Cu);
    ctx->pc = 0x1B1260u;
    if (runtime->hasFunction(0x1B1260u)) {
        auto targetFn = runtime->lookupFunction(0x1B1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C6Cu; }
        if (ctx->pc != 0x1D2C6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1260_0x1b1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C6Cu; }
        if (ctx->pc != 0x1D2C6Cu) { return; }
    }
    ctx->pc = 0x1D2C6Cu;
label_1d2c6c:
    // 0x1d2c6c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1d2c6cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1d2c70: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1d2c70u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1d2c74: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x1d2c74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_1d2c78:
    // 0x1d2c78: 0x96020816  lhu         $v0, 0x816($s0)
    ctx->pc = 0x1d2c78u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2070)));
    // 0x1d2c7c: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x1d2c7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d2c80: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1D2C80u;
    {
        const bool branch_taken_0x1d2c80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d2c80) {
            ctx->pc = 0x1D2C64u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2c64;
        }
    }
    ctx->pc = 0x1D2C88u;
    // 0x1d2c88: 0x8e05080c  lw          $a1, 0x80C($s0)
    ctx->pc = 0x1d2c88u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2060)));
    // 0x1d2c8c: 0xc064d60  jal         func_193580
    ctx->pc = 0x1D2C8Cu;
    SET_GPR_U32(ctx, 31, 0x1D2C94u);
    ctx->pc = 0x1D2C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2C8Cu;
            // 0x1d2c90: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193580u;
    if (runtime->hasFunction(0x193580u)) {
        auto targetFn = runtime->lookupFunction(0x193580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C94u; }
        if (ctx->pc != 0x1D2C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193580_0x193580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2C94u; }
        if (ctx->pc != 0x1D2C94u) { return; }
    }
    ctx->pc = 0x1D2C94u;
label_1d2c94:
    // 0x1d2c94: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d2c94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d2c98: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d2c98u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2c9c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d2c9cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d2ca0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d2ca0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2ca4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2CA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2CA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2CA4u;
            // 0x1d2ca8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2C3Cu: goto label_1d2c3c;
            case 0x1D2C44u: goto label_1d2c44;
            case 0x1D2C50u: goto label_1d2c50;
            case 0x1D2C58u: goto label_1d2c58;
            case 0x1D2C64u: goto label_1d2c64;
            case 0x1D2C6Cu: goto label_1d2c6c;
            case 0x1D2C78u: goto label_1d2c78;
            case 0x1D2C94u: goto label_1d2c94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2CACu;
    // 0x1d2cac: 0x0  nop
    ctx->pc = 0x1d2cacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
