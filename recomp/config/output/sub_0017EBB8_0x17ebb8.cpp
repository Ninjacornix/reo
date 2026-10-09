#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EBB8
// Address: 0x17ebb8 - 0x17ec98
void sub_0017EBB8_0x17ebb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EBB8_0x17ebb8");
#endif

    switch (ctx->pc) {
        case 0x17ebdcu: goto label_17ebdc;
        case 0x17ec48u: goto label_17ec48;
        case 0x17ec78u: goto label_17ec78;
        default: break;
    }

    ctx->pc = 0x17ebb8u;

    // 0x17ebb8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17ebb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17ebbc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17ebbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17ebc0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ebc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17ebc4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17ebc4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ebc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ebc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ebcc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17ebccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ebd0: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x17ebd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x17ebd4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EBD4u;
    SET_GPR_U32(ctx, 31, 0x17EBDCu);
    ctx->pc = 0x17EBD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EBD4u;
            // 0x17ebd8: 0xc0802d  daddu       $s0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EBDCu; }
        if (ctx->pc != 0x17EBDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EBDCu; }
        if (ctx->pc != 0x17EBDCu) { return; }
    }
    ctx->pc = 0x17EBDCu;
label_17ebdc:
    // 0x17ebdc: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17ebdcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17ebe0: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17ebe0u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ebe4: 0x4bc522fe  vopmula.xyz $ACC, $vf4, $vf5
    ctx->pc = 0x17ebe4u;
    { __m128 res = PS2_VOPMUL(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_acc = _mm_blendv_ps(ctx->vu0_acc, res, _mm_castsi128_ps(mask)); }
    // 0x17ebe8: 0x4bc429ae  vopmsub.xyz $vf6, $vf5, $vf4
    ctx->pc = 0x17ebe8u;
    { __m128 res = PS2_VSUB(ctx->vu0_acc, PS2_VOPMUL(ctx->vu0_vf[5], ctx->vu0_vf[4])); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[6] = _mm_blendv_ps(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17ebec: 0x4a2631ac  vsub.w      $vf6, $vf6, $vf6
    ctx->pc = 0x17ebecu;
    { __m128 res = PS2_VSUB(ctx->vu0_vf[6], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(-1, 0, 0, 0); ctx->vu0_vf[6] = PS2_VBLEND(ctx->vu0_vf[6], res, _mm_castsi128_ps(mask)); }
    // 0x17ebf0: 0xfa460000  sqc2        $vf6, 0x0($s2)
    ctx->pc = 0x17ebf0u;
    WRITE128(ADD32(GPR_U32(ctx, 18), 0), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x17ebf4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17EBF4u;
    {
        const bool branch_taken_0x17ebf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EBF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EBF4u;
            // 0x17ebf8: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ebf4) {
            ctx->pc = 0x17EC10u;
            goto label_17ec10;
        }
    }
    ctx->pc = 0x17EBFCu;
    // 0x17ebfc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17ebfcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17ec00: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ec00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ec04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ec04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ec08: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17EC08u;
    ctx->pc = 0x17EC0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EC08u;
            // 0x17ec0c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17EC10u;
label_17ec10:
    // 0x17ec10: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17ec10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17ec14: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ec14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ec18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ec18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ec1c: 0x3e00008  jr          $ra
    ctx->pc = 0x17EC1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EC1Cu;
            // 0x17ec20: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EBDCu: goto label_17ebdc;
            case 0x17EC10u: goto label_17ec10;
            case 0x17EC48u: goto label_17ec48;
            case 0x17EC78u: goto label_17ec78;
            case 0x17EC7Cu: goto label_17ec7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EC24u;
    // 0x17ec24: 0x0  nop
    ctx->pc = 0x17ec24u;
    // NOP
    // 0x17ec28: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x17ec28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17ec2c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ec2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17ec30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ec30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ec34: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17ec34u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ec38: 0xe7b40030  swc1        $f20, 0x30($sp)
    ctx->pc = 0x17ec38u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17ec3c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17ec3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17ec40: 0xc047598  jal         func_11D660
    ctx->pc = 0x17EC40u;
    SET_GPR_U32(ctx, 31, 0x17EC48u);
    ctx->pc = 0x17EC44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EC40u;
            // 0x17ec44: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EC48u; }
        if (ctx->pc != 0x17EC48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EC48u; }
        if (ctx->pc != 0x17EC48u) { return; }
    }
    ctx->pc = 0x17EC48u;
label_17ec48:
    // 0x17ec48: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x17ec48u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ec4c: 0xda240000  lqc2        $vf4, 0x0($s1)
    ctx->pc = 0x17ec4cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17ec50: 0xda050000  lqc2        $vf5, 0x0($s0)
    ctx->pc = 0x17ec50u;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ec54: 0x4bc5216a  vmul.xyz    $vf5, $vf4, $vf5
    ctx->pc = 0x17ec54u;
    { __m128 res = PS2_VMUL(ctx->vu0_vf[4], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[5] = PS2_VBLEND(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ec58: 0x4b052941  vaddy.x     $vf5, $vf5, $vf5y
    ctx->pc = 0x17ec58u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(1,1,1,1))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ec5c: 0x4b052942  vaddz.x     $vf5, $vf5, $vf5z
    ctx->pc = 0x17ec5cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[5], _mm_shuffle_ps(ctx->vu0_vf[5], ctx->vu0_vf[5], _MM_SHUFFLE(2,2,2,2))); __m128i mask = _mm_set_epi32(0, 0, 0, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17ec60: 0x48222800  qmfc2.ni    $v0, $vf5
    ctx->pc = 0x17ec60u;
    SET_GPR_VEC(ctx, 2, _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17ec64: 0x4482a000  mtc1        $v0, $f20
    ctx->pc = 0x17ec64u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x17ec68: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17EC68u;
    {
        const bool branch_taken_0x17ec68 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x17EC6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EC68u;
            // 0x17ec6c: 0x4600a006  mov.s       $f0, $f20 (Delay Slot)
        ctx->f[0] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ec68) {
            ctx->pc = 0x17EC7Cu;
            goto label_17ec7c;
        }
    }
    ctx->pc = 0x17EC70u;
    // 0x17ec70: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x17EC70u;
    SET_GPR_U32(ctx, 31, 0x17EC78u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EC78u; }
        if (ctx->pc != 0x17EC78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EC78u; }
        if (ctx->pc != 0x17EC78u) { return; }
    }
    ctx->pc = 0x17EC78u;
label_17ec78:
    // 0x17ec78: 0x4600a006  mov.s       $f0, $f20
    ctx->pc = 0x17ec78u;
    ctx->f[0] = FPU_MOV_S(ctx->f[20]);
label_17ec7c:
    // 0x17ec7c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17ec7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17ec80: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ec80u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ec84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ec84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ec88: 0xc7b40030  lwc1        $f20, 0x30($sp)
    ctx->pc = 0x17ec88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17ec8c: 0x3e00008  jr          $ra
    ctx->pc = 0x17EC8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EC90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EC8Cu;
            // 0x17ec90: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EBDCu: goto label_17ebdc;
            case 0x17EC10u: goto label_17ec10;
            case 0x17EC48u: goto label_17ec48;
            case 0x17EC78u: goto label_17ec78;
            case 0x17EC7Cu: goto label_17ec7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EC94u;
    // 0x17ec94: 0x0  nop
    ctx->pc = 0x17ec94u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
