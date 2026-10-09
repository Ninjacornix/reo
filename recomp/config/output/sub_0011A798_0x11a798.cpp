#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011A798
// Address: 0x11a798 - 0x11a9d4
void sub_0011A798_0x11a798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011A798_0x11a798");
#endif

    switch (ctx->pc) {
        case 0x11a7e0u: goto label_11a7e0;
        case 0x11a7f8u: goto label_11a7f8;
        case 0x11a818u: goto label_11a818;
        case 0x11a904u: goto label_11a904;
        case 0x11a924u: goto label_11a924;
        case 0x11a94cu: goto label_11a94c;
        case 0x11a95cu: goto label_11a95c;
        case 0x11a964u: goto label_11a964;
        case 0x11a978u: goto label_11a978;
        case 0x11a988u: goto label_11a988;
        case 0x11a998u: goto label_11a998;
        case 0x11a9a0u: goto label_11a9a0;
        default: break;
    }

    ctx->pc = 0x11a798u;

    // 0x11a798: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x11a798u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x11a79c: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x11a79cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11a7a0: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x11a7a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x11a7a4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x11a7a4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a7a8: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x11a7a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x11a7ac: 0xc0b82d  daddu       $s7, $a2, $zero
    ctx->pc = 0x11a7acu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a7b0: 0xffbe00c0  sd          $fp, 0xC0($sp)
    ctx->pc = 0x11a7b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 30));
    // 0x11a7b4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x11a7b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a7b8: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x11a7b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x11a7bc: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x11a7bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x11a7c0: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x11a7c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x11a7c4: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x11a7c4u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
    // 0x11a7c8: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x11a7c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x11a7cc: 0x27d3ca40  addiu       $s3, $fp, -0x35C0
    ctx->pc = 0x11a7ccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 30), 4294953536));
    // 0x11a7d0: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x11a7d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x11a7d4: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x11a7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x11a7d8: 0xc04619c  jal         func_118670
    ctx->pc = 0x11A7D8u;
    SET_GPR_U32(ctx, 31, 0x11A7E0u);
    ctx->pc = 0x11A7DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A7D8u;
            // 0x11a7dc: 0xffb10050  sd          $s1, 0x50($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A7E0u; }
        if (ctx->pc != 0x11A7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A7E0u; }
        if (ctx->pc != 0x11A7E0u) { return; }
    }
    ctx->pc = 0x11A7E0u;
label_11a7e0:
    // 0x11a7e0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11a7e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11a7e4: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x11a7e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x11a7e8: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11A7E8u;
    {
        const bool branch_taken_0x11a7e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a7e8) {
            ctx->pc = 0x11A7ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11A7E8u;
            // 0x11a7ec: 0x92420000  lbu         $v0, 0x0($s2) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11A7FCu;
            goto label_11a7fc;
        }
    }
    ctx->pc = 0x11A7F0u;
    // 0x11a7f0: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x11A7F0u;
    SET_GPR_U32(ctx, 31, 0x11A7F8u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A7F8u; }
        if (ctx->pc != 0x11A7F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A7F8u; }
        if (ctx->pc != 0x11A7F8u) { return; }
    }
    ctx->pc = 0x11A7F8u;
label_11a7f8:
    // 0x11a7f8: 0x92420000  lbu         $v0, 0x0($s2)
    ctx->pc = 0x11a7f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
label_11a7fc:
    // 0x11a7fc: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x11a7fcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a800: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x11a800u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a804: 0x1060000e  beqz        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x11A804u;
    {
        const bool branch_taken_0x11a804 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A804u;
            // 0x11a808: 0xa2620050  sb          $v0, 0x50($s3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 19), 80), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a804) {
            ctx->pc = 0x11A840u;
            goto label_11a840;
        }
    }
    ctx->pc = 0x11A80Cu;
    // 0x11a80c: 0x27b40030  addiu       $s4, $sp, 0x30
    ctx->pc = 0x11a80cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11a810: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11a810u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11a814: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11a814u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
