#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8AF0
// Address: 0x1c8af0 - 0x1c8b14
void sub_001C8AF0_0x1c8af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8AF0_0x1c8af0");
#endif

    switch (ctx->pc) {
        case 0x1c8b08u: goto label_1c8b08;
        default: break;
    }

    ctx->pc = 0x1c8af0u;

    // 0x1c8af0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8af4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1c8af4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c8af8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8af8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8afc: 0xa7a5001e  sh          $a1, 0x1E($sp)
    ctx->pc = 0x1c8afcu;
    WRITE16(ADD32(GPR_U32(ctx, 29), 30), (uint16_t)GPR_U32(ctx, 5));
    // 0x1c8b00: 0xc072258  jal         func_1C8960
    ctx->pc = 0x1C8B00u;
    SET_GPR_U32(ctx, 31, 0x1C8B08u);
    ctx->pc = 0x1C8B04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8B00u;
            // 0x1c8b04: 0x27a5001e  addiu       $a1, $sp, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8960u;
    if (runtime->hasFunction(0x1C8960u)) {
        auto targetFn = runtime->lookupFunction(0x1C8960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8B08u; }
        if (ctx->pc != 0x1C8B08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8960_0x1c8960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8B08u; }
        if (ctx->pc != 0x1C8B08u) { return; }
    }
    ctx->pc = 0x1C8B08u;
label_1c8b08:
    // 0x1c8b08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8b08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8b0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8B0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8B0Cu;
            // 0x1c8b10: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8B08u: goto label_1c8b08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8B14u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
