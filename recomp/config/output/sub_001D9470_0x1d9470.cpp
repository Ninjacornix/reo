#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D9470
// Address: 0x1d9470 - 0x1d9aa0
void sub_001D9470_0x1d9470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D9470_0x1d9470");
#endif

    switch (ctx->pc) {
        case 0x1d94b0u: goto label_1d94b0;
        case 0x1d9524u: goto label_1d9524;
        case 0x1d9530u: goto label_1d9530;
        case 0x1d9540u: goto label_1d9540;
        case 0x1d9568u: goto label_1d9568;
        case 0x1d9580u: goto label_1d9580;
        case 0x1d9588u: goto label_1d9588;
        case 0x1d9598u: goto label_1d9598;
        case 0x1d95c0u: goto label_1d95c0;
        case 0x1d95d8u: goto label_1d95d8;
        case 0x1d95e0u: goto label_1d95e0;
        case 0x1d95f0u: goto label_1d95f0;
        case 0x1d9618u: goto label_1d9618;
        case 0x1d9630u: goto label_1d9630;
        case 0x1d96c4u: goto label_1d96c4;
        case 0x1d9738u: goto label_1d9738;
        case 0x1d976cu: goto label_1d976c;
        case 0x1d9780u: goto label_1d9780;
        case 0x1d97a0u: goto label_1d97a0;
        case 0x1d97b8u: goto label_1d97b8;
        case 0x1d9820u: goto label_1d9820;
        case 0x1d9830u: goto label_1d9830;
        case 0x1d9868u: goto label_1d9868;
        case 0x1d988cu: goto label_1d988c;
        case 0x1d9928u: goto label_1d9928;
        case 0x1d9950u: goto label_1d9950;
        case 0x1d9958u: goto label_1d9958;
        case 0x1d9998u: goto label_1d9998;
        case 0x1d99a0u: goto label_1d99a0;
        case 0x1d99d0u: goto label_1d99d0;
        case 0x1d99e0u: goto label_1d99e0;
        case 0x1d99f4u: goto label_1d99f4;
        case 0x1d9a38u: goto label_1d9a38;
        default: break;
    }

    ctx->pc = 0x1d9470u;

label_1d9470:
    // 0x1d9470: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1d9470u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d9474: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1d9474u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9478: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d9478u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d947c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d947cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9480: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d9480u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d9484: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d9484u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d9488: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1d9488u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d948c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d948cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d9490: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d9490u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d9494: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d9494u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d9498: 0x80850000  lb          $a1, 0x0($a0)
    ctx->pc = 0x1d9498u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d949c: 0x10a0001e  beqz        $a1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1D949Cu;
    {
        const bool branch_taken_0x1d949c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D94A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D949Cu;
            // 0x1d94a0: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d949c) {
            ctx->pc = 0x1D9518u;
            goto label_1d9518;
        }
    }
    ctx->pc = 0x1D94A4u;
    // 0x1d94a4: 0x2402002e  addiu       $v0, $zero, 0x2E
    ctx->pc = 0x1d94a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1d94a8: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1d94a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d94ac: 0x0  nop
    ctx->pc = 0x1d94acu;
    // NOP
label_1d94b0:
    // 0x1d94b0: 0x28a40030  slti        $a0, $a1, 0x30
    ctx->pc = 0x1d94b0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)48) ? 1 : 0);
    // 0x1d94b4: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D94B4u;
    {
        const bool branch_taken_0x1d94b4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D94B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D94B4u;
            // 0x1d94b8: 0x28a1003a  slti        $at, $a1, 0x3A (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)58) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d94b4) {
            ctx->pc = 0x1D94D8u;
            goto label_1d94d8;
        }
    }
    ctx->pc = 0x1D94BCu;
    // 0x1d94bc: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D94BCu;
    {
        const bool branch_taken_0x1d94bc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d94bc) {
            ctx->pc = 0x1D94D8u;
            goto label_1d94d8;
        }
    }
    ctx->pc = 0x1D94C4u;
    // 0x1d94c4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1d94c4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1d94c8: 0x14e3000f  bne         $a3, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1D94C8u;
    {
        const bool branch_taken_0x1d94c8 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        if (branch_taken_0x1d94c8) {
            ctx->pc = 0x1D9508u;
            goto label_1d9508;
        }
    }
    ctx->pc = 0x1D94D0u;
    // 0x1d94d0: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x1D94D0u;
    {
        const bool branch_taken_0x1d94d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D94D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D94D0u;
            // 0x1d94d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d94d0) {
            ctx->pc = 0x1D9670u;
            goto label_1d9670;
        }
    }
    ctx->pc = 0x1D94D8u;
label_1d94d8:
    // 0x1d94d8: 0x14a20009  bne         $a1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D94D8u;
    {
        const bool branch_taken_0x1d94d8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d94d8) {
            ctx->pc = 0x1D9500u;
            goto label_1d9500;
        }
    }
    ctx->pc = 0x1D94E0u;
    // 0x1d94e0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1d94e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1d94e4: 0x15030004  bne         $t0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D94E4u;
    {
        const bool branch_taken_0x1d94e4 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 3));
        if (branch_taken_0x1d94e4) {
            ctx->pc = 0x1D94F8u;
            goto label_1d94f8;
        }
    }
    ctx->pc = 0x1D94ECu;
    // 0x1d94ec: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1D94ECu;
    {
        const bool branch_taken_0x1d94ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D94F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D94ECu;
            // 0x1d94f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d94ec) {
            ctx->pc = 0x1D9670u;
            goto label_1d9670;
        }
    }
    ctx->pc = 0x1D94F4u;
    // 0x1d94f4: 0x0  nop
    ctx->pc = 0x1d94f4u;
    // NOP
