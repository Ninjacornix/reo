#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191C40
// Address: 0x191c40 - 0x191cbc
void sub_00191C40_0x191c40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191C40_0x191c40");
#endif

    switch (ctx->pc) {
        case 0x191c78u: goto label_191c78;
        default: break;
    }

    ctx->pc = 0x191c40u;

    // 0x191c40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x191c40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x191c44: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x191c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x191c48: 0x27a20028  addiu       $v0, $sp, 0x28
    ctx->pc = 0x191c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x191c4c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191c4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x191c50: 0x27a50038  addiu       $a1, $sp, 0x38
    ctx->pc = 0x191c50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x191c54: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191c54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191c58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x191c58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191c5c: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191c5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191c60: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191c60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191c64: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x191c64u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x191c68: 0x27a4003c  addiu       $a0, $sp, 0x3C
    ctx->pc = 0x191c68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x191c6c: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x191c6cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x191c70: 0xc06486c  jal         func_1921B0
    ctx->pc = 0x191C70u;
    SET_GPR_U32(ctx, 31, 0x191C78u);
    ctx->pc = 0x191C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191C70u;
            // 0x191c74: 0xe4400008  swc1        $f0, 0x8($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1921B0u;
    if (runtime->hasFunction(0x1921B0u)) {
        auto targetFn = runtime->lookupFunction(0x1921B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191C78u; }
        if (ctx->pc != 0x191C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001921B0_0x1921b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191C78u; }
        if (ctx->pc != 0x191C78u) { return; }
    }
    ctx->pc = 0x191C78u;
label_191c78:
    // 0x191c78: 0xc7a20038  lwc1        $f2, 0x38($sp)
    ctx->pc = 0x191c78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191c7c: 0xc7a10028  lwc1        $f1, 0x28($sp)
    ctx->pc = 0x191c7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191c80: 0xc7a3002c  lwc1        $f3, 0x2C($sp)
    ctx->pc = 0x191c80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x191c84: 0xc7a0003c  lwc1        $f0, 0x3C($sp)
    ctx->pc = 0x191c84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191c88: 0x4601101a  mula.s      $f2, $f1
    ctx->pc = 0x191c88u;
    ctx->f[31] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x191c8c: 0x4603001d  msub.s      $f0, $f0, $f3
    ctx->pc = 0x191c8cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191c90: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x191c90u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x191c94: 0xc7a2003c  lwc1        $f2, 0x3C($sp)
    ctx->pc = 0x191c94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191c98: 0xc7a10028  lwc1        $f1, 0x28($sp)
    ctx->pc = 0x191c98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191c9c: 0xc7a00038  lwc1        $f0, 0x38($sp)
    ctx->pc = 0x191c9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191ca0: 0x4601101a  mula.s      $f2, $f1
    ctx->pc = 0x191ca0u;
    ctx->f[31] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x191ca4: 0x4603001c  madd.s      $f0, $f0, $f3
    ctx->pc = 0x191ca4u;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191ca8: 0xe6000004  swc1        $f0, 0x4($s0)
    ctx->pc = 0x191ca8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 4), bits); }
    // 0x191cac: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x191cacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x191cb0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x191cb0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x191cb4: 0x3e00008  jr          $ra
    ctx->pc = 0x191CB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191CB4u;
            // 0x191cb8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191C78u: goto label_191c78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191CBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