label_11a818:
    // 0x11a818: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x11a818u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x11a81c: 0x2a220400  slti        $v0, $s1, 0x400
    ctx->pc = 0x11a81cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11a820: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x11A820u;
    {
        const bool branch_taken_0x11a820 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A820u;
            // 0x11a824: 0x2511021  addu        $v0, $s2, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a820) {
            ctx->pc = 0x11A84Cu;
            goto label_11a84c;
        }
    }
    ctx->pc = 0x11A828u;
    // 0x11a828: 0x2712021  addu        $a0, $s3, $s1
    ctx->pc = 0x11a828u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 17)));
    // 0x11a82c: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x11a82cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11a830: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x11A830u;
    {
        const bool branch_taken_0x11a830 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x11A834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A830u;
            // 0x11a834: 0xa0830050  sb          $v1, 0x50($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 80), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a830) {
            ctx->pc = 0x11A818u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11a818;
        }
    }
    ctx->pc = 0x11A838u;
    // 0x11a838: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x11A838u;
    {
        const bool branch_taken_0x11a838 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A83Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A838u;
            // 0x11a83c: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a838) {
            ctx->pc = 0x11A850u;
            goto label_11a850;
        }
    }
    ctx->pc = 0x11A840u;
label_11a840:
    // 0x11a840: 0x27b40030  addiu       $s4, $sp, 0x30
    ctx->pc = 0x11a840u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x11a844: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x11a844u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x11a848: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11a848u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
label_11a84c:
    // 0x11a84c: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x11a84cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_11a850:
    // 0x11a850: 0x16220003  bne         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11A850u;
    {
        const bool branch_taken_0x11a850 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x11a850) {
            ctx->pc = 0x11A860u;
            goto label_11a860;
        }
    }
    ctx->pc = 0x11A858u;
    // 0x11a858: 0xa260044f  sb          $zero, 0x44F($s3)
    ctx->pc = 0x11a858u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 1103), (uint8_t)GPR_U32(ctx, 0));
    // 0x11a85c: 0x241103ff  addiu       $s1, $zero, 0x3FF
    ctx->pc = 0x11a85cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1023));
label_11a860:
    // 0x11a860: 0x6a030007  ldl         $v1, 0x7($s0)
    ctx->pc = 0x11a860u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x11a864: 0x6e030000  ldr         $v1, 0x0($s0)
    ctx->pc = 0x11a864u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x11a868: 0x6a04000f  ldl         $a0, 0xF($s0)
    ctx->pc = 0x11a868u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x11a86c: 0x6e040008  ldr         $a0, 0x8($s0)
    ctx->pc = 0x11a86cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x11a870: 0x6a050017  ldl         $a1, 0x17($s0)
    ctx->pc = 0x11a870u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x11a874: 0x6e050010  ldr         $a1, 0x10($s0)
    ctx->pc = 0x11a874u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x11a878: 0x6a06001f  ldl         $a2, 0x1F($s0)
    ctx->pc = 0x11a878u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x11a87c: 0x6e060018  ldr         $a2, 0x18($s0)
    ctx->pc = 0x11a87cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x11a880: 0xb2630017  sdl         $v1, 0x17($s3)
    ctx->pc = 0x11a880u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a884: 0xb6630010  sdr         $v1, 0x10($s3)
    ctx->pc = 0x11a884u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a888: 0xb264001f  sdl         $a0, 0x1F($s3)
    ctx->pc = 0x11a888u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a88c: 0xb6640018  sdr         $a0, 0x18($s3)
    ctx->pc = 0x11a88cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a890: 0xb2650027  sdl         $a1, 0x27($s3)
    ctx->pc = 0x11a890u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a894: 0xb6650020  sdr         $a1, 0x20($s3)
    ctx->pc = 0x11a894u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a898: 0xb266002f  sdl         $a2, 0x2F($s3)
    ctx->pc = 0x11a898u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a89c: 0xb6660028  sdr         $a2, 0x28($s3)
    ctx->pc = 0x11a89cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8a0: 0x6a030027  ldl         $v1, 0x27($s0)
    ctx->pc = 0x11a8a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 39); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x11a8a4: 0x6e030020  ldr         $v1, 0x20($s0)
    ctx->pc = 0x11a8a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 32); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x11a8a8: 0x6a04002f  ldl         $a0, 0x2F($s0)
    ctx->pc = 0x11a8a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 47); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x11a8ac: 0x6e040028  ldr         $a0, 0x28($s0)
    ctx->pc = 0x11a8acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 40); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x11a8b0: 0x6a050037  ldl         $a1, 0x37($s0)
    ctx->pc = 0x11a8b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x11a8b4: 0x6e050030  ldr         $a1, 0x30($s0)
    ctx->pc = 0x11a8b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x11a8b8: 0x6a06003f  ldl         $a2, 0x3F($s0)
    ctx->pc = 0x11a8b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x11a8bc: 0x6e060038  ldr         $a2, 0x38($s0)
    ctx->pc = 0x11a8bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x11a8c0: 0xb2630037  sdl         $v1, 0x37($s3)
    ctx->pc = 0x11a8c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 55); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8c4: 0xb6630030  sdr         $v1, 0x30($s3)
    ctx->pc = 0x11a8c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 48); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8c8: 0xb264003f  sdl         $a0, 0x3F($s3)
    ctx->pc = 0x11a8c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 63); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8cc: 0xb6640038  sdr         $a0, 0x38($s3)
    ctx->pc = 0x11a8ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 56); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8d0: 0xb2650047  sdl         $a1, 0x47($s3)
    ctx->pc = 0x11a8d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 71); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8d4: 0xb6650040  sdr         $a1, 0x40($s3)
    ctx->pc = 0x11a8d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 64); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8d8: 0xb266004f  sdl         $a2, 0x4F($s3)
    ctx->pc = 0x11a8d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 79); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8dc: 0xb6660048  sdr         $a2, 0x48($s3)
    ctx->pc = 0x11a8dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 19), 72); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11a8e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11a8e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11a8e4: 0xae77000c  sw          $s7, 0xC($s3)
    ctx->pc = 0x11a8e4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 23));
    // 0x11a8e8: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x11a8e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11a8ec: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x11a8ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x11a8f0: 0x27d0ca40  addiu       $s0, $fp, -0x35C0
    ctx->pc = 0x11a8f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 30), 4294953536));
    // 0x11a8f4: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x11a8f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x11a8f8: 0x26b5d680  addiu       $s5, $s5, -0x2980
    ctx->pc = 0x11a8f8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294956672));
    // 0x11a8fc: 0xc045188  jal         func_114620
    ctx->pc = 0x11A8FCu;
    SET_GPR_U32(ctx, 31, 0x11A904u);
    ctx->pc = 0x11A900u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A8FCu;
            // 0x11a900: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A904u; }
        if (ctx->pc != 0x11A904u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A904u; }
        if (ctx->pc != 0x11A904u) { return; }
    }
    ctx->pc = 0x11A904u;
