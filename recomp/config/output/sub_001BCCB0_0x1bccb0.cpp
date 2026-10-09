#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BCCB0
// Address: 0x1bccb0 - 0x1bcd30
void sub_001BCCB0_0x1bccb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BCCB0_0x1bccb0");
#endif

    switch (ctx->pc) {
        case 0x1bccc0u: goto label_1bccc0;
        case 0x1bccc8u: goto label_1bccc8;
        case 0x1bccd0u: goto label_1bccd0;
        case 0x1bccd8u: goto label_1bccd8;
        case 0x1bcce8u: goto label_1bcce8;
        case 0x1bccf8u: goto label_1bccf8;
        case 0x1bcd04u: goto label_1bcd04;
        case 0x1bcd0cu: goto label_1bcd0c;
        case 0x1bcd14u: goto label_1bcd14;
        default: break;
    }

    ctx->pc = 0x1bccb0u;

    // 0x1bccb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bccb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bccb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bccb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bccb8: 0xc06c8b0  jal         func_1B22C0
    ctx->pc = 0x1BCCB8u;
    SET_GPR_U32(ctx, 31, 0x1BCCC0u);
    ctx->pc = 0x1B22C0u;
    if (runtime->hasFunction(0x1B22C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B22C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCC0u; }
        if (ctx->pc != 0x1BCCC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B22C0_0x1b22c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCC0u; }
        if (ctx->pc != 0x1BCCC0u) { return; }
    }
    ctx->pc = 0x1BCCC0u;
label_1bccc0:
    // 0x1bccc0: 0xc06c8d0  jal         func_1B2340
    ctx->pc = 0x1BCCC0u;
    SET_GPR_U32(ctx, 31, 0x1BCCC8u);
    ctx->pc = 0x1B2340u;
    if (runtime->hasFunction(0x1B2340u)) {
        auto targetFn = runtime->lookupFunction(0x1B2340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCC8u; }
        if (ctx->pc != 0x1BCCC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2340_0x1b2340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCC8u; }
        if (ctx->pc != 0x1BCCC8u) { return; }
    }
    ctx->pc = 0x1BCCC8u;
label_1bccc8:
    // 0x1bccc8: 0xc06bda8  jal         func_1AF6A0
    ctx->pc = 0x1BCCC8u;
    SET_GPR_U32(ctx, 31, 0x1BCCD0u);
    ctx->pc = 0x1BCCCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCCC8u;
            // 0x1bcccc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF6A0u;
    if (runtime->hasFunction(0x1AF6A0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF6A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCD0u; }
        if (ctx->pc != 0x1BCCD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF6A0_0x1af6a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCD0u; }
        if (ctx->pc != 0x1BCCD0u) { return; }
    }
    ctx->pc = 0x1BCCD0u;
label_1bccd0:
    // 0x1bccd0: 0xc06bc30  jal         func_1AF0C0
    ctx->pc = 0x1BCCD0u;
    SET_GPR_U32(ctx, 31, 0x1BCCD8u);
    ctx->pc = 0x1BCCD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCCD0u;
            // 0x1bccd4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF0C0u;
    if (runtime->hasFunction(0x1AF0C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AF0C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCD8u; }
        if (ctx->pc != 0x1BCCD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF0C0_0x1af0c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCD8u; }
        if (ctx->pc != 0x1BCCD8u) { return; }
    }
    ctx->pc = 0x1BCCD8u;
label_1bccd8:
    // 0x1bccd8: 0x3c04001c  lui         $a0, 0x1C
    ctx->pc = 0x1bccd8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28 << 16));
    // 0x1bccdc: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1bccdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1bcce0: 0xc06dfb8  jal         func_1B7EE0
    ctx->pc = 0x1BCCE0u;
    SET_GPR_U32(ctx, 31, 0x1BCCE8u);
    ctx->pc = 0x1BCCE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCCE0u;
            // 0x1bcce4: 0x2484b8f0  addiu       $a0, $a0, -0x4710 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7EE0u;
    if (runtime->hasFunction(0x1B7EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1B7EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCE8u; }
        if (ctx->pc != 0x1BCCE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7EE0_0x1b7ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCE8u; }
        if (ctx->pc != 0x1BCCE8u) { return; }
    }
    ctx->pc = 0x1BCCE8u;
