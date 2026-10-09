#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00184828
// Address: 0x184828 - 0x184aa0
void sub_00184828_0x184828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00184828_0x184828");
#endif

    switch (ctx->pc) {
        case 0x18486cu: goto label_18486c;
        case 0x1848b0u: goto label_1848b0;
        case 0x1848c0u: goto label_1848c0;
        case 0x1848e0u: goto label_1848e0;
        case 0x18490cu: goto label_18490c;
        case 0x1849a8u: goto label_1849a8;
        case 0x1849b8u: goto label_1849b8;
        case 0x1849e0u: goto label_1849e0;
        case 0x184a0cu: goto label_184a0c;
        case 0x184a28u: goto label_184a28;
        case 0x184a6cu: goto label_184a6c;
        default: break;
    }

    ctx->pc = 0x184828u;

    // 0x184828: 0x27bdfd20  addiu       $sp, $sp, -0x2E0
    ctx->pc = 0x184828u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966560));
    // 0x18482c: 0xffb10298  sd          $s1, 0x298($sp)
    ctx->pc = 0x18482cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 664), GPR_U64(ctx, 17));
    // 0x184830: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x184830u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184834: 0xffb202a0  sd          $s2, 0x2A0($sp)
    ctx->pc = 0x184834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 672), GPR_U64(ctx, 18));
    // 0x184838: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x184838u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18483c: 0xffb302a8  sd          $s3, 0x2A8($sp)
    ctx->pc = 0x18483cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 680), GPR_U64(ctx, 19));
    // 0x184840: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x184840u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184844: 0xffb402b0  sd          $s4, 0x2B0($sp)
    ctx->pc = 0x184844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 688), GPR_U64(ctx, 20));
    // 0x184848: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x184848u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18484c: 0xffb602c0  sd          $s6, 0x2C0($sp)
    ctx->pc = 0x18484cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 704), GPR_U64(ctx, 22));
    // 0x184850: 0xffb00290  sd          $s0, 0x290($sp)
    ctx->pc = 0x184850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 656), GPR_U64(ctx, 16));
    // 0x184854: 0xffb502b8  sd          $s5, 0x2B8($sp)
    ctx->pc = 0x184854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 696), GPR_U64(ctx, 21));
    // 0x184858: 0xffb702c8  sd          $s7, 0x2C8($sp)
    ctx->pc = 0x184858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 712), GPR_U64(ctx, 23));
    // 0x18485c: 0xffbe02d0  sd          $fp, 0x2D0($sp)
    ctx->pc = 0x18485cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 720), GPR_U64(ctx, 30));
    // 0x184860: 0xffbf02d8  sd          $ra, 0x2D8($sp)
    ctx->pc = 0x184860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 728), GPR_U64(ctx, 31));
    // 0x184864: 0xc062210  jal         func_188840
    ctx->pc = 0x184864u;
    SET_GPR_U32(ctx, 31, 0x18486Cu);
    ctx->pc = 0x184868u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184864u;
            // 0x184868: 0x80b02d  daddu       $s6, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18486Cu; }
        if (ctx->pc != 0x18486Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18486Cu; }
        if (ctx->pc != 0x18486Cu) { return; }
    }
    ctx->pc = 0x18486Cu;
label_18486c:
    // 0x18486c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18486Cu;
    {
        const bool branch_taken_0x18486c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x184870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18486Cu;
            // 0x184870: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18486c) {
            ctx->pc = 0x184880u;
            goto label_184880;
        }
    }
    ctx->pc = 0x184874u;
    // 0x184874: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184874u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184878: 0x1000007d  b           . + 4 + (0x7D << 2)
    ctx->pc = 0x184878u;
    {
        const bool branch_taken_0x184878 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18487Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184878u;
            // 0x18487c: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184878) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x184880u;
label_184880:
    // 0x184880: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184880u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184884: 0x2c31818  mult        $v1, $s6, $v1
    ctx->pc = 0x184884u;
    { int64_t result = (int64_t)GPR_S32(ctx, 22) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x184888: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x184888u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x18488c: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x18488cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x184890: 0x8c8463d4  lw          $a0, 0x63D4($a0)
    ctx->pc = 0x184890u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 25556)));
    // 0x184894: 0x10800076  beqz        $a0, . + 4 + (0x76 << 2)
    ctx->pc = 0x184894u;
    {
        const bool branch_taken_0x184894 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x184898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184894u;
            // 0x184898: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184894) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x18489Cu;
    // 0x18489c: 0x27b00200  addiu       $s0, $sp, 0x200
    ctx->pc = 0x18489cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x1848a0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1848a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1848a4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1848a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1848a8: 0xc0609a2  jal         func_182688
    ctx->pc = 0x1848A8u;
    SET_GPR_U32(ctx, 31, 0x1848B0u);
    ctx->pc = 0x1848ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1848A8u;
            // 0x1848ac: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1848B0u; }
        if (ctx->pc != 0x1848B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1848B0u; }
        if (ctx->pc != 0x1848B0u) { return; }
    }
    ctx->pc = 0x1848B0u;
