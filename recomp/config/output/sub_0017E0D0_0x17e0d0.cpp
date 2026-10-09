#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E0D0
// Address: 0x17e0d0 - 0x17e120
void sub_0017E0D0_0x17e0d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E0D0_0x17e0d0");
#endif

    switch (ctx->pc) {
        case 0x17e0f8u: goto label_17e0f8;
        case 0x17e10cu: goto label_17e10c;
        default: break;
    }

    ctx->pc = 0x17e0d0u;

    // 0x17e0d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17e0d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17e0d4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17e0d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17e0d8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17e0d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e0dc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17e0dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17e0e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17e0e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e0e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17e0e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17e0e8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x17e0e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e0ec: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x17e0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x17e0f0: 0xc05f65a  jal         func_17D968
    ctx->pc = 0x17E0F0u;
    SET_GPR_U32(ctx, 31, 0x17E0F8u);
    ctx->pc = 0x17E0F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E0F0u;
            // 0x17e0f4: 0x27a70004  addiu       $a3, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D968u;
    if (runtime->hasFunction(0x17D968u)) {
        auto targetFn = runtime->lookupFunction(0x17D968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E0F8u; }
        if (ctx->pc != 0x17E0F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D968_0x17d968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E0F8u; }
        if (ctx->pc != 0x17E0F8u) { return; }
    }
    ctx->pc = 0x17E0F8u;
label_17e0f8:
    // 0x17e0f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17e0f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e0fc: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x17e0fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e100: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x17e100u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e104: 0xc05f848  jal         func_17E120
    ctx->pc = 0x17E104u;
    SET_GPR_U32(ctx, 31, 0x17E10Cu);
    ctx->pc = 0x17E108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E104u;
            // 0x17e108: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E120u;
    if (runtime->hasFunction(0x17E120u)) {
        auto targetFn = runtime->lookupFunction(0x17E120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E10Cu; }
        if (ctx->pc != 0x17E10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E120_0x17e120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E10Cu; }
        if (ctx->pc != 0x17E10Cu) { return; }
    }
    ctx->pc = 0x17E10Cu;
label_17e10c:
    // 0x17e10c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17e10cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e110: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17e110u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e114: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17e114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17e118: 0x3e00008  jr          $ra
    ctx->pc = 0x17E118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E11Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E118u;
            // 0x17e11c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E0F8u: goto label_17e0f8;
            case 0x17E10Cu: goto label_17e10c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E120u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
