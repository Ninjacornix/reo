#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165EF0
// Address: 0x165ef0 - 0x165f40
void sub_00165EF0_0x165ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165EF0_0x165ef0");
#endif

    ctx->pc = 0x165ef0u;

    // 0x165ef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x165ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x165ef4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x165ef4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165ef8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x165ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x165efc: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x165efcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165f00: 0x24850f60  addiu       $a1, $a0, 0xF60
    ctx->pc = 0x165f00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 3936));
    // 0x165f04: 0x8c831b74  lw          $v1, 0x1B74($a0)
    ctx->pc = 0x165f04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x165f08: 0xac62002c  sw          $v0, 0x2C($v1)
    ctx->pc = 0x165f08u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 44), GPR_U32(ctx, 2));
    // 0x165f0c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x165F0Cu;
    {
        const bool branch_taken_0x165f0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x165F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165F0Cu;
            // 0x165f10: 0x8c670000  lw          $a3, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165f0c) {
            ctx->pc = 0x165F24u;
            goto label_165f24;
        }
    }
    ctx->pc = 0x165F14u;
    // 0x165f14: 0x8c830050  lw          $v1, 0x50($a0)
    ctx->pc = 0x165f14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 80)));
    // 0x165f18: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x165f18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x165f1c: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x165F1Cu;
    {
        const bool branch_taken_0x165f1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x165F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165F1Cu;
            // 0x165f20: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165f1c) {
            ctx->pc = 0x165F38u;
            goto label_165f38;
        }
    }
    ctx->pc = 0x165F24u;
label_165f24:
    // 0x165f24: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x165f24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165f28: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x165f28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165f2c: 0x80597e2  j           func_165F88
    ctx->pc = 0x165F2Cu;
    ctx->pc = 0x165F30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165F2Cu;
            // 0x165f30: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165F88u;
    if (runtime->hasFunction(0x165F88u)) {
        auto targetFn = runtime->lookupFunction(0x165F88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00165F88_0x165f88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x165F34u;
    // 0x165f34: 0x0  nop
    ctx->pc = 0x165f34u;
    // NOP
label_165f38:
    // 0x165f38: 0x3e00008  jr          $ra
    ctx->pc = 0x165F38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165F38u;
            // 0x165f3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165F24u: goto label_165f24;
            case 0x165F38u: goto label_165f38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165F40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
