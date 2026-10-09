#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9DA0
// Address: 0x1d9da0 - 0x1da078
void sub_001D9DA0_0x1d9da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9DA0_0x1d9da0");
#endif

    switch (ctx->pc) {
        case 0x1d9e28u: goto label_1d9e28;
        case 0x1d9e30u: goto label_1d9e30;
        case 0x1d9e60u: goto label_1d9e60;
        case 0x1d9e70u: goto label_1d9e70;
        case 0x1d9ea0u: goto label_1d9ea0;
        case 0x1d9eb4u: goto label_1d9eb4;
        case 0x1d9ef8u: goto label_1d9ef8;
        case 0x1d9f90u: goto label_1d9f90;
        case 0x1d9fd4u: goto label_1d9fd4;
        default: break;
    }

    ctx->pc = 0x1d9da0u;

    // 0x1d9da0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1d9da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d9da4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1d9da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1d9da8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1d9da8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1d9dac: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d9dacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d9db0: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x1d9db0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9db4: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d9db4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d9db8: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x1d9db8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9dbc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d9dbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d9dc0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d9dc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d9dc4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d9dc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d9dc8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d9dc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d9dcc: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9DCCu;
    {
        const bool branch_taken_0x1d9dcc = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1D9DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9DCCu;
            // 0x1d9dd0: 0xa7a0008e  sh          $zero, 0x8E($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 142), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9dcc) {
            ctx->pc = 0x1D9DE0u;
            goto label_1d9de0;
        }
    }
    ctx->pc = 0x1D9DD4u;
    // 0x1d9dd4: 0x28820003  slti        $v0, $a0, 0x3
    ctx->pc = 0x1d9dd4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d9dd8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D9DD8u;
    {
        const bool branch_taken_0x1d9dd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9dd8) {
            ctx->pc = 0x1D9DF8u;
            goto label_1d9df8;
        }
    }
    ctx->pc = 0x1D9DE0u;
label_1d9de0:
    // 0x1d9de0: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1d9de0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d9de4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9de4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9de8: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1d9de8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1d9dec: 0x10000098  b           . + 4 + (0x98 << 2)
    ctx->pc = 0x1D9DECu;
    {
        const bool branch_taken_0x1d9dec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9DECu;
            // 0x1d9df0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9dec) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9DF4u;
    // 0x1d9df4: 0x0  nop
    ctx->pc = 0x1d9df4u;
    // NOP
label_1d9df8:
    // 0x1d9df8: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9df8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9dfc: 0x49080  sll         $s2, $a0, 2
    ctx->pc = 0x1d9dfcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d9e00: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9e00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d9e04: 0x528021  addu        $s0, $v0, $s2
    ctx->pc = 0x1d9e04u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1d9e08: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1d9e08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d9e0c: 0x441008c  bgez        $v0, . + 4 + (0x8C << 2)
    ctx->pc = 0x1D9E0Cu;
    {
        const bool branch_taken_0x1d9e0c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D9E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E0Cu;
            // 0x1d9e10: 0x24030009  addiu       $v1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e0c) {
            ctx->pc = 0x1DA040u;
            goto label_1da040;
        }
    }
    ctx->pc = 0x1D9E14u;
    // 0x1d9e14: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9e14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9e18: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9e1c: 0x1000008c  b           . + 4 + (0x8C << 2)
    ctx->pc = 0x1D9E1Cu;
    {
        const bool branch_taken_0x1d9e1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E1Cu;
            // 0x1d9e20: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e1c) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9E24u;
    // 0x1d9e24: 0x0  nop
    ctx->pc = 0x1d9e24u;
    // NOP
label_1d9e28:
    // 0x1d9e28: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9E28u;
    SET_GPR_U32(ctx, 31, 0x1D9E30u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E30u; }
        if (ctx->pc != 0x1D9E30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E30u; }
        if (ctx->pc != 0x1D9E30u) { return; }
    }
    ctx->pc = 0x1D9E30u;