label_1d94f8:
    // 0x1d94f8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D94F8u;
    {
        const bool branch_taken_0x1d94f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D94FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D94F8u;
            // 0x1d94fc: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d94f8) {
            ctx->pc = 0x1D9508u;
            goto label_1d9508;
        }
    }
    ctx->pc = 0x1D9500u;
label_1d9500:
    // 0x1d9500: 0x1000005b  b           . + 4 + (0x5B << 2)
    ctx->pc = 0x1D9500u;
    {
        const bool branch_taken_0x1d9500 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9500u;
            // 0x1d9504: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9500) {
            ctx->pc = 0x1D9670u;
            goto label_1d9670;
        }
    }
    ctx->pc = 0x1D9508u;
label_1d9508:
    // 0x1d9508: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d9508u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1d950c: 0x80c50000  lb          $a1, 0x0($a2)
    ctx->pc = 0x1d950cu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1d9510: 0x14a0ffe7  bnez        $a1, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1D9510u;
    {
        const bool branch_taken_0x1d9510 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d9510) {
            ctx->pc = 0x1D94B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d94b0;
        }
    }
    ctx->pc = 0x1D9518u;
label_1d9518:
    // 0x1d9518: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1d9518u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d951c: 0xc040de0  jal         func_103780
    ctx->pc = 0x1D951Cu;
    SET_GPR_U32(ctx, 31, 0x1D9524u);
    ctx->pc = 0x1D9520u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D951Cu;
            // 0x1d9520: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9524u; }
        if (ctx->pc != 0x1D9524u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9524u; }
        if (ctx->pc != 0x1D9524u) { return; }
    }
    ctx->pc = 0x1D9524u;
label_1d9524:
    // 0x1d9524: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9524u;
    {
        const bool branch_taken_0x1d9524 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9524u;
            // 0x1d9528: 0x305200ff  andi        $s2, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9524) {
            ctx->pc = 0x1D9538u;
            goto label_1d9538;
        }
    }
    ctx->pc = 0x1D952Cu;
    // 0x1d952c: 0x0  nop
    ctx->pc = 0x1d952cu;
    // NOP
label_1d9530:
    // 0x1d9530: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d9530u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d9534: 0x0  nop
    ctx->pc = 0x1d9534u;
    // NOP
label_1d9538:
    // 0x1d9538: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1D9538u;
    SET_GPR_U32(ctx, 31, 0x1D9540u);
    ctx->pc = 0x1D953Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9538u;
            // 0x1d953c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9540u; }
        if (ctx->pc != 0x1D9540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9540u; }
        if (ctx->pc != 0x1D9540u) { return; }
    }
    ctx->pc = 0x1D9540u;
label_1d9540:
    // 0x1d9540: 0x262082b  sltu        $at, $s3, $v0
    ctx->pc = 0x1d9540u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d9544: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9544u;
    {
        const bool branch_taken_0x1d9544 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9544u;
            // 0x1d9548: 0x2931821  addu        $v1, $s4, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9544) {
            ctx->pc = 0x1D9560u;
            goto label_1d9560;
        }
    }
    ctx->pc = 0x1D954Cu;
    // 0x1d954c: 0x2402002e  addiu       $v0, $zero, 0x2E
    ctx->pc = 0x1d954cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1d9550: 0x80630000  lb          $v1, 0x0($v1)
    ctx->pc = 0x1d9550u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d9554: 0x1462fff6  bne         $v1, $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1D9554u;
    {
        const bool branch_taken_0x1d9554 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9554) {
            ctx->pc = 0x1D9530u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9530;
        }
    }
    ctx->pc = 0x1D955Cu;
    // 0x1d955c: 0x0  nop
    ctx->pc = 0x1d955cu;
    // NOP
label_1d9560:
    // 0x1d9560: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1D9560u;
    SET_GPR_U32(ctx, 31, 0x1D9568u);
    ctx->pc = 0x1D9564u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9560u;
            // 0x1d9564: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9568u; }
        if (ctx->pc != 0x1D9568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9568u; }
        if (ctx->pc != 0x1D9568u) { return; }
    }
    ctx->pc = 0x1D9568u;
label_1d9568:
    // 0x1d9568: 0x262082b  sltu        $at, $s3, $v0
    ctx->pc = 0x1d9568u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d956c: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D956Cu;
    {
        const bool branch_taken_0x1d956c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d956c) {
            ctx->pc = 0x1D9578u;
            goto label_1d9578;
        }
    }
    ctx->pc = 0x1D9574u;
    // 0x1d9574: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d9574u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1d9578:
    // 0x1d9578: 0xc040de0  jal         func_103780
    ctx->pc = 0x1D9578u;
    SET_GPR_U32(ctx, 31, 0x1D9580u);
    ctx->pc = 0x1D957Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9578u;
            // 0x1d957c: 0x2932021  addu        $a0, $s4, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9580u; }
        if (ctx->pc != 0x1D9580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9580u; }
        if (ctx->pc != 0x1D9580u) { return; }
    }
    ctx->pc = 0x1D9580u;
label_1d9580:
    // 0x1d9580: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9580u;
    {
        const bool branch_taken_0x1d9580 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9580u;
            // 0x1d9584: 0x305100ff  andi        $s1, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9580) {
            ctx->pc = 0x1D9590u;
            goto label_1d9590;
        }
    }
    ctx->pc = 0x1D9588u;
label_1d9588:
    // 0x1d9588: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d9588u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d958c: 0x0  nop
    ctx->pc = 0x1d958cu;
    // NOP
label_1d9590:
    // 0x1d9590: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1D9590u;
    SET_GPR_U32(ctx, 31, 0x1D9598u);
    ctx->pc = 0x1D9594u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9590u;
            // 0x1d9594: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9598u; }
        if (ctx->pc != 0x1D9598u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9598u; }
        if (ctx->pc != 0x1D9598u) { return; }
    }
    ctx->pc = 0x1D9598u;
