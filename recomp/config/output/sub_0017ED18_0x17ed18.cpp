#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017ED18
// Address: 0x17ed18 - 0x17eda0
void sub_0017ED18_0x17ed18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017ED18_0x17ed18");
#endif

    switch (ctx->pc) {
        case 0x17ed34u: goto label_17ed34;
        default: break;
    }

    ctx->pc = 0x17ed18u;

    // 0x17ed18: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17ed18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17ed1c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17ed1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17ed20: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17ed20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17ed24: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17ed24u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ed28: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17ed28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17ed2c: 0xc047598  jal         func_11D660
    ctx->pc = 0x17ED2Cu;
    SET_GPR_U32(ctx, 31, 0x17ED34u);
    ctx->pc = 0x17ED30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ED2Cu;
            // 0x17ed30: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17ED34u; }
        if (ctx->pc != 0x17ED34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17ED34u; }
        if (ctx->pc != 0x17ED34u) { return; }
    }
    ctx->pc = 0x17ED34u;
label_17ed34:
    // 0x17ed34: 0x7a080000  lq          $t0, 0x0($s0)
    ctx->pc = 0x17ed34u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x17ed38: 0x7a090010  lq          $t1, 0x10($s0)
    ctx->pc = 0x17ed38u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17ed3c: 0x7a0a0020  lq          $t2, 0x20($s0)
    ctx->pc = 0x17ed3cu;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x17ed40: 0x7a0b0030  lq          $t3, 0x30($s0)
    ctx->pc = 0x17ed40u;
    SET_GPR_VEC(ctx, 11, READ128(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x17ed44: 0x71286488  pextlw      $t4, $t1, $t0
    ctx->pc = 0x17ed44u;
    SET_GPR_VEC(ctx, 12, PS2_PEXTLW(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x17ed48: 0x71286ca8  pextuw      $t5, $t1, $t0
    ctx->pc = 0x17ed48u;
    SET_GPR_VEC(ctx, 13, PS2_PEXTUW(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x17ed4c: 0x716a7488  pextlw      $t6, $t3, $t2
    ctx->pc = 0x17ed4cu;
    SET_GPR_VEC(ctx, 14, PS2_PEXTLW(GPR_VEC(ctx, 11), GPR_VEC(ctx, 10)));
    // 0x17ed50: 0x716a7ca8  pextuw      $t7, $t3, $t2
    ctx->pc = 0x17ed50u;
    SET_GPR_VEC(ctx, 15, PS2_PEXTUW(GPR_VEC(ctx, 11), GPR_VEC(ctx, 10)));
    // 0x17ed54: 0x71cc4389  pcpyld      $t0, $t6, $t4
    ctx->pc = 0x17ed54u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x17ed58: 0x718e4ba9  pcpyud      $t1, $t4, $t6
    ctx->pc = 0x17ed58u;
    SET_GPR_VEC(ctx, 9, _mm_unpackhi_epi64(GPR_VEC(ctx, 12), GPR_VEC(ctx, 14)));
    // 0x17ed5c: 0x71ed5389  pcpyld      $t2, $t7, $t5
    ctx->pc = 0x17ed5cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 15), GPR_VEC(ctx, 13)));
    // 0x17ed60: 0x71af5ba9  pcpyud      $t3, $t5, $t7
    ctx->pc = 0x17ed60u;
    SET_GPR_VEC(ctx, 11, _mm_unpackhi_epi64(GPR_VEC(ctx, 13), GPR_VEC(ctx, 15)));
    // 0x17ed64: 0x7e280000  sq          $t0, 0x0($s1)
    ctx->pc = 0x17ed64u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 0), GPR_VEC(ctx, 8));
    // 0x17ed68: 0x7e290010  sq          $t1, 0x10($s1)
    ctx->pc = 0x17ed68u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 16), GPR_VEC(ctx, 9));
    // 0x17ed6c: 0x7e2a0020  sq          $t2, 0x20($s1)
    ctx->pc = 0x17ed6cu;
    WRITE128(ADD32(GPR_U32(ctx, 17), 32), GPR_VEC(ctx, 10));
    // 0x17ed70: 0x7e2b0030  sq          $t3, 0x30($s1)
    ctx->pc = 0x17ed70u;
    WRITE128(ADD32(GPR_U32(ctx, 17), 48), GPR_VEC(ctx, 11));
    // 0x17ed74: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17ED74u;
    {
        const bool branch_taken_0x17ed74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17ED78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17ED74u;
            // 0x17ed78: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17ed74) {
            ctx->pc = 0x17ED8Cu;
            goto label_17ed8c;
        }
    }
    ctx->pc = 0x17ED7Cu;
    // 0x17ed7c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ed7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ed80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ed80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ed84: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x17ED84u;
    ctx->pc = 0x17ED88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ED84u;
            // 0x17ed88: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17ED8Cu;
label_17ed8c:
    // 0x17ed8c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17ed8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ed90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ed90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ed94: 0x3e00008  jr          $ra
    ctx->pc = 0x17ED94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17ED98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17ED94u;
            // 0x17ed98: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17ED34u: goto label_17ed34;
            case 0x17ED8Cu: goto label_17ed8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17ED9Cu;
    // 0x17ed9c: 0x0  nop
    ctx->pc = 0x17ed9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
