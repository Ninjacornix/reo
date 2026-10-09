#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164270
// Address: 0x164270 - 0x164298
void sub_00164270_0x164270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164270_0x164270");
#endif

    switch (ctx->pc) {
        case 0x164284u: goto label_164284;
        default: break;
    }

    ctx->pc = 0x164270u;

    // 0x164270: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164274: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x164274u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x164278: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x164278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16427c: 0xc05799e  jal         func_15E678
    ctx->pc = 0x16427Cu;
    SET_GPR_U32(ctx, 31, 0x164284u);
    ctx->pc = 0x164280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16427Cu;
            // 0x164280: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164284u; }
        if (ctx->pc != 0x164284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164284u; }
        if (ctx->pc != 0x164284u) { return; }
    }
    ctx->pc = 0x164284u;
label_164284:
    // 0x164284: 0xac500054  sw          $s0, 0x54($v0)
    ctx->pc = 0x164284u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 84), GPR_U32(ctx, 16));
    // 0x164288: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x164288u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16428c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16428cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164290: 0x3e00008  jr          $ra
    ctx->pc = 0x164290u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164290u;
            // 0x164294: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164284u: goto label_164284;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164298u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
