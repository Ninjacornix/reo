#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164510
// Address: 0x164510 - 0x164540
void sub_00164510_0x164510(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164510_0x164510");
#endif

    switch (ctx->pc) {
        case 0x164520u: goto label_164520;
        default: break;
    }

    ctx->pc = 0x164510u;

    // 0x164510: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164514: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164518: 0xc04c16e  jal         func_1305B8
    ctx->pc = 0x164518u;
    SET_GPR_U32(ctx, 31, 0x164520u);
    ctx->pc = 0x1305B8u;
    if (runtime->hasFunction(0x1305B8u)) {
        auto targetFn = runtime->lookupFunction(0x1305B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164520u; }
        if (ctx->pc != 0x164520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305B8_0x1305b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164520u; }
        if (ctx->pc != 0x164520u) { return; }
    }
    ctx->pc = 0x164520u;
label_164520:
    // 0x164520: 0x38420004  xori        $v0, $v0, 0x4
    ctx->pc = 0x164520u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)4);
    // 0x164524: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164524u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164528: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x164528u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x16452c: 0x3e00008  jr          $ra
    ctx->pc = 0x16452Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16452Cu;
            // 0x164530: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164520u: goto label_164520;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164534u;
    // 0x164534: 0x0  nop
    ctx->pc = 0x164534u;
    // NOP
    // 0x164538: 0x3e00008  jr          $ra
    ctx->pc = 0x164538u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164520u: goto label_164520;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164540u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
