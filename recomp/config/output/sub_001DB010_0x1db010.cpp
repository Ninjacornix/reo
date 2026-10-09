#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DB010
// Address: 0x1db010 - 0x1db0b8
void sub_001DB010_0x1db010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DB010_0x1db010");
#endif

    switch (ctx->pc) {
        case 0x1db030u: goto label_1db030;
        case 0x1db064u: goto label_1db064;
        default: break;
    }

    ctx->pc = 0x1db010u;

    // 0x1db010: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1db010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1db014: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1db014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1db018: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1db018u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1db01c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1db01cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db020: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1db020u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1db024: 0x2404001c  addiu       $a0, $zero, 0x1C
    ctx->pc = 0x1db024u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x1db028: 0xc079f1f  jal         func_1E7C7C
    ctx->pc = 0x1DB028u;
    SET_GPR_U32(ctx, 31, 0x1DB030u);
    ctx->pc = 0x1E7C7Cu;
    if (runtime->hasFunction(0x1E7C7Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E7C7Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB030u; }
        if (ctx->pc != 0x1DB030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7C7C_0x1e7c7c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB030u; }
        if (ctx->pc != 0x1DB030u) { return; }
    }
    ctx->pc = 0x1DB030u;
label_1db030:
    // 0x1db030: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1db030u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1db034: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1db034u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db038: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DB038u;
    {
        const bool branch_taken_0x1db038 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1db038) {
            ctx->pc = 0x1DB04Cu;
            goto label_1db04c;
        }
    }
    ctx->pc = 0x1DB040u;
    // 0x1db040: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1db040u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db044: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1DB044u;
    {
        const bool branch_taken_0x1db044 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1db044) {
            ctx->pc = 0x1DB078u;
            goto label_1db078;
        }
    }
    ctx->pc = 0x1DB04Cu;
label_1db04c:
    // 0x1db04c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1db04cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db050: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1db050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1db054: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1db054u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db058: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1db058u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db05c: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1DB05Cu;
    SET_GPR_U32(ctx, 31, 0x1DB064u);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB064u; }
        if (ctx->pc != 0x1DB064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB064u; }
        if (ctx->pc != 0x1DB064u) { return; }
    }
    ctx->pc = 0x1DB064u;
label_1db064:
    // 0x1db064: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1db064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db068: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1db068u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1db06c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1db06cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db070: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x1db070u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x1db074: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1db074u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
label_1db078:
    // 0x1db078: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1db078u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db07c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1db07cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db080: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1db080u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1db084: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1db084u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1db088: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB088u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DB030u: goto label_1db030;
            case 0x1DB04Cu: goto label_1db04c;
            case 0x1DB064u: goto label_1db064;
            case 0x1DB078u: goto label_1db078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DB090u;
    // 0x1db090: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1db090u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1db094: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1db094u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1db098: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1db098u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db09c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1db09cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1db0a0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1db0a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db0a4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1db0a4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db0a8: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1db0a8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db0ac: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1db0acu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1db0b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB0B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DB030u: goto label_1db030;
            case 0x1DB04Cu: goto label_1db04c;
            case 0x1DB064u: goto label_1db064;
            case 0x1DB078u: goto label_1db078;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DB0B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
