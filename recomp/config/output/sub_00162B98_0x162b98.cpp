#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162B98
// Address: 0x162b98 - 0x162bbc
void sub_00162B98_0x162b98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162B98_0x162b98");
#endif

    switch (ctx->pc) {
        case 0x162bb0u: goto label_162bb0;
        default: break;
    }

    ctx->pc = 0x162b98u;

    // 0x162b98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162b98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x162b9c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x162b9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162ba0: 0x27a50004  addiu       $a1, $sp, 0x4
    ctx->pc = 0x162ba0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x162ba4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x162ba8: 0xc058b04  jal         func_162C10
    ctx->pc = 0x162BA8u;
    SET_GPR_U32(ctx, 31, 0x162BB0u);
    ctx->pc = 0x162BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162BA8u;
            // 0x162bac: 0x27a60008  addiu       $a2, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162C10u;
    if (runtime->hasFunction(0x162C10u)) {
        auto targetFn = runtime->lookupFunction(0x162C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162BB0u; }
        if (ctx->pc != 0x162BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162C10_0x162c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162BB0u; }
        if (ctx->pc != 0x162BB0u) { return; }
    }
    ctx->pc = 0x162BB0u;
label_162bb0:
    // 0x162bb0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x162bb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162bb4: 0x3e00008  jr          $ra
    ctx->pc = 0x162BB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162BB4u;
            // 0x162bb8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162BB0u: goto label_162bb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162BBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
