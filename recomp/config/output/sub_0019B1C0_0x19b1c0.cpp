#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019B1C0
// Address: 0x19b1c0 - 0x19b478
void sub_0019B1C0_0x19b1c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019B1C0_0x19b1c0");
#endif

    switch (ctx->pc) {
        case 0x19b1ecu: goto label_19b1ec;
        case 0x19b2bcu: goto label_19b2bc;
        case 0x19b2ecu: goto label_19b2ec;
        case 0x19b31cu: goto label_19b31c;
        case 0x19b340u: goto label_19b340;
        case 0x19b38cu: goto label_19b38c;
        case 0x19b438u: goto label_19b438;
        case 0x19b448u: goto label_19b448;
        default: break;
    }

    ctx->pc = 0x19b1c0u;

    // 0x19b1c0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x19b1c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19b1c4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19b1c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19b1c8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19b1c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19b1cc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19b1ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19b1d0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19b1d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b1d4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19b1d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19b1d8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19b1d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b1dc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19b1dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b1e0: 0x24040fb0  addiu       $a0, $zero, 0xFB0
    ctx->pc = 0x19b1e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4016));
    // 0x19b1e4: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19B1E4u;
    SET_GPR_U32(ctx, 31, 0x19B1ECu);
    ctx->pc = 0x19B1E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B1E4u;
            // 0x19b1e8: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B1ECu; }
        if (ctx->pc != 0x19B1ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B1ECu; }
        if (ctx->pc != 0x19B1ECu) { return; }
    }
    ctx->pc = 0x19B1ECu;
label_19b1ec:
    // 0x19b1ec: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19b1ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19b1f0: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19b1f0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19b1f4: 0x346400fa  ori         $a0, $v1, 0xFA
    ctx->pc = 0x19b1f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)250);
    // 0x19b1f8: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19b1f8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19b1fc: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19b1fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19b200: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19b200u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19b204: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19b204u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19b208: 0x34650404  ori         $a1, $v1, 0x404
    ctx->pc = 0x19b208u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19b20c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19b20cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19b210: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19b210u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19b214: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19b214u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19b218: 0x3c046cf8  lui         $a0, 0x6CF8
    ctx->pc = 0x19b218u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)27896 << 16));
    // 0x19b21c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19b21cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19b220: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19b220u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19b224: 0xac450018  sw          $a1, 0x18($v0)
    ctx->pc = 0x19b224u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19b228: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b228u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b22c: 0xac44001c  sw          $a0, 0x1C($v0)
    ctx->pc = 0x19b22cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19b230: 0x24e74d40  addiu       $a3, $a3, 0x4D40
    ctx->pc = 0x19b230u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19b234: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19b234u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b238: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19b238u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b23c: 0x24460040  addiu       $a2, $v0, 0x40
    ctx->pc = 0x19b23cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19b240: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19b240u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x19b244: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b244u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b248: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b248u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b24c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b24cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b250: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19b250u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19b254: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19b254u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b258: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19b258u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b25c: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b25cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b260: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b260u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b264: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b264u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b268: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19b268u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19b26c: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19b26cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b270: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19b270u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b274: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b274u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b278: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b278u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b27c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b27cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b280: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19b280u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19b284: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19b284u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b288: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19b288u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19b28c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b28cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b290: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19b290u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b294: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19b294u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19b298: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b298u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b29c: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19b29cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b2a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b2a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b2a4: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19b2a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b2a8: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19b2a8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19b2ac: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19b2acu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19b2b0: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19b2b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19b2b4: 0xac400038  sw          $zero, 0x38($v0)
    ctx->pc = 0x19b2b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19b2b8: 0xac40003c  sw          $zero, 0x3C($v0)
    ctx->pc = 0x19b2b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
