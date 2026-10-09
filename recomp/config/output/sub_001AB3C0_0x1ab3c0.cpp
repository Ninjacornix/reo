#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB3C0
// Address: 0x1ab3c0 - 0x1ab450
void sub_001AB3C0_0x1ab3c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB3C0_0x1ab3c0");
#endif

    switch (ctx->pc) {
        case 0x1ab3e0u: goto label_1ab3e0;
        case 0x1ab404u: goto label_1ab404;
        default: break;
    }

    ctx->pc = 0x1ab3c0u;

    // 0x1ab3c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1ab3c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1ab3c4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1ab3c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1ab3c8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ab3c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ab3cc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ab3ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ab3d0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ab3d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ab3d4: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1ab3d4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab3d8: 0x3c10002b  lui         $s0, 0x2B
    ctx->pc = 0x1ab3d8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)43 << 16));
    // 0x1ab3dc: 0x261016c0  addiu       $s0, $s0, 0x16C0
    ctx->pc = 0x1ab3dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5824));
label_1ab3e0:
    // 0x1ab3e0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1ab3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1ab3e4: 0x119080  sll         $s2, $s1, 2
    ctx->pc = 0x1ab3e4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1ab3e8: 0x24423e58  addiu       $v0, $v0, 0x3E58
    ctx->pc = 0x1ab3e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 15960));
    // 0x1ab3ec: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1ab3ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab3f0: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x1ab3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1ab3f4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1ab3f4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab3f8: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ab3f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ab3fc: 0xc06a6b0  jal         func_1A9AC0
    ctx->pc = 0x1AB3FCu;
    SET_GPR_U32(ctx, 31, 0x1AB404u);
    ctx->pc = 0x1AB400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB3FCu;
            // 0x1ab400: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9AC0u;
    if (runtime->hasFunction(0x1A9AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A9AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB404u; }
        if (ctx->pc != 0x1AB404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9AC0_0x1a9ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB404u; }
        if (ctx->pc != 0x1AB404u) { return; }
    }
    ctx->pc = 0x1AB404u;
label_1ab404:
    // 0x1ab404: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1ab404u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1ab408: 0x2404fffc  addiu       $a0, $zero, -0x4
    ctx->pc = 0x1ab408u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1ab40c: 0x24633e60  addiu       $v1, $v1, 0x3E60
    ctx->pc = 0x1ab40cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 15968));
    // 0x1ab410: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1ab410u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1ab414: 0x721821  addu        $v1, $v1, $s2
    ctx->pc = 0x1ab414u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x1ab418: 0x8c650000  lw          $a1, 0x0($v1)
    ctx->pc = 0x1ab418u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ab41c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1ab41cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1ab420: 0x2a230002  slti        $v1, $s1, 0x2
    ctx->pc = 0x1ab420u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1ab424: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1ab424u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1ab428: 0x24a5011c  addiu       $a1, $a1, 0x11C
    ctx->pc = 0x1ab428u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 284));
    // 0x1ab42c: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x1ab42cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1ab430: 0x1460ffeb  bnez        $v1, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1AB430u;
    {
        const bool branch_taken_0x1ab430 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AB434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB430u;
            // 0x1ab434: 0x2048021  addu        $s0, $s0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab430) {
            ctx->pc = 0x1AB3E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab3e0;
        }
    }
    ctx->pc = 0x1AB438u;
    // 0x1ab438: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1ab438u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ab43c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ab43cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ab440: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ab440u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ab444: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ab444u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab448: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB448u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB44Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB448u;
            // 0x1ab44c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB3E0u: goto label_1ab3e0;
            case 0x1AB404u: goto label_1ab404;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB450u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
