#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001024F0
// Address: 0x1024f0 - 0x1027f0
void sub_001024F0_0x1024f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001024F0_0x1024f0");
#endif

    switch (ctx->pc) {
        case 0x102504u: goto label_102504;
        case 0x10254cu: goto label_10254c;
        case 0x102588u: goto label_102588;
        case 0x10259cu: goto label_10259c;
        case 0x1025bcu: goto label_1025bc;
        case 0x1025d8u: goto label_1025d8;
        case 0x1025ecu: goto label_1025ec;
        case 0x102600u: goto label_102600;
        case 0x102614u: goto label_102614;
        case 0x102628u: goto label_102628;
        case 0x10263cu: goto label_10263c;
        case 0x102648u: goto label_102648;
        case 0x10265cu: goto label_10265c;
        case 0x1026c8u: goto label_1026c8;
        case 0x1026e0u: goto label_1026e0;
        case 0x1026fcu: goto label_1026fc;
        case 0x102724u: goto label_102724;
        case 0x102740u: goto label_102740;
        case 0x102754u: goto label_102754;
        case 0x102768u: goto label_102768;
        case 0x10277cu: goto label_10277c;
        case 0x102790u: goto label_102790;
        case 0x1027a4u: goto label_1027a4;
        case 0x1027a8u: goto label_1027a8;
        case 0x1027c4u: goto label_1027c4;
        default: break;
    }

    ctx->pc = 0x1024f0u;

    // 0x1024f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1024f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1024f4: 0x2405043a  addiu       $a1, $zero, 0x43A
    ctx->pc = 0x1024f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1082));
    // 0x1024f8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1024f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1024fc: 0xc0408c2  jal         func_102308
    ctx->pc = 0x1024FCu;
    SET_GPR_U32(ctx, 31, 0x102504u);
    ctx->pc = 0x102500u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1024FCu;
            // 0x102500: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102504u; }
        if (ctx->pc != 0x102504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102504u; }
        if (ctx->pc != 0x102504u) { return; }
    }
    ctx->pc = 0x102504u;
label_102504:
    // 0x102504: 0x97a20000  lhu         $v0, 0x0($sp)
    ctx->pc = 0x102504u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102508: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x102508u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10250c: 0x3e00008  jr          $ra
    ctx->pc = 0x10250Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10250Cu;
            // 0x102510: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102504u: goto label_102504;
            case 0x10254Cu: goto label_10254c;
            case 0x102588u: goto label_102588;
            case 0x10259Cu: goto label_10259c;
            case 0x1025BCu: goto label_1025bc;
            case 0x1025D8u: goto label_1025d8;
            case 0x1025ECu: goto label_1025ec;
            case 0x102600u: goto label_102600;
            case 0x102614u: goto label_102614;
            case 0x102628u: goto label_102628;
            case 0x10263Cu: goto label_10263c;
            case 0x102648u: goto label_102648;
            case 0x10265Cu: goto label_10265c;
            case 0x102674u: goto label_102674;
            case 0x1026C8u: goto label_1026c8;
            case 0x1026E0u: goto label_1026e0;
            case 0x1026FCu: goto label_1026fc;
            case 0x102724u: goto label_102724;
            case 0x102740u: goto label_102740;
            case 0x102754u: goto label_102754;
            case 0x102768u: goto label_102768;
            case 0x10277Cu: goto label_10277c;
            case 0x102790u: goto label_102790;
            case 0x1027A4u: goto label_1027a4;
            case 0x1027A8u: goto label_1027a8;
            case 0x1027C4u: goto label_1027c4;
            case 0x1027D4u: goto label_1027d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102514u;
    // 0x102514: 0x0  nop
    ctx->pc = 0x102514u;
    // NOP
    // 0x102518: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x102518u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x10251c: 0xffb200b0  sd          $s2, 0xB0($sp)
    ctx->pc = 0x10251cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 18));
    // 0x102520: 0xffbf0120  sd          $ra, 0x120($sp)
    ctx->pc = 0x102520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 31));
    // 0x102524: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x102524u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102528: 0xffbe0110  sd          $fp, 0x110($sp)
    ctx->pc = 0x102528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 272), GPR_U64(ctx, 30));
    // 0x10252c: 0xffb70100  sd          $s7, 0x100($sp)
    ctx->pc = 0x10252cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 256), GPR_U64(ctx, 23));
    // 0x102530: 0xffb600f0  sd          $s6, 0xF0($sp)
    ctx->pc = 0x102530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 240), GPR_U64(ctx, 22));
    // 0x102534: 0xffb500e0  sd          $s5, 0xE0($sp)
    ctx->pc = 0x102534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 21));
    // 0x102538: 0xffb400d0  sd          $s4, 0xD0($sp)
    ctx->pc = 0x102538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 20));
    // 0x10253c: 0xffb300c0  sd          $s3, 0xC0($sp)
    ctx->pc = 0x10253cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 19));
    // 0x102540: 0xffb100a0  sd          $s1, 0xA0($sp)
    ctx->pc = 0x102540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 17));
    // 0x102544: 0xc0408a6  jal         func_102298
    ctx->pc = 0x102544u;
    SET_GPR_U32(ctx, 31, 0x10254Cu);
    ctx->pc = 0x102548u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102544u;
            // 0x102548: 0xffb00090  sd          $s0, 0x90($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102298u;
    if (runtime->hasFunction(0x102298u)) {
        auto targetFn = runtime->lookupFunction(0x102298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10254Cu; }
        if (ctx->pc != 0x10254Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102298_0x102298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10254Cu; }
        if (ctx->pc != 0x10254Cu) { return; }
    }
    ctx->pc = 0x10254Cu;
