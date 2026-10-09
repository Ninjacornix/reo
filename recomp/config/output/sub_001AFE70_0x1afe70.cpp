#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFE70
// Address: 0x1afe70 - 0x1afee0
void sub_001AFE70_0x1afe70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFE70_0x1afe70");
#endif

    switch (ctx->pc) {
        case 0x1afe80u: goto label_1afe80;
        case 0x1afeb8u: goto label_1afeb8;
        case 0x1afec8u: goto label_1afec8;
        default: break;
    }

    ctx->pc = 0x1afe70u;

    // 0x1afe70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afe70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afe74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afe74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afe78: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFE78u;
    SET_GPR_U32(ctx, 31, 0x1AFE80u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFE80u; }
        if (ctx->pc != 0x1AFE80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFE80u; }
        if (ctx->pc != 0x1AFE80u) { return; }
    }
    ctx->pc = 0x1AFE80u;
label_1afe80:
    // 0x1afe80: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afe80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afe84: 0x10430012  beq         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AFE84u;
    {
        const bool branch_taken_0x1afe84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFE88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFE84u;
            // 0x1afe88: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afe84) {
            ctx->pc = 0x1AFED0u;
            goto label_1afed0;
        }
    }
    ctx->pc = 0x1AFE8Cu;
    // 0x1afe8c: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFE8Cu;
    {
        const bool branch_taken_0x1afe8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afe8c) {
            ctx->pc = 0x1AFED0u;
            goto label_1afed0;
        }
    }
    ctx->pc = 0x1AFE94u;
    // 0x1afe94: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afe94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afe98: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFE98u;
    {
        const bool branch_taken_0x1afe98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afe98) {
            ctx->pc = 0x1AFEC0u;
            goto label_1afec0;
        }
    }
    ctx->pc = 0x1AFEA0u;
    // 0x1afea0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFEA0u;
    {
        const bool branch_taken_0x1afea0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afea0) {
            ctx->pc = 0x1AFEB0u;
            goto label_1afeb0;
        }
    }
    ctx->pc = 0x1AFEA8u;
    // 0x1afea8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1AFEA8u;
    {
        const bool branch_taken_0x1afea8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFEACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFEA8u;
            // 0x1afeac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afea8) {
            ctx->pc = 0x1AFED4u;
            goto label_1afed4;
        }
    }
    ctx->pc = 0x1AFEB0u;
label_1afeb0:
    // 0x1afeb0: 0xc2045dc  jal         func_811770
    ctx->pc = 0x1AFEB0u;
    SET_GPR_U32(ctx, 31, 0x1AFEB8u);
    ctx->pc = 0x811770u;
    {
        auto targetFn = runtime->lookupFunction(0x811770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFEB8u; }
        if (ctx->pc != 0x1AFEB8u) { return; }
    }
    ctx->pc = 0x1AFEB8u;
label_1afeb8:
    // 0x1afeb8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1AFEB8u;
    {
        const bool branch_taken_0x1afeb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFEBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFEB8u;
            // 0x1afebc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afeb8) {
            ctx->pc = 0x1AFED8u;
            goto label_1afed8;
        }
    }
    ctx->pc = 0x1AFEC0u;
label_1afec0:
    // 0x1afec0: 0xc2043cc  jal         func_810F30
    ctx->pc = 0x1AFEC0u;
    SET_GPR_U32(ctx, 31, 0x1AFEC8u);
    ctx->pc = 0x810F30u;
    {
        auto targetFn = runtime->lookupFunction(0x810F30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFEC8u; }
        if (ctx->pc != 0x1AFEC8u) { return; }
    }
    ctx->pc = 0x1AFEC8u;
label_1afec8:
    // 0x1afec8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1AFEC8u;
    {
        const bool branch_taken_0x1afec8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afec8) {
            ctx->pc = 0x1AFED4u;
            goto label_1afed4;
        }
    }
    ctx->pc = 0x1AFED0u;
label_1afed0:
    // 0x1afed0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1afed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1afed4:
    // 0x1afed4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afed8:
    // 0x1afed8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFEDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFED8u;
            // 0x1afedc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFE80u: goto label_1afe80;
            case 0x1AFEB0u: goto label_1afeb0;
            case 0x1AFEB8u: goto label_1afeb8;
            case 0x1AFEC0u: goto label_1afec0;
            case 0x1AFEC8u: goto label_1afec8;
            case 0x1AFED0u: goto label_1afed0;
            case 0x1AFED4u: goto label_1afed4;
            case 0x1AFED8u: goto label_1afed8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFEE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
