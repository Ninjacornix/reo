#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE190
// Address: 0x1ae190 - 0x1ae1dc
void sub_001AE190_0x1ae190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE190_0x1ae190");
#endif

    switch (ctx->pc) {
        case 0x1ae1ccu: goto label_1ae1cc;
        default: break;
    }

    ctx->pc = 0x1ae190u;

    // 0x1ae190: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1ae190u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ae194: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ae194u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ae198: 0x441821  addu        $v1, $v0, $a0
    ctx->pc = 0x1ae198u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ae19c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ae19cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ae1a0: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae1a4: 0x328c0  sll         $a1, $v1, 3
    ctx->pc = 0x1ae1a4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae1a8: 0x24428d70  addiu       $v0, $v0, -0x7290
    ctx->pc = 0x1ae1a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937968));
    // 0x1ae1ac: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ae1acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae1b0: 0x452021  addu        $a0, $v0, $a1
    ctx->pc = 0x1ae1b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1ae1b4: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae1b8: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1ae1b8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ae1bc: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae1c0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae1c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae1c4: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1AE1C4u;
    SET_GPR_U32(ctx, 31, 0x1AE1CCu);
    ctx->pc = 0x1AE1C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE1C4u;
            // 0x1ae1c8: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE1CCu; }
        if (ctx->pc != 0x1AE1CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE1CCu; }
        if (ctx->pc != 0x1AE1CCu) { return; }
    }
    ctx->pc = 0x1AE1CCu;
label_1ae1cc:
    // 0x1ae1cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ae1ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae1d0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ae1d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae1d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE1D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE1D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE1D4u;
            // 0x1ae1d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE1CCu: goto label_1ae1cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE1DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
