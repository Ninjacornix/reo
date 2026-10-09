#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129D18
// Address: 0x129d18 - 0x129d48
void sub_00129D18_0x129d18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129D18_0x129d18");
#endif

    switch (ctx->pc) {
        case 0x129d30u: goto label_129d30;
        default: break;
    }

    ctx->pc = 0x129d18u;

    // 0x129d18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129d18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129d1c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x129D1Cu;
    {
        const bool branch_taken_0x129d1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x129D20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D1Cu;
            // 0x129d20: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129d1c) {
            ctx->pc = 0x129D38u;
            goto label_129d38;
        }
    }
    ctx->pc = 0x129D24u;
    // 0x129d24: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129d24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129d28: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129D28u;
    SET_GPR_U32(ctx, 31, 0x129D30u);
    ctx->pc = 0x129D2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129D28u;
            // 0x129d2c: 0x2484a1e0  addiu       $a0, $a0, -0x5E20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129D30u; }
        if (ctx->pc != 0x129D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129D30u; }
        if (ctx->pc != 0x129D30u) { return; }
    }
    ctx->pc = 0x129D30u;
label_129d30:
    // 0x129d30: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x129D30u;
    {
        const bool branch_taken_0x129d30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D30u;
            // 0x129d34: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129d30) {
            ctx->pc = 0x129D3Cu;
            goto label_129d3c;
        }
    }
    ctx->pc = 0x129D38u;
label_129d38:
    // 0x129d38: 0x8c820020  lw          $v0, 0x20($a0)
    ctx->pc = 0x129d38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
label_129d3c:
    // 0x129d3c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129d3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129d40: 0x3e00008  jr          $ra
    ctx->pc = 0x129D40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D40u;
            // 0x129d44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129D30u: goto label_129d30;
            case 0x129D38u: goto label_129d38;
            case 0x129D3Cu: goto label_129d3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129D48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
