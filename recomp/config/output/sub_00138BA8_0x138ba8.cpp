#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138BA8
// Address: 0x138ba8 - 0x138bd0
void sub_00138BA8_0x138ba8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138BA8_0x138ba8");
#endif

    switch (ctx->pc) {
        case 0x138bbcu: goto label_138bbc;
        default: break;
    }

    ctx->pc = 0x138ba8u;

    // 0x138ba8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x138ba8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138bac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138bacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138bb0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x138bb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x138bb4: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x138BB4u;
    SET_GPR_U32(ctx, 31, 0x138BBCu);
    ctx->pc = 0x138BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138BB4u;
            // 0x138bb8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138BBCu; }
        if (ctx->pc != 0x138BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138BBCu; }
        if (ctx->pc != 0x138BBCu) { return; }
    }
    ctx->pc = 0x138BBCu;
label_138bbc:
    // 0x138bbc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x138bbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138bc0: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x138bc0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x138bc4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138bc4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138bc8: 0x804fc9c  j           func_13F270
    ctx->pc = 0x138BC8u;
    ctx->pc = 0x138BCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138BC8u;
            // 0x138bcc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x138BD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
