#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC6A0
// Address: 0x1bc6a0 - 0x1bc6ec
void sub_001BC6A0_0x1bc6a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC6A0_0x1bc6a0");
#endif

    switch (ctx->pc) {
        case 0x1bc6d0u: goto label_1bc6d0;
        case 0x1bc6e0u: goto label_1bc6e0;
        default: break;
    }

    ctx->pc = 0x1bc6a0u;

    // 0x1bc6a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bc6a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bc6a4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1bc6a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bc6a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bc6a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bc6ac: 0x90850008  lbu         $a1, 0x8($a0)
    ctx->pc = 0x1bc6acu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1bc6b0: 0x10a30009  beq         $a1, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BC6B0u;
    {
        const bool branch_taken_0x1bc6b0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bc6b0) {
            ctx->pc = 0x1BC6D8u;
            goto label_1bc6d8;
        }
    }
    ctx->pc = 0x1BC6B8u;
    // 0x1bc6b8: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BC6B8u;
    {
        const bool branch_taken_0x1bc6b8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bc6b8) {
            ctx->pc = 0x1BC6C8u;
            goto label_1bc6c8;
        }
    }
    ctx->pc = 0x1BC6C0u;
    // 0x1bc6c0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1BC6C0u;
    {
        const bool branch_taken_0x1bc6c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC6C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC6C0u;
            // 0x1bc6c4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc6c0) {
            ctx->pc = 0x1BC6E4u;
            goto label_1bc6e4;
        }
    }
    ctx->pc = 0x1BC6C8u;
label_1bc6c8:
    // 0x1bc6c8: 0xc06f1bc  jal         func_1BC6F0
    ctx->pc = 0x1BC6C8u;
    SET_GPR_U32(ctx, 31, 0x1BC6D0u);
    ctx->pc = 0x1BC6F0u;
    if (runtime->hasFunction(0x1BC6F0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC6F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC6D0u; }
        if (ctx->pc != 0x1BC6D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC6F0_0x1bc6f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC6D0u; }
        if (ctx->pc != 0x1BC6D0u) { return; }
    }
    ctx->pc = 0x1BC6D0u;
label_1bc6d0:
    // 0x1bc6d0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1BC6D0u;
    {
        const bool branch_taken_0x1bc6d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bc6d0) {
            ctx->pc = 0x1BC6E0u;
            goto label_1bc6e0;
        }
    }
    ctx->pc = 0x1BC6D8u;
label_1bc6d8:
    // 0x1bc6d8: 0xc06f21c  jal         func_1BC870
    ctx->pc = 0x1BC6D8u;
    SET_GPR_U32(ctx, 31, 0x1BC6E0u);
    ctx->pc = 0x1BC870u;
    if (runtime->hasFunction(0x1BC870u)) {
        auto targetFn = runtime->lookupFunction(0x1BC870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC6E0u; }
        if (ctx->pc != 0x1BC6E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC870_0x1bc870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BC6E0u; }
        if (ctx->pc != 0x1BC6E0u) { return; }
    }
    ctx->pc = 0x1BC6E0u;
label_1bc6e0:
    // 0x1bc6e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bc6e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1bc6e4:
    // 0x1bc6e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC6E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC6E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC6E4u;
            // 0x1bc6e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BC6C8u: goto label_1bc6c8;
            case 0x1BC6D0u: goto label_1bc6d0;
            case 0x1BC6D8u: goto label_1bc6d8;
            case 0x1BC6E0u: goto label_1bc6e0;
            case 0x1BC6E4u: goto label_1bc6e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC6ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
