#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A738
// Address: 0x13a738 - 0x13a910
void sub_0013A738_0x13a738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A738_0x13a738");
#endif

    switch (ctx->pc) {
        case 0x13a788u: goto label_13a788;
        case 0x13a7bcu: goto label_13a7bc;
        case 0x13a7c4u: goto label_13a7c4;
        case 0x13a7c8u: goto label_13a7c8;
        case 0x13a7d0u: goto label_13a7d0;
        case 0x13a7e0u: goto label_13a7e0;
        case 0x13a7e8u: goto label_13a7e8;
        case 0x13a7f4u: goto label_13a7f4;
        case 0x13a80cu: goto label_13a80c;
        case 0x13a83cu: goto label_13a83c;
        case 0x13a850u: goto label_13a850;
        case 0x13a870u: goto label_13a870;
        case 0x13a8b0u: goto label_13a8b0;
        case 0x13a8d8u: goto label_13a8d8;
        default: break;
    }

    ctx->pc = 0x13a738u;

    // 0x13a738: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x13a738u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x13a73c: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x13a73cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x13a740: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x13a740u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a744: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x13a744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x13a748: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x13a748u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a74c: 0xffb50068  sd          $s5, 0x68($sp)
    ctx->pc = 0x13a74cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 21));
    // 0x13a750: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x13a750u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a754: 0xffbe0080  sd          $fp, 0x80($sp)
    ctx->pc = 0x13a754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 30));
    // 0x13a758: 0xf02d  daddu       $fp, $zero, $zero
    ctx->pc = 0x13a758u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a75c: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x13a75cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x13a760: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x13a760u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x13a764: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x13a764u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x13a768: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x13a768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x13a76c: 0xffb70078  sd          $s7, 0x78($sp)
    ctx->pc = 0x13a76cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 23));
    // 0x13a770: 0xffbf0088  sd          $ra, 0x88($sp)
    ctx->pc = 0x13a770u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 31));
    // 0x13a774: 0x1ac00045  blez        $s6, . + 4 + (0x45 << 2)
    ctx->pc = 0x13A774u;
    {
        const bool branch_taken_0x13a774 = (GPR_S64(ctx, 22) <= 0);
        ctx->pc = 0x13A778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A774u;
            // 0x13a778: 0xafa00030  sw          $zero, 0x30($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a774) {
            ctx->pc = 0x13A88Cu;
            goto label_13a88c;
        }
    }
    ctx->pc = 0x13A77Cu;
    // 0x13a77c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13a77cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13a780: 0x2a0902d  daddu       $s2, $s5, $zero
    ctx->pc = 0x13a780u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a784: 0x2457d8d0  addiu       $s7, $v0, -0x2730
    ctx->pc = 0x13a784u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957264));
label_13a788:
    // 0x13a788: 0x8ee2000c  lw          $v0, 0xC($s7)
    ctx->pc = 0x13a788u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 12)));
    // 0x13a78c: 0x8ee30008  lw          $v1, 0x8($s7)
    ctx->pc = 0x13a78cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 8)));
    // 0x13a790: 0x542018  mult        $a0, $v0, $s4
    ctx->pc = 0x13a790u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x13a794: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x13a794u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x13a798: 0x941021  addu        $v0, $a0, $s4
    ctx->pc = 0x13a798u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 20)));
    // 0x13a79c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13a79cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13a7a0: 0x2a38821  addu        $s1, $s5, $v1
    ctx->pc = 0x13a7a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x13a7a4: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x13a7a4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13a7a8: 0x10400034  beqz        $v0, . + 4 + (0x34 << 2)
    ctx->pc = 0x13A7A8u;
    {
        const bool branch_taken_0x13a7a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A7ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A7A8u;
            // 0x13a7ac: 0x3c130022  lui         $s3, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a7a8) {
            ctx->pc = 0x13A87Cu;
            goto label_13a87c;
        }
    }
    ctx->pc = 0x13A7B0u;
    // 0x13a7b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13a7b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a7b4: 0xc04e892  jal         func_13A248
    ctx->pc = 0x13A7B4u;
    SET_GPR_U32(ctx, 31, 0x13A7BCu);
    ctx->pc = 0x13A7B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A7B4u;
            // 0x13a7b8: 0x2665d9f8  addiu       $a1, $s3, -0x2608 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 4294957560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A248u;
    if (runtime->hasFunction(0x13A248u)) {
        auto targetFn = runtime->lookupFunction(0x13A248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7BCu; }
        if (ctx->pc != 0x13A7BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A248_0x13a248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7BCu; }
        if (ctx->pc != 0x13A7BCu) { return; }
    }
    ctx->pc = 0x13A7BCu;
