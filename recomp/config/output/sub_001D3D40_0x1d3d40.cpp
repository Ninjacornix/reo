#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3D40
// Address: 0x1d3d40 - 0x1d3db8
void sub_001D3D40_0x1d3d40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3D40_0x1d3d40");
#endif

    switch (ctx->pc) {
        case 0x1d3d64u: goto label_1d3d64;
        case 0x1d3d6cu: goto label_1d3d6c;
        case 0x1d3d74u: goto label_1d3d74;
        case 0x1d3da4u: goto label_1d3da4;
        default: break;
    }

    ctx->pc = 0x1d3d40u;

    // 0x1d3d40: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d3d40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d3d44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3d44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3d48: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d3d48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d3d4c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3d4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3d50: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3d50u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3d54: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d3d54u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3d58: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d3d58u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d3d5c: 0xc06b3a8  jal         func_1ACEA0
    ctx->pc = 0x1D3D5Cu;
    SET_GPR_U32(ctx, 31, 0x1D3D64u);
    ctx->pc = 0x1D3D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D5Cu;
            // 0x1d3d60: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACEA0u;
    if (runtime->hasFunction(0x1ACEA0u)) {
        auto targetFn = runtime->lookupFunction(0x1ACEA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D64u; }
        if (ctx->pc != 0x1D3D64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACEA0_0x1acea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D64u; }
        if (ctx->pc != 0x1D3D64u) { return; }
    }
    ctx->pc = 0x1D3D64u;
label_1d3d64:
    // 0x1d3d64: 0xc06e0d8  jal         func_1B8360
    ctx->pc = 0x1D3D64u;
    SET_GPR_U32(ctx, 31, 0x1D3D6Cu);
    ctx->pc = 0x1B8360u;
    if (runtime->hasFunction(0x1B8360u)) {
        auto targetFn = runtime->lookupFunction(0x1B8360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D6Cu; }
        if (ctx->pc != 0x1D3D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8360_0x1b8360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D6Cu; }
        if (ctx->pc != 0x1D3D6Cu) { return; }
    }
    ctx->pc = 0x1D3D6Cu;
label_1d3d6c:
    // 0x1d3d6c: 0xc06e0e0  jal         func_1B8380
    ctx->pc = 0x1D3D6Cu;
    SET_GPR_U32(ctx, 31, 0x1D3D74u);
    ctx->pc = 0x1D3D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D6Cu;
            // 0x1d3d70: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8380u;
    if (runtime->hasFunction(0x1B8380u)) {
        auto targetFn = runtime->lookupFunction(0x1B8380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D74u; }
        if (ctx->pc != 0x1D3D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8380_0x1b8380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D74u; }
        if (ctx->pc != 0x1D3D74u) { return; }
    }
    ctx->pc = 0x1D3D74u;
label_1d3d74:
    // 0x1d3d74: 0x2182b  sltu        $v1, $zero, $v0
    ctx->pc = 0x1d3d74u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d3d78: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1d3d78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1d3d7c: 0x0  nop
    ctx->pc = 0x1d3d7cu;
    // NOP
    // 0x1d3d80: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D3D80u;
    {
        const bool branch_taken_0x1d3d80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d3d80) {
            ctx->pc = 0x1D3D6Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3d6c;
        }
    }
    ctx->pc = 0x1D3D88u;
    // 0x1d3d88: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D3D88u;
    {
        const bool branch_taken_0x1d3d88 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1D3D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D88u;
            // 0x1d3d8c: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3d88) {
            ctx->pc = 0x1D3DA4u;
            goto label_1d3da4;
        }
    }
    ctx->pc = 0x1D3D90u;
    // 0x1d3d90: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d3d90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3d94: 0x8c22440c  lw          $v0, 0x440C($at)
    ctx->pc = 0x1d3d94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d3d98: 0x2406000c  addiu       $a2, $zero, 0xC
    ctx->pc = 0x1d3d98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d3d9c: 0xc06b454  jal         func_1AD150
    ctx->pc = 0x1D3D9Cu;
    SET_GPR_U32(ctx, 31, 0x1D3DA4u);
    ctx->pc = 0x1D3DA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D9Cu;
            // 0x1d3da0: 0x24454000  addiu       $a1, $v0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 16384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD150u;
    if (runtime->hasFunction(0x1AD150u)) {
        auto targetFn = runtime->lookupFunction(0x1AD150u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3DA4u; }
        if (ctx->pc != 0x1D3DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD150_0x1ad150(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3DA4u; }
        if (ctx->pc != 0x1D3DA4u) { return; }
    }
    ctx->pc = 0x1D3DA4u;
label_1d3da4:
    // 0x1d3da4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d3da4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3da8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d3da8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3dac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3dacu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3db0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3DB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3DB0u;
            // 0x1d3db4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3D64u: goto label_1d3d64;
            case 0x1D3D6Cu: goto label_1d3d6c;
            case 0x1D3D74u: goto label_1d3d74;
            case 0x1D3DA4u: goto label_1d3da4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3DB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
