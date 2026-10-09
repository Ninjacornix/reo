#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173B00
// Address: 0x173b00 - 0x173b28
void sub_00173B00_0x173b00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173B00_0x173b00");
#endif

    switch (ctx->pc) {
        case 0x173b1cu: goto label_173b1c;
        default: break;
    }

    ctx->pc = 0x173b00u;

    // 0x173b00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173b00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173b04: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x173b04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x173b08: 0x24060006  addiu       $a2, $zero, 0x6
    ctx->pc = 0x173b08u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x173b0c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x173b0cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173b10: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x173b10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x173b14: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x173B14u;
    SET_GPR_U32(ctx, 31, 0x173B1Cu);
    ctx->pc = 0x173B18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173B14u;
            // 0x173b18: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173B1Cu; }
        if (ctx->pc != 0x173B1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173B1Cu; }
        if (ctx->pc != 0x173B1Cu) { return; }
    }
    ctx->pc = 0x173B1Cu;
label_173b1c:
    // 0x173b1c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x173b1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173b20: 0x3e00008  jr          $ra
    ctx->pc = 0x173B20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173B20u;
            // 0x173b24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173B1Cu: goto label_173b1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173B28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