label_1d9e30:
    // 0x1d9e30: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1d9e30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d9e34: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d9e34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d9e38: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D9E38u;
    {
        const bool branch_taken_0x1d9e38 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D9E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E38u;
            // 0x1d9e3c: 0x3c020035  lui         $v0, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e38) {
            ctx->pc = 0x1D9E68u;
            goto label_1d9e68;
        }
    }
    ctx->pc = 0x1D9E40u;
    // 0x1d9e40: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d9e40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9e44: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d9e44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d9e48: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9e48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9e4c: 0x521821  addu        $v1, $v0, $s2
    ctx->pc = 0x1d9e4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1d9e50: 0x24020071  addiu       $v0, $zero, 0x71
    ctx->pc = 0x1d9e50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
    // 0x1d9e54: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1d9e54u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1d9e58: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9E58u;
    SET_GPR_U32(ctx, 31, 0x1D9E60u);
    ctx->pc = 0x1D9E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E58u;
            // 0x1d9e5c: 0xac228c88  sw          $v0, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E60u; }
        if (ctx->pc != 0x1D9E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E60u; }
        if (ctx->pc != 0x1D9E60u) { return; }
    }
    ctx->pc = 0x1D9E60u;
label_1d9e60:
    // 0x1d9e60: 0x1000007b  b           . + 4 + (0x7B << 2)
    ctx->pc = 0x1D9E60u;
    {
        const bool branch_taken_0x1d9e60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E60u;
            // 0x1d9e64: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e60) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9E68u;
label_1d9e68:
    // 0x1d9e68: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9E68u;
    SET_GPR_U32(ctx, 31, 0x1D9E70u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E70u; }
        if (ctx->pc != 0x1D9E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9E70u; }
        if (ctx->pc != 0x1D9E70u) { return; }
    }
    ctx->pc = 0x1D9E70u;
label_1d9e70:
    // 0x1d9e70: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1d9e70u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9e74: 0x280182d  daddu       $v1, $s4, $zero
    ctx->pc = 0x1d9e74u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9e78: 0x26820001  addiu       $v0, $s4, 0x1
    ctx->pc = 0x1d9e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1d9e7c: 0x2a43c  dsll32      $s4, $v0, 16
    ctx->pc = 0x1d9e7cu;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9e80: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1d9e80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d9e84: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9e84u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9e88: 0x284141a0  slti        $at, $v0, 0x41A0
    ctx->pc = 0x1d9e88u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1d9e8c: 0x10200022  beqz        $at, . + 4 + (0x22 << 2)
    ctx->pc = 0x1D9E8Cu;
    {
        const bool branch_taken_0x1d9e8c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9E8Cu;
            // 0x1d9e90: 0x14a43f  dsra32      $s4, $s4, 16 (Delay Slot)
        SET_GPR_S64(ctx, 20, GPR_S64(ctx, 20) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9e8c) {
            ctx->pc = 0x1D9F18u;
            goto label_1d9f18;
        }
    }
    ctx->pc = 0x1D9E94u;
    // 0x1d9e94: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9e94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9e98: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d9e9c: 0x529821  addu        $s3, $v0, $s2
    ctx->pc = 0x1d9e9cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_1d9ea0:
    // 0x1d9ea0: 0x86640000  lh          $a0, 0x0($s3)
    ctx->pc = 0x1d9ea0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d9ea4: 0x27a5008e  addiu       $a1, $sp, 0x8E
    ctx->pc = 0x1d9ea4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 142));
    // 0x1d9ea8: 0x27a6008c  addiu       $a2, $sp, 0x8C
    ctx->pc = 0x1d9ea8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 140));
    // 0x1d9eac: 0xc075f48  jal         func_1D7D20
    ctx->pc = 0x1D9EACu;
    SET_GPR_U32(ctx, 31, 0x1D9EB4u);
    ctx->pc = 0x1D9EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9EACu;
            // 0x1d9eb0: 0x27a7008a  addiu       $a3, $sp, 0x8A (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 138));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7D20u;
    if (runtime->hasFunction(0x1D7D20u)) {
        auto targetFn = runtime->lookupFunction(0x1D7D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9EB4u; }
        if (ctx->pc != 0x1D9EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7D20_0x1d7d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9EB4u; }
        if (ctx->pc != 0x1D9EB4u) { return; }
    }
    ctx->pc = 0x1D9EB4u;
