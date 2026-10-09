#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1690
// Address: 0x1b1690 - 0x1b16d4
void sub_001B1690_0x1b1690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1690_0x1b1690");
#endif

    switch (ctx->pc) {
        case 0x1b16a4u: goto label_1b16a4;
        case 0x1b16b8u: goto label_1b16b8;
        case 0x1b16c4u: goto label_1b16c4;
        default: break;
    }

    ctx->pc = 0x1b1690u;

    // 0x1b1690: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b1690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b1694: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b1694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b1698: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b1698u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b169c: 0xc06c560  jal         func_1B1580
    ctx->pc = 0x1B169Cu;
    SET_GPR_U32(ctx, 31, 0x1B16A4u);
    ctx->pc = 0x1B16A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B169Cu;
            // 0x1b16a0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1580u;
    if (runtime->hasFunction(0x1B1580u)) {
        auto targetFn = runtime->lookupFunction(0x1B1580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B16A4u; }
        if (ctx->pc != 0x1B16A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1580_0x1b1580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B16A4u; }
        if (ctx->pc != 0x1B16A4u) { return; }
    }
    ctx->pc = 0x1B16A4u;
label_1b16a4:
    // 0x1b16a4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b16a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b16a8: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B16A8u;
    {
        const bool branch_taken_0x1b16a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B16ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B16A8u;
            // 0x1b16ac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b16a8) {
            ctx->pc = 0x1B16BCu;
            goto label_1b16bc;
        }
    }
    ctx->pc = 0x1B16B0u;
    // 0x1b16b0: 0xc06c6a4  jal         func_1B1A90
    ctx->pc = 0x1B16B0u;
    SET_GPR_U32(ctx, 31, 0x1B16B8u);
    ctx->pc = 0x1B16B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B16B0u;
            // 0x1b16b4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1A90u;
    if (runtime->hasFunction(0x1B1A90u)) {
        auto targetFn = runtime->lookupFunction(0x1B1A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B16B8u; }
        if (ctx->pc != 0x1B16B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1A90_0x1b1a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B16B8u; }
        if (ctx->pc != 0x1B16B8u) { return; }
    }
    ctx->pc = 0x1B16B8u;
label_1b16b8:
    // 0x1b16b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b16b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1b16bc:
    // 0x1b16bc: 0xc06c674  jal         func_1B19D0
    ctx->pc = 0x1B16BCu;
    SET_GPR_U32(ctx, 31, 0x1B16C4u);
    ctx->pc = 0x1B19D0u;
    if (runtime->hasFunction(0x1B19D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B19D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B16C4u; }
        if (ctx->pc != 0x1B16C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B19D0_0x1b19d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B16C4u; }
        if (ctx->pc != 0x1B16C4u) { return; }
    }
    ctx->pc = 0x1B16C4u;
label_1b16c4:
    // 0x1b16c4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b16c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b16c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b16c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b16cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B16CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B16D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B16CCu;
            // 0x1b16d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B16A4u: goto label_1b16a4;
            case 0x1B16B8u: goto label_1b16b8;
            case 0x1B16BCu: goto label_1b16bc;
            case 0x1B16C4u: goto label_1b16c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B16D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
