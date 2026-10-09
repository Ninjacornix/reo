#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D0A0
// Address: 0x13d0a0 - 0x13d0d0
void sub_0013D0A0_0x13d0a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D0A0_0x13d0a0");
#endif

    switch (ctx->pc) {
        case 0x13d0b8u: goto label_13d0b8;
        default: break;
    }

    ctx->pc = 0x13d0a0u;

    // 0x13d0a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d0a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d0a4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D0A4u;
    {
        const bool branch_taken_0x13d0a4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D0A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D0A4u;
            // 0x13d0a8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d0a4) {
            ctx->pc = 0x13D0C0u;
            goto label_13d0c0;
        }
    }
    ctx->pc = 0x13D0ACu;
    // 0x13d0ac: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d0acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d0b0: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D0B0u;
    SET_GPR_U32(ctx, 31, 0x13D0B8u);
    ctx->pc = 0x13D0B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D0B0u;
            // 0x13d0b4: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D0B8u; }
        if (ctx->pc != 0x13D0B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D0B8u; }
        if (ctx->pc != 0x13D0B8u) { return; }
    }
    ctx->pc = 0x13D0B8u;
label_13d0b8:
    // 0x13d0b8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13D0B8u;
    {
        const bool branch_taken_0x13d0b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D0BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D0B8u;
            // 0x13d0bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d0b8) {
            ctx->pc = 0x13D0C4u;
            goto label_13d0c4;
        }
    }
    ctx->pc = 0x13D0C0u;
label_13d0c0:
    // 0x13d0c0: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x13d0c0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
label_13d0c4:
    // 0x13d0c4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d0c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d0c8: 0x3e00008  jr          $ra
    ctx->pc = 0x13D0C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D0CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D0C8u;
            // 0x13d0cc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D0B8u: goto label_13d0b8;
            case 0x13D0C0u: goto label_13d0c0;
            case 0x13D0C4u: goto label_13d0c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D0D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
