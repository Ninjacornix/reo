#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F9C8
// Address: 0x17f9c8 - 0x17fa30
void sub_0017F9C8_0x17f9c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F9C8_0x17f9c8");
#endif

    switch (ctx->pc) {
        case 0x17f9f4u: goto label_17f9f4;
        case 0x17fa00u: goto label_17fa00;
        case 0x17fa0cu: goto label_17fa0c;
        default: break;
    }

    ctx->pc = 0x17f9c8u;

    // 0x17f9c8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17f9c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17f9cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f9ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f9d0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17f9d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f9d4: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x17f9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x17f9d8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x17f9d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x17f9dc: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x17f9dcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f9e0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f9e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f9e4: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x17f9e4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f9e8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17f9e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x17f9ec: 0xc05fc76  jal         func_17F1D8
    ctx->pc = 0x17F9ECu;
    SET_GPR_U32(ctx, 31, 0x17F9F4u);
    ctx->pc = 0x17F9F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F9ECu;
            // 0x17f9f0: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F1D8u;
    if (runtime->hasFunction(0x17F1D8u)) {
        auto targetFn = runtime->lookupFunction(0x17F1D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F9F4u; }
        if (ctx->pc != 0x17F9F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F1D8_0x17f1d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F9F4u; }
        if (ctx->pc != 0x17F9F4u) { return; }
    }
    ctx->pc = 0x17F9F4u;
label_17f9f4:
    // 0x17f9f4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17f9f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f9f8: 0xc05fc76  jal         func_17F1D8
    ctx->pc = 0x17F9F8u;
    SET_GPR_U32(ctx, 31, 0x17FA00u);
    ctx->pc = 0x17F9FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F9F8u;
            // 0x17f9fc: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F1D8u;
    if (runtime->hasFunction(0x17F1D8u)) {
        auto targetFn = runtime->lookupFunction(0x17F1D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FA00u; }
        if (ctx->pc != 0x17FA00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F1D8_0x17f1d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FA00u; }
        if (ctx->pc != 0x17FA00u) { return; }
    }
    ctx->pc = 0x17FA00u;
label_17fa00:
    // 0x17fa00: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17fa00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fa04: 0xc05fc76  jal         func_17F1D8
    ctx->pc = 0x17FA04u;
    SET_GPR_U32(ctx, 31, 0x17FA0Cu);
    ctx->pc = 0x17FA08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FA04u;
            // 0x17fa08: 0x26040020  addiu       $a0, $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F1D8u;
    if (runtime->hasFunction(0x17F1D8u)) {
        auto targetFn = runtime->lookupFunction(0x17F1D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FA0Cu; }
        if (ctx->pc != 0x17FA0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F1D8_0x17f1d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FA0Cu; }
        if (ctx->pc != 0x17FA0Cu) { return; }
    }
    ctx->pc = 0x17FA0Cu;
label_17fa0c:
    // 0x17fa0c: 0x26040030  addiu       $a0, $s0, 0x30
    ctx->pc = 0x17fa0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
    // 0x17fa10: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x17fa10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fa14: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x17fa14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17fa18: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x17fa18u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17fa1c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x17fa1cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17fa20: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17fa20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17fa24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17fa24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17fa28: 0x805fc76  j           func_17F1D8
    ctx->pc = 0x17FA28u;
    ctx->pc = 0x17FA2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FA28u;
            // 0x17fa2c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F1D8u;
    if (runtime->hasFunction(0x17F1D8u)) {
        auto targetFn = runtime->lookupFunction(0x17F1D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017F1D8_0x17f1d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17FA30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
