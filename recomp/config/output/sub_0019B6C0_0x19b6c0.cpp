#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019B6C0
// Address: 0x19b6c0 - 0x19b978
void sub_0019B6C0_0x19b6c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019B6C0_0x19b6c0");
#endif

    switch (ctx->pc) {
        case 0x19b6ecu: goto label_19b6ec;
        case 0x19b7ecu: goto label_19b7ec;
        case 0x19b81cu: goto label_19b81c;
        case 0x19b840u: goto label_19b840;
        case 0x19b88cu: goto label_19b88c;
        case 0x19b938u: goto label_19b938;
        case 0x19b948u: goto label_19b948;
        default: break;
    }

    ctx->pc = 0x19b6c0u;

    // 0x19b6c0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x19b6c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19b6c4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19b6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19b6c8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19b6c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19b6cc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19b6ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19b6d0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19b6d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b6d4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19b6d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19b6d8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19b6d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b6dc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19b6dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b6e0: 0x24040f80  addiu       $a0, $zero, 0xF80
    ctx->pc = 0x19b6e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3968));
    // 0x19b6e4: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19B6E4u;
    SET_GPR_U32(ctx, 31, 0x19B6ECu);
    ctx->pc = 0x19B6E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B6E4u;
            // 0x19b6e8: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B6ECu; }
        if (ctx->pc != 0x19B6ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B6ECu; }
        if (ctx->pc != 0x19B6ECu) { return; }
    }
    ctx->pc = 0x19B6ECu;
label_19b6ec:
    // 0x19b6ec: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19b6ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19b6f0: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19b6f0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19b6f4: 0x346400f7  ori         $a0, $v1, 0xF7
    ctx->pc = 0x19b6f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)247);
    // 0x19b6f8: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19b6f8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19b6fc: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19b6fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19b700: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19b700u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19b704: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19b704u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19b708: 0x34650404  ori         $a1, $v1, 0x404
    ctx->pc = 0x19b708u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19b70c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19b70cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19b710: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19b710u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19b714: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19b714u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19b718: 0x3c046cf5  lui         $a0, 0x6CF5
    ctx->pc = 0x19b718u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)27893 << 16));
    // 0x19b71c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19b71cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19b720: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19b720u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19b724: 0xac450018  sw          $a1, 0x18($v0)
    ctx->pc = 0x19b724u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19b728: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b728u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b72c: 0xac44001c  sw          $a0, 0x1C($v0)
    ctx->pc = 0x19b72cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19b730: 0x24e74d40  addiu       $a3, $a3, 0x4D40
    ctx->pc = 0x19b730u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19b734: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19b734u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b738: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19b738u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b73c: 0x24460050  addiu       $a2, $v0, 0x50
    ctx->pc = 0x19b73cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 80));
    // 0x19b740: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19b740u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x19b744: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b744u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b748: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b748u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b74c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b74cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b750: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19b750u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19b754: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19b754u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b758: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19b758u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b75c: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b75cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b760: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b760u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b764: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b764u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b768: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19b768u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19b76c: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19b76cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b770: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19b770u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b774: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b774u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b778: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b778u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b77c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b77cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b780: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19b780u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19b784: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19b784u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b788: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19b788u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19b78c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b78cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b790: 0xc4214e40  lwc1        $f1, 0x4E40($at)
    ctx->pc = 0x19b790u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b794: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19b794u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19b798: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b798u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b79c: 0xc4214e44  lwc1        $f1, 0x4E44($at)
    ctx->pc = 0x19b79cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7a0: 0xe4410034  swc1        $f1, 0x34($v0)
    ctx->pc = 0x19b7a0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19b7a4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b7a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b7a8: 0xc4214e48  lwc1        $f1, 0x4E48($at)
    ctx->pc = 0x19b7a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7ac: 0xe4410038  swc1        $f1, 0x38($v0)
    ctx->pc = 0x19b7acu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19b7b0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b7b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b7b4: 0xc4214e4c  lwc1        $f1, 0x4E4C($at)
    ctx->pc = 0x19b7b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7b8: 0xe441003c  swc1        $f1, 0x3C($v0)
    ctx->pc = 0x19b7b8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19b7bc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b7bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b7c0: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19b7c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7c4: 0xe4410040  swc1        $f1, 0x40($v0)
    ctx->pc = 0x19b7c4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19b7c8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b7c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b7cc: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19b7ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b7d0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b7d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b7d4: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19b7d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7d8: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19b7d8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19b7dc: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19b7dcu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19b7e0: 0xe4400044  swc1        $f0, 0x44($v0)
    ctx->pc = 0x19b7e0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19b7e4: 0xac400048  sw          $zero, 0x48($v0)
    ctx->pc = 0x19b7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19b7e8: 0xac40004c  sw          $zero, 0x4C($v0)
    ctx->pc = 0x19b7e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
