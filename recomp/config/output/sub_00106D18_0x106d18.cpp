#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106D18
// Address: 0x106d18 - 0x106ee0
void sub_00106D18_0x106d18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106D18_0x106d18");
#endif

    switch (ctx->pc) {
        case 0x106da4u: goto label_106da4;
        case 0x106dbcu: goto label_106dbc;
        case 0x106dccu: goto label_106dcc;
        case 0x106e40u: goto label_106e40;
        case 0x106eb4u: goto label_106eb4;
        case 0x106ebcu: goto label_106ebc;
        default: break;
    }

    ctx->pc = 0x106d18u;

    // 0x106d18: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x106d18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x106d1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106d20: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x106d20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106d24: 0x2e020011  sltiu       $v0, $s0, 0x11
    ctx->pc = 0x106d24u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)17) ? 1 : 0);
    // 0x106d28: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x106d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x106d2c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106d2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106d30: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x106d30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106d34: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x106d34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x106d38: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x106d38u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106d3c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x106d3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x106d40: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x106D40u;
    {
        const bool branch_taken_0x106d40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106D40u;
            // 0x106d44: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106d40) {
            ctx->pc = 0x106D68u;
            goto label_106d68;
        }
    }
    ctx->pc = 0x106D48u;
    // 0x106d48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106d48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106d4c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106d4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106d50: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x106d50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106d54: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x106d54u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x106d58: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x106d58u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x106d5c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x106d5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x106d60: 0x8041c76  j           func_1071D8
    ctx->pc = 0x106D60u;
    ctx->pc = 0x106D64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106D60u;
            // 0x106d64: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001071D8_0x1071d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x106D68u;
label_106d68:
    // 0x106d68: 0x24a50013  addiu       $a1, $a1, 0x13
    ctx->pc = 0x106d68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19));
    // 0x106d6c: 0x2e020010  sltiu       $v0, $s0, 0x10
    ctx->pc = 0x106d6cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x106d70: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x106d70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x106d74: 0x2ca4001f  sltiu       $a0, $a1, 0x1F
    ctx->pc = 0x106d74u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)31) ? 1 : 0);
    // 0x106d78: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x106D78u;
    {
        const bool branch_taken_0x106d78 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x106D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106D78u;
            // 0x106d7c: 0x62800b  movn        $s0, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106d78) {
            ctx->pc = 0x106D90u;
            goto label_106d90;
        }
    }
    ctx->pc = 0x106D80u;
    // 0x106d80: 0x2402fff0  addiu       $v0, $zero, -0x10
    ctx->pc = 0x106d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x106d84: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x106D84u;
    {
        const bool branch_taken_0x106d84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106D84u;
            // 0x106d88: 0xa29824  and         $s3, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106d84) {
            ctx->pc = 0x106D94u;
            goto label_106d94;
        }
    }
    ctx->pc = 0x106D8Cu;
    // 0x106d8c: 0x0  nop
    ctx->pc = 0x106d8cu;
    // NOP
label_106d90:
    // 0x106d90: 0x24130010  addiu       $s3, $zero, 0x10
    ctx->pc = 0x106d90u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_106d94:
    // 0x106d94: 0x2702821  addu        $a1, $s3, $s0
    ctx->pc = 0x106d94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x106d98: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x106d98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106d9c: 0xc041c76  jal         func_1071D8
    ctx->pc = 0x106D9Cu;
    SET_GPR_U32(ctx, 31, 0x106DA4u);
    ctx->pc = 0x106DA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106D9Cu;
            // 0x106da0: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106DA4u; }
        if (ctx->pc != 0x106DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001071D8_0x1071d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106DA4u; }
        if (ctx->pc != 0x106DA4u) { return; }
    }
    ctx->pc = 0x106DA4u;
label_106da4:
    // 0x106da4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x106da4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106da8: 0x52200046  beql        $s1, $zero, . + 4 + (0x46 << 2)
    ctx->pc = 0x106DA8u;
    {
        const bool branch_taken_0x106da8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x106da8) {
            ctx->pc = 0x106DACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106DA8u;
            // 0x106dac: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106EC4u;
            goto label_106ec4;
        }
    }
    ctx->pc = 0x106DB0u;
    // 0x106db0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x106db0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106db4: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x106DB4u;
    SET_GPR_U32(ctx, 31, 0x106DBCu);
    ctx->pc = 0x106DB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106DB4u;
            // 0x106db8: 0x2632fff8  addiu       $s2, $s1, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106DBCu; }
        if (ctx->pc != 0x106DBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106DBCu; }
        if (ctx->pc != 0x106DBCu) { return; }
    }
    ctx->pc = 0x106DBCu;
