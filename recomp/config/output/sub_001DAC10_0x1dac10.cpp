#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DAC10
// Address: 0x1dac10 - 0x1dacac
void sub_001DAC10_0x1dac10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DAC10_0x1dac10");
#endif

    switch (ctx->pc) {
        case 0x1dac84u: goto label_1dac84;
        case 0x1dac8cu: goto label_1dac8c;
        default: break;
    }

    ctx->pc = 0x1dac10u;

    // 0x1dac10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dac10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dac14: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dac14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1dac18: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1dac18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1dac1c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dac1cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dac20: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dac20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dac24: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1dac24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dac28: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1dac28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dac2c: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DAC2Cu;
    {
        const bool branch_taken_0x1dac2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1dac2c) {
            ctx->pc = 0x1DAC50u;
            goto label_1dac50;
        }
    }
    ctx->pc = 0x1DAC34u;
    // 0x1dac34: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dac34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dac38: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dac38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dac3c: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dac3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dac40: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dac40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dac44: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dac44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dac48: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DAC48u;
    {
        const bool branch_taken_0x1dac48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dac48) {
            ctx->pc = 0x1DAC5Cu;
            goto label_1dac5c;
        }
    }
    ctx->pc = 0x1DAC50u;
label_1dac50:
    // 0x1dac50: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1dac50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1dac54: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1DAC54u;
    {
        const bool branch_taken_0x1dac54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dac54) {
            ctx->pc = 0x1DAC94u;
            goto label_1dac94;
        }
    }
    ctx->pc = 0x1DAC5Cu;
label_1dac5c:
    // 0x1dac5c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dac5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dac60: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dac60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dac64: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dac64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dac68: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dac68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dac6c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dac6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dac70: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dac70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dac74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dac74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dac78: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1dac78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dac7c: 0xc07a772  jal         func_1E9DC8
    ctx->pc = 0x1DAC7Cu;
    SET_GPR_U32(ctx, 31, 0x1DAC84u);
    ctx->pc = 0x1E9DC8u;
    if (runtime->hasFunction(0x1E9DC8u)) {
        auto targetFn = runtime->lookupFunction(0x1E9DC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAC84u; }
        if (ctx->pc != 0x1DAC84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E9DC8_0x1e9dc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAC84u; }
        if (ctx->pc != 0x1DAC84u) { return; }
    }
    ctx->pc = 0x1DAC84u;
label_1dac84:
    // 0x1dac84: 0xc079f00  jal         func_1E7C00
    ctx->pc = 0x1DAC84u;
    SET_GPR_U32(ctx, 31, 0x1DAC8Cu);
    ctx->pc = 0x1E7C00u;
    if (runtime->hasFunction(0x1E7C00u)) {
        auto targetFn = runtime->lookupFunction(0x1E7C00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAC8Cu; }
        if (ctx->pc != 0x1DAC8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7C00_0x1e7c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAC8Cu; }
        if (ctx->pc != 0x1DAC8Cu) { return; }
    }
    ctx->pc = 0x1DAC8Cu;
label_1dac8c:
    // 0x1dac8c: 0xaf80801c  sw          $zero, -0x7FE4($gp)
    ctx->pc = 0x1dac8cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934556), GPR_U32(ctx, 0));
    // 0x1dac90: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dac90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1dac94:
    // 0x1dac94: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dac94u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dac98: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dac98u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dac9c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1dac9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1daca0: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1daca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1daca4: 0x3e00008  jr          $ra
    ctx->pc = 0x1DACA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DAC50u: goto label_1dac50;
            case 0x1DAC5Cu: goto label_1dac5c;
            case 0x1DAC84u: goto label_1dac84;
            case 0x1DAC8Cu: goto label_1dac8c;
            case 0x1DAC94u: goto label_1dac94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DACACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
