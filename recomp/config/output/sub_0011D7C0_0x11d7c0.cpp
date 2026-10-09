#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D7C0
// Address: 0x11d7c0 - 0x11d7f4
void sub_0011D7C0_0x11d7c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D7C0_0x11d7c0");
#endif

    switch (ctx->pc) {
        case 0x11d7e4u: goto label_11d7e4;
        default: break;
    }

    ctx->pc = 0x11d7c0u;

    // 0x11d7c0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11d7c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11d7c4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11d7c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11d7c8: 0x8c45a458  lw          $a1, -0x5BA8($v0)
    ctx->pc = 0x11d7c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943832)));
    // 0x11d7cc: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x11d7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x11d7d0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11d7d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11d7d4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x11d7d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d7d8: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x11d7d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11d7dc: 0xc0475ca  jal         func_11D728
    ctx->pc = 0x11D7DCu;
    SET_GPR_U32(ctx, 31, 0x11D7E4u);
    ctx->pc = 0x11D7E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D7DCu;
            // 0x11d7e0: 0xa32821  addu        $a1, $a1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D728u;
    if (runtime->hasFunction(0x11D728u)) {
        auto targetFn = runtime->lookupFunction(0x11D728u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D7E4u; }
        if (ctx->pc != 0x11D7E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D728_0x11d728(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D7E4u; }
        if (ctx->pc != 0x11D7E4u) { return; }
    }
    ctx->pc = 0x11D7E4u;
label_11d7e4:
    // 0x11d7e4: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x11d7e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11d7e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11d7e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11d7ec: 0x3e00008  jr          $ra
    ctx->pc = 0x11D7ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D7F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D7ECu;
            // 0x11d7f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D7E4u: goto label_11d7e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D7F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
