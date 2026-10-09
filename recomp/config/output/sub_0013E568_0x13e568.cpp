#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013E568
// Address: 0x13e568 - 0x13e598
void sub_0013E568_0x13e568(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013E568_0x13e568");
#endif

    switch (ctx->pc) {
        case 0x13e58cu: goto label_13e58c;
        default: break;
    }

    ctx->pc = 0x13e568u;

    // 0x13e568: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13e568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13e56c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x13e56cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e570: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x13e570u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x13e574: 0x2404000b  addiu       $a0, $zero, 0xB
    ctx->pc = 0x13e574u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x13e578: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13e578u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e57c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e57cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e580: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13e580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13e584: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E584u;
    SET_GPR_U32(ctx, 31, 0x13E58Cu);
    ctx->pc = 0x13E588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E584u;
            // 0x13e588: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E58Cu; }
        if (ctx->pc != 0x13E58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E58Cu; }
        if (ctx->pc != 0x13E58Cu) { return; }
    }
    ctx->pc = 0x13E58Cu;
label_13e58c:
    // 0x13e58c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13e58cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e590: 0x3e00008  jr          $ra
    ctx->pc = 0x13E590u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E590u;
            // 0x13e594: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E58Cu: goto label_13e58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E598u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
