#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138D60
// Address: 0x138d60 - 0x138de8
void sub_00138D60_0x138d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138D60_0x138d60");
#endif

    switch (ctx->pc) {
        case 0x138d70u: goto label_138d70;
        case 0x138d7cu: goto label_138d7c;
        case 0x138d84u: goto label_138d84;
        case 0x138d90u: goto label_138d90;
        case 0x138dc0u: goto label_138dc0;
        case 0x138dd8u: goto label_138dd8;
        default: break;
    }

    ctx->pc = 0x138d60u;

    // 0x138d60: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x138d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x138d64: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x138d64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x138d68: 0xc045144  jal         func_114510
    ctx->pc = 0x138D68u;
    SET_GPR_U32(ctx, 31, 0x138D70u);
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D70u; }
        if (ctx->pc != 0x138D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D70u; }
        if (ctx->pc != 0x138D70u) { return; }
    }
    ctx->pc = 0x138D70u;
label_138d70:
    // 0x138d70: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x138d70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138d74: 0xc045f08  jal         func_117C20
    ctx->pc = 0x138D74u;
    SET_GPR_U32(ctx, 31, 0x138D7Cu);
    ctx->pc = 0x138D78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138D74u;
            // 0x138d78: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117C20u;
    if (runtime->hasFunction(0x117C20u)) {
        auto targetFn = runtime->lookupFunction(0x117C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D7Cu; }
        if (ctx->pc != 0x138D7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117C20_0x117c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D7Cu; }
        if (ctx->pc != 0x138D7Cu) { return; }
    }
    ctx->pc = 0x138D7Cu;
label_138d7c:
    // 0x138d7c: 0xc045144  jal         func_114510
    ctx->pc = 0x138D7Cu;
    SET_GPR_U32(ctx, 31, 0x138D84u);
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D84u; }
        if (ctx->pc != 0x138D84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D84u; }
        if (ctx->pc != 0x138D84u) { return; }
    }
    ctx->pc = 0x138D84u;
label_138d84:
    // 0x138d84: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x138d84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x138d88: 0xc045f08  jal         func_117C20
    ctx->pc = 0x138D88u;
    SET_GPR_U32(ctx, 31, 0x138D90u);
    ctx->pc = 0x138D8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138D88u;
            // 0x138d8c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117C20u;
    if (runtime->hasFunction(0x117C20u)) {
        auto targetFn = runtime->lookupFunction(0x117C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D90u; }
        if (ctx->pc != 0x138D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117C20_0x117c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138D90u; }
        if (ctx->pc != 0x138D90u) { return; }
    }
    ctx->pc = 0x138D90u;
label_138d90:
    // 0x138d90: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x138d90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x138d94: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138d94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138d98: 0x3c060014  lui         $a2, 0x14
    ctx->pc = 0x138d98u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)20 << 16));
    // 0x138d9c: 0x8c45c414  lw          $a1, -0x3BEC($v0)
    ctx->pc = 0x138d9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294951956)));
    // 0x138da0: 0x3c070022  lui         $a3, 0x22
    ctx->pc = 0x138da0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)34 << 16));
    // 0x138da4: 0x24c68c90  addiu       $a2, $a2, -0x7370
    ctx->pc = 0x138da4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294937744));
    // 0x138da8: 0x24e7c8e0  addiu       $a3, $a3, -0x3720
    ctx->pc = 0x138da8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294953184));
    // 0x138dac: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x138dacu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138db0: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x138db0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138db4: 0x3a0502d  daddu       $t2, $sp, $zero
    ctx->pc = 0x138db4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138db8: 0xc045f2e  jal         func_117CB8
    ctx->pc = 0x138DB8u;
    SET_GPR_U32(ctx, 31, 0x138DC0u);
    ctx->pc = 0x138DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138DB8u;
            // 0x138dbc: 0x2484c898  addiu       $a0, $a0, -0x3768 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117CB8u;
    if (runtime->hasFunction(0x117CB8u)) {
        auto targetFn = runtime->lookupFunction(0x117CB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138DC0u; }
        if (ctx->pc != 0x138DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117CB8_0x117cb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138DC0u; }
        if (ctx->pc != 0x138DC0u) { return; }
    }
    ctx->pc = 0x138DC0u;
label_138dc0:
    // 0x138dc0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138dc4: 0x2442c418  addiu       $v0, $v0, -0x3BE8
    ctx->pc = 0x138dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294951960));
    // 0x138dc8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x138dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138dcc: 0x0  nop
    ctx->pc = 0x138dccu;
    // NOP
    // 0x138dd0: 0xc046034  jal         func_1180D0
    ctx->pc = 0x138DD0u;
    SET_GPR_U32(ctx, 31, 0x138DD8u);
    ctx->pc = 0x138DD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138DD0u;
            // 0x138dd4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1180D0u;
    if (runtime->hasFunction(0x1180D0u)) {
        auto targetFn = runtime->lookupFunction(0x1180D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138DD8u; }
        if (ctx->pc != 0x138DD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001180D0_0x1180d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138DD8u; }
        if (ctx->pc != 0x138DD8u) { return; }
    }
    ctx->pc = 0x138DD8u;
label_138dd8:
    // 0x138dd8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x138dd8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ddc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x138ddcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x138de0: 0x3e00008  jr          $ra
    ctx->pc = 0x138DE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138DE0u;
            // 0x138de4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138D70u: goto label_138d70;
            case 0x138D7Cu: goto label_138d7c;
            case 0x138D84u: goto label_138d84;
            case 0x138D90u: goto label_138d90;
            case 0x138DC0u: goto label_138dc0;
            case 0x138DD8u: goto label_138dd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138DE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
