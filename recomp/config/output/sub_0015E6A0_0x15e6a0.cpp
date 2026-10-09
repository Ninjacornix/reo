#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E6A0
// Address: 0x15e6a0 - 0x15e818
void sub_0015E6A0_0x15e6a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E6A0_0x15e6a0");
#endif

    switch (ctx->pc) {
        case 0x15e6f4u: goto label_15e6f4;
        case 0x15e71cu: goto label_15e71c;
        case 0x15e724u: goto label_15e724;
        case 0x15e72cu: goto label_15e72c;
        case 0x15e734u: goto label_15e734;
        case 0x15e73cu: goto label_15e73c;
        case 0x15e74cu: goto label_15e74c;
        case 0x15e758u: goto label_15e758;
        case 0x15e760u: goto label_15e760;
        case 0x15e780u: goto label_15e780;
        case 0x15e790u: goto label_15e790;
        case 0x15e798u: goto label_15e798;
        case 0x15e7a0u: goto label_15e7a0;
        case 0x15e7b4u: goto label_15e7b4;
        case 0x15e7c8u: goto label_15e7c8;
        case 0x15e7d0u: goto label_15e7d0;
        case 0x15e7e0u: goto label_15e7e0;
        case 0x15e7e8u: goto label_15e7e8;
        case 0x15e7f0u: goto label_15e7f0;
        default: break;
    }

    ctx->pc = 0x15e6a0u;

    // 0x15e6a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15e6a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15e6a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15e6a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15e6a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15e6a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e6ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15e6acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15e6b0: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15E6B0u;
    {
        const bool branch_taken_0x15e6b0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x15E6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E6B0u;
            // 0x15e6b4: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e6b0) {
            ctx->pc = 0x15E6D8u;
            goto label_15e6d8;
        }
    }
    ctx->pc = 0x15E6B8u;
    // 0x15e6b8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15e6b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15e6bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e6bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e6c0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15e6c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e6c4: 0x2484ee68  addiu       $a0, $a0, -0x1198
    ctx->pc = 0x15e6c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962792));
    // 0x15e6c8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15e6c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e6cc: 0x8058dd4  j           func_163750
    ctx->pc = 0x15E6CCu;
    ctx->pc = 0x15E6D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E6CCu;
            // 0x15e6d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15E6D4u;
    // 0x15e6d4: 0x0  nop
    ctx->pc = 0x15e6d4u;
    // NOP
label_15e6d8:
    // 0x15e6d8: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x15e6d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x15e6dc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15e6dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15e6e0: 0x24638538  addiu       $v1, $v1, -0x7AC8
    ctx->pc = 0x15e6e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294935864));
    // 0x15e6e4: 0x2442edc8  addiu       $v0, $v0, -0x1238
    ctx->pc = 0x15e6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962632));
    // 0x15e6e8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x15e6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x15e6ec: 0xc058d20  jal         func_163480
    ctx->pc = 0x15E6ECu;
    SET_GPR_U32(ctx, 31, 0x15E6F4u);
    ctx->pc = 0x15E6F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E6ECu;
            // 0x15e6f0: 0x3c110023  lui         $s1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163480u;
    if (runtime->hasFunction(0x163480u)) {
        auto targetFn = runtime->lookupFunction(0x163480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E6F4u; }
        if (ctx->pc != 0x15E6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163480_0x163480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E6F4u; }
        if (ctx->pc != 0x15E6F4u) { return; }
    }
    ctx->pc = 0x15E6F4u;
label_15e6f4:
    // 0x15e6f4: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x15e6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x15e6f8: 0x2442fffe  addiu       $v0, $v0, -0x2
    ctx->pc = 0x15e6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967294));
    // 0x15e6fc: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x15e6fcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15e700: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x15e700u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x15e704: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x15e704u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x15e708: 0x8e23de50  lw          $v1, -0x21B0($s1)
    ctx->pc = 0x15e708u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294958672)));
    // 0x15e70c: 0x54600039  bnel        $v1, $zero, . + 4 + (0x39 << 2)
    ctx->pc = 0x15E70Cu;
    {
        const bool branch_taken_0x15e70c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x15e70c) {
            ctx->pc = 0x15E710u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E70Cu;
            // 0x15e710: 0x2623de50  addiu       $v1, $s1, -0x21B0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294958672));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E7F4u;
            goto label_15e7f4;
        }
    }
    ctx->pc = 0x15E714u;
    // 0x15e714: 0xc04a87a  jal         func_12A1E8
    ctx->pc = 0x15E714u;
    SET_GPR_U32(ctx, 31, 0x15E71Cu);
    ctx->pc = 0x12A1E8u;
    if (runtime->hasFunction(0x12A1E8u)) {
        auto targetFn = runtime->lookupFunction(0x12A1E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E71Cu; }
        if (ctx->pc != 0x15E71Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A1E8_0x12a1e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E71Cu; }
        if (ctx->pc != 0x15E71Cu) { return; }
    }
    ctx->pc = 0x15E71Cu;
