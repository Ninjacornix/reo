#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130DC8
// Address: 0x130dc8 - 0x130df4
void sub_00130DC8_0x130dc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130DC8_0x130dc8");
#endif

    switch (ctx->pc) {
        case 0x130ddcu: goto label_130ddc;
        default: break;
    }

    ctx->pc = 0x130dc8u;

    // 0x130dc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130dc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130dcc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130dd0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130dd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130dd4: 0xc04c182  jal         func_130608
    ctx->pc = 0x130DD4u;
    SET_GPR_U32(ctx, 31, 0x130DDCu);
    ctx->pc = 0x130DD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130DD4u;
            // 0x130dd8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130608u;
    if (runtime->hasFunction(0x130608u)) {
        auto targetFn = runtime->lookupFunction(0x130608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130DDCu; }
        if (ctx->pc != 0x130DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130608_0x130608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130DDCu; }
        if (ctx->pc != 0x130DDCu) { return; }
    }
    ctx->pc = 0x130DDCu;
label_130ddc:
    // 0x130ddc: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x130ddcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x130de0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130de0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130de4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130de4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130de8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130de8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130dec: 0x3e00008  jr          $ra
    ctx->pc = 0x130DECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130DECu;
            // 0x130df0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130DDCu: goto label_130ddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130DF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