label_1d9598:
    // 0x1d9598: 0x262082b  sltu        $at, $s3, $v0
    ctx->pc = 0x1d9598u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d959c: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D959Cu;
    {
        const bool branch_taken_0x1d959c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D95A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D959Cu;
            // 0x1d95a0: 0x2931821  addu        $v1, $s4, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d959c) {
            ctx->pc = 0x1D95B8u;
            goto label_1d95b8;
        }
    }
    ctx->pc = 0x1D95A4u;
    // 0x1d95a4: 0x2402002e  addiu       $v0, $zero, 0x2E
    ctx->pc = 0x1d95a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1d95a8: 0x80630000  lb          $v1, 0x0($v1)
    ctx->pc = 0x1d95a8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d95ac: 0x1462fff6  bne         $v1, $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1D95ACu;
    {
        const bool branch_taken_0x1d95ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d95ac) {
            ctx->pc = 0x1D9588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9588;
        }
    }
    ctx->pc = 0x1D95B4u;
    // 0x1d95b4: 0x0  nop
    ctx->pc = 0x1d95b4u;
    // NOP
label_1d95b8:
    // 0x1d95b8: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1D95B8u;
    SET_GPR_U32(ctx, 31, 0x1D95C0u);
    ctx->pc = 0x1D95BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D95B8u;
            // 0x1d95bc: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D95C0u; }
        if (ctx->pc != 0x1D95C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D95C0u; }
        if (ctx->pc != 0x1D95C0u) { return; }
    }
    ctx->pc = 0x1D95C0u;
label_1d95c0:
    // 0x1d95c0: 0x262082b  sltu        $at, $s3, $v0
    ctx->pc = 0x1d95c0u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d95c4: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D95C4u;
    {
        const bool branch_taken_0x1d95c4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d95c4) {
            ctx->pc = 0x1D95D0u;
            goto label_1d95d0;
        }
    }
    ctx->pc = 0x1D95CCu;
    // 0x1d95cc: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d95ccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1d95d0:
    // 0x1d95d0: 0xc040de0  jal         func_103780
    ctx->pc = 0x1D95D0u;
    SET_GPR_U32(ctx, 31, 0x1D95D8u);
    ctx->pc = 0x1D95D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D95D0u;
            // 0x1d95d4: 0x2932021  addu        $a0, $s4, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D95D8u; }
        if (ctx->pc != 0x1D95D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D95D8u; }
        if (ctx->pc != 0x1D95D8u) { return; }
    }
    ctx->pc = 0x1D95D8u;
label_1d95d8:
    // 0x1d95d8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D95D8u;
    {
        const bool branch_taken_0x1d95d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D95DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D95D8u;
            // 0x1d95dc: 0x305000ff  andi        $s0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d95d8) {
            ctx->pc = 0x1D95E8u;
            goto label_1d95e8;
        }
    }
    ctx->pc = 0x1D95E0u;
label_1d95e0:
    // 0x1d95e0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d95e0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d95e4: 0x0  nop
    ctx->pc = 0x1d95e4u;
    // NOP
label_1d95e8:
    // 0x1d95e8: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1D95E8u;
    SET_GPR_U32(ctx, 31, 0x1D95F0u);
    ctx->pc = 0x1D95ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D95E8u;
            // 0x1d95ec: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D95F0u; }
        if (ctx->pc != 0x1D95F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D95F0u; }
        if (ctx->pc != 0x1D95F0u) { return; }
    }
    ctx->pc = 0x1D95F0u;
label_1d95f0:
    // 0x1d95f0: 0x262082b  sltu        $at, $s3, $v0
    ctx->pc = 0x1d95f0u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d95f4: 0x10200006  beqz        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D95F4u;
    {
        const bool branch_taken_0x1d95f4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D95F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D95F4u;
            // 0x1d95f8: 0x2931821  addu        $v1, $s4, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d95f4) {
            ctx->pc = 0x1D9610u;
            goto label_1d9610;
        }
    }
    ctx->pc = 0x1D95FCu;
    // 0x1d95fc: 0x2402002e  addiu       $v0, $zero, 0x2E
    ctx->pc = 0x1d95fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1d9600: 0x80630000  lb          $v1, 0x0($v1)
    ctx->pc = 0x1d9600u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d9604: 0x1462fff6  bne         $v1, $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1D9604u;
    {
        const bool branch_taken_0x1d9604 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9604) {
            ctx->pc = 0x1D95E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d95e0;
        }
    }
    ctx->pc = 0x1D960Cu;
    // 0x1d960c: 0x0  nop
    ctx->pc = 0x1d960cu;
    // NOP
label_1d9610:
    // 0x1d9610: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1D9610u;
    SET_GPR_U32(ctx, 31, 0x1D9618u);
    ctx->pc = 0x1D9614u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9610u;
            // 0x1d9614: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9618u; }
        if (ctx->pc != 0x1D9618u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9618u; }
        if (ctx->pc != 0x1D9618u) { return; }
    }
    ctx->pc = 0x1D9618u;
label_1d9618:
    // 0x1d9618: 0x262082b  sltu        $at, $s3, $v0
    ctx->pc = 0x1d9618u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d961c: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1D961Cu;
    {
        const bool branch_taken_0x1d961c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d961c) {
            ctx->pc = 0x1D9628u;
            goto label_1d9628;
        }
    }
    ctx->pc = 0x1D9624u;
    // 0x1d9624: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1d9624u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1d9628:
    // 0x1d9628: 0xc040de0  jal         func_103780
    ctx->pc = 0x1D9628u;
    SET_GPR_U32(ctx, 31, 0x1D9630u);
    ctx->pc = 0x1D962Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9628u;
            // 0x1d962c: 0x2932021  addu        $a0, $s4, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103780u;
    if (runtime->hasFunction(0x103780u)) {
        auto targetFn = runtime->lookupFunction(0x103780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9630u; }
        if (ctx->pc != 0x1D9630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103780_0x103780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9630u; }
        if (ctx->pc != 0x1D9630u) { return; }
    }
    ctx->pc = 0x1D9630u;
