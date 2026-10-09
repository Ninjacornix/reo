#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6B80
// Address: 0x1d6b80 - 0x1d6be0
void sub_001D6B80_0x1d6b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6B80_0x1d6b80");
#endif

    switch (ctx->pc) {
        case 0x1d6bacu: goto label_1d6bac;
        case 0x1d6bc0u: goto label_1d6bc0;
        default: break;
    }

    ctx->pc = 0x1d6b80u;

    // 0x1d6b80: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d6b80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d6b84: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d6b84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6b88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d6b88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d6b8c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d6b8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d6b90: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1d6b90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d6b94: 0x60082a  slt         $at, $v1, $zero
    ctx->pc = 0x1d6b94u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1d6b98: 0x1420000b  bnez        $at, . + 4 + (0xB << 2)
    ctx->pc = 0x1D6B98u;
    {
        const bool branch_taken_0x1d6b98 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D6B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6B98u;
            // 0x1d6b9c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6b98) {
            ctx->pc = 0x1D6BC8u;
            goto label_1d6bc8;
        }
    }
    ctx->pc = 0x1D6BA0u;
    // 0x1d6ba0: 0x3243c  dsll32      $a0, $v1, 16
    ctx->pc = 0x1d6ba0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d6ba4: 0xc076060  jal         func_1D8180
    ctx->pc = 0x1D6BA4u;
    SET_GPR_U32(ctx, 31, 0x1D6BACu);
    ctx->pc = 0x1D6BA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6BA4u;
            // 0x1d6ba8: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8180u;
    if (runtime->hasFunction(0x1D8180u)) {
        auto targetFn = runtime->lookupFunction(0x1D8180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6BACu; }
        if (ctx->pc != 0x1D6BACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8180_0x1d8180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6BACu; }
        if (ctx->pc != 0x1D6BACu) { return; }
    }
    ctx->pc = 0x1D6BACu;
label_1d6bac:
    // 0x1d6bac: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d6bacu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6bb0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d6bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6bb4: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1d6bb4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1d6bb8: 0xc0759b4  jal         func_1D66D0
    ctx->pc = 0x1D6BB8u;
    SET_GPR_U32(ctx, 31, 0x1D6BC0u);
    ctx->pc = 0x1D6BBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6BB8u;
            // 0x1d6bbc: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D66D0u;
    if (runtime->hasFunction(0x1D66D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D66D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6BC0u; }
        if (ctx->pc != 0x1D6BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D66D0_0x1d66d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6BC0u; }
        if (ctx->pc != 0x1D6BC0u) { return; }
    }
    ctx->pc = 0x1D6BC0u;
label_1d6bc0:
    // 0x1d6bc0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6BC0u;
    {
        const bool branch_taken_0x1d6bc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6bc0) {
            ctx->pc = 0x1D6BD0u;
            goto label_1d6bd0;
        }
    }
    ctx->pc = 0x1D6BC8u;
label_1d6bc8:
    // 0x1d6bc8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d6bc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6bcc: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1d6bccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
label_1d6bd0:
    // 0x1d6bd0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d6bd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d6bd4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d6bd4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6bd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6BD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6BD8u;
            // 0x1d6bdc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6BACu: goto label_1d6bac;
            case 0x1D6BC0u: goto label_1d6bc0;
            case 0x1D6BC8u: goto label_1d6bc8;
            case 0x1D6BD0u: goto label_1d6bd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6BE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
