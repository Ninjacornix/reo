#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164420
// Address: 0x164420 - 0x164448
void sub_00164420_0x164420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164420_0x164420");
#endif

    switch (ctx->pc) {
        case 0x164438u: goto label_164438;
        default: break;
    }

    ctx->pc = 0x164420u;

    // 0x164420: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164424: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x164424u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164428: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x164428u;
    {
        const bool branch_taken_0x164428 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x16442Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164428u;
            // 0x16442c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164428) {
            ctx->pc = 0x16443Cu;
            goto label_16443c;
        }
    }
    ctx->pc = 0x164430u;
    // 0x164430: 0xc04c38a  jal         func_130E28
    ctx->pc = 0x164430u;
    SET_GPR_U32(ctx, 31, 0x164438u);
    ctx->pc = 0x130E28u;
    if (runtime->hasFunction(0x130E28u)) {
        auto targetFn = runtime->lookupFunction(0x130E28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164438u; }
        if (ctx->pc != 0x164438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E28_0x130e28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164438u; }
        if (ctx->pc != 0x164438u) { return; }
    }
    ctx->pc = 0x164438u;
label_164438:
    // 0x164438: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x164438u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16443c:
    // 0x16443c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16443cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164440: 0x3e00008  jr          $ra
    ctx->pc = 0x164440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164440u;
            // 0x164444: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164438u: goto label_164438;
            case 0x16443Cu: goto label_16443c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164448u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