label_1d9630:
    // 0x1d9630: 0x322300ff  andi        $v1, $s1, 0xFF
    ctx->pc = 0x1d9630u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d9634: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1d9634u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1d9638: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1d9638u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1d963c: 0x324600ff  andi        $a2, $s2, 0xFF
    ctx->pc = 0x1d963cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1d9640: 0x3085ff00  andi        $a1, $a0, 0xFF00
    ctx->pc = 0x1d9640u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1d9644: 0x320300ff  andi        $v1, $s0, 0xFF
    ctx->pc = 0x1d9644u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)255);
    // 0x1d9648: 0x32400  sll         $a0, $v1, 16
    ctx->pc = 0x1d9648u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1d964c: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x1d964cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1d9650: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1d9650u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1d9654: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1d9654u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1d9658: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x1d9658u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1d965c: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1d965cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1d9660: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1d9660u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1d9664: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1d9664u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1d9668: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1d9668u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1d966c: 0x0  nop
    ctx->pc = 0x1d966cu;
    // NOP
label_1d9670:
    // 0x1d9670: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d9670u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d9674: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d9674u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d9678: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d9678u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d967c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d967cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d9680: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d9680u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9684: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9684u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9688: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D968Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9688u;
            // 0x1d968c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9690u;
    // 0x1d9690: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x1d9690u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1d9694: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1d9694u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1d9698: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1d9698u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1d969c: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x1d969cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x1d96a0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1d96a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1d96a4: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1d96a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1d96a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D96A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D96ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96A8u;
            // 0x1d96ac: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D96B0u;
    // 0x1d96b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d96b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d96b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d96b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d96b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d96b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d96bc: 0xc07651c  jal         func_1D9470
    ctx->pc = 0x1D96BCu;
    SET_GPR_U32(ctx, 31, 0x1D96C4u);
    ctx->pc = 0x1D96C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96BCu;
            // 0x1d96c0: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9470u;
    goto label_1d9470;
    ctx->pc = 0x1D96C4u;
label_1d96c4:
    // 0x1d96c4: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1d96c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1d96c8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1d96c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d96cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d96ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d96d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d96d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d96d4: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1d96d4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d96d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D96D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D96DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96D8u;
            // 0x1d96dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D96E0u;
    // 0x1d96e0: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d96e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d96e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D96E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D96E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96E4u;
            // 0x1d96e8: 0x24428c88  addiu       $v0, $v0, -0x7378 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937736));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D96ECu;
    // 0x1d96ec: 0x0  nop
    ctx->pc = 0x1d96ecu;
    // NOP
    // 0x1d96f0: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d96f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d96f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D96F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D96F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D96F4u;
            // 0x1d96f8: 0x24428c80  addiu       $v0, $v0, -0x7380 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937728));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D96FCu;
    // 0x1d96fc: 0x0  nop
    ctx->pc = 0x1d96fcu;
    // NOP
    // 0x1d9700: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d9700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d9704: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d9704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d9708: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d9708u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d970c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d970cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d9710: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d9710u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9714: 0x6000004  bltz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9714u;
    {
        const bool branch_taken_0x1d9714 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x1D9718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9714u;
            // 0x1d9718: 0x2a020003  slti        $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9714) {
            ctx->pc = 0x1D9728u;
            goto label_1d9728;
        }
    }
    ctx->pc = 0x1D971Cu;
    // 0x1d971c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D971Cu;
    {
        const bool branch_taken_0x1d971c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d971c) {
            ctx->pc = 0x1D9730u;
            goto label_1d9730;
        }
    }
    ctx->pc = 0x1D9724u;
    // 0x1d9724: 0x0  nop
    ctx->pc = 0x1d9724u;
    // NOP
label_1d9728:
    // 0x1d9728: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1D9728u;
    {
        const bool branch_taken_0x1d9728 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D972Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9728u;
            // 0x1d972c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9728) {
            ctx->pc = 0x1D97C0u;
            goto label_1d97c0;
        }
    }
    ctx->pc = 0x1D9730u;
label_1d9730:
    // 0x1d9730: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9730u;
    SET_GPR_U32(ctx, 31, 0x1D9738u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9738u; }
        if (ctx->pc != 0x1D9738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9738u; }
        if (ctx->pc != 0x1D9738u) { return; }
    }
    ctx->pc = 0x1D9738u;
label_1d9738:
    // 0x1d9738: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9738u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d973c: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x1d973cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d9740: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d9744: 0x508821  addu        $s1, $v0, $s0
    ctx->pc = 0x1d9744u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d9748: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1d9748u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d974c: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1d974cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1d9750: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D9750u;
    {
        const bool branch_taken_0x1d9750 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D9754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9750u;
            // 0x1d9754: 0x3c020035  lui         $v0, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9750) {
            ctx->pc = 0x1D9778u;
            goto label_1d9778;
        }
    }
    ctx->pc = 0x1D9758u;
    // 0x1d9758: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d9758u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d975c: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d975cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d9760: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d9760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d9764: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9764u;
    SET_GPR_U32(ctx, 31, 0x1D976Cu);
    ctx->pc = 0x1D9768u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9764u;
            // 0x1d9768: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D976Cu; }
        if (ctx->pc != 0x1D976Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D976Cu; }
        if (ctx->pc != 0x1D976Cu) { return; }
    }
    ctx->pc = 0x1D976Cu;
label_1d976c:
    // 0x1d976c: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D976Cu;
    {
        const bool branch_taken_0x1d976c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D976Cu;
            // 0x1d9770: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d976c) {
            ctx->pc = 0x1D97C0u;
            goto label_1d97c0;
        }
    }
    ctx->pc = 0x1D9774u;
    // 0x1d9774: 0x0  nop
    ctx->pc = 0x1d9774u;
    // NOP
