#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3610
// Address: 0x1f3610 - 0x1f3694
void sub_001F3610_0x1f3610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3610_0x1f3610");
#endif

    switch (ctx->pc) {
        case 0x1f3638u: goto label_1f3638;
        case 0x1f3664u: goto label_1f3664;
        case 0x1f3678u: goto label_1f3678;
        default: break;
    }

    ctx->pc = 0x1f3610u;

    // 0x1f3610: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f3610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f3614: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f3614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f3618: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f3618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f361c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f361cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3620: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f3620u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f3624: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f3624u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f3628: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f3628u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f362c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f362cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3630: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F3630u;
    SET_GPR_U32(ctx, 31, 0x1F3638u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3638u; }
        if (ctx->pc != 0x1F3638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3638u; }
        if (ctx->pc != 0x1F3638u) { return; }
    }
    ctx->pc = 0x1F3638u;
label_1f3638:
    // 0x1f3638: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f3638u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f363c: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1f363cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3640: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f3640u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3644: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1f3644u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1f3648: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3648u;
    {
        const bool branch_taken_0x1f3648 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3648) {
            ctx->pc = 0x1F3658u;
            goto label_1f3658;
        }
    }
    ctx->pc = 0x1F3650u;
    // 0x1f3650: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f3650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3654: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f3654u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
label_1f3658:
    // 0x1f3658: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3658u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f365c: 0xc07cd3b  jal         func_1F34EC
    ctx->pc = 0x1F365Cu;
    SET_GPR_U32(ctx, 31, 0x1F3664u);
    ctx->pc = 0x1F34ECu;
    if (runtime->hasFunction(0x1F34ECu)) {
        auto targetFn = runtime->lookupFunction(0x1F34ECu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3664u; }
        if (ctx->pc != 0x1F3664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34EC_0x1f34ec(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3664u; }
        if (ctx->pc != 0x1F3664u) { return; }
    }
    ctx->pc = 0x1F3664u;
label_1f3664:
    // 0x1f3664: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f3664u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3668: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f3668u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f366c: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1f366cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f3670: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F3670u;
    SET_GPR_U32(ctx, 31, 0x1F3678u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3678u; }
        if (ctx->pc != 0x1F3678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3678u; }
        if (ctx->pc != 0x1F3678u) { return; }
    }
    ctx->pc = 0x1F3678u;
label_1f3678:
    // 0x1f3678: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f3678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f367c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f367cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3680: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f3680u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3684: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f3684u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f3688: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f3688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f368c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F368Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3638u: goto label_1f3638;
            case 0x1F3658u: goto label_1f3658;
            case 0x1F3664u: goto label_1f3664;
            case 0x1F3678u: goto label_1f3678;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3694u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
