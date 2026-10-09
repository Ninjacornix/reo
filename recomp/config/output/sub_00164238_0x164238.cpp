#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164238
// Address: 0x164238 - 0x164258
void sub_00164238_0x164238(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164238_0x164238");
#endif

    switch (ctx->pc) {
        case 0x164248u: goto label_164248;
        default: break;
    }

    ctx->pc = 0x164238u;

    // 0x164238: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164238u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16423c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16423cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164240: 0xc058fb8  jal         func_163EE0
    ctx->pc = 0x164240u;
    SET_GPR_U32(ctx, 31, 0x164248u);
    ctx->pc = 0x163EE0u;
    if (runtime->hasFunction(0x163EE0u)) {
        auto targetFn = runtime->lookupFunction(0x163EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164248u; }
        if (ctx->pc != 0x164248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163EE0_0x163ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164248u; }
        if (ctx->pc != 0x164248u) { return; }
    }
    ctx->pc = 0x164248u;
label_164248:
    // 0x164248: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164248u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16424c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16424cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164250: 0x3e00008  jr          $ra
    ctx->pc = 0x164250u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164250u;
            // 0x164254: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164248u: goto label_164248;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164258u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
