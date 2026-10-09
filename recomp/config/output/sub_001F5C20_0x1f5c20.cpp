#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F5C20
// Address: 0x1f5c20 - 0x1f5e28
void sub_001F5C20_0x1f5c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F5C20_0x1f5c20");
#endif

    switch (ctx->pc) {
        case 0x1f5c48u: goto label_1f5c48;
        case 0x1f5c90u: goto label_1f5c90;
        case 0x1f5de0u: goto label_1f5de0;
        default: break;
    }

    ctx->pc = 0x1f5c20u;

    // 0x1f5c20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f5c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f5c24: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5c24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5c28: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f5c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f5c2c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f5c2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f5c30: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f5c30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f5c34: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f5c34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f5c38: 0x10400075  beqz        $v0, . + 4 + (0x75 << 2)
    ctx->pc = 0x1F5C38u;
    {
        const bool branch_taken_0x1f5c38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5C38u;
            // 0x1f5c3c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5c38) {
            ctx->pc = 0x1F5E10u;
            goto label_1f5e10;
        }
    }
    ctx->pc = 0x1F5C40u;
    // 0x1f5c40: 0xc07d20c  jal         func_1F4830
    ctx->pc = 0x1F5C40u;
    SET_GPR_U32(ctx, 31, 0x1F5C48u);
    ctx->pc = 0x1F4830u;
    if (runtime->hasFunction(0x1F4830u)) {
        auto targetFn = runtime->lookupFunction(0x1F4830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5C48u; }
        if (ctx->pc != 0x1F5C48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4830_0x1f4830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5C48u; }
        if (ctx->pc != 0x1F5C48u) { return; }
    }
    ctx->pc = 0x1F5C48u;
label_1f5c48:
    // 0x1f5c48: 0x3050ffff  andi        $s0, $v0, 0xFFFF
    ctx->pc = 0x1f5c48u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f5c4c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5c4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5c50: 0x9022ec10  lbu         $v0, -0x13F0($at)
    ctx->pc = 0x1f5c50u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962192)));
    // 0x1f5c54: 0x1202000c  beq         $s0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1F5C54u;
    {
        const bool branch_taken_0x1f5c54 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F5C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5C54u;
            // 0x1f5c58: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5c54) {
            ctx->pc = 0x1F5C88u;
            goto label_1f5c88;
        }
    }
    ctx->pc = 0x1F5C5Cu;
    // 0x1f5c5c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f5c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f5c60: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f5c60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f5c64: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f5c64u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f5c68: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f5c68u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f5c6c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f5c6cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5c70: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f5c70u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5c74: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f5c74u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5c78: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f5c78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5c7c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f5c7cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5c80: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f5c80u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5c84: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f5c84u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f5c88:
    // 0x1f5c88: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5C88u;
    SET_GPR_U32(ctx, 31, 0x1F5C90u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5C90u; }
        if (ctx->pc != 0x1F5C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5C90u; }
        if (ctx->pc != 0x1F5C90u) { return; }
    }
    ctx->pc = 0x1F5C90u;
label_1f5c90:
    // 0x1f5c90: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5c90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5c94: 0x8c23ec14  lw          $v1, -0x13EC($at)
    ctx->pc = 0x1f5c94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962196)));
    // 0x1f5c98: 0x1043000d  beq         $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1F5C98u;
    {
        const bool branch_taken_0x1f5c98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1F5C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5C98u;
            // 0x1f5c9c: 0x3203ffff  andi        $v1, $s0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5c98) {
            ctx->pc = 0x1F5CD0u;
            goto label_1f5cd0;
        }
    }
    ctx->pc = 0x1F5CA0u;
    // 0x1f5ca0: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1f5ca0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f5ca4: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f5ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f5ca8: 0xae24008c  sw          $a0, 0x8C($s1)
    ctx->pc = 0x1f5ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 4));
    // 0x1f5cac: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1f5cacu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f5cb0: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f5cb0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5cb4: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f5cb4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5cb8: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f5cb8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5cbc: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f5cbcu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5cc0: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f5cc0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5cc4: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f5cc4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5cc8: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f5cc8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5ccc: 0x3203ffff  andi        $v1, $s0, 0xFFFF
    ctx->pc = 0x1f5cccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
