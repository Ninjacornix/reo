#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DE8E0
// Address: 0x1de8e0 - 0x1de990
void sub_001DE8E0_0x1de8e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DE8E0_0x1de8e0");
#endif

    switch (ctx->pc) {
        case 0x1de900u: goto label_1de900;
        case 0x1de92cu: goto label_1de92c;
        case 0x1de958u: goto label_1de958;
        default: break;
    }

    ctx->pc = 0x1de8e0u;

    // 0x1de8e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1de8e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1de8e4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1de8e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1de8e8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1de8e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1de8ec: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1de8ecu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de8f0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1de8f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1de8f4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1de8f4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de8f8: 0xc077950  jal         func_1DE540
    ctx->pc = 0x1DE8F8u;
    SET_GPR_U32(ctx, 31, 0x1DE900u);
    ctx->pc = 0x1DE540u;
    if (runtime->hasFunction(0x1DE540u)) {
        auto targetFn = runtime->lookupFunction(0x1DE540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE900u; }
        if (ctx->pc != 0x1DE900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE540_0x1de540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE900u; }
        if (ctx->pc != 0x1DE900u) { return; }
    }
    ctx->pc = 0x1DE900u;
label_1de900:
    // 0x1de900: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de900u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de904: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1de904u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1de908: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1de908u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1de90c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de90cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de910: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de914: 0x2842037d  slti        $v0, $v0, 0x37D
    ctx->pc = 0x1de914u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)893) ? 1 : 0);
    // 0x1de918: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DE918u;
    {
        const bool branch_taken_0x1de918 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1de918) {
            ctx->pc = 0x1DE928u;
            goto label_1de928;
        }
    }
    ctx->pc = 0x1DE920u;
    // 0x1de920: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1DE920u;
    {
        const bool branch_taken_0x1de920 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de920) {
            ctx->pc = 0x1DE978u;
            goto label_1de978;
        }
    }
    ctx->pc = 0x1DE928u;
label_1de928:
    // 0x1de928: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1de928u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1de92c:
    // 0x1de92c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1de92cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1de930: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1de930u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1de934: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1de934u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1de938: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1de938u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1de93c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DE93Cu;
    {
        const bool branch_taken_0x1de93c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1de93c) {
            ctx->pc = 0x1DE94Cu;
            goto label_1de94c;
        }
    }
    ctx->pc = 0x1DE944u;
    // 0x1de944: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1DE944u;
    {
        const bool branch_taken_0x1de944 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de944) {
            ctx->pc = 0x1DE978u;
            goto label_1de978;
        }
    }
    ctx->pc = 0x1DE94Cu;
label_1de94c:
    // 0x1de94c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1de94cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1de950: 0xc077871  jal         func_1DE1C4
    ctx->pc = 0x1DE950u;
    SET_GPR_U32(ctx, 31, 0x1DE958u);
    ctx->pc = 0x1DE1C4u;
    if (runtime->hasFunction(0x1DE1C4u)) {
        auto targetFn = runtime->lookupFunction(0x1DE1C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE958u; }
        if (ctx->pc != 0x1DE958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE1C4_0x1de1c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DE958u; }
        if (ctx->pc != 0x1DE958u) { return; }
    }
    ctx->pc = 0x1DE958u;
label_1de958:
    // 0x1de958: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1de958u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1de95c: 0x2442001c  addiu       $v0, $v0, 0x1C
    ctx->pc = 0x1de95cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 28));
    // 0x1de960: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1de960u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1de964: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1de964u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1de968: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1de968u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1de96c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1de96cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1de970: 0x1000ffee  b           . + 4 + (-0x12 << 2)
    ctx->pc = 0x1DE970u;
    {
        const bool branch_taken_0x1de970 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1de970) {
            ctx->pc = 0x1DE92Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1de92c;
        }
    }
    ctx->pc = 0x1DE978u;
label_1de978:
    // 0x1de978: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1de978u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1de97c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1de97cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1de980: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1de980u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1de984: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1de984u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1de988: 0x3e00008  jr          $ra
    ctx->pc = 0x1DE988u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DE900u: goto label_1de900;
            case 0x1DE928u: goto label_1de928;
            case 0x1DE92Cu: goto label_1de92c;
            case 0x1DE94Cu: goto label_1de94c;
            case 0x1DE958u: goto label_1de958;
            case 0x1DE978u: goto label_1de978;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DE990u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
