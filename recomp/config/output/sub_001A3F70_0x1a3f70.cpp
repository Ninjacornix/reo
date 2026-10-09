#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3F70
// Address: 0x1a3f70 - 0x1a45a0
void sub_001A3F70_0x1a3f70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3F70_0x1a3f70");
#endif

    switch (ctx->pc) {
        case 0x1a3fa0u: goto label_1a3fa0;
        case 0x1a3fc0u: goto label_1a3fc0;
        case 0x1a3fccu: goto label_1a3fcc;
        case 0x1a3fd8u: goto label_1a3fd8;
        case 0x1a3ffcu: goto label_1a3ffc;
        case 0x1a4004u: goto label_1a4004;
        case 0x1a4010u: goto label_1a4010;
        case 0x1a401cu: goto label_1a401c;
        case 0x1a40c8u: goto label_1a40c8;
        case 0x1a40d0u: goto label_1a40d0;
        case 0x1a40dcu: goto label_1a40dc;
        case 0x1a40e8u: goto label_1a40e8;
        case 0x1a4100u: goto label_1a4100;
        case 0x1a4148u: goto label_1a4148;
        case 0x1a4168u: goto label_1a4168;
        case 0x1a4178u: goto label_1a4178;
        case 0x1a41d0u: goto label_1a41d0;
        case 0x1a4248u: goto label_1a4248;
        case 0x1a425cu: goto label_1a425c;
        case 0x1a4280u: goto label_1a4280;
        case 0x1a42a4u: goto label_1a42a4;
        case 0x1a42c0u: goto label_1a42c0;
        case 0x1a43f4u: goto label_1a43f4;
        case 0x1a4418u: goto label_1a4418;
        case 0x1a443cu: goto label_1a443c;
        default: break;
    }

    ctx->pc = 0x1a3f70u;

    // 0x1a3f70: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a3f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a3f74: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1a3f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1a3f78: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a3f78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a3f7c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a3f7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a3f80: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1a3f80u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3f84: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1a3f84u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3f88: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a3f88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a3f8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a3f8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a3f90: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a3f90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3f94: 0x3c05000a  lui         $a1, 0xA
    ctx->pc = 0x1a3f94u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)10 << 16));
    // 0x1a3f98: 0xc068d68  jal         func_1A35A0
    ctx->pc = 0x1A3F98u;
    SET_GPR_U32(ctx, 31, 0x1A3FA0u);
    ctx->pc = 0x1A3F9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3F98u;
            // 0x1a3f9c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35A0u;
    if (runtime->hasFunction(0x1A35A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3FA0u; }
        if (ctx->pc != 0x1A3FA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35A0_0x1a35a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3FA0u; }
        if (ctx->pc != 0x1A3FA0u) { return; }
    }
    ctx->pc = 0x1A3FA0u;
label_1a3fa0:
    // 0x1a3fa0: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A3FA0u;
    {
        const bool branch_taken_0x1a3fa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3fa0) {
            ctx->pc = 0x1A3FACu;
            goto label_1a3fac;
        }
    }
    ctx->pc = 0x1A3FA8u;
    // 0x1a3fa8: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x1a3fa8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a3fac:
    // 0x1a3fac: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x1a3facu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x1a3fb0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a3fb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3fb4: 0x34421000  ori         $v0, $v0, 0x1000
    ctx->pc = 0x1a3fb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4096);
    // 0x1a3fb8: 0xc068da8  jal         func_1A36A0
    ctx->pc = 0x1A3FB8u;
    SET_GPR_U32(ctx, 31, 0x1A3FC0u);
    ctx->pc = 0x1A3FBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3FB8u;
            // 0x1a3fbc: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A36A0u;
    if (runtime->hasFunction(0x1A36A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A36A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3FC0u; }
        if (ctx->pc != 0x1A3FC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A36A0_0x1a36a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3FC0u; }
        if (ctx->pc != 0x1A3FC0u) { return; }
    }
    ctx->pc = 0x1A3FC0u;
label_1a3fc0:
    // 0x1a3fc0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1a3fc0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3fc4: 0xc068df8  jal         func_1A37E0
    ctx->pc = 0x1A3FC4u;
    SET_GPR_U32(ctx, 31, 0x1A3FCCu);
    ctx->pc = 0x1A3FC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3FC4u;
            // 0x1a3fc8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A37E0u;
    if (runtime->hasFunction(0x1A37E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A37E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3FCCu; }
        if (ctx->pc != 0x1A3FCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A37E0_0x1a37e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3FCCu; }
        if (ctx->pc != 0x1A3FCCu) { return; }
    }
    ctx->pc = 0x1A3FCCu;
label_1a3fcc:
    // 0x1a3fcc: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x1a3fccu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x1a3fd0: 0xc068fb8  jal         func_1A3EE0
    ctx->pc = 0x1A3FD0u;
    SET_GPR_U32(ctx, 31, 0x1A3FD8u);
    ctx->pc = 0x1A3FD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3FD0u;
            // 0x1a3fd4: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3EE0u;
    if (runtime->hasFunction(0x1A3EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1A3EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3FD8u; }
        if (ctx->pc != 0x1A3FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3EE0_0x1a3ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3FD8u; }
        if (ctx->pc != 0x1A3FD8u) { return; }
    }
    ctx->pc = 0x1A3FD8u;
label_1a3fd8:
    // 0x1a3fd8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a3fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a3fdc: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A3FDCu;
    {
        const bool branch_taken_0x1a3fdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1A3FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3FDCu;
            // 0x1a3fe0: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3fdc) {
            ctx->pc = 0x1A3FF4u;
            goto label_1a3ff4;
        }
    }
    ctx->pc = 0x1A3FE4u;
    // 0x1a3fe4: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1a3fe4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a3fe8: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1a3fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1a3fec: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1a3fecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a3ff0: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x1a3ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
label_1a3ff4:
    // 0x1a3ff4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1A3FF4u;
    {
        const bool branch_taken_0x1a3ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3FF4u;
            // 0x1a3ff8: 0x782d  daddu       $t7, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3ff4) {
            ctx->pc = 0x1A4034u;
            goto label_1a4034;
        }
    }
    ctx->pc = 0x1A3FFCu;
label_1a3ffc:
    // 0x1a3ffc: 0xc068dd8  jal         func_1A3760
    ctx->pc = 0x1A3FFCu;
    SET_GPR_U32(ctx, 31, 0x1A4004u);
    ctx->pc = 0x1A4000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3FFCu;
            // 0x1a4000: 0x1e0282d  daddu       $a1, $t7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3760u;
    if (runtime->hasFunction(0x1A3760u)) {
        auto targetFn = runtime->lookupFunction(0x1A3760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4004u; }
        if (ctx->pc != 0x1A4004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3760_0x1a3760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4004u; }
        if (ctx->pc != 0x1A4004u) { return; }
    }
    ctx->pc = 0x1A4004u;
