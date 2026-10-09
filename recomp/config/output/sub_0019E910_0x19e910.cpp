#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019E910
// Address: 0x19e910 - 0x19e9f0
void sub_0019E910_0x19e910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019E910_0x19e910");
#endif

    switch (ctx->pc) {
        case 0x19e94cu: goto label_19e94c;
        case 0x19e958u: goto label_19e958;
        case 0x19e9a8u: goto label_19e9a8;
        default: break;
    }

    ctx->pc = 0x19e910u;

    // 0x19e910: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19e910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19e914: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x19e914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x19e918: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x19e918u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x19e91c: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x19e91cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x19e920: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x19e920u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e924: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x19e924u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19e928: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x19e928u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e92c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19e92cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19e930: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x19e930u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e934: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19e934u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19e938: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x19e938u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e93c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19e93cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19e940: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x19e940u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x19e944: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19e944u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19e948: 0x26310910  addiu       $s1, $s1, 0x910
    ctx->pc = 0x19e948u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2320));
label_19e94c:
    // 0x19e94c: 0x1312c0  sll         $v0, $s3, 11
    ctx->pc = 0x19e94cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 11));
    // 0x19e950: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x19e950u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e954: 0x2c28021  addu        $s0, $s6, $v0
    ctx->pc = 0x19e954u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 2)));
label_19e958:
    // 0x19e958: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x19e958u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x19e95c: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x19e95cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x19e960: 0x121100  sll         $v0, $s2, 4
    ctx->pc = 0x19e960u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
    // 0x19e964: 0x24630810  addiu       $v1, $v1, 0x810
    ctx->pc = 0x19e964u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2064));
    // 0x19e968: 0x2022021  addu        $a0, $s0, $v0
    ctx->pc = 0x19e968u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x19e96c: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x19e96cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e970: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x19e970u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x19e974: 0x24420790  addiu       $v0, $v0, 0x790
    ctx->pc = 0x19e974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1936));
    // 0x19e978: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x19e978u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x19e97c: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x19e97cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x19e980: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x19e980u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x19e984: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x19e984u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x19e988: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x19e988u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x19e98c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x19e98cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x19e990: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x19e990u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x19e994: 0x2831818  mult        $v1, $s4, $v1
    ctx->pc = 0x19e994u;
    { int64_t result = (int64_t)GPR_S32(ctx, 20) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19e998: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x19e998u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x19e99c: 0x2a31821  addu        $v1, $s5, $v1
    ctx->pc = 0x19e99cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x19e9a0: 0xc067a7c  jal         func_19E9F0
    ctx->pc = 0x19E9A0u;
    SET_GPR_U32(ctx, 31, 0x19E9A8u);
    ctx->pc = 0x19E9A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19E9A0u;
            // 0x19e9a4: 0x622821  addu        $a1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19E9F0u;
    if (runtime->hasFunction(0x19E9F0u)) {
        auto targetFn = runtime->lookupFunction(0x19E9F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E9A8u; }
        if (ctx->pc != 0x19E9A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019E9F0_0x19e9f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E9A8u; }
        if (ctx->pc != 0x19E9A8u) { return; }
    }
    ctx->pc = 0x19E9A8u;
label_19e9a8:
    // 0x19e9a8: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x19e9a8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x19e9ac: 0x2a430008  slti        $v1, $s2, 0x8
    ctx->pc = 0x19e9acu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x19e9b0: 0x1460ffe9  bnez        $v1, . + 4 + (-0x17 << 2)
    ctx->pc = 0x19E9B0u;
    {
        const bool branch_taken_0x19e9b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19e9b0) {
            ctx->pc = 0x19E958u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e958;
        }
    }
    ctx->pc = 0x19E9B8u;
    // 0x19e9b8: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x19e9b8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x19e9bc: 0x2a630004  slti        $v1, $s3, 0x4
    ctx->pc = 0x19e9bcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x19e9c0: 0x1460ffe2  bnez        $v1, . + 4 + (-0x1E << 2)
    ctx->pc = 0x19E9C0u;
    {
        const bool branch_taken_0x19e9c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19e9c0) {
            ctx->pc = 0x19E94Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e94c;
        }
    }
    ctx->pc = 0x19E9C8u;
    // 0x19e9c8: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x19e9c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x19e9cc: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x19e9ccu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x19e9d0: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x19e9d0u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x19e9d4: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x19e9d4u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19e9d8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19e9d8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19e9dc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19e9dcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19e9e0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19e9e0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19e9e4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19e9e4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19e9e8: 0x3e00008  jr          $ra
    ctx->pc = 0x19E9E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19E9ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E9E8u;
            // 0x19e9ec: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19E94Cu: goto label_19e94c;
            case 0x19E958u: goto label_19e958;
            case 0x19E9A8u: goto label_19e9a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19E9F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
