#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DC28
// Address: 0x15dc28 - 0x15dcc0
void sub_0015DC28_0x15dc28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DC28_0x15dc28");
#endif

    switch (ctx->pc) {
        case 0x15dc60u: goto label_15dc60;
        default: break;
    }

    ctx->pc = 0x15dc28u;

    // 0x15dc28: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15dc28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15dc2c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15dc2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15dc30: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x15dc30u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15dc34: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15dc34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15dc38: 0x249300bc  addiu       $s3, $a0, 0xBC
    ctx->pc = 0x15dc38u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), 188));
    // 0x15dc3c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15dc3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15dc40: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15dc40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15dc44: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x15dc44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x15dc48: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x15dc48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x15dc4c: 0x8ca20038  lw          $v0, 0x38($a1)
    ctx->pc = 0x15dc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 56)));
    // 0x15dc50: 0x8c9400d4  lw          $s4, 0xD4($a0)
    ctx->pc = 0x15dc50u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 212)));
    // 0x15dc54: 0x8c510004  lw          $s1, 0x4($v0)
    ctx->pc = 0x15dc54u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x15dc58: 0xc057a4c  jal         func_15E930
    ctx->pc = 0x15DC58u;
    SET_GPR_U32(ctx, 31, 0x15DC60u);
    ctx->pc = 0x15DC5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DC58u;
            // 0x15dc5c: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E930u;
    if (runtime->hasFunction(0x15E930u)) {
        auto targetFn = runtime->lookupFunction(0x15E930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DC60u; }
        if (ctx->pc != 0x15DC60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E930_0x15e930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DC60u; }
        if (ctx->pc != 0x15DC60u) { return; }
    }
    ctx->pc = 0x15DC60u;
label_15dc60:
    // 0x15dc60: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15dc60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15dc64: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x15DC64u;
    {
        const bool branch_taken_0x15dc64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x15dc64) {
            ctx->pc = 0x15DC68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DC64u;
            // 0x15dc68: 0xae400044  sw          $zero, 0x44($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DC78u;
            goto label_15dc78;
        }
    }
    ctx->pc = 0x15DC6Cu;
    // 0x15dc6c: 0x16930004  bne         $s4, $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x15DC6Cu;
    {
        const bool branch_taken_0x15dc6c = (GPR_U64(ctx, 20) != GPR_U64(ctx, 19));
        if (branch_taken_0x15dc6c) {
            ctx->pc = 0x15DC80u;
            goto label_15dc80;
        }
    }
    ctx->pc = 0x15DC74u;
    // 0x15dc74: 0xae400044  sw          $zero, 0x44($s2)
    ctx->pc = 0x15dc74u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 0));
label_15dc78:
    // 0x15dc78: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x15DC78u;
    {
        const bool branch_taken_0x15dc78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DC7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DC78u;
            // 0x15dc7c: 0xae400040  sw          $zero, 0x40($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 64), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dc78) {
            ctx->pc = 0x15DCA0u;
            goto label_15dca0;
        }
    }
    ctx->pc = 0x15DC80u;
label_15dc80:
    // 0x15dc80: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15DC80u;
    {
        const bool branch_taken_0x15dc80 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DC84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DC80u;
            // 0x15dc84: 0x2a220005  slti        $v0, $s1, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dc80) {
            ctx->pc = 0x15DC98u;
            goto label_15dc98;
        }
    }
    ctx->pc = 0x15DC88u;
    // 0x15dc88: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x15DC88u;
    {
        const bool branch_taken_0x15dc88 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15dc88) {
            ctx->pc = 0x15DC8Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DC88u;
            // 0x15dc8c: 0xae510044  sw          $s1, 0x44($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DC9Cu;
            goto label_15dc9c;
        }
    }
    ctx->pc = 0x15DC90u;
    // 0x15dc90: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x15dc90u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x15dc94: 0x2631fffc  addiu       $s1, $s1, -0x4
    ctx->pc = 0x15dc94u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967292));
label_15dc98:
    // 0x15dc98: 0xae510044  sw          $s1, 0x44($s2)
    ctx->pc = 0x15dc98u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 17));
label_15dc9c:
    // 0x15dc9c: 0xae500040  sw          $s0, 0x40($s2)
    ctx->pc = 0x15dc9cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 64), GPR_U32(ctx, 16));
label_15dca0:
    // 0x15dca0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15dca0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15dca4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15dca4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15dca8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15dca8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15dcac: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15dcacu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15dcb0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x15dcb0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15dcb4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x15dcb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15dcb8: 0x3e00008  jr          $ra
    ctx->pc = 0x15DCB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DCBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DCB8u;
            // 0x15dcbc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DC60u: goto label_15dc60;
            case 0x15DC78u: goto label_15dc78;
            case 0x15DC80u: goto label_15dc80;
            case 0x15DC98u: goto label_15dc98;
            case 0x15DC9Cu: goto label_15dc9c;
            case 0x15DCA0u: goto label_15dca0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15DCC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
