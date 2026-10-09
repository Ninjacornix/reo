#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115BE8
// Address: 0x115be8 - 0x115d60
void sub_00115BE8_0x115be8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115BE8_0x115be8");
#endif

    switch (ctx->pc) {
        case 0x115c38u: goto label_115c38;
        case 0x115c68u: goto label_115c68;
        case 0x115cd4u: goto label_115cd4;
        case 0x115cf0u: goto label_115cf0;
        case 0x115d08u: goto label_115d08;
        case 0x115d14u: goto label_115d14;
        case 0x115d30u: goto label_115d30;
        default: break;
    }

    ctx->pc = 0x115be8u;

    // 0x115be8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x115be8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x115bec: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x115becu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x115bf0: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x115bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x115bf4: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x115bf4u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x115bf8: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x115bf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x115bfc: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x115bfcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115c00: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x115c00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x115c04: 0x26b3ab90  addiu       $s3, $s5, -0x5470
    ctx->pc = 0x115c04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 21), 4294945680));
    // 0x115c08: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x115c08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115c0c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x115c0cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115c10: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x115c10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115c14: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x115c14u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115c18: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x115c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x115c1c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x115c1cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115c20: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x115c20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x115c24: 0x8e62000c  lw          $v0, 0xC($s3)
    ctx->pc = 0x115c24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x115c28: 0x14400042  bnez        $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x115C28u;
    {
        const bool branch_taken_0x115c28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x115C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115C28u;
            // 0x115c2c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115c28) {
            ctx->pc = 0x115D34u;
            goto label_115d34;
        }
    }
    ctx->pc = 0x115C30u;
    // 0x115c30: 0xc047598  jal         func_11D660
    ctx->pc = 0x115C30u;
    SET_GPR_U32(ctx, 31, 0x115C38u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115C38u; }
        if (ctx->pc != 0x115C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115C38u; }
        if (ctx->pc != 0x115C38u) { return; }
    }
    ctx->pc = 0x115C38u;
label_115c38:
    // 0x115c38: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x115c38u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115c3c: 0x3c042000  lui         $a0, 0x2000
    ctx->pc = 0x115c3cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8192 << 16));
    // 0x115c40: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x115c40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x115c44: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x115c44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x115c48: 0x2442abc0  addiu       $v0, $v0, -0x5440
    ctx->pc = 0x115c48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945728));
    // 0x115c4c: 0xae63000c  sw          $v1, 0xC($s3)
    ctx->pc = 0x115c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 3));
    // 0x115c50: 0x443025  or          $a2, $v0, $a0
    ctx->pc = 0x115c50u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x115c54: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x115c54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x115c58: 0xae660010  sw          $a2, 0x10($s3)
    ctx->pc = 0x115c58u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 6));
    // 0x115c5c: 0x2407000a  addiu       $a3, $zero, 0xA
    ctx->pc = 0x115c5cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x115c60: 0x2405000d  addiu       $a1, $zero, 0xD
    ctx->pc = 0x115c60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x115c64: 0x24c4000c  addiu       $a0, $a2, 0xC
    ctx->pc = 0x115c64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 12));
label_115c68:
    // 0x115c68: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x115c68u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x115c6c: 0x52480012  beql        $s2, $t0, . + 4 + (0x12 << 2)
    ctx->pc = 0x115C6Cu;
    {
        const bool branch_taken_0x115c6c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 8));
        if (branch_taken_0x115c6c) {
            ctx->pc = 0x115C70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x115C6Cu;
            // 0x115c70: 0x26b0ab90  addiu       $s0, $s5, -0x5470 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294945680));
        ctx->in_delay_slot = false;
            ctx->pc = 0x115CB8u;
            goto label_115cb8;
        }
    }
    ctx->pc = 0x115C74u;
    // 0x115c74: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x115c74u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x115c78: 0x14470007  bne         $v0, $a3, . + 4 + (0x7 << 2)
    ctx->pc = 0x115C78u;
    {
        const bool branch_taken_0x115c78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        ctx->pc = 0x115C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115C78u;
            // 0x115c7c: 0x92030000  lbu         $v1, 0x0($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115c78) {
            ctx->pc = 0x115C98u;
            goto label_115c98;
        }
    }
    ctx->pc = 0x115C80u;
    // 0x115c80: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x115c80u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x115c84: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x115c84u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x115c88: 0x2a220100  slti        $v0, $s1, 0x100
    ctx->pc = 0x115c88u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x115c8c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x115C8Cu;
    {
        const bool branch_taken_0x115c8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x115C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115C8Cu;
            // 0x115c90: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115c8c) {
            ctx->pc = 0x115CB4u;
            goto label_115cb4;
        }
    }
    ctx->pc = 0x115C94u;
    // 0x115c94: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x115c94u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_115c98:
    // 0x115c98: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x115c98u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x115c9c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x115c9cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x115ca0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x115ca0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x115ca4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x115ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x115ca8: 0x2a220100  slti        $v0, $s1, 0x100
    ctx->pc = 0x115ca8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x115cac: 0x1440ffee  bnez        $v0, . + 4 + (-0x12 << 2)
    ctx->pc = 0x115CACu;
    {
        const bool branch_taken_0x115cac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x115CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115CACu;
            // 0x115cb0: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115cac) {
            ctx->pc = 0x115C68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115c68;
        }
    }
    ctx->pc = 0x115CB4u;
label_115cb4:
    // 0x115cb4: 0x26b0ab90  addiu       $s0, $s5, -0x5470
    ctx->pc = 0x115cb4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294945680));
