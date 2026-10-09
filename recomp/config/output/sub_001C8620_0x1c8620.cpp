#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8620
// Address: 0x1c8620 - 0x1c8660
void sub_001C8620_0x1c8620(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8620_0x1c8620");
#endif

    switch (ctx->pc) {
        case 0x1c864cu: goto label_1c864c;
        default: break;
    }

    ctx->pc = 0x1c8620u;

    // 0x1c8620: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c8620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c8624: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c8624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c8628: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c862c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c862cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c8630: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C8630u;
    {
        const bool branch_taken_0x1c8630 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C8634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8630u;
            // 0x1c8634: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8630) {
            ctx->pc = 0x1C8640u;
            goto label_1c8640;
        }
    }
    ctx->pc = 0x1C8638u;
    // 0x1c8638: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C8638u;
    {
        const bool branch_taken_0x1c8638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C863Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8638u;
            // 0x1c863c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8638) {
            ctx->pc = 0x1C8654u;
            goto label_1c8654;
        }
    }
    ctx->pc = 0x1C8640u;
label_1c8640:
    // 0x1c8640: 0x8cc5000c  lw          $a1, 0xC($a2)
    ctx->pc = 0x1c8640u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x1c8644: 0xc071b44  jal         func_1C6D10
    ctx->pc = 0x1C8644u;
    SET_GPR_U32(ctx, 31, 0x1C864Cu);
    ctx->pc = 0x1C8648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8644u;
            // 0x1c8648: 0x8cc40008  lw          $a0, 0x8($a2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C6D10u;
    if (runtime->hasFunction(0x1C6D10u)) {
        auto targetFn = runtime->lookupFunction(0x1C6D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C864Cu; }
        if (ctx->pc != 0x1C864Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C6D10_0x1c6d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C864Cu; }
        if (ctx->pc != 0x1C864Cu) { return; }
    }
    ctx->pc = 0x1C864Cu;
label_1c864c:
    // 0x1c864c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c864cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c8650: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8650u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1c8654:
    // 0x1c8654: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8654u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8654u;
            // 0x1c8658: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8640u: goto label_1c8640;
            case 0x1C864Cu: goto label_1c864c;
            case 0x1C8654u: goto label_1c8654;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C865Cu;
    // 0x1c865c: 0x0  nop
    ctx->pc = 0x1c865cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
