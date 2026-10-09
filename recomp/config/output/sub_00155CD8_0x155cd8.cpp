#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155CD8
// Address: 0x155cd8 - 0x155d28
void sub_00155CD8_0x155cd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155CD8_0x155cd8");
#endif

    switch (ctx->pc) {
        case 0x155cecu: goto label_155cec;
        default: break;
    }

    ctx->pc = 0x155cd8u;

    // 0x155cd8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x155cd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x155cdc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x155cdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x155ce0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x155ce0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x155ce4: 0xc05578e  jal         func_155E38
    ctx->pc = 0x155CE4u;
    SET_GPR_U32(ctx, 31, 0x155CECu);
    ctx->pc = 0x155CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155CE4u;
            // 0x155ce8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155CECu; }
        if (ctx->pc != 0x155CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155CECu; }
        if (ctx->pc != 0x155CECu) { return; }
    }
    ctx->pc = 0x155CECu;
label_155cec:
    // 0x155cec: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x155cecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x155cf0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x155cf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155cf4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x155CF4u;
    {
        const bool branch_taken_0x155cf4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x155CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155CF4u;
            // 0x155cf8: 0x34a50201  ori         $a1, $a1, 0x201 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)513);
        ctx->in_delay_slot = false;
        if (branch_taken_0x155cf4) {
            ctx->pc = 0x155D10u;
            goto label_155d10;
        }
    }
    ctx->pc = 0x155CFCu;
    // 0x155cfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155cfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155d00: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x155d00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155d04: 0x805419c  j           func_150670
    ctx->pc = 0x155D04u;
    ctx->pc = 0x155D08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155D04u;
            // 0x155d08: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x155D0Cu;
    // 0x155d0c: 0x0  nop
    ctx->pc = 0x155d0cu;
    // NOP
label_155d10:
    // 0x155d10: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x155d10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x155d14: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x155d14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155d18: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x155d18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x155d1c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155d1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155d20: 0x3e00008  jr          $ra
    ctx->pc = 0x155D20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155D20u;
            // 0x155d24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x155CECu: goto label_155cec;
            case 0x155D10u: goto label_155d10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155D28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
