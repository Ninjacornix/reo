#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DCC0
// Address: 0x11dcc0 - 0x11dd08
void sub_0011DCC0_0x11dcc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DCC0_0x11dcc0");
#endif

    switch (ctx->pc) {
        case 0x11dcd8u: goto label_11dcd8;
        case 0x11dce0u: goto label_11dce0;
        default: break;
    }

    ctx->pc = 0x11dcc0u;

    // 0x11dcc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11dcc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11dcc4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11dcc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11dcc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11dcc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11dccc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11dcccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11dcd0: 0xc0476cc  jal         func_11DB30
    ctx->pc = 0x11DCD0u;
    SET_GPR_U32(ctx, 31, 0x11DCD8u);
    ctx->pc = 0x11DCD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DCD0u;
            // 0x11dcd4: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DB30u;
    if (runtime->hasFunction(0x11DB30u)) {
        auto targetFn = runtime->lookupFunction(0x11DB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DCD8u; }
        if (ctx->pc != 0x11DCD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DB30_0x11db30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DCD8u; }
        if (ctx->pc != 0x11DCD8u) { return; }
    }
    ctx->pc = 0x11DCD8u;
label_11dcd8:
    // 0x11dcd8: 0xc047712  jal         func_11DC48
    ctx->pc = 0x11DCD8u;
    SET_GPR_U32(ctx, 31, 0x11DCE0u);
    ctx->pc = 0x11DCDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DCD8u;
            // 0x11dcdc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DC48u;
    if (runtime->hasFunction(0x11DC48u)) {
        auto targetFn = runtime->lookupFunction(0x11DC48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DCE0u; }
        if (ctx->pc != 0x11DCE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DC48_0x11dc48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DCE0u; }
        if (ctx->pc != 0x11DCE0u) { return; }
    }
    ctx->pc = 0x11DCE0u;
label_11dce0:
    // 0x11dce0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11dce0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11dce4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11dce4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dce8: 0x8c46a180  lw          $a2, -0x5E80($v0)
    ctx->pc = 0x11dce8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943104)));
    // 0x11dcec: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x11dcecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dcf0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11dcf0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11dcf4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11dcf4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11dcf8: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x11dcf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x11dcfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11dcfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dd00: 0x8045098  j           func_114260
    ctx->pc = 0x11DD00u;
    ctx->pc = 0x11DD04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DD00u;
            // 0x11dd04: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114260u;
    if (runtime->hasFunction(0x114260u)) {
        auto targetFn = runtime->lookupFunction(0x114260u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114260_0x114260(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11DD08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
