#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102518
// Address: 0x102518 - 0x1026a4
void sub_00102518_0x102518(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102518_0x102518");
#endif

    switch (ctx->pc) {
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
        default: break;
    }

    ctx->pc = 0x102518u;

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
            default: break;
        }
        return;
    }
    ctx->pc = 0x1026A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
