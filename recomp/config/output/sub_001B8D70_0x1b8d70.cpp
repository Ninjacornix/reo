#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8D70
// Address: 0x1b8d70 - 0x1b8f38
void sub_001B8D70_0x1b8d70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8D70_0x1b8d70");
#endif

    switch (ctx->pc) {
        case 0x1b8dd4u: goto label_1b8dd4;
        case 0x1b8e04u: goto label_1b8e04;
        case 0x1b8e28u: goto label_1b8e28;
        case 0x1b8e74u: goto label_1b8e74;
        case 0x1b8e8cu: goto label_1b8e8c;
        case 0x1b8eecu: goto label_1b8eec;
        case 0x1b8f1cu: goto label_1b8f1c;
        default: break;
    }

    ctx->pc = 0x1b8d70u;

    // 0x1b8d70: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1b8d70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1b8d74: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1b8d74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b8d78: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1b8d78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1b8d7c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b8d7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b8d80: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b8d80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b8d84: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b8d84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b8d88: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b8d88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b8d8c: 0x5863c  dsll32      $s0, $a1, 24
    ctx->pc = 0x1b8d8cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) << (32 + 24));
    // 0x1b8d90: 0x10863f  dsra32      $s0, $s0, 24
    ctx->pc = 0x1b8d90u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 24));
    // 0x1b8d94: 0x12030019  beq         $s0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1B8D94u;
    {
        const bool branch_taken_0x1b8d94 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B8D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8D94u;
            // 0x1b8d98: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8d94) {
            ctx->pc = 0x1B8DFCu;
            goto label_1b8dfc;
        }
    }
    ctx->pc = 0x1B8D9Cu;
    // 0x1b8d9c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1b8d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b8da0: 0x12020014  beq         $s0, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1B8DA0u;
    {
        const bool branch_taken_0x1b8da0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B8DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8DA0u;
            // 0x1b8da4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8da0) {
            ctx->pc = 0x1B8DF4u;
            goto label_1b8df4;
        }
    }
    ctx->pc = 0x1B8DA8u;
    // 0x1b8da8: 0x12020010  beq         $s0, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B8DA8u;
    {
        const bool branch_taken_0x1b8da8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b8da8) {
            ctx->pc = 0x1B8DECu;
            goto label_1b8dec;
        }
    }
    ctx->pc = 0x1B8DB0u;
    // 0x1b8db0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b8db0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8db4: 0x12020005  beq         $s0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B8DB4u;
    {
        const bool branch_taken_0x1b8db4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B8DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8DB4u;
            // 0x1b8db8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8db4) {
            ctx->pc = 0x1B8DCCu;
            goto label_1b8dcc;
        }
    }
    ctx->pc = 0x1B8DBCu;
    // 0x1b8dbc: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B8DBCu;
    {
        const bool branch_taken_0x1b8dbc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8dbc) {
            ctx->pc = 0x1B8DCCu;
            goto label_1b8dcc;
        }
    }
    ctx->pc = 0x1B8DC4u;
    // 0x1b8dc4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1B8DC4u;
    {
        const bool branch_taken_0x1b8dc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8DC4u;
            // 0x1b8dc8: 0x92620002  lbu         $v0, 0x2($s3) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8dc4) {
            ctx->pc = 0x1B8E18u;
            goto label_1b8e18;
        }
    }
    ctx->pc = 0x1B8DCCu;
label_1b8dcc:
    // 0x1b8dcc: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B8DCCu;
    SET_GPR_U32(ctx, 31, 0x1B8DD4u);
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8DD4u; }
        if (ctx->pc != 0x1B8DD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8DD4u; }
        if (ctx->pc != 0x1B8DD4u) { return; }
    }
    ctx->pc = 0x1B8DD4u;
label_1b8dd4:
    // 0x1b8dd4: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b8dd4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b8dd8: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x1b8dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1b8ddc: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x1b8ddcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x1b8de0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8de0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b8de4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B8DE4u;
    {
        const bool branch_taken_0x1b8de4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8DE4u;
            // 0x1b8de8: 0x3051ffff  andi        $s1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8de4) {
            ctx->pc = 0x1B8E14u;
            goto label_1b8e14;
        }
    }
    ctx->pc = 0x1B8DECu;