label_15e71c:
    // 0x15e71c: 0xc04fdfe  jal         func_13F7F8
    ctx->pc = 0x15E71Cu;
    SET_GPR_U32(ctx, 31, 0x15E724u);
    ctx->pc = 0x13F7F8u;
    if (runtime->hasFunction(0x13F7F8u)) {
        auto targetFn = runtime->lookupFunction(0x13F7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E724u; }
        if (ctx->pc != 0x15E724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F7F8_0x13f7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E724u; }
        if (ctx->pc != 0x15E724u) { return; }
    }
    ctx->pc = 0x15E724u;
label_15e724:
    // 0x15e724: 0xc04fcb0  jal         func_13F2C0
    ctx->pc = 0x15E724u;
    SET_GPR_U32(ctx, 31, 0x15E72Cu);
    ctx->pc = 0x13F2C0u;
    if (runtime->hasFunction(0x13F2C0u)) {
        auto targetFn = runtime->lookupFunction(0x13F2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E72Cu; }
        if (ctx->pc != 0x15E72Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F2C0_0x13f2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E72Cu; }
        if (ctx->pc != 0x15E72Cu) { return; }
    }
    ctx->pc = 0x15E72Cu;
label_15e72c:
    // 0x15e72c: 0xc050008  jal         func_140020
    ctx->pc = 0x15E72Cu;
    SET_GPR_U32(ctx, 31, 0x15E734u);
    ctx->pc = 0x140020u;
    if (runtime->hasFunction(0x140020u)) {
        auto targetFn = runtime->lookupFunction(0x140020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E734u; }
        if (ctx->pc != 0x15E734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140020_0x140020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E734u; }
        if (ctx->pc != 0x15E734u) { return; }
    }
    ctx->pc = 0x15E734u;
label_15e734:
    // 0x15e734: 0xc059102  jal         func_164408
    ctx->pc = 0x15E734u;
    SET_GPR_U32(ctx, 31, 0x15E73Cu);
    ctx->pc = 0x164408u;
    if (runtime->hasFunction(0x164408u)) {
        auto targetFn = runtime->lookupFunction(0x164408u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E73Cu; }
        if (ctx->pc != 0x15E73Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164408_0x164408(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E73Cu; }
        if (ctx->pc != 0x15E73Cu) { return; }
    }
    ctx->pc = 0x15E73Cu;
label_15e73c:
    // 0x15e73c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15E73Cu;
    {
        const bool branch_taken_0x15e73c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E73Cu;
            // 0x15e740: 0x2404ff9b  addiu       $a0, $zero, -0x65 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967195));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e73c) {
            ctx->pc = 0x15E758u;
            goto label_15e758;
        }
    }
    ctx->pc = 0x15E744u;
    // 0x15e744: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15E744u;
    SET_GPR_U32(ctx, 31, 0x15E74Cu);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E74Cu; }
        if (ctx->pc != 0x15E74Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E74Cu; }
        if (ctx->pc != 0x15E74Cu) { return; }
    }
    ctx->pc = 0x15E74Cu;
label_15e74c:
    // 0x15e74c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15e74cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15e750: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15E750u;
    SET_GPR_U32(ctx, 31, 0x15E758u);
    ctx->pc = 0x15E754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E750u;
            // 0x15e754: 0x2484ee90  addiu       $a0, $a0, -0x1170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962832));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E758u; }
        if (ctx->pc != 0x15E758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E758u; }
        if (ctx->pc != 0x15E758u) { return; }
    }
    ctx->pc = 0x15E758u;
label_15e758:
    // 0x15e758: 0xc057a18  jal         func_15E860
    ctx->pc = 0x15E758u;
    SET_GPR_U32(ctx, 31, 0x15E760u);
    ctx->pc = 0x15E75Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E758u;
            // 0x15e75c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E860u;
    if (runtime->hasFunction(0x15E860u)) {
        auto targetFn = runtime->lookupFunction(0x15E860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E760u; }
        if (ctx->pc != 0x15E760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E860_0x15e860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E760u; }
        if (ctx->pc != 0x15E760u) { return; }
    }
    ctx->pc = 0x15E760u;
