#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F1D8
// Address: 0x17f1d8 - 0x17f3d0
void sub_0017F1D8_0x17f1d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F1D8_0x17f1d8");
#endif

    switch (ctx->pc) {
        case 0x17f1f4u: goto label_17f1f4;
        case 0x17f244u: goto label_17f244;
        case 0x17f2acu: goto label_17f2ac;
        case 0x17f2fcu: goto label_17f2fc;
        case 0x17f34cu: goto label_17f34c;
        case 0x17f39cu: goto label_17f39c;
        default: break;
    }

    ctx->pc = 0x17f1d8u;

    // 0x17f1d8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f1d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f1dc: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f1dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f1e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f1e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f1e4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f1e4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f1e8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f1e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f1ec: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F1ECu;
    SET_GPR_U32(ctx, 31, 0x17F1F4u);
    ctx->pc = 0x17F1F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F1ECu;
            // 0x17f1f0: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F1F4u; }
        if (ctx->pc != 0x17F1F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F1F4u; }
        if (ctx->pc != 0x17F1F4u) { return; }
    }
    ctx->pc = 0x17F1F4u;
label_17f1f4:
    // 0x17f1f4: 0x7a060000  lq          $a2, 0x0($s0)
    ctx->pc = 0x17f1f4u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f1f8: 0x7e260000  sq          $a2, 0x0($s1)
    ctx->pc = 0x17f1f8u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), GPR_VEC(ctx, 6));
    // 0x17f1fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F1FCu;
    {
        const bool branch_taken_0x17f1fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F1FCu;
            // 0x17f200: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f1fc) {
            ctx->pc = 0x17F214u;
            goto label_17f214;
        }
    }
    ctx->pc = 0x17F204u;
    // 0x17f204: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f204u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f208: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f208u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f20c: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F20Cu;
    ctx->pc = 0x17F210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F20Cu;
            // 0x17f210: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F214u;
label_17f214:
    // 0x17f214: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f214u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f218: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f218u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f21c: 0x3e00008  jr          $ra
    ctx->pc = 0x17F21Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F21Cu;
            // 0x17f220: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F1F4u: goto label_17f1f4;
            case 0x17F214u: goto label_17f214;
            case 0x17F244u: goto label_17f244;
            case 0x17F27Cu: goto label_17f27c;
            case 0x17F2ACu: goto label_17f2ac;
            case 0x17F2D0u: goto label_17f2d0;
            case 0x17F2FCu: goto label_17f2fc;
            case 0x17F320u: goto label_17f320;
            case 0x17F34Cu: goto label_17f34c;
            case 0x17F370u: goto label_17f370;
            case 0x17F39Cu: goto label_17f39c;
            case 0x17F3C0u: goto label_17f3c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F224u;
    // 0x17f224: 0x0  nop
    ctx->pc = 0x17f224u;
    // NOP
    // 0x17f228: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f22c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f22cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f230: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f230u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f234: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f234u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f238: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f23c: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F23Cu;
    SET_GPR_U32(ctx, 31, 0x17F244u);
    ctx->pc = 0x17F240u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F23Cu;
            // 0x17f240: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F244u; }
        if (ctx->pc != 0x17F244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F244u; }
        if (ctx->pc != 0x17F244u) { return; }
    }
    ctx->pc = 0x17F244u;
label_17f244:
    // 0x17f244: 0x7a060000  lq          $a2, 0x0($s0)
    ctx->pc = 0x17f244u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f248: 0x7a070010  lq          $a3, 0x10($s0)
    ctx->pc = 0x17f248u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17f24c: 0x7a080020  lq          $t0, 0x20($s0)
    ctx->pc = 0x17f24cu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x17f250: 0x7a090030  lq          $t1, 0x30($s0)
    ctx->pc = 0x17f250u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x17f254: 0x7e260000  sq          $a2, 0x0($s1)
    ctx->pc = 0x17f254u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), GPR_VEC(ctx, 6));
    // 0x17f258: 0x7e270010  sq          $a3, 0x10($s1)
    ctx->pc = 0x17f258u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 16), GPR_VEC(ctx, 7));
    // 0x17f25c: 0x7e280020  sq          $t0, 0x20($s1)
    ctx->pc = 0x17f25cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 32), GPR_VEC(ctx, 8));
    // 0x17f260: 0x7e290030  sq          $t1, 0x30($s1)
    ctx->pc = 0x17f260u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 48), GPR_VEC(ctx, 9));
    // 0x17f264: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F264u;
    {
        const bool branch_taken_0x17f264 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F264u;
            // 0x17f268: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f264) {
            ctx->pc = 0x17F27Cu;
            goto label_17f27c;
        }
    }
    ctx->pc = 0x17F26Cu;
    // 0x17f26c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f26cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f270: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f270u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f274: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F274u;
    ctx->pc = 0x17F278u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F274u;
            // 0x17f278: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F27Cu;
