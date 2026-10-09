#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161A80
// Address: 0x161a80 - 0x161ac8
void sub_00161A80_0x161a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161A80_0x161a80");
#endif

    switch (ctx->pc) {
        case 0x161aa4u: goto label_161aa4;
        default: break;
    }

    ctx->pc = 0x161a80u;

    // 0x161a80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161a80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161a84: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161a84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161a88: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161a88u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161a8c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161a8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x161a90: 0x8e0200e8  lw          $v0, 0xE8($s0)
    ctx->pc = 0x161a90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x161a94: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x161A94u;
    {
        const bool branch_taken_0x161a94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x161a94) {
            ctx->pc = 0x161A98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161A94u;
            // 0x161a98: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161AB8u;
            goto label_161ab8;
        }
    }
    ctx->pc = 0x161A9Cu;
    // 0x161a9c: 0xc0586b2  jal         func_161AC8
    ctx->pc = 0x161A9Cu;
    SET_GPR_U32(ctx, 31, 0x161AA4u);
    ctx->pc = 0x161AC8u;
    if (runtime->hasFunction(0x161AC8u)) {
        auto targetFn = runtime->lookupFunction(0x161AC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161AA4u; }
        if (ctx->pc != 0x161AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00161AC8_0x161ac8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161AA4u; }
        if (ctx->pc != 0x161AA4u) { return; }
    }
    ctx->pc = 0x161AA4u;
label_161aa4:
    // 0x161aa4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161aa4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161aa8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161aa8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161aac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161aacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161ab0: 0x805871e  j           func_161C78
    ctx->pc = 0x161AB0u;
    ctx->pc = 0x161AB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161AB0u;
            // 0x161ab4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161C78u;
    if (runtime->hasFunction(0x161C78u)) {
        auto targetFn = runtime->lookupFunction(0x161C78u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00161C78_0x161c78(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161AB8u;
label_161ab8:
    // 0x161ab8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161ab8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161abc: 0x3e00008  jr          $ra
    ctx->pc = 0x161ABCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161ABCu;
            // 0x161ac0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161AA4u: goto label_161aa4;
            case 0x161AB8u: goto label_161ab8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161AC4u;
    // 0x161ac4: 0x0  nop
    ctx->pc = 0x161ac4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