label_19b7ec:
    // 0x19b7ec: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19b7ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b7f0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19b7f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b7f4: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19b7f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b7f8: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19b7f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b7fc: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19b7fcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b800: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19b800u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b804: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19B804u;
    {
        const bool branch_taken_0x19b804 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19B808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B804u;
            // 0x19b808: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b804) {
            ctx->pc = 0x19B7ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19b7ec;
        }
    }
    ctx->pc = 0x19B80Cu;
    // 0x19b80c: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19b80cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19b810: 0x24460090  addiu       $a2, $v0, 0x90
    ctx->pc = 0x19b810u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 144));
    // 0x19b814: 0x24e74d00  addiu       $a3, $a3, 0x4D00
    ctx->pc = 0x19b814u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19b818: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19b818u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19b81c:
    // 0x19b81c: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19b81cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b820: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19b820u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b824: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19b824u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b828: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19b828u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b82c: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19b82cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b830: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19b830u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b834: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19B834u;
    {
        const bool branch_taken_0x19b834 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19B838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B834u;
            // 0x19b838: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b834) {
            ctx->pc = 0x19B81Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19b81c;
        }
    }
    ctx->pc = 0x19B83Cu;
    // 0x19b83c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x19b83cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19b840:
    // 0x19b840: 0x8e430054  lw          $v1, 0x54($s2)
    ctx->pc = 0x19b840u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19b844: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x19b844u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19b848: 0x1042004  sllv        $a0, $a0, $t0
    ctx->pc = 0x19b848u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19b84c: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x19b84cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x19b850: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x19B850u;
    {
        const bool branch_taken_0x19b850 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x19B854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B850u;
            // 0x19b854: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b850) {
            ctx->pc = 0x19B88Cu;
            goto label_19b88c;
        }
    }
    ctx->pc = 0x19B858u;
    // 0x19b858: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19b858u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19b85c: 0x682021  addu        $a0, $v1, $t0
    ctx->pc = 0x19b85cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19b860: 0x83180  sll         $a2, $t0, 6
    ctx->pc = 0x19b860u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 8), 6));
    // 0x19b864: 0x461821  addu        $v1, $v0, $a2
    ctx->pc = 0x19b864u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19b868: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x19b868u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x19b86c: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x19b86cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x19b870: 0x24650170  addiu       $a1, $v1, 0x170
    ctx->pc = 0x19b870u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 368));
    // 0x19b874: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x19b874u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19b878: 0xc13021  addu        $a2, $a2, $at
    ctx->pc = 0x19b878u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19b87c: 0x24640970  addiu       $a0, $v1, 0x970
    ctx->pc = 0x19b87cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2416));
    // 0x19b880: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19b880u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19b884: 0xc066538  jal         func_1994E0
    ctx->pc = 0x19B884u;
    SET_GPR_U32(ctx, 31, 0x19B88Cu);
    ctx->pc = 0x19B888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B884u;
            // 0x19b888: 0x34673f40  ori         $a3, $v1, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1994E0u;
    if (runtime->hasFunction(0x1994E0u)) {
        auto targetFn = runtime->lookupFunction(0x1994E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B88Cu; }
        if (ctx->pc != 0x19B88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B88Cu; }
        if (ctx->pc != 0x19B88Cu) { return; }
    }
    ctx->pc = 0x19B88Cu;