label_15e760:
    // 0x15e760: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15e760u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15e764: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x15e764u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x15e768: 0x2442ef5c  addiu       $v0, $v0, -0x10A4
    ctx->pc = 0x15e768u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963036));
    // 0x15e76c: 0x3c01447a  lui         $at, 0x447A
    ctx->pc = 0x15e76cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)17530 << 16));
    // 0x15e770: 0x44816000  mtc1        $at, $f12
    ctx->pc = 0x15e770u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x15e774: 0x0  nop
    ctx->pc = 0x15e774u;
    // NOP
    // 0x15e778: 0xc04462e  jal         func_1118B8
    ctx->pc = 0x15E778u;
    SET_GPR_U32(ctx, 31, 0x15E780u);
    ctx->pc = 0x15E77Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E778u;
            // 0x15e77c: 0x460c0302  mul.s       $f12, $f0, $f12 (Delay Slot)
        ctx->f[12] = FPU_MUL_S(ctx->f[0], ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118B8u;
    if (runtime->hasFunction(0x1118B8u)) {
        auto targetFn = runtime->lookupFunction(0x1118B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E780u; }
        if (ctx->pc != 0x15E780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E780u; }
        if (ctx->pc != 0x15E780u) { return; }
    }
    ctx->pc = 0x15E780u;
label_15e780:
    // 0x15e780: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x15e780u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x15e784: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x15e784u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x15e788: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x15E788u;
    SET_GPR_U32(ctx, 31, 0x15E790u);
    ctx->pc = 0x15E78Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E788u;
            // 0x15e78c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E790u; }
        if (ctx->pc != 0x15E790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E790u; }
        if (ctx->pc != 0x15E790u) { return; }
    }
    ctx->pc = 0x15E790u;
label_15e790:
    // 0x15e790: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x15E790u;
    SET_GPR_U32(ctx, 31, 0x15E798u);
    ctx->pc = 0x15E794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E790u;
            // 0x15e794: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E798u; }
        if (ctx->pc != 0x15E798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E798u; }
        if (ctx->pc != 0x15E798u) { return; }
    }
    ctx->pc = 0x15E798u;
label_15e798:
    // 0x15e798: 0xc057ad0  jal         func_15EB40
    ctx->pc = 0x15E798u;
    SET_GPR_U32(ctx, 31, 0x15E7A0u);
    ctx->pc = 0x15E79Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E798u;
            // 0x15e79c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EB40u;
    if (runtime->hasFunction(0x15EB40u)) {
        auto targetFn = runtime->lookupFunction(0x15EB40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7A0u; }
        if (ctx->pc != 0x15E7A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EB40_0x15eb40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7A0u; }
        if (ctx->pc != 0x15E7A0u) { return; }
    }
    ctx->pc = 0x15E7A0u;
label_15e7a0:
    // 0x15e7a0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15e7a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15e7a4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15E7A4u;
    {
        const bool branch_taken_0x15e7a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E7A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E7A4u;
            // 0x15e7a8: 0x2484eeb8  addiu       $a0, $a0, -0x1148 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962872));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e7a4) {
            ctx->pc = 0x15E7B4u;
            goto label_15e7b4;
        }
    }
    ctx->pc = 0x15E7ACu;
    // 0x15e7ac: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15E7ACu;
    SET_GPR_U32(ctx, 31, 0x15E7B4u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7B4u; }
        if (ctx->pc != 0x15E7B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7B4u; }
        if (ctx->pc != 0x15E7B4u) { return; }
    }
    ctx->pc = 0x15E7B4u;
