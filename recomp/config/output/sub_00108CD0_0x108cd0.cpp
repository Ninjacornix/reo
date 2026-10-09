#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108CD0
// Address: 0x108cd0 - 0x108e10
void sub_00108CD0_0x108cd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108CD0_0x108cd0");
#endif

    switch (ctx->pc) {
        case 0x108cf4u: goto label_108cf4;
        case 0x108d04u: goto label_108d04;
        case 0x108d84u: goto label_108d84;
        case 0x108de0u: goto label_108de0;
        case 0x108df0u: goto label_108df0;
        default: break;
    }

    ctx->pc = 0x108cd0u;

    // 0x108cd0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x108cd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x108cd4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x108cd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x108cd8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x108cd8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108cdc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x108cdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108ce0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x108ce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x108ce4: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x108ce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x108ce8: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x108ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x108cec: 0xc04226c  jal         func_1089B0
    ctx->pc = 0x108CECu;
    SET_GPR_U32(ctx, 31, 0x108CF4u);
    ctx->pc = 0x108CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108CECu;
            // 0x108cf0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1089B0u;
    if (runtime->hasFunction(0x1089B0u)) {
        auto targetFn = runtime->lookupFunction(0x1089B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108CF4u; }
        if (ctx->pc != 0x108CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001089B0_0x1089b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108CF4u; }
        if (ctx->pc != 0x108CF4u) { return; }
    }
    ctx->pc = 0x108CF4u;
label_108cf4:
    // 0x108cf4: 0x27a50004  addiu       $a1, $sp, 0x4
    ctx->pc = 0x108cf4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x108cf8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x108cf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108cfc: 0xc04226c  jal         func_1089B0
    ctx->pc = 0x108CFCu;
    SET_GPR_U32(ctx, 31, 0x108D04u);
    ctx->pc = 0x108D00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108CFCu;
            // 0x108d00: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1089B0u;
    if (runtime->hasFunction(0x1089B0u)) {
        auto targetFn = runtime->lookupFunction(0x1089B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108D04u; }
        if (ctx->pc != 0x108D04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001089B0_0x1089b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108D04u; }
        if (ctx->pc != 0x108D04u) { return; }
    }
    ctx->pc = 0x108D04u;
label_108d04:
    // 0x108d04: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x108d04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x108d08: 0x40402d  daddu       $t0, $v0, $zero
    ctx->pc = 0x108d08u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108d0c: 0x8e260010  lw          $a2, 0x10($s1)
    ctx->pc = 0x108d0cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x108d10: 0x12283f  dsra32      $a1, $s2, 0
    ctx->pc = 0x108d10u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 18) >> (32 + 0));
    // 0x108d14: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x108d14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x108d18: 0x8383f  dsra32      $a3, $t0, 0
    ctx->pc = 0x108d18u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 8) >> (32 + 0));
    // 0x108d1c: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x108d1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108d20: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x108d20u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x108d24: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x108d24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x108d28: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x108d28u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x108d2c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x108d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x108d30: 0x22500  sll         $a0, $v0, 20
    ctx->pc = 0x108d30u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 20));
    // 0x108d34: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x108d34u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108d38: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x108d38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x108d3c: 0xe31823  subu        $v1, $a3, $v1
    ctx->pc = 0x108d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x108d40: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x108D40u;
    {
        const bool branch_taken_0x108d40 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x108D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108D40u;
            // 0x108d44: 0x5283c  dsll32      $a1, $a1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108d40) {
            ctx->pc = 0x108D60u;
            goto label_108d60;
        }
    }
    ctx->pc = 0x108D48u;
    // 0x108d48: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x108d48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x108d4c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x108d4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x108d50: 0x2429024  and         $s2, $s2, $v0
    ctx->pc = 0x108d50u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) & GPR_U64(ctx, 2));
    // 0x108d54: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x108D54u;
    {
        const bool branch_taken_0x108d54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108D54u;
            // 0x108d58: 0x2459025  or          $s2, $s2, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108d54) {
            ctx->pc = 0x108D74u;
            goto label_108d74;
        }
    }
    ctx->pc = 0x108D5Cu;
    // 0x108d5c: 0x0  nop
    ctx->pc = 0x108d5cu;
    // NOP
label_108d60:
    // 0x108d60: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x108d60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x108d64: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x108d64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x108d68: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x108d68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x108d6c: 0x1024024  and         $t0, $t0, $v0
    ctx->pc = 0x108d6cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) & GPR_U64(ctx, 2));
    // 0x108d70: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x108d70u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
