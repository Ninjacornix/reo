#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DC7B8
// Address: 0x1dc7b8 - 0x1dcc2c
void sub_001DC7B8_0x1dc7b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DC7B8_0x1dc7b8");
#endif

    switch (ctx->pc) {
        case 0x1dc828u: goto label_1dc828;
        case 0x1dc840u: goto label_1dc840;
        case 0x1dc884u: goto label_1dc884;
        case 0x1dc8b0u: goto label_1dc8b0;
        case 0x1dc92cu: goto label_1dc92c;
        case 0x1dc97cu: goto label_1dc97c;
        case 0x1dc99cu: goto label_1dc99c;
        case 0x1dc9d8u: goto label_1dc9d8;
        case 0x1dca04u: goto label_1dca04;
        case 0x1dca54u: goto label_1dca54;
        case 0x1dcaecu: goto label_1dcaec;
        case 0x1dcb28u: goto label_1dcb28;
        case 0x1dcb60u: goto label_1dcb60;
        case 0x1dcb70u: goto label_1dcb70;
        case 0x1dcbd0u: goto label_1dcbd0;
        case 0x1dcbf0u: goto label_1dcbf0;
        default: break;
    }

    ctx->pc = 0x1dc7b8u;

    // 0x1dc7b8: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1dc7b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1dc7bc: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x1dc7bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x1dc7c0: 0xffbe0058  sd          $fp, 0x58($sp)
    ctx->pc = 0x1dc7c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 30));
    // 0x1dc7c4: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1dc7c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1dc7c8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dc7c8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc7cc: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dc7ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dc7d0: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1dc7d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1dc7d4: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1dc7d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1dc7d8: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1dc7d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1dc7dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1dc7dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dc7e0: 0xafc2003c  sw          $v0, 0x3C($fp)
    ctx->pc = 0x1dc7e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 2));
    // 0x1dc7e4: 0xafc00040  sw          $zero, 0x40($fp)
    ctx->pc = 0x1dc7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 0));
    // 0x1dc7e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc7ec: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc7f0: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1dc7f0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dc7f4: 0x30424000  andi        $v0, $v0, 0x4000
    ctx->pc = 0x1dc7f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16384);
    // 0x1dc7f8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1dc7f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dc7fc: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1DC7FCu;
    {
        const bool branch_taken_0x1dc7fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc7fc) {
            ctx->pc = 0x1DC840u;
            goto label_1dc840;
        }
    }
    ctx->pc = 0x1DC804u;
    // 0x1dc804: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dc804u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc808: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc80c: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc80cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc810: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc814: 0x8c650058  lw          $a1, 0x58($v1)
    ctx->pc = 0x1dc814u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 88)));
    // 0x1dc818: 0x8c46000c  lw          $a2, 0xC($v0)
    ctx->pc = 0x1dc818u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1dc81c: 0x8fc7000c  lw          $a3, 0xC($fp)
    ctx->pc = 0x1dc81cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1dc820: 0xc079e3e  jal         func_1E78F8
    ctx->pc = 0x1DC820u;
    SET_GPR_U32(ctx, 31, 0x1DC828u);
    ctx->pc = 0x1E78F8u;
    if (runtime->hasFunction(0x1E78F8u)) {
        auto targetFn = runtime->lookupFunction(0x1E78F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC828u; }
        if (ctx->pc != 0x1DC828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E78F8_0x1e78f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC828u; }
        if (ctx->pc != 0x1DC828u) { return; }
    }
    ctx->pc = 0x1DC828u;
