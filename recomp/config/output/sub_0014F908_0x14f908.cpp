#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0014F908
// Address: 0x14f908 - 0x14ff50
void sub_0014F908_0x14f908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0014F908_0x14f908");
#endif

    switch (ctx->pc) {
        case 0x14f94cu: goto label_14f94c;
        case 0x14f968u: goto label_14f968;
        case 0x14f974u: goto label_14f974;
        case 0x14f994u: goto label_14f994;
        case 0x14f9a4u: goto label_14f9a4;
        case 0x14f9b0u: goto label_14f9b0;
        case 0x14f9d0u: goto label_14f9d0;
        case 0x14f9e4u: goto label_14f9e4;
        case 0x14f9f0u: goto label_14f9f0;
        case 0x14f9f8u: goto label_14f9f8;
        case 0x14fa0cu: goto label_14fa0c;
        case 0x14fa18u: goto label_14fa18;
        case 0x14fa20u: goto label_14fa20;
        case 0x14fa40u: goto label_14fa40;
        case 0x14fa4cu: goto label_14fa4c;
        case 0x14fa54u: goto label_14fa54;
        case 0x14fa68u: goto label_14fa68;
        case 0x14fa74u: goto label_14fa74;
        case 0x14fa7cu: goto label_14fa7c;
        case 0x14fa98u: goto label_14fa98;
        case 0x14faa4u: goto label_14faa4;
        case 0x14fab0u: goto label_14fab0;
        case 0x14fad8u: goto label_14fad8;
        case 0x14fb08u: goto label_14fb08;
        case 0x14fb14u: goto label_14fb14;
        case 0x14fb1cu: goto label_14fb1c;
        case 0x14fb48u: goto label_14fb48;
        case 0x14fb78u: goto label_14fb78;
        case 0x14fb84u: goto label_14fb84;
        case 0x14fb8cu: goto label_14fb8c;
        case 0x14fc18u: goto label_14fc18;
        case 0x14fc28u: goto label_14fc28;
        case 0x14fc34u: goto label_14fc34;
        case 0x14fc50u: goto label_14fc50;
        case 0x14fc60u: goto label_14fc60;
        case 0x14fc6cu: goto label_14fc6c;
        case 0x14fc80u: goto label_14fc80;
        case 0x14fc8cu: goto label_14fc8c;
        case 0x14fc94u: goto label_14fc94;
        case 0x14fcb4u: goto label_14fcb4;
        case 0x14fcc0u: goto label_14fcc0;
        case 0x14fcc8u: goto label_14fcc8;
        case 0x14fcdcu: goto label_14fcdc;
        case 0x14fce8u: goto label_14fce8;
        case 0x14fcf0u: goto label_14fcf0;
        case 0x14fd08u: goto label_14fd08;
        case 0x14fd38u: goto label_14fd38;
        case 0x14fd58u: goto label_14fd58;
        case 0x14fd68u: goto label_14fd68;
        case 0x14fd78u: goto label_14fd78;
        case 0x14fd80u: goto label_14fd80;
        case 0x14fdb8u: goto label_14fdb8;
        case 0x14fde8u: goto label_14fde8;
        case 0x14fe0cu: goto label_14fe0c;
        case 0x14fe1cu: goto label_14fe1c;
        case 0x14fe2cu: goto label_14fe2c;
        case 0x14fe34u: goto label_14fe34;
        case 0x14fea8u: goto label_14fea8;
        case 0x14ff08u: goto label_14ff08;
        default: break;
    }

    ctx->pc = 0x14f908u;

    // 0x14f908: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x14f908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x14f90c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x14f90cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x14f910: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14f910u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f914: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x14f914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x14f918: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x14f918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x14f91c: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x14f91cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f920: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x14f920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x14f924: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x14f924u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f928: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x14f928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x14f92c: 0xe0b82d  daddu       $s7, $a3, $zero
    ctx->pc = 0x14f92cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f930: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x14f930u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x14f934: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x14f934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x14f938: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x14f938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x14f93c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x14f93cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x14f940: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x14f940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x14f944: 0xc052490  jal         func_149240
    ctx->pc = 0x14F944u;
    SET_GPR_U32(ctx, 31, 0x14F94Cu);
    ctx->pc = 0x14F948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F944u;
            // 0x14f948: 0xafa40000  sw          $a0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149240u;
    if (runtime->hasFunction(0x149240u)) {
        auto targetFn = runtime->lookupFunction(0x149240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F94Cu; }
        if (ctx->pc != 0x14F94Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149240_0x149240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F94Cu; }
        if (ctx->pc != 0x14F94Cu) { return; }
    }
    ctx->pc = 0x14F94Cu;
label_14f94c:
    // 0x14f94c: 0x40f02d  daddu       $fp, $v0, $zero
    ctx->pc = 0x14f94cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f950: 0x26e20800  addiu       $v0, $s7, 0x800
    ctx->pc = 0x14f950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 23), 2048));
    // 0x14f954: 0x26e31000  addiu       $v1, $s7, 0x1000
    ctx->pc = 0x14f954u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), 4096));
    // 0x14f958: 0x3414ff80  ori         $s4, $zero, 0xFF80
    ctx->pc = 0x14f958u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x14f95c: 0x14a3bc  dsll32      $s4, $s4, 14
    ctx->pc = 0x14f95cu;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) << (32 + 14));
    // 0x14f960: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x14f960u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x14f964: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x14f964u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
label_14f968:
    // 0x14f968: 0x2664fff0  addiu       $a0, $s3, -0x10
    ctx->pc = 0x14f968u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967280));
    // 0x14f96c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14F96Cu;
    SET_GPR_U32(ctx, 31, 0x14F974u);
    ctx->pc = 0x14F970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F96Cu;
            // 0x14f970: 0x1380c0  sll         $s0, $s3, 3 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F974u; }
        if (ctx->pc != 0x14F974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F974u; }
        if (ctx->pc != 0x14F974u) { return; }
    }
    ctx->pc = 0x14F974u;
label_14f974:
    // 0x14f974: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14f974u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14f978: 0xdc25e2b0  ld          $a1, -0x1D50($at)
    ctx->pc = 0x14f978u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959792)));
    // 0x14f97c: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x14f97cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14f980: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x14f980u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f984: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x14f984u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x14f988: 0x2039021  addu        $s2, $s0, $v1
    ctx->pc = 0x14f988u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x14f98c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14F98Cu;
    SET_GPR_U32(ctx, 31, 0x14F994u);
    ctx->pc = 0x14F990u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F98Cu;
            // 0x14f990: 0x2028821  addu        $s1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F994u; }
        if (ctx->pc != 0x14F994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F994u; }
        if (ctx->pc != 0x14F994u) { return; }
    }
    ctx->pc = 0x14F994u;
label_14f994:
    // 0x14f994: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x14f994u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f998: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14f998u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f99c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14F99Cu;
    SET_GPR_U32(ctx, 31, 0x14F9A4u);
    ctx->pc = 0x14F9A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F99Cu;
            // 0x14f9a0: 0x2178021  addu        $s0, $s0, $s7 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 23)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9A4u; }
        if (ctx->pc != 0x14F9A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9A4u; }
        if (ctx->pc != 0x14F9A4u) { return; }
    }
    ctx->pc = 0x14F9A4u;
label_14f9a4:
    // 0x14f9a4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x14f9a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f9a8: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14F9A8u;
    SET_GPR_U32(ctx, 31, 0x14F9B0u);
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9B0u; }
        if (ctx->pc != 0x14F9B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9B0u; }
        if (ctx->pc != 0x14F9B0u) { return; }
    }
    ctx->pc = 0x14F9B0u;
label_14f9b0:
    // 0x14f9b0: 0x2664ff80  addiu       $a0, $s3, -0x80
    ctx->pc = 0x14f9b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967168));
    // 0x14f9b4: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x14f9b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x14f9b8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x14f9b8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x14f9bc: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x14f9bcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x14f9c0: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x14f9c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x14f9c4: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x14f9c4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x14f9c8: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14F9C8u;
    SET_GPR_U32(ctx, 31, 0x14F9D0u);
    ctx->pc = 0x14F9CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F9C8u;
            // 0x14f9cc: 0xa6020002  sh          $v0, 0x2($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9D0u; }
        if (ctx->pc != 0x14F9D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9D0u; }
        if (ctx->pc != 0x14F9D0u) { return; }
    }
    ctx->pc = 0x14F9D0u;
label_14f9d0:
    // 0x14f9d0: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14f9d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14f9d4: 0xdc25e2b8  ld          $a1, -0x1D48($at)
    ctx->pc = 0x14f9d4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959800)));
    // 0x14f9d8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x14f9d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f9dc: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14F9DCu;
    SET_GPR_U32(ctx, 31, 0x14F9E4u);
    ctx->pc = 0x14F9E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F9DCu;
            // 0x14f9e0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9E4u; }
        if (ctx->pc != 0x14F9E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9E4u; }
        if (ctx->pc != 0x14F9E4u) { return; }
    }
    ctx->pc = 0x14F9E4u;
