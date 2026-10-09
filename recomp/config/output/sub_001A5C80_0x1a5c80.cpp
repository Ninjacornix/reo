#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5C80
// Address: 0x1a5c80 - 0x1a5f00
void sub_001A5C80_0x1a5c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5C80_0x1a5c80");
#endif

    switch (ctx->pc) {
        case 0x1a5c90u: goto label_1a5c90;
        case 0x1a5ca8u: goto label_1a5ca8;
        case 0x1a5d38u: goto label_1a5d38;
        case 0x1a5d50u: goto label_1a5d50;
        case 0x1a5d74u: goto label_1a5d74;
        case 0x1a5db8u: goto label_1a5db8;
        case 0x1a5dc8u: goto label_1a5dc8;
        case 0x1a5dd0u: goto label_1a5dd0;
        case 0x1a5df8u: goto label_1a5df8;
        case 0x1a5e90u: goto label_1a5e90;
        case 0x1a5e98u: goto label_1a5e98;
        default: break;
    }

    ctx->pc = 0x1a5c80u;

    // 0x1a5c80: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a5c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a5c84: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a5c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a5c88: 0xc069998  jal         func_1A6660
    ctx->pc = 0x1A5C88u;
    SET_GPR_U32(ctx, 31, 0x1A5C90u);
    ctx->pc = 0x1A5C8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5C88u;
            // 0x1a5c8c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A6660u;
    if (runtime->hasFunction(0x1A6660u)) {
        auto targetFn = runtime->lookupFunction(0x1A6660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5C90u; }
        if (ctx->pc != 0x1A5C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6660_0x1a6660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5C90u; }
        if (ctx->pc != 0x1A5C90u) { return; }
    }
    ctx->pc = 0x1A5C90u;
label_1a5c90:
    // 0x1a5c90: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5C90u;
    {
        const bool branch_taken_0x1a5c90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a5c90) {
            ctx->pc = 0x1A5CA0u;
            goto label_1a5ca0;
        }
    }
    ctx->pc = 0x1A5C98u;
    // 0x1a5c98: 0x10000073  b           . + 4 + (0x73 << 2)
    ctx->pc = 0x1A5C98u;
    {
        const bool branch_taken_0x1a5c98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5C98u;
            // 0x1a5c9c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5c98) {
            ctx->pc = 0x1A5E68u;
            goto label_1a5e68;
        }
    }
    ctx->pc = 0x1A5CA0u;
label_1a5ca0:
    // 0x1a5ca0: 0xc06980c  jal         func_1A6030
    ctx->pc = 0x1A5CA0u;
    SET_GPR_U32(ctx, 31, 0x1A5CA8u);
    ctx->pc = 0x1A6030u;
    if (runtime->hasFunction(0x1A6030u)) {
        auto targetFn = runtime->lookupFunction(0x1A6030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5CA8u; }
        if (ctx->pc != 0x1A5CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6030_0x1a6030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5CA8u; }
        if (ctx->pc != 0x1A5CA8u) { return; }
    }
    ctx->pc = 0x1A5CA8u;
