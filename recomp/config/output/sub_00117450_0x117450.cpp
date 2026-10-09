#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117450
// Address: 0x117450 - 0x117490
void sub_00117450_0x117450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117450_0x117450");
#endif

    switch (ctx->pc) {
        case 0x117478u: goto label_117478;
        default: break;
    }

    ctx->pc = 0x117450u;

    // 0x117450: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x117450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x117454: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x117454u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117458: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x117458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11745c: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11745cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117460: 0x34840008  ori         $a0, $a0, 0x8
    ctx->pc = 0x117460u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x117464: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x117464u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117468: 0x8ca70024  lw          $a3, 0x24($a1)
    ctx->pc = 0x117468u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x11746c: 0x8ca80028  lw          $t0, 0x28($a1)
    ctx->pc = 0x11746cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x117470: 0xc045b92  jal         func_116E48
    ctx->pc = 0x117470u;
    SET_GPR_U32(ctx, 31, 0x117478u);
    ctx->pc = 0x117474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117470u;
            // 0x117474: 0x8ca9002c  lw          $t1, 0x2C($a1) (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 44)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E48u;
    if (runtime->hasFunction(0x116E48u)) {
        auto targetFn = runtime->lookupFunction(0x116E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117478u; }
        if (ctx->pc != 0x117478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E48_0x116e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117478u; }
        if (ctx->pc != 0x117478u) { return; }
    }
    ctx->pc = 0x117478u;
label_117478:
    // 0x117478: 0x24030800  addiu       $v1, $zero, 0x800
    ctx->pc = 0x117478u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x11747c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11747cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117480: 0x2180b  movn        $v1, $zero, $v0
    ctx->pc = 0x117480u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x117484: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x117484u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117488: 0x3e00008  jr          $ra
    ctx->pc = 0x117488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11748Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117488u;
            // 0x11748c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117478u: goto label_117478;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117490u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
