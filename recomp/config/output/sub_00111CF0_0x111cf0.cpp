#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111CF0
// Address: 0x111cf0 - 0x111d48
void sub_00111CF0_0x111cf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111CF0_0x111cf0");
#endif

    switch (ctx->pc) {
        case 0x111d10u: goto label_111d10;
        case 0x111d20u: goto label_111d20;
        case 0x111d30u: goto label_111d30;
        case 0x111d38u: goto label_111d38;
        default: break;
    }

    ctx->pc = 0x111cf0u;

    // 0x111cf0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x111cf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x111cf4: 0xffa40060  sd          $a0, 0x60($sp)
    ctx->pc = 0x111cf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 4));
    // 0x111cf8: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x111cf8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x111cfc: 0xffa50068  sd          $a1, 0x68($sp)
    ctx->pc = 0x111cfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 5));
    // 0x111d00: 0xffb00070  sd          $s0, 0x70($sp)
    ctx->pc = 0x111d00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 16));
    // 0x111d04: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x111d04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x111d08: 0xc044674  jal         func_1119D0
    ctx->pc = 0x111D08u;
    SET_GPR_U32(ctx, 31, 0x111D10u);
    ctx->pc = 0x111D0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111D08u;
            // 0x111d0c: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D10u; }
        if (ctx->pc != 0x111D10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D10u; }
        if (ctx->pc != 0x111D10u) { return; }
    }
    ctx->pc = 0x111D10u;
label_111d10:
    // 0x111d10: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x111d10u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x111d14: 0x27a40068  addiu       $a0, $sp, 0x68
    ctx->pc = 0x111d14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x111d18: 0xc044674  jal         func_1119D0
    ctx->pc = 0x111D18u;
    SET_GPR_U32(ctx, 31, 0x111D20u);
    ctx->pc = 0x111D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111D18u;
            // 0x111d1c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D20u; }
        if (ctx->pc != 0x111D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D20u; }
        if (ctx->pc != 0x111D20u) { return; }
    }
    ctx->pc = 0x111D20u;
label_111d20:
    // 0x111d20: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x111d20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111d24: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x111d24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111d28: 0xc0446a4  jal         func_111A90
    ctx->pc = 0x111D28u;
    SET_GPR_U32(ctx, 31, 0x111D30u);
    ctx->pc = 0x111D2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111D28u;
            // 0x111d2c: 0x27a60040  addiu       $a2, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111A90u;
    if (runtime->hasFunction(0x111A90u)) {
        auto targetFn = runtime->lookupFunction(0x111A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D30u; }
        if (ctx->pc != 0x111D30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111A90_0x111a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D30u; }
        if (ctx->pc != 0x111D30u) { return; }
    }
    ctx->pc = 0x111D30u;
label_111d30:
    // 0x111d30: 0xc04463e  jal         func_1118F8
    ctx->pc = 0x111D30u;
    SET_GPR_U32(ctx, 31, 0x111D38u);
    ctx->pc = 0x111D34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111D30u;
            // 0x111d34: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118F8u;
    if (runtime->hasFunction(0x1118F8u)) {
        auto targetFn = runtime->lookupFunction(0x1118F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D38u; }
        if (ctx->pc != 0x111D38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118F8_0x1118f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D38u; }
        if (ctx->pc != 0x111D38u) { return; }
    }
    ctx->pc = 0x111D38u;
label_111d38:
    // 0x111d38: 0xdfb00070  ld          $s0, 0x70($sp)
    ctx->pc = 0x111d38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x111d3c: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x111d3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x111d40: 0x3e00008  jr          $ra
    ctx->pc = 0x111D40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111D40u;
            // 0x111d44: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111D10u: goto label_111d10;
            case 0x111D20u: goto label_111d20;
            case 0x111D30u: goto label_111d30;
            case 0x111D38u: goto label_111d38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111D48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