label_13a7bc:
    // 0x13a7bc: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A7BCu;
    SET_GPR_U32(ctx, 31, 0x13A7C4u);
    ctx->pc = 0x13A7C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A7BCu;
            // 0x13a7c0: 0x34049400  ori         $a0, $zero, 0x9400 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37888);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7C4u; }
        if (ctx->pc != 0x13A7C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7C4u; }
        if (ctx->pc != 0x13A7C4u) { return; }
    }
    ctx->pc = 0x13A7C4u;
label_13a7c4:
    // 0x13a7c4: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x13a7c4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13a7c8:
    // 0x13a7c8: 0xc04035e  jal         func_100D78
    ctx->pc = 0x13A7C8u;
    SET_GPR_U32(ctx, 31, 0x13A7D0u);
    ctx->pc = 0x13A7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A7C8u;
            // 0x13a7cc: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7D0u; }
        if (ctx->pc != 0x13A7D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7D0u; }
        if (ctx->pc != 0x13A7D0u) { return; }
    }
    ctx->pc = 0x13A7D0u;
label_13a7d0:
    // 0x13a7d0: 0x1050fffd  beq         $v0, $s0, . + 4 + (-0x3 << 2)
    ctx->pc = 0x13A7D0u;
    {
        const bool branch_taken_0x13a7d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        if (branch_taken_0x13a7d0) {
            ctx->pc = 0x13A7C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13a7c8;
        }
    }
    ctx->pc = 0x13A7D8u;
    // 0x13a7d8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A7D8u;
    SET_GPR_U32(ctx, 31, 0x13A7E0u);
    ctx->pc = 0x13A7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A7D8u;
            // 0x13a7dc: 0x34049401  ori         $a0, $zero, 0x9401 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)37889);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7E0u; }
        if (ctx->pc != 0x13A7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7E0u; }
        if (ctx->pc != 0x13A7E0u) { return; }
    }
    ctx->pc = 0x13A7E0u;
label_13a7e0:
    // 0x13a7e0: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A7E0u;
    SET_GPR_U32(ctx, 31, 0x13A7E8u);
    ctx->pc = 0x13A7E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A7E0u;
            // 0x13a7e4: 0x34049500  ori         $a0, $zero, 0x9500 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)38144);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7E8u; }
        if (ctx->pc != 0x13A7E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7E8u; }
        if (ctx->pc != 0x13A7E8u) { return; }
    }
    ctx->pc = 0x13A7E8u;
label_13a7e8:
    // 0x13a7e8: 0x2665d9f8  addiu       $a1, $s3, -0x2608
    ctx->pc = 0x13a7e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), 4294957560));
    // 0x13a7ec: 0xc04e58a  jal         func_139628
    ctx->pc = 0x13A7ECu;
    SET_GPR_U32(ctx, 31, 0x13A7F4u);
    ctx->pc = 0x13A7F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A7ECu;
            // 0x13a7f0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139628u;
    if (runtime->hasFunction(0x139628u)) {
        auto targetFn = runtime->lookupFunction(0x139628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7F4u; }
        if (ctx->pc != 0x13A7F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139628_0x139628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A7F4u; }
        if (ctx->pc != 0x13A7F4u) { return; }
    }
    ctx->pc = 0x13A7F4u;
label_13a7f4:
    // 0x13a7f4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13a7f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13a7f8: 0x14430013  bne         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x13A7F8u;
    {
        const bool branch_taken_0x13a7f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x13a7f8) {
            ctx->pc = 0x13A848u;
            goto label_13a848;
        }
    }
    ctx->pc = 0x13A800u;
    // 0x13a800: 0x34049501  ori         $a0, $zero, 0x9501
    ctx->pc = 0x13a800u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)38145);
    // 0x13a804: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A804u;
    SET_GPR_U32(ctx, 31, 0x13A80Cu);
    ctx->pc = 0x13A808u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A804u;
            // 0x13a808: 0x27de0001  addiu       $fp, $fp, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A80Cu; }
        if (ctx->pc != 0x13A80Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A80Cu; }
        if (ctx->pc != 0x13A80Cu) { return; }
    }
    ctx->pc = 0x13A80Cu;
