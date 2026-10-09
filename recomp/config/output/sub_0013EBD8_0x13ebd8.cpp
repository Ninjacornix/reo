#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EBD8
// Address: 0x13ebd8 - 0x13ec50
void sub_0013EBD8_0x13ebd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EBD8_0x13ebd8");
#endif

    switch (ctx->pc) {
        case 0x13ec18u: goto label_13ec18;
        case 0x13ec28u: goto label_13ec28;
        default: break;
    }

    ctx->pc = 0x13ebd8u;

    // 0x13ebd8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13ebd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13ebdc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13ebdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13ebe0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13ebe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13ebe4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13ebe4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ebe8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13ebe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13ebec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13ebecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13ebf0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13ebf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13ebf4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13ebf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13ebf8: 0xa2250050  sb          $a1, 0x50($s1)
    ctx->pc = 0x13ebf8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 80), (uint8_t)GPR_U32(ctx, 5));
    // 0x13ebfc: 0x10a2000d  beq         $a1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13EBFCu;
    {
        const bool branch_taken_0x13ebfc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13EC00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EBFCu;
            // 0x13ec00: 0x82230026  lb          $v1, 0x26($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 38)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ebfc) {
            ctx->pc = 0x13EC34u;
            goto label_13ec34;
        }
    }
    ctx->pc = 0x13EC04u;
    // 0x13ec04: 0x1860000c  blez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x13EC04u;
    {
        const bool branch_taken_0x13ec04 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x13EC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC04u;
            // 0x13ec08: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ec04) {
            ctx->pc = 0x13EC38u;
            goto label_13ec38;
        }
    }
    ctx->pc = 0x13EC0Cu;
    // 0x13ec0c: 0x60902d  daddu       $s2, $v1, $zero
    ctx->pc = 0x13ec0cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ec10: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x13ec10u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13ec14: 0x26300010  addiu       $s0, $s1, 0x10
    ctx->pc = 0x13ec14u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
label_13ec18:
    // 0x13ec18: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x13ec18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ec1c: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x13ec1cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x13ec20: 0xc04e2f8  jal         func_138BE0
    ctx->pc = 0x13EC20u;
    SET_GPR_U32(ctx, 31, 0x13EC28u);
    ctx->pc = 0x13EC24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC20u;
            // 0x13ec24: 0x2652ffff  addiu       $s2, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138BE0u;
    if (runtime->hasFunction(0x138BE0u)) {
        auto targetFn = runtime->lookupFunction(0x138BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EC28u; }
        if (ctx->pc != 0x13EC28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138BE0_0x138be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EC28u; }
        if (ctx->pc != 0x13EC28u) { return; }
    }
    ctx->pc = 0x13EC28u;
label_13ec28:
    // 0x13ec28: 0xa2330051  sb          $s3, 0x51($s1)
    ctx->pc = 0x13ec28u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 81), (uint8_t)GPR_U32(ctx, 19));
    // 0x13ec2c: 0x1640fffa  bnez        $s2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13EC2Cu;
    {
        const bool branch_taken_0x13ec2c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x13EC30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC2Cu;
            // 0x13ec30: 0xa2200050  sb          $zero, 0x50($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 80), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ec2c) {
            ctx->pc = 0x13EC18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13ec18;
        }
    }
    ctx->pc = 0x13EC34u;
label_13ec34:
    // 0x13ec34: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ec34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13ec38:
    // 0x13ec38: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ec38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ec3c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13ec3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13ec40: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13ec40u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13ec44: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13ec44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13ec48: 0x3e00008  jr          $ra
    ctx->pc = 0x13EC48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EC4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EC48u;
            // 0x13ec4c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13EC18u: goto label_13ec18;
            case 0x13EC28u: goto label_13ec28;
            case 0x13EC34u: goto label_13ec34;
            case 0x13EC38u: goto label_13ec38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13EC50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
