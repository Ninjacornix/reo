#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD520
// Address: 0x1cd520 - 0x1cd5b0
void sub_001CD520_0x1cd520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD520_0x1cd520");
#endif

    switch (ctx->pc) {
        case 0x1cd574u: goto label_1cd574;
        case 0x1cd58cu: goto label_1cd58c;
        default: break;
    }

    ctx->pc = 0x1cd520u;

    // 0x1cd520: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cd520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cd524: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1cd524u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1cd528: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cd528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cd52c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd52cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd530: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cd530u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cd534: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1cd534u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1cd538: 0x942743da  lhu         $a3, 0x43DA($at)
    ctx->pc = 0x1cd538u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1cd53c: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1cd53cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1cd540: 0x244266d0  addiu       $v0, $v0, 0x66D0
    ctx->pc = 0x1cd540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26320));
    // 0x1cd544: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1cd544u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd548: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1cd548u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1cd54c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cd54cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cd550: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x1cd550u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cd554: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd554u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd558: 0x24a55fd0  addiu       $a1, $a1, 0x5FD0
    ctx->pc = 0x1cd558u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24528));
    // 0x1cd55c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1cd55cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1cd560: 0x942943dc  lhu         $t1, 0x43DC($at)
    ctx->pc = 0x1cd560u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1cd564: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1cd564u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1cd568: 0x942a43de  lhu         $t2, 0x43DE($at)
    ctx->pc = 0x1cd568u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17374)));
    // 0x1cd56c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CD56Cu;
    SET_GPR_U32(ctx, 31, 0x1CD574u);
    ctx->pc = 0x1CD570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD56Cu;
            // 0x1cd570: 0xe0402d  daddu       $t0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD574u; }
        if (ctx->pc != 0x1CD574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD574u; }
        if (ctx->pc != 0x1CD574u) { return; }
    }
    ctx->pc = 0x1CD574u;
label_1cd574:
    // 0x1cd574: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CD574u;
    {
        const bool branch_taken_0x1cd574 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD574u;
            // 0x1cd578: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd574) {
            ctx->pc = 0x1CD58Cu;
            goto label_1cd58c;
        }
    }
    ctx->pc = 0x1CD57Cu;
    // 0x1cd57c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cd57cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cd580: 0x24840af0  addiu       $a0, $a0, 0xAF0
    ctx->pc = 0x1cd580u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2800));
    // 0x1cd584: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CD584u;
    SET_GPR_U32(ctx, 31, 0x1CD58Cu);
    ctx->pc = 0x1CD588u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD584u;
            // 0x1cd588: 0x24a55fa0  addiu       $a1, $a1, 0x5FA0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD58Cu; }
        if (ctx->pc != 0x1CD58Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD58Cu; }
        if (ctx->pc != 0x1CD58Cu) { return; }
    }
    ctx->pc = 0x1CD58Cu;
label_1cd58c:
    // 0x1cd58c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cd58cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cd590: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1cd590u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1cd594: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cd594u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cd598: 0x24420af0  addiu       $v0, $v0, 0xAF0
    ctx->pc = 0x1cd598u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2800));
    // 0x1cd59c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD59Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD5A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD59Cu;
            // 0x1cd5a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD574u: goto label_1cd574;
            case 0x1CD58Cu: goto label_1cd58c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD5A4u;
    // 0x1cd5a4: 0x0  nop
    ctx->pc = 0x1cd5a4u;
    // NOP
    // 0x1cd5a8: 0x0  nop
    ctx->pc = 0x1cd5a8u;
    // NOP
    // 0x1cd5ac: 0x0  nop
    ctx->pc = 0x1cd5acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
