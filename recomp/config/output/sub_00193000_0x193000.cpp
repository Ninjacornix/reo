#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193000
// Address: 0x193000 - 0x193030
void sub_00193000_0x193000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193000_0x193000");
#endif

    switch (ctx->pc) {
        case 0x193010u: goto label_193010;
        default: break;
    }

    ctx->pc = 0x193000u;

    // 0x193000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x193000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x193004: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x193004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x193008: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x193008u;
    SET_GPR_U32(ctx, 31, 0x193010u);
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193010u; }
        if (ctx->pc != 0x193010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193010u; }
        if (ctx->pc != 0x193010u) { return; }
    }
    ctx->pc = 0x193010u;
label_193010:
    // 0x193010: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x193010u;
    {
        const bool branch_taken_0x193010 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x193010) {
            ctx->pc = 0x193020u;
            goto label_193020;
        }
    }
    ctx->pc = 0x193018u;
    // 0x193018: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x193018u;
    {
        const bool branch_taken_0x193018 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19301Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193018u;
            // 0x19301c: 0x84420002  lh          $v0, 0x2($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193018) {
            ctx->pc = 0x193024u;
            goto label_193024;
        }
    }
    ctx->pc = 0x193020u;
label_193020:
    // 0x193020: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x193020u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_193024:
    // 0x193024: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x193024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x193028: 0x3e00008  jr          $ra
    ctx->pc = 0x193028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19302Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193028u;
            // 0x19302c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193010u: goto label_193010;
            case 0x193020u: goto label_193020;
            case 0x193024u: goto label_193024;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193030u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
