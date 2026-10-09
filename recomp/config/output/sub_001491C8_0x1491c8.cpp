#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001491C8
// Address: 0x1491c8 - 0x149200
void sub_001491C8_0x1491c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001491C8_0x1491c8");
#endif

    switch (ctx->pc) {
        case 0x1491e8u: goto label_1491e8;
        default: break;
    }

    ctx->pc = 0x1491c8u;

    // 0x1491c8: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x1491c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x1491cc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1491ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1491d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1491d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1491d4: 0x24634c00  addiu       $v1, $v1, 0x4C00
    ctx->pc = 0x1491d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19456));
    // 0x1491d8: 0x2442e260  addiu       $v0, $v0, -0x1DA0
    ctx->pc = 0x1491d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294959712));
    // 0x1491dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1491dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1491e0: 0xc052482  jal         func_149208
    ctx->pc = 0x1491E0u;
    SET_GPR_U32(ctx, 31, 0x1491E8u);
    ctx->pc = 0x1491E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1491E0u;
            // 0x1491e4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149208u;
    if (runtime->hasFunction(0x149208u)) {
        auto targetFn = runtime->lookupFunction(0x149208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1491E8u; }
        if (ctx->pc != 0x1491E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149208_0x149208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1491E8u; }
        if (ctx->pc != 0x1491E8u) { return; }
    }
    ctx->pc = 0x1491E8u;
label_1491e8:
    // 0x1491e8: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x1491e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1491ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1491ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1491f0: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1491f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1491f4: 0x8052486  j           func_149218
    ctx->pc = 0x1491F4u;
    ctx->pc = 0x1491F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1491F4u;
            // 0x1491f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149218u;
    if (runtime->hasFunction(0x149218u)) {
        auto targetFn = runtime->lookupFunction(0x149218u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00149218_0x149218(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1491FCu;
    // 0x1491fc: 0x0  nop
    ctx->pc = 0x1491fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
