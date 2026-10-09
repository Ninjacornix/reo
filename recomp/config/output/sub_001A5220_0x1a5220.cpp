#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5220
// Address: 0x1a5220 - 0x1a5280
void sub_001A5220_0x1a5220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5220_0x1a5220");
#endif

    ctx->pc = 0x1a5220u;

    // 0x1a5220: 0xc4a30004  lwc1        $f3, 0x4($a1)
    ctx->pc = 0x1a5220u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1a5224: 0xc4c20008  lwc1        $f2, 0x8($a2)
    ctx->pc = 0x1a5224u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1a5228: 0xc4c10004  lwc1        $f1, 0x4($a2)
    ctx->pc = 0x1a5228u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a522c: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x1a522cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5230: 0x4602181a  mula.s      $f3, $f2
    ctx->pc = 0x1a5230u;
    ctx->f[31] = FPU_MUL_S(ctx->f[3], ctx->f[2]);
    // 0x1a5234: 0x4600081d  msub.s      $f0, $f1, $f0
    ctx->pc = 0x1a5234u;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[1], ctx->f[0]));
    // 0x1a5238: 0xe4800000  swc1        $f0, 0x0($a0)
    ctx->pc = 0x1a5238u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 0), bits); }
    // 0x1a523c: 0xc4a30008  lwc1        $f3, 0x8($a1)
    ctx->pc = 0x1a523cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1a5240: 0xc4c20000  lwc1        $f2, 0x0($a2)
    ctx->pc = 0x1a5240u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1a5244: 0xc4c10008  lwc1        $f1, 0x8($a2)
    ctx->pc = 0x1a5244u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a5248: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x1a5248u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a524c: 0x4602181a  mula.s      $f3, $f2
    ctx->pc = 0x1a524cu;
    ctx->f[31] = FPU_MUL_S(ctx->f[3], ctx->f[2]);
    // 0x1a5250: 0x4600081d  msub.s      $f0, $f1, $f0
    ctx->pc = 0x1a5250u;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[1], ctx->f[0]));
    // 0x1a5254: 0xe4800004  swc1        $f0, 0x4($a0)
    ctx->pc = 0x1a5254u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 4), bits); }
    // 0x1a5258: 0xc4a30000  lwc1        $f3, 0x0($a1)
    ctx->pc = 0x1a5258u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1a525c: 0xc4c20004  lwc1        $f2, 0x4($a2)
    ctx->pc = 0x1a525cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1a5260: 0xc4a00004  lwc1        $f0, 0x4($a1)
    ctx->pc = 0x1a5260u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5264: 0xc4c10000  lwc1        $f1, 0x0($a2)
    ctx->pc = 0x1a5264u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a5268: 0x4602181a  mula.s      $f3, $f2
    ctx->pc = 0x1a5268u;
    ctx->f[31] = FPU_MUL_S(ctx->f[3], ctx->f[2]);
    // 0x1a526c: 0x4600081d  msub.s      $f0, $f1, $f0
    ctx->pc = 0x1a526cu;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[1], ctx->f[0]));
    // 0x1a5270: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5270u;
            // 0x1a5274: 0xe4800008  swc1        $f0, 0x8($a0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 4), 8), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A5278u;
    // 0x1a5278: 0x0  nop
    ctx->pc = 0x1a5278u;
    // NOP
    // 0x1a527c: 0x0  nop
    ctx->pc = 0x1a527cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
