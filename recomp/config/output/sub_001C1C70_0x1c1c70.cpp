#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1C70
// Address: 0x1c1c70 - 0x1c1ea0
void sub_001C1C70_0x1c1c70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1C70_0x1c1c70");
#endif

    switch (ctx->pc) {
        case 0x1c1c8cu: goto label_1c1c8c;
        case 0x1c1c94u: goto label_1c1c94;
        case 0x1c1d40u: goto label_1c1d40;
        case 0x1c1d70u: goto label_1c1d70;
        default: break;
    }

    ctx->pc = 0x1c1c70u;

    // 0x1c1c70: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c1c70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c1c74: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c1c74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c1c78: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c1c78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c1c7c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c1c7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c1c80: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c1c80u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1c84: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1C1C84u;
    SET_GPR_U32(ctx, 31, 0x1C1C8Cu);
    ctx->pc = 0x1C1C88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1C84u;
            // 0x1c1c88: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1C8Cu; }
        if (ctx->pc != 0x1C1C8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1C8Cu; }
        if (ctx->pc != 0x1C1C8Cu) { return; }
    }
    ctx->pc = 0x1C1C8Cu;
label_1c1c8c:
    // 0x1c1c8c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C1C8Cu;
    {
        const bool branch_taken_0x1c1c8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1C8Cu;
            // 0x1c1c90: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1c8c) {
            ctx->pc = 0x1C1CB4u;
            goto label_1c1cb4;
        }
    }
    ctx->pc = 0x1C1C94u;
label_1c1c94:
    // 0x1c1c94: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1c1c94u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c1c98: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C1C98u;
    {
        const bool branch_taken_0x1c1c98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1c98) {
            ctx->pc = 0x1C1CC0u;
            goto label_1c1cc0;
        }
    }
    ctx->pc = 0x1C1CA0u;
    // 0x1c1ca0: 0x386300ff  xori        $v1, $v1, 0xFF
    ctx->pc = 0x1c1ca0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)255);
    // 0x1c1ca4: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1c1ca4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1c1ca8: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1c1ca8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c1cac: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1c1cacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1c1cb0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1c1cb0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1c1cb4:
    // 0x1c1cb4: 0x82182a  slt         $v1, $a0, $v0
    ctx->pc = 0x1c1cb4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c1cb8: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1C1CB8u;
    {
        const bool branch_taken_0x1c1cb8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c1cb8) {
            ctx->pc = 0x1C1C94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c1c94;
        }
    }
    ctx->pc = 0x1C1CC0u;
label_1c1cc0:
    // 0x1c1cc0: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1c1cc0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c1cc4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c1cc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c1cc8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c1cc8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1ccc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1cccu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1cd0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1CD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1CD0u;
            // 0x1c1cd4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1CD8u;
    // 0x1c1cd8: 0x0  nop
    ctx->pc = 0x1c1cd8u;
    // NOP
    // 0x1c1cdc: 0x0  nop
    ctx->pc = 0x1c1cdcu;
    // NOP
    // 0x1c1ce0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1ce4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1ce8: 0x244252f0  addiu       $v0, $v0, 0x52F0
    ctx->pc = 0x1c1ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21232));
    // 0x1c1cec: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1cecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1cf0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1CF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1CF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1CF0u;
            // 0x1c1cf4: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1CF8u;
    // 0x1c1cf8: 0x0  nop
    ctx->pc = 0x1c1cf8u;
    // NOP
    // 0x1c1cfc: 0x0  nop
    ctx->pc = 0x1c1cfcu;
    // NOP
    // 0x1c1d00: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1c1d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1c1d04: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c1d04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c1d08: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1c1d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1c1d0c: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x1c1d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1c1d10: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c1d10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c1d14: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c1d14u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c1d18: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c1d18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c1d1c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c1d1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c1d20: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1c1d20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1d24: 0x8c33443c  lw          $s3, 0x443C($at)
    ctx->pc = 0x1c1d24u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17468)));
    // 0x1c1d28: 0x26630004  addiu       $v1, $s3, 0x4
    ctx->pc = 0x1c1d28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1c1d2c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1c1d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c1d30: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1c1d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1c1d34: 0x8c700004  lw          $s0, 0x4($v1)
    ctx->pc = 0x1c1d34u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1c1d38: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1C1D38u;
    {
        const bool branch_taken_0x1c1d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1D38u;
            // 0x1c1d3c: 0x2629021  addu        $s2, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1d38) {
            ctx->pc = 0x1C1D74u;
            goto label_1c1d74;
        }
    }
    ctx->pc = 0x1C1D40u;
