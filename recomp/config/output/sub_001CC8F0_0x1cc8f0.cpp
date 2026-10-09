#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC8F0
// Address: 0x1cc8f0 - 0x1cc950
void sub_001CC8F0_0x1cc8f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC8F0_0x1cc8f0");
#endif

    switch (ctx->pc) {
        case 0x1cc90cu: goto label_1cc90c;
        case 0x1cc928u: goto label_1cc928;
        case 0x1cc938u: goto label_1cc938;
        default: break;
    }

    ctx->pc = 0x1cc8f0u;

    // 0x1cc8f0: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1cc8f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1cc8f4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cc8f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cc8f8: 0xc21024  and         $v0, $a2, $v0
    ctx->pc = 0x1cc8f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x1cc8fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CC8FCu;
    {
        const bool branch_taken_0x1cc8fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC8FCu;
            // 0x1cc900: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc8fc) {
            ctx->pc = 0x1CC914u;
            goto label_1cc914;
        }
    }
    ctx->pc = 0x1CC904u;
    // 0x1cc904: 0xc06a8f8  jal         func_1AA3E0
    ctx->pc = 0x1CC904u;
    SET_GPR_U32(ctx, 31, 0x1CC90Cu);
    ctx->pc = 0x1AA3E0u;
    if (runtime->hasFunction(0x1AA3E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC90Cu; }
        if (ctx->pc != 0x1CC90Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC90Cu; }
        if (ctx->pc != 0x1CC90Cu) { return; }
    }
    ctx->pc = 0x1CC90Cu;
label_1cc90c:
    // 0x1cc90c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1CC90Cu;
    {
        const bool branch_taken_0x1cc90c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC90Cu;
            // 0x1cc910: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc90c) {
            ctx->pc = 0x1CC93Cu;
            goto label_1cc93c;
        }
    }
    ctx->pc = 0x1CC914u;
label_1cc914:
    // 0x1cc914: 0x30c2ffff  andi        $v0, $a2, 0xFFFF
    ctx->pc = 0x1cc914u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x1cc918: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CC918u;
    {
        const bool branch_taken_0x1cc918 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cc918) {
            ctx->pc = 0x1CC930u;
            goto label_1cc930;
        }
    }
    ctx->pc = 0x1CC920u;
    // 0x1cc920: 0xc06a928  jal         func_1AA4A0
    ctx->pc = 0x1CC920u;
    SET_GPR_U32(ctx, 31, 0x1CC928u);
    ctx->pc = 0x1AA4A0u;
    if (runtime->hasFunction(0x1AA4A0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC928u; }
        if (ctx->pc != 0x1CC928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA4A0_0x1aa4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC928u; }
        if (ctx->pc != 0x1CC928u) { return; }
    }
    ctx->pc = 0x1CC928u;
label_1cc928:
    // 0x1cc928: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1CC928u;
    {
        const bool branch_taken_0x1cc928 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc928) {
            ctx->pc = 0x1CC938u;
            goto label_1cc938;
        }
    }
    ctx->pc = 0x1CC930u;
label_1cc930:
    // 0x1cc930: 0xc06a920  jal         func_1AA480
    ctx->pc = 0x1CC930u;
    SET_GPR_U32(ctx, 31, 0x1CC938u);
    ctx->pc = 0x1AA480u;
    if (runtime->hasFunction(0x1AA480u)) {
        auto targetFn = runtime->lookupFunction(0x1AA480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC938u; }
        if (ctx->pc != 0x1CC938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA480_0x1aa480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC938u; }
        if (ctx->pc != 0x1CC938u) { return; }
    }
    ctx->pc = 0x1CC938u;
label_1cc938:
    // 0x1cc938: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc938u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1cc93c:
    // 0x1cc93c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC93Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC93Cu;
            // 0x1cc940: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC90Cu: goto label_1cc90c;
            case 0x1CC914u: goto label_1cc914;
            case 0x1CC928u: goto label_1cc928;
            case 0x1CC930u: goto label_1cc930;
            case 0x1CC938u: goto label_1cc938;
            case 0x1CC93Cu: goto label_1cc93c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC944u;
    // 0x1cc944: 0x0  nop
    ctx->pc = 0x1cc944u;
    // NOP
    // 0x1cc948: 0x0  nop
    ctx->pc = 0x1cc948u;
    // NOP
    // 0x1cc94c: 0x0  nop
    ctx->pc = 0x1cc94cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
