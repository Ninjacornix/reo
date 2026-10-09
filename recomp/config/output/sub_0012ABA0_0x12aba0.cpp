#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012ABA0
// Address: 0x12aba0 - 0x12abf8
void sub_0012ABA0_0x12aba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012ABA0_0x12aba0");
#endif

    switch (ctx->pc) {
        case 0x12abc8u: goto label_12abc8;
        case 0x12abd0u: goto label_12abd0;
        default: break;
    }

    ctx->pc = 0x12aba0u;

    // 0x12aba0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12aba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12aba4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12aba4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12aba8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12aba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12abac: 0x244204f8  addiu       $v0, $v0, 0x4F8
    ctx->pc = 0x12abacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1272));
    // 0x12abb0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12abb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12abb4: 0xdc430000  ld          $v1, 0x0($v0)
    ctx->pc = 0x12abb4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12abb8: 0x54600008  bnel        $v1, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x12ABB8u;
    {
        const bool branch_taken_0x12abb8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12abb8) {
            ctx->pc = 0x12ABBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12ABB8u;
            // 0x12abbc: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12ABDCu;
            goto label_12abdc;
        }
    }
    ctx->pc = 0x12ABC0u;
    // 0x12abc0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x12abc0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12abc4: 0x0  nop
    ctx->pc = 0x12abc4u;
    // NOP
label_12abc8:
    // 0x12abc8: 0xc04aae2  jal         func_12AB88
    ctx->pc = 0x12ABC8u;
    SET_GPR_U32(ctx, 31, 0x12ABD0u);
    ctx->pc = 0x12AB88u;
    if (runtime->hasFunction(0x12AB88u)) {
        auto targetFn = runtime->lookupFunction(0x12AB88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ABD0u; }
        if (ctx->pc != 0x12ABD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012AB88_0x12ab88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12ABD0u; }
        if (ctx->pc != 0x12ABD0u) { return; }
    }
    ctx->pc = 0x12ABD0u;
label_12abd0:
    // 0x12abd0: 0xde020000  ld          $v0, 0x0($s0)
    ctx->pc = 0x12abd0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12abd4: 0x1040fffc  beqz        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x12ABD4u;
    {
        const bool branch_taken_0x12abd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12ABD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12ABD4u;
            // 0x12abd8: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12abd4) {
            ctx->pc = 0x12ABC8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12abc8;
        }
    }
    ctx->pc = 0x12ABDCu;
label_12abdc:
    // 0x12abdc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12abdcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12abe0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12abe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12abe4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12abe4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12abe8: 0x24420500  addiu       $v0, $v0, 0x500
    ctx->pc = 0x12abe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1280));
    // 0x12abec: 0xfc430000  sd          $v1, 0x0($v0)
    ctx->pc = 0x12abecu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x12abf0: 0x8045118  j           func_114460
    ctx->pc = 0x12ABF0u;
    ctx->pc = 0x12ABF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12ABF0u;
            // 0x12abf4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114460_0x114460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12ABF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
