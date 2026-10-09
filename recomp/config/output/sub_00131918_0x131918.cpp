#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131918
// Address: 0x131918 - 0x131b60
void sub_00131918_0x131918(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131918_0x131918");
#endif

    switch (ctx->pc) {
        case 0x131968u: goto label_131968;
        case 0x131970u: goto label_131970;
        case 0x131988u: goto label_131988;
        case 0x13199cu: goto label_13199c;
        case 0x1319b0u: goto label_1319b0;
        case 0x1319ccu: goto label_1319cc;
        case 0x1319d4u: goto label_1319d4;
        case 0x1319e8u: goto label_1319e8;
        case 0x1319f0u: goto label_1319f0;
        case 0x131a10u: goto label_131a10;
        case 0x131a28u: goto label_131a28;
        case 0x131a48u: goto label_131a48;
        case 0x131a68u: goto label_131a68;
        case 0x131a88u: goto label_131a88;
        case 0x131ab4u: goto label_131ab4;
        case 0x131ac4u: goto label_131ac4;
        case 0x131ae8u: goto label_131ae8;
        case 0x131b10u: goto label_131b10;
        case 0x131b24u: goto label_131b24;
        default: break;
    }

    ctx->pc = 0x131918u;

label_131918:
    // 0x131918: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x131918u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13191c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13191cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131920: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x131920u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131924: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131928: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x131928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13192c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13192cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x131930: 0x1620000b  bnez        $s1, . + 4 + (0xB << 2)
    ctx->pc = 0x131930u;
    {
        const bool branch_taken_0x131930 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x131934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131930u;
            // 0x131934: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131930) {
            ctx->pc = 0x131960u;
            goto label_131960;
        }
    }
    ctx->pc = 0x131938u;
    // 0x131938: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x131938u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13193c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13193cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131940: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131940u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131944: 0x2484aed0  addiu       $a0, $a0, -0x5130
    ctx->pc = 0x131944u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946512));
    // 0x131948: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x131948u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13194c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13194cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x131950: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x131950u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x131954: 0x804a034  j           func_1280D0
    ctx->pc = 0x131954u;
    ctx->pc = 0x131958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131954u;
            // 0x131958: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13195Cu;
    // 0x13195c: 0x0  nop
    ctx->pc = 0x13195cu;
    // NOP
label_131960:
    // 0x131960: 0xc04c632  jal         func_1318C8
    ctx->pc = 0x131960u;
    SET_GPR_U32(ctx, 31, 0x131968u);
    ctx->pc = 0x1318C8u;
    if (runtime->hasFunction(0x1318C8u)) {
        auto targetFn = runtime->lookupFunction(0x1318C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131968u; }
        if (ctx->pc != 0x131968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001318C8_0x1318c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131968u; }
        if (ctx->pc != 0x131968u) { return; }
    }
    ctx->pc = 0x131968u;
label_131968:
    // 0x131968: 0xc04c63c  jal         func_1318F0
    ctx->pc = 0x131968u;
    SET_GPR_U32(ctx, 31, 0x131970u);
    ctx->pc = 0x13196Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131968u;
            // 0x13196c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1318F0u;
    if (runtime->hasFunction(0x1318F0u)) {
        auto targetFn = runtime->lookupFunction(0x1318F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131970u; }
        if (ctx->pc != 0x131970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001318F0_0x1318f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131970u; }
        if (ctx->pc != 0x131970u) { return; }
    }
    ctx->pc = 0x131970u;
label_131970:
    // 0x131970: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x131970u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x131974: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x131974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131978: 0x54620004  bnel        $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x131978u;
    {
        const bool branch_taken_0x131978 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x131978) {
            ctx->pc = 0x13197Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131978u;
            // 0x13197c: 0x8e24000c  lw          $a0, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13198Cu;
            goto label_13198c;
        }
    }
    ctx->pc = 0x131980u;
    // 0x131980: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x131980u;
    SET_GPR_U32(ctx, 31, 0x131988u);
    ctx->pc = 0x131984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131980u;
            // 0x131984: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131988u; }
        if (ctx->pc != 0x131988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131988u; }
        if (ctx->pc != 0x131988u) { return; }
    }
    ctx->pc = 0x131988u;
label_131988:
    // 0x131988: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x131988u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