label_1a4004:
    // 0x1a4004: 0x40682d  daddu       $t5, $v0, $zero
    ctx->pc = 0x1a4004u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4008: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A4008u;
    {
        const bool branch_taken_0x1a4008 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A400Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4008u;
            // 0x1a400c: 0x702d  daddu       $t6, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4008) {
            ctx->pc = 0x1A4024u;
            goto label_1a4024;
        }
    }
    ctx->pc = 0x1A4010u;
label_1a4010:
    // 0x1a4010: 0x1e0282d  daddu       $a1, $t7, $zero
    ctx->pc = 0x1a4010u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4014: 0xc068e4c  jal         func_1A3930
    ctx->pc = 0x1A4014u;
    SET_GPR_U32(ctx, 31, 0x1A401Cu);
    ctx->pc = 0x1A4018u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4014u;
            // 0x1a4018: 0x1c0302d  daddu       $a2, $t6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3930u;
    if (runtime->hasFunction(0x1A3930u)) {
        auto targetFn = runtime->lookupFunction(0x1A3930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A401Cu; }
        if (ctx->pc != 0x1A401Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3930_0x1a3930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A401Cu; }
        if (ctx->pc != 0x1A401Cu) { return; }
    }
    ctx->pc = 0x1A401Cu;
label_1a401c:
    // 0x1a401c: 0x1826021  addu        $t4, $t4, $v0
    ctx->pc = 0x1a401cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 2)));
    // 0x1a4020: 0x25ce0001  addiu       $t6, $t6, 0x1
    ctx->pc = 0x1a4020u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 1));
label_1a4024:
    // 0x1a4024: 0x1cd102a  slt         $v0, $t6, $t5
    ctx->pc = 0x1a4024u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 14) < (int64_t)GPR_S64(ctx, 13)) ? 1 : 0);
    // 0x1a4028: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A4028u;
    {
        const bool branch_taken_0x1a4028 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A402Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4028u;
            // 0x1a402c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4028) {
            ctx->pc = 0x1A4010u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a4010;
        }
    }
    ctx->pc = 0x1A4030u;
    // 0x1a4030: 0x25ef0001  addiu       $t7, $t7, 0x1
    ctx->pc = 0x1a4030u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
label_1a4034:
    // 0x1a4034: 0x1f1102a  slt         $v0, $t7, $s1
    ctx->pc = 0x1a4034u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 15) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1a4038: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1A4038u;
    {
        const bool branch_taken_0x1a4038 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A403Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4038u;
            // 0x1a403c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4038) {
            ctx->pc = 0x1A3FFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3ffc;
        }
    }
    ctx->pc = 0x1A4040u;
    // 0x1a4040: 0x8e650004  lw          $a1, 0x4($s3)
    ctx->pc = 0x1a4040u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x1a4044: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1a4044u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1a4048: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1a4048u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a404c: 0xac2021  addu        $a0, $a1, $t4
    ctx->pc = 0x1a404cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 12)));
    // 0x1a4050: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1a4050u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1a4054: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A4054u;
    {
        const bool branch_taken_0x1a4054 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4054u;
            // 0x1a4058: 0x42040  sll         $a0, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4054) {
            ctx->pc = 0x1A4064u;
            goto label_1a4064;
        }
    }
    ctx->pc = 0x1A405Cu;
    // 0x1a405c: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1a405cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a4060: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a4060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a4064:
    // 0x1a4064: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a4064u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a4068: 0x8c22ffe0  lw          $v0, -0x20($at)
    ctx->pc = 0x1a4068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967264)));
    // 0x1a406c: 0x44082a  slt         $at, $v0, $a0
    ctx->pc = 0x1a406cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1a4070: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A4070u;
    {
        const bool branch_taken_0x1a4070 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4070u;
            // 0x1a4074: 0x3c010004  lui         $at, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4070) {
            ctx->pc = 0x1A4084u;
            goto label_1a4084;
        }
    }
    ctx->pc = 0x1A4078u;
    // 0x1a4078: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a4078u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a407c: 0xac24ffe0  sw          $a0, -0x20($at)
    ctx->pc = 0x1a407cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967264), GPR_U32(ctx, 4));
    // 0x1a4080: 0x3c010004  lui         $at, 0x4
    ctx->pc = 0x1a4080u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
label_1a4084:
    // 0x1a4084: 0x34210001  ori         $at, $at, 0x1
    ctx->pc = 0x1a4084u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)1);
    // 0x1a4088: 0x81082a  slt         $at, $a0, $at
    ctx->pc = 0x1a4088u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1a408c: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A408Cu;
    {
        const bool branch_taken_0x1a408c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A408Cu;
            // 0x1a4090: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a408c) {
            ctx->pc = 0x1A409Cu;
            goto label_1a409c;
        }
    }
    ctx->pc = 0x1A4094u;
    // 0x1a4094: 0x10000138  b           . + 4 + (0x138 << 2)
    ctx->pc = 0x1A4094u;
    {
        const bool branch_taken_0x1a4094 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4094u;
            // 0x1a4098: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4094) {
            ctx->pc = 0x1A4578u;
            goto label_1a4578;
        }
    }
    ctx->pc = 0x1A409Cu;
label_1a409c:
    // 0x1a409c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1a409cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1a40a0: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A40A0u;
    {
        const bool branch_taken_0x1a40a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A40A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A40A0u;
            // 0x1a40a4: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a40a0) {
            ctx->pc = 0x1A40B0u;
            goto label_1a40b0;
        }
    }
    ctx->pc = 0x1A40A8u;
    // 0x1a40a8: 0x10000133  b           . + 4 + (0x133 << 2)
    ctx->pc = 0x1A40A8u;
    {
        const bool branch_taken_0x1a40a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A40ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A40A8u;
            // 0x1a40ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a40a8) {
            ctx->pc = 0x1A4578u;
            goto label_1a4578;
        }
    }
    ctx->pc = 0x1A40B0u;
label_1a40b0:
    // 0x1a40b0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a40b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a40b4: 0xae620008  sw          $v0, 0x8($s3)
    ctx->pc = 0x1a40b4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 2));
    // 0x1a40b8: 0xae64001c  sw          $a0, 0x1C($s3)
    ctx->pc = 0x1a40b8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 4));
    // 0x1a40bc: 0x8e780008  lw          $t8, 0x8($s3)
    ctx->pc = 0x1a40bcu;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a40c0: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1A40C0u;
    {
        const bool branch_taken_0x1a40c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A40C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A40C0u;
            // 0x1a40c4: 0x702d  daddu       $t6, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a40c0) {
            ctx->pc = 0x1A41A4u;
            goto label_1a41a4;
        }
    }
    ctx->pc = 0x1A40C8u;
