#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B19D0
// Address: 0x1b19d0 - 0x1b1a90
void sub_001B19D0_0x1b19d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B19D0_0x1b19d0");
#endif

    switch (ctx->pc) {
        case 0x1b19f4u: goto label_1b19f4;
        case 0x1b19fcu: goto label_1b19fc;
        case 0x1b1a40u: goto label_1b1a40;
        case 0x1b1a54u: goto label_1b1a54;
        default: break;
    }

    ctx->pc = 0x1b19d0u;

    // 0x1b19d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b19d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b19d4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b19d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b19d8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b19d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b19dc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b19dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b19e0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b19e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b19e4: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b19e4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b19e8: 0x8c920000  lw          $s2, 0x0($a0)
    ctx->pc = 0x1b19e8u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b19ec: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B19ECu;
    {
        const bool branch_taken_0x1b19ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B19F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B19ECu;
            // 0x1b19f0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b19ec) {
            ctx->pc = 0x1B1A08u;
            goto label_1b1a08;
        }
    }
    ctx->pc = 0x1B19F4u;
label_1b19f4:
    // 0x1b19f4: 0xc06c4c0  jal         func_1B1300
    ctx->pc = 0x1B19F4u;
    SET_GPR_U32(ctx, 31, 0x1B19FCu);
    ctx->pc = 0x1B19F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B19F4u;
            // 0x1b19f8: 0x8e440000  lw          $a0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1300u;
    if (runtime->hasFunction(0x1B1300u)) {
        auto targetFn = runtime->lookupFunction(0x1B1300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B19FCu; }
        if (ctx->pc != 0x1B19FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1300_0x1b1300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B19FCu; }
        if (ctx->pc != 0x1B19FCu) { return; }
    }
    ctx->pc = 0x1B19FCu;
label_1b19fc:
    // 0x1b19fc: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1b19fcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1b1a00: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b1a00u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b1a04: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x1b1a04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
label_1b1a08:
    // 0x1b1a08: 0x96030816  lhu         $v1, 0x816($s0)
    ctx->pc = 0x1b1a08u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2070)));
    // 0x1b1a0c: 0x223182a  slt         $v1, $s1, $v1
    ctx->pc = 0x1b1a0cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b1a10: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1B1A10u;
    {
        const bool branch_taken_0x1b1a10 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b1a10) {
            ctx->pc = 0x1B19F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b19f4;
        }
    }
    ctx->pc = 0x1B1A18u;
    // 0x1b1a18: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1b1a18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1b1a1c: 0x8e120004  lw          $s2, 0x4($s0)
    ctx->pc = 0x1b1a1cu;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b1a20: 0x12400013  beqz        $s2, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B1A20u;
    {
        const bool branch_taken_0x1b1a20 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b1a20) {
            ctx->pc = 0x1B1A70u;
            goto label_1b1a70;
        }
    }
    ctx->pc = 0x1B1A28u;
    // 0x1b1a28: 0x9204081c  lbu         $a0, 0x81C($s0)
    ctx->pc = 0x1b1a28u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2076)));
    // 0x1b1a2c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b1a2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b1a30: 0x1083000f  beq         $a0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1B1A30u;
    {
        const bool branch_taken_0x1b1a30 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B1A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1A30u;
            // 0x1b1a34: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1a30) {
            ctx->pc = 0x1B1A70u;
            goto label_1b1a70;
        }
    }
    ctx->pc = 0x1B1A38u;
    // 0x1b1a38: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1B1A38u;
    {
        const bool branch_taken_0x1b1a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1A38u;
            // 0x1b1a3c: 0x96030816  lhu         $v1, 0x816($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2070)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1a38) {
            ctx->pc = 0x1B1A64u;
            goto label_1b1a64;
        }
    }
    ctx->pc = 0x1B1A40u;
label_1b1a40:
    // 0x1b1a40: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x1b1a40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1b1a44: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B1A44u;
    {
        const bool branch_taken_0x1b1a44 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b1a44) {
            ctx->pc = 0x1B1A54u;
            goto label_1b1a54;
        }
    }
    ctx->pc = 0x1B1A4Cu;
    // 0x1b1a4c: 0xc06c4c0  jal         func_1B1300
    ctx->pc = 0x1B1A4Cu;
    SET_GPR_U32(ctx, 31, 0x1B1A54u);
    ctx->pc = 0x1B1300u;
    if (runtime->hasFunction(0x1B1300u)) {
        auto targetFn = runtime->lookupFunction(0x1B1300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1A54u; }
        if (ctx->pc != 0x1B1A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1300_0x1b1300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1A54u; }
        if (ctx->pc != 0x1B1A54u) { return; }
    }
    ctx->pc = 0x1B1A54u;
label_1b1a54:
    // 0x1b1a54: 0xae400000  sw          $zero, 0x0($s2)
    ctx->pc = 0x1b1a54u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
    // 0x1b1a58: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b1a58u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b1a5c: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x1b1a5cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x1b1a60: 0x96030816  lhu         $v1, 0x816($s0)
    ctx->pc = 0x1b1a60u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2070)));
label_1b1a64:
    // 0x1b1a64: 0x223182a  slt         $v1, $s1, $v1
    ctx->pc = 0x1b1a64u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b1a68: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x1B1A68u;
    {
        const bool branch_taken_0x1b1a68 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b1a68) {
            ctx->pc = 0x1B1A40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1a40;
        }
    }
    ctx->pc = 0x1B1A70u;
label_1b1a70:
    // 0x1b1a70: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1b1a70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1b1a74: 0xa6000816  sh          $zero, 0x816($s0)
    ctx->pc = 0x1b1a74u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2070), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b1a78: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b1a78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b1a7c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b1a7cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b1a80: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b1a80u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1a84: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1a84u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1a88: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1A88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1A88u;
            // 0x1b1a8c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B19F4u: goto label_1b19f4;
            case 0x1B19FCu: goto label_1b19fc;
            case 0x1B1A08u: goto label_1b1a08;
            case 0x1B1A40u: goto label_1b1a40;
            case 0x1B1A54u: goto label_1b1a54;
            case 0x1B1A64u: goto label_1b1a64;
            case 0x1B1A70u: goto label_1b1a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1A90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
