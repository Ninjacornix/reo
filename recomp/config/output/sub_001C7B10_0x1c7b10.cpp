#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7B10
// Address: 0x1c7b10 - 0x1c7bc0
void sub_001C7B10_0x1c7b10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7B10_0x1c7b10");
#endif

    switch (ctx->pc) {
        case 0x1c7b38u: goto label_1c7b38;
        case 0x1c7b48u: goto label_1c7b48;
        case 0x1c7b58u: goto label_1c7b58;
        case 0x1c7b68u: goto label_1c7b68;
        default: break;
    }

    ctx->pc = 0x1c7b10u;

    // 0x1c7b10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c7b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c7b14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c7b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c7b18: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c7b18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c7b1c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7b1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7b20: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c7b20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7b24: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1c7b24u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7b28: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7b28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7b2c: 0x24842f90  addiu       $a0, $a0, 0x2F90
    ctx->pc = 0x1c7b2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
    // 0x1c7b30: 0xc071f54  jal         func_1C7D50
    ctx->pc = 0x1C7B30u;
    SET_GPR_U32(ctx, 31, 0x1C7B38u);
    ctx->pc = 0x1C7B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B30u;
            // 0x1c7b34: 0x3405f003  ori         $a1, $zero, 0xF003 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)61443);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D50u;
    if (runtime->hasFunction(0x1C7D50u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7B38u; }
        if (ctx->pc != 0x1C7B38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D50_0x1c7d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7B38u; }
        if (ctx->pc != 0x1C7B38u) { return; }
    }
    ctx->pc = 0x1C7B38u;
label_1c7b38:
    // 0x1c7b38: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7b38u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7b3c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c7b3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c7b40: 0xc071f58  jal         func_1C7D60
    ctx->pc = 0x1C7B40u;
    SET_GPR_U32(ctx, 31, 0x1C7B48u);
    ctx->pc = 0x1C7B44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B40u;
            // 0x1c7b44: 0x24842f90  addiu       $a0, $a0, 0x2F90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D60u;
    if (runtime->hasFunction(0x1C7D60u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7B48u; }
        if (ctx->pc != 0x1C7B48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D60_0x1c7d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7B48u; }
        if (ctx->pc != 0x1C7B48u) { return; }
    }
    ctx->pc = 0x1C7B48u;
label_1c7b48:
    // 0x1c7b48: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7b48u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7b4c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1c7b4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7b50: 0xc071f58  jal         func_1C7D60
    ctx->pc = 0x1C7B50u;
    SET_GPR_U32(ctx, 31, 0x1C7B58u);
    ctx->pc = 0x1C7B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B50u;
            // 0x1c7b54: 0x24842f90  addiu       $a0, $a0, 0x2F90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D60u;
    if (runtime->hasFunction(0x1C7D60u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7B58u; }
        if (ctx->pc != 0x1C7B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D60_0x1c7d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7B58u; }
        if (ctx->pc != 0x1C7B58u) { return; }
    }
    ctx->pc = 0x1C7B58u;
label_1c7b58:
    // 0x1c7b58: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1c7b58u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1c7b5c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1c7b5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c7b60: 0xc071f58  jal         func_1C7D60
    ctx->pc = 0x1C7B60u;
    SET_GPR_U32(ctx, 31, 0x1C7B68u);
    ctx->pc = 0x1C7B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B60u;
            // 0x1c7b64: 0x24842f90  addiu       $a0, $a0, 0x2F90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7D60u;
    if (runtime->hasFunction(0x1C7D60u)) {
        auto targetFn = runtime->lookupFunction(0x1C7D60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7B68u; }
        if (ctx->pc != 0x1C7B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7D60_0x1c7d60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7B68u; }
        if (ctx->pc != 0x1C7B68u) { return; }
    }
    ctx->pc = 0x1C7B68u;
label_1c7b68:
    // 0x1c7b68: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c7b68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c7b6c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c7b6cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c7b70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c7b70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c7b74: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7B74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B74u;
            // 0x1c7b78: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7B38u: goto label_1c7b38;
            case 0x1C7B48u: goto label_1c7b48;
            case 0x1C7B58u: goto label_1c7b58;
            case 0x1C7B68u: goto label_1c7b68;
            case 0x1C7B9Cu: goto label_1c7b9c;
            case 0x1C7BACu: goto label_1c7bac;
            case 0x1C7BB4u: goto label_1c7bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7B7Cu;
    // 0x1c7b7c: 0x0  nop
    ctx->pc = 0x1c7b7cu;
    // NOP
    // 0x1c7b80: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7b80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7b84: 0x8c2351b4  lw          $v1, 0x51B4($at)
    ctx->pc = 0x1c7b84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20916)));
    // 0x1c7b88: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C7B88u;
    {
        const bool branch_taken_0x1c7b88 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B88u;
            // 0x1c7b8c: 0x3c010033  lui         $at, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7b88) {
            ctx->pc = 0x1C7B9Cu;
            goto label_1c7b9c;
        }
    }
    ctx->pc = 0x1C7B90u;
    // 0x1c7b90: 0x8c2251b0  lw          $v0, 0x51B0($at)
    ctx->pc = 0x1c7b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20912)));
    // 0x1c7b94: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C7B94u;
    {
        const bool branch_taken_0x1c7b94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B94u;
            // 0x1c7b98: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7b94) {
            ctx->pc = 0x1C7BB4u;
            goto label_1c7bb4;
        }
    }
    ctx->pc = 0x1C7B9Cu;
label_1c7b9c:
    // 0x1c7b9c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C7B9Cu;
    {
        const bool branch_taken_0x1c7b9c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B9Cu;
            // 0x1c7ba0: 0x3c010033  lui         $at, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7b9c) {
            ctx->pc = 0x1C7BACu;
            goto label_1c7bac;
        }
    }
    ctx->pc = 0x1C7BA4u;
    // 0x1c7ba4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C7BA4u;
    {
        const bool branch_taken_0x1c7ba4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7BA4u;
            // 0x1c7ba8: 0x2462037a  addiu       $v0, $v1, 0x37A (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 890));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7ba4) {
            ctx->pc = 0x1C7BB4u;
            goto label_1c7bb4;
        }
    }
    ctx->pc = 0x1C7BACu;
label_1c7bac:
    // 0x1c7bac: 0x8c2251b0  lw          $v0, 0x51B0($at)
    ctx->pc = 0x1c7bacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20912)));
    // 0x1c7bb0: 0x24420352  addiu       $v0, $v0, 0x352
    ctx->pc = 0x1c7bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 850));
label_1c7bb4:
    // 0x1c7bb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7BB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7B38u: goto label_1c7b38;
            case 0x1C7B48u: goto label_1c7b48;
            case 0x1C7B58u: goto label_1c7b58;
            case 0x1C7B68u: goto label_1c7b68;
            case 0x1C7B9Cu: goto label_1c7b9c;
            case 0x1C7BACu: goto label_1c7bac;
            case 0x1C7BB4u: goto label_1c7bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7BBCu;
    // 0x1c7bbc: 0x0  nop
    ctx->pc = 0x1c7bbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