label_1a40c8:
    // 0x1a40c8: 0xc068dd8  jal         func_1A3760
    ctx->pc = 0x1A40C8u;
    SET_GPR_U32(ctx, 31, 0x1A40D0u);
    ctx->pc = 0x1A40CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A40C8u;
            // 0x1a40cc: 0x1c0282d  daddu       $a1, $t6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3760u;
    if (runtime->hasFunction(0x1A3760u)) {
        auto targetFn = runtime->lookupFunction(0x1A3760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A40D0u; }
        if (ctx->pc != 0x1A40D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3760_0x1a3760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A40D0u; }
        if (ctx->pc != 0x1A40D0u) { return; }
    }
    ctx->pc = 0x1A40D0u;
label_1a40d0:
    // 0x1a40d0: 0x40682d  daddu       $t5, $v0, $zero
    ctx->pc = 0x1a40d0u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a40d4: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1A40D4u;
    {
        const bool branch_taken_0x1a40d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A40D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A40D4u;
            // 0x1a40d8: 0x602d  daddu       $t4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a40d4) {
            ctx->pc = 0x1A4194u;
            goto label_1a4194;
        }
    }
    ctx->pc = 0x1A40DCu;
label_1a40dc:
    // 0x1a40dc: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x1a40dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a40e0: 0xc068e4c  jal         func_1A3930
    ctx->pc = 0x1A40E0u;
    SET_GPR_U32(ctx, 31, 0x1A40E8u);
    ctx->pc = 0x1A40E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A40E0u;
            // 0x1a40e4: 0x180302d  daddu       $a2, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3930u;
    if (runtime->hasFunction(0x1A3930u)) {
        auto targetFn = runtime->lookupFunction(0x1A3930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A40E8u; }
        if (ctx->pc != 0x1A40E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3930_0x1a3930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A40E8u; }
        if (ctx->pc != 0x1A40E8u) { return; }
    }
    ctx->pc = 0x1A40E8u;
label_1a40e8:
    // 0x1a40e8: 0xa7020000  sh          $v0, 0x0($t8)
    ctx->pc = 0x1a40e8u;
    WRITE16(ADD32(GPR_U32(ctx, 24), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a40ec: 0x40782d  daddu       $t7, $v0, $zero
    ctx->pc = 0x1a40ecu;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a40f0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a40f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a40f4: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x1a40f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a40f8: 0xc068e78  jal         func_1A39E0
    ctx->pc = 0x1A40F8u;
    SET_GPR_U32(ctx, 31, 0x1A4100u);
    ctx->pc = 0x1A40FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A40F8u;
            // 0x1a40fc: 0x180302d  daddu       $a2, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A39E0u;
    if (runtime->hasFunction(0x1A39E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A39E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4100u; }
        if (ctx->pc != 0x1A4100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A39E0_0x1a39e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4100u; }
        if (ctx->pc != 0x1A4100u) { return; }
    }
    ctx->pc = 0x1A4100u;
label_1a4100:
    // 0x1a4100: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4100u;
    {
        const bool branch_taken_0x1a4100 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a4100) {
            ctx->pc = 0x1A4118u;
            goto label_1a4118;
        }
    }
    ctx->pc = 0x1A4108u;
    // 0x1a4108: 0x97020000  lhu         $v0, 0x0($t8)
    ctx->pc = 0x1a4108u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x1a410c: 0x34428000  ori         $v0, $v0, 0x8000
    ctx->pc = 0x1a410cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x1a4110: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A4110u;
    {
        const bool branch_taken_0x1a4110 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4110u;
            // 0x1a4114: 0xa7020000  sh          $v0, 0x0($t8) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 24), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4110) {
            ctx->pc = 0x1A4124u;
            goto label_1a4124;
        }
    }
    ctx->pc = 0x1A4118u;
label_1a4118:
    // 0x1a4118: 0x97020000  lhu         $v0, 0x0($t8)
    ctx->pc = 0x1a4118u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x1a411c: 0x34424000  ori         $v0, $v0, 0x4000
    ctx->pc = 0x1a411cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16384);
    // 0x1a4120: 0xa7020000  sh          $v0, 0x0($t8)
    ctx->pc = 0x1a4120u;
    WRITE16(ADD32(GPR_U32(ctx, 24), 0), (uint16_t)GPR_U32(ctx, 2));
label_1a4124:
    // 0x1a4124: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1a4124u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a4128: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x1a4128u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x1a412c: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1a412cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1a4130: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A4130u;
    {
        const bool branch_taken_0x1a4130 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4130u;
            // 0x1a4134: 0x27180002  addiu       $t8, $t8, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4130) {
            ctx->pc = 0x1A4150u;
            goto label_1a4150;
        }
    }
    ctx->pc = 0x1A4138u;
    // 0x1a4138: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a4138u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a413c: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x1a413cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4140: 0xc068e20  jal         func_1A3880
    ctx->pc = 0x1A4140u;
    SET_GPR_U32(ctx, 31, 0x1A4148u);
    ctx->pc = 0x1A4144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4140u;
            // 0x1a4144: 0x180302d  daddu       $a2, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3880u;
    if (runtime->hasFunction(0x1A3880u)) {
        auto targetFn = runtime->lookupFunction(0x1A3880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4148u; }
        if (ctx->pc != 0x1A4148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3880_0x1a3880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4148u; }
        if (ctx->pc != 0x1A4148u) { return; }
    }
    ctx->pc = 0x1A4148u;
label_1a4148:
    // 0x1a4148: 0xa7020000  sh          $v0, 0x0($t8)
    ctx->pc = 0x1a4148u;
    WRITE16(ADD32(GPR_U32(ctx, 24), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a414c: 0x27180002  addiu       $t8, $t8, 0x2
    ctx->pc = 0x1a414cu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 2));
label_1a4150:
    // 0x1a4150: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x1a4150u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1a4154: 0x30421000  andi        $v0, $v0, 0x1000
    ctx->pc = 0x1a4154u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4096);
    // 0x1a4158: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1A4158u;
    {
        const bool branch_taken_0x1a4158 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A415Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4158u;
            // 0x1a415c: 0xc82d  daddu       $t9, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4158) {
            ctx->pc = 0x1A4190u;
            goto label_1a4190;
        }
    }
    ctx->pc = 0x1A4160u;
    // 0x1a4160: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A4160u;
    {
        const bool branch_taken_0x1a4160 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4160u;
            // 0x1a4164: 0x32f102a  slt         $v0, $t9, $t7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 15)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4160) {
            ctx->pc = 0x1A4188u;
            goto label_1a4188;
        }
    }
    ctx->pc = 0x1A4168u;
