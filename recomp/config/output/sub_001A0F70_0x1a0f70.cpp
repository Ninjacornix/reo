#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A0F70
// Address: 0x1a0f70 - 0x1a1270
void sub_001A0F70_0x1a0f70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A0F70_0x1a0f70");
#endif

    switch (ctx->pc) {
        case 0x1a0facu: goto label_1a0fac;
        case 0x1a0fdcu: goto label_1a0fdc;
        case 0x1a0ffcu: goto label_1a0ffc;
        case 0x1a1088u: goto label_1a1088;
        case 0x1a1124u: goto label_1a1124;
        case 0x1a112cu: goto label_1a112c;
        case 0x1a11bcu: goto label_1a11bc;
        case 0x1a1240u: goto label_1a1240;
        case 0x1a1254u: goto label_1a1254;
        default: break;
    }

    ctx->pc = 0x1a0f70u;

    // 0x1a0f70: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a0f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a0f74: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1a0f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1a0f78: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a0f78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a0f7c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a0f7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a0f80: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1a0f80u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0f84: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a0f84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a0f88: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1a0f88u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0f8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a0f8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a0f90: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x1a0f90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1a0f94: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x1a0f94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a0f98: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a0f98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a0f9c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1a0f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1a0fa0: 0x601827  not         $v1, $v1
    ctx->pc = 0x1a0fa0u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1a0fa4: 0xc068580  jal         func_1A1600
    ctx->pc = 0x1A0FA4u;
    SET_GPR_U32(ctx, 31, 0x1A0FACu);
    ctx->pc = 0x1A0FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FA4u;
            // 0x1a0fa8: 0x628024  and         $s0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1600u;
    if (runtime->hasFunction(0x1A1600u)) {
        auto targetFn = runtime->lookupFunction(0x1A1600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0FACu; }
        if (ctx->pc != 0x1A0FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1600_0x1a1600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0FACu; }
        if (ctx->pc != 0x1A0FACu) { return; }
    }
    ctx->pc = 0x1A0FACu;
label_1a0fac:
    // 0x1a0fac: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1a0facu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0fb0: 0x3407ffff  ori         $a3, $zero, 0xFFFF
    ctx->pc = 0x1a0fb0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a0fb4: 0x16270003  bne         $s1, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A0FB4u;
    {
        const bool branch_taken_0x1a0fb4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 7));
        if (branch_taken_0x1a0fb4) {
            ctx->pc = 0x1A0FC4u;
            goto label_1a0fc4;
        }
    }
    ctx->pc = 0x1A0FBCu;
    // 0x1a0fbc: 0x100000a5  b           . + 4 + (0xA5 << 2)
    ctx->pc = 0x1A0FBCu;
    {
        const bool branch_taken_0x1a0fbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0FC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FBCu;
            // 0x1a0fc0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0fbc) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A0FC4u;
label_1a0fc4:
    // 0x1a0fc4: 0x8e620024  lw          $v0, 0x24($s3)
    ctx->pc = 0x1a0fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 36)));
    // 0x1a0fc8: 0x14470006  bne         $v0, $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A0FC8u;
    {
        const bool branch_taken_0x1a0fc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        ctx->pc = 0x1A0FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FC8u;
            // 0x1a0fcc: 0x21900  sll         $v1, $v0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0fc8) {
            ctx->pc = 0x1A0FE4u;
            goto label_1a0fe4;
        }
    }
    ctx->pc = 0x1A0FD0u;
    // 0x1a0fd0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a0fd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a0fd4: 0xc068384  jal         func_1A0E10
    ctx->pc = 0x1A0FD4u;
    SET_GPR_U32(ctx, 31, 0x1A0FDCu);
    ctx->pc = 0x1A0FD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FD4u;
            // 0x1a0fd8: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0E10u;
    if (runtime->hasFunction(0x1A0E10u)) {
        auto targetFn = runtime->lookupFunction(0x1A0E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0FDCu; }
        if (ctx->pc != 0x1A0FDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0E10_0x1a0e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A0FDCu; }
        if (ctx->pc != 0x1A0FDCu) { return; }
    }
    ctx->pc = 0x1A0FDCu;
label_1a0fdc:
    // 0x1a0fdc: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1A0FDCu;
    {
        const bool branch_taken_0x1a0fdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FDCu;
            // 0x1a0fe0: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0fdc) {
            ctx->pc = 0x1A1258u;
            goto label_1a1258;
        }
    }
    ctx->pc = 0x1A0FE4u;