label_1d9eb4:
    // 0x1d9eb4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d9eb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9eb8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9eb8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9ebc: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9EBCu;
    {
        const bool branch_taken_0x1d9ebc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D9EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9EBCu;
            // 0x1d9ec0: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9ebc) {
            ctx->pc = 0x1D9ED8u;
            goto label_1d9ed8;
        }
    }
    ctx->pc = 0x1D9EC4u;
    // 0x1d9ec4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9ec4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9ec8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9ecc: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1D9ECCu;
    {
        const bool branch_taken_0x1d9ecc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9ECCu;
            // 0x1d9ed0: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9ecc) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9ED4u;
    // 0x1d9ed4: 0x0  nop
    ctx->pc = 0x1d9ed4u;
    // NOP
label_1d9ed8:
    // 0x1d9ed8: 0x87a3008e  lh          $v1, 0x8E($sp)
    ctx->pc = 0x1d9ed8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 142)));
    // 0x1d9edc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1d9edcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d9ee0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9EE0u;
    {
        const bool branch_taken_0x1d9ee0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9EE0u;
            // 0x1d9ee4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9ee0) {
            ctx->pc = 0x1D9EF0u;
            goto label_1d9ef0;
        }
    }
    ctx->pc = 0x1D9EE8u;
    // 0x1d9ee8: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D9EE8u;
    {
        const bool branch_taken_0x1d9ee8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9ee8) {
            ctx->pc = 0x1D9F18u;
            goto label_1d9f18;
        }
    }
    ctx->pc = 0x1D9EF0u;
label_1d9ef0:
    // 0x1d9ef0: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1D9EF0u;
    SET_GPR_U32(ctx, 31, 0x1D9EF8u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9EF8u; }
        if (ctx->pc != 0x1D9EF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9EF8u; }
        if (ctx->pc != 0x1D9EF8u) { return; }
    }
    ctx->pc = 0x1D9EF8u;
label_1d9ef8:
    // 0x1d9ef8: 0x280182d  daddu       $v1, $s4, $zero
    ctx->pc = 0x1d9ef8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9efc: 0x26820001  addiu       $v0, $s4, 0x1
    ctx->pc = 0x1d9efcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1d9f00: 0x2a43c  dsll32      $s4, $v0, 16
    ctx->pc = 0x1d9f00u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9f04: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1d9f04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d9f08: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9f08u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9f0c: 0x284241a0  slti        $v0, $v0, 0x41A0
    ctx->pc = 0x1d9f0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1d9f10: 0x1440ffe3  bnez        $v0, . + 4 + (-0x1D << 2)
    ctx->pc = 0x1D9F10u;
    {
        const bool branch_taken_0x1d9f10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9F10u;
            // 0x1d9f14: 0x14a43f  dsra32      $s4, $s4, 16 (Delay Slot)
        SET_GPR_S64(ctx, 20, GPR_S64(ctx, 20) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9f10) {
            ctx->pc = 0x1D9EA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9ea0;
        }
    }
    ctx->pc = 0x1D9F18u;
