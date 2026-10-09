#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE990
// Address: 0x1de990 - 0x1dea40
void sub_001DE990_0x1de990(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE990_0x1de990");
#endif

    switch (ctx->pc) {
        case 0x1de9b0u: goto label_1de9b0;
        case 0x1de9dcu: goto label_1de9dc;
        case 0x1dea08u: goto label_1dea08;
        default: break;
    }

    ctx->pc = 0x1de990u;

    // 0x1de990: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de990u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de994: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de994u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de998: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1de998u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1de99c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de99cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de9a0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de9a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de9a4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1de9a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de9a8: 0xc077950  jal         func_1DE540
    ctx->pc = 0x1DE9A8u;
    SET_GPR_U32(ctx, 31, 0x1DE9B0u);
    ctx->pc = 0x1DE540u;
    if (runtime->hasFunction(0x1DE540u)) {
        auto targetFn = runtime->lookupFunction(0x1DE540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE9B0u; }
        if (ctx->pc != 0x1DE9B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE540_0x1de540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE9B0u; }
        if (ctx->pc != 0x1DE9B0u) { return; }
    }
    ctx->pc = 0x1DE9B0u;
label_1de9b0:
    // 0x1de9b0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de9b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de9b4: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1de9b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1de9b8: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1de9b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1de9bc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de9c0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de9c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de9c4: 0x2842037d  slti        $v0, $v0, 0x37D
    ctx->pc = 0x1de9c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)893) ? 1 : 0);
    // 0x1de9c8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DE9C8u;
    {
        const bool branch_taken_0x1de9c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1de9c8) {
            ctx->pc = 0x1DE9D8u;
            goto label_1de9d8;
        }
    }
    ctx->pc = 0x1DE9D0u;
    // 0x1de9d0: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1DE9D0u;
    {
        const bool branch_taken_0x1de9d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de9d0) {
            ctx->pc = 0x1DEA28u;
            goto label_1dea28;
        }
    }
    ctx->pc = 0x1DE9D8u;
label_1de9d8:
    // 0x1de9d8: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1de9d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1de9dc:
    // 0x1de9dc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de9e0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1de9e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1de9e4: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de9e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de9e8: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1de9e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1de9ec: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DE9ECu;
    {
        const bool branch_taken_0x1de9ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1de9ec) {
            ctx->pc = 0x1DE9FCu;
            goto label_1de9fc;
        }
    }
    ctx->pc = 0x1DE9F4u;
    // 0x1de9f4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1DE9F4u;
    {
        const bool branch_taken_0x1de9f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de9f4) {
            ctx->pc = 0x1DEA28u;
            goto label_1dea28;
        }
    }
    ctx->pc = 0x1DE9FCu;
label_1de9fc:
    // 0x1de9fc: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1de9fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dea00: 0xc0777f5  jal         func_1DDFD4
    ctx->pc = 0x1DEA00u;
    SET_GPR_U32(ctx, 31, 0x1DEA08u);
    ctx->pc = 0x1DDFD4u;
    if (runtime->hasFunction(0x1DDFD4u)) {
        auto targetFn = runtime->lookupFunction(0x1DDFD4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEA08u; }
        if (ctx->pc != 0x1DEA08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DDFD4_0x1ddfd4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEA08u; }
        if (ctx->pc != 0x1DEA08u) { return; }
    }
    ctx->pc = 0x1DEA08u;
label_1dea08:
    // 0x1dea08: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dea08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dea0c: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1dea0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1dea10: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dea10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dea14: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dea14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dea18: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1dea18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dea1c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dea1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dea20: 0x1000ffee  b           . + 4 + (-0x12 << 2)
    ctx->pc = 0x1DEA20u;
    {
        const bool branch_taken_0x1dea20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dea20) {
            ctx->pc = 0x1DE9DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1de9dc;
        }
    }
    ctx->pc = 0x1DEA28u;
label_1dea28:
    // 0x1dea28: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dea28u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dea2c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dea2cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dea30: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1dea30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1dea34: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1dea34u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1dea38: 0x3e00008  jr          $ra
    ctx->pc = 0x1DEA38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DE9B0u: goto label_1de9b0;
            case 0x1DE9D8u: goto label_1de9d8;
            case 0x1DE9DCu: goto label_1de9dc;
            case 0x1DE9FCu: goto label_1de9fc;
            case 0x1DEA08u: goto label_1dea08;
            case 0x1DEA28u: goto label_1dea28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DEA40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
