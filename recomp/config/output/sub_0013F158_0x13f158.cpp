#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F158
// Address: 0x13f158 - 0x13f17c
void sub_0013F158_0x13f158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F158_0x13f158");
#endif

    switch (ctx->pc) {
        case 0x13f16cu: goto label_13f16c;
        default: break;
    }

    ctx->pc = 0x13f158u;

    // 0x13f158: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f158u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f15c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f15cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f160: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f164: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F164u;
    SET_GPR_U32(ctx, 31, 0x13F16Cu);
    ctx->pc = 0x13F168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F164u;
            // 0x13f168: 0x2484d988  addiu       $a0, $a0, -0x2678 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F16Cu; }
        if (ctx->pc != 0x13F16Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F16Cu; }
        if (ctx->pc != 0x13F16Cu) { return; }
    }
    ctx->pc = 0x13F16Cu;
label_13f16c:
    // 0x13f16c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13f16cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f170: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f170u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f174: 0x3e00008  jr          $ra
    ctx->pc = 0x13F174u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F174u;
            // 0x13f178: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F17Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