label_1d9778:
    // 0x1d9778: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9778u;
    SET_GPR_U32(ctx, 31, 0x1D9780u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9780u; }
        if (ctx->pc != 0x1D9780u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9780u; }
        if (ctx->pc != 0x1D9780u) { return; }
    }
    ctx->pc = 0x1D9780u;
label_1d9780:
    // 0x1d9780: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1d9780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d9784: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D9784u;
    {
        const bool branch_taken_0x1d9784 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D9788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9784u;
            // 0x1d9788: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9784) {
            ctx->pc = 0x1D9798u;
            goto label_1d9798;
        }
    }
    ctx->pc = 0x1D978Cu;
    // 0x1d978c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D978Cu;
    {
        const bool branch_taken_0x1d978c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d978c) {
            ctx->pc = 0x1D97C0u;
            goto label_1d97c0;
        }
    }
    ctx->pc = 0x1D9794u;
    // 0x1d9794: 0x0  nop
    ctx->pc = 0x1d9794u;
    // NOP
label_1d9798:
    // 0x1d9798: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9798u;
    SET_GPR_U32(ctx, 31, 0x1D97A0u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D97A0u; }
        if (ctx->pc != 0x1D97A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D97A0u; }
        if (ctx->pc != 0x1D97A0u) { return; }
    }
    ctx->pc = 0x1D97A0u;
label_1d97a0:
    // 0x1d97a0: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d97a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d97a4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d97a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d97a8: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d97a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d97ac: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d97acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d97b0: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D97B0u;
    SET_GPR_U32(ctx, 31, 0x1D97B8u);
    ctx->pc = 0x1D97B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D97B0u;
            // 0x1d97b4: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D97B8u; }
        if (ctx->pc != 0x1D97B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D97B8u; }
        if (ctx->pc != 0x1D97B8u) { return; }
    }
    ctx->pc = 0x1D97B8u;
label_1d97b8:
    // 0x1d97b8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d97b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d97bc: 0x0  nop
    ctx->pc = 0x1d97bcu;
    // NOP
label_1d97c0:
    // 0x1d97c0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d97c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d97c4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d97c4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d97c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d97c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d97cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D97CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D97D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D97CCu;
            // 0x1d97d0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D97D4u;
    // 0x1d97d4: 0x0  nop
    ctx->pc = 0x1d97d4u;
    // NOP
    // 0x1d97d8: 0x0  nop
    ctx->pc = 0x1d97d8u;
    // NOP
    // 0x1d97dc: 0x0  nop
    ctx->pc = 0x1d97dcu;
    // NOP
    // 0x1d97e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D97E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D97E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D97E0u;
            // 0x1d97e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D97E8u;
    // 0x1d97e8: 0x0  nop
    ctx->pc = 0x1d97e8u;
    // NOP
    // 0x1d97ec: 0x0  nop
    ctx->pc = 0x1d97ecu;
    // NOP
    // 0x1d97f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d97f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d97f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d97f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d97f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d97f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d97fc: 0x10a20006  beq         $a1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D97FCu;
    {
        const bool branch_taken_0x1d97fc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D97FCu;
            // 0x1d9800: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d97fc) {
            ctx->pc = 0x1D9818u;
            goto label_1d9818;
        }
    }
    ctx->pc = 0x1D9804u;
    // 0x1d9804: 0x24030016  addiu       $v1, $zero, 0x16
    ctx->pc = 0x1d9804u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1d9808: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9808u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d980c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d980cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9810: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1D9810u;
    {
        const bool branch_taken_0x1d9810 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9810u;
            // 0x1d9814: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9810) {
            ctx->pc = 0x1D9890u;
            goto label_1d9890;
        }
    }
    ctx->pc = 0x1D9818u;
label_1d9818:
    // 0x1d9818: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9818u;
    SET_GPR_U32(ctx, 31, 0x1D9820u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9820u; }
        if (ctx->pc != 0x1D9820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9820u; }
        if (ctx->pc != 0x1D9820u) { return; }
    }
    ctx->pc = 0x1D9820u;
label_1d9820:
    // 0x1d9820: 0x3c040035  lui         $a0, 0x35
    ctx->pc = 0x1d9820u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)53 << 16));
    // 0x1d9824: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1d9824u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9828: 0x24848c90  addiu       $a0, $a0, -0x7370
    ctx->pc = 0x1d9828u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937744));
    // 0x1d982c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d982cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1d9830:
    // 0x1d9830: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1d9830u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d9834: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9834u;
    {
        const bool branch_taken_0x1d9834 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d9834) {
            ctx->pc = 0x1D9850u;
            goto label_1d9850;
        }
    }
    ctx->pc = 0x1D983Cu;
    // 0x1d983c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d983cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d9840: 0x2a020003  slti        $v0, $s0, 0x3
    ctx->pc = 0x1d9840u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d9844: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D9844u;
    {
        const bool branch_taken_0x1d9844 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9844u;
            // 0x1d9848: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9844) {
            ctx->pc = 0x1D9830u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9830;
        }
    }
    ctx->pc = 0x1D984Cu;
    // 0x1d984c: 0x0  nop
    ctx->pc = 0x1d984cu;
    // NOP
label_1d9850:
    // 0x1d9850: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1d9850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d9854: 0x16020006  bne         $s0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D9854u;
    {
        const bool branch_taken_0x1d9854 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D9858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9854u;
            // 0x1d9858: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9854) {
            ctx->pc = 0x1D9870u;
            goto label_1d9870;
        }
    }
    ctx->pc = 0x1D985Cu;
    // 0x1d985c: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d985cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9860: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9860u;
    SET_GPR_U32(ctx, 31, 0x1D9868u);
    ctx->pc = 0x1D9864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9860u;
            // 0x1d9864: 0xac228c88  sw          $v0, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9868u; }
        if (ctx->pc != 0x1D9868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9868u; }
        if (ctx->pc != 0x1D9868u) { return; }
    }
    ctx->pc = 0x1D9868u;