label_14f9e4:
    // 0x14f9e4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14f9e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f9e8: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14F9E8u;
    SET_GPR_U32(ctx, 31, 0x14F9F0u);
    ctx->pc = 0x14F9ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F9E8u;
            // 0x14f9ec: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9F0u; }
        if (ctx->pc != 0x14F9F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9F0u; }
        if (ctx->pc != 0x14F9F0u) { return; }
    }
    ctx->pc = 0x14F9F0u;
label_14f9f0:
    // 0x14f9f0: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14F9F0u;
    SET_GPR_U32(ctx, 31, 0x14F9F8u);
    ctx->pc = 0x14F9F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14F9F0u;
            // 0x14f9f4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9F8u; }
        if (ctx->pc != 0x14F9F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14F9F8u; }
        if (ctx->pc != 0x14F9F8u) { return; }
    }
    ctx->pc = 0x14F9F8u;
label_14f9f8:
    // 0x14f9f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14f9f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14f9fc: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14f9fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fa00: 0xdc25e2c0  ld          $a1, -0x1D40($at)
    ctx->pc = 0x14fa00u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959808)));
    // 0x14fa04: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FA04u;
    SET_GPR_U32(ctx, 31, 0x14FA0Cu);
    ctx->pc = 0x14FA08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA04u;
            // 0x14fa08: 0xa6220004  sh          $v0, 0x4($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA0Cu; }
        if (ctx->pc != 0x14FA0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA0Cu; }
        if (ctx->pc != 0x14FA0Cu) { return; }
    }
    ctx->pc = 0x14FA0Cu;
label_14fa0c:
    // 0x14fa0c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fa0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fa10: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FA10u;
    SET_GPR_U32(ctx, 31, 0x14FA18u);
    ctx->pc = 0x14FA14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA10u;
            // 0x14fa14: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA18u; }
        if (ctx->pc != 0x14FA18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA18u; }
        if (ctx->pc != 0x14FA18u) { return; }
    }
    ctx->pc = 0x14FA18u;
label_14fa18:
    // 0x14fa18: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FA18u;
    SET_GPR_U32(ctx, 31, 0x14FA20u);
    ctx->pc = 0x14FA1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA18u;
            // 0x14fa1c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA20u; }
        if (ctx->pc != 0x14FA20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA20u; }
        if (ctx->pc != 0x14FA20u) { return; }
    }
    ctx->pc = 0x14FA20u;
label_14fa20:
    // 0x14fa20: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x14fa20u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fa24: 0xa6220002  sh          $v0, 0x2($s1)
    ctx->pc = 0x14fa24u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fa28: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14fa28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fa2c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x14fa2cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fa30: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fa30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fa34: 0xdc25e2c8  ld          $a1, -0x1D38($at)
    ctx->pc = 0x14fa34u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959816)));
    // 0x14fa38: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FA38u;
    SET_GPR_U32(ctx, 31, 0x14FA40u);
    ctx->pc = 0x14FA3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA38u;
            // 0x14fa3c: 0xa6400004  sh          $zero, 0x4($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA40u; }
        if (ctx->pc != 0x14FA40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA40u; }
        if (ctx->pc != 0x14FA40u) { return; }
    }
    ctx->pc = 0x14FA40u;
label_14fa40:
    // 0x14fa40: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fa40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fa44: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FA44u;
    SET_GPR_U32(ctx, 31, 0x14FA4Cu);
    ctx->pc = 0x14FA48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA44u;
            // 0x14fa48: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA4Cu; }
        if (ctx->pc != 0x14FA4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA4Cu; }
        if (ctx->pc != 0x14FA4Cu) { return; }
    }
    ctx->pc = 0x14FA4Cu;
label_14fa4c:
    // 0x14fa4c: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FA4Cu;
    SET_GPR_U32(ctx, 31, 0x14FA54u);
    ctx->pc = 0x14FA50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA4Cu;
            // 0x14fa50: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA54u; }
        if (ctx->pc != 0x14FA54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA54u; }
        if (ctx->pc != 0x14FA54u) { return; }
    }
    ctx->pc = 0x14FA54u;
label_14fa54:
    // 0x14fa54: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x14fa54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fa58: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fa58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fa5c: 0xdc25e2d0  ld          $a1, -0x1D30($at)
    ctx->pc = 0x14fa5cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959824)));
    // 0x14fa60: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FA60u;
    SET_GPR_U32(ctx, 31, 0x14FA68u);
    ctx->pc = 0x14FA64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA60u;
            // 0x14fa64: 0xa6420002  sh          $v0, 0x2($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA68u; }
        if (ctx->pc != 0x14FA68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA68u; }
        if (ctx->pc != 0x14FA68u) { return; }
    }
    ctx->pc = 0x14FA68u;
label_14fa68:
    // 0x14fa68: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fa68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fa6c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FA6Cu;
    SET_GPR_U32(ctx, 31, 0x14FA74u);
    ctx->pc = 0x14FA70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA6Cu;
            // 0x14fa70: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA74u; }
        if (ctx->pc != 0x14FA74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA74u; }
        if (ctx->pc != 0x14FA74u) { return; }
    }
    ctx->pc = 0x14FA74u;
label_14fa74:
    // 0x14fa74: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FA74u;
    SET_GPR_U32(ctx, 31, 0x14FA7Cu);
    ctx->pc = 0x14FA78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA74u;
            // 0x14fa78: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA7Cu; }
        if (ctx->pc != 0x14FA7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA7Cu; }
        if (ctx->pc != 0x14FA7Cu) { return; }
    }
    ctx->pc = 0x14FA7Cu;
label_14fa7c:
    // 0x14fa7c: 0xa6400006  sh          $zero, 0x6($s2)
    ctx->pc = 0x14fa7cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fa80: 0x2a630100  slti        $v1, $s3, 0x100
    ctx->pc = 0x14fa80u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x14fa84: 0x1460ffb8  bnez        $v1, . + 4 + (-0x48 << 2)
    ctx->pc = 0x14FA84u;
    {
        const bool branch_taken_0x14fa84 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x14FA88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA84u;
            // 0x14fa88: 0xa6420000  sh          $v0, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fa84) {
            ctx->pc = 0x14F968u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14f968;
        }
    }
    ctx->pc = 0x14FA8Cu;
    // 0x14fa8c: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x14fa8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fa90: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FA90u;
    SET_GPR_U32(ctx, 31, 0x14FA98u);
    ctx->pc = 0x14FA94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA90u;
            // 0x14fa94: 0x2b68823  subu        $s1, $s5, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA98u; }
        if (ctx->pc != 0x14FA98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FA98u; }
        if (ctx->pc != 0x14FA98u) { return; }
    }
    ctx->pc = 0x14FA98u;
label_14fa98:
    // 0x14fa98: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x14fa98u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fa9c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FA9Cu;
    SET_GPR_U32(ctx, 31, 0x14FAA4u);
    ctx->pc = 0x14FAA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FA9Cu;
            // 0x14faa0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FAA4u; }
        if (ctx->pc != 0x14FAA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FAA4u; }
        if (ctx->pc != 0x14FAA4u) { return; }
    }
    ctx->pc = 0x14FAA4u;
label_14faa4:
    // 0x14faa4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x14faa4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14faa8: 0xc04480e  jal         func_112038
    ctx->pc = 0x14FAA8u;
    SET_GPR_U32(ctx, 31, 0x14FAB0u);
    ctx->pc = 0x14FAACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FAA8u;
            // 0x14faac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FAB0u; }
        if (ctx->pc != 0x14FAB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FAB0u; }
        if (ctx->pc != 0x14FAB0u) { return; }
    }
    ctx->pc = 0x14FAB0u;
label_14fab0:
    // 0x14fab0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x14fab0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14fab4: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x14fab4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fab8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x14fab8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14fabc: 0x14620020  bne         $v1, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x14FABCu;
    {
        const bool branch_taken_0x14fabc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x14FAC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FABCu;
            // 0x14fac0: 0x1e8980  sll         $s1, $fp, 6 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 30), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fabc) {
            ctx->pc = 0x14FB40u;
            goto label_14fb40;
        }
    }
    ctx->pc = 0x14FAC4u;
    // 0x14fac4: 0x1ea180  sll         $s4, $fp, 6
    ctx->pc = 0x14fac4u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 30), 6));
    // 0x14fac8: 0x26f00006  addiu       $s0, $s7, 0x6
    ctx->pc = 0x14fac8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), 6));
    // 0x14facc: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14faccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fad0: 0x241100ff  addiu       $s1, $zero, 0xFF
    ctx->pc = 0x14fad0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x14fad4: 0x0  nop
    ctx->pc = 0x14fad4u;
    // NOP
label_14fad8:
    // 0x14fad8: 0x276102a  slt         $v0, $s3, $s6
    ctx->pc = 0x14fad8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x14fadc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x14FADCu;
    {
        const bool branch_taken_0x14fadc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FADCu;
            // 0x14fae0: 0x2b3102a  slt         $v0, $s5, $s3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fadc) {
            ctx->pc = 0x14FAF0u;
            goto label_14faf0;
        }
    }
    ctx->pc = 0x14FAE4u;
    // 0x14fae4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x14FAE4u;
    {
        const bool branch_taken_0x14fae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FAE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FAE4u;
            // 0x14fae8: 0xa6140000  sh          $s4, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fae4) {
            ctx->pc = 0x14FB24u;
            goto label_14fb24;
        }
    }
    ctx->pc = 0x14FAECu;
    // 0x14faec: 0x0  nop
    ctx->pc = 0x14faecu;
    // NOP
