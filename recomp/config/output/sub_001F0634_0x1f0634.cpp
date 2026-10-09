#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F0634
// Address: 0x1f0634 - 0x1f0718
void sub_001F0634_0x1f0634(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F0634_0x1f0634");
#endif

    switch (ctx->pc) {
        case 0x1f0658u: goto label_1f0658;
        case 0x1f0674u: goto label_1f0674;
        case 0x1f06ecu: goto label_1f06ec;
        case 0x1f0700u: goto label_1f0700;
        default: break;
    }

    ctx->pc = 0x1f0634u;

    // 0x1f0634: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f0634u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f0638: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f0638u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f063c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f063cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f0640: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0640u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0644: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0644u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0648: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f0648u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f064c: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1f064cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1f0650: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f0650u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0654: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f0654u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
label_1f0658:
    // 0x1f0658: 0x27c20008  addiu       $v0, $fp, 0x8
    ctx->pc = 0x1f0658u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f065c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f065cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0660: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f0660u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0664: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f0664u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0668: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1f0668u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f066c: 0xc07ae0c  jal         func_1EB830
    ctx->pc = 0x1F066Cu;
    SET_GPR_U32(ctx, 31, 0x1F0674u);
    ctx->pc = 0x1EB830u;
    if (runtime->hasFunction(0x1EB830u)) {
        auto targetFn = runtime->lookupFunction(0x1EB830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0674u; }
        if (ctx->pc != 0x1F0674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB830_0x1eb830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0674u; }
        if (ctx->pc != 0x1F0674u) { return; }
    }
    ctx->pc = 0x1F0674u;
label_1f0674:
    // 0x1f0674: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1F0674u;
    {
        const bool branch_taken_0x1f0674 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f0674) {
            ctx->pc = 0x1F0658u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f0658;
        }
    }
    ctx->pc = 0x1F067Cu;
    // 0x1f067c: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1f067cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0680: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0680u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0684: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f0684u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f0688: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f0688u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f068c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f068cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f0690: 0x24430004  addiu       $v1, $v0, 0x4
    ctx->pc = 0x1f0690u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f0694: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f0694u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f0698: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1f0698u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1f069c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f069cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f06a0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f06a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f06a4: 0x24430008  addiu       $v1, $v0, 0x8
    ctx->pc = 0x1f06a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f06a8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f06a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f06ac: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1f06acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1f06b0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f06b0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f06b4: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f06b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f06b8: 0x2443000c  addiu       $v1, $v0, 0xC
    ctx->pc = 0x1f06b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1f06bc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f06bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f06c0: 0x8c42000c  lw          $v0, 0xC($v0)
    ctx->pc = 0x1f06c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f06c4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f06c4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f06c8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f06c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f06cc: 0x24430010  addiu       $v1, $v0, 0x10
    ctx->pc = 0x1f06ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1f06d0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f06d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f06d4: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1f06d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1f06d8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f06d8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f06dc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f06dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f06e0: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x1f06e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1f06e4: 0xc07add9  jal         func_1EB764
    ctx->pc = 0x1F06E4u;
    SET_GPR_U32(ctx, 31, 0x1F06ECu);
    ctx->pc = 0x1EB764u;
    if (runtime->hasFunction(0x1EB764u)) {
        auto targetFn = runtime->lookupFunction(0x1EB764u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F06ECu; }
        if (ctx->pc != 0x1F06ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB764_0x1eb764(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F06ECu; }
        if (ctx->pc != 0x1F06ECu) { return; }
    }
    ctx->pc = 0x1F06ECu;
label_1f06ec:
    // 0x1f06ec: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f06ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f06f0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f06f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f06f4: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f06f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f06f8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F06F8u;
    SET_GPR_U32(ctx, 31, 0x1F0700u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0700u; }
        if (ctx->pc != 0x1F0700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0700u; }
        if (ctx->pc != 0x1F0700u) { return; }
    }
    ctx->pc = 0x1F0700u;
label_1f0700:
    // 0x1f0700: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f0700u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0704: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f0704u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f0708: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f0708u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f070c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f070cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f0710: 0x3e00008  jr          $ra
    ctx->pc = 0x1F0710u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0658u: goto label_1f0658;
            case 0x1F0674u: goto label_1f0674;
            case 0x1F06ECu: goto label_1f06ec;
            case 0x1F0700u: goto label_1f0700;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F0718u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
