#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E9E8
// Address: 0x17e9e8 - 0x17ea1c
void sub_0017E9E8_0x17e9e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E9E8_0x17e9e8");
#endif

    switch (ctx->pc) {
        case 0x17ea10u: goto label_17ea10;
        default: break;
    }

    ctx->pc = 0x17e9e8u;

    // 0x17e9e8: 0x41178  dsll        $v0, $a0, 5
    ctx->pc = 0x17e9e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << 5);
    // 0x17e9ec: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17e9ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17e9f0: 0x44102f  dsubu       $v0, $v0, $a0
    ctx->pc = 0x17e9f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 4));
    // 0x17e9f4: 0xdc65f980  ld          $a1, -0x680($v1)
    ctx->pc = 0x17e9f4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 4294965632)));
    // 0x17e9f8: 0x210b8  dsll        $v0, $v0, 2
    ctx->pc = 0x17e9f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 2);
    // 0x17e9fc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17e9fcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17ea00: 0x44102d  daddu       $v0, $v0, $a0
    ctx->pc = 0x17ea00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 4));
    // 0x17ea04: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17ea04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17ea08: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x17EA08u;
    SET_GPR_U32(ctx, 31, 0x17EA10u);
    ctx->pc = 0x17EA0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17EA08u;
            // 0x17ea0c: 0x220f8  dsll        $a0, $v0, 3 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << 3);
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EA10u; }
        if (ctx->pc != 0x17EA10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17EA10u; }
        if (ctx->pc != 0x17EA10u) { return; }
    }
    ctx->pc = 0x17EA10u;
label_17ea10:
    // 0x17ea10: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17ea10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ea14: 0x3e00008  jr          $ra
    ctx->pc = 0x17EA14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EA18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EA14u;
            // 0x17ea18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17EA10u: goto label_17ea10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17EA1Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
