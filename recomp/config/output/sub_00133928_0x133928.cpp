#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133928
// Address: 0x133928 - 0x133ab8
void sub_00133928_0x133928(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133928_0x133928");
#endif

    switch (ctx->pc) {
        case 0x13395cu: goto label_13395c;
        case 0x133968u: goto label_133968;
        case 0x133974u: goto label_133974;
        case 0x1339a4u: goto label_1339a4;
        case 0x1339c0u: goto label_1339c0;
        case 0x1339e0u: goto label_1339e0;
        case 0x1339f8u: goto label_1339f8;
        case 0x133a04u: goto label_133a04;
        case 0x133a14u: goto label_133a14;
        case 0x133a20u: goto label_133a20;
        case 0x133a2cu: goto label_133a2c;
        case 0x133a4cu: goto label_133a4c;
        case 0x133a68u: goto label_133a68;
        case 0x133a80u: goto label_133a80;
        case 0x133a88u: goto label_133a88;
        default: break;
    }

    ctx->pc = 0x133928u;

    // 0x133928: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x133928u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x13392c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13392cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x133930: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x133930u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133934: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x133934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x133938: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x133938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x13393c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x13393cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x133940: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x133940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x133944: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x133944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x133948: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x133948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x13394c: 0x8e320004  lw          $s2, 0x4($s1)
    ctx->pc = 0x13394cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x133950: 0x8e300014  lw          $s0, 0x14($s1)
    ctx->pc = 0x133950u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x133954: 0xc04b61a  jal         func_12D868
    ctx->pc = 0x133954u;
    SET_GPR_U32(ctx, 31, 0x13395Cu);
    ctx->pc = 0x133958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133954u;
            // 0x133958: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D868u;
    if (runtime->hasFunction(0x12D868u)) {
        auto targetFn = runtime->lookupFunction(0x12D868u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13395Cu; }
        if (ctx->pc != 0x13395Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D868_0x12d868(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13395Cu; }
        if (ctx->pc != 0x13395Cu) { return; }
    }
    ctx->pc = 0x13395Cu;
label_13395c:
    // 0x13395c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13395cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133960: 0xc04b620  jal         func_12D880
    ctx->pc = 0x133960u;
    SET_GPR_U32(ctx, 31, 0x133968u);
    ctx->pc = 0x133964u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133960u;
            // 0x133964: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D880u;
    if (runtime->hasFunction(0x12D880u)) {
        auto targetFn = runtime->lookupFunction(0x12D880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133968u; }
        if (ctx->pc != 0x133968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D880_0x12d880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133968u; }
        if (ctx->pc != 0x133968u) { return; }
    }
    ctx->pc = 0x133968u;
label_133968:
    // 0x133968: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133968u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13396c: 0xc04b62c  jal         func_12D8B0
    ctx->pc = 0x13396Cu;
    SET_GPR_U32(ctx, 31, 0x133974u);
    ctx->pc = 0x133970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13396Cu;
            // 0x133970: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D8B0u;
    if (runtime->hasFunction(0x12D8B0u)) {
        auto targetFn = runtime->lookupFunction(0x12D8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133974u; }
        if (ctx->pc != 0x133974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D8B0_0x12d8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133974u; }
        if (ctx->pc != 0x133974u) { return; }
    }
    ctx->pc = 0x133974u;
label_133974:
    // 0x133974: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x133974u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133978: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x133978u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13397c: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x13397cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x133980: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x133980u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x133984: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x133984u;
    {
        const bool branch_taken_0x133984 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x133988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133984u;
            // 0x133988: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133984) {
            ctx->pc = 0x1339B0u;
            goto label_1339b0;
        }
    }
    ctx->pc = 0x13398Cu;
    // 0x13398c: 0x8222006c  lb          $v0, 0x6C($s1)
    ctx->pc = 0x13398cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 108)));
    // 0x133990: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x133990u;
    {
        const bool branch_taken_0x133990 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x133990) {
            ctx->pc = 0x133994u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x133990u;
            // 0x133994: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1339B4u;
            goto label_1339b4;
        }
    }
    ctx->pc = 0x133998u;
    // 0x133998: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x133998u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13399c: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x13399Cu;
    SET_GPR_U32(ctx, 31, 0x1339A4u);
    ctx->pc = 0x1339A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13399Cu;
            // 0x1339a0: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1339A4u; }
        if (ctx->pc != 0x1339A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1339A4u; }
        if (ctx->pc != 0x1339A4u) { return; }
    }
    ctx->pc = 0x1339A4u;
