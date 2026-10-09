#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1F10
// Address: 0x1b1f10 - 0x1b2020
void sub_001B1F10_0x1b1f10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1F10_0x1b1f10");
#endif

    switch (ctx->pc) {
        case 0x1b1f28u: goto label_1b1f28;
        case 0x1b1f44u: goto label_1b1f44;
        case 0x1b1f50u: goto label_1b1f50;
        case 0x1b1f80u: goto label_1b1f80;
        case 0x1b1f94u: goto label_1b1f94;
        case 0x1b1fc4u: goto label_1b1fc4;
        case 0x1b1fe8u: goto label_1b1fe8;
        default: break;
    }

    ctx->pc = 0x1b1f10u;

    // 0x1b1f10: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b1f10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b1f14: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b1f14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b1f18: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b1f18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b1f1c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b1f1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b1f20: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1b1f20u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1f24: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b1f24u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_1b1f28:
    // 0x1b1f28: 0x24020c84  addiu       $v0, $zero, 0xC84
    ctx->pc = 0x1b1f28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3204));
    // 0x1b1f2c: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b1f2cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1f30: 0x2421818  mult        $v1, $s2, $v0
    ctx->pc = 0x1b1f30u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1b1f34: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1b1f34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1b1f38: 0x2442ec30  addiu       $v0, $v0, -0x13D0
    ctx->pc = 0x1b1f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962224));
    // 0x1b1f3c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B1F3Cu;
    {
        const bool branch_taken_0x1b1f3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1F3Cu;
            // 0x1b1f40: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1f3c) {
            ctx->pc = 0x1B1F60u;
            goto label_1b1f60;
        }
    }
    ctx->pc = 0x1B1F44u;
label_1b1f44:
    // 0x1b1f44: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1b1f44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1b1f48: 0xc073ea8  jal         func_1CFAA0
    ctx->pc = 0x1B1F48u;
    SET_GPR_U32(ctx, 31, 0x1B1F50u);
    ctx->pc = 0x1B1F4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1F48u;
            // 0x1b1f4c: 0x94440004  lhu         $a0, 0x4($v0) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CFAA0u;
    if (runtime->hasFunction(0x1CFAA0u)) {
        auto targetFn = runtime->lookupFunction(0x1CFAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1F50u; }
        if (ctx->pc != 0x1B1F50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CFAA0_0x1cfaa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1F50u; }
        if (ctx->pc != 0x1B1F50u) { return; }
    }
    ctx->pc = 0x1B1F50u;
label_1b1f50:
    // 0x1b1f50: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b1f50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b1f54: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B1F54u;
    {
        const bool branch_taken_0x1b1f54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b1f54) {
            ctx->pc = 0x1B1F6Cu;
            goto label_1b1f6c;
        }
    }
    ctx->pc = 0x1B1F5Cu;
    // 0x1b1f5c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b1f5cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b1f60:
    // 0x1b1f60: 0x2a220640  slti        $v0, $s1, 0x640
    ctx->pc = 0x1b1f60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)1600) ? 1 : 0);
    // 0x1b1f64: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1B1F64u;
    {
        const bool branch_taken_0x1b1f64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B1F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1F64u;
            // 0x1b1f68: 0x111040  sll         $v0, $s1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1f64) {
            ctx->pc = 0x1B1F44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1f44;
        }
    }
    ctx->pc = 0x1B1F6Cu;
label_1b1f6c:
    // 0x1b1f6c: 0x24020640  addiu       $v0, $zero, 0x640
    ctx->pc = 0x1b1f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1600));
    // 0x1b1f70: 0x16220005  bne         $s1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B1F70u;
    {
        const bool branch_taken_0x1b1f70 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B1F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1F70u;
            // 0x1b1f74: 0x26040004  addiu       $a0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1f70) {
            ctx->pc = 0x1B1F88u;
            goto label_1b1f88;
        }
    }
    ctx->pc = 0x1B1F78u;
    // 0x1b1f78: 0xc06c6ec  jal         func_1B1BB0
    ctx->pc = 0x1B1F78u;
    SET_GPR_U32(ctx, 31, 0x1B1F80u);
    ctx->pc = 0x1B1F7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1F78u;
            // 0x1b1f7c: 0x26040004  addiu       $a0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BB0u;
    if (runtime->hasFunction(0x1B1BB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1F80u; }
        if (ctx->pc != 0x1B1F80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BB0_0x1b1bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1F80u; }
        if (ctx->pc != 0x1B1F80u) { return; }
    }
    ctx->pc = 0x1B1F80u;
label_1b1f80:
    // 0x1b1f80: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B1F80u;
    {
        const bool branch_taken_0x1b1f80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1F80u;
            // 0x1b1f84: 0x121180  sll         $v0, $s2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1f80) {
            ctx->pc = 0x1B1F98u;
            goto label_1b1f98;
        }
    }
    ctx->pc = 0x1B1F88u;
