#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A8C60
// Address: 0x1a8c60 - 0x1a8ca0
void sub_001A8C60_0x1a8c60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A8C60_0x1a8c60");
#endif

    switch (ctx->pc) {
        case 0x1a8c80u: goto label_1a8c80;
        default: break;
    }

    ctx->pc = 0x1a8c60u;

    // 0x1a8c60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a8c60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a8c64: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8c64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8c68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a8c68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a8c6c: 0x80231040  lb          $v1, 0x1040($at)
    ctx->pc = 0x1a8c6cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4160)));
    // 0x1a8c70: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A8C70u;
    {
        const bool branch_taken_0x1a8c70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8C70u;
            // 0x1a8c74: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8c70) {
            ctx->pc = 0x1A8C88u;
            goto label_1a8c88;
        }
    }
    ctx->pc = 0x1A8C78u;
    // 0x1a8c78: 0xc04c50a  jal         func_131428
    ctx->pc = 0x1A8C78u;
    SET_GPR_U32(ctx, 31, 0x1A8C80u);
    ctx->pc = 0x131428u;
    if (runtime->hasFunction(0x131428u)) {
        auto targetFn = runtime->lookupFunction(0x131428u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8C80u; }
        if (ctx->pc != 0x1A8C80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131428_0x131428(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8C80u; }
        if (ctx->pc != 0x1A8C80u) { return; }
    }
    ctx->pc = 0x1A8C80u;
label_1a8c80:
    // 0x1a8c80: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8c80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8c84: 0xa0201040  sb          $zero, 0x1040($at)
    ctx->pc = 0x1a8c84u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4160), (uint8_t)GPR_U32(ctx, 0));
label_1a8c88:
    // 0x1a8c88: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a8c88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a8c8c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A8C8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A8C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8C8Cu;
            // 0x1a8c90: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A8C80u: goto label_1a8c80;
            case 0x1A8C88u: goto label_1a8c88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A8C94u;
    // 0x1a8c94: 0x0  nop
    ctx->pc = 0x1a8c94u;
    // NOP
    // 0x1a8c98: 0x0  nop
    ctx->pc = 0x1a8c98u;
    // NOP
    // 0x1a8c9c: 0x0  nop
    ctx->pc = 0x1a8c9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