label_1dc828:
    // 0x1dc828: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc82c: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc82cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc830: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dc830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc834: 0x8c45000c  lw          $a1, 0xC($v0)
    ctx->pc = 0x1dc834u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1dc838: 0xc07cd19  jal         func_1F3464
    ctx->pc = 0x1DC838u;
    SET_GPR_U32(ctx, 31, 0x1DC840u);
    ctx->pc = 0x1F3464u;
    if (runtime->hasFunction(0x1F3464u)) {
        auto targetFn = runtime->lookupFunction(0x1F3464u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC840u; }
        if (ctx->pc != 0x1DC840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3464_0x1f3464(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC840u; }
        if (ctx->pc != 0x1DC840u) { return; }
    }
    ctx->pc = 0x1DC840u;
label_1dc840:
    // 0x1dc840: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc840u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc844: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc848: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1dc848u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dc84c: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x1dc84cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x1dc850: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1dc850u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dc854: 0x1040001d  beqz        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1DC854u;
    {
        const bool branch_taken_0x1dc854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc854) {
            ctx->pc = 0x1DC8CCu;
            goto label_1dc8cc;
        }
    }
    ctx->pc = 0x1DC85Cu;
    // 0x1dc85c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc85cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc860: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc860u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc864: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1dc864u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1dc868: 0xafc20040  sw          $v0, 0x40($fp)
    ctx->pc = 0x1dc868u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 2));
    // 0x1dc86c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dc86cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc870: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dc870u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc874: 0x8c450060  lw          $a1, 0x60($v0)
    ctx->pc = 0x1dc874u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dc878: 0x8fc60040  lw          $a2, 0x40($fp)
    ctx->pc = 0x1dc878u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1dc87c: 0xc079d39  jal         func_1E74E4
    ctx->pc = 0x1DC87Cu;
    SET_GPR_U32(ctx, 31, 0x1DC884u);
    ctx->pc = 0x1E74E4u;
    if (runtime->hasFunction(0x1E74E4u)) {
        auto targetFn = runtime->lookupFunction(0x1E74E4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC884u; }
        if (ctx->pc != 0x1DC884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E74E4_0x1e74e4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC884u; }
        if (ctx->pc != 0x1DC884u) { return; }
    }
    ctx->pc = 0x1DC884u;
label_1dc884:
    // 0x1dc884: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dc884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc888: 0x8c42005c  lw          $v0, 0x5C($v0)
    ctx->pc = 0x1dc888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1dc88c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1dc88cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1dc890: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dc890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dc894: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1dc894u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1dc898: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1DC898u;
    {
        const bool branch_taken_0x1dc898 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dc898) {
            ctx->pc = 0x1DC8B4u;
            goto label_1dc8b4;
        }
    }
    ctx->pc = 0x1DC8A0u;
    // 0x1dc8a0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dc8a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc8a4: 0x8fc50040  lw          $a1, 0x40($fp)
    ctx->pc = 0x1dc8a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1dc8a8: 0xc07cd2f  jal         func_1F34BC
    ctx->pc = 0x1DC8A8u;
    SET_GPR_U32(ctx, 31, 0x1DC8B0u);
    ctx->pc = 0x1F34BCu;
    if (runtime->hasFunction(0x1F34BCu)) {
        auto targetFn = runtime->lookupFunction(0x1F34BCu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC8B0u; }
        if (ctx->pc != 0x1DC8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34BC_0x1f34bc(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC8B0u; }
        if (ctx->pc != 0x1DC8B0u) { return; }
    }
    ctx->pc = 0x1DC8B0u;
label_1dc8b0:
    // 0x1dc8b0: 0xafc0003c  sw          $zero, 0x3C($fp)
    ctx->pc = 0x1dc8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 0));
label_1dc8b4:
    // 0x1dc8b4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dc8b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc8b8: 0x8c42005c  lw          $v0, 0x5C($v0)
    ctx->pc = 0x1dc8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1dc8bc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1dc8bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1dc8c0: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dc8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1dc8c4: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1DC8C4u;
    {
        const bool branch_taken_0x1dc8c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc8c4) {
            ctx->pc = 0x1DC910u;
            goto label_1dc910;
        }
    }
    ctx->pc = 0x1DC8CCu;
