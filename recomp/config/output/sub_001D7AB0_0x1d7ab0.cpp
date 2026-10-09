#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7AB0
// Address: 0x1d7ab0 - 0x1d7b00
void sub_001D7AB0_0x1d7ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7AB0_0x1d7ab0");
#endif

    switch (ctx->pc) {
        case 0x1d7ac0u: goto label_1d7ac0;
        case 0x1d7ae0u: goto label_1d7ae0;
        case 0x1d7aecu: goto label_1d7aec;
        default: break;
    }

    ctx->pc = 0x1d7ab0u;

    // 0x1d7ab0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d7ab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d7ab4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d7ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d7ab8: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D7AB8u;
    SET_GPR_U32(ctx, 31, 0x1D7AC0u);
    ctx->pc = 0x1D7ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7AB8u;
            // 0x1d7abc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7AC0u; }
        if (ctx->pc != 0x1D7AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7AC0u; }
        if (ctx->pc != 0x1D7AC0u) { return; }
    }
    ctx->pc = 0x1D7AC0u;
label_1d7ac0:
    // 0x1d7ac0: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d7ac0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d7ac4: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d7ac4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d7ac8: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d7ac8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d7acc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d7accu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d7ad0: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d7ad0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d7ad4: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d7ad4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d7ad8: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D7AD8u;
    SET_GPR_U32(ctx, 31, 0x1D7AE0u);
    ctx->pc = 0x1D7ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7AD8u;
            // 0x1d7adc: 0xc0402d  daddu       $t0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7AE0u; }
        if (ctx->pc != 0x1D7AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7AE0u; }
        if (ctx->pc != 0x1D7AE0u) { return; }
    }
    ctx->pc = 0x1D7AE0u;
label_1d7ae0:
    // 0x1d7ae0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7ae0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7ae4: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D7AE4u;
    SET_GPR_U32(ctx, 31, 0x1D7AECu);
    ctx->pc = 0x1D7AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7AE4u;
            // 0x1d7ae8: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7AECu; }
        if (ctx->pc != 0x1D7AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7AECu; }
        if (ctx->pc != 0x1D7AECu) { return; }
    }
    ctx->pc = 0x1D7AECu;
label_1d7aec:
    // 0x1d7aec: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d7aecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7af0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d7af0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d7af4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d7af4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7af8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7AF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7AF8u;
            // 0x1d7afc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7AC0u: goto label_1d7ac0;
            case 0x1D7AE0u: goto label_1d7ae0;
            case 0x1D7AECu: goto label_1d7aec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7B00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
