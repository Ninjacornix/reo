#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132B58
// Address: 0x132b58 - 0x132bc4
void sub_00132B58_0x132b58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132B58_0x132b58");
#endif

    switch (ctx->pc) {
        case 0x132b78u: goto label_132b78;
        case 0x132b9cu: goto label_132b9c;
        default: break;
    }

    ctx->pc = 0x132b58u;

    // 0x132b58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132b58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132b5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x132b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x132b60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x132b60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x132b64: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132B64u;
    {
        const bool branch_taken_0x132b64 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x132B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B64u;
            // 0x132b68: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132b64) {
            ctx->pc = 0x132B80u;
            goto label_132b80;
        }
    }
    ctx->pc = 0x132B6Cu;
    // 0x132b6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132b6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132b70: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132B70u;
    SET_GPR_U32(ctx, 31, 0x132B78u);
    ctx->pc = 0x132B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132B70u;
            // 0x132b74: 0x2484b300  addiu       $a0, $a0, -0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132B78u; }
        if (ctx->pc != 0x132B78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x132B78u; }
        if (ctx->pc != 0x132B78u) { return; }
    }
    ctx->pc = 0x132B78u;
label_132b78:
    // 0x132b78: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x132B78u;
    {
        const bool branch_taken_0x132b78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B78u;
            // 0x132b7c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132b78) {
            ctx->pc = 0x132BB4u;
            goto label_132bb4;
        }
    }
    ctx->pc = 0x132B80u;
label_132b80:
    // 0x132b80: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x132b80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x132b84: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x132B84u;
    {
        const bool branch_taken_0x132b84 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x132B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B84u;
            // 0x132b88: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132b84) {
            ctx->pc = 0x132BB0u;
            goto label_132bb0;
        }
    }
    ctx->pc = 0x132B8Cu;
    // 0x132b8c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x132b8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x132b90: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x132b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x132b94: 0x40f809  jalr        $v0
    ctx->pc = 0x132B94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x132B9Cu);
        ctx->pc = 0x132B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132B94u;
            // 0x132b98: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x132B9Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132B78u: goto label_132b78;
            case 0x132B80u: goto label_132b80;
            case 0x132B9Cu: goto label_132b9c;
            case 0x132BB0u: goto label_132bb0;
            case 0x132BB4u: goto label_132bb4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x132B9Cu; }
            if (ctx->pc != 0x132B9Cu) { return; }
        }
        }
    }
    ctx->pc = 0x132B9Cu;
label_132b9c:
    // 0x132b9c: 0x8603003e  lh          $v1, 0x3E($s0)
    ctx->pc = 0x132b9cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 62)));
    // 0x132ba0: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x132ba0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x132ba4: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x132ba4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x132ba8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x132BA8u;
    {
        const bool branch_taken_0x132ba8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x132BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132BA8u;
            // 0x132bac: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x132ba8) {
            ctx->pc = 0x132BB4u;
            goto label_132bb4;
        }
    }
    ctx->pc = 0x132BB0u;
label_132bb0:
    // 0x132bb0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x132bb0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_132bb4:
    // 0x132bb4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x132bb4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132bb8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x132bb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132bbc: 0x3e00008  jr          $ra
    ctx->pc = 0x132BBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132BC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132BBCu;
            // 0x132bc0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132B78u: goto label_132b78;
            case 0x132B80u: goto label_132b80;
            case 0x132B9Cu: goto label_132b9c;
            case 0x132BB0u: goto label_132bb0;
            case 0x132BB4u: goto label_132bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132BC4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
