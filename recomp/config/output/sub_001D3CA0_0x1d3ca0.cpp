#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3CA0
// Address: 0x1d3ca0 - 0x1d3ce4
void sub_001D3CA0_0x1d3ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3CA0_0x1d3ca0");
#endif

    switch (ctx->pc) {
        case 0x1d3cc4u: goto label_1d3cc4;
        case 0x1d3cd4u: goto label_1d3cd4;
        default: break;
    }

    ctx->pc = 0x1d3ca0u;

    // 0x1d3ca0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d3ca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d3ca4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3ca4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3ca8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d3ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d3cac: 0x24a56688  addiu       $a1, $a1, 0x6688
    ctx->pc = 0x1d3cacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26248));
    // 0x1d3cb0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3cb0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3cb4: 0x90860b98  lbu         $a2, 0xB98($a0)
    ctx->pc = 0x1d3cb4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2968)));
    // 0x1d3cb8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d3cb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3cbc: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3CBCu;
    SET_GPR_U32(ctx, 31, 0x1D3CC4u);
    ctx->pc = 0x1D3CC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3CBCu;
            // 0x1d3cc0: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3CC4u; }
        if (ctx->pc != 0x1D3CC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3CC4u; }
        if (ctx->pc != 0x1D3CC4u) { return; }
    }
    ctx->pc = 0x1D3CC4u;
label_1d3cc4:
    // 0x1d3cc4: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1d3cc4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1d3cc8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d3cc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3ccc: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D3CCCu;
    SET_GPR_U32(ctx, 31, 0x1D3CD4u);
    ctx->pc = 0x1D3CD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3CCCu;
            // 0x1d3cd0: 0x24450004  addiu       $a1, $v0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3CD4u; }
        if (ctx->pc != 0x1D3CD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3CD4u; }
        if (ctx->pc != 0x1D3CD4u) { return; }
    }
    ctx->pc = 0x1D3CD4u;
label_1d3cd4:
    // 0x1d3cd4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d3cd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3cd8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3cd8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3cdc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3CDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3CDCu;
            // 0x1d3ce0: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3CC4u: goto label_1d3cc4;
            case 0x1D3CD4u: goto label_1d3cd4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3CE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