label_1dc8cc:
    // 0x1dc8cc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc8ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc8d0: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc8d4: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dc8d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc8d8: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x1dc8d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1dc8dc: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x1dc8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1dc8e0: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x1dc8e0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1dc8e4: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1DC8E4u;
    {
        const bool branch_taken_0x1dc8e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dc8e4) {
            ctx->pc = 0x1DC904u;
            goto label_1dc904;
        }
    }
    ctx->pc = 0x1DC8ECu;
    // 0x1dc8ec: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dc8ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc8f0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc8f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc8f4: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc8f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc8f8: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1dc8f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1dc8fc: 0xac620010  sw          $v0, 0x10($v1)
    ctx->pc = 0x1dc8fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x1dc900: 0xafc0003c  sw          $zero, 0x3C($fp)
    ctx->pc = 0x1dc900u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 60), GPR_U32(ctx, 0));
label_1dc904:
    // 0x1dc904: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dc904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dc908: 0x24420068  addiu       $v0, $v0, 0x68
    ctx->pc = 0x1dc908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 104));
    // 0x1dc90c: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dc90cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1dc910:
    // 0x1dc910: 0x8fc2003c  lw          $v0, 0x3C($fp)
    ctx->pc = 0x1dc910u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1dc914: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1DC914u;
    {
        const bool branch_taken_0x1dc914 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dc914) {
            ctx->pc = 0x1DC954u;
            goto label_1dc954;
        }
    }
    ctx->pc = 0x1DC91Cu;
    // 0x1dc91c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1dc91cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dc920: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dc920u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc924: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1DC924u;
    SET_GPR_U32(ctx, 31, 0x1DC92Cu);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC92Cu; }
        if (ctx->pc != 0x1DC92Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC92Cu; }
        if (ctx->pc != 0x1DC92Cu) { return; }
    }
    ctx->pc = 0x1DC92Cu;
label_1dc92c:
    // 0x1dc92c: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1dc92cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1dc930: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dc930u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dc934: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1DC934u;
    {
        const bool branch_taken_0x1dc934 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc934) {
            ctx->pc = 0x1DC954u;
            goto label_1dc954;
        }
    }
    ctx->pc = 0x1DC93Cu;
    // 0x1dc93c: 0x24021771  addiu       $v0, $zero, 0x1771
    ctx->pc = 0x1dc93cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6001));
    // 0x1dc940: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x1dc940u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x1dc944: 0xac229d10  sw          $v0, -0x62F0($at)
    ctx->pc = 0x1dc944u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dc948: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dc948u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dc94c: 0x100000b0  b           . + 4 + (0xB0 << 2)
    ctx->pc = 0x1DC94Cu;
    {
        const bool branch_taken_0x1dc94c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc94c) {
            ctx->pc = 0x1DCC10u;
            goto label_1dcc10;
        }
    }
    ctx->pc = 0x1DC954u;
label_1dc954:
    // 0x1dc954: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc954u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc958: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc95c: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1dc95cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dc960: 0x30420800  andi        $v0, $v0, 0x800
    ctx->pc = 0x1dc960u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2048);
    // 0x1dc964: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1dc964u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dc968: 0x10400090  beqz        $v0, . + 4 + (0x90 << 2)
    ctx->pc = 0x1DC968u;
    {
        const bool branch_taken_0x1dc968 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc968) {
            ctx->pc = 0x1DCBACu;
            goto label_1dcbac;
        }
    }
    ctx->pc = 0x1DC970u;
    // 0x1dc970: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dc970u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc974: 0xc07cd3b  jal         func_1F34EC
    ctx->pc = 0x1DC974u;
    SET_GPR_U32(ctx, 31, 0x1DC97Cu);
    ctx->pc = 0x1F34ECu;
    if (runtime->hasFunction(0x1F34ECu)) {
        auto targetFn = runtime->lookupFunction(0x1F34ECu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC97Cu; }
        if (ctx->pc != 0x1DC97Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34EC_0x1f34ec(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC97Cu; }
        if (ctx->pc != 0x1DC97Cu) { return; }
    }
    ctx->pc = 0x1DC97Cu;
label_1dc97c:
    // 0x1dc97c: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1dc97cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1dc980: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dc980u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc984: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dc984u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dc988: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1dc988u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dc98c: 0x304203ff  andi        $v0, $v0, 0x3FF
    ctx->pc = 0x1dc98cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1023);
    // 0x1dc990: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1dc990u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dc994: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1dc994u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1dc998: 0xafc00038  sw          $zero, 0x38($fp)
    ctx->pc = 0x1dc998u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 0));