label_1d9f18:
    // 0x1d9f18: 0x87a4008e  lh          $a0, 0x8E($sp)
    ctx->pc = 0x1d9f18u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 142)));
    // 0x1d9f1c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1d9f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d9f20: 0x14820007  bne         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D9F20u;
    {
        const bool branch_taken_0x1d9f20 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9f20) {
            ctx->pc = 0x1D9F40u;
            goto label_1d9f40;
        }
    }
    ctx->pc = 0x1D9F28u;
    // 0x1d9f28: 0x87a3008a  lh          $v1, 0x8A($sp)
    ctx->pc = 0x1d9f28u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1d9f2c: 0x14600012  bnez        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1D9F2Cu;
    {
        const bool branch_taken_0x1d9f2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f2c) {
            ctx->pc = 0x1D9F78u;
            goto label_1d9f78;
        }
    }
    ctx->pc = 0x1D9F34u;
    // 0x1d9f34: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D9F34u;
    {
        const bool branch_taken_0x1d9f34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f34) {
            ctx->pc = 0x1D9F98u;
            goto label_1d9f98;
        }
    }
    ctx->pc = 0x1D9F3Cu;
    // 0x1d9f3c: 0x0  nop
    ctx->pc = 0x1d9f3cu;
    // NOP
label_1d9f40:
    // 0x1d9f40: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9f44: 0x14820006  bne         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9F44u;
    {
        const bool branch_taken_0x1d9f44 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9f44) {
            ctx->pc = 0x1D9F60u;
            goto label_1d9f60;
        }
    }
    ctx->pc = 0x1D9F4Cu;
    // 0x1d9f4c: 0x87a3008a  lh          $v1, 0x8A($sp)
    ctx->pc = 0x1d9f4cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1d9f50: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D9F50u;
    {
        const bool branch_taken_0x1d9f50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f50) {
            ctx->pc = 0x1D9F78u;
            goto label_1d9f78;
        }
    }
    ctx->pc = 0x1D9F58u;
    // 0x1d9f58: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1D9F58u;
    {
        const bool branch_taken_0x1d9f58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f58) {
            ctx->pc = 0x1D9F98u;
            goto label_1d9f98;
        }
    }
    ctx->pc = 0x1D9F60u;
label_1d9f60:
    // 0x1d9f60: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1d9f60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d9f64: 0x10830004  beq         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9F64u;
    {
        const bool branch_taken_0x1d9f64 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1D9F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9F64u;
            // 0x1d9f68: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9f64) {
            ctx->pc = 0x1D9F78u;
            goto label_1d9f78;
        }
    }
    ctx->pc = 0x1D9F6Cu;
    // 0x1d9f6c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9f6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9f70: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x1D9F70u;
    {
        const bool branch_taken_0x1d9f70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9F70u;
            // 0x1d9f74: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9f70) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9F78u;
label_1d9f78:
    // 0x1d9f78: 0x87a3008a  lh          $v1, 0x8A($sp)
    ctx->pc = 0x1d9f78u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1d9f7c: 0x3102a  slt         $v0, $zero, $v1
    ctx->pc = 0x1d9f7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d9f80: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9F80u;
    {
        const bool branch_taken_0x1d9f80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f80) {
            ctx->pc = 0x1D9F98u;
            goto label_1d9f98;
        }
    }
    ctx->pc = 0x1D9F88u;
    // 0x1d9f88: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1D9F88u;
    SET_GPR_U32(ctx, 31, 0x1D9F90u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9F90u; }
        if (ctx->pc != 0x1D9F90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9F90u; }
        if (ctx->pc != 0x1D9F90u) { return; }
    }
    ctx->pc = 0x1D9F90u;
label_1d9f90:
    // 0x1d9f90: 0x1000ffa5  b           . + 4 + (-0x5B << 2)
    ctx->pc = 0x1D9F90u;
    {
        const bool branch_taken_0x1d9f90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9f90) {
            ctx->pc = 0x1D9E28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9e28;
        }
    }
    ctx->pc = 0x1D9F98u;