label_1c1d40:
    // 0x1c1d40: 0x1118c0  sll         $v1, $s1, 3
    ctx->pc = 0x1c1d40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1c1d44: 0x2421021  addu        $v0, $s2, $v0
    ctx->pc = 0x1c1d44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1c1d48: 0x711823  subu        $v1, $v1, $s1
    ctx->pc = 0x1c1d48u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1c1d4c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c1d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c1d50: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c1d50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c1d54: 0x2466017c  addiu       $a2, $v1, 0x17C
    ctx->pc = 0x1c1d54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 380));
    // 0x1c1d58: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1c1d58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1d5c: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1c1d5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1c1d60: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1c1d60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1d64: 0x24080018  addiu       $t0, $zero, 0x18
    ctx->pc = 0x1c1d64u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1c1d68: 0xc06d208  jal         func_1B4820
    ctx->pc = 0x1C1D68u;
    SET_GPR_U32(ctx, 31, 0x1C1D70u);
    ctx->pc = 0x1C1D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1D68u;
            // 0x1c1d6c: 0x2624821  addu        $t1, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B4820u;
    if (runtime->hasFunction(0x1B4820u)) {
        auto targetFn = runtime->lookupFunction(0x1B4820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1D70u; }
        if (ctx->pc != 0x1C1D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4820_0x1b4820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1D70u; }
        if (ctx->pc != 0x1C1D70u) { return; }
    }
    ctx->pc = 0x1C1D70u;