label_1339a4:
    // 0x1339a4: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1339A4u;
    {
        const bool branch_taken_0x1339a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1339A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1339A4u;
            // 0x1339a8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1339a4) {
            ctx->pc = 0x133A98u;
            goto label_133a98;
        }
    }
    ctx->pc = 0x1339ACu;
    // 0x1339ac: 0x0  nop
    ctx->pc = 0x1339acu;
    // NOP
label_1339b0:
    // 0x1339b0: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1339b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_1339b4:
    // 0x1339b4: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x1339b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1339b8: 0x40f809  jalr        $v0
    ctx->pc = 0x1339B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1339C0u);
        ctx->pc = 0x1339BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1339B8u;
            // 0x1339bc: 0x8e260050  lw          $a2, 0x50($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 80)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1339C0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1339C0u; }
            if (ctx->pc != 0x1339C0u) { return; }
        }
        }
    }
    ctx->pc = 0x1339C0u;
label_1339c0:
    // 0x1339c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1339c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1339c4: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1339c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1339c8: 0x8e230050  lw          $v1, 0x50($s1)
    ctx->pc = 0x1339c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 80)));
    // 0x1339cc: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1339ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1339d0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1339D0u;
    {
        const bool branch_taken_0x1339d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1339D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1339D0u;
            // 0x1339d4: 0x2484b6c0  addiu       $a0, $a0, -0x4940 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948544));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1339d0) {
            ctx->pc = 0x1339E0u;
            goto label_1339e0;
        }
    }
    ctx->pc = 0x1339D8u;
    // 0x1339d8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1339D8u;
    SET_GPR_U32(ctx, 31, 0x1339E0u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1339E0u; }
        if (ctx->pc != 0x1339E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1339E0u; }
        if (ctx->pc != 0x1339E0u) { return; }
    }
    ctx->pc = 0x1339E0u;
label_1339e0:
    // 0x1339e0: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1339e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1339e4: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1339e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1339e8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1339e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1339ec: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x1339ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1339f0: 0x40f809  jalr        $v0
    ctx->pc = 0x1339F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1339F8u);
        ctx->pc = 0x1339F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1339F0u;
            // 0x1339f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1339F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1339F8u; }
            if (ctx->pc != 0x1339F8u) { return; }
        }
        }
    }
    ctx->pc = 0x1339F8u;
label_1339f8:
    // 0x1339f8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1339f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1339fc: 0xc04b5d6  jal         func_12D758
    ctx->pc = 0x1339FCu;
    SET_GPR_U32(ctx, 31, 0x133A04u);
    ctx->pc = 0x133A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1339FCu;
            // 0x133a00: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D758u;
    if (runtime->hasFunction(0x12D758u)) {
        auto targetFn = runtime->lookupFunction(0x12D758u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A04u; }
        if (ctx->pc != 0x133A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D758_0x12d758(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A04u; }
        if (ctx->pc != 0x133A04u) { return; }
    }
    ctx->pc = 0x133A04u;
label_133a04:
    // 0x133a04: 0x2932823  subu        $a1, $s4, $s3
    ctx->pc = 0x133a04u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
    // 0x133a08: 0xae250090  sw          $a1, 0x90($s1)
    ctx->pc = 0x133a08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 5));
    // 0x133a0c: 0xc04b5d2  jal         func_12D748
    ctx->pc = 0x133A0Cu;
    SET_GPR_U32(ctx, 31, 0x133A14u);
    ctx->pc = 0x133A10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133A0Cu;
            // 0x133a10: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D748u;
    if (runtime->hasFunction(0x12D748u)) {
        auto targetFn = runtime->lookupFunction(0x12D748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A14u; }
        if (ctx->pc != 0x133A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D748_0x12d748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A14u; }
        if (ctx->pc != 0x133A14u) { return; }
    }
    ctx->pc = 0x133A14u;
label_133a14:
    // 0x133a14: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133a14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a18: 0xc04b5da  jal         func_12D768
    ctx->pc = 0x133A18u;
    SET_GPR_U32(ctx, 31, 0x133A20u);
    ctx->pc = 0x133A1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133A18u;
            // 0x133a1c: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D768u;
    if (runtime->hasFunction(0x12D768u)) {
        auto targetFn = runtime->lookupFunction(0x12D768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A20u; }
        if (ctx->pc != 0x133A20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D768_0x12d768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A20u; }
        if (ctx->pc != 0x133A20u) { return; }
    }
    ctx->pc = 0x133A20u;
