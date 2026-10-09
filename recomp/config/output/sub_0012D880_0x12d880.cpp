#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D880
// Address: 0x12d880 - 0x12d8b0
void sub_0012D880_0x12d880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D880_0x12d880");
#endif

    ctx->pc = 0x12d880u;

    // 0x12d880: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d880u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d884: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12d884u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d888: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12D888u;
    {
        const bool branch_taken_0x12d888 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D88Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D888u;
            // 0x12d88c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d888) {
            ctx->pc = 0x12D8A0u;
            goto label_12d8a0;
        }
    }
    ctx->pc = 0x12D890u;
    // 0x12d890: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d890u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d894: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d894u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d898: 0x80493c8  j           func_124F20
    ctx->pc = 0x12D898u;
    ctx->pc = 0x12D89Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D898u;
            // 0x12d89c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124F20u;
    if (runtime->hasFunction(0x124F20u)) {
        auto targetFn = runtime->lookupFunction(0x124F20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124F20_0x124f20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D8A0u;
label_12d8a0:
    // 0x12d8a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d8a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d8a4: 0x3e00008  jr          $ra
    ctx->pc = 0x12D8A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D8A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D8A4u;
            // 0x12d8a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D8A0u: goto label_12d8a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D8ACu;
    // 0x12d8ac: 0x0  nop
    ctx->pc = 0x12d8acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