label_13198c:
    // 0x13198c: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x13198Cu;
    {
        const bool branch_taken_0x13198c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x13198c) {
            ctx->pc = 0x131990u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13198Cu;
            // 0x131990: 0x8e240004  lw          $a0, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1319A0u;
            goto label_1319a0;
        }
    }
    ctx->pc = 0x131994u;
    // 0x131994: 0xc04b1a0  jal         func_12C680
    ctx->pc = 0x131994u;
    SET_GPR_U32(ctx, 31, 0x13199Cu);
    ctx->pc = 0x131998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131994u;
            // 0x131998: 0xae20000c  sw          $zero, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C680u;
    if (runtime->hasFunction(0x12C680u)) {
        auto targetFn = runtime->lookupFunction(0x12C680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13199Cu; }
        if (ctx->pc != 0x13199Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C680_0x12c680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13199Cu; }
        if (ctx->pc != 0x13199Cu) { return; }
    }
    ctx->pc = 0x13199Cu;
label_13199c:
    // 0x13199c: 0x8e240004  lw          $a0, 0x4($s1)
    ctx->pc = 0x13199cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_1319a0:
    // 0x1319a0: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1319A0u;
    {
        const bool branch_taken_0x1319a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1319a0) {
            ctx->pc = 0x1319A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1319A0u;
            // 0x1319a4: 0x8e300008  lw          $s0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1319B4u;
            goto label_1319b4;
        }
    }
    ctx->pc = 0x1319A8u;
    // 0x1319a8: 0xc04b2d6  jal         func_12CB58
    ctx->pc = 0x1319A8u;
    SET_GPR_U32(ctx, 31, 0x1319B0u);
    ctx->pc = 0x1319ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1319A8u;
            // 0x1319ac: 0xae200004  sw          $zero, 0x4($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CB58u;
    if (runtime->hasFunction(0x12CB58u)) {
        auto targetFn = runtime->lookupFunction(0x12CB58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319B0u; }
        if (ctx->pc != 0x1319B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CB58_0x12cb58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319B0u; }
        if (ctx->pc != 0x1319B0u) { return; }
    }
    ctx->pc = 0x1319B0u;
label_1319b0:
    // 0x1319b0: 0x8e300008  lw          $s0, 0x8($s1)
    ctx->pc = 0x1319b0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
label_1319b4:
    // 0x1319b4: 0x12000007  beqz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1319B4u;
    {
        const bool branch_taken_0x1319b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1319B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1319B4u;
            // 0x1319b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1319b4) {
            ctx->pc = 0x1319D4u;
            goto label_1319d4;
        }
    }
    ctx->pc = 0x1319BCu;
    // 0x1319bc: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x1319bcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x1319c0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1319c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1319c4: 0xc04c1e6  jal         func_130798
    ctx->pc = 0x1319C4u;
    SET_GPR_U32(ctx, 31, 0x1319CCu);
    ctx->pc = 0x1319C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1319C4u;
            // 0x1319c8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130798u;
    if (runtime->hasFunction(0x130798u)) {
        auto targetFn = runtime->lookupFunction(0x130798u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319CCu; }
        if (ctx->pc != 0x1319CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130798_0x130798(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319CCu; }
        if (ctx->pc != 0x1319CCu) { return; }
    }
    ctx->pc = 0x1319CCu;
label_1319cc:
    // 0x1319cc: 0xc04c108  jal         func_130420
    ctx->pc = 0x1319CCu;
    SET_GPR_U32(ctx, 31, 0x1319D4u);
    ctx->pc = 0x1319D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1319CCu;
            // 0x1319d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130420u;
    if (runtime->hasFunction(0x130420u)) {
        auto targetFn = runtime->lookupFunction(0x130420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319D4u; }
        if (ctx->pc != 0x1319D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130420_0x130420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319D4u; }
        if (ctx->pc != 0x1319D4u) { return; }
    }
    ctx->pc = 0x1319D4u;
label_1319d4:
    // 0x1319d4: 0x8e240094  lw          $a0, 0x94($s1)
    ctx->pc = 0x1319d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 148)));
    // 0x1319d8: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1319D8u;
    {
        const bool branch_taken_0x1319d8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1319d8) {
            ctx->pc = 0x1319E8u;
            goto label_1319e8;
        }
    }
    ctx->pc = 0x1319E0u;
    // 0x1319e0: 0xc04f32e  jal         func_13CCB8
    ctx->pc = 0x1319E0u;
    SET_GPR_U32(ctx, 31, 0x1319E8u);
    ctx->pc = 0x1319E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1319E0u;
            // 0x1319e4: 0xae200094  sw          $zero, 0x94($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 148), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CCB8u;
    if (runtime->hasFunction(0x13CCB8u)) {
        auto targetFn = runtime->lookupFunction(0x13CCB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319E8u; }
        if (ctx->pc != 0x1319E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CCB8_0x13ccb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319E8u; }
        if (ctx->pc != 0x1319E8u) { return; }
    }
    ctx->pc = 0x1319E8u;
