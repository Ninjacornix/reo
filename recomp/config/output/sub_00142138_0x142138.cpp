#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142138
// Address: 0x142138 - 0x142190
void sub_00142138_0x142138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142138_0x142138");
#endif

    switch (ctx->pc) {
        case 0x142168u: goto label_142168;
        default: break;
    }

    ctx->pc = 0x142138u;

    // 0x142138: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x142138u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14213c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x14213cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x142140: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x142140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x142144: 0x2442a5ec  addiu       $v0, $v0, -0x5A14
    ctx->pc = 0x142144u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944236));
    // 0x142148: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x142148u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14214c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x14214cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x142150: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x142150u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x142154: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x142154u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x142158: 0x1480000b  bnez        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x142158u;
    {
        const bool branch_taken_0x142158 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x14215Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142158u;
            // 0x14215c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142158) {
            ctx->pc = 0x142188u;
            goto label_142188;
        }
    }
    ctx->pc = 0x142160u;
    // 0x142160: 0xc05081e  jal         func_142078
    ctx->pc = 0x142160u;
    SET_GPR_U32(ctx, 31, 0x142168u);
    ctx->pc = 0x142078u;
    if (runtime->hasFunction(0x142078u)) {
        auto targetFn = runtime->lookupFunction(0x142078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142168u; }
        if (ctx->pc != 0x142168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142078_0x142078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142168u; }
        if (ctx->pc != 0x142168u) { return; }
    }
    ctx->pc = 0x142168u;
label_142168:
    // 0x142168: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x142168u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x14216c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14216cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142170: 0x248449f0  addiu       $a0, $a0, 0x49F0
    ctx->pc = 0x142170u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18928));
    // 0x142174: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x142174u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142178: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x142178u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x14217c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x14217Cu;
    ctx->pc = 0x142180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14217Cu;
            // 0x142180: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x142184u;
    // 0x142184: 0x0  nop
    ctx->pc = 0x142184u;
    // NOP
label_142188:
    // 0x142188: 0x3e00008  jr          $ra
    ctx->pc = 0x142188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14218Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142188u;
            // 0x14218c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x142168u: goto label_142168;
            case 0x142188u: goto label_142188;
            default: break;
        }
        return;
    }
    ctx->pc = 0x142190u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
