#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101D08
// Address: 0x101d08 - 0x101e00
void sub_00101D08_0x101d08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101D08_0x101d08");
#endif

    switch (ctx->pc) {
        case 0x101d2cu: goto label_101d2c;
        case 0x101d50u: goto label_101d50;
        case 0x101d84u: goto label_101d84;
        case 0x101d98u: goto label_101d98;
        case 0x101dccu: goto label_101dcc;
        case 0x101de0u: goto label_101de0;
        default: break;
    }

    ctx->pc = 0x101d08u;

    // 0x101d08: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x101d08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x101d0c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x101d0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x101d10: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x101d10u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101d14: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x101d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x101d18: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x101d18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x101d1c: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x101d1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x101d20: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x101d20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x101d24: 0xc0403a2  jal         func_100E88
    ctx->pc = 0x101D24u;
    SET_GPR_U32(ctx, 31, 0x101D2Cu);
    ctx->pc = 0x101D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101D24u;
            // 0x101d28: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100E88u;
    if (runtime->hasFunction(0x100E88u)) {
        auto targetFn = runtime->lookupFunction(0x100E88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101D2Cu; }
        if (ctx->pc != 0x101D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E88_0x100e88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101D2Cu; }
        if (ctx->pc != 0x101D2Cu) { return; }
    }
    ctx->pc = 0x101D2Cu;
label_101d2c:
    // 0x101d2c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101D2Cu;
    {
        const bool branch_taken_0x101d2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x101D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101D2Cu;
            // 0x101d30: 0x3c130020  lui         $s3, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101d2c) {
            ctx->pc = 0x101D3Cu;
            goto label_101d3c;
        }
    }
    ctx->pc = 0x101D34u;
    // 0x101d34: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x101D34u;
    {
        const bool branch_taken_0x101d34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101D34u;
            // 0x101d38: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101d34) {
            ctx->pc = 0x101DE4u;
            goto label_101de4;
        }
    }
    ctx->pc = 0x101D3Cu;
label_101d3c:
    // 0x101d3c: 0x8e627910  lw          $v0, 0x7910($s3)
    ctx->pc = 0x101d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 30992)));
    // 0x101d40: 0x18400003  blez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101D40u;
    {
        const bool branch_taken_0x101d40 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x101D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101D40u;
            // 0x101d44: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101d40) {
            ctx->pc = 0x101D50u;
            goto label_101d50;
        }
    }
    ctx->pc = 0x101D48u;
    // 0x101d48: 0xc045a12  jal         func_116848
    ctx->pc = 0x101D48u;
    SET_GPR_U32(ctx, 31, 0x101D50u);
    ctx->pc = 0x101D4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101D48u;
            // 0x101d4c: 0x24847678  addiu       $a0, $a0, 0x7678 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101D50u; }
        if (ctx->pc != 0x101D50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101D50u; }
        if (ctx->pc != 0x101D50u) { return; }
    }
    ctx->pc = 0x101D50u;
label_101d50:
    // 0x101d50: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x101d50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x101d54: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x101d54u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x101d58: 0x24508b00  addiu       $s0, $v0, -0x7500
    ctx->pc = 0x101d58u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937344));
    // 0x101d5c: 0x24849480  addiu       $a0, $a0, -0x6B80
    ctx->pc = 0x101d5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294939776));
    // 0x101d60: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x101d60u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x101d64: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x101d64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101d68: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x101d68u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101d6c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x101d6cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101d70: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x101d70u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101d74: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x101d74u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101d78: 0x240a0010  addiu       $t2, $zero, 0x10
    ctx->pc = 0x101d78u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x101d7c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x101D7Cu;
    SET_GPR_U32(ctx, 31, 0x101D84u);
    ctx->pc = 0x101D80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101D7Cu;
            // 0x101d80: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101D84u; }
        if (ctx->pc != 0x101D84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101D84u; }
        if (ctx->pc != 0x101D84u) { return; }
    }
    ctx->pc = 0x101D84u;
