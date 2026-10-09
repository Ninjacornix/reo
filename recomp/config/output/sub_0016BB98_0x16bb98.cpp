#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016BB98
// Address: 0x16bb98 - 0x16bbe8
void sub_0016BB98_0x16bb98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016BB98_0x16bb98");
#endif

    switch (ctx->pc) {
        case 0x16bbbcu: goto label_16bbbc;
        default: break;
    }

    ctx->pc = 0x16bb98u;

    // 0x16bb98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16bb98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16bb9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16bb9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16bba0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16bba0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bba4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16bba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16bba8: 0x8e032ab0  lw          $v1, 0x2AB0($s0)
    ctx->pc = 0x16bba8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x16bbac: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x16BBACu;
    {
        const bool branch_taken_0x16bbac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BBB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BBACu;
            // 0x16bbb0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bbac) {
            ctx->pc = 0x16BBD4u;
            goto label_16bbd4;
        }
    }
    ctx->pc = 0x16BBB4u;
    // 0x16bbb4: 0xc05aefa  jal         func_16BBE8
    ctx->pc = 0x16BBB4u;
    SET_GPR_U32(ctx, 31, 0x16BBBCu);
    ctx->pc = 0x16BBE8u;
    if (runtime->hasFunction(0x16BBE8u)) {
        auto targetFn = runtime->lookupFunction(0x16BBE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BBBCu; }
        if (ctx->pc != 0x16BBBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BBE8_0x16bbe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BBBCu; }
        if (ctx->pc != 0x16BBBCu) { return; }
    }
    ctx->pc = 0x16BBBCu;
label_16bbbc:
    // 0x16bbbc: 0x58400004  blezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16BBBCu;
    {
        const bool branch_taken_0x16bbbc = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x16bbbc) {
            ctx->pc = 0x16BBC0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16BBBCu;
            // 0x16bbc0: 0x8e022ab0  lw          $v0, 0x2AB0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16BBD0u;
            goto label_16bbd0;
        }
    }
    ctx->pc = 0x16BBC4u;
    // 0x16bbc4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x16BBC4u;
    {
        const bool branch_taken_0x16bbc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BBC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BBC4u;
            // 0x16bbc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bbc4) {
            ctx->pc = 0x16BBD4u;
            goto label_16bbd4;
        }
    }
    ctx->pc = 0x16BBCCu;
    // 0x16bbcc: 0x0  nop
    ctx->pc = 0x16bbccu;
    // NOP
label_16bbd0:
    // 0x16bbd0: 0x244208a0  addiu       $v0, $v0, 0x8A0
    ctx->pc = 0x16bbd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2208));
label_16bbd4:
    // 0x16bbd4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16bbd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bbd8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16bbd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bbdc: 0x3e00008  jr          $ra
    ctx->pc = 0x16BBDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BBE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BBDCu;
            // 0x16bbe0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BBBCu: goto label_16bbbc;
            case 0x16BBD0u: goto label_16bbd0;
            case 0x16BBD4u: goto label_16bbd4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BBE4u;
    // 0x16bbe4: 0x0  nop
    ctx->pc = 0x16bbe4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