label_14faf0:
    // 0x14faf0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x14FAF0u;
    {
        const bool branch_taken_0x14faf0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x14faf0) {
            ctx->pc = 0x14FB00u;
            goto label_14fb00;
        }
    }
    ctx->pc = 0x14FAF8u;
    // 0x14faf8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x14FAF8u;
    {
        const bool branch_taken_0x14faf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FAFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FAF8u;
            // 0x14fafc: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14faf8) {
            ctx->pc = 0x14FB24u;
            goto label_14fb24;
        }
    }
    ctx->pc = 0x14FB00u;
label_14fb00:
    // 0x14fb00: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FB00u;
    SET_GPR_U32(ctx, 31, 0x14FB08u);
    ctx->pc = 0x14FB04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB00u;
            // 0x14fb04: 0x2b12023  subu        $a0, $s5, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB08u; }
        if (ctx->pc != 0x14FB08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB08u; }
        if (ctx->pc != 0x14FB08u) { return; }
    }
    ctx->pc = 0x14FB08u;
label_14fb08:
    // 0x14fb08: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x14fb08u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fb0c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FB0Cu;
    SET_GPR_U32(ctx, 31, 0x14FB14u);
    ctx->pc = 0x14FB10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB0Cu;
            // 0x14fb10: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB14u; }
        if (ctx->pc != 0x14FB14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB14u; }
        if (ctx->pc != 0x14FB14u) { return; }
    }
    ctx->pc = 0x14FB14u;
label_14fb14:
    // 0x14fb14: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FB14u;
    SET_GPR_U32(ctx, 31, 0x14FB1Cu);
    ctx->pc = 0x14FB18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB14u;
            // 0x14fb18: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB1Cu; }
        if (ctx->pc != 0x14FB1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB1Cu; }
        if (ctx->pc != 0x14FB1Cu) { return; }
    }
    ctx->pc = 0x14FB1Cu;
label_14fb1c:
    // 0x14fb1c: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x14fb1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x14fb20: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x14fb20u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_14fb24:
    // 0x14fb24: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x14fb24u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x14fb28: 0x26100008  addiu       $s0, $s0, 0x8
    ctx->pc = 0x14fb28u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x14fb2c: 0x2a620100  slti        $v0, $s3, 0x100
    ctx->pc = 0x14fb2cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x14fb30: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x14FB30u;
    {
        const bool branch_taken_0x14fb30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14FB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB30u;
            // 0x14fb34: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fb30) {
            ctx->pc = 0x14FAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fad8;
        }
    }
    ctx->pc = 0x14FB38u;
    // 0x14fb38: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x14FB38u;
    {
        const bool branch_taken_0x14fb38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB38u;
            // 0x14fb3c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fb38) {
            ctx->pc = 0x14FBA8u;
            goto label_14fba8;
        }
    }
    ctx->pc = 0x14FB40u;
label_14fb40:
    // 0x14fb40: 0x26f00006  addiu       $s0, $s7, 0x6
    ctx->pc = 0x14fb40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 23), 6));
    // 0x14fb44: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14fb44u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_14fb48:
    // 0x14fb48: 0x276102a  slt         $v0, $s3, $s6
    ctx->pc = 0x14fb48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x14fb4c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x14FB4Cu;
    {
        const bool branch_taken_0x14fb4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FB50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB4Cu;
            // 0x14fb50: 0x2b3102a  slt         $v0, $s5, $s3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fb4c) {
            ctx->pc = 0x14FB60u;
            goto label_14fb60;
        }
    }
    ctx->pc = 0x14FB54u;
    // 0x14fb54: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x14FB54u;
    {
        const bool branch_taken_0x14fb54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB54u;
            // 0x14fb58: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fb54) {
            ctx->pc = 0x14FB94u;
            goto label_14fb94;
        }
    }
    ctx->pc = 0x14FB5Cu;
    // 0x14fb5c: 0x0  nop
    ctx->pc = 0x14fb5cu;
    // NOP
label_14fb60:
    // 0x14fb60: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x14FB60u;
    {
        const bool branch_taken_0x14fb60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x14fb60) {
            ctx->pc = 0x14FB70u;
            goto label_14fb70;
        }
    }
    ctx->pc = 0x14FB68u;
    // 0x14fb68: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x14FB68u;
    {
        const bool branch_taken_0x14fb68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FB6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB68u;
            // 0x14fb6c: 0xa6110000  sh          $s1, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fb68) {
            ctx->pc = 0x14FB94u;
            goto label_14fb94;
        }
    }
    ctx->pc = 0x14FB70u;
label_14fb70:
    // 0x14fb70: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FB70u;
    SET_GPR_U32(ctx, 31, 0x14FB78u);
    ctx->pc = 0x14FB74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB70u;
            // 0x14fb74: 0x2762023  subu        $a0, $s3, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB78u; }
        if (ctx->pc != 0x14FB78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB78u; }
        if (ctx->pc != 0x14FB78u) { return; }
    }
    ctx->pc = 0x14FB78u;
label_14fb78:
    // 0x14fb78: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x14fb78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fb7c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FB7Cu;
    SET_GPR_U32(ctx, 31, 0x14FB84u);
    ctx->pc = 0x14FB80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB7Cu;
            // 0x14fb80: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB84u; }
        if (ctx->pc != 0x14FB84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB84u; }
        if (ctx->pc != 0x14FB84u) { return; }
    }
    ctx->pc = 0x14FB84u;
label_14fb84:
    // 0x14fb84: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FB84u;
    SET_GPR_U32(ctx, 31, 0x14FB8Cu);
    ctx->pc = 0x14FB88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB84u;
            // 0x14fb88: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB8Cu; }
        if (ctx->pc != 0x14FB8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FB8Cu; }
        if (ctx->pc != 0x14FB8Cu) { return; }
    }
    ctx->pc = 0x14FB8Cu;
