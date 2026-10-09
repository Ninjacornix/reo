#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192840
// Address: 0x192840 - 0x1928d4
void sub_00192840_0x192840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192840_0x192840");
#endif

    switch (ctx->pc) {
        case 0x192858u: goto label_192858;
        case 0x192878u: goto label_192878;
        case 0x1928a0u: goto label_1928a0;
        default: break;
    }

    ctx->pc = 0x192840u;

    // 0x192840: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x192840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x192844: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x192844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x192848: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192848u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19284c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19284cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192850: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x192850u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192854: 0x220802d  daddu       $s0, $s1, $zero
    ctx->pc = 0x192854u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_192858:
    // 0x192858: 0x862200c4  lh          $v0, 0xC4($s1)
    ctx->pc = 0x192858u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 196)));
    // 0x19285c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19285cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x192860: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x192860u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x192864: 0x26250080  addiu       $a1, $s1, 0x80
    ctx->pc = 0x192864u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 128));
    // 0x192868: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x192868u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19286c: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x19286cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x192870: 0xc0644a0  jal         func_191280
    ctx->pc = 0x192870u;
    SET_GPR_U32(ctx, 31, 0x192878u);
    ctx->pc = 0x192874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192870u;
            // 0x192874: 0x412021  addu        $a0, $v0, $at (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192878u; }
        if (ctx->pc != 0x192878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192878u; }
        if (ctx->pc != 0x192878u) { return; }
    }
    ctx->pc = 0x192878u;
label_192878:
    // 0x192878: 0x8e2300d0  lw          $v1, 0xD0($s1)
    ctx->pc = 0x192878u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x19287c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19287Cu;
    {
        const bool branch_taken_0x19287c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x19287c) {
            ctx->pc = 0x19288Cu;
            goto label_19288c;
        }
    }
    ctx->pc = 0x192884u;
    // 0x192884: 0x1000fff4  b           . + 4 + (-0xC << 2)
    ctx->pc = 0x192884u;
    {
        const bool branch_taken_0x192884 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192884u;
            // 0x192888: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192884) {
            ctx->pc = 0x192858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192858;
        }
    }
    ctx->pc = 0x19288Cu;
label_19288c:
    // 0x19288c: 0x8e2300cc  lw          $v1, 0xCC($s1)
    ctx->pc = 0x19288cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x192890: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x192890u;
    {
        const bool branch_taken_0x192890 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x192890) {
            ctx->pc = 0x1928B8u;
            goto label_1928b8;
        }
    }
    ctx->pc = 0x192898u;
    // 0x192898: 0x1000ffef  b           . + 4 + (-0x11 << 2)
    ctx->pc = 0x192898u;
    {
        const bool branch_taken_0x192898 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19289Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192898u;
            // 0x19289c: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192898) {
            ctx->pc = 0x192858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192858;
        }
    }
    ctx->pc = 0x1928A0u;
label_1928a0:
    // 0x1928a0: 0x8e2300cc  lw          $v1, 0xCC($s1)
    ctx->pc = 0x1928a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x1928a4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1928A4u;
    {
        const bool branch_taken_0x1928a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1928a4) {
            ctx->pc = 0x1928B4u;
            goto label_1928b4;
        }
    }
    ctx->pc = 0x1928ACu;
    // 0x1928ac: 0x1000ffea  b           . + 4 + (-0x16 << 2)
    ctx->pc = 0x1928ACu;
    {
        const bool branch_taken_0x1928ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1928B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1928ACu;
            // 0x1928b0: 0x60882d  daddu       $s1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1928ac) {
            ctx->pc = 0x192858u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192858;
        }
    }
    ctx->pc = 0x1928B4u;
label_1928b4:
    // 0x1928b4: 0x8e3100c8  lw          $s1, 0xC8($s1)
    ctx->pc = 0x1928b4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 200)));
label_1928b8:
    // 0x1928b8: 0x1630fff9  bne         $s1, $s0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1928B8u;
    {
        const bool branch_taken_0x1928b8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 16));
        if (branch_taken_0x1928b8) {
            ctx->pc = 0x1928A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1928a0;
        }
    }
    ctx->pc = 0x1928C0u;
    // 0x1928c0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1928c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1928c4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1928c4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1928c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1928c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1928cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1928CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1928D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1928CCu;
            // 0x1928d0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192858u: goto label_192858;
            case 0x192878u: goto label_192878;
            case 0x19288Cu: goto label_19288c;
            case 0x1928A0u: goto label_1928a0;
            case 0x1928B4u: goto label_1928b4;
            case 0x1928B8u: goto label_1928b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1928D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