label_1319e8:
    // 0x1319e8: 0xc049938  jal         func_1264E0
    ctx->pc = 0x1319E8u;
    SET_GPR_U32(ctx, 31, 0x1319F0u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319F0u; }
        if (ctx->pc != 0x1319F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1319F0u; }
        if (ctx->pc != 0x1319F0u) { return; }
    }
    ctx->pc = 0x1319F0u;
label_1319f0:
    // 0x1319f0: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x1319f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1319f4: 0x50800007  beql        $a0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1319F4u;
    {
        const bool branch_taken_0x1319f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1319f4) {
            ctx->pc = 0x1319F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1319F4u;
            // 0x1319f8: 0x82220003  lb          $v0, 0x3($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131A14u;
            goto label_131a14;
        }
    }
    ctx->pc = 0x1319FCu;
    // 0x1319fc: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1319fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x131a00: 0xae200010  sw          $zero, 0x10($s1)
    ctx->pc = 0x131a00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x131a04: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x131a04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x131a08: 0x40f809  jalr        $v0
    ctx->pc = 0x131A08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x131A10u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x131A10u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131918u: goto label_131918;
            case 0x131960u: goto label_131960;
            case 0x131968u: goto label_131968;
            case 0x131970u: goto label_131970;
            case 0x131988u: goto label_131988;
            case 0x13198Cu: goto label_13198c;
            case 0x13199Cu: goto label_13199c;
            case 0x1319A0u: goto label_1319a0;
            case 0x1319B0u: goto label_1319b0;
            case 0x1319B4u: goto label_1319b4;
            case 0x1319CCu: goto label_1319cc;
            case 0x1319D4u: goto label_1319d4;
            case 0x1319E8u: goto label_1319e8;
            case 0x1319F0u: goto label_1319f0;
            case 0x131A10u: goto label_131a10;
            case 0x131A14u: goto label_131a14;
            case 0x131A28u: goto label_131a28;
            case 0x131A48u: goto label_131a48;
            case 0x131A68u: goto label_131a68;
            case 0x131A6Cu: goto label_131a6c;
            case 0x131A88u: goto label_131a88;
            case 0x131A8Cu: goto label_131a8c;
            case 0x131AA0u: goto label_131aa0;
            case 0x131AB4u: goto label_131ab4;
            case 0x131AB8u: goto label_131ab8;
            case 0x131AC4u: goto label_131ac4;
            case 0x131AE8u: goto label_131ae8;
            case 0x131B10u: goto label_131b10;
            case 0x131B24u: goto label_131b24;
            case 0x131B28u: goto label_131b28;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131A10u; }
            if (ctx->pc != 0x131A10u) { return; }
        }
        }
    }
    ctx->pc = 0x131A10u;
label_131a10:
    // 0x131a10: 0x82220003  lb          $v0, 0x3($s1)
    ctx->pc = 0x131a10u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
label_131a14:
    // 0x131a14: 0x18400022  blez        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x131A14u;
    {
        const bool branch_taken_0x131a14 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x131A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131A14u;
            // 0x131a18: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131a14) {
            ctx->pc = 0x131AA0u;
            goto label_131aa0;
        }
    }
    ctx->pc = 0x131A1Cu;
    // 0x131a1c: 0x26320080  addiu       $s2, $s1, 0x80
    ctx->pc = 0x131a1cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x131a20: 0x26300078  addiu       $s0, $s1, 0x78
    ctx->pc = 0x131a20u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 120));
    // 0x131a24: 0x0  nop
    ctx->pc = 0x131a24u;
    // NOP