label_13a80c:
    // 0x13a80c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13a80cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13a810: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x13a810u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13a814: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x13a814u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13a818: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x13a818u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x13a81c: 0xae430004  sw          $v1, 0x4($s2)
    ctx->pc = 0x13a81cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
    // 0x13a820: 0x8c82d8e8  lw          $v0, -0x2718($a0)
    ctx->pc = 0x13a820u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294957288)));
    // 0x13a824: 0x54400016  bnel        $v0, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x13A824u;
    {
        const bool branch_taken_0x13a824 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13a824) {
            ctx->pc = 0x13A828u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13A824u;
            // 0x13a828: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13A880u;
            goto label_13a880;
        }
    }
    ctx->pc = 0x13A82Cu;
    // 0x13a82c: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x13a82cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x13a830: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x13a830u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a834: 0xc045a12  jal         func_116848
    ctx->pc = 0x13A834u;
    SET_GPR_U32(ctx, 31, 0x13A83Cu);
    ctx->pc = 0x13A838u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A834u;
            // 0x13a838: 0x2444cc88  addiu       $a0, $v0, -0x3378 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A83Cu; }
        if (ctx->pc != 0x13A83Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A83Cu; }
        if (ctx->pc != 0x13A83Cu) { return; }
    }
    ctx->pc = 0x13A83Cu;
label_13a83c:
    // 0x13a83c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x13A83Cu;
    {
        const bool branch_taken_0x13a83c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A83Cu;
            // 0x13a840: 0x26940001  addiu       $s4, $s4, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a83c) {
            ctx->pc = 0x13A880u;
            goto label_13a880;
        }
    }
    ctx->pc = 0x13A844u;
    // 0x13a844: 0x0  nop
    ctx->pc = 0x13a844u;
    // NOP
label_13a848:
    // 0x13a848: 0xc04e082  jal         func_138208
    ctx->pc = 0x13A848u;
    SET_GPR_U32(ctx, 31, 0x13A850u);
    ctx->pc = 0x13A84Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A848u;
            // 0x13a84c: 0x34049502  ori         $a0, $zero, 0x9502 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)38146);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A850u; }
        if (ctx->pc != 0x13A850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A850u; }
        if (ctx->pc != 0x13A850u) { return; }
    }
    ctx->pc = 0x13A850u;
label_13a850:
    // 0x13a850: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13a850u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13a854: 0x8c62d8e8  lw          $v0, -0x2718($v1)
    ctx->pc = 0x13a854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294957288)));
    // 0x13a858: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x13A858u;
    {
        const bool branch_taken_0x13a858 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13a858) {
            ctx->pc = 0x13A85Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13A858u;
            // 0x13a85c: 0x8fa30030  lw          $v1, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13A874u;
            goto label_13a874;
        }
    }
    ctx->pc = 0x13A860u;
    // 0x13a860: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x13a860u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x13a864: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x13a864u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a868: 0xc045a12  jal         func_116848
    ctx->pc = 0x13A868u;
    SET_GPR_U32(ctx, 31, 0x13A870u);
    ctx->pc = 0x13A86Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A868u;
            // 0x13a86c: 0x2444cca0  addiu       $a0, $v0, -0x3360 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A870u; }
        if (ctx->pc != 0x13A870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A870u; }
        if (ctx->pc != 0x13A870u) { return; }
    }
    ctx->pc = 0x13A870u;
label_13a870:
    // 0x13a870: 0x8fa30030  lw          $v1, 0x30($sp)
    ctx->pc = 0x13a870u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_13a874:
    // 0x13a874: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13a874u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13a878: 0xafa30030  sw          $v1, 0x30($sp)
    ctx->pc = 0x13a878u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 3));
label_13a87c:
    // 0x13a87c: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x13a87cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_13a880:
    // 0x13a880: 0x296102a  slt         $v0, $s4, $s6
    ctx->pc = 0x13a880u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 22)) ? 1 : 0);
    // 0x13a884: 0x1440ffc0  bnez        $v0, . + 4 + (-0x40 << 2)
    ctx->pc = 0x13A884u;
    {
        const bool branch_taken_0x13a884 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13A888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A884u;
            // 0x13a888: 0x26520008  addiu       $s2, $s2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a884) {
            ctx->pc = 0x13A788u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13a788;
        }
    }
    ctx->pc = 0x13A88Cu;
