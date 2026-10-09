#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9090
// Address: 0x1b9090 - 0x1b90b8
void sub_001B9090_0x1b9090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9090_0x1b9090");
#endif

    switch (ctx->pc) {
        case 0x1b90a0u: goto label_1b90a0;
        default: break;
    }

    ctx->pc = 0x1b9090u;

    // 0x1b9090: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b9090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b9094: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b9094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b9098: 0xc15d1a0  jal         func_574680
    ctx->pc = 0x1B9098u;
    SET_GPR_U32(ctx, 31, 0x1B90A0u);
    ctx->pc = 0x1B909Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9098u;
            // 0x1b909c: 0x24840038  addiu       $a0, $a0, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
        ctx->in_delay_slot = false;
    ctx->pc = 0x574680u;
    {
        auto targetFn = runtime->lookupFunction(0x574680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B90A0u; }
        if (ctx->pc != 0x1B90A0u) { return; }
    }
    ctx->pc = 0x1B90A0u;
label_1b90a0:
    // 0x1b90a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b90a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b90a4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1b90a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1b90a8: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1b90a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1b90ac: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1b90acu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1b90b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1B90B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B90B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B90B0u;
            // 0x1b90b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B90A0u: goto label_1b90a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B90B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