label_131a28:
    // 0x131a28: 0x8e03ffa0  lw          $v1, -0x60($s0)
    ctx->pc = 0x131a28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294967200)));
    // 0x131a2c: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x131A2Cu;
    {
        const bool branch_taken_0x131a2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x131A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131A2Cu;
            // 0x131a30: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131a2c) {
            ctx->pc = 0x131A48u;
            goto label_131a48;
        }
    }
    ctx->pc = 0x131A34u;
    // 0x131a34: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x131a34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x131a38: 0xae00ffa0  sw          $zero, -0x60($s0)
    ctx->pc = 0x131a38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294967200), GPR_U32(ctx, 0));
    // 0x131a3c: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x131a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x131a40: 0x40f809  jalr        $v0
    ctx->pc = 0x131A40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x131A48u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x131A48u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131918u: goto label_131918;
            case 0x131960u: goto label_131960;
            case 0x131968u: goto label_131968;
            case 0x131970u: goto label_131970;
            case 0x131988u: goto label_131988;
            case 0x13198Cu: goto label_13198c;
            case 0x13199Cu: goto label_13199c;
            case 0x1319A0u: goto label_1319a0;
            case 0x1319B0u: goto label_1319b0;
            case 0x1319B4u: goto label_1319b4;
            case 0x1319CCu: goto label_1319cc;
            case 0x1319D4u: goto label_1319d4;
            case 0x1319E8u: goto label_1319e8;
            case 0x1319F0u: goto label_1319f0;
            case 0x131A10u: goto label_131a10;
            case 0x131A14u: goto label_131a14;
            case 0x131A28u: goto label_131a28;
            case 0x131A48u: goto label_131a48;
            case 0x131A68u: goto label_131a68;
            case 0x131A6Cu: goto label_131a6c;
            case 0x131A88u: goto label_131a88;
            case 0x131A8Cu: goto label_131a8c;
            case 0x131AA0u: goto label_131aa0;
            case 0x131AB4u: goto label_131ab4;
            case 0x131AB8u: goto label_131ab8;
            case 0x131AC4u: goto label_131ac4;
            case 0x131AE8u: goto label_131ae8;
            case 0x131B10u: goto label_131b10;
            case 0x131B24u: goto label_131b24;
            case 0x131B28u: goto label_131b28;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131A48u; }
            if (ctx->pc != 0x131A48u) { return; }
        }
        }
    }
    ctx->pc = 0x131A48u;
label_131a48:
    // 0x131a48: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x131a48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x131a4c: 0x50800007  beql        $a0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x131A4Cu;
    {
        const bool branch_taken_0x131a4c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x131a4c) {
            ctx->pc = 0x131A50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131A4Cu;
            // 0x131a50: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131A6Cu;
            goto label_131a6c;
        }
    }
    ctx->pc = 0x131A54u;
    // 0x131a54: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x131a54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x131a58: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x131a58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x131a5c: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x131a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x131a60: 0x40f809  jalr        $v0
    ctx->pc = 0x131A60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x131A68u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x131A68u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131918u: goto label_131918;
            case 0x131960u: goto label_131960;
            case 0x131968u: goto label_131968;
            case 0x131970u: goto label_131970;
            case 0x131988u: goto label_131988;
            case 0x13198Cu: goto label_13198c;
            case 0x13199Cu: goto label_13199c;
            case 0x1319A0u: goto label_1319a0;
            case 0x1319B0u: goto label_1319b0;
            case 0x1319B4u: goto label_1319b4;
            case 0x1319CCu: goto label_1319cc;
            case 0x1319D4u: goto label_1319d4;
            case 0x1319E8u: goto label_1319e8;
            case 0x1319F0u: goto label_1319f0;
            case 0x131A10u: goto label_131a10;
            case 0x131A14u: goto label_131a14;
            case 0x131A28u: goto label_131a28;
            case 0x131A48u: goto label_131a48;
            case 0x131A68u: goto label_131a68;
            case 0x131A6Cu: goto label_131a6c;
            case 0x131A88u: goto label_131a88;
            case 0x131A8Cu: goto label_131a8c;
            case 0x131AA0u: goto label_131aa0;
            case 0x131AB4u: goto label_131ab4;
            case 0x131AB8u: goto label_131ab8;
            case 0x131AC4u: goto label_131ac4;
            case 0x131AE8u: goto label_131ae8;
            case 0x131B10u: goto label_131b10;
            case 0x131B24u: goto label_131b24;
            case 0x131B28u: goto label_131b28;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131A68u; }
            if (ctx->pc != 0x131A68u) { return; }
        }
        }
    }
    ctx->pc = 0x131A68u;
