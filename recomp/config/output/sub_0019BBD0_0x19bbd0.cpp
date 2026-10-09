#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019BBD0
// Address: 0x19bbd0 - 0x19be94
void sub_0019BBD0_0x19bbd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019BBD0_0x19bbd0");
#endif

    switch (ctx->pc) {
        case 0x19bbfcu: goto label_19bbfc;
        case 0x19bcfcu: goto label_19bcfc;
        case 0x19bd2cu: goto label_19bd2c;
        case 0x19bd50u: goto label_19bd50;
        case 0x19bd9cu: goto label_19bd9c;
        case 0x19bdb4u: goto label_19bdb4;
        case 0x19be54u: goto label_19be54;
        case 0x19be64u: goto label_19be64;
        default: break;
    }

    ctx->pc = 0x19bbd0u;

    // 0x19bbd0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x19bbd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19bbd4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19bbd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19bbd8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19bbd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19bbdc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19bbdcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19bbe0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19bbe0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bbe4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19bbe4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19bbe8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19bbe8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bbec: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19bbecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bbf0: 0x24040fb0  addiu       $a0, $zero, 0xFB0
    ctx->pc = 0x19bbf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4016));
    // 0x19bbf4: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19BBF4u;
    SET_GPR_U32(ctx, 31, 0x19BBFCu);
    ctx->pc = 0x19BBF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BBF4u;
            // 0x19bbf8: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BBFCu; }
        if (ctx->pc != 0x19BBFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BBFCu; }
        if (ctx->pc != 0x19BBFCu) { return; }
    }
    ctx->pc = 0x19BBFCu;
label_19bbfc:
    // 0x19bbfc: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19bbfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19bc00: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19bc00u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19bc04: 0x346400fa  ori         $a0, $v1, 0xFA
    ctx->pc = 0x19bc04u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)250);
    // 0x19bc08: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19bc08u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19bc0c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19bc0cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19bc10: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19bc10u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19bc14: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19bc14u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19bc18: 0x34650404  ori         $a1, $v1, 0x404
    ctx->pc = 0x19bc18u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19bc1c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19bc1cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19bc20: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19bc20u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19bc24: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19bc24u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19bc28: 0x3c046cf8  lui         $a0, 0x6CF8
    ctx->pc = 0x19bc28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)27896 << 16));
    // 0x19bc2c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19bc2cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19bc30: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19bc30u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19bc34: 0xac450018  sw          $a1, 0x18($v0)
    ctx->pc = 0x19bc34u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19bc38: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bc38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bc3c: 0xac44001c  sw          $a0, 0x1C($v0)
    ctx->pc = 0x19bc3cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19bc40: 0x24e74d40  addiu       $a3, $a3, 0x4D40
    ctx->pc = 0x19bc40u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19bc44: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19bc44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19bc48: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19bc48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bc4c: 0x24460050  addiu       $a2, $v0, 0x50
    ctx->pc = 0x19bc4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 80));
    // 0x19bc50: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19bc50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x19bc54: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19bc54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bc58: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bc58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bc5c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19bc5cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bc60: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19bc60u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19bc64: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19bc64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19bc68: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19bc68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bc6c: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19bc6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bc70: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bc70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bc74: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19bc74u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bc78: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19bc78u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19bc7c: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19bc7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19bc80: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19bc80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bc84: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19bc84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bc88: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bc88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bc8c: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19bc8cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bc90: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19bc90u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19bc94: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19bc94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bc98: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19bc98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19bc9c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bc9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bca0: 0xc4214e40  lwc1        $f1, 0x4E40($at)
    ctx->pc = 0x19bca0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bca4: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19bca4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19bca8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bca8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bcac: 0xc4214e44  lwc1        $f1, 0x4E44($at)
    ctx->pc = 0x19bcacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bcb0: 0xe4410034  swc1        $f1, 0x34($v0)
    ctx->pc = 0x19bcb0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19bcb4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bcb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bcb8: 0xc4214e48  lwc1        $f1, 0x4E48($at)
    ctx->pc = 0x19bcb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bcbc: 0xe4410038  swc1        $f1, 0x38($v0)
    ctx->pc = 0x19bcbcu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19bcc0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bcc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bcc4: 0xc4214e4c  lwc1        $f1, 0x4E4C($at)
    ctx->pc = 0x19bcc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bcc8: 0xe441003c  swc1        $f1, 0x3C($v0)
    ctx->pc = 0x19bcc8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19bccc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19bcccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19bcd0: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19bcd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bcd4: 0xe4410040  swc1        $f1, 0x40($v0)
    ctx->pc = 0x19bcd4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19bcd8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19bcd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19bcdc: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19bcdcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bce0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19bce0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19bce4: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19bce4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bce8: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19bce8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19bcec: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19bcecu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19bcf0: 0xe4400044  swc1        $f0, 0x44($v0)
    ctx->pc = 0x19bcf0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19bcf4: 0xac400048  sw          $zero, 0x48($v0)
    ctx->pc = 0x19bcf4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19bcf8: 0xac40004c  sw          $zero, 0x4C($v0)
    ctx->pc = 0x19bcf8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
