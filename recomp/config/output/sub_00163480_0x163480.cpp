#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163480
// Address: 0x163480 - 0x163558
void sub_00163480_0x163480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163480_0x163480");
#endif

    switch (ctx->pc) {
        case 0x163490u: goto label_163490;
        case 0x1634f4u: goto label_1634f4;
        case 0x163544u: goto label_163544;
        default: break;
    }

    ctx->pc = 0x163480u;

    // 0x163480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163484: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163488: 0xc05083e  jal         func_1420F8
    ctx->pc = 0x163488u;
    SET_GPR_U32(ctx, 31, 0x163490u);
    ctx->pc = 0x1420F8u;
    if (runtime->hasFunction(0x1420F8u)) {
        auto targetFn = runtime->lookupFunction(0x1420F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163490u; }
        if (ctx->pc != 0x163490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001420F8_0x1420f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163490u; }
        if (ctx->pc != 0x163490u) { return; }
    }
    ctx->pc = 0x163490u;
label_163490:
    // 0x163490: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163490u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163494: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x163494u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x163498: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x163498u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x16349c: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x16349cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x1634a0: 0x3c050027  lui         $a1, 0x27
    ctx->pc = 0x1634a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
    // 0x1634a4: 0xac400740  sw          $zero, 0x740($v0)
    ctx->pc = 0x1634a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1856), GPR_U32(ctx, 0));
    // 0x1634a8: 0xac600744  sw          $zero, 0x744($v1)
    ctx->pc = 0x1634a8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1860), GPR_U32(ctx, 0));
    // 0x1634ac: 0xac800748  sw          $zero, 0x748($a0)
    ctx->pc = 0x1634acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 1864), GPR_U32(ctx, 0));
    // 0x1634b0: 0xaca0074c  sw          $zero, 0x74C($a1)
    ctx->pc = 0x1634b0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 1868), GPR_U32(ctx, 0));
    // 0x1634b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1634B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1634B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1634B4u;
            // 0x1634b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163490u: goto label_163490;
            case 0x1634F4u: goto label_1634f4;
            case 0x163544u: goto label_163544;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1634BCu;
    // 0x1634bc: 0x0  nop
    ctx->pc = 0x1634bcu;
    // NOP
    // 0x1634c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1634c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1634c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1634c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1634c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1634c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1634cc: 0x805084e  j           func_142138
    ctx->pc = 0x1634CCu;
    ctx->pc = 0x1634D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1634CCu;
            // 0x1634d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142138u;
    if (runtime->hasFunction(0x142138u)) {
        auto targetFn = runtime->lookupFunction(0x142138u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00142138_0x142138(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1634D4u;
    // 0x1634d4: 0x0  nop
    ctx->pc = 0x1634d4u;
    // NOP
    // 0x1634d8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1634d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1634dc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1634dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1634e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1634e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1634e4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1634e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1634e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1634e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1634ec: 0xc0506c4  jal         func_141B10
    ctx->pc = 0x1634ECu;
    SET_GPR_U32(ctx, 31, 0x1634F4u);
    ctx->pc = 0x1634F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1634ECu;
            // 0x1634f0: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141B10u;
    if (runtime->hasFunction(0x141B10u)) {
        auto targetFn = runtime->lookupFunction(0x141B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1634F4u; }
        if (ctx->pc != 0x1634F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1634F4u; }
        if (ctx->pc != 0x1634F4u) { return; }
    }
    ctx->pc = 0x1634F4u;
label_1634f4:
    // 0x1634f4: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x1634f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x1634f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1634f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1634fc: 0xac620740  sw          $v0, 0x740($v1)
    ctx->pc = 0x1634fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1856), GPR_U32(ctx, 2));
    // 0x163500: 0x3e00008  jr          $ra
    ctx->pc = 0x163500u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163500u;
            // 0x163504: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163490u: goto label_163490;
            case 0x1634F4u: goto label_1634f4;
            case 0x163544u: goto label_163544;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163508u;
    // 0x163508: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163508u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16350c: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16350cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x163510: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163514: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x163514u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163518: 0x8c450740  lw          $a1, 0x740($v0)
    ctx->pc = 0x163518u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1856)));
    // 0x16351c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16351cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163520: 0x80506f8  j           func_141BE0
    ctx->pc = 0x163520u;
    ctx->pc = 0x163524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163520u;
            // 0x163524: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141BE0u;
    if (runtime->hasFunction(0x141BE0u)) {
        auto targetFn = runtime->lookupFunction(0x141BE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141BE0_0x141be0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x163528u;
    // 0x163528: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x163528u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16352c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x16352cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x163530: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163530u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163534: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x163534u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163538: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16353c: 0xc0506c4  jal         func_141B10
    ctx->pc = 0x16353Cu;
    SET_GPR_U32(ctx, 31, 0x163544u);
    ctx->pc = 0x163540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16353Cu;
            // 0x163540: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141B10u;
    if (runtime->hasFunction(0x141B10u)) {
        auto targetFn = runtime->lookupFunction(0x141B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163544u; }
        if (ctx->pc != 0x163544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163544u; }
        if (ctx->pc != 0x163544u) { return; }
    }
    ctx->pc = 0x163544u;
label_163544:
    // 0x163544: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x163544u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x163548: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16354c: 0xac620744  sw          $v0, 0x744($v1)
    ctx->pc = 0x16354cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1860), GPR_U32(ctx, 2));
    // 0x163550: 0x3e00008  jr          $ra
    ctx->pc = 0x163550u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163550u;
            // 0x163554: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163490u: goto label_163490;
            case 0x1634F4u: goto label_1634f4;
            case 0x163544u: goto label_163544;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163558u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