label_1a0fe4:
    // 0x1a0fe4: 0x8e64000c  lw          $a0, 0xC($s3)
    ctx->pc = 0x1a0fe4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x1a0fe8: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a0fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a0fec: 0x10800076  beqz        $a0, . + 4 + (0x76 << 2)
    ctx->pc = 0x1A0FECu;
    {
        const bool branch_taken_0x1a0fec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FECu;
            // 0x1a0ff0: 0x431821  addu        $v1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0fec) {
            ctx->pc = 0x1A11C8u;
            goto label_1a11c8;
        }
    }
    ctx->pc = 0x1A0FF4u;
    // 0x1a0ff4: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1A0FF4u;
    {
        const bool branch_taken_0x1a0ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A0FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A0FF4u;
            // 0x1a0ff8: 0x9464000e  lhu         $a0, 0xE($v1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a0ff4) {
            ctx->pc = 0x1A1098u;
            goto label_1a1098;
        }
    }
    ctx->pc = 0x1A0FFCu;
label_1a0ffc:
    // 0x1a0ffc: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x1a0ffcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a1000: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1a1000u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1a1004: 0x8c650004  lw          $a1, 0x4($v1)
    ctx->pc = 0x1a1004u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1a1008: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1a1008u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1a100c: 0x444821  addu        $t1, $v0, $a0
    ctx->pc = 0x1a100cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1a1010: 0x8e680018  lw          $t0, 0x18($s3)
    ctx->pc = 0x1a1010u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1014: 0x8d230000  lw          $v1, 0x0($t1)
    ctx->pc = 0x1a1014u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1a1018: 0xc52821  addu        $a1, $a2, $a1
    ctx->pc = 0x1a1018u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1a101c: 0x2504ffff  addiu       $a0, $t0, -0x1
    ctx->pc = 0x1a101cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x1a1020: 0x1052821  addu        $a1, $t0, $a1
    ctx->pc = 0x1a1020u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1a1024: 0x802027  not         $a0, $a0
    ctx->pc = 0x1a1024u;
    SET_GPR_U64(ctx, 4, ~(GPR_U64(ctx, 4) | GPR_U64(ctx, 0)));
    // 0x1a1028: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a1028u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a102c: 0x854024  and         $t0, $a0, $a1
    ctx->pc = 0x1a102cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x1a1030: 0x681823  subu        $v1, $v1, $t0
    ctx->pc = 0x1a1030u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1a1034: 0x70082b  sltu        $at, $v1, $s0
    ctx->pc = 0x1a1034u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a1038: 0x14200015  bnez        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1A1038u;
    {
        const bool branch_taken_0x1a1038 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A103Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1038u;
            // 0x1a103c: 0x113100  sll         $a2, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1038) {
            ctx->pc = 0x1A1090u;
            goto label_1a1090;
        }
    }
    ctx->pc = 0x1A1040u;
    // 0x1a1040: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a1040u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1044: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1a1044u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1a1048: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a1048u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a104c: 0xa440000a  sh          $zero, 0xA($v0)
    ctx->pc = 0x1a104cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a1050: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1050u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1054: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1a1054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1a1058: 0xac520004  sw          $s2, 0x4($v0)
    ctx->pc = 0x1a1058u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
    // 0x1a105c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a105cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1060: 0x8e630018  lw          $v1, 0x18($s3)
    ctx->pc = 0x1a1060u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1064: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x1a1064u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1a1068: 0xa4430008  sh          $v1, 0x8($v0)
    ctx->pc = 0x1a1068u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a106c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a106cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1070: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1a1070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1a1074: 0xac480000  sw          $t0, 0x0($v0)
    ctx->pc = 0x1a1074u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 8));
    // 0x1a1078: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a1078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a107c: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a107cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a1080: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A1080u;
    SET_GPR_U32(ctx, 31, 0x1A1088u);
    ctx->pc = 0x1A1084u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1080u;
            // 0x1a1084: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1088u; }
        if (ctx->pc != 0x1A1088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1088u; }
        if (ctx->pc != 0x1A1088u) { return; }
    }
    ctx->pc = 0x1A1088u;
