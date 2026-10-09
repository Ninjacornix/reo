#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189C80
// Address: 0x189c80 - 0x189e10
void sub_00189C80_0x189c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189C80_0x189c80");
#endif

    switch (ctx->pc) {
        case 0x189cb0u: goto label_189cb0;
        case 0x189cf8u: goto label_189cf8;
        case 0x189d64u: goto label_189d64;
        case 0x189d70u: goto label_189d70;
        case 0x189d84u: goto label_189d84;
        case 0x189d98u: goto label_189d98;
        case 0x189dbcu: goto label_189dbc;
        case 0x189dd4u: goto label_189dd4;
        case 0x189de4u: goto label_189de4;
        default: break;
    }

    ctx->pc = 0x189c80u;

    // 0x189c80: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x189c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x189c84: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x189c84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x189c88: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x189c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x189c8c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x189c8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x189c90: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x189c90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x189c94: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x189c94u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189c98: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x189c98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x189c9c: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x189c9cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189ca0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x189ca0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x189ca4: 0x8c2341a0  lw          $v1, 0x41A0($at)
    ctx->pc = 0x189ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16800)));
    // 0x189ca8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x189CA8u;
    {
        const bool branch_taken_0x189ca8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189CA8u;
            // 0x189cac: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189ca8) {
            ctx->pc = 0x189CCCu;
            goto label_189ccc;
        }
    }
    ctx->pc = 0x189CB0u;
label_189cb0:
    // 0x189cb0: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x189cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x189cb4: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x189cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x189cb8: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x189cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x189cbc: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x189cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x189cc0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x189CC0u;
    {
        const bool branch_taken_0x189cc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x189CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189CC0u;
            // 0x189cc4: 0x121040  sll         $v0, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189cc0) {
            ctx->pc = 0x189CDCu;
            goto label_189cdc;
        }
    }
    ctx->pc = 0x189CC8u;
    // 0x189cc8: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x189cc8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_189ccc:
    // 0x189ccc: 0x2e420280  sltiu       $v0, $s2, 0x280
    ctx->pc = 0x189cccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)640) ? 1 : 0);
    // 0x189cd0: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x189CD0u;
    {
        const bool branch_taken_0x189cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x189CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189CD0u;
            // 0x189cd4: 0x121040  sll         $v0, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189cd0) {
            ctx->pc = 0x189CB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189cb0;
        }
    }
    ctx->pc = 0x189CD8u;
    // 0x189cd8: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x189cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_189cdc:
    // 0x189cdc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x189cdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189ce0: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x189ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x189ce4: 0x24060180  addiu       $a2, $zero, 0x180
    ctx->pc = 0x189ce4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
    // 0x189ce8: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x189ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x189cec: 0x628821  addu        $s1, $v1, $v0
    ctx->pc = 0x189cecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x189cf0: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x189CF0u;
    SET_GPR_U32(ctx, 31, 0x189CF8u);
    ctx->pc = 0x189CF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189CF0u;
            // 0x189cf4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189CF8u; }
        if (ctx->pc != 0x189CF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189CF8u; }
        if (ctx->pc != 0x189CF8u) { return; }
    }
    ctx->pc = 0x189CF8u;
