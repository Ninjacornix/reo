#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B4E8
// Address: 0x17b4e8 - 0x17b530
void sub_0017B4E8_0x17b4e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B4E8_0x17b4e8");
#endif

    switch (ctx->pc) {
        case 0x17b524u: goto label_17b524;
        default: break;
    }

    ctx->pc = 0x17b4e8u;

    // 0x17b4e8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17b4e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17b4ec: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x17b4ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b4f0: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17b4f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x17b4f4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b4f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b4f8: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x17b4f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x17b4fc: 0x8c480048  lw          $t0, 0x48($v0)
    ctx->pc = 0x17b4fcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x17b500: 0x8c470044  lw          $a3, 0x44($v0)
    ctx->pc = 0x17b500u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
    // 0x17b504: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x17b504u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17b508: 0xafa70024  sw          $a3, 0x24($sp)
    ctx->pc = 0x17b508u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 7));
    // 0x17b50c: 0xafa60020  sw          $a2, 0x20($sp)
    ctx->pc = 0x17b50cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 6));
    // 0x17b510: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x17b510u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x17b514: 0xafa80028  sw          $t0, 0x28($sp)
    ctx->pc = 0x17b514u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 8));
    // 0x17b518: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x17b518u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x17b51c: 0xc053fd4  jal         func_14FF50
    ctx->pc = 0x17B51Cu;
    SET_GPR_U32(ctx, 31, 0x17B524u);
    ctx->pc = 0x17B520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B51Cu;
            // 0x17b520: 0xafa80008  sw          $t0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14FF50u;
    if (runtime->hasFunction(0x14FF50u)) {
        auto targetFn = runtime->lookupFunction(0x14FF50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B524u; }
        if (ctx->pc != 0x17B524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014FF50_0x14ff50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B524u; }
        if (ctx->pc != 0x17B524u) { return; }
    }
    ctx->pc = 0x17B524u;
label_17b524:
    // 0x17b524: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x17b524u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17b528: 0x3e00008  jr          $ra
    ctx->pc = 0x17B528u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B528u;
            // 0x17b52c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B524u: goto label_17b524;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B530u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
