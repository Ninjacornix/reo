#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C598
// Address: 0x12c598 - 0x12c5cc
void sub_0012C598_0x12c598(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C598_0x12c598");
#endif

    switch (ctx->pc) {
        case 0x12c5bcu: goto label_12c5bc;
        default: break;
    }

    ctx->pc = 0x12c598u;

    // 0x12c598: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c59c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c5a0: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x12c5a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c5a4: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x12c5a4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12c5a8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12c5a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c5ac: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12c5acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12c5b0: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x12c5b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c5b4: 0xc050374  jal         func_140DD0
    ctx->pc = 0x12C5B4u;
    SET_GPR_U32(ctx, 31, 0x12C5BCu);
    ctx->pc = 0x12C5B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C5B4u;
            // 0x12c5b8: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140DD0u;
    if (runtime->hasFunction(0x140DD0u)) {
        auto targetFn = runtime->lookupFunction(0x140DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C5BCu; }
        if (ctx->pc != 0x12C5BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140DD0_0x140dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C5BCu; }
        if (ctx->pc != 0x12C5BCu) { return; }
    }
    ctx->pc = 0x12C5BCu;
label_12c5bc:
    // 0x12c5bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c5bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c5c0: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x12c5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x12c5c4: 0x3e00008  jr          $ra
    ctx->pc = 0x12C5C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C5C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C5C4u;
            // 0x12c5c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C5BCu: goto label_12c5bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C5CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
