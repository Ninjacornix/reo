#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE460
// Address: 0x1be460 - 0x1be6d0
void sub_001BE460_0x1be460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE460_0x1be460");
#endif

    switch (ctx->pc) {
        case 0x1be488u: goto label_1be488;
        case 0x1be490u: goto label_1be490;
        case 0x1be4a4u: goto label_1be4a4;
        case 0x1be638u: goto label_1be638;
        case 0x1be640u: goto label_1be640;
        case 0x1be674u: goto label_1be674;
        default: break;
    }

    ctx->pc = 0x1be460u;

    // 0x1be460: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1be460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1be464: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1be464u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1be468: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1be468u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1be46c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1be46cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1be470: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1be470u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1be474: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1be474u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1be478: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1be478u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1be47c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1be47cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1be480: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BE480u;
    SET_GPR_U32(ctx, 31, 0x1BE488u);
    ctx->pc = 0x1BE484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE480u;
            // 0x1be484: 0x24a504b8  addiu       $a1, $a1, 0x4B8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE488u; }
        if (ctx->pc != 0x1BE488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE488u; }
        if (ctx->pc != 0x1BE488u) { return; }
    }
    ctx->pc = 0x1BE488u;
label_1be488:
    // 0x1be488: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1BE488u;
    SET_GPR_U32(ctx, 31, 0x1BE490u);
    ctx->pc = 0x1BE48Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE488u;
            // 0x1be48c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE490u; }
        if (ctx->pc != 0x1BE490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE490u; }
        if (ctx->pc != 0x1BE490u) { return; }
    }
    ctx->pc = 0x1BE490u;
label_1be490:
    // 0x1be490: 0x2223821  addu        $a3, $s1, $v0
    ctx->pc = 0x1be490u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1be494: 0x3206ffff  andi        $a2, $s0, 0xFFFF
    ctx->pc = 0x1be494u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x1be498: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1be498u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1be49c: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1BE49Cu;
    {
        const bool branch_taken_0x1be49c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE4A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE49Cu;
            // 0x1be4a0: 0x3404ff53  ori         $a0, $zero, 0xFF53 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65363);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be49c) {
            ctx->pc = 0x1BE52Cu;
            goto label_1be52c;
        }
    }
    ctx->pc = 0x1BE4A4u;
label_1be4a4:
    // 0x1be4a4: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE4A4u;
    {
        const bool branch_taken_0x1be4a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BE4A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE4A4u;
            // 0x1be4a8: 0x30c5ffff  andi        $a1, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be4a4) {
            ctx->pc = 0x1BE4B4u;
            goto label_1be4b4;
        }
    }
    ctx->pc = 0x1BE4ACu;
    // 0x1be4ac: 0x64060001  daddiu      $a2, $zero, 0x1
    ctx->pc = 0x1be4acu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)1);
    // 0x1be4b0: 0x30c5ffff  andi        $a1, $a2, 0xFFFF
    ctx->pc = 0x1be4b0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
label_1be4b4:
    // 0x1be4b4: 0x51880  sll         $v1, $a1, 2
    ctx->pc = 0x1be4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1be4b8: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1be4b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1be4bc: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1be4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1be4c0: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1be4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1be4c4: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1be4c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1be4c8: 0x64001a  div         $zero, $v1, $a0
    ctx->pc = 0x1be4c8u;
    { int32_t divisor = GPR_S32(ctx, 4);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1be4cc: 0x0  nop
    ctx->pc = 0x1be4ccu;
    // NOP
    // 0x1be4d0: 0x0  nop
    ctx->pc = 0x1be4d0u;
    // NOP
    // 0x1be4d4: 0x1810  mfhi        $v1
    ctx->pc = 0x1be4d4u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1be4d8: 0x3066ffff  andi        $a2, $v1, 0xFFFF
    ctx->pc = 0x1be4d8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1be4dc: 0x30c5007f  andi        $a1, $a2, 0x7F
    ctx->pc = 0x1be4dcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)127);
    // 0x1be4e0: 0x28a30030  slti        $v1, $a1, 0x30
    ctx->pc = 0x1be4e0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)48) ? 1 : 0);
    // 0x1be4e4: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BE4E4u;
    {
        const bool branch_taken_0x1be4e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BE4E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE4E4u;
            // 0x1be4e8: 0x28a30041  slti        $v1, $a1, 0x41 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)65) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be4e4) {
            ctx->pc = 0x1BE4F8u;
            goto label_1be4f8;
        }
    }
    ctx->pc = 0x1BE4ECu;
    // 0x1be4ec: 0x28a1003a  slti        $at, $a1, 0x3A
    ctx->pc = 0x1be4ecu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)58) ? 1 : 0);
    // 0x1be4f0: 0x1420000b  bnez        $at, . + 4 + (0xB << 2)
    ctx->pc = 0x1BE4F0u;
    {
        const bool branch_taken_0x1be4f0 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1be4f0) {
            ctx->pc = 0x1BE520u;
            goto label_1be520;
        }
    }
    ctx->pc = 0x1BE4F8u;