label_19b2bc:
    // 0x19b2bc: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19b2bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b2c0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19b2c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b2c4: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19b2c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b2c8: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19b2c8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b2cc: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19b2ccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b2d0: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19b2d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b2d4: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19B2D4u;
    {
        const bool branch_taken_0x19b2d4 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19B2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B2D4u;
            // 0x19b2d8: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b2d4) {
            ctx->pc = 0x19B2BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19b2bc;
        }
    }
    ctx->pc = 0x19B2DCu;
    // 0x19b2dc: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19b2dcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19b2e0: 0x24460080  addiu       $a2, $v0, 0x80
    ctx->pc = 0x19b2e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19b2e4: 0x24e74d00  addiu       $a3, $a3, 0x4D00
    ctx->pc = 0x19b2e4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19b2e8: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19b2e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19b2ec:
    // 0x19b2ec: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19b2ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b2f0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19b2f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b2f4: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19b2f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b2f8: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19b2f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b2fc: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19b2fcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b300: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19b300u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b304: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19B304u;
    {
        const bool branch_taken_0x19b304 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19B308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B304u;
            // 0x19b308: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b304) {
            ctx->pc = 0x19B2ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19b2ec;
        }
    }
    ctx->pc = 0x19B30Cu;
    // 0x19b30c: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19b30cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19b310: 0x244600c0  addiu       $a2, $v0, 0xC0
    ctx->pc = 0x19b310u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
    // 0x19b314: 0x24e74cc0  addiu       $a3, $a3, 0x4CC0
    ctx->pc = 0x19b314u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19648));
    // 0x19b318: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19b318u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19b31c:
    // 0x19b31c: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19b31cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b320: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19b320u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b324: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19b324u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b328: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19b328u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b32c: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19b32cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b330: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19b330u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b334: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19B334u;
    {
        const bool branch_taken_0x19b334 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19B338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B334u;
            // 0x19b338: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b334) {
            ctx->pc = 0x19B31Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19b31c;
        }
    }
    ctx->pc = 0x19B33Cu;
    // 0x19b33c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x19b33cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19b340:
    // 0x19b340: 0x8e430054  lw          $v1, 0x54($s2)
    ctx->pc = 0x19b340u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19b344: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x19b344u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19b348: 0x1042004  sllv        $a0, $a0, $t0
    ctx->pc = 0x19b348u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19b34c: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x19b34cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x19b350: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x19B350u;
    {
        const bool branch_taken_0x19b350 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x19B354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B350u;
            // 0x19b354: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b350) {
            ctx->pc = 0x19B38Cu;
            goto label_19b38c;
        }
    }
    ctx->pc = 0x19B358u;
    // 0x19b358: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19b358u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19b35c: 0x682021  addu        $a0, $v1, $t0
    ctx->pc = 0x19b35cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19b360: 0x83180  sll         $a2, $t0, 6
    ctx->pc = 0x19b360u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 8), 6));
    // 0x19b364: 0x461821  addu        $v1, $v0, $a2
    ctx->pc = 0x19b364u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19b368: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x19b368u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x19b36c: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x19b36cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x19b370: 0x246501a0  addiu       $a1, $v1, 0x1A0
    ctx->pc = 0x19b370u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 416));
    // 0x19b374: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x19b374u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19b378: 0xc13021  addu        $a2, $a2, $at
    ctx->pc = 0x19b378u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19b37c: 0x246409a0  addiu       $a0, $v1, 0x9A0
    ctx->pc = 0x19b37cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2464));
    // 0x19b380: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19b380u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19b384: 0xc066538  jal         func_1994E0
    ctx->pc = 0x19B384u;
    SET_GPR_U32(ctx, 31, 0x19B38Cu);
    ctx->pc = 0x19B388u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B384u;
            // 0x19b388: 0x34673f40  ori         $a3, $v1, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1994E0u;
    if (runtime->hasFunction(0x1994E0u)) {
        auto targetFn = runtime->lookupFunction(0x1994E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B38Cu; }
        if (ctx->pc != 0x19B38Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B38Cu; }
        if (ctx->pc != 0x19B38Cu) { return; }
    }
    ctx->pc = 0x19B38Cu;
