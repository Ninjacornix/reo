#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00171B98
// Address: 0x171b98 - 0x171bdc
void sub_00171B98_0x171b98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00171B98_0x171b98");
#endif

    switch (ctx->pc) {
        case 0x171bbcu: goto label_171bbc;
        default: break;
    }

    ctx->pc = 0x171b98u;

    // 0x171b98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x171b98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x171b9c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x171b9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x171ba0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x171ba0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171ba4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x171ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x171ba8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x171ba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171bac: 0x8c901b30  lw          $s0, 0x1B30($a0)
    ctx->pc = 0x171bacu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 6960)));
    // 0x171bb0: 0x26040a48  addiu       $a0, $s0, 0xA48
    ctx->pc = 0x171bb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2632));
    // 0x171bb4: 0xc05c534  jal         func_1714D0
    ctx->pc = 0x171BB4u;
    SET_GPR_U32(ctx, 31, 0x171BBCu);
    ctx->pc = 0x171BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171BB4u;
            // 0x171bb8: 0x261009d8  addiu       $s0, $s0, 0x9D8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2520));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1714D0u;
    if (runtime->hasFunction(0x1714D0u)) {
        auto targetFn = runtime->lookupFunction(0x1714D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171BBCu; }
        if (ctx->pc != 0x171BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001714D0_0x1714d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171BBCu; }
        if (ctx->pc != 0x171BBCu) { return; }
    }
    ctx->pc = 0x171BBCu;
label_171bbc:
    // 0x171bbc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x171bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x171bc0: 0xae110020  sw          $s1, 0x20($s0)
    ctx->pc = 0x171bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 17));
    // 0x171bc4: 0xae02001c  sw          $v0, 0x1C($s0)
    ctx->pc = 0x171bc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
    // 0x171bc8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x171bc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171bcc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171bccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171bd0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x171bd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171bd4: 0x3e00008  jr          $ra
    ctx->pc = 0x171BD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x171BD4u;
            // 0x171bd8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x171BBCu: goto label_171bbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171BDCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