label_1be4f8:
    // 0x1be4f8: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE4F8u;
    {
        const bool branch_taken_0x1be4f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BE4FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE4F8u;
            // 0x1be4fc: 0x28a1005b  slti        $at, $a1, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)91) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be4f8) {
            ctx->pc = 0x1BE508u;
            goto label_1be508;
        }
    }
    ctx->pc = 0x1BE500u;
    // 0x1be500: 0x14200007  bnez        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BE500u;
    {
        const bool branch_taken_0x1be500 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1be500) {
            ctx->pc = 0x1BE520u;
            goto label_1be520;
        }
    }
    ctx->pc = 0x1BE508u;
label_1be508:
    // 0x1be508: 0x28a30061  slti        $v1, $a1, 0x61
    ctx->pc = 0x1be508u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)97) ? 1 : 0);
    // 0x1be50c: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BE50Cu;
    {
        const bool branch_taken_0x1be50c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BE510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE50Cu;
            // 0x1be510: 0x29030008  slti        $v1, $t0, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)8) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be50c) {
            ctx->pc = 0x1BE530u;
            goto label_1be530;
        }
    }
    ctx->pc = 0x1BE514u;
    // 0x1be514: 0x28a1007b  slti        $at, $a1, 0x7B
    ctx->pc = 0x1be514u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)123) ? 1 : 0);
    // 0x1be518: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BE518u;
    {
        const bool branch_taken_0x1be518 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1be518) {
            ctx->pc = 0x1BE52Cu;
            goto label_1be52c;
        }
    }
    ctx->pc = 0x1BE520u;
label_1be520:
    // 0x1be520: 0xa0e50000  sb          $a1, 0x0($a3)
    ctx->pc = 0x1be520u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1be524: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1be524u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1be528: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1be528u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1be52c:
    // 0x1be52c: 0x29030008  slti        $v1, $t0, 0x8
    ctx->pc = 0x1be52cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)8) ? 1 : 0);
