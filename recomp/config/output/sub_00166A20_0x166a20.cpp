#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166A20
// Address: 0x166a20 - 0x166a88
void sub_00166A20_0x166a20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166A20_0x166a20");
#endif

    switch (ctx->pc) {
        case 0x166a74u: goto label_166a74;
        default: break;
    }

    ctx->pc = 0x166a20u;

    // 0x166a20: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x166a20u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x166a24: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166a24u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x166a28: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x166a28u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x166a2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166a30: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166a30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166a34: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x166a34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x166a38: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x166a38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x166a3c: 0x24841140  addiu       $a0, $a0, 0x1140
    ctx->pc = 0x166a3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4416));
    // 0x166a40: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166a40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166a44: 0x24060005  addiu       $a2, $zero, 0x5
    ctx->pc = 0x166a44u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x166a48: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x166a48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x166a4c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x166a4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x166a50: 0x14660009  bne         $v1, $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x166A50u;
    {
        const bool branch_taken_0x166a50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        ctx->pc = 0x166A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166A50u;
            // 0x166a54: 0x24900010  addiu       $s0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166a50) {
            ctx->pc = 0x166A78u;
            goto label_166a78;
        }
    }
    ctx->pc = 0x166A58u;
    // 0x166a58: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x166a58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x166a5c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x166A5Cu;
    {
        const bool branch_taken_0x166a5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166A5Cu;
            // 0x166a60: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166a5c) {
            ctx->pc = 0x166A78u;
            goto label_166a78;
        }
    }
    ctx->pc = 0x166A64u;
    // 0x166a64: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x166a64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x166a68: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x166a68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x166a6c: 0x60f809  jalr        $v1
    ctx->pc = 0x166A6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x166A74u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x166A74u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166A74u: goto label_166a74;
            case 0x166A78u: goto label_166a78;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x166A74u; }
            if (ctx->pc != 0x166A74u) { return; }
        }
        }
    }
    ctx->pc = 0x166A74u;
label_166a74:
    // 0x166a74: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x166a74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_166a78:
    // 0x166a78: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166a78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166a7c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x166a7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166a80: 0x3e00008  jr          $ra
    ctx->pc = 0x166A80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166A80u;
            // 0x166a84: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166A74u: goto label_166a74;
            case 0x166A78u: goto label_166a78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166A88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
