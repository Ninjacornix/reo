#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DAB54
// Address: 0x1dab54 - 0x1daeac
void sub_001DAB54_0x1dab54(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DAB54_0x1dab54");
#endif

    switch (ctx->pc) {
        case 0x1dac84u: goto label_1dac84;
        case 0x1dac8cu: goto label_1dac8c;
        case 0x1dad28u: goto label_1dad28;
        case 0x1dae48u: goto label_1dae48;
        default: break;
    }

    ctx->pc = 0x1dab54u;

    // 0x1dab54: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1dab54u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1dab58: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1dab58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1dab5c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dab5cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dab60: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dab60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dab64: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1dab64u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1dab68: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1dab68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1dab6c: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1dab6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dab70: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1dab70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dab74: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DAB74u;
    {
        const bool branch_taken_0x1dab74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1dab74) {
            ctx->pc = 0x1DAB98u;
            goto label_1dab98;
        }
    }
    ctx->pc = 0x1DAB7Cu;
    // 0x1dab7c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dab7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dab80: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dab80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dab84: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dab84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dab88: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dab88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dab8c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dab8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dab90: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DAB90u;
    {
        const bool branch_taken_0x1dab90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dab90) {
            ctx->pc = 0x1DABA4u;
            goto label_1daba4;
        }
    }
    ctx->pc = 0x1DAB98u;
label_1dab98:
    // 0x1dab98: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dab98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dab9c: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1DAB9Cu;
    {
        const bool branch_taken_0x1dab9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dab9c) {
            ctx->pc = 0x1DABFCu;
            goto label_1dabfc;
        }
    }
    ctx->pc = 0x1DABA4u;
label_1daba4:
    // 0x1daba4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1daba4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1daba8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1daba8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dabac: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dabacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dabb0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dabb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dabb4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dabb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dabb8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1dabb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1dabbc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1dabbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dabc0: 0x24420548  addiu       $v0, $v0, 0x548
    ctx->pc = 0x1dabc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1352));
    // 0x1dabc4: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1dabc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1dabc8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dabc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dabcc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dabccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dabd0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dabd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dabd4: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dabd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dabd8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dabd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dabdc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dabdcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1dabe0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dabe0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dabe4: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dabe4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dabe8: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1dabe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dabec: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1dabecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dabf0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dabf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dabf4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1dabf4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1dabf8: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1dabf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
label_1dabfc:
    // 0x1dabfc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dabfcu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dac00: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1dac00u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1dac04: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1dac04u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1dac08: 0x3e00008  jr          $ra
    ctx->pc = 0x1DAC08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DAB98u: goto label_1dab98;
            case 0x1DABA4u: goto label_1daba4;
            case 0x1DABFCu: goto label_1dabfc;
            case 0x1DAC50u: goto label_1dac50;
            case 0x1DAC5Cu: goto label_1dac5c;
            case 0x1DAC84u: goto label_1dac84;
            case 0x1DAC8Cu: goto label_1dac8c;
            case 0x1DAC94u: goto label_1dac94;
            case 0x1DACF0u: goto label_1dacf0;
            case 0x1DACFCu: goto label_1dacfc;
            case 0x1DAD28u: goto label_1dad28;
            case 0x1DADBCu: goto label_1dadbc;
            case 0x1DAE14u: goto label_1dae14;
            case 0x1DAE20u: goto label_1dae20;
            case 0x1DAE48u: goto label_1dae48;
            case 0x1DAE94u: goto label_1dae94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DAC10u;
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
            case 0x1DAB98u: goto label_1dab98;
            case 0x1DABA4u: goto label_1daba4;
            case 0x1DABFCu: goto label_1dabfc;
            case 0x1DAC50u: goto label_1dac50;
            case 0x1DAC5Cu: goto label_1dac5c;
            case 0x1DAC84u: goto label_1dac84;
            case 0x1DAC8Cu: goto label_1dac8c;
            case 0x1DAC94u: goto label_1dac94;
            case 0x1DACF0u: goto label_1dacf0;
            case 0x1DACFCu: goto label_1dacfc;
            case 0x1DAD28u: goto label_1dad28;
            case 0x1DADBCu: goto label_1dadbc;
            case 0x1DAE14u: goto label_1dae14;
            case 0x1DAE20u: goto label_1dae20;
            case 0x1DAE48u: goto label_1dae48;
            case 0x1DAE94u: goto label_1dae94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DACACu;
    // 0x1dacac: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dacacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dacb0: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dacb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1dacb4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1dacb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1dacb8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dacb8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dacbc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dacbcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dacc0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1dacc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1dacc4: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1dacc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dacc8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1dacc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1daccc: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DACCCu;
    {
        const bool branch_taken_0x1daccc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1daccc) {
            ctx->pc = 0x1DACF0u;
            goto label_1dacf0;
        }
    }
    ctx->pc = 0x1DACD4u;
    // 0x1dacd4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dacd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dacd8: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dacd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dacdc: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dacdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dace0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dace0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dace4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dace4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dace8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DACE8u;
    {
        const bool branch_taken_0x1dace8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dace8) {
            ctx->pc = 0x1DACFCu;
            goto label_1dacfc;
        }
    }
    ctx->pc = 0x1DACF0u;
