#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A3CA0
// Address: 0x1a3ca0 - 0x1a3d00
void sub_001A3CA0_0x1a3ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A3CA0_0x1a3ca0");
#endif

    switch (ctx->pc) {
        case 0x1a3cb8u: goto label_1a3cb8;
        case 0x1a3cd0u: goto label_1a3cd0;
        default: break;
    }

    ctx->pc = 0x1a3ca0u;

    // 0x1a3ca0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a3ca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a3ca4: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1a3ca4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a3ca8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a3ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a3cac: 0x3c05000c  lui         $a1, 0xC
    ctx->pc = 0x1a3cacu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)12 << 16));
    // 0x1a3cb0: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A3CB0u;
    SET_GPR_U32(ctx, 31, 0x1A3CB8u);
    ctx->pc = 0x1A3CB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3CB0u;
            // 0x1a3cb4: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3CB8u; }
        if (ctx->pc != 0x1A3CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A3CB8u; }
        if (ctx->pc != 0x1A3CB8u) { return; }
    }
    ctx->pc = 0x1A3CB8u;
label_1a3cb8:
    // 0x1a3cb8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A3CB8u;
    {
        const bool branch_taken_0x1a3cb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A3CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3CB8u;
            // 0x1a3cbc: 0x2444000c  addiu       $a0, $v0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3cb8) {
            ctx->pc = 0x1A3CC8u;
            goto label_1a3cc8;
        }
    }
    ctx->pc = 0x1A3CC0u;
    // 0x1a3cc0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1A3CC0u;
    {
        const bool branch_taken_0x1a3cc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3CC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3CC0u;
            // 0x1a3cc4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3cc0) {
            ctx->pc = 0x1A3CF4u;
            goto label_1a3cf4;
        }
    }
    ctx->pc = 0x1A3CC8u;
label_1a3cc8:
    // 0x1a3cc8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A3CC8u;
    {
        const bool branch_taken_0x1a3cc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A3CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3CC8u;
            // 0x1a3ccc: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a3cc8) {
            ctx->pc = 0x1A3CE4u;
            goto label_1a3ce4;
        }
    }
    ctx->pc = 0x1A3CD0u;
label_1a3cd0:
    // 0x1a3cd0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a3cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a3cd4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a3cd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a3cd8: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1a3cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1a3cdc: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1a3cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1a3ce0: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a3ce0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a3ce4:
    // 0x1a3ce4: 0x68102a  slt         $v0, $v1, $t0
    ctx->pc = 0x1a3ce4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1a3ce8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1A3CE8u;
    {
        const bool branch_taken_0x1a3ce8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a3ce8) {
            ctx->pc = 0x1A3CD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a3cd0;
        }
    }
    ctx->pc = 0x1A3CF0u;
    // 0x1a3cf0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a3cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_1a3cf4:
    // 0x1a3cf4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a3cf4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a3cf8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A3CF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A3CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A3CF8u;
            // 0x1a3cfc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A3CB8u: goto label_1a3cb8;
            case 0x1A3CC8u: goto label_1a3cc8;
            case 0x1A3CD0u: goto label_1a3cd0;
            case 0x1A3CE4u: goto label_1a3ce4;
            case 0x1A3CF4u: goto label_1a3cf4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A3D00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
