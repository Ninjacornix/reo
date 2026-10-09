#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D1B0
// Address: 0x16d1b0 - 0x16d200
void sub_0016D1B0_0x16d1b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D1B0_0x16d1b0");
#endif

    switch (ctx->pc) {
        case 0x16d1ccu: goto label_16d1cc;
        default: break;
    }

    ctx->pc = 0x16d1b0u;

    // 0x16d1b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16d1b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16d1b4: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16d1b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16d1b8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x16d1b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d1bc: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16d1bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16d1c0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x16d1c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d1c4: 0xc059bfa  jal         func_166FE8
    ctx->pc = 0x16D1C4u;
    SET_GPR_U32(ctx, 31, 0x16D1CCu);
    ctx->pc = 0x16D1C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D1C4u;
            // 0x16d1c8: 0x8c851b38  lw          $a1, 0x1B38($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6968)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166FE8u;
    if (runtime->hasFunction(0x166FE8u)) {
        auto targetFn = runtime->lookupFunction(0x166FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D1CCu; }
        if (ctx->pc != 0x16D1CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166FE8_0x166fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D1CCu; }
        if (ctx->pc != 0x16D1CCu) { return; }
    }
    ctx->pc = 0x16D1CCu;
label_16d1cc:
    // 0x16d1cc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16D1CCu;
    {
        const bool branch_taken_0x16d1cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D1CCu;
            // 0x16d1d0: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d1cc) {
            ctx->pc = 0x16D1E0u;
            goto label_16d1e0;
        }
    }
    ctx->pc = 0x16D1D4u;
    // 0x16d1d4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x16d1d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x16d1d8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x16D1D8u;
    {
        const bool branch_taken_0x16d1d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D1DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D1D8u;
            // 0x16d1dc: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d1d8) {
            ctx->pc = 0x16D1ECu;
            goto label_16d1ec;
        }
    }
    ctx->pc = 0x16D1E0u;
label_16d1e0:
    // 0x16d1e0: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x16d1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16d1e4: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x16d1e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x16d1e8: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x16d1e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
label_16d1ec:
    // 0x16d1ec: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16d1ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16d1f0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16d1f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16d1f4: 0x3e00008  jr          $ra
    ctx->pc = 0x16D1F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D1F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D1F4u;
            // 0x16d1f8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D1CCu: goto label_16d1cc;
            case 0x16D1E0u: goto label_16d1e0;
            case 0x16D1ECu: goto label_16d1ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D1FCu;
    // 0x16d1fc: 0x0  nop
    ctx->pc = 0x16d1fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
