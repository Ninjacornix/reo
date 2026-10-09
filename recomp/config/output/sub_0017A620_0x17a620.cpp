#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A620
// Address: 0x17a620 - 0x17a678
void sub_0017A620_0x17a620(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A620_0x17a620");
#endif

    switch (ctx->pc) {
        case 0x17a65cu: goto label_17a65c;
        default: break;
    }

    ctx->pc = 0x17a620u;

    // 0x17a620: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17a620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a624: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17a624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17a628: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17a628u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a62c: 0x805e98e  j           func_17A638
    ctx->pc = 0x17A62Cu;
    ctx->pc = 0x17A630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A62Cu;
            // 0x17a630: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A638u;
    goto label_17a638;
    ctx->pc = 0x17A634u;
    // 0x17a634: 0x0  nop
    ctx->pc = 0x17a634u;
    // NOP
label_17a638:
    // 0x17a638: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17a638u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a63c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17a63cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a640: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a644: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x17a644u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x17a648: 0x2610f1f0  addiu       $s0, $s0, -0xE10
    ctx->pc = 0x17a648u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963696));
    // 0x17a64c: 0x240600a8  addiu       $a2, $zero, 0xA8
    ctx->pc = 0x17a64cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 168));
    // 0x17a650: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17a650u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17a654: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x17A654u;
    SET_GPR_U32(ctx, 31, 0x17A65Cu);
    ctx->pc = 0x17A658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A654u;
            // 0x17a658: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A65Cu; }
        if (ctx->pc != 0x17A65Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A65Cu; }
        if (ctx->pc != 0x17A65Cu) { return; }
    }
    ctx->pc = 0x17A65Cu;
label_17a65c:
    // 0x17a65c: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x17a65cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x17a660: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x17a660u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x17a664: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17a664u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a668: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a668u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a66c: 0x3e00008  jr          $ra
    ctx->pc = 0x17A66Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A66Cu;
            // 0x17a670: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A638u: goto label_17a638;
            case 0x17A65Cu: goto label_17a65c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A674u;
    // 0x17a674: 0x0  nop
    ctx->pc = 0x17a674u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
