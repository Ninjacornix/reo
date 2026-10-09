#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBF50
// Address: 0x1cbf50 - 0x1cc000
void sub_001CBF50_0x1cbf50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBF50_0x1cbf50");
#endif

    switch (ctx->pc) {
        case 0x1cbf8cu: goto label_1cbf8c;
        case 0x1cbfa4u: goto label_1cbfa4;
        case 0x1cbfbcu: goto label_1cbfbc;
        case 0x1cbfd4u: goto label_1cbfd4;
        case 0x1cbfecu: goto label_1cbfec;
        case 0x1cbff4u: goto label_1cbff4;
        default: break;
    }

    ctx->pc = 0x1cbf50u;

    // 0x1cbf50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cbf50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cbf54: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cbf54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cbf58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cbf5c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf60: 0xac20d9f0  sw          $zero, -0x2610($at)
    ctx->pc = 0x1cbf60u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957552), GPR_U32(ctx, 0));
    // 0x1cbf64: 0x2442fa20  addiu       $v0, $v0, -0x5E0
    ctx->pc = 0x1cbf64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965792));
    // 0x1cbf68: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf6c: 0xac20d9f8  sw          $zero, -0x2608($at)
    ctx->pc = 0x1cbf6cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957560), GPR_U32(ctx, 0));
    // 0x1cbf70: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbf70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbf74: 0xac225ff0  sw          $v0, 0x5FF0($at)
    ctx->pc = 0x1cbf74u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24560), GPR_U32(ctx, 2));
    // 0x1cbf78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf7c: 0xac20da00  sw          $zero, -0x2600($at)
    ctx->pc = 0x1cbf7cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957568), GPR_U32(ctx, 0));
    // 0x1cbf80: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf84: 0xc072f78  jal         func_1CBDE0
    ctx->pc = 0x1CBF84u;
    SET_GPR_U32(ctx, 31, 0x1CBF8Cu);
    ctx->pc = 0x1CBF88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBF84u;
            // 0x1cbf88: 0xa020fa10  sb          $zero, -0x5F0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294965776), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBDE0u;
    if (runtime->hasFunction(0x1CBDE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBF8Cu; }
        if (ctx->pc != 0x1CBF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDE0_0x1cbde0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBF8Cu; }
        if (ctx->pc != 0x1CBF8Cu) { return; }
    }
    ctx->pc = 0x1CBF8Cu;
label_1cbf8c:
    // 0x1cbf8c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf90: 0x3c06001d  lui         $a2, 0x1D
    ctx->pc = 0x1cbf90u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)29 << 16));
    // 0x1cbf94: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbf94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbf98: 0x24050012  addiu       $a1, $zero, 0x12
    ctx->pc = 0x1cbf98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1cbf9c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1CBF9Cu;
    SET_GPR_U32(ctx, 31, 0x1CBFA4u);
    ctx->pc = 0x1CBFA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBF9Cu;
            // 0x1cbfa0: 0x24c6be00  addiu       $a2, $a2, -0x4200 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294950400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFA4u; }
        if (ctx->pc != 0x1CBFA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFA4u; }
        if (ctx->pc != 0x1CBFA4u) { return; }
    }
    ctx->pc = 0x1CBFA4u;
label_1cbfa4:
    // 0x1cbfa4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbfa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbfa8: 0x3c06001d  lui         $a2, 0x1D
    ctx->pc = 0x1cbfa8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)29 << 16));
    // 0x1cbfac: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbfacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbfb0: 0x24050014  addiu       $a1, $zero, 0x14
    ctx->pc = 0x1cbfb0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1cbfb4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1CBFB4u;
    SET_GPR_U32(ctx, 31, 0x1CBFBCu);
    ctx->pc = 0x1CBFB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBFB4u;
            // 0x1cbfb8: 0x24c6bea0  addiu       $a2, $a2, -0x4160 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294950560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFBCu; }
        if (ctx->pc != 0x1CBFBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFBCu; }
        if (ctx->pc != 0x1CBFBCu) { return; }
    }
    ctx->pc = 0x1CBFBCu;
label_1cbfbc:
    // 0x1cbfbc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbfbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbfc0: 0x3c06001d  lui         $a2, 0x1D
    ctx->pc = 0x1cbfc0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)29 << 16));
    // 0x1cbfc4: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbfc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbfc8: 0x24050013  addiu       $a1, $zero, 0x13
    ctx->pc = 0x1cbfc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1cbfcc: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1CBFCCu;
    SET_GPR_U32(ctx, 31, 0x1CBFD4u);
    ctx->pc = 0x1CBFD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBFCCu;
            // 0x1cbfd0: 0x24c6bf40  addiu       $a2, $a2, -0x40C0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294950720));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFD4u; }
        if (ctx->pc != 0x1CBFD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFD4u; }
        if (ctx->pc != 0x1CBFD4u) { return; }
    }
    ctx->pc = 0x1CBFD4u;
label_1cbfd4:
    // 0x1cbfd4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbfd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbfd8: 0x3c06001d  lui         $a2, 0x1D
    ctx->pc = 0x1cbfd8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)29 << 16));
    // 0x1cbfdc: 0x8c24c7f0  lw          $a0, -0x3810($at)
    ctx->pc = 0x1cbfdcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
    // 0x1cbfe0: 0x24050015  addiu       $a1, $zero, 0x15
    ctx->pc = 0x1cbfe0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1cbfe4: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1CBFE4u;
    SET_GPR_U32(ctx, 31, 0x1CBFECu);
    ctx->pc = 0x1CBFE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBFE4u;
            // 0x1cbfe8: 0x24c6bf40  addiu       $a2, $a2, -0x40C0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294950720));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFECu; }
        if (ctx->pc != 0x1CBFECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFECu; }
        if (ctx->pc != 0x1CBFECu) { return; }
    }
    ctx->pc = 0x1CBFECu;
label_1cbfec:
    // 0x1cbfec: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CBFECu;
    SET_GPR_U32(ctx, 31, 0x1CBFF4u);
    ctx->pc = 0x1CBDF0u;
    if (runtime->hasFunction(0x1CBDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFF4u; }
        if (ctx->pc != 0x1CBFF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDF0_0x1cbdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBFF4u; }
        if (ctx->pc != 0x1CBFF4u) { return; }
    }
    ctx->pc = 0x1CBFF4u;
label_1cbff4:
    // 0x1cbff4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cbff4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbff8: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBFF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBFFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBFF8u;
            // 0x1cbffc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBF8Cu: goto label_1cbf8c;
            case 0x1CBFA4u: goto label_1cbfa4;
            case 0x1CBFBCu: goto label_1cbfbc;
            case 0x1CBFD4u: goto label_1cbfd4;
            case 0x1CBFECu: goto label_1cbfec;
            case 0x1CBFF4u: goto label_1cbff4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC000u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
