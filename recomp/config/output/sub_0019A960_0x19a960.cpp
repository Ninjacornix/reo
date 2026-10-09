#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019A960
// Address: 0x19a960 - 0x19aad4
void sub_0019A960_0x19a960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019A960_0x19a960");
#endif

    switch (ctx->pc) {
        case 0x19a98cu: goto label_19a98c;
        case 0x19aa64u: goto label_19aa64;
        case 0x19aa74u: goto label_19aa74;
        case 0x19aa84u: goto label_19aa84;
        default: break;
    }

    ctx->pc = 0x19a960u;

    // 0x19a960: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19a960u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a964: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19a964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a968: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19a968u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a96c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19a96cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a970: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19a970u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a974: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19a974u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a978: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19a978u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a97c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19a97cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a980: 0x24040110  addiu       $a0, $zero, 0x110
    ctx->pc = 0x19a980u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 272));
    // 0x19a984: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19A984u;
    SET_GPR_U32(ctx, 31, 0x19A98Cu);
    ctx->pc = 0x19A988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A984u;
            // 0x19a988: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A98Cu; }
        if (ctx->pc != 0x19A98Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A98Cu; }
        if (ctx->pc != 0x19A98Cu) { return; }
    }
    ctx->pc = 0x19A98Cu;
label_19a98c:
    // 0x19a98c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19a98cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19a990: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19a990u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19a994: 0x34640010  ori         $a0, $v1, 0x10
    ctx->pc = 0x19a994u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16);
    // 0x19a998: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19a998u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19a99c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19a99cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a9a0: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19a9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19a9a4: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19a9a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a9a8: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19a9a8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19a9ac: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19a9acu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a9b0: 0x3c076c0e  lui         $a3, 0x6C0E
    ctx->pc = 0x19a9b0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27662 << 16));
    // 0x19a9b4: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19a9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a9b8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19a9b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19a9bc: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19a9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a9c0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a9c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a9c4: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19a9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a9c8: 0x24440040  addiu       $a0, $v0, 0x40
    ctx->pc = 0x19a9c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a9cc: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19a9ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a9d0: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19a9d0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19a9d4: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19a9d4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19a9d8: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x19a9d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a9dc: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a9dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a9e0: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19a9e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a9e4: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19a9e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a9e8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a9e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a9ec: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a9ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a9f0: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a9f0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a9f4: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19a9f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a9f8: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a9f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a9fc: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19a9fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19aa00: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19aa00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa04: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aa04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aa08: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19aa08u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19aa0c: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19aa0cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19aa10: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19aa10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19aa14: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19aa14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19aa18: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19aa18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa1c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aa1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aa20: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19aa20u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19aa24: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19aa24u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19aa28: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19aa28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa2c: 0xe440002c  swc1        $f0, 0x2C($v0)
    ctx->pc = 0x19aa2cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19aa30: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aa30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aa34: 0xc4204e40  lwc1        $f0, 0x4E40($at)
    ctx->pc = 0x19aa34u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa38: 0xe4400030  swc1        $f0, 0x30($v0)
    ctx->pc = 0x19aa38u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19aa3c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aa3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aa40: 0xc4204e44  lwc1        $f0, 0x4E44($at)
    ctx->pc = 0x19aa40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa44: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19aa44u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19aa48: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aa48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aa4c: 0xc4204e48  lwc1        $f0, 0x4E48($at)
    ctx->pc = 0x19aa4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa50: 0xe4400038  swc1        $f0, 0x38($v0)
    ctx->pc = 0x19aa50u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19aa54: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19aa54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19aa58: 0xc4204e4c  lwc1        $f0, 0x4E4C($at)
    ctx->pc = 0x19aa58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa5c: 0xc066500  jal         func_199400
    ctx->pc = 0x19AA5Cu;
    SET_GPR_U32(ctx, 31, 0x19AA64u);
    ctx->pc = 0x19AA60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AA5Cu;
            // 0x19aa60: 0xe440003c  swc1        $f0, 0x3C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AA64u; }
        if (ctx->pc != 0x19AA64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AA64u; }
        if (ctx->pc != 0x19AA64u) { return; }
    }
    ctx->pc = 0x19AA64u;
label_19aa64:
    // 0x19aa64: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19aa64u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19aa68: 0x24440080  addiu       $a0, $v0, 0x80
    ctx->pc = 0x19aa68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19aa6c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19AA6Cu;
    SET_GPR_U32(ctx, 31, 0x19AA74u);
    ctx->pc = 0x19AA70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AA6Cu;
            // 0x19aa70: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AA74u; }
        if (ctx->pc != 0x19AA74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AA74u; }
        if (ctx->pc != 0x19AA74u) { return; }
    }
    ctx->pc = 0x19AA74u;
label_19aa74:
    // 0x19aa74: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19aa74u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19aa78: 0x244600c0  addiu       $a2, $v0, 0xC0
    ctx->pc = 0x19aa78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
    // 0x19aa7c: 0x24e74cc0  addiu       $a3, $a3, 0x4CC0
    ctx->pc = 0x19aa7cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19648));
    // 0x19aa80: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19aa80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19aa84:
    // 0x19aa84: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19aa84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19aa88: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19aa88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19aa8c: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19aa8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19aa90: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19aa90u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19aa94: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19aa94u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19aa98: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19aa98u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19aa9c: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19AA9Cu;
    {
        const bool branch_taken_0x19aa9c = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19AAA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19AA9Cu;
            // 0x19aaa0: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19aa9c) {
            ctx->pc = 0x19AA84u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19aa84;
        }
    }
    ctx->pc = 0x19AAA4u;
    // 0x19aaa4: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19aaa4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19aaa8: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19aaa8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19aaac: 0xac430100  sw          $v1, 0x100($v0)
    ctx->pc = 0x19aaacu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 256), GPR_U32(ctx, 3));
    // 0x19aab0: 0xac400104  sw          $zero, 0x104($v0)
    ctx->pc = 0x19aab0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 260), GPR_U32(ctx, 0));
    // 0x19aab4: 0xac400108  sw          $zero, 0x108($v0)
    ctx->pc = 0x19aab4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 264), GPR_U32(ctx, 0));
    // 0x19aab8: 0xac40010c  sw          $zero, 0x10C($v0)
    ctx->pc = 0x19aab8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 268), GPR_U32(ctx, 0));
    // 0x19aabc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19aabcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19aac0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19aac0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19aac4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19aac4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19aac8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19aac8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19aacc: 0x3e00008  jr          $ra
    ctx->pc = 0x19AACCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19AAD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19AACCu;
            // 0x19aad0: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19A98Cu: goto label_19a98c;
            case 0x19AA64u: goto label_19aa64;
            case 0x19AA74u: goto label_19aa74;
            case 0x19AA84u: goto label_19aa84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19AAD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