label_1a5ca8:
    // 0x1a5ca8: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x1a5ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a5cac: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5cacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5cb0: 0xa02209a0  sb          $v0, 0x9A0($at)
    ctx->pc = 0x1a5cb0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 2464), (uint8_t)GPR_U32(ctx, 2));
    // 0x1a5cb4: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a5cb4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a5cb8: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a5cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a5cbc: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    ctx->pc = 0x1a5cbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1a5cc0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5cc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5cc4: 0x244209a0  addiu       $v0, $v0, 0x9A0
    ctx->pc = 0x1a5cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2464));
    // 0x1a5cc8: 0xa42309a2  sh          $v1, 0x9A2($at)
    ctx->pc = 0x1a5cc8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 2466), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a5ccc: 0x3c06002b  lui         $a2, 0x2B
    ctx->pc = 0x1a5cccu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)43 << 16));
    // 0x1a5cd0: 0x78450000  lq          $a1, 0x0($v0)
    ctx->pc = 0x1a5cd0u;
    SET_GPR_VEC(ctx, 5, READ128(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a5cd4: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a5cd4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a5cd8: 0x78440010  lq          $a0, 0x10($v0)
    ctx->pc = 0x1a5cd8u;
    SET_GPR_VEC(ctx, 4, READ128(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1a5cdc: 0x27a80020  addiu       $t0, $sp, 0x20
    ctx->pc = 0x1a5cdcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a5ce0: 0x24e709c0  addiu       $a3, $a3, 0x9C0
    ctx->pc = 0x1a5ce0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2496));
    // 0x1a5ce4: 0x24c60a10  addiu       $a2, $a2, 0xA10
    ctx->pc = 0x1a5ce4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2576));
    // 0x1a5ce8: 0x24630800  addiu       $v1, $v1, 0x800
    ctx->pc = 0x1a5ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2048));
    // 0x1a5cec: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1a5cecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1a5cf0: 0x7d050000  sq          $a1, 0x0($t0)
    ctx->pc = 0x1a5cf0u;
    WRITE128(ADD32(GPR_U32(ctx, 8), 0), GPR_VEC(ctx, 5));
    // 0x1a5cf4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1a5cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1a5cf8: 0x7d040010  sq          $a0, 0x10($t0)
    ctx->pc = 0x1a5cf8u;
    WRITE128(ADD32(GPR_U32(ctx, 8), 16), GPR_VEC(ctx, 4));
    // 0x1a5cfc: 0x79050000  lq          $a1, 0x0($t0)
    ctx->pc = 0x1a5cfcu;
    SET_GPR_VEC(ctx, 5, READ128(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a5d00: 0x79040010  lq          $a0, 0x10($t0)
    ctx->pc = 0x1a5d00u;
    SET_GPR_VEC(ctx, 4, READ128(ADD32(GPR_U32(ctx, 8), 16)));
    // 0x1a5d04: 0x7ce50000  sq          $a1, 0x0($a3)
    ctx->pc = 0x1a5d04u;
    WRITE128(ADD32(GPR_U32(ctx, 7), 0), GPR_VEC(ctx, 5));
    // 0x1a5d08: 0x7ce40010  sq          $a0, 0x10($a3)
    ctx->pc = 0x1a5d08u;
    WRITE128(ADD32(GPR_U32(ctx, 7), 16), GPR_VEC(ctx, 4));
    // 0x1a5d0c: 0xa0c00000  sb          $zero, 0x0($a2)
    ctx->pc = 0x1a5d0cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a5d10: 0xa0c00001  sb          $zero, 0x1($a2)
    ctx->pc = 0x1a5d10u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a5d14: 0xa0c00002  sb          $zero, 0x2($a2)
    ctx->pc = 0x1a5d14u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a5d18: 0xa0c00003  sb          $zero, 0x3($a2)
    ctx->pc = 0x1a5d18u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a5d1c: 0xa0c00005  sb          $zero, 0x5($a2)
    ctx->pc = 0x1a5d1cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 5), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a5d20: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x1a5d20u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x1a5d24: 0x8c231040  lw          $v1, 0x1040($at)
    ctx->pc = 0x1a5d24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4160)));
    // 0x1a5d28: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A5D28u;
    {
        const bool branch_taken_0x1a5d28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1A5D2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5D28u;
            // 0x1a5d2c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5d28) {
            ctx->pc = 0x1A5D40u;
            goto label_1a5d40;
        }
    }
    ctx->pc = 0x1A5D30u;
    // 0x1a5d30: 0xc0699a8  jal         func_1A66A0
    ctx->pc = 0x1A5D30u;
    SET_GPR_U32(ctx, 31, 0x1A5D38u);
    ctx->pc = 0x1A5D34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5D30u;
            // 0x1a5d34: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A66A0u;
    if (runtime->hasFunction(0x1A66A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A66A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5D38u; }
        if (ctx->pc != 0x1A5D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A66A0_0x1a66a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5D38u; }
        if (ctx->pc != 0x1A5D38u) { return; }
    }
    ctx->pc = 0x1A5D38u;
label_1a5d38:
    // 0x1a5d38: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1A5D38u;
    {
        const bool branch_taken_0x1a5d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a5d38) {
            ctx->pc = 0x1A5E10u;
            goto label_1a5e10;
        }
    }
    ctx->pc = 0x1A5D40u;
