#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169F08
// Address: 0x169f08 - 0x169f2c
void sub_00169F08_0x169f08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169F08_0x169f08");
#endif

    switch (ctx->pc) {
        case 0x169f1cu: goto label_169f1c;
        default: break;
    }

    ctx->pc = 0x169f08u;

    // 0x169f08: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169f08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169f0c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x169f0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x169f10: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169f10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169f14: 0xc059f28  jal         func_167CA0
    ctx->pc = 0x169F14u;
    SET_GPR_U32(ctx, 31, 0x169F1Cu);
    ctx->pc = 0x169F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169F14u;
            // 0x169f18: 0x8c851ab4  lw          $a1, 0x1AB4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6836)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CA0u;
    if (runtime->hasFunction(0x167CA0u)) {
        auto targetFn = runtime->lookupFunction(0x167CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169F1Cu; }
        if (ctx->pc != 0x169F1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CA0_0x167ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169F1Cu; }
        if (ctx->pc != 0x169F1Cu) { return; }
    }
    ctx->pc = 0x169F1Cu;
label_169f1c:
    // 0x169f1c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x169f1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169f20: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169f20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169f24: 0x3e00008  jr          $ra
    ctx->pc = 0x169F24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169F28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169F24u;
            // 0x169f28: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169F1Cu: goto label_169f1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169F2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
