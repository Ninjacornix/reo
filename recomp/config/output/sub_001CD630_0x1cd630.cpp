#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD630
// Address: 0x1cd630 - 0x1cd6a0
void sub_001CD630_0x1cd630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD630_0x1cd630");
#endif

    switch (ctx->pc) {
        case 0x1cd66cu: goto label_1cd66c;
        case 0x1cd684u: goto label_1cd684;
        default: break;
    }

    ctx->pc = 0x1cd630u;

    // 0x1cd630: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cd630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cd634: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd634u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd638: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cd638u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cd63c: 0x51880  sll         $v1, $a1, 2
    ctx->pc = 0x1cd63cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1cd640: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd640u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd644: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd644u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd648: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd648u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd64c: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1cd64cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd650: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd650u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd654: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1cd654u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd658: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd658u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd65c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd65cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd660: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd660u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd664: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD664u;
    SET_GPR_U32(ctx, 31, 0x1CD66Cu);
    ctx->pc = 0x1CD668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD664u;
            // 0x1cd668: 0x24a56010  addiu       $a1, $a1, 0x6010 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD66Cu; }
        if (ctx->pc != 0x1CD66Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD66Cu; }
        if (ctx->pc != 0x1CD66Cu) { return; }
    }
    ctx->pc = 0x1CD66Cu;
label_1cd66c:
    // 0x1cd66c: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CD66Cu;
    {
        const bool branch_taken_0x1cd66c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD66Cu;
            // 0x1cd670: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd66c) {
            ctx->pc = 0x1CD684u;
            goto label_1cd684;
        }
    }
    ctx->pc = 0x1CD674u;
    // 0x1cd674: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd674u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd678: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd678u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd67c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CD67Cu;
    SET_GPR_U32(ctx, 31, 0x1CD684u);
    ctx->pc = 0x1CD680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD67Cu;
            // 0x1cd680: 0x24a55fa0  addiu       $a1, $a1, 0x5FA0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD684u; }
        if (ctx->pc != 0x1CD684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD684u; }
        if (ctx->pc != 0x1CD684u) { return; }
    }
    ctx->pc = 0x1CD684u;
label_1cd684:
    // 0x1cd684: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cd684u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cd688: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cd688u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cd68c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd68cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd690: 0x24420af0  addiu       $v0, $v0, 0xAF0
    ctx->pc = 0x1cd690u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2800));
    // 0x1cd694: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD694u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD694u;
            // 0x1cd698: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD66Cu: goto label_1cd66c;
            case 0x1CD684u: goto label_1cd684;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD69Cu;
    // 0x1cd69c: 0x0  nop
    ctx->pc = 0x1cd69cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
