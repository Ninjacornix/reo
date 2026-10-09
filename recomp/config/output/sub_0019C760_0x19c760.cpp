#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019C760
// Address: 0x19c760 - 0x19c8dc
void sub_0019C760_0x19c760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019C760_0x19c760");
#endif

    switch (ctx->pc) {
        case 0x19c78cu: goto label_19c78c;
        case 0x19c864u: goto label_19c864;
        case 0x19c874u: goto label_19c874;
        case 0x19c87cu: goto label_19c87c;
        case 0x19c88cu: goto label_19c88c;
        default: break;
    }

    ctx->pc = 0x19c760u;

    // 0x19c760: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19c760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19c764: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19c764u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19c768: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19c768u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19c76c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19c76cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c770: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19c770u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c774: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19c774u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19c778: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19c778u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c77c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19c77cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c780: 0x24040140  addiu       $a0, $zero, 0x140
    ctx->pc = 0x19c780u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x19c784: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19C784u;
    SET_GPR_U32(ctx, 31, 0x19C78Cu);
    ctx->pc = 0x19C788u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C784u;
            // 0x19c788: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C78Cu; }
        if (ctx->pc != 0x19C78Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C78Cu; }
        if (ctx->pc != 0x19C78Cu) { return; }
    }
    ctx->pc = 0x19C78Cu;
label_19c78c:
    // 0x19c78c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19c78cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19c790: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19c790u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19c794: 0x34640013  ori         $a0, $v1, 0x13
    ctx->pc = 0x19c794u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)19);
    // 0x19c798: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19c798u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19c79c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19c79cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19c7a0: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19c7a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19c7a4: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19c7a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19c7a8: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19c7a8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19c7ac: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19c7acu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19c7b0: 0x3c076c11  lui         $a3, 0x6C11
    ctx->pc = 0x19c7b0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27665 << 16));
    // 0x19c7b4: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19c7b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19c7b8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19c7b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19c7bc: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19c7bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19c7c0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c7c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c7c4: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19c7c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19c7c8: 0x24440040  addiu       $a0, $v0, 0x40
    ctx->pc = 0x19c7c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19c7cc: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19c7ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19c7d0: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19c7d0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19c7d4: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19c7d4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19c7d8: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x19c7d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19c7dc: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c7dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c7e0: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19c7e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c7e4: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19c7e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19c7e8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c7e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c7ec: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c7ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c7f0: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c7f0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c7f4: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19c7f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19c7f8: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c7f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c7fc: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19c7fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c800: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c800u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c804: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c804u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c808: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c808u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c80c: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19c80cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19c810: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c810u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c814: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19c814u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c818: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c818u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c81c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c81cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c820: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c820u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c824: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19c824u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19c828: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19c828u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c82c: 0xe440002c  swc1        $f0, 0x2C($v0)
    ctx->pc = 0x19c82cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19c830: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c834: 0xc4204e40  lwc1        $f0, 0x4E40($at)
    ctx->pc = 0x19c834u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c838: 0xe4400030  swc1        $f0, 0x30($v0)
    ctx->pc = 0x19c838u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19c83c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c83cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c840: 0xc4204e44  lwc1        $f0, 0x4E44($at)
    ctx->pc = 0x19c840u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c844: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19c844u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19c848: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c848u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c84c: 0xc4204e48  lwc1        $f0, 0x4E48($at)
    ctx->pc = 0x19c84cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c850: 0xe4400038  swc1        $f0, 0x38($v0)
    ctx->pc = 0x19c850u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19c854: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c854u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c858: 0xc4204e4c  lwc1        $f0, 0x4E4C($at)
    ctx->pc = 0x19c858u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c85c: 0xc066500  jal         func_199400
    ctx->pc = 0x19C85Cu;
    SET_GPR_U32(ctx, 31, 0x19C864u);
    ctx->pc = 0x19C860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C85Cu;
            // 0x19c860: 0xe440003c  swc1        $f0, 0x3C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C864u; }
        if (ctx->pc != 0x19C864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C864u; }
        if (ctx->pc != 0x19C864u) { return; }
    }
    ctx->pc = 0x19C864u;
label_19c864:
    // 0x19c864: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19c864u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19c868: 0x24440080  addiu       $a0, $v0, 0x80
    ctx->pc = 0x19c868u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19c86c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19C86Cu;
    SET_GPR_U32(ctx, 31, 0x19C874u);
    ctx->pc = 0x19C870u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C86Cu;
            // 0x19c870: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C874u; }
        if (ctx->pc != 0x19C874u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C874u; }
        if (ctx->pc != 0x19C874u) { return; }
    }
    ctx->pc = 0x19C874u;
label_19c874:
    // 0x19c874: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19C874u;
    SET_GPR_U32(ctx, 31, 0x19C87Cu);
    ctx->pc = 0x19C878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C874u;
            // 0x19c878: 0x244400c0  addiu       $a0, $v0, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C87Cu; }
        if (ctx->pc != 0x19C87Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C87Cu; }
        if (ctx->pc != 0x19C87Cu) { return; }
    }
    ctx->pc = 0x19C87Cu;
label_19c87c:
    // 0x19c87c: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19c87cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19c880: 0x244600f0  addiu       $a2, $v0, 0xF0
    ctx->pc = 0x19c880u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 240));
    // 0x19c884: 0x24e74cc0  addiu       $a3, $a3, 0x4CC0
    ctx->pc = 0x19c884u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19648));
    // 0x19c888: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19c888u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19c88c:
    // 0x19c88c: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19c88cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19c890: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19c890u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19c894: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19c894u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19c898: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19c898u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19c89c: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19c89cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19c8a0: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19c8a0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19c8a4: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19C8A4u;
    {
        const bool branch_taken_0x19c8a4 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19C8A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C8A4u;
            // 0x19c8a8: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c8a4) {
            ctx->pc = 0x19C88Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19c88c;
        }
    }
    ctx->pc = 0x19C8ACu;
    // 0x19c8ac: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19c8acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19c8b0: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19c8b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19c8b4: 0xac430130  sw          $v1, 0x130($v0)
    ctx->pc = 0x19c8b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 304), GPR_U32(ctx, 3));
    // 0x19c8b8: 0xac400134  sw          $zero, 0x134($v0)
    ctx->pc = 0x19c8b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 308), GPR_U32(ctx, 0));
    // 0x19c8bc: 0xac400138  sw          $zero, 0x138($v0)
    ctx->pc = 0x19c8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 312), GPR_U32(ctx, 0));
    // 0x19c8c0: 0xac40013c  sw          $zero, 0x13C($v0)
    ctx->pc = 0x19c8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 316), GPR_U32(ctx, 0));
    // 0x19c8c4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19c8c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c8c8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19c8c8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c8cc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19c8ccu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c8d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19c8d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c8d4: 0x3e00008  jr          $ra
    ctx->pc = 0x19C8D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C8D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C8D4u;
            // 0x19c8d8: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19C78Cu: goto label_19c78c;
            case 0x19C864u: goto label_19c864;
            case 0x19C874u: goto label_19c874;
            case 0x19C87Cu: goto label_19c87c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C8DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