label_1c1d70:
    // 0x1c1d70: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1c1d70u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1c1d74:
    // 0x1c1d74: 0x230102a  slt         $v0, $s1, $s0
    ctx->pc = 0x1c1d74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1c1d78: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
    ctx->pc = 0x1C1D78u;
    {
        const bool branch_taken_0x1c1d78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1D78u;
            // 0x1c1d7c: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1d78) {
            ctx->pc = 0x1C1D40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c1d40;
        }
    }
    ctx->pc = 0x1C1D80u;
    // 0x1c1d80: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x1c1d80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1d84: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1c1d84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c1d88: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c1d88u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c1d8c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c1d8cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c1d90: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c1d90u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1d94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1d94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1d98: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1D98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1D98u;
            // 0x1c1d9c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1DA0u;
    // 0x1c1da0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1da0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1da4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1da4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1da8: 0x24425378  addiu       $v0, $v0, 0x5378
    ctx->pc = 0x1c1da8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21368));
    // 0x1c1dac: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1dacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1db0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1DB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1DB0u;
            // 0x1c1db4: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1DB8u;
    // 0x1c1db8: 0x0  nop
    ctx->pc = 0x1c1db8u;
    // NOP
    // 0x1c1dbc: 0x0  nop
    ctx->pc = 0x1c1dbcu;
    // NOP
    // 0x1c1dc0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1dc4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1dc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1dc8: 0x24425380  addiu       $v0, $v0, 0x5380
    ctx->pc = 0x1c1dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21376));
    // 0x1c1dcc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1dccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1dd0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1DD0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1DD0u;
            // 0x1c1dd4: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1DD8u;
    // 0x1c1dd8: 0x0  nop
    ctx->pc = 0x1c1dd8u;
    // NOP
    // 0x1c1ddc: 0x0  nop
    ctx->pc = 0x1c1ddcu;
    // NOP
    // 0x1c1de0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1de0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1de4: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1de4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1de8: 0x244253f0  addiu       $v0, $v0, 0x53F0
    ctx->pc = 0x1c1de8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21488));
    // 0x1c1dec: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1decu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1df0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1DF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1DF0u;
            // 0x1c1df4: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1DF8u;
    // 0x1c1df8: 0x0  nop
    ctx->pc = 0x1c1df8u;
    // NOP
    // 0x1c1dfc: 0x0  nop
    ctx->pc = 0x1c1dfcu;
    // NOP
    // 0x1c1e00: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1e00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1e04: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1e04u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1e08: 0x24425428  addiu       $v0, $v0, 0x5428
    ctx->pc = 0x1c1e08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21544));
    // 0x1c1e0c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1e10: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1E10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1E10u;
            // 0x1c1e14: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1E18u;
    // 0x1c1e18: 0x0  nop
    ctx->pc = 0x1c1e18u;
    // NOP
    // 0x1c1e1c: 0x0  nop
    ctx->pc = 0x1c1e1cu;
    // NOP
    // 0x1c1e20: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1e20u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1e24: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1e24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1e28: 0x24425430  addiu       $v0, $v0, 0x5430
    ctx->pc = 0x1c1e28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21552));
    // 0x1c1e2c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1e30: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1E30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1E30u;
            // 0x1c1e34: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1E38u;
    // 0x1c1e38: 0x0  nop
    ctx->pc = 0x1c1e38u;
    // NOP
    // 0x1c1e3c: 0x0  nop
    ctx->pc = 0x1c1e3cu;
    // NOP
    // 0x1c1e40: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C1E40u;
    {
        const bool branch_taken_0x1c1e40 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1C1E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1E40u;
            // 0x1c1e44: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1e40) {
            ctx->pc = 0x1C1E58u;
            goto label_1c1e58;
        }
    }
    ctx->pc = 0x1C1E48u;
    // 0x1c1e48: 0x2882005a  slti        $v0, $a0, 0x5A
    ctx->pc = 0x1c1e48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)90) ? 1 : 0);
    // 0x1c1e4c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C1E4Cu;
    {
        const bool branch_taken_0x1c1e4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1E4Cu;
            // 0x1c1e50: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1e4c) {
            ctx->pc = 0x1C1E60u;
            goto label_1c1e60;
        }
    }
    ctx->pc = 0x1C1E54u;
    // 0x1c1e54: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c1e54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c1e58:
    // 0x1c1e58: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C1E58u;
    {
        const bool branch_taken_0x1c1e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c1e58) {
            ctx->pc = 0x1C1E70u;
            goto label_1c1e70;
        }
    }
    ctx->pc = 0x1C1E60u;
label_1c1e60:
    // 0x1c1e60: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1e60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1e64: 0x24425d20  addiu       $v0, $v0, 0x5D20
    ctx->pc = 0x1c1e64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23840));
    // 0x1c1e68: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1e68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1e6c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c1e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1c1e70:
    // 0x1c1e70: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1E70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1E78u;
    // 0x1c1e78: 0x0  nop
    ctx->pc = 0x1c1e78u;
    // NOP
    // 0x1c1e7c: 0x0  nop
    ctx->pc = 0x1c1e7cu;
    // NOP
    // 0x1c1e80: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1e80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c1e84: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c1e84u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c1e88: 0x24425450  addiu       $v0, $v0, 0x5450
    ctx->pc = 0x1c1e88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21584));
    // 0x1c1e8c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c1e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c1e90: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1E90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1E90u;
            // 0x1c1e94: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1C8Cu: goto label_1c1c8c;
            case 0x1C1C94u: goto label_1c1c94;
            case 0x1C1CB4u: goto label_1c1cb4;
            case 0x1C1CC0u: goto label_1c1cc0;
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            case 0x1C1E58u: goto label_1c1e58;
            case 0x1C1E60u: goto label_1c1e60;
            case 0x1C1E70u: goto label_1c1e70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1E98u;
    // 0x1c1e98: 0x0  nop
    ctx->pc = 0x1c1e98u;
    // NOP
    // 0x1c1e9c: 0x0  nop
    ctx->pc = 0x1c1e9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
