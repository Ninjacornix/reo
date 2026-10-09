#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116CD0
// Address: 0x116cd0 - 0x116e08
void sub_00116CD0_0x116cd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116CD0_0x116cd0");
#endif

    switch (ctx->pc) {
        case 0x116d58u: goto label_116d58;
        case 0x116dc0u: goto label_116dc0;
        case 0x116dd4u: goto label_116dd4;
        case 0x116de4u: goto label_116de4;
        default: break;
    }

    ctx->pc = 0x116cd0u;

    // 0x116cd0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x116cd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x116cd4: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x116cd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x116cd8: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x116cd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x116cdc: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x116cdcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116ce0: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x116ce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x116ce4: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x116ce4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116ce8: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x116ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x116cec: 0x2622fff0  addiu       $v0, $s1, -0x10
    ctx->pc = 0x116cecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967280));
    // 0x116cf0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x116cf0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116cf4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x116cf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x116cf8: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x116cf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x116cfc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x116cfcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116d00: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x116d00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116d04: 0x2c420061  sltiu       $v0, $v0, 0x61
    ctx->pc = 0x116d04u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)97) ? 1 : 0);
    // 0x116d08: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x116D08u;
    {
        const bool branch_taken_0x116d08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x116D0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116D08u;
            // 0x116d0c: 0x140282d  daddu       $a1, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116d08) {
            ctx->pc = 0x116D18u;
            goto label_116d18;
        }
    }
    ctx->pc = 0x116D10u;
    // 0x116d10: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x116D10u;
    {
        const bool branch_taken_0x116d10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116D10u;
            // 0x116d14: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116d10) {
            ctx->pc = 0x116DE4u;
            goto label_116de4;
        }
    }
    ctx->pc = 0x116D18u;
label_116d18:
    // 0x116d18: 0x18a00011  blez        $a1, . + 4 + (0x11 << 2)
    ctx->pc = 0x116D18u;
    {
        const bool branch_taken_0x116d18 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x116D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116D18u;
            // 0x116d1c: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116d18) {
            ctx->pc = 0x116D60u;
            goto label_116d60;
        }
    }
    ctx->pc = 0x116D20u;
    // 0x116d20: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x116d20u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x116d24: 0x51a00  sll         $v1, $a1, 8
    ctx->pc = 0x116d24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 8));
    // 0x116d28: 0xae090004  sw          $t1, 0x4($s0)
    ctx->pc = 0x116d28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 9));
    // 0x116d2c: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x116d2cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x116d30: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x116d30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x116d34: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x116d34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x116d38: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x116d38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x116d3c: 0x32630004  andi        $v1, $s3, 0x4
    ctx->pc = 0x116d3cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)4);
    // 0x116d40: 0xafa90004  sw          $t1, 0x4($sp)
    ctx->pc = 0x116d40u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 9));
    // 0x116d44: 0xafa50008  sw          $a1, 0x8($sp)
    ctx->pc = 0x116d44u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 5));
    // 0x116d48: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x116D48u;
    {
        const bool branch_taken_0x116d48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x116D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116D48u;
            // 0x116d4c: 0xafa0000c  sw          $zero, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116d48) {
            ctx->pc = 0x116D6Cu;
            goto label_116d6c;
        }
    }
    ctx->pc = 0x116D50u;
    // 0x116d50: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x116D50u;
    SET_GPR_U32(ctx, 31, 0x116D58u);
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116D58u; }
        if (ctx->pc != 0x116D58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116D58u; }
        if (ctx->pc != 0x116D58u) { return; }
    }
    ctx->pc = 0x116D58u;
label_116d58:
    // 0x116d58: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x116D58u;
    {
        const bool branch_taken_0x116d58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116D58u;
            // 0x116d5c: 0x122900  sll         $a1, $s2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116d58) {
            ctx->pc = 0x116D70u;
            goto label_116d70;
        }
    }
    ctx->pc = 0x116D60u;
label_116d60:
    // 0x116d60: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x116d60u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x116d64: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x116d64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x116d68: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x116d68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_116d6c:
    // 0x116d6c: 0x122900  sll         $a1, $s2, 4
    ctx->pc = 0x116d6cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
