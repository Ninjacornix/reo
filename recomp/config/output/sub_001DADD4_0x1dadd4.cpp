#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DADD4
// Address: 0x1dadd4 - 0x1daeac
void sub_001DADD4_0x1dadd4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DADD4_0x1dadd4");
#endif

    switch (ctx->pc) {
        case 0x1dae48u: goto label_1dae48;
        default: break;
    }

    ctx->pc = 0x1dadd4u;

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
