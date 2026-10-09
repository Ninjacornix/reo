#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E7318
// Address: 0x1e7318 - 0x1e73c0
void sub_001E7318_0x1e7318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E7318_0x1e7318");
#endif

    switch (ctx->pc) {
        case 0x1e7334u: goto label_1e7334;
        case 0x1e7364u: goto label_1e7364;
        case 0x1e7390u: goto label_1e7390;
        case 0x1e73a8u: goto label_1e73a8;
        default: break;
    }

    ctx->pc = 0x1e7318u;

    // 0x1e7318: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e7318u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e731c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e731cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e7320: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e7320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e7324: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7324u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7328: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e7328u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e732c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e732cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e7330: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e7330u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
label_1e7334:
    // 0x1e7334: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e7334u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7338: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7338u;
    {
        const bool branch_taken_0x1e7338 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7338) {
            ctx->pc = 0x1E7348u;
            goto label_1e7348;
        }
    }
    ctx->pc = 0x1E7340u;
    // 0x1e7340: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1E7340u;
    {
        const bool branch_taken_0x1e7340 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7340) {
            ctx->pc = 0x1E739Cu;
            goto label_1e739c;
        }
    }
    ctx->pc = 0x1E7348u;
label_1e7348:
    // 0x1e7348: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7348u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e734c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e734cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e7350: 0x27c30008  addiu       $v1, $fp, 0x8
    ctx->pc = 0x1e7350u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1e7354: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e7354u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7358: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e7358u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e735c: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1E735Cu;
    SET_GPR_U32(ctx, 31, 0x1E7364u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7364u; }
        if (ctx->pc != 0x1E7364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7364u; }
        if (ctx->pc != 0x1E7364u) { return; }
    }
    ctx->pc = 0x1E7364u;
label_1e7364:
    // 0x1e7364: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7364u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e7368: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e7368u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e736c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E736Cu;
    {
        const bool branch_taken_0x1e736c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e736c) {
            ctx->pc = 0x1E737Cu;
            goto label_1e737c;
        }
    }
    ctx->pc = 0x1E7374u;
    // 0x1e7374: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1E7374u;
    {
        const bool branch_taken_0x1e7374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7374) {
            ctx->pc = 0x1E739Cu;
            goto label_1e739c;
        }
    }
    ctx->pc = 0x1E737Cu;
label_1e737c:
    // 0x1e737c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e737cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7380: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e7380u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e7384: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e7384u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7388: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E7388u;
    SET_GPR_U32(ctx, 31, 0x1E7390u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7390u; }
        if (ctx->pc != 0x1E7390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7390u; }
        if (ctx->pc != 0x1E7390u) { return; }
    }
    ctx->pc = 0x1E7390u;
label_1e7390:
    // 0x1e7390: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7390u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e7394: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x1E7394u;
    {
        const bool branch_taken_0x1e7394 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7394) {
            ctx->pc = 0x1E7334u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e7334;
        }
    }
    ctx->pc = 0x1E739Cu;
label_1e739c:
    // 0x1e739c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e739cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e73a0: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1E73A0u;
    SET_GPR_U32(ctx, 31, 0x1E73A8u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E73A8u; }
        if (ctx->pc != 0x1E73A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E73A8u; }
        if (ctx->pc != 0x1E73A8u) { return; }
    }
    ctx->pc = 0x1E73A8u;
label_1e73a8:
    // 0x1e73a8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e73a8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e73ac: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e73acu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e73b0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e73b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e73b4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e73b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e73b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E73B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7334u: goto label_1e7334;
            case 0x1E7348u: goto label_1e7348;
            case 0x1E7364u: goto label_1e7364;
            case 0x1E737Cu: goto label_1e737c;
            case 0x1E7390u: goto label_1e7390;
            case 0x1E739Cu: goto label_1e739c;
            case 0x1E73A8u: goto label_1e73a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E73C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
