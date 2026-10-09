#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3C20
// Address: 0x1a3c20 - 0x1a3c60
void sub_001A3C20_0x1a3c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3C20_0x1a3c20");
#endif

    switch (ctx->pc) {
        case 0x1a3c38u: goto label_1a3c38;
        default: break;
    }

    ctx->pc = 0x1a3c20u;

    // 0x1a3c20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3c24: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1a3c24u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3c28: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a3c2c: 0x3c05000a  lui         $a1, 0xA
    ctx->pc = 0x1a3c2cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)10 << 16));
    // 0x1a3c30: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3C30u;
    SET_GPR_U32(ctx, 31, 0x1A3C38u);
    ctx->pc = 0x1A3C34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3C30u;
            // 0x1a3c34: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3C38u; }
        if (ctx->pc != 0x1A3C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3C38u; }
        if (ctx->pc != 0x1A3C38u) { return; }
    }
    ctx->pc = 0x1A3C38u;
label_1a3c38:
    // 0x1a3c38: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3C38u;
    {
        const bool branch_taken_0x1a3c38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3C38u;
            // 0x1a3c3c: 0x818c0  sll         $v1, $t0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3c38) {
            ctx->pc = 0x1A3C48u;
            goto label_1a3c48;
        }
    }
    ctx->pc = 0x1A3C40u;
    // 0x1a3c40: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3C40u;
    {
        const bool branch_taken_0x1a3c40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3C40u;
            // 0x1a3c44: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3c40) {
            ctx->pc = 0x1A3C50u;
            goto label_1a3c50;
        }
    }
    ctx->pc = 0x1A3C48u;
label_1a3c48:
    // 0x1a3c48: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1a3c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1a3c4c: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1a3c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
label_1a3c50:
    // 0x1a3c50: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3c50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3c54: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3C54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3C54u;
            // 0x1a3c58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3C38u: goto label_1a3c38;
            case 0x1A3C48u: goto label_1a3c48;
            case 0x1A3C50u: goto label_1a3c50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3C5Cu;
    // 0x1a3c5c: 0x0  nop
    ctx->pc = 0x1a3c5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