label_1be530:
    // 0x1be530: 0x1460ffdc  bnez        $v1, . + 4 + (-0x24 << 2)
    ctx->pc = 0x1BE530u;
    {
        const bool branch_taken_0x1be530 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BE534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE530u;
            // 0x1be534: 0x30c3ffff  andi        $v1, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be530) {
            ctx->pc = 0x1BE4A4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1be4a4;
        }
    }
    ctx->pc = 0x1BE538u;
    // 0x1be538: 0xa0e00000  sb          $zero, 0x0($a3)
    ctx->pc = 0x1be538u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1be53c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1be53cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1be540: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1be540u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1be544: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1be544u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1be548: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE548u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE548u;
            // 0x1be54c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BE488u: goto label_1be488;
            case 0x1BE490u: goto label_1be490;
            case 0x1BE4A4u: goto label_1be4a4;
            case 0x1BE4B4u: goto label_1be4b4;
            case 0x1BE4F8u: goto label_1be4f8;
            case 0x1BE508u: goto label_1be508;
            case 0x1BE520u: goto label_1be520;
            case 0x1BE52Cu: goto label_1be52c;
            case 0x1BE530u: goto label_1be530;
            case 0x1BE5DCu: goto label_1be5dc;
            case 0x1BE600u: goto label_1be600;
            case 0x1BE624u: goto label_1be624;
            case 0x1BE628u: goto label_1be628;
            case 0x1BE630u: goto label_1be630;
            case 0x1BE638u: goto label_1be638;
            case 0x1BE640u: goto label_1be640;
            case 0x1BE658u: goto label_1be658;
            case 0x1BE674u: goto label_1be674;
            case 0x1BE698u: goto label_1be698;
            case 0x1BE6ACu: goto label_1be6ac;
            case 0x1BE6B4u: goto label_1be6b4;
            case 0x1BE6BCu: goto label_1be6bc;
            case 0x1BE6C0u: goto label_1be6c0;
            case 0x1BE6C4u: goto label_1be6c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE550u;
    // 0x1be550: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be550u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be554: 0xac244508  sw          $a0, 0x4508($at)
    ctx->pc = 0x1be554u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17672), GPR_U32(ctx, 4));
    // 0x1be558: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be558u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be55c: 0xa0204500  sb          $zero, 0x4500($at)
    ctx->pc = 0x1be55cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17664), (uint8_t)GPR_U32(ctx, 0));
    // 0x1be560: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be564: 0xa0204501  sb          $zero, 0x4501($at)
    ctx->pc = 0x1be564u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17665), (uint8_t)GPR_U32(ctx, 0));
    // 0x1be568: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be568u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be56c: 0xa0204502  sb          $zero, 0x4502($at)
    ctx->pc = 0x1be56cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17666), (uint8_t)GPR_U32(ctx, 0));
    // 0x1be570: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be570u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be574: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE574u;
            // 0x1be578: 0xa0204503  sb          $zero, 0x4503($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17667), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BE488u: goto label_1be488;
            case 0x1BE490u: goto label_1be490;
            case 0x1BE4A4u: goto label_1be4a4;
            case 0x1BE4B4u: goto label_1be4b4;
            case 0x1BE4F8u: goto label_1be4f8;
            case 0x1BE508u: goto label_1be508;
            case 0x1BE520u: goto label_1be520;
            case 0x1BE52Cu: goto label_1be52c;
            case 0x1BE530u: goto label_1be530;
            case 0x1BE5DCu: goto label_1be5dc;
            case 0x1BE600u: goto label_1be600;
            case 0x1BE624u: goto label_1be624;
            case 0x1BE628u: goto label_1be628;
            case 0x1BE630u: goto label_1be630;
            case 0x1BE638u: goto label_1be638;
            case 0x1BE640u: goto label_1be640;
            case 0x1BE658u: goto label_1be658;
            case 0x1BE674u: goto label_1be674;
            case 0x1BE698u: goto label_1be698;
            case 0x1BE6ACu: goto label_1be6ac;
            case 0x1BE6B4u: goto label_1be6b4;
            case 0x1BE6BCu: goto label_1be6bc;
            case 0x1BE6C0u: goto label_1be6c0;
            case 0x1BE6C4u: goto label_1be6c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE57Cu;
    // 0x1be57c: 0x0  nop
    ctx->pc = 0x1be57cu;
    // NOP
    // 0x1be580: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1be580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1be584: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be584u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be588: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1be588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1be58c: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1be58cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1be590: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1be590u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1be594: 0x90244500  lbu         $a0, 0x4500($at)
    ctx->pc = 0x1be594u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17664)));
    // 0x1be598: 0x3c100032  lui         $s0, 0x32
    ctx->pc = 0x1be598u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)50 << 16));
    // 0x1be59c: 0x10820045  beq         $a0, $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1BE59Cu;
    {
        const bool branch_taken_0x1be59c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BE5A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE59Cu;
            // 0x1be5a0: 0x26104500  addiu       $s0, $s0, 0x4500 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 17664));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be59c) {
            ctx->pc = 0x1BE6B4u;
            goto label_1be6b4;
        }
    }
    ctx->pc = 0x1BE5A4u;
    // 0x1be5a4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1be5a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1be5a8: 0x10820040  beq         $a0, $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x1BE5A8u;
    {
        const bool branch_taken_0x1be5a8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BE5ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE5A8u;
            // 0x1be5ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be5a8) {
            ctx->pc = 0x1BE6ACu;
            goto label_1be6ac;
        }
    }
    ctx->pc = 0x1BE5B0u;
    // 0x1be5b0: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1be5b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1be5b4: 0x10820028  beq         $a0, $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x1BE5B4u;
    {
        const bool branch_taken_0x1be5b4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BE5B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE5B4u;
            // 0x1be5b8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be5b4) {
            ctx->pc = 0x1BE658u;
            goto label_1be658;
        }
    }
    ctx->pc = 0x1BE5BCu;
    // 0x1be5bc: 0x1083001c  beq         $a0, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1BE5BCu;
    {
        const bool branch_taken_0x1be5bc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BE5C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE5BCu;
            // 0x1be5c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be5bc) {
            ctx->pc = 0x1BE630u;
            goto label_1be630;
        }
    }
    ctx->pc = 0x1BE5C4u;
    // 0x1be5c4: 0x1082003d  beq         $a0, $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x1BE5C4u;
    {
        const bool branch_taken_0x1be5c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1be5c4) {
            ctx->pc = 0x1BE6BCu;
            goto label_1be6bc;
        }
    }
    ctx->pc = 0x1BE5CCu;
    // 0x1be5cc: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE5CCu;
    {
        const bool branch_taken_0x1be5cc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE5D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE5CCu;
            // 0x1be5d0: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be5cc) {
            ctx->pc = 0x1BE5DCu;
            goto label_1be5dc;
        }
    }
    ctx->pc = 0x1BE5D4u;
    // 0x1be5d4: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1BE5D4u;
    {
        const bool branch_taken_0x1be5d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE5D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE5D4u;
            // 0x1be5d8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be5d4) {
            ctx->pc = 0x1BE6C0u;
            goto label_1be6c0;
        }
    }
    ctx->pc = 0x1BE5DCu;
