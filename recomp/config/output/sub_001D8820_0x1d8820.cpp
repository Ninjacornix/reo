#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8820
// Address: 0x1d8820 - 0x1d8940
void sub_001D8820_0x1d8820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8820_0x1d8820");
#endif

    switch (ctx->pc) {
        case 0x1d886cu: goto label_1d886c;
        case 0x1d88b0u: goto label_1d88b0;
        case 0x1d88bcu: goto label_1d88bc;
        case 0x1d88c8u: goto label_1d88c8;
        case 0x1d88d4u: goto label_1d88d4;
        case 0x1d88e0u: goto label_1d88e0;
        case 0x1d8900u: goto label_1d8900;
        case 0x1d890cu: goto label_1d890c;
        default: break;
    }

    ctx->pc = 0x1d8820u;

    // 0x1d8820: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1d8820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d8824: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1d8824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1d8828: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1d8828u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1d882c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1d882cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1d8830: 0x140b82d  daddu       $s7, $t2, $zero
    ctx->pc = 0x1d8830u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8834: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d8834u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d8838: 0x160b02d  daddu       $s6, $t3, $zero
    ctx->pc = 0x1d8838u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d883c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d883cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d8840: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1d8840u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8844: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d8844u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d8848: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1d8848u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d884c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d884cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d8850: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1d8850u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8854: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d8854u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d8858: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1d8858u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d885c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d885cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8860: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x1d8860u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8864: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8864u;
    SET_GPR_U32(ctx, 31, 0x1D886Cu);
    ctx->pc = 0x1D8868u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8864u;
            // 0x1d8868: 0x120802d  daddu       $s0, $t1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D886Cu; }
        if (ctx->pc != 0x1D886Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D886Cu; }
        if (ctx->pc != 0x1D886Cu) { return; }
    }
    ctx->pc = 0x1D886Cu;
label_1d886c:
    // 0x1d886c: 0x16143c  dsll32      $v0, $s6, 16
    ctx->pc = 0x1d886cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) << (32 + 16));
    // 0x1d8870: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d8870u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8874: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d8874u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d8878: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8878u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d887c: 0xac227280  sw          $v0, 0x7280($at)
    ctx->pc = 0x1d887cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 29312), GPR_U32(ctx, 2));
    // 0x1d8880: 0x3c130034  lui         $s3, 0x34
    ctx->pc = 0x1d8880u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)52 << 16));
    // 0x1d8884: 0x8fa30090  lw          $v1, 0x90($sp)
    ctx->pc = 0x1d8884u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1d8888: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8888u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d888c: 0x87a20098  lh          $v0, 0x98($sp)
    ctx->pc = 0x1d888cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x1d8890: 0x2673729c  addiu       $s3, $s3, 0x729C
    ctx->pc = 0x1d8890u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 29340));
    // 0x1d8894: 0x26640004  addiu       $a0, $s3, 0x4
    ctx->pc = 0x1d8894u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1d8898: 0xac237284  sw          $v1, 0x7284($at)
    ctx->pc = 0x1d8898u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 29316), GPR_U32(ctx, 3));
    // 0x1d889c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d889cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d88a0: 0xac227288  sw          $v0, 0x7288($at)
    ctx->pc = 0x1d88a0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 29320), GPR_U32(ctx, 2));
    // 0x1d88a4: 0xa6750000  sh          $s5, 0x0($s3)
    ctx->pc = 0x1d88a4u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 21));
    // 0x1d88a8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D88A8u;
    SET_GPR_U32(ctx, 31, 0x1D88B0u);
    ctx->pc = 0x1D88ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D88A8u;
            // 0x1d88ac: 0xa6740002  sh          $s4, 0x2($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 2), (uint16_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88B0u; }
        if (ctx->pc != 0x1D88B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88B0u; }
        if (ctx->pc != 0x1D88B0u) { return; }
    }
    ctx->pc = 0x1D88B0u;