label_1f5cd0:
    // 0x1f5cd0: 0x3c050036  lui         $a1, 0x36
    ctx->pc = 0x1f5cd0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)54 << 16));
    // 0x1f5cd4: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x1f5cd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1f5cd8: 0x33080  sll         $a2, $v1, 2
    ctx->pc = 0x1f5cd8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1f5cdc: 0x24a5ebe4  addiu       $a1, $a1, -0x141C
    ctx->pc = 0x1f5cdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962148));
    // 0x1f5ce0: 0xa2240001  sb          $a0, 0x1($s1)
    ctx->pc = 0x1f5ce0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x1f5ce4: 0xa63821  addu        $a3, $a1, $a2
    ctx->pc = 0x1f5ce4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1f5ce8: 0x244802f2  addiu       $t0, $v0, 0x2F2
    ctx->pc = 0x1f5ce8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 754));
    // 0x1f5cec: 0x8ce60000  lw          $a2, 0x0($a3)
    ctx->pc = 0x1f5cecu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1f5cf0: 0x106282b  sltu        $a1, $t0, $a2
    ctx->pc = 0x1f5cf0u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x1f5cf4: 0x14a00016  bnez        $a1, . + 4 + (0x16 << 2)
    ctx->pc = 0x1F5CF4u;
    {
        const bool branch_taken_0x1f5cf4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F5CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5CF4u;
            // 0x1f5cf8: 0x640402f2  daddiu      $a0, $zero, 0x2F2 (Delay Slot)
        SET_GPR_S64(ctx, 4, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)754);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5cf4) {
            ctx->pc = 0x1F5D50u;
            goto label_1f5d50;
        }
    }
    ctx->pc = 0x1F5CFCu;
    // 0x1f5cfc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5cfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d00: 0xc22023  subu        $a0, $a2, $v0
    ctx->pc = 0x1f5d00u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1f5d04: 0xac20ec14  sw          $zero, -0x13EC($at)
    ctx->pc = 0x1f5d04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962196), GPR_U32(ctx, 0));
    // 0x1f5d08: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d0c: 0x9026ec10  lbu         $a2, -0x13F0($at)
    ctx->pc = 0x1f5d0cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962192)));
    // 0x1f5d10: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d14: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f5d14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1f5d18: 0x9425ebe0  lhu         $a1, -0x1420($at)
    ctx->pc = 0x1f5d18u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294962144)));
    // 0x1f5d1c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d20: 0xa026ec10  sb          $a2, -0x13F0($at)
    ctx->pc = 0x1f5d20u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962192), (uint8_t)GPR_U32(ctx, 6));
    // 0x1f5d24: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d28: 0x9026ec10  lbu         $a2, -0x13F0($at)
    ctx->pc = 0x1f5d28u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962192)));
    // 0x1f5d2c: 0xc5082a  slt         $at, $a2, $a1
    ctx->pc = 0x1f5d2cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1f5d30: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F5D30u;
    {
        const bool branch_taken_0x1f5d30 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5D30u;
            // 0x1f5d34: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5d30) {
            ctx->pc = 0x1F5D44u;
            goto label_1f5d44;
        }
    }
    ctx->pc = 0x1F5D38u;
    // 0x1f5d38: 0x28c50003  slti        $a1, $a2, 0x3
    ctx->pc = 0x1f5d38u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1f5d3c: 0x14a0001e  bnez        $a1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1F5D3Cu;
    {
        const bool branch_taken_0x1f5d3c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f5d3c) {
            ctx->pc = 0x1F5DB8u;
            goto label_1f5db8;
        }
    }
    ctx->pc = 0x1F5D44u;
label_1f5d44:
    // 0x1f5d44: 0x24050012  addiu       $a1, $zero, 0x12
    ctx->pc = 0x1f5d44u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1f5d48: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1F5D48u;
    {
        const bool branch_taken_0x1f5d48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5D48u;
            // 0x1f5d4c: 0xa2250001  sb          $a1, 0x1($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5d48) {
            ctx->pc = 0x1F5DB8u;
            goto label_1f5db8;
        }
    }
    ctx->pc = 0x1F5D50u;
label_1f5d50:
    // 0x1f5d50: 0x2d052000  sltiu       $a1, $t0, 0x2000
    ctx->pc = 0x1f5d50u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)(int64_t)(int32_t)8192) ? 1 : 0);
    // 0x1f5d54: 0x14a00017  bnez        $a1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1F5D54u;
    {
        const bool branch_taken_0x1f5d54 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F5D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5D54u;
            // 0x1f5d58: 0x3c010036  lui         $at, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5d54) {
            ctx->pc = 0x1F5DB4u;
            goto label_1f5db4;
        }
    }
    ctx->pc = 0x1F5D5Cu;
    // 0x1f5d5c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d60: 0x24042000  addiu       $a0, $zero, 0x2000
    ctx->pc = 0x1f5d60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1f5d64: 0xac20ec14  sw          $zero, -0x13EC($at)
    ctx->pc = 0x1f5d64u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962196), GPR_U32(ctx, 0));
    // 0x1f5d68: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x1f5d68u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1f5d6c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d70: 0x9026ec10  lbu         $a2, -0x13F0($at)
    ctx->pc = 0x1f5d70u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962192)));
    // 0x1f5d74: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d78: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f5d78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1f5d7c: 0x9425ebe0  lhu         $a1, -0x1420($at)
    ctx->pc = 0x1f5d7cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294962144)));
    // 0x1f5d80: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d84: 0xa026ec10  sb          $a2, -0x13F0($at)
    ctx->pc = 0x1f5d84u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294962192), (uint8_t)GPR_U32(ctx, 6));
    // 0x1f5d88: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5d88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5d8c: 0x9026ec10  lbu         $a2, -0x13F0($at)
    ctx->pc = 0x1f5d8cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962192)));
    // 0x1f5d90: 0xc5082a  slt         $at, $a2, $a1
    ctx->pc = 0x1f5d90u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1f5d94: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F5D94u;
    {
        const bool branch_taken_0x1f5d94 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5D94u;
            // 0x1f5d98: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5d94) {
            ctx->pc = 0x1F5DA8u;
            goto label_1f5da8;
        }
    }
    ctx->pc = 0x1F5D9Cu;
    // 0x1f5d9c: 0x28c50003  slti        $a1, $a2, 0x3
    ctx->pc = 0x1f5d9cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1f5da0: 0x14a00005  bnez        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F5DA0u;
    {
        const bool branch_taken_0x1f5da0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f5da0) {
            ctx->pc = 0x1F5DB8u;
            goto label_1f5db8;
        }
    }
    ctx->pc = 0x1F5DA8u;
