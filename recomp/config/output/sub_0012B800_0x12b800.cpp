#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B800
// Address: 0x12b800 - 0x12b898
void sub_0012B800_0x12b800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B800_0x12b800");
#endif

    switch (ctx->pc) {
        case 0x12b828u: goto label_12b828;
        case 0x12b830u: goto label_12b830;
        case 0x12b838u: goto label_12b838;
        case 0x12b840u: goto label_12b840;
        case 0x12b848u: goto label_12b848;
        case 0x12b860u: goto label_12b860;
        case 0x12b86cu: goto label_12b86c;
        case 0x12b878u: goto label_12b878;
        default: break;
    }

    ctx->pc = 0x12b800u;

    // 0x12b800: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12b800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12b804: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b804u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b808: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12b808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12b80c: 0x24630454  addiu       $v1, $v1, 0x454
    ctx->pc = 0x12b80cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1108));
    // 0x12b810: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12b810u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12b814: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x12b814u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12b818: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x12B818u;
    {
        const bool branch_taken_0x12b818 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12B81Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B818u;
            // 0x12b81c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b818) {
            ctx->pc = 0x12B888u;
            goto label_12b888;
        }
    }
    ctx->pc = 0x12B820u;
    // 0x12b820: 0xc04adec  jal         func_12B7B0
    ctx->pc = 0x12B820u;
    SET_GPR_U32(ctx, 31, 0x12B828u);
    ctx->pc = 0x12B7B0u;
    if (runtime->hasFunction(0x12B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x12B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B828u; }
        if (ctx->pc != 0x12B828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B7B0_0x12b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B828u; }
        if (ctx->pc != 0x12B828u) { return; }
    }
    ctx->pc = 0x12B828u;
label_12b828:
    // 0x12b828: 0xc04ae5a  jal         func_12B968
    ctx->pc = 0x12B828u;
    SET_GPR_U32(ctx, 31, 0x12B830u);
    ctx->pc = 0x12B968u;
    if (runtime->hasFunction(0x12B968u)) {
        auto targetFn = runtime->lookupFunction(0x12B968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B830u; }
        if (ctx->pc != 0x12B830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B968_0x12b968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B830u; }
        if (ctx->pc != 0x12B830u) { return; }
    }
    ctx->pc = 0x12B830u;
label_12b830:
    // 0x12b830: 0xc04aec2  jal         func_12BB08
    ctx->pc = 0x12B830u;
    SET_GPR_U32(ctx, 31, 0x12B838u);
    ctx->pc = 0x12BB08u;
    if (runtime->hasFunction(0x12BB08u)) {
        auto targetFn = runtime->lookupFunction(0x12BB08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B838u; }
        if (ctx->pc != 0x12B838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BB08_0x12bb08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B838u; }
        if (ctx->pc != 0x12B838u) { return; }
    }
    ctx->pc = 0x12B838u;
label_12b838:
    // 0x12b838: 0xc04ae8e  jal         func_12BA38
    ctx->pc = 0x12B838u;
    SET_GPR_U32(ctx, 31, 0x12B840u);
    ctx->pc = 0x12BA38u;
    if (runtime->hasFunction(0x12BA38u)) {
        auto targetFn = runtime->lookupFunction(0x12BA38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B840u; }
        if (ctx->pc != 0x12B840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BA38_0x12ba38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B840u; }
        if (ctx->pc != 0x12B840u) { return; }
    }
    ctx->pc = 0x12B840u;
label_12b840:
    // 0x12b840: 0xc04af2a  jal         func_12BCA8
    ctx->pc = 0x12B840u;
    SET_GPR_U32(ctx, 31, 0x12B848u);
    ctx->pc = 0x12BCA8u;
    if (runtime->hasFunction(0x12BCA8u)) {
        auto targetFn = runtime->lookupFunction(0x12BCA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B848u; }
        if (ctx->pc != 0x12B848u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BCA8_0x12bca8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B848u; }
        if (ctx->pc != 0x12B848u) { return; }
    }
    ctx->pc = 0x12B848u;
label_12b848:
    // 0x12b848: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b848u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b84c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b84cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b850: 0x244204e8  addiu       $v0, $v0, 0x4E8
    ctx->pc = 0x12b850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1256));
    // 0x12b854: 0x8c657d78  lw          $a1, 0x7D78($v1)
    ctx->pc = 0x12b854u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32120)));
    // 0x12b858: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B858u;
    SET_GPR_U32(ctx, 31, 0x12B860u);
    ctx->pc = 0x12B85Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B858u;
            // 0x12b85c: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B860u; }
        if (ctx->pc != 0x12B860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B860u; }
        if (ctx->pc != 0x12B860u) { return; }
    }
    ctx->pc = 0x12B860u;
label_12b860:
    // 0x12b860: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x12b860u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b864: 0xc05077c  jal         func_141DF0
    ctx->pc = 0x12B864u;
    SET_GPR_U32(ctx, 31, 0x12B86Cu);
    ctx->pc = 0x12B868u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B864u;
            // 0x12b868: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141DF0u;
    if (runtime->hasFunction(0x141DF0u)) {
        auto targetFn = runtime->lookupFunction(0x141DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B86Cu; }
        if (ctx->pc != 0x12B86Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141DF0_0x141df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B86Cu; }
        if (ctx->pc != 0x12B86Cu) { return; }
    }
    ctx->pc = 0x12B86Cu;
label_12b86c:
    // 0x12b86c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x12b86cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b870: 0xc050782  jal         func_141E08
    ctx->pc = 0x12B870u;
    SET_GPR_U32(ctx, 31, 0x12B878u);
    ctx->pc = 0x12B874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B870u;
            // 0x12b874: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141E08u;
    if (runtime->hasFunction(0x141E08u)) {
        auto targetFn = runtime->lookupFunction(0x141E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B878u; }
        if (ctx->pc != 0x12B878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141E08_0x141e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B878u; }
        if (ctx->pc != 0x12B878u) { return; }
    }
    ctx->pc = 0x12B878u;
label_12b878:
    // 0x12b878: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12b878u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b87c: 0x805084e  j           func_142138
    ctx->pc = 0x12B87Cu;
    ctx->pc = 0x12B880u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B87Cu;
            // 0x12b880: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142138u;
    if (runtime->hasFunction(0x142138u)) {
        auto targetFn = runtime->lookupFunction(0x142138u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00142138_0x142138(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12B884u;
    // 0x12b884: 0x0  nop
    ctx->pc = 0x12b884u;
    // NOP
label_12b888:
    // 0x12b888: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12b888u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12b88c: 0x3e00008  jr          $ra
    ctx->pc = 0x12B88Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B88Cu;
            // 0x12b890: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B828u: goto label_12b828;
            case 0x12B830u: goto label_12b830;
            case 0x12B838u: goto label_12b838;
            case 0x12B840u: goto label_12b840;
            case 0x12B848u: goto label_12b848;
            case 0x12B860u: goto label_12b860;
            case 0x12B86Cu: goto label_12b86c;
            case 0x12B878u: goto label_12b878;
            case 0x12B888u: goto label_12b888;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B894u;
    // 0x12b894: 0x0  nop
    ctx->pc = 0x12b894u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
