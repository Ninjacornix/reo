#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2DA0
// Address: 0x1a2da0 - 0x1a2ff0
void sub_001A2DA0_0x1a2da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2DA0_0x1a2da0");
#endif

    switch (ctx->pc) {
        case 0x1a2dbcu: goto label_1a2dbc;
        case 0x1a2dd8u: goto label_1a2dd8;
        case 0x1a2e3cu: goto label_1a2e3c;
        case 0x1a2e58u: goto label_1a2e58;
        case 0x1a2e68u: goto label_1a2e68;
        case 0x1a2e88u: goto label_1a2e88;
        case 0x1a2e90u: goto label_1a2e90;
        case 0x1a2eccu: goto label_1a2ecc;
        case 0x1a2ed8u: goto label_1a2ed8;
        case 0x1a2ee0u: goto label_1a2ee0;
        case 0x1a2f44u: goto label_1a2f44;
        default: break;
    }

    ctx->pc = 0x1a2da0u;

label_1a2da0:
    // 0x1a2da0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1a2da0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1a2da4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1a2da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1a2da8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a2da8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a2dac: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a2dacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a2db0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1a2db0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2db4: 0xc068acc  jal         func_1A2B30
    ctx->pc = 0x1A2DB4u;
    SET_GPR_U32(ctx, 31, 0x1A2DBCu);
    ctx->pc = 0x1A2DB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2DB4u;
            // 0x1a2db8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B30u;
    if (runtime->hasFunction(0x1A2B30u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2DBCu; }
        if (ctx->pc != 0x1A2DBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B30_0x1a2b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2DBCu; }
        if (ctx->pc != 0x1A2DBCu) { return; }
    }
    ctx->pc = 0x1A2DBCu;
label_1a2dbc:
    // 0x1a2dbc: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x1a2dbcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a2dc0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A2DC0u;
    {
        const bool branch_taken_0x1a2dc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2DC0u;
            // 0x1a2dc4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2dc0) {
            ctx->pc = 0x1A2DD0u;
            goto label_1a2dd0;
        }
    }
    ctx->pc = 0x1A2DC8u;
    // 0x1a2dc8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A2DC8u;
    {
        const bool branch_taken_0x1a2dc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2DC8u;
            // 0x1a2dcc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2dc8) {
            ctx->pc = 0x1A2DE0u;
            goto label_1a2de0;
        }
    }
    ctx->pc = 0x1A2DD0u;
label_1a2dd0:
    // 0x1a2dd0: 0xc068aec  jal         func_1A2BB0
    ctx->pc = 0x1A2DD0u;
    SET_GPR_U32(ctx, 31, 0x1A2DD8u);
    ctx->pc = 0x1A2DD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2DD0u;
            // 0x1a2dd4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2BB0u;
    if (runtime->hasFunction(0x1A2BB0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2DD8u; }
        if (ctx->pc != 0x1A2DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2BB0_0x1a2bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2DD8u; }
        if (ctx->pc != 0x1A2DD8u) { return; }
    }
    ctx->pc = 0x1A2DD8u;
label_1a2dd8:
    // 0x1a2dd8: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x1a2dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x1a2ddc: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1a2ddcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
