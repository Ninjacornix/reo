#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5AE0
// Address: 0x1b5ae0 - 0x1b5ca0
void sub_001B5AE0_0x1b5ae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5AE0_0x1b5ae0");
#endif

    switch (ctx->pc) {
        case 0x1b5b2cu: goto label_1b5b2c;
        case 0x1b5b38u: goto label_1b5b38;
        case 0x1b5b44u: goto label_1b5b44;
        case 0x1b5b5cu: goto label_1b5b5c;
        case 0x1b5becu: goto label_1b5bec;
        case 0x1b5bfcu: goto label_1b5bfc;
        case 0x1b5c18u: goto label_1b5c18;
        case 0x1b5c2cu: goto label_1b5c2c;
        case 0x1b5c6cu: goto label_1b5c6c;
        default: break;
    }

    ctx->pc = 0x1b5ae0u;

    // 0x1b5ae0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1b5ae0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1b5ae4: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5ae4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5ae8: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1b5ae8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1b5aec: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1b5aecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1b5af0: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b5af0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b5af4: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1b5af4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5af8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b5af8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b5afc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b5afcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b5b00: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b5b00u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b5b04: 0x3c12002c  lui         $s2, 0x2C
    ctx->pc = 0x1b5b04u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)44 << 16));
    // 0x1b5b08: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b5b08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b5b0c: 0x8c23ab40  lw          $v1, -0x54C0($at)
    ctx->pc = 0x1b5b0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945600)));
    // 0x1b5b10: 0x2c630170  sltiu       $v1, $v1, 0x170
    ctx->pc = 0x1b5b10u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)368) ? 1 : 0);
    // 0x1b5b14: 0x14600059  bnez        $v1, . + 4 + (0x59 << 2)
    ctx->pc = 0x1B5B14u;
    {
        const bool branch_taken_0x1b5b14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5B14u;
            // 0x1b5b18: 0x2652aaf0  addiu       $s2, $s2, -0x5510 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294945520));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5b14) {
            ctx->pc = 0x1B5C7Cu;
            goto label_1b5c7c;
        }
    }
    ctx->pc = 0x1B5B1Cu;
    // 0x1b5b1c: 0x8e50004c  lw          $s0, 0x4C($s2)
    ctx->pc = 0x1b5b1cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x1b5b20: 0x8e45000c  lw          $a1, 0xC($s2)
    ctx->pc = 0x1b5b20u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1b5b24: 0xc06dba4  jal         func_1B6E90
    ctx->pc = 0x1B5B24u;
    SET_GPR_U32(ctx, 31, 0x1B5B2Cu);
    ctx->pc = 0x1B5B28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5B24u;
            // 0x1b5b28: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6E90u;
    if (runtime->hasFunction(0x1B6E90u)) {
        auto targetFn = runtime->lookupFunction(0x1B6E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5B2Cu; }
        if (ctx->pc != 0x1B5B2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6E90_0x1b6e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5B2Cu; }
        if (ctx->pc != 0x1B5B2Cu) { return; }
    }
    ctx->pc = 0x1B5B2Cu;
label_1b5b2c:
    // 0x1b5b2c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1b5b2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5b30: 0xc06dc54  jal         func_1B7150
    ctx->pc = 0x1B5B30u;
    SET_GPR_U32(ctx, 31, 0x1B5B38u);
    ctx->pc = 0x1B5B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5B30u;
            // 0x1b5b34: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7150u;
    if (runtime->hasFunction(0x1B7150u)) {
        auto targetFn = runtime->lookupFunction(0x1B7150u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5B38u; }
        if (ctx->pc != 0x1B5B38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7150_0x1b7150(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5B38u; }
        if (ctx->pc != 0x1B5B38u) { return; }
    }
    ctx->pc = 0x1B5B38u;
label_1b5b38:
    // 0x1b5b38: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b5b38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5b3c: 0xc06dd34  jal         func_1B74D0
    ctx->pc = 0x1B5B3Cu;
    SET_GPR_U32(ctx, 31, 0x1B5B44u);
    ctx->pc = 0x1B5B40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5B3Cu;
            // 0x1b5b40: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B74D0u;
    if (runtime->hasFunction(0x1B74D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B74D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5B44u; }
        if (ctx->pc != 0x1B5B44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B74D0_0x1b74d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5B44u; }
        if (ctx->pc != 0x1B5B44u) { return; }
    }
    ctx->pc = 0x1B5B44u;
label_1b5b44:
    // 0x1b5b44: 0x8e430050  lw          $v1, 0x50($s2)
    ctx->pc = 0x1b5b44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
    // 0x1b5b48: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b5b48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5b4c: 0x200882d  daddu       $s1, $s0, $zero
    ctx->pc = 0x1b5b4cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5b50: 0x2463fe90  addiu       $v1, $v1, -0x170
    ctx->pc = 0x1b5b50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966928));
    // 0x1b5b54: 0xae430050  sw          $v1, 0x50($s2)
    ctx->pc = 0x1b5b54u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 80), GPR_U32(ctx, 3));
    // 0x1b5b58: 0x8e540070  lw          $s4, 0x70($s2)
    ctx->pc = 0x1b5b58u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 112)));
