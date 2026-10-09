#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177990
// Address: 0x177990 - 0x177a30
void sub_00177990_0x177990(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177990_0x177990");
#endif

    switch (ctx->pc) {
        case 0x1779b4u: goto label_1779b4;
        case 0x1779c4u: goto label_1779c4;
        case 0x1779e0u: goto label_1779e0;
        case 0x1779f0u: goto label_1779f0;
        default: break;
    }

    ctx->pc = 0x177990u;

    // 0x177990: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x177990u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x177994: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x177994u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x177998: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177998u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17799c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17799cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1779a0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1779a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1779a4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1779a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1779a8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1779a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1779ac: 0xc05dec4  jal         func_177B10
    ctx->pc = 0x1779ACu;
    SET_GPR_U32(ctx, 31, 0x1779B4u);
    ctx->pc = 0x1779B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1779ACu;
            // 0x1779b0: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177B10u;
    if (runtime->hasFunction(0x177B10u)) {
        auto targetFn = runtime->lookupFunction(0x177B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1779B4u; }
        if (ctx->pc != 0x1779B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177B10_0x177b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1779B4u; }
        if (ctx->pc != 0x1779B4u) { return; }
    }
    ctx->pc = 0x1779B4u;
label_1779b4:
    // 0x1779b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1779b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1779b8: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1779b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1779bc: 0xc05de94  jal         func_177A50
    ctx->pc = 0x1779BCu;
    SET_GPR_U32(ctx, 31, 0x1779C4u);
    ctx->pc = 0x1779C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1779BCu;
            // 0x1779c0: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A50u;
    if (runtime->hasFunction(0x177A50u)) {
        auto targetFn = runtime->lookupFunction(0x177A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1779C4u; }
        if (ctx->pc != 0x1779C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A50_0x177a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1779C4u; }
        if (ctx->pc != 0x1779C4u) { return; }
    }
    ctx->pc = 0x1779C4u;
label_1779c4:
    // 0x1779c4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1779c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1779c8: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x1779c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1779cc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1779ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1779d0: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1779D0u;
    {
        const bool branch_taken_0x1779d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1779D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1779D0u;
            // 0x1779d4: 0x24060005  addiu       $a2, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1779d0) {
            ctx->pc = 0x177A10u;
            goto label_177a10;
        }
    }
    ctx->pc = 0x1779D8u;
    // 0x1779d8: 0xc05dec4  jal         func_177B10
    ctx->pc = 0x1779D8u;
    SET_GPR_U32(ctx, 31, 0x1779E0u);
    ctx->pc = 0x177B10u;
    if (runtime->hasFunction(0x177B10u)) {
        auto targetFn = runtime->lookupFunction(0x177B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1779E0u; }
        if (ctx->pc != 0x1779E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177B10_0x177b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1779E0u; }
        if (ctx->pc != 0x1779E0u) { return; }
    }
    ctx->pc = 0x1779E0u;
label_1779e0:
    // 0x1779e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1779e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1779e4: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1779e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1779e8: 0xc05de94  jal         func_177A50
    ctx->pc = 0x1779E8u;
    SET_GPR_U32(ctx, 31, 0x1779F0u);
    ctx->pc = 0x1779ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1779E8u;
            // 0x1779ec: 0x24060006  addiu       $a2, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177A50u;
    if (runtime->hasFunction(0x177A50u)) {
        auto targetFn = runtime->lookupFunction(0x177A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1779F0u; }
        if (ctx->pc != 0x1779F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177A50_0x177a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1779F0u; }
        if (ctx->pc != 0x1779F0u) { return; }
    }
    ctx->pc = 0x1779F0u;
label_1779f0:
    // 0x1779f0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1779f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1779f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1779f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1779f8: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1779f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1779fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1779fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177a00: 0x24060007  addiu       $a2, $zero, 0x7
    ctx->pc = 0x177a00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x177a04: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x177a04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177a08: 0x805dec4  j           func_177B10
    ctx->pc = 0x177A08u;
    ctx->pc = 0x177A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177A08u;
            // 0x177a0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177B10u;
    if (runtime->hasFunction(0x177B10u)) {
        auto targetFn = runtime->lookupFunction(0x177B10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177B10_0x177b10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x177A10u;
label_177a10:
    // 0x177a10: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x177a10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177a14: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177a14u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177a18: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x177a18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x177a1c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x177a1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177a20: 0x24060007  addiu       $a2, $zero, 0x7
    ctx->pc = 0x177a20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x177a24: 0x805dec4  j           func_177B10
    ctx->pc = 0x177A24u;
    ctx->pc = 0x177A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177A24u;
            // 0x177a28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177B10u;
    if (runtime->hasFunction(0x177B10u)) {
        auto targetFn = runtime->lookupFunction(0x177B10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177B10_0x177b10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x177A2Cu;
    // 0x177a2c: 0x0  nop
    ctx->pc = 0x177a2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
