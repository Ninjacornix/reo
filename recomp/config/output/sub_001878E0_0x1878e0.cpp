#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001878E0
// Address: 0x1878e0 - 0x187930
void sub_001878E0_0x1878e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001878E0_0x1878e0");
#endif

    switch (ctx->pc) {
        case 0x187908u: goto label_187908;
        case 0x18791cu: goto label_18791c;
        default: break;
    }

    ctx->pc = 0x1878e0u;

    // 0x1878e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1878e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1878e4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1878e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1878e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1878e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1878ec: 0x2450b8c0  addiu       $s0, $v0, -0x4740
    ctx->pc = 0x1878ecu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949056));
    // 0x1878f0: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1878f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1878f4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1878f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1878f8: 0x4600003  bltz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1878F8u;
    {
        const bool branch_taken_0x1878f8 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1878FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1878F8u;
            // 0x1878fc: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1878f8) {
            ctx->pc = 0x187908u;
            goto label_187908;
        }
    }
    ctx->pc = 0x187900u;
    // 0x187900: 0xc04518c  jal         func_114630
    ctx->pc = 0x187900u;
    SET_GPR_U32(ctx, 31, 0x187908u);
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187908u; }
        if (ctx->pc != 0x187908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187908u; }
        if (ctx->pc != 0x187908u) { return; }
    }
    ctx->pc = 0x187908u;
label_187908:
    // 0x187908: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x187908u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x18790c: 0x4820004  bltzl       $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18790Cu;
    {
        const bool branch_taken_0x18790c = (GPR_S64(ctx, 4) < 0);
        if (branch_taken_0x18790c) {
            ctx->pc = 0x187910u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18790Cu;
            // 0x187910: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187920u;
            goto label_187920;
        }
    }
    ctx->pc = 0x187914u;
    // 0x187914: 0xc04518c  jal         func_114630
    ctx->pc = 0x187914u;
    SET_GPR_U32(ctx, 31, 0x18791Cu);
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18791Cu; }
        if (ctx->pc != 0x18791Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18791Cu; }
        if (ctx->pc != 0x18791Cu) { return; }
    }
    ctx->pc = 0x18791Cu;
label_18791c:
    // 0x18791c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x18791cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_187920:
    // 0x187920: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x187920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x187924: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x187924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x187928: 0x3e00008  jr          $ra
    ctx->pc = 0x187928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18792Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187928u;
            // 0x18792c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187908u: goto label_187908;
            case 0x18791Cu: goto label_18791c;
            case 0x187920u: goto label_187920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187930u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