label_1a5d40:
    // 0x1a5d40: 0x1460001f  bnez        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x1A5D40u;
    {
        const bool branch_taken_0x1a5d40 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5D40u;
            // 0x1a5d44: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5d40) {
            ctx->pc = 0x1A5DC0u;
            goto label_1a5dc0;
        }
    }
    ctx->pc = 0x1A5D48u;
    // 0x1a5d48: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A5D48u;
    {
        const bool branch_taken_0x1a5d48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5D48u;
            // 0x1a5d4c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5d48) {
            ctx->pc = 0x1A5D78u;
            goto label_1a5d78;
        }
    }
    ctx->pc = 0x1A5D50u;
label_1a5d50:
    // 0x1a5d50: 0x101840  sll         $v1, $s0, 1
    ctx->pc = 0x1a5d50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1a5d54: 0x8c241040  lw          $a0, 0x1040($at)
    ctx->pc = 0x1a5d54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4160)));
    // 0x1a5d58: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a5d58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a5d5c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1a5d5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a5d60: 0x24420a10  addiu       $v0, $v0, 0xA10
    ctx->pc = 0x1a5d60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2576));
    // 0x1a5d64: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1a5d64u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a5d68: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1a5d68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5d6c: 0xc0699a8  jal         func_1A66A0
    ctx->pc = 0x1A5D6Cu;
    SET_GPR_U32(ctx, 31, 0x1A5D74u);
    ctx->pc = 0x1A5D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5D6Cu;
            // 0x1a5d70: 0x433021  addu        $a2, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A66A0u;
    if (runtime->hasFunction(0x1A66A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A66A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5D74u; }
        if (ctx->pc != 0x1A5D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A66A0_0x1a66a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5D74u; }
        if (ctx->pc != 0x1A5D74u) { return; }
    }
    ctx->pc = 0x1A5D74u;
label_1a5d74:
    // 0x1a5d74: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a5d74u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a5d78:
    // 0x1a5d78: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5d78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5d7c: 0x8c220980  lw          $v0, 0x980($at)
    ctx->pc = 0x1a5d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2432)));
    // 0x1a5d80: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x1a5d80u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a5d84: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1A5D84u;
    {
        const bool branch_taken_0x1a5d84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5D84u;
            // 0x1a5d88: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5d84) {
            ctx->pc = 0x1A5D50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5d50;
        }
    }
    ctx->pc = 0x1A5D8Cu;
    // 0x1a5d8c: 0x1e000020  bgtz        $s0, . + 4 + (0x20 << 2)
    ctx->pc = 0x1A5D8Cu;
    {
        const bool branch_taken_0x1a5d8c = (GPR_S64(ctx, 16) > 0);
        if (branch_taken_0x1a5d8c) {
            ctx->pc = 0x1A5E10u;
            goto label_1a5e10;
        }
    }
    ctx->pc = 0x1A5D94u;
    // 0x1a5d94: 0x101840  sll         $v1, $s0, 1
    ctx->pc = 0x1a5d94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1a5d98: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a5d98u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a5d9c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1a5d9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1a5da0: 0x24420a10  addiu       $v0, $v0, 0xA10
    ctx->pc = 0x1a5da0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2576));
    // 0x1a5da4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1a5da4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a5da8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1a5da8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a5dac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a5dacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5db0: 0xc0699a8  jal         func_1A66A0
    ctx->pc = 0x1A5DB0u;
    SET_GPR_U32(ctx, 31, 0x1A5DB8u);
    ctx->pc = 0x1A5DB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5DB0u;
            // 0x1a5db4: 0x433021  addu        $a2, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A66A0u;
    if (runtime->hasFunction(0x1A66A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A66A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5DB8u; }
        if (ctx->pc != 0x1A5DB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A66A0_0x1a66a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5DB8u; }
        if (ctx->pc != 0x1A5DB8u) { return; }
    }
    ctx->pc = 0x1A5DB8u;
label_1a5db8:
    // 0x1a5db8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1A5DB8u;
    {
        const bool branch_taken_0x1a5db8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a5db8) {
            ctx->pc = 0x1A5E10u;
            goto label_1a5e10;
        }
    }
    ctx->pc = 0x1A5DC0u;
label_1a5dc0:
    // 0x1a5dc0: 0xc0699a8  jal         func_1A66A0
    ctx->pc = 0x1A5DC0u;
    SET_GPR_U32(ctx, 31, 0x1A5DC8u);
    ctx->pc = 0x1A5DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5DC0u;
            // 0x1a5dc4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A66A0u;
    if (runtime->hasFunction(0x1A66A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A66A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5DC8u; }
        if (ctx->pc != 0x1A5DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A66A0_0x1a66a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5DC8u; }
        if (ctx->pc != 0x1A5DC8u) { return; }
    }
    ctx->pc = 0x1A5DC8u;
