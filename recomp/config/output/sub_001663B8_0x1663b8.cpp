#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001663B8
// Address: 0x1663b8 - 0x1663f8
void sub_001663B8_0x1663b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001663B8_0x1663b8");
#endif

    switch (ctx->pc) {
        case 0x1663d0u: goto label_1663d0;
        default: break;
    }

    ctx->pc = 0x1663b8u;

    // 0x1663b8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1663b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1663bc: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1663bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1663c0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1663c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1663c4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1663c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1663c8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1663C8u;
    SET_GPR_U32(ctx, 31, 0x1663D0u);
    ctx->pc = 0x1663CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1663C8u;
            // 0x1663cc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1663D0u; }
        if (ctx->pc != 0x1663D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1663D0u; }
        if (ctx->pc != 0x1663D0u) { return; }
    }
    ctx->pc = 0x1663D0u;
label_1663d0:
    // 0x1663d0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1663D0u;
    {
        const bool branch_taken_0x1663d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1663D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1663D0u;
            // 0x1663d4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1663d0) {
            ctx->pc = 0x1663E8u;
            goto label_1663e8;
        }
    }
    ctx->pc = 0x1663D8u;
    // 0x1663d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1663d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1663dc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1663dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1663e0: 0x80598fe  j           func_1663F8
    ctx->pc = 0x1663E0u;
    ctx->pc = 0x1663E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1663E0u;
            // 0x1663e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1663F8u;
    if (runtime->hasFunction(0x1663F8u)) {
        auto targetFn = runtime->lookupFunction(0x1663F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001663F8_0x1663f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1663E8u;
label_1663e8:
    // 0x1663e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1663e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1663ec: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1663ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1663f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1663F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1663F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1663F0u;
            // 0x1663f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1663D0u: goto label_1663d0;
            case 0x1663E8u: goto label_1663e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1663F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
