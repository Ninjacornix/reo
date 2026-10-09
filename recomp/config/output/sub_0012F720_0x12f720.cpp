#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012F720
// Address: 0x12f720 - 0x12f750
void sub_0012F720_0x12f720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012F720_0x12f720");
#endif

    switch (ctx->pc) {
        case 0x12f730u: goto label_12f730;
        default: break;
    }

    ctx->pc = 0x12f720u;

    // 0x12f720: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12f720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12f724: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12f724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12f728: 0xc04b6b0  jal         func_12DAC0
    ctx->pc = 0x12F728u;
    SET_GPR_U32(ctx, 31, 0x12F730u);
    ctx->pc = 0x12DAC0u;
    if (runtime->hasFunction(0x12DAC0u)) {
        auto targetFn = runtime->lookupFunction(0x12DAC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F730u; }
        if (ctx->pc != 0x12F730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012DAC0_0x12dac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12F730u; }
        if (ctx->pc != 0x12F730u) { return; }
    }
    ctx->pc = 0x12F730u;
label_12f730:
    // 0x12f730: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12f730u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12f734: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x12f734u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x12f738: 0x24848760  addiu       $a0, $a0, -0x78A0
    ctx->pc = 0x12f738u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936416));
    // 0x12f73c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12f73cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12f740: 0x24061780  addiu       $a2, $zero, 0x1780
    ctx->pc = 0x12f740u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6016));
    // 0x12f744: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12F744u;
    ctx->pc = 0x12F748u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12F744u;
            // 0x12f748: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12F74Cu;
    // 0x12f74c: 0x0  nop
    ctx->pc = 0x12f74cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
