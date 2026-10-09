#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFC60
// Address: 0x1afc60 - 0x1afce0
void sub_001AFC60_0x1afc60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFC60_0x1afc60");
#endif

    switch (ctx->pc) {
        case 0x1afc80u: goto label_1afc80;
        case 0x1afcc4u: goto label_1afcc4;
        case 0x1afcd4u: goto label_1afcd4;
        default: break;
    }

    ctx->pc = 0x1afc60u;

    // 0x1afc60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afc60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afc64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1afc64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1afc68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afc68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afc6c: 0x902343fa  lbu         $v1, 0x43FA($at)
    ctx->pc = 0x1afc6cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17402)));
    // 0x1afc70: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1AFC70u;
    {
        const bool branch_taken_0x1afc70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afc70) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFC78u;
    // 0x1afc78: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFC78u;
    SET_GPR_U32(ctx, 31, 0x1AFC80u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC80u; }
        if (ctx->pc != 0x1AFC80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC80u; }
        if (ctx->pc != 0x1AFC80u) { return; }
    }
    ctx->pc = 0x1AFC80u;
label_1afc80:
    // 0x1afc80: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afc80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afc84: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1AFC84u;
    {
        const bool branch_taken_0x1afc84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFC84u;
            // 0x1afc88: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afc84) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFC8Cu;
    // 0x1afc8c: 0x10430011  beq         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1AFC8Cu;
    {
        const bool branch_taken_0x1afc8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afc8c) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFC94u;
    // 0x1afc94: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afc94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afc98: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1AFC98u;
    {
        const bool branch_taken_0x1afc98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afc98) {
            ctx->pc = 0x1AFCCCu;
            goto label_1afccc;
        }
    }
    ctx->pc = 0x1AFCA0u;
    // 0x1afca0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFCA0u;
    {
        const bool branch_taken_0x1afca0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFCA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFCA0u;
            // 0x1afca4: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afca0) {
            ctx->pc = 0x1AFCB0u;
            goto label_1afcb0;
        }
    }
    ctx->pc = 0x1AFCA8u;
    // 0x1afca8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1AFCA8u;
    {
        const bool branch_taken_0x1afca8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFCACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFCA8u;
            // 0x1afcac: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afca8) {
            ctx->pc = 0x1AFCD8u;
            goto label_1afcd8;
        }
    }
    ctx->pc = 0x1AFCB0u;
label_1afcb0:
    // 0x1afcb0: 0x9023ae94  lbu         $v1, -0x516C($at)
    ctx->pc = 0x1afcb0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946452)));
    // 0x1afcb4: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AFCB4u;
    {
        const bool branch_taken_0x1afcb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1afcb4) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFCBCu;
    // 0x1afcbc: 0xc204080  jal         func_810200
    ctx->pc = 0x1AFCBCu;
    SET_GPR_U32(ctx, 31, 0x1AFCC4u);
    ctx->pc = 0x810200u;
    {
        auto targetFn = runtime->lookupFunction(0x810200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFCC4u; }
        if (ctx->pc != 0x1AFCC4u) { return; }
    }
    ctx->pc = 0x1AFCC4u;
label_1afcc4:
    // 0x1afcc4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFCC4u;
    {
        const bool branch_taken_0x1afcc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afcc4) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFCCCu;
label_1afccc:
    // 0x1afccc: 0xc204778  jal         func_811DE0
    ctx->pc = 0x1AFCCCu;
    SET_GPR_U32(ctx, 31, 0x1AFCD4u);
    ctx->pc = 0x811DE0u;
    {
        auto targetFn = runtime->lookupFunction(0x811DE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFCD4u; }
        if (ctx->pc != 0x1AFCD4u) { return; }
    }
    ctx->pc = 0x1AFCD4u;
label_1afcd4:
    // 0x1afcd4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afcd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afcd8:
    // 0x1afcd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFCD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFCDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFCD8u;
            // 0x1afcdc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFC80u: goto label_1afc80;
            case 0x1AFCB0u: goto label_1afcb0;
            case 0x1AFCC4u: goto label_1afcc4;
            case 0x1AFCCCu: goto label_1afccc;
            case 0x1AFCD4u: goto label_1afcd4;
            case 0x1AFCD8u: goto label_1afcd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFCE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
