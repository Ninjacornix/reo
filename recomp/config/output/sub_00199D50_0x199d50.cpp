#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00199D50
// Address: 0x199d50 - 0x199e64
void sub_00199D50_0x199d50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00199D50_0x199d50");
#endif

    switch (ctx->pc) {
        case 0x199d7cu: goto label_199d7c;
        case 0x199e24u: goto label_199e24;
        case 0x199e34u: goto label_199e34;
        default: break;
    }

    ctx->pc = 0x199d50u;

    // 0x199d50: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x199d50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x199d54: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x199d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x199d58: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x199d58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x199d5c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x199d5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x199d60: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x199d60u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199d64: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x199d64u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x199d68: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x199d68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199d6c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x199d6cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199d70: 0x240400c0  addiu       $a0, $zero, 0xC0
    ctx->pc = 0x199d70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x199d74: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x199D74u;
    SET_GPR_U32(ctx, 31, 0x199D7Cu);
    ctx->pc = 0x199D78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x199D74u;
            // 0x199d78: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199D7Cu; }
        if (ctx->pc != 0x199D7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199D7Cu; }
        if (ctx->pc != 0x199D7Cu) { return; }
    }
    ctx->pc = 0x199D7Cu;
label_199d7c:
    // 0x199d7c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x199d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x199d80: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x199d80u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x199d84: 0x3464000b  ori         $a0, $v1, 0xB
    ctx->pc = 0x199d84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)11);
    // 0x199d88: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x199d88u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x199d8c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x199d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x199d90: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x199d90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x199d94: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x199d94u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x199d98: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x199d98u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x199d9c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x199d9cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x199da0: 0x3c076c09  lui         $a3, 0x6C09
    ctx->pc = 0x199da0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27657 << 16));
    // 0x199da4: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x199da4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x199da8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x199da8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x199dac: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x199dacu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x199db0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199db0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199db4: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x199db4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x199db8: 0x24440030  addiu       $a0, $v0, 0x30
    ctx->pc = 0x199db8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x199dbc: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x199dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x199dc0: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x199dc0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x199dc4: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x199dc4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x199dc8: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x199dc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x199dcc: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x199dccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199dd0: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x199dd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199dd4: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x199dd4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x199dd8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x199dd8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199ddc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199ddcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199de0: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x199de0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199de4: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x199de4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x199de8: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x199de8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199dec: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x199decu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199df0: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x199df0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199df4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199df4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199df8: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x199df8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199dfc: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x199dfcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x199e00: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x199e00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199e04: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x199e04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199e08: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x199e08u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199e0c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199e0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199e10: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x199e10u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199e14: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x199e14u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x199e18: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x199e18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199e1c: 0xc066500  jal         func_199400
    ctx->pc = 0x199E1Cu;
    SET_GPR_U32(ctx, 31, 0x199E24u);
    ctx->pc = 0x199E20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x199E1Cu;
            // 0x199e20: 0xe440002c  swc1        $f0, 0x2C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E24u; }
        if (ctx->pc != 0x199E24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E24u; }
        if (ctx->pc != 0x199E24u) { return; }
    }
    ctx->pc = 0x199E24u;
label_199e24:
    // 0x199e24: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x199e24u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x199e28: 0x24440070  addiu       $a0, $v0, 0x70
    ctx->pc = 0x199e28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 112));
    // 0x199e2c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x199E2Cu;
    SET_GPR_U32(ctx, 31, 0x199E34u);
    ctx->pc = 0x199E30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x199E2Cu;
            // 0x199e30: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E34u; }
        if (ctx->pc != 0x199E34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E34u; }
        if (ctx->pc != 0x199E34u) { return; }
    }
    ctx->pc = 0x199E34u;
label_199e34:
    // 0x199e34: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x199e34u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x199e38: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x199e38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x199e3c: 0xac4300b0  sw          $v1, 0xB0($v0)
    ctx->pc = 0x199e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 176), GPR_U32(ctx, 3));
    // 0x199e40: 0xac4000b4  sw          $zero, 0xB4($v0)
    ctx->pc = 0x199e40u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 180), GPR_U32(ctx, 0));
    // 0x199e44: 0xac4000b8  sw          $zero, 0xB8($v0)
    ctx->pc = 0x199e44u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 184), GPR_U32(ctx, 0));
    // 0x199e48: 0xac4000bc  sw          $zero, 0xBC($v0)
    ctx->pc = 0x199e48u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 188), GPR_U32(ctx, 0));
    // 0x199e4c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x199e4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x199e50: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x199e50u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x199e54: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x199e54u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x199e58: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x199e58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x199e5c: 0x3e00008  jr          $ra
    ctx->pc = 0x199E5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x199E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x199E5Cu;
            // 0x199e60: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D7Cu: goto label_199d7c;
            case 0x199E24u: goto label_199e24;
            case 0x199E34u: goto label_199e34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x199E64u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
