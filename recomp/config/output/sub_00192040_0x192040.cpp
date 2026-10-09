#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192040
// Address: 0x192040 - 0x1920a0
void sub_00192040_0x192040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192040_0x192040");
#endif

    switch (ctx->pc) {
        case 0x19206cu: goto label_19206c;
        case 0x19207cu: goto label_19207c;
        case 0x19208cu: goto label_19208c;
        default: break;
    }

    ctx->pc = 0x192040u;

    // 0x192040: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x192040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x192044: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x192044u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x192048: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x192048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19204c: 0x34463f40  ori         $a2, $v0, 0x3F40
    ctx->pc = 0x19204cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16192);
    // 0x192050: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192050u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x192054: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x192054u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192058: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x192058u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19205c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x19205cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192060: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x192060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x192064: 0xc0644a0  jal         func_191280
    ctx->pc = 0x192064u;
    SET_GPR_U32(ctx, 31, 0x19206Cu);
    ctx->pc = 0x192068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192064u;
            // 0x192068: 0x34453700  ori         $a1, $v0, 0x3700 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19206Cu; }
        if (ctx->pc != 0x19206Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19206Cu; }
        if (ctx->pc != 0x19206Cu) { return; }
    }
    ctx->pc = 0x19206Cu;
label_19206c:
    // 0x19206c: 0x3c050029  lui         $a1, 0x29
    ctx->pc = 0x19206cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)41 << 16));
    // 0x192070: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x192070u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x192074: 0xc0644c0  jal         func_191300
    ctx->pc = 0x192074u;
    SET_GPR_U32(ctx, 31, 0x19207Cu);
    ctx->pc = 0x192078u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192074u;
            // 0x192078: 0x24a54d80  addiu       $a1, $a1, 0x4D80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19840));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191300u;
    if (runtime->hasFunction(0x191300u)) {
        auto targetFn = runtime->lookupFunction(0x191300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19207Cu; }
        if (ctx->pc != 0x19207Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191300_0x191300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19207Cu; }
        if (ctx->pc != 0x19207Cu) { return; }
    }
    ctx->pc = 0x19207Cu;
label_19207c:
    // 0x19207c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x19207cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192080: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x192080u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192084: 0xc0646ac  jal         func_191AB0
    ctx->pc = 0x192084u;
    SET_GPR_U32(ctx, 31, 0x19208Cu);
    ctx->pc = 0x192088u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192084u;
            // 0x192088: 0x27a60030  addiu       $a2, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191AB0u;
    if (runtime->hasFunction(0x191AB0u)) {
        auto targetFn = runtime->lookupFunction(0x191AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19208Cu; }
        if (ctx->pc != 0x19208Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191AB0_0x191ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19208Cu; }
        if (ctx->pc != 0x19208Cu) { return; }
    }
    ctx->pc = 0x19208Cu;
label_19208c:
    // 0x19208c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x19208cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192090: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x192090u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192094: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x192094u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192098: 0x3e00008  jr          $ra
    ctx->pc = 0x192098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19209Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192098u;
            // 0x19209c: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19206Cu: goto label_19206c;
            case 0x19207Cu: goto label_19207c;
            case 0x19208Cu: goto label_19208c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1920A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