label_1a1088:
    // 0x1a1088: 0x10000072  b           . + 4 + (0x72 << 2)
    ctx->pc = 0x1A1088u;
    {
        const bool branch_taken_0x1a1088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A108Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1088u;
            // 0x1a108c: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1088) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A1090u;
label_1a1090:
    // 0x1a1090: 0x120182d  daddu       $v1, $t1, $zero
    ctx->pc = 0x1a1090u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1094: 0x9464000e  lhu         $a0, 0xE($v1)
    ctx->pc = 0x1a1094u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
label_1a1098:
    // 0x1a1098: 0x1487ffd8  bne         $a0, $a3, . + 4 + (-0x28 << 2)
    ctx->pc = 0x1A1098u;
    {
        const bool branch_taken_0x1a1098 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 7));
        if (branch_taken_0x1a1098) {
            ctx->pc = 0x1A0FFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a0ffc;
        }
    }
    ctx->pc = 0x1A10A0u;
    // 0x1a10a0: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x1a10a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a10a4: 0x8c650004  lw          $a1, 0x4($v1)
    ctx->pc = 0x1a10a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1a10a8: 0x8e670018  lw          $a3, 0x18($s3)
    ctx->pc = 0x1a10a8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a10ac: 0x8e630010  lw          $v1, 0x10($s3)
    ctx->pc = 0x1a10acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1a10b0: 0xc52821  addu        $a1, $a2, $a1
    ctx->pc = 0x1a10b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1a10b4: 0x24e4ffff  addiu       $a0, $a3, -0x1
    ctx->pc = 0x1a10b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1a10b8: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x1a10b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x1a10bc: 0x802027  not         $a0, $a0
    ctx->pc = 0x1a10bcu;
    SET_GPR_U64(ctx, 4, ~(GPR_U64(ctx, 4) | GPR_U64(ctx, 0)));
    // 0x1a10c0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1a10c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a10c4: 0x853024  and         $a2, $a0, $a1
    ctx->pc = 0x1a10c4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x1a10c8: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x1a10c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1a10cc: 0x70082b  sltu        $at, $v1, $s0
    ctx->pc = 0x1a10ccu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a10d0: 0x1420005e  bnez        $at, . + 4 + (0x5E << 2)
    ctx->pc = 0x1A10D0u;
    {
        const bool branch_taken_0x1a10d0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A10D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A10D0u;
            // 0x1a10d4: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a10d0) {
            ctx->pc = 0x1A124Cu;
            goto label_1a124c;
        }
    }
    ctx->pc = 0x1A10D8u;
    // 0x1a10d8: 0x113900  sll         $a3, $s1, 4
    ctx->pc = 0x1a10d8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
    // 0x1a10dc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a10dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a10e0: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a10e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a10e4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a10e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a10e8: 0xa440000a  sh          $zero, 0xA($v0)
    ctx->pc = 0x1a10e8u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a10ec: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a10ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a10f0: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a10f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a10f4: 0xac520004  sw          $s2, 0x4($v0)
    ctx->pc = 0x1a10f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
    // 0x1a10f8: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a10f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a10fc: 0x8e630018  lw          $v1, 0x18($s3)
    ctx->pc = 0x1a10fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1100: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1100u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1104: 0xa4430008  sh          $v1, 0x8($v0)
    ctx->pc = 0x1a1104u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a1108: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1108u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a110c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1a110cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1a1110: 0xac460000  sw          $a2, 0x0($v0)
    ctx->pc = 0x1a1110u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 6));
    // 0x1a1114: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a1114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a1118: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a1118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a111c: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A111Cu;
    SET_GPR_U32(ctx, 31, 0x1A1124u);
    ctx->pc = 0x1A1120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A111Cu;
            // 0x1a1120: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1124u; }
        if (ctx->pc != 0x1A1124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1124u; }
        if (ctx->pc != 0x1A1124u) { return; }
    }
    ctx->pc = 0x1A1124u;
