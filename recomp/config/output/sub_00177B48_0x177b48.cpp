#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177B48
// Address: 0x177b48 - 0x177be0
void sub_00177B48_0x177b48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177B48_0x177b48");
#endif

    switch (ctx->pc) {
        case 0x177b78u: goto label_177b78;
        case 0x177b7cu: goto label_177b7c;
        case 0x177bb4u: goto label_177bb4;
        default: break;
    }

    ctx->pc = 0x177b48u;

    // 0x177b48: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x177b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x177b4c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x177b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x177b50: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x177b50u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177b54: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x177b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x177b58: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x177b58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177b5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177b60: 0x26501aa0  addiu       $s0, $s2, 0x1AA0
    ctx->pc = 0x177b60u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 6816));
    // 0x177b64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x177b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x177b68: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x177b68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177b6c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x177b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x177b70: 0x59880  sll         $s3, $a1, 2
    ctx->pc = 0x177b70u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x177b74: 0x0  nop
    ctx->pc = 0x177b74u;
    // NOP
label_177b78:
    // 0x177b78: 0x2a220009  slti        $v0, $s1, 0x9
    ctx->pc = 0x177b78u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)9) ? 1 : 0);
label_177b7c:
    // 0x177b7c: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x177B7Cu;
    {
        const bool branch_taken_0x177b7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177B7Cu;
            // 0x177b80: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177b7c) {
            ctx->pc = 0x177BC0u;
            goto label_177bc0;
        }
    }
    ctx->pc = 0x177B84u;
    // 0x177b84: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x177b84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x177b88: 0x26100044  addiu       $s0, $s0, 0x44
    ctx->pc = 0x177b88u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x177b8c: 0x0  nop
    ctx->pc = 0x177b8cu;
    // NOP
    // 0x177b90: 0x0  nop
    ctx->pc = 0x177b90u;
    // NOP
    // 0x177b94: 0x1040fff8  beqz        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x177B94u;
    {
        const bool branch_taken_0x177b94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x177B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177B94u;
            // 0x177b98: 0x2621821  addu        $v1, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177b94) {
            ctx->pc = 0x177B78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_177b78;
        }
    }
    ctx->pc = 0x177B9Cu;
    // 0x177b9c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x177b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x177ba0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x177ba0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ba4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x177ba4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ba8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x177ba8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177bac: 0x40f809  jalr        $v0
    ctx->pc = 0x177BACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x177BB4u);
        ctx->pc = 0x177BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177BACu;
            // 0x177bb0: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x177BB4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177B78u: goto label_177b78;
            case 0x177B7Cu: goto label_177b7c;
            case 0x177BB4u: goto label_177bb4;
            case 0x177BC0u: goto label_177bc0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x177BB4u; }
            if (ctx->pc != 0x177BB4u) { return; }
        }
        }
    }
    ctx->pc = 0x177BB4u;
label_177bb4:
    // 0x177bb4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x177bb4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177bb8: 0x1080fff0  beqz        $a0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x177BB8u;
    {
        const bool branch_taken_0x177bb8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x177BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177BB8u;
            // 0x177bbc: 0x2a220009  slti        $v0, $s1, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)9) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x177bb8) {
            ctx->pc = 0x177B7Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_177b7c;
        }
    }
    ctx->pc = 0x177BC0u;
label_177bc0:
    // 0x177bc0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177bc0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177bc4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x177bc4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177bc8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x177bc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177bcc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x177bccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177bd0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x177bd0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x177bd4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x177bd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x177bd8: 0x3e00008  jr          $ra
    ctx->pc = 0x177BD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177BD8u;
            // 0x177bdc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177B78u: goto label_177b78;
            case 0x177B7Cu: goto label_177b7c;
            case 0x177BB4u: goto label_177bb4;
            case 0x177BC0u: goto label_177bc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177BE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
