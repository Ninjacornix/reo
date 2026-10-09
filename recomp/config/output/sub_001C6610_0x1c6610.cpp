#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6610
// Address: 0x1c6610 - 0x1c6660
void sub_001C6610_0x1c6610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6610_0x1c6610");
#endif

    switch (ctx->pc) {
        case 0x1c6628u: goto label_1c6628;
        case 0x1c6640u: goto label_1c6640;
        case 0x1c6648u: goto label_1c6648;
        default: break;
    }

    ctx->pc = 0x1c6610u;

    // 0x1c6610: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c6610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c6614: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c6614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c6618: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c6618u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c661c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1c661cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6620: 0xc072254  jal         func_1C8950
    ctx->pc = 0x1C6620u;
    SET_GPR_U32(ctx, 31, 0x1C6628u);
    ctx->pc = 0x1C6624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6620u;
            // 0x1c6624: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8950u;
    if (runtime->hasFunction(0x1C8950u)) {
        auto targetFn = runtime->lookupFunction(0x1C8950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6628u; }
        if (ctx->pc != 0x1C6628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8950_0x1c8950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6628u; }
        if (ctx->pc != 0x1C6628u) { return; }
    }
    ctx->pc = 0x1C6628u;
label_1c6628:
    // 0x1c6628: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c6628u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c662c: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x1c662cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1c6630: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x1c6630u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1c6634: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1c6634u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c6638: 0xc041ed8  jal         func_107B60
    ctx->pc = 0x1C6638u;
    SET_GPR_U32(ctx, 31, 0x1C6640u);
    ctx->pc = 0x1C663Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6638u;
            // 0x1c663c: 0x822821  addu        $a1, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107B60u;
    if (runtime->hasFunction(0x107B60u)) {
        auto targetFn = runtime->lookupFunction(0x107B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6640u; }
        if (ctx->pc != 0x1C6640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107B60_0x107b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6640u; }
        if (ctx->pc != 0x1C6640u) { return; }
    }
    ctx->pc = 0x1C6640u;
label_1c6640:
    // 0x1c6640: 0xc072294  jal         func_1C8A50
    ctx->pc = 0x1C6640u;
    SET_GPR_U32(ctx, 31, 0x1C6648u);
    ctx->pc = 0x1C6644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6640u;
            // 0x1c6644: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8A50u;
    if (runtime->hasFunction(0x1C8A50u)) {
        auto targetFn = runtime->lookupFunction(0x1C8A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6648u; }
        if (ctx->pc != 0x1C6648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8A50_0x1c8a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C6648u; }
        if (ctx->pc != 0x1C6648u) { return; }
    }
    ctx->pc = 0x1C6648u;
label_1c6648:
    // 0x1c6648: 0xae30000c  sw          $s0, 0xC($s1)
    ctx->pc = 0x1c6648u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 16));
    // 0x1c664c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c664cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c6650: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c6650u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c6654: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c6654u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c6658: 0x3e00008  jr          $ra
    ctx->pc = 0x1C6658u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C665Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6658u;
            // 0x1c665c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C6628u: goto label_1c6628;
            case 0x1C6640u: goto label_1c6640;
            case 0x1C6648u: goto label_1c6648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6660u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
