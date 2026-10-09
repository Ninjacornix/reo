#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178B90
// Address: 0x178b90 - 0x178bc0
void sub_00178B90_0x178b90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178B90_0x178b90");
#endif

    switch (ctx->pc) {
        case 0x178bb0u: goto label_178bb0;
        default: break;
    }

    ctx->pc = 0x178b90u;

    // 0x178b90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x178b90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x178b94: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x178b94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178b98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x178b98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x178b9c: 0x24452a78  addiu       $a1, $v0, 0x2A78
    ctx->pc = 0x178b9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 10872));
    // 0x178ba0: 0x24421cc0  addiu       $v0, $v0, 0x1CC0
    ctx->pc = 0x178ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7360));
    // 0x178ba4: 0xac450008  sw          $a1, 0x8($v0)
    ctx->pc = 0x178ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 5));
    // 0x178ba8: 0xc05e2f0  jal         func_178BC0
    ctx->pc = 0x178BA8u;
    SET_GPR_U32(ctx, 31, 0x178BB0u);
    ctx->pc = 0x178BACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178BA8u;
            // 0x178bac: 0x8c460010  lw          $a2, 0x10($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178BC0u;
    if (runtime->hasFunction(0x178BC0u)) {
        auto targetFn = runtime->lookupFunction(0x178BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178BB0u; }
        if (ctx->pc != 0x178BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178BC0_0x178bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178BB0u; }
        if (ctx->pc != 0x178BB0u) { return; }
    }
    ctx->pc = 0x178BB0u;
label_178bb0:
    // 0x178bb0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x178bb0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178bb4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x178bb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178bb8: 0x3e00008  jr          $ra
    ctx->pc = 0x178BB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178BB8u;
            // 0x178bbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178BB0u: goto label_178bb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178BC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