label_1a4168:
    // 0x1a4168: 0x1c0282d  daddu       $a1, $t6, $zero
    ctx->pc = 0x1a4168u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a416c: 0x180302d  daddu       $a2, $t4, $zero
    ctx->pc = 0x1a416cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4170: 0xc068ea8  jal         func_1A3AA0
    ctx->pc = 0x1A4170u;
    SET_GPR_U32(ctx, 31, 0x1A4178u);
    ctx->pc = 0x1A4174u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4170u;
            // 0x1a4174: 0x320382d  daddu       $a3, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3AA0u;
    if (runtime->hasFunction(0x1A3AA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A3AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4178u; }
        if (ctx->pc != 0x1A4178u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3AA0_0x1a3aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4178u; }
        if (ctx->pc != 0x1A4178u) { return; }
    }
    ctx->pc = 0x1A4178u;
label_1a4178:
    // 0x1a4178: 0xa7020000  sh          $v0, 0x0($t8)
    ctx->pc = 0x1a4178u;
    WRITE16(ADD32(GPR_U32(ctx, 24), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1a417c: 0x27390001  addiu       $t9, $t9, 0x1
    ctx->pc = 0x1a417cu;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), 1));
    // 0x1a4180: 0x27180002  addiu       $t8, $t8, 0x2
    ctx->pc = 0x1a4180u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 24), 2));
    // 0x1a4184: 0x32f102a  slt         $v0, $t9, $t7
    ctx->pc = 0x1a4184u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 15)) ? 1 : 0);
label_1a4188:
    // 0x1a4188: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1A4188u;
    {
        const bool branch_taken_0x1a4188 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A418Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4188u;
            // 0x1a418c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4188) {
            ctx->pc = 0x1A4168u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a4168;
        }
    }
    ctx->pc = 0x1A4190u;
label_1a4190:
    // 0x1a4190: 0x258c0001  addiu       $t4, $t4, 0x1
    ctx->pc = 0x1a4190u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
label_1a4194:
    // 0x1a4194: 0x18d102a  slt         $v0, $t4, $t5
    ctx->pc = 0x1a4194u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 13)) ? 1 : 0);
    // 0x1a4198: 0x1440ffd0  bnez        $v0, . + 4 + (-0x30 << 2)
    ctx->pc = 0x1A4198u;
    {
        const bool branch_taken_0x1a4198 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A419Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4198u;
            // 0x1a419c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4198) {
            ctx->pc = 0x1A40DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a40dc;
        }
    }
    ctx->pc = 0x1A41A0u;
    // 0x1a41a0: 0x25ce0001  addiu       $t6, $t6, 0x1
    ctx->pc = 0x1a41a0u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 1));
label_1a41a4:
    // 0x1a41a4: 0x1d1102a  slt         $v0, $t6, $s1
    ctx->pc = 0x1a41a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 14) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1a41a8: 0x1440ffc7  bnez        $v0, . + 4 + (-0x39 << 2)
    ctx->pc = 0x1A41A8u;
    {
        const bool branch_taken_0x1a41a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A41ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A41A8u;
            // 0x1a41ac: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a41a8) {
            ctx->pc = 0x1A40C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a40c8;
        }
    }
    ctx->pc = 0x1A41B0u;
    // 0x1a41b0: 0x24020025  addiu       $v0, $zero, 0x25
    ctx->pc = 0x1a41b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
    // 0x1a41b4: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A41B4u;
    {
        const bool branch_taken_0x1a41b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A41B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A41B4u;
            // 0x1a41b8: 0xae62000c  sw          $v0, 0xC($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a41b4) {
            ctx->pc = 0x1A41C8u;
            goto label_1a41c8;
        }
    }
    ctx->pc = 0x1A41BCu;
    // 0x1a41bc: 0x8e62000c  lw          $v0, 0xC($s3)
    ctx->pc = 0x1a41bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x1a41c0: 0x34420010  ori         $v0, $v0, 0x10
    ctx->pc = 0x1a41c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
    // 0x1a41c4: 0xae62000c  sw          $v0, 0xC($s3)
    ctx->pc = 0x1a41c4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 2));
label_1a41c8:
    // 0x1a41c8: 0xc068e10  jal         func_1A3840
    ctx->pc = 0x1A41C8u;
    SET_GPR_U32(ctx, 31, 0x1A41D0u);
    ctx->pc = 0x1A41CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A41C8u;
            // 0x1a41cc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3840u;
    if (runtime->hasFunction(0x1A3840u)) {
        auto targetFn = runtime->lookupFunction(0x1A3840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A41D0u; }
        if (ctx->pc != 0x1A41D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3840_0x1a3840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A41D0u; }
        if (ctx->pc != 0x1A41D0u) { return; }
    }
    ctx->pc = 0x1A41D0u;
label_1a41d0:
    // 0x1a41d0: 0xae620014  sw          $v0, 0x14($s3)
    ctx->pc = 0x1a41d0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 2));
    // 0x1a41d4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a41d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a41d8: 0x8e640014  lw          $a0, 0x14($s3)
    ctx->pc = 0x1a41d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 20)));
    // 0x1a41dc: 0x8c22ffe0  lw          $v0, -0x20($at)
    ctx->pc = 0x1a41dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967264)));
    // 0x1a41e0: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x1a41e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1a41e4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a41e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a41e8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a41e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a41ec: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1a41ecu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1a41f0: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A41F0u;
    {
        const bool branch_taken_0x1a41f0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A41F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A41F0u;
            // 0x1a41f4: 0x3c010004  lui         $at, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a41f0) {
            ctx->pc = 0x1A4204u;
            goto label_1a4204;
        }
    }
    ctx->pc = 0x1A41F8u;
    // 0x1a41f8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a41f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a41fc: 0xac23ffe0  sw          $v1, -0x20($at)
    ctx->pc = 0x1a41fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967264), GPR_U32(ctx, 3));
    // 0x1a4200: 0x3c010004  lui         $at, 0x4
    ctx->pc = 0x1a4200u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4 << 16));
label_1a4204:
    // 0x1a4204: 0x34210001  ori         $at, $at, 0x1
    ctx->pc = 0x1a4204u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)1);
    // 0x1a4208: 0x61082a  slt         $at, $v1, $at
    ctx->pc = 0x1a4208u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 1)) ? 1 : 0);
    // 0x1a420c: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A420Cu;
    {
        const bool branch_taken_0x1a420c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A420Cu;
            // 0x1a4210: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a420c) {
            ctx->pc = 0x1A421Cu;
            goto label_1a421c;
        }
    }
    ctx->pc = 0x1A4214u;
    // 0x1a4214: 0x100000d8  b           . + 4 + (0xD8 << 2)
    ctx->pc = 0x1A4214u;
    {
        const bool branch_taken_0x1a4214 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4214u;
            // 0x1a4218: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4214) {
            ctx->pc = 0x1A4578u;
            goto label_1a4578;
        }
    }
    ctx->pc = 0x1A421Cu;
