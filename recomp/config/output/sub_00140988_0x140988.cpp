#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140988
// Address: 0x140988 - 0x1409e4
void sub_00140988_0x140988(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140988_0x140988");
#endif

    switch (ctx->pc) {
        case 0x1409b0u: goto label_1409b0;
        case 0x1409c0u: goto label_1409c0;
        default: break;
    }

    ctx->pc = 0x140988u;

    // 0x140988: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140988u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x14098c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x14098cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140990: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x140990u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140994: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x140994u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140998: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x140998u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14099c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x14099cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1409a0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1409a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1409a4: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1409a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1409a8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1409A8u;
    SET_GPR_U32(ctx, 31, 0x1409B0u);
    ctx->pc = 0x1409ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1409A8u;
            // 0x1409ac: 0x8e060004  lw          $a2, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1409B0u; }
        if (ctx->pc != 0x1409B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1409B0u; }
        if (ctx->pc != 0x1409B0u) { return; }
    }
    ctx->pc = 0x1409B0u;
label_1409b0:
    // 0x1409b0: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1409b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1409b4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1409b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1409b8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1409B8u;
    SET_GPR_U32(ctx, 31, 0x1409C0u);
    ctx->pc = 0x1409BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1409B8u;
            // 0x1409bc: 0x24060007  addiu       $a2, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1409C0u; }
        if (ctx->pc != 0x1409C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1409C0u; }
        if (ctx->pc != 0x1409C0u) { return; }
    }
    ctx->pc = 0x1409C0u;
label_1409c0:
    // 0x1409c0: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x1409c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1409c4: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1409c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1409c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1409c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1409cc: 0x2484fff0  addiu       $a0, $a0, -0x10
    ctx->pc = 0x1409ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967280));
    // 0x1409d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1409d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1409d4: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1409d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x1409d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1409d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1409dc: 0x8050210  j           func_140840
    ctx->pc = 0x1409DCu;
    ctx->pc = 0x1409E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1409DCu;
            // 0x1409e0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140840u;
    if (runtime->hasFunction(0x140840u)) {
        auto targetFn = runtime->lookupFunction(0x140840u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00140840_0x140840(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1409E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