label_1d9f98:
    // 0x1d9f98: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9F98u;
    {
        const bool branch_taken_0x1d9f98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9F98u;
            // 0x1d9f9c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9f98) {
            ctx->pc = 0x1D9FA8u;
            goto label_1d9fa8;
        }
    }
    ctx->pc = 0x1D9FA0u;
    // 0x1d9fa0: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1D9FA0u;
    {
        const bool branch_taken_0x1d9fa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9fa0) {
            ctx->pc = 0x1DA030u;
            goto label_1da030;
        }
    }
    ctx->pc = 0x1D9FA8u;
label_1d9fa8:
    // 0x1d9fa8: 0x75082b  sltu        $at, $v1, $s5
    ctx->pc = 0x1d9fa8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 21)) ? 1 : 0);
    // 0x1d9fac: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9FACu;
    {
        const bool branch_taken_0x1d9fac = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d9fac) {
            ctx->pc = 0x1D9FC0u;
            goto label_1d9fc0;
        }
    }
    ctx->pc = 0x1D9FB4u;
    // 0x1d9fb4: 0x3ac3c  dsll32      $s5, $v1, 16
    ctx->pc = 0x1d9fb4u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d9fb8: 0x15ac3f  dsra32      $s5, $s5, 16
    ctx->pc = 0x1d9fb8u;
    SET_GPR_S64(ctx, 21, GPR_S64(ctx, 21) >> (32 + 16));
    // 0x1d9fbc: 0x0  nop
    ctx->pc = 0x1d9fbcu;
    // NOP
label_1d9fc0:
    // 0x1d9fc0: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1d9fc0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d9fc4: 0x15343c  dsll32      $a2, $s5, 16
    ctx->pc = 0x1d9fc4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 21) << (32 + 16));
    // 0x1d9fc8: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x1d9fc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9fcc: 0xc075fd8  jal         func_1D7F60
    ctx->pc = 0x1D9FCCu;
    SET_GPR_U32(ctx, 31, 0x1D9FD4u);
    ctx->pc = 0x1D9FD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9FCCu;
            // 0x1d9fd0: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7F60u;
    if (runtime->hasFunction(0x1D7F60u)) {
        auto targetFn = runtime->lookupFunction(0x1D7F60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9FD4u; }
        if (ctx->pc != 0x1D9FD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7F60_0x1d7f60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9FD4u; }
        if (ctx->pc != 0x1D9FD4u) { return; }
    }
    ctx->pc = 0x1D9FD4u;
label_1d9fd4:
    // 0x1d9fd4: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d9fd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9fd8: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1d9fd8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1d9fdc: 0x4810006  bgez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9FDCu;
    {
        const bool branch_taken_0x1d9fdc = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1D9FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9FDCu;
            // 0x1d9fe0: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9fdc) {
            ctx->pc = 0x1D9FF8u;
            goto label_1d9ff8;
        }
    }
    ctx->pc = 0x1D9FE4u;
    // 0x1d9fe4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9fe4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9fe8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9fec: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D9FECu;
    {
        const bool branch_taken_0x1d9fec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9FECu;
            // 0x1d9ff0: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9fec) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1D9FF4u;
    // 0x1d9ff4: 0x0  nop
    ctx->pc = 0x1d9ff4u;
    // NOP
label_1d9ff8:
    // 0x1d9ff8: 0x87a3008e  lh          $v1, 0x8E($sp)
    ctx->pc = 0x1d9ff8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 142)));
    // 0x1d9ffc: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1d9ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1da000: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DA000u;
    {
        const bool branch_taken_0x1da000 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1DA004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA000u;
            // 0x1da004: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da000) {
            ctx->pc = 0x1DA010u;
            goto label_1da010;
        }
    }
    ctx->pc = 0x1DA008u;
    // 0x1da008: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DA008u;
    {
        const bool branch_taken_0x1da008 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1da008) {
            ctx->pc = 0x1DA030u;
            goto label_1da030;
        }
    }
    ctx->pc = 0x1DA010u;
