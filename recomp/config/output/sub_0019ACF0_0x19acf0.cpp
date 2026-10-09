#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019ACF0
// Address: 0x19acf0 - 0x19af78
void sub_0019ACF0_0x19acf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019ACF0_0x19acf0");
#endif

    switch (ctx->pc) {
        case 0x19ad1cu: goto label_19ad1c;
        case 0x19adecu: goto label_19adec;
        case 0x19ae1cu: goto label_19ae1c;
        case 0x19ae40u: goto label_19ae40;
        case 0x19ae8cu: goto label_19ae8c;
        case 0x19af38u: goto label_19af38;
        case 0x19af48u: goto label_19af48;
        default: break;
    }

    ctx->pc = 0x19acf0u;

    // 0x19acf0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x19acf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19acf4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19acf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19acf8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19acf8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19acfc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19acfcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19ad00: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19ad00u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ad04: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19ad04u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19ad08: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19ad08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ad0c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19ad0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ad10: 0x24040f70  addiu       $a0, $zero, 0xF70
    ctx->pc = 0x19ad10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3952));
    // 0x19ad14: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19AD14u;
    SET_GPR_U32(ctx, 31, 0x19AD1Cu);
    ctx->pc = 0x19AD18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AD14u;
            // 0x19ad18: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AD1Cu; }
        if (ctx->pc != 0x19AD1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AD1Cu; }
        if (ctx->pc != 0x19AD1Cu) { return; }
    }
    ctx->pc = 0x19AD1Cu;
label_19ad1c:
    // 0x19ad1c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19ad1cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19ad20: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19ad20u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19ad24: 0x346400f6  ori         $a0, $v1, 0xF6
    ctx->pc = 0x19ad24u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)246);
    // 0x19ad28: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19ad28u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19ad2c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19ad2cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19ad30: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19ad30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19ad34: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19ad34u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19ad38: 0x34650404  ori         $a1, $v1, 0x404
    ctx->pc = 0x19ad38u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19ad3c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19ad3cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19ad40: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19ad40u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19ad44: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19ad44u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19ad48: 0x3c046cf4  lui         $a0, 0x6CF4
    ctx->pc = 0x19ad48u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)27892 << 16));
    // 0x19ad4c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19ad4cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19ad50: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19ad50u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19ad54: 0xac450018  sw          $a1, 0x18($v0)
    ctx->pc = 0x19ad54u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19ad58: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ad58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ad5c: 0xac44001c  sw          $a0, 0x1C($v0)
    ctx->pc = 0x19ad5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19ad60: 0x24e74d40  addiu       $a3, $a3, 0x4D40
    ctx->pc = 0x19ad60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19ad64: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19ad64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19ad68: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19ad68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ad6c: 0x24460040  addiu       $a2, $v0, 0x40
    ctx->pc = 0x19ad6cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19ad70: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19ad70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x19ad74: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19ad74u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ad78: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ad78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ad7c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19ad7cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ad80: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19ad80u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19ad84: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19ad84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19ad88: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19ad88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ad8c: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19ad8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ad90: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ad90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ad94: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19ad94u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ad98: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19ad98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19ad9c: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19ad9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19ada0: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19ada0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ada4: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19ada4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ada8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ada8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19adac: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19adacu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19adb0: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19adb0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19adb4: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19adb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19adb8: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19adb8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19adbc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19adbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19adc0: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19adc0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19adc4: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19adc4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19adc8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19adc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19adcc: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19adccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19add0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19add0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19add4: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19add4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19add8: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19add8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19addc: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19addcu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19ade0: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19ade0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19ade4: 0xac400038  sw          $zero, 0x38($v0)
    ctx->pc = 0x19ade4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19ade8: 0xac40003c  sw          $zero, 0x3C($v0)
    ctx->pc = 0x19ade8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
