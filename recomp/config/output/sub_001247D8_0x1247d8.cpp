#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001247D8
// Address: 0x1247d8 - 0x12480c
void sub_001247D8_0x1247d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001247D8_0x1247d8");
#endif

    switch (ctx->pc) {
        case 0x1247e8u: goto label_1247e8;
        case 0x1247f0u: goto label_1247f0;
        default: break;
    }

    ctx->pc = 0x1247d8u;

    // 0x1247d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1247d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1247dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1247dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1247e0: 0xc04d36e  jal         func_134DB8
    ctx->pc = 0x1247E0u;
    SET_GPR_U32(ctx, 31, 0x1247E8u);
    ctx->pc = 0x134DB8u;
    if (runtime->hasFunction(0x134DB8u)) {
        auto targetFn = runtime->lookupFunction(0x134DB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247E8u; }
        if (ctx->pc != 0x1247E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134DB8_0x134db8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247E8u; }
        if (ctx->pc != 0x1247E8u) { return; }
    }
    ctx->pc = 0x1247E8u;
label_1247e8:
    // 0x1247e8: 0xc04914e  jal         func_124538
    ctx->pc = 0x1247E8u;
    SET_GPR_U32(ctx, 31, 0x1247F0u);
    ctx->pc = 0x124538u;
    if (runtime->hasFunction(0x124538u)) {
        auto targetFn = runtime->lookupFunction(0x124538u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247F0u; }
        if (ctx->pc != 0x1247F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124538_0x124538(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1247F0u; }
        if (ctx->pc != 0x1247F0u) { return; }
    }
    ctx->pc = 0x1247F0u;
label_1247f0:
    // 0x1247f0: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1247f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1247f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1247f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1247f8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1247f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1247fc: 0x2484b958  addiu       $a0, $a0, -0x46A8
    ctx->pc = 0x1247fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949208));
    // 0x124800: 0x24060e40  addiu       $a2, $zero, 0xE40
    ctx->pc = 0x124800u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3648));
    // 0x124804: 0x8041f1a  j           func_107C68
    ctx->pc = 0x124804u;
    ctx->pc = 0x124808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124804u;
            // 0x124808: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12480Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