label_1a1124:
    // 0x1a1124: 0x1000004b  b           . + 4 + (0x4B << 2)
    ctx->pc = 0x1A1124u;
    {
        const bool branch_taken_0x1a1124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1124u;
            // 0x1a1128: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1124) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A112Cu;
label_1a112c:
    // 0x1a112c: 0x8e690018  lw          $t1, 0x18($s3)
    ctx->pc = 0x1a112cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1130: 0x42900  sll         $a1, $a0, 4
    ctx->pc = 0x1a1130u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1a1134: 0x454021  addu        $t0, $v0, $a1
    ctx->pc = 0x1a1134u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1a1138: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1a1138u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a113c: 0x8d070000  lw          $a3, 0x0($t0)
    ctx->pc = 0x1a113cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a1140: 0x8d060004  lw          $a2, 0x4($t0)
    ctx->pc = 0x1a1140u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x1a1144: 0x2525ffff  addiu       $a1, $t1, -0x1
    ctx->pc = 0x1a1144u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967295));
    // 0x1a1148: 0xa02827  not         $a1, $a1
    ctx->pc = 0x1a1148u;
    SET_GPR_U64(ctx, 5, ~(GPR_U64(ctx, 5) | GPR_U64(ctx, 0)));
    // 0x1a114c: 0xe63021  addu        $a2, $a3, $a2
    ctx->pc = 0x1a114cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x1a1150: 0x1263021  addu        $a2, $t1, $a2
    ctx->pc = 0x1a1150u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x1a1154: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1a1154u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1a1158: 0xa62824  and         $a1, $a1, $a2
    ctx->pc = 0x1a1158u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 6));
    // 0x1a115c: 0x852023  subu        $a0, $a0, $a1
    ctx->pc = 0x1a115cu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1a1160: 0x90082b  sltu        $at, $a0, $s0
    ctx->pc = 0x1a1160u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a1164: 0x14200017  bnez        $at, . + 4 + (0x17 << 2)
    ctx->pc = 0x1A1164u;
    {
        const bool branch_taken_0x1a1164 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A1168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1164u;
            // 0x1a1168: 0x113900  sll         $a3, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1164) {
            ctx->pc = 0x1A11C4u;
            goto label_1a11c4;
        }
    }
    ctx->pc = 0x1A116Cu;
    // 0x1a116c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a116cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1170: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1170u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1174: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a1174u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1178: 0xa440000a  sh          $zero, 0xA($v0)
    ctx->pc = 0x1a1178u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a117c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a117cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1180: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1184: 0xac520004  sw          $s2, 0x4($v0)
    ctx->pc = 0x1a1184u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
    // 0x1a1188: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a118c: 0x8e660018  lw          $a2, 0x18($s3)
    ctx->pc = 0x1a118cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1190: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1190u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1194: 0xa4460008  sh          $a2, 0x8($v0)
    ctx->pc = 0x1a1194u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a1198: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1a1198u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a119c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a119cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a11a0: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1a11a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a11a4: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1a11a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1a11a8: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1a11a8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1a11ac: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a11acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a11b0: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a11b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a11b4: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A11B4u;
    SET_GPR_U32(ctx, 31, 0x1A11BCu);
    ctx->pc = 0x1A11B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A11B4u;
            // 0x1a11b8: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A11BCu; }
        if (ctx->pc != 0x1A11BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A11BCu; }
        if (ctx->pc != 0x1A11BCu) { return; }
    }
    ctx->pc = 0x1A11BCu;