label_1d9868:
    // 0x1d9868: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1D9868u;
    {
        const bool branch_taken_0x1d9868 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D986Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9868u;
            // 0x1d986c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9868) {
            ctx->pc = 0x1D9890u;
            goto label_1d9890;
        }
    }
    ctx->pc = 0x1D9870u;
label_1d9870:
    // 0x1d9870: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9870u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9874: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1d9874u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d9878: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9878u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d987c: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x1d987cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1d9880: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d9880u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d9884: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9884u;
    SET_GPR_U32(ctx, 31, 0x1D988Cu);
    ctx->pc = 0x1D9888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9884u;
            // 0x1d9888: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D988Cu; }
        if (ctx->pc != 0x1D988Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D988Cu; }
        if (ctx->pc != 0x1D988Cu) { return; }
    }
    ctx->pc = 0x1D988Cu;
label_1d988c:
    // 0x1d988c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d988cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1d9890:
    // 0x1d9890: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d9890u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9894: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9894u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9898: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D989Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9898u;
            // 0x1d989c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D98A0u;
    // 0x1d98a0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1d98a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d98a4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d98a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d98a8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d98a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d98ac: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d98acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d98b0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d98b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d98b4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d98b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d98b8: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D98B8u;
    {
        const bool branch_taken_0x1d98b8 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1D98BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D98B8u;
            // 0x1d98bc: 0xa7a0005e  sh          $zero, 0x5E($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 94), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d98b8) {
            ctx->pc = 0x1D98D0u;
            goto label_1d98d0;
        }
    }
    ctx->pc = 0x1D98C0u;
    // 0x1d98c0: 0x28820003  slti        $v0, $a0, 0x3
    ctx->pc = 0x1d98c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d98c4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D98C4u;
    {
        const bool branch_taken_0x1d98c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d98c4) {
            ctx->pc = 0x1D98E8u;
            goto label_1d98e8;
        }
    }
    ctx->pc = 0x1D98CCu;
    // 0x1d98cc: 0x0  nop
    ctx->pc = 0x1d98ccu;
    // NOP
label_1d98d0:
    // 0x1d98d0: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1d98d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d98d4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d98d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d98d8: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1d98d8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1d98dc: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x1D98DCu;
    {
        const bool branch_taken_0x1d98dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D98E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D98DCu;
            // 0x1d98e0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d98dc) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D98E4u;
    // 0x1d98e4: 0x0  nop
    ctx->pc = 0x1d98e4u;
    // NOP
label_1d98e8:
    // 0x1d98e8: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1d98e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1d98ec: 0x48080  sll         $s0, $a0, 2
    ctx->pc = 0x1d98ecu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d98f0: 0x24638c90  addiu       $v1, $v1, -0x7370
    ctx->pc = 0x1d98f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937744));
    // 0x1d98f4: 0x708821  addu        $s1, $v1, $s0
    ctx->pc = 0x1d98f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1d98f8: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1d98f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1d98fc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1d98fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d9900: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9900u;
    {
        const bool branch_taken_0x1d9900 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9900u;
            // 0x1d9904: 0x24030009  addiu       $v1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9900) {
            ctx->pc = 0x1D9918u;
            goto label_1d9918;
        }
    }
    ctx->pc = 0x1D9908u;
    // 0x1d9908: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9908u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d990c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d990cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9910: 0x1000005b  b           . + 4 + (0x5B << 2)
    ctx->pc = 0x1D9910u;
    {
        const bool branch_taken_0x1d9910 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9910u;
            // 0x1d9914: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9910) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D9918u;
label_1d9918:
    // 0x1d9918: 0x8ca40004  lw          $a0, 0x4($a1)
    ctx->pc = 0x1d9918u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1d991c: 0x94a50002  lhu         $a1, 0x2($a1)
    ctx->pc = 0x1d991cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1d9920: 0xc075ec0  jal         func_1D7B00
    ctx->pc = 0x1D9920u;
    SET_GPR_U32(ctx, 31, 0x1D9928u);
    ctx->pc = 0x1D9924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9920u;
            // 0x1d9924: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7B00u;
    if (runtime->hasFunction(0x1D7B00u)) {
        auto targetFn = runtime->lookupFunction(0x1D7B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9928u; }
        if (ctx->pc != 0x1D9928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7B00_0x1d7b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9928u; }
        if (ctx->pc != 0x1D9928u) { return; }
    }
    ctx->pc = 0x1D9928u;
label_1d9928:
    // 0x1d9928: 0x2943c  dsll32      $s2, $v0, 16
    ctx->pc = 0x1d9928u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d992c: 0x12943f  dsra32      $s2, $s2, 16
    ctx->pc = 0x1d992cu;
    SET_GPR_S64(ctx, 18, GPR_S64(ctx, 18) >> (32 + 16));
    // 0x1d9930: 0x6410005  bgez        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9930u;
    {
        const bool branch_taken_0x1d9930 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x1D9934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9930u;
            // 0x1d9934: 0x24030076  addiu       $v1, $zero, 0x76 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 118));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9930) {
            ctx->pc = 0x1D9948u;
            goto label_1d9948;
        }
    }
    ctx->pc = 0x1D9938u;
    // 0x1d9938: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9938u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d993c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d993cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9940: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1D9940u;
    {
        const bool branch_taken_0x1d9940 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9940u;
            // 0x1d9944: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9940) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D9948u;
label_1d9948:
    // 0x1d9948: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9948u;
    SET_GPR_U32(ctx, 31, 0x1D9950u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9950u; }
        if (ctx->pc != 0x1D9950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9950u; }
        if (ctx->pc != 0x1D9950u) { return; }
    }
    ctx->pc = 0x1D9950u;