label_1dacf0:
    // 0x1dacf0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1dacf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1dacf4: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1DACF4u;
    {
        const bool branch_taken_0x1dacf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dacf4) {
            ctx->pc = 0x1DADBCu;
            goto label_1dadbc;
        }
    }
    ctx->pc = 0x1DACFCu;
label_1dacfc:
    // 0x1dacfc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dacfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dad00: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dad00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dad04: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dad04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dad08: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dad08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dad0c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dad0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dad10: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1dad10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dad14: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad18: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dad18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dad1c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1dad1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad20: 0xc07cac2  jal         func_1F2B08
    ctx->pc = 0x1DAD20u;
    SET_GPR_U32(ctx, 31, 0x1DAD28u);
    ctx->pc = 0x1F2B08u;
    if (runtime->hasFunction(0x1F2B08u)) {
        auto targetFn = runtime->lookupFunction(0x1F2B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAD28u; }
        if (ctx->pc != 0x1DAD28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2B08_0x1f2b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAD28u; }
        if (ctx->pc != 0x1DAD28u) { return; }
    }
    ctx->pc = 0x1DAD28u;
label_1dad28:
    // 0x1dad28: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad2c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad30: 0x8c420524  lw          $v0, 0x524($v0)
    ctx->pc = 0x1dad30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1316)));
    // 0x1dad34: 0xac620034  sw          $v0, 0x34($v1)
    ctx->pc = 0x1dad34u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 52), GPR_U32(ctx, 2));
    // 0x1dad38: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad3c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad40: 0x8c420528  lw          $v0, 0x528($v0)
    ctx->pc = 0x1dad40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1320)));
    // 0x1dad44: 0xac620038  sw          $v0, 0x38($v1)
    ctx->pc = 0x1dad44u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 56), GPR_U32(ctx, 2));
    // 0x1dad48: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad4c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad50: 0x8c42052c  lw          $v0, 0x52C($v0)
    ctx->pc = 0x1dad50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1324)));
    // 0x1dad54: 0xac62003c  sw          $v0, 0x3C($v1)
    ctx->pc = 0x1dad54u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 60), GPR_U32(ctx, 2));
    // 0x1dad58: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad5c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad60: 0x8c420530  lw          $v0, 0x530($v0)
    ctx->pc = 0x1dad60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1328)));
    // 0x1dad64: 0xac620040  sw          $v0, 0x40($v1)
    ctx->pc = 0x1dad64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 64), GPR_U32(ctx, 2));
    // 0x1dad68: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad6c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad70: 0x8c420534  lw          $v0, 0x534($v0)
    ctx->pc = 0x1dad70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1332)));
    // 0x1dad74: 0xac620044  sw          $v0, 0x44($v1)
    ctx->pc = 0x1dad74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 68), GPR_U32(ctx, 2));
    // 0x1dad78: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad7c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad80: 0x8c420538  lw          $v0, 0x538($v0)
    ctx->pc = 0x1dad80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1336)));
    // 0x1dad84: 0xac620048  sw          $v0, 0x48($v1)
    ctx->pc = 0x1dad84u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 72), GPR_U32(ctx, 2));
    // 0x1dad88: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad8c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dad90: 0x8c42053c  lw          $v0, 0x53C($v0)
    ctx->pc = 0x1dad90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1340)));
    // 0x1dad94: 0xac62004c  sw          $v0, 0x4C($v1)
    ctx->pc = 0x1dad94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 76), GPR_U32(ctx, 2));
    // 0x1dad98: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dad98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dad9c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dad9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dada0: 0x8c420540  lw          $v0, 0x540($v0)
    ctx->pc = 0x1dada0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1344)));
    // 0x1dada4: 0xac620050  sw          $v0, 0x50($v1)
    ctx->pc = 0x1dada4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 80), GPR_U32(ctx, 2));
    // 0x1dada8: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dada8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dadac: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1dadacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dadb0: 0x8c420544  lw          $v0, 0x544($v0)
    ctx->pc = 0x1dadb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1348)));
    // 0x1dadb4: 0xac620054  sw          $v0, 0x54($v1)
    ctx->pc = 0x1dadb4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 84), GPR_U32(ctx, 2));
    // 0x1dadb8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dadb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1dadbc:
    // 0x1dadbc: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dadbcu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dadc0: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dadc0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dadc4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1dadc4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1dadc8: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1dadc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1dadcc: 0x3e00008  jr          $ra
    ctx->pc = 0x1DADCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DAB98u: goto label_1dab98;
            case 0x1DABA4u: goto label_1daba4;
            case 0x1DABFCu: goto label_1dabfc;
            case 0x1DAC50u: goto label_1dac50;
            case 0x1DAC5Cu: goto label_1dac5c;
            case 0x1DAC84u: goto label_1dac84;
            case 0x1DAC8Cu: goto label_1dac8c;
            case 0x1DAC94u: goto label_1dac94;
            case 0x1DACF0u: goto label_1dacf0;
            case 0x1DACFCu: goto label_1dacfc;
            case 0x1DAD28u: goto label_1dad28;
            case 0x1DADBCu: goto label_1dadbc;
            case 0x1DAE14u: goto label_1dae14;
            case 0x1DAE20u: goto label_1dae20;
            case 0x1DAE48u: goto label_1dae48;
            case 0x1DAE94u: goto label_1dae94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DADD4u;
    // 0x1dadd4: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dadd4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dadd8: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dadd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1daddc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1daddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1dade0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dade0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dade4: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dade4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dade8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1dade8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dadec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1dadecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dadf0: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1DADF0u;
    {
        const bool branch_taken_0x1dadf0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1dadf0) {
            ctx->pc = 0x1DAE14u;
            goto label_1dae14;
        }
    }
    ctx->pc = 0x1DADF8u;
    // 0x1dadf8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dadf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dadfc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dadfcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dae00: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dae00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dae04: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dae04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dae08: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dae08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dae0c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DAE0Cu;
    {
        const bool branch_taken_0x1dae0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dae0c) {
            ctx->pc = 0x1DAE20u;
            goto label_1dae20;
        }
    }
    ctx->pc = 0x1DAE14u;
