#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013E640
// Address: 0x13e640 - 0x13e688
void sub_0013E640_0x13e640(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013E640_0x13e640");
#endif

    switch (ctx->pc) {
        case 0x13e674u: goto label_13e674;
        default: break;
    }

    ctx->pc = 0x13e640u;

    // 0x13e640: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13e640u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13e644: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13e644u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13e648: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13e648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13e64c: 0x24501468  addiu       $s0, $v0, 0x1468
    ctx->pc = 0x13e64cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 5224));
    // 0x13e650: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x13e650u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e654: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13E654u;
    {
        const bool branch_taken_0x13e654 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13E658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E654u;
            // 0x13e658: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e654) {
            ctx->pc = 0x13E678u;
            goto label_13e678;
        }
    }
    ctx->pc = 0x13E65Cu;
    // 0x13e65c: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x13e65cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13e660: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13e660u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e664: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13e664u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e668: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e668u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e66c: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E66Cu;
    SET_GPR_U32(ctx, 31, 0x13E674u);
    ctx->pc = 0x13E670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E66Cu;
            // 0x13e670: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E674u; }
        if (ctx->pc != 0x13E674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E674u; }
        if (ctx->pc != 0x13E674u) { return; }
    }
    ctx->pc = 0x13E674u;
label_13e674:
    // 0x13e674: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13e674u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_13e678:
    // 0x13e678: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e678u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e67c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13e67cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e680: 0x3e00008  jr          $ra
    ctx->pc = 0x13E680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E680u;
            // 0x13e684: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E674u: goto label_13e674;
            case 0x13E678u: goto label_13e678;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E688u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
