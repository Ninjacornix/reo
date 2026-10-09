#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DA18
// Address: 0x12da18 - 0x12da30
void sub_0012DA18_0x12da18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DA18_0x12da18");
#endif

    ctx->pc = 0x12da18u;

    // 0x12da18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12da18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12da1c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12da1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12da20: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12da20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12da24: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12da24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12da28: 0x80493a0  j           func_124E80
    ctx->pc = 0x12DA28u;
    ctx->pc = 0x12DA2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12DA28u;
            // 0x12da2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E80u;
    {
        auto targetFn = runtime->lookupFunction(0x124E80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x12DA30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
