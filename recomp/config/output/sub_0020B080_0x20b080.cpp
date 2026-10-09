#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020B080
// Address: 0x20b080 - 0x20b0a0
void sub_0020B080_0x20b080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020B080_0x20b080");
#endif

    switch (ctx->pc) {
        case 0x20b090u: goto label_20b090;
        default: break;
    }

    ctx->pc = 0x20b080u;

    // 0x20b080: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x20b080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x20b084: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x20b084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x20b088: 0xc01d858  jal         func_076160
    ctx->pc = 0x20B088u;
    SET_GPR_U32(ctx, 31, 0x20B090u);
    ctx->pc = 0x20B08Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20B088u;
            // 0x20b08c: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x76160u;
    {
        auto targetFn = runtime->lookupFunction(0x76160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20B090u; }
        if (ctx->pc != 0x20B090u) { return; }
    }
    ctx->pc = 0x20B090u;
label_20b090:
    // 0x20b090: 0xf  sync
    ctx->pc = 0x20b090u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20b094: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x20b094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x20b098: 0x3e00008  jr          $ra
    ctx->pc = 0x20B098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20B09Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B098u;
            // 0x20b09c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20B090u: goto label_20b090;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20B0A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