label_10254c:
    // 0x10254c: 0x14400049  bnez        $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x10254Cu;
    {
        const bool branch_taken_0x10254c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10254Cu;
            // 0x102550: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10254c) {
            ctx->pc = 0x102674u;
            goto label_102674;
        }
    }
    ctx->pc = 0x102554u;
    // 0x102554: 0x27a20050  addiu       $v0, $sp, 0x50
    ctx->pc = 0x102554u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x102558: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x102558u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10255c: 0xafa20084  sw          $v0, 0x84($sp)
    ctx->pc = 0x10255cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 132), GPR_U32(ctx, 2));
    // 0x102560: 0x27b40010  addiu       $s4, $sp, 0x10
    ctx->pc = 0x102560u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x102564: 0x27a20060  addiu       $v0, $sp, 0x60
    ctx->pc = 0x102564u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x102568: 0x27b50020  addiu       $s5, $sp, 0x20
    ctx->pc = 0x102568u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10256c: 0xafa20080  sw          $v0, 0x80($sp)
    ctx->pc = 0x10256cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 2));
    // 0x102570: 0x27b60030  addiu       $s6, $sp, 0x30
    ctx->pc = 0x102570u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x102574: 0x27b70040  addiu       $s7, $sp, 0x40
    ctx->pc = 0x102574u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x102578: 0x27be0070  addiu       $fp, $sp, 0x70
    ctx->pc = 0x102578u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x10257c: 0x2653021c  addiu       $s3, $s2, 0x21C
    ctx->pc = 0x10257cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), 540));
    // 0x102580: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x102580u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102584: 0x0  nop
    ctx->pc = 0x102584u;
    // NOP
label_102588:
    // 0x102588: 0x26250400  addiu       $a1, $s1, 0x400
    ctx->pc = 0x102588u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 1024));
    // 0x10258c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10258cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102590: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x102590u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x102594: 0xc0408c2  jal         func_102308
    ctx->pc = 0x102594u;
    SET_GPR_U32(ctx, 31, 0x10259Cu);
    ctx->pc = 0x102598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102594u;
            // 0x102598: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10259Cu; }
        if (ctx->pc != 0x10259Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10259Cu; }
        if (ctx->pc != 0x10259Cu) { return; }
    }
    ctx->pc = 0x10259Cu;
