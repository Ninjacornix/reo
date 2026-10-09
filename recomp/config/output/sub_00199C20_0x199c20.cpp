#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00199C20
// Address: 0x199c20 - 0x199cd0
void sub_00199C20_0x199c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00199C20_0x199c20");
#endif

    ctx->pc = 0x199c20u;

    // 0x199c20: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199c20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199c24: 0x3c034300  lui         $v1, 0x4300
    ctx->pc = 0x199c24u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17152 << 16));
    // 0x199c28: 0xc4204204  lwc1        $f0, 0x4204($at)
    ctx->pc = 0x199c28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16900)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199c2c: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x199c2cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x199c30: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199c30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199c34: 0xc4204208  lwc1        $f0, 0x4208($at)
    ctx->pc = 0x199c34u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16904)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199c38: 0xe4800004  swc1        $f0, 0x4($a0)
    ctx->pc = 0x199c38u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x199c3c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199c3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199c40: 0xc420420c  lwc1        $f0, 0x420C($at)
    ctx->pc = 0x199c40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16908)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199c44: 0xe4800008  swc1        $f0, 0x8($a0)
    ctx->pc = 0x199c44u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
    // 0x199c48: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199c48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199c4c: 0xc4204210  lwc1        $f0, 0x4210($at)
    ctx->pc = 0x199c4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16912)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199c50: 0xe480000c  swc1        $f0, 0xC($a0)
    ctx->pc = 0x199c50u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 12), bits); }
    // 0x199c54: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199c54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199c58: 0xc4204224  lwc1        $f0, 0x4224($at)
    ctx->pc = 0x199c58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16932)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199c5c: 0x460c0002  mul.s       $f0, $f0, $f12
    ctx->pc = 0x199c5cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[12]);
    // 0x199c60: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199c60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199c64: 0xe4a00000  swc1        $f0, 0x0($a1)
    ctx->pc = 0x199c64u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
    // 0x199c68: 0xc4204228  lwc1        $f0, 0x4228($at)
    ctx->pc = 0x199c68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16936)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199c6c: 0x460c0002  mul.s       $f0, $f0, $f12
    ctx->pc = 0x199c6cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[12]);
    // 0x199c70: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199c74: 0xe4a00004  swc1        $f0, 0x4($a1)
    ctx->pc = 0x199c74u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
    // 0x199c78: 0xc420422c  lwc1        $f0, 0x422C($at)
    ctx->pc = 0x199c78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16940)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199c7c: 0x460c0002  mul.s       $f0, $f0, $f12
    ctx->pc = 0x199c7cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[12]);
    // 0x199c80: 0xe4a00008  swc1        $f0, 0x8($a1)
    ctx->pc = 0x199c80u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
    // 0x199c84: 0xaca3000c  sw          $v1, 0xC($a1)
    ctx->pc = 0x199c84u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 3));
    // 0x199c88: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x199c88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199c8c: 0x460c0036  c.le.s      $f0, $f12
    ctx->pc = 0x199c8cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x199c90: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x199C90u;
    {
        const bool branch_taken_0x199c90 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x199c90) {
            ctx->pc = 0x199C9Cu;
            goto label_199c9c;
        }
    }
    ctx->pc = 0x199C98u;
    // 0x199c98: 0xe4ac0000  swc1        $f12, 0x0($a1)
    ctx->pc = 0x199c98u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 0), bits); }
label_199c9c:
    // 0x199c9c: 0xc4a00004  lwc1        $f0, 0x4($a1)
    ctx->pc = 0x199c9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199ca0: 0x460c0036  c.le.s      $f0, $f12
    ctx->pc = 0x199ca0u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x199ca4: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x199CA4u;
    {
        const bool branch_taken_0x199ca4 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x199ca4) {
            ctx->pc = 0x199CB0u;
            goto label_199cb0;
        }
    }
    ctx->pc = 0x199CACu;
    // 0x199cac: 0xe4ac0004  swc1        $f12, 0x4($a1)
    ctx->pc = 0x199cacu;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 4), bits); }
label_199cb0:
    // 0x199cb0: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x199cb0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199cb4: 0x460c0036  c.le.s      $f0, $f12
    ctx->pc = 0x199cb4u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[12])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x199cb8: 0x45010002  bc1t        . + 4 + (0x2 << 2)
    ctx->pc = 0x199CB8u;
    {
        const bool branch_taken_0x199cb8 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x199cb8) {
            ctx->pc = 0x199CC4u;
            goto label_199cc4;
        }
    }
    ctx->pc = 0x199CC0u;
    // 0x199cc0: 0xe4ac0008  swc1        $f12, 0x8($a1)
    ctx->pc = 0x199cc0u;
    { float f = ctx->f[12]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 5), 8), bits); }
label_199cc4:
    // 0x199cc4: 0x3e00008  jr          $ra
    ctx->pc = 0x199CC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199C9Cu: goto label_199c9c;
            case 0x199CB0u: goto label_199cb0;
            case 0x199CC4u: goto label_199cc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x199CCCu;
    // 0x199ccc: 0x0  nop
    ctx->pc = 0x199cccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
