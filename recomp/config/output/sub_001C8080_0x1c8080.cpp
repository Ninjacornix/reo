#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8080
// Address: 0x1c8080 - 0x1c80d0
void sub_001C8080_0x1c8080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8080_0x1c8080");
#endif

    switch (ctx->pc) {
        case 0x1c80a8u: goto label_1c80a8;
        default: break;
    }

    ctx->pc = 0x1c8080u;

    // 0x1c8080: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c8080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c8084: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8084u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8088: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c808c: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1c808cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c8090: 0x1460000a  bnez        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1C8090u;
    {
        const bool branch_taken_0x1c8090 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C8094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8090u;
            // 0x1c8094: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8090) {
            ctx->pc = 0x1C80BCu;
            goto label_1c80bc;
        }
    }
    ctx->pc = 0x1C8098u;
    // 0x1c8098: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1c8098u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1c809c: 0x2484cd80  addiu       $a0, $a0, -0x3280
    ctx->pc = 0x1c809cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954368));
    // 0x1c80a0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C80A0u;
    SET_GPR_U32(ctx, 31, 0x1C80A8u);
    ctx->pc = 0x1C80A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C80A0u;
            // 0x1c80a4: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C80A8u; }
        if (ctx->pc != 0x1C80A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C80A8u; }
        if (ctx->pc != 0x1C80A8u) { return; }
    }
    ctx->pc = 0x1C80A8u;
label_1c80a8:
    // 0x1c80a8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c80a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c80ac: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c80acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c80b0: 0xac23cd78  sw          $v1, -0x3288($at)
    ctx->pc = 0x1c80b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294954360), GPR_U32(ctx, 3));
    // 0x1c80b4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c80b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c80b8: 0xac23cd70  sw          $v1, -0x3290($at)
    ctx->pc = 0x1c80b8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294954352), GPR_U32(ctx, 3));
label_1c80bc:
    // 0x1c80bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c80bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c80c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C80C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C80C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C80C0u;
            // 0x1c80c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C80A8u: goto label_1c80a8;
            case 0x1C80BCu: goto label_1c80bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C80C8u;
    // 0x1c80c8: 0x0  nop
    ctx->pc = 0x1c80c8u;
    // NOP
    // 0x1c80cc: 0x0  nop
    ctx->pc = 0x1c80ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
