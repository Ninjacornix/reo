#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161A28
// Address: 0x161a28 - 0x161a80
void sub_00161A28_0x161a28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161A28_0x161a28");
#endif

    switch (ctx->pc) {
        case 0x161a5cu: goto label_161a5c;
        default: break;
    }

    ctx->pc = 0x161a28u;

    // 0x161a28: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161a28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161a2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161a30: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x161a30u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161a34: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161a34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x161a38: 0x8e0200e8  lw          $v0, 0xE8($s0)
    ctx->pc = 0x161a38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x161a3c: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x161A3Cu;
    {
        const bool branch_taken_0x161a3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x161A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161A3Cu;
            // 0x161a40: 0x26030100  addiu       $v1, $s0, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161a3c) {
            ctx->pc = 0x161A70u;
            goto label_161a70;
        }
    }
    ctx->pc = 0x161A44u;
    // 0x161a44: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x161a44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x161a48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x161a48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x161a4c: 0x50620009  beql        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x161A4Cu;
    {
        const bool branch_taken_0x161a4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x161a4c) {
            ctx->pc = 0x161A50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x161A4Cu;
            // 0x161a50: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x161A74u;
            goto label_161a74;
        }
    }
    ctx->pc = 0x161A54u;
    // 0x161a54: 0xc0586b2  jal         func_161AC8
    ctx->pc = 0x161A54u;
    SET_GPR_U32(ctx, 31, 0x161A5Cu);
    ctx->pc = 0x161AC8u;
    if (runtime->hasFunction(0x161AC8u)) {
        auto targetFn = runtime->lookupFunction(0x161AC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161A5Cu; }
        if (ctx->pc != 0x161A5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00161AC8_0x161ac8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161A5Cu; }
        if (ctx->pc != 0x161A5Cu) { return; }
    }
    ctx->pc = 0x161A5Cu;
label_161a5c:
    // 0x161a5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161a5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161a60: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161a60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161a64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161a64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161a68: 0x805871e  j           func_161C78
    ctx->pc = 0x161A68u;
    ctx->pc = 0x161A6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161A68u;
            // 0x161a6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161C78u;
    if (runtime->hasFunction(0x161C78u)) {
        auto targetFn = runtime->lookupFunction(0x161C78u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00161C78_0x161c78(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x161A70u;
label_161a70:
    // 0x161a70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161a70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_161a74:
    // 0x161a74: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161a74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161a78: 0x3e00008  jr          $ra
    ctx->pc = 0x161A78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161A78u;
            // 0x161a7c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161A5Cu: goto label_161a5c;
            case 0x161A70u: goto label_161a70;
            case 0x161A74u: goto label_161a74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161A80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
