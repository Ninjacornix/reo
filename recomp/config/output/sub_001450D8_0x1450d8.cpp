#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001450D8
// Address: 0x1450d8 - 0x145228
void sub_001450D8_0x1450d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001450D8_0x1450d8");
#endif

    switch (ctx->pc) {
        case 0x14512cu: goto label_14512c;
        case 0x145144u: goto label_145144;
        case 0x145164u: goto label_145164;
        case 0x145174u: goto label_145174;
        case 0x145184u: goto label_145184;
        case 0x14519cu: goto label_14519c;
        case 0x1451ccu: goto label_1451cc;
        case 0x1451f0u: goto label_1451f0;
        default: break;
    }

    ctx->pc = 0x1450d8u;

    // 0x1450d8: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1450d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1450dc: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x1450dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x1450e0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1450e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1450e4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1450e4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1450e8: 0xffbe0080  sd          $fp, 0x80($sp)
    ctx->pc = 0x1450e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 30));
    // 0x1450ec: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1450ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1450f0: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x1450f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x1450f4: 0xc0f02d  daddu       $fp, $a2, $zero
    ctx->pc = 0x1450f4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1450f8: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x1450f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x1450fc: 0x120b82d  daddu       $s7, $t1, $zero
    ctx->pc = 0x1450fcu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145100: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x145100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x145104: 0x140b02d  daddu       $s6, $t2, $zero
    ctx->pc = 0x145104u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145108: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x145108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x14510c: 0x160a82d  daddu       $s5, $t3, $zero
    ctx->pc = 0x14510cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145110: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x145110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x145114: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x145114u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145118: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x145118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14511c: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x14511cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145120: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x145120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x145124: 0xc051552  jal         func_145548
    ctx->pc = 0x145124u;
    SET_GPR_U32(ctx, 31, 0x14512Cu);
    ctx->pc = 0x145128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145124u;
            // 0x145128: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145548u;
    if (runtime->hasFunction(0x145548u)) {
        auto targetFn = runtime->lookupFunction(0x145548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14512Cu; }
        if (ctx->pc != 0x14512Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145548_0x145548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14512Cu; }
        if (ctx->pc != 0x14512Cu) { return; }
    }
    ctx->pc = 0x14512Cu;
label_14512c:
    // 0x14512c: 0x12200007  beqz        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x14512Cu;
    {
        const bool branch_taken_0x14512c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x145130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14512Cu;
            // 0x145130: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14512c) {
            ctx->pc = 0x14514Cu;
            goto label_14514c;
        }
    }
    ctx->pc = 0x145134u;
    // 0x145134: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x145134u;
    {
        const bool branch_taken_0x145134 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x145138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145134u;
            // 0x145138: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145134) {
            ctx->pc = 0x14514Cu;
            goto label_14514c;
        }
    }
    ctx->pc = 0x14513Cu;
    // 0x14513c: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x14513Cu;
    SET_GPR_U32(ctx, 31, 0x145144u);
    ctx->pc = 0x145140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14513Cu;
            // 0x145140: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145144u; }
        if (ctx->pc != 0x145144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145144u; }
        if (ctx->pc != 0x145144u) { return; }
    }
    ctx->pc = 0x145144u;
label_145144:
    // 0x145144: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x145144u;
    {
        const bool branch_taken_0x145144 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x145148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145144u;
            // 0x145148: 0x40382d  daddu       $a3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145144) {
            ctx->pc = 0x145150u;
            goto label_145150;
        }
    }
    ctx->pc = 0x14514Cu;
label_14514c:
    // 0x14514c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x14514cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_145150:
    // 0x145150: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x145150u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145154: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x145154u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145158: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x145158u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14515c: 0xc0513ac  jal         func_144EB0
    ctx->pc = 0x14515Cu;
    SET_GPR_U32(ctx, 31, 0x145164u);
    ctx->pc = 0x145160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14515Cu;
            // 0x145160: 0x2a0402d  daddu       $t0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144EB0u;
    if (runtime->hasFunction(0x144EB0u)) {
        auto targetFn = runtime->lookupFunction(0x144EB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145164u; }
        if (ctx->pc != 0x145164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144EB0_0x144eb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145164u; }
        if (ctx->pc != 0x145164u) { return; }
    }
    ctx->pc = 0x145164u;
