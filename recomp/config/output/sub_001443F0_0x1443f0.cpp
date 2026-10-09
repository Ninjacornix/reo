#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001443F0
// Address: 0x1443f0 - 0x144500
void sub_001443F0_0x1443f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001443F0_0x1443f0");
#endif

    switch (ctx->pc) {
        case 0x144438u: goto label_144438;
        case 0x144440u: goto label_144440;
        case 0x144480u: goto label_144480;
        case 0x1444a4u: goto label_1444a4;
        case 0x1444b8u: goto label_1444b8;
        default: break;
    }

    ctx->pc = 0x1443f0u;

    // 0x1443f0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1443f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1443f4: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x1443f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x1443f8: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x1443f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x1443fc: 0x24170001  addiu       $s7, $zero, 0x1
    ctx->pc = 0x1443fcu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x144400: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x144400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x144404: 0x24160022  addiu       $s6, $zero, 0x22
    ctx->pc = 0x144404u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x144408: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x144408u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x14440c: 0x24150023  addiu       $s5, $zero, 0x23
    ctx->pc = 0x14440cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
    // 0x144410: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x144410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x144414: 0x3c140024  lui         $s4, 0x24
    ctx->pc = 0x144414u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)36 << 16));
    // 0x144418: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x144418u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x14441c: 0x2413000f  addiu       $s3, $zero, 0xF
    ctx->pc = 0x14441cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x144420: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x144420u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x144424: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x144424u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144428: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x144428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x14442c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x14442cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144430: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x144430u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x144434: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x144434u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_144438:
    // 0x144438: 0xc051552  jal         func_145548
    ctx->pc = 0x144438u;
    SET_GPR_U32(ctx, 31, 0x144440u);
    ctx->pc = 0x14443Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144438u;
            // 0x14443c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145548u;
    if (runtime->hasFunction(0x145548u)) {
        auto targetFn = runtime->lookupFunction(0x145548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144440u; }
        if (ctx->pc != 0x144440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145548_0x145548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144440u; }
        if (ctx->pc != 0x144440u) { return; }
    }
    ctx->pc = 0x144440u;
label_144440:
    // 0x144440: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x144440u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144444: 0x12160017  beq         $s0, $s6, . + 4 + (0x17 << 2)
    ctx->pc = 0x144444u;
    {
        const bool branch_taken_0x144444 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 22));
        ctx->pc = 0x144448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144444u;
            // 0x144448: 0x2e020023  sltiu       $v0, $s0, 0x23 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)35) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x144444) {
            ctx->pc = 0x1444A4u;
            goto label_1444a4;
        }
    }
    ctx->pc = 0x14444Cu;
    // 0x14444c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x14444Cu;
    {
        const bool branch_taken_0x14444c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x14444c) {
            ctx->pc = 0x144464u;
            goto label_144464;
        }
    }
    ctx->pc = 0x144454u;
    // 0x144454: 0x12000008  beqz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x144454u;
    {
        const bool branch_taken_0x144454 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x144458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144454u;
            // 0x144458: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144454) {
            ctx->pc = 0x144478u;
            goto label_144478;
        }
    }
    ctx->pc = 0x14445Cu;
    // 0x14445c: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x14445Cu;
    {
        const bool branch_taken_0x14445c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14445Cu;
            // 0x144460: 0x2509021  addu        $s2, $s2, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14445c) {
            ctx->pc = 0x1444C4u;
            goto label_1444c4;
        }
    }
    ctx->pc = 0x144464u;
label_144464:
    // 0x144464: 0x56150017  bnel        $s0, $s5, . + 4 + (0x17 << 2)
    ctx->pc = 0x144464u;
    {
        const bool branch_taken_0x144464 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 21));
        if (branch_taken_0x144464) {
            ctx->pc = 0x144468u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x144464u;
            // 0x144468: 0x2509021  addu        $s2, $s2, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1444C4u;
            goto label_1444c4;
        }
    }
    ctx->pc = 0x14446Cu;
    // 0x14446c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x14446cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x144470: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x144470u;
    {
        const bool branch_taken_0x144470 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144470u;
            // 0x144474: 0x26520021  addiu       $s2, $s2, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 33));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144470) {
            ctx->pc = 0x1444C8u;
            goto label_1444c8;
        }
    }
    ctx->pc = 0x144478u;
label_144478:
    // 0x144478: 0xc0515ee  jal         func_1457B8
    ctx->pc = 0x144478u;
    SET_GPR_U32(ctx, 31, 0x144480u);
    ctx->pc = 0x14447Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144478u;
            // 0x14447c: 0x2405000b  addiu       $a1, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1457B8u;
    if (runtime->hasFunction(0x1457B8u)) {
        auto targetFn = runtime->lookupFunction(0x1457B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144480u; }
        if (ctx->pc != 0x144480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001457B8_0x1457b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144480u; }
        if (ctx->pc != 0x144480u) { return; }
    }
    ctx->pc = 0x144480u;
