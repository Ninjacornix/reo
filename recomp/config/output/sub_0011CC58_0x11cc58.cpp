#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011CC58
// Address: 0x11cc58 - 0x11cca8
void sub_0011CC58_0x11cc58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011CC58_0x11cc58");
#endif

    switch (ctx->pc) {
        case 0x11cc68u: goto label_11cc68;
        case 0x11cc80u: goto label_11cc80;
        case 0x11cc8cu: goto label_11cc8c;
        case 0x11cc98u: goto label_11cc98;
        default: break;
    }

    ctx->pc = 0x11cc58u;

    // 0x11cc58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x11cc58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11cc5c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x11cc5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11cc60: 0xc04528c  jal         func_114A30
    ctx->pc = 0x11CC60u;
    SET_GPR_U32(ctx, 31, 0x11CC68u);
    ctx->pc = 0x11CC64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC60u;
            // 0x11cc64: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A30u;
    if (runtime->hasFunction(0x114A30u)) {
        auto targetFn = runtime->lookupFunction(0x114A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC68u; }
        if (ctx->pc != 0x11CC68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A30_0x114a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC68u; }
        if (ctx->pc != 0x11CC68u) { return; }
    }
    ctx->pc = 0x11CC68u;
label_11cc68:
    // 0x11cc68: 0x3c030004  lui         $v1, 0x4
    ctx->pc = 0x11cc68u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4 << 16));
    // 0x11cc6c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x11cc6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x11cc70: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x11CC70u;
    {
        const bool branch_taken_0x11cc70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11CC74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC70u;
            // 0x11cc74: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11cc70) {
            ctx->pc = 0x11CC9Cu;
            goto label_11cc9c;
        }
    }
    ctx->pc = 0x11CC78u;
    // 0x11cc78: 0xc0452a8  jal         func_114AA0
    ctx->pc = 0x11CC78u;
    SET_GPR_U32(ctx, 31, 0x11CC80u);
    ctx->pc = 0x114AA0u;
    if (runtime->hasFunction(0x114AA0u)) {
        auto targetFn = runtime->lookupFunction(0x114AA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC80u; }
        if (ctx->pc != 0x11CC80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114AA0_0x114aa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC80u; }
        if (ctx->pc != 0x11CC80u) { return; }
    }
    ctx->pc = 0x11CC80u;
label_11cc80:
    // 0x11cc80: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x11cc80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11cc84: 0xc047df4  jal         func_11F7D0
    ctx->pc = 0x11CC84u;
    SET_GPR_U32(ctx, 31, 0x11CC8Cu);
    ctx->pc = 0x11CC88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC84u;
            // 0x11cc88: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F7D0u;
    if (runtime->hasFunction(0x11F7D0u)) {
        auto targetFn = runtime->lookupFunction(0x11F7D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC8Cu; }
        if (ctx->pc != 0x11CC8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011F7D0_0x11f7d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC8Cu; }
        if (ctx->pc != 0x11CC8Cu) { return; }
    }
    ctx->pc = 0x11CC8Cu;
label_11cc8c:
    // 0x11cc8c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x11cc8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11cc90: 0xc047df4  jal         func_11F7D0
    ctx->pc = 0x11CC90u;
    SET_GPR_U32(ctx, 31, 0x11CC98u);
    ctx->pc = 0x11CC94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11CC90u;
            // 0x11cc94: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F7D0u;
    if (runtime->hasFunction(0x11F7D0u)) {
        auto targetFn = runtime->lookupFunction(0x11F7D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC98u; }
        if (ctx->pc != 0x11CC98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011F7D0_0x11f7d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11CC98u; }
        if (ctx->pc != 0x11CC98u) { return; }
    }
    ctx->pc = 0x11CC98u;
label_11cc98:
    // 0x11cc98: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11cc98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_11cc9c:
    // 0x11cc9c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11cc9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11cca0: 0x3e00008  jr          $ra
    ctx->pc = 0x11CCA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11CCA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11CCA0u;
            // 0x11cca4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11CC68u: goto label_11cc68;
            case 0x11CC80u: goto label_11cc80;
            case 0x11CC8Cu: goto label_11cc8c;
            case 0x11CC98u: goto label_11cc98;
            case 0x11CC9Cu: goto label_11cc9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11CCA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
