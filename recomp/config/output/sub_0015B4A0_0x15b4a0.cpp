#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B4A0
// Address: 0x15b4a0 - 0x15b4f8
void sub_0015B4A0_0x15b4a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B4A0_0x15b4a0");
#endif

    switch (ctx->pc) {
        case 0x15b4b4u: goto label_15b4b4;
        case 0x15b4ccu: goto label_15b4cc;
        case 0x15b4d4u: goto label_15b4d4;
        case 0x15b4e0u: goto label_15b4e0;
        default: break;
    }

    ctx->pc = 0x15b4a0u;

    // 0x15b4a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15b4a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b4a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15b4a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15b4a8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15b4a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15b4ac: 0xc056d3e  jal         func_15B4F8
    ctx->pc = 0x15B4ACu;
    SET_GPR_U32(ctx, 31, 0x15B4B4u);
    ctx->pc = 0x15B4F8u;
    if (runtime->hasFunction(0x15B4F8u)) {
        auto targetFn = runtime->lookupFunction(0x15B4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B4B4u; }
        if (ctx->pc != 0x15B4B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B4F8_0x15b4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B4B4u; }
        if (ctx->pc != 0x15B4B4u) { return; }
    }
    ctx->pc = 0x15B4B4u;
label_15b4b4:
    // 0x15b4b4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15b4b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b4b8: 0x240503c4  addiu       $a1, $zero, 0x3C4
    ctx->pc = 0x15b4b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 964));
    // 0x15b4bc: 0x1200000a  beqz        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x15B4BCu;
    {
        const bool branch_taken_0x15b4bc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x15B4C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B4BCu;
            // 0x15b4c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15b4bc) {
            ctx->pc = 0x15B4E8u;
            goto label_15b4e8;
        }
    }
    ctx->pc = 0x15B4C4u;
    // 0x15b4c4: 0xc056da4  jal         func_15B690
    ctx->pc = 0x15B4C4u;
    SET_GPR_U32(ctx, 31, 0x15B4CCu);
    ctx->pc = 0x15B690u;
    if (runtime->hasFunction(0x15B690u)) {
        auto targetFn = runtime->lookupFunction(0x15B690u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B4CCu; }
        if (ctx->pc != 0x15B4CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B690_0x15b690(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B4CCu; }
        if (ctx->pc != 0x15B4CCu) { return; }
    }
    ctx->pc = 0x15B4CCu;
label_15b4cc:
    // 0x15b4cc: 0xc056d52  jal         func_15B548
    ctx->pc = 0x15B4CCu;
    SET_GPR_U32(ctx, 31, 0x15B4D4u);
    ctx->pc = 0x15B4D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B4CCu;
            // 0x15b4d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B548u;
    if (runtime->hasFunction(0x15B548u)) {
        auto targetFn = runtime->lookupFunction(0x15B548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B4D4u; }
        if (ctx->pc != 0x15B4D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B548_0x15b548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B4D4u; }
        if (ctx->pc != 0x15B4D4u) { return; }
    }
    ctx->pc = 0x15B4D4u;
label_15b4d4:
    // 0x15b4d4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x15b4d4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b4d8: 0xc056e08  jal         func_15B820
    ctx->pc = 0x15B4D8u;
    SET_GPR_U32(ctx, 31, 0x15B4E0u);
    ctx->pc = 0x15B4DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B4D8u;
            // 0x15b4dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B820u;
    if (runtime->hasFunction(0x15B820u)) {
        auto targetFn = runtime->lookupFunction(0x15B820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B4E0u; }
        if (ctx->pc != 0x15B4E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B820_0x15b820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B4E0u; }
        if (ctx->pc != 0x15B4E0u) { return; }
    }
    ctx->pc = 0x15B4E0u;
label_15b4e0:
    // 0x15b4e0: 0xae020380  sw          $v0, 0x380($s0)
    ctx->pc = 0x15b4e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 896), GPR_U32(ctx, 2));
    // 0x15b4e4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x15b4e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_15b4e8:
    // 0x15b4e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15b4e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b4ec: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15b4ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b4f0: 0x3e00008  jr          $ra
    ctx->pc = 0x15B4F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B4F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B4F0u;
            // 0x15b4f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B4B4u: goto label_15b4b4;
            case 0x15B4CCu: goto label_15b4cc;
            case 0x15B4D4u: goto label_15b4d4;
            case 0x15B4E0u: goto label_15b4e0;
            case 0x15B4E8u: goto label_15b4e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15B4F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