label_115cb8:
    // 0x115cb8: 0x2622000c  addiu       $v0, $s1, 0xC
    ctx->pc = 0x115cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
    // 0x115cbc: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x115cbcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x115cc0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x115cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x115cc4: 0x80c50007  lb          $a1, 0x7($a2)
    ctx->pc = 0x115cc4u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 7)));
    // 0x115cc8: 0x8ea4ab90  lw          $a0, -0x5470($s5)
    ctx->pc = 0x115cc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294945680)));
    // 0x115ccc: 0xc0455f8  jal         func_1157E0
    ctx->pc = 0x115CCCu;
    SET_GPR_U32(ctx, 31, 0x115CD4u);
    ctx->pc = 0x115CD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115CCCu;
            // 0x115cd0: 0xa4c30000  sh          $v1, 0x0($a2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1157E0u;
    if (runtime->hasFunction(0x1157E0u)) {
        auto targetFn = runtime->lookupFunction(0x1157E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115CD4u; }
        if (ctx->pc != 0x115CD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001157E0_0x1157e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115CD4u; }
        if (ctx->pc != 0x115CD4u) { return; }
    }
    ctx->pc = 0x115CD4u;
label_115cd4:
    // 0x115cd4: 0x4410008  bgez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x115CD4u;
    {
        const bool branch_taken_0x115cd4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x115cd4) {
            ctx->pc = 0x115CF8u;
            goto label_115cf8;
        }
    }
    ctx->pc = 0x115CDCu;
    // 0x115cdc: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x115cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x115ce0: 0x12c00014  beqz        $s6, . + 4 + (0x14 << 2)
    ctx->pc = 0x115CE0u;
    {
        const bool branch_taken_0x115ce0 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x115CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115CE0u;
            // 0x115ce4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115ce0) {
            ctx->pc = 0x115D34u;
            goto label_115d34;
        }
    }
    ctx->pc = 0x115CE8u;
    // 0x115ce8: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x115CE8u;
    SET_GPR_U32(ctx, 31, 0x115CF0u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115CF0u; }
        if (ctx->pc != 0x115CF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115CF0u; }
        if (ctx->pc != 0x115CF0u) { return; }
    }
    ctx->pc = 0x115CF0u;
label_115cf0:
    // 0x115cf0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x115CF0u;
    {
        const bool branch_taken_0x115cf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115CF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115CF0u;
            // 0x115cf4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115cf0) {
            ctx->pc = 0x115D34u;
            goto label_115d34;
        }
    }
    ctx->pc = 0x115CF8u;
label_115cf8:
    // 0x115cf8: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x115cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x115cfc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x115CFCu;
    {
        const bool branch_taken_0x115cfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x115D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115CFCu;
            // 0x115d00: 0x2a0882d  daddu       $s1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115cfc) {
            ctx->pc = 0x115D20u;
            goto label_115d20;
        }
    }
    ctx->pc = 0x115D04u;
    // 0x115d04: 0x0  nop
    ctx->pc = 0x115d04u;
    // NOP
label_115d08:
    // 0x115d08: 0x8e24ab90  lw          $a0, -0x5470($s1)
    ctx->pc = 0x115d08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294945680)));
    // 0x115d0c: 0xc045604  jal         func_115810
    ctx->pc = 0x115D0Cu;
    SET_GPR_U32(ctx, 31, 0x115D14u);
    ctx->pc = 0x115810u;
    if (runtime->hasFunction(0x115810u)) {
        auto targetFn = runtime->lookupFunction(0x115810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115D14u; }
        if (ctx->pc != 0x115D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115810_0x115810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115D14u; }
        if (ctx->pc != 0x115D14u) { return; }
    }
    ctx->pc = 0x115D14u;
label_115d14:
    // 0x115d14: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x115d14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x115d18: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x115D18u;
    {
        const bool branch_taken_0x115d18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x115d18) {
            ctx->pc = 0x115D08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115d08;
        }
    }
    ctx->pc = 0x115D20u;
label_115d20:
    // 0x115d20: 0x12c00004  beqz        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x115D20u;
    {
        const bool branch_taken_0x115d20 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x115D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115D20u;
            // 0x115d24: 0x280102d  daddu       $v0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115d20) {
            ctx->pc = 0x115D34u;
            goto label_115d34;
        }
    }
    ctx->pc = 0x115D28u;
    // 0x115d28: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x115D28u;
    SET_GPR_U32(ctx, 31, 0x115D30u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115D30u; }
        if (ctx->pc != 0x115D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115D30u; }
        if (ctx->pc != 0x115D30u) { return; }
    }
    ctx->pc = 0x115D30u;
label_115d30:
    // 0x115d30: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x115d30u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_115d34:
    // 0x115d34: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x115d34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x115d38: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x115d38u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x115d3c: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x115d3cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x115d40: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x115d40u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x115d44: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x115d44u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x115d48: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x115d48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115d4c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115d4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115d50: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115d50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115d54: 0x3e00008  jr          $ra
    ctx->pc = 0x115D54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115D54u;
            // 0x115d58: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115C38u: goto label_115c38;
            case 0x115C68u: goto label_115c68;
            case 0x115C98u: goto label_115c98;
            case 0x115CB4u: goto label_115cb4;
            case 0x115CB8u: goto label_115cb8;
            case 0x115CD4u: goto label_115cd4;
            case 0x115CF0u: goto label_115cf0;
            case 0x115CF8u: goto label_115cf8;
            case 0x115D08u: goto label_115d08;
            case 0x115D14u: goto label_115d14;
            case 0x115D20u: goto label_115d20;
            case 0x115D30u: goto label_115d30;
            case 0x115D34u: goto label_115d34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115D5Cu;
    // 0x115d5c: 0x0  nop
    ctx->pc = 0x115d5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
