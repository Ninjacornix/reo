#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001911D0
// Address: 0x1911d0 - 0x191280
void sub_001911D0_0x1911d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001911D0_0x1911d0");
#endif

    switch (ctx->pc) {
        case 0x191258u: goto label_191258;
        case 0x191268u: goto label_191268;
        default: break;
    }

    ctx->pc = 0x1911d0u;

label_1911d0:
    // 0x1911d0: 0xd8880000  lqc2        $vf8, 0x0($a0)
    ctx->pc = 0x1911d0u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1911d4: 0xd8890010  lqc2        $vf9, 0x10($a0)
    ctx->pc = 0x1911d4u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1911d8: 0xd88a0020  lqc2        $vf10, 0x20($a0)
    ctx->pc = 0x1911d8u;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1911dc: 0x4b080100  vaddx.x     $vf4, $vf0, $vf8x
    ctx->pc = 0x1911dcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1911e0: 0x4b080141  vaddy.x     $vf5, $vf0, $vf8y
    ctx->pc = 0x1911e0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1911e4: 0x4b080182  vaddz.x     $vf6, $vf0, $vf8z
    ctx->pc = 0x1911e4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[8], ctx->vu0_vf[8], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1911e8: 0x4a890100  vaddx.y     $vf4, $vf0, $vf9x
    ctx->pc = 0x1911e8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1911ec: 0x4a890141  vaddy.y     $vf5, $vf0, $vf9y
    ctx->pc = 0x1911ecu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1911f0: 0x4a890182  vaddz.y     $vf6, $vf0, $vf9z
    ctx->pc = 0x1911f0u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[9], ctx->vu0_vf[9], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, -1, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x1911f4: 0x4a4a0100  vaddx.z     $vf4, $vf0, $vf10x
    ctx->pc = 0x1911f4u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x1911f8: 0x4a4a0141  vaddy.z     $vf5, $vf0, $vf10y
    ctx->pc = 0x1911f8u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x1911fc: 0x4a4a0182  vaddz.z     $vf6, $vf0, $vf10z
    ctx->pc = 0x1911fcu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[10], ctx->vu0_vf[10], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, -1, 0, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x191200: 0x4a204100  vaddx.w     $vf4, $vf8, $vf0x
    ctx->pc = 0x191200u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[8], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[4] = _mm_blendv_ps(ctx->vu0_vf[4], res, _mm_castsi128_ps(mask)); }
    // 0x191204: 0x4a204940  vaddx.w     $vf5, $vf9, $vf0x
    ctx->pc = 0x191204u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[9], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x191208: 0x4a205180  vaddx.w     $vf6, $vf10, $vf0x
    ctx->pc = 0x191208u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[10], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x19120c: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x19120cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x191210: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x191210u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x191214: 0x3e00008  jr          $ra
    ctx->pc = 0x191214u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191214u;
            // 0x191218: 0xf8860020  sqc2        $vf6, 0x20($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1911D0u: goto label_1911d0;
            case 0x191258u: goto label_191258;
            case 0x191268u: goto label_191268;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19121Cu;
    // 0x19121c: 0x0  nop
    ctx->pc = 0x19121cu;
    // NOP
    // 0x191220: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x191220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x191224: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x191224u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x191228: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191228u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19122c: 0xc4800030  lwc1        $f0, 0x30($a0)
    ctx->pc = 0x19122cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191230: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x191230u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191234: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x191234u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x191238: 0xe7a00020  swc1        $f0, 0x20($sp)
    ctx->pc = 0x191238u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 32), bits); }
    // 0x19123c: 0xc4800034  lwc1        $f0, 0x34($a0)
    ctx->pc = 0x19123cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 52)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191240: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x191240u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x191244: 0xe7a00024  swc1        $f0, 0x24($sp)
    ctx->pc = 0x191244u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 36), bits); }
    // 0x191248: 0xc4800038  lwc1        $f0, 0x38($a0)
    ctx->pc = 0x191248u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19124c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19124cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x191250: 0xc064474  jal         func_1911D0
    ctx->pc = 0x191250u;
    SET_GPR_U32(ctx, 31, 0x191258u);
    ctx->pc = 0x191254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191250u;
            // 0x191254: 0xe7a00028  swc1        $f0, 0x28($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1911D0u;
    goto label_1911d0;
    ctx->pc = 0x191258u;
label_191258:
    // 0x191258: 0x26040030  addiu       $a0, $s0, 0x30
    ctx->pc = 0x191258u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x19125c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x19125cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191260: 0xc064674  jal         func_1919D0
    ctx->pc = 0x191260u;
    SET_GPR_U32(ctx, 31, 0x191268u);
    ctx->pc = 0x191264u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191260u;
            // 0x191264: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1919D0u;
    if (runtime->hasFunction(0x1919D0u)) {
        auto targetFn = runtime->lookupFunction(0x1919D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191268u; }
        if (ctx->pc != 0x191268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001919D0_0x1919d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191268u; }
        if (ctx->pc != 0x191268u) { return; }
    }
    ctx->pc = 0x191268u;
label_191268:
    // 0x191268: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x191268u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19126c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19126cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x191270: 0x3e00008  jr          $ra
    ctx->pc = 0x191270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x191274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x191270u;
            // 0x191274: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1911D0u: goto label_1911d0;
            case 0x191258u: goto label_191258;
            case 0x191268u: goto label_191268;
            default: break;
        }
        return;
    }
    ctx->pc = 0x191278u;
    // 0x191278: 0x0  nop
    ctx->pc = 0x191278u;
    // NOP
    // 0x19127c: 0x0  nop
    ctx->pc = 0x19127cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