label_145164:
    // 0x145164: 0x12e00005  beqz        $s7, . + 4 + (0x5 << 2)
    ctx->pc = 0x145164u;
    {
        const bool branch_taken_0x145164 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        ctx->pc = 0x145168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145164u;
            // 0x145168: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145164) {
            ctx->pc = 0x14517Cu;
            goto label_14517c;
        }
    }
    ctx->pc = 0x14516Cu;
    // 0x14516c: 0xc051092  jal         func_144248
    ctx->pc = 0x14516Cu;
    SET_GPR_U32(ctx, 31, 0x145174u);
    ctx->pc = 0x145170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14516Cu;
            // 0x145170: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144248u;
    if (runtime->hasFunction(0x144248u)) {
        auto targetFn = runtime->lookupFunction(0x144248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145174u; }
        if (ctx->pc != 0x145174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144248_0x144248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145174u; }
        if (ctx->pc != 0x145174u) { return; }
    }
    ctx->pc = 0x145174u;
label_145174:
    // 0x145174: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x145174u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x145178: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x145178u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_14517c:
    // 0x14517c: 0xc051552  jal         func_145548
    ctx->pc = 0x14517Cu;
    SET_GPR_U32(ctx, 31, 0x145184u);
    ctx->pc = 0x145180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14517Cu;
            // 0x145180: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145548u;
    if (runtime->hasFunction(0x145548u)) {
        auto targetFn = runtime->lookupFunction(0x145548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145184u; }
        if (ctx->pc != 0x145184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145548_0x145548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145184u; }
        if (ctx->pc != 0x145184u) { return; }
    }
    ctx->pc = 0x145184u;
label_145184:
    // 0x145184: 0x12800007  beqz        $s4, . + 4 + (0x7 << 2)
    ctx->pc = 0x145184u;
    {
        const bool branch_taken_0x145184 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x145188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x145184u;
            // 0x145188: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x145184) {
            ctx->pc = 0x1451A4u;
            goto label_1451a4;
        }
    }
    ctx->pc = 0x14518Cu;
    // 0x14518c: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x14518Cu;
    {
        const bool branch_taken_0x14518c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x145190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14518Cu;
            // 0x145190: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14518c) {
            ctx->pc = 0x1451A4u;
            goto label_1451a4;
        }
    }
    ctx->pc = 0x145194u;
    // 0x145194: 0xc05167a  jal         func_1459E8
    ctx->pc = 0x145194u;
    SET_GPR_U32(ctx, 31, 0x14519Cu);
    ctx->pc = 0x145198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x145194u;
            // 0x145198: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1459E8u;
    if (runtime->hasFunction(0x1459E8u)) {
        auto targetFn = runtime->lookupFunction(0x1459E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14519Cu; }
        if (ctx->pc != 0x14519Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14519Cu; }
        if (ctx->pc != 0x14519Cu) { return; }
    }
    ctx->pc = 0x14519Cu;
label_14519c:
    // 0x14519c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x14519Cu;
    {
        const bool branch_taken_0x14519c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1451A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14519Cu;
            // 0x1451a0: 0x40382d  daddu       $a3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14519c) {
            ctx->pc = 0x1451A8u;
            goto label_1451a8;
        }
    }
    ctx->pc = 0x1451A4u;
label_1451a4:
    // 0x1451a4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1451a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1451a8:
    // 0x1451a8: 0x12c00004  beqz        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x1451A8u;
    {
        const bool branch_taken_0x1451a8 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        ctx->pc = 0x1451ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1451A8u;
            // 0x1451ac: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1451a8) {
            ctx->pc = 0x1451BCu;
            goto label_1451bc;
        }
    }
    ctx->pc = 0x1451B0u;
    // 0x1451b0: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x1451b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1451b4: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1451b4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1451b8: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x1451b8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