label_10259c:
    // 0x10259c: 0x7ba20000  lq          $v0, 0x0($sp)
    ctx->pc = 0x10259cu;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1025a0: 0x2e230020  sltiu       $v1, $s1, 0x20
    ctx->pc = 0x1025a0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x1025a4: 0x7e020000  sq          $v0, 0x0($s0)
    ctx->pc = 0x1025a4u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 0), GPR_VEC(ctx, 2));
    // 0x1025a8: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1025A8u;
    {
        const bool branch_taken_0x1025a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1025ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1025A8u;
            // 0x1025ac: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1025a8) {
            ctx->pc = 0x102588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_102588;
        }
    }
    ctx->pc = 0x1025B0u;
    // 0x1025b0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1025b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1025b4: 0xc0408c2  jal         func_102308
    ctx->pc = 0x1025B4u;
    SET_GPR_U32(ctx, 31, 0x1025BCu);
    ctx->pc = 0x1025B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1025B4u;
            // 0x1025b8: 0x24050430  addiu       $a1, $zero, 0x430 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1025BCu; }
        if (ctx->pc != 0x1025BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1025BCu; }
        if (ctx->pc != 0x1025BCu) { return; }
    }
    ctx->pc = 0x1025BCu;
label_1025bc:
    // 0x1025bc: 0x260802d  daddu       $s0, $s3, $zero
    ctx->pc = 0x1025bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1025c0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1025c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1025c4: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1025c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1025c8: 0x24050431  addiu       $a1, $zero, 0x431
    ctx->pc = 0x1025c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1073));
    // 0x1025cc: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1025ccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1025d0: 0xc0408c2  jal         func_102308
    ctx->pc = 0x1025D0u;
    SET_GPR_U32(ctx, 31, 0x1025D8u);
    ctx->pc = 0x1025D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1025D0u;
            // 0x1025d4: 0xae420200  sw          $v0, 0x200($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 512), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1025D8u; }
        if (ctx->pc != 0x1025D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1025D8u; }
        if (ctx->pc != 0x1025D8u) { return; }
    }
    ctx->pc = 0x1025D8u;
label_1025d8:
    // 0x1025d8: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x1025d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1025dc: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1025dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1025e0: 0x24050432  addiu       $a1, $zero, 0x432
    ctx->pc = 0x1025e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1074));
    // 0x1025e4: 0xc0408c2  jal         func_102308
    ctx->pc = 0x1025E4u;
    SET_GPR_U32(ctx, 31, 0x1025ECu);
    ctx->pc = 0x1025E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1025E4u;
            // 0x1025e8: 0xae420204  sw          $v0, 0x204($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 516), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1025ECu; }
        if (ctx->pc != 0x1025ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1025ECu; }
        if (ctx->pc != 0x1025ECu) { return; }
    }
    ctx->pc = 0x1025ECu;
label_1025ec:
    // 0x1025ec: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x1025ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1025f0: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1025f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1025f4: 0x24050434  addiu       $a1, $zero, 0x434
    ctx->pc = 0x1025f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1076));
    // 0x1025f8: 0xc0408c2  jal         func_102308
    ctx->pc = 0x1025F8u;
    SET_GPR_U32(ctx, 31, 0x102600u);
    ctx->pc = 0x1025FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1025F8u;
            // 0x1025fc: 0xae420208  sw          $v0, 0x208($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 520), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102600u; }
        if (ctx->pc != 0x102600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102600u; }
        if (ctx->pc != 0x102600u) { return; }
    }
    ctx->pc = 0x102600u;
label_102600:
    // 0x102600: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x102600u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x102604: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x102604u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102608: 0x24050435  addiu       $a1, $zero, 0x435
    ctx->pc = 0x102608u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1077));
    // 0x10260c: 0xc0408c2  jal         func_102308
    ctx->pc = 0x10260Cu;
    SET_GPR_U32(ctx, 31, 0x102614u);
    ctx->pc = 0x102610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10260Cu;
            // 0x102610: 0xae42020c  sw          $v0, 0x20C($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 524), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102614u; }
        if (ctx->pc != 0x102614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102614u; }
        if (ctx->pc != 0x102614u) { return; }
    }
    ctx->pc = 0x102614u;
