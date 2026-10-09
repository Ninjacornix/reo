#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4AE0
// Address: 0x1d4ae0 - 0x1d4b68
void sub_001D4AE0_0x1d4ae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4AE0_0x1d4ae0");
#endif

    switch (ctx->pc) {
        case 0x1d4af4u: goto label_1d4af4;
        case 0x1d4b08u: goto label_1d4b08;
        case 0x1d4b18u: goto label_1d4b18;
        case 0x1d4b28u: goto label_1d4b28;
        case 0x1d4b30u: goto label_1d4b30;
        case 0x1d4b48u: goto label_1d4b48;
        case 0x1d4b58u: goto label_1d4b58;
        default: break;
    }

    ctx->pc = 0x1d4ae0u;

    // 0x1d4ae0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d4ae0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d4ae4: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x1d4ae4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4ae8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4ae8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d4aec: 0xc0dee54  jal         func_37B950
    ctx->pc = 0x1D4AECu;
    SET_GPR_U32(ctx, 31, 0x1D4AF4u);
    ctx->pc = 0x1D4AF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4AECu;
            // 0x1d4af0: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x37B950u;
    {
        auto targetFn = runtime->lookupFunction(0x37B950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4AF4u; }
        if (ctx->pc != 0x1D4AF4u) { return; }
    }
    ctx->pc = 0x1D4AF4u;
label_1d4af4:
    // 0x1d4af4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4af4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4af8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d4af8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4afc: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d4afcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4b00: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4B00u;
    SET_GPR_U32(ctx, 31, 0x1D4B08u);
    ctx->pc = 0x1D4B04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4B00u;
            // 0x1d4b04: 0x24a56d90  addiu       $a1, $a1, 0x6D90 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 28048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B08u; }
        if (ctx->pc != 0x1D4B08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B08u; }
        if (ctx->pc != 0x1D4B08u) { return; }
    }
    ctx->pc = 0x1D4B08u;
label_1d4b08:
    // 0x1d4b08: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d4b08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d4b0c: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d4b0cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d4b10: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1D4B10u;
    SET_GPR_U32(ctx, 31, 0x1D4B18u);
    ctx->pc = 0x1D4B14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4B10u;
            // 0x1d4b14: 0x24044010  addiu       $a0, $zero, 0x4010 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B18u; }
        if (ctx->pc != 0x1D4B18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B18u; }
        if (ctx->pc != 0x1D4B18u) { return; }
    }
    ctx->pc = 0x1D4B18u;
label_1d4b18:
    // 0x1d4b18: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D4B18u;
    {
        const bool branch_taken_0x1d4b18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4B18u;
            // 0x1d4b1c: 0x24044010  addiu       $a0, $zero, 0x4010 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4b18) {
            ctx->pc = 0x1D4B30u;
            goto label_1d4b30;
        }
    }
    ctx->pc = 0x1D4B20u;
    // 0x1d4b20: 0xc073420  jal         func_1CD080
    ctx->pc = 0x1D4B20u;
    SET_GPR_U32(ctx, 31, 0x1D4B28u);
    ctx->pc = 0x1D4B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4B20u;
            // 0x1d4b24: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD080u;
    if (runtime->hasFunction(0x1CD080u)) {
        auto targetFn = runtime->lookupFunction(0x1CD080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B28u; }
        if (ctx->pc != 0x1D4B28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B28u; }
        if (ctx->pc != 0x1D4B28u) { return; }
    }
    ctx->pc = 0x1D4B28u;
label_1d4b28:
    // 0x1d4b28: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x1D4B28u;
    SET_GPR_U32(ctx, 31, 0x1D4B30u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B30u; }
        if (ctx->pc != 0x1D4B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B30u; }
        if (ctx->pc != 0x1D4B30u) { return; }
    }
    ctx->pc = 0x1D4B30u;
label_1d4b30:
    // 0x1d4b30: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d4b30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d4b34: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d4b34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4b38: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d4b38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4b3c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d4b3cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4b40: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D4B40u;
    SET_GPR_U32(ctx, 31, 0x1D4B48u);
    ctx->pc = 0x1D4B44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4B40u;
            // 0x1d4b44: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B48u; }
        if (ctx->pc != 0x1D4B48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B48u; }
        if (ctx->pc != 0x1D4B48u) { return; }
    }
    ctx->pc = 0x1D4B48u;
label_1d4b48:
    // 0x1d4b48: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D4B48u;
    {
        const bool branch_taken_0x1d4b48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4B48u;
            // 0x1d4b4c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4b48) {
            ctx->pc = 0x1D4B58u;
            goto label_1d4b58;
        }
    }
    ctx->pc = 0x1D4B50u;
    // 0x1d4b50: 0xc0732e4  jal         func_1CCB90
    ctx->pc = 0x1D4B50u;
    SET_GPR_U32(ctx, 31, 0x1D4B58u);
    ctx->pc = 0x1D4B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4B50u;
            // 0x1d4b54: 0x24044010  addiu       $a0, $zero, 0x4010 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CCB90u;
    if (runtime->hasFunction(0x1CCB90u)) {
        auto targetFn = runtime->lookupFunction(0x1CCB90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B58u; }
        if (ctx->pc != 0x1D4B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B58u; }
        if (ctx->pc != 0x1D4B58u) { return; }
    }
    ctx->pc = 0x1D4B58u;
label_1d4b58:
    // 0x1d4b58: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4b58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4b5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4b5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4b60: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4B60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4B60u;
            // 0x1d4b64: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4AF4u: goto label_1d4af4;
            case 0x1D4B08u: goto label_1d4b08;
            case 0x1D4B18u: goto label_1d4b18;
            case 0x1D4B28u: goto label_1d4b28;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B48u: goto label_1d4b48;
            case 0x1D4B58u: goto label_1d4b58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4B68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
