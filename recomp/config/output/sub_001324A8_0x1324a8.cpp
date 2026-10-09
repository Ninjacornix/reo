#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001324A8
// Address: 0x1324a8 - 0x1324f8
void sub_001324A8_0x1324a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001324A8_0x1324a8");
#endif

    switch (ctx->pc) {
        case 0x1324c0u: goto label_1324c0;
        default: break;
    }

    ctx->pc = 0x1324a8u;

    // 0x1324a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1324a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1324ac: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1324ACu;
    {
        const bool branch_taken_0x1324ac = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1324B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1324ACu;
            // 0x1324b0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1324ac) {
            ctx->pc = 0x1324C8u;
            goto label_1324c8;
        }
    }
    ctx->pc = 0x1324B4u;
    // 0x1324b4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1324b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1324b8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1324B8u;
    SET_GPR_U32(ctx, 31, 0x1324C0u);
    ctx->pc = 0x1324BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1324B8u;
            // 0x1324bc: 0x2484af98  addiu       $a0, $a0, -0x5068 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1324C0u; }
        if (ctx->pc != 0x1324C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1324C0u; }
        if (ctx->pc != 0x1324C0u) { return; }
    }
    ctx->pc = 0x1324C0u;
label_1324c0:
    // 0x1324c0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1324C0u;
    {
        const bool branch_taken_0x1324c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1324C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1324C0u;
            // 0x1324c4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1324c0) {
            ctx->pc = 0x1324E8u;
            goto label_1324e8;
        }
    }
    ctx->pc = 0x1324C8u;
label_1324c8:
    // 0x1324c8: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x1324c8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1324cc: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1324ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1324d0: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1324D0u;
    {
        const bool branch_taken_0x1324d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1324d0) {
            ctx->pc = 0x1324D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1324D0u;
            // 0x1324d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1324E8u;
            goto label_1324e8;
        }
    }
    ctx->pc = 0x1324D8u;
    // 0x1324d8: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1324d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1324dc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1324dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1324e0: 0x804b602  j           func_12D808
    ctx->pc = 0x1324E0u;
    ctx->pc = 0x1324E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1324E0u;
            // 0x1324e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D808u;
    if (runtime->hasFunction(0x12D808u)) {
        auto targetFn = runtime->lookupFunction(0x12D808u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D808_0x12d808(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1324E8u;
label_1324e8:
    // 0x1324e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1324e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1324ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1324ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1324F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1324ECu;
            // 0x1324f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1324C0u: goto label_1324c0;
            case 0x1324C8u: goto label_1324c8;
            case 0x1324E8u: goto label_1324e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1324F4u;
    // 0x1324f4: 0x0  nop
    ctx->pc = 0x1324f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
