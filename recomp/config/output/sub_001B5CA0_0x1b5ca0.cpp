#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5CA0
// Address: 0x1b5ca0 - 0x1b5dc0
void sub_001B5CA0_0x1b5ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5CA0_0x1b5ca0");
#endif

    switch (ctx->pc) {
        case 0x1b5cc4u: goto label_1b5cc4;
        case 0x1b5d2cu: goto label_1b5d2c;
        case 0x1b5d58u: goto label_1b5d58;
        default: break;
    }

    ctx->pc = 0x1b5ca0u;

    // 0x1b5ca0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b5ca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b5ca4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1b5ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b5ca8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b5ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b5cac: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b5cacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b5cb0: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1b5cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1b5cb4: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B5CB4u;
    {
        const bool branch_taken_0x1b5cb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b5cb4) {
            ctx->pc = 0x1B5CCCu;
            goto label_1b5ccc;
        }
    }
    ctx->pc = 0x1B5CBCu;
    // 0x1b5cbc: 0xc06da18  jal         func_1B6860
    ctx->pc = 0x1B5CBCu;
    SET_GPR_U32(ctx, 31, 0x1B5CC4u);
    ctx->pc = 0x1B6860u;
    if (runtime->hasFunction(0x1B6860u)) {
        auto targetFn = runtime->lookupFunction(0x1B6860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5CC4u; }
        if (ctx->pc != 0x1B5CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6860_0x1b6860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5CC4u; }
        if (ctx->pc != 0x1B5CC4u) { return; }
    }
    ctx->pc = 0x1B5CC4u;
label_1b5cc4:
    // 0x1b5cc4: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1B5CC4u;
    {
        const bool branch_taken_0x1b5cc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5CC4u;
            // 0x1b5cc8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5cc4) {
            ctx->pc = 0x1B5DA8u;
            goto label_1b5da8;
        }
    }
    ctx->pc = 0x1B5CCCu;
label_1b5ccc:
    // 0x1b5ccc: 0x8c860020  lw          $a2, 0x20($a0)
    ctx->pc = 0x1b5cccu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1b5cd0: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x1b5cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1b5cd4: 0x8c880010  lw          $t0, 0x10($a0)
    ctx->pc = 0x1b5cd4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1b5cd8: 0xa61818  mult        $v1, $a1, $a2
    ctx->pc = 0x1b5cd8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b5cdc: 0x15000007  bnez        $t0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B5CDCu;
    {
        const bool branch_taken_0x1b5cdc = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5CDCu;
            // 0x1b5ce0: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5cdc) {
            ctx->pc = 0x1B5CFCu;
            goto label_1b5cfc;
        }
    }
    ctx->pc = 0x1B5CE4u;
    // 0x1b5ce4: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x1b5ce4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1b5ce8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b5ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b5cec: 0x14a30003  bne         $a1, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B5CECu;
    {
        const bool branch_taken_0x1b5cec = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b5cec) {
            ctx->pc = 0x1B5CFCu;
            goto label_1b5cfc;
        }
    }
    ctx->pc = 0x1B5CF4u;
    // 0x1b5cf4: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1B5CF4u;
    {
        const bool branch_taken_0x1b5cf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b5cf4) {
            ctx->pc = 0x1B5DA4u;
            goto label_1b5da4;
        }
    }
    ctx->pc = 0x1B5CFCu;
label_1b5cfc:
    // 0x1b5cfc: 0x8c850018  lw          $a1, 0x18($a0)
    ctx->pc = 0x1b5cfcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x1b5d00: 0x8c830064  lw          $v1, 0x64($a0)
    ctx->pc = 0x1b5d00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 100)));
    // 0x1b5d04: 0x8c870048  lw          $a3, 0x48($a0)
    ctx->pc = 0x1b5d04u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x1b5d08: 0xa32818  mult        $a1, $a1, $v1
    ctx->pc = 0x1b5d08u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x1b5d0c: 0x73880  sll         $a3, $a3, 2
    ctx->pc = 0x1b5d0cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1b5d10: 0xe43821  addu        $a3, $a3, $a0
    ctx->pc = 0x1b5d10u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x1b5d14: 0x8ce3002c  lw          $v1, 0x2C($a3)
    ctx->pc = 0x1b5d14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x1b5d18: 0x15000006  bnez        $t0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B5D18u;
    {
        const bool branch_taken_0x1b5d18 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5D18u;
            // 0x1b5d1c: 0x658021  addu        $s0, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5d18) {
            ctx->pc = 0x1B5D34u;
            goto label_1b5d34;
        }
    }
    ctx->pc = 0x1B5D20u;
    // 0x1b5d20: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1b5d20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5d24: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1B5D24u;
    SET_GPR_U32(ctx, 31, 0x1B5D2Cu);
    ctx->pc = 0x1B5D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5D24u;
            // 0x1b5d28: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5D2Cu; }
        if (ctx->pc != 0x1B5D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5D2Cu; }
        if (ctx->pc != 0x1B5D2Cu) { return; }
    }
    ctx->pc = 0x1B5D2Cu;