label_116d70:
    // 0x116d70: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x116d70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x116d74: 0x8c44afa0  lw          $a0, -0x5060($v0)
    ctx->pc = 0x116d74u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294946720)));
    // 0x116d78: 0x3a51821  addu        $v1, $sp, $a1
    ctx->pc = 0x116d78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 5)));
    // 0x116d7c: 0xac700000  sw          $s0, 0x0($v1)
    ctx->pc = 0x116d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 16));
    // 0x116d80: 0x27a20004  addiu       $v0, $sp, 0x4
    ctx->pc = 0x116d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x116d84: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x116d84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x116d88: 0x27a30008  addiu       $v1, $sp, 0x8
    ctx->pc = 0x116d88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x116d8c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x116d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x116d90: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x116d90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x116d94: 0xac710000  sw          $s1, 0x0($v1)
    ctx->pc = 0x116d94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 17));
    // 0x116d98: 0x27a4000c  addiu       $a0, $sp, 0xC
    ctx->pc = 0x116d98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x116d9c: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x116d9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x116da0: 0xae140008  sw          $s4, 0x8($s0)
    ctx->pc = 0x116da0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 20));
    // 0x116da4: 0xa2110000  sb          $s1, 0x0($s0)
    ctx->pc = 0x116da4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 17));
    // 0x116da8: 0x24020044  addiu       $v0, $zero, 0x44
    ctx->pc = 0x116da8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0x116dac: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x116dacu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x116db0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x116db0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116db4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x116db4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116db8: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x116DB8u;
    SET_GPR_U32(ctx, 31, 0x116DC0u);
    ctx->pc = 0x116DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116DB8u;
            // 0x116dbc: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116DC0u; }
        if (ctx->pc != 0x116DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116DC0u; }
        if (ctx->pc != 0x116DC0u) { return; }
    }
    ctx->pc = 0x116DC0u;
label_116dc0:
    // 0x116dc0: 0x32620001  andi        $v0, $s3, 0x1
    ctx->pc = 0x116dc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)1);
    // 0x116dc4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x116DC4u;
    {
        const bool branch_taken_0x116dc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x116DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116DC4u;
            // 0x116dc8: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116dc4) {
            ctx->pc = 0x116DDCu;
            goto label_116ddc;
        }
    }
    ctx->pc = 0x116DCCu;
    // 0x116dcc: 0xc04527c  jal         func_1149F0
    ctx->pc = 0x116DCCu;
    SET_GPR_U32(ctx, 31, 0x116DD4u);
    ctx->pc = 0x116DD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116DCCu;
            // 0x116dd0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149F0u;
    if (runtime->hasFunction(0x1149F0u)) {
        auto targetFn = runtime->lookupFunction(0x1149F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116DD4u; }
        if (ctx->pc != 0x116DD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149F0_0x1149f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116DD4u; }
        if (ctx->pc != 0x116DD4u) { return; }
    }
    ctx->pc = 0x116DD4u;
label_116dd4:
    // 0x116dd4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x116DD4u;
    {
        const bool branch_taken_0x116dd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x116DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116DD4u;
            // 0x116dd8: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x116dd4) {
            ctx->pc = 0x116DE8u;
            goto label_116de8;
        }
    }
    ctx->pc = 0x116DDCu;
label_116ddc:
    // 0x116ddc: 0xc045278  jal         func_1149E0
    ctx->pc = 0x116DDCu;
    SET_GPR_U32(ctx, 31, 0x116DE4u);
    ctx->pc = 0x116DE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116DDCu;
            // 0x116de0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149E0u;
    if (runtime->hasFunction(0x1149E0u)) {
        auto targetFn = runtime->lookupFunction(0x1149E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116DE4u; }
        if (ctx->pc != 0x116DE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149E0_0x1149e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x116DE4u; }
        if (ctx->pc != 0x116DE4u) { return; }
    }
    ctx->pc = 0x116DE4u;
label_116de4:
    // 0x116de4: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x116de4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_116de8:
    // 0x116de8: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x116de8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x116dec: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x116decu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x116df0: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x116df0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x116df4: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x116df4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x116df8: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x116df8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x116dfc: 0x3e00008  jr          $ra
    ctx->pc = 0x116DFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116DFCu;
            // 0x116e00: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x116D18u: goto label_116d18;
            case 0x116D58u: goto label_116d58;
            case 0x116D60u: goto label_116d60;
            case 0x116D6Cu: goto label_116d6c;
            case 0x116D70u: goto label_116d70;
            case 0x116DC0u: goto label_116dc0;
            case 0x116DD4u: goto label_116dd4;
            case 0x116DDCu: goto label_116ddc;
            case 0x116DE4u: goto label_116de4;
            case 0x116DE8u: goto label_116de8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116E04u;
    // 0x116e04: 0x0  nop
    ctx->pc = 0x116e04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