label_108d74:
    // 0x108d74: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x108d74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108d78: 0x100282d  daddu       $a1, $t0, $zero
    ctx->pc = 0x108d78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108d7c: 0xc04480e  jal         func_112038
    ctx->pc = 0x108D7Cu;
    SET_GPR_U32(ctx, 31, 0x108D84u);
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108D84u; }
        if (ctx->pc != 0x108D84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108D84u; }
        if (ctx->pc != 0x108D84u) { return; }
    }
    ctx->pc = 0x108D84u;
label_108d84:
    // 0x108d84: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x108d84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x108d88: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x108d88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x108d8c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x108d8cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x108d90: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x108d90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x108d94: 0x3e00008  jr          $ra
    ctx->pc = 0x108D94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108D94u;
            // 0x108d98: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108CF4u: goto label_108cf4;
            case 0x108D04u: goto label_108d04;
            case 0x108D60u: goto label_108d60;
            case 0x108D74u: goto label_108d74;
            case 0x108D84u: goto label_108d84;
            case 0x108DD8u: goto label_108dd8;
            case 0x108DE0u: goto label_108de0;
            case 0x108DF0u: goto label_108df0;
            case 0x108DFCu: goto label_108dfc;
            case 0x108E04u: goto label_108e04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108D9Cu;
    // 0x108d9c: 0x0  nop
    ctx->pc = 0x108d9cu;
    // NOP
    // 0x108da0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x108da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x108da4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x108da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x108da8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x108da8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108dac: 0x2a020018  slti        $v0, $s0, 0x18
    ctx->pc = 0x108dacu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x108db0: 0x3404ffc0  ori         $a0, $zero, 0xFFC0
    ctx->pc = 0x108db0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x108db4: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x108db4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x108db8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x108DB8u;
    {
        const bool branch_taken_0x108db8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x108DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108DB8u;
            // 0x108dbc: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108db8) {
            ctx->pc = 0x108DD8u;
            goto label_108dd8;
        }
    }
    ctx->pc = 0x108DC0u;
    // 0x108dc0: 0x1018c0  sll         $v1, $s0, 3
    ctx->pc = 0x108dc0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x108dc4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x108dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x108dc8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x108dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x108dcc: 0xdc427928  ld          $v0, 0x7928($v0)
    ctx->pc = 0x108dccu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 31016)));
    // 0x108dd0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x108DD0u;
    {
        const bool branch_taken_0x108dd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108DD0u;
            // 0x108dd4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108dd0) {
            ctx->pc = 0x108E04u;
            goto label_108e04;
        }
    }
    ctx->pc = 0x108DD8u;
label_108dd8:
    // 0x108dd8: 0x1a000008  blez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x108DD8u;
    {
        const bool branch_taken_0x108dd8 = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x108dd8) {
            ctx->pc = 0x108DFCu;
            goto label_108dfc;
        }
    }
    ctx->pc = 0x108DE0u;
label_108de0:
    // 0x108de0: 0x34058048  ori         $a1, $zero, 0x8048
    ctx->pc = 0x108de0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32840);
    // 0x108de4: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x108de4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x108de8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x108DE8u;
    SET_GPR_U32(ctx, 31, 0x108DF0u);
    ctx->pc = 0x108DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x108DE8u;
            // 0x108dec: 0x2610ffff  addiu       $s0, $s0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108DF0u; }
        if (ctx->pc != 0x108DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108DF0u; }
        if (ctx->pc != 0x108DF0u) { return; }
    }
    ctx->pc = 0x108DF0u;
label_108df0:
    // 0x108df0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x108df0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108df4: 0x1e00fffa  bgtz        $s0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x108DF4u;
    {
        const bool branch_taken_0x108df4 = (GPR_S64(ctx, 16) > 0);
        if (branch_taken_0x108df4) {
            ctx->pc = 0x108DE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108de0;
        }
    }
    ctx->pc = 0x108DFCu;
label_108dfc:
    // 0x108dfc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x108dfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108e00: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x108e00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_108e04:
    // 0x108e04: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x108e04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x108e08: 0x3e00008  jr          $ra
    ctx->pc = 0x108E08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x108E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108E08u;
            // 0x108e0c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108CF4u: goto label_108cf4;
            case 0x108D04u: goto label_108d04;
            case 0x108D60u: goto label_108d60;
            case 0x108D74u: goto label_108d74;
            case 0x108D84u: goto label_108d84;
            case 0x108DD8u: goto label_108dd8;
            case 0x108DE0u: goto label_108de0;
            case 0x108DF0u: goto label_108df0;
            case 0x108DFCu: goto label_108dfc;
            case 0x108E04u: goto label_108e04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x108E10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