label_102614:
    // 0x102614: 0x8fa20040  lw          $v0, 0x40($sp)
    ctx->pc = 0x102614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x102618: 0x24050436  addiu       $a1, $zero, 0x436
    ctx->pc = 0x102618u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1078));
    // 0x10261c: 0x8fa40084  lw          $a0, 0x84($sp)
    ctx->pc = 0x10261cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 132)));
    // 0x102620: 0xc0408c2  jal         func_102308
    ctx->pc = 0x102620u;
    SET_GPR_U32(ctx, 31, 0x102628u);
    ctx->pc = 0x102624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102620u;
            // 0x102624: 0xae420210  sw          $v0, 0x210($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 528), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102628u; }
        if (ctx->pc != 0x102628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102628u; }
        if (ctx->pc != 0x102628u) { return; }
    }
    ctx->pc = 0x102628u;
label_102628:
    // 0x102628: 0x8fa20050  lw          $v0, 0x50($sp)
    ctx->pc = 0x102628u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x10262c: 0x24050437  addiu       $a1, $zero, 0x437
    ctx->pc = 0x10262cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1079));
    // 0x102630: 0x8fa40080  lw          $a0, 0x80($sp)
    ctx->pc = 0x102630u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x102634: 0xc0408c2  jal         func_102308
    ctx->pc = 0x102634u;
    SET_GPR_U32(ctx, 31, 0x10263Cu);
    ctx->pc = 0x102638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102634u;
            // 0x102638: 0xae420214  sw          $v0, 0x214($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 532), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10263Cu; }
        if (ctx->pc != 0x10263Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10263Cu; }
        if (ctx->pc != 0x10263Cu) { return; }
    }
    ctx->pc = 0x10263Cu;
label_10263c:
    // 0x10263c: 0x8fa20060  lw          $v0, 0x60($sp)
    ctx->pc = 0x10263cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x102640: 0xae420218  sw          $v0, 0x218($s2)
    ctx->pc = 0x102640u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 536), GPR_U32(ctx, 2));
    // 0x102644: 0x0  nop
    ctx->pc = 0x102644u;
    // NOP
label_102648:
    // 0x102648: 0x26250420  addiu       $a1, $s1, 0x420
    ctx->pc = 0x102648u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 1056));
    // 0x10264c: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10264cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102650: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x102650u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x102654: 0xc0408c2  jal         func_102308
    ctx->pc = 0x102654u;
    SET_GPR_U32(ctx, 31, 0x10265Cu);
    ctx->pc = 0x102658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102654u;
            // 0x102658: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102308u;
    if (runtime->hasFunction(0x102308u)) {
        auto targetFn = runtime->lookupFunction(0x102308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10265Cu; }
        if (ctx->pc != 0x10265Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102308_0x102308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10265Cu; }
        if (ctx->pc != 0x10265Cu) { return; }
    }
    ctx->pc = 0x10265Cu;
