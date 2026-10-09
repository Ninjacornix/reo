#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192360
// Address: 0x192360 - 0x192444
void sub_00192360_0x192360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192360_0x192360");
#endif

    ctx->pc = 0x192360u;

    // 0x192360: 0xc486000c  lwc1        $f6, 0xC($a0)
    ctx->pc = 0x192360u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x192364: 0xc4a0000c  lwc1        $f0, 0xC($a1)
    ctx->pc = 0x192364u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192368: 0xc4830004  lwc1        $f3, 0x4($a0)
    ctx->pc = 0x192368u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19236c: 0xc4a20004  lwc1        $f2, 0x4($a1)
    ctx->pc = 0x19236cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x192370: 0xc4850000  lwc1        $f5, 0x0($a0)
    ctx->pc = 0x192370u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x192374: 0xc4a40000  lwc1        $f4, 0x0($a1)
    ctx->pc = 0x192374u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x192378: 0xc4810008  lwc1        $f1, 0x8($a0)
    ctx->pc = 0x192378u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19237c: 0x4600301a  mula.s      $f6, $f0
    ctx->pc = 0x19237cu;
    ctx->f[31] = FPU_MUL_S(ctx->f[6], ctx->f[0]);
    // 0x192380: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x192380u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192384: 0x46021882  mul.s       $f2, $f3, $f2
    ctx->pc = 0x192384u;
    ctx->f[2] = FPU_MUL_S(ctx->f[3], ctx->f[2]);
    // 0x192388: 0x4604291d  msub.s      $f4, $f5, $f4
    ctx->pc = 0x192388u;
    ctx->f[4] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[5], ctx->f[4]));
    // 0x19238c: 0x46022019  suba.s      $f4, $f2
    ctx->pc = 0x19238cu;
    ctx->f[31] = FPU_SUB_S(ctx->f[4], ctx->f[2]);
    // 0x192390: 0x4600081d  msub.s      $f0, $f1, $f0
    ctx->pc = 0x192390u;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[1], ctx->f[0]));
    // 0x192394: 0xe4c0000c  swc1        $f0, 0xC($a2)
    ctx->pc = 0x192394u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 12), bits); }
    // 0x192398: 0xc486000c  lwc1        $f6, 0xC($a0)
    ctx->pc = 0x192398u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x19239c: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x19239cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1923a0: 0xc4830004  lwc1        $f3, 0x4($a0)
    ctx->pc = 0x1923a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1923a4: 0xc4a20008  lwc1        $f2, 0x8($a1)
    ctx->pc = 0x1923a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1923a8: 0xc4850000  lwc1        $f5, 0x0($a0)
    ctx->pc = 0x1923a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x1923ac: 0xc4a4000c  lwc1        $f4, 0xC($a1)
    ctx->pc = 0x1923acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1923b0: 0xc4810008  lwc1        $f1, 0x8($a0)
    ctx->pc = 0x1923b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1923b4: 0x4600301a  mula.s      $f6, $f0
    ctx->pc = 0x1923b4u;
    ctx->f[31] = FPU_MUL_S(ctx->f[6], ctx->f[0]);
    // 0x1923b8: 0xc4a00004  lwc1        $f0, 0x4($a1)
    ctx->pc = 0x1923b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1923bc: 0x46021882  mul.s       $f2, $f3, $f2
    ctx->pc = 0x1923bcu;
    ctx->f[2] = FPU_MUL_S(ctx->f[3], ctx->f[2]);
    // 0x1923c0: 0x4604291c  madd.s      $f4, $f5, $f4
    ctx->pc = 0x1923c0u;
    ctx->f[4] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[5], ctx->f[4]));
    // 0x1923c4: 0x46041018  adda.s      $f2, $f4
    ctx->pc = 0x1923c4u;
    ctx->f[31] = FPU_ADD_S(ctx->f[2], ctx->f[4]);
    // 0x1923c8: 0x4600081d  msub.s      $f0, $f1, $f0
    ctx->pc = 0x1923c8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[1], ctx->f[0]));
    // 0x1923cc: 0xe4c00000  swc1        $f0, 0x0($a2)
    ctx->pc = 0x1923ccu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 0), bits); }
    // 0x1923d0: 0xc486000c  lwc1        $f6, 0xC($a0)
    ctx->pc = 0x1923d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x1923d4: 0xc4a00004  lwc1        $f0, 0x4($a1)
    ctx->pc = 0x1923d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1923d8: 0xc4830008  lwc1        $f3, 0x8($a0)
    ctx->pc = 0x1923d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1923dc: 0xc4a20000  lwc1        $f2, 0x0($a1)
    ctx->pc = 0x1923dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1923e0: 0xc4850004  lwc1        $f5, 0x4($a0)
    ctx->pc = 0x1923e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x1923e4: 0xc4a4000c  lwc1        $f4, 0xC($a1)
    ctx->pc = 0x1923e4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1923e8: 0xc4810000  lwc1        $f1, 0x0($a0)
    ctx->pc = 0x1923e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1923ec: 0x4600301a  mula.s      $f6, $f0
    ctx->pc = 0x1923ecu;
    ctx->f[31] = FPU_MUL_S(ctx->f[6], ctx->f[0]);
    // 0x1923f0: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x1923f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1923f4: 0x46021882  mul.s       $f2, $f3, $f2
    ctx->pc = 0x1923f4u;
    ctx->f[2] = FPU_MUL_S(ctx->f[3], ctx->f[2]);
    // 0x1923f8: 0x4604291c  madd.s      $f4, $f5, $f4
    ctx->pc = 0x1923f8u;
    ctx->f[4] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[5], ctx->f[4]));
    // 0x1923fc: 0x46041018  adda.s      $f2, $f4
    ctx->pc = 0x1923fcu;
    ctx->f[31] = FPU_ADD_S(ctx->f[2], ctx->f[4]);
    // 0x192400: 0x4600081d  msub.s      $f0, $f1, $f0
    ctx->pc = 0x192400u;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[1], ctx->f[0]));
    // 0x192404: 0xe4c00004  swc1        $f0, 0x4($a2)
    ctx->pc = 0x192404u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 4), bits); }
    // 0x192408: 0xc486000c  lwc1        $f6, 0xC($a0)
    ctx->pc = 0x192408u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x19240c: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x19240cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192410: 0xc4830000  lwc1        $f3, 0x0($a0)
    ctx->pc = 0x192410u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x192414: 0xc4a20004  lwc1        $f2, 0x4($a1)
    ctx->pc = 0x192414u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x192418: 0xc4850008  lwc1        $f5, 0x8($a0)
    ctx->pc = 0x192418u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x19241c: 0xc4a4000c  lwc1        $f4, 0xC($a1)
    ctx->pc = 0x19241cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x192420: 0xc4810004  lwc1        $f1, 0x4($a0)
    ctx->pc = 0x192420u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x192424: 0x4600301a  mula.s      $f6, $f0
    ctx->pc = 0x192424u;
    ctx->f[31] = FPU_MUL_S(ctx->f[6], ctx->f[0]);
    // 0x192428: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x192428u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19242c: 0x46021882  mul.s       $f2, $f3, $f2
    ctx->pc = 0x19242cu;
    ctx->f[2] = FPU_MUL_S(ctx->f[3], ctx->f[2]);
    // 0x192430: 0x4604291c  madd.s      $f4, $f5, $f4
    ctx->pc = 0x192430u;
    ctx->f[4] = FPU_ADD_S(ctx->f[31], FPU_MUL_S(ctx->f[5], ctx->f[4]));
    // 0x192434: 0x46041018  adda.s      $f2, $f4
    ctx->pc = 0x192434u;
    ctx->f[31] = FPU_ADD_S(ctx->f[2], ctx->f[4]);
    // 0x192438: 0x4600081d  msub.s      $f0, $f1, $f0
    ctx->pc = 0x192438u;
    ctx->f[0] = FPU_SUB_S(ctx->f[31], FPU_MUL_S(ctx->f[1], ctx->f[0]));
    // 0x19243c: 0x3e00008  jr          $ra
    ctx->pc = 0x19243Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19243Cu;
            // 0x192440: 0xe4c00008  swc1        $f0, 0x8($a2) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 8), bits); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x192444u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
