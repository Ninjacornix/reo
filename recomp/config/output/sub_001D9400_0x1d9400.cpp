#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9400
// Address: 0x1d9400 - 0x1d9450
void sub_001D9400_0x1d9400(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9400_0x1d9400");
#endif

    switch (ctx->pc) {
        case 0x1d9410u: goto label_1d9410;
        case 0x1d9430u: goto label_1d9430;
        case 0x1d943cu: goto label_1d943c;
        default: break;
    }

    ctx->pc = 0x1d9400u;

    // 0x1d9400: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d9400u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d9404: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d9404u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d9408: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D9408u;
    SET_GPR_U32(ctx, 31, 0x1D9410u);
    ctx->pc = 0x1D940Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9408u;
            // 0x1d940c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9410u; }
        if (ctx->pc != 0x1D9410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9410u; }
        if (ctx->pc != 0x1D9410u) { return; }
    }
    ctx->pc = 0x1D9410u;
label_1d9410:
    // 0x1d9410: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d9410u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d9414: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d9414u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d9418: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d9418u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d941c: 0x24040050  addiu       $a0, $zero, 0x50
    ctx->pc = 0x1d941cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1d9420: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d9420u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d9424: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d9424u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d9428: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D9428u;
    SET_GPR_U32(ctx, 31, 0x1D9430u);
    ctx->pc = 0x1D942Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9428u;
            // 0x1d942c: 0xc0402d  daddu       $t0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9430u; }
        if (ctx->pc != 0x1D9430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9430u; }
        if (ctx->pc != 0x1D9430u) { return; }
    }
    ctx->pc = 0x1D9430u;
label_1d9430:
    // 0x1d9430: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d9430u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d9434: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D9434u;
    SET_GPR_U32(ctx, 31, 0x1D943Cu);
    ctx->pc = 0x1D9438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9434u;
            // 0x1d9438: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D943Cu; }
        if (ctx->pc != 0x1D943Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D943Cu; }
        if (ctx->pc != 0x1D943Cu) { return; }
    }
    ctx->pc = 0x1D943Cu;
label_1d943c:
    // 0x1d943c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d943cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9440: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d9440u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9444: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9444u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9448: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9448u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D944Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9448u;
            // 0x1d944c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9410u: goto label_1d9410;
            case 0x1D9430u: goto label_1d9430;
            case 0x1D943Cu: goto label_1d943c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9450u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