label_10265c:
    // 0x10265c: 0x97a20070  lhu         $v0, 0x70($sp)
    ctx->pc = 0x10265cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x102660: 0x2e230010  sltiu       $v1, $s1, 0x10
    ctx->pc = 0x102660u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x102664: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x102664u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x102668: 0x1460fff7  bnez        $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x102668u;
    {
        const bool branch_taken_0x102668 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10266Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102668u;
            // 0x10266c: 0x26100002  addiu       $s0, $s0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102668) {
            ctx->pc = 0x102648u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_102648;
        }
    }
    ctx->pc = 0x102670u;
    // 0x102670: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x102670u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_102674:
    // 0x102674: 0xdfbf0120  ld          $ra, 0x120($sp)
    ctx->pc = 0x102674u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x102678: 0xdfbe0110  ld          $fp, 0x110($sp)
    ctx->pc = 0x102678u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x10267c: 0xdfb70100  ld          $s7, 0x100($sp)
    ctx->pc = 0x10267cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x102680: 0xdfb600f0  ld          $s6, 0xF0($sp)
    ctx->pc = 0x102680u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x102684: 0xdfb500e0  ld          $s5, 0xE0($sp)
    ctx->pc = 0x102684u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x102688: 0xdfb400d0  ld          $s4, 0xD0($sp)
    ctx->pc = 0x102688u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x10268c: 0xdfb300c0  ld          $s3, 0xC0($sp)
    ctx->pc = 0x10268cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x102690: 0xdfb200b0  ld          $s2, 0xB0($sp)
    ctx->pc = 0x102690u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x102694: 0xdfb100a0  ld          $s1, 0xA0($sp)
    ctx->pc = 0x102694u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x102698: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x102698u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x10269c: 0x3e00008  jr          $ra
    ctx->pc = 0x10269Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1026A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10269Cu;
            // 0x1026a0: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102504u: goto label_102504;
            case 0x10254Cu: goto label_10254c;
            case 0x102588u: goto label_102588;
            case 0x10259Cu: goto label_10259c;
            case 0x1025BCu: goto label_1025bc;
            case 0x1025D8u: goto label_1025d8;
            case 0x1025ECu: goto label_1025ec;
            case 0x102600u: goto label_102600;
            case 0x102614u: goto label_102614;
            case 0x102628u: goto label_102628;
            case 0x10263Cu: goto label_10263c;
            case 0x102648u: goto label_102648;
            case 0x10265Cu: goto label_10265c;
            case 0x102674u: goto label_102674;
            case 0x1026C8u: goto label_1026c8;
            case 0x1026E0u: goto label_1026e0;
            case 0x1026FCu: goto label_1026fc;
            case 0x102724u: goto label_102724;
            case 0x102740u: goto label_102740;
            case 0x102754u: goto label_102754;
            case 0x102768u: goto label_102768;
            case 0x10277Cu: goto label_10277c;
            case 0x102790u: goto label_102790;
            case 0x1027A4u: goto label_1027a4;
            case 0x1027A8u: goto label_1027a8;
            case 0x1027C4u: goto label_1027c4;
            case 0x1027D4u: goto label_1027d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1026A4u;
    // 0x1026a4: 0x0  nop
    ctx->pc = 0x1026a4u;
    // NOP
    // 0x1026a8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1026a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1026ac: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1026acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1026b0: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1026b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1026b4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1026b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1026b8: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1026b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1026bc: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1026bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1026c0: 0xc0408a6  jal         func_102298
    ctx->pc = 0x1026C0u;
    SET_GPR_U32(ctx, 31, 0x1026C8u);
    ctx->pc = 0x1026C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1026C0u;
            // 0x1026c4: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102298u;
    if (runtime->hasFunction(0x102298u)) {
        auto targetFn = runtime->lookupFunction(0x102298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1026C8u; }
        if (ctx->pc != 0x1026C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102298_0x102298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1026C8u; }
        if (ctx->pc != 0x1026C8u) { return; }
    }
    ctx->pc = 0x1026C8u;
label_1026c8:
    // 0x1026c8: 0x14400042  bnez        $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x1026C8u;
    {
        const bool branch_taken_0x1026c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1026CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1026C8u;
            // 0x1026cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1026c8) {
            ctx->pc = 0x1027D4u;
            goto label_1027d4;
        }
    }
    ctx->pc = 0x1026D0u;
    // 0x1026d0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1026d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1026d4: 0x2653021c  addiu       $s3, $s2, 0x21C
    ctx->pc = 0x1026d4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 18), 540));
    // 0x1026d8: 0x240802d  daddu       $s0, $s2, $zero
    ctx->pc = 0x1026d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1026dc: 0x0  nop
    ctx->pc = 0x1026dcu;
    // NOP
label_1026e0:
    // 0x1026e0: 0x7a020000  lq          $v0, 0x0($s0)
    ctx->pc = 0x1026e0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1026e4: 0x26240400  addiu       $a0, $s1, 0x400
    ctx->pc = 0x1026e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1024));
    // 0x1026e8: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1026e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1026ec: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1026ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1026f0: 0x7fa20000  sq          $v0, 0x0($sp)
    ctx->pc = 0x1026f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 2));
    // 0x1026f4: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x1026F4u;
    SET_GPR_U32(ctx, 31, 0x1026FCu);
    ctx->pc = 0x1026F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1026F4u;
            // 0x1026f8: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1026FCu; }
        if (ctx->pc != 0x1026FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1026FCu; }
        if (ctx->pc != 0x1026FCu) { return; }
    }
    ctx->pc = 0x1026FCu;