label_131a68:
    // 0x131a68: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x131a68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_131a6c:
    // 0x131a6c: 0x50800007  beql        $a0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x131A6Cu;
    {
        const bool branch_taken_0x131a6c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x131a6c) {
            ctx->pc = 0x131A70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131A6Cu;
            // 0x131a70: 0x82220003  lb          $v0, 0x3($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131A8Cu;
            goto label_131a8c;
        }
    }
    ctx->pc = 0x131A74u;
    // 0x131a74: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x131a74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x131a78: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x131a78u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x131a7c: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x131a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x131a80: 0x40f809  jalr        $v0
    ctx->pc = 0x131A80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x131A88u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x131A88u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131918u: goto label_131918;
            case 0x131960u: goto label_131960;
            case 0x131968u: goto label_131968;
            case 0x131970u: goto label_131970;
            case 0x131988u: goto label_131988;
            case 0x13198Cu: goto label_13198c;
            case 0x13199Cu: goto label_13199c;
            case 0x1319A0u: goto label_1319a0;
            case 0x1319B0u: goto label_1319b0;
            case 0x1319B4u: goto label_1319b4;
            case 0x1319CCu: goto label_1319cc;
            case 0x1319D4u: goto label_1319d4;
            case 0x1319E8u: goto label_1319e8;
            case 0x1319F0u: goto label_1319f0;
            case 0x131A10u: goto label_131a10;
            case 0x131A14u: goto label_131a14;
            case 0x131A28u: goto label_131a28;
            case 0x131A48u: goto label_131a48;
            case 0x131A68u: goto label_131a68;
            case 0x131A6Cu: goto label_131a6c;
            case 0x131A88u: goto label_131a88;
            case 0x131A8Cu: goto label_131a8c;
            case 0x131AA0u: goto label_131aa0;
            case 0x131AB4u: goto label_131ab4;
            case 0x131AB8u: goto label_131ab8;
            case 0x131AC4u: goto label_131ac4;
            case 0x131AE8u: goto label_131ae8;
            case 0x131B10u: goto label_131b10;
            case 0x131B24u: goto label_131b24;
            case 0x131B28u: goto label_131b28;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131A88u; }
            if (ctx->pc != 0x131A88u) { return; }
        }
        }
    }
    ctx->pc = 0x131A88u;
label_131a88:
    // 0x131a88: 0x82220003  lb          $v0, 0x3($s1)
    ctx->pc = 0x131a88u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
label_131a8c:
    // 0x131a8c: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x131a8cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x131a90: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x131a90u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x131a94: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x131a94u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x131a98: 0x1440ffe3  bnez        $v0, . + 4 + (-0x1D << 2)
    ctx->pc = 0x131A98u;
    {
        const bool branch_taken_0x131a98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x131A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131A98u;
            // 0x131a9c: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131a98) {
            ctx->pc = 0x131A28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_131a28;
        }
    }
    ctx->pc = 0x131AA0u;
label_131aa0:
    // 0x131aa0: 0x8e240074  lw          $a0, 0x74($s1)
    ctx->pc = 0x131aa0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 116)));
    // 0x131aa4: 0x50800004  beql        $a0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x131AA4u;
    {
        const bool branch_taken_0x131aa4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x131aa4) {
            ctx->pc = 0x131AA8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131AA4u;
            // 0x131aa8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131AB8u;
            goto label_131ab8;
        }
    }
    ctx->pc = 0x131AACu;
    // 0x131aac: 0xc048a3c  jal         func_1228F0
    ctx->pc = 0x131AACu;
    SET_GPR_U32(ctx, 31, 0x131AB4u);
    ctx->pc = 0x131AB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131AACu;
            // 0x131ab0: 0xae200074  sw          $zero, 0x74($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 116), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1228F0u;
    if (runtime->hasFunction(0x1228F0u)) {
        auto targetFn = runtime->lookupFunction(0x1228F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131AB4u; }
        if (ctx->pc != 0x131AB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001228F0_0x1228f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131AB4u; }
        if (ctx->pc != 0x131AB4u) { return; }
    }
    ctx->pc = 0x131AB4u;
label_131ab4:
    // 0x131ab4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x131ab4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_131ab8:
    // 0x131ab8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131ab8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131abc: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x131ABCu;
    SET_GPR_U32(ctx, 31, 0x131AC4u);
    ctx->pc = 0x131AC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131ABCu;
            // 0x131ac0: 0x240600c4  addiu       $a2, $zero, 0xC4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 196));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131AC4u; }
        if (ctx->pc != 0x131AC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131AC4u; }
        if (ctx->pc != 0x131AC4u) { return; }
    }
    ctx->pc = 0x131AC4u;
