#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB500
// Address: 0x1ab500 - 0x1ab560
void sub_001AB500_0x1ab500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB500_0x1ab500");
#endif

    switch (ctx->pc) {
        case 0x1ab528u: goto label_1ab528;
        case 0x1ab53cu: goto label_1ab53c;
        default: break;
    }

    ctx->pc = 0x1ab500u;

    // 0x1ab500: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1ab500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1ab504: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x1ab504u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x1ab508: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1ab508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1ab50c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1ab50cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ab510: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ab510u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ab514: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ab514u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ab518: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1ab518u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab51c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ab51cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ab520: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1ab520u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab524: 0x8c500008  lw          $s0, 0x8($v0)
    ctx->pc = 0x1ab524u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
label_1ab528:
    // 0x1ab528: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ab528u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab52c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1ab52cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab530: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1ab530u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab534: 0xc04714c  jal         func_11C530
    ctx->pc = 0x1AB534u;
    SET_GPR_U32(ctx, 31, 0x1AB53Cu);
    ctx->pc = 0x1AB538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB534u;
            // 0x1ab538: 0x27a7004c  addiu       $a3, $sp, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 76));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C530u;
    if (runtime->hasFunction(0x11C530u)) {
        auto targetFn = runtime->lookupFunction(0x11C530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB53Cu; }
        if (ctx->pc != 0x1AB53Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C530_0x11c530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB53Cu; }
        if (ctx->pc != 0x1AB53Cu) { return; }
    }
    ctx->pc = 0x1AB53Cu;
label_1ab53c:
    // 0x1ab53c: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AB53Cu;
    {
        const bool branch_taken_0x1ab53c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1ab53c) {
            ctx->pc = 0x1AB528u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab528;
        }
    }
    ctx->pc = 0x1AB544u;
    // 0x1ab544: 0x8fa2004c  lw          $v0, 0x4C($sp)
    ctx->pc = 0x1ab544u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x1ab548: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1ab548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ab54c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ab54cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ab550: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ab550u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ab554: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ab554u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab558: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB558u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB55Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB558u;
            // 0x1ab55c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB528u: goto label_1ab528;
            case 0x1AB53Cu: goto label_1ab53c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB560u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