label_17f27c:
    // 0x17f27c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f27cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f280: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f280u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f284: 0x3e00008  jr          $ra
    ctx->pc = 0x17F284u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F284u;
            // 0x17f288: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F1F4u: goto label_17f1f4;
            case 0x17F214u: goto label_17f214;
            case 0x17F244u: goto label_17f244;
            case 0x17F27Cu: goto label_17f27c;
            case 0x17F2ACu: goto label_17f2ac;
            case 0x17F2D0u: goto label_17f2d0;
            case 0x17F2FCu: goto label_17f2fc;
            case 0x17F320u: goto label_17f320;
            case 0x17F34Cu: goto label_17f34c;
            case 0x17F370u: goto label_17f370;
            case 0x17F39Cu: goto label_17f39c;
            case 0x17F3C0u: goto label_17f3c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F28Cu;
    // 0x17f28c: 0x0  nop
    ctx->pc = 0x17f28cu;
    // NOP
    // 0x17f290: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f290u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f294: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f294u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f298: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f298u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f29c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f29cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f2a0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f2a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f2a4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F2A4u;
    SET_GPR_U32(ctx, 31, 0x17F2ACu);
    ctx->pc = 0x17F2A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2A4u;
            // 0x17f2a8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F2ACu; }
        if (ctx->pc != 0x17F2ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F2ACu; }
        if (ctx->pc != 0x17F2ACu) { return; }
    }
    ctx->pc = 0x17F2ACu;
label_17f2ac:
    // 0x17f2ac: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f2acu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f2b0: 0x4be5217d  vftoi4.xyzw $vf5, $vf4
    ctx->pc = 0x17f2b0u;
    { __m128 src = ctx->vu0_vf[4]; src = _mm_mul_ps(src, _mm_set1_ps(16.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f2b4: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f2b4u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f2b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F2B8u;
    {
        const bool branch_taken_0x17f2b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F2BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2B8u;
            // 0x17f2bc: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f2b8) {
            ctx->pc = 0x17F2D0u;
            goto label_17f2d0;
        }
    }
    ctx->pc = 0x17F2C0u;
    // 0x17f2c0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f2c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f2c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f2c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f2c8: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F2C8u;
    ctx->pc = 0x17F2CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2C8u;
            // 0x17f2cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F2D0u;
label_17f2d0:
    // 0x17f2d0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f2d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f2d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f2d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f2d8: 0x3e00008  jr          $ra
    ctx->pc = 0x17F2D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F2DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2D8u;
            // 0x17f2dc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F1F4u: goto label_17f1f4;
            case 0x17F214u: goto label_17f214;
            case 0x17F244u: goto label_17f244;
            case 0x17F27Cu: goto label_17f27c;
            case 0x17F2ACu: goto label_17f2ac;
            case 0x17F2D0u: goto label_17f2d0;
            case 0x17F2FCu: goto label_17f2fc;
            case 0x17F320u: goto label_17f320;
            case 0x17F34Cu: goto label_17f34c;
            case 0x17F370u: goto label_17f370;
            case 0x17F39Cu: goto label_17f39c;
            case 0x17F3C0u: goto label_17f3c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F2E0u;
    // 0x17f2e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f2e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f2e4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f2e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f2e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f2e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f2ec: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f2ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f2f0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f2f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f2f4: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F2F4u;
    SET_GPR_U32(ctx, 31, 0x17F2FCu);
    ctx->pc = 0x17F2F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F2F4u;
            // 0x17f2f8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F2FCu; }
        if (ctx->pc != 0x17F2FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F2FCu; }
        if (ctx->pc != 0x17F2FCu) { return; }
    }
    ctx->pc = 0x17F2FCu;
label_17f2fc:
    // 0x17f2fc: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f2fcu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f300: 0x4be5217c  vftoi0.xyzw $vf5, $vf4
    ctx->pc = 0x17f300u;
    { __m128 src = ctx->vu0_vf[4]; src = _mm_mul_ps(src, _mm_set1_ps(1.0f)); __m128i res_i = _mm_cvttps_epi32(src); __m128 res = _mm_castsi128_ps(res_i); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f304: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f304u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f308: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F308u;
    {
        const bool branch_taken_0x17f308 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F30Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F308u;
            // 0x17f30c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f308) {
            ctx->pc = 0x17F320u;
            goto label_17f320;
        }
    }
    ctx->pc = 0x17F310u;
    // 0x17f310: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f310u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f314: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f314u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f318: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F318u;
    ctx->pc = 0x17F31Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F318u;
            // 0x17f31c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F320u;
label_17f320:
    // 0x17f320: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f320u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f324: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f324u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f328: 0x3e00008  jr          $ra
    ctx->pc = 0x17F328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F328u;
            // 0x17f32c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F1F4u: goto label_17f1f4;
            case 0x17F214u: goto label_17f214;
            case 0x17F244u: goto label_17f244;
            case 0x17F27Cu: goto label_17f27c;
            case 0x17F2ACu: goto label_17f2ac;
            case 0x17F2D0u: goto label_17f2d0;
            case 0x17F2FCu: goto label_17f2fc;
            case 0x17F320u: goto label_17f320;
            case 0x17F34Cu: goto label_17f34c;
            case 0x17F370u: goto label_17f370;
            case 0x17F39Cu: goto label_17f39c;
            case 0x17F3C0u: goto label_17f3c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F330u;
    // 0x17f330: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f334: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f338: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f33c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f33cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f340: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f344: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F344u;
    SET_GPR_U32(ctx, 31, 0x17F34Cu);
    ctx->pc = 0x17F348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F344u;
            // 0x17f348: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F34Cu; }
        if (ctx->pc != 0x17F34Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F34Cu; }
        if (ctx->pc != 0x17F34Cu) { return; }
    }
    ctx->pc = 0x17F34Cu;