label_19adec:
    // 0x19adec: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19adecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19adf0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19adf0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19adf4: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19adf4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19adf8: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19adf8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19adfc: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19adfcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19ae00: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19ae00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19ae04: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19AE04u;
    {
        const bool branch_taken_0x19ae04 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19AE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19AE04u;
            // 0x19ae08: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ae04) {
            ctx->pc = 0x19ADECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19adec;
        }
    }
    ctx->pc = 0x19AE0Cu;
    // 0x19ae0c: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19ae0cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19ae10: 0x24460080  addiu       $a2, $v0, 0x80
    ctx->pc = 0x19ae10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19ae14: 0x24e74d00  addiu       $a3, $a3, 0x4D00
    ctx->pc = 0x19ae14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19ae18: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19ae18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19ae1c:
    // 0x19ae1c: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19ae1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19ae20: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19ae20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19ae24: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19ae24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19ae28: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19ae28u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19ae2c: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19ae2cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19ae30: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19ae30u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19ae34: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19AE34u;
    {
        const bool branch_taken_0x19ae34 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19AE38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19AE34u;
            // 0x19ae38: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ae34) {
            ctx->pc = 0x19AE1Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19ae1c;
        }
    }
    ctx->pc = 0x19AE3Cu;
    // 0x19ae3c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x19ae3cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19ae40:
    // 0x19ae40: 0x8e430054  lw          $v1, 0x54($s2)
    ctx->pc = 0x19ae40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19ae44: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x19ae44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19ae48: 0x1042004  sllv        $a0, $a0, $t0
    ctx->pc = 0x19ae48u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19ae4c: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x19ae4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x19ae50: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x19AE50u;
    {
        const bool branch_taken_0x19ae50 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x19AE54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19AE50u;
            // 0x19ae54: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ae50) {
            ctx->pc = 0x19AE8Cu;
            goto label_19ae8c;
        }
    }
    ctx->pc = 0x19AE58u;
    // 0x19ae58: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19ae58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19ae5c: 0x682021  addu        $a0, $v1, $t0
    ctx->pc = 0x19ae5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19ae60: 0x83180  sll         $a2, $t0, 6
    ctx->pc = 0x19ae60u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 8), 6));
    // 0x19ae64: 0x461821  addu        $v1, $v0, $a2
    ctx->pc = 0x19ae64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19ae68: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x19ae68u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x19ae6c: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x19ae6cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x19ae70: 0x24650160  addiu       $a1, $v1, 0x160
    ctx->pc = 0x19ae70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 352));
    // 0x19ae74: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x19ae74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19ae78: 0xc13021  addu        $a2, $a2, $at
    ctx->pc = 0x19ae78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19ae7c: 0x24640960  addiu       $a0, $v1, 0x960
    ctx->pc = 0x19ae7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2400));
    // 0x19ae80: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19ae80u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19ae84: 0xc066538  jal         func_1994E0
    ctx->pc = 0x19AE84u;
    SET_GPR_U32(ctx, 31, 0x19AE8Cu);
    ctx->pc = 0x19AE88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AE84u;
            // 0x19ae88: 0x34673f40  ori         $a3, $v1, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1994E0u;
    if (runtime->hasFunction(0x1994E0u)) {
        auto targetFn = runtime->lookupFunction(0x1994E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AE8Cu; }
        if (ctx->pc != 0x19AE8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AE8Cu; }
        if (ctx->pc != 0x19AE8Cu) { return; }
    }
    ctx->pc = 0x19AE8Cu;
