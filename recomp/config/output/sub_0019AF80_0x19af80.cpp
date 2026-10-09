#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019AF80
// Address: 0x19af80 - 0x19b1bc
void sub_0019AF80_0x19af80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019AF80_0x19af80");
#endif

    switch (ctx->pc) {
        case 0x19afb0u: goto label_19afb0;
        case 0x19b094u: goto label_19b094;
        case 0x19b0a4u: goto label_19b0a4;
        case 0x19b0b4u: goto label_19b0b4;
        case 0x19b174u: goto label_19b174;
        case 0x19b184u: goto label_19b184;
        default: break;
    }

    ctx->pc = 0x19af80u;

    // 0x19af80: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x19af80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19af84: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x19af84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19af88: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19af88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19af8c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19af8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19af90: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x19af90u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19af94: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19af94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19af98: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x19af98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19af9c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x19af9cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19afa0: 0x240401b0  addiu       $a0, $zero, 0x1B0
    ctx->pc = 0x19afa0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 432));
    // 0x19afa4: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x19afa4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19afa8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19AFA8u;
    SET_GPR_U32(ctx, 31, 0x19AFB0u);
    ctx->pc = 0x19AFACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AFA8u;
            // 0x19afac: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AFB0u; }
        if (ctx->pc != 0x19AFB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AFB0u; }
        if (ctx->pc != 0x19AFB0u) { return; }
    }
    ctx->pc = 0x19AFB0u;
label_19afb0:
    // 0x19afb0: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19afb0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19afb4: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19afb4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19afb8: 0x3463001a  ori         $v1, $v1, 0x1A
    ctx->pc = 0x19afb8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)26);
    // 0x19afbc: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19afbcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19afc0: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19afc0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19afc4: 0x3c056c18  lui         $a1, 0x6C18
    ctx->pc = 0x19afc4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)27672 << 16));
    // 0x19afc8: 0xac510004  sw          $s1, 0x4($v0)
    ctx->pc = 0x19afc8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19afcc: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19afccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19afd0: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19afd0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19afd4: 0x34640404  ori         $a0, $v1, 0x404
    ctx->pc = 0x19afd4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19afd8: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19afd8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19afdc: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19afdcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19afe0: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19afe0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19afe4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19afe4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19afe8: 0xac440018  sw          $a0, 0x18($v0)
    ctx->pc = 0x19afe8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19afec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x19afecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19aff0: 0xac45001c  sw          $a1, 0x1C($v0)
    ctx->pc = 0x19aff0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19aff4: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19aff4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19aff8: 0x8e69004c  lw          $t1, 0x4C($s3)
    ctx->pc = 0x19aff8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19affc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19affcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b000: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19b000u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b004: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19b004u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19b008: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19b008u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19b00c: 0x26040040  addiu       $a0, $s0, 0x40
    ctx->pc = 0x19b00cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x19b010: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x19b010u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x19b014: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19b014u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19b018: 0xc5210024  lwc1        $f1, 0x24($t1)
    ctx->pc = 0x19b018u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b01c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b01cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b020: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b020u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b024: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19b024u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19b028: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19b028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b02c: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19b02cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b030: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b030u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b034: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b034u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b038: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b038u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b03c: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19b03cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19b040: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19b040u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b044: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19b044u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b048: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b048u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b04c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b04cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b050: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b050u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b054: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19b054u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19b058: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19b058u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b05c: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19b05cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19b060: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b060u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b064: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19b064u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b068: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19b068u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19b06c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b06cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b070: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19b070u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b074: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b074u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b078: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19b078u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b07c: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19b07cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19b080: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19b080u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19b084: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19b084u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19b088: 0xac400038  sw          $zero, 0x38($v0)
    ctx->pc = 0x19b088u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19b08c: 0xc066500  jal         func_199400
    ctx->pc = 0x19B08Cu;
    SET_GPR_U32(ctx, 31, 0x19B094u);
    ctx->pc = 0x19B090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B08Cu;
            // 0x19b090: 0xac40003c  sw          $zero, 0x3C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B094u; }
        if (ctx->pc != 0x19B094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B094u; }
        if (ctx->pc != 0x19B094u) { return; }
    }
    ctx->pc = 0x19B094u;
label_19b094:
    // 0x19b094: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19b094u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19b098: 0x26040080  addiu       $a0, $s0, 0x80
    ctx->pc = 0x19b098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
    // 0x19b09c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19B09Cu;
    SET_GPR_U32(ctx, 31, 0x19B0A4u);
    ctx->pc = 0x19B0A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B09Cu;
            // 0x19b0a0: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B0A4u; }
        if (ctx->pc != 0x19B0A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B0A4u; }
        if (ctx->pc != 0x19B0A4u) { return; }
    }
    ctx->pc = 0x19B0A4u;
