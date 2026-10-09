#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163880
// Address: 0x163880 - 0x1638e8
void sub_00163880_0x163880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163880_0x163880");
#endif

    switch (ctx->pc) {
        case 0x1638a0u: goto label_1638a0;
        case 0x1638b4u: goto label_1638b4;
        case 0x1638bcu: goto label_1638bc;
        case 0x1638c8u: goto label_1638c8;
        default: break;
    }

    ctx->pc = 0x163880u;

    // 0x163880: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163880u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x163884: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x163884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x163888: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16388c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16388cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163890: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163890u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163894: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x163894u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163898: 0x2a22000a  slti        $v0, $s1, 0xA
    ctx->pc = 0x163898u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x16389c: 0x0  nop
    ctx->pc = 0x16389cu;
    // NOP
label_1638a0:
    // 0x1638a0: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1638A0u;
    {
        const bool branch_taken_0x1638a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1638A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1638A0u;
            // 0x1638a4: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1638a0) {
            ctx->pc = 0x1638D4u;
            goto label_1638d4;
        }
    }
    ctx->pc = 0x1638A8u;
    // 0x1638a8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1638a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1638ac: 0xc0590ca  jal         func_164328
    ctx->pc = 0x1638ACu;
    SET_GPR_U32(ctx, 31, 0x1638B4u);
    ctx->pc = 0x1638B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1638ACu;
            // 0x1638b0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164328u;
    if (runtime->hasFunction(0x164328u)) {
        auto targetFn = runtime->lookupFunction(0x164328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1638B4u; }
        if (ctx->pc != 0x1638B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164328_0x164328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1638B4u; }
        if (ctx->pc != 0x1638B4u) { return; }
    }
    ctx->pc = 0x1638B4u;
label_1638b4:
    // 0x1638b4: 0xc04b010  jal         func_12C040
    ctx->pc = 0x1638B4u;
    SET_GPR_U32(ctx, 31, 0x1638BCu);
    ctx->pc = 0x12C040u;
    if (runtime->hasFunction(0x12C040u)) {
        auto targetFn = runtime->lookupFunction(0x12C040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1638BCu; }
        if (ctx->pc != 0x1638BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C040_0x12c040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1638BCu; }
        if (ctx->pc != 0x1638BCu) { return; }
    }
    ctx->pc = 0x1638BCu;
label_1638bc:
    // 0x1638bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1638bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1638c0: 0xc0590ca  jal         func_164328
    ctx->pc = 0x1638C0u;
    SET_GPR_U32(ctx, 31, 0x1638C8u);
    ctx->pc = 0x1638C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1638C0u;
            // 0x1638c4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164328u;
    if (runtime->hasFunction(0x164328u)) {
        auto targetFn = runtime->lookupFunction(0x164328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1638C8u; }
        if (ctx->pc != 0x1638C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164328_0x164328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1638C8u; }
        if (ctx->pc != 0x1638C8u) { return; }
    }
    ctx->pc = 0x1638C8u;
label_1638c8:
    // 0x1638c8: 0x8e020060  lw          $v0, 0x60($s0)
    ctx->pc = 0x1638c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1638cc: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1638CCu;
    {
        const bool branch_taken_0x1638cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1638D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1638CCu;
            // 0x1638d0: 0x2a22000a  slti        $v0, $s1, 0xA (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)10) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1638cc) {
            ctx->pc = 0x1638A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1638a0;
        }
    }
    ctx->pc = 0x1638D4u;
label_1638d4:
    // 0x1638d4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1638d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1638d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1638d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1638dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1638dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1638e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1638E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1638E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1638E0u;
            // 0x1638e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1638A0u: goto label_1638a0;
            case 0x1638B4u: goto label_1638b4;
            case 0x1638BCu: goto label_1638bc;
            case 0x1638C8u: goto label_1638c8;
            case 0x1638D4u: goto label_1638d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1638E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