label_1b1f88:
    // 0x1b1f88: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1f88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1f8c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B1F8Cu;
    SET_GPR_U32(ctx, 31, 0x1B1F94u);
    ctx->pc = 0x1B1F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1F8Cu;
            // 0x1b1f90: 0x24060c80  addiu       $a2, $zero, 0xC80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1F94u; }
        if (ctx->pc != 0x1B1F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1F94u; }
        if (ctx->pc != 0x1B1F94u) { return; }
    }
    ctx->pc = 0x1B1F94u;
label_1b1f94:
    // 0x1b1f94: 0x121180  sll         $v0, $s2, 6
    ctx->pc = 0x1b1f94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 6));
label_1b1f98:
    // 0x1b1f98: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1b1f98u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1f9c: 0x521023  subu        $v0, $v0, $s2
    ctx->pc = 0x1b1f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1b1fa0: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1b1fa0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1fa4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1b1fa4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1b1fa8: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1b1fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1b1fac: 0x721823  subu        $v1, $v1, $s2
    ctx->pc = 0x1b1facu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x1b1fb0: 0x2442d4a0  addiu       $v0, $v0, -0x2B60
    ctx->pc = 0x1b1fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956192));
    // 0x1b1fb4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b1fb4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b1fb8: 0x438021  addu        $s0, $v0, $v1
    ctx->pc = 0x1b1fb8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b1fbc: 0xc06c704  jal         func_1B1C10
    ctx->pc = 0x1B1FBCu;
    SET_GPR_U32(ctx, 31, 0x1B1FC4u);
    ctx->pc = 0x1B1FC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1FBCu;
            // 0x1b1fc0: 0x26040004  addiu       $a0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1C10u;
    if (runtime->hasFunction(0x1B1C10u)) {
        auto targetFn = runtime->lookupFunction(0x1B1C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1FC4u; }
        if (ctx->pc != 0x1B1FC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1C10_0x1b1c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1FC4u; }
        if (ctx->pc != 0x1B1FC4u) { return; }
    }
    ctx->pc = 0x1B1FC4u;
label_1b1fc4:
    // 0x1b1fc4: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1b1fc4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1b1fc8: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1b1fc8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1fcc: 0x2a430006  slti        $v1, $s2, 0x6
    ctx->pc = 0x1b1fccu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1b1fd0: 0x1460ffd5  bnez        $v1, . + 4 + (-0x2B << 2)
    ctx->pc = 0x1B1FD0u;
    {
        const bool branch_taken_0x1b1fd0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B1FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1FD0u;
            // 0x1b1fd4: 0xa2000001  sb          $zero, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1fd0) {
            ctx->pc = 0x1B1F28u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1f28;
        }
    }
    ctx->pc = 0x1B1FD8u;
    // 0x1b1fd8: 0x2406003d  addiu       $a2, $zero, 0x3D
    ctx->pc = 0x1b1fd8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
    // 0x1b1fdc: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b1fdcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b1fe0: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1b1fe0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b1fe4: 0x2484aeb0  addiu       $a0, $a0, -0x5150
    ctx->pc = 0x1b1fe4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946480));
label_1b1fe8:
    // 0x1b1fe8: 0x861821  addu        $v1, $a0, $a2
    ctx->pc = 0x1b1fe8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1b1fec: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1b1fecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1b1ff0: 0xa0650000  sb          $a1, 0x0($v1)
    ctx->pc = 0x1b1ff0u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1b1ff4: 0x0  nop
    ctx->pc = 0x1b1ff4u;
    // NOP
    // 0x1b1ff8: 0x0  nop
    ctx->pc = 0x1b1ff8u;
    // NOP
    // 0x1b1ffc: 0x4c1fffa  bgez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B1FFCu;
    {
        const bool branch_taken_0x1b1ffc = (GPR_S64(ctx, 6) >= 0);
        if (branch_taken_0x1b1ffc) {
            ctx->pc = 0x1B1FE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1fe8;
        }
    }
    ctx->pc = 0x1B2004u;
    // 0x1b2004: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b2004u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b2008: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b2008u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b200c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b200cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2010: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b2010u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2014: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2014u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2014u;
            // 0x1b2018: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1F28u: goto label_1b1f28;
            case 0x1B1F44u: goto label_1b1f44;
            case 0x1B1F50u: goto label_1b1f50;
            case 0x1B1F60u: goto label_1b1f60;
            case 0x1B1F6Cu: goto label_1b1f6c;
            case 0x1B1F80u: goto label_1b1f80;
            case 0x1B1F88u: goto label_1b1f88;
            case 0x1B1F94u: goto label_1b1f94;
            case 0x1B1F98u: goto label_1b1f98;
            case 0x1B1FC4u: goto label_1b1fc4;
            case 0x1B1FE8u: goto label_1b1fe8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B201Cu;
    // 0x1b201c: 0x0  nop
    ctx->pc = 0x1b201cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