label_1d9950:
    // 0x1d9950: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9950u;
    SET_GPR_U32(ctx, 31, 0x1D9958u);
    ctx->pc = 0x1D9954u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9950u;
            // 0x1d9954: 0xae320000  sw          $s2, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9958u; }
        if (ctx->pc != 0x1D9958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9958u; }
        if (ctx->pc != 0x1D9958u) { return; }
    }
    ctx->pc = 0x1D9958u;
label_1d9958:
    // 0x1d9958: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1d9958u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d995c: 0x260182d  daddu       $v1, $s3, $zero
    ctx->pc = 0x1d995cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9960: 0x26620001  addiu       $v0, $s3, 0x1
    ctx->pc = 0x1d9960u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d9964: 0x29c3c  dsll32      $s3, $v0, 16
    ctx->pc = 0x1d9964u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9968: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1d9968u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d996c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d996cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9970: 0x284141a0  slti        $at, $v0, 0x41A0
    ctx->pc = 0x1d9970u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1d9974: 0x10200038  beqz        $at, . + 4 + (0x38 << 2)
    ctx->pc = 0x1D9974u;
    {
        const bool branch_taken_0x1d9974 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9974u;
            // 0x1d9978: 0x139c3f  dsra32      $s3, $s3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9974) {
            ctx->pc = 0x1D9A58u;
            goto label_1d9a58;
        }
    }
    ctx->pc = 0x1D997Cu;
    // 0x1d997c: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1d997cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1d9980: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9980u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9984: 0x24638c70  addiu       $v1, $v1, -0x7390
    ctx->pc = 0x1d9984u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937712));
    // 0x1d9988: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d998c: 0x709021  addu        $s2, $v1, $s0
    ctx->pc = 0x1d998cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1d9990: 0x508821  addu        $s1, $v0, $s0
    ctx->pc = 0x1d9990u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d9994: 0x0  nop
    ctx->pc = 0x1d9994u;
    // NOP
label_1d9998:
    // 0x1d9998: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9998u;
    SET_GPR_U32(ctx, 31, 0x1D99A0u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99A0u; }
        if (ctx->pc != 0x1D99A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99A0u; }
        if (ctx->pc != 0x1D99A0u) { return; }
    }
    ctx->pc = 0x1D99A0u;
label_1d99a0:
    // 0x1d99a0: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1d99a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1d99a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d99a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d99a8: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D99A8u;
    {
        const bool branch_taken_0x1d99a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D99ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99A8u;
            // 0x1d99ac: 0x3c020035  lui         $v0, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d99a8) {
            ctx->pc = 0x1D99D8u;
            goto label_1d99d8;
        }
    }
    ctx->pc = 0x1D99B0u;
    // 0x1d99b0: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d99b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d99b4: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d99b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d99b8: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d99b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d99bc: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x1d99bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d99c0: 0x24020071  addiu       $v0, $zero, 0x71
    ctx->pc = 0x1d99c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
    // 0x1d99c4: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1d99c4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1d99c8: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D99C8u;
    SET_GPR_U32(ctx, 31, 0x1D99D0u);
    ctx->pc = 0x1D99CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99C8u;
            // 0x1d99cc: 0xac228c88  sw          $v0, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99D0u; }
        if (ctx->pc != 0x1D99D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99D0u; }
        if (ctx->pc != 0x1D99D0u) { return; }
    }
    ctx->pc = 0x1D99D0u;
label_1d99d0:
    // 0x1d99d0: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1D99D0u;
    {
        const bool branch_taken_0x1d99d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D99D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99D0u;
            // 0x1d99d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d99d0) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D99D8u;
label_1d99d8:
    // 0x1d99d8: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D99D8u;
    SET_GPR_U32(ctx, 31, 0x1D99E0u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99E0u; }
        if (ctx->pc != 0x1D99E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99E0u; }
        if (ctx->pc != 0x1D99E0u) { return; }
    }
    ctx->pc = 0x1D99E0u;
label_1d99e0:
    // 0x1d99e0: 0x86240000  lh          $a0, 0x0($s1)
    ctx->pc = 0x1d99e0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d99e4: 0x27a5005e  addiu       $a1, $sp, 0x5E
    ctx->pc = 0x1d99e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 94));
    // 0x1d99e8: 0x27a6005c  addiu       $a2, $sp, 0x5C
    ctx->pc = 0x1d99e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
    // 0x1d99ec: 0xc075f48  jal         func_1D7D20
    ctx->pc = 0x1D99ECu;
    SET_GPR_U32(ctx, 31, 0x1D99F4u);
    ctx->pc = 0x1D99F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99ECu;
            // 0x1d99f0: 0x27a7005a  addiu       $a3, $sp, 0x5A (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 90));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7D20u;
    if (runtime->hasFunction(0x1D7D20u)) {
        auto targetFn = runtime->lookupFunction(0x1D7D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99F4u; }
        if (ctx->pc != 0x1D99F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7D20_0x1d7d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99F4u; }
        if (ctx->pc != 0x1D99F4u) { return; }
    }
    ctx->pc = 0x1D99F4u;
label_1d99f4:
    // 0x1d99f4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d99f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d99f8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d99f8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d99fc: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D99FCu;
    {
        const bool branch_taken_0x1d99fc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D9A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99FCu;
            // 0x1d9a00: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d99fc) {
            ctx->pc = 0x1D9A18u;
            goto label_1d9a18;
        }
    }
    ctx->pc = 0x1D9A04u;
    // 0x1d9a04: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9a04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9a08: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9a0c: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1D9A0Cu;
    {
        const bool branch_taken_0x1d9a0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A0Cu;
            // 0x1d9a10: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a0c) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D9A14u;
    // 0x1d9a14: 0x0  nop
    ctx->pc = 0x1d9a14u;
    // NOP
label_1d9a18:
    // 0x1d9a18: 0x87a3005e  lh          $v1, 0x5E($sp)
    ctx->pc = 0x1d9a18u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 94)));
    // 0x1d9a1c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1d9a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d9a20: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9A20u;
    {
        const bool branch_taken_0x1d9a20 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A20u;
            // 0x1d9a24: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a20) {
            ctx->pc = 0x1D9A30u;
            goto label_1d9a30;
        }
    }
    ctx->pc = 0x1D9A28u;
    // 0x1d9a28: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D9A28u;
    {
        const bool branch_taken_0x1d9a28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9a28) {
            ctx->pc = 0x1D9A58u;
            goto label_1d9a58;
        }
    }
    ctx->pc = 0x1D9A30u;
