#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167DD0
// Address: 0x167dd0 - 0x167df0
void sub_00167DD0_0x167dd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167DD0_0x167dd0");
#endif

    switch (ctx->pc) {
        case 0x167de0u: goto label_167de0;
        default: break;
    }

    ctx->pc = 0x167dd0u;

    // 0x167dd0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x167dd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x167dd4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x167dd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x167dd8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x167DD8u;
    SET_GPR_U32(ctx, 31, 0x167DE0u);
    ctx->pc = 0x167DDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167DD8u;
            // 0x167ddc: 0x24050031  addiu       $a1, $zero, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167DE0u; }
        if (ctx->pc != 0x167DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167DE0u; }
        if (ctx->pc != 0x167DE0u) { return; }
    }
    ctx->pc = 0x167DE0u;
label_167de0:
    // 0x167de0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x167de0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x167de4: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x167de4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x167de8: 0x3e00008  jr          $ra
    ctx->pc = 0x167DE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167DE8u;
            // 0x167dec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167DE0u: goto label_167de0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167DF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
