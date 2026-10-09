#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019F6C0
// Address: 0x19f6c0 - 0x19f750
void sub_0019F6C0_0x19f6c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019F6C0_0x19f6c0");
#endif

    switch (ctx->pc) {
        case 0x19f6d0u: goto label_19f6d0;
        case 0x19f6d8u: goto label_19f6d8;
        case 0x19f6e0u: goto label_19f6e0;
        case 0x19f714u: goto label_19f714;
        case 0x19f71cu: goto label_19f71c;
        case 0x19f724u: goto label_19f724;
        case 0x19f73cu: goto label_19f73c;
        default: break;
    }

    ctx->pc = 0x19f6c0u;

    // 0x19f6c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19f6c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19f6c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x19f6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19f6c8: 0xc06eaf0  jal         func_1BABC0
    ctx->pc = 0x19F6C8u;
    SET_GPR_U32(ctx, 31, 0x19F6D0u);
    ctx->pc = 0x1BABC0u;
    if (runtime->hasFunction(0x1BABC0u)) {
        auto targetFn = runtime->lookupFunction(0x1BABC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6D0u; }
        if (ctx->pc != 0x19F6D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BABC0_0x1babc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6D0u; }
        if (ctx->pc != 0x19F6D0u) { return; }
    }
    ctx->pc = 0x19F6D0u;
label_19f6d0:
    // 0x19f6d0: 0xc063594  jal         func_18D650
    ctx->pc = 0x19F6D0u;
    SET_GPR_U32(ctx, 31, 0x19F6D8u);
    ctx->pc = 0x18D650u;
    if (runtime->hasFunction(0x18D650u)) {
        auto targetFn = runtime->lookupFunction(0x18D650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6D8u; }
        if (ctx->pc != 0x19F6D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D650_0x18d650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6D8u; }
        if (ctx->pc != 0x19F6D8u) { return; }
    }
    ctx->pc = 0x19F6D8u;
label_19f6d8:
    // 0x19f6d8: 0xc06a42c  jal         func_1A90B0
    ctx->pc = 0x19F6D8u;
    SET_GPR_U32(ctx, 31, 0x19F6E0u);
    ctx->pc = 0x1A90B0u;
    if (runtime->hasFunction(0x1A90B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A90B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6E0u; }
        if (ctx->pc != 0x19F6E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A90B0_0x1a90b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6E0u; }
        if (ctx->pc != 0x19F6E0u) { return; }
    }
    ctx->pc = 0x19F6E0u;
label_19f6e0:
    // 0x19f6e0: 0x24020083  addiu       $v0, $zero, 0x83
    ctx->pc = 0x19f6e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 131));
    // 0x19f6e4: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x19f6e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x19f6e8: 0xac220010  sw          $v0, 0x10($at)
    ctx->pc = 0x19f6e8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 16), GPR_U32(ctx, 2)); // MMIO: 0x10000010
    // 0x19f6ec: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x19f6ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x19f6f0: 0xac200000  sw          $zero, 0x0($at)
    ctx->pc = 0x19f6f0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x19f6f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f6f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f6f8: 0xac20fa0c  sw          $zero, -0x5F4($at)
    ctx->pc = 0x19f6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965772), GPR_U32(ctx, 0));
    // 0x19f6fc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f6fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f700: 0x8c22fec8  lw          $v0, -0x138($at)
    ctx->pc = 0x19f700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966984)));
    // 0x19f704: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x19f704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x19f708: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f708u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f70c: 0xc06351c  jal         func_18D470
    ctx->pc = 0x19F70Cu;
    SET_GPR_U32(ctx, 31, 0x19F714u);
    ctx->pc = 0x19F710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F70Cu;
            // 0x19f710: 0xac22fec8  sw          $v0, -0x138($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966984), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18D470u;
    if (runtime->hasFunction(0x18D470u)) {
        auto targetFn = runtime->lookupFunction(0x18D470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F714u; }
        if (ctx->pc != 0x19F714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D470_0x18d470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F714u; }
        if (ctx->pc != 0x19F714u) { return; }
    }
    ctx->pc = 0x19F714u;
label_19f714:
    // 0x19f714: 0xc063750  jal         func_18DD40
    ctx->pc = 0x19F714u;
    SET_GPR_U32(ctx, 31, 0x19F71Cu);
    ctx->pc = 0x18DD40u;
    if (runtime->hasFunction(0x18DD40u)) {
        auto targetFn = runtime->lookupFunction(0x18DD40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F71Cu; }
        if (ctx->pc != 0x19F71Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DD40_0x18dd40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F71Cu; }
        if (ctx->pc != 0x19F71Cu) { return; }
    }
    ctx->pc = 0x19F71Cu;
label_19f71c:
    // 0x19f71c: 0xc068248  jal         func_1A0920
    ctx->pc = 0x19F71Cu;
    SET_GPR_U32(ctx, 31, 0x19F724u);
    ctx->pc = 0x1A0920u;
    if (runtime->hasFunction(0x1A0920u)) {
        auto targetFn = runtime->lookupFunction(0x1A0920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F724u; }
        if (ctx->pc != 0x19F724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0920_0x1a0920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F724u; }
        if (ctx->pc != 0x19F724u) { return; }
    }
    ctx->pc = 0x19F724u;
label_19f724:
    // 0x19f724: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f724u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f728: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x19f728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x19f72c: 0xac20fda0  sw          $zero, -0x260($at)
    ctx->pc = 0x19f72cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966688), GPR_U32(ctx, 0));
    // 0x19f730: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f730u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f734: 0xc06ead8  jal         func_1BAB60
    ctx->pc = 0x19F734u;
    SET_GPR_U32(ctx, 31, 0x19F73Cu);
    ctx->pc = 0x19F738u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F734u;
            // 0x19f738: 0xac22fd9c  sw          $v0, -0x264($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966684), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BAB60u;
    if (runtime->hasFunction(0x1BAB60u)) {
        auto targetFn = runtime->lookupFunction(0x1BAB60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F73Cu; }
        if (ctx->pc != 0x19F73Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAB60_0x1bab60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F73Cu; }
        if (ctx->pc != 0x19F73Cu) { return; }
    }
    ctx->pc = 0x19F73Cu;
label_19f73c:
    // 0x19f73c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19f73cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f740: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19f740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f744: 0x3e00008  jr          $ra
    ctx->pc = 0x19F744u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F744u;
            // 0x19f748: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F6D0u: goto label_19f6d0;
            case 0x19F6D8u: goto label_19f6d8;
            case 0x19F6E0u: goto label_19f6e0;
            case 0x19F714u: goto label_19f714;
            case 0x19F71Cu: goto label_19f71c;
            case 0x19F724u: goto label_19f724;
            case 0x19F73Cu: goto label_19f73c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F74Cu;
    // 0x19f74c: 0x0  nop
    ctx->pc = 0x19f74cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
