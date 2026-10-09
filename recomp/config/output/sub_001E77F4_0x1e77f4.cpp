#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E77F4
// Address: 0x1e77f4 - 0x1e78f8
void sub_001E77F4_0x1e77f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E77F4_0x1e77f4");
#endif

    switch (ctx->pc) {
        case 0x1e7828u: goto label_1e7828;
        case 0x1e783cu: goto label_1e783c;
        case 0x1e784cu: goto label_1e784c;
        case 0x1e785cu: goto label_1e785c;
        case 0x1e7884u: goto label_1e7884;
        case 0x1e7894u: goto label_1e7894;
        case 0x1e78a4u: goto label_1e78a4;
        case 0x1e78d8u: goto label_1e78d8;
        default: break;
    }

    ctx->pc = 0x1e77f4u;

    // 0x1e77f4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e77f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e77f8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1e77f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1e77fc: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1e77fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1e7800: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e7800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e7804: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e7804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e7808: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7808u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e780c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e780cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e7810: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e7810u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e7814: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e7814u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e7818: 0xafc0000c  sw          $zero, 0xC($fp)
    ctx->pc = 0x1e7818u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 0));
    // 0x1e781c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e781cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7820: 0xc07cced  jal         func_1F33B4
    ctx->pc = 0x1E7820u;
    SET_GPR_U32(ctx, 31, 0x1E7828u);
    ctx->pc = 0x1F33B4u;
    if (runtime->hasFunction(0x1F33B4u)) {
        auto targetFn = runtime->lookupFunction(0x1F33B4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7828u; }
        if (ctx->pc != 0x1E7828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F33B4_0x1f33b4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7828u; }
        if (ctx->pc != 0x1E7828u) { return; }
    }
    ctx->pc = 0x1E7828u;
label_1e7828:
    // 0x1e7828: 0x18400013  blez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1E7828u;
    {
        const bool branch_taken_0x1e7828 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1e7828) {
            ctx->pc = 0x1E7878u;
            goto label_1e7878;
        }
    }
    ctx->pc = 0x1E7830u;
    // 0x1e7830: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7834: 0xc07ccb5  jal         func_1F32D4
    ctx->pc = 0x1E7834u;
    SET_GPR_U32(ctx, 31, 0x1E783Cu);
    ctx->pc = 0x1F32D4u;
    if (runtime->hasFunction(0x1F32D4u)) {
        auto targetFn = runtime->lookupFunction(0x1F32D4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E783Cu; }
        if (ctx->pc != 0x1E783Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F32D4_0x1f32d4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E783Cu; }
        if (ctx->pc != 0x1E783Cu) { return; }
    }
    ctx->pc = 0x1E783Cu;
label_1e783c:
    // 0x1e783c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1e783cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7840: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7840u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7844: 0xc07cced  jal         func_1F33B4
    ctx->pc = 0x1E7844u;
    SET_GPR_U32(ctx, 31, 0x1E784Cu);
    ctx->pc = 0x1F33B4u;
    if (runtime->hasFunction(0x1F33B4u)) {
        auto targetFn = runtime->lookupFunction(0x1F33B4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E784Cu; }
        if (ctx->pc != 0x1E784Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F33B4_0x1f33b4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E784Cu; }
        if (ctx->pc != 0x1E784Cu) { return; }
    }
    ctx->pc = 0x1E784Cu;
label_1e784c:
    // 0x1e784c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1e784cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7850: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7850u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7854: 0xc07cccb  jal         func_1F332C
    ctx->pc = 0x1E7854u;
    SET_GPR_U32(ctx, 31, 0x1E785Cu);
    ctx->pc = 0x1F332Cu;
    if (runtime->hasFunction(0x1F332Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F332Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E785Cu; }
        if (ctx->pc != 0x1E785Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F332C_0x1f332c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E785Cu; }
        if (ctx->pc != 0x1E785Cu) { return; }
    }
    ctx->pc = 0x1E785Cu;
