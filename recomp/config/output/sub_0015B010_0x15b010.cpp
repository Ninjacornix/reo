#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B010
// Address: 0x15b010 - 0x15b078
void sub_0015B010_0x15b010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B010_0x15b010");
#endif

    switch (ctx->pc) {
        case 0x15b038u: goto label_15b038;
        case 0x15b050u: goto label_15b050;
        default: break;
    }

    ctx->pc = 0x15b010u;

    // 0x15b010: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15b010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15b014: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15b014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15b018: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15b018u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b01c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15b01cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15b020: 0x2cb10001  sltiu       $s1, $a1, 0x1
    ctx->pc = 0x15b020u;
    SET_GPR_U64(ctx, 17, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x15b024: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15b024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15b028: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15b028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15b02c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x15b02cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x15b030: 0x40f809  jalr        $v0
    ctx->pc = 0x15B030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15B038u);
        ctx->pc = 0x15B034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B030u;
            // 0x15b034: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15B038u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B038u: goto label_15b038;
            case 0x15B050u: goto label_15b050;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15B038u; }
            if (ctx->pc != 0x15B038u) { return; }
        }
        }
    }
    ctx->pc = 0x15B038u;
label_15b038:
    // 0x15b038: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15b038u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15b03c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15b03cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b040: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x15b040u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b044: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x15b044u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x15b048: 0x40f809  jalr        $v0
    ctx->pc = 0x15B048u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15B050u);
        ctx->pc = 0x15B04Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B048u;
            // 0x15b04c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15B050u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B038u: goto label_15b038;
            case 0x15B050u: goto label_15b050;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15B050u; }
            if (ctx->pc != 0x15B050u) { return; }
        }
        }
    }
    ctx->pc = 0x15B050u;
label_15b050:
    // 0x15b050: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x15b050u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15b054: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15b054u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15b058: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15b058u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15b05c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15b05cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15b060: 0x3e00008  jr          $ra
    ctx->pc = 0x15B060u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B060u;
            // 0x15b064: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B038u: goto label_15b038;
            case 0x15B050u: goto label_15b050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B068u;
    // 0x15b068: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x15b068u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x15b06c: 0x3e00008  jr          $ra
    ctx->pc = 0x15B06Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B06Cu;
            // 0x15b070: 0x2442e5c0  addiu       $v0, $v0, -0x1A40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960576));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B038u: goto label_15b038;
            case 0x15B050u: goto label_15b050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B074u;
    // 0x15b074: 0x0  nop
    ctx->pc = 0x15b074u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
