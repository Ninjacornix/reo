#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F0FE0
// Address: 0x1f0fe0 - 0x1f105c
void sub_001F0FE0_0x1f0fe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F0FE0_0x1f0fe0");
#endif

    switch (ctx->pc) {
        case 0x1f1004u: goto label_1f1004;
        case 0x1f1030u: goto label_1f1030;
        default: break;
    }

    ctx->pc = 0x1f0fe0u;

    // 0x1f0fe0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f0fe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f0fe4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f0fe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f0fe8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f0fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f0fec: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f0fecu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0ff0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0ff4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f0ff4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f0ff8: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x1f0ff8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1f0ffc: 0xc079f1f  jal         func_1E7C7C
    ctx->pc = 0x1F0FFCu;
    SET_GPR_U32(ctx, 31, 0x1F1004u);
    ctx->pc = 0x1E7C7Cu;
    if (runtime->hasFunction(0x1E7C7Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E7C7Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1004u; }
        if (ctx->pc != 0x1F1004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7C7C_0x1e7c7c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1004u; }
        if (ctx->pc != 0x1F1004u) { return; }
    }
    ctx->pc = 0x1F1004u;
label_1f1004:
    // 0x1f1004: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f1004u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f1008: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f1008u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f100c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F100Cu;
    {
        const bool branch_taken_0x1f100c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f100c) {
            ctx->pc = 0x1F1020u;
            goto label_1f1020;
        }
    }
    ctx->pc = 0x1F1014u;
    // 0x1f1014: 0x2402e4a9  addiu       $v0, $zero, -0x1B57
    ctx->pc = 0x1f1014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960297));
    // 0x1f1018: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1F1018u;
    {
        const bool branch_taken_0x1f1018 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1018) {
            ctx->pc = 0x1F1044u;
            goto label_1f1044;
        }
    }
    ctx->pc = 0x1F1020u;
label_1f1020:
    // 0x1f1020: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1f1020u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1024: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1f1024u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1028: 0xc07c417  jal         func_1F105C
    ctx->pc = 0x1F1028u;
    SET_GPR_U32(ctx, 31, 0x1F1030u);
    ctx->pc = 0x1F105Cu;
    if (runtime->hasFunction(0x1F105Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F105Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1030u; }
        if (ctx->pc != 0x1F1030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F105C_0x1f105c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F1030u; }
        if (ctx->pc != 0x1F1030u) { return; }
    }
    ctx->pc = 0x1F1030u;
label_1f1030:
    // 0x1f1030: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f1030u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f1034: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f1034u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1038: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f1038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f103c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f103cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f1040: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1f1040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_1f1044:
    // 0x1f1044: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1044u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1048: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f1048u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f104c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f104cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f1050: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f1050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f1054: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1054u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1004u: goto label_1f1004;
            case 0x1F1020u: goto label_1f1020;
            case 0x1F1030u: goto label_1f1030;
            case 0x1F1044u: goto label_1f1044;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F105Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