label_11a904:
    // 0x11a904: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11a904u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a908: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11a908u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a90c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x11a90cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a910: 0xae740004  sw          $s4, 0x4($s3)
    ctx->pc = 0x11a910u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
    // 0x11a914: 0xae620008  sw          $v0, 0x8($s3)
    ctx->pc = 0x11a914u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 2));
    // 0x11a918: 0x24050450  addiu       $a1, $zero, 0x450
    ctx->pc = 0x11a918u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1104));
    // 0x11a91c: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x11A91Cu;
    SET_GPR_U32(ctx, 31, 0x11A924u);
    ctx->pc = 0x11A920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A91Cu;
            // 0x11a920: 0xae720000  sw          $s2, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A924u; }
        if (ctx->pc != 0x11A924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A924u; }
        if (ctx->pc != 0x11A924u) { return; }
    }
    ctx->pc = 0x11A924u;
label_11a924:
    // 0x11a924: 0x26c4e140  addiu       $a0, $s6, -0x1EC0
    ctx->pc = 0x11a924u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 4294959424));
    // 0x11a928: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11a928u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a92c: 0x26280051  addiu       $t0, $s1, 0x51
    ctx->pc = 0x11a92cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 81));
    // 0x11a930: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11a930u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11a934: 0x2405000d  addiu       $a1, $zero, 0xD
    ctx->pc = 0x11a934u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x11a938: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11a938u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a93c: 0x2a0482d  daddu       $t1, $s5, $zero
    ctx->pc = 0x11a93cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11a940: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x11a940u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x11a944: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11A944u;
    SET_GPR_U32(ctx, 31, 0x11A94Cu);
    ctx->pc = 0x11A948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A944u;
            // 0x11a948: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A94Cu; }
        if (ctx->pc != 0x11A94Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A94Cu; }
        if (ctx->pc != 0x11A94Cu) { return; }
    }
    ctx->pc = 0x11A94Cu;
label_11a94c:
    // 0x11a94c: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x11A94Cu;
    {
        const bool branch_taken_0x11a94c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x11A950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A94Cu;
            // 0x11a950: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a94c) {
            ctx->pc = 0x11A96Cu;
            goto label_11a96c;
        }
    }
    ctx->pc = 0x11A954u;
    // 0x11a954: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A954u;
    SET_GPR_U32(ctx, 31, 0x11A95Cu);
    ctx->pc = 0x11A958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A954u;
            // 0x11a958: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A95Cu; }
        if (ctx->pc != 0x11A95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A95Cu; }
        if (ctx->pc != 0x11A95Cu) { return; }
    }
    ctx->pc = 0x11A95Cu;