label_1be5dc:
    // 0x1be5dc: 0x8c244508  lw          $a0, 0x4508($at)
    ctx->pc = 0x1be5dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17672)));
    // 0x1be5e0: 0x14820007  bne         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BE5E0u;
    {
        const bool branch_taken_0x1be5e0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x1be5e0) {
            ctx->pc = 0x1BE600u;
            goto label_1be600;
        }
    }
    ctx->pc = 0x1BE5E8u;
    // 0x1be5e8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be5e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be5ec: 0x902243d1  lbu         $v0, 0x43D1($at)
    ctx->pc = 0x1be5ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17361)));
    // 0x1be5f0: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE5F0u;
    {
        const bool branch_taken_0x1be5f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1BE5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE5F0u;
            // 0x1be5f4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be5f0) {
            ctx->pc = 0x1BE600u;
            goto label_1be600;
        }
    }
    ctx->pc = 0x1BE5F8u;
    // 0x1be5f8: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1BE5F8u;
    {
        const bool branch_taken_0x1be5f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE5FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE5F8u;
            // 0x1be5fc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be5f8) {
            ctx->pc = 0x1BE6C4u;
            goto label_1be6c4;
        }
    }
    ctx->pc = 0x1BE600u;
label_1be600:
    // 0x1be600: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BE600u;
    {
        const bool branch_taken_0x1be600 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BE604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE600u;
            // 0x1be604: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be600) {
            ctx->pc = 0x1BE628u;
            goto label_1be628;
        }
    }
    ctx->pc = 0x1BE608u;
    // 0x1be608: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be608u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be60c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1be60cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1be610: 0x902343d1  lbu         $v1, 0x43D1($at)
    ctx->pc = 0x1be610u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17361)));
    // 0x1be614: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BE614u;
    {
        const bool branch_taken_0x1be614 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1BE618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE614u;
            // 0x1be618: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be614) {
            ctx->pc = 0x1BE624u;
            goto label_1be624;
        }
    }
    ctx->pc = 0x1BE61Cu;
    // 0x1be61c: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1BE61Cu;
    {
        const bool branch_taken_0x1be61c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1be61c) {
            ctx->pc = 0x1BE6C0u;
            goto label_1be6c0;
        }
    }
    ctx->pc = 0x1BE624u;
label_1be624:
    // 0x1be624: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1be624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1be628:
    // 0x1be628: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1BE628u;
    {
        const bool branch_taken_0x1be628 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE62Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE628u;
            // 0x1be62c: 0xa2020000  sb          $v0, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be628) {
            ctx->pc = 0x1BE6BCu;
            goto label_1be6bc;
        }
    }
    ctx->pc = 0x1BE630u;
label_1be630:
    // 0x1be630: 0xc06b878  jal         func_1AE1E0
    ctx->pc = 0x1BE630u;
    SET_GPR_U32(ctx, 31, 0x1BE638u);
    ctx->pc = 0x1AE1E0u;
    if (runtime->hasFunction(0x1AE1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE638u; }
        if (ctx->pc != 0x1BE638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE1E0_0x1ae1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE638u; }
        if (ctx->pc != 0x1BE638u) { return; }
    }
    ctx->pc = 0x1BE638u;
label_1be638:
    // 0x1be638: 0xc0de938  jal         func_37A4E0
    ctx->pc = 0x1BE638u;
    SET_GPR_U32(ctx, 31, 0x1BE640u);
    ctx->pc = 0x37A4E0u;
    {
        auto targetFn = runtime->lookupFunction(0x37A4E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE640u; }
        if (ctx->pc != 0x1BE640u) { return; }
    }
    ctx->pc = 0x1BE640u;
label_1be640:
    // 0x1be640: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x1be640u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1be644: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1be644u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1be648: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1be648u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1be64c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1be64cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1be650: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1BE650u;
    {
        const bool branch_taken_0x1be650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE650u;
            // 0x1be654: 0xa2020000  sb          $v0, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be650) {
            ctx->pc = 0x1BE6BCu;
            goto label_1be6bc;
        }
    }
    ctx->pc = 0x1BE658u;
