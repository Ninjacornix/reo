#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192500
// Address: 0x192500 - 0x192580
void sub_00192500_0x192500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192500_0x192500");
#endif

    switch (ctx->pc) {
        case 0x192520u: goto label_192520;
        case 0x19252cu: goto label_19252c;
        case 0x192538u: goto label_192538;
        default: break;
    }

    ctx->pc = 0x192500u;

    // 0x192500: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x192500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x192504: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x192504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x192508: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192508u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19250c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19250cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192510: 0x8c910014  lw          $s1, 0x14($a0)
    ctx->pc = 0x192510u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x192514: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x192514u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x192518: 0xc063714  jal         func_18DC50
    ctx->pc = 0x192518u;
    SET_GPR_U32(ctx, 31, 0x192520u);
    ctx->pc = 0x19251Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192518u;
            // 0x19251c: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC50u;
    if (runtime->hasFunction(0x18DC50u)) {
        auto targetFn = runtime->lookupFunction(0x18DC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192520u; }
        if (ctx->pc != 0x192520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192520u; }
        if (ctx->pc != 0x192520u) { return; }
    }
    ctx->pc = 0x192520u;
label_192520:
    // 0x192520: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x192520u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192524: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x192524u;
    SET_GPR_U32(ctx, 31, 0x19252Cu);
    ctx->pc = 0x192528u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192524u;
            // 0x192528: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19252Cu; }
        if (ctx->pc != 0x19252Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19252Cu; }
        if (ctx->pc != 0x19252Cu) { return; }
    }
    ctx->pc = 0x19252Cu;
label_19252c:
    // 0x19252c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x19252cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192530: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x192530u;
    {
        const bool branch_taken_0x192530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192530u;
            // 0x192534: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192530) {
            ctx->pc = 0x19254Cu;
            goto label_19254c;
        }
    }
    ctx->pc = 0x192538u;
label_192538:
    // 0x192538: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x192538u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x19253c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x19253cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x192540: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x192540u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x192544: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x192544u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x192548: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x192548u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
label_19254c:
    // 0x19254c: 0x8e230018  lw          $v1, 0x18($s1)
    ctx->pc = 0x19254cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x192550: 0x31882  srl         $v1, $v1, 2
    ctx->pc = 0x192550u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 2));
    // 0x192554: 0xa3182b  sltu        $v1, $a1, $v1
    ctx->pc = 0x192554u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x192558: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x192558u;
    {
        const bool branch_taken_0x192558 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x192558) {
            ctx->pc = 0x192538u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192538;
        }
    }
    ctx->pc = 0x192560u;
    // 0x192560: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x192560u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192564: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x192564u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192568: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x192568u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19256c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19256cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192570: 0x3e00008  jr          $ra
    ctx->pc = 0x192570u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192570u;
            // 0x192574: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192520u: goto label_192520;
            case 0x19252Cu: goto label_19252c;
            case 0x192538u: goto label_192538;
            case 0x19254Cu: goto label_19254c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192578u;
    // 0x192578: 0x0  nop
    ctx->pc = 0x192578u;
    // NOP
    // 0x19257c: 0x0  nop
    ctx->pc = 0x19257cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