label_1b5b5c:
    // 0x1b5b5c: 0x8e430050  lw          $v1, 0x50($s2)
    ctx->pc = 0x1b5b5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
    // 0x1b5b60: 0x2c630130  sltiu       $v1, $v1, 0x130
    ctx->pc = 0x1b5b60u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)304) ? 1 : 0);
    // 0x1b5b64: 0x14600045  bnez        $v1, . + 4 + (0x45 << 2)
    ctx->pc = 0x1B5B64u;
    {
        const bool branch_taken_0x1b5b64 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b5b64) {
            ctx->pc = 0x1B5C7Cu;
            goto label_1b5c7c;
        }
    }
    ctx->pc = 0x1B5B6Cu;
    // 0x1b5b6c: 0x92a40000  lbu         $a0, 0x0($s5)
    ctx->pc = 0x1b5b6cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1b5b70: 0x1080003b  beqz        $a0, . + 4 + (0x3B << 2)
    ctx->pc = 0x1B5B70u;
    {
        const bool branch_taken_0x1b5b70 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5B70u;
            // 0x1b5b74: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5b70) {
            ctx->pc = 0x1B5C60u;
            goto label_1b5c60;
        }
    }
    ctx->pc = 0x1B5B78u;
    // 0x1b5b78: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x1b5b78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1b5b7c: 0x14830007  bne         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B5B7Cu;
    {
        const bool branch_taken_0x1b5b7c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b5b7c) {
            ctx->pc = 0x1B5B9Cu;
            goto label_1b5b9c;
        }
    }
    ctx->pc = 0x1B5B84u;
    // 0x1b5b84: 0xae540070  sw          $s4, 0x70($s2)
    ctx->pc = 0x1b5b84u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 112), GPR_U32(ctx, 20));
    // 0x1b5b88: 0x8e44006c  lw          $a0, 0x6C($s2)
    ctx->pc = 0x1b5b88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 108)));
    // 0x1b5b8c: 0x8e430074  lw          $v1, 0x74($s2)
    ctx->pc = 0x1b5b8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 116)));
    // 0x1b5b90: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b5b90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b5b94: 0x1000fff1  b           . + 4 + (-0xF << 2)
    ctx->pc = 0x1B5B94u;
    {
        const bool branch_taken_0x1b5b94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5B94u;
            // 0x1b5b98: 0xae430074  sw          $v1, 0x74($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 116), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5b94) {
            ctx->pc = 0x1B5B5Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5b5c;
        }
    }
    ctx->pc = 0x1B5B9Cu;
label_1b5b9c:
    // 0x1b5b9c: 0x2c820080  sltiu       $v0, $a0, 0x80
    ctx->pc = 0x1b5b9cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b5ba0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B5BA0u;
    {
        const bool branch_taken_0x1b5ba0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5BA0u;
            // 0x1b5ba4: 0x2c8200e0  sltiu       $v0, $a0, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5ba0) {
            ctx->pc = 0x1B5BB4u;
            goto label_1b5bb4;
        }
    }
    ctx->pc = 0x1B5BA8u;
    // 0x1b5ba8: 0x2c8100a0  sltiu       $at, $a0, 0xA0
    ctx->pc = 0x1b5ba8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)160) ? 1 : 0);
    // 0x1b5bac: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B5BACu;
    {
        const bool branch_taken_0x1b5bac = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b5bac) {
            ctx->pc = 0x1B5BC4u;
            goto label_1b5bc4;
        }
    }
    ctx->pc = 0x1B5BB4u;
label_1b5bb4:
    // 0x1b5bb4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B5BB4u;
    {
        const bool branch_taken_0x1b5bb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5BB4u;
            // 0x1b5bb8: 0x2c810100  sltiu       $at, $a0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5bb4) {
            ctx->pc = 0x1B5BE0u;
            goto label_1b5be0;
        }
    }
    ctx->pc = 0x1B5BBCu;
    // 0x1b5bbc: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B5BBCu;
    {
        const bool branch_taken_0x1b5bbc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b5bbc) {
            ctx->pc = 0x1B5BE0u;
            goto label_1b5be0;
        }
    }
    ctx->pc = 0x1B5BC4u;
