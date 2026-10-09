#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8F70
// Address: 0x1d8f70 - 0x1d8fc0
void sub_001D8F70_0x1d8f70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8F70_0x1d8f70");
#endif

    switch (ctx->pc) {
        case 0x1d8f80u: goto label_1d8f80;
        case 0x1d8fa0u: goto label_1d8fa0;
        case 0x1d8facu: goto label_1d8fac;
        default: break;
    }

    ctx->pc = 0x1d8f70u;

    // 0x1d8f70: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d8f70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d8f74: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d8f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d8f78: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8F78u;
    SET_GPR_U32(ctx, 31, 0x1D8F80u);
    ctx->pc = 0x1D8F7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8F78u;
            // 0x1d8f7c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8F80u; }
        if (ctx->pc != 0x1D8F80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8F80u; }
        if (ctx->pc != 0x1D8F80u) { return; }
    }
    ctx->pc = 0x1D8F80u;
label_1d8f80:
    // 0x1d8f80: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8f80u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8f84: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d8f84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d8f88: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8f88u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d8f8c: 0x24040035  addiu       $a0, $zero, 0x35
    ctx->pc = 0x1d8f8cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
    // 0x1d8f90: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8f90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8f94: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d8f94u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8f98: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8F98u;
    SET_GPR_U32(ctx, 31, 0x1D8FA0u);
    ctx->pc = 0x1D8F9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8F98u;
            // 0x1d8f9c: 0xc0402d  daddu       $t0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8FA0u; }
        if (ctx->pc != 0x1D8FA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8FA0u; }
        if (ctx->pc != 0x1D8FA0u) { return; }
    }
    ctx->pc = 0x1D8FA0u;
label_1d8fa0:
    // 0x1d8fa0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8fa0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8fa4: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8FA4u;
    SET_GPR_U32(ctx, 31, 0x1D8FACu);
    ctx->pc = 0x1D8FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8FA4u;
            // 0x1d8fa8: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8FACu; }
        if (ctx->pc != 0x1D8FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8FACu; }
        if (ctx->pc != 0x1D8FACu) { return; }
    }
    ctx->pc = 0x1D8FACu;
label_1d8fac:
    // 0x1d8fac: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8facu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8fb0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d8fb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8fb4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8fb4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8fb8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8FB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8FB8u;
            // 0x1d8fbc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8F80u: goto label_1d8f80;
            case 0x1D8FA0u: goto label_1d8fa0;
            case 0x1D8FACu: goto label_1d8fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8FC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