label_19b38c:
    // 0x19b38c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x19b38cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x19b390: 0x29030020  slti        $v1, $t0, 0x20
    ctx->pc = 0x19b390u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x19b394: 0x1460ffea  bnez        $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x19B394u;
    {
        const bool branch_taken_0x19b394 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19B398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B394u;
            // 0x19b398: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b394) {
            ctx->pc = 0x19B340u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19b340;
        }
    }
    ctx->pc = 0x19B39Cu;
    // 0x19b39c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19b39cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19b3a0: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19b3a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b3a4: 0xafa3004c  sw          $v1, 0x4C($sp)
    ctx->pc = 0x19b3a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19b3a8: 0xafa3005c  sw          $v1, 0x5C($sp)
    ctx->pc = 0x19b3a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19b3ac: 0x24440100  addiu       $a0, $v0, 0x100
    ctx->pc = 0x19b3acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
    // 0x19b3b0: 0xafa3006c  sw          $v1, 0x6C($sp)
    ctx->pc = 0x19b3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19b3b4: 0x24450130  addiu       $a1, $v0, 0x130
    ctx->pc = 0x19b3b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 304));
    // 0x19b3b8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19b3b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19b3bc: 0x27a70040  addiu       $a3, $sp, 0x40
    ctx->pc = 0x19b3bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19b3c0: 0x34663f40  ori         $a2, $v1, 0x3F40
    ctx->pc = 0x19b3c0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19b3c4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b3c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b3c8: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19b3c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b3cc: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19b3ccu;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19b3d0: 0xe7a10040  swc1        $f1, 0x40($sp)
    ctx->pc = 0x19b3d0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19b3d4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b3d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b3d8: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19b3d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19b3dc: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19b3dcu;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19b3e0: 0xe7a50044  swc1        $f5, 0x44($sp)
    ctx->pc = 0x19b3e0u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19b3e4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b3e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b3e8: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19b3e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19b3ec: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19b3ecu;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19b3f0: 0xe7a40048  swc1        $f4, 0x48($sp)
    ctx->pc = 0x19b3f0u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19b3f4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b3f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b3f8: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19b3f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b3fc: 0xe7a30050  swc1        $f3, 0x50($sp)
    ctx->pc = 0x19b3fcu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19b400: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b400u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b404: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19b404u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b408: 0xe7a20054  swc1        $f2, 0x54($sp)
    ctx->pc = 0x19b408u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19b40c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b40cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b410: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19b410u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b414: 0xe7a10058  swc1        $f1, 0x58($sp)
    ctx->pc = 0x19b414u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19b418: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b418u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b41c: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19b41cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b420: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x19b420u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19b424: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b424u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b428: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19b428u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b42c: 0xe7a10064  swc1        $f1, 0x64($sp)
    ctx->pc = 0x19b42cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19b430: 0xc06661c  jal         func_199870
    ctx->pc = 0x19B430u;
    SET_GPR_U32(ctx, 31, 0x19B438u);
    ctx->pc = 0x19B434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B430u;
            // 0x19b434: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199870u;
    if (runtime->hasFunction(0x199870u)) {
        auto targetFn = runtime->lookupFunction(0x199870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B438u; }
        if (ctx->pc != 0x19B438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B438u; }
        if (ctx->pc != 0x19B438u) { return; }
    }
    ctx->pc = 0x19B438u;
label_19b438:
    // 0x19b438: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19b438u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b43c: 0xc46c0024  lwc1        $f12, 0x24($v1)
    ctx->pc = 0x19b43cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19b440: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19B440u;
    SET_GPR_U32(ctx, 31, 0x19B448u);
    ctx->pc = 0x19B444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B440u;
            // 0x19b444: 0x24440140  addiu       $a0, $v0, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B448u; }
        if (ctx->pc != 0x19B448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B448u; }
        if (ctx->pc != 0x19B448u) { return; }
    }
    ctx->pc = 0x19B448u;
label_19b448:
    // 0x19b448: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19b448u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19b44c: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19b44cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19b450: 0xac430fa0  sw          $v1, 0xFA0($v0)
    ctx->pc = 0x19b450u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4000), GPR_U32(ctx, 3));
    // 0x19b454: 0xac400fa4  sw          $zero, 0xFA4($v0)
    ctx->pc = 0x19b454u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4004), GPR_U32(ctx, 0));
    // 0x19b458: 0xac400fa8  sw          $zero, 0xFA8($v0)
    ctx->pc = 0x19b458u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4008), GPR_U32(ctx, 0));
    // 0x19b45c: 0xac400fac  sw          $zero, 0xFAC($v0)
    ctx->pc = 0x19b45cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4012), GPR_U32(ctx, 0));
    // 0x19b460: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19b460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19b464: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19b464u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19b468: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19b468u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19b46c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19b46cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19b470: 0x3e00008  jr          $ra
    ctx->pc = 0x19B470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19B474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B470u;
            // 0x19b474: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19B1ECu: goto label_19b1ec;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B438u: goto label_19b438;
            case 0x19B448u: goto label_19b448;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19B478u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