label_1dc99c:
    // 0x1dc99c: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1dc99cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1dc9a0: 0x28420038  slti        $v0, $v0, 0x38
    ctx->pc = 0x1dc9a0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)56) ? 1 : 0);
    // 0x1dc9a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DC9A4u;
    {
        const bool branch_taken_0x1dc9a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dc9a4) {
            ctx->pc = 0x1DC9B4u;
            goto label_1dc9b4;
        }
    }
    ctx->pc = 0x1DC9ACu;
    // 0x1dc9ac: 0x1000007f  b           . + 4 + (0x7F << 2)
    ctx->pc = 0x1DC9ACu;
    {
        const bool branch_taken_0x1dc9ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc9ac) {
            ctx->pc = 0x1DCBACu;
            goto label_1dcbac;
        }
    }
    ctx->pc = 0x1DC9B4u;
label_1dc9b4:
    // 0x1dc9b4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1dc9b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1dc9b8: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1dc9b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1dc9bc: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1dc9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dc9c0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1dc9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1dc9c4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1dc9c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1dc9c8: 0x24500010  addiu       $s0, $v0, 0x10
    ctx->pc = 0x1dc9c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1dc9cc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dc9ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dc9d0: 0xc07cc13  jal         func_1F304C
    ctx->pc = 0x1DC9D0u;
    SET_GPR_U32(ctx, 31, 0x1DC9D8u);
    ctx->pc = 0x1F304Cu;
    if (runtime->hasFunction(0x1F304Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F304Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC9D8u; }
        if (ctx->pc != 0x1DC9D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F304C_0x1f304c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DC9D8u; }
        if (ctx->pc != 0x1DC9D8u) { return; }
    }
    ctx->pc = 0x1DC9D8u;
label_1dc9d8:
    // 0x1dc9d8: 0x50102b  sltu        $v0, $v0, $s0
    ctx->pc = 0x1dc9d8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x1dc9dc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DC9DCu;
    {
        const bool branch_taken_0x1dc9dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc9dc) {
            ctx->pc = 0x1DC9ECu;
            goto label_1dc9ec;
        }
    }
    ctx->pc = 0x1DC9E4u;
    // 0x1dc9e4: 0x10000071  b           . + 4 + (0x71 << 2)
    ctx->pc = 0x1DC9E4u;
    {
        const bool branch_taken_0x1dc9e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dc9e4) {
            ctx->pc = 0x1DCBACu;
            goto label_1dcbac;
        }
    }
    ctx->pc = 0x1DC9ECu;
label_1dc9ec:
    // 0x1dc9ec: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1dc9ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1dc9f0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dc9f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dc9f4: 0x8fc50030  lw          $a1, 0x30($fp)
    ctx->pc = 0x1dc9f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1dc9f8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1dc9f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1dc9fc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1DC9FCu;
    SET_GPR_U32(ctx, 31, 0x1DCA04u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCA04u; }
        if (ctx->pc != 0x1DCA04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCA04u; }
        if (ctx->pc != 0x1DCA04u) { return; }
    }
    ctx->pc = 0x1DCA04u;