label_1a421c:
    // 0x1a421c: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1a421cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1a4220: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A4220u;
    {
        const bool branch_taken_0x1a4220 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4220u;
            // 0x1a4224: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4220) {
            ctx->pc = 0x1A4230u;
            goto label_1a4230;
        }
    }
    ctx->pc = 0x1A4228u;
    // 0x1a4228: 0x100000d3  b           . + 4 + (0xD3 << 2)
    ctx->pc = 0x1A4228u;
    {
        const bool branch_taken_0x1a4228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A422Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4228u;
            // 0x1a422c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4228) {
            ctx->pc = 0x1A4578u;
            goto label_1a4578;
        }
    }
    ctx->pc = 0x1A4230u;
label_1a4230:
    // 0x1a4230: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x1a4230u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1a4234: 0xae620010  sw          $v0, 0x10($s3)
    ctx->pc = 0x1a4234u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x1a4238: 0xae630018  sw          $v1, 0x18($s3)
    ctx->pc = 0x1a4238u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 24), GPR_U32(ctx, 3));
    // 0x1a423c: 0x8e690010  lw          $t1, 0x10($s3)
    ctx->pc = 0x1a423cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1a4240: 0x100000c9  b           . + 4 + (0xC9 << 2)
    ctx->pc = 0x1A4240u;
    {
        const bool branch_taken_0x1a4240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4240u;
            // 0x1a4244: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4240) {
            ctx->pc = 0x1A4568u;
            goto label_1a4568;
        }
    }
    ctx->pc = 0x1A4248u;
label_1a4248:
    // 0x1a4248: 0x12000068  beqz        $s0, . + 4 + (0x68 << 2)
    ctx->pc = 0x1A4248u;
    {
        const bool branch_taken_0x1a4248 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A424Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4248u;
            // 0x1a424c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4248) {
            ctx->pc = 0x1A43ECu;
            goto label_1a43ec;
        }
    }
    ctx->pc = 0x1A4250u;
    // 0x1a4250: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a4250u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4254: 0xc068ee0  jal         func_1A3B80
    ctx->pc = 0x1A4254u;
    SET_GPR_U32(ctx, 31, 0x1A425Cu);
    ctx->pc = 0x1A4258u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4254u;
            // 0x1a4258: 0x140282d  daddu       $a1, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3B80u;
    if (runtime->hasFunction(0x1A3B80u)) {
        auto targetFn = runtime->lookupFunction(0x1A3B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A425Cu; }
        if (ctx->pc != 0x1A425Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3B80_0x1a3b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A425Cu; }
        if (ctx->pc != 0x1A425Cu) { return; }
    }
    ctx->pc = 0x1A425Cu;
label_1a425c:
    // 0x1a425c: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1a425cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4260: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a4260u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4264: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x1a4264u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4268: 0xe5200000  swc1        $f0, 0x0($t1)
    ctx->pc = 0x1a4268u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 0), bits); }
    // 0x1a426c: 0xc4400004  lwc1        $f0, 0x4($v0)
    ctx->pc = 0x1a426cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4270: 0xe5200004  swc1        $f0, 0x4($t1)
    ctx->pc = 0x1a4270u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 4), bits); }
    // 0x1a4274: 0xc4400008  lwc1        $f0, 0x8($v0)
    ctx->pc = 0x1a4274u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4278: 0xc068ef4  jal         func_1A3BD0
    ctx->pc = 0x1A4278u;
    SET_GPR_U32(ctx, 31, 0x1A4280u);
    ctx->pc = 0x1A427Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4278u;
            // 0x1a427c: 0xe5200008  swc1        $f0, 0x8($t1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3BD0u;
    if (runtime->hasFunction(0x1A3BD0u)) {
        auto targetFn = runtime->lookupFunction(0x1A3BD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4280u; }
        if (ctx->pc != 0x1A4280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3BD0_0x1a3bd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4280u; }
        if (ctx->pc != 0x1A4280u) { return; }
    }
    ctx->pc = 0x1A4280u;
label_1a4280:
    // 0x1a4280: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1a4280u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4284: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a4284u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4288: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x1a4288u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a428c: 0xe520000c  swc1        $f0, 0xC($t1)
    ctx->pc = 0x1a428cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 12), bits); }
    // 0x1a4290: 0xc4400004  lwc1        $f0, 0x4($v0)
    ctx->pc = 0x1a4290u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4294: 0xe5200010  swc1        $f0, 0x10($t1)
    ctx->pc = 0x1a4294u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 16), bits); }
    // 0x1a4298: 0xc4400008  lwc1        $f0, 0x8($v0)
    ctx->pc = 0x1a4298u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a429c: 0xc068f08  jal         func_1A3C20
    ctx->pc = 0x1A429Cu;
    SET_GPR_U32(ctx, 31, 0x1A42A4u);
    ctx->pc = 0x1A42A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A429Cu;
            // 0x1a42a0: 0xe5200014  swc1        $f0, 0x14($t1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 20), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3C20u;
    if (runtime->hasFunction(0x1A3C20u)) {
        auto targetFn = runtime->lookupFunction(0x1A3C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A42A4u; }
        if (ctx->pc != 0x1A42A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3C20_0x1a3c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A42A4u; }
        if (ctx->pc != 0x1A42A4u) { return; }
    }
    ctx->pc = 0x1A42A4u;
label_1a42a4:
    // 0x1a42a4: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1a42a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a42a8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a42a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a42ac: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x1a42acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a42b0: 0xe520001c  swc1        $f0, 0x1C($t1)
    ctx->pc = 0x1a42b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 28), bits); }
    // 0x1a42b4: 0xc4400004  lwc1        $f0, 0x4($v0)
    ctx->pc = 0x1a42b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a42b8: 0xc068f18  jal         func_1A3C60
    ctx->pc = 0x1A42B8u;
    SET_GPR_U32(ctx, 31, 0x1A42C0u);
    ctx->pc = 0x1A42BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A42B8u;
            // 0x1a42bc: 0xe5200020  swc1        $f0, 0x20($t1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 32), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3C60u;
    if (runtime->hasFunction(0x1A3C60u)) {
        auto targetFn = runtime->lookupFunction(0x1A3C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A42C0u; }
        if (ctx->pc != 0x1A42C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3C60_0x1a3c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A42C0u; }
        if (ctx->pc != 0x1A42C0u) { return; }
    }
    ctx->pc = 0x1A42C0u;