label_1b8dec:
    // 0x1b8dec: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B8DECu;
    {
        const bool branch_taken_0x1b8dec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8DECu;
            // 0x1b8df0: 0x3071ffff  andi        $s1, $v1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8dec) {
            ctx->pc = 0x1B8E14u;
            goto label_1b8e14;
        }
    }
    ctx->pc = 0x1B8DF4u;
label_1b8df4:
    // 0x1b8df4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B8DF4u;
    {
        const bool branch_taken_0x1b8df4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8DF4u;
            // 0x1b8df8: 0x64110005  daddiu      $s1, $zero, 0x5 (Delay Slot)
        SET_GPR_S64(ctx, 17, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)5);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8df4) {
            ctx->pc = 0x1B8E14u;
            goto label_1b8e14;
        }
    }
    ctx->pc = 0x1B8DFCu;
label_1b8dfc:
    // 0x1b8dfc: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1B8DFCu;
    SET_GPR_U32(ctx, 31, 0x1B8E04u);
    ctx->pc = 0x1B8E00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8DFCu;
            // 0x1b8e00: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8E04u; }
        if (ctx->pc != 0x1B8E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8E04u; }
        if (ctx->pc != 0x1B8E04u) { return; }
    }
    ctx->pc = 0x1B8E04u;
label_1b8e04:
    // 0x1b8e04: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1b8e04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b8e08: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1b8e08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1b8e0c: 0x24420006  addiu       $v0, $v0, 0x6
    ctx->pc = 0x1b8e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    // 0x1b8e10: 0x3051ffff  andi        $s1, $v0, 0xFFFF
    ctx->pc = 0x1b8e10u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1b8e14:
    // 0x1b8e14: 0x92620002  lbu         $v0, 0x2($s3)
    ctx->pc = 0x1b8e14u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 2)));
label_1b8e18:
    // 0x1b8e18: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B8E18u;
    {
        const bool branch_taken_0x1b8e18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B8E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8E18u;
            // 0x1b8e1c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8e18) {
            ctx->pc = 0x1B8E64u;
            goto label_1b8e64;
        }
    }
    ctx->pc = 0x1B8E20u;
    // 0x1b8e20: 0xc06e3d0  jal         func_1B8F40
    ctx->pc = 0x1B8E20u;
    SET_GPR_U32(ctx, 31, 0x1B8E28u);
    ctx->pc = 0x1B8E24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8E20u;
            // 0x1b8e24: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8F40u;
    if (runtime->hasFunction(0x1B8F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B8F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8E28u; }
        if (ctx->pc != 0x1B8E28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8F40_0x1b8f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8E28u; }
        if (ctx->pc != 0x1B8E28u) { return; }
    }
    ctx->pc = 0x1B8E28u;
label_1b8e28:
    // 0x1b8e28: 0x21e3c  dsll32      $v1, $v0, 24
    ctx->pc = 0x1b8e28u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1b8e2c: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1b8e2cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1b8e30: 0x3222ffff  andi        $v0, $s1, 0xFFFF
    ctx->pc = 0x1b8e30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
    // 0x1b8e34: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1b8e34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b8e38: 0x9263054f  lbu         $v1, 0x54F($s3)
    ctx->pc = 0x1b8e38u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 1359)));
    // 0x1b8e3c: 0x3052ffff  andi        $s2, $v0, 0xFFFF
    ctx->pc = 0x1b8e3cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b8e40: 0x2402002b  addiu       $v0, $zero, 0x2B
    ctx->pc = 0x1b8e40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
    // 0x1b8e44: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B8E44u;
    {
        const bool branch_taken_0x1b8e44 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B8E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8E44u;
            // 0x1b8e48: 0x26640038  addiu       $a0, $s3, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8e44) {
            ctx->pc = 0x1B8E6Cu;
            goto label_1b8e6c;
        }
    }
    ctx->pc = 0x1B8E4Cu;
    // 0x1b8e4c: 0x92630009  lbu         $v1, 0x9($s3)
    ctx->pc = 0x1b8e4cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 9)));
    // 0x1b8e50: 0x2402006d  addiu       $v0, $zero, 0x6D
    ctx->pc = 0x1b8e50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
    // 0x1b8e54: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B8E54u;
    {
        const bool branch_taken_0x1b8e54 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b8e54) {
            ctx->pc = 0x1B8E68u;
            goto label_1b8e68;
        }
    }
    ctx->pc = 0x1B8E5Cu;
    // 0x1b8e5c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B8E5Cu;
    {
        const bool branch_taken_0x1b8e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8E5Cu;
            // 0x1b8e60: 0x64100001  daddiu      $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8e5c) {
            ctx->pc = 0x1B8E68u;
            goto label_1b8e68;
        }
    }
    ctx->pc = 0x1B8E64u;