label_1dca04:
    // 0x1dca04: 0x97c20020  lhu         $v0, 0x20($fp)
    ctx->pc = 0x1dca04u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1dca08: 0x304203ff  andi        $v0, $v0, 0x3FF
    ctx->pc = 0x1dca08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1023);
    // 0x1dca0c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1dca0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dca10: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1dca10u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1dca14: 0x97c20020  lhu         $v0, 0x20($fp)
    ctx->pc = 0x1dca14u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1dca18: 0x30428000  andi        $v0, $v0, 0x8000
    ctx->pc = 0x1dca18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32768);
    // 0x1dca1c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1dca1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dca20: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1DCA20u;
    {
        const bool branch_taken_0x1dca20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dca20) {
            ctx->pc = 0x1DCA90u;
            goto label_1dca90;
        }
    }
    ctx->pc = 0x1DCA28u;
    // 0x1dca28: 0x8fc20040  lw          $v0, 0x40($fp)
    ctx->pc = 0x1dca28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1dca2c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1DCA2Cu;
    {
        const bool branch_taken_0x1dca2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dca2c) {
            ctx->pc = 0x1DCA54u;
            goto label_1dca54;
        }
    }
    ctx->pc = 0x1DCA34u;
    // 0x1dca34: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1dca34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1dca38: 0xafc20040  sw          $v0, 0x40($fp)
    ctx->pc = 0x1dca38u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 2));
    // 0x1dca3c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dca3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dca40: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1dca40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dca44: 0x8c450060  lw          $a1, 0x60($v0)
    ctx->pc = 0x1dca44u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dca48: 0x8fc60040  lw          $a2, 0x40($fp)
    ctx->pc = 0x1dca48u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1dca4c: 0xc079d39  jal         func_1E74E4
    ctx->pc = 0x1DCA4Cu;
    SET_GPR_U32(ctx, 31, 0x1DCA54u);
    ctx->pc = 0x1E74E4u;
    if (runtime->hasFunction(0x1E74E4u)) {
        auto targetFn = runtime->lookupFunction(0x1E74E4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCA54u; }
        if (ctx->pc != 0x1DCA54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E74E4_0x1e74e4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCA54u; }
        if (ctx->pc != 0x1DCA54u) { return; }
    }
    ctx->pc = 0x1DCA54u;
label_1dca54:
    // 0x1dca54: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dca54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dca58: 0x8c42005c  lw          $v0, 0x5C($v0)
    ctx->pc = 0x1dca58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1dca5c: 0x8fc30040  lw          $v1, 0x40($fp)
    ctx->pc = 0x1dca5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1dca60: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1dca60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dca64: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1dca64u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1dca68: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DCA68u;
    {
        const bool branch_taken_0x1dca68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dca68) {
            ctx->pc = 0x1DCA78u;
            goto label_1dca78;
        }
    }
    ctx->pc = 0x1DCA70u;
    // 0x1dca70: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x1DCA70u;
    {
        const bool branch_taken_0x1dca70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dca70) {
            ctx->pc = 0x1DCB98u;
            goto label_1dcb98;
        }
    }
    ctx->pc = 0x1DCA78u;
label_1dca78:
    // 0x1dca78: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dca78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dca7c: 0x8c42005c  lw          $v0, 0x5C($v0)
    ctx->pc = 0x1dca7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1dca80: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1dca80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1dca84: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dca84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1dca88: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1DCA88u;
    {
        const bool branch_taken_0x1dca88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dca88) {
            ctx->pc = 0x1DCAC8u;
            goto label_1dcac8;
        }
    }
    ctx->pc = 0x1DCA90u;
label_1dca90:
    // 0x1dca90: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dca90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dca94: 0x8fc30028  lw          $v1, 0x28($fp)
    ctx->pc = 0x1dca94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1dca98: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1dca98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1dca9c: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x1dca9cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1dcaa0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DCAA0u;
    {
        const bool branch_taken_0x1dcaa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcaa0) {
            ctx->pc = 0x1DCAB0u;
            goto label_1dcab0;
        }
    }
    ctx->pc = 0x1DCAA8u;
    // 0x1dcaa8: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1DCAA8u;
    {
        const bool branch_taken_0x1dcaa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcaa8) {
            ctx->pc = 0x1DCB98u;
            goto label_1dcb98;
        }
    }
    ctx->pc = 0x1DCAB0u;
