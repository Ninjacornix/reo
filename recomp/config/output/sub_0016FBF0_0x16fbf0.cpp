#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016FBF0
// Address: 0x16fbf0 - 0x16fc80
void sub_0016FBF0_0x16fbf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016FBF0_0x16fbf0");
#endif

    switch (ctx->pc) {
        case 0x16fc20u: goto label_16fc20;
        case 0x16fc5cu: goto label_16fc5c;
        default: break;
    }

    ctx->pc = 0x16fbf0u;

    // 0x16fbf0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16fbf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16fbf4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16fbf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16fbf8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16fbf8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16fbfc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16fbfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16fc00: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16fc00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16fc04: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16fc04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16fc08: 0x18c00016  blez        $a2, . + 4 + (0x16 << 2)
    ctx->pc = 0x16FC08u;
    {
        const bool branch_taken_0x16fc08 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x16FC0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FC08u;
            // 0x16fc0c: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16fc08) {
            ctx->pc = 0x16FC64u;
            goto label_16fc64;
        }
    }
    ctx->pc = 0x16FC10u;
    // 0x16fc10: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16fc10u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16fc14: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16fc14u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16fc18: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x16fc18u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16fc1c: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x16fc1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_16fc20:
    // 0x16fc20: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x16fc20u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x16fc24: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x16fc24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x16fc28: 0x2604002c  addiu       $a0, $s0, 0x2C
    ctx->pc = 0x16fc28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 44));
    // 0x16fc2c: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x16fc2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x16fc30: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x16fc30u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x16fc34: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x16fc34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x16fc38: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x16fc38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x16fc3c: 0xae130010  sw          $s3, 0x10($s0)
    ctx->pc = 0x16fc3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 19));
    // 0x16fc40: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x16fc40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x16fc44: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x16fc44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x16fc48: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x16fc48u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x16fc4c: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x16fc4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x16fc50: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x16fc50u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x16fc54: 0xc05bf20  jal         func_16FC80
    ctx->pc = 0x16FC54u;
    SET_GPR_U32(ctx, 31, 0x16FC5Cu);
    ctx->pc = 0x16FC58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FC54u;
            // 0x16fc58: 0x26100080  addiu       $s0, $s0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16FC80u;
    if (runtime->hasFunction(0x16FC80u)) {
        auto targetFn = runtime->lookupFunction(0x16FC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FC5Cu; }
        if (ctx->pc != 0x16FC5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FC80_0x16fc80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FC5Cu; }
        if (ctx->pc != 0x16FC5Cu) { return; }
    }
    ctx->pc = 0x16FC5Cu;
label_16fc5c:
    // 0x16fc5c: 0x5620fff0  bnel        $s1, $zero, . + 4 + (-0x10 << 2)
    ctx->pc = 0x16FC5Cu;
    {
        const bool branch_taken_0x16fc5c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x16fc5c) {
            ctx->pc = 0x16FC60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16FC5Cu;
            // 0x16fc60: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16FC20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16fc20;
        }
    }
    ctx->pc = 0x16FC64u;
label_16fc64:
    // 0x16fc64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16fc64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16fc68: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16fc68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16fc6c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16fc6cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16fc70: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16fc70u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16fc74: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16fc74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16fc78: 0x3e00008  jr          $ra
    ctx->pc = 0x16FC78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16FC7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FC78u;
            // 0x16fc7c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16FC20u: goto label_16fc20;
            case 0x16FC5Cu: goto label_16fc5c;
            case 0x16FC64u: goto label_16fc64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16FC80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