label_189cf8:
    // 0x189cf8: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x189cf8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x189cfc: 0x32020004  andi        $v0, $s0, 0x4
    ctx->pc = 0x189cfcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)4);
    // 0x189d00: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x189d00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x189d04: 0x8e63000c  lw          $v1, 0xC($s3)
    ctx->pc = 0x189d04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x189d08: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x189d08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x189d0c: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x189d0cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x189d10: 0xae200050  sw          $zero, 0x50($s1)
    ctx->pc = 0x189d10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 80), GPR_U32(ctx, 0));
    // 0x189d14: 0x14400029  bnez        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x189D14u;
    {
        const bool branch_taken_0x189d14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x189D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189D14u;
            // 0x189d18: 0xae200054  sw          $zero, 0x54($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 84), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189d14) {
            ctx->pc = 0x189DBCu;
            goto label_189dbc;
        }
    }
    ctx->pc = 0x189D1Cu;
    // 0x189d1c: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x189d1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x189d20: 0x2404fff0  addiu       $a0, $zero, -0x10
    ctx->pc = 0x189d20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x189d24: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x189d24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x189d28: 0x8e63001c  lw          $v1, 0x1C($s3)
    ctx->pc = 0x189d28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x189d2c: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x189d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x189d30: 0x2463000f  addiu       $v1, $v1, 0xF
    ctx->pc = 0x189d30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x189d34: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x189d34u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x189d38: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x189d38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x189d3c: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x189d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x189d40: 0x8e630018  lw          $v1, 0x18($s3)
    ctx->pc = 0x189d40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x189d44: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x189d44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x189d48: 0x2463000f  addiu       $v1, $v1, 0xF
    ctx->pc = 0x189d48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x189d4c: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x189d4cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x189d50: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x189d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x189d54: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x189d54u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x189d58: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x189d58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x189d5c: 0xc063714  jal         func_18DC50
    ctx->pc = 0x189D5Cu;
    SET_GPR_U32(ctx, 31, 0x189D64u);
    ctx->pc = 0x189D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189D5Cu;
            // 0x189d60: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC50u;
    if (runtime->hasFunction(0x18DC50u)) {
        auto targetFn = runtime->lookupFunction(0x18DC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189D64u; }
        if (ctx->pc != 0x189D64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189D64u; }
        if (ctx->pc != 0x189D64u) { return; }
    }
    ctx->pc = 0x189D64u;
label_189d64:
    // 0x189d64: 0xae220014  sw          $v0, 0x14($s1)
    ctx->pc = 0x189d64u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
    // 0x189d68: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x189D68u;
    SET_GPR_U32(ctx, 31, 0x189D70u);
    ctx->pc = 0x189D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189D68u;
            // 0x189d6c: 0x8e240014  lw          $a0, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189D70u; }
        if (ctx->pc != 0x189D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189D70u; }
        if (ctx->pc != 0x189D70u) { return; }
    }
    ctx->pc = 0x189D70u;
label_189d70:
    // 0x189d70: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x189d70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189d74: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x189d74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189d78: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x189d78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189d7c: 0xc0636ec  jal         func_18DBB0
    ctx->pc = 0x189D7Cu;
    SET_GPR_U32(ctx, 31, 0x189D84u);
    ctx->pc = 0x189D80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189D7Cu;
            // 0x189d80: 0x24060024  addiu       $a2, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DBB0u;
    if (runtime->hasFunction(0x18DBB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189D84u; }
        if (ctx->pc != 0x189D84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189D84u; }
        if (ctx->pc != 0x189D84u) { return; }
    }
    ctx->pc = 0x189D84u;
label_189d84:
    // 0x189d84: 0x8e66001c  lw          $a2, 0x1C($s3)
    ctx->pc = 0x189d84u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x189d88: 0x26100030  addiu       $s0, $s0, 0x30
    ctx->pc = 0x189d88u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x189d8c: 0x8e650008  lw          $a1, 0x8($s3)
    ctx->pc = 0x189d8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x189d90: 0xc0636ec  jal         func_18DBB0
    ctx->pc = 0x189D90u;
    SET_GPR_U32(ctx, 31, 0x189D98u);
    ctx->pc = 0x189D94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189D90u;
            // 0x189d94: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DBB0u;
    if (runtime->hasFunction(0x18DBB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189D98u; }
        if (ctx->pc != 0x189D98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189D98u; }
        if (ctx->pc != 0x189D98u) { return; }
    }
    ctx->pc = 0x189D98u;
