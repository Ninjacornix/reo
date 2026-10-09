#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E7438
// Address: 0x1e7438 - 0x1e74e4
void sub_001E7438_0x1e7438(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E7438_0x1e7438");
#endif

    switch (ctx->pc) {
        case 0x1e7454u: goto label_1e7454;
        case 0x1e7484u: goto label_1e7484;
        case 0x1e74b0u: goto label_1e74b0;
        case 0x1e74c8u: goto label_1e74c8;
        default: break;
    }

    ctx->pc = 0x1e7438u;

    // 0x1e7438: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e7438u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e743c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e743cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e7440: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e7440u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e7444: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7444u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7448: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e7448u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e744c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e744cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e7450: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e7450u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
label_1e7454:
    // 0x1e7454: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e7454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7458: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7458u;
    {
        const bool branch_taken_0x1e7458 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7458) {
            ctx->pc = 0x1E7468u;
            goto label_1e7468;
        }
    }
    ctx->pc = 0x1E7460u;
    // 0x1e7460: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1E7460u;
    {
        const bool branch_taken_0x1e7460 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7460) {
            ctx->pc = 0x1E74BCu;
            goto label_1e74bc;
        }
    }
    ctx->pc = 0x1E7468u;
label_1e7468:
    // 0x1e7468: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7468u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e746c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e746cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e7470: 0x27c30008  addiu       $v1, $fp, 0x8
    ctx->pc = 0x1e7470u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1e7474: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e7474u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7478: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e7478u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e747c: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1E747Cu;
    SET_GPR_U32(ctx, 31, 0x1E7484u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7484u; }
        if (ctx->pc != 0x1E7484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7484u; }
        if (ctx->pc != 0x1E7484u) { return; }
    }
    ctx->pc = 0x1E7484u;
label_1e7484:
    // 0x1e7484: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7484u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e7488: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e7488u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e748c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E748Cu;
    {
        const bool branch_taken_0x1e748c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e748c) {
            ctx->pc = 0x1E749Cu;
            goto label_1e749c;
        }
    }
    ctx->pc = 0x1E7494u;
    // 0x1e7494: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1E7494u;
    {
        const bool branch_taken_0x1e7494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7494) {
            ctx->pc = 0x1E74BCu;
            goto label_1e74bc;
        }
    }
    ctx->pc = 0x1E749Cu;
label_1e749c:
    // 0x1e749c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e749cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e74a0: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e74a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e74a4: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e74a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e74a8: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E74A8u;
    SET_GPR_U32(ctx, 31, 0x1E74B0u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E74B0u; }
        if (ctx->pc != 0x1E74B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E74B0u; }
        if (ctx->pc != 0x1E74B0u) { return; }
    }
    ctx->pc = 0x1E74B0u;
label_1e74b0:
    // 0x1e74b0: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e74b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e74b4: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x1E74B4u;
    {
        const bool branch_taken_0x1e74b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e74b4) {
            ctx->pc = 0x1E7454u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e7454;
        }
    }
    ctx->pc = 0x1E74BCu;
label_1e74bc:
    // 0x1e74bc: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e74bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e74c0: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1E74C0u;
    SET_GPR_U32(ctx, 31, 0x1E74C8u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E74C8u; }
        if (ctx->pc != 0x1E74C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E74C8u; }
        if (ctx->pc != 0x1E74C8u) { return; }
    }
    ctx->pc = 0x1E74C8u;
label_1e74c8:
    // 0x1e74c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e74c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e74cc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e74ccu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e74d0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e74d0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e74d4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e74d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e74d8: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e74d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e74dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1E74DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7454u: goto label_1e7454;
            case 0x1E7468u: goto label_1e7468;
            case 0x1E7484u: goto label_1e7484;
            case 0x1E749Cu: goto label_1e749c;
            case 0x1E74B0u: goto label_1e74b0;
            case 0x1E74BCu: goto label_1e74bc;
            case 0x1E74C8u: goto label_1e74c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E74E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
