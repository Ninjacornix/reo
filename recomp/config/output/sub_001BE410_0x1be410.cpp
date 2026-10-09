#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE410
// Address: 0x1be410 - 0x1be450
void sub_001BE410_0x1be410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE410_0x1be410");
#endif

    switch (ctx->pc) {
        case 0x1be430u: goto label_1be430;
        case 0x1be438u: goto label_1be438;
        default: break;
    }

    ctx->pc = 0x1be410u;

    // 0x1be410: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1be410u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1be414: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1be414u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1be418: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1be418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1be41c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1be41cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1be420: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1be420u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1be424: 0x24a504a0  addiu       $a1, $a1, 0x4A0
    ctx->pc = 0x1be424u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1184));
    // 0x1be428: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BE428u;
    SET_GPR_U32(ctx, 31, 0x1BE430u);
    ctx->pc = 0x1BE42Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE428u;
            // 0x1be42c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE430u; }
        if (ctx->pc != 0x1BE430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE430u; }
        if (ctx->pc != 0x1BE430u) { return; }
    }
    ctx->pc = 0x1BE430u;
label_1be430:
    // 0x1be430: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x1BE430u;
    SET_GPR_U32(ctx, 31, 0x1BE438u);
    ctx->pc = 0x1BE434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE430u;
            // 0x1be434: 0x26040008  addiu       $a0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE438u; }
        if (ctx->pc != 0x1BE438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE438u; }
        if (ctx->pc != 0x1BE438u) { return; }
    }
    ctx->pc = 0x1BE438u;
label_1be438:
    // 0x1be438: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1be438u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1be43c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1be43cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1be440: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE440u;
            // 0x1be444: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BE430u: goto label_1be430;
            case 0x1BE438u: goto label_1be438;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE448u;
    // 0x1be448: 0x0  nop
    ctx->pc = 0x1be448u;
    // NOP
    // 0x1be44c: 0x0  nop
    ctx->pc = 0x1be44cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