label_13a88c:
    // 0x13a88c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13a88cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13a890: 0x2490d8e8  addiu       $s0, $a0, -0x2718
    ctx->pc = 0x13a890u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957288));
    // 0x13a894: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13a894u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13a898: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x13A898u;
    {
        const bool branch_taken_0x13a898 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13a898) {
            ctx->pc = 0x13A89Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13A898u;
            // 0x13a89c: 0x8fa20030  lw          $v0, 0x30($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13A8B4u;
            goto label_13a8b4;
        }
    }
    ctx->pc = 0x13A8A0u;
    // 0x13a8a0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13a8a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13a8a4: 0x3c0282d  daddu       $a1, $fp, $zero
    ctx->pc = 0x13a8a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a8a8: 0xc045a12  jal         func_116848
    ctx->pc = 0x13A8A8u;
    SET_GPR_U32(ctx, 31, 0x13A8B0u);
    ctx->pc = 0x13A8ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A8A8u;
            // 0x13a8ac: 0x2484ccb8  addiu       $a0, $a0, -0x3348 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A8B0u; }
        if (ctx->pc != 0x13A8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A8B0u; }
        if (ctx->pc != 0x13A8B0u) { return; }
    }
    ctx->pc = 0x13A8B0u;
label_13a8b0:
    // 0x13a8b0: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x13a8b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_13a8b4:
    // 0x13a8b4: 0x18400009  blez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13A8B4u;
    {
        const bool branch_taken_0x13a8b4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13A8B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A8B4u;
            // 0x13a8b8: 0x3c0102d  daddu       $v0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a8b4) {
            ctx->pc = 0x13A8DCu;
            goto label_13a8dc;
        }
    }
    ctx->pc = 0x13A8BCu;
    // 0x13a8bc: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x13a8bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13a8c0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x13a8c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x13a8c4: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13A8C4u;
    {
        const bool branch_taken_0x13a8c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13A8C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A8C4u;
            // 0x13a8c8: 0x2405000a  addiu       $a1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a8c4) {
            ctx->pc = 0x13A8D8u;
            goto label_13a8d8;
        }
    }
    ctx->pc = 0x13A8CCu;
    // 0x13a8cc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13a8ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13a8d0: 0xc045a12  jal         func_116848
    ctx->pc = 0x13A8D0u;
    SET_GPR_U32(ctx, 31, 0x13A8D8u);
    ctx->pc = 0x13A8D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A8D0u;
            // 0x13a8d4: 0x2484ccd0  addiu       $a0, $a0, -0x3330 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A8D8u; }
        if (ctx->pc != 0x13A8D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A8D8u; }
        if (ctx->pc != 0x13A8D8u) { return; }
    }
    ctx->pc = 0x13A8D8u;
label_13a8d8:
    // 0x13a8d8: 0x3c0102d  daddu       $v0, $fp, $zero
    ctx->pc = 0x13a8d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
label_13a8dc:
    // 0x13a8dc: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x13a8dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x13a8e0: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x13a8e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x13a8e4: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x13a8e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x13a8e8: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x13a8e8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x13a8ec: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x13a8ecu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x13a8f0: 0xdfb50068  ld          $s5, 0x68($sp)
    ctx->pc = 0x13a8f0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x13a8f4: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x13a8f4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x13a8f8: 0xdfb70078  ld          $s7, 0x78($sp)
    ctx->pc = 0x13a8f8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x13a8fc: 0xdfbe0080  ld          $fp, 0x80($sp)
    ctx->pc = 0x13a8fcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x13a900: 0xdfbf0088  ld          $ra, 0x88($sp)
    ctx->pc = 0x13a900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x13a904: 0x3e00008  jr          $ra
    ctx->pc = 0x13A904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A904u;
            // 0x13a908: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A788u: goto label_13a788;
            case 0x13A7BCu: goto label_13a7bc;
            case 0x13A7C4u: goto label_13a7c4;
            case 0x13A7C8u: goto label_13a7c8;
            case 0x13A7D0u: goto label_13a7d0;
            case 0x13A7E0u: goto label_13a7e0;
            case 0x13A7E8u: goto label_13a7e8;
            case 0x13A7F4u: goto label_13a7f4;
            case 0x13A80Cu: goto label_13a80c;
            case 0x13A83Cu: goto label_13a83c;
            case 0x13A848u: goto label_13a848;
            case 0x13A850u: goto label_13a850;
            case 0x13A870u: goto label_13a870;
            case 0x13A874u: goto label_13a874;
            case 0x13A87Cu: goto label_13a87c;
            case 0x13A880u: goto label_13a880;
            case 0x13A88Cu: goto label_13a88c;
            case 0x13A8B0u: goto label_13a8b0;
            case 0x13A8B4u: goto label_13a8b4;
            case 0x13A8D8u: goto label_13a8d8;
            case 0x13A8DCu: goto label_13a8dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A90Cu;
    // 0x13a90c: 0x0  nop
    ctx->pc = 0x13a90cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
