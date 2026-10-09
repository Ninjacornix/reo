#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DEAF0
// Address: 0x1deaf0 - 0x1deba0
void sub_001DEAF0_0x1deaf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DEAF0_0x1deaf0");
#endif

    switch (ctx->pc) {
        case 0x1deb10u: goto label_1deb10;
        case 0x1deb3cu: goto label_1deb3c;
        case 0x1deb68u: goto label_1deb68;
        default: break;
    }

    ctx->pc = 0x1deaf0u;

    // 0x1deaf0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1deaf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1deaf4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1deaf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1deaf8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1deaf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1deafc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1deafcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1deb00: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1deb00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1deb04: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1deb04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deb08: 0xc077950  jal         func_1DE540
    ctx->pc = 0x1DEB08u;
    SET_GPR_U32(ctx, 31, 0x1DEB10u);
    ctx->pc = 0x1DE540u;
    if (runtime->hasFunction(0x1DE540u)) {
        auto targetFn = runtime->lookupFunction(0x1DE540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEB10u; }
        if (ctx->pc != 0x1DEB10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE540_0x1de540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEB10u; }
        if (ctx->pc != 0x1DEB10u) { return; }
    }
    ctx->pc = 0x1DEB10u;
label_1deb10:
    // 0x1deb10: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1deb10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deb14: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1deb14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1deb18: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1deb18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1deb1c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1deb1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deb20: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1deb20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1deb24: 0x2842037d  slti        $v0, $v0, 0x37D
    ctx->pc = 0x1deb24u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)893) ? 1 : 0);
    // 0x1deb28: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DEB28u;
    {
        const bool branch_taken_0x1deb28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1deb28) {
            ctx->pc = 0x1DEB38u;
            goto label_1deb38;
        }
    }
    ctx->pc = 0x1DEB30u;
    // 0x1deb30: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1DEB30u;
    {
        const bool branch_taken_0x1deb30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1deb30) {
            ctx->pc = 0x1DEB88u;
            goto label_1deb88;
        }
    }
    ctx->pc = 0x1DEB38u;
label_1deb38:
    // 0x1deb38: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1deb38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1deb3c:
    // 0x1deb3c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1deb3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1deb40: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1deb40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1deb44: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1deb44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1deb48: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1deb48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1deb4c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DEB4Cu;
    {
        const bool branch_taken_0x1deb4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1deb4c) {
            ctx->pc = 0x1DEB5Cu;
            goto label_1deb5c;
        }
    }
    ctx->pc = 0x1DEB54u;
    // 0x1deb54: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1DEB54u;
    {
        const bool branch_taken_0x1deb54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1deb54) {
            ctx->pc = 0x1DEB88u;
            goto label_1deb88;
        }
    }
    ctx->pc = 0x1DEB5Cu;
label_1deb5c:
    // 0x1deb5c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1deb5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1deb60: 0xc0776d4  jal         func_1DDB50
    ctx->pc = 0x1DEB60u;
    SET_GPR_U32(ctx, 31, 0x1DEB68u);
    ctx->pc = 0x1DDB50u;
    if (runtime->hasFunction(0x1DDB50u)) {
        auto targetFn = runtime->lookupFunction(0x1DDB50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEB68u; }
        if (ctx->pc != 0x1DEB68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DDB50_0x1ddb50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEB68u; }
        if (ctx->pc != 0x1DEB68u) { return; }
    }
    ctx->pc = 0x1DEB68u;
label_1deb68:
    // 0x1deb68: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1deb68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1deb6c: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1deb6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1deb70: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1deb70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1deb74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1deb74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1deb78: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1deb78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1deb7c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1deb7cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1deb80: 0x1000ffee  b           . + 4 + (-0x12 << 2)
    ctx->pc = 0x1DEB80u;
    {
        const bool branch_taken_0x1deb80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1deb80) {
            ctx->pc = 0x1DEB3Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1deb3c;
        }
    }
    ctx->pc = 0x1DEB88u;
label_1deb88:
    // 0x1deb88: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1deb88u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1deb8c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1deb8cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1deb90: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1deb90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1deb94: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1deb94u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1deb98: 0x3e00008  jr          $ra
    ctx->pc = 0x1DEB98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DEB10u: goto label_1deb10;
            case 0x1DEB38u: goto label_1deb38;
            case 0x1DEB3Cu: goto label_1deb3c;
            case 0x1DEB5Cu: goto label_1deb5c;
            case 0x1DEB68u: goto label_1deb68;
            case 0x1DEB88u: goto label_1deb88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DEBA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