label_131ac4:
    // 0x131ac4: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x131ac4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x131ac8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131ac8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131acc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131accu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131ad0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x131ad0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131ad4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x131ad4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x131ad8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x131ad8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x131adc: 0x804993e  j           func_1264F8
    ctx->pc = 0x131ADCu;
    ctx->pc = 0x131AE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131ADCu;
            // 0x131ae0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131AE4u;
    // 0x131ae4: 0x0  nop
    ctx->pc = 0x131ae4u;
    // NOP
label_131ae8:
    // 0x131ae8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x131ae8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x131aec: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x131aecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x131af0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x131af0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x131af4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131af4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131af8: 0x2450f3c8  addiu       $s0, $v0, -0xC38
    ctx->pc = 0x131af8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294964168));
    // 0x131afc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x131afcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131b00: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x131b00u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x131b04: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x131b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x131b08: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x131b08u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131b0c: 0x0  nop
    ctx->pc = 0x131b0cu;
    // NOP
label_131b10:
    // 0x131b10: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x131b10u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x131b14: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x131B14u;
    {
        const bool branch_taken_0x131b14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x131b14) {
            ctx->pc = 0x131B18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131B14u;
            // 0x131b18: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131B28u;
            goto label_131b28;
        }
    }
    ctx->pc = 0x131B1Cu;
    // 0x131b1c: 0xc04c646  jal         func_131918
    ctx->pc = 0x131B1Cu;
    SET_GPR_U32(ctx, 31, 0x131B24u);
    ctx->pc = 0x131B20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131B1Cu;
            // 0x131b20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131918u;
    goto label_131918;
    ctx->pc = 0x131B24u;
label_131b24:
    // 0x131b24: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x131b24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_131b28:
    // 0x131b28: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x131B28u;
    {
        const bool branch_taken_0x131b28 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x131B2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131B28u;
            // 0x131b2c: 0x261000c4  addiu       $s0, $s0, 0xC4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 196));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131b28) {
            ctx->pc = 0x131B10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_131b10;
        }
    }
    ctx->pc = 0x131B30u;
    // 0x131b30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131b30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131b34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131b34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131b38: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x131b38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131b3c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x131b3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x131b40: 0x3e00008  jr          $ra
    ctx->pc = 0x131B40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131B40u;
            // 0x131b44: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131918u: goto label_131918;
            case 0x131960u: goto label_131960;
            case 0x131968u: goto label_131968;
            case 0x131970u: goto label_131970;
            case 0x131988u: goto label_131988;
            case 0x13198Cu: goto label_13198c;
            case 0x13199Cu: goto label_13199c;
            case 0x1319A0u: goto label_1319a0;
            case 0x1319B0u: goto label_1319b0;
            case 0x1319B4u: goto label_1319b4;
            case 0x1319CCu: goto label_1319cc;
            case 0x1319D4u: goto label_1319d4;
            case 0x1319E8u: goto label_1319e8;
            case 0x1319F0u: goto label_1319f0;
            case 0x131A10u: goto label_131a10;
            case 0x131A14u: goto label_131a14;
            case 0x131A28u: goto label_131a28;
            case 0x131A48u: goto label_131a48;
            case 0x131A68u: goto label_131a68;
            case 0x131A6Cu: goto label_131a6c;
            case 0x131A88u: goto label_131a88;
            case 0x131A8Cu: goto label_131a8c;
            case 0x131AA0u: goto label_131aa0;
            case 0x131AB4u: goto label_131ab4;
            case 0x131AB8u: goto label_131ab8;
            case 0x131AC4u: goto label_131ac4;
            case 0x131AE8u: goto label_131ae8;
            case 0x131B10u: goto label_131b10;
            case 0x131B24u: goto label_131b24;
            case 0x131B28u: goto label_131b28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131B48u;
    // 0x131b48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131b4c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x131b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x131b50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x131b50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131b54: 0x804c6ba  j           func_131AE8
    ctx->pc = 0x131B54u;
    ctx->pc = 0x131B58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131B54u;
            // 0x131b58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131AE8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_131ae8;
    ctx->pc = 0x131B5Cu;
    // 0x131b5c: 0x0  nop
    ctx->pc = 0x131b5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