label_106dbc:
    // 0x106dbc: 0x10283c  dsll32      $a1, $s0, 0
    ctx->pc = 0x106dbcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) << (32 + 0));
    // 0x106dc0: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x106dc0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x106dc4: 0xc044370  jal         func_110DC0
    ctx->pc = 0x106DC4u;
    SET_GPR_U32(ctx, 31, 0x106DCCu);
    ctx->pc = 0x106DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106DC4u;
            // 0x106dc8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110DC0u;
    if (runtime->hasFunction(0x110DC0u)) {
        auto targetFn = runtime->lookupFunction(0x110DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106DCCu; }
        if (ctx->pc != 0x106DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110DC0_0x110dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106DCCu; }
        if (ctx->pc != 0x106DCCu) { return; }
    }
    ctx->pc = 0x106DCCu;
label_106dcc:
    // 0x106dcc: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x106DCCu;
    {
        const bool branch_taken_0x106dcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x106DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106DCCu;
            // 0x106dd0: 0x2303821  addu        $a3, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106dcc) {
            ctx->pc = 0x106E40u;
            goto label_106e40;
        }
    }
    ctx->pc = 0x106DD4u;
    // 0x106dd4: 0x101023  negu        $v0, $s0
    ctx->pc = 0x106dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 16)));
    // 0x106dd8: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x106dd8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x106ddc: 0x8e460004  lw          $a2, 0x4($s2)
    ctx->pc = 0x106ddcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x106de0: 0xe23824  and         $a3, $a3, $v0
    ctx->pc = 0x106de0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & GPR_U64(ctx, 2));
    // 0x106de4: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x106de4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x106de8: 0x24e7fff8  addiu       $a3, $a3, -0x8
    ctx->pc = 0x106de8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967288));
    // 0x106dec: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x106decu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x106df0: 0xf21023  subu        $v0, $a3, $s2
    ctx->pc = 0x106df0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 18)));
    // 0x106df4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x106df4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106df8: 0x28420010  slti        $v0, $v0, 0x10
    ctx->pc = 0x106df8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x106dfc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x106dfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106e00: 0x501818  mult        $v1, $v0, $s0
    ctx->pc = 0x106e00u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x106e04: 0x673821  addu        $a3, $v1, $a3
    ctx->pc = 0x106e04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x106e08: 0xf24023  subu        $t0, $a3, $s2
    ctx->pc = 0x106e08u;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 18)));
    // 0x106e0c: 0xc83023  subu        $a2, $a2, $t0
    ctx->pc = 0x106e0cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x106e10: 0x34c30001  ori         $v1, $a2, 0x1
    ctx->pc = 0x106e10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)1);
    // 0x106e14: 0xe63021  addu        $a2, $a3, $a2
    ctx->pc = 0x106e14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x106e18: 0xace30004  sw          $v1, 0x4($a3)
    ctx->pc = 0x106e18u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 3));
    // 0x106e1c: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x106e1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x106e20: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x106e20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x106e24: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x106e24u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x106e28: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x106e28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x106e2c: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x106e2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x106e30: 0x681825  or          $v1, $v1, $t0
    ctx->pc = 0x106e30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 8));
    // 0x106e34: 0xae430004  sw          $v1, 0x4($s2)
    ctx->pc = 0x106e34u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
    // 0x106e38: 0xc041636  jal         func_1058D8
    ctx->pc = 0x106E38u;
    SET_GPR_U32(ctx, 31, 0x106E40u);
    ctx->pc = 0x106E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106E38u;
            // 0x106e3c: 0xe0902d  daddu       $s2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106E40u; }
        if (ctx->pc != 0x106E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106E40u; }
        if (ctx->pc != 0x106E40u) { return; }
    }
    ctx->pc = 0x106E40u;