label_1b5bc4:
    // 0x1b5bc4: 0x92a30000  lbu         $v1, 0x0($s5)
    ctx->pc = 0x1b5bc4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1b5bc8: 0x10600025  beqz        $v1, . + 4 + (0x25 << 2)
    ctx->pc = 0x1B5BC8u;
    {
        const bool branch_taken_0x1b5bc8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5BC8u;
            // 0x1b5bcc: 0x26b50001  addiu       $s5, $s5, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5bc8) {
            ctx->pc = 0x1B5C60u;
            goto label_1b5c60;
        }
    }
    ctx->pc = 0x1B5BD0u;
    // 0x1b5bd0: 0x41200  sll         $v0, $a0, 8
    ctx->pc = 0x1b5bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1b5bd4: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1b5bd4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5bd8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B5BD8u;
    {
        const bool branch_taken_0x1b5bd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5BD8u;
            // 0x1b5bdc: 0x431025  or          $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5bd8) {
            ctx->pc = 0x1B5BF0u;
            goto label_1b5bf0;
        }
    }
    ctx->pc = 0x1B5BE0u;
label_1b5be0:
    // 0x1b5be0: 0x8e450008  lw          $a1, 0x8($s2)
    ctx->pc = 0x1b5be0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1b5be4: 0xc06d960  jal         func_1B6580
    ctx->pc = 0x1B5BE4u;
    SET_GPR_U32(ctx, 31, 0x1B5BECu);
    ctx->pc = 0x1B5BE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5BE4u;
            // 0x1b5be8: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6580u;
    if (runtime->hasFunction(0x1B6580u)) {
        auto targetFn = runtime->lookupFunction(0x1B6580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5BECu; }
        if (ctx->pc != 0x1B5BECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6580_0x1b6580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5BECu; }
        if (ctx->pc != 0x1B5BECu) { return; }
    }
    ctx->pc = 0x1B5BECu;
label_1b5bec:
    // 0x1b5bec: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x1b5becu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b5bf0:
    // 0x1b5bf0: 0x8e450008  lw          $a1, 0x8($s2)
    ctx->pc = 0x1b5bf0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1b5bf4: 0xc06d93c  jal         func_1B64F0
    ctx->pc = 0x1B5BF4u;
    SET_GPR_U32(ctx, 31, 0x1B5BFCu);
    ctx->pc = 0x1B5BF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5BF4u;
            // 0x1b5bf8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B64F0u;
    if (runtime->hasFunction(0x1B64F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B64F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5BFCu; }
        if (ctx->pc != 0x1B5BFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B64F0_0x1b64f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5BFCu; }
        if (ctx->pc != 0x1B5BFCu) { return; }
    }
    ctx->pc = 0x1B5BFCu;
label_1b5bfc:
    // 0x1b5bfc: 0x8e43001c  lw          $v1, 0x1C($s2)
    ctx->pc = 0x1b5bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x1b5c00: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1b5c00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5c04: 0xa3082b  sltu        $at, $a1, $v1
    ctx->pc = 0x1b5c04u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b5c08: 0x1020000f  beqz        $at, . + 4 + (0xF << 2)
    ctx->pc = 0x1B5C08u;
    {
        const bool branch_taken_0x1b5c08 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5C08u;
            // 0x1b5c0c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5c08) {
            ctx->pc = 0x1B5C48u;
            goto label_1b5c48;
        }
    }
    ctx->pc = 0x1B5C10u;
    // 0x1b5c10: 0xc06d728  jal         func_1B5CA0
    ctx->pc = 0x1B5C10u;
    SET_GPR_U32(ctx, 31, 0x1B5C18u);
    ctx->pc = 0x1B5CA0u;
    if (runtime->hasFunction(0x1B5CA0u)) {
        auto targetFn = runtime->lookupFunction(0x1B5CA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5C18u; }
        if (ctx->pc != 0x1B5C18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5CA0_0x1b5ca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5C18u; }
        if (ctx->pc != 0x1B5C18u) { return; }
    }
    ctx->pc = 0x1B5C18u;
label_1b5c18:
    // 0x1b5c18: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1b5c18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5c1c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1b5c1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5c20: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1b5c20u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5c24: 0xc06dc74  jal         func_1B71D0
    ctx->pc = 0x1B5C24u;
    SET_GPR_U32(ctx, 31, 0x1B5C2Cu);
    ctx->pc = 0x1B5C28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5C24u;
            // 0x1b5c28: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B71D0u;
    if (runtime->hasFunction(0x1B71D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B71D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5C2Cu; }
        if (ctx->pc != 0x1B5C2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B71D0_0x1b71d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5C2Cu; }
        if (ctx->pc != 0x1B5C2Cu) { return; }
    }
    ctx->pc = 0x1B5C2Cu;
