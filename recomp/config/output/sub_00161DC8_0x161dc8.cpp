#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161DC8
// Address: 0x161dc8 - 0x161e14
void sub_00161DC8_0x161dc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161DC8_0x161dc8");
#endif

    switch (ctx->pc) {
        case 0x161df0u: goto label_161df0;
        default: break;
    }

    ctx->pc = 0x161dc8u;

    // 0x161dc8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x161dc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x161dcc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x161dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x161dd0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x161dd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161dd4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x161dd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x161dd8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x161dd8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ddc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x161ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x161de0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161de0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161de4: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x161de4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x161de8: 0xc05f4e4  jal         func_17D390
    ctx->pc = 0x161DE8u;
    SET_GPR_U32(ctx, 31, 0x161DF0u);
    ctx->pc = 0x161DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161DE8u;
            // 0x161dec: 0x8c8400a8  lw          $a0, 0xA8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 168)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D390u;
    if (runtime->hasFunction(0x17D390u)) {
        auto targetFn = runtime->lookupFunction(0x17D390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161DF0u; }
        if (ctx->pc != 0x161DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D390_0x17d390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161DF0u; }
        if (ctx->pc != 0x161DF0u) { return; }
    }
    ctx->pc = 0x161DF0u;
label_161df0:
    // 0x161df0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x161df0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161df4: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x161df4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x161df8: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x161df8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x161dfc: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x161dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x161e00: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x161e00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161e04: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x161e04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x161e08: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x161e08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x161e0c: 0x3e00008  jr          $ra
    ctx->pc = 0x161E0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161E0Cu;
            // 0x161e10: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161DF0u: goto label_161df0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161E14u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