label_19bcfc:
    // 0x19bcfc: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19bcfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19bd00: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19bd00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19bd04: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19bd04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19bd08: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19bd08u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19bd0c: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19bd0cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19bd10: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19bd10u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19bd14: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19BD14u;
    {
        const bool branch_taken_0x19bd14 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19BD18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19BD14u;
            // 0x19bd18: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19bd14) {
            ctx->pc = 0x19BCFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19bcfc;
        }
    }
    ctx->pc = 0x19BD1Cu;
    // 0x19bd1c: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19bd1cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19bd20: 0x24460090  addiu       $a2, $v0, 0x90
    ctx->pc = 0x19bd20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 144));
    // 0x19bd24: 0x24e74d00  addiu       $a3, $a3, 0x4D00
    ctx->pc = 0x19bd24u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19bd28: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19bd28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19bd2c:
    // 0x19bd2c: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19bd2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19bd30: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19bd30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19bd34: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19bd34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19bd38: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19bd38u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19bd3c: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19bd3cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19bd40: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19bd40u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19bd44: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19BD44u;
    {
        const bool branch_taken_0x19bd44 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19BD48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19BD44u;
            // 0x19bd48: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19bd44) {
            ctx->pc = 0x19BD2Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19bd2c;
        }
    }
    ctx->pc = 0x19BD4Cu;
    // 0x19bd4c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x19bd4cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19bd50:
    // 0x19bd50: 0x8e430054  lw          $v1, 0x54($s2)
    ctx->pc = 0x19bd50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19bd54: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x19bd54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19bd58: 0x1042004  sllv        $a0, $a0, $t0
    ctx->pc = 0x19bd58u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19bd5c: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x19bd5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x19bd60: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x19BD60u;
    {
        const bool branch_taken_0x19bd60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x19BD64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19BD60u;
            // 0x19bd64: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19bd60) {
            ctx->pc = 0x19BD9Cu;
            goto label_19bd9c;
        }
    }
    ctx->pc = 0x19BD68u;
    // 0x19bd68: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19bd68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x19bd6c: 0x682021  addu        $a0, $v1, $t0
    ctx->pc = 0x19bd6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19bd70: 0x83180  sll         $a2, $t0, 6
    ctx->pc = 0x19bd70u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 8), 6));
    // 0x19bd74: 0x461821  addu        $v1, $v0, $a2
    ctx->pc = 0x19bd74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19bd78: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x19bd78u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x19bd7c: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x19bd7cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x19bd80: 0x246501a0  addiu       $a1, $v1, 0x1A0
    ctx->pc = 0x19bd80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 416));
    // 0x19bd84: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x19bd84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19bd88: 0xc13021  addu        $a2, $a2, $at
    ctx->pc = 0x19bd88u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19bd8c: 0x246409a0  addiu       $a0, $v1, 0x9A0
    ctx->pc = 0x19bd8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2464));
    // 0x19bd90: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19bd90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19bd94: 0xc066538  jal         func_1994E0
    ctx->pc = 0x19BD94u;
    SET_GPR_U32(ctx, 31, 0x19BD9Cu);
    ctx->pc = 0x19BD98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BD94u;
            // 0x19bd98: 0x34673f40  ori         $a3, $v1, 0x3F40 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1994E0u;
    if (runtime->hasFunction(0x1994E0u)) {
        auto targetFn = runtime->lookupFunction(0x1994E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BD9Cu; }
        if (ctx->pc != 0x19BD9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BD9Cu; }
        if (ctx->pc != 0x19BD9Cu) { return; }
    }
    ctx->pc = 0x19BD9Cu;
label_19bd9c:
    // 0x19bd9c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x19bd9cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x19bda0: 0x29030020  slti        $v1, $t0, 0x20
    ctx->pc = 0x19bda0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x19bda4: 0x1460ffea  bnez        $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x19BDA4u;
    {
        const bool branch_taken_0x19bda4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19BDA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19BDA4u;
            // 0x19bda8: 0x244400d0  addiu       $a0, $v0, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 208));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19bda4) {
            ctx->pc = 0x19BD50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19bd50;
        }
    }
    ctx->pc = 0x19BDACu;
    // 0x19bdac: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19BDACu;
    SET_GPR_U32(ctx, 31, 0x19BDB4u);
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BDB4u; }
        if (ctx->pc != 0x19BDB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BDB4u; }
        if (ctx->pc != 0x19BDB4u) { return; }
    }
    ctx->pc = 0x19BDB4u;
