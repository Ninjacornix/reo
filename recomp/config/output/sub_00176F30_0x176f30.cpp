#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176F30
// Address: 0x176f30 - 0x176f68
void sub_00176F30_0x176f30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176F30_0x176f30");
#endif

    ctx->pc = 0x176f30u;

    // 0x176f30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x176f30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x176f34: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x176f34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176f38: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x176F38u;
    {
        const bool branch_taken_0x176f38 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x176F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176F38u;
            // 0x176f3c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176f38) {
            ctx->pc = 0x176F58u;
            goto label_176f58;
        }
    }
    ctx->pc = 0x176F40u;
    // 0x176f40: 0x8ca60018  lw          $a2, 0x18($a1)
    ctx->pc = 0x176f40u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x176f44: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x176f44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176f48: 0x8ca50014  lw          $a1, 0x14($a1)
    ctx->pc = 0x176f48u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x176f4c: 0x805dbda  j           func_176F68
    ctx->pc = 0x176F4Cu;
    ctx->pc = 0x176F50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176F4Cu;
            // 0x176f50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176F68u;
    if (runtime->hasFunction(0x176F68u)) {
        auto targetFn = runtime->lookupFunction(0x176F68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00176F68_0x176f68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x176F54u;
    // 0x176f54: 0x0  nop
    ctx->pc = 0x176f54u;
    // NOP
label_176f58:
    // 0x176f58: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x176f58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176f5c: 0x3e00008  jr          $ra
    ctx->pc = 0x176F5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176F5Cu;
            // 0x176f60: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176F58u: goto label_176f58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176F64u;
    // 0x176f64: 0x0  nop
    ctx->pc = 0x176f64u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