label_1a42c0:
    // 0x1a42c0: 0xc441000c  lwc1        $f1, 0xC($v0)
    ctx->pc = 0x1a42c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a42c4: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a42c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a42c8: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a42c8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a42cc: 0x0  nop
    ctx->pc = 0x1a42ccu;
    // NOP
    // 0x1a42d0: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a42d0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a42d4: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A42D4u;
    {
        const bool branch_taken_0x1a42d4 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a42d4) {
            ctx->pc = 0x1A42ECu;
            goto label_1a42ec;
        }
    }
    ctx->pc = 0x1A42DCu;
    // 0x1a42dc: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a42dcu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a42e0: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a42e0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a42e4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A42E4u;
    {
        const bool branch_taken_0x1a42e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A42E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A42E4u;
            // 0x1a42e8: 0xc4410000  lwc1        $f1, 0x0($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a42e4) {
            ctx->pc = 0x1A4308u;
            goto label_1a4308;
        }
    }
    ctx->pc = 0x1A42ECu;
label_1a42ec:
    // 0x1a42ec: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a42ecu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a42f0: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a42f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a42f4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a42f4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a42f8: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a42f8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a42fc: 0x0  nop
    ctx->pc = 0x1a42fcu;
    // NOP
    // 0x1a4300: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a4300u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a4304: 0xc4410000  lwc1        $f1, 0x0($v0)
    ctx->pc = 0x1a4304u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a4308:
    // 0x1a4308: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a4308u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a430c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a430cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4310: 0x0  nop
    ctx->pc = 0x1a4310u;
    // NOP
    // 0x1a4314: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a4314u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a4318: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4318u;
    {
        const bool branch_taken_0x1a4318 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1A431Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4318u;
            // 0x1a431c: 0x42e00  sll         $a1, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4318) {
            ctx->pc = 0x1A4330u;
            goto label_1a4330;
        }
    }
    ctx->pc = 0x1A4320u;
    // 0x1a4320: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4320u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4324: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a4324u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4328: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A4328u;
    {
        const bool branch_taken_0x1a4328 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A432Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4328u;
            // 0x1a432c: 0xc4410004  lwc1        $f1, 0x4($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4328) {
            ctx->pc = 0x1A434Cu;
            goto label_1a434c;
        }
    }
    ctx->pc = 0x1A4330u;
label_1a4330:
    // 0x1a4330: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a4330u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a4334: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a4334u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a4338: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4338u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a433c: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a433cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4340: 0x0  nop
    ctx->pc = 0x1a4340u;
    // NOP
    // 0x1a4344: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a4344u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a4348: 0xc4410004  lwc1        $f1, 0x4($v0)
    ctx->pc = 0x1a4348u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a434c:
    // 0x1a434c: 0x41c00  sll         $v1, $a0, 16
    ctx->pc = 0x1a434cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1a4350: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x1a4350u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1a4354: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a4354u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a4358: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a4358u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a435c: 0x0  nop
    ctx->pc = 0x1a435cu;
    // NOP
    // 0x1a4360: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a4360u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a4364: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4364u;
    {
        const bool branch_taken_0x1a4364 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a4364) {
            ctx->pc = 0x1A437Cu;
            goto label_1a437c;
        }
    }
    ctx->pc = 0x1A436Cu;
    // 0x1a436c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a436cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4370: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a4370u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4374: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A4374u;
    {
        const bool branch_taken_0x1a4374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4374u;
            // 0x1a4378: 0xc4410008  lwc1        $f1, 0x8($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4374) {
            ctx->pc = 0x1A4398u;
            goto label_1a4398;
        }
    }
    ctx->pc = 0x1A437Cu;
label_1a437c:
    // 0x1a437c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a437cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a4380: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a4380u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a4384: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4384u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4388: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a4388u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a438c: 0x0  nop
    ctx->pc = 0x1a438cu;
    // NOP
    // 0x1a4390: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a4390u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a4394: 0xc4410008  lwc1        $f1, 0x8($v0)
    ctx->pc = 0x1a4394u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a4398:
    // 0x1a4398: 0x41a00  sll         $v1, $a0, 8
    ctx->pc = 0x1a4398u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1a439c: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1a439cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1a43a0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a43a0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a43a4: 0x0  nop
    ctx->pc = 0x1a43a4u;
    // NOP
    // 0x1a43a8: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a43a8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a43ac: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A43ACu;
    {
        const bool branch_taken_0x1a43ac = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1A43B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A43ACu;
            // 0x1a43b0: 0x652025  or          $a0, $v1, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a43ac) {
            ctx->pc = 0x1A43C4u;
            goto label_1a43c4;
        }
    }
    ctx->pc = 0x1A43B4u;
    // 0x1a43b4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a43b4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a43b8: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a43b8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a43bc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A43BCu;
    {
        const bool branch_taken_0x1a43bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A43C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A43BCu;
            // 0x1a43c0: 0x641025  or          $v0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a43bc) {
            ctx->pc = 0x1A43E0u;
            goto label_1a43e0;
        }
    }
    ctx->pc = 0x1A43C4u;
label_1a43c4:
    // 0x1a43c4: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a43c4u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a43c8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1a43c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1a43cc: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a43ccu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a43d0: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a43d0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a43d4: 0x0  nop
    ctx->pc = 0x1a43d4u;
    // NOP
    // 0x1a43d8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1a43d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a43dc: 0x641025  or          $v0, $v1, $a0
    ctx->pc = 0x1a43dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
label_1a43e0:
    // 0x1a43e0: 0xad220018  sw          $v0, 0x18($t1)
    ctx->pc = 0x1a43e0u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 24), GPR_U32(ctx, 2));
    // 0x1a43e4: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x1A43E4u;
    {
        const bool branch_taken_0x1a43e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A43E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A43E4u;
            // 0x1a43e8: 0x25290024  addiu       $t1, $t1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 36));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a43e4) {
            ctx->pc = 0x1A4564u;
            goto label_1a4564;
        }
    }
    ctx->pc = 0x1A43ECu;
label_1a43ec:
    // 0x1a43ec: 0xc068ee0  jal         func_1A3B80
    ctx->pc = 0x1A43ECu;
    SET_GPR_U32(ctx, 31, 0x1A43F4u);
    ctx->pc = 0x1A43F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A43ECu;
            // 0x1a43f0: 0x140282d  daddu       $a1, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3B80u;
    if (runtime->hasFunction(0x1A3B80u)) {
        auto targetFn = runtime->lookupFunction(0x1A3B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A43F4u; }
        if (ctx->pc != 0x1A43F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3B80_0x1a3b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A43F4u; }
        if (ctx->pc != 0x1A43F4u) { return; }
    }
    ctx->pc = 0x1A43F4u;
