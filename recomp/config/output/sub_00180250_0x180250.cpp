#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180250
// Address: 0x180250 - 0x1802d0
void sub_00180250_0x180250(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180250_0x180250");
#endif

    switch (ctx->pc) {
        case 0x180280u: goto label_180280;
        case 0x18029cu: goto label_18029c;
        case 0x1802b4u: goto label_1802b4;
        default: break;
    }

    ctx->pc = 0x180250u;

    // 0x180250: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x180250u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x180254: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x180254u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x180258: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x180258u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18025c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18025cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x180260: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x180260u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180264: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x180264u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x180268: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x180268u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18026c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18026cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x180270: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x180270u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180274: 0x8c900014  lw          $s0, 0x14($a0)
    ctx->pc = 0x180274u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x180278: 0xc045228  jal         func_1148A0
    ctx->pc = 0x180278u;
    SET_GPR_U32(ctx, 31, 0x180280u);
    ctx->pc = 0x18027Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180278u;
            // 0x18027c: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180280u; }
        if (ctx->pc != 0x180280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x180280u; }
        if (ctx->pc != 0x180280u) { return; }
    }
    ctx->pc = 0x180280u;
label_180280:
    // 0x180280: 0x12000007  beqz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x180280u;
    {
        const bool branch_taken_0x180280 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x180280) {
            ctx->pc = 0x1802A0u;
            goto label_1802a0;
        }
    }
    ctx->pc = 0x180288u;
    // 0x180288: 0x2539021  addu        $s2, $s2, $s3
    ctx->pc = 0x180288u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
    // 0x18028c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x18028cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180290: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x180290u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180294: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x180294u;
    SET_GPR_U32(ctx, 31, 0x18029Cu);
    ctx->pc = 0x180298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180294u;
            // 0x180298: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18029Cu; }
        if (ctx->pc != 0x18029Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18029Cu; }
        if (ctx->pc != 0x18029Cu) { return; }
    }
    ctx->pc = 0x18029Cu;
label_18029c:
    // 0x18029c: 0x0  nop
    ctx->pc = 0x18029cu;
    // NOP
label_1802a0:
    // 0x1802a0: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x1802a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1802a4: 0x8e25001c  lw          $a1, 0x1C($s1)
    ctx->pc = 0x1802a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1802a8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1802a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1802ac: 0xc06007c  jal         func_1801F0
    ctx->pc = 0x1802ACu;
    SET_GPR_U32(ctx, 31, 0x1802B4u);
    ctx->pc = 0x1802B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1802ACu;
            // 0x1802b0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1801F0u;
    if (runtime->hasFunction(0x1801F0u)) {
        auto targetFn = runtime->lookupFunction(0x1801F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1802B4u; }
        if (ctx->pc != 0x1802B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001801F0_0x1801f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1802B4u; }
        if (ctx->pc != 0x1802B4u) { return; }
    }
    ctx->pc = 0x1802B4u;
label_1802b4:
    // 0x1802b4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1802b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1802b8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1802b8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1802bc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1802bcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1802c0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1802c0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1802c4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1802c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1802c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1802C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1802CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1802C8u;
            // 0x1802cc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180280u: goto label_180280;
            case 0x18029Cu: goto label_18029c;
            case 0x1802A0u: goto label_1802a0;
            case 0x1802B4u: goto label_1802b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1802D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