label_14fb8c:
    // 0x14fb8c: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x14fb8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x14fb90: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x14fb90u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_14fb94:
    // 0x14fb94: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x14fb94u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x14fb98: 0x2a620100  slti        $v0, $s3, 0x100
    ctx->pc = 0x14fb98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x14fb9c: 0x1440ffea  bnez        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x14FB9Cu;
    {
        const bool branch_taken_0x14fb9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14FBA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FB9Cu;
            // 0x14fba0: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fb9c) {
            ctx->pc = 0x14FB48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fb48;
        }
    }
    ctx->pc = 0x14FBA4u;
    // 0x14fba4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x14fba4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_14fba8:
    // 0x14fba8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x14fba8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x14fbac: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x14fbacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14fbb0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x14fbb0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x14fbb4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x14fbb4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14fbb8: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x14fbb8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x14fbbc: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x14fbbcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14fbc0: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x14fbc0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x14fbc4: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x14fbc4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14fbc8: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x14fbc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x14fbcc: 0x3e00008  jr          $ra
    ctx->pc = 0x14FBCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14FBD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FBCCu;
            // 0x14fbd0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14F94Cu: goto label_14f94c;
            case 0x14F968u: goto label_14f968;
            case 0x14F974u: goto label_14f974;
            case 0x14F994u: goto label_14f994;
            case 0x14F9A4u: goto label_14f9a4;
            case 0x14F9B0u: goto label_14f9b0;
            case 0x14F9D0u: goto label_14f9d0;
            case 0x14F9E4u: goto label_14f9e4;
            case 0x14F9F0u: goto label_14f9f0;
            case 0x14F9F8u: goto label_14f9f8;
            case 0x14FA0Cu: goto label_14fa0c;
            case 0x14FA18u: goto label_14fa18;
            case 0x14FA20u: goto label_14fa20;
            case 0x14FA40u: goto label_14fa40;
            case 0x14FA4Cu: goto label_14fa4c;
            case 0x14FA54u: goto label_14fa54;
            case 0x14FA68u: goto label_14fa68;
            case 0x14FA74u: goto label_14fa74;
            case 0x14FA7Cu: goto label_14fa7c;
            case 0x14FA98u: goto label_14fa98;
            case 0x14FAA4u: goto label_14faa4;
            case 0x14FAB0u: goto label_14fab0;
            case 0x14FAD8u: goto label_14fad8;
            case 0x14FAF0u: goto label_14faf0;
            case 0x14FB00u: goto label_14fb00;
            case 0x14FB08u: goto label_14fb08;
            case 0x14FB14u: goto label_14fb14;
            case 0x14FB1Cu: goto label_14fb1c;
            case 0x14FB24u: goto label_14fb24;
            case 0x14FB40u: goto label_14fb40;
            case 0x14FB48u: goto label_14fb48;
            case 0x14FB60u: goto label_14fb60;
            case 0x14FB70u: goto label_14fb70;
            case 0x14FB78u: goto label_14fb78;
            case 0x14FB84u: goto label_14fb84;
            case 0x14FB8Cu: goto label_14fb8c;
            case 0x14FB94u: goto label_14fb94;
            case 0x14FBA8u: goto label_14fba8;
            case 0x14FC18u: goto label_14fc18;
            case 0x14FC28u: goto label_14fc28;
            case 0x14FC34u: goto label_14fc34;
            case 0x14FC50u: goto label_14fc50;
            case 0x14FC60u: goto label_14fc60;
            case 0x14FC6Cu: goto label_14fc6c;
            case 0x14FC80u: goto label_14fc80;
            case 0x14FC8Cu: goto label_14fc8c;
            case 0x14FC94u: goto label_14fc94;
            case 0x14FCB4u: goto label_14fcb4;
            case 0x14FCC0u: goto label_14fcc0;
            case 0x14FCC8u: goto label_14fcc8;
            case 0x14FCDCu: goto label_14fcdc;
            case 0x14FCE8u: goto label_14fce8;
            case 0x14FCF0u: goto label_14fcf0;
            case 0x14FD08u: goto label_14fd08;
            case 0x14FD38u: goto label_14fd38;
            case 0x14FD48u: goto label_14fd48;
            case 0x14FD58u: goto label_14fd58;
            case 0x14FD68u: goto label_14fd68;
            case 0x14FD78u: goto label_14fd78;
            case 0x14FD80u: goto label_14fd80;
            case 0x14FDB8u: goto label_14fdb8;
            case 0x14FDE8u: goto label_14fde8;
            case 0x14FDF8u: goto label_14fdf8;
            case 0x14FE0Cu: goto label_14fe0c;
            case 0x14FE1Cu: goto label_14fe1c;
            case 0x14FE2Cu: goto label_14fe2c;
            case 0x14FE34u: goto label_14fe34;
            case 0x14FEA8u: goto label_14fea8;
            case 0x14FF08u: goto label_14ff08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FBD4u;
    // 0x14fbd4: 0x0  nop
    ctx->pc = 0x14fbd4u;
    // NOP
    // 0x14fbd8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x14fbd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x14fbdc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x14fbdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x14fbe0: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14fbe0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fbe4: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x14fbe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x14fbe8: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x14fbe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x14fbec: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x14fbecu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fbf0: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x14fbf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x14fbf4: 0x26b61000  addiu       $s6, $s5, 0x1000
    ctx->pc = 0x14fbf4u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 21), 4096));
    // 0x14fbf8: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x14fbf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x14fbfc: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x14fbfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x14fc00: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x14fc00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14fc04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x14fc04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x14fc08: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x14fc08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x14fc0c: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x14fc0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x14fc10: 0xc052490  jal         func_149240
    ctx->pc = 0x14FC10u;
    SET_GPR_U32(ctx, 31, 0x14FC18u);
    ctx->pc = 0x14FC14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC10u;
            // 0x14fc14: 0x26b70800  addiu       $s7, $s5, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 21), 2048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149240u;
    if (runtime->hasFunction(0x149240u)) {
        auto targetFn = runtime->lookupFunction(0x149240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC18u; }
        if (ctx->pc != 0x14FC18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149240_0x149240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC18u; }
        if (ctx->pc != 0x14FC18u) { return; }
    }
    ctx->pc = 0x14FC18u;
label_14fc18:
    // 0x14fc18: 0x3414ff80  ori         $s4, $zero, 0xFF80
    ctx->pc = 0x14fc18u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x14fc1c: 0x14a3bc  dsll32      $s4, $s4, 14
    ctx->pc = 0x14fc1cu;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) << (32 + 14));
    // 0x14fc20: 0x40f02d  daddu       $fp, $v0, $zero
    ctx->pc = 0x14fc20u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc24: 0x0  nop
    ctx->pc = 0x14fc24u;
    // NOP
label_14fc28:
    // 0x14fc28: 0x2664ff80  addiu       $a0, $s3, -0x80
    ctx->pc = 0x14fc28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967168));
    // 0x14fc2c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FC2Cu;
    SET_GPR_U32(ctx, 31, 0x14FC34u);
    ctx->pc = 0x14FC30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC2Cu;
            // 0x14fc30: 0x1388c0  sll         $s1, $s3, 3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC34u; }
        if (ctx->pc != 0x14FC34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC34u; }
        if (ctx->pc != 0x14FC34u) { return; }
    }
    ctx->pc = 0x14FC34u;
label_14fc34:
    // 0x14fc34: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fc34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fc38: 0xdc25e2d8  ld          $a1, -0x1D28($at)
    ctx->pc = 0x14fc38u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959832)));
    // 0x14fc3c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x14fc3cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc40: 0x2378021  addu        $s0, $s1, $s7
    ctx->pc = 0x14fc40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 23)));
    // 0x14fc44: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14fc44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc48: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FC48u;
    SET_GPR_U32(ctx, 31, 0x14FC50u);
    ctx->pc = 0x14FC4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC48u;
            // 0x14fc4c: 0x2368821  addu        $s1, $s1, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC50u; }
        if (ctx->pc != 0x14FC50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC50u; }
        if (ctx->pc != 0x14FC50u) { return; }
    }
    ctx->pc = 0x14FC50u;
label_14fc50:
    // 0x14fc50: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fc50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc54: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x14fc54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc58: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FC58u;
    SET_GPR_U32(ctx, 31, 0x14FC60u);
    ctx->pc = 0x14FC5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC58u;
            // 0x14fc5c: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC60u; }
        if (ctx->pc != 0x14FC60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC60u; }
        if (ctx->pc != 0x14FC60u) { return; }
    }
    ctx->pc = 0x14FC60u;
label_14fc60:
    // 0x14fc60: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x14fc60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc64: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FC64u;
    SET_GPR_U32(ctx, 31, 0x14FC6Cu);
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC6Cu; }
        if (ctx->pc != 0x14FC6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC6Cu; }
        if (ctx->pc != 0x14FC6Cu) { return; }
    }
    ctx->pc = 0x14FC6Cu;
label_14fc6c:
    // 0x14fc6c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14fc6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc70: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fc70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fc74: 0xdc25e2e0  ld          $a1, -0x1D20($at)
    ctx->pc = 0x14fc74u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959840)));
    // 0x14fc78: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FC78u;
    SET_GPR_U32(ctx, 31, 0x14FC80u);
    ctx->pc = 0x14FC7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC78u;
            // 0x14fc7c: 0xa6020004  sh          $v0, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC80u; }
        if (ctx->pc != 0x14FC80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC80u; }
        if (ctx->pc != 0x14FC80u) { return; }
    }
    ctx->pc = 0x14FC80u;
label_14fc80:
    // 0x14fc80: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fc80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fc84: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FC84u;
    SET_GPR_U32(ctx, 31, 0x14FC8Cu);
    ctx->pc = 0x14FC88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC84u;
            // 0x14fc88: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC8Cu; }
        if (ctx->pc != 0x14FC8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC8Cu; }
        if (ctx->pc != 0x14FC8Cu) { return; }
    }
    ctx->pc = 0x14FC8Cu;
label_14fc8c:
    // 0x14fc8c: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FC8Cu;
    SET_GPR_U32(ctx, 31, 0x14FC94u);
    ctx->pc = 0x14FC90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FC8Cu;
            // 0x14fc90: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC94u; }
        if (ctx->pc != 0x14FC94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FC94u; }
        if (ctx->pc != 0x14FC94u) { return; }
    }
    ctx->pc = 0x14FC94u;
label_14fc94:
    // 0x14fc94: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x14fc94u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fc98: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x14fc98u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fc9c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14fc9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fca0: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x14fca0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fca4: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fca4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fca8: 0xdc25e2e8  ld          $a1, -0x1D18($at)
    ctx->pc = 0x14fca8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959848)));
    // 0x14fcac: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FCACu;
    SET_GPR_U32(ctx, 31, 0x14FCB4u);
    ctx->pc = 0x14FCB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCACu;
            // 0x14fcb0: 0xa6200004  sh          $zero, 0x4($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCB4u; }
        if (ctx->pc != 0x14FCB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCB4u; }
        if (ctx->pc != 0x14FCB4u) { return; }
    }
    ctx->pc = 0x14FCB4u;
label_14fcb4:
    // 0x14fcb4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fcb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fcb8: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FCB8u;
    SET_GPR_U32(ctx, 31, 0x14FCC0u);
    ctx->pc = 0x14FCBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCB8u;
            // 0x14fcbc: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCC0u; }
        if (ctx->pc != 0x14FCC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCC0u; }
        if (ctx->pc != 0x14FCC0u) { return; }
    }
    ctx->pc = 0x14FCC0u;
label_14fcc0:
    // 0x14fcc0: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FCC0u;
    SET_GPR_U32(ctx, 31, 0x14FCC8u);
    ctx->pc = 0x14FCC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCC0u;
            // 0x14fcc4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCC8u; }
        if (ctx->pc != 0x14FCC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCC8u; }
        if (ctx->pc != 0x14FCC8u) { return; }
    }
    ctx->pc = 0x14FCC8u;