label_1e785c:
    // 0x1e785c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e785cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7860: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7860u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7864: 0x8c420510  lw          $v0, 0x510($v0)
    ctx->pc = 0x1e7864u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1296)));
    // 0x1e7868: 0x2021018  mult        $v0, $s0, $v0
    ctx->pc = 0x1e7868u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1e786c: 0x2221023  subu        $v0, $s1, $v0
    ctx->pc = 0x1e786cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1e7870: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1e7870u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e7874: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7874u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
label_1e7878:
    // 0x1e7878: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7878u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e787c: 0xc07ccb5  jal         func_1F32D4
    ctx->pc = 0x1E787Cu;
    SET_GPR_U32(ctx, 31, 0x1E7884u);
    ctx->pc = 0x1F32D4u;
    if (runtime->hasFunction(0x1F32D4u)) {
        auto targetFn = runtime->lookupFunction(0x1F32D4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7884u; }
        if (ctx->pc != 0x1E7884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F32D4_0x1f32d4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7884u; }
        if (ctx->pc != 0x1E7884u) { return; }
    }
    ctx->pc = 0x1E7884u;
label_1e7884:
    // 0x1e7884: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1e7884u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7888: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7888u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e788c: 0xc07cced  jal         func_1F33B4
    ctx->pc = 0x1E788Cu;
    SET_GPR_U32(ctx, 31, 0x1E7894u);
    ctx->pc = 0x1F33B4u;
    if (runtime->hasFunction(0x1F33B4u)) {
        auto targetFn = runtime->lookupFunction(0x1F33B4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7894u; }
        if (ctx->pc != 0x1E7894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F33B4_0x1f33b4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7894u; }
        if (ctx->pc != 0x1E7894u) { return; }
    }
    ctx->pc = 0x1E7894u;
label_1e7894:
    // 0x1e7894: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1e7894u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7898: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e7898u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e789c: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1E789Cu;
    SET_GPR_U32(ctx, 31, 0x1E78A4u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E78A4u; }
        if (ctx->pc != 0x1E78A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E78A4u; }
        if (ctx->pc != 0x1E78A4u) { return; }
    }
    ctx->pc = 0x1E78A4u;
label_1e78a4:
    // 0x1e78a4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e78a4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e78a8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e78a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e78ac: 0x624821  addu        $t1, $v1, $v0
    ctx->pc = 0x1e78acu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e78b0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e78b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e78b4: 0x24420510  addiu       $v0, $v0, 0x510
    ctx->pc = 0x1e78b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1296));
    // 0x1e78b8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e78b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e78bc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e78bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e78c0: 0x8c6504fc  lw          $a1, 0x4FC($v1)
    ctx->pc = 0x1e78c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1276)));
    // 0x1e78c4: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1e78c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e78c8: 0x8fc7000c  lw          $a3, 0xC($fp)
    ctx->pc = 0x1e78c8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e78cc: 0x200402d  daddu       $t0, $s0, $zero
    ctx->pc = 0x1e78ccu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e78d0: 0xc07c3ae  jal         func_1F0EB8
    ctx->pc = 0x1E78D0u;
    SET_GPR_U32(ctx, 31, 0x1E78D8u);
    ctx->pc = 0x1F0EB8u;
    if (runtime->hasFunction(0x1F0EB8u)) {
        auto targetFn = runtime->lookupFunction(0x1F0EB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E78D8u; }
        if (ctx->pc != 0x1E78D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0EB8_0x1f0eb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E78D8u; }
        if (ctx->pc != 0x1E78D8u) { return; }
    }
    ctx->pc = 0x1E78D8u;
label_1e78d8:
    // 0x1e78d8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e78d8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e78dc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1e78dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e78e0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1e78e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e78e4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e78e4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e78e8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e78e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e78ec: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e78ecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e78f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E78F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7828u: goto label_1e7828;
            case 0x1E783Cu: goto label_1e783c;
            case 0x1E784Cu: goto label_1e784c;
            case 0x1E785Cu: goto label_1e785c;
            case 0x1E7878u: goto label_1e7878;
            case 0x1E7884u: goto label_1e7884;
            case 0x1E7894u: goto label_1e7894;
            case 0x1E78A4u: goto label_1e78a4;
            case 0x1E78D8u: goto label_1e78d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E78F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