label_1a2de0:
    // 0x1a2de0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1a2de0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a2de4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a2de4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a2de8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a2de8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a2dec: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2DECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2DECu;
            // 0x1a2df0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2DA0u: goto label_1a2da0;
            case 0x1A2DBCu: goto label_1a2dbc;
            case 0x1A2DD0u: goto label_1a2dd0;
            case 0x1A2DD8u: goto label_1a2dd8;
            case 0x1A2DE0u: goto label_1a2de0;
            case 0x1A2E3Cu: goto label_1a2e3c;
            case 0x1A2E50u: goto label_1a2e50;
            case 0x1A2E58u: goto label_1a2e58;
            case 0x1A2E68u: goto label_1a2e68;
            case 0x1A2E88u: goto label_1a2e88;
            case 0x1A2E90u: goto label_1a2e90;
            case 0x1A2EB4u: goto label_1a2eb4;
            case 0x1A2ECCu: goto label_1a2ecc;
            case 0x1A2ED8u: goto label_1a2ed8;
            case 0x1A2EE0u: goto label_1a2ee0;
            case 0x1A2F1Cu: goto label_1a2f1c;
            case 0x1A2F38u: goto label_1a2f38;
            case 0x1A2F44u: goto label_1a2f44;
            case 0x1A2F90u: goto label_1a2f90;
            case 0x1A2FC4u: goto label_1a2fc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2DF4u;
    // 0x1a2df4: 0x0  nop
    ctx->pc = 0x1a2df4u;
    // NOP
    // 0x1a2df8: 0x0  nop
    ctx->pc = 0x1a2df8u;
    // NOP
    // 0x1a2dfc: 0x0  nop
    ctx->pc = 0x1a2dfcu;
    // NOP
    // 0x1a2e00: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1a2e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1a2e04: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1a2e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1a2e08: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1a2e08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1a2e0c: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1a2e0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1a2e10: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1a2e10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1a2e14: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a2e14u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a2e18: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a2e18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a2e1c: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1a2e1cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2e20: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a2e20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a2e24: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1a2e24u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2e28: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a2e28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a2e2c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a2e2cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2e30: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1a2e30u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2e34: 0xc068acc  jal         func_1A2B30
    ctx->pc = 0x1A2E34u;
    SET_GPR_U32(ctx, 31, 0x1A2E3Cu);
    ctx->pc = 0x1A2E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2E34u;
            // 0x1a2e38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B30u;
    if (runtime->hasFunction(0x1A2B30u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2E3Cu; }
        if (ctx->pc != 0x1A2E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B30_0x1a2b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2E3Cu; }
        if (ctx->pc != 0x1A2E3Cu) { return; }
    }
    ctx->pc = 0x1A2E3Cu;
label_1a2e3c:
    // 0x1a2e3c: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x1a2e3cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a2e40: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A2E40u;
    {
        const bool branch_taken_0x1a2e40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2E40u;
            // 0x1a2e44: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2e40) {
            ctx->pc = 0x1A2E50u;
            goto label_1a2e50;
        }
    }
    ctx->pc = 0x1A2E48u;
    // 0x1a2e48: 0x1000005e  b           . + 4 + (0x5E << 2)
    ctx->pc = 0x1A2E48u;
    {
        const bool branch_taken_0x1a2e48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2E48u;
            // 0x1a2e4c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2e48) {
            ctx->pc = 0x1A2FC4u;
            goto label_1a2fc4;
        }
    }
    ctx->pc = 0x1A2E50u;
label_1a2e50:
    // 0x1a2e50: 0xc068b68  jal         func_1A2DA0
    ctx->pc = 0x1A2E50u;
    SET_GPR_U32(ctx, 31, 0x1A2E58u);
    ctx->pc = 0x1A2E54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2E50u;
            // 0x1a2e54: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2DA0u;
    goto label_1a2da0;
    ctx->pc = 0x1A2E58u;
label_1a2e58:
    // 0x1a2e58: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x1a2e58u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x1a2e5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a2e5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2e60: 0xc068aec  jal         func_1A2BB0
    ctx->pc = 0x1A2E60u;
    SET_GPR_U32(ctx, 31, 0x1A2E68u);
    ctx->pc = 0x1A2E64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2E60u;
            // 0x1a2e64: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2BB0u;
    if (runtime->hasFunction(0x1A2BB0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2E68u; }
        if (ctx->pc != 0x1A2E68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2BB0_0x1a2bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2E68u; }
        if (ctx->pc != 0x1A2E68u) { return; }
    }
    ctx->pc = 0x1A2E68u;
label_1a2e68:
    // 0x1a2e68: 0xa6220002  sh          $v0, 0x2($s1)
    ctx->pc = 0x1a2e68u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a2e6c: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x1a2e6cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2e70: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1a2e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a2e74: 0x26340010  addiu       $s4, $s1, 0x10
    ctx->pc = 0x1a2e74u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x1a2e78: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1a2e78u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1a2e7c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a2e7cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2e80: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A2E80u;
    {
        const bool branch_taken_0x1a2e80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2E84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2E80u;
            // 0x1a2e84: 0xae200008  sw          $zero, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2e80) {
            ctx->pc = 0x1A2EB4u;
            goto label_1a2eb4;
        }
    }
    ctx->pc = 0x1A2E88u;
