#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169638
// Address: 0x169638 - 0x1696b0
void sub_00169638_0x169638(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169638_0x169638");
#endif

    switch (ctx->pc) {
        case 0x169668u: goto label_169668;
        case 0x169674u: goto label_169674;
        default: break;
    }

    ctx->pc = 0x169638u;

    // 0x169638: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x169638u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16963c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16963cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x169640: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x169640u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169644: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x169644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x169648: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x169648u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16964c: 0x230102a  slt         $v0, $s1, $s0
    ctx->pc = 0x16964cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x169650: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x169650u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x169654: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x169654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x169658: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x169658u;
    {
        const bool branch_taken_0x169658 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16965Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169658u;
            // 0x16965c: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169658) {
            ctx->pc = 0x169694u;
            goto label_169694;
        }
    }
    ctx->pc = 0x169660u;
    // 0x169660: 0x320500ff  andi        $a1, $s0, 0xFF
    ctx->pc = 0x169660u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x169664: 0x0  nop
    ctx->pc = 0x169664u;
    // NOP
label_169668:
    // 0x169668: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x169668u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16966c: 0xc05e4fe  jal         func_1793F8
    ctx->pc = 0x16966Cu;
    SET_GPR_U32(ctx, 31, 0x169674u);
    ctx->pc = 0x169670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16966Cu;
            // 0x169670: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1793F8u;
    if (runtime->hasFunction(0x1793F8u)) {
        auto targetFn = runtime->lookupFunction(0x1793F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169674u; }
        if (ctx->pc != 0x169674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001793F8_0x1793f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169674u; }
        if (ctx->pc != 0x169674u) { return; }
    }
    ctx->pc = 0x169674u;
label_169674:
    // 0x169674: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x169674u;
    {
        const bool branch_taken_0x169674 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x169678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169674u;
            // 0x169678: 0x8fa30000  lw          $v1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169674) {
            ctx->pc = 0x169684u;
            goto label_169684;
        }
    }
    ctx->pc = 0x16967Cu;
    // 0x16967c: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x16967Cu;
    {
        const bool branch_taken_0x16967c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x169680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16967Cu;
            // 0x169680: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16967c) {
            ctx->pc = 0x169698u;
            goto label_169698;
        }
    }
    ctx->pc = 0x169684u;
label_169684:
    // 0x169684: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x169684u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x169688: 0x230102a  slt         $v0, $s1, $s0
    ctx->pc = 0x169688u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x16968c: 0x1040fff6  beqz        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x16968Cu;
    {
        const bool branch_taken_0x16968c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x169690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16968Cu;
            // 0x169690: 0x320500ff  andi        $a1, $s0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16968c) {
            ctx->pc = 0x169668u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_169668;
        }
    }
    ctx->pc = 0x169694u;
label_169694:
    // 0x169694: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x169694u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_169698:
    // 0x169698: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x169698u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16969c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16969cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1696a0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1696a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1696a4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1696a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1696a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1696A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1696ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1696A8u;
            // 0x1696ac: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169668u: goto label_169668;
            case 0x169674u: goto label_169674;
            case 0x169684u: goto label_169684;
            case 0x169694u: goto label_169694;
            case 0x169698u: goto label_169698;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1696B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