label_1dcab0:
    // 0x1dcab0: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dcab0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dcab4: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1dcab4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1dcab8: 0xac620010  sw          $v0, 0x10($v1)
    ctx->pc = 0x1dcab8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x1dcabc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dcabcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dcac0: 0x24420068  addiu       $v0, $v0, 0x68
    ctx->pc = 0x1dcac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 104));
    // 0x1dcac4: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1dcac4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1dcac8:
    // 0x1dcac8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dcac8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dcacc: 0x27c30010  addiu       $v1, $fp, 0x10
    ctx->pc = 0x1dcaccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1dcad0: 0x97c60034  lhu         $a2, 0x34($fp)
    ctx->pc = 0x1dcad0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1dcad4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dcad4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dcad8: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1dcad8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcadc: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1dcadcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dcae0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1dcae0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcae4: 0xc07c80a  jal         func_1F2028
    ctx->pc = 0x1DCAE4u;
    SET_GPR_U32(ctx, 31, 0x1DCAECu);
    ctx->pc = 0x1F2028u;
    if (runtime->hasFunction(0x1F2028u)) {
        auto targetFn = runtime->lookupFunction(0x1F2028u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCAECu; }
        if (ctx->pc != 0x1DCAECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2028_0x1f2028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCAECu; }
        if (ctx->pc != 0x1DCAECu) { return; }
    }
    ctx->pc = 0x1DCAECu;
label_1dcaec:
    // 0x1dcaec: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1dcaecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1dcaf0: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dcaf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dcaf4: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1DCAF4u;
    {
        const bool branch_taken_0x1dcaf4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1dcaf4) {
            ctx->pc = 0x1DCB14u;
            goto label_1dcb14;
        }
    }
    ctx->pc = 0x1DCAFCu;
    // 0x1dcafc: 0x24021772  addiu       $v0, $zero, 0x1772
    ctx->pc = 0x1dcafcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6002));
    // 0x1dcb00: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x1dcb00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x1dcb04: 0xac229d10  sw          $v0, -0x62F0($at)
    ctx->pc = 0x1dcb04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dcb08: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dcb08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dcb0c: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1DCB0Cu;
    {
        const bool branch_taken_0x1dcb0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcb0c) {
            ctx->pc = 0x1DCC10u;
            goto label_1dcc10;
        }
    }
    ctx->pc = 0x1DCB14u;
label_1dcb14:
    // 0x1dcb14: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1dcb14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcb18: 0x8fc50030  lw          $a1, 0x30($fp)
    ctx->pc = 0x1dcb18u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1dcb1c: 0x8fc60034  lw          $a2, 0x34($fp)
    ctx->pc = 0x1dcb1cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1dcb20: 0xc07cd5f  jal         func_1F357C
    ctx->pc = 0x1DCB20u;
    SET_GPR_U32(ctx, 31, 0x1DCB28u);
    ctx->pc = 0x1F357Cu;
    if (runtime->hasFunction(0x1F357Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F357Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCB28u; }
        if (ctx->pc != 0x1DCB28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F357C_0x1f357c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCB28u; }
        if (ctx->pc != 0x1DCB28u) { return; }
    }
    ctx->pc = 0x1DCB28u;
label_1dcb28:
    // 0x1dcb28: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1dcb28u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1dcb2c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dcb2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dcb30: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1DCB30u;
    {
        const bool branch_taken_0x1dcb30 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1dcb30) {
            ctx->pc = 0x1DCB50u;
            goto label_1dcb50;
        }
    }
    ctx->pc = 0x1DCB38u;
    // 0x1dcb38: 0x24021773  addiu       $v0, $zero, 0x1773
    ctx->pc = 0x1dcb38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6003));
    // 0x1dcb3c: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x1dcb3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x1dcb40: 0xac229d10  sw          $v0, -0x62F0($at)
    ctx->pc = 0x1dcb40u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dcb44: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dcb44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dcb48: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1DCB48u;
    {
        const bool branch_taken_0x1dcb48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcb48) {
            ctx->pc = 0x1DCC10u;
            goto label_1dcc10;
        }
    }
    ctx->pc = 0x1DCB50u;
