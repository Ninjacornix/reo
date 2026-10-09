#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F7D0
// Address: 0x17f7d0 - 0x17f854
void sub_0017F7D0_0x17f7d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F7D0_0x17f7d0");
#endif

    switch (ctx->pc) {
        case 0x17f7fcu: goto label_17f7fc;
        default: break;
    }

    ctx->pc = 0x17f7d0u;

    // 0x17f7d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17f7d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17f7d4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f7d8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f7dc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f7dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7e0: 0xe7b50038  swc1        $f21, 0x38($sp)
    ctx->pc = 0x17f7e0u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 56), bits); }
    // 0x17f7e4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17f7e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7e8: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17f7e8u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17f7ec: 0x46006546  mov.s       $f21, $f12
    ctx->pc = 0x17f7ecu;
    ctx->f[21] = FPU_MOV_S(ctx->f[12]);
    // 0x17f7f0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f7f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f7f4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F7F4u;
    SET_GPR_U32(ctx, 31, 0x17F7FCu);
    ctx->pc = 0x17F7F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F7F4u;
            // 0x17f7f8: 0x46006d06  mov.s       $f20, $f13 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[13]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7FCu; }
        if (ctx->pc != 0x17F7FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7FCu; }
        if (ctx->pc != 0x17F7FCu) { return; }
    }
    ctx->pc = 0x17F7FCu;
label_17f7fc:
    // 0x17f7fc: 0x4408a800  mfc1        $t0, $f21
    ctx->pc = 0x17f7fcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[21], sizeof(bits)); SET_GPR_U32(ctx, 8, bits); }
    // 0x17f800: 0x4409a000  mfc1        $t1, $f20
    ctx->pc = 0x17f800u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[20], sizeof(bits)); SET_GPR_U32(ctx, 9, bits); }
    // 0x17f804: 0xda060000  lqc2        $vf6, 0x0($s0)
    ctx->pc = 0x17f804u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f808: 0x48a82000  qmtc2.ni    $t0, $vf4
    ctx->pc = 0x17f808u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(GPR_VEC(ctx, 8));
    // 0x17f80c: 0x48a92800  qmtc2.ni    $t1, $vf5
    ctx->pc = 0x17f80cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(GPR_VEC(ctx, 9));
    // 0x17f810: 0x4be43190  vmaxx.xyzw  $vf6, $vf6, $vf4x
    ctx->pc = 0x17f810u;
    { __m128 res = _mm_max_ps(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[4], ctx->vu0_vf[4], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f814: 0x4be53194  vminix.xyzw $vf6, $vf6, $vf5x
    ctx->pc = 0x17f814u;
    { __m128 res = _mm_min_ps(ctx->vu0_vf[6], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17f818: 0xfa260000  sqc2        $vf6, 0x0($s1)
    ctx->pc = 0x17f818u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17f81c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17F81Cu;
    {
        const bool branch_taken_0x17f81c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F81Cu;
            // 0x17f820: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f81c) {
            ctx->pc = 0x17F83Cu;
            goto label_17f83c;
        }
    }
    ctx->pc = 0x17F824u;
    // 0x17f824: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f824u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f828: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f828u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f82c: 0xc7b50038  lwc1        $f21, 0x38($sp)
    ctx->pc = 0x17f82cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17f830: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17f830u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f834: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F834u;
    ctx->pc = 0x17F838u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F834u;
            // 0x17f838: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F83Cu;
label_17f83c:
    // 0x17f83c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f83cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f840: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f840u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f844: 0xc7b50038  lwc1        $f21, 0x38($sp)
    ctx->pc = 0x17f844u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17f848: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17f848u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f84c: 0x3e00008  jr          $ra
    ctx->pc = 0x17F84Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F84Cu;
            // 0x17f850: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F7FCu: goto label_17f7fc;
            case 0x17F83Cu: goto label_17f83c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F854u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