label_1d88b0:
    // 0x1d88b0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1d88b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d88b4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D88B4u;
    SET_GPR_U32(ctx, 31, 0x1D88BCu);
    ctx->pc = 0x1D88B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D88B4u;
            // 0x1d88b8: 0x26640104  addiu       $a0, $s3, 0x104 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 260));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88BCu; }
        if (ctx->pc != 0x1D88BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88BCu; }
        if (ctx->pc != 0x1D88BCu) { return; }
    }
    ctx->pc = 0x1D88BCu;
label_1d88bc:
    // 0x1d88bc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d88bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d88c0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D88C0u;
    SET_GPR_U32(ctx, 31, 0x1D88C8u);
    ctx->pc = 0x1D88C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D88C0u;
            // 0x1d88c4: 0x26640204  addiu       $a0, $s3, 0x204 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 516));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88C8u; }
        if (ctx->pc != 0x1D88C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88C8u; }
        if (ctx->pc != 0x1D88C8u) { return; }
    }
    ctx->pc = 0x1D88C8u;
label_1d88c8:
    // 0x1d88c8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d88c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d88cc: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D88CCu;
    SET_GPR_U32(ctx, 31, 0x1D88D4u);
    ctx->pc = 0x1D88D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D88CCu;
            // 0x1d88d0: 0x26640304  addiu       $a0, $s3, 0x304 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 772));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88D4u; }
        if (ctx->pc != 0x1D88D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88D4u; }
        if (ctx->pc != 0x1D88D4u) { return; }
    }
    ctx->pc = 0x1D88D4u;
label_1d88d4:
    // 0x1d88d4: 0x26640404  addiu       $a0, $s3, 0x404
    ctx->pc = 0x1d88d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 1028));
    // 0x1d88d8: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1D88D8u;
    SET_GPR_U32(ctx, 31, 0x1D88E0u);
    ctx->pc = 0x1D88DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D88D8u;
            // 0x1d88dc: 0x2e0282d  daddu       $a1, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88E0u; }
        if (ctx->pc != 0x1D88E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D88E0u; }
        if (ctx->pc != 0x1D88E0u) { return; }
    }
    ctx->pc = 0x1D88E0u;
label_1d88e0:
    // 0x1d88e0: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d88e0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d88e4: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d88e4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d88e8: 0x24040021  addiu       $a0, $zero, 0x21
    ctx->pc = 0x1d88e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x1d88ec: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d88ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d88f0: 0x24060524  addiu       $a2, $zero, 0x524
    ctx->pc = 0x1d88f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1316));
    // 0x1d88f4: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d88f4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d88f8: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D88F8u;
    SET_GPR_U32(ctx, 31, 0x1D8900u);
    ctx->pc = 0x1D88FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D88F8u;
            // 0x1d88fc: 0x24080020  addiu       $t0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8900u; }
        if (ctx->pc != 0x1D8900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8900u; }
        if (ctx->pc != 0x1D8900u) { return; }
    }
    ctx->pc = 0x1D8900u;
label_1d8900:
    // 0x1d8900: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8900u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8904: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8904u;
    SET_GPR_U32(ctx, 31, 0x1D890Cu);
    ctx->pc = 0x1D8908u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8904u;
            // 0x1d8908: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D890Cu; }
        if (ctx->pc != 0x1D890Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D890Cu; }
        if (ctx->pc != 0x1D890Cu) { return; }
    }
    ctx->pc = 0x1D890Cu;
label_1d890c:
    // 0x1d890c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d890cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8910: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1d8910u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1d8914: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1d8914u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1d8918: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1d8918u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d891c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d891cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d8920: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d8920u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d8924: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d8924u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d8928: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d8928u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d892c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d892cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8930: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8930u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8934: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8934u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8934u;
            // 0x1d8938: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D886Cu: goto label_1d886c;
            case 0x1D88B0u: goto label_1d88b0;
            case 0x1D88BCu: goto label_1d88bc;
            case 0x1D88C8u: goto label_1d88c8;
            case 0x1D88D4u: goto label_1d88d4;
            case 0x1D88E0u: goto label_1d88e0;
            case 0x1D8900u: goto label_1d8900;
            case 0x1D890Cu: goto label_1d890c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D893Cu;
    // 0x1d893c: 0x0  nop
    ctx->pc = 0x1d893cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
