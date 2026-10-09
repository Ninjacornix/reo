#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DEA40
// Address: 0x1dea40 - 0x1deaf0
void sub_001DEA40_0x1dea40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DEA40_0x1dea40");
#endif

    switch (ctx->pc) {
        case 0x1dea60u: goto label_1dea60;
        case 0x1dea8cu: goto label_1dea8c;
        case 0x1deab8u: goto label_1deab8;
        default: break;
    }

    ctx->pc = 0x1dea40u;

    // 0x1dea40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dea40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dea44: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dea44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1dea48: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1dea48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1dea4c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dea4cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dea50: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dea50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dea54: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dea54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dea58: 0xc077950  jal         func_1DE540
    ctx->pc = 0x1DEA58u;
    SET_GPR_U32(ctx, 31, 0x1DEA60u);
    ctx->pc = 0x1DE540u;
    if (runtime->hasFunction(0x1DE540u)) {
        auto targetFn = runtime->lookupFunction(0x1DE540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEA60u; }
        if (ctx->pc != 0x1DEA60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE540_0x1de540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEA60u; }
        if (ctx->pc != 0x1DEA60u) { return; }
    }
    ctx->pc = 0x1DEA60u;
label_1dea60:
    // 0x1dea60: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dea60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dea64: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1dea64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1dea68: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dea68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dea6c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dea6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dea70: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1dea70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1dea74: 0x2842037d  slti        $v0, $v0, 0x37D
    ctx->pc = 0x1dea74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)893) ? 1 : 0);
    // 0x1dea78: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DEA78u;
    {
        const bool branch_taken_0x1dea78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dea78) {
            ctx->pc = 0x1DEA88u;
            goto label_1dea88;
        }
    }
    ctx->pc = 0x1DEA80u;
    // 0x1dea80: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1DEA80u;
    {
        const bool branch_taken_0x1dea80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dea80) {
            ctx->pc = 0x1DEAD8u;
            goto label_1dead8;
        }
    }
    ctx->pc = 0x1DEA88u;
label_1dea88:
    // 0x1dea88: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1dea88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1dea8c:
    // 0x1dea8c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dea8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dea90: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dea90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dea94: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1dea94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1dea98: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1dea98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1dea9c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DEA9Cu;
    {
        const bool branch_taken_0x1dea9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dea9c) {
            ctx->pc = 0x1DEAACu;
            goto label_1deaac;
        }
    }
    ctx->pc = 0x1DEAA4u;
    // 0x1deaa4: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1DEAA4u;
    {
        const bool branch_taken_0x1deaa4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1deaa4) {
            ctx->pc = 0x1DEAD8u;
            goto label_1dead8;
        }
    }
    ctx->pc = 0x1DEAACu;
label_1deaac:
    // 0x1deaac: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1deaacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1deab0: 0xc0777f5  jal         func_1DDFD4
    ctx->pc = 0x1DEAB0u;
    SET_GPR_U32(ctx, 31, 0x1DEAB8u);
    ctx->pc = 0x1DDFD4u;
    if (runtime->hasFunction(0x1DDFD4u)) {
        auto targetFn = runtime->lookupFunction(0x1DDFD4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEAB8u; }
        if (ctx->pc != 0x1DEAB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DDFD4_0x1ddfd4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEAB8u; }
        if (ctx->pc != 0x1DEAB8u) { return; }
    }
    ctx->pc = 0x1DEAB8u;
label_1deab8:
    // 0x1deab8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1deab8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1deabc: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1deabcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1deac0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1deac0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1deac4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1deac4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1deac8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1deac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1deacc: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1deaccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dead0: 0x1000ffee  b           . + 4 + (-0x12 << 2)
    ctx->pc = 0x1DEAD0u;
    {
        const bool branch_taken_0x1dead0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dead0) {
            ctx->pc = 0x1DEA8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dea8c;
        }
    }
    ctx->pc = 0x1DEAD8u;
label_1dead8:
    // 0x1dead8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dead8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1deadc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1deadcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1deae0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1deae0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1deae4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1deae4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1deae8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DEAE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DEA60u: goto label_1dea60;
            case 0x1DEA88u: goto label_1dea88;
            case 0x1DEA8Cu: goto label_1dea8c;
            case 0x1DEAACu: goto label_1deaac;
            case 0x1DEAB8u: goto label_1deab8;
            case 0x1DEAD8u: goto label_1dead8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DEAF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
