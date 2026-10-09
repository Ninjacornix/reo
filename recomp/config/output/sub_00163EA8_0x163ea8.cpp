#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163EA8
// Address: 0x163ea8 - 0x163ee0
void sub_00163EA8_0x163ea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163EA8_0x163ea8");
#endif

    switch (ctx->pc) {
        case 0x163ebcu: goto label_163ebc;
        case 0x163ec4u: goto label_163ec4;
        case 0x163eccu: goto label_163ecc;
        default: break;
    }

    ctx->pc = 0x163ea8u;

    // 0x163ea8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163ea8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163eac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163eb0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x163eb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x163eb4: 0xc058da4  jal         func_163690
    ctx->pc = 0x163EB4u;
    SET_GPR_U32(ctx, 31, 0x163EBCu);
    ctx->pc = 0x163690u;
    if (runtime->hasFunction(0x163690u)) {
        auto targetFn = runtime->lookupFunction(0x163690u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163EBCu; }
        if (ctx->pc != 0x163EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163690_0x163690(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163EBCu; }
        if (ctx->pc != 0x163EBCu) { return; }
    }
    ctx->pc = 0x163EBCu;
label_163ebc:
    // 0x163ebc: 0xc058fb8  jal         func_163EE0
    ctx->pc = 0x163EBCu;
    SET_GPR_U32(ctx, 31, 0x163EC4u);
    ctx->pc = 0x163EC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163EBCu;
            // 0x163ec0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163EE0u;
    if (runtime->hasFunction(0x163EE0u)) {
        auto targetFn = runtime->lookupFunction(0x163EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163EC4u; }
        if (ctx->pc != 0x163EC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163EE0_0x163ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163EC4u; }
        if (ctx->pc != 0x163EC4u) { return; }
    }
    ctx->pc = 0x163EC4u;
label_163ec4:
    // 0x163ec4: 0xc058dac  jal         func_1636B0
    ctx->pc = 0x163EC4u;
    SET_GPR_U32(ctx, 31, 0x163ECCu);
    ctx->pc = 0x163EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163EC4u;
            // 0x163ec8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1636B0u;
    if (runtime->hasFunction(0x1636B0u)) {
        auto targetFn = runtime->lookupFunction(0x1636B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163ECCu; }
        if (ctx->pc != 0x163ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001636B0_0x1636b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163ECCu; }
        if (ctx->pc != 0x163ECCu) { return; }
    }
    ctx->pc = 0x163ECCu;
label_163ecc:
    // 0x163ecc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x163eccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163ed0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163ed0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163ed4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163ed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163ed8: 0x3e00008  jr          $ra
    ctx->pc = 0x163ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163ED8u;
            // 0x163edc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163EBCu: goto label_163ebc;
            case 0x163EC4u: goto label_163ec4;
            case 0x163ECCu: goto label_163ecc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163EE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