label_1da010:
    // 0x1da010: 0x14950007  bne         $a0, $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x1DA010u;
    {
        const bool branch_taken_0x1da010 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 21));
        if (branch_taken_0x1da010) {
            ctx->pc = 0x1DA030u;
            goto label_1da030;
        }
    }
    ctx->pc = 0x1DA018u;
    // 0x1da018: 0x87a2008a  lh          $v0, 0x8A($sp)
    ctx->pc = 0x1da018u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 138)));
    // 0x1da01c: 0x14820004  bne         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DA01Cu;
    {
        const bool branch_taken_0x1da01c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1DA020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA01Cu;
            // 0x1da020: 0x24020068  addiu       $v0, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da01c) {
            ctx->pc = 0x1DA030u;
            goto label_1da030;
        }
    }
    ctx->pc = 0x1DA024u;
    // 0x1da024: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1da024u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1da028: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1da028u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1da02c: 0x0  nop
    ctx->pc = 0x1da02cu;
    // NOP
label_1da030:
    // 0x1da030: 0x4143c  dsll32      $v0, $a0, 16
    ctx->pc = 0x1da030u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1da034: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1DA034u;
    {
        const bool branch_taken_0x1da034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA034u;
            // 0x1da038: 0x2143f  dsra32      $v0, $v0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da034) {
            ctx->pc = 0x1DA050u;
            goto label_1da050;
        }
    }
    ctx->pc = 0x1DA03Cu;
    // 0x1da03c: 0x0  nop
    ctx->pc = 0x1da03cu;
    // NOP
label_1da040:
    // 0x1da040: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1da040u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1da044: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1da044u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1da048: 0x1000ff77  b           . + 4 + (-0x89 << 2)
    ctx->pc = 0x1DA048u;
    {
        const bool branch_taken_0x1da048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1DA04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA048u;
            // 0x1da04c: 0x528821  addu        $s1, $v0, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1da048) {
            ctx->pc = 0x1D9E28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9e28;
        }
    }
    ctx->pc = 0x1DA050u;
label_1da050:
    // 0x1da050: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1da050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1da054: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1da054u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1da058: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1da058u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1da05c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1da05cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1da060: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1da060u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1da064: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1da064u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1da068: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1da068u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da06c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1da06cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1da070: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1DA074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1DA070u;
            // 0x1da074: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9DE0u: goto label_1d9de0;
            case 0x1D9DF8u: goto label_1d9df8;
            case 0x1D9E28u: goto label_1d9e28;
            case 0x1D9E30u: goto label_1d9e30;
            case 0x1D9E60u: goto label_1d9e60;
            case 0x1D9E68u: goto label_1d9e68;
            case 0x1D9E70u: goto label_1d9e70;
            case 0x1D9EA0u: goto label_1d9ea0;
            case 0x1D9EB4u: goto label_1d9eb4;
            case 0x1D9ED8u: goto label_1d9ed8;
            case 0x1D9EF0u: goto label_1d9ef0;
            case 0x1D9EF8u: goto label_1d9ef8;
            case 0x1D9F18u: goto label_1d9f18;
            case 0x1D9F40u: goto label_1d9f40;
            case 0x1D9F60u: goto label_1d9f60;
            case 0x1D9F78u: goto label_1d9f78;
            case 0x1D9F90u: goto label_1d9f90;
            case 0x1D9F98u: goto label_1d9f98;
            case 0x1D9FA8u: goto label_1d9fa8;
            case 0x1D9FC0u: goto label_1d9fc0;
            case 0x1D9FD4u: goto label_1d9fd4;
            case 0x1D9FF8u: goto label_1d9ff8;
            case 0x1DA010u: goto label_1da010;
            case 0x1DA030u: goto label_1da030;
            case 0x1DA040u: goto label_1da040;
            case 0x1DA050u: goto label_1da050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA078u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
