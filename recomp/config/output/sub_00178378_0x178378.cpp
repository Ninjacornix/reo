#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178378
// Address: 0x178378 - 0x1783d8
void sub_00178378_0x178378(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178378_0x178378");
#endif

    switch (ctx->pc) {
        case 0x178398u: goto label_178398;
        case 0x1783c0u: goto label_1783c0;
        default: break;
    }

    ctx->pc = 0x178378u;

    // 0x178378: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x178378u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17837c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17837cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178380: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x178380u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178384: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x178384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x178388: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x178388u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17838c: 0x1840000a  blez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x17838Cu;
    {
        const bool branch_taken_0x17838c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x178390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17838Cu;
            // 0x178390: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17838c) {
            ctx->pc = 0x1783B8u;
            goto label_1783b8;
        }
    }
    ctx->pc = 0x178394u;
    // 0x178394: 0x26030018  addiu       $v1, $s0, 0x18
    ctx->pc = 0x178394u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
label_178398:
    // 0x178398: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x178398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17839c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x17839cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1783a0: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x1783a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1783a4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1783a4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1783a8: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1783a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1783ac: 0x82102a  slt         $v0, $a0, $v0
    ctx->pc = 0x1783acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1783b0: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1783B0u;
    {
        const bool branch_taken_0x1783b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1783B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1783B0u;
            // 0x1783b4: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1783b0) {
            ctx->pc = 0x178398u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_178398;
        }
    }
    ctx->pc = 0x1783B8u;
label_1783b8:
    // 0x1783b8: 0xc05e0f6  jal         func_1783D8
    ctx->pc = 0x1783B8u;
    SET_GPR_U32(ctx, 31, 0x1783C0u);
    ctx->pc = 0x1783BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1783B8u;
            // 0x1783bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1783D8u;
    if (runtime->hasFunction(0x1783D8u)) {
        auto targetFn = runtime->lookupFunction(0x1783D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1783C0u; }
        if (ctx->pc != 0x1783C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001783D8_0x1783d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1783C0u; }
        if (ctx->pc != 0x1783C0u) { return; }
    }
    ctx->pc = 0x1783C0u;
label_1783c0:
    // 0x1783c0: 0xae0201a8  sw          $v0, 0x1A8($s0)
    ctx->pc = 0x1783c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 2));
    // 0x1783c4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1783c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1783c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1783c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1783cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1783CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1783D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1783CCu;
            // 0x1783d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178398u: goto label_178398;
            case 0x1783B8u: goto label_1783b8;
            case 0x1783C0u: goto label_1783c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1783D4u;
    // 0x1783d4: 0x0  nop
    ctx->pc = 0x1783d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
