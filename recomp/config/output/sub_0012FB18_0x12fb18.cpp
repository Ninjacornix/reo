#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FB18
// Address: 0x12fb18 - 0x12fb7c
void sub_0012FB18_0x12fb18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FB18_0x12fb18");
#endif

    switch (ctx->pc) {
        case 0x12fb40u: goto label_12fb40;
        case 0x12fb48u: goto label_12fb48;
        case 0x12fb60u: goto label_12fb60;
        case 0x12fb68u: goto label_12fb68;
        default: break;
    }

    ctx->pc = 0x12fb18u;

    // 0x12fb18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12fb18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12fb1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12fb1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12fb20: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12fb20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fb24: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12fb24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12fb28: 0xae050044  sw          $a1, 0x44($s0)
    ctx->pc = 0x12fb28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 5));
    // 0x12fb2c: 0x8e020080  lw          $v0, 0x80($s0)
    ctx->pc = 0x12fb2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x12fb30: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12FB30u;
    {
        const bool branch_taken_0x12fb30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB30u;
            // 0x12fb34: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fb30) {
            ctx->pc = 0x12FB40u;
            goto label_12fb40;
        }
    }
    ctx->pc = 0x12FB38u;
    // 0x12fb38: 0xc04b8c8  jal         func_12E320
    ctx->pc = 0x12FB38u;
    SET_GPR_U32(ctx, 31, 0x12FB40u);
    ctx->pc = 0x12E320u;
    if (runtime->hasFunction(0x12E320u)) {
        auto targetFn = runtime->lookupFunction(0x12E320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FB40u; }
        if (ctx->pc != 0x12FB40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E320_0x12e320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FB40u; }
        if (ctx->pc != 0x12FB40u) { return; }
    }
    ctx->pc = 0x12FB40u;
label_12fb40:
    // 0x12fb40: 0xc04b8a0  jal         func_12E280
    ctx->pc = 0x12FB40u;
    SET_GPR_U32(ctx, 31, 0x12FB48u);
    ctx->pc = 0x12FB44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB40u;
            // 0x12fb44: 0x8e040044  lw          $a0, 0x44($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E280u;
    if (runtime->hasFunction(0x12E280u)) {
        auto targetFn = runtime->lookupFunction(0x12E280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FB48u; }
        if (ctx->pc != 0x12FB48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E280_0x12e280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FB48u; }
        if (ctx->pc != 0x12FB48u) { return; }
    }
    ctx->pc = 0x12FB48u;
label_12fb48:
    // 0x12fb48: 0x8e030084  lw          $v1, 0x84($s0)
    ctx->pc = 0x12fb48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x12fb4c: 0xae020080  sw          $v0, 0x80($s0)
    ctx->pc = 0x12fb4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 128), GPR_U32(ctx, 2));
    // 0x12fb50: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12FB50u;
    {
        const bool branch_taken_0x12fb50 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB50u;
            // 0x12fb54: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fb50) {
            ctx->pc = 0x12FB60u;
            goto label_12fb60;
        }
    }
    ctx->pc = 0x12FB58u;
    // 0x12fb58: 0xc04b8c8  jal         func_12E320
    ctx->pc = 0x12FB58u;
    SET_GPR_U32(ctx, 31, 0x12FB60u);
    ctx->pc = 0x12E320u;
    if (runtime->hasFunction(0x12E320u)) {
        auto targetFn = runtime->lookupFunction(0x12E320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FB60u; }
        if (ctx->pc != 0x12FB60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E320_0x12e320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FB60u; }
        if (ctx->pc != 0x12FB60u) { return; }
    }
    ctx->pc = 0x12FB60u;
label_12fb60:
    // 0x12fb60: 0xc04b8a0  jal         func_12E280
    ctx->pc = 0x12FB60u;
    SET_GPR_U32(ctx, 31, 0x12FB68u);
    ctx->pc = 0x12FB64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB60u;
            // 0x12fb64: 0x8e040044  lw          $a0, 0x44($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E280u;
    if (runtime->hasFunction(0x12E280u)) {
        auto targetFn = runtime->lookupFunction(0x12E280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FB68u; }
        if (ctx->pc != 0x12FB68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E280_0x12e280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FB68u; }
        if (ctx->pc != 0x12FB68u) { return; }
    }
    ctx->pc = 0x12FB68u;
label_12fb68:
    // 0x12fb68: 0xae020084  sw          $v0, 0x84($s0)
    ctx->pc = 0x12fb68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 2));
    // 0x12fb6c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12fb6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12fb70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12fb70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fb74: 0x3e00008  jr          $ra
    ctx->pc = 0x12FB74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FB78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FB74u;
            // 0x12fb78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FB40u: goto label_12fb40;
            case 0x12FB48u: goto label_12fb48;
            case 0x12FB60u: goto label_12fb60;
            case 0x12FB68u: goto label_12fb68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FB7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