label_1b5c2c:
    // 0x1b5c2c: 0x8e430050  lw          $v1, 0x50($s2)
    ctx->pc = 0x1b5c2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
    // 0x1b5c30: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1b5c30u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5c34: 0x2463fee0  addiu       $v1, $v1, -0x120
    ctx->pc = 0x1b5c34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967008));
    // 0x1b5c38: 0xae430050  sw          $v1, 0x50($s2)
    ctx->pc = 0x1b5c38u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 80), GPR_U32(ctx, 3));
    // 0x1b5c3c: 0x8e430064  lw          $v1, 0x64($s2)
    ctx->pc = 0x1b5c3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 100)));
    // 0x1b5c40: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b5c40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b5c44: 0xae430064  sw          $v1, 0x64($s2)
    ctx->pc = 0x1b5c44u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 100), GPR_U32(ctx, 3));
label_1b5c48:
    // 0x1b5c48: 0x8e44006c  lw          $a0, 0x6C($s2)
    ctx->pc = 0x1b5c48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 108)));
    // 0x1b5c4c: 0x8e430070  lw          $v1, 0x70($s2)
    ctx->pc = 0x1b5c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 112)));
    // 0x1b5c50: 0x2642006  srlv        $a0, $a0, $s3
    ctx->pc = 0x1b5c50u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), GPR_U32(ctx, 19) & 0x1F));
    // 0x1b5c54: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b5c54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b5c58: 0x1000ffc0  b           . + 4 + (-0x40 << 2)
    ctx->pc = 0x1B5C58u;
    {
        const bool branch_taken_0x1b5c58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5C58u;
            // 0x1b5c5c: 0xae430070  sw          $v1, 0x70($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 112), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5c58) {
            ctx->pc = 0x1B5B5Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5b5c;
        }
    }
    ctx->pc = 0x1B5C60u;
label_1b5c60:
    // 0x1b5c60: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b5c60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5c64: 0xc06dd34  jal         func_1B74D0
    ctx->pc = 0x1B5C64u;
    SET_GPR_U32(ctx, 31, 0x1B5C6Cu);
    ctx->pc = 0x1B5C68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5C64u;
            // 0x1b5c68: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B74D0u;
    if (runtime->hasFunction(0x1B74D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B74D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5C6Cu; }
        if (ctx->pc != 0x1B5C6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B74D0_0x1b74d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5C6Cu; }
        if (ctx->pc != 0x1B5C6Cu) { return; }
    }
    ctx->pc = 0x1B5C6Cu;
label_1b5c6c:
    // 0x1b5c6c: 0x8e430050  lw          $v1, 0x50($s2)
    ctx->pc = 0x1b5c6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
    // 0x1b5c70: 0x2463fff0  addiu       $v1, $v1, -0x10
    ctx->pc = 0x1b5c70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967280));
    // 0x1b5c74: 0xae430050  sw          $v1, 0x50($s2)
    ctx->pc = 0x1b5c74u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 80), GPR_U32(ctx, 3));
    // 0x1b5c78: 0xae42004c  sw          $v0, 0x4C($s2)
    ctx->pc = 0x1b5c78u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 76), GPR_U32(ctx, 2));
label_1b5c7c:
    // 0x1b5c7c: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1b5c7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1b5c80: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1b5c80u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b5c84: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b5c84u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b5c88: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b5c88u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b5c8c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b5c8cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b5c90: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b5c90u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b5c94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b5c94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b5c98: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5C98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B5C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5C98u;
            // 0x1b5c9c: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B5B2Cu: goto label_1b5b2c;
            case 0x1B5B38u: goto label_1b5b38;
            case 0x1B5B44u: goto label_1b5b44;
            case 0x1B5B5Cu: goto label_1b5b5c;
            case 0x1B5B9Cu: goto label_1b5b9c;
            case 0x1B5BB4u: goto label_1b5bb4;
            case 0x1B5BC4u: goto label_1b5bc4;
            case 0x1B5BE0u: goto label_1b5be0;
            case 0x1B5BECu: goto label_1b5bec;
            case 0x1B5BF0u: goto label_1b5bf0;
            case 0x1B5BFCu: goto label_1b5bfc;
            case 0x1B5C18u: goto label_1b5c18;
            case 0x1B5C2Cu: goto label_1b5c2c;
            case 0x1B5C48u: goto label_1b5c48;
            case 0x1B5C60u: goto label_1b5c60;
            case 0x1B5C6Cu: goto label_1b5c6c;
            case 0x1B5C7Cu: goto label_1b5c7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B5CA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