label_1848b0:
    // 0x1848b0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1848B0u;
    {
        const bool branch_taken_0x1848b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1848B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1848B0u;
            // 0x1848b4: 0xafa20280  sw          $v0, 0x280($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 640), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1848b0) {
            ctx->pc = 0x1848C8u;
            goto label_1848c8;
        }
    }
    ctx->pc = 0x1848B8u;
    // 0x1848b8: 0xc06089c  jal         func_182270
    ctx->pc = 0x1848B8u;
    SET_GPR_U32(ctx, 31, 0x1848C0u);
    ctx->pc = 0x1848BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1848B8u;
            // 0x1848bc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1848C0u; }
        if (ctx->pc != 0x1848C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1848C0u; }
        if (ctx->pc != 0x1848C0u) { return; }
    }
    ctx->pc = 0x1848C0u;
label_1848c0:
    // 0x1848c0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1848C0u;
    {
        const bool branch_taken_0x1848c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1848c0) {
            ctx->pc = 0x1848D8u;
            goto label_1848d8;
        }
    }
    ctx->pc = 0x1848C8u;
label_1848c8:
    // 0x1848c8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1848c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1848cc: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x1848CCu;
    {
        const bool branch_taken_0x1848cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1848D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1848CCu;
            // 0x1848d0: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1848cc) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x1848D4u;
    // 0x1848d4: 0x0  nop
    ctx->pc = 0x1848d4u;
    // NOP
label_1848d8:
    // 0x1848d8: 0xc060880  jal         func_182200
    ctx->pc = 0x1848D8u;
    SET_GPR_U32(ctx, 31, 0x1848E0u);
    ctx->pc = 0x1848DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1848D8u;
            // 0x1848dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1848E0u; }
        if (ctx->pc != 0x1848E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1848E0u; }
        if (ctx->pc != 0x1848E0u) { return; }
    }
    ctx->pc = 0x1848E0u;
