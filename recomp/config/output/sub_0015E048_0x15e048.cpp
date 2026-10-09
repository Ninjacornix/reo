#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E048
// Address: 0x15e048 - 0x15e160
void sub_0015E048_0x15e048(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E048_0x15e048");
#endif

    switch (ctx->pc) {
        case 0x15e070u: goto label_15e070;
        case 0x15e0acu: goto label_15e0ac;
        case 0x15e0f4u: goto label_15e0f4;
        case 0x15e104u: goto label_15e104;
        case 0x15e130u: goto label_15e130;
        default: break;
    }

    ctx->pc = 0x15e048u;

    // 0x15e048: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15e048u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15e04c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15e04cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15e050: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15e050u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e054: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15e054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15e058: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15e058u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15e05c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x15e05cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x15e060: 0x8ca20038  lw          $v0, 0x38($a1)
    ctx->pc = 0x15e060u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 56)));
    // 0x15e064: 0x8c520004  lw          $s2, 0x4($v0)
    ctx->pc = 0x15e064u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x15e068: 0xc057a4c  jal         func_15E930
    ctx->pc = 0x15E068u;
    SET_GPR_U32(ctx, 31, 0x15E070u);
    ctx->pc = 0x15E06Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E068u;
            // 0x15e06c: 0x8c510000  lw          $s1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E930u;
    if (runtime->hasFunction(0x15E930u)) {
        auto targetFn = runtime->lookupFunction(0x15E930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E070u; }
        if (ctx->pc != 0x15E070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E930_0x15e930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E070u; }
        if (ctx->pc != 0x15E070u) { return; }
    }
    ctx->pc = 0x15E070u;
label_15e070:
    // 0x15e070: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15e070u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15e074: 0x5443002f  bnel        $v0, $v1, . + 4 + (0x2F << 2)
    ctx->pc = 0x15E074u;
    {
        const bool branch_taken_0x15e074 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x15e074) {
            ctx->pc = 0x15E078u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E074u;
            // 0x15e078: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E134u;
            goto label_15e134;
        }
    }
    ctx->pc = 0x15E07Cu;
    // 0x15e07c: 0x8e0200d8  lw          $v0, 0xD8($s0)
    ctx->pc = 0x15e07cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 216)));
    // 0x15e080: 0x5040002c  beql        $v0, $zero, . + 4 + (0x2C << 2)
    ctx->pc = 0x15E080u;
    {
        const bool branch_taken_0x15e080 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15e080) {
            ctx->pc = 0x15E084u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E080u;
            // 0x15e084: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E134u;
            goto label_15e134;
        }
    }
    ctx->pc = 0x15E088u;
    // 0x15e088: 0x1220000b  beqz        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x15E088u;
    {
        const bool branch_taken_0x15e088 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E088u;
            // 0x15e08c: 0x2a420005  slti        $v0, $s2, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e088) {
            ctx->pc = 0x15E0B8u;
            goto label_15e0b8;
        }
    }
    ctx->pc = 0x15E090u;
    // 0x15e090: 0x5440000a  bnel        $v0, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x15E090u;
    {
        const bool branch_taken_0x15e090 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15e090) {
            ctx->pc = 0x15E094u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E090u;
            // 0x15e094: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E0BCu;
            goto label_15e0bc;
        }
    }
    ctx->pc = 0x15E098u;
    // 0x15e098: 0x26240004  addiu       $a0, $s1, 0x4
    ctx->pc = 0x15e098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x15e09c: 0x2645fffc  addiu       $a1, $s2, -0x4
    ctx->pc = 0x15e09cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967292));
    // 0x15e0a0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x15e0a0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e0a4: 0xc05f9a8  jal         func_17E6A0
    ctx->pc = 0x15E0A4u;
    SET_GPR_U32(ctx, 31, 0x15E0ACu);
    ctx->pc = 0x15E0A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E0A4u;
            // 0x15e0a8: 0x27a70004  addiu       $a3, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E6A0u;
    if (runtime->hasFunction(0x17E6A0u)) {
        auto targetFn = runtime->lookupFunction(0x17E6A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E0ACu; }
        if (ctx->pc != 0x15E0ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E6A0_0x17e6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E0ACu; }
        if (ctx->pc != 0x15E0ACu) { return; }
    }
    ctx->pc = 0x15E0ACu;
label_15e0ac:
    // 0x15e0ac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x15E0ACu;
    {
        const bool branch_taken_0x15e0ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E0B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E0ACu;
            // 0x15e0b0: 0x8fa20000  lw          $v0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e0ac) {
            ctx->pc = 0x15E0C4u;
            goto label_15e0c4;
        }
    }
    ctx->pc = 0x15E0B4u;
    // 0x15e0b4: 0x0  nop
    ctx->pc = 0x15e0b4u;
    // NOP
label_15e0b8:
    // 0x15e0b8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x15e0b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
