#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019E5D0
// Address: 0x19e5d0 - 0x19e6b0
void sub_0019E5D0_0x19e5d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019E5D0_0x19e5d0");
#endif

    switch (ctx->pc) {
        case 0x19e60cu: goto label_19e60c;
        case 0x19e618u: goto label_19e618;
        case 0x19e668u: goto label_19e668;
        default: break;
    }

    ctx->pc = 0x19e5d0u;

    // 0x19e5d0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19e5d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19e5d4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x19e5d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x19e5d8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x19e5d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x19e5dc: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x19e5dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x19e5e0: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x19e5e0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e5e4: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x19e5e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19e5e8: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x19e5e8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e5ec: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19e5ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19e5f0: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x19e5f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e5f4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19e5f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19e5f8: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x19e5f8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e5fc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19e5fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19e600: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x19e600u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x19e604: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19e604u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19e608: 0x26310890  addiu       $s1, $s1, 0x890
    ctx->pc = 0x19e608u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2192));
label_19e60c:
    // 0x19e60c: 0x131280  sll         $v0, $s3, 10
    ctx->pc = 0x19e60cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 10));
    // 0x19e610: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x19e610u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e614: 0x2c28021  addu        $s0, $s6, $v0
    ctx->pc = 0x19e614u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 2)));
label_19e618:
    // 0x19e618: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x19e618u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x19e61c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x19e61cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x19e620: 0x121100  sll         $v0, $s2, 4
    ctx->pc = 0x19e620u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x19e624: 0x24630810  addiu       $v1, $v1, 0x810
    ctx->pc = 0x19e624u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2064));
    // 0x19e628: 0x2022021  addu        $a0, $s0, $v0
    ctx->pc = 0x19e628u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x19e62c: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x19e62cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e630: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x19e630u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x19e634: 0x24420790  addiu       $v0, $v0, 0x790
    ctx->pc = 0x19e634u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1936));
    // 0x19e638: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x19e638u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x19e63c: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x19e63cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x19e640: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x19e640u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x19e644: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x19e644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x19e648: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x19e648u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x19e64c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x19e64cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x19e650: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x19e650u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x19e654: 0x2831818  mult        $v1, $s4, $v1
    ctx->pc = 0x19e654u;
    { int64_t result = (int64_t)GPR_S32(ctx, 20) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19e658: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x19e658u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x19e65c: 0x2a31821  addu        $v1, $s5, $v1
    ctx->pc = 0x19e65cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x19e660: 0xc0679ac  jal         func_19E6B0
    ctx->pc = 0x19E660u;
    SET_GPR_U32(ctx, 31, 0x19E668u);
    ctx->pc = 0x19E664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19E660u;
            // 0x19e664: 0x622821  addu        $a1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19E6B0u;
    if (runtime->hasFunction(0x19E6B0u)) {
        auto targetFn = runtime->lookupFunction(0x19E6B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E668u; }
        if (ctx->pc != 0x19E668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019E6B0_0x19e6b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E668u; }
        if (ctx->pc != 0x19E668u) { return; }
    }
    ctx->pc = 0x19E668u;
label_19e668:
    // 0x19e668: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x19e668u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x19e66c: 0x2a430004  slti        $v1, $s2, 0x4
    ctx->pc = 0x19e66cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x19e670: 0x1460ffe9  bnez        $v1, . + 4 + (-0x17 << 2)
    ctx->pc = 0x19E670u;
    {
        const bool branch_taken_0x19e670 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19e670) {
            ctx->pc = 0x19E618u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e618;
        }
    }
    ctx->pc = 0x19E678u;
    // 0x19e678: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x19e678u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x19e67c: 0x2a630008  slti        $v1, $s3, 0x8
    ctx->pc = 0x19e67cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x19e680: 0x1460ffe2  bnez        $v1, . + 4 + (-0x1E << 2)
    ctx->pc = 0x19E680u;
    {
        const bool branch_taken_0x19e680 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19e680) {
            ctx->pc = 0x19E60Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e60c;
        }
    }
    ctx->pc = 0x19E688u;
    // 0x19e688: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x19e688u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x19e68c: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x19e68cu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x19e690: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x19e690u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x19e694: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x19e694u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19e698: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19e698u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19e69c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19e69cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19e6a0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19e6a0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19e6a4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19e6a4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19e6a8: 0x3e00008  jr          $ra
    ctx->pc = 0x19E6A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19E6ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E6A8u;
            // 0x19e6ac: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19E60Cu: goto label_19e60c;
            case 0x19E618u: goto label_19e618;
            case 0x19E668u: goto label_19e668;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19E6B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
