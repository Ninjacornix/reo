#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB230
// Address: 0x1bb230 - 0x1bb2b0
void sub_001BB230_0x1bb230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB230_0x1bb230");
#endif

    switch (ctx->pc) {
        case 0x1bb240u: goto label_1bb240;
        case 0x1bb248u: goto label_1bb248;
        case 0x1bb250u: goto label_1bb250;
        case 0x1bb258u: goto label_1bb258;
        case 0x1bb260u: goto label_1bb260;
        case 0x1bb268u: goto label_1bb268;
        case 0x1bb270u: goto label_1bb270;
        case 0x1bb280u: goto label_1bb280;
        case 0x1bb288u: goto label_1bb288;
        case 0x1bb290u: goto label_1bb290;
        default: break;
    }

    ctx->pc = 0x1bb230u;

    // 0x1bb230: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bb230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb234: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bb234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb238: 0xc06b700  jal         func_1ADC00
    ctx->pc = 0x1BB238u;
    SET_GPR_U32(ctx, 31, 0x1BB240u);
    ctx->pc = 0x1ADC00u;
    if (runtime->hasFunction(0x1ADC00u)) {
        auto targetFn = runtime->lookupFunction(0x1ADC00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB240u; }
        if (ctx->pc != 0x1BB240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADC00_0x1adc00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB240u; }
        if (ctx->pc != 0x1BB240u) { return; }
    }
    ctx->pc = 0x1BB240u;
label_1bb240:
    // 0x1bb240: 0xc06e0b8  jal         func_1B82E0
    ctx->pc = 0x1BB240u;
    SET_GPR_U32(ctx, 31, 0x1BB248u);
    ctx->pc = 0x1B82E0u;
    if (runtime->hasFunction(0x1B82E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB248u; }
        if (ctx->pc != 0x1BB248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82E0_0x1b82e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB248u; }
        if (ctx->pc != 0x1BB248u) { return; }
    }
    ctx->pc = 0x1BB248u;
label_1bb248:
    // 0x1bb248: 0xc06bb58  jal         func_1AED60
    ctx->pc = 0x1BB248u;
    SET_GPR_U32(ctx, 31, 0x1BB250u);
    ctx->pc = 0x1AED60u;
    if (runtime->hasFunction(0x1AED60u)) {
        auto targetFn = runtime->lookupFunction(0x1AED60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB250u; }
        if (ctx->pc != 0x1BB250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AED60_0x1aed60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB250u; }
        if (ctx->pc != 0x1BB250u) { return; }
    }
    ctx->pc = 0x1BB250u;
label_1bb250:
    // 0x1bb250: 0xc06eb08  jal         func_1BAC20
    ctx->pc = 0x1BB250u;
    SET_GPR_U32(ctx, 31, 0x1BB258u);
    ctx->pc = 0x1BAC20u;
    if (runtime->hasFunction(0x1BAC20u)) {
        auto targetFn = runtime->lookupFunction(0x1BAC20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB258u; }
        if (ctx->pc != 0x1BB258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BAC20_0x1bac20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB258u; }
        if (ctx->pc != 0x1BB258u) { return; }
    }
    ctx->pc = 0x1BB258u;
label_1bb258:
    // 0x1bb258: 0xc06bddc  jal         func_1AF770
    ctx->pc = 0x1BB258u;
    SET_GPR_U32(ctx, 31, 0x1BB260u);
    ctx->pc = 0x1AF770u;
    if (runtime->hasFunction(0x1AF770u)) {
        auto targetFn = runtime->lookupFunction(0x1AF770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB260u; }
        if (ctx->pc != 0x1BB260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF770_0x1af770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB260u; }
        if (ctx->pc != 0x1BB260u) { return; }
    }
    ctx->pc = 0x1BB260u;