label_1451bc:
    // 0x1451bc: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1451bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1451c0: 0x2a0402d  daddu       $t0, $s5, $zero
    ctx->pc = 0x1451c0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1451c4: 0xc0513ac  jal         func_144EB0
    ctx->pc = 0x1451C4u;
    SET_GPR_U32(ctx, 31, 0x1451CCu);
    ctx->pc = 0x1451C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1451C4u;
            // 0x1451c8: 0x26440004  addiu       $a0, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144EB0u;
    if (runtime->hasFunction(0x144EB0u)) {
        auto targetFn = runtime->lookupFunction(0x144EB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1451CCu; }
        if (ctx->pc != 0x1451CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144EB0_0x144eb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1451CCu; }
        if (ctx->pc != 0x1451CCu) { return; }
    }
    ctx->pc = 0x1451CCu;
label_1451cc:
    // 0x1451cc: 0x12c00004  beqz        $s6, . + 4 + (0x4 << 2)
    ctx->pc = 0x1451CCu;
    {
        const bool branch_taken_0x1451cc = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        if (branch_taken_0x1451cc) {
            ctx->pc = 0x1451E0u;
            goto label_1451e0;
        }
    }
    ctx->pc = 0x1451D4u;
    // 0x1451d4: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x1451d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1451d8: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1451d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1451dc: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x1451dcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
label_1451e0:
    // 0x1451e0: 0x12e00005  beqz        $s7, . + 4 + (0x5 << 2)
    ctx->pc = 0x1451E0u;
    {
        const bool branch_taken_0x1451e0 = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        ctx->pc = 0x1451E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1451E0u;
            // 0x1451e4: 0xdfbf0090  ld          $ra, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1451e0) {
            ctx->pc = 0x1451F8u;
            goto label_1451f8;
        }
    }
    ctx->pc = 0x1451E8u;
    // 0x1451e8: 0xc051092  jal         func_144248
    ctx->pc = 0x1451E8u;
    SET_GPR_U32(ctx, 31, 0x1451F0u);
    ctx->pc = 0x1451ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1451E8u;
            // 0x1451ec: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144248u;
    if (runtime->hasFunction(0x144248u)) {
        auto targetFn = runtime->lookupFunction(0x144248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1451F0u; }
        if (ctx->pc != 0x1451F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144248_0x144248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1451F0u; }
        if (ctx->pc != 0x1451F0u) { return; }
    }
    ctx->pc = 0x1451F0u;
label_1451f0:
    // 0x1451f0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1451f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1451f4: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1451f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1451f8:
    // 0x1451f8: 0xdfbe0080  ld          $fp, 0x80($sp)
    ctx->pc = 0x1451f8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1451fc: 0xdfb70070  ld          $s7, 0x70($sp)
    ctx->pc = 0x1451fcu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x145200: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x145200u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x145204: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x145204u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x145208: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x145208u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14520c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x14520cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x145210: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x145210u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x145214: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x145214u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x145218: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x145218u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14521c: 0x3e00008  jr          $ra
    ctx->pc = 0x14521Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14521Cu;
            // 0x145220: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14512Cu: goto label_14512c;
            case 0x145144u: goto label_145144;
            case 0x14514Cu: goto label_14514c;
            case 0x145150u: goto label_145150;
            case 0x145164u: goto label_145164;
            case 0x145174u: goto label_145174;
            case 0x14517Cu: goto label_14517c;
            case 0x145184u: goto label_145184;
            case 0x14519Cu: goto label_14519c;
            case 0x1451A4u: goto label_1451a4;
            case 0x1451A8u: goto label_1451a8;
            case 0x1451BCu: goto label_1451bc;
            case 0x1451CCu: goto label_1451cc;
            case 0x1451E0u: goto label_1451e0;
            case 0x1451F0u: goto label_1451f0;
            case 0x1451F8u: goto label_1451f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145224u;
    // 0x145224: 0x0  nop
    ctx->pc = 0x145224u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
