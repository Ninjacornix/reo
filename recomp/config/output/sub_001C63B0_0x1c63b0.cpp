#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C63B0
// Address: 0x1c63b0 - 0x1c6404
void sub_001C63B0_0x1c63b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C63B0_0x1c63b0");
#endif

    switch (ctx->pc) {
        case 0x1c63c8u: goto label_1c63c8;
        case 0x1c63dcu: goto label_1c63dc;
        default: break;
    }

    ctx->pc = 0x1c63b0u;

    // 0x1c63b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c63b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c63b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c63b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c63b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c63b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c63bc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c63bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c63c0: 0xc072110  jal         func_1C8440
    ctx->pc = 0x1C63C0u;
    SET_GPR_U32(ctx, 31, 0x1C63C8u);
    ctx->pc = 0x1C63C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C63C0u;
            // 0x1c63c4: 0x26040028  addiu       $a0, $s0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8440u;
    if (runtime->hasFunction(0x1C8440u)) {
        auto targetFn = runtime->lookupFunction(0x1C8440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C63C8u; }
        if (ctx->pc != 0x1C63C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8440_0x1c8440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C63C8u; }
        if (ctx->pc != 0x1C63C8u) { return; }
    }
    ctx->pc = 0x1C63C8u;
label_1c63c8:
    // 0x1c63c8: 0x960201e0  lhu         $v0, 0x1E0($s0)
    ctx->pc = 0x1c63c8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 480)));
    // 0x1c63cc: 0x26040028  addiu       $a0, $s0, 0x28
    ctx->pc = 0x1c63ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
    // 0x1c63d0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c63d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c63d4: 0xc0721fc  jal         func_1C87F0
    ctx->pc = 0x1C63D4u;
    SET_GPR_U32(ctx, 31, 0x1C63DCu);
    ctx->pc = 0x1C63D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C63D4u;
            // 0x1c63d8: 0xa60201e0  sh          $v0, 0x1E0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 480), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C87F0u;
    if (runtime->hasFunction(0x1C87F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C87F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C63DCu; }
        if (ctx->pc != 0x1C63DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C87F0_0x1c87f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C63DCu; }
        if (ctx->pc != 0x1C63DCu) { return; }
    }
    ctx->pc = 0x1C63DCu;
label_1c63dc:
    // 0x1c63dc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c63dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c63e0: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C63E0u;
    {
        const bool branch_taken_0x1c63e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c63e0) {
            ctx->pc = 0x1C63F0u;
            goto label_1c63f0;
        }
    }
    ctx->pc = 0x1C63E8u;
    // 0x1c63e8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C63E8u;
    {
        const bool branch_taken_0x1c63e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C63ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C63E8u;
            // 0x1c63ec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c63e8) {
            ctx->pc = 0x1C63F4u;
            goto label_1c63f4;
        }
    }
    ctx->pc = 0x1C63F0u;
label_1c63f0:
    // 0x1c63f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c63f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c63f4:
    // 0x1c63f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c63f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c63f8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c63f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c63fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C63FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C6400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C63FCu;
            // 0x1c6400: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C63C8u: goto label_1c63c8;
            case 0x1C63DCu: goto label_1c63dc;
            case 0x1C63F0u: goto label_1c63f0;
            case 0x1C63F4u: goto label_1c63f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C6404u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
