#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BAA00
// Address: 0x1baa00 - 0x1baaf0
void sub_001BAA00_0x1baa00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BAA00_0x1baa00");
#endif

    switch (ctx->pc) {
        case 0x1baa2cu: goto label_1baa2c;
        case 0x1baa38u: goto label_1baa38;
        case 0x1baa50u: goto label_1baa50;
        case 0x1baa58u: goto label_1baa58;
        case 0x1baa68u: goto label_1baa68;
        case 0x1baa88u: goto label_1baa88;
        case 0x1baab0u: goto label_1baab0;
        case 0x1baab8u: goto label_1baab8;
        case 0x1baac4u: goto label_1baac4;
        case 0x1baad4u: goto label_1baad4;
        case 0x1baadcu: goto label_1baadc;
        default: break;
    }

    ctx->pc = 0x1baa00u;

    // 0x1baa00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1baa00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1baa04: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1baa04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1baa08: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1baa08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1baa0c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1baa0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1baa10: 0x8c226598  lw          $v0, 0x6598($at)
    ctx->pc = 0x1baa10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26008)));
    // 0x1baa14: 0x1044001a  beq         $v0, $a0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1BAA14u;
    {
        const bool branch_taken_0x1baa14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x1baa14) {
            ctx->pc = 0x1BAA80u;
            goto label_1baa80;
        }
    }
    ctx->pc = 0x1BAA1Cu;
    // 0x1baa1c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BAA1Cu;
    {
        const bool branch_taken_0x1baa1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BAA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAA1Cu;
            // 0x1baa20: 0x24040280  addiu       $a0, $zero, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1baa1c) {
            ctx->pc = 0x1BAA30u;
            goto label_1baa30;
        }
    }
    ctx->pc = 0x1BAA24u;
    // 0x1baa24: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1BAA24u;
    {
        const bool branch_taken_0x1baa24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BAA28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAA24u;
            // 0x1baa28: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1baa24) {
            ctx->pc = 0x1BAAE0u;
            goto label_1baae0;
        }
    }
    ctx->pc = 0x1BAA2Cu;
label_1baa2c:
    // 0x1baa2c: 0x24040280  addiu       $a0, $zero, 0x280
    ctx->pc = 0x1baa2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
label_1baa30:
    // 0x1baa30: 0xc067ce0  jal         func_19F380
    ctx->pc = 0x1BAA30u;
    SET_GPR_U32(ctx, 31, 0x1BAA38u);
    ctx->pc = 0x1BAA34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAA30u;
            // 0x1baa34: 0x240501c0  addiu       $a1, $zero, 0x1C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19F380u;
    if (runtime->hasFunction(0x19F380u)) {
        auto targetFn = runtime->lookupFunction(0x19F380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA38u; }
        if (ctx->pc != 0x1BAA38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F380_0x19f380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA38u; }
        if (ctx->pc != 0x1BAA38u) { return; }
    }
    ctx->pc = 0x1BAA38u;
label_1baa38:
    // 0x1baa38: 0x0  nop
    ctx->pc = 0x1baa38u;
    // NOP
    // 0x1baa3c: 0x0  nop
    ctx->pc = 0x1baa3cu;
    // NOP
    // 0x1baa40: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1BAA40u;
    {
        const bool branch_taken_0x1baa40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1baa40) {
            ctx->pc = 0x1BAA2Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1baa2c;
        }
    }
    ctx->pc = 0x1BAA48u;
    // 0x1baa48: 0xc06ebb0  jal         func_1BAEC0
    ctx->pc = 0x1BAA48u;
    SET_GPR_U32(ctx, 31, 0x1BAA50u);
    ctx->pc = 0x1BAEC0u;
    if (runtime->hasFunction(0x1BAEC0u)) {
        auto targetFn = runtime->lookupFunction(0x1BAEC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA50u; }
        if (ctx->pc != 0x1BAA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAEC0_0x1baec0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA50u; }
        if (ctx->pc != 0x1BAA50u) { return; }
    }
    ctx->pc = 0x1BAA50u;
