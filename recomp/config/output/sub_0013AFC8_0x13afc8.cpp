#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013AFC8
// Address: 0x13afc8 - 0x13aff8
void sub_0013AFC8_0x13afc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013AFC8_0x13afc8");
#endif

    switch (ctx->pc) {
        case 0x13afecu: goto label_13afec;
        default: break;
    }

    ctx->pc = 0x13afc8u;

    // 0x13afc8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13afc8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13afcc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13afccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13afd0: 0x8c43da7c  lw          $v1, -0x2584($v0)
    ctx->pc = 0x13afd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957692)));
    // 0x13afd4: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x13afd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13afd8: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x13AFD8u;
    {
        const bool branch_taken_0x13afd8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13AFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AFD8u;
            // 0x13afdc: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13afd8) {
            ctx->pc = 0x13AFECu;
            goto label_13afec;
        }
    }
    ctx->pc = 0x13AFE0u;
    // 0x13afe0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13afe0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13afe4: 0x60f809  jalr        $v1
    ctx->pc = 0x13AFE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x13AFECu);
        ctx->pc = 0x13AFE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AFE4u;
            // 0x13afe8: 0x8c44da80  lw          $a0, -0x2580($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957696)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13AFECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AFECu: goto label_13afec;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13AFECu; }
            if (ctx->pc != 0x13AFECu) { return; }
        }
        }
    }
    ctx->pc = 0x13AFECu;
label_13afec:
    // 0x13afec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13afecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13aff0: 0x3e00008  jr          $ra
    ctx->pc = 0x13AFF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13AFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13AFF0u;
            // 0x13aff4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13AFECu: goto label_13afec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13AFF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