label_1a43f4:
    // 0x1a43f4: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1a43f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a43f8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a43f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a43fc: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x1a43fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4400: 0xe5200000  swc1        $f0, 0x0($t1)
    ctx->pc = 0x1a4400u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 0), bits); }
    // 0x1a4404: 0xc4400004  lwc1        $f0, 0x4($v0)
    ctx->pc = 0x1a4404u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4408: 0xe5200004  swc1        $f0, 0x4($t1)
    ctx->pc = 0x1a4408u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 4), bits); }
    // 0x1a440c: 0xc4400008  lwc1        $f0, 0x8($v0)
    ctx->pc = 0x1a440cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4410: 0xc068ef4  jal         func_1A3BD0
    ctx->pc = 0x1A4410u;
    SET_GPR_U32(ctx, 31, 0x1A4418u);
    ctx->pc = 0x1A4414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4410u;
            // 0x1a4414: 0xe5200008  swc1        $f0, 0x8($t1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3BD0u;
    if (runtime->hasFunction(0x1A3BD0u)) {
        auto targetFn = runtime->lookupFunction(0x1A3BD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4418u; }
        if (ctx->pc != 0x1A4418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3BD0_0x1a3bd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A4418u; }
        if (ctx->pc != 0x1A4418u) { return; }
    }
    ctx->pc = 0x1A4418u;
label_1a4418:
    // 0x1a4418: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1a4418u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a441c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1a441cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4420: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x1a4420u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a4424: 0xe520000c  swc1        $f0, 0xC($t1)
    ctx->pc = 0x1a4424u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 12), bits); }
    // 0x1a4428: 0xc4400004  lwc1        $f0, 0x4($v0)
    ctx->pc = 0x1a4428u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a442c: 0xe5200010  swc1        $f0, 0x10($t1)
    ctx->pc = 0x1a442cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 16), bits); }
    // 0x1a4430: 0xc4400008  lwc1        $f0, 0x8($v0)
    ctx->pc = 0x1a4430u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a4434: 0xc068f18  jal         func_1A3C60
    ctx->pc = 0x1A4434u;
    SET_GPR_U32(ctx, 31, 0x1A443Cu);
    ctx->pc = 0x1A4438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4434u;
            // 0x1a4438: 0xe5200014  swc1        $f0, 0x14($t1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 9), 20), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3C60u;
    if (runtime->hasFunction(0x1A3C60u)) {
        auto targetFn = runtime->lookupFunction(0x1A3C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A443Cu; }
        if (ctx->pc != 0x1A443Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3C60_0x1a3c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A443Cu; }
        if (ctx->pc != 0x1A443Cu) { return; }
    }
    ctx->pc = 0x1A443Cu;
label_1a443c:
    // 0x1a443c: 0xc441000c  lwc1        $f1, 0xC($v0)
    ctx->pc = 0x1a443cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a4440: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a4440u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a4444: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a4444u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4448: 0x0  nop
    ctx->pc = 0x1a4448u;
    // NOP
    // 0x1a444c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a444cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a4450: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4450u;
    {
        const bool branch_taken_0x1a4450 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a4450) {
            ctx->pc = 0x1A4468u;
            goto label_1a4468;
        }
    }
    ctx->pc = 0x1A4458u;
    // 0x1a4458: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4458u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a445c: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a445cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4460: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A4460u;
    {
        const bool branch_taken_0x1a4460 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A4464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4460u;
            // 0x1a4464: 0xc4410000  lwc1        $f1, 0x0($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4460) {
            ctx->pc = 0x1A4484u;
            goto label_1a4484;
        }
    }
    ctx->pc = 0x1A4468u;
label_1a4468:
    // 0x1a4468: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a4468u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a446c: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a446cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a4470: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4470u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4474: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a4474u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4478: 0x0  nop
    ctx->pc = 0x1a4478u;
    // NOP
    // 0x1a447c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a447cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a4480: 0xc4410000  lwc1        $f1, 0x0($v0)
    ctx->pc = 0x1a4480u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a4484:
    // 0x1a4484: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a4484u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a4488: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a4488u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a448c: 0x0  nop
    ctx->pc = 0x1a448cu;
    // NOP
    // 0x1a4490: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a4490u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a4494: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4494u;
    {
        const bool branch_taken_0x1a4494 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1A4498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4494u;
            // 0x1a4498: 0x42e00  sll         $a1, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4494) {
            ctx->pc = 0x1A44ACu;
            goto label_1a44ac;
        }
    }
    ctx->pc = 0x1A449Cu;
    // 0x1a449c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a449cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a44a0: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a44a0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a44a4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A44A4u;
    {
        const bool branch_taken_0x1a44a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A44A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A44A4u;
            // 0x1a44a8: 0xc4410004  lwc1        $f1, 0x4($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a44a4) {
            ctx->pc = 0x1A44C8u;
            goto label_1a44c8;
        }
    }
    ctx->pc = 0x1A44ACu;
label_1a44ac:
    // 0x1a44ac: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a44acu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a44b0: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a44b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a44b4: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a44b4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a44b8: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a44b8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a44bc: 0x0  nop
    ctx->pc = 0x1a44bcu;
    // NOP
    // 0x1a44c0: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a44c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a44c4: 0xc4410004  lwc1        $f1, 0x4($v0)
    ctx->pc = 0x1a44c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a44c8:
    // 0x1a44c8: 0x41c00  sll         $v1, $a0, 16
    ctx->pc = 0x1a44c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1a44cc: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x1a44ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1a44d0: 0x3c034f00  lui         $v1, 0x4F00
    ctx->pc = 0x1a44d0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20224 << 16));
    // 0x1a44d4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1a44d4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a44d8: 0x0  nop
    ctx->pc = 0x1a44d8u;
    // NOP
    // 0x1a44dc: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a44dcu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a44e0: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A44E0u;
    {
        const bool branch_taken_0x1a44e0 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a44e0) {
            ctx->pc = 0x1A44F8u;
            goto label_1a44f8;
        }
    }
    ctx->pc = 0x1A44E8u;
    // 0x1a44e8: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a44e8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a44ec: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a44ecu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a44f0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A44F0u;
    {
        const bool branch_taken_0x1a44f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A44F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A44F0u;
            // 0x1a44f4: 0xc4410008  lwc1        $f1, 0x8($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a44f0) {
            ctx->pc = 0x1A4514u;
            goto label_1a4514;
        }
    }
    ctx->pc = 0x1A44F8u;
label_1a44f8:
    // 0x1a44f8: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a44f8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a44fc: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a44fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a4500: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4500u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4504: 0x44040800  mfc1        $a0, $f1
    ctx->pc = 0x1a4504u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1a4508: 0x0  nop
    ctx->pc = 0x1a4508u;
    // NOP
    // 0x1a450c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1a450cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1a4510: 0xc4410008  lwc1        $f1, 0x8($v0)
    ctx->pc = 0x1a4510u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