label_106e40:
    // 0x106e40: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x106e40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x106e44: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x106e44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x106e48: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x106e48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x106e4c: 0x53202b  sltu        $a0, $v0, $s3
    ctx->pc = 0x106e4cu;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 19)) ? 1 : 0);
    // 0x106e50: 0x50800007  beql        $a0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x106E50u;
    {
        const bool branch_taken_0x106e50 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x106e50) {
            ctx->pc = 0x106E54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106E50u;
            // 0x106e54: 0x531023  subu        $v0, $v0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106E70u;
            goto label_106e70;
        }
    }
    ctx->pc = 0x106E58u;
    // 0x106e58: 0x2621023  subu        $v0, $s3, $v0
    ctx->pc = 0x106e58u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x106e5c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x106e5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x106e60: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x106e60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x106e64: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x106E64u;
    {
        const bool branch_taken_0x106e64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106E64u;
            // 0x106e68: 0x2202f  dsubu       $a0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106e64) {
            ctx->pc = 0x106E78u;
            goto label_106e78;
        }
    }
    ctx->pc = 0x106E6Cu;
    // 0x106e6c: 0x0  nop
    ctx->pc = 0x106e6cu;
    // NOP
label_106e70:
    // 0x106e70: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x106e70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x106e74: 0x2203e  dsrl32      $a0, $v0, 0
    ctx->pc = 0x106e74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) >> (32 + 0));
label_106e78:
    // 0x106e78: 0x28820010  slti        $v0, $a0, 0x10
    ctx->pc = 0x106e78u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x106e7c: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x106E7Cu;
    {
        const bool branch_taken_0x106e7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x106E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106E7Cu;
            // 0x106e80: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106e7c) {
            ctx->pc = 0x106EB4u;
            goto label_106eb4;
        }
    }
    ctx->pc = 0x106E84u;
    // 0x106e84: 0x2533021  addu        $a2, $s2, $s3
    ctx->pc = 0x106e84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
    // 0x106e88: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x106e88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x106e8c: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x106e8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106e90: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x106e90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x106e94: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x106e94u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x106e98: 0x24c50008  addiu       $a1, $a2, 0x8
    ctx->pc = 0x106e98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x106e9c: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x106e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x106ea0: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x106ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x106ea4: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x106ea4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x106ea8: 0x731825  or          $v1, $v1, $s3
    ctx->pc = 0x106ea8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 19));
    // 0x106eac: 0xc041636  jal         func_1058D8
    ctx->pc = 0x106EACu;
    SET_GPR_U32(ctx, 31, 0x106EB4u);
    ctx->pc = 0x106EB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106EACu;
            // 0x106eb0: 0xae430004  sw          $v1, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106EB4u; }
        if (ctx->pc != 0x106EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106EB4u; }
        if (ctx->pc != 0x106EB4u) { return; }
    }
    ctx->pc = 0x106EB4u;
label_106eb4:
    // 0x106eb4: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x106EB4u;
    SET_GPR_U32(ctx, 31, 0x106EBCu);
    ctx->pc = 0x106EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106EB4u;
            // 0x106eb8: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106EBCu; }
        if (ctx->pc != 0x106EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106EBCu; }
        if (ctx->pc != 0x106EBCu) { return; }
    }
    ctx->pc = 0x106EBCu;
label_106ebc:
    // 0x106ebc: 0x26420008  addiu       $v0, $s2, 0x8
    ctx->pc = 0x106ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
    // 0x106ec0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106ec0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_106ec4:
    // 0x106ec4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106ec4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106ec8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x106ec8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106ecc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x106eccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x106ed0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x106ed0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x106ed4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x106ed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x106ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x106ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106ED8u;
            // 0x106edc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106D68u: goto label_106d68;
            case 0x106D90u: goto label_106d90;
            case 0x106D94u: goto label_106d94;
            case 0x106DA4u: goto label_106da4;
            case 0x106DBCu: goto label_106dbc;
            case 0x106DCCu: goto label_106dcc;
            case 0x106E40u: goto label_106e40;
            case 0x106E70u: goto label_106e70;
            case 0x106E78u: goto label_106e78;
            case 0x106EB4u: goto label_106eb4;
            case 0x106EBCu: goto label_106ebc;
            case 0x106EC4u: goto label_106ec4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106EE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