label_1be658:
    // 0x1be658: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1be658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1be65c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1be65cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1be660: 0x14400016  bnez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1BE660u;
    {
        const bool branch_taken_0x1be660 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BE664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE660u;
            // 0x1be664: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be660) {
            ctx->pc = 0x1BE6BCu;
            goto label_1be6bc;
        }
    }
    ctx->pc = 0x1BE668u;
    // 0x1be668: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be668u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be66c: 0xc06f8a0  jal         func_1BE280
    ctx->pc = 0x1BE66Cu;
    SET_GPR_U32(ctx, 31, 0x1BE674u);
    ctx->pc = 0x1BE670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE66Cu;
            // 0x1be670: 0x8c244508  lw          $a0, 0x4508($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17672)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE280u;
    if (runtime->hasFunction(0x1BE280u)) {
        auto targetFn = runtime->lookupFunction(0x1BE280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE674u; }
        if (ctx->pc != 0x1BE674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE280_0x1be280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE674u; }
        if (ctx->pc != 0x1BE674u) { return; }
    }
    ctx->pc = 0x1BE674u;
label_1be674:
    // 0x1be674: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be674u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be678: 0x8c2344e8  lw          $v1, 0x44E8($at)
    ctx->pc = 0x1be678u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17640)));
    // 0x1be67c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1be67cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1be680: 0x8c224508  lw          $v0, 0x4508($at)
    ctx->pc = 0x1be680u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17672)));
    // 0x1be684: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BE684u;
    {
        const bool branch_taken_0x1be684 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BE688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE684u;
            // 0x1be688: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be684) {
            ctx->pc = 0x1BE698u;
            goto label_1be698;
        }
    }
    ctx->pc = 0x1BE68Cu;
    // 0x1be68c: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1be68cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1be690: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1BE690u;
    {
        const bool branch_taken_0x1be690 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE690u;
            // 0x1be694: 0xa2020000  sb          $v0, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be690) {
            ctx->pc = 0x1BE6BCu;
            goto label_1be6bc;
        }
    }
    ctx->pc = 0x1BE698u;
label_1be698:
    // 0x1be698: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1be698u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1be69c: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1be69cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1be6a0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1be6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1be6a4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BE6A4u;
    {
        const bool branch_taken_0x1be6a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE6A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE6A4u;
            // 0x1be6a8: 0xa2020000  sb          $v0, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be6a4) {
            ctx->pc = 0x1BE6BCu;
            goto label_1be6bc;
        }
    }
    ctx->pc = 0x1BE6ACu;
label_1be6ac:
    // 0x1be6ac: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1BE6ACu;
    {
        const bool branch_taken_0x1be6ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1be6ac) {
            ctx->pc = 0x1BE6C0u;
            goto label_1be6c0;
        }
    }
    ctx->pc = 0x1BE6B4u;
label_1be6b4:
    // 0x1be6b4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1BE6B4u;
    {
        const bool branch_taken_0x1be6b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BE6B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE6B4u;
            // 0x1be6b8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1be6b4) {
            ctx->pc = 0x1BE6C0u;
            goto label_1be6c0;
        }
    }
    ctx->pc = 0x1BE6BCu;
label_1be6bc:
    // 0x1be6bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1be6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1be6c0:
    // 0x1be6c0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1be6c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1be6c4:
    // 0x1be6c4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1be6c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1be6c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE6C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE6C8u;
            // 0x1be6cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BE488u: goto label_1be488;
            case 0x1BE490u: goto label_1be490;
            case 0x1BE4A4u: goto label_1be4a4;
            case 0x1BE4B4u: goto label_1be4b4;
            case 0x1BE4F8u: goto label_1be4f8;
            case 0x1BE508u: goto label_1be508;
            case 0x1BE520u: goto label_1be520;
            case 0x1BE52Cu: goto label_1be52c;
            case 0x1BE530u: goto label_1be530;
            case 0x1BE5DCu: goto label_1be5dc;
            case 0x1BE600u: goto label_1be600;
            case 0x1BE624u: goto label_1be624;
            case 0x1BE628u: goto label_1be628;
            case 0x1BE630u: goto label_1be630;
            case 0x1BE638u: goto label_1be638;
            case 0x1BE640u: goto label_1be640;
            case 0x1BE658u: goto label_1be658;
            case 0x1BE674u: goto label_1be674;
            case 0x1BE698u: goto label_1be698;
            case 0x1BE6ACu: goto label_1be6ac;
            case 0x1BE6B4u: goto label_1be6b4;
            case 0x1BE6BCu: goto label_1be6bc;
            case 0x1BE6C0u: goto label_1be6c0;
            case 0x1BE6C4u: goto label_1be6c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE6D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