label_14fcc8:
    // 0x14fcc8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x14fcc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fccc: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fcccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fcd0: 0xdc25e2f0  ld          $a1, -0x1D10($at)
    ctx->pc = 0x14fcd0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959856)));
    // 0x14fcd4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FCD4u;
    SET_GPR_U32(ctx, 31, 0x14FCDCu);
    ctx->pc = 0x14FCD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCD4u;
            // 0x14fcd8: 0xa6220002  sh          $v0, 0x2($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCDCu; }
        if (ctx->pc != 0x14FCDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCDCu; }
        if (ctx->pc != 0x14FCDCu) { return; }
    }
    ctx->pc = 0x14FCDCu;
label_14fcdc:
    // 0x14fcdc: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x14fcdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fce0: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FCE0u;
    SET_GPR_U32(ctx, 31, 0x14FCE8u);
    ctx->pc = 0x14FCE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCE0u;
            // 0x14fce4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCE8u; }
        if (ctx->pc != 0x14FCE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCE8u; }
        if (ctx->pc != 0x14FCE8u) { return; }
    }
    ctx->pc = 0x14FCE8u;
label_14fce8:
    // 0x14fce8: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FCE8u;
    SET_GPR_U32(ctx, 31, 0x14FCF0u);
    ctx->pc = 0x14FCECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCE8u;
            // 0x14fcec: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCF0u; }
        if (ctx->pc != 0x14FCF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FCF0u; }
        if (ctx->pc != 0x14FCF0u) { return; }
    }
    ctx->pc = 0x14FCF0u;
label_14fcf0:
    // 0x14fcf0: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x14fcf0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fcf4: 0x2a630100  slti        $v1, $s3, 0x100
    ctx->pc = 0x14fcf4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x14fcf8: 0x1460ffcb  bnez        $v1, . + 4 + (-0x35 << 2)
    ctx->pc = 0x14FCF8u;
    {
        const bool branch_taken_0x14fcf8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x14FCFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FCF8u;
            // 0x14fcfc: 0xa6220000  sh          $v0, 0x0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fcf8) {
            ctx->pc = 0x14FC28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fc28;
        }
    }
    ctx->pc = 0x14FD00u;
    // 0x14fd00: 0x2a0102d  daddu       $v0, $s5, $zero
    ctx->pc = 0x14fd00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fd04: 0x2413000f  addiu       $s3, $zero, 0xF
    ctx->pc = 0x14fd04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_14fd08:
    // 0x14fd08: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x14fd08u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x14fd0c: 0xa4400004  sh          $zero, 0x4($v0)
    ctx->pc = 0x14fd0cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fd10: 0xa4400002  sh          $zero, 0x2($v0)
    ctx->pc = 0x14fd10u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 2), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fd14: 0xa4400000  sh          $zero, 0x0($v0)
    ctx->pc = 0x14fd14u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fd18: 0xa4400006  sh          $zero, 0x6($v0)
    ctx->pc = 0x14fd18u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x14fd1c: 0x661fffa  bgez        $s3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x14FD1Cu;
    {
        const bool branch_taken_0x14fd1c = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x14FD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD1Cu;
            // 0x14fd20: 0x24420008  addiu       $v0, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fd1c) {
            ctx->pc = 0x14FD08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fd08;
        }
    }
    ctx->pc = 0x14FD24u;
    // 0x14fd24: 0x1ea140  sll         $s4, $fp, 5
    ctx->pc = 0x14fd24u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 30), 5));
    // 0x14fd28: 0x24120070  addiu       $s2, $zero, 0x70
    ctx->pc = 0x14fd28u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 112));
    // 0x14fd2c: 0x26b00080  addiu       $s0, $s5, 0x80
    ctx->pc = 0x14fd2cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 128));
    // 0x14fd30: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x14fd30u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fd34: 0x2413006f  addiu       $s3, $zero, 0x6F
    ctx->pc = 0x14fd34u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 111));
label_14fd38:
    // 0x14fd38: 0x232001a  div         $zero, $s1, $s2
    ctx->pc = 0x14fd38u;
    { int32_t divisor = GPR_S32(ctx, 18);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x14fd3c: 0x26310100  addiu       $s1, $s1, 0x100
    ctx->pc = 0x14fd3cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 256));
    // 0x14fd40: 0x52400001  beql        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x14FD40u;
    {
        const bool branch_taken_0x14fd40 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x14fd40) {
            ctx->pc = 0x14FD44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD40u;
            // 0x14fd44: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x14FD48u;
            goto label_14fd48;
        }
    }
    ctx->pc = 0x14FD48u;
label_14fd48:
    // 0x14fd48: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x14fd48u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x14fd4c: 0x2012  mflo        $a0
    ctx->pc = 0x14fd4cu;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x14fd50: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FD50u;
    SET_GPR_U32(ctx, 31, 0x14FD58u);
    ctx->pc = 0x14FD54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD50u;
            // 0x14fd54: 0x2484fff0  addiu       $a0, $a0, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD58u; }
        if (ctx->pc != 0x14FD58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD58u; }
        if (ctx->pc != 0x14FD58u) { return; }
    }
    ctx->pc = 0x14FD58u;
label_14fd58:
    // 0x14fd58: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fd58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fd5c: 0xdc25e2f8  ld          $a1, -0x1D08($at)
    ctx->pc = 0x14fd5cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959864)));
    // 0x14fd60: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FD60u;
    SET_GPR_U32(ctx, 31, 0x14FD68u);
    ctx->pc = 0x14FD64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD60u;
            // 0x14fd64: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD68u; }
        if (ctx->pc != 0x14FD68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD68u; }
        if (ctx->pc != 0x14FD68u) { return; }
    }
    ctx->pc = 0x14FD68u;
label_14fd68:
    // 0x14fd68: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x14fd68u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x14fd6c: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x14fd6cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x14fd70: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FD70u;
    SET_GPR_U32(ctx, 31, 0x14FD78u);
    ctx->pc = 0x14FD74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD70u;
            // 0x14fd74: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD78u; }
        if (ctx->pc != 0x14FD78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD78u; }
        if (ctx->pc != 0x14FD78u) { return; }
    }
    ctx->pc = 0x14FD78u;
label_14fd78:
    // 0x14fd78: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FD78u;
    SET_GPR_U32(ctx, 31, 0x14FD80u);
    ctx->pc = 0x14FD7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD78u;
            // 0x14fd7c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD80u; }
        if (ctx->pc != 0x14FD80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FD80u; }
        if (ctx->pc != 0x14FD80u) { return; }
    }
    ctx->pc = 0x14FD80u;
label_14fd80:
    // 0x14fd80: 0xa6140006  sh          $s4, 0x6($s0)
    ctx->pc = 0x14fd80u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 20));
    // 0x14fd84: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x14fd84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x14fd88: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x14fd88u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x14fd8c: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x14fd8cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fd90: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x14fd90u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fd94: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x14fd94u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fd98: 0x661ffe7  bgez        $s3, . + 4 + (-0x19 << 2)
    ctx->pc = 0x14FD98u;
    {
        const bool branch_taken_0x14fd98 = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x14FD9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FD98u;
            // 0x14fd9c: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fd98) {
            ctx->pc = 0x14FD38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fd38;
        }
    }
    ctx->pc = 0x14FDA0u;
    // 0x14fda0: 0x1ea180  sll         $s4, $fp, 6
    ctx->pc = 0x14fda0u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 30), 6));
    // 0x14fda4: 0x2402458d  addiu       $v0, $zero, 0x458D
    ctx->pc = 0x14fda4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17805));
    // 0x14fda8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x14fda8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fdac: 0x26a30400  addiu       $v1, $s5, 0x400
    ctx->pc = 0x14fdacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 1024));
    // 0x14fdb0: 0x2413000f  addiu       $s3, $zero, 0xF
    ctx->pc = 0x14fdb0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x14fdb4: 0x0  nop
    ctx->pc = 0x14fdb4u;
    // NOP
label_14fdb8:
    // 0x14fdb8: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x14fdb8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x14fdbc: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x14fdbcu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fdc0: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x14fdc0u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fdc4: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x14fdc4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fdc8: 0xa4640006  sh          $a0, 0x6($v1)
    ctx->pc = 0x14fdc8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 6), (uint16_t)GPR_U32(ctx, 4));
    // 0x14fdcc: 0x661fffa  bgez        $s3, . + 4 + (-0x6 << 2)
    ctx->pc = 0x14FDCCu;
    {
        const bool branch_taken_0x14fdcc = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x14FDD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FDCCu;
            // 0x14fdd0: 0x24630008  addiu       $v1, $v1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fdcc) {
            ctx->pc = 0x14FDB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fdb8;
        }
    }
    ctx->pc = 0x14FDD4u;
    // 0x14fdd4: 0x26b00480  addiu       $s0, $s5, 0x480
    ctx->pc = 0x14fdd4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 1152));
    // 0x14fdd8: 0x241500ff  addiu       $s5, $zero, 0xFF
    ctx->pc = 0x14fdd8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x14fddc: 0x24120070  addiu       $s2, $zero, 0x70
    ctx->pc = 0x14fddcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 112));
    // 0x14fde0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x14fde0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14fde4: 0x2413006f  addiu       $s3, $zero, 0x6F
    ctx->pc = 0x14fde4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 111));