label_1848e0:
    // 0x1848e0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1848E0u;
    {
        const bool branch_taken_0x1848e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1848E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1848E0u;
            // 0x1848e4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1848e0) {
            ctx->pc = 0x1848F8u;
            goto label_1848f8;
        }
    }
    ctx->pc = 0x1848E8u;
    // 0x1848e8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1848e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1848ec: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1848ECu;
    {
        const bool branch_taken_0x1848ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1848F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1848ECu;
            // 0x1848f0: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1848ec) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x1848F4u;
    // 0x1848f4: 0x0  nop
    ctx->pc = 0x1848f4u;
    // NOP
label_1848f8:
    // 0x1848f8: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1848f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1848fc: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1848fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184900: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x184900u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184904: 0xc0610d8  jal         func_184360
    ctx->pc = 0x184904u;
    SET_GPR_U32(ctx, 31, 0x18490Cu);
    ctx->pc = 0x184908u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184904u;
            // 0x184908: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x184360u;
    if (runtime->hasFunction(0x184360u)) {
        auto targetFn = runtime->lookupFunction(0x184360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18490Cu; }
        if (ctx->pc != 0x18490Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00184360_0x184360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18490Cu; }
        if (ctx->pc != 0x18490Cu) { return; }
    }
    ctx->pc = 0x18490Cu;
label_18490c:
    // 0x18490c: 0x3c038101  lui         $v1, 0x8101
    ctx->pc = 0x18490cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33025 << 16));
    // 0x184910: 0x34630011  ori         $v1, $v1, 0x11
    ctx->pc = 0x184910u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)17);
    // 0x184914: 0x14430056  bne         $v0, $v1, . + 4 + (0x56 << 2)
    ctx->pc = 0x184914u;
    {
        const bool branch_taken_0x184914 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x184918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184914u;
            // 0x184918: 0xafa20280  sw          $v0, 0x280($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 640), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184914) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x18491Cu;
    // 0x18491c: 0x97a40000  lhu         $a0, 0x0($sp)
    ctx->pc = 0x18491cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x184920: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184920u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184924: 0x30830001  andi        $v1, $a0, 0x1
    ctx->pc = 0x184924u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x184928: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x184928u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x18492c: 0x10600050  beqz        $v1, . + 4 + (0x50 << 2)
    ctx->pc = 0x18492Cu;
    {
        const bool branch_taken_0x18492c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x184930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18492Cu;
            // 0x184930: 0x3442000d  ori         $v0, $v0, 0xD (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)13);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18492c) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x184934u;
    // 0x184934: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184934u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184938: 0x30832000  andi        $v1, $a0, 0x2000
    ctx->pc = 0x184938u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8192);
    // 0x18493c: 0x1460004c  bnez        $v1, . + 4 + (0x4C << 2)
    ctx->pc = 0x18493Cu;
    {
        const bool branch_taken_0x18493c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x184940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18493Cu;
            // 0x184940: 0x3442000d  ori         $v0, $v0, 0xD (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)13);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18493c) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x184944u;
    // 0x184944: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184944u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184948: 0x30830020  andi        $v1, $a0, 0x20
    ctx->pc = 0x184948u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32);
    // 0x18494c: 0x14600048  bnez        $v1, . + 4 + (0x48 << 2)
    ctx->pc = 0x18494Cu;
    {
        const bool branch_taken_0x18494c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x184950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18494Cu;
            // 0x184950: 0x34420002  ori         $v0, $v0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18494c) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x184954u;
    // 0x184954: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x184954u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x184958: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184958u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18495c: 0xd2182a  slt         $v1, $a2, $s2
    ctx->pc = 0x18495cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x184960: 0x14600043  bnez        $v1, . + 4 + (0x43 << 2)
    ctx->pc = 0x184960u;
    {
        const bool branch_taken_0x184960 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x184964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184960u;
            // 0x184964: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184960) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x184968u;
    // 0x184968: 0xd21823  subu        $v1, $a2, $s2
    ctx->pc = 0x184968u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x18496c: 0x8fa40010  lw          $a0, 0x10($sp)
    ctx->pc = 0x18496cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x184970: 0x74a00a  movz        $s4, $v1, $s4
    ctx->pc = 0x184970u;
    if (GPR_U64(ctx, 20) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 3));
    // 0x184974: 0x3c177fff  lui         $s7, 0x7FFF
    ctx->pc = 0x184974u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)32767 << 16));
    // 0x184978: 0x2921021  addu        $v0, $s4, $s2
    ctx->pc = 0x184978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
    // 0x18497c: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x18497cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x184980: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x184980u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x184984: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x184984u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184988: 0x62a00b  movn        $s4, $v1, $v0
    ctx->pc = 0x184988u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 3));
    // 0x18498c: 0x241effff  addiu       $fp, $zero, -0x1
    ctx->pc = 0x18498cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x184990: 0xafb40284  sw          $s4, 0x284($sp)
    ctx->pc = 0x184990u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 644), GPR_U32(ctx, 20));
    // 0x184994: 0x14850008  bne         $a0, $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x184994u;
    {
        const bool branch_taken_0x184994 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 5));
        ctx->pc = 0x184998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184994u;
            // 0x184998: 0x36f7ffff  ori         $s7, $s7, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184994) {
            ctx->pc = 0x1849B8u;
            goto label_1849b8;
        }
    }
    ctx->pc = 0x18499Cu;
    // 0x18499c: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x18499Cu;
    {
        const bool branch_taken_0x18499c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1849A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18499Cu;
            // 0x1849a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18499c) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x1849A4u;
    // 0x1849a4: 0x0  nop
    ctx->pc = 0x1849a4u;
    // NOP
label_1849a8:
    // 0x1849a8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1849a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1849ac: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1849ACu;
    {
        const bool branch_taken_0x1849ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1849B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1849ACu;
            // 0x1849b0: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1849ac) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x1849B4u;
    // 0x1849b4: 0x0  nop
    ctx->pc = 0x1849b4u;
    // NOP
label_1849b8:
    // 0x1849b8: 0x2a420400  slti        $v0, $s2, 0x400
    ctx->pc = 0x1849b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x1849bc: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1849BCu;
    {
        const bool branch_taken_0x1849bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1849C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1849BCu;
            // 0x1849c0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1849bc) {
            ctx->pc = 0x184A1Cu;
            goto label_184a1c;
        }
    }
    ctx->pc = 0x1849C4u;
    // 0x1849c4: 0x3c150028  lui         $s5, 0x28
    ctx->pc = 0x1849c4u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)40 << 16));
    // 0x1849c8: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1849c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1849cc: 0x26b06c80  addiu       $s0, $s5, 0x6C80
    ctx->pc = 0x1849ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 27776));
    // 0x1849d0: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1849d0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1849d4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1849d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1849d8: 0xc061d1e  jal         func_187478
    ctx->pc = 0x1849D8u;
    SET_GPR_U32(ctx, 31, 0x1849E0u);
    ctx->pc = 0x1849DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1849D8u;
            // 0x1849dc: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x187478u;
    if (runtime->hasFunction(0x187478u)) {
        auto targetFn = runtime->lookupFunction(0x187478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1849E0u; }
        if (ctx->pc != 0x1849E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00187478_0x187478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1849E0u; }
        if (ctx->pc != 0x1849E0u) { return; }
    }
    ctx->pc = 0x1849E0u;