label_1bcce8:
    // 0x1bcce8: 0x3c04001c  lui         $a0, 0x1C
    ctx->pc = 0x1bcce8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28 << 16));
    // 0x1bccec: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x1bccecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1bccf0: 0xc06dfb8  jal         func_1B7EE0
    ctx->pc = 0x1BCCF0u;
    SET_GPR_U32(ctx, 31, 0x1BCCF8u);
    ctx->pc = 0x1BCCF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCCF0u;
            // 0x1bccf4: 0x2484b480  addiu       $a0, $a0, -0x4B80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947968));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7EE0u;
    if (runtime->hasFunction(0x1B7EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1B7EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCF8u; }
        if (ctx->pc != 0x1BCCF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7EE0_0x1b7ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCCF8u; }
        if (ctx->pc != 0x1BCCF8u) { return; }
    }
    ctx->pc = 0x1BCCF8u;
label_1bccf8:
    // 0x1bccf8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bccf8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bccfc: 0xc074ee4  jal         func_1D3B90
    ctx->pc = 0x1BCCFCu;
    SET_GPR_U32(ctx, 31, 0x1BCD04u);
    ctx->pc = 0x1BCD00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCCFCu;
            // 0x1bcd00: 0xa02043c0  sb          $zero, 0x43C0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17344), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3B90u;
    if (runtime->hasFunction(0x1D3B90u)) {
        auto targetFn = runtime->lookupFunction(0x1D3B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD04u; }
        if (ctx->pc != 0x1BCD04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3B90_0x1d3b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD04u; }
        if (ctx->pc != 0x1BCD04u) { return; }
    }
    ctx->pc = 0x1BCD04u;
label_1bcd04:
    // 0x1bcd04: 0xc0747f0  jal         func_1D1FC0
    ctx->pc = 0x1BCD04u;
    SET_GPR_U32(ctx, 31, 0x1BCD0Cu);
    ctx->pc = 0x1D1FC0u;
    if (runtime->hasFunction(0x1D1FC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D1FC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD0Cu; }
        if (ctx->pc != 0x1BCD0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1FC0_0x1d1fc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD0Cu; }
        if (ctx->pc != 0x1BCD0Cu) { return; }
    }
    ctx->pc = 0x1BCD0Cu;
label_1bcd0c:
    // 0x1bcd0c: 0xc06cf64  jal         func_1B3D90
    ctx->pc = 0x1BCD0Cu;
    SET_GPR_U32(ctx, 31, 0x1BCD14u);
    ctx->pc = 0x1B3D90u;
    if (runtime->hasFunction(0x1B3D90u)) {
        auto targetFn = runtime->lookupFunction(0x1B3D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD14u; }
        if (ctx->pc != 0x1BCD14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3D90_0x1b3d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCD14u; }
        if (ctx->pc != 0x1BCD14u) { return; }
    }
    ctx->pc = 0x1BCD14u;
label_1bcd14:
    // 0x1bcd14: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bcd14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bcd18: 0x3e00008  jr          $ra
    ctx->pc = 0x1BCD18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BCD1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCD18u;
            // 0x1bcd1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BCCC0u: goto label_1bccc0;
            case 0x1BCCC8u: goto label_1bccc8;
            case 0x1BCCD0u: goto label_1bccd0;
            case 0x1BCCD8u: goto label_1bccd8;
            case 0x1BCCE8u: goto label_1bcce8;
            case 0x1BCCF8u: goto label_1bccf8;
            case 0x1BCD04u: goto label_1bcd04;
            case 0x1BCD0Cu: goto label_1bcd0c;
            case 0x1BCD14u: goto label_1bcd14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BCD20u;
    // 0x1bcd20: 0x80748a0  j           func_1D2280
    ctx->pc = 0x1BCD20u;
    ctx->pc = 0x1D2280u;
    if (runtime->hasFunction(0x1D2280u)) {
        auto targetFn = runtime->lookupFunction(0x1D2280u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001D2280_0x1d2280(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1BCD28u;
    // 0x1bcd28: 0x0  nop
    ctx->pc = 0x1bcd28u;
    // NOP
    // 0x1bcd2c: 0x0  nop
    ctx->pc = 0x1bcd2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
