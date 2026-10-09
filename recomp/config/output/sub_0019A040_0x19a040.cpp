#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019A040
// Address: 0x19a040 - 0x19a15c
void sub_0019A040_0x19a040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019A040_0x19a040");
#endif

    switch (ctx->pc) {
        case 0x19a06cu: goto label_19a06c;
        case 0x19a114u: goto label_19a114;
        case 0x19a124u: goto label_19a124;
        case 0x19a12cu: goto label_19a12c;
        default: break;
    }

    ctx->pc = 0x19a040u;

    // 0x19a040: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19a040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a044: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19a044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a048: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19a048u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a04c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19a04cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a050: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19a050u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a054: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19a054u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a058: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19a058u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a05c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19a05cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a060: 0x240400f0  addiu       $a0, $zero, 0xF0
    ctx->pc = 0x19a060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
    // 0x19a064: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19A064u;
    SET_GPR_U32(ctx, 31, 0x19A06Cu);
    ctx->pc = 0x19A068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A064u;
            // 0x19a068: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A06Cu; }
        if (ctx->pc != 0x19A06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A06Cu; }
        if (ctx->pc != 0x19A06Cu) { return; }
    }
    ctx->pc = 0x19A06Cu;
label_19a06c:
    // 0x19a06c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19a06cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19a070: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19a070u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19a074: 0x3464000e  ori         $a0, $v1, 0xE
    ctx->pc = 0x19a074u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14);
    // 0x19a078: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19a078u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19a07c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19a07cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a080: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19a080u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19a084: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19a084u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a088: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19a088u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19a08c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19a08cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a090: 0x3c076c0c  lui         $a3, 0x6C0C
    ctx->pc = 0x19a090u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27660 << 16));
    // 0x19a094: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19a094u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a098: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19a098u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19a09c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19a09cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a0a0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a0a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a0a4: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19a0a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a0a8: 0x24440030  addiu       $a0, $v0, 0x30
    ctx->pc = 0x19a0a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x19a0ac: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19a0acu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a0b0: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19a0b0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19a0b4: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19a0b4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19a0b8: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x19a0b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a0bc: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a0bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a0c0: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19a0c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a0c4: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19a0c4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a0c8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a0c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a0cc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a0ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a0d0: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a0d0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a0d4: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19a0d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a0d8: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a0dc: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19a0dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a0e0: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a0e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a0e4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a0e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a0e8: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a0e8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a0ec: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19a0ecu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a0f0: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a0f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a0f4: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19a0f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a0f8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a0f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a0fc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a0fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a100: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a100u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a104: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19a104u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a108: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19a108u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a10c: 0xc066500  jal         func_199400
    ctx->pc = 0x19A10Cu;
    SET_GPR_U32(ctx, 31, 0x19A114u);
    ctx->pc = 0x19A110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A10Cu;
            // 0x19a110: 0xe440002c  swc1        $f0, 0x2C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A114u; }
        if (ctx->pc != 0x19A114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A114u; }
        if (ctx->pc != 0x19A114u) { return; }
    }
    ctx->pc = 0x19A114u;
label_19a114:
    // 0x19a114: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19a114u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19a118: 0x24440070  addiu       $a0, $v0, 0x70
    ctx->pc = 0x19a118u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 112));
    // 0x19a11c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19A11Cu;
    SET_GPR_U32(ctx, 31, 0x19A124u);
    ctx->pc = 0x19A120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A11Cu;
            // 0x19a120: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A124u; }
        if (ctx->pc != 0x19A124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A124u; }
        if (ctx->pc != 0x19A124u) { return; }
    }
    ctx->pc = 0x19A124u;
label_19a124:
    // 0x19a124: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19A124u;
    SET_GPR_U32(ctx, 31, 0x19A12Cu);
    ctx->pc = 0x19A128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A124u;
            // 0x19a128: 0x244400b0  addiu       $a0, $v0, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A12Cu; }
        if (ctx->pc != 0x19A12Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A12Cu; }
        if (ctx->pc != 0x19A12Cu) { return; }
    }
    ctx->pc = 0x19A12Cu;
label_19a12c:
    // 0x19a12c: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19a12cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19a130: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19a130u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19a134: 0xac4300e0  sw          $v1, 0xE0($v0)
    ctx->pc = 0x19a134u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 224), GPR_U32(ctx, 3));
    // 0x19a138: 0xac4000e4  sw          $zero, 0xE4($v0)
    ctx->pc = 0x19a138u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 228), GPR_U32(ctx, 0));
    // 0x19a13c: 0xac4000e8  sw          $zero, 0xE8($v0)
    ctx->pc = 0x19a13cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 232), GPR_U32(ctx, 0));
    // 0x19a140: 0xac4000ec  sw          $zero, 0xEC($v0)
    ctx->pc = 0x19a140u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 236), GPR_U32(ctx, 0));
    // 0x19a144: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19a144u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a148: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19a148u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a14c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19a14cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a150: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19a150u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a154: 0x3e00008  jr          $ra
    ctx->pc = 0x19A154u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19A154u;
            // 0x19a158: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19A06Cu: goto label_19a06c;
            case 0x19A114u: goto label_19a114;
            case 0x19A124u: goto label_19a124;
            case 0x19A12Cu: goto label_19a12c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A15Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