label_1b8e64:
    // 0x1b8e64: 0x3232ffff  andi        $s2, $s1, 0xFFFF
    ctx->pc = 0x1b8e64u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
label_1b8e68:
    // 0x1b8e68: 0x26640038  addiu       $a0, $s3, 0x38
    ctx->pc = 0x1b8e68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 56));
label_1b8e6c:
    // 0x1b8e6c: 0xc15d1a0  jal         func_574680
    ctx->pc = 0x1B8E6Cu;
    SET_GPR_U32(ctx, 31, 0x1B8E74u);
    ctx->pc = 0x574680u;
    {
        auto targetFn = runtime->lookupFunction(0x574680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8E74u; }
        if (ctx->pc != 0x1B8E74u) { return; }
    }
    ctx->pc = 0x1B8E74u;
label_1b8e74:
    // 0x1b8e74: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x1B8E74u;
    {
        const bool branch_taken_0x1b8e74 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8E74u;
            // 0x1b8e78: 0x3051ffff  andi        $s1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8e74) {
            ctx->pc = 0x1B8EA8u;
            goto label_1b8ea8;
        }
    }
    ctx->pc = 0x1B8E7Cu;
    // 0x1b8e7c: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1b8e7cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1b8e80: 0x27a40050  addiu       $a0, $sp, 0x50
    ctx->pc = 0x1b8e80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1b8e84: 0xc06450c  jal         func_191430
    ctx->pc = 0x1B8E84u;
    SET_GPR_U32(ctx, 31, 0x1B8E8Cu);
    ctx->pc = 0x1B8E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8E84u;
            // 0x1b8e88: 0x24a540e0  addiu       $a1, $a1, 0x40E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16608));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191430u;
    if (runtime->hasFunction(0x191430u)) {
        auto targetFn = runtime->lookupFunction(0x191430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8E8Cu; }
        if (ctx->pc != 0x1B8E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191430_0x191430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8E8Cu; }
        if (ctx->pc != 0x1B8E8Cu) { return; }
    }
    ctx->pc = 0x1B8E8Cu;
label_1b8e8c:
    // 0x1b8e8c: 0xc7a20080  lwc1        $f2, 0x80($sp)
    ctx->pc = 0x1b8e8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 128)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b8e90: 0xc7a10084  lwc1        $f1, 0x84($sp)
    ctx->pc = 0x1b8e90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 132)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b8e94: 0xc7a00088  lwc1        $f0, 0x88($sp)
    ctx->pc = 0x1b8e94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 136)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b8e98: 0xe7a20090  swc1        $f2, 0x90($sp)
    ctx->pc = 0x1b8e98u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 144), bits); }
    // 0x1b8e9c: 0xe7a10094  swc1        $f1, 0x94($sp)
    ctx->pc = 0x1b8e9cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 148), bits); }
    // 0x1b8ea0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B8EA0u;
    {
        const bool branch_taken_0x1b8ea0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8EA0u;
            // 0x1b8ea4: 0xe7a00098  swc1        $f0, 0x98($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 152), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8ea0) {
            ctx->pc = 0x1B8EC4u;
            goto label_1b8ec4;
        }
    }
    ctx->pc = 0x1B8EA8u;
label_1b8ea8:
    // 0x1b8ea8: 0xc6620038  lwc1        $f2, 0x38($s3)
    ctx->pc = 0x1b8ea8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b8eac: 0x27a20090  addiu       $v0, $sp, 0x90
    ctx->pc = 0x1b8eacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1b8eb0: 0xc661003c  lwc1        $f1, 0x3C($s3)
    ctx->pc = 0x1b8eb0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b8eb4: 0xc6600040  lwc1        $f0, 0x40($s3)
    ctx->pc = 0x1b8eb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b8eb8: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x1b8eb8u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x1b8ebc: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x1b8ebcu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x1b8ec0: 0xe4400008  swc1        $f0, 0x8($v0)
    ctx->pc = 0x1b8ec0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