label_15e7b4:
    // 0x15e7b4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15e7b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15e7b8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15e7b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15e7bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15e7bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e7c0: 0xc057a66  jal         func_15E998
    ctx->pc = 0x15E7C0u;
    SET_GPR_U32(ctx, 31, 0x15E7C8u);
    ctx->pc = 0x15E998u;
    if (runtime->hasFunction(0x15E998u)) {
        auto targetFn = runtime->lookupFunction(0x15E998u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7C8u; }
        if (ctx->pc != 0x15E7C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E998_0x15e998(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7C8u; }
        if (ctx->pc != 0x15E7C8u) { return; }
    }
    ctx->pc = 0x15E7C8u;
label_15e7c8:
    // 0x15e7c8: 0xc04f566  jal         func_13D598
    ctx->pc = 0x15E7C8u;
    SET_GPR_U32(ctx, 31, 0x15E7D0u);
    ctx->pc = 0x13D598u;
    if (runtime->hasFunction(0x13D598u)) {
        auto targetFn = runtime->lookupFunction(0x13D598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7D0u; }
        if (ctx->pc != 0x15E7D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D598_0x13d598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7D0u; }
        if (ctx->pc != 0x15E7D0u) { return; }
    }
    ctx->pc = 0x15E7D0u;
label_15e7d0:
    // 0x15e7d0: 0x3c040016  lui         $a0, 0x16
    ctx->pc = 0x15e7d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)22 << 16));
    // 0x15e7d4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15e7d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e7d8: 0xc04f534  jal         func_13D4D0
    ctx->pc = 0x15E7D8u;
    SET_GPR_U32(ctx, 31, 0x15E7E0u);
    ctx->pc = 0x15E7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E7D8u;
            // 0x15e7dc: 0x2484e688  addiu       $a0, $a0, -0x1978 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4D0u;
    if (runtime->hasFunction(0x13D4D0u)) {
        auto targetFn = runtime->lookupFunction(0x13D4D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7E0u; }
        if (ctx->pc != 0x15E7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4D0_0x13d4d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7E0u; }
        if (ctx->pc != 0x15E7E0u) { return; }
    }
    ctx->pc = 0x15E7E0u;
label_15e7e0:
    // 0x15e7e0: 0xc0582c0  jal         func_160B00
    ctx->pc = 0x15E7E0u;
    SET_GPR_U32(ctx, 31, 0x15E7E8u);
    ctx->pc = 0x160B00u;
    if (runtime->hasFunction(0x160B00u)) {
        auto targetFn = runtime->lookupFunction(0x160B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7E8u; }
        if (ctx->pc != 0x15E7E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B00_0x160b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7E8u; }
        if (ctx->pc != 0x15E7E8u) { return; }
    }
    ctx->pc = 0x15E7E8u;
label_15e7e8:
    // 0x15e7e8: 0xc057a06  jal         func_15E818
    ctx->pc = 0x15E7E8u;
    SET_GPR_U32(ctx, 31, 0x15E7F0u);
    ctx->pc = 0x15E7ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E7E8u;
            // 0x15e7ec: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E818u;
    if (runtime->hasFunction(0x15E818u)) {
        auto targetFn = runtime->lookupFunction(0x15E818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7F0u; }
        if (ctx->pc != 0x15E7F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E818_0x15e818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E7F0u; }
        if (ctx->pc != 0x15E7F0u) { return; }
    }
    ctx->pc = 0x15E7F0u;
label_15e7f0:
    // 0x15e7f0: 0x2623de50  addiu       $v1, $s1, -0x21B0
    ctx->pc = 0x15e7f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294958672));
label_15e7f4:
    // 0x15e7f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15e7f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e7f8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x15e7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x15e7fc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e7fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e800: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15e800u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15e804: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x15e804u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x15e808: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x15e808u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x15e80c: 0x3e00008  jr          $ra
    ctx->pc = 0x15E80Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E80Cu;
            // 0x15e810: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E6D8u: goto label_15e6d8;
            case 0x15E6F4u: goto label_15e6f4;
            case 0x15E71Cu: goto label_15e71c;
            case 0x15E724u: goto label_15e724;
            case 0x15E72Cu: goto label_15e72c;
            case 0x15E734u: goto label_15e734;
            case 0x15E73Cu: goto label_15e73c;
            case 0x15E74Cu: goto label_15e74c;
            case 0x15E758u: goto label_15e758;
            case 0x15E760u: goto label_15e760;
            case 0x15E780u: goto label_15e780;
            case 0x15E790u: goto label_15e790;
            case 0x15E798u: goto label_15e798;
            case 0x15E7A0u: goto label_15e7a0;
            case 0x15E7B4u: goto label_15e7b4;
            case 0x15E7C8u: goto label_15e7c8;
            case 0x15E7D0u: goto label_15e7d0;
            case 0x15E7E0u: goto label_15e7e0;
            case 0x15E7E8u: goto label_15e7e8;
            case 0x15E7F0u: goto label_15e7f0;
            case 0x15E7F4u: goto label_15e7f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E814u;
    // 0x15e814: 0x0  nop
    ctx->pc = 0x15e814u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
