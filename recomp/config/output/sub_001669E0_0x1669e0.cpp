#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001669E0
// Address: 0x1669e0 - 0x166a20
void sub_001669E0_0x1669e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001669E0_0x1669e0");
#endif

    switch (ctx->pc) {
        case 0x1669f8u: goto label_1669f8;
        case 0x166a04u: goto label_166a04;
        default: break;
    }

    ctx->pc = 0x1669e0u;

    // 0x1669e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1669e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1669e4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1669e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1669e8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1669e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1669ec: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1669ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1669f0: 0xc059a88  jal         func_166A20
    ctx->pc = 0x1669F0u;
    SET_GPR_U32(ctx, 31, 0x1669F8u);
    ctx->pc = 0x1669F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1669F0u;
            // 0x1669f4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166A20u;
    if (runtime->hasFunction(0x166A20u)) {
        auto targetFn = runtime->lookupFunction(0x166A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1669F8u; }
        if (ctx->pc != 0x1669F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166A20_0x166a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1669F8u; }
        if (ctx->pc != 0x1669F8u) { return; }
    }
    ctx->pc = 0x1669F8u;
label_1669f8:
    // 0x1669f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1669f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1669fc: 0xc059a88  jal         func_166A20
    ctx->pc = 0x1669FCu;
    SET_GPR_U32(ctx, 31, 0x166A04u);
    ctx->pc = 0x166A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1669FCu;
            // 0x166a00: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166A20u;
    if (runtime->hasFunction(0x166A20u)) {
        auto targetFn = runtime->lookupFunction(0x166A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166A04u; }
        if (ctx->pc != 0x166A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166A20_0x166a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166A04u; }
        if (ctx->pc != 0x166A04u) { return; }
    }
    ctx->pc = 0x166A04u;
label_166a04:
    // 0x166a04: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166a04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166a08: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x166a08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166a0c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x166a0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x166a10: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166a10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166a14: 0x8059a88  j           func_166A20
    ctx->pc = 0x166A14u;
    ctx->pc = 0x166A18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166A14u;
            // 0x166a18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166A20u;
    if (runtime->hasFunction(0x166A20u)) {
        auto targetFn = runtime->lookupFunction(0x166A20u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00166A20_0x166a20(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166A1Cu;
    // 0x166a1c: 0x0  nop
    ctx->pc = 0x166a1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
