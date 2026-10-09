#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115900
// Address: 0x115900 - 0x115930
void sub_00115900_0x115900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115900_0x115900");
#endif

    switch (ctx->pc) {
        case 0x115924u: goto label_115924;
        default: break;
    }

    ctx->pc = 0x115900u;

    // 0x115900: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x115900u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x115904: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115904u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x115908: 0x52e03  sra         $a1, $a1, 24
    ctx->pc = 0x115908u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
    // 0x11590c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x11590cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115910: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x115910u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x115914: 0x2404fff9  addiu       $a0, $zero, -0x7
    ctx->pc = 0x115914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967289));
    // 0x115918: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x115918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11591c: 0xc045294  jal         func_114A50
    ctx->pc = 0x11591Cu;
    SET_GPR_U32(ctx, 31, 0x115924u);
    ctx->pc = 0x115920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11591Cu;
            // 0x115920: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115924u; }
        if (ctx->pc != 0x115924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115924u; }
        if (ctx->pc != 0x115924u) { return; }
    }
    ctx->pc = 0x115924u;
label_115924:
    // 0x115924: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115928: 0x3e00008  jr          $ra
    ctx->pc = 0x115928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11592Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115928u;
            // 0x11592c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115924u: goto label_115924;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