label_14fde8:
    // 0x14fde8: 0x232001a  div         $zero, $s1, $s2
    ctx->pc = 0x14fde8u;
    { int32_t divisor = GPR_S32(ctx, 18);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x14fdec: 0x26310100  addiu       $s1, $s1, 0x100
    ctx->pc = 0x14fdecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 256));
    // 0x14fdf0: 0x52400001  beql        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x14FDF0u;
    {
        const bool branch_taken_0x14fdf0 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x14fdf0) {
            ctx->pc = 0x14FDF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14FDF0u;
            // 0x14fdf4: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x14FDF8u;
            goto label_14fdf8;
        }
    }
    ctx->pc = 0x14FDF8u;
label_14fdf8:
    // 0x14fdf8: 0x2673ffff  addiu       $s3, $s3, -0x1
    ctx->pc = 0x14fdf8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x14fdfc: 0x2012  mflo        $a0
    ctx->pc = 0x14fdfcu;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x14fe00: 0x2a42023  subu        $a0, $s5, $a0
    ctx->pc = 0x14fe00u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 4)));
    // 0x14fe04: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x14FE04u;
    SET_GPR_U32(ctx, 31, 0x14FE0Cu);
    ctx->pc = 0x14FE08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE04u;
            // 0x14fe08: 0x2484fff0  addiu       $a0, $a0, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE0Cu; }
        if (ctx->pc != 0x14FE0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE0Cu; }
        if (ctx->pc != 0x14FE0Cu) { return; }
    }
    ctx->pc = 0x14FE0Cu;
label_14fe0c:
    // 0x14fe0c: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x14fe0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x14fe10: 0xdc25e300  ld          $a1, -0x1D00($at)
    ctx->pc = 0x14fe10u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 4294959872)));
    // 0x14fe14: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x14FE14u;
    SET_GPR_U32(ctx, 31, 0x14FE1Cu);
    ctx->pc = 0x14FE18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE14u;
            // 0x14fe18: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE1Cu; }
        if (ctx->pc != 0x14FE1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE1Cu; }
        if (ctx->pc != 0x14FE1Cu) { return; }
    }
    ctx->pc = 0x14FE1Cu;
label_14fe1c:
    // 0x14fe1c: 0x3405ff80  ori         $a1, $zero, 0xFF80
    ctx->pc = 0x14fe1cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x14fe20: 0x52bbc  dsll32      $a1, $a1, 14
    ctx->pc = 0x14fe20u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x14fe24: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x14FE24u;
    SET_GPR_U32(ctx, 31, 0x14FE2Cu);
    ctx->pc = 0x14FE28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE24u;
            // 0x14fe28: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE2Cu; }
        if (ctx->pc != 0x14FE2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE2Cu; }
        if (ctx->pc != 0x14FE2Cu) { return; }
    }
    ctx->pc = 0x14FE2Cu;
label_14fe2c:
    // 0x14fe2c: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x14FE2Cu;
    SET_GPR_U32(ctx, 31, 0x14FE34u);
    ctx->pc = 0x14FE30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE2Cu;
            // 0x14fe30: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE34u; }
        if (ctx->pc != 0x14FE34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14FE34u; }
        if (ctx->pc != 0x14FE34u) { return; }
    }
    ctx->pc = 0x14FE34u;
label_14fe34:
    // 0x14fe34: 0xa6140006  sh          $s4, 0x6($s0)
    ctx->pc = 0x14fe34u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 20));
    // 0x14fe38: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x14fe38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x14fe3c: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x14fe3cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x14fe40: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x14fe40u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fe44: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x14fe44u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fe48: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x14fe48u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x14fe4c: 0x661ffe6  bgez        $s3, . + 4 + (-0x1A << 2)
    ctx->pc = 0x14FE4Cu;
    {
        const bool branch_taken_0x14fe4c = (GPR_S64(ctx, 19) >= 0);
        ctx->pc = 0x14FE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE4Cu;
            // 0x14fe50: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fe4c) {
            ctx->pc = 0x14FDE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fde8;
        }
    }
    ctx->pc = 0x14FE54u;
    // 0x14fe54: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14fe54u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14fe58: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x14fe58u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14fe5c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x14fe5cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14fe60: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x14fe60u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x14fe64: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x14fe64u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14fe68: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x14fe68u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x14fe6c: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x14fe6cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14fe70: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x14fe70u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x14fe74: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x14fe74u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14fe78: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x14fe78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x14fe7c: 0x3e00008  jr          $ra
    ctx->pc = 0x14FE7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14FE80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FE7Cu;
            // 0x14fe80: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14F94Cu: goto label_14f94c;
            case 0x14F968u: goto label_14f968;
            case 0x14F974u: goto label_14f974;
            case 0x14F994u: goto label_14f994;
            case 0x14F9A4u: goto label_14f9a4;
            case 0x14F9B0u: goto label_14f9b0;
            case 0x14F9D0u: goto label_14f9d0;
            case 0x14F9E4u: goto label_14f9e4;
            case 0x14F9F0u: goto label_14f9f0;
            case 0x14F9F8u: goto label_14f9f8;
            case 0x14FA0Cu: goto label_14fa0c;
            case 0x14FA18u: goto label_14fa18;
            case 0x14FA20u: goto label_14fa20;
            case 0x14FA40u: goto label_14fa40;
            case 0x14FA4Cu: goto label_14fa4c;
            case 0x14FA54u: goto label_14fa54;
            case 0x14FA68u: goto label_14fa68;
            case 0x14FA74u: goto label_14fa74;
            case 0x14FA7Cu: goto label_14fa7c;
            case 0x14FA98u: goto label_14fa98;
            case 0x14FAA4u: goto label_14faa4;
            case 0x14FAB0u: goto label_14fab0;
            case 0x14FAD8u: goto label_14fad8;
            case 0x14FAF0u: goto label_14faf0;
            case 0x14FB00u: goto label_14fb00;
            case 0x14FB08u: goto label_14fb08;
            case 0x14FB14u: goto label_14fb14;
            case 0x14FB1Cu: goto label_14fb1c;
            case 0x14FB24u: goto label_14fb24;
            case 0x14FB40u: goto label_14fb40;
            case 0x14FB48u: goto label_14fb48;
            case 0x14FB60u: goto label_14fb60;
            case 0x14FB70u: goto label_14fb70;
            case 0x14FB78u: goto label_14fb78;
            case 0x14FB84u: goto label_14fb84;
            case 0x14FB8Cu: goto label_14fb8c;
            case 0x14FB94u: goto label_14fb94;
            case 0x14FBA8u: goto label_14fba8;
            case 0x14FC18u: goto label_14fc18;
            case 0x14FC28u: goto label_14fc28;
            case 0x14FC34u: goto label_14fc34;
            case 0x14FC50u: goto label_14fc50;
            case 0x14FC60u: goto label_14fc60;
            case 0x14FC6Cu: goto label_14fc6c;
            case 0x14FC80u: goto label_14fc80;
            case 0x14FC8Cu: goto label_14fc8c;
            case 0x14FC94u: goto label_14fc94;
            case 0x14FCB4u: goto label_14fcb4;
            case 0x14FCC0u: goto label_14fcc0;
            case 0x14FCC8u: goto label_14fcc8;
            case 0x14FCDCu: goto label_14fcdc;
            case 0x14FCE8u: goto label_14fce8;
            case 0x14FCF0u: goto label_14fcf0;
            case 0x14FD08u: goto label_14fd08;
            case 0x14FD38u: goto label_14fd38;
            case 0x14FD48u: goto label_14fd48;
            case 0x14FD58u: goto label_14fd58;
            case 0x14FD68u: goto label_14fd68;
            case 0x14FD78u: goto label_14fd78;
            case 0x14FD80u: goto label_14fd80;
            case 0x14FDB8u: goto label_14fdb8;
            case 0x14FDE8u: goto label_14fde8;
            case 0x14FDF8u: goto label_14fdf8;
            case 0x14FE0Cu: goto label_14fe0c;
            case 0x14FE1Cu: goto label_14fe1c;
            case 0x14FE2Cu: goto label_14fe2c;
            case 0x14FE34u: goto label_14fe34;
            case 0x14FEA8u: goto label_14fea8;
            case 0x14FF08u: goto label_14ff08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FE84u;
    // 0x14fe84: 0x0  nop
    ctx->pc = 0x14fe84u;
    // NOP
    // 0x14fe88: 0x3e00008  jr          $ra
    ctx->pc = 0x14FE88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14F94Cu: goto label_14f94c;
            case 0x14F968u: goto label_14f968;
            case 0x14F974u: goto label_14f974;
            case 0x14F994u: goto label_14f994;
            case 0x14F9A4u: goto label_14f9a4;
            case 0x14F9B0u: goto label_14f9b0;
            case 0x14F9D0u: goto label_14f9d0;
            case 0x14F9E4u: goto label_14f9e4;
            case 0x14F9F0u: goto label_14f9f0;
            case 0x14F9F8u: goto label_14f9f8;
            case 0x14FA0Cu: goto label_14fa0c;
            case 0x14FA18u: goto label_14fa18;
            case 0x14FA20u: goto label_14fa20;
            case 0x14FA40u: goto label_14fa40;
            case 0x14FA4Cu: goto label_14fa4c;
            case 0x14FA54u: goto label_14fa54;
            case 0x14FA68u: goto label_14fa68;
            case 0x14FA74u: goto label_14fa74;
            case 0x14FA7Cu: goto label_14fa7c;
            case 0x14FA98u: goto label_14fa98;
            case 0x14FAA4u: goto label_14faa4;
            case 0x14FAB0u: goto label_14fab0;
            case 0x14FAD8u: goto label_14fad8;
            case 0x14FAF0u: goto label_14faf0;
            case 0x14FB00u: goto label_14fb00;
            case 0x14FB08u: goto label_14fb08;
            case 0x14FB14u: goto label_14fb14;
            case 0x14FB1Cu: goto label_14fb1c;
            case 0x14FB24u: goto label_14fb24;
            case 0x14FB40u: goto label_14fb40;
            case 0x14FB48u: goto label_14fb48;
            case 0x14FB60u: goto label_14fb60;
            case 0x14FB70u: goto label_14fb70;
            case 0x14FB78u: goto label_14fb78;
            case 0x14FB84u: goto label_14fb84;
            case 0x14FB8Cu: goto label_14fb8c;
            case 0x14FB94u: goto label_14fb94;
            case 0x14FBA8u: goto label_14fba8;
            case 0x14FC18u: goto label_14fc18;
            case 0x14FC28u: goto label_14fc28;
            case 0x14FC34u: goto label_14fc34;
            case 0x14FC50u: goto label_14fc50;
            case 0x14FC60u: goto label_14fc60;
            case 0x14FC6Cu: goto label_14fc6c;
            case 0x14FC80u: goto label_14fc80;
            case 0x14FC8Cu: goto label_14fc8c;
            case 0x14FC94u: goto label_14fc94;
            case 0x14FCB4u: goto label_14fcb4;
            case 0x14FCC0u: goto label_14fcc0;
            case 0x14FCC8u: goto label_14fcc8;
            case 0x14FCDCu: goto label_14fcdc;
            case 0x14FCE8u: goto label_14fce8;
            case 0x14FCF0u: goto label_14fcf0;
            case 0x14FD08u: goto label_14fd08;
            case 0x14FD38u: goto label_14fd38;
            case 0x14FD48u: goto label_14fd48;
            case 0x14FD58u: goto label_14fd58;
            case 0x14FD68u: goto label_14fd68;
            case 0x14FD78u: goto label_14fd78;
            case 0x14FD80u: goto label_14fd80;
            case 0x14FDB8u: goto label_14fdb8;
            case 0x14FDE8u: goto label_14fde8;
            case 0x14FDF8u: goto label_14fdf8;
            case 0x14FE0Cu: goto label_14fe0c;
            case 0x14FE1Cu: goto label_14fe1c;
            case 0x14FE2Cu: goto label_14fe2c;
            case 0x14FE34u: goto label_14fe34;
            case 0x14FEA8u: goto label_14fea8;
            case 0x14FF08u: goto label_14ff08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FE90u;
    // 0x14fe90: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x14fe90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x14fe94: 0x2463c008  addiu       $v1, $v1, -0x3FF8
    ctx->pc = 0x14fe94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294950920));
    // 0x14fe98: 0x831025  or          $v0, $a0, $v1
    ctx->pc = 0x14fe98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x14fe9c: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x14fe9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x14fea0: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x14FEA0u;
    {
        const bool branch_taken_0x14fea0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FEA0u;
            // 0x14fea4: 0x24621800  addiu       $v0, $v1, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 6144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fea0) {
            ctx->pc = 0x14FF08u;
            goto label_14ff08;
        }
    }
    ctx->pc = 0x14FEA8u;