label_1026fc:
    // 0x1026fc: 0x2e220020  sltiu       $v0, $s1, 0x20
    ctx->pc = 0x1026fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x102700: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x102700u;
    {
        const bool branch_taken_0x102700 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102700u;
            // 0x102704: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102700) {
            ctx->pc = 0x1026E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1026e0;
        }
    }
    ctx->pc = 0x102708u;
    // 0x102708: 0x9e420200  lwu         $v0, 0x200($s2)
    ctx->pc = 0x102708u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 512)));
    // 0x10270c: 0x70001ca9  por         $v1, $zero, $zero
    ctx->pc = 0x10270cu;
    SET_GPR_VEC(ctx, 3, PS2_POR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 0)));
    // 0x102710: 0x7fa30000  sq          $v1, 0x0($sp)
    ctx->pc = 0x102710u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 3));
    // 0x102714: 0x24040430  addiu       $a0, $zero, 0x430
    ctx->pc = 0x102714u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1072));
    // 0x102718: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102718u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10271c: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x10271Cu;
    SET_GPR_U32(ctx, 31, 0x102724u);
    ctx->pc = 0x102720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10271Cu;
            // 0x102720: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102724u; }
        if (ctx->pc != 0x102724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102724u; }
        if (ctx->pc != 0x102724u) { return; }
    }
    ctx->pc = 0x102724u;
label_102724:
    // 0x102724: 0x260802d  daddu       $s0, $s3, $zero
    ctx->pc = 0x102724u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102728: 0x9e420204  lwu         $v0, 0x204($s2)
    ctx->pc = 0x102728u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 516)));
    // 0x10272c: 0x24040431  addiu       $a0, $zero, 0x431
    ctx->pc = 0x10272cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1073));
    // 0x102730: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102730u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102734: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x102734u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102738: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x102738u;
    SET_GPR_U32(ctx, 31, 0x102740u);
    ctx->pc = 0x10273Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102738u;
            // 0x10273c: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102740u; }
        if (ctx->pc != 0x102740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102740u; }
        if (ctx->pc != 0x102740u) { return; }
    }
    ctx->pc = 0x102740u;
label_102740:
    // 0x102740: 0x9e420208  lwu         $v0, 0x208($s2)
    ctx->pc = 0x102740u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 520)));
    // 0x102744: 0x24040432  addiu       $a0, $zero, 0x432
    ctx->pc = 0x102744u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1074));
    // 0x102748: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102748u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10274c: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x10274Cu;
    SET_GPR_U32(ctx, 31, 0x102754u);
    ctx->pc = 0x102750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10274Cu;
            // 0x102750: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102754u; }
        if (ctx->pc != 0x102754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102754u; }
        if (ctx->pc != 0x102754u) { return; }
    }
    ctx->pc = 0x102754u;
label_102754:
    // 0x102754: 0x9e42020c  lwu         $v0, 0x20C($s2)
    ctx->pc = 0x102754u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 524)));
    // 0x102758: 0x24040434  addiu       $a0, $zero, 0x434
    ctx->pc = 0x102758u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1076));
    // 0x10275c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x10275cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102760: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x102760u;
    SET_GPR_U32(ctx, 31, 0x102768u);
    ctx->pc = 0x102764u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102760u;
            // 0x102764: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102768u; }
        if (ctx->pc != 0x102768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102768u; }
        if (ctx->pc != 0x102768u) { return; }
    }
    ctx->pc = 0x102768u;
label_102768:
    // 0x102768: 0x9e420210  lwu         $v0, 0x210($s2)
    ctx->pc = 0x102768u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 528)));
    // 0x10276c: 0x24040435  addiu       $a0, $zero, 0x435
    ctx->pc = 0x10276cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1077));
    // 0x102770: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102770u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102774: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x102774u;
    SET_GPR_U32(ctx, 31, 0x10277Cu);
    ctx->pc = 0x102778u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102774u;
            // 0x102778: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10277Cu; }
        if (ctx->pc != 0x10277Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10277Cu; }
        if (ctx->pc != 0x10277Cu) { return; }
    }
    ctx->pc = 0x10277Cu;
label_10277c:
    // 0x10277c: 0x9e420214  lwu         $v0, 0x214($s2)
    ctx->pc = 0x10277cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 532)));
    // 0x102780: 0x24040436  addiu       $a0, $zero, 0x436
    ctx->pc = 0x102780u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1078));
    // 0x102784: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102784u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102788: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x102788u;
    SET_GPR_U32(ctx, 31, 0x102790u);
    ctx->pc = 0x10278Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102788u;
            // 0x10278c: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102790u; }
        if (ctx->pc != 0x102790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102790u; }
        if (ctx->pc != 0x102790u) { return; }
    }
    ctx->pc = 0x102790u;