label_144480:
    // 0x144480: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x144480u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144484: 0x8e220860  lw          $v0, 0x860($s1)
    ctx->pc = 0x144484u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2144)));
    // 0x144488: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x144488u;
    {
        const bool branch_taken_0x144488 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14448Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144488u;
            // 0x14448c: 0x2685dde8  addiu       $a1, $s4, -0x2218 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), 4294958568));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144488) {
            ctx->pc = 0x1444ACu;
            goto label_1444ac;
        }
    }
    ctx->pc = 0x144490u;
    // 0x144490: 0x14730007  bne         $v1, $s3, . + 4 + (0x7 << 2)
    ctx->pc = 0x144490u;
    {
        const bool branch_taken_0x144490 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        ctx->pc = 0x144494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144490u;
            // 0x144494: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144490) {
            ctx->pc = 0x1444B0u;
            goto label_1444b0;
        }
    }
    ctx->pc = 0x144498u;
    // 0x144498: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x144498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14449c: 0xc051636  jal         func_1458D8
    ctx->pc = 0x14449Cu;
    SET_GPR_U32(ctx, 31, 0x1444A4u);
    ctx->pc = 0x1444A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14449Cu;
            // 0x1444a0: 0x2405000b  addiu       $a1, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1458D8u;
    if (runtime->hasFunction(0x1458D8u)) {
        auto targetFn = runtime->lookupFunction(0x1458D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1444A4u; }
        if (ctx->pc != 0x1444A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1444A4u; }
        if (ctx->pc != 0x1444A4u) { return; }
    }
    ctx->pc = 0x1444A4u;
label_1444a4:
    // 0x1444a4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1444A4u;
    {
        const bool branch_taken_0x1444a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1444A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1444A4u;
            // 0x1444a8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1444a4) {
            ctx->pc = 0x1444C8u;
            goto label_1444c8;
        }
    }
    ctx->pc = 0x1444ACu;
label_1444ac:
    // 0x1444ac: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1444acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1444b0:
    // 0x1444b0: 0xc05220e  jal         func_148838
    ctx->pc = 0x1444B0u;
    SET_GPR_U32(ctx, 31, 0x1444B8u);
    ctx->pc = 0x1444B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1444B0u;
            // 0x1444b4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148838u;
    if (runtime->hasFunction(0x148838u)) {
        auto targetFn = runtime->lookupFunction(0x148838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1444B8u; }
        if (ctx->pc != 0x1444B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148838_0x148838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1444B8u; }
        if (ctx->pc != 0x1444B8u) { return; }
    }
    ctx->pc = 0x1444B8u;
label_1444b8:
    // 0x1444b8: 0xae370134  sw          $s7, 0x134($s1)
    ctx->pc = 0x1444b8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 308), GPR_U32(ctx, 23));
    // 0x1444bc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1444BCu;
    {
        const bool branch_taken_0x1444bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1444C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1444BCu;
            // 0x1444c0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1444bc) {
            ctx->pc = 0x1444D4u;
            goto label_1444d4;
        }
    }
    ctx->pc = 0x1444C4u;
label_1444c4:
    // 0x1444c4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1444c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1444c8:
    // 0x1444c8: 0x1440ffdb  bnez        $v0, . + 4 + (-0x25 << 2)
    ctx->pc = 0x1444C8u;
    {
        const bool branch_taken_0x1444c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1444CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1444C8u;
            // 0x1444cc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1444c8) {
            ctx->pc = 0x144438u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_144438;
        }
    }
    ctx->pc = 0x1444D0u;
    // 0x1444d0: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x1444d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1444d4:
    // 0x1444d4: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1444d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1444d8: 0xdfb70070  ld          $s7, 0x70($sp)
    ctx->pc = 0x1444d8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1444dc: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x1444dcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1444e0: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x1444e0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1444e4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x1444e4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1444e8: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x1444e8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1444ec: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1444ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1444f0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1444f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1444f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1444f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1444f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1444F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1444FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1444F8u;
            // 0x1444fc: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144438u: goto label_144438;
            case 0x144440u: goto label_144440;
            case 0x144464u: goto label_144464;
            case 0x144478u: goto label_144478;
            case 0x144480u: goto label_144480;
            case 0x1444A4u: goto label_1444a4;
            case 0x1444ACu: goto label_1444ac;
            case 0x1444B0u: goto label_1444b0;
            case 0x1444B8u: goto label_1444b8;
            case 0x1444C4u: goto label_1444c4;
            case 0x1444C8u: goto label_1444c8;
            case 0x1444D4u: goto label_1444d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144500u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
