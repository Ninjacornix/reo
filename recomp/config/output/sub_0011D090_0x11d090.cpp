#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D090
// Address: 0x11d090 - 0x11d0d0
void sub_0011D090_0x11d090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D090_0x11d090");
#endif

    switch (ctx->pc) {
        case 0x11d0a0u: goto label_11d0a0;
        case 0x11d0b4u: goto label_11d0b4;
        case 0x11d0c4u: goto label_11d0c4;
        default: break;
    }

    ctx->pc = 0x11d090u;

    // 0x11d090: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11d090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11d094: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11d094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11d098: 0xc0452a0  jal         func_114A80
    ctx->pc = 0x11D098u;
    SET_GPR_U32(ctx, 31, 0x11D0A0u);
    ctx->pc = 0x114A80u;
    if (runtime->hasFunction(0x114A80u)) {
        auto targetFn = runtime->lookupFunction(0x114A80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D0A0u; }
        if (ctx->pc != 0x11D0A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A80_0x114a80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D0A0u; }
        if (ctx->pc != 0x11D0A0u) { return; }
    }
    ctx->pc = 0x11D0A0u;
label_11d0a0:
    // 0x11d0a0: 0x3c030200  lui         $v1, 0x200
    ctx->pc = 0x11d0a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)512 << 16));
    // 0x11d0a4: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x11D0A4u;
    {
        const bool branch_taken_0x11d0a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x11d0a4) {
            ctx->pc = 0x11D0BCu;
            goto label_11d0bc;
        }
    }
    ctx->pc = 0x11D0ACu;
    // 0x11d0ac: 0xc047434  jal         func_11D0D0
    ctx->pc = 0x11D0ACu;
    SET_GPR_U32(ctx, 31, 0x11D0B4u);
    ctx->pc = 0x11D0D0u;
    if (runtime->hasFunction(0x11D0D0u)) {
        auto targetFn = runtime->lookupFunction(0x11D0D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D0B4u; }
        if (ctx->pc != 0x11D0B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D0D0_0x11d0d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D0B4u; }
        if (ctx->pc != 0x11D0B4u) { return; }
    }
    ctx->pc = 0x11D0B4u;
label_11d0b4:
    // 0x11d0b4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x11D0B4u;
    {
        const bool branch_taken_0x11d0b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11D0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D0B4u;
            // 0x11d0b8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11d0b4) {
            ctx->pc = 0x11D0C8u;
            goto label_11d0c8;
        }
    }
    ctx->pc = 0x11D0BCu;
label_11d0bc:
    // 0x11d0bc: 0xc0452a4  jal         func_114A90
    ctx->pc = 0x11D0BCu;
    SET_GPR_U32(ctx, 31, 0x11D0C4u);
    ctx->pc = 0x114A90u;
    if (runtime->hasFunction(0x114A90u)) {
        auto targetFn = runtime->lookupFunction(0x114A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D0C4u; }
        if (ctx->pc != 0x11D0C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A90_0x114a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D0C4u; }
        if (ctx->pc != 0x11D0C4u) { return; }
    }
    ctx->pc = 0x11D0C4u;
label_11d0c4:
    // 0x11d0c4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11d0c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_11d0c8:
    // 0x11d0c8: 0x3e00008  jr          $ra
    ctx->pc = 0x11D0C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D0CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D0C8u;
            // 0x11d0cc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D0A0u: goto label_11d0a0;
            case 0x11D0B4u: goto label_11d0b4;
            case 0x11D0BCu: goto label_11d0bc;
            case 0x11D0C4u: goto label_11d0c4;
            case 0x11D0C8u: goto label_11d0c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D0D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