label_1849e0:
    // 0x1849e0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1849e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1849e4: 0x2502821  addu        $a1, $s2, $s0
    ctx->pc = 0x1849e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x1849e8: 0x1040ffef  beqz        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1849E8u;
    {
        const bool branch_taken_0x1849e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1849ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1849E8u;
            // 0x1849ec: 0xafa20280  sw          $v0, 0x280($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 640), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1849e8) {
            ctx->pc = 0x1849A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1849a8;
        }
    }
    ctx->pc = 0x1849F0u;
    // 0x1849f0: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x1849f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1849f4: 0x528023  subu        $s0, $v0, $s2
    ctx->pc = 0x1849f4u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1849f8: 0x214102a  slt         $v0, $s0, $s4
    ctx->pc = 0x1849f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x1849fc: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1849FCu;
    {
        const bool branch_taken_0x1849fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x184A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1849FCu;
            // 0x184a00: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1849fc) {
            ctx->pc = 0x184A58u;
            goto label_184a58;
        }
    }
    ctx->pc = 0x184A04u;
    // 0x184a04: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x184A04u;
    SET_GPR_U32(ctx, 31, 0x184A0Cu);
    ctx->pc = 0x184A08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184A04u;
            // 0x184a08: 0x2709821  addu        $s3, $s3, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184A0Cu; }
        if (ctx->pc != 0x184A0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184A0Cu; }
        if (ctx->pc != 0x184A0Cu) { return; }
    }
    ctx->pc = 0x184A0Cu;
label_184a0c:
    // 0x184a0c: 0x2921821  addu        $v1, $s4, $s2
    ctx->pc = 0x184a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
    // 0x184a10: 0x2474fc00  addiu       $s4, $v1, -0x400
    ctx->pc = 0x184a10u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966272));
    // 0x184a14: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x184a14u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184a18: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x184a18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_184a1c:
    // 0x184a1c: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x184a1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184a20: 0xc060b02  jal         func_182C08
    ctx->pc = 0x184A20u;
    SET_GPR_U32(ctx, 31, 0x184A28u);
    ctx->pc = 0x184A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184A20u;
            // 0x184a24: 0x27a60280  addiu       $a2, $sp, 0x280 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182C08u;
    if (runtime->hasFunction(0x182C08u)) {
        auto targetFn = runtime->lookupFunction(0x182C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184A28u; }
        if (ctx->pc != 0x184A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182C08_0x182c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184A28u; }
        if (ctx->pc != 0x184A28u) { return; }
    }
    ctx->pc = 0x184A28u;