label_1bb260:
    // 0x1bb260: 0xc073254  jal         func_1CC950
    ctx->pc = 0x1BB260u;
    SET_GPR_U32(ctx, 31, 0x1BB268u);
    ctx->pc = 0x1CC950u;
    if (runtime->hasFunction(0x1CC950u)) {
        auto targetFn = runtime->lookupFunction(0x1CC950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB268u; }
        if (ctx->pc != 0x1BB268u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC950_0x1cc950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB268u; }
        if (ctx->pc != 0x1BB268u) { return; }
    }
    ctx->pc = 0x1BB268u;
label_1bb268:
    // 0x1bb268: 0xc06be70  jal         func_1AF9C0
    ctx->pc = 0x1BB268u;
    SET_GPR_U32(ctx, 31, 0x1BB270u);
    ctx->pc = 0x1AF9C0u;
    if (runtime->hasFunction(0x1AF9C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF9C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB270u; }
        if (ctx->pc != 0x1BB270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF9C0_0x1af9c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB270u; }
        if (ctx->pc != 0x1BB270u) { return; }
    }
    ctx->pc = 0x1BB270u;
label_1bb270:
    // 0x1bb270: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb270u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb274: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bb274u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bb278: 0xc06ec44  jal         func_1BB110
    ctx->pc = 0x1BB278u;
    SET_GPR_U32(ctx, 31, 0x1BB280u);
    ctx->pc = 0x1BB27Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB278u;
            // 0x1bb27c: 0xac224e20  sw          $v0, 0x4E20($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20000), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BB110u;
    if (runtime->hasFunction(0x1BB110u)) {
        auto targetFn = runtime->lookupFunction(0x1BB110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB280u; }
        if (ctx->pc != 0x1BB280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB110_0x1bb110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB280u; }
        if (ctx->pc != 0x1BB280u) { return; }
    }
    ctx->pc = 0x1BB280u;
label_1bb280:
    // 0x1bb280: 0xc06bb14  jal         func_1AEC50
    ctx->pc = 0x1BB280u;
    SET_GPR_U32(ctx, 31, 0x1BB288u);
    ctx->pc = 0x1AEC50u;
    if (runtime->hasFunction(0x1AEC50u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB288u; }
        if (ctx->pc != 0x1BB288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC50_0x1aec50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB288u; }
        if (ctx->pc != 0x1BB288u) { return; }
    }
    ctx->pc = 0x1BB288u;
label_1bb288:
    // 0x1bb288: 0xc06df24  jal         func_1B7C90
    ctx->pc = 0x1BB288u;
    SET_GPR_U32(ctx, 31, 0x1BB290u);
    ctx->pc = 0x1B7C90u;
    if (runtime->hasFunction(0x1B7C90u)) {
        auto targetFn = runtime->lookupFunction(0x1B7C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB290u; }
        if (ctx->pc != 0x1BB290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7C90_0x1b7c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB290u; }
        if (ctx->pc != 0x1BB290u) { return; }
    }
    ctx->pc = 0x1BB290u;
label_1bb290:
    // 0x1bb290: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bb290u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bb294: 0xac204190  sw          $zero, 0x4190($at)
    ctx->pc = 0x1bb294u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16784), GPR_U32(ctx, 0));
    // 0x1bb298: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bb298u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb29c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB29Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB29Cu;
            // 0x1bb2a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB240u: goto label_1bb240;
            case 0x1BB248u: goto label_1bb248;
            case 0x1BB250u: goto label_1bb250;
            case 0x1BB258u: goto label_1bb258;
            case 0x1BB260u: goto label_1bb260;
            case 0x1BB268u: goto label_1bb268;
            case 0x1BB270u: goto label_1bb270;
            case 0x1BB280u: goto label_1bb280;
            case 0x1BB288u: goto label_1bb288;
            case 0x1BB290u: goto label_1bb290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB2A4u;
    // 0x1bb2a4: 0x0  nop
    ctx->pc = 0x1bb2a4u;
    // NOP
    // 0x1bb2a8: 0x0  nop
    ctx->pc = 0x1bb2a8u;
    // NOP
    // 0x1bb2ac: 0x0  nop
    ctx->pc = 0x1bb2acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