label_17f34c:
    // 0x17f34c: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f34cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f350: 0x4be5213d  vitof4.xyzw $vf5, $vf4
    ctx->pc = 0x17f350u;
    { __m128i src = _mm_castps_si128(ctx->vu0_vf[4]); __m128 res = _mm_cvtepi32_ps(src); res = _mm_mul_ps(res, _mm_set1_ps(0.0625f)); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f354: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f354u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f358: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F358u;
    {
        const bool branch_taken_0x17f358 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F35Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F358u;
            // 0x17f35c: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f358) {
            ctx->pc = 0x17F370u;
            goto label_17f370;
        }
    }
    ctx->pc = 0x17F360u;
    // 0x17f360: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f360u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f364: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f364u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f368: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F368u;
    ctx->pc = 0x17F36Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F368u;
            // 0x17f36c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F370u;
label_17f370:
    // 0x17f370: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f370u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f374: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f374u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f378: 0x3e00008  jr          $ra
    ctx->pc = 0x17F378u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F37Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F378u;
            // 0x17f37c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F1F4u: goto label_17f1f4;
            case 0x17F214u: goto label_17f214;
            case 0x17F244u: goto label_17f244;
            case 0x17F27Cu: goto label_17f27c;
            case 0x17F2ACu: goto label_17f2ac;
            case 0x17F2D0u: goto label_17f2d0;
            case 0x17F2FCu: goto label_17f2fc;
            case 0x17F320u: goto label_17f320;
            case 0x17F34Cu: goto label_17f34c;
            case 0x17F370u: goto label_17f370;
            case 0x17F39Cu: goto label_17f39c;
            case 0x17F3C0u: goto label_17f3c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F380u;
    // 0x17f380: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f384: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f388: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f38c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17f38cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f390: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f394: 0xc047598  jal         func_11D660
    ctx->pc = 0x17F394u;
    SET_GPR_U32(ctx, 31, 0x17F39Cu);
    ctx->pc = 0x17F398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F394u;
            // 0x17f398: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F39Cu; }
        if (ctx->pc != 0x17F39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F39Cu; }
        if (ctx->pc != 0x17F39Cu) { return; }
    }
    ctx->pc = 0x17F39Cu;
label_17f39c:
    // 0x17f39c: 0xda040000  lqc2        $vf4, 0x0($s0)
    ctx->pc = 0x17f39cu;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17f3a0: 0x4be5213c  vitof0.xyzw $vf5, $vf4
    ctx->pc = 0x17f3a0u;
    { __m128i src = _mm_castps_si128(ctx->vu0_vf[4]); __m128 res = _mm_cvtepi32_ps(src); res = _mm_mul_ps(res, _mm_set1_ps(1.0f)); __m128i mask = _mm_set_epi32(-1, -1, -1, -1); ctx->vu0_vf[5] = _mm_blendv_ps(ctx->vu0_vf[5], res, _mm_castsi128_ps(mask)); }
    // 0x17f3a4: 0xfa250000  sqc2        $vf5, 0x0($s1)
    ctx->pc = 0x17f3a4u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x17f3a8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17F3A8u;
    {
        const bool branch_taken_0x17f3a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17F3ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F3A8u;
            // 0x17f3ac: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17f3a8) {
            ctx->pc = 0x17F3C0u;
            goto label_17f3c0;
        }
    }
    ctx->pc = 0x17F3B0u;
    // 0x17f3b0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f3b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f3b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f3b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f3b8: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17F3B8u;
    ctx->pc = 0x17F3BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F3B8u;
            // 0x17f3bc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F3C0u;
label_17f3c0:
    // 0x17f3c0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f3c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f3c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f3c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f3c8: 0x3e00008  jr          $ra
    ctx->pc = 0x17F3C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F3CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F3C8u;
            // 0x17f3cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F1F4u: goto label_17f1f4;
            case 0x17F214u: goto label_17f214;
            case 0x17F244u: goto label_17f244;
            case 0x17F27Cu: goto label_17f27c;
            case 0x17F2ACu: goto label_17f2ac;
            case 0x17F2D0u: goto label_17f2d0;
            case 0x17F2FCu: goto label_17f2fc;
            case 0x17F320u: goto label_17f320;
            case 0x17F34Cu: goto label_17f34c;
            case 0x17F370u: goto label_17f370;
            case 0x17F39Cu: goto label_17f39c;
            case 0x17F3C0u: goto label_17f3c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F3D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
