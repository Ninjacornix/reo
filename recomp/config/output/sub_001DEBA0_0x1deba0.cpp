#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DEBA0
// Address: 0x1deba0 - 0x1dec50
void sub_001DEBA0_0x1deba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DEBA0_0x1deba0");
#endif

    switch (ctx->pc) {
        case 0x1debc0u: goto label_1debc0;
        case 0x1debecu: goto label_1debec;
        case 0x1dec18u: goto label_1dec18;
        default: break;
    }

    ctx->pc = 0x1deba0u;

    // 0x1deba0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1deba0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1deba4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1deba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1deba8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1deba8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1debac: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1debacu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1debb0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1debb0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1debb4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1debb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1debb8: 0xc077950  jal         func_1DE540
    ctx->pc = 0x1DEBB8u;
    SET_GPR_U32(ctx, 31, 0x1DEBC0u);
    ctx->pc = 0x1DE540u;
    if (runtime->hasFunction(0x1DE540u)) {
        auto targetFn = runtime->lookupFunction(0x1DE540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEBC0u; }
        if (ctx->pc != 0x1DEBC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE540_0x1de540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEBC0u; }
        if (ctx->pc != 0x1DEBC0u) { return; }
    }
    ctx->pc = 0x1DEBC0u;
label_1debc0:
    // 0x1debc0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1debc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1debc4: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1debc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1debc8: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1debc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1debcc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1debccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1debd0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1debd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1debd4: 0x2842037d  slti        $v0, $v0, 0x37D
    ctx->pc = 0x1debd4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)893) ? 1 : 0);
    // 0x1debd8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DEBD8u;
    {
        const bool branch_taken_0x1debd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1debd8) {
            ctx->pc = 0x1DEBE8u;
            goto label_1debe8;
        }
    }
    ctx->pc = 0x1DEBE0u;
    // 0x1debe0: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1DEBE0u;
    {
        const bool branch_taken_0x1debe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1debe0) {
            ctx->pc = 0x1DEC38u;
            goto label_1dec38;
        }
    }
    ctx->pc = 0x1DEBE8u;
label_1debe8:
    // 0x1debe8: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1debe8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1debec:
    // 0x1debec: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1debecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1debf0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1debf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1debf4: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1debf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1debf8: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1debf8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1debfc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DEBFCu;
    {
        const bool branch_taken_0x1debfc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1debfc) {
            ctx->pc = 0x1DEC0Cu;
            goto label_1dec0c;
        }
    }
    ctx->pc = 0x1DEC04u;
    // 0x1dec04: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1DEC04u;
    {
        const bool branch_taken_0x1dec04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dec04) {
            ctx->pc = 0x1DEC38u;
            goto label_1dec38;
        }
    }
    ctx->pc = 0x1DEC0Cu;
label_1dec0c:
    // 0x1dec0c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1dec0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dec10: 0xc077658  jal         func_1DD960
    ctx->pc = 0x1DEC10u;
    SET_GPR_U32(ctx, 31, 0x1DEC18u);
    ctx->pc = 0x1DD960u;
    if (runtime->hasFunction(0x1DD960u)) {
        auto targetFn = runtime->lookupFunction(0x1DD960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEC18u; }
        if (ctx->pc != 0x1DEC18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DD960_0x1dd960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEC18u; }
        if (ctx->pc != 0x1DEC18u) { return; }
    }
    ctx->pc = 0x1DEC18u;
label_1dec18:
    // 0x1dec18: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dec18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dec1c: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x1dec1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x1dec20: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dec20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dec24: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dec24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dec28: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1dec28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dec2c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dec2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dec30: 0x1000ffee  b           . + 4 + (-0x12 << 2)
    ctx->pc = 0x1DEC30u;
    {
        const bool branch_taken_0x1dec30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dec30) {
            ctx->pc = 0x1DEBECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1debec;
        }
    }
    ctx->pc = 0x1DEC38u;
label_1dec38:
    // 0x1dec38: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dec38u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dec3c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dec3cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dec40: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1dec40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1dec44: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1dec44u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1dec48: 0x3e00008  jr          $ra
    ctx->pc = 0x1DEC48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DEBC0u: goto label_1debc0;
            case 0x1DEBE8u: goto label_1debe8;
            case 0x1DEBECu: goto label_1debec;
            case 0x1DEC0Cu: goto label_1dec0c;
            case 0x1DEC18u: goto label_1dec18;
            case 0x1DEC38u: goto label_1dec38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DEC50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