label_1a4514:
    // 0x1a4514: 0x41a00  sll         $v1, $a0, 8
    ctx->pc = 0x1a4514u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1a4518: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1a4518u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1a451c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a451cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4520: 0x0  nop
    ctx->pc = 0x1a4520u;
    // NOP
    // 0x1a4524: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1a4524u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a4528: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A4528u;
    {
        const bool branch_taken_0x1a4528 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1A452Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4528u;
            // 0x1a452c: 0x652025  or          $a0, $v1, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4528) {
            ctx->pc = 0x1A4540u;
            goto label_1a4540;
        }
    }
    ctx->pc = 0x1A4530u;
    // 0x1a4530: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4530u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a4534: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a4534u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a4538: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A4538u;
    {
        const bool branch_taken_0x1a4538 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A453Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4538u;
            // 0x1a453c: 0x641025  or          $v0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4538) {
            ctx->pc = 0x1A455Cu;
            goto label_1a455c;
        }
    }
    ctx->pc = 0x1A4540u;
label_1a4540:
    // 0x1a4540: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1a4540u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1a4544: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1a4544u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1a4548: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1a4548u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1a454c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1a454cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1a4550: 0x0  nop
    ctx->pc = 0x1a4550u;
    // NOP
    // 0x1a4554: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1a4554u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1a4558: 0x641025  or          $v0, $v1, $a0
    ctx->pc = 0x1a4558u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
label_1a455c:
    // 0x1a455c: 0xad220018  sw          $v0, 0x18($t1)
    ctx->pc = 0x1a455cu;
    WRITE32(ADD32(GPR_U32(ctx, 9), 24), GPR_U32(ctx, 2));
    // 0x1a4560: 0x2529001c  addiu       $t1, $t1, 0x1C
    ctx->pc = 0x1a4560u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 28));
label_1a4564:
    // 0x1a4564: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1a4564u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
label_1a4568:
    // 0x1a4568: 0x8e620014  lw          $v0, 0x14($s3)
    ctx->pc = 0x1a4568u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 20)));
    // 0x1a456c: 0x142102a  slt         $v0, $t2, $v0
    ctx->pc = 0x1a456cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a4570: 0x1440ff35  bnez        $v0, . + 4 + (-0xCB << 2)
    ctx->pc = 0x1A4570u;
    {
        const bool branch_taken_0x1a4570 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A4574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4570u;
            // 0x1a4574: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a4570) {
            ctx->pc = 0x1A4248u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a4248;
        }
    }
    ctx->pc = 0x1A4578u;
label_1a4578:
    // 0x1a4578: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1a4578u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a457c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a457cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a4580: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a4580u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a4584: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a4584u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a4588: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a4588u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a458c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A458Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A4590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A458Cu;
            // 0x1a4590: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3FA0u: goto label_1a3fa0;
            case 0x1A3FACu: goto label_1a3fac;
            case 0x1A3FC0u: goto label_1a3fc0;
            case 0x1A3FCCu: goto label_1a3fcc;
            case 0x1A3FD8u: goto label_1a3fd8;
            case 0x1A3FF4u: goto label_1a3ff4;
            case 0x1A3FFCu: goto label_1a3ffc;
            case 0x1A4004u: goto label_1a4004;
            case 0x1A4010u: goto label_1a4010;
            case 0x1A401Cu: goto label_1a401c;
            case 0x1A4024u: goto label_1a4024;
            case 0x1A4034u: goto label_1a4034;
            case 0x1A4064u: goto label_1a4064;
            case 0x1A4084u: goto label_1a4084;
            case 0x1A409Cu: goto label_1a409c;
            case 0x1A40B0u: goto label_1a40b0;
            case 0x1A40C8u: goto label_1a40c8;
            case 0x1A40D0u: goto label_1a40d0;
            case 0x1A40DCu: goto label_1a40dc;
            case 0x1A40E8u: goto label_1a40e8;
            case 0x1A4100u: goto label_1a4100;
            case 0x1A4118u: goto label_1a4118;
            case 0x1A4124u: goto label_1a4124;
            case 0x1A4148u: goto label_1a4148;
            case 0x1A4150u: goto label_1a4150;
            case 0x1A4168u: goto label_1a4168;
            case 0x1A4178u: goto label_1a4178;
            case 0x1A4188u: goto label_1a4188;
            case 0x1A4190u: goto label_1a4190;
            case 0x1A4194u: goto label_1a4194;
            case 0x1A41A4u: goto label_1a41a4;
            case 0x1A41C8u: goto label_1a41c8;
            case 0x1A41D0u: goto label_1a41d0;
            case 0x1A4204u: goto label_1a4204;
            case 0x1A421Cu: goto label_1a421c;
            case 0x1A4230u: goto label_1a4230;
            case 0x1A4248u: goto label_1a4248;
            case 0x1A425Cu: goto label_1a425c;
            case 0x1A4280u: goto label_1a4280;
            case 0x1A42A4u: goto label_1a42a4;
            case 0x1A42C0u: goto label_1a42c0;
            case 0x1A42ECu: goto label_1a42ec;
            case 0x1A4308u: goto label_1a4308;
            case 0x1A4330u: goto label_1a4330;
            case 0x1A434Cu: goto label_1a434c;
            case 0x1A437Cu: goto label_1a437c;
            case 0x1A4398u: goto label_1a4398;
            case 0x1A43C4u: goto label_1a43c4;
            case 0x1A43E0u: goto label_1a43e0;
            case 0x1A43ECu: goto label_1a43ec;
            case 0x1A43F4u: goto label_1a43f4;
            case 0x1A4418u: goto label_1a4418;
            case 0x1A443Cu: goto label_1a443c;
            case 0x1A4468u: goto label_1a4468;
            case 0x1A4484u: goto label_1a4484;
            case 0x1A44ACu: goto label_1a44ac;
            case 0x1A44C8u: goto label_1a44c8;
            case 0x1A44F8u: goto label_1a44f8;
            case 0x1A4514u: goto label_1a4514;
            case 0x1A4540u: goto label_1a4540;
            case 0x1A455Cu: goto label_1a455c;
            case 0x1A4564u: goto label_1a4564;
            case 0x1A4568u: goto label_1a4568;
            case 0x1A4578u: goto label_1a4578;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A4594u;
    // 0x1a4594: 0x0  nop
    ctx->pc = 0x1a4594u;
    // NOP
    // 0x1a4598: 0x0  nop
    ctx->pc = 0x1a4598u;
    // NOP
    // 0x1a459c: 0x0  nop
    ctx->pc = 0x1a459cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