label_184a28:
    // 0x184a28: 0x8fa30280  lw          $v1, 0x280($sp)
    ctx->pc = 0x184a28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x184a2c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x184a2cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184a30: 0x1460000f  bnez        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x184A30u;
    {
        const bool branch_taken_0x184a30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x184A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184A30u;
            // 0x184a34: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184a30) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x184A38u;
    // 0x184a38: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184a38u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184a3c: 0x123e000c  beq         $s1, $fp, . + 4 + (0xC << 2)
    ctx->pc = 0x184A3Cu;
    {
        const bool branch_taken_0x184a3c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 30));
        ctx->pc = 0x184A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184A3Cu;
            // 0x184a40: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184a3c) {
            ctx->pc = 0x184A70u;
            goto label_184a70;
        }
    }
    ctx->pc = 0x184A44u;
    // 0x184a44: 0x1240ffdc  beqz        $s2, . + 4 + (-0x24 << 2)
    ctx->pc = 0x184A44u;
    {
        const bool branch_taken_0x184a44 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x184A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184A44u;
            // 0x184a48: 0x2378824  and         $s1, $s1, $s7 (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & GPR_U64(ctx, 23));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184a44) {
            ctx->pc = 0x1849B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1849b8;
        }
    }
    ctx->pc = 0x184A4Cu;
    // 0x184a4c: 0x1000ffda  b           . + 4 + (-0x26 << 2)
    ctx->pc = 0x184A4Cu;
    {
        const bool branch_taken_0x184a4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184A4Cu;
            // 0x184a50: 0x2652fc00  addiu       $s2, $s2, -0x400 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294966272));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184a4c) {
            ctx->pc = 0x1849B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1849b8;
        }
    }
    ctx->pc = 0x184A54u;
    // 0x184a54: 0x0  nop
    ctx->pc = 0x184a54u;
    // NOP
label_184a58:
    // 0x184a58: 0x26a56c80  addiu       $a1, $s5, 0x6C80
    ctx->pc = 0x184a58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), 27776));
    // 0x184a5c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x184a5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184a60: 0x2452821  addu        $a1, $s2, $a1
    ctx->pc = 0x184a60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x184a64: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x184A64u;
    SET_GPR_U32(ctx, 31, 0x184A6Cu);
    ctx->pc = 0x184A68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184A64u;
            // 0x184a68: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184A6Cu; }
        if (ctx->pc != 0x184A6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184A6Cu; }
        if (ctx->pc != 0x184A6Cu) { return; }
    }
    ctx->pc = 0x184A6Cu;
label_184a6c:
    // 0x184a6c: 0x8fa20284  lw          $v0, 0x284($sp)
    ctx->pc = 0x184a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 644)));
label_184a70:
    // 0x184a70: 0xdfb00290  ld          $s0, 0x290($sp)
    ctx->pc = 0x184a70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 656)));
    // 0x184a74: 0xdfb10298  ld          $s1, 0x298($sp)
    ctx->pc = 0x184a74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 664)));
    // 0x184a78: 0xdfb202a0  ld          $s2, 0x2A0($sp)
    ctx->pc = 0x184a78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 672)));
    // 0x184a7c: 0xdfb302a8  ld          $s3, 0x2A8($sp)
    ctx->pc = 0x184a7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 680)));
    // 0x184a80: 0xdfb402b0  ld          $s4, 0x2B0($sp)
    ctx->pc = 0x184a80u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 688)));
    // 0x184a84: 0xdfb502b8  ld          $s5, 0x2B8($sp)
    ctx->pc = 0x184a84u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 696)));
    // 0x184a88: 0xdfb602c0  ld          $s6, 0x2C0($sp)
    ctx->pc = 0x184a88u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 704)));
    // 0x184a8c: 0xdfb702c8  ld          $s7, 0x2C8($sp)
    ctx->pc = 0x184a8cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 712)));
    // 0x184a90: 0xdfbe02d0  ld          $fp, 0x2D0($sp)
    ctx->pc = 0x184a90u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 720)));
    // 0x184a94: 0xdfbf02d8  ld          $ra, 0x2D8($sp)
    ctx->pc = 0x184a94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 728)));
    // 0x184a98: 0x3e00008  jr          $ra
    ctx->pc = 0x184A98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x184A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184A98u;
            // 0x184a9c: 0x27bd02e0  addiu       $sp, $sp, 0x2E0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 736));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18486Cu: goto label_18486c;
            case 0x184880u: goto label_184880;
            case 0x1848B0u: goto label_1848b0;
            case 0x1848C0u: goto label_1848c0;
            case 0x1848C8u: goto label_1848c8;
            case 0x1848D8u: goto label_1848d8;
            case 0x1848E0u: goto label_1848e0;
            case 0x1848F8u: goto label_1848f8;
            case 0x18490Cu: goto label_18490c;
            case 0x1849A8u: goto label_1849a8;
            case 0x1849B8u: goto label_1849b8;
            case 0x1849E0u: goto label_1849e0;
            case 0x184A0Cu: goto label_184a0c;
            case 0x184A1Cu: goto label_184a1c;
            case 0x184A28u: goto label_184a28;
            case 0x184A58u: goto label_184a58;
            case 0x184A6Cu: goto label_184a6c;
            case 0x184A70u: goto label_184a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x184AA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