label_1a5dc8:
    // 0x1a5dc8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A5DC8u;
    {
        const bool branch_taken_0x1a5dc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5DC8u;
            // 0x1a5dcc: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5dc8) {
            ctx->pc = 0x1A5DFCu;
            goto label_1a5dfc;
        }
    }
    ctx->pc = 0x1A5DD0u;
label_1a5dd0:
    // 0x1a5dd0: 0x26050001  addiu       $a1, $s0, 0x1
    ctx->pc = 0x1a5dd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1a5dd4: 0x8c241040  lw          $a0, 0x1040($at)
    ctx->pc = 0x1a5dd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4160)));
    // 0x1a5dd8: 0x51840  sll         $v1, $a1, 1
    ctx->pc = 0x1a5dd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1a5ddc: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1a5ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a5de0: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a5de0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a5de4: 0x24420a10  addiu       $v0, $v0, 0xA10
    ctx->pc = 0x1a5de4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2576));
    // 0x1a5de8: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1a5de8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a5dec: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1a5decu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5df0: 0xc0699a8  jal         func_1A66A0
    ctx->pc = 0x1A5DF0u;
    SET_GPR_U32(ctx, 31, 0x1A5DF8u);
    ctx->pc = 0x1A5DF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5DF0u;
            // 0x1a5df4: 0x433021  addu        $a2, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A66A0u;
    if (runtime->hasFunction(0x1A66A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A66A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5DF8u; }
        if (ctx->pc != 0x1A5DF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A66A0_0x1a66a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5DF8u; }
        if (ctx->pc != 0x1A5DF8u) { return; }
    }
    ctx->pc = 0x1A5DF8u;
label_1a5df8:
    // 0x1a5df8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1a5df8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1a5dfc:
    // 0x1a5dfc: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5dfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5e00: 0x8c220980  lw          $v0, 0x980($at)
    ctx->pc = 0x1a5e00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2432)));
    // 0x1a5e04: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x1a5e04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a5e08: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
    ctx->pc = 0x1A5E08u;
    {
        const bool branch_taken_0x1a5e08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5E08u;
            // 0x1a5e0c: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5e08) {
            ctx->pc = 0x1A5DD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5dd0;
        }
    }
    ctx->pc = 0x1A5E10u;
label_1a5e10:
    // 0x1a5e10: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1a5e10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1a5e14: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a5e14u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a5e18: 0x24421150  addiu       $v0, $v0, 0x1150
    ctx->pc = 0x1a5e18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4432));
    // 0x1a5e1c: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a5e1cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a5e20: 0xdc430000  ld          $v1, 0x0($v0)
    ctx->pc = 0x1a5e20u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a5e24: 0x27a50048  addiu       $a1, $sp, 0x48
    ctx->pc = 0x1a5e24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
    // 0x1a5e28: 0x3c06002b  lui         $a2, 0x2B
    ctx->pc = 0x1a5e28u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)43 << 16));
    // 0x1a5e2c: 0x24840a00  addiu       $a0, $a0, 0xA00
    ctx->pc = 0x1a5e2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2560));
    // 0x1a5e30: 0x24e70a10  addiu       $a3, $a3, 0xA10
    ctx->pc = 0x1a5e30u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2576));
    // 0x1a5e34: 0x24c60a30  addiu       $a2, $a2, 0xA30
    ctx->pc = 0x1a5e34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2608));
    // 0x1a5e38: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5e38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5e3c: 0xfca30000  sd          $v1, 0x0($a1)
    ctx->pc = 0x1a5e3cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 3));
    // 0x1a5e40: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a5e40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a5e44: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x1a5e44u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a5e48: 0xfc830000  sd          $v1, 0x0($a0)
    ctx->pc = 0x1a5e48u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x1a5e4c: 0x90e30002  lbu         $v1, 0x2($a3)
    ctx->pc = 0x1a5e4cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x1a5e50: 0xa0c30004  sb          $v1, 0x4($a2)
    ctx->pc = 0x1a5e50u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a5e54: 0x90e30003  lbu         $v1, 0x3($a3)
    ctx->pc = 0x1a5e54u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x1a5e58: 0xa0c30005  sb          $v1, 0x5($a2)
    ctx->pc = 0x1a5e58u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 5), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a5e5c: 0xa0200988  sb          $zero, 0x988($at)
    ctx->pc = 0x1a5e5cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 2440), (uint8_t)GPR_U32(ctx, 0));
    // 0x1a5e60: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5e60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5e64: 0xa0200990  sb          $zero, 0x990($at)
    ctx->pc = 0x1a5e64u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 2448), (uint8_t)GPR_U32(ctx, 0));
