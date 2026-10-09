#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5180
// Address: 0x1a5180 - 0x1a51b0
void sub_001A5180_0x1a5180(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5180_0x1a5180");
#endif

    ctx->pc = 0x1a5180u;

    // 0x1a5180: 0xc4800004  lwc1        $f0, 0x4($a0)
    ctx->pc = 0x1a5180u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5184: 0xc4810000  lwc1        $f1, 0x0($a0)
    ctx->pc = 0x1a5184u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a5188: 0xc4820008  lwc1        $f2, 0x8($a0)
    ctx->pc = 0x1a5188u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1a518c: 0x46000002  mul.s       $f0, $f0, $f0
    ctx->pc = 0x1a518cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[0]);
    // 0x1a5190: 0x46010842  mul.s       $f1, $f1, $f1
    ctx->pc = 0x1a5190u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[1]);
    // 0x1a5194: 0x46000818  adda.s      $f1, $f0
    ctx->pc = 0x1a5194u;
    ctx->f[31] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1a5198: 0x4602101c  madd.s      $f0, $f2, $f2
    ctx->pc = 0x1a5198u;
    ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[2], ctx->f[2]));
    // 0x1a519c: 0x46000004  c1          0x4
    ctx->pc = 0x1a519cu;
    ctx->f[0] = FPU_SQRT_S(ctx->f[0]);
    // 0x1a51a0: 0x0  nop
    ctx->pc = 0x1a51a0u;
    // NOP
    // 0x1a51a4: 0x0  nop
    ctx->pc = 0x1a51a4u;
    // NOP
    // 0x1a51a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A51A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A51B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