label_1a11bc:
    // 0x1a11bc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1A11BCu;
    {
        const bool branch_taken_0x1a11bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A11C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A11BCu;
            // 0x1a11c0: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a11bc) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A11C4u;
label_1a11c4:
    // 0x1a11c4: 0x100182d  daddu       $v1, $t0, $zero
    ctx->pc = 0x1a11c4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_1a11c8:
    // 0x1a11c8: 0x9465000e  lhu         $a1, 0xE($v1)
    ctx->pc = 0x1a11c8u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
    // 0x1a11cc: 0x3404ffff  ori         $a0, $zero, 0xFFFF
    ctx->pc = 0x1a11ccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a11d0: 0x14a4ffd6  bne         $a1, $a0, . + 4 + (-0x2A << 2)
    ctx->pc = 0x1A11D0u;
    {
        const bool branch_taken_0x1a11d0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 4));
        ctx->pc = 0x1A11D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A11D0u;
            // 0x1a11d4: 0x30a4ffff  andi        $a0, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a11d0) {
            ctx->pc = 0x1A112Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a112c;
        }
    }
    ctx->pc = 0x1A11D8u;
    // 0x1a11d8: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x1a11d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a11dc: 0x8e640010  lw          $a0, 0x10($s3)
    ctx->pc = 0x1a11dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1a11e0: 0xa42023  subu        $a0, $a1, $a0
    ctx->pc = 0x1a11e0u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1a11e4: 0x90082b  sltu        $at, $a0, $s0
    ctx->pc = 0x1a11e4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1a11e8: 0x14200017  bnez        $at, . + 4 + (0x17 << 2)
    ctx->pc = 0x1A11E8u;
    {
        const bool branch_taken_0x1a11e8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A11ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A11E8u;
            // 0x1a11ec: 0x113900  sll         $a3, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a11e8) {
            ctx->pc = 0x1A1248u;
            goto label_1a1248;
        }
    }
    ctx->pc = 0x1A11F0u;
    // 0x1a11f0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a11f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a11f4: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a11f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a11f8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1a11f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a11fc: 0xa440000a  sh          $zero, 0xA($v0)
    ctx->pc = 0x1a11fcu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1a1200: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1200u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1204: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1208: 0xac520004  sw          $s2, 0x4($v0)
    ctx->pc = 0x1a1208u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
    // 0x1a120c: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a120cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1210: 0x8e660018  lw          $a2, 0x18($s3)
    ctx->pc = 0x1a1210u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x1a1214: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x1a1214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1a1218: 0xa4460008  sh          $a2, 0x8($v0)
    ctx->pc = 0x1a1218u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 8), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a121c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1a121cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a1220: 0x8e620008  lw          $v0, 0x8($s3)
    ctx->pc = 0x1a1220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1a1224: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x1a1224u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a1228: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1a1228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1a122c: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x1a122cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x1a1230: 0x8e62001c  lw          $v0, 0x1C($s3)
    ctx->pc = 0x1a1230u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x1a1234: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1a1234u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1a1238: 0xc06859c  jal         func_1A1670
    ctx->pc = 0x1A1238u;
    SET_GPR_U32(ctx, 31, 0x1A1240u);
    ctx->pc = 0x1A123Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1238u;
            // 0x1a123c: 0xae62001c  sw          $v0, 0x1C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1670u;
    if (runtime->hasFunction(0x1A1670u)) {
        auto targetFn = runtime->lookupFunction(0x1A1670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1240u; }
        if (ctx->pc != 0x1A1240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1670_0x1a1670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1240u; }
        if (ctx->pc != 0x1A1240u) { return; }
    }
    ctx->pc = 0x1A1240u;
label_1a1240:
    // 0x1a1240: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A1240u;
    {
        const bool branch_taken_0x1a1240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1240u;
            // 0x1a1244: 0x26220001  addiu       $v0, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1240) {
            ctx->pc = 0x1A1254u;
            goto label_1a1254;
        }
    }
    ctx->pc = 0x1A1248u;
label_1a1248:
    // 0x1a1248: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1a1248u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1a124c:
    // 0x1a124c: 0xc068384  jal         func_1A0E10
    ctx->pc = 0x1A124Cu;
    SET_GPR_U32(ctx, 31, 0x1A1254u);
    ctx->pc = 0x1A1250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A124Cu;
            // 0x1a1250: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0E10u;
    if (runtime->hasFunction(0x1A0E10u)) {
        auto targetFn = runtime->lookupFunction(0x1A0E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1254u; }
        if (ctx->pc != 0x1A1254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0E10_0x1a0e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1254u; }
        if (ctx->pc != 0x1A1254u) { return; }
    }
    ctx->pc = 0x1A1254u;
label_1a1254:
    // 0x1a1254: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1a1254u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1a1258:
    // 0x1a1258: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a1258u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a125c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a125cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a1260: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a1260u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a1264: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a1264u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1268: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A126Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1268u;
            // 0x1a126c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A0FACu: goto label_1a0fac;
            case 0x1A0FC4u: goto label_1a0fc4;
            case 0x1A0FDCu: goto label_1a0fdc;
            case 0x1A0FE4u: goto label_1a0fe4;
            case 0x1A0FFCu: goto label_1a0ffc;
            case 0x1A1088u: goto label_1a1088;
            case 0x1A1090u: goto label_1a1090;
            case 0x1A1098u: goto label_1a1098;
            case 0x1A1124u: goto label_1a1124;
            case 0x1A112Cu: goto label_1a112c;
            case 0x1A11BCu: goto label_1a11bc;
            case 0x1A11C4u: goto label_1a11c4;
            case 0x1A11C8u: goto label_1a11c8;
            case 0x1A1240u: goto label_1a1240;
            case 0x1A1248u: goto label_1a1248;
            case 0x1A124Cu: goto label_1a124c;
            case 0x1A1254u: goto label_1a1254;
            case 0x1A1258u: goto label_1a1258;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1270u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