label_15e0bc:
    // 0x15e0bc: 0xafa00004  sw          $zero, 0x4($sp)
    ctx->pc = 0x15e0bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 0));
    // 0x15e0c0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x15e0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_15e0c4:
    // 0x15e0c4: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x15E0C4u;
    {
        const bool branch_taken_0x15e0c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E0C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E0C4u;
            // 0x15e0c8: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e0c4) {
            ctx->pc = 0x15E118u;
            goto label_15e118;
        }
    }
    ctx->pc = 0x15E0CCu;
    // 0x15e0cc: 0x58e00013  blezl       $a3, . + 4 + (0x13 << 2)
    ctx->pc = 0x15E0CCu;
    {
        const bool branch_taken_0x15e0cc = (GPR_S64(ctx, 7) <= 0);
        if (branch_taken_0x15e0cc) {
            ctx->pc = 0x15E0D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E0CCu;
            // 0x15e0d0: 0xae0000e0  sw          $zero, 0xE0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E11Cu;
            goto label_15e11c;
        }
    }
    ctx->pc = 0x15E0D4u;
    // 0x15e0d4: 0x8e0200dc  lw          $v0, 0xDC($s0)
    ctx->pc = 0x15e0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 220)));
    // 0x15e0d8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15e0d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e0dc: 0x8e0400d8  lw          $a0, 0xD8($s0)
    ctx->pc = 0x15e0dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 216)));
    // 0x15e0e0: 0x47182a  slt         $v1, $v0, $a3
    ctx->pc = 0x15e0e0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x15e0e4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x15e0e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e0e8: 0x43380b  movn        $a3, $v0, $v1
    ctx->pc = 0x15e0e8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 2));
    // 0x15e0ec: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x15E0ECu;
    SET_GPR_U32(ctx, 31, 0x15E0F4u);
    ctx->pc = 0x15E0F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E0ECu;
            // 0x15e0f0: 0xafa70004  sw          $a3, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E0F4u; }
        if (ctx->pc != 0x15E0F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E0F4u; }
        if (ctx->pc != 0x15E0F4u) { return; }
    }
    ctx->pc = 0x15E0F4u;
label_15e0f4:
    // 0x15e0f4: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x15e0f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e0f8: 0x8e0400d8  lw          $a0, 0xD8($s0)
    ctx->pc = 0x15e0f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 216)));
    // 0x15e0fc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x15E0FCu;
    SET_GPR_U32(ctx, 31, 0x15E104u);
    ctx->pc = 0x15E100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E0FCu;
            // 0x15e100: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E104u; }
        if (ctx->pc != 0x15E104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E104u; }
        if (ctx->pc != 0x15E104u) { return; }
    }
    ctx->pc = 0x15E104u;
label_15e104:
    // 0x15e104: 0x8e0300d8  lw          $v1, 0xD8($s0)
    ctx->pc = 0x15e104u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 216)));
    // 0x15e108: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x15e108u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15e10c: 0xae0300e0  sw          $v1, 0xE0($s0)
    ctx->pc = 0x15e10cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 3));
    // 0x15e110: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15E110u;
    {
        const bool branch_taken_0x15e110 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E110u;
            // 0x15e114: 0xae0200e4  sw          $v0, 0xE4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 228), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e110) {
            ctx->pc = 0x15E120u;
            goto label_15e120;
        }
    }
    ctx->pc = 0x15E118u;
label_15e118:
    // 0x15e118: 0xae0000e0  sw          $zero, 0xE0($s0)
    ctx->pc = 0x15e118u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 0));
label_15e11c:
    // 0x15e11c: 0xae0000e4  sw          $zero, 0xE4($s0)
    ctx->pc = 0x15e11cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 228), GPR_U32(ctx, 0));
label_15e120:
    // 0x15e120: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15e120u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e124: 0x8c8500e0  lw          $a1, 0xE0($a0)
    ctx->pc = 0x15e124u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 224)));
    // 0x15e128: 0xc058824  jal         func_162090
    ctx->pc = 0x15E128u;
    SET_GPR_U32(ctx, 31, 0x15E130u);
    ctx->pc = 0x15E12Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E128u;
            // 0x15e12c: 0x8c8600e4  lw          $a2, 0xE4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 228)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162090u;
    if (runtime->hasFunction(0x162090u)) {
        auto targetFn = runtime->lookupFunction(0x162090u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E130u; }
        if (ctx->pc != 0x15E130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162090_0x162090(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E130u; }
        if (ctx->pc != 0x15E130u) { return; }
    }
    ctx->pc = 0x15E130u;
label_15e130:
    // 0x15e130: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15e130u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_15e134:
    // 0x15e134: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15e134u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15e138: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15e138u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15e13c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x15e13cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15e140: 0x3e00008  jr          $ra
    ctx->pc = 0x15E140u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E140u;
            // 0x15e144: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E070u: goto label_15e070;
            case 0x15E0ACu: goto label_15e0ac;
            case 0x15E0B8u: goto label_15e0b8;
            case 0x15E0BCu: goto label_15e0bc;
            case 0x15E0C4u: goto label_15e0c4;
            case 0x15E0F4u: goto label_15e0f4;
            case 0x15E104u: goto label_15e104;
            case 0x15E118u: goto label_15e118;
            case 0x15E11Cu: goto label_15e11c;
            case 0x15E120u: goto label_15e120;
            case 0x15E130u: goto label_15e130;
            case 0x15E134u: goto label_15e134;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E148u;
    // 0x15e148: 0x8c8200e4  lw          $v0, 0xE4($a0)
    ctx->pc = 0x15e148u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 228)));
    // 0x15e14c: 0x8c8300e0  lw          $v1, 0xE0($a0)
    ctx->pc = 0x15e14cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 224)));
    // 0x15e150: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x15e150u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x15e154: 0x3e00008  jr          $ra
    ctx->pc = 0x15E154u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E154u;
            // 0x15e158: 0xaca30000  sw          $v1, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E070u: goto label_15e070;
            case 0x15E0ACu: goto label_15e0ac;
            case 0x15E0B8u: goto label_15e0b8;
            case 0x15E0BCu: goto label_15e0bc;
            case 0x15E0C4u: goto label_15e0c4;
            case 0x15E0F4u: goto label_15e0f4;
            case 0x15E104u: goto label_15e104;
            case 0x15E118u: goto label_15e118;
            case 0x15E11Cu: goto label_15e11c;
            case 0x15E120u: goto label_15e120;
            case 0x15E130u: goto label_15e130;
            case 0x15E134u: goto label_15e134;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E15Cu;
    // 0x15e15c: 0x0  nop
    ctx->pc = 0x15e15cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