label_101d84:
    // 0x101d84: 0x4430006  bgezl       $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x101D84u;
    {
        const bool branch_taken_0x101d84 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x101d84) {
            ctx->pc = 0x101D88u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x101D84u;
            // 0x101d88: 0x26020004  addiu       $v0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x101DA0u;
            goto label_101da0;
        }
    }
    ctx->pc = 0x101D8Cu;
    // 0x101d8c: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101d90: 0xc045190  jal         func_114640
    ctx->pc = 0x101D90u;
    SET_GPR_U32(ctx, 31, 0x101D98u);
    ctx->pc = 0x101D94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101D90u;
            // 0x101d94: 0x8c44792c  lw          $a0, 0x792C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31020)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101D98u; }
        if (ctx->pc != 0x101D98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101D98u; }
        if (ctx->pc != 0x101D98u) { return; }
    }
    ctx->pc = 0x101D98u;
label_101d98:
    // 0x101d98: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x101D98u;
    {
        const bool branch_taken_0x101d98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101D98u;
            // 0x101d9c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101d98) {
            ctx->pc = 0x101DE4u;
            goto label_101de4;
        }
    }
    ctx->pc = 0x101DA0u;
label_101da0:
    // 0x101da0: 0x3c112000  lui         $s1, 0x2000
    ctx->pc = 0x101da0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)8192 << 16));
    // 0x101da4: 0x511025  or          $v0, $v0, $s1
    ctx->pc = 0x101da4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 17));
    // 0x101da8: 0x68430007  ldl         $v1, 0x7($v0)
    ctx->pc = 0x101da8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x101dac: 0x6c430000  ldr         $v1, 0x0($v0)
    ctx->pc = 0x101dacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x101db0: 0xb2430007  sdl         $v1, 0x7($s2)
    ctx->pc = 0x101db0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x101db4: 0xb6430000  sdr         $v1, 0x0($s2)
    ctx->pc = 0x101db4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x101db8: 0x8e637910  lw          $v1, 0x7910($s3)
    ctx->pc = 0x101db8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 30992)));
    // 0x101dbc: 0x18600003  blez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x101DBCu;
    {
        const bool branch_taken_0x101dbc = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x101DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101DBCu;
            // 0x101dc0: 0x3c040023  lui         $a0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101dbc) {
            ctx->pc = 0x101DCCu;
            goto label_101dcc;
        }
    }
    ctx->pc = 0x101DC4u;
    // 0x101dc4: 0xc045a12  jal         func_116848
    ctx->pc = 0x101DC4u;
    SET_GPR_U32(ctx, 31, 0x101DCCu);
    ctx->pc = 0x101DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101DC4u;
            // 0x101dc8: 0x24847698  addiu       $a0, $a0, 0x7698 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 30360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101DCCu; }
        if (ctx->pc != 0x101DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101DCCu; }
        if (ctx->pc != 0x101DCCu) { return; }
    }
    ctx->pc = 0x101DCCu;
label_101dcc:
    // 0x101dcc: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101dccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101dd0: 0x2111825  or          $v1, $s0, $s1
    ctx->pc = 0x101dd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) | GPR_U64(ctx, 17));
    // 0x101dd4: 0x8c44792c  lw          $a0, 0x792C($v0)
    ctx->pc = 0x101dd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31020)));
    // 0x101dd8: 0xc045190  jal         func_114640
    ctx->pc = 0x101DD8u;
    SET_GPR_U32(ctx, 31, 0x101DE0u);
    ctx->pc = 0x101DDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101DD8u;
            // 0x101ddc: 0x8c700000  lw          $s0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101DE0u; }
        if (ctx->pc != 0x101DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101DE0u; }
        if (ctx->pc != 0x101DE0u) { return; }
    }
    ctx->pc = 0x101DE0u;
label_101de0:
    // 0x101de0: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101de0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101de4:
    // 0x101de4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x101de4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x101de8: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x101de8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x101dec: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x101decu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101df0: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x101df0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101df4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x101df4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101df8: 0x3e00008  jr          $ra
    ctx->pc = 0x101DF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101DF8u;
            // 0x101dfc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101D2Cu: goto label_101d2c;
            case 0x101D3Cu: goto label_101d3c;
            case 0x101D50u: goto label_101d50;
            case 0x101D84u: goto label_101d84;
            case 0x101D98u: goto label_101d98;
            case 0x101DA0u: goto label_101da0;
            case 0x101DCCu: goto label_101dcc;
            case 0x101DE0u: goto label_101de0;
            case 0x101DE4u: goto label_101de4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101E00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