label_1d9a30:
    // 0x1d9a30: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1D9A30u;
    SET_GPR_U32(ctx, 31, 0x1D9A38u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9A38u; }
        if (ctx->pc != 0x1D9A38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9A38u; }
        if (ctx->pc != 0x1D9A38u) { return; }
    }
    ctx->pc = 0x1D9A38u;
label_1d9a38:
    // 0x1d9a38: 0x260182d  daddu       $v1, $s3, $zero
    ctx->pc = 0x1d9a38u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9a3c: 0x26620001  addiu       $v0, $s3, 0x1
    ctx->pc = 0x1d9a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d9a40: 0x29c3c  dsll32      $s3, $v0, 16
    ctx->pc = 0x1d9a40u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9a44: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1d9a44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d9a48: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9a48u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9a4c: 0x284241a0  slti        $v0, $v0, 0x41A0
    ctx->pc = 0x1d9a4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1d9a50: 0x1440ffd1  bnez        $v0, . + 4 + (-0x2F << 2)
    ctx->pc = 0x1D9A50u;
    {
        const bool branch_taken_0x1d9a50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A50u;
            // 0x1d9a54: 0x139c3f  dsra32      $s3, $s3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a50) {
            ctx->pc = 0x1D9998u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9998;
        }
    }
    ctx->pc = 0x1D9A58u;
label_1d9a58:
    // 0x1d9a58: 0x87a3005e  lh          $v1, 0x5E($sp)
    ctx->pc = 0x1d9a58u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 94)));
    // 0x1d9a5c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1d9a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d9a60: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9A60u;
    {
        const bool branch_taken_0x1d9a60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A60u;
            // 0x1d9a64: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a60) {
            ctx->pc = 0x1D9A78u;
            goto label_1d9a78;
        }
    }
    ctx->pc = 0x1D9A68u;
    // 0x1d9a68: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9a68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9a6c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9a70: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9A70u;
    {
        const bool branch_taken_0x1d9a70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A70u;
            // 0x1d9a74: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a70) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D9A78u;
label_1d9a78:
    // 0x1d9a78: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d9a78u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9a7c: 0x0  nop
    ctx->pc = 0x1d9a7cu;
    // NOP
label_1d9a80:
    // 0x1d9a80: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d9a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d9a84: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d9a84u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d9a88: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d9a88u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d9a8c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d9a8cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9a90: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9a90u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9a94: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9A94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D9A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A94u;
            // 0x1d9a98: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D9470u: goto label_1d9470;
            case 0x1D94B0u: goto label_1d94b0;
            case 0x1D94D8u: goto label_1d94d8;
            case 0x1D94F8u: goto label_1d94f8;
            case 0x1D9500u: goto label_1d9500;
            case 0x1D9508u: goto label_1d9508;
            case 0x1D9518u: goto label_1d9518;
            case 0x1D9524u: goto label_1d9524;
            case 0x1D9530u: goto label_1d9530;
            case 0x1D9538u: goto label_1d9538;
            case 0x1D9540u: goto label_1d9540;
            case 0x1D9560u: goto label_1d9560;
            case 0x1D9568u: goto label_1d9568;
            case 0x1D9578u: goto label_1d9578;
            case 0x1D9580u: goto label_1d9580;
            case 0x1D9588u: goto label_1d9588;
            case 0x1D9590u: goto label_1d9590;
            case 0x1D9598u: goto label_1d9598;
            case 0x1D95B8u: goto label_1d95b8;
            case 0x1D95C0u: goto label_1d95c0;
            case 0x1D95D0u: goto label_1d95d0;
            case 0x1D95D8u: goto label_1d95d8;
            case 0x1D95E0u: goto label_1d95e0;
            case 0x1D95E8u: goto label_1d95e8;
            case 0x1D95F0u: goto label_1d95f0;
            case 0x1D9610u: goto label_1d9610;
            case 0x1D9618u: goto label_1d9618;
            case 0x1D9628u: goto label_1d9628;
            case 0x1D9630u: goto label_1d9630;
            case 0x1D9670u: goto label_1d9670;
            case 0x1D96C4u: goto label_1d96c4;
            case 0x1D9728u: goto label_1d9728;
            case 0x1D9730u: goto label_1d9730;
            case 0x1D9738u: goto label_1d9738;
            case 0x1D976Cu: goto label_1d976c;
            case 0x1D9778u: goto label_1d9778;
            case 0x1D9780u: goto label_1d9780;
            case 0x1D9798u: goto label_1d9798;
            case 0x1D97A0u: goto label_1d97a0;
            case 0x1D97B8u: goto label_1d97b8;
            case 0x1D97C0u: goto label_1d97c0;
            case 0x1D9818u: goto label_1d9818;
            case 0x1D9820u: goto label_1d9820;
            case 0x1D9830u: goto label_1d9830;
            case 0x1D9850u: goto label_1d9850;
            case 0x1D9868u: goto label_1d9868;
            case 0x1D9870u: goto label_1d9870;
            case 0x1D988Cu: goto label_1d988c;
            case 0x1D9890u: goto label_1d9890;
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9A9Cu;
    // 0x1d9a9c: 0x0  nop
    ctx->pc = 0x1d9a9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