label_102790:
    // 0x102790: 0x9e420218  lwu         $v0, 0x218($s2)
    ctx->pc = 0x102790u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 536)));
    // 0x102794: 0x24040437  addiu       $a0, $zero, 0x437
    ctx->pc = 0x102794u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1079));
    // 0x102798: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x102798u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10279c: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x10279Cu;
    SET_GPR_U32(ctx, 31, 0x1027A4u);
    ctx->pc = 0x1027A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10279Cu;
            // 0x1027a0: 0xffa20000  sd          $v0, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1027A4u; }
        if (ctx->pc != 0x1027A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1027A4u; }
        if (ctx->pc != 0x1027A4u) { return; }
    }
    ctx->pc = 0x1027A4u;
label_1027a4:
    // 0x1027a4: 0x0  nop
    ctx->pc = 0x1027a4u;
    // NOP
label_1027a8:
    // 0x1027a8: 0x96020000  lhu         $v0, 0x0($s0)
    ctx->pc = 0x1027a8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1027ac: 0x26240420  addiu       $a0, $s1, 0x420
    ctx->pc = 0x1027acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1056));
    // 0x1027b0: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1027b0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1027b4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1027b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1027b8: 0xffa20000  sd          $v0, 0x0($sp)
    ctx->pc = 0x1027b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    // 0x1027bc: 0xc0408b2  jal         func_1022C8
    ctx->pc = 0x1027BCu;
    SET_GPR_U32(ctx, 31, 0x1027C4u);
    ctx->pc = 0x1027C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1027BCu;
            // 0x1027c0: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1022C8u;
    if (runtime->hasFunction(0x1022C8u)) {
        auto targetFn = runtime->lookupFunction(0x1022C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1027C4u; }
        if (ctx->pc != 0x1027C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001022C8_0x1022c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1027C4u; }
        if (ctx->pc != 0x1027C4u) { return; }
    }
    ctx->pc = 0x1027C4u;
label_1027c4:
    // 0x1027c4: 0x2e220010  sltiu       $v0, $s1, 0x10
    ctx->pc = 0x1027c4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1027c8: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1027C8u;
    {
        const bool branch_taken_0x1027c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1027CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1027C8u;
            // 0x1027cc: 0x26100002  addiu       $s0, $s0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1027c8) {
            ctx->pc = 0x1027A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1027a8;
        }
    }
    ctx->pc = 0x1027D0u;
    // 0x1027d0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1027d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1027d4:
    // 0x1027d4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1027d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1027d8: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x1027d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1027dc: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1027dcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1027e0: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1027e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1027e4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1027e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1027e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1027E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1027ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1027E8u;
            // 0x1027ec: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102504u: goto label_102504;
            case 0x10254Cu: goto label_10254c;
            case 0x102588u: goto label_102588;
            case 0x10259Cu: goto label_10259c;
            case 0x1025BCu: goto label_1025bc;
            case 0x1025D8u: goto label_1025d8;
            case 0x1025ECu: goto label_1025ec;
            case 0x102600u: goto label_102600;
            case 0x102614u: goto label_102614;
            case 0x102628u: goto label_102628;
            case 0x10263Cu: goto label_10263c;
            case 0x102648u: goto label_102648;
            case 0x10265Cu: goto label_10265c;
            case 0x102674u: goto label_102674;
            case 0x1026C8u: goto label_1026c8;
            case 0x1026E0u: goto label_1026e0;
            case 0x1026FCu: goto label_1026fc;
            case 0x102724u: goto label_102724;
            case 0x102740u: goto label_102740;
            case 0x102754u: goto label_102754;
            case 0x102768u: goto label_102768;
            case 0x10277Cu: goto label_10277c;
            case 0x102790u: goto label_102790;
            case 0x1027A4u: goto label_1027a4;
            case 0x1027A8u: goto label_1027a8;
            case 0x1027C4u: goto label_1027c4;
            case 0x1027D4u: goto label_1027d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1027F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