label_19bdb4:
    // 0x19bdb4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bdb4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bdb8: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19bdb8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19bdbc: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19bdbcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bdc0: 0xafa3004c  sw          $v1, 0x4C($sp)
    ctx->pc = 0x19bdc0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19bdc4: 0xafa3005c  sw          $v1, 0x5C($sp)
    ctx->pc = 0x19bdc4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19bdc8: 0x24440100  addiu       $a0, $v0, 0x100
    ctx->pc = 0x19bdc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
    // 0x19bdcc: 0xafa3006c  sw          $v1, 0x6C($sp)
    ctx->pc = 0x19bdccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19bdd0: 0x24450130  addiu       $a1, $v0, 0x130
    ctx->pc = 0x19bdd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 304));
    // 0x19bdd4: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19bdd4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19bdd8: 0x27a70040  addiu       $a3, $sp, 0x40
    ctx->pc = 0x19bdd8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19bddc: 0x34663f40  ori         $a2, $v1, 0x3F40
    ctx->pc = 0x19bddcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19bde0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bde0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bde4: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19bde4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19bde8: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19bde8u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19bdec: 0xe7a10040  swc1        $f1, 0x40($sp)
    ctx->pc = 0x19bdecu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19bdf0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bdf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bdf4: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19bdf4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19bdf8: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19bdf8u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19bdfc: 0xe7a50044  swc1        $f5, 0x44($sp)
    ctx->pc = 0x19bdfcu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19be00: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19be00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19be04: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19be04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19be08: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19be08u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19be0c: 0xe7a40048  swc1        $f4, 0x48($sp)
    ctx->pc = 0x19be0cu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19be10: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19be10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19be14: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19be14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19be18: 0xe7a30050  swc1        $f3, 0x50($sp)
    ctx->pc = 0x19be18u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19be1c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19be1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19be20: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19be20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19be24: 0xe7a20054  swc1        $f2, 0x54($sp)
    ctx->pc = 0x19be24u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19be28: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19be28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19be2c: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19be2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19be30: 0xe7a10058  swc1        $f1, 0x58($sp)
    ctx->pc = 0x19be30u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19be34: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19be34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19be38: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19be38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19be3c: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x19be3cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19be40: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19be40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19be44: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19be44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19be48: 0xe7a10064  swc1        $f1, 0x64($sp)
    ctx->pc = 0x19be48u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19be4c: 0xc06661c  jal         func_199870
    ctx->pc = 0x19BE4Cu;
    SET_GPR_U32(ctx, 31, 0x19BE54u);
    ctx->pc = 0x19BE50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BE4Cu;
            // 0x19be50: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199870u;
    if (runtime->hasFunction(0x199870u)) {
        auto targetFn = runtime->lookupFunction(0x199870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BE54u; }
        if (ctx->pc != 0x19BE54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BE54u; }
        if (ctx->pc != 0x19BE54u) { return; }
    }
    ctx->pc = 0x19BE54u;
label_19be54:
    // 0x19be54: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19be54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19be58: 0xc46c0024  lwc1        $f12, 0x24($v1)
    ctx->pc = 0x19be58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19be5c: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19BE5Cu;
    SET_GPR_U32(ctx, 31, 0x19BE64u);
    ctx->pc = 0x19BE60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BE5Cu;
            // 0x19be60: 0x24440140  addiu       $a0, $v0, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BE64u; }
        if (ctx->pc != 0x19BE64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BE64u; }
        if (ctx->pc != 0x19BE64u) { return; }
    }
    ctx->pc = 0x19BE64u;
label_19be64:
    // 0x19be64: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19be64u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19be68: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19be68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19be6c: 0xac430fa0  sw          $v1, 0xFA0($v0)
    ctx->pc = 0x19be6cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4000), GPR_U32(ctx, 3));
    // 0x19be70: 0xac400fa4  sw          $zero, 0xFA4($v0)
    ctx->pc = 0x19be70u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4004), GPR_U32(ctx, 0));
    // 0x19be74: 0xac400fa8  sw          $zero, 0xFA8($v0)
    ctx->pc = 0x19be74u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4008), GPR_U32(ctx, 0));
    // 0x19be78: 0xac400fac  sw          $zero, 0xFAC($v0)
    ctx->pc = 0x19be78u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4012), GPR_U32(ctx, 0));
    // 0x19be7c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19be7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19be80: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19be80u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19be84: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19be84u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19be88: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19be88u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19be8c: 0x3e00008  jr          $ra
    ctx->pc = 0x19BE8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19BE90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19BE8Cu;
            // 0x19be90: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19BBFCu: goto label_19bbfc;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19BDB4u: goto label_19bdb4;
            case 0x19BE54u: goto label_19be54;
            case 0x19BE64u: goto label_19be64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19BE94u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