label_1a2e88:
    // 0x1a2e88: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a2e88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2e8c: 0x2822021  addu        $a0, $s4, $v0
    ctx->pc = 0x1a2e8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
label_1a2e90:
    // 0x1a2e90: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x1a2e90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1a2e94: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x1a2e94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1a2e98: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1a2e98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1a2e9c: 0xac600010  sw          $zero, 0x10($v1)
    ctx->pc = 0x1a2e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    // 0x1a2ea0: 0x28a20004  slti        $v0, $a1, 0x4
    ctx->pc = 0x1a2ea0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1a2ea4: 0xac600020  sw          $zero, 0x20($v1)
    ctx->pc = 0x1a2ea4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32), GPR_U32(ctx, 0));
    // 0x1a2ea8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A2EA8u;
    {
        const bool branch_taken_0x1a2ea8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2EA8u;
            // 0x1a2eac: 0xac600030  sw          $zero, 0x30($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2ea8) {
            ctx->pc = 0x1A2E90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2e90;
        }
    }
    ctx->pc = 0x1A2EB0u;
    // 0x1a2eb0: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a2eb0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1a2eb4:
    // 0x1a2eb4: 0xd6102a  slt         $v0, $a2, $s6
    ctx->pc = 0x1a2eb4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x1a2eb8: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1A2EB8u;
    {
        const bool branch_taken_0x1a2eb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2EB8u;
            // 0x1a2ebc: 0x61180  sll         $v0, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2eb8) {
            ctx->pc = 0x1A2E88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2e88;
        }
    }
    ctx->pc = 0x1A2EC0u;
    // 0x1a2ec0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1a2ec0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2ec4: 0xc068ad8  jal         func_1A2B60
    ctx->pc = 0x1A2EC4u;
    SET_GPR_U32(ctx, 31, 0x1A2ECCu);
    ctx->pc = 0x1A2EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2EC4u;
            // 0x1a2ec8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B60u;
    if (runtime->hasFunction(0x1A2B60u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2ECCu; }
        if (ctx->pc != 0x1A2ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B60_0x1a2b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2ECCu; }
        if (ctx->pc != 0x1A2ECCu) { return; }
    }
    ctx->pc = 0x1A2ECCu;
label_1a2ecc:
    // 0x1a2ecc: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x1a2eccu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2ed0: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1A2ED0u;
    {
        const bool branch_taken_0x1a2ed0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2ED0u;
            // 0x1a2ed4: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2ed0) {
            ctx->pc = 0x1A2F90u;
            goto label_1a2f90;
        }
    }
    ctx->pc = 0x1A2ED8u;
label_1a2ed8:
    // 0x1a2ed8: 0xc068b5c  jal         func_1A2D70
    ctx->pc = 0x1A2ED8u;
    SET_GPR_U32(ctx, 31, 0x1A2EE0u);
    ctx->pc = 0x1A2EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2ED8u;
            // 0x1a2edc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2D70u;
    if (runtime->hasFunction(0x1A2D70u)) {
        auto targetFn = runtime->lookupFunction(0x1A2D70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2EE0u; }
        if (ctx->pc != 0x1A2EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2D70_0x1a2d70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2EE0u; }
        if (ctx->pc != 0x1A2EE0u) { return; }
    }
    ctx->pc = 0x1A2EE0u;
