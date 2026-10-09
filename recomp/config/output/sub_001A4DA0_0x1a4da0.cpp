#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A4DA0
// Address: 0x1a4da0 - 0x1a4e30
void sub_001A4DA0_0x1a4da0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A4DA0_0x1a4da0");
#endif

    ctx->pc = 0x1a4da0u;

    // 0x1a4da0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a4da0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a4da4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A4DA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A4DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4DA4u;
            // 0x1a4da8: 0xac24ffe8  sw          $a0, -0x18($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294967272), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A4DACu;
    // 0x1a4dac: 0x0  nop
    ctx->pc = 0x1a4dacu;
    // NOP
    // 0x1a4db0: 0x460e8801  sub.s       $f0, $f17, $f14
    ctx->pc = 0x1a4db0u;
    ctx->f[0] = FPU_SUB_S(ctx->f[17], ctx->f[14]);
    // 0x1a4db4: 0x3c043f80  lui         $a0, 0x3F80
    ctx->pc = 0x1a4db4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)16256 << 16));
    // 0x1a4db8: 0x3c034000  lui         $v1, 0x4000
    ctx->pc = 0x1a4db8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16384 << 16));
    // 0x1a4dbc: 0x3c024040  lui         $v0, 0x4040
    ctx->pc = 0x1a4dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16448 << 16));
    // 0x1a4dc0: 0x44841000  mtc1        $a0, $f2
    ctx->pc = 0x1a4dc0u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1a4dc4: 0x460e6201  sub.s       $f8, $f12, $f14
    ctx->pc = 0x1a4dc4u;
    ctx->f[8] = FPU_SUB_S(ctx->f[12], ctx->f[14]);
    // 0x1a4dc8: 0x460011c3  div.s       $f7, $f2, $f0
    ctx->pc = 0x1a4dc8u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[7] = std::bit_cast<float>(__maxf); } else ctx->f[7] = ctx->f[2] / ctx->f[0];
    // 0x1a4dcc: 0x460840c2  mul.s       $f3, $f8, $f8
    ctx->pc = 0x1a4dccu;
    ctx->f[3] = FPU_MUL_S(ctx->f[8], ctx->f[8]);
    // 0x1a4dd0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1a4dd0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1a4dd4: 0x46073942  mul.s       $f5, $f7, $f7
    ctx->pc = 0x1a4dd4u;
    ctx->f[5] = FPU_MUL_S(ctx->f[7], ctx->f[7]);
    // 0x1a4dd8: 0x46030002  mul.s       $f0, $f0, $f3
    ctx->pc = 0x1a4dd8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[3]);
    // 0x1a4ddc: 0x46050102  mul.s       $f4, $f0, $f5
    ctx->pc = 0x1a4ddcu;
    ctx->f[4] = FPU_MUL_S(ctx->f[0], ctx->f[5]);
    // 0x1a4de0: 0x46071982  mul.s       $f6, $f3, $f7
    ctx->pc = 0x1a4de0u;
    ctx->f[6] = FPU_MUL_S(ctx->f[3], ctx->f[7]);
    // 0x1a4de4: 0x46081802  mul.s       $f0, $f3, $f8
    ctx->pc = 0x1a4de4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[3], ctx->f[8]);
    // 0x1a4de8: 0x460028c2  mul.s       $f3, $f5, $f0
    ctx->pc = 0x1a4de8u;
    ctx->f[3] = FPU_MUL_S(ctx->f[5], ctx->f[0]);
    // 0x1a4dec: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1a4decu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1a4df0: 0x0  nop
    ctx->pc = 0x1a4df0u;
    // NOP
    // 0x1a4df4: 0x46030802  mul.s       $f0, $f1, $f3
    ctx->pc = 0x1a4df4u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[3]);
    // 0x1a4df8: 0x46070142  mul.s       $f5, $f0, $f7
    ctx->pc = 0x1a4df8u;
    ctx->f[5] = FPU_MUL_S(ctx->f[0], ctx->f[7]);
    // 0x1a4dfc: 0x460618c1  sub.s       $f3, $f3, $f6
    ctx->pc = 0x1a4dfcu;
    ctx->f[3] = FPU_SUB_S(ctx->f[3], ctx->f[6]);
    // 0x1a4e00: 0x46042841  sub.s       $f1, $f5, $f4
    ctx->pc = 0x1a4e00u;
    ctx->f[1] = FPU_SUB_S(ctx->f[5], ctx->f[4]);
    // 0x1a4e04: 0x46061801  sub.s       $f0, $f3, $f6
    ctx->pc = 0x1a4e04u;
    ctx->f[0] = FPU_SUB_S(ctx->f[3], ctx->f[6]);
    // 0x1a4e08: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1a4e08u;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1a4e0c: 0x46004000  add.s       $f0, $f8, $f0
    ctx->pc = 0x1a4e0cu;
    ctx->f[0] = FPU_ADD_S(ctx->f[8], ctx->f[0]);
    // 0x1a4e10: 0x4601681a  mula.s      $f13, $f1
    ctx->pc = 0x1a4e10u;
    ctx->f[31] = FPU_MUL_S(ctx->f[13], ctx->f[1]);
    // 0x1a4e14: 0x46002847  neg.s       $f1, $f5
    ctx->pc = 0x1a4e14u;
    ctx->f[1] = FPU_NEG_S(ctx->f[5]);
    // 0x1a4e18: 0x46040840  add.s       $f1, $f1, $f4
    ctx->pc = 0x1a4e18u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[4]);
    // 0x1a4e1c: 0x46007802  mul.s       $f0, $f15, $f0
    ctx->pc = 0x1a4e1cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[15], ctx->f[0]);
    // 0x1a4e20: 0x4601805c  madd.s      $f1, $f16, $f1
    ctx->pc = 0x1a4e20u;
    ctx->f[1] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[16], ctx->f[1]));
    // 0x1a4e24: 0x46010018  adda.s      $f0, $f1
    ctx->pc = 0x1a4e24u;
    ctx->f[31] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1a4e28: 0x3e00008  jr          $ra
    ctx->pc = 0x1A4E28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A4E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A4E28u;
            // 0x1a4e2c: 0x4603901c  madd.s      $f0, $f18, $f3 (Delay Slot)
        ctx->f[0] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[18], ctx->f[3]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A4E30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