label_1dae14:
    // 0x1dae14: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1dae14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1dae18: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1DAE18u;
    {
        const bool branch_taken_0x1dae18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dae18) {
            ctx->pc = 0x1DAE94u;
            goto label_1dae94;
        }
    }
    ctx->pc = 0x1DAE20u;
label_1dae20:
    // 0x1dae20: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dae20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dae24: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1dae24u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dae28: 0x27828018  addiu       $v0, $gp, -0x7FE8
    ctx->pc = 0x1dae28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 28), 4294934552));
    // 0x1dae2c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1dae2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dae30: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dae30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dae34: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dae34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dae38: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae3c: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dae3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dae40: 0xc07cad6  jal         func_1F2B58
    ctx->pc = 0x1DAE40u;
    SET_GPR_U32(ctx, 31, 0x1DAE48u);
    ctx->pc = 0x1F2B58u;
    if (runtime->hasFunction(0x1F2B58u)) {
        auto targetFn = runtime->lookupFunction(0x1F2B58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAE48u; }
        if (ctx->pc != 0x1DAE48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2B58_0x1f2b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DAE48u; }
        if (ctx->pc != 0x1DAE48u) { return; }
    }
    ctx->pc = 0x1DAE48u;
label_1dae48:
    // 0x1dae48: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae4c: 0xac400524  sw          $zero, 0x524($v0)
    ctx->pc = 0x1dae4cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1316), GPR_U32(ctx, 0));
    // 0x1dae50: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae54: 0xac400528  sw          $zero, 0x528($v0)
    ctx->pc = 0x1dae54u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1320), GPR_U32(ctx, 0));
    // 0x1dae58: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae5c: 0xac40052c  sw          $zero, 0x52C($v0)
    ctx->pc = 0x1dae5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1324), GPR_U32(ctx, 0));
    // 0x1dae60: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae64: 0xac400530  sw          $zero, 0x530($v0)
    ctx->pc = 0x1dae64u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1328), GPR_U32(ctx, 0));
    // 0x1dae68: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae6c: 0xac400534  sw          $zero, 0x534($v0)
    ctx->pc = 0x1dae6cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1332), GPR_U32(ctx, 0));
    // 0x1dae70: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae74: 0xac400538  sw          $zero, 0x538($v0)
    ctx->pc = 0x1dae74u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1336), GPR_U32(ctx, 0));
    // 0x1dae78: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae7c: 0xac40053c  sw          $zero, 0x53C($v0)
    ctx->pc = 0x1dae7cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1340), GPR_U32(ctx, 0));
    // 0x1dae80: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae84: 0xac400540  sw          $zero, 0x540($v0)
    ctx->pc = 0x1dae84u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1344), GPR_U32(ctx, 0));
    // 0x1dae88: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dae88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dae8c: 0xac400544  sw          $zero, 0x544($v0)
    ctx->pc = 0x1dae8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1348), GPR_U32(ctx, 0));
    // 0x1dae90: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dae90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1dae94:
    // 0x1dae94: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dae94u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dae98: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dae98u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dae9c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1dae9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1daea0: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1daea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1daea4: 0x3e00008  jr          $ra
    ctx->pc = 0x1DAEA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DAB98u: goto label_1dab98;
            case 0x1DABA4u: goto label_1daba4;
            case 0x1DABFCu: goto label_1dabfc;
            case 0x1DAC50u: goto label_1dac50;
            case 0x1DAC5Cu: goto label_1dac5c;
            case 0x1DAC84u: goto label_1dac84;
            case 0x1DAC8Cu: goto label_1dac8c;
            case 0x1DAC94u: goto label_1dac94;
            case 0x1DACF0u: goto label_1dacf0;
            case 0x1DACFCu: goto label_1dacfc;
            case 0x1DAD28u: goto label_1dad28;
            case 0x1DADBCu: goto label_1dadbc;
            case 0x1DAE14u: goto label_1dae14;
            case 0x1DAE20u: goto label_1dae20;
            case 0x1DAE48u: goto label_1dae48;
            case 0x1DAE94u: goto label_1dae94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DAEACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
