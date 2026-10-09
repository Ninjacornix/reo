#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191B40
// Address: 0x191b40 - 0x191bb8
void sub_00191B40_0x191b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191B40_0x191b40");
#endif

    switch (ctx->pc) {
        case 0x191b78u: goto label_191b78;
        default: break;
    }

    ctx->pc = 0x191b40u;

    // 0x191b40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x191b40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x191b44: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x191b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x191b48: 0x27a20028  addiu       $v0, $sp, 0x28
    ctx->pc = 0x191b48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
    // 0x191b4c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191b4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x191b50: 0x27a50038  addiu       $a1, $sp, 0x38
    ctx->pc = 0x191b50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x191b54: 0xc4820000  lwc1        $f2, 0x0($a0)
    ctx->pc = 0x191b54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191b58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x191b58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191b5c: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x191b5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191b60: 0xc4800008  lwc1        $f0, 0x8($a0)
    ctx->pc = 0x191b60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191b64: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x191b64u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x191b68: 0x27a4003c  addiu       $a0, $sp, 0x3C
    ctx->pc = 0x191b68u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x191b6c: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x191b6cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x191b70: 0xc06486c  jal         func_1921B0
    ctx->pc = 0x191B70u;
    SET_GPR_U32(ctx, 31, 0x191B78u);
    ctx->pc = 0x191B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191B70u;
            // 0x191b74: 0xe4400008  swc1        $f0, 0x8($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1921B0u;
    if (runtime->hasFunction(0x1921B0u)) {
        auto targetFn = runtime->lookupFunction(0x1921B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191B78u; }
        if (ctx->pc != 0x191B78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001921B0_0x1921b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191B78u; }
        if (ctx->pc != 0x191B78u) { return; }
    }
    ctx->pc = 0x191B78u;
label_191b78:
    // 0x191b78: 0xc7a2002c  lwc1        $f2, 0x2C($sp)
    ctx->pc = 0x191b78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x191b7c: 0xc7a10038  lwc1        $f1, 0x38($sp)
    ctx->pc = 0x191b7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191b80: 0xc7a30030  lwc1        $f3, 0x30($sp)
    ctx->pc = 0x191b80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x191b84: 0xc7a0003c  lwc1        $f0, 0x3C($sp)
    ctx->pc = 0x191b84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191b88: 0x4602081a  mula.s      $f1, $f2
    ctx->pc = 0x191b88u;
    ctx->f[31] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x191b8c: 0x4603001d  msub.s      $f0, $f0, $f3
    ctx->pc = 0x191b8cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191b90: 0xe6000004  swc1        $f0, 0x4($s0)
    ctx->pc = 0x191b90u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 4), bits); }
    // 0x191b94: 0xc7a1003c  lwc1        $f1, 0x3C($sp)
    ctx->pc = 0x191b94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x191b98: 0xc7a00038  lwc1        $f0, 0x38($sp)
    ctx->pc = 0x191b98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191b9c: 0x4602081a  mula.s      $f1, $f2
    ctx->pc = 0x191b9cu;
    ctx->f[31] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x191ba0: 0x4603001c  madd.s      $f0, $f0, $f3
    ctx->pc = 0x191ba0u;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[0], ctx->f[3]));
    // 0x191ba4: 0xe6000008  swc1        $f0, 0x8($s0)
    ctx->pc = 0x191ba4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
    // 0x191ba8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x191ba8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x191bac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x191bacu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x191bb0: 0x3e00008  jr          $ra
    ctx->pc = 0x191BB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191BB0u;
            // 0x191bb4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x191B78u: goto label_191b78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191BB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