label_1a2ee0:
    // 0x1a2ee0: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1a2ee0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a2ee4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1a2ee4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a2ee8: 0xa6840000  sh          $a0, 0x0($s4)
    ctx->pc = 0x1a2ee8u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a2eec: 0x8c440044  lw          $a0, 0x44($v0)
    ctx->pc = 0x1a2eecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
    // 0x1a2ef0: 0xa6840002  sh          $a0, 0x2($s4)
    ctx->pc = 0x1a2ef0u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a2ef4: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x1a2ef4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1a2ef8: 0xa6840006  sh          $a0, 0x6($s4)
    ctx->pc = 0x1a2ef8u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 6), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a2efc: 0x8c44000c  lw          $a0, 0xC($v0)
    ctx->pc = 0x1a2efcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1a2f00: 0xa6840008  sh          $a0, 0x8($s4)
    ctx->pc = 0x1a2f00u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 8), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a2f04: 0x86840006  lh          $a0, 0x6($s4)
    ctx->pc = 0x1a2f04u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 6)));
    // 0x1a2f08: 0x10830004  beq         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A2F08u;
    {
        const bool branch_taken_0x1a2f08 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A2F0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2F08u;
            // 0x1a2f0c: 0x151c3c  dsll32      $v1, $s5, 16 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 21) << (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2f08) {
            ctx->pc = 0x1A2F1Cu;
            goto label_1a2f1c;
        }
    }
    ctx->pc = 0x1A2F10u;
    // 0x1a2f10: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1a2f10u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1a2f14: 0x831823  subu        $v1, $a0, $v1
    ctx->pc = 0x1a2f14u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a2f18: 0xa6830006  sh          $v1, 0x6($s4)
    ctx->pc = 0x1a2f18u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 6), (uint16_t)GPR_U32(ctx, 3));
label_1a2f1c:
    // 0x1a2f1c: 0x86840008  lh          $a0, 0x8($s4)
    ctx->pc = 0x1a2f1cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x1a2f20: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1a2f20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a2f24: 0x10830004  beq         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A2F24u;
    {
        const bool branch_taken_0x1a2f24 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1A2F28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2F24u;
            // 0x1a2f28: 0x151c3c  dsll32      $v1, $s5, 16 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 21) << (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2f24) {
            ctx->pc = 0x1A2F38u;
            goto label_1a2f38;
        }
    }
    ctx->pc = 0x1A2F2Cu;
    // 0x1a2f2c: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1a2f2cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1a2f30: 0x831823  subu        $v1, $a0, $v1
    ctx->pc = 0x1a2f30u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a2f34: 0xa6830008  sh          $v1, 0x8($s4)
    ctx->pc = 0x1a2f34u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 8), (uint16_t)GPR_U32(ctx, 3));
label_1a2f38:
    // 0x1a2f38: 0x8c430040  lw          $v1, 0x40($v0)
    ctx->pc = 0x1a2f38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x1a2f3c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a2f3cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2f40: 0xa683000a  sh          $v1, 0xA($s4)
    ctx->pc = 0x1a2f40u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 10), (uint16_t)GPR_U32(ctx, 3));
