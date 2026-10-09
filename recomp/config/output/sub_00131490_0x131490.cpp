#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131490
// Address: 0x131490 - 0x1314dc
void sub_00131490_0x131490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131490_0x131490");
#endif

    switch (ctx->pc) {
        case 0x1314acu: goto label_1314ac;
        case 0x1314c8u: goto label_1314c8;
        default: break;
    }

    ctx->pc = 0x131490u;

    // 0x131490: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131494: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131498: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131498u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13149c: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13149Cu;
    {
        const bool branch_taken_0x13149c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1314A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13149Cu;
            // 0x1314a0: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13149c) {
            ctx->pc = 0x1314C0u;
            goto label_1314c0;
        }
    }
    ctx->pc = 0x1314A4u;
    // 0x1314a4: 0xc04f27a  jal         func_13C9E8
    ctx->pc = 0x1314A4u;
    SET_GPR_U32(ctx, 31, 0x1314ACu);
    ctx->pc = 0x1314A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1314A4u;
            // 0x1314a8: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C9E8u;
    if (runtime->hasFunction(0x13C9E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C9E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1314ACu; }
        if (ctx->pc != 0x1314ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C9E8_0x13c9e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1314ACu; }
        if (ctx->pc != 0x1314ACu) { return; }
    }
    ctx->pc = 0x1314ACu;
label_1314ac:
    // 0x1314ac: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1314acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1314b0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1314b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1314b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1314b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1314b8: 0x804f286  j           func_13CA18
    ctx->pc = 0x1314B8u;
    ctx->pc = 0x1314BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1314B8u;
            // 0x1314bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CA18u;
    if (runtime->hasFunction(0x13CA18u)) {
        auto targetFn = runtime->lookupFunction(0x13CA18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013CA18_0x13ca18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1314C0u;
label_1314c0:
    // 0x1314c0: 0xc04f27a  jal         func_13C9E8
    ctx->pc = 0x1314C0u;
    SET_GPR_U32(ctx, 31, 0x1314C8u);
    ctx->pc = 0x13C9E8u;
    if (runtime->hasFunction(0x13C9E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C9E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1314C8u; }
        if (ctx->pc != 0x1314C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C9E8_0x13c9e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1314C8u; }
        if (ctx->pc != 0x1314C8u) { return; }
    }
    ctx->pc = 0x1314C8u;
label_1314c8:
    // 0x1314c8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1314c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1314cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1314ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1314d0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1314d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1314d4: 0x804f286  j           func_13CA18
    ctx->pc = 0x1314D4u;
    ctx->pc = 0x1314D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1314D4u;
            // 0x1314d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CA18u;
    if (runtime->hasFunction(0x13CA18u)) {
        auto targetFn = runtime->lookupFunction(0x13CA18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013CA18_0x13ca18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1314DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
