#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111D48
// Address: 0x111d48 - 0x111db0
void sub_00111D48_0x111d48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111D48_0x111d48");
#endif

    switch (ctx->pc) {
        case 0x111d68u: goto label_111d68;
        case 0x111d78u: goto label_111d78;
        case 0x111d94u: goto label_111d94;
        case 0x111d9cu: goto label_111d9c;
        default: break;
    }

    ctx->pc = 0x111d48u;

    // 0x111d48: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x111d48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x111d4c: 0xffa40060  sd          $a0, 0x60($sp)
    ctx->pc = 0x111d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 4));
    // 0x111d50: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x111d50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x111d54: 0xffa50068  sd          $a1, 0x68($sp)
    ctx->pc = 0x111d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 5));
    // 0x111d58: 0xffb00070  sd          $s0, 0x70($sp)
    ctx->pc = 0x111d58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 16));
    // 0x111d5c: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x111d5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x111d60: 0xc044674  jal         func_1119D0
    ctx->pc = 0x111D60u;
    SET_GPR_U32(ctx, 31, 0x111D68u);
    ctx->pc = 0x111D64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111D60u;
            // 0x111d64: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D68u; }
        if (ctx->pc != 0x111D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D68u; }
        if (ctx->pc != 0x111D68u) { return; }
    }
    ctx->pc = 0x111D68u;
label_111d68:
    // 0x111d68: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x111d68u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x111d6c: 0x27a40068  addiu       $a0, $sp, 0x68
    ctx->pc = 0x111d6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x111d70: 0xc044674  jal         func_1119D0
    ctx->pc = 0x111D70u;
    SET_GPR_U32(ctx, 31, 0x111D78u);
    ctx->pc = 0x111D74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111D70u;
            // 0x111d74: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D78u; }
        if (ctx->pc != 0x111D78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D78u; }
        if (ctx->pc != 0x111D78u) { return; }
    }
    ctx->pc = 0x111D78u;
label_111d78:
    // 0x111d78: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x111d78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111d7c: 0x8fa20024  lw          $v0, 0x24($sp)
    ctx->pc = 0x111d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x111d80: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x111d80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111d84: 0x27a60040  addiu       $a2, $sp, 0x40
    ctx->pc = 0x111d84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x111d88: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x111d88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x111d8c: 0xc0446a4  jal         func_111A90
    ctx->pc = 0x111D8Cu;
    SET_GPR_U32(ctx, 31, 0x111D94u);
    ctx->pc = 0x111D90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111D8Cu;
            // 0x111d90: 0xafa20024  sw          $v0, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111A90u;
    if (runtime->hasFunction(0x111A90u)) {
        auto targetFn = runtime->lookupFunction(0x111A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D94u; }
        if (ctx->pc != 0x111D94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111A90_0x111a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D94u; }
        if (ctx->pc != 0x111D94u) { return; }
    }
    ctx->pc = 0x111D94u;
label_111d94:
    // 0x111d94: 0xc04463e  jal         func_1118F8
    ctx->pc = 0x111D94u;
    SET_GPR_U32(ctx, 31, 0x111D9Cu);
    ctx->pc = 0x111D98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111D94u;
            // 0x111d98: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118F8u;
    if (runtime->hasFunction(0x1118F8u)) {
        auto targetFn = runtime->lookupFunction(0x1118F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D9Cu; }
        if (ctx->pc != 0x111D9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118F8_0x1118f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111D9Cu; }
        if (ctx->pc != 0x111D9Cu) { return; }
    }
    ctx->pc = 0x111D9Cu;
label_111d9c:
    // 0x111d9c: 0xdfb00070  ld          $s0, 0x70($sp)
    ctx->pc = 0x111d9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x111da0: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x111da0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x111da4: 0x3e00008  jr          $ra
    ctx->pc = 0x111DA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111DA4u;
            // 0x111da8: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111D68u: goto label_111d68;
            case 0x111D78u: goto label_111d78;
            case 0x111D94u: goto label_111d94;
            case 0x111D9Cu: goto label_111d9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111DACu;
    // 0x111dac: 0x0  nop
    ctx->pc = 0x111dacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
