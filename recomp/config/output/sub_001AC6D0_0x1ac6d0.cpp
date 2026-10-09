#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AC6D0
// Address: 0x1ac6d0 - 0x1ac708
void sub_001AC6D0_0x1ac6d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AC6D0_0x1ac6d0");
#endif

    switch (ctx->pc) {
        case 0x1ac6e0u: goto label_1ac6e0;
        case 0x1ac6ecu: goto label_1ac6ec;
        case 0x1ac6f8u: goto label_1ac6f8;
        default: break;
    }

    ctx->pc = 0x1ac6d0u;

    // 0x1ac6d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ac6d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ac6d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ac6d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ac6d8: 0xc069c78  jal         func_1A71E0
    ctx->pc = 0x1AC6D8u;
    SET_GPR_U32(ctx, 31, 0x1AC6E0u);
    ctx->pc = 0x1A71E0u;
    if (runtime->hasFunction(0x1A71E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A71E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6E0u; }
        if (ctx->pc != 0x1AC6E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A71E0_0x1a71e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6E0u; }
        if (ctx->pc != 0x1AC6E0u) { return; }
    }
    ctx->pc = 0x1AC6E0u;
label_1ac6e0:
    // 0x1ac6e0: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1ac6e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1ac6e4: 0xc069fec  jal         func_1A7FB0
    ctx->pc = 0x1AC6E4u;
    SET_GPR_U32(ctx, 31, 0x1AC6ECu);
    ctx->pc = 0x1AC6E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC6E4u;
            // 0x1ac6e8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7FB0u;
    if (runtime->hasFunction(0x1A7FB0u)) {
        auto targetFn = runtime->lookupFunction(0x1A7FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6ECu; }
        if (ctx->pc != 0x1AC6ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7FB0_0x1a7fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6ECu; }
        if (ctx->pc != 0x1AC6ECu) { return; }
    }
    ctx->pc = 0x1AC6ECu;
label_1ac6ec:
    // 0x1ac6ec: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ac6ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ac6f0: 0xc06b570  jal         func_1AD5C0
    ctx->pc = 0x1AC6F0u;
    SET_GPR_U32(ctx, 31, 0x1AC6F8u);
    ctx->pc = 0x1AC6F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC6F0u;
            // 0x1ac6f4: 0xac203838  sw          $zero, 0x3838($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 14392), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD5C0u;
    if (runtime->hasFunction(0x1AD5C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AD5C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6F8u; }
        if (ctx->pc != 0x1AC6F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD5C0_0x1ad5c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6F8u; }
        if (ctx->pc != 0x1AC6F8u) { return; }
    }
    ctx->pc = 0x1AC6F8u;
label_1ac6f8:
    // 0x1ac6f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ac6f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ac6fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac700: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC700u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AC704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC700u;
            // 0x1ac704: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AC6E0u: goto label_1ac6e0;
            case 0x1AC6ECu: goto label_1ac6ec;
            case 0x1AC6F8u: goto label_1ac6f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC708u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