label_1dcb50:
    // 0x1dcb50: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1dcb50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcb54: 0x8fc50040  lw          $a1, 0x40($fp)
    ctx->pc = 0x1dcb54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1dcb58: 0xc07cd2f  jal         func_1F34BC
    ctx->pc = 0x1DCB58u;
    SET_GPR_U32(ctx, 31, 0x1DCB60u);
    ctx->pc = 0x1F34BCu;
    if (runtime->hasFunction(0x1F34BCu)) {
        auto targetFn = runtime->lookupFunction(0x1F34BCu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCB60u; }
        if (ctx->pc != 0x1DCB60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34BC_0x1f34bc(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCB60u; }
        if (ctx->pc != 0x1DCB60u) { return; }
    }
    ctx->pc = 0x1DCB60u;
label_1dcb60:
    // 0x1dcb60: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1dcb60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dcb64: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1dcb64u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dcb68: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1DCB68u;
    SET_GPR_U32(ctx, 31, 0x1DCB70u);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCB70u; }
        if (ctx->pc != 0x1DCB70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCB70u; }
        if (ctx->pc != 0x1DCB70u) { return; }
    }
    ctx->pc = 0x1DCB70u;
label_1dcb70:
    // 0x1dcb70: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1dcb70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1dcb74: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dcb74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dcb78: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1DCB78u;
    {
        const bool branch_taken_0x1dcb78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcb78) {
            ctx->pc = 0x1DCB98u;
            goto label_1dcb98;
        }
    }
    ctx->pc = 0x1DCB80u;
    // 0x1dcb80: 0x24021774  addiu       $v0, $zero, 0x1774
    ctx->pc = 0x1dcb80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6004));
    // 0x1dcb84: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x1dcb84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x1dcb88: 0xac229d10  sw          $v0, -0x62F0($at)
    ctx->pc = 0x1dcb88u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dcb8c: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dcb8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dcb90: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1DCB90u;
    {
        const bool branch_taken_0x1dcb90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcb90) {
            ctx->pc = 0x1DCC10u;
            goto label_1dcc10;
        }
    }
    ctx->pc = 0x1DCB98u;
label_1dcb98:
    // 0x1dcb98: 0x8fc20038  lw          $v0, 0x38($fp)
    ctx->pc = 0x1dcb98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1dcb9c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1dcb9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dcba0: 0xafc20038  sw          $v0, 0x38($fp)
    ctx->pc = 0x1dcba0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 56), GPR_U32(ctx, 2));
    // 0x1dcba4: 0x1000ff7d  b           . + 4 + (-0x83 << 2)
    ctx->pc = 0x1DCBA4u;
    {
        const bool branch_taken_0x1dcba4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcba4) {
            ctx->pc = 0x1DC99Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dc99c;
        }
    }
    ctx->pc = 0x1DCBACu;
label_1dcbac:
    // 0x1dcbac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dcbacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcbb0: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1dcbb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dcbb4: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1dcbb4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dcbb8: 0x304203ff  andi        $v0, $v0, 0x3FF
    ctx->pc = 0x1dcbb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1023);
    // 0x1dcbbc: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1dcbbcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1dcbc0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dcbc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcbc4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1dcbc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcbc8: 0xc07c6c0  jal         func_1F1B00
    ctx->pc = 0x1DCBC8u;
    SET_GPR_U32(ctx, 31, 0x1DCBD0u);
    ctx->pc = 0x1F1B00u;
    if (runtime->hasFunction(0x1F1B00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCBD0u; }
        if (ctx->pc != 0x1DCBD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B00_0x1f1b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCBD0u; }
        if (ctx->pc != 0x1DCBD0u) { return; }
    }
    ctx->pc = 0x1DCBD0u;
