#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114B40
// Address: 0x114b40 - 0x114be8
void sub_00114B40_0x114b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114B40_0x114b40");
#endif

    switch (ctx->pc) {
        case 0x114b58u: goto label_114b58;
        case 0x114b60u: goto label_114b60;
        case 0x114b84u: goto label_114b84;
        case 0x114b90u: goto label_114b90;
        case 0x114bb4u: goto label_114bb4;
        case 0x114bd4u: goto label_114bd4;
        default: break;
    }

    ctx->pc = 0x114b40u;

    // 0x114b40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x114b40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x114b44: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x114b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x114b48: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x114b48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x114b4c: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x114b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x114b50: 0xc045264  jal         func_114990
    ctx->pc = 0x114B50u;
    SET_GPR_U32(ctx, 31, 0x114B58u);
    ctx->pc = 0x114B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x114B50u;
            // 0x114b54: 0x37a50008  ori         $a1, $sp, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
    ctx->pc = 0x114990u;
    if (runtime->hasFunction(0x114990u)) {
        auto targetFn = runtime->lookupFunction(0x114990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B58u; }
        if (ctx->pc != 0x114B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114990_0x114990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B58u; }
        if (ctx->pc != 0x114B58u) { return; }
    }
    ctx->pc = 0x114B58u;
label_114b58:
    // 0x114b58: 0xc047598  jal         func_11D660
    ctx->pc = 0x114B58u;
    SET_GPR_U32(ctx, 31, 0x114B60u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B60u; }
        if (ctx->pc != 0x114B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B60u; }
        if (ctx->pc != 0x114B60u) { return; }
    }
    ctx->pc = 0x114B60u;
label_114b60:
    // 0x114b60: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x114b60u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x114b64: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x114b64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x114b68: 0x3463f000  ori         $v1, $v1, 0xF000
    ctx->pc = 0x114b68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)61440);
    // 0x114b6c: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x114b6cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x114b70: 0xf  sync
    ctx->pc = 0x114b70u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114b74: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x114B74u;
    {
        const bool branch_taken_0x114b74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x114B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114B74u;
            // 0x114b78: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114b74) {
            ctx->pc = 0x114B88u;
            goto label_114b88;
        }
    }
    ctx->pc = 0x114B7Cu;
    // 0x114b7c: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x114B7Cu;
    SET_GPR_U32(ctx, 31, 0x114B84u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B84u; }
        if (ctx->pc != 0x114B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B84u; }
        if (ctx->pc != 0x114B84u) { return; }
    }
    ctx->pc = 0x114B84u;
label_114b84:
    // 0x114b84: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x114b84u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
label_114b88:
    // 0x114b88: 0x3463f000  ori         $v1, $v1, 0xF000
    ctx->pc = 0x114b88u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)61440);
    // 0x114b8c: 0x0  nop
    ctx->pc = 0x114b8cu;
    // NOP
label_114b90:
    // 0x114b90: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x114b90u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x114b94: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x114b94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x114b98: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x114B98u;
    {
        const bool branch_taken_0x114b98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x114b98) {
            ctx->pc = 0x114BACu;
            goto label_114bac;
        }
    }
    ctx->pc = 0x114BA0u;
    // 0x114ba0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x114ba0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x114ba4: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x114BA4u;
    {
        const bool branch_taken_0x114ba4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x114ba4) {
            ctx->pc = 0x114B90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_114b90;
        }
    }
    ctx->pc = 0x114BACu;
label_114bac:
    // 0x114bac: 0xc047598  jal         func_11D660
    ctx->pc = 0x114BACu;
    SET_GPR_U32(ctx, 31, 0x114BB4u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114BB4u; }
        if (ctx->pc != 0x114BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114BB4u; }
        if (ctx->pc != 0x114BB4u) { return; }
    }
    ctx->pc = 0x114BB4u;
label_114bb4:
    // 0x114bb4: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x114bb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x114bb8: 0x3c011001  lui         $at, 0x1001
    ctx->pc = 0x114bb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4097 << 16));
    // 0x114bbc: 0xac23f000  sw          $v1, -0x1000($at)
    ctx->pc = 0x114bbcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 4294963200), GPR_U32(ctx, 3)); // MMIO: 0x1000f000
    // 0x114bc0: 0xf  sync
    ctx->pc = 0x114bc0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114bc4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x114BC4u;
    {
        const bool branch_taken_0x114bc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x114bc4) {
            ctx->pc = 0x114BD4u;
            goto label_114bd4;
        }
    }
    ctx->pc = 0x114BCCu;
    // 0x114bcc: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x114BCCu;
    SET_GPR_U32(ctx, 31, 0x114BD4u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114BD4u; }
        if (ctx->pc != 0x114BD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114BD4u; }
        if (ctx->pc != 0x114BD4u) { return; }
    }
    ctx->pc = 0x114BD4u;
label_114bd4:
    // 0x114bd4: 0xdfa20008  ld          $v0, 0x8($sp)
    ctx->pc = 0x114bd4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x114bd8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x114bd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x114bdc: 0x3e00008  jr          $ra
    ctx->pc = 0x114BDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114BDCu;
            // 0x114be0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114B58u: goto label_114b58;
            case 0x114B60u: goto label_114b60;
            case 0x114B84u: goto label_114b84;
            case 0x114B88u: goto label_114b88;
            case 0x114B90u: goto label_114b90;
            case 0x114BACu: goto label_114bac;
            case 0x114BB4u: goto label_114bb4;
            case 0x114BD4u: goto label_114bd4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114BE4u;
    // 0x114be4: 0x0  nop
    ctx->pc = 0x114be4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
