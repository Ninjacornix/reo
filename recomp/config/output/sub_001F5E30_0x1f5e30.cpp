#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F5E30
// Address: 0x1f5e30 - 0x1f5f70
void sub_001F5E30_0x1f5e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F5E30_0x1f5e30");
#endif

    switch (ctx->pc) {
        case 0x1f5e54u: goto label_1f5e54;
        case 0x1f5e78u: goto label_1f5e78;
        case 0x1f5e84u: goto label_1f5e84;
        case 0x1f5ea8u: goto label_1f5ea8;
        case 0x1f5eb4u: goto label_1f5eb4;
        case 0x1f5ed8u: goto label_1f5ed8;
        case 0x1f5ee4u: goto label_1f5ee4;
        case 0x1f5eecu: goto label_1f5eec;
        case 0x1f5ef4u: goto label_1f5ef4;
        case 0x1f5efcu: goto label_1f5efc;
        case 0x1f5f04u: goto label_1f5f04;
        case 0x1f5f0cu: goto label_1f5f0c;
        case 0x1f5f14u: goto label_1f5f14;
        case 0x1f5f1cu: goto label_1f5f1c;
        case 0x1f5f24u: goto label_1f5f24;
        case 0x1f5f2cu: goto label_1f5f2c;
        case 0x1f5f34u: goto label_1f5f34;
        case 0x1f5f3cu: goto label_1f5f3c;
        case 0x1f5f44u: goto label_1f5f44;
        case 0x1f5f4cu: goto label_1f5f4c;
        default: break;
    }

    ctx->pc = 0x1f5e30u;

    // 0x1f5e30: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f5e30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f5e34: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f5e34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f5e38: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f5e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f5e3c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f5e3cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f5e40: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f5e40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f5e44: 0x10400045  beqz        $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1F5E44u;
    {
        const bool branch_taken_0x1f5e44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5E44u;
            // 0x1f5e48: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5e44) {
            ctx->pc = 0x1F5F5Cu;
            goto label_1f5f5c;
        }
    }
    ctx->pc = 0x1F5E4Cu;
    // 0x1f5e4c: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5E4Cu;
    SET_GPR_U32(ctx, 31, 0x1F5E54u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5E54u; }
        if (ctx->pc != 0x1F5E54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5E54u; }
        if (ctx->pc != 0x1F5E54u) { return; }
    }
    ctx->pc = 0x1F5E54u;
label_1f5e54:
    // 0x1f5e54: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1f5e54u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1f5e58: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1f5e58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1f5e5c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F5E5Cu;
    {
        const bool branch_taken_0x1f5e5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5E5Cu;
            // 0x1f5e60: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5e5c) {
            ctx->pc = 0x1F5E7Cu;
            goto label_1f5e7c;
        }
    }
    ctx->pc = 0x1F5E64u;
    // 0x1f5e64: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1f5e64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1f5e68: 0x27a5002c  addiu       $a1, $sp, 0x2C
    ctx->pc = 0x1f5e68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    // 0x1f5e6c: 0x24845f50  addiu       $a0, $a0, 0x5F50
    ctx->pc = 0x1f5e6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24400));
    // 0x1f5e70: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F5E70u;
    SET_GPR_U32(ctx, 31, 0x1F5E78u);
    ctx->pc = 0x1F5E74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5E70u;
            // 0x1f5e74: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5E78u; }
        if (ctx->pc != 0x1F5E78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5E78u; }
        if (ctx->pc != 0x1F5E78u) { return; }
    }
    ctx->pc = 0x1F5E78u;
label_1f5e78:
    // 0x1f5e78: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f5e78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1f5e7c:
    // 0x1f5e7c: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5E7Cu;
    SET_GPR_U32(ctx, 31, 0x1F5E84u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5E84u; }
        if (ctx->pc != 0x1F5E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5E84u; }
        if (ctx->pc != 0x1F5E84u) { return; }
    }
    ctx->pc = 0x1F5E84u;
label_1f5e84:
    // 0x1f5e84: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1f5e84u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1f5e88: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1f5e88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1f5e8c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F5E8Cu;
    {
        const bool branch_taken_0x1f5e8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5E8Cu;
            // 0x1f5e90: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5e8c) {
            ctx->pc = 0x1F5EACu;
            goto label_1f5eac;
        }
    }
    ctx->pc = 0x1F5E94u;
    // 0x1f5e94: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1f5e94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1f5e98: 0x27a5002c  addiu       $a1, $sp, 0x2C
    ctx->pc = 0x1f5e98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    // 0x1f5e9c: 0x24845f60  addiu       $a0, $a0, 0x5F60
    ctx->pc = 0x1f5e9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24416));
    // 0x1f5ea0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F5EA0u;
    SET_GPR_U32(ctx, 31, 0x1F5EA8u);
    ctx->pc = 0x1F5EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5EA0u;
            // 0x1f5ea4: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EA8u; }
        if (ctx->pc != 0x1F5EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EA8u; }
        if (ctx->pc != 0x1F5EA8u) { return; }
    }
    ctx->pc = 0x1F5EA8u;