label_1b8ec4:
    // 0x1b8ec4: 0x92660003  lbu         $a2, 0x3($s3)
    ctx->pc = 0x1b8ec4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x1b8ec8: 0x3250ffff  andi        $s0, $s2, 0xFFFF
    ctx->pc = 0x1b8ec8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1b8ecc: 0x322a00ff  andi        $t2, $s1, 0xFF
    ctx->pc = 0x1b8eccu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1b8ed0: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1b8ed0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b8ed4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b8ed4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8ed8: 0x27a70090  addiu       $a3, $sp, 0x90
    ctx->pc = 0x1b8ed8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1b8edc: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8edcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8ee0: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8ee0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8ee4: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B8EE4u;
    SET_GPR_U32(ctx, 31, 0x1B8EECu);
    ctx->pc = 0x1B8EE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8EE4u;
            // 0x1b8ee8: 0x3232ffff  andi        $s2, $s1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8EECu; }
        if (ctx->pc != 0x1B8EECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8EECu; }
        if (ctx->pc != 0x1B8EECu) { return; }
    }
    ctx->pc = 0x1B8EECu;
label_1b8eec:
    // 0x1b8eec: 0x121a03  sra         $v1, $s2, 8
    ctx->pc = 0x1b8eecu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 18), 8));
    // 0x1b8ef0: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x1b8ef0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1b8ef4: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B8EF4u;
    {
        const bool branch_taken_0x1b8ef4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b8ef4) {
            ctx->pc = 0x1B8F1Cu;
            goto label_1b8f1c;
        }
    }
    ctx->pc = 0x1B8EFCu;
    // 0x1b8efc: 0x92660003  lbu         $a2, 0x3($s3)
    ctx->pc = 0x1b8efcu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x1b8f00: 0x306affff  andi        $t2, $v1, 0xFFFF
    ctx->pc = 0x1b8f00u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1b8f04: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b8f04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8f08: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1b8f08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b8f0c: 0x27a70090  addiu       $a3, $sp, 0x90
    ctx->pc = 0x1b8f0cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1b8f10: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1b8f10u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8f14: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B8F14u;
    SET_GPR_U32(ctx, 31, 0x1B8F1Cu);
    ctx->pc = 0x1B8F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8F14u;
            // 0x1b8f18: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8F1Cu; }
        if (ctx->pc != 0x1B8F1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8F1Cu; }
        if (ctx->pc != 0x1B8F1Cu) { return; }
    }
    ctx->pc = 0x1B8F1Cu;
label_1b8f1c:
    // 0x1b8f1c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1b8f1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b8f20: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b8f20u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b8f24: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b8f24u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b8f28: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b8f28u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b8f2c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b8f2cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8f30: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8F30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8F34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8F30u;
            // 0x1b8f34: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8DCCu: goto label_1b8dcc;
            case 0x1B8DD4u: goto label_1b8dd4;
            case 0x1B8DECu: goto label_1b8dec;
            case 0x1B8DF4u: goto label_1b8df4;
            case 0x1B8DFCu: goto label_1b8dfc;
            case 0x1B8E04u: goto label_1b8e04;
            case 0x1B8E14u: goto label_1b8e14;
            case 0x1B8E18u: goto label_1b8e18;
            case 0x1B8E28u: goto label_1b8e28;
            case 0x1B8E64u: goto label_1b8e64;
            case 0x1B8E68u: goto label_1b8e68;
            case 0x1B8E6Cu: goto label_1b8e6c;
            case 0x1B8E74u: goto label_1b8e74;
            case 0x1B8E8Cu: goto label_1b8e8c;
            case 0x1B8EA8u: goto label_1b8ea8;
            case 0x1B8EC4u: goto label_1b8ec4;
            case 0x1B8EECu: goto label_1b8eec;
            case 0x1B8F1Cu: goto label_1b8f1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8F38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
