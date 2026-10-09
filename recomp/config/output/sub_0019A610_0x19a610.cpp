#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019A610
// Address: 0x19a610 - 0x19a794
void sub_0019A610_0x19a610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019A610_0x19a610");
#endif

    switch (ctx->pc) {
        case 0x19a63cu: goto label_19a63c;
        case 0x19a714u: goto label_19a714;
        case 0x19a724u: goto label_19a724;
        case 0x19a72cu: goto label_19a72c;
        default: break;
    }

    ctx->pc = 0x19a610u;

    // 0x19a610: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19a610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a614: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19a614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a618: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19a618u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a61c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19a61cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a620: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19a620u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a624: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19a624u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a628: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19a628u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a62c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19a62cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a630: 0x24040110  addiu       $a0, $zero, 0x110
    ctx->pc = 0x19a630u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 272));
    // 0x19a634: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19A634u;
    SET_GPR_U32(ctx, 31, 0x19A63Cu);
    ctx->pc = 0x19A638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A634u;
            // 0x19a638: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A63Cu; }
        if (ctx->pc != 0x19A63Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A63Cu; }
        if (ctx->pc != 0x19A63Cu) { return; }
    }
    ctx->pc = 0x19A63Cu;
label_19a63c:
    // 0x19a63c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19a63cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19a640: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19a640u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19a644: 0x34640010  ori         $a0, $v1, 0x10
    ctx->pc = 0x19a644u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16);
    // 0x19a648: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19a648u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19a64c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19a64cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a650: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19a650u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19a654: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19a654u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a658: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19a658u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19a65c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19a65cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a660: 0x3c076c0e  lui         $a3, 0x6C0E
    ctx->pc = 0x19a660u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27662 << 16));
    // 0x19a664: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19a664u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a668: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19a668u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19a66c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19a66cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a670: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a670u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a674: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19a674u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a678: 0x24440040  addiu       $a0, $v0, 0x40
    ctx->pc = 0x19a678u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a67c: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19a67cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a680: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19a680u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19a684: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19a684u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19a688: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x19a688u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a68c: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a68cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a690: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19a690u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a694: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19a694u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a698: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a698u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a69c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a69cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a6a0: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a6a0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a6a4: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19a6a4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a6a8: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a6a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a6ac: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19a6acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a6b0: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a6b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6b4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a6b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a6b8: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a6b8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a6bc: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19a6bcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a6c0: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a6c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a6c4: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19a6c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a6c8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a6c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6cc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a6ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a6d0: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a6d0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a6d4: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19a6d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a6d8: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19a6d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6dc: 0xe440002c  swc1        $f0, 0x2C($v0)
    ctx->pc = 0x19a6dcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19a6e0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a6e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a6e4: 0xc4204e40  lwc1        $f0, 0x4E40($at)
    ctx->pc = 0x19a6e4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6e8: 0xe4400030  swc1        $f0, 0x30($v0)
    ctx->pc = 0x19a6e8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19a6ec: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a6ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a6f0: 0xc4204e44  lwc1        $f0, 0x4E44($at)
    ctx->pc = 0x19a6f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6f4: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19a6f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19a6f8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a6f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a6fc: 0xc4204e48  lwc1        $f0, 0x4E48($at)
    ctx->pc = 0x19a6fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a700: 0xe4400038  swc1        $f0, 0x38($v0)
    ctx->pc = 0x19a700u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19a704: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a704u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a708: 0xc4204e4c  lwc1        $f0, 0x4E4C($at)
    ctx->pc = 0x19a708u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a70c: 0xc066500  jal         func_199400
    ctx->pc = 0x19A70Cu;
    SET_GPR_U32(ctx, 31, 0x19A714u);
    ctx->pc = 0x19A710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A70Cu;
            // 0x19a710: 0xe440003c  swc1        $f0, 0x3C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A714u; }
        if (ctx->pc != 0x19A714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A714u; }
        if (ctx->pc != 0x19A714u) { return; }
    }
    ctx->pc = 0x19A714u;
label_19a714:
    // 0x19a714: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19a714u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19a718: 0x24440080  addiu       $a0, $v0, 0x80
    ctx->pc = 0x19a718u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19a71c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19A71Cu;
    SET_GPR_U32(ctx, 31, 0x19A724u);
    ctx->pc = 0x19A720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A71Cu;
            // 0x19a720: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A724u; }
        if (ctx->pc != 0x19A724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A724u; }
        if (ctx->pc != 0x19A724u) { return; }
    }
    ctx->pc = 0x19A724u;
label_19a724:
    // 0x19a724: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19A724u;
    SET_GPR_U32(ctx, 31, 0x19A72Cu);
    ctx->pc = 0x19A728u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A724u;
            // 0x19a728: 0x244400c0  addiu       $a0, $v0, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A72Cu; }
        if (ctx->pc != 0x19A72Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A72Cu; }
        if (ctx->pc != 0x19A72Cu) { return; }
    }
    ctx->pc = 0x19A72Cu;
label_19a72c:
    // 0x19a72c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a72cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a730: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19a730u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19a734: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19a734u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a738: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19a738u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19a73c: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19a73cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19a740: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19a740u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19a744: 0xe44100f0  swc1        $f1, 0xF0($v0)
    ctx->pc = 0x19a744u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 240), bits); }
    // 0x19a748: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a748u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a74c: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19a74cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19a750: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a750u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a754: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19a754u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a758: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19a758u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19a75c: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19a75cu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19a760: 0xe44000f4  swc1        $f0, 0xF4($v0)
    ctx->pc = 0x19a760u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 244), bits); }
    // 0x19a764: 0xac4000f8  sw          $zero, 0xF8($v0)
    ctx->pc = 0x19a764u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 248), GPR_U32(ctx, 0));
    // 0x19a768: 0xac4000fc  sw          $zero, 0xFC($v0)
    ctx->pc = 0x19a768u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 252), GPR_U32(ctx, 0));
    // 0x19a76c: 0xac430100  sw          $v1, 0x100($v0)
    ctx->pc = 0x19a76cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 256), GPR_U32(ctx, 3));
    // 0x19a770: 0xac400104  sw          $zero, 0x104($v0)
    ctx->pc = 0x19a770u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 260), GPR_U32(ctx, 0));
    // 0x19a774: 0xac400108  sw          $zero, 0x108($v0)
    ctx->pc = 0x19a774u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 264), GPR_U32(ctx, 0));
    // 0x19a778: 0xac40010c  sw          $zero, 0x10C($v0)
    ctx->pc = 0x19a778u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 268), GPR_U32(ctx, 0));
    // 0x19a77c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19a77cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a780: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19a780u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a784: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19a784u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a788: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19a788u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a78c: 0x3e00008  jr          $ra
    ctx->pc = 0x19A78Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19A78Cu;
            // 0x19a790: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19A63Cu: goto label_19a63c;
            case 0x19A714u: goto label_19a714;
            case 0x19A724u: goto label_19a724;
            case 0x19A72Cu: goto label_19a72c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A794u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
