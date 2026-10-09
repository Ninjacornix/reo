#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00118758
// Address: 0x118758 - 0x11879c
void sub_00118758_0x118758(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00118758_0x118758");
#endif

    switch (ctx->pc) {
        case 0x118780u: goto label_118780;
        default: break;
    }

    ctx->pc = 0x118758u;

    // 0x118758: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x118758u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11875c: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x11875cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x118760: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x118760u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x118764: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x118764u;
    {
        const bool branch_taken_0x118764 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x118768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118764u;
            // 0x118768: 0xffb00000  sd          $s0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118764) {
            ctx->pc = 0x118784u;
            goto label_118784;
        }
    }
    ctx->pc = 0x11876Cu;
    // 0x11876c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x11876cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x118770: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x118770u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118774: 0x8c5ce200  lw          $gp, -0x1E00($v0)
    ctx->pc = 0x118774u;
    SET_GPR_S32(ctx, 28, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294959616)));
    // 0x118778: 0x60f809  jalr        $v1
    ctx->pc = 0x118778u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x118780u);
        ctx->pc = 0x11877Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118778u;
            // 0x11877c: 0x8ca40004  lw          $a0, 0x4($a1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x118780u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118780u: goto label_118780;
            case 0x118784u: goto label_118784;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x118780u; }
            if (ctx->pc != 0x118780u) { return; }
        }
        }
    }
    ctx->pc = 0x118780u;
label_118780:
    // 0x118780: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x118780u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_118784:
    // 0x118784: 0xf  sync
    ctx->pc = 0x118784u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x118788: 0x42000038  ei
    ctx->pc = 0x118788u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x11878c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11878cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x118790: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x118790u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x118794: 0x3e00008  jr          $ra
    ctx->pc = 0x118794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118794u;
            // 0x118798: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118780u: goto label_118780;
            case 0x118784u: goto label_118784;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11879Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