label_14fea8:
    // 0x14fea8: 0x68650007  ldl         $a1, 0x7($v1)
    ctx->pc = 0x14fea8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x14feac: 0x6c650000  ldr         $a1, 0x0($v1)
    ctx->pc = 0x14feacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x14feb0: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x14feb0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x14feb4: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x14feb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x14feb8: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x14feb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x14febc: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x14febcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x14fec0: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x14fec0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x14fec4: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x14fec4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x14fec8: 0xb0850007  sdl         $a1, 0x7($a0)
    ctx->pc = 0x14fec8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fecc: 0xb4850000  sdr         $a1, 0x0($a0)
    ctx->pc = 0x14feccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fed0: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x14fed0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fed4: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x14fed4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fed8: 0xb0870017  sdl         $a3, 0x17($a0)
    ctx->pc = 0x14fed8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fedc: 0xb4870010  sdr         $a3, 0x10($a0)
    ctx->pc = 0x14fedcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fee0: 0xb088001f  sdl         $t0, 0x1F($a0)
    ctx->pc = 0x14fee0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fee4: 0xb4880018  sdr         $t0, 0x18($a0)
    ctx->pc = 0x14fee4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fee8: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x14fee8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x14feec: 0x0  nop
    ctx->pc = 0x14feecu;
    // NOP
    // 0x14fef0: 0x0  nop
    ctx->pc = 0x14fef0u;
    // NOP
    // 0x14fef4: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x14FEF4u;
    {
        const bool branch_taken_0x14fef4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x14FEF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FEF4u;
            // 0x14fef8: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fef4) {
            ctx->pc = 0x14FEA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fea8;
        }
    }
    ctx->pc = 0x14FEFCu;
    // 0x14fefc: 0x3e00008  jr          $ra
    ctx->pc = 0x14FEFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14F94Cu: goto label_14f94c;
            case 0x14F968u: goto label_14f968;
            case 0x14F974u: goto label_14f974;
            case 0x14F994u: goto label_14f994;
            case 0x14F9A4u: goto label_14f9a4;
            case 0x14F9B0u: goto label_14f9b0;
            case 0x14F9D0u: goto label_14f9d0;
            case 0x14F9E4u: goto label_14f9e4;
            case 0x14F9F0u: goto label_14f9f0;
            case 0x14F9F8u: goto label_14f9f8;
            case 0x14FA0Cu: goto label_14fa0c;
            case 0x14FA18u: goto label_14fa18;
            case 0x14FA20u: goto label_14fa20;
            case 0x14FA40u: goto label_14fa40;
            case 0x14FA4Cu: goto label_14fa4c;
            case 0x14FA54u: goto label_14fa54;
            case 0x14FA68u: goto label_14fa68;
            case 0x14FA74u: goto label_14fa74;
            case 0x14FA7Cu: goto label_14fa7c;
            case 0x14FA98u: goto label_14fa98;
            case 0x14FAA4u: goto label_14faa4;
            case 0x14FAB0u: goto label_14fab0;
            case 0x14FAD8u: goto label_14fad8;
            case 0x14FAF0u: goto label_14faf0;
            case 0x14FB00u: goto label_14fb00;
            case 0x14FB08u: goto label_14fb08;
            case 0x14FB14u: goto label_14fb14;
            case 0x14FB1Cu: goto label_14fb1c;
            case 0x14FB24u: goto label_14fb24;
            case 0x14FB40u: goto label_14fb40;
            case 0x14FB48u: goto label_14fb48;
            case 0x14FB60u: goto label_14fb60;
            case 0x14FB70u: goto label_14fb70;
            case 0x14FB78u: goto label_14fb78;
            case 0x14FB84u: goto label_14fb84;
            case 0x14FB8Cu: goto label_14fb8c;
            case 0x14FB94u: goto label_14fb94;
            case 0x14FBA8u: goto label_14fba8;
            case 0x14FC18u: goto label_14fc18;
            case 0x14FC28u: goto label_14fc28;
            case 0x14FC34u: goto label_14fc34;
            case 0x14FC50u: goto label_14fc50;
            case 0x14FC60u: goto label_14fc60;
            case 0x14FC6Cu: goto label_14fc6c;
            case 0x14FC80u: goto label_14fc80;
            case 0x14FC8Cu: goto label_14fc8c;
            case 0x14FC94u: goto label_14fc94;
            case 0x14FCB4u: goto label_14fcb4;
            case 0x14FCC0u: goto label_14fcc0;
            case 0x14FCC8u: goto label_14fcc8;
            case 0x14FCDCu: goto label_14fcdc;
            case 0x14FCE8u: goto label_14fce8;
            case 0x14FCF0u: goto label_14fcf0;
            case 0x14FD08u: goto label_14fd08;
            case 0x14FD38u: goto label_14fd38;
            case 0x14FD48u: goto label_14fd48;
            case 0x14FD58u: goto label_14fd58;
            case 0x14FD68u: goto label_14fd68;
            case 0x14FD78u: goto label_14fd78;
            case 0x14FD80u: goto label_14fd80;
            case 0x14FDB8u: goto label_14fdb8;
            case 0x14FDE8u: goto label_14fde8;
            case 0x14FDF8u: goto label_14fdf8;
            case 0x14FE0Cu: goto label_14fe0c;
            case 0x14FE1Cu: goto label_14fe1c;
            case 0x14FE2Cu: goto label_14fe2c;
            case 0x14FE34u: goto label_14fe34;
            case 0x14FEA8u: goto label_14fea8;
            case 0x14FF08u: goto label_14ff08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FF04u;
    // 0x14ff04: 0x0  nop
    ctx->pc = 0x14ff04u;
    // NOP
