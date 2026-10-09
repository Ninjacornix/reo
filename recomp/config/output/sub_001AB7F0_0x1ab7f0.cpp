#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB7F0
// Address: 0x1ab7f0 - 0x1ab860
void sub_001AB7F0_0x1ab7f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB7F0_0x1ab7f0");
#endif

    switch (ctx->pc) {
        case 0x1ab820u: goto label_1ab820;
        default: break;
    }

    ctx->pc = 0x1ab7f0u;

    // 0x1ab7f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ab7f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ab7f4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ab7f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ab7f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ab7f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ab7fc: 0x8c230ec0  lw          $v1, 0xEC0($at)
    ctx->pc = 0x1ab7fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 3776)));
    // 0x1ab800: 0x10600014  beqz        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1AB800u;
    {
        const bool branch_taken_0x1ab800 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB800u;
            // 0x1ab804: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab800) {
            ctx->pc = 0x1AB854u;
            goto label_1ab854;
        }
    }
    ctx->pc = 0x1AB808u;
    // 0x1ab808: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ab808u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ab80c: 0x8c2416b0  lw          $a0, 0x16B0($at)
    ctx->pc = 0x1ab80cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5808)));
    // 0x1ab810: 0x14830009  bne         $a0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AB810u;
    {
        const bool branch_taken_0x1ab810 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1AB814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB810u;
            // 0x1ab814: 0x2483ffff  addiu       $v1, $a0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab810) {
            ctx->pc = 0x1AB838u;
            goto label_1ab838;
        }
    }
    ctx->pc = 0x1AB818u;
    // 0x1ab818: 0xc04af64  jal         func_12BD90
    ctx->pc = 0x1AB818u;
    SET_GPR_U32(ctx, 31, 0x1AB820u);
    ctx->pc = 0x12BD90u;
    if (runtime->hasFunction(0x12BD90u)) {
        auto targetFn = runtime->lookupFunction(0x12BD90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB820u; }
        if (ctx->pc != 0x1AB820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD90_0x12bd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB820u; }
        if (ctx->pc != 0x1AB820u) { return; }
    }
    ctx->pc = 0x1AB820u;
label_1ab820:
    // 0x1ab820: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ab820u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ab824: 0x8c2316b0  lw          $v1, 0x16B0($at)
    ctx->pc = 0x1ab824u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5808)));
    // 0x1ab828: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1ab828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1ab82c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ab82cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ab830: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AB830u;
    {
        const bool branch_taken_0x1ab830 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB830u;
            // 0x1ab834: 0xac2316b0  sw          $v1, 0x16B0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 5808), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab830) {
            ctx->pc = 0x1AB854u;
            goto label_1ab854;
        }
    }
    ctx->pc = 0x1AB838u;
label_1ab838:
    // 0x1ab838: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ab838u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ab83c: 0xac2316b0  sw          $v1, 0x16B0($at)
    ctx->pc = 0x1ab83cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 5808), GPR_U32(ctx, 3));
    // 0x1ab840: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ab840u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ab844: 0x8c2316b0  lw          $v1, 0x16B0($at)
    ctx->pc = 0x1ab844u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5808)));
    // 0x1ab848: 0x4610002  bgez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AB848u;
    {
        const bool branch_taken_0x1ab848 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1AB84Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB848u;
            // 0x1ab84c: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab848) {
            ctx->pc = 0x1AB854u;
            goto label_1ab854;
        }
    }
    ctx->pc = 0x1AB850u;
    // 0x1ab850: 0xac2016b0  sw          $zero, 0x16B0($at)
    ctx->pc = 0x1ab850u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 5808), GPR_U32(ctx, 0));
label_1ab854:
    // 0x1ab854: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ab854u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab858: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB858u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB85Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB858u;
            // 0x1ab85c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB820u: goto label_1ab820;
            case 0x1AB838u: goto label_1ab838;
            case 0x1AB854u: goto label_1ab854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB860u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