label_19ae8c:
    // 0x19ae8c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x19ae8cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x19ae90: 0x29030020  slti        $v1, $t0, 0x20
    ctx->pc = 0x19ae90u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x19ae94: 0x1460ffea  bnez        $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x19AE94u;
    {
        const bool branch_taken_0x19ae94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19AE98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19AE94u;
            // 0x19ae98: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ae94) {
            ctx->pc = 0x19AE40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19ae40;
        }
    }
    ctx->pc = 0x19AE9Cu;
    // 0x19ae9c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19ae9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19aea0: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19aea0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19aea4: 0xafa3004c  sw          $v1, 0x4C($sp)
    ctx->pc = 0x19aea4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19aea8: 0xafa3005c  sw          $v1, 0x5C($sp)
    ctx->pc = 0x19aea8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19aeac: 0x244400c0  addiu       $a0, $v0, 0xC0
    ctx->pc = 0x19aeacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
    // 0x19aeb0: 0xafa3006c  sw          $v1, 0x6C($sp)
    ctx->pc = 0x19aeb0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19aeb4: 0x244500f0  addiu       $a1, $v0, 0xF0
    ctx->pc = 0x19aeb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 240));
    // 0x19aeb8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19aeb8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19aebc: 0x27a70040  addiu       $a3, $sp, 0x40
    ctx->pc = 0x19aebcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19aec0: 0x34663f40  ori         $a2, $v1, 0x3F40
    ctx->pc = 0x19aec0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19aec4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aec4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aec8: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19aec8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aecc: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19aeccu;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19aed0: 0xe7a10040  swc1        $f1, 0x40($sp)
    ctx->pc = 0x19aed0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19aed4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aed4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aed8: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19aed8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19aedc: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19aedcu;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19aee0: 0xe7a50044  swc1        $f5, 0x44($sp)
    ctx->pc = 0x19aee0u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19aee4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aee4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aee8: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19aee8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19aeec: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19aeecu;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19aef0: 0xe7a40048  swc1        $f4, 0x48($sp)
    ctx->pc = 0x19aef0u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19aef4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aef4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aef8: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19aef8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19aefc: 0xe7a30050  swc1        $f3, 0x50($sp)
    ctx->pc = 0x19aefcu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19af00: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19af00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19af04: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19af04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19af08: 0xe7a20054  swc1        $f2, 0x54($sp)
    ctx->pc = 0x19af08u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19af0c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19af0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19af10: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19af10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19af14: 0xe7a10058  swc1        $f1, 0x58($sp)
    ctx->pc = 0x19af14u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19af18: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19af18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19af1c: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19af1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19af20: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x19af20u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19af24: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19af24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19af28: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19af28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19af2c: 0xe7a10064  swc1        $f1, 0x64($sp)
    ctx->pc = 0x19af2cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19af30: 0xc06661c  jal         func_199870
    ctx->pc = 0x19AF30u;
    SET_GPR_U32(ctx, 31, 0x19AF38u);
    ctx->pc = 0x19AF34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AF30u;
            // 0x19af34: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199870u;
    if (runtime->hasFunction(0x199870u)) {
        auto targetFn = runtime->lookupFunction(0x199870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AF38u; }
        if (ctx->pc != 0x19AF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AF38u; }
        if (ctx->pc != 0x19AF38u) { return; }
    }
    ctx->pc = 0x19AF38u;
label_19af38:
    // 0x19af38: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19af38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19af3c: 0xc46c0024  lwc1        $f12, 0x24($v1)
    ctx->pc = 0x19af3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19af40: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19AF40u;
    SET_GPR_U32(ctx, 31, 0x19AF48u);
    ctx->pc = 0x19AF44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AF40u;
            // 0x19af44: 0x24440100  addiu       $a0, $v0, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AF48u; }
        if (ctx->pc != 0x19AF48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AF48u; }
        if (ctx->pc != 0x19AF48u) { return; }
    }
    ctx->pc = 0x19AF48u;
label_19af48:
    // 0x19af48: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19af48u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19af4c: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19af4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19af50: 0xac430f60  sw          $v1, 0xF60($v0)
    ctx->pc = 0x19af50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3936), GPR_U32(ctx, 3));
    // 0x19af54: 0xac400f64  sw          $zero, 0xF64($v0)
    ctx->pc = 0x19af54u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3940), GPR_U32(ctx, 0));
    // 0x19af58: 0xac400f68  sw          $zero, 0xF68($v0)
    ctx->pc = 0x19af58u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3944), GPR_U32(ctx, 0));
    // 0x19af5c: 0xac400f6c  sw          $zero, 0xF6C($v0)
    ctx->pc = 0x19af5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3948), GPR_U32(ctx, 0));
    // 0x19af60: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19af60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19af64: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19af64u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19af68: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19af68u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19af6c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19af6cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19af70: 0x3e00008  jr          $ra
    ctx->pc = 0x19AF70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19AF74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19AF70u;
            // 0x19af74: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19AD1Cu: goto label_19ad1c;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19AF38u: goto label_19af38;
            case 0x19AF48u: goto label_19af48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19AF78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
