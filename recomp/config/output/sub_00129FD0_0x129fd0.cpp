#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129FD0
// Address: 0x129fd0 - 0x12a004
void sub_00129FD0_0x129fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129FD0_0x129fd0");
#endif

    ctx->pc = 0x129fd0u;

    // 0x129fd0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129fd4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x129fd4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129fd8: 0x10800007  beqz        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x129FD8u;
    {
        const bool branch_taken_0x129fd8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x129FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129FD8u;
            // 0x129fdc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129fd8) {
            ctx->pc = 0x129FF8u;
            goto label_129ff8;
        }
    }
    ctx->pc = 0x129FE0u;
    // 0x129fe0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x129fe0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x129fe4: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x129FE4u;
    {
        const bool branch_taken_0x129fe4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x129FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129FE4u;
            // 0x129fe8: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129fe4) {
            ctx->pc = 0x129FF8u;
            goto label_129ff8;
        }
    }
    ctx->pc = 0x129FECu;
    // 0x129fec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129fecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129ff0: 0x804c3f8  j           func_130FE0
    ctx->pc = 0x129FF0u;
    ctx->pc = 0x129FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129FF0u;
            // 0x129ff4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130FE0u;
    if (runtime->hasFunction(0x130FE0u)) {
        auto targetFn = runtime->lookupFunction(0x130FE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130FE0_0x130fe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x129FF8u;
label_129ff8:
    // 0x129ff8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x129ff8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129ffc: 0x3e00008  jr          $ra
    ctx->pc = 0x129FFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129FFCu;
            // 0x12a000: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129FF8u: goto label_129ff8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A004u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
