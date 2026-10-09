#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160660
// Address: 0x160660 - 0x16069c
void sub_00160660_0x160660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160660_0x160660");
#endif

    ctx->pc = 0x160660u;

    // 0x160660: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160664: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x160664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160668: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x160668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16066c: 0x14a20006  bne         $a1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16066Cu;
    {
        const bool branch_taken_0x16066c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x160670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16066Cu;
            // 0x160670: 0x8c840040  lw          $a0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16066c) {
            ctx->pc = 0x160688u;
            goto label_160688;
        }
    }
    ctx->pc = 0x160674u;
    // 0x160674: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160674u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160678: 0x24050027  addiu       $a1, $zero, 0x27
    ctx->pc = 0x160678u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x16067c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16067cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160680: 0x805d4ce  j           func_175338
    ctx->pc = 0x160680u;
    ctx->pc = 0x160684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160680u;
            // 0x160684: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160688u;
label_160688:
    // 0x160688: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x160688u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16068c: 0x24050027  addiu       $a1, $zero, 0x27
    ctx->pc = 0x16068cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
    // 0x160690: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x160690u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160694: 0x805d4ce  j           func_175338
    ctx->pc = 0x160694u;
    ctx->pc = 0x160698u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160694u;
            // 0x160698: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16069Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