label_1dcbd0:
    // 0x1dcbd0: 0x8fc2003c  lw          $v0, 0x3C($fp)
    ctx->pc = 0x1dcbd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 60)));
    // 0x1dcbd4: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1DCBD4u;
    {
        const bool branch_taken_0x1dcbd4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcbd4) {
            ctx->pc = 0x1DCC0Cu;
            goto label_1dcc0c;
        }
    }
    ctx->pc = 0x1DCBDCu;
    // 0x1dcbdc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dcbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dcbe0: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dcbe0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dcbe4: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1dcbe4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcbe8: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DCBE8u;
    SET_GPR_U32(ctx, 31, 0x1DCBF0u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCBF0u; }
        if (ctx->pc != 0x1DCBF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCBF0u; }
        if (ctx->pc != 0x1DCBF0u) { return; }
    }
    ctx->pc = 0x1DCBF0u;
label_1dcbf0:
    // 0x1dcbf0: 0xafc20044  sw          $v0, 0x44($fp)
    ctx->pc = 0x1dcbf0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1dcbf4: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dcbf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dcbf8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DCBF8u;
    {
        const bool branch_taken_0x1dcbf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcbf8) {
            ctx->pc = 0x1DCC0Cu;
            goto label_1dcc0c;
        }
    }
    ctx->pc = 0x1DCC00u;
    // 0x1dcc00: 0x8fc20044  lw          $v0, 0x44($fp)
    ctx->pc = 0x1dcc00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dcc04: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1DCC04u;
    {
        const bool branch_taken_0x1dcc04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcc04) {
            ctx->pc = 0x1DCC10u;
            goto label_1dcc10;
        }
    }
    ctx->pc = 0x1DCC0Cu;
label_1dcc0c:
    // 0x1dcc0c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dcc0cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1dcc10:
    // 0x1dcc10: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dcc10u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcc14: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x1dcc14u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1dcc18: 0xdfbe0058  ld          $fp, 0x58($sp)
    ctx->pc = 0x1dcc18u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1dcc1c: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1dcc1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1dcc20: 0x27bd0070  addiu       $sp, $sp, 0x70
    ctx->pc = 0x1dcc20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1dcc24: 0x3e00008  jr          $ra
    ctx->pc = 0x1DCC24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DC828u: goto label_1dc828;
            case 0x1DC840u: goto label_1dc840;
            case 0x1DC884u: goto label_1dc884;
            case 0x1DC8B0u: goto label_1dc8b0;
            case 0x1DC8B4u: goto label_1dc8b4;
            case 0x1DC8CCu: goto label_1dc8cc;
            case 0x1DC904u: goto label_1dc904;
            case 0x1DC910u: goto label_1dc910;
            case 0x1DC92Cu: goto label_1dc92c;
            case 0x1DC954u: goto label_1dc954;
            case 0x1DC97Cu: goto label_1dc97c;
            case 0x1DC99Cu: goto label_1dc99c;
            case 0x1DC9B4u: goto label_1dc9b4;
            case 0x1DC9D8u: goto label_1dc9d8;
            case 0x1DC9ECu: goto label_1dc9ec;
            case 0x1DCA04u: goto label_1dca04;
            case 0x1DCA54u: goto label_1dca54;
            case 0x1DCA78u: goto label_1dca78;
            case 0x1DCA90u: goto label_1dca90;
            case 0x1DCAB0u: goto label_1dcab0;
            case 0x1DCAC8u: goto label_1dcac8;
            case 0x1DCAECu: goto label_1dcaec;
            case 0x1DCB14u: goto label_1dcb14;
            case 0x1DCB28u: goto label_1dcb28;
            case 0x1DCB50u: goto label_1dcb50;
            case 0x1DCB60u: goto label_1dcb60;
            case 0x1DCB70u: goto label_1dcb70;
            case 0x1DCB98u: goto label_1dcb98;
            case 0x1DCBACu: goto label_1dcbac;
            case 0x1DCBD0u: goto label_1dcbd0;
            case 0x1DCBF0u: goto label_1dcbf0;
            case 0x1DCC0Cu: goto label_1dcc0c;
            case 0x1DCC10u: goto label_1dcc10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DCC2Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