label_11a95c:
    // 0x11a95c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A95Cu;
    SET_GPR_U32(ctx, 31, 0x11A964u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A964u; }
        if (ctx->pc != 0x11A964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A964u; }
        if (ctx->pc != 0x11A964u) { return; }
    }
    ctx->pc = 0x11A964u;
label_11a964:
    // 0x11a964: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x11A964u;
    {
        const bool branch_taken_0x11a964 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A964u;
            // 0x11a968: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a964) {
            ctx->pc = 0x11A9A4u;
            goto label_11a9a4;
        }
    }
    ctx->pc = 0x11A96Cu;
label_11a96c:
    // 0x11a96c: 0x2a21025  or          $v0, $s5, $v0
    ctx->pc = 0x11a96cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) | GPR_U64(ctx, 2));
    // 0x11a970: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11A970u;
    SET_GPR_U32(ctx, 31, 0x11A978u);
    ctx->pc = 0x11A974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A970u;
            // 0x11a974: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A978u; }
        if (ctx->pc != 0x11A978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A978u; }
        if (ctx->pc != 0x11A978u) { return; }
    }
    ctx->pc = 0x11A978u;
label_11a978:
    // 0x11a978: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11A978u;
    {
        const bool branch_taken_0x11a978 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x11a978) {
            ctx->pc = 0x11A990u;
            goto label_11a990;
        }
    }
    ctx->pc = 0x11A980u;
    // 0x11a980: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A980u;
    SET_GPR_U32(ctx, 31, 0x11A988u);
    ctx->pc = 0x11A984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A980u;
            // 0x11a984: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A988u; }
        if (ctx->pc != 0x11A988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A988u; }
        if (ctx->pc != 0x11A988u) { return; }
    }
    ctx->pc = 0x11A988u;
label_11a988:
    // 0x11a988: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x11A988u;
    {
        const bool branch_taken_0x11a988 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11A98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A988u;
            // 0x11a98c: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11a988) {
            ctx->pc = 0x11A9A4u;
            goto label_11a9a4;
        }
    }
    ctx->pc = 0x11A990u;
label_11a990:
    // 0x11a990: 0xc045198  jal         func_114660
    ctx->pc = 0x11A990u;
    SET_GPR_U32(ctx, 31, 0x11A998u);
    ctx->pc = 0x11A994u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A990u;
            // 0x11a994: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A998u; }
        if (ctx->pc != 0x11A998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A998u; }
        if (ctx->pc != 0x11A998u) { return; }
    }
    ctx->pc = 0x11A998u;
label_11a998:
    // 0x11a998: 0xc04518c  jal         func_114630
    ctx->pc = 0x11A998u;
    SET_GPR_U32(ctx, 31, 0x11A9A0u);
    ctx->pc = 0x11A99Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11A998u;
            // 0x11a99c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A9A0u; }
        if (ctx->pc != 0x11A9A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11A9A0u; }
        if (ctx->pc != 0x11A9A0u) { return; }
    }
    ctx->pc = 0x11A9A0u;
label_11a9a0:
    // 0x11a9a0: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11a9a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11a9a4:
    // 0x11a9a4: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x11a9a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x11a9a8: 0xdfbe00c0  ld          $fp, 0xC0($sp)
    ctx->pc = 0x11a9a8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x11a9ac: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x11a9acu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x11a9b0: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x11a9b0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x11a9b4: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x11a9b4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x11a9b8: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x11a9b8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11a9bc: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11a9bcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11a9c0: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x11a9c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11a9c4: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x11a9c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11a9c8: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x11a9c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11a9cc: 0x3e00008  jr          $ra
    ctx->pc = 0x11A9CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11A9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11A9CCu;
            // 0x11a9d0: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11A7E0u: goto label_11a7e0;
            case 0x11A7F8u: goto label_11a7f8;
            case 0x11A7FCu: goto label_11a7fc;
            case 0x11A818u: goto label_11a818;
            case 0x11A840u: goto label_11a840;
            case 0x11A84Cu: goto label_11a84c;
            case 0x11A850u: goto label_11a850;
            case 0x11A860u: goto label_11a860;
            case 0x11A904u: goto label_11a904;
            case 0x11A924u: goto label_11a924;
            case 0x11A94Cu: goto label_11a94c;
            case 0x11A95Cu: goto label_11a95c;
            case 0x11A964u: goto label_11a964;
            case 0x11A96Cu: goto label_11a96c;
            case 0x11A978u: goto label_11a978;
            case 0x11A988u: goto label_11a988;
            case 0x11A990u: goto label_11a990;
            case 0x11A998u: goto label_11a998;
            case 0x11A9A0u: goto label_11a9a0;
            case 0x11A9A4u: goto label_11a9a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11A9D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