label_1a5e68:
    // 0x1a5e68: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a5e68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a5e6c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a5e6cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5e70: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5E70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5E70u;
            // 0x1a5e74: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5C90u: goto label_1a5c90;
            case 0x1A5CA0u: goto label_1a5ca0;
            case 0x1A5CA8u: goto label_1a5ca8;
            case 0x1A5D38u: goto label_1a5d38;
            case 0x1A5D40u: goto label_1a5d40;
            case 0x1A5D50u: goto label_1a5d50;
            case 0x1A5D74u: goto label_1a5d74;
            case 0x1A5D78u: goto label_1a5d78;
            case 0x1A5DB8u: goto label_1a5db8;
            case 0x1A5DC0u: goto label_1a5dc0;
            case 0x1A5DC8u: goto label_1a5dc8;
            case 0x1A5DD0u: goto label_1a5dd0;
            case 0x1A5DF8u: goto label_1a5df8;
            case 0x1A5DFCu: goto label_1a5dfc;
            case 0x1A5E10u: goto label_1a5e10;
            case 0x1A5E68u: goto label_1a5e68;
            case 0x1A5E90u: goto label_1a5e90;
            case 0x1A5E98u: goto label_1a5e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5E78u;
    // 0x1a5e78: 0x0  nop
    ctx->pc = 0x1a5e78u;
    // NOP
    // 0x1a5e7c: 0x0  nop
    ctx->pc = 0x1a5e7cu;
    // NOP
    // 0x1a5e80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a5e80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a5e84: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a5e84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a5e88: 0xc06980c  jal         func_1A6030
    ctx->pc = 0x1A5E88u;
    SET_GPR_U32(ctx, 31, 0x1A5E90u);
    ctx->pc = 0x1A6030u;
    if (runtime->hasFunction(0x1A6030u)) {
        auto targetFn = runtime->lookupFunction(0x1A6030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5E90u; }
        if (ctx->pc != 0x1A5E90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6030_0x1a6030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5E90u; }
        if (ctx->pc != 0x1A5E90u) { return; }
    }
    ctx->pc = 0x1A5E90u;
label_1a5e90:
    // 0x1a5e90: 0xc0699c8  jal         func_1A6720
    ctx->pc = 0x1A5E90u;
    SET_GPR_U32(ctx, 31, 0x1A5E98u);
    ctx->pc = 0x1A6720u;
    if (runtime->hasFunction(0x1A6720u)) {
        auto targetFn = runtime->lookupFunction(0x1A6720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5E98u; }
        if (ctx->pc != 0x1A5E98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A6720_0x1a6720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5E98u; }
        if (ctx->pc != 0x1A5E98u) { return; }
    }
    ctx->pc = 0x1A5E98u;