label_1f5da8:
    // 0x1f5da8: 0x24050012  addiu       $a1, $zero, 0x12
    ctx->pc = 0x1f5da8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1f5dac: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F5DACu;
    {
        const bool branch_taken_0x1f5dac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5DB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5DACu;
            // 0x1f5db0: 0xa2250001  sb          $a1, 0x1($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5dac) {
            ctx->pc = 0x1F5DB8u;
            goto label_1f5db8;
        }
    }
    ctx->pc = 0x1F5DB4u;
label_1f5db4:
    // 0x1f5db4: 0xac28ec14  sw          $t0, -0x13EC($at)
    ctx->pc = 0x1f5db4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294962196), GPR_U32(ctx, 8));
label_1f5db8:
    // 0x1f5db8: 0x8ce50000  lw          $a1, 0x0($a3)
    ctx->pc = 0x1f5db8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1f5dbc: 0x10a00014  beqz        $a1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F5DBCu;
    {
        const bool branch_taken_0x1f5dbc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5DC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5DBCu;
            // 0x1f5dc0: 0x32b40  sll         $a1, $v1, 13 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5dbc) {
            ctx->pc = 0x1F5E10u;
            goto label_1f5e10;
        }
    }
    ctx->pc = 0x1F5DC4u;
    // 0x1f5dc4: 0x3086ffff  andi        $a2, $a0, 0xFFFF
    ctx->pc = 0x1f5dc4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1f5dc8: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1f5dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1f5dcc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f5dccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5dd0: 0x24637ad0  addiu       $v1, $v1, 0x7AD0
    ctx->pc = 0x1f5dd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 31440));
    // 0x1f5dd4: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1f5dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1f5dd8: 0xc07d244  jal         func_1F4910
    ctx->pc = 0x1F5DD8u;
    SET_GPR_U32(ctx, 31, 0x1F5DE0u);
    ctx->pc = 0x1F5DDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5DD8u;
            // 0x1f5ddc: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4910u;
    if (runtime->hasFunction(0x1F4910u)) {
        auto targetFn = runtime->lookupFunction(0x1F4910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5DE0u; }
        if (ctx->pc != 0x1F5DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4910_0x1f4910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5DE0u; }
        if (ctx->pc != 0x1F5DE0u) { return; }
    }
    ctx->pc = 0x1F5DE0u;
label_1f5de0:
    // 0x1f5de0: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F5DE0u;
    {
        const bool branch_taken_0x1f5de0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F5DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5DE0u;
            // 0x1f5de4: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5de0) {
            ctx->pc = 0x1F5E10u;
            goto label_1f5e10;
        }
    }
    ctx->pc = 0x1F5DE8u;
    // 0x1f5de8: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f5de8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f5dec: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f5decu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f5df0: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f5df0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f5df4: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f5df4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5df8: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f5df8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5dfc: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f5dfcu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f5e00: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f5e00u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5e04: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f5e04u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5e08: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f5e08u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f5e0c: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f5e0cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f5e10:
    // 0x1f5e10: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f5e10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f5e14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f5e14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5e18: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f5e18u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f5e1c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f5e1cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f5e20: 0x3e00008  jr          $ra
    ctx->pc = 0x1F5E20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F5E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5E20u;
            // 0x1f5e24: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F5C48u: goto label_1f5c48;
            case 0x1F5C88u: goto label_1f5c88;
            case 0x1F5C90u: goto label_1f5c90;
            case 0x1F5CD0u: goto label_1f5cd0;
            case 0x1F5D44u: goto label_1f5d44;
            case 0x1F5D50u: goto label_1f5d50;
            case 0x1F5DA8u: goto label_1f5da8;
            case 0x1F5DB4u: goto label_1f5db4;
            case 0x1F5DB8u: goto label_1f5db8;
            case 0x1F5DE0u: goto label_1f5de0;
            case 0x1F5E10u: goto label_1f5e10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F5E28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