label_133a20:
    // 0x133a20: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x133a20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a24: 0xc04b5ba  jal         func_12D6E8
    ctx->pc = 0x133A24u;
    SET_GPR_U32(ctx, 31, 0x133A2Cu);
    ctx->pc = 0x133A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133A24u;
            // 0x133a28: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D6E8u;
    if (runtime->hasFunction(0x12D6E8u)) {
        auto targetFn = runtime->lookupFunction(0x12D6E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A2Cu; }
        if (ctx->pc != 0x133A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D6E8_0x12d6e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A2Cu; }
        if (ctx->pc != 0x133A2Cu) { return; }
    }
    ctx->pc = 0x133A2Cu;
label_133a2c:
    // 0x133a2c: 0x82230002  lb          $v1, 0x2($s1)
    ctx->pc = 0x133a2cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x133a30: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x133a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x133a34: 0x14620012  bne         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x133A34u;
    {
        const bool branch_taken_0x133a34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x133A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133A34u;
            // 0x133a38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133a34) {
            ctx->pc = 0x133A80u;
            goto label_133a80;
        }
    }
    ctx->pc = 0x133A3Cu;
    // 0x133a3c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x133a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x133a40: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x133a40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x133a44: 0x60f809  jalr        $v1
    ctx->pc = 0x133A44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x133A4Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x133A4Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133A4Cu; }
            if (ctx->pc != 0x133A4Cu) { return; }
        }
        }
    }
    ctx->pc = 0x133A4Cu;
label_133a4c:
    // 0x133a4c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x133a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x133a50: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x133a50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x133a54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a58: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x133a58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x133a5c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x133a5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x133a60: 0x60f809  jalr        $v1
    ctx->pc = 0x133A60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x133A68u);
        ctx->pc = 0x133A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133A60u;
            // 0x133a64: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133A68u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133A68u; }
            if (ctx->pc != 0x133A68u) { return; }
        }
        }
    }
    ctx->pc = 0x133A68u;
label_133a68:
    // 0x133a68: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x133a68u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x133a6c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x133a6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a70: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x133a70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x133a74: 0x8cc20020  lw          $v0, 0x20($a2)
    ctx->pc = 0x133a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x133a78: 0x40f809  jalr        $v0
    ctx->pc = 0x133A78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x133A80u);
        ctx->pc = 0x133A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133A78u;
            // 0x133a7c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x133A80u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x133A80u; }
            if (ctx->pc != 0x133A80u) { return; }
        }
        }
    }
    ctx->pc = 0x133A80u;
label_133a80:
    // 0x133a80: 0xc04b694  jal         func_12DA50
    ctx->pc = 0x133A80u;
    SET_GPR_U32(ctx, 31, 0x133A88u);
    ctx->pc = 0x133A84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133A80u;
            // 0x133a84: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA50u;
    if (runtime->hasFunction(0x12DA50u)) {
        auto targetFn = runtime->lookupFunction(0x12DA50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A88u; }
        if (ctx->pc != 0x133A88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DA50_0x12da50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x133A88u; }
        if (ctx->pc != 0x133A88u) { return; }
    }
    ctx->pc = 0x133A88u;
label_133a88:
    // 0x133a88: 0x8e22004c  lw          $v0, 0x4C($s1)
    ctx->pc = 0x133a88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 76)));
    // 0x133a8c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x133a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x133a90: 0xae22004c  sw          $v0, 0x4C($s1)
    ctx->pc = 0x133a90u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 76), GPR_U32(ctx, 2));
    // 0x133a94: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x133a94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_133a98:
    // 0x133a98: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x133a98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x133a9c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x133a9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x133aa0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x133aa0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x133aa4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x133aa4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x133aa8: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x133aa8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x133aac: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x133aacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x133ab0: 0x3e00008  jr          $ra
    ctx->pc = 0x133AB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x133AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133AB0u;
            // 0x133ab4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13395Cu: goto label_13395c;
            case 0x133968u: goto label_133968;
            case 0x133974u: goto label_133974;
            case 0x1339A4u: goto label_1339a4;
            case 0x1339B0u: goto label_1339b0;
            case 0x1339B4u: goto label_1339b4;
            case 0x1339C0u: goto label_1339c0;
            case 0x1339E0u: goto label_1339e0;
            case 0x1339F8u: goto label_1339f8;
            case 0x133A04u: goto label_133a04;
            case 0x133A14u: goto label_133a14;
            case 0x133A20u: goto label_133a20;
            case 0x133A2Cu: goto label_133a2c;
            case 0x133A4Cu: goto label_133a4c;
            case 0x133A68u: goto label_133a68;
            case 0x133A80u: goto label_133a80;
            case 0x133A88u: goto label_133a88;
            case 0x133A98u: goto label_133a98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x133AB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
