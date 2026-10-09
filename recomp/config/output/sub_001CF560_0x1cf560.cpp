#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF560
// Address: 0x1cf560 - 0x1cf5f0
void sub_001CF560_0x1cf560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF560_0x1cf560");
#endif

    switch (ctx->pc) {
        case 0x1cf594u: goto label_1cf594;
        case 0x1cf59cu: goto label_1cf59c;
        case 0x1cf5acu: goto label_1cf5ac;
        case 0x1cf5ccu: goto label_1cf5cc;
        default: break;
    }

    ctx->pc = 0x1cf560u;

    // 0x1cf560: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1cf560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1cf564: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1cf564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1cf568: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cf568u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cf56c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cf56cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cf570: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1cf570u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf574: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cf574u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cf578: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1cf578u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf57c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1cf57cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf580: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cf580u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cf584: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x1cf584u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf588: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x1cf588u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf58c: 0xc07496c  jal         func_1D25B0
    ctx->pc = 0x1CF58Cu;
    SET_GPR_U32(ctx, 31, 0x1CF594u);
    ctx->pc = 0x1CF590u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF58Cu;
            // 0x1cf590: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D25B0u;
    if (runtime->hasFunction(0x1D25B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D25B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF594u; }
        if (ctx->pc != 0x1CF594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D25B0_0x1d25b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF594u; }
        if (ctx->pc != 0x1CF594u) { return; }
    }
    ctx->pc = 0x1CF594u;
label_1cf594:
    // 0x1cf594: 0xc06cb34  jal         func_1B2CD0
    ctx->pc = 0x1CF594u;
    SET_GPR_U32(ctx, 31, 0x1CF59Cu);
    ctx->pc = 0x1CF598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF594u;
            // 0x1cf598: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2CD0u;
    if (runtime->hasFunction(0x1B2CD0u)) {
        auto targetFn = runtime->lookupFunction(0x1B2CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF59Cu; }
        if (ctx->pc != 0x1CF59Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2CD0_0x1b2cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF59Cu; }
        if (ctx->pc != 0x1CF59Cu) { return; }
    }
    ctx->pc = 0x1CF59Cu;
label_1cf59c:
    // 0x1cf59c: 0x324600ff  andi        $a2, $s2, 0xFF
    ctx->pc = 0x1cf59cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1cf5a0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1cf5a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf5a4: 0xc0749f4  jal         func_1D27D0
    ctx->pc = 0x1CF5A4u;
    SET_GPR_U32(ctx, 31, 0x1CF5ACu);
    ctx->pc = 0x1CF5A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF5A4u;
            // 0x1cf5a8: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D27D0u;
    if (runtime->hasFunction(0x1D27D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D27D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF5ACu; }
        if (ctx->pc != 0x1CF5ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D27D0_0x1d27d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF5ACu; }
        if (ctx->pc != 0x1CF5ACu) { return; }
    }
    ctx->pc = 0x1CF5ACu;
label_1cf5ac:
    // 0x1cf5ac: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF5ACu;
    {
        const bool branch_taken_0x1cf5ac = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF5B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF5ACu;
            // 0x1cf5b0: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf5ac) {
            ctx->pc = 0x1CF5BCu;
            goto label_1cf5bc;
        }
    }
    ctx->pc = 0x1CF5B4u;
    // 0x1cf5b4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1CF5B4u;
    {
        const bool branch_taken_0x1cf5b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF5B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF5B4u;
            // 0x1cf5b8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf5b4) {
            ctx->pc = 0x1CF5D0u;
            goto label_1cf5d0;
        }
    }
    ctx->pc = 0x1CF5BCu;
label_1cf5bc:
    // 0x1cf5bc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1cf5bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf5c0: 0x8c2466c8  lw          $a0, 0x66C8($at)
    ctx->pc = 0x1cf5c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26312)));
    // 0x1cf5c4: 0xc0737f8  jal         func_1CDFE0
    ctx->pc = 0x1CF5C4u;
    SET_GPR_U32(ctx, 31, 0x1CF5CCu);
    ctx->pc = 0x1CF5C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF5C4u;
            // 0x1cf5c8: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDFE0u;
    if (runtime->hasFunction(0x1CDFE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CDFE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF5CCu; }
        if (ctx->pc != 0x1CF5CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDFE0_0x1cdfe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF5CCu; }
        if (ctx->pc != 0x1CF5CCu) { return; }
    }
    ctx->pc = 0x1CF5CCu;
label_1cf5cc:
    // 0x1cf5cc: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1cf5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_1cf5d0:
    // 0x1cf5d0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1cf5d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cf5d4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cf5d4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cf5d8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cf5d8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cf5dc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cf5dcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cf5e0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cf5e0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cf5e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF5E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CF5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF5E4u;
            // 0x1cf5e8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF594u: goto label_1cf594;
            case 0x1CF59Cu: goto label_1cf59c;
            case 0x1CF5ACu: goto label_1cf5ac;
            case 0x1CF5BCu: goto label_1cf5bc;
            case 0x1CF5CCu: goto label_1cf5cc;
            case 0x1CF5D0u: goto label_1cf5d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF5ECu;
    // 0x1cf5ec: 0x0  nop
    ctx->pc = 0x1cf5ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