label_19b0a4:
    // 0x19b0a4: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19b0a4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19b0a8: 0x260500c0  addiu       $a1, $s0, 0xC0
    ctx->pc = 0x19b0a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 192));
    // 0x19b0ac: 0x24c64cc0  addiu       $a2, $a2, 0x4CC0
    ctx->pc = 0x19b0acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19648));
    // 0x19b0b0: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x19b0b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19b0b4:
    // 0x19b0b4: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x19b0b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x19b0b8: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x19b0b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19b0bc: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x19b0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19b0c0: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x19b0c0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x19b0c4: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x19b0c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x19b0c8: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x19b0c8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x19b0cc: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19B0CCu;
    {
        const bool branch_taken_0x19b0cc = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x19B0D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B0CCu;
            // 0x19b0d0: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19b0cc) {
            ctx->pc = 0x19B0B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19b0b4;
        }
    }
    ctx->pc = 0x19B0D4u;
    // 0x19b0d4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b0d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b0d8: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x19b0d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19b0dc: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19b0dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b0e0: 0xafa2005c  sw          $v0, 0x5C($sp)
    ctx->pc = 0x19b0e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19b0e4: 0xafa2006c  sw          $v0, 0x6C($sp)
    ctx->pc = 0x19b0e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x19b0e8: 0x26040100  addiu       $a0, $s0, 0x100
    ctx->pc = 0x19b0e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
    // 0x19b0ec: 0xafa2007c  sw          $v0, 0x7C($sp)
    ctx->pc = 0x19b0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 2));
    // 0x19b0f0: 0x26050130  addiu       $a1, $s0, 0x130
    ctx->pc = 0x19b0f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 304));
    // 0x19b0f4: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19b0f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x19b0f8: 0x27a70050  addiu       $a3, $sp, 0x50
    ctx->pc = 0x19b0f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19b0fc: 0x34463700  ori         $a2, $v0, 0x3700
    ctx->pc = 0x19b0fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x19b100: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b100u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b104: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19b104u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b108: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19b108u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19b10c: 0xe7a10050  swc1        $f1, 0x50($sp)
    ctx->pc = 0x19b10cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19b110: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b110u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b114: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19b114u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19b118: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19b118u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19b11c: 0xe7a50054  swc1        $f5, 0x54($sp)
    ctx->pc = 0x19b11cu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19b120: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b120u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b124: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19b124u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19b128: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19b128u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19b12c: 0xe7a40058  swc1        $f4, 0x58($sp)
    ctx->pc = 0x19b12cu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19b130: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b130u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b134: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19b134u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b138: 0xe7a30060  swc1        $f3, 0x60($sp)
    ctx->pc = 0x19b138u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19b13c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b13cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b140: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19b140u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b144: 0xe7a20064  swc1        $f2, 0x64($sp)
    ctx->pc = 0x19b144u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19b148: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b148u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b14c: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19b14cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b150: 0xe7a10068  swc1        $f1, 0x68($sp)
    ctx->pc = 0x19b150u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x19b154: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b154u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b158: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19b158u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b15c: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x19b15cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x19b160: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b160u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b164: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19b164u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b168: 0xe7a10074  swc1        $f1, 0x74($sp)
    ctx->pc = 0x19b168u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x19b16c: 0xc0665d0  jal         func_199740
    ctx->pc = 0x19B16Cu;
    SET_GPR_U32(ctx, 31, 0x19B174u);
    ctx->pc = 0x19B170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B16Cu;
            // 0x19b170: 0xe7a00078  swc1        $f0, 0x78($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199740u;
    if (runtime->hasFunction(0x199740u)) {
        auto targetFn = runtime->lookupFunction(0x199740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B174u; }
        if (ctx->pc != 0x19B174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199740_0x199740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B174u; }
        if (ctx->pc != 0x19B174u) { return; }
    }
    ctx->pc = 0x19B174u;
label_19b174:
    // 0x19b174: 0x8e62004c  lw          $v0, 0x4C($s3)
    ctx->pc = 0x19b174u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b178: 0xc44c0024  lwc1        $f12, 0x24($v0)
    ctx->pc = 0x19b178u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19b17c: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19B17Cu;
    SET_GPR_U32(ctx, 31, 0x19B184u);
    ctx->pc = 0x19B180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B17Cu;
            // 0x19b180: 0x26040140  addiu       $a0, $s0, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B184u; }
        if (ctx->pc != 0x19B184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B184u; }
        if (ctx->pc != 0x19B184u) { return; }
    }
    ctx->pc = 0x19B184u;
label_19b184:
    // 0x19b184: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19b184u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19b188: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x19b188u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b18c: 0x2431825  or          $v1, $s2, $v1
    ctx->pc = 0x19b18cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) | GPR_U64(ctx, 3));
    // 0x19b190: 0xae0301a0  sw          $v1, 0x1A0($s0)
    ctx->pc = 0x19b190u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 3));
    // 0x19b194: 0xae0001a4  sw          $zero, 0x1A4($s0)
    ctx->pc = 0x19b194u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 0));
    // 0x19b198: 0xae0001a8  sw          $zero, 0x1A8($s0)
    ctx->pc = 0x19b198u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 0));
    // 0x19b19c: 0xae0001ac  sw          $zero, 0x1AC($s0)
    ctx->pc = 0x19b19cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 0));
    // 0x19b1a0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x19b1a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19b1a4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19b1a4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19b1a8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19b1a8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19b1ac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19b1acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19b1b0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19b1b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19b1b4: 0x3e00008  jr          $ra
    ctx->pc = 0x19B1B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19B1B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B1B4u;
            // 0x19b1b8: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19AFB0u: goto label_19afb0;
            case 0x19B094u: goto label_19b094;
            case 0x19B0A4u: goto label_19b0a4;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B174u: goto label_19b174;
            case 0x19B184u: goto label_19b184;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19B1BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
