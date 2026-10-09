#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148448
// Address: 0x148448 - 0x148490
void sub_00148448_0x148448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148448_0x148448");
#endif

    switch (ctx->pc) {
        case 0x148470u: goto label_148470;
        case 0x148480u: goto label_148480;
        default: break;
    }

    ctx->pc = 0x148448u;

    // 0x148448: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x148448u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14844c: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x14844cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148450: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x148450u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x148454: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x148454u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x148458: 0x8ce40040  lw          $a0, 0x40($a3)
    ctx->pc = 0x148458u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 64)));
    // 0x14845c: 0x8c82018c  lw          $v0, 0x18C($a0)
    ctx->pc = 0x14845cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 396)));
    // 0x148460: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x148460u;
    {
        const bool branch_taken_0x148460 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x148460) {
            ctx->pc = 0x148478u;
            goto label_148478;
        }
    }
    ctx->pc = 0x148468u;
    // 0x148468: 0xc052124  jal         func_148490
    ctx->pc = 0x148468u;
    SET_GPR_U32(ctx, 31, 0x148470u);
    ctx->pc = 0x14846Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148468u;
            // 0x14846c: 0xe0202d  daddu       $a0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148490u;
    if (runtime->hasFunction(0x148490u)) {
        auto targetFn = runtime->lookupFunction(0x148490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148470u; }
        if (ctx->pc != 0x148470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148490_0x148490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148470u; }
        if (ctx->pc != 0x148470u) { return; }
    }
    ctx->pc = 0x148470u;
label_148470:
    // 0x148470: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x148470u;
    {
        const bool branch_taken_0x148470 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x148474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148470u;
            // 0x148474: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148470) {
            ctx->pc = 0x148484u;
            goto label_148484;
        }
    }
    ctx->pc = 0x148478u;
label_148478:
    // 0x148478: 0xc0520ca  jal         func_148328
    ctx->pc = 0x148478u;
    SET_GPR_U32(ctx, 31, 0x148480u);
    ctx->pc = 0x14847Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148478u;
            // 0x14847c: 0xe0202d  daddu       $a0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148328u;
    if (runtime->hasFunction(0x148328u)) {
        auto targetFn = runtime->lookupFunction(0x148328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148480u; }
        if (ctx->pc != 0x148480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148328_0x148328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148480u; }
        if (ctx->pc != 0x148480u) { return; }
    }
    ctx->pc = 0x148480u;
label_148480:
    // 0x148480: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x148480u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_148484:
    // 0x148484: 0x3e00008  jr          $ra
    ctx->pc = 0x148484u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148484u;
            // 0x148488: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148470u: goto label_148470;
            case 0x148478u: goto label_148478;
            case 0x148480u: goto label_148480;
            case 0x148484u: goto label_148484;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14848Cu;
    // 0x14848c: 0x0  nop
    ctx->pc = 0x14848cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
