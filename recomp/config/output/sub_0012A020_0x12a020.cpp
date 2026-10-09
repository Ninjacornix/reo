#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A020
// Address: 0x12a020 - 0x12a158
void sub_0012A020_0x12a020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A020_0x12a020");
#endif

    switch (ctx->pc) {
        case 0x12a034u: goto label_12a034;
        case 0x12a064u: goto label_12a064;
        case 0x12a06cu: goto label_12a06c;
        case 0x12a078u: goto label_12a078;
        case 0x12a084u: goto label_12a084;
        case 0x12a090u: goto label_12a090;
        case 0x12a09cu: goto label_12a09c;
        case 0x12a0a8u: goto label_12a0a8;
        default: break;
    }

    ctx->pc = 0x12a020u;

label_12a020:
    // 0x12a020: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a024: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12a024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a028: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12a028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12a02c: 0xc049938  jal         func_1264E0
    ctx->pc = 0x12A02Cu;
    SET_GPR_U32(ctx, 31, 0x12A034u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A034u; }
        if (ctx->pc != 0x12A034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A034u; }
        if (ctx->pc != 0x12A034u) { return; }
    }
    ctx->pc = 0x12A034u;
label_12a034:
    // 0x12a034: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a034u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a038: 0x2450f390  addiu       $s0, $v0, -0xC70
    ctx->pc = 0x12a038u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294964112));
    // 0x12a03c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x12a03cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12a040: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12A040u;
    {
        const bool branch_taken_0x12a040 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12A044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A040u;
            // 0x12a044: 0xdfbf0008  ld          $ra, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a040) {
            ctx->pc = 0x12A058u;
            goto label_12a058;
        }
    }
    ctx->pc = 0x12A048u;
    // 0x12a048: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a048u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a04c: 0x804993e  j           func_1264F8
    ctx->pc = 0x12A04Cu;
    ctx->pc = 0x12A050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A04Cu;
            // 0x12a050: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A054u;
    // 0x12a054: 0x0  nop
    ctx->pc = 0x12a054u;
    // NOP
label_12a058:
    // 0x12a058: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12a058u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a05c: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x12A05Cu;
    SET_GPR_U32(ctx, 31, 0x12A064u);
    ctx->pc = 0x12A060u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A05Cu;
            // 0x12a060: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A064u; }
        if (ctx->pc != 0x12A064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A064u; }
        if (ctx->pc != 0x12A064u) { return; }
    }
    ctx->pc = 0x12A064u;
label_12a064:
    // 0x12a064: 0xc04c352  jal         func_130D48
    ctx->pc = 0x12A064u;
    SET_GPR_U32(ctx, 31, 0x12A06Cu);
    ctx->pc = 0x130D48u;
    if (runtime->hasFunction(0x130D48u)) {
        auto targetFn = runtime->lookupFunction(0x130D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A06Cu; }
        if (ctx->pc != 0x12A06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130D48_0x130d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A06Cu; }
        if (ctx->pc != 0x12A06Cu) { return; }
    }
    ctx->pc = 0x12A06Cu;
label_12a06c:
    // 0x12a06c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x12a06cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12a070: 0xc04d7bc  jal         func_135EF0
    ctx->pc = 0x12A070u;
    SET_GPR_U32(ctx, 31, 0x12A078u);
    ctx->pc = 0x12A074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A070u;
            // 0x12a074: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135EF0u;
    if (runtime->hasFunction(0x135EF0u)) {
        auto targetFn = runtime->lookupFunction(0x135EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A078u; }
        if (ctx->pc != 0x12A078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135EF0_0x135ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A078u; }
        if (ctx->pc != 0x12A078u) { return; }
    }
    ctx->pc = 0x12A078u;
label_12a078:
    // 0x12a078: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x12a078u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12a07c: 0xc04df60  jal         func_137D80
    ctx->pc = 0x12A07Cu;
    SET_GPR_U32(ctx, 31, 0x12A084u);
    ctx->pc = 0x12A080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A07Cu;
            // 0x12a080: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137D80u;
    if (runtime->hasFunction(0x137D80u)) {
        auto targetFn = runtime->lookupFunction(0x137D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A084u; }
        if (ctx->pc != 0x12A084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137D80_0x137d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A084u; }
        if (ctx->pc != 0x12A084u) { return; }
    }
    ctx->pc = 0x12A084u;
label_12a084:
    // 0x12a084: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x12a084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12a088: 0xc04d7bc  jal         func_135EF0
    ctx->pc = 0x12A088u;
    SET_GPR_U32(ctx, 31, 0x12A090u);
    ctx->pc = 0x12A08Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A088u;
            // 0x12a08c: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135EF0u;
    if (runtime->hasFunction(0x135EF0u)) {
        auto targetFn = runtime->lookupFunction(0x135EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A090u; }
        if (ctx->pc != 0x12A090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135EF0_0x135ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A090u; }
        if (ctx->pc != 0x12A090u) { return; }
    }
    ctx->pc = 0x12A090u;
label_12a090:
    // 0x12a090: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x12a090u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x12a094: 0xc04c352  jal         func_130D48
    ctx->pc = 0x12A094u;
    SET_GPR_U32(ctx, 31, 0x12A09Cu);
    ctx->pc = 0x12A098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A094u;
            // 0x12a098: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130D48u;
    if (runtime->hasFunction(0x130D48u)) {
        auto targetFn = runtime->lookupFunction(0x130D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A09Cu; }
        if (ctx->pc != 0x12A09Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130D48_0x130d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A09Cu; }
        if (ctx->pc != 0x12A09Cu) { return; }
    }
    ctx->pc = 0x12A09Cu;