label_1baa50:
    // 0x1baa50: 0xc06ec74  jal         func_1BB1D0
    ctx->pc = 0x1BAA50u;
    SET_GPR_U32(ctx, 31, 0x1BAA58u);
    ctx->pc = 0x1BB1D0u;
    if (runtime->hasFunction(0x1BB1D0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA58u; }
        if (ctx->pc != 0x1BAA58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB1D0_0x1bb1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA58u; }
        if (ctx->pc != 0x1BAA58u) { return; }
    }
    ctx->pc = 0x1BAA58u;
label_1baa58:
    // 0x1baa58: 0x3c04001c  lui         $a0, 0x1C
    ctx->pc = 0x1baa58u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28 << 16));
    // 0x1baa5c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1baa5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1baa60: 0xc06dfb8  jal         func_1B7EE0
    ctx->pc = 0x1BAA60u;
    SET_GPR_U32(ctx, 31, 0x1BAA68u);
    ctx->pc = 0x1BAA64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAA60u;
            // 0x1baa64: 0x2484c6a0  addiu       $a0, $a0, -0x3960 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952608));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7EE0u;
    if (runtime->hasFunction(0x1B7EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1B7EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA68u; }
        if (ctx->pc != 0x1BAA68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7EE0_0x1b7ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA68u; }
        if (ctx->pc != 0x1BAA68u) { return; }
    }
    ctx->pc = 0x1BAA68u;
label_1baa68:
    // 0x1baa68: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1baa68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1baa6c: 0x8c226598  lw          $v0, 0x6598($at)
    ctx->pc = 0x1baa6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26008)));
    // 0x1baa70: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1baa70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1baa74: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1baa74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1baa78: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1BAA78u;
    {
        const bool branch_taken_0x1baa78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BAA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAA78u;
            // 0x1baa7c: 0xac226598  sw          $v0, 0x6598($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26008), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1baa78) {
            ctx->pc = 0x1BAADCu;
            goto label_1baadc;
        }
    }
    ctx->pc = 0x1BAA80u;
label_1baa80:
    // 0x1baa80: 0xc06eabc  jal         func_1BAAF0
    ctx->pc = 0x1BAA80u;
    SET_GPR_U32(ctx, 31, 0x1BAA88u);
    ctx->pc = 0x1BAAF0u;
    if (runtime->hasFunction(0x1BAAF0u)) {
        auto targetFn = runtime->lookupFunction(0x1BAAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA88u; }
        if (ctx->pc != 0x1BAA88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAAF0_0x1baaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAA88u; }
        if (ctx->pc != 0x1BAA88u) { return; }
    }
    ctx->pc = 0x1BAA88u;
label_1baa88:
    // 0x1baa88: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1baa88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1baa8c: 0x942344d0  lhu         $v1, 0x44D0($at)
    ctx->pc = 0x1baa8cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17616)));
    // 0x1baa90: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1baa90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1baa94: 0x942244c0  lhu         $v0, 0x44C0($at)
    ctx->pc = 0x1baa94u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17600)));
    // 0x1baa98: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1baa98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1baa9c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1baa9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1baaa0: 0xa42344c8  sh          $v1, 0x44C8($at)
    ctx->pc = 0x1baaa0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17608), (uint16_t)GPR_U32(ctx, 3));
    // 0x1baaa4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1baaa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1baaa8: 0xc06a460  jal         func_1A9180
    ctx->pc = 0x1BAAA8u;
    SET_GPR_U32(ctx, 31, 0x1BAAB0u);
    ctx->pc = 0x1BAAACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAAA8u;
            // 0x1baaac: 0xa42244c0  sh          $v0, 0x44C0($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 17600), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9180u;
    if (runtime->hasFunction(0x1A9180u)) {
        auto targetFn = runtime->lookupFunction(0x1A9180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAAB0u; }
        if (ctx->pc != 0x1BAAB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9180_0x1a9180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAAB0u; }
        if (ctx->pc != 0x1BAAB0u) { return; }
    }
    ctx->pc = 0x1BAAB0u;