label_189d98:
    // 0x189d98: 0x8e63001c  lw          $v1, 0x1C($s3)
    ctx->pc = 0x189d98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 28)));
    // 0x189d9c: 0x2402fff0  addiu       $v0, $zero, -0x10
    ctx->pc = 0x189d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x189da0: 0x8e660018  lw          $a2, 0x18($s3)
    ctx->pc = 0x189da0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 24)));
    // 0x189da4: 0x8e650010  lw          $a1, 0x10($s3)
    ctx->pc = 0x189da4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x189da8: 0x2463000f  addiu       $v1, $v1, 0xF
    ctx->pc = 0x189da8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x189dac: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x189dacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x189db0: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x189db0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x189db4: 0xc0636ec  jal         func_18DBB0
    ctx->pc = 0x189DB4u;
    SET_GPR_U32(ctx, 31, 0x189DBCu);
    ctx->pc = 0x189DB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189DB4u;
            // 0x189db8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DBB0u;
    if (runtime->hasFunction(0x18DBB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DBB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189DBCu; }
        if (ctx->pc != 0x189DBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189DBCu; }
        if (ctx->pc != 0x189DBCu) { return; }
    }
    ctx->pc = 0x189DBCu;
label_189dbc:
    // 0x189dbc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x189dbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x189dc0: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x189dc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189dc4: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x189dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x189dc8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x189dc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189dcc: 0xc062784  jal         func_189E10
    ctx->pc = 0x189DCCu;
    SET_GPR_U32(ctx, 31, 0x189DD4u);
    ctx->pc = 0x189DD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189DCCu;
            // 0x189dd0: 0xae22000c  sw          $v0, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189E10u;
    if (runtime->hasFunction(0x189E10u)) {
        auto targetFn = runtime->lookupFunction(0x189E10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189DD4u; }
        if (ctx->pc != 0x189DD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189E10_0x189e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189DD4u; }
        if (ctx->pc != 0x189DD4u) { return; }
    }
    ctx->pc = 0x189DD4u;
label_189dd4:
    // 0x189dd4: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x189DD4u;
    {
        const bool branch_taken_0x189dd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x189DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189DD4u;
            // 0x189dd8: 0x26440001  addiu       $a0, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189dd4) {
            ctx->pc = 0x189DECu;
            goto label_189dec;
        }
    }
    ctx->pc = 0x189DDCu;
    // 0x189ddc: 0xc063128  jal         func_18C4A0
    ctx->pc = 0x189DDCu;
    SET_GPR_U32(ctx, 31, 0x189DE4u);
    ctx->pc = 0x18C4A0u;
    if (runtime->hasFunction(0x18C4A0u)) {
        auto targetFn = runtime->lookupFunction(0x18C4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189DE4u; }
        if (ctx->pc != 0x189DE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C4A0_0x18c4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189DE4u; }
        if (ctx->pc != 0x189DE4u) { return; }
    }
    ctx->pc = 0x189DE4u;
label_189de4:
    // 0x189de4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x189DE4u;
    {
        const bool branch_taken_0x189de4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189DE4u;
            // 0x189de8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189de4) {
            ctx->pc = 0x189DF0u;
            goto label_189df0;
        }
    }
    ctx->pc = 0x189DECu;
label_189dec:
    // 0x189dec: 0x26420001  addiu       $v0, $s2, 0x1
    ctx->pc = 0x189decu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_189df0:
    // 0x189df0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x189df0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x189df4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x189df4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x189df8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x189df8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x189dfc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x189dfcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189e00: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x189e00u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x189e04: 0x3e00008  jr          $ra
    ctx->pc = 0x189E04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189E08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189E04u;
            // 0x189e08: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189CB0u: goto label_189cb0;
            case 0x189CCCu: goto label_189ccc;
            case 0x189CDCu: goto label_189cdc;
            case 0x189CF8u: goto label_189cf8;
            case 0x189D64u: goto label_189d64;
            case 0x189D70u: goto label_189d70;
            case 0x189D84u: goto label_189d84;
            case 0x189D98u: goto label_189d98;
            case 0x189DBCu: goto label_189dbc;
            case 0x189DD4u: goto label_189dd4;
            case 0x189DE4u: goto label_189de4;
            case 0x189DECu: goto label_189dec;
            case 0x189DF0u: goto label_189df0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189E0Cu;
    // 0x189e0c: 0x0  nop
    ctx->pc = 0x189e0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
