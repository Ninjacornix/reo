#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102B48
// Address: 0x102b48 - 0x102bb0
void sub_00102B48_0x102b48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102B48_0x102b48");
#endif

    switch (ctx->pc) {
        case 0x102b5cu: goto label_102b5c;
        default: break;
    }

    ctx->pc = 0x102b48u;

    // 0x102b48: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x102b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x102b4c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x102b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102b50: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x102b50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x102b54: 0xc040b08  jal         func_102C20
    ctx->pc = 0x102B54u;
    SET_GPR_U32(ctx, 31, 0x102B5Cu);
    ctx->pc = 0x102B58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102B54u;
            // 0x102b58: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102C20u;
    if (runtime->hasFunction(0x102C20u)) {
        auto targetFn = runtime->lookupFunction(0x102C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102B5Cu; }
        if (ctx->pc != 0x102B5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102C20_0x102c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102B5Cu; }
        if (ctx->pc != 0x102B5Cu) { return; }
    }
    ctx->pc = 0x102B5Cu;
label_102b5c:
    // 0x102b5c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102B5Cu;
    {
        const bool branch_taken_0x102b5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x102B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B5Cu;
            // 0x102b60: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b5c) {
            ctx->pc = 0x102B6Cu;
            goto label_102b6c;
        }
    }
    ctx->pc = 0x102B64u;
    // 0x102b64: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x102B64u;
    {
        const bool branch_taken_0x102b64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x102b64) {
            ctx->pc = 0x102B74u;
            goto label_102b74;
        }
    }
    ctx->pc = 0x102B6Cu;
label_102b6c:
    // 0x102b6c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x102B6Cu;
    {
        const bool branch_taken_0x102b6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x102B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B6Cu;
            // 0x102b70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b6c) {
            ctx->pc = 0x102BA0u;
            goto label_102ba0;
        }
    }
    ctx->pc = 0x102B74u;
label_102b74:
    // 0x102b74: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102B74u;
    {
        const bool branch_taken_0x102b74 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x102B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B74u;
            // 0x102b78: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b74) {
            ctx->pc = 0x102B84u;
            goto label_102b84;
        }
    }
    ctx->pc = 0x102B7Cu;
    // 0x102b7c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x102B7Cu;
    {
        const bool branch_taken_0x102b7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x102B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B7Cu;
            // 0x102b80: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b7c) {
            ctx->pc = 0x102B94u;
            goto label_102b94;
        }
    }
    ctx->pc = 0x102B84u;
label_102b84:
    // 0x102b84: 0x16030006  bne         $s0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x102B84u;
    {
        const bool branch_taken_0x102b84 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        ctx->pc = 0x102B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B84u;
            // 0x102b88: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b84) {
            ctx->pc = 0x102BA0u;
            goto label_102ba0;
        }
    }
    ctx->pc = 0x102B8Cu;
    // 0x102b8c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x102b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x102b90: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x102b90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_102b94:
    // 0x102b94: 0x34423c10  ori         $v0, $v0, 0x3C10
    ctx->pc = 0x102b94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)15376);
    // 0x102b98: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x102b98u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x102b9c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x102b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_102ba0:
    // 0x102ba0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x102ba0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102ba4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102ba4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102ba8: 0x3e00008  jr          $ra
    ctx->pc = 0x102BA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102BA8u;
            // 0x102bac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102B5Cu: goto label_102b5c;
            case 0x102B6Cu: goto label_102b6c;
            case 0x102B74u: goto label_102b74;
            case 0x102B84u: goto label_102b84;
            case 0x102B94u: goto label_102b94;
            case 0x102BA0u: goto label_102ba0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102BB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
