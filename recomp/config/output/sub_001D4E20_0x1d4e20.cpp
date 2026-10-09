#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4E20
// Address: 0x1d4e20 - 0x1d4ef0
void sub_001D4E20_0x1d4e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4E20_0x1d4e20");
#endif

    switch (ctx->pc) {
        case 0x1d4e64u: goto label_1d4e64;
        case 0x1d4e74u: goto label_1d4e74;
        case 0x1d4e8cu: goto label_1d4e8c;
        case 0x1d4ea4u: goto label_1d4ea4;
        default: break;
    }

    ctx->pc = 0x1d4e20u;

    // 0x1d4e20: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d4e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d4e24: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4e24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4e28: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d4e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d4e2c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d4e2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d4e30: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d4e30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4e34: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d4e34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4e38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4e38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4e3c: 0x90222728  lbu         $v0, 0x2728($at)
    ctx->pc = 0x1d4e3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 10024)));
    // 0x1d4e40: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D4E40u;
    {
        const bool branch_taken_0x1d4e40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E40u;
            // 0x1d4e44: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4e40) {
            ctx->pc = 0x1D4E54u;
            goto label_1d4e54;
        }
    }
    ctx->pc = 0x1D4E48u;
    // 0x1d4e48: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1d4e48u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d4e4c: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1D4E4Cu;
    {
        const bool branch_taken_0x1d4e4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E4Cu;
            // 0x1d4e50: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4e4c) {
            ctx->pc = 0x1D4ED4u;
            goto label_1d4ed4;
        }
    }
    ctx->pc = 0x1D4E54u;
label_1d4e54:
    // 0x1d4e54: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d4e54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4e58: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d4e58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4e5c: 0xc07560c  jal         func_1D5830
    ctx->pc = 0x1D4E5Cu;
    SET_GPR_U32(ctx, 31, 0x1D4E64u);
    ctx->pc = 0x1D4E60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E5Cu;
            // 0x1d4e60: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5830u;
    if (runtime->hasFunction(0x1D5830u)) {
        auto targetFn = runtime->lookupFunction(0x1D5830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E64u; }
        if (ctx->pc != 0x1D4E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5830_0x1d5830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E64u; }
        if (ctx->pc != 0x1D4E64u) { return; }
    }
    ctx->pc = 0x1D4E64u;
label_1d4e64:
    // 0x1d4e64: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1d4e64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4e68: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d4e68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4e6c: 0xc07561e  jal         func_1D5878
    ctx->pc = 0x1D4E6Cu;
    SET_GPR_U32(ctx, 31, 0x1D4E74u);
    ctx->pc = 0x1D4E70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E6Cu;
            // 0x1d4e70: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5878u;
    if (runtime->hasFunction(0x1D5878u)) {
        auto targetFn = runtime->lookupFunction(0x1D5878u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E74u; }
        if (ctx->pc != 0x1D4E74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5878_0x1d5878(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E74u; }
        if (ctx->pc != 0x1D4E74u) { return; }
    }
    ctx->pc = 0x1D4E74u;
label_1d4e74:
    // 0x1d4e74: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1d4e74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4e78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4e78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4e7c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1d4e7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4e80: 0xac252688  sw          $a1, 0x2688($at)
    ctx->pc = 0x1d4e80u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9864), GPR_U32(ctx, 5));
    // 0x1d4e84: 0xc075632  jal         func_1D58C8
    ctx->pc = 0x1D4E84u;
    SET_GPR_U32(ctx, 31, 0x1D4E8Cu);
    ctx->pc = 0x1D4E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E84u;
            // 0x1d4e88: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D58C8u;
    if (runtime->hasFunction(0x1D58C8u)) {
        auto targetFn = runtime->lookupFunction(0x1D58C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E8Cu; }
        if (ctx->pc != 0x1D4E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D58C8_0x1d58c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E8Cu; }
        if (ctx->pc != 0x1D4E8Cu) { return; }
    }
    ctx->pc = 0x1D4E8Cu;
label_1d4e8c:
    // 0x1d4e8c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4e8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d4e90: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1d4e90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4e94: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d4e94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4e98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d4e98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4e9c: 0xc07594e  jal         func_1D6538
    ctx->pc = 0x1D4E9Cu;
    SET_GPR_U32(ctx, 31, 0x1D4EA4u);
    ctx->pc = 0x1D4EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E9Cu;
            // 0x1d4ea0: 0xac202680  sw          $zero, 0x2680($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 9856), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6538u;
    if (runtime->hasFunction(0x1D6538u)) {
        auto targetFn = runtime->lookupFunction(0x1D6538u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4EA4u; }
        if (ctx->pc != 0x1D4EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6538_0x1d6538(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4EA4u; }
        if (ctx->pc != 0x1D4EA4u) { return; }
    }
    ctx->pc = 0x1D4EA4u;
label_1d4ea4:
    // 0x1d4ea4: 0x1640000a  bnez        $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x1D4EA4u;
    {
        const bool branch_taken_0x1d4ea4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4ea4) {
            ctx->pc = 0x1D4ED0u;
            goto label_1d4ed0;
        }
    }
    ctx->pc = 0x1D4EACu;
    // 0x1d4eac: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D4EACu;
    {
        const bool branch_taken_0x1d4eac = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4eac) {
            ctx->pc = 0x1D4ED0u;
            goto label_1d4ed0;
        }
    }
    ctx->pc = 0x1D4EB4u;
    // 0x1d4eb4: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D4EB4u;
    {
        const bool branch_taken_0x1d4eb4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4eb4) {
            ctx->pc = 0x1D4ED0u;
            goto label_1d4ed0;
        }
    }
    ctx->pc = 0x1D4EBCu;
    // 0x1d4ebc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D4EBCu;
    {
        const bool branch_taken_0x1d4ebc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4ebc) {
            ctx->pc = 0x1D4ED0u;
            goto label_1d4ed0;
        }
    }
    ctx->pc = 0x1D4EC4u;
    // 0x1d4ec4: 0x82620000  lb          $v0, 0x0($s3)
    ctx->pc = 0x1d4ec4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1d4ec8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d4ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d4ecc: 0xa2620000  sb          $v0, 0x0($s3)
    ctx->pc = 0x1d4eccu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 2));
label_1d4ed0:
    // 0x1d4ed0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4ed4:
    // 0x1d4ed4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d4ed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d4ed8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d4ed8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d4edc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d4edcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4ee0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d4ee0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4ee4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4ee4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4EE8u;
            // 0x1d4eec: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
