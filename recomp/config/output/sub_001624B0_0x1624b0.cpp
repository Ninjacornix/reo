#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001624B0
// Address: 0x1624b0 - 0x16250c
void sub_001624B0_0x1624b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001624B0_0x1624b0");
#endif

    switch (ctx->pc) {
        case 0x1624c4u: goto label_1624c4;
        case 0x1624d8u: goto label_1624d8;
        case 0x1624f8u: goto label_1624f8;
        default: break;
    }

    ctx->pc = 0x1624b0u;

    // 0x1624b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1624b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1624b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1624b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1624b8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1624b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1624bc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1624BCu;
    SET_GPR_U32(ctx, 31, 0x1624C4u);
    ctx->pc = 0x1624C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1624BCu;
            // 0x1624c0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624C4u; }
        if (ctx->pc != 0x1624C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624C4u; }
        if (ctx->pc != 0x1624C4u) { return; }
    }
    ctx->pc = 0x1624C4u;
label_1624c4:
    // 0x1624c4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1624C4u;
    {
        const bool branch_taken_0x1624c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1624C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1624C4u;
            // 0x1624c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1624c4) {
            ctx->pc = 0x1624F0u;
            goto label_1624f0;
        }
    }
    ctx->pc = 0x1624CCu;
    // 0x1624cc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1624ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1624d0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1624D0u;
    SET_GPR_U32(ctx, 31, 0x1624D8u);
    ctx->pc = 0x1624D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1624D0u;
            // 0x1624d4: 0x248400d8  addiu       $a0, $a0, 0xD8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624D8u; }
        if (ctx->pc != 0x1624D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624D8u; }
        if (ctx->pc != 0x1624D8u) { return; }
    }
    ctx->pc = 0x1624D8u;
label_1624d8:
    // 0x1624d8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1624d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1624dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1624dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1624e0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1624e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1624e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1624E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1624E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1624E4u;
            // 0x1624e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1624C4u: goto label_1624c4;
            case 0x1624D8u: goto label_1624d8;
            case 0x1624F0u: goto label_1624f0;
            case 0x1624F8u: goto label_1624f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1624ECu;
    // 0x1624ec: 0x0  nop
    ctx->pc = 0x1624ecu;
    // NOP
label_1624f0:
    // 0x1624f0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1624F0u;
    SET_GPR_U32(ctx, 31, 0x1624F8u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624F8u; }
        if (ctx->pc != 0x1624F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1624F8u; }
        if (ctx->pc != 0x1624F8u) { return; }
    }
    ctx->pc = 0x1624F8u;
label_1624f8:
    // 0x1624f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1624f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1624fc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1624fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162500: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162500u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162504: 0x805f588  j           func_17D620
    ctx->pc = 0x162504u;
    ctx->pc = 0x162508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162504u;
            // 0x162508: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D620u;
    if (runtime->hasFunction(0x17D620u)) {
        auto targetFn = runtime->lookupFunction(0x17D620u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D620_0x17d620(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16250Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
