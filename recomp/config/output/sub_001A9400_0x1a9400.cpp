#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9400
// Address: 0x1a9400 - 0x1a9480
void sub_001A9400_0x1a9400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9400_0x1a9400");
#endif

    switch (ctx->pc) {
        case 0x1a941cu: goto label_1a941c;
        case 0x1a9424u: goto label_1a9424;
        case 0x1a942cu: goto label_1a942c;
        case 0x1a9434u: goto label_1a9434;
        case 0x1a9474u: goto label_1a9474;
        default: break;
    }

    ctx->pc = 0x1a9400u;

    // 0x1a9400: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a9400u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a9404: 0x18800005  blez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A9404u;
    {
        const bool branch_taken_0x1a9404 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x1A9408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9404u;
            // 0x1a9408: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9404) {
            ctx->pc = 0x1A941Cu;
            goto label_1a941c;
        }
    }
    ctx->pc = 0x1A940Cu;
    // 0x1a940c: 0x8ca50000  lw          $a1, 0x0($a1)
    ctx->pc = 0x1a940cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1a9410: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a9410u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a9414: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1A9414u;
    SET_GPR_U32(ctx, 31, 0x1A941Cu);
    ctx->pc = 0x1A9418u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9414u;
            // 0x1a9418: 0x24843710  addiu       $a0, $a0, 0x3710 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A941Cu; }
        if (ctx->pc != 0x1A941Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A941Cu; }
        if (ctx->pc != 0x1A941Cu) { return; }
    }
    ctx->pc = 0x1A941Cu;
label_1a941c:
    // 0x1a941c: 0xc06a474  jal         func_1A91D0
    ctx->pc = 0x1A941Cu;
    SET_GPR_U32(ctx, 31, 0x1A9424u);
    ctx->pc = 0x1A91D0u;
    if (runtime->hasFunction(0x1A91D0u)) {
        auto targetFn = runtime->lookupFunction(0x1A91D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9424u; }
        if (ctx->pc != 0x1A9424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A91D0_0x1a91d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9424u; }
        if (ctx->pc != 0x1A9424u) { return; }
    }
    ctx->pc = 0x1A9424u;
label_1a9424:
    // 0x1a9424: 0xc06ea80  jal         func_1BAA00
    ctx->pc = 0x1A9424u;
    SET_GPR_U32(ctx, 31, 0x1A942Cu);
    ctx->pc = 0x1BAA00u;
    if (runtime->hasFunction(0x1BAA00u)) {
        auto targetFn = runtime->lookupFunction(0x1BAA00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A942Cu; }
        if (ctx->pc != 0x1A942Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAA00_0x1baa00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A942Cu; }
        if (ctx->pc != 0x1A942Cu) { return; }
    }
    ctx->pc = 0x1A942Cu;
label_1a942c:
    // 0x1a942c: 0xc0759c8  jal         func_1D6720
    ctx->pc = 0x1A942Cu;
    SET_GPR_U32(ctx, 31, 0x1A9434u);
    ctx->pc = 0x1D6720u;
    if (runtime->hasFunction(0x1D6720u)) {
        auto targetFn = runtime->lookupFunction(0x1D6720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9434u; }
        if (ctx->pc != 0x1A9434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6720_0x1d6720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9434u; }
        if (ctx->pc != 0x1A9434u) { return; }
    }
    ctx->pc = 0x1A9434u;
label_1a9434:
    // 0x1a9434: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1a9434u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1a9438: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1a9438u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1a943c: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A943Cu;
    {
        const bool branch_taken_0x1a943c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A9440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A943Cu;
            // 0x1a9440: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a943c) {
            ctx->pc = 0x1A9424u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9424;
        }
    }
    ctx->pc = 0x1A9444u;
    // 0x1a9444: 0x942244c0  lhu         $v0, 0x44C0($at)
    ctx->pc = 0x1a9444u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17600)));
    // 0x1a9448: 0x3042001f  andi        $v0, $v0, 0x1F
    ctx->pc = 0x1a9448u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
    // 0x1a944c: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1A944Cu;
    {
        const bool branch_taken_0x1a944c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a944c) {
            ctx->pc = 0x1A9424u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9424;
        }
    }
    ctx->pc = 0x1A9454u;
    // 0x1a9454: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1a9454u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1a9458: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1a9458u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1a945c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1a945cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1a9460: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1a9460u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a9464: 0x8022cc48  lb          $v0, -0x33B8($at)
    ctx->pc = 0x1a9464u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1a9468: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1a9468u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1a946c: 0xc0759d8  jal         func_1D6760
    ctx->pc = 0x1A946Cu;
    SET_GPR_U32(ctx, 31, 0x1A9474u);
    ctx->pc = 0x1A9470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A946Cu;
            // 0x1a9470: 0x2c450001  sltiu       $a1, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6760u;
    if (runtime->hasFunction(0x1D6760u)) {
        auto targetFn = runtime->lookupFunction(0x1D6760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9474u; }
        if (ctx->pc != 0x1A9474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6760_0x1d6760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9474u; }
        if (ctx->pc != 0x1A9474u) { return; }
    }
    ctx->pc = 0x1A9474u;
label_1a9474:
    // 0x1a9474: 0x1000ffeb  b           . + 4 + (-0x15 << 2)
    ctx->pc = 0x1A9474u;
    {
        const bool branch_taken_0x1a9474 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9474) {
            ctx->pc = 0x1A9424u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9424;
        }
    }
    ctx->pc = 0x1A947Cu;
    // 0x1a947c: 0x0  nop
    ctx->pc = 0x1a947cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
