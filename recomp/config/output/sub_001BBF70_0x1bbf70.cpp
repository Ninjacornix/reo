#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BBF70
// Address: 0x1bbf70 - 0x1bbfa0
void sub_001BBF70_0x1bbf70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BBF70_0x1bbf70");
#endif

    switch (ctx->pc) {
        case 0x1bbf8cu: goto label_1bbf8c;
        case 0x1bbf94u: goto label_1bbf94;
        default: break;
    }

    ctx->pc = 0x1bbf70u;

    // 0x1bbf70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bbf70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bbf74: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bbf74u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bbf78: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bbf78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bbf7c: 0x248465e0  addiu       $a0, $a0, 0x65E0
    ctx->pc = 0x1bbf7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26080));
    // 0x1bbf80: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bbf80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bbf84: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BBF84u;
    SET_GPR_U32(ctx, 31, 0x1BBF8Cu);
    ctx->pc = 0x1BBF88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBF84u;
            // 0x1bbf88: 0x24060018  addiu       $a2, $zero, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBF8Cu; }
        if (ctx->pc != 0x1BBF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBF8Cu; }
        if (ctx->pc != 0x1BBF8Cu) { return; }
    }
    ctx->pc = 0x1BBF8Cu;
label_1bbf8c:
    // 0x1bbf8c: 0xc06f0e0  jal         func_1BC380
    ctx->pc = 0x1BBF8Cu;
    SET_GPR_U32(ctx, 31, 0x1BBF94u);
    ctx->pc = 0x1BC380u;
    if (runtime->hasFunction(0x1BC380u)) {
        auto targetFn = runtime->lookupFunction(0x1BC380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBF94u; }
        if (ctx->pc != 0x1BBF94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC380_0x1bc380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBF94u; }
        if (ctx->pc != 0x1BBF94u) { return; }
    }
    ctx->pc = 0x1BBF94u;
label_1bbf94:
    // 0x1bbf94: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bbf94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bbf98: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBF98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BBF9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBF98u;
            // 0x1bbf9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBF8Cu: goto label_1bbf8c;
            case 0x1BBF94u: goto label_1bbf94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBFA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