label_1a2f44:
    // 0x1a2f44: 0x64080  sll         $t0, $a2, 2
    ctx->pc = 0x1a2f44u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1a2f48: 0x25030010  addiu       $v1, $t0, 0x10
    ctx->pc = 0x1a2f48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 16));
    // 0x1a2f4c: 0x2883821  addu        $a3, $s4, $t0
    ctx->pc = 0x1a2f4cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 8)));
    // 0x1a2f50: 0x432021  addu        $a0, $v0, $v1
    ctx->pc = 0x1a2f50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a2f54: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a2f54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a2f58: 0xc4800000  lwc1        $f0, 0x0($a0)
    ctx->pc = 0x1a2f58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a2f5c: 0x25030020  addiu       $v1, $t0, 0x20
    ctx->pc = 0x1a2f5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 32));
    // 0x1a2f60: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1a2f60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a2f64: 0x25030030  addiu       $v1, $t0, 0x30
    ctx->pc = 0x1a2f64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 48));
    // 0x1a2f68: 0xe4e00010  swc1        $f0, 0x10($a3)
    ctx->pc = 0x1a2f68u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 16), bits); }
    // 0x1a2f6c: 0x432021  addu        $a0, $v0, $v1
    ctx->pc = 0x1a2f6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a2f70: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x1a2f70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a2f74: 0x28c30004  slti        $v1, $a2, 0x4
    ctx->pc = 0x1a2f74u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1a2f78: 0xe4e00020  swc1        $f0, 0x20($a3)
    ctx->pc = 0x1a2f78u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 32), bits); }
    // 0x1a2f7c: 0xc4800000  lwc1        $f0, 0x0($a0)
    ctx->pc = 0x1a2f7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a2f80: 0x1460fff0  bnez        $v1, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1A2F80u;
    {
        const bool branch_taken_0x1a2f80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2F80u;
            // 0x1a2f84: 0xe4e00030  swc1        $f0, 0x30($a3) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 7), 48), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2f80) {
            ctx->pc = 0x1A2F44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2f44;
        }
    }
    ctx->pc = 0x1A2F88u;
    // 0x1a2f88: 0x26940040  addiu       $s4, $s4, 0x40
    ctx->pc = 0x1a2f88u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 64));
    // 0x1a2f8c: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1a2f8cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1a2f90:
    // 0x1a2f90: 0x276102a  slt         $v0, $s3, $s6
    ctx->pc = 0x1a2f90u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x1a2f94: 0x1440ffd0  bnez        $v0, . + 4 + (-0x30 << 2)
    ctx->pc = 0x1A2F94u;
    {
        const bool branch_taken_0x1a2f94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2F94u;
            // 0x1a2f98: 0x2752821  addu        $a1, $s3, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2f94) {
            ctx->pc = 0x1A2ED8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2ed8;
        }
    }
    ctx->pc = 0x1A2F9Cu;
    // 0x1a2f9c: 0xc6230000  lwc1        $f3, 0x0($s1)
    ctx->pc = 0x1a2f9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1a2fa0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a2fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a2fa4: 0xc6220004  lwc1        $f2, 0x4($s1)
    ctx->pc = 0x1a2fa4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1a2fa8: 0xc6210008  lwc1        $f1, 0x8($s1)
    ctx->pc = 0x1a2fa8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a2fac: 0xc620000c  lwc1        $f0, 0xC($s1)
    ctx->pc = 0x1a2facu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a2fb0: 0xe6430000  swc1        $f3, 0x0($s2)
    ctx->pc = 0x1a2fb0u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
    // 0x1a2fb4: 0xe6420004  swc1        $f2, 0x4($s2)
    ctx->pc = 0x1a2fb4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 4), bits); }
    // 0x1a2fb8: 0xe6410008  swc1        $f1, 0x8($s2)
    ctx->pc = 0x1a2fb8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 8), bits); }
    // 0x1a2fbc: 0xe640000c  swc1        $f0, 0xC($s2)
    ctx->pc = 0x1a2fbcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 12), bits); }
    // 0x1a2fc0: 0xae510008  sw          $s1, 0x8($s2)
    ctx->pc = 0x1a2fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 17));
label_1a2fc4:
    // 0x1a2fc4: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1a2fc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1a2fc8: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1a2fc8u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1a2fcc: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1a2fccu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1a2fd0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1a2fd0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a2fd4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a2fd4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a2fd8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a2fd8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a2fdc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a2fdcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a2fe0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a2fe0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a2fe4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2FE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2FE4u;
            // 0x1a2fe8: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2DA0u: goto label_1a2da0;
            case 0x1A2DBCu: goto label_1a2dbc;
            case 0x1A2DD0u: goto label_1a2dd0;
            case 0x1A2DD8u: goto label_1a2dd8;
            case 0x1A2DE0u: goto label_1a2de0;
            case 0x1A2E3Cu: goto label_1a2e3c;
            case 0x1A2E50u: goto label_1a2e50;
            case 0x1A2E58u: goto label_1a2e58;
            case 0x1A2E68u: goto label_1a2e68;
            case 0x1A2E88u: goto label_1a2e88;
            case 0x1A2E90u: goto label_1a2e90;
            case 0x1A2EB4u: goto label_1a2eb4;
            case 0x1A2ECCu: goto label_1a2ecc;
            case 0x1A2ED8u: goto label_1a2ed8;
            case 0x1A2EE0u: goto label_1a2ee0;
            case 0x1A2F1Cu: goto label_1a2f1c;
            case 0x1A2F38u: goto label_1a2f38;
            case 0x1A2F44u: goto label_1a2f44;
            case 0x1A2F90u: goto label_1a2f90;
            case 0x1A2FC4u: goto label_1a2fc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2FECu;
    // 0x1a2fec: 0x0  nop
    ctx->pc = 0x1a2fecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
