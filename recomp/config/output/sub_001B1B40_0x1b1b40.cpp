#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1B40
// Address: 0x1b1b40 - 0x1b1bb0
void sub_001B1B40_0x1b1b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1B40_0x1b1b40");
#endif

    switch (ctx->pc) {
        case 0x1b1b68u: goto label_1b1b68;
        case 0x1b1b80u: goto label_1b1b80;
        default: break;
    }

    ctx->pc = 0x1b1b40u;

    // 0x1b1b40: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b1b40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b1b44: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1b1b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1b1b48: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b1b48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b1b4c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b1b4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b1b50: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1b1b50u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1b54: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b1b54u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b1b58: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1b1b58u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1b5c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b1b5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b1b60: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B1B60u;
    {
        const bool branch_taken_0x1b1b60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1B60u;
            // 0x1b1b64: 0xa68821  addu        $s1, $a1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1b60) {
            ctx->pc = 0x1B1B88u;
            goto label_1b1b88;
        }
    }
    ctx->pc = 0x1B1B68u;
label_1b1b68:
    // 0x1b1b68: 0x2638021  addu        $s0, $s3, $v1
    ctx->pc = 0x1b1b68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1b1b6c: 0x96040000  lhu         $a0, 0x0($s0)
    ctx->pc = 0x1b1b6cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b1b70: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B1B70u;
    {
        const bool branch_taken_0x1b1b70 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b1b70) {
            ctx->pc = 0x1B1B84u;
            goto label_1b1b84;
        }
    }
    ctx->pc = 0x1B1B78u;
    // 0x1b1b78: 0xc064968  jal         func_1925A0
    ctx->pc = 0x1B1B78u;
    SET_GPR_U32(ctx, 31, 0x1B1B80u);
    ctx->pc = 0x1925A0u;
    if (runtime->hasFunction(0x1925A0u)) {
        auto targetFn = runtime->lookupFunction(0x1925A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1B80u; }
        if (ctx->pc != 0x1B1B80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001925A0_0x1925a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1B80u; }
        if (ctx->pc != 0x1B1B80u) { return; }
    }
    ctx->pc = 0x1B1B80u;
label_1b1b80:
    // 0x1b1b80: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1b1b80u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_1b1b84:
    // 0x1b1b84: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1b1b84u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_1b1b88:
    // 0x1b1b88: 0x251182a  slt         $v1, $s2, $s1
    ctx->pc = 0x1b1b88u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x1b1b8c: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1B1B8Cu;
    {
        const bool branch_taken_0x1b1b8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B1B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1B8Cu;
            // 0x1b1b90: 0x121840  sll         $v1, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1b8c) {
            ctx->pc = 0x1B1B68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1b68;
        }
    }
    ctx->pc = 0x1B1B94u;
    // 0x1b1b94: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1b1b94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b1b98: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b1b98u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b1b9c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b1b9cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b1ba0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b1ba0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1ba4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1ba4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1ba8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1BA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1BA8u;
            // 0x1b1bac: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1B68u: goto label_1b1b68;
            case 0x1B1B80u: goto label_1b1b80;
            case 0x1B1B84u: goto label_1b1b84;
            case 0x1B1B88u: goto label_1b1b88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1BB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