label_1f5ea8:
    // 0x1f5ea8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f5ea8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1f5eac:
    // 0x1f5eac: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5EACu;
    SET_GPR_U32(ctx, 31, 0x1F5EB4u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EB4u; }
        if (ctx->pc != 0x1F5EB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EB4u; }
        if (ctx->pc != 0x1F5EB4u) { return; }
    }
    ctx->pc = 0x1F5EB4u;
label_1f5eb4:
    // 0x1f5eb4: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1f5eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1f5eb8: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1f5eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1f5ebc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F5EBCu;
    {
        const bool branch_taken_0x1f5ebc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F5EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5EBCu;
            // 0x1f5ec0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f5ebc) {
            ctx->pc = 0x1F5EDCu;
            goto label_1f5edc;
        }
    }
    ctx->pc = 0x1F5EC4u;
    // 0x1f5ec4: 0x3c040033  lui         $a0, 0x33
    ctx->pc = 0x1f5ec4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)51 << 16));
    // 0x1f5ec8: 0x27a5002c  addiu       $a1, $sp, 0x2C
    ctx->pc = 0x1f5ec8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
    // 0x1f5ecc: 0x2484af20  addiu       $a0, $a0, -0x50E0
    ctx->pc = 0x1f5eccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946592));
    // 0x1f5ed0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F5ED0u;
    SET_GPR_U32(ctx, 31, 0x1F5ED8u);
    ctx->pc = 0x1F5ED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5ED0u;
            // 0x1f5ed4: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5ED8u; }
        if (ctx->pc != 0x1F5ED8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5ED8u; }
        if (ctx->pc != 0x1F5ED8u) { return; }
    }
    ctx->pc = 0x1F5ED8u;
label_1f5ed8:
    // 0x1f5ed8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f5ed8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1f5edc:
    // 0x1f5edc: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5EDCu;
    SET_GPR_U32(ctx, 31, 0x1F5EE4u);
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EE4u; }
        if (ctx->pc != 0x1F5EE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EE4u; }
        if (ctx->pc != 0x1F5EE4u) { return; }
    }
    ctx->pc = 0x1F5EE4u;
label_1f5ee4:
    // 0x1f5ee4: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5EE4u;
    SET_GPR_U32(ctx, 31, 0x1F5EECu);
    ctx->pc = 0x1F5EE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5EE4u;
            // 0x1f5ee8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EECu; }
        if (ctx->pc != 0x1F5EECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EECu; }
        if (ctx->pc != 0x1F5EECu) { return; }
    }
    ctx->pc = 0x1F5EECu;
label_1f5eec:
    // 0x1f5eec: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5EECu;
    SET_GPR_U32(ctx, 31, 0x1F5EF4u);
    ctx->pc = 0x1F5EF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5EECu;
            // 0x1f5ef0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EF4u; }
        if (ctx->pc != 0x1F5EF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EF4u; }
        if (ctx->pc != 0x1F5EF4u) { return; }
    }
    ctx->pc = 0x1F5EF4u;
label_1f5ef4:
    // 0x1f5ef4: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5EF4u;
    SET_GPR_U32(ctx, 31, 0x1F5EFCu);
    ctx->pc = 0x1F5EF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5EF4u;
            // 0x1f5ef8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EFCu; }
        if (ctx->pc != 0x1F5EFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5EFCu; }
        if (ctx->pc != 0x1F5EFCu) { return; }
    }
    ctx->pc = 0x1F5EFCu;
label_1f5efc:
    // 0x1f5efc: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5EFCu;
    SET_GPR_U32(ctx, 31, 0x1F5F04u);
    ctx->pc = 0x1F5F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5EFCu;
            // 0x1f5f00: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F04u; }
        if (ctx->pc != 0x1F5F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F04u; }
        if (ctx->pc != 0x1F5F04u) { return; }
    }
    ctx->pc = 0x1F5F04u;
label_1f5f04:
    // 0x1f5f04: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F04u;
    SET_GPR_U32(ctx, 31, 0x1F5F0Cu);
    ctx->pc = 0x1F5F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F04u;
            // 0x1f5f08: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F0Cu; }
        if (ctx->pc != 0x1F5F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F0Cu; }
        if (ctx->pc != 0x1F5F0Cu) { return; }
    }
    ctx->pc = 0x1F5F0Cu;
label_1f5f0c:
    // 0x1f5f0c: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F0Cu;
    SET_GPR_U32(ctx, 31, 0x1F5F14u);
    ctx->pc = 0x1F5F10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F0Cu;
            // 0x1f5f10: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F14u; }
        if (ctx->pc != 0x1F5F14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F14u; }
        if (ctx->pc != 0x1F5F14u) { return; }
    }
    ctx->pc = 0x1F5F14u;
label_1f5f14:
    // 0x1f5f14: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F14u;
    SET_GPR_U32(ctx, 31, 0x1F5F1Cu);
    ctx->pc = 0x1F5F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F14u;
            // 0x1f5f18: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F1Cu; }
        if (ctx->pc != 0x1F5F1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F1Cu; }
        if (ctx->pc != 0x1F5F1Cu) { return; }
    }
    ctx->pc = 0x1F5F1Cu;
