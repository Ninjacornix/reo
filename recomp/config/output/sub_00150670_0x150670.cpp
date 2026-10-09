#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150670
// Address: 0x150670 - 0x1506bc
void sub_00150670_0x150670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150670_0x150670");
#endif

    switch (ctx->pc) {
        case 0x150698u: goto label_150698;
        case 0x1506a8u: goto label_1506a8;
        default: break;
    }

    ctx->pc = 0x150670u;

    // 0x150670: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150674: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x150674u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150678: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150678u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15067c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15067cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150680: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x150680u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x150684: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x150684u;
    {
        const bool branch_taken_0x150684 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x150688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150684u;
            // 0x150688: 0x24440004  addiu       $a0, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150684) {
            ctx->pc = 0x1506A0u;
            goto label_1506a0;
        }
    }
    ctx->pc = 0x15068Cu;
    // 0x15068c: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x15068cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x150690: 0xc0541b0  jal         func_1506C0
    ctx->pc = 0x150690u;
    SET_GPR_U32(ctx, 31, 0x150698u);
    ctx->pc = 0x150694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150690u;
            // 0x150694: 0x2484d858  addiu       $a0, $a0, -0x27A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1506C0u;
    if (runtime->hasFunction(0x1506C0u)) {
        auto targetFn = runtime->lookupFunction(0x1506C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150698u; }
        if (ctx->pc != 0x150698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001506C0_0x1506c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150698u; }
        if (ctx->pc != 0x150698u) { return; }
    }
    ctx->pc = 0x150698u;
label_150698:
    // 0x150698: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x150698u;
    {
        const bool branch_taken_0x150698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15069Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150698u;
            // 0x15069c: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150698) {
            ctx->pc = 0x1506ACu;
            goto label_1506ac;
        }
    }
    ctx->pc = 0x1506A0u;
label_1506a0:
    // 0x1506a0: 0xc0541b0  jal         func_1506C0
    ctx->pc = 0x1506A0u;
    SET_GPR_U32(ctx, 31, 0x1506A8u);
    ctx->pc = 0x1506C0u;
    if (runtime->hasFunction(0x1506C0u)) {
        auto targetFn = runtime->lookupFunction(0x1506C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1506A8u; }
        if (ctx->pc != 0x1506A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001506C0_0x1506c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1506A8u; }
        if (ctx->pc != 0x1506A8u) { return; }
    }
    ctx->pc = 0x1506A8u;
label_1506a8:
    // 0x1506a8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1506a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1506ac:
    // 0x1506ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1506acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1506b0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1506b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1506b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1506B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1506B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1506B4u;
            // 0x1506b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150698u: goto label_150698;
            case 0x1506A0u: goto label_1506a0;
            case 0x1506A8u: goto label_1506a8;
            case 0x1506ACu: goto label_1506ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1506BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