label_14ff08:
    // 0x14ff08: 0xdc650000  ld          $a1, 0x0($v1)
    ctx->pc = 0x14ff08u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ff0c: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x14ff0cu;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x14ff10: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x14ff10u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x14ff14: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x14ff14u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x14ff18: 0xfc850000  sd          $a1, 0x0($a0)
    ctx->pc = 0x14ff18u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 5));
    // 0x14ff1c: 0xfc860008  sd          $a2, 0x8($a0)
    ctx->pc = 0x14ff1cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 6));
    // 0x14ff20: 0xfc870010  sd          $a3, 0x10($a0)
    ctx->pc = 0x14ff20u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 7));
    // 0x14ff24: 0xfc880018  sd          $t0, 0x18($a0)
    ctx->pc = 0x14ff24u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x14ff28: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x14ff28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x14ff2c: 0x0  nop
    ctx->pc = 0x14ff2cu;
    // NOP
    // 0x14ff30: 0x0  nop
    ctx->pc = 0x14ff30u;
    // NOP
    // 0x14ff34: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x14FF34u;
    {
        const bool branch_taken_0x14ff34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x14FF38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FF34u;
            // 0x14ff38: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14ff34) {
            ctx->pc = 0x14FF08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14ff08;
        }
    }
    ctx->pc = 0x14FF3Cu;
    // 0x14ff3c: 0x3e00008  jr          $ra
    ctx->pc = 0x14FF3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14F94Cu: goto label_14f94c;
            case 0x14F968u: goto label_14f968;
            case 0x14F974u: goto label_14f974;
            case 0x14F994u: goto label_14f994;
            case 0x14F9A4u: goto label_14f9a4;
            case 0x14F9B0u: goto label_14f9b0;
            case 0x14F9D0u: goto label_14f9d0;
            case 0x14F9E4u: goto label_14f9e4;
            case 0x14F9F0u: goto label_14f9f0;
            case 0x14F9F8u: goto label_14f9f8;
            case 0x14FA0Cu: goto label_14fa0c;
            case 0x14FA18u: goto label_14fa18;
            case 0x14FA20u: goto label_14fa20;
            case 0x14FA40u: goto label_14fa40;
            case 0x14FA4Cu: goto label_14fa4c;
            case 0x14FA54u: goto label_14fa54;
            case 0x14FA68u: goto label_14fa68;
            case 0x14FA74u: goto label_14fa74;
            case 0x14FA7Cu: goto label_14fa7c;
            case 0x14FA98u: goto label_14fa98;
            case 0x14FAA4u: goto label_14faa4;
            case 0x14FAB0u: goto label_14fab0;
            case 0x14FAD8u: goto label_14fad8;
            case 0x14FAF0u: goto label_14faf0;
            case 0x14FB00u: goto label_14fb00;
            case 0x14FB08u: goto label_14fb08;
            case 0x14FB14u: goto label_14fb14;
            case 0x14FB1Cu: goto label_14fb1c;
            case 0x14FB24u: goto label_14fb24;
            case 0x14FB40u: goto label_14fb40;
            case 0x14FB48u: goto label_14fb48;
            case 0x14FB60u: goto label_14fb60;
            case 0x14FB70u: goto label_14fb70;
            case 0x14FB78u: goto label_14fb78;
            case 0x14FB84u: goto label_14fb84;
            case 0x14FB8Cu: goto label_14fb8c;
            case 0x14FB94u: goto label_14fb94;
            case 0x14FBA8u: goto label_14fba8;
            case 0x14FC18u: goto label_14fc18;
            case 0x14FC28u: goto label_14fc28;
            case 0x14FC34u: goto label_14fc34;
            case 0x14FC50u: goto label_14fc50;
            case 0x14FC60u: goto label_14fc60;
            case 0x14FC6Cu: goto label_14fc6c;
            case 0x14FC80u: goto label_14fc80;
            case 0x14FC8Cu: goto label_14fc8c;
            case 0x14FC94u: goto label_14fc94;
            case 0x14FCB4u: goto label_14fcb4;
            case 0x14FCC0u: goto label_14fcc0;
            case 0x14FCC8u: goto label_14fcc8;
            case 0x14FCDCu: goto label_14fcdc;
            case 0x14FCE8u: goto label_14fce8;
            case 0x14FCF0u: goto label_14fcf0;
            case 0x14FD08u: goto label_14fd08;
            case 0x14FD38u: goto label_14fd38;
            case 0x14FD48u: goto label_14fd48;
            case 0x14FD58u: goto label_14fd58;
            case 0x14FD68u: goto label_14fd68;
            case 0x14FD78u: goto label_14fd78;
            case 0x14FD80u: goto label_14fd80;
            case 0x14FDB8u: goto label_14fdb8;
            case 0x14FDE8u: goto label_14fde8;
            case 0x14FDF8u: goto label_14fdf8;
            case 0x14FE0Cu: goto label_14fe0c;
            case 0x14FE1Cu: goto label_14fe1c;
            case 0x14FE2Cu: goto label_14fe2c;
            case 0x14FE34u: goto label_14fe34;
            case 0x14FEA8u: goto label_14fea8;
            case 0x14FF08u: goto label_14ff08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FF44u;
    // 0x14ff44: 0x0  nop
    ctx->pc = 0x14ff44u;
    // NOP
    // 0x14ff48: 0x3e00008  jr          $ra
    ctx->pc = 0x14FF48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14F94Cu: goto label_14f94c;
            case 0x14F968u: goto label_14f968;
            case 0x14F974u: goto label_14f974;
            case 0x14F994u: goto label_14f994;
            case 0x14F9A4u: goto label_14f9a4;
            case 0x14F9B0u: goto label_14f9b0;
            case 0x14F9D0u: goto label_14f9d0;
            case 0x14F9E4u: goto label_14f9e4;
            case 0x14F9F0u: goto label_14f9f0;
            case 0x14F9F8u: goto label_14f9f8;
            case 0x14FA0Cu: goto label_14fa0c;
            case 0x14FA18u: goto label_14fa18;
            case 0x14FA20u: goto label_14fa20;
            case 0x14FA40u: goto label_14fa40;
            case 0x14FA4Cu: goto label_14fa4c;
            case 0x14FA54u: goto label_14fa54;
            case 0x14FA68u: goto label_14fa68;
            case 0x14FA74u: goto label_14fa74;
            case 0x14FA7Cu: goto label_14fa7c;
            case 0x14FA98u: goto label_14fa98;
            case 0x14FAA4u: goto label_14faa4;
            case 0x14FAB0u: goto label_14fab0;
            case 0x14FAD8u: goto label_14fad8;
            case 0x14FAF0u: goto label_14faf0;
            case 0x14FB00u: goto label_14fb00;
            case 0x14FB08u: goto label_14fb08;
            case 0x14FB14u: goto label_14fb14;
            case 0x14FB1Cu: goto label_14fb1c;
            case 0x14FB24u: goto label_14fb24;
            case 0x14FB40u: goto label_14fb40;
            case 0x14FB48u: goto label_14fb48;
            case 0x14FB60u: goto label_14fb60;
            case 0x14FB70u: goto label_14fb70;
            case 0x14FB78u: goto label_14fb78;
            case 0x14FB84u: goto label_14fb84;
            case 0x14FB8Cu: goto label_14fb8c;
            case 0x14FB94u: goto label_14fb94;
            case 0x14FBA8u: goto label_14fba8;
            case 0x14FC18u: goto label_14fc18;
            case 0x14FC28u: goto label_14fc28;
            case 0x14FC34u: goto label_14fc34;
            case 0x14FC50u: goto label_14fc50;
            case 0x14FC60u: goto label_14fc60;
            case 0x14FC6Cu: goto label_14fc6c;
            case 0x14FC80u: goto label_14fc80;
            case 0x14FC8Cu: goto label_14fc8c;
            case 0x14FC94u: goto label_14fc94;
            case 0x14FCB4u: goto label_14fcb4;
            case 0x14FCC0u: goto label_14fcc0;
            case 0x14FCC8u: goto label_14fcc8;
            case 0x14FCDCu: goto label_14fcdc;
            case 0x14FCE8u: goto label_14fce8;
            case 0x14FCF0u: goto label_14fcf0;
            case 0x14FD08u: goto label_14fd08;
            case 0x14FD38u: goto label_14fd38;
            case 0x14FD48u: goto label_14fd48;
            case 0x14FD58u: goto label_14fd58;
            case 0x14FD68u: goto label_14fd68;
            case 0x14FD78u: goto label_14fd78;
            case 0x14FD80u: goto label_14fd80;
            case 0x14FDB8u: goto label_14fdb8;
            case 0x14FDE8u: goto label_14fde8;
            case 0x14FDF8u: goto label_14fdf8;
            case 0x14FE0Cu: goto label_14fe0c;
            case 0x14FE1Cu: goto label_14fe1c;
            case 0x14FE2Cu: goto label_14fe2c;
            case 0x14FE34u: goto label_14fe34;
            case 0x14FEA8u: goto label_14fea8;
            case 0x14FF08u: goto label_14ff08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FF50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