label_12a09c:
    // 0x12a09c: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x12a09cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x12a0a0: 0xc04a698  jal         func_129A60
    ctx->pc = 0x12A0A0u;
    SET_GPR_U32(ctx, 31, 0x12A0A8u);
    ctx->pc = 0x12A0A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A0A0u;
            // 0x12a0a4: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129A60u;
    if (runtime->hasFunction(0x129A60u)) {
        auto targetFn = runtime->lookupFunction(0x129A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A0A8u; }
        if (ctx->pc != 0x12A0A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129A60_0x129a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A0A8u; }
        if (ctx->pc != 0x12A0A8u) { return; }
    }
    ctx->pc = 0x12A0A8u;
label_12a0a8:
    // 0x12a0a8: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x12a0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x12a0ac: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12a0acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a0b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a0b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a0b4: 0x3e00008  jr          $ra
    ctx->pc = 0x12A0B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A0B4u;
            // 0x12a0b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A020u: goto label_12a020;
            case 0x12A034u: goto label_12a034;
            case 0x12A058u: goto label_12a058;
            case 0x12A064u: goto label_12a064;
            case 0x12A06Cu: goto label_12a06c;
            case 0x12A078u: goto label_12a078;
            case 0x12A084u: goto label_12a084;
            case 0x12A090u: goto label_12a090;
            case 0x12A09Cu: goto label_12a09c;
            case 0x12A0A8u: goto label_12a0a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A0BCu;
    // 0x12a0bc: 0x0  nop
    ctx->pc = 0x12a0bcu;
    // NOP
    // 0x12a0c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a0c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a0c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a0c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a0c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a0cc: 0x804a808  j           func_12A020
    ctx->pc = 0x12A0CCu;
    ctx->pc = 0x12A0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A0CCu;
            // 0x12a0d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12A020u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_12a020;
    ctx->pc = 0x12A0D4u;
    // 0x12a0d4: 0x0  nop
    ctx->pc = 0x12a0d4u;
    // NOP
    // 0x12a0d8: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a0dc: 0x2463f390  addiu       $v1, $v1, -0xC70
    ctx->pc = 0x12a0dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294964112));
    // 0x12a0e0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12a0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a0e4: 0x3e00008  jr          $ra
    ctx->pc = 0x12A0E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A0E4u;
            // 0x12a0e8: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A020u: goto label_12a020;
            case 0x12A034u: goto label_12a034;
            case 0x12A058u: goto label_12a058;
            case 0x12A064u: goto label_12a064;
            case 0x12A06Cu: goto label_12a06c;
            case 0x12A078u: goto label_12a078;
            case 0x12A084u: goto label_12a084;
            case 0x12A090u: goto label_12a090;
            case 0x12A09Cu: goto label_12a09c;
            case 0x12A0A8u: goto label_12a0a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A0ECu;
    // 0x12a0ec: 0x0  nop
    ctx->pc = 0x12a0ecu;
    // NOP
    // 0x12a0f0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a0f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a0f4: 0x3e00008  jr          $ra
    ctx->pc = 0x12A0F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A0F4u;
            // 0x12a0f8: 0xac44f3bc  sw          $a0, -0xC44($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294964156), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A020u: goto label_12a020;
            case 0x12A034u: goto label_12a034;
            case 0x12A058u: goto label_12a058;
            case 0x12A064u: goto label_12a064;
            case 0x12A06Cu: goto label_12a06c;
            case 0x12A078u: goto label_12a078;
            case 0x12A084u: goto label_12a084;
            case 0x12A090u: goto label_12a090;
            case 0x12A09Cu: goto label_12a09c;
            case 0x12A0A8u: goto label_12a0a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A0FCu;
    // 0x12a0fc: 0x0  nop
    ctx->pc = 0x12a0fcu;
    // NOP
    // 0x12a100: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a100u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a104: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x12a104u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a108: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a10c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a10cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a110: 0x804a034  j           func_1280D0
    ctx->pc = 0x12A110u;
    ctx->pc = 0x12A114u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A110u;
            // 0x12a114: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A118u;
    // 0x12a118: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a118u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a11c: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x12a11cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a120: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a124: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a124u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a128: 0x804a034  j           func_1280D0
    ctx->pc = 0x12A128u;
    ctx->pc = 0x12A12Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A128u;
            // 0x12a12c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A130u;
    // 0x12a130: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a134: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a134u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a138: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12a138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a13c: 0x2463f3c4  addiu       $v1, $v1, -0xC3C
    ctx->pc = 0x12a13cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294964164));
    // 0x12a140: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12a140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a144: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12a144u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a148: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12a148u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12a14c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x12a14cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x12a150: 0x804cb02  j           func_132C08
    ctx->pc = 0x12A150u;
    ctx->pc = 0x12A154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A150u;
            // 0x12a154: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132C08u;
    if (runtime->hasFunction(0x132C08u)) {
        auto targetFn = runtime->lookupFunction(0x132C08u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00132C08_0x132c08(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12A158u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
