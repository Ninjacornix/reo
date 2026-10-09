#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A018
// Address: 0x10a018 - 0x10a04c
void sub_0010A018_0x10a018(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A018_0x10a018");
#endif

    ctx->pc = 0x10a018u;

    // 0x10a018: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a018u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a01c: 0x24030009  addiu       $v1, $zero, 0x9
    ctx->pc = 0x10a01cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x10a020: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10a020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10a024: 0x9482000c  lhu         $v0, 0xC($a0)
    ctx->pc = 0x10a024u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x10a028: 0x30420009  andi        $v0, $v0, 0x9
    ctx->pc = 0x10a028u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)9);
    // 0x10a02c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x10A02Cu;
    {
        const bool branch_taken_0x10a02c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x10A030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A02Cu;
            // 0x10a030: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a02c) {
            ctx->pc = 0x10A040u;
            goto label_10a040;
        }
    }
    ctx->pc = 0x10A034u;
    // 0x10a034: 0x804142c  j           func_1050B0
    ctx->pc = 0x10A034u;
    ctx->pc = 0x10A038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A034u;
            // 0x10a038: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001050B0_0x1050b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10A03Cu;
    // 0x10a03c: 0x0  nop
    ctx->pc = 0x10a03cu;
    // NOP
label_10a040:
    // 0x10a040: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a040u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a044: 0x3e00008  jr          $ra
    ctx->pc = 0x10A044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A044u;
            // 0x10a048: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A040u: goto label_10a040;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A04Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
