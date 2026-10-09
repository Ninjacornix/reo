#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125C08
// Address: 0x125c08 - 0x125c30
void sub_00125C08_0x125c08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125C08_0x125c08");
#endif

    switch (ctx->pc) {
        case 0x125c20u: goto label_125c20;
        default: break;
    }

    ctx->pc = 0x125c08u;

    // 0x125c08: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x125c08u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x125c0c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x125c0cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x125c10: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x125c10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x125c14: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x125c14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x125c18: 0xc041e86  jal         func_107A18
    ctx->pc = 0x125C18u;
    SET_GPR_U32(ctx, 31, 0x125C20u);
    ctx->pc = 0x125C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125C18u;
            // 0x125c1c: 0x24a59bb8  addiu       $a1, $a1, -0x6448 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941624));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125C20u; }
        if (ctx->pc != 0x125C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125C20u; }
        if (ctx->pc != 0x125C20u) { return; }
    }
    ctx->pc = 0x125C20u;
label_125c20:
    // 0x125c20: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x125c20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125c24: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x125c24u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x125c28: 0x3e00008  jr          $ra
    ctx->pc = 0x125C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125C28u;
            // 0x125c2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C20u: goto label_125c20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125C30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