label_1baab0:
    // 0x1baab0: 0xc04491c  jal         func_112470
    ctx->pc = 0x1BAAB0u;
    SET_GPR_U32(ctx, 31, 0x1BAAB8u);
    ctx->pc = 0x1BAAB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAAB0u;
            // 0x1baab4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112470u;
    if (runtime->hasFunction(0x112470u)) {
        auto targetFn = runtime->lookupFunction(0x112470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAAB8u; }
        if (ctx->pc != 0x1BAAB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAAB8u; }
        if (ctx->pc != 0x1BAAB8u) { return; }
    }
    ctx->pc = 0x1BAAB8u;
label_1baab8:
    // 0x1baab8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1baab8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1baabc: 0xc06bd70  jal         func_1AF5C0
    ctx->pc = 0x1BAABCu;
    SET_GPR_U32(ctx, 31, 0x1BAAC4u);
    ctx->pc = 0x1BAAC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAABCu;
            // 0x1baac0: 0xe4206590  swc1        $f0, 0x6590($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26000), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF5C0u;
    if (runtime->hasFunction(0x1AF5C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF5C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAAC4u; }
        if (ctx->pc != 0x1BAAC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF5C0_0x1af5c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAAC4u; }
        if (ctx->pc != 0x1BAAC4u) { return; }
    }
    ctx->pc = 0x1BAAC4u;
label_1baac4:
    // 0x1baac4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BAAC4u;
    {
        const bool branch_taken_0x1baac4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1baac4) {
            ctx->pc = 0x1BAAD4u;
            goto label_1baad4;
        }
    }
    ctx->pc = 0x1BAACCu;
    // 0x1baacc: 0xc06bd34  jal         func_1AF4D0
    ctx->pc = 0x1BAACCu;
    SET_GPR_U32(ctx, 31, 0x1BAAD4u);
    ctx->pc = 0x1AF4D0u;
    if (runtime->hasFunction(0x1AF4D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF4D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAAD4u; }
        if (ctx->pc != 0x1BAAD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF4D0_0x1af4d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAAD4u; }
        if (ctx->pc != 0x1BAAD4u) { return; }
    }
    ctx->pc = 0x1BAAD4u;
label_1baad4:
    // 0x1baad4: 0xc06df2c  jal         func_1B7CB0
    ctx->pc = 0x1BAAD4u;
    SET_GPR_U32(ctx, 31, 0x1BAADCu);
    ctx->pc = 0x1B7CB0u;
    if (runtime->hasFunction(0x1B7CB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B7CB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAADCu; }
        if (ctx->pc != 0x1BAADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7CB0_0x1b7cb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAADCu; }
        if (ctx->pc != 0x1BAADCu) { return; }
    }
    ctx->pc = 0x1BAADCu;
label_1baadc:
    // 0x1baadc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1baadcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1baae0:
    // 0x1baae0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1baae0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1baae4: 0x3e00008  jr          $ra
    ctx->pc = 0x1BAAE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BAAE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BAAE4u;
            // 0x1baae8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BAA2Cu: goto label_1baa2c;
            case 0x1BAA30u: goto label_1baa30;
            case 0x1BAA38u: goto label_1baa38;
            case 0x1BAA50u: goto label_1baa50;
            case 0x1BAA58u: goto label_1baa58;
            case 0x1BAA68u: goto label_1baa68;
            case 0x1BAA80u: goto label_1baa80;
            case 0x1BAA88u: goto label_1baa88;
            case 0x1BAAB0u: goto label_1baab0;
            case 0x1BAAB8u: goto label_1baab8;
            case 0x1BAAC4u: goto label_1baac4;
            case 0x1BAAD4u: goto label_1baad4;
            case 0x1BAADCu: goto label_1baadc;
            case 0x1BAAE0u: goto label_1baae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BAAECu;
    // 0x1baaec: 0x0  nop
    ctx->pc = 0x1baaecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