label_1b5d2c:
    // 0x1b5d2c: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1B5D2Cu;
    {
        const bool branch_taken_0x1b5d2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5D2Cu;
            // 0x1b5d30: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5d2c) {
            ctx->pc = 0x1B5DA4u;
            goto label_1b5da4;
        }
    }
    ctx->pc = 0x1B5D34u;
label_1b5d34:
    // 0x1b5d34: 0x8c85000c  lw          $a1, 0xC($a0)
    ctx->pc = 0x1b5d34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1b5d38: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x1b5d38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1b5d3c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1b5d3cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5d40: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b5d40u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5d44: 0x24a40003  addiu       $a0, $a1, 0x3
    ctx->pc = 0x1b5d44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
    // 0x1b5d48: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1b5d48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1b5d4c: 0xa31818  mult        $v1, $a1, $v1
    ctx->pc = 0x1b5d4cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b5d50: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1B5D50u;
    {
        const bool branch_taken_0x1b5d50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5D50u;
            // 0x1b5d54: 0x34082  srl         $t0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SRL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5d50) {
            ctx->pc = 0x1B5D94u;
            goto label_1b5d94;
        }
    }
    ctx->pc = 0x1B5D58u;
label_1b5d58:
    // 0x1b5d58: 0x90460000  lbu         $a2, 0x0($v0)
    ctx->pc = 0x1b5d58u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b5d5c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1b5d5cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1b5d60: 0x30c300c0  andi        $v1, $a2, 0xC0
    ctx->pc = 0x1b5d60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)192);
    // 0x1b5d64: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1b5d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1b5d68: 0x32183  sra         $a0, $v1, 6
    ctx->pc = 0x1b5d68u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 3), 6));
    // 0x1b5d6c: 0x30c30030  andi        $v1, $a2, 0x30
    ctx->pc = 0x1b5d6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)48);
    // 0x1b5d70: 0x832825  or          $a1, $a0, $v1
    ctx->pc = 0x1b5d70u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1b5d74: 0x30c3000c  andi        $v1, $a2, 0xC
    ctx->pc = 0x1b5d74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)12);
    // 0x1b5d78: 0x32180  sll         $a0, $v1, 6
    ctx->pc = 0x1b5d78u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
    // 0x1b5d7c: 0x30c30003  andi        $v1, $a2, 0x3
    ctx->pc = 0x1b5d7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)3);
    // 0x1b5d80: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1b5d80u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1b5d84: 0x31b00  sll         $v1, $v1, 12
    ctx->pc = 0x1b5d84u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 12));
    // 0x1b5d88: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1b5d88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1b5d8c: 0xa6030000  sh          $v1, 0x0($s0)
    ctx->pc = 0x1b5d8cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b5d90: 0x26100002  addiu       $s0, $s0, 0x2
    ctx->pc = 0x1b5d90u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
label_1b5d94:
    // 0x1b5d94: 0x128182a  slt         $v1, $t1, $t0
    ctx->pc = 0x1b5d94u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1b5d98: 0x1460ffef  bnez        $v1, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1B5D98u;
    {
        const bool branch_taken_0x1b5d98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b5d98) {
            ctx->pc = 0x1B5D58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5d58;
        }
    }
    ctx->pc = 0x1B5DA0u;
    // 0x1b5da0: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x1b5da0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_1b5da4:
    // 0x1b5da4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b5da4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b5da8:
    // 0x1b5da8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b5da8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b5dac: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5DACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B5DB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5DACu;
            // 0x1b5db0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B5CC4u: goto label_1b5cc4;
            case 0x1B5CCCu: goto label_1b5ccc;
            case 0x1B5CFCu: goto label_1b5cfc;
            case 0x1B5D2Cu: goto label_1b5d2c;
            case 0x1B5D34u: goto label_1b5d34;
            case 0x1B5D58u: goto label_1b5d58;
            case 0x1B5D94u: goto label_1b5d94;
            case 0x1B5DA4u: goto label_1b5da4;
            case 0x1B5DA8u: goto label_1b5da8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B5DB4u;
    // 0x1b5db4: 0x0  nop
    ctx->pc = 0x1b5db4u;
    // NOP
    // 0x1b5db8: 0x0  nop
    ctx->pc = 0x1b5db8u;
    // NOP
    // 0x1b5dbc: 0x0  nop
    ctx->pc = 0x1b5dbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