label_1a5e98:
    // 0x1a5e98: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a5e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5e9c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5E9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5E9Cu;
            // 0x1a5ea0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5C90u: goto label_1a5c90;
            case 0x1A5CA0u: goto label_1a5ca0;
            case 0x1A5CA8u: goto label_1a5ca8;
            case 0x1A5D38u: goto label_1a5d38;
            case 0x1A5D40u: goto label_1a5d40;
            case 0x1A5D50u: goto label_1a5d50;
            case 0x1A5D74u: goto label_1a5d74;
            case 0x1A5D78u: goto label_1a5d78;
            case 0x1A5DB8u: goto label_1a5db8;
            case 0x1A5DC0u: goto label_1a5dc0;
            case 0x1A5DC8u: goto label_1a5dc8;
            case 0x1A5DD0u: goto label_1a5dd0;
            case 0x1A5DF8u: goto label_1a5df8;
            case 0x1A5DFCu: goto label_1a5dfc;
            case 0x1A5E10u: goto label_1a5e10;
            case 0x1A5E68u: goto label_1a5e68;
            case 0x1A5E90u: goto label_1a5e90;
            case 0x1A5E98u: goto label_1a5e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5EA4u;
    // 0x1a5ea4: 0x0  nop
    ctx->pc = 0x1a5ea4u;
    // NOP
    // 0x1a5ea8: 0x0  nop
    ctx->pc = 0x1a5ea8u;
    // NOP
    // 0x1a5eac: 0x0  nop
    ctx->pc = 0x1a5eacu;
    // NOP
    // 0x1a5eb0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a5eb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a5eb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5EB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5EB4u;
            // 0x1a5eb8: 0xa0240990  sb          $a0, 0x990($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 2448), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5C90u: goto label_1a5c90;
            case 0x1A5CA0u: goto label_1a5ca0;
            case 0x1A5CA8u: goto label_1a5ca8;
            case 0x1A5D38u: goto label_1a5d38;
            case 0x1A5D40u: goto label_1a5d40;
            case 0x1A5D50u: goto label_1a5d50;
            case 0x1A5D74u: goto label_1a5d74;
            case 0x1A5D78u: goto label_1a5d78;
            case 0x1A5DB8u: goto label_1a5db8;
            case 0x1A5DC0u: goto label_1a5dc0;
            case 0x1A5DC8u: goto label_1a5dc8;
            case 0x1A5DD0u: goto label_1a5dd0;
            case 0x1A5DF8u: goto label_1a5df8;
            case 0x1A5DFCu: goto label_1a5dfc;
            case 0x1A5E10u: goto label_1a5e10;
            case 0x1A5E68u: goto label_1a5e68;
            case 0x1A5E90u: goto label_1a5e90;
            case 0x1A5E98u: goto label_1a5e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5EBCu;
    // 0x1a5ebc: 0x0  nop
    ctx->pc = 0x1a5ebcu;
    // NOP
    // 0x1a5ec0: 0x448c0  sll         $t1, $a0, 3
    ctx->pc = 0x1a5ec0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1a5ec4: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a5ec4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a5ec8: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a5ec8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a5ecc: 0x24630a02  addiu       $v1, $v1, 0xA02
    ctx->pc = 0x1a5eccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2562));
    // 0x1a5ed0: 0x24840a00  addiu       $a0, $a0, 0xA00
    ctx->pc = 0x1a5ed0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2560));
    // 0x1a5ed4: 0x894021  addu        $t0, $a0, $t1
    ctx->pc = 0x1a5ed4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1a5ed8: 0x692021  addu        $a0, $v1, $t1
    ctx->pc = 0x1a5ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1a5edc: 0xa5050000  sh          $a1, 0x0($t0)
    ctx->pc = 0x1a5edcu;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1a5ee0: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a5ee0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a5ee4: 0xa4860000  sh          $a2, 0x0($a0)
    ctx->pc = 0x1a5ee4u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a5ee8: 0x24630a04  addiu       $v1, $v1, 0xA04
    ctx->pc = 0x1a5ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2564));
    // 0x1a5eec: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x1a5eecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1a5ef0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5EF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5EF0u;
            // 0x1a5ef4: 0xa4670000  sh          $a3, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5C90u: goto label_1a5c90;
            case 0x1A5CA0u: goto label_1a5ca0;
            case 0x1A5CA8u: goto label_1a5ca8;
            case 0x1A5D38u: goto label_1a5d38;
            case 0x1A5D40u: goto label_1a5d40;
            case 0x1A5D50u: goto label_1a5d50;
            case 0x1A5D74u: goto label_1a5d74;
            case 0x1A5D78u: goto label_1a5d78;
            case 0x1A5DB8u: goto label_1a5db8;
            case 0x1A5DC0u: goto label_1a5dc0;
            case 0x1A5DC8u: goto label_1a5dc8;
            case 0x1A5DD0u: goto label_1a5dd0;
            case 0x1A5DF8u: goto label_1a5df8;
            case 0x1A5DFCu: goto label_1a5dfc;
            case 0x1A5E10u: goto label_1a5e10;
            case 0x1A5E68u: goto label_1a5e68;
            case 0x1A5E90u: goto label_1a5e90;
            case 0x1A5E98u: goto label_1a5e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5EF8u;
    // 0x1a5ef8: 0x0  nop
    ctx->pc = 0x1a5ef8u;
    // NOP
    // 0x1a5efc: 0x0  nop
    ctx->pc = 0x1a5efcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