label_1f5f1c:
    // 0x1f5f1c: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F1Cu;
    SET_GPR_U32(ctx, 31, 0x1F5F24u);
    ctx->pc = 0x1F5F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F1Cu;
            // 0x1f5f20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F24u; }
        if (ctx->pc != 0x1F5F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F24u; }
        if (ctx->pc != 0x1F5F24u) { return; }
    }
    ctx->pc = 0x1F5F24u;
label_1f5f24:
    // 0x1f5f24: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F24u;
    SET_GPR_U32(ctx, 31, 0x1F5F2Cu);
    ctx->pc = 0x1F5F28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F24u;
            // 0x1f5f28: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F2Cu; }
        if (ctx->pc != 0x1F5F2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F2Cu; }
        if (ctx->pc != 0x1F5F2Cu) { return; }
    }
    ctx->pc = 0x1F5F2Cu;
label_1f5f2c:
    // 0x1f5f2c: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F2Cu;
    SET_GPR_U32(ctx, 31, 0x1F5F34u);
    ctx->pc = 0x1F5F30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F2Cu;
            // 0x1f5f30: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F34u; }
        if (ctx->pc != 0x1F5F34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F34u; }
        if (ctx->pc != 0x1F5F34u) { return; }
    }
    ctx->pc = 0x1F5F34u;
label_1f5f34:
    // 0x1f5f34: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F34u;
    SET_GPR_U32(ctx, 31, 0x1F5F3Cu);
    ctx->pc = 0x1F5F38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F34u;
            // 0x1f5f38: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F3Cu; }
        if (ctx->pc != 0x1F5F3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F3Cu; }
        if (ctx->pc != 0x1F5F3Cu) { return; }
    }
    ctx->pc = 0x1F5F3Cu;
label_1f5f3c:
    // 0x1f5f3c: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F3Cu;
    SET_GPR_U32(ctx, 31, 0x1F5F44u);
    ctx->pc = 0x1F5F40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F3Cu;
            // 0x1f5f40: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F44u; }
        if (ctx->pc != 0x1F5F44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F44u; }
        if (ctx->pc != 0x1F5F44u) { return; }
    }
    ctx->pc = 0x1F5F44u;
label_1f5f44:
    // 0x1f5f44: 0xc07d224  jal         func_1F4890
    ctx->pc = 0x1F5F44u;
    SET_GPR_U32(ctx, 31, 0x1F5F4Cu);
    ctx->pc = 0x1F5F48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F44u;
            // 0x1f5f48: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4890u;
    if (runtime->hasFunction(0x1F4890u)) {
        auto targetFn = runtime->lookupFunction(0x1F4890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F4Cu; }
        if (ctx->pc != 0x1F5F4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4890_0x1f4890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F5F4Cu; }
        if (ctx->pc != 0x1F5F4Cu) { return; }
    }
    ctx->pc = 0x1F5F4Cu;
label_1f5f4c:
    // 0x1f5f4c: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1f5f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x1f5f50: 0x3c01008a  lui         $at, 0x8A
    ctx->pc = 0x1f5f50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)138 << 16));
    // 0x1f5f54: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1f5f54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1f5f58: 0xac226508  sw          $v0, 0x6508($at)
    ctx->pc = 0x1f5f58u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 25864), GPR_U32(ctx, 2));
label_1f5f5c:
    // 0x1f5f5c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f5f5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f5f60: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f5f60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f5f64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f5f64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f5f68: 0x3e00008  jr          $ra
    ctx->pc = 0x1F5F68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F5F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F5F68u;
            // 0x1f5f6c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F5E54u: goto label_1f5e54;
            case 0x1F5E78u: goto label_1f5e78;
            case 0x1F5E7Cu: goto label_1f5e7c;
            case 0x1F5E84u: goto label_1f5e84;
            case 0x1F5EA8u: goto label_1f5ea8;
            case 0x1F5EACu: goto label_1f5eac;
            case 0x1F5EB4u: goto label_1f5eb4;
            case 0x1F5ED8u: goto label_1f5ed8;
            case 0x1F5EDCu: goto label_1f5edc;
            case 0x1F5EE4u: goto label_1f5ee4;
            case 0x1F5EECu: goto label_1f5eec;
            case 0x1F5EF4u: goto label_1f5ef4;
            case 0x1F5EFCu: goto label_1f5efc;
            case 0x1F5F04u: goto label_1f5f04;
            case 0x1F5F0Cu: goto label_1f5f0c;
            case 0x1F5F14u: goto label_1f5f14;
            case 0x1F5F1Cu: goto label_1f5f1c;
            case 0x1F5F24u: goto label_1f5f24;
            case 0x1F5F2Cu: goto label_1f5f2c;
            case 0x1F5F34u: goto label_1f5f34;
            case 0x1F5F3Cu: goto label_1f5f3c;
            case 0x1F5F44u: goto label_1f5f44;
            case 0x1F5F4Cu: goto label_1f5f4c;
            case 0x1F5F5Cu: goto label_1f5f5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F5F70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