label_19b88c:
    // 0x19b88c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x19b88cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x19b890: 0x29030020  slti        $v1, $t0, 0x20
    ctx->pc = 0x19b890u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x19b894: 0x1460ffea  bnez        $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x19B894u;
    {
        const bool branch_taken_0x19b894 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19B898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B894u;
            // 0x19b898: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b894) {
            ctx->pc = 0x19B840u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19b840;
        }
    }
    ctx->pc = 0x19B89Cu;
    // 0x19b89c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19b89cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19b8a0: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19b8a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b8a4: 0xafa3004c  sw          $v1, 0x4C($sp)
    ctx->pc = 0x19b8a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19b8a8: 0xafa3005c  sw          $v1, 0x5C($sp)
    ctx->pc = 0x19b8a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19b8ac: 0x244400d0  addiu       $a0, $v0, 0xD0
    ctx->pc = 0x19b8acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 208));
    // 0x19b8b0: 0xafa3006c  sw          $v1, 0x6C($sp)
    ctx->pc = 0x19b8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19b8b4: 0x24450100  addiu       $a1, $v0, 0x100
    ctx->pc = 0x19b8b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
    // 0x19b8b8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19b8b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19b8bc: 0x27a70040  addiu       $a3, $sp, 0x40
    ctx->pc = 0x19b8bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19b8c0: 0x34663f40  ori         $a2, $v1, 0x3F40
    ctx->pc = 0x19b8c0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19b8c4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b8c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b8c8: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19b8c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b8cc: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19b8ccu;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19b8d0: 0xe7a10040  swc1        $f1, 0x40($sp)
    ctx->pc = 0x19b8d0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19b8d4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b8d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b8d8: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19b8d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19b8dc: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19b8dcu;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19b8e0: 0xe7a50044  swc1        $f5, 0x44($sp)
    ctx->pc = 0x19b8e0u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19b8e4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b8e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b8e8: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19b8e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19b8ec: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19b8ecu;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19b8f0: 0xe7a40048  swc1        $f4, 0x48($sp)
    ctx->pc = 0x19b8f0u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19b8f4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b8f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b8f8: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19b8f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b8fc: 0xe7a30050  swc1        $f3, 0x50($sp)
    ctx->pc = 0x19b8fcu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19b900: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b900u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b904: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19b904u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b908: 0xe7a20054  swc1        $f2, 0x54($sp)
    ctx->pc = 0x19b908u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19b90c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b90cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b910: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19b910u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b914: 0xe7a10058  swc1        $f1, 0x58($sp)
    ctx->pc = 0x19b914u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19b918: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b918u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b91c: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19b91cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b920: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x19b920u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19b924: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b924u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b928: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19b928u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b92c: 0xe7a10064  swc1        $f1, 0x64($sp)
    ctx->pc = 0x19b92cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19b930: 0xc06661c  jal         func_199870
    ctx->pc = 0x19B930u;
    SET_GPR_U32(ctx, 31, 0x19B938u);
    ctx->pc = 0x19B934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B930u;
            // 0x19b934: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199870u;
    if (runtime->hasFunction(0x199870u)) {
        auto targetFn = runtime->lookupFunction(0x199870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B938u; }
        if (ctx->pc != 0x19B938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B938u; }
        if (ctx->pc != 0x19B938u) { return; }
    }
    ctx->pc = 0x19B938u;
label_19b938:
    // 0x19b938: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19b938u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b93c: 0xc46c0024  lwc1        $f12, 0x24($v1)
    ctx->pc = 0x19b93cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19b940: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19B940u;
    SET_GPR_U32(ctx, 31, 0x19B948u);
    ctx->pc = 0x19B944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B940u;
            // 0x19b944: 0x24440110  addiu       $a0, $v0, 0x110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B948u; }
        if (ctx->pc != 0x19B948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B948u; }
        if (ctx->pc != 0x19B948u) { return; }
    }
    ctx->pc = 0x19B948u;
label_19b948:
    // 0x19b948: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19b948u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19b94c: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19b94cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19b950: 0xac430f70  sw          $v1, 0xF70($v0)
    ctx->pc = 0x19b950u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3952), GPR_U32(ctx, 3));
    // 0x19b954: 0xac400f74  sw          $zero, 0xF74($v0)
    ctx->pc = 0x19b954u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3956), GPR_U32(ctx, 0));
    // 0x19b958: 0xac400f78  sw          $zero, 0xF78($v0)
    ctx->pc = 0x19b958u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3960), GPR_U32(ctx, 0));
    // 0x19b95c: 0xac400f7c  sw          $zero, 0xF7C($v0)
    ctx->pc = 0x19b95cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3964), GPR_U32(ctx, 0));
    // 0x19b960: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19b960u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19b964: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19b964u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19b968: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19b968u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19b96c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19b96cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19b970: 0x3e00008  jr          $ra
    ctx->pc = 0x19B970u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19B974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B970u;
            // 0x19b974: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19B6ECu: goto label_19b6ec;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19B938u: goto label_19b938;
            case 0x19B948u: goto label_19b948;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19B978u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
