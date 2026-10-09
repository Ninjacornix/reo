#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137468
// Address: 0x137468 - 0x137558
void sub_00137468_0x137468(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137468_0x137468");
#endif

    switch (ctx->pc) {
        case 0x1374acu: goto label_1374ac;
        case 0x1374b4u: goto label_1374b4;
        case 0x1374c0u: goto label_1374c0;
        case 0x1374d4u: goto label_1374d4;
        case 0x137528u: goto label_137528;
        default: break;
    }

    ctx->pc = 0x137468u;

    // 0x137468: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x137468u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13746c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13746cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x137470: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x137470u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137474: 0x24041200  addiu       $a0, $zero, 0x1200
    ctx->pc = 0x137474u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4608));
    // 0x137478: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x137478u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13747c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13747cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x137480: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x137480u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137484: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x137484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x137488: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x137488u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13748c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x13748cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x137490: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x137490u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137494: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x137494u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x137498: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x137498u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13749c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x13749cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x1374a0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x1374a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x1374a4: 0xc04e082  jal         func_138208
    ctx->pc = 0x1374A4u;
    SET_GPR_U32(ctx, 31, 0x1374ACu);
    ctx->pc = 0x1374A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1374A4u;
            // 0x1374a8: 0xe0b02d  daddu       $s6, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1374ACu; }
        if (ctx->pc != 0x1374ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1374ACu; }
        if (ctx->pc != 0x1374ACu) { return; }
    }
    ctx->pc = 0x1374ACu;
label_1374ac:
    // 0x1374ac: 0xc04035e  jal         func_100D78
    ctx->pc = 0x1374ACu;
    SET_GPR_U32(ctx, 31, 0x1374B4u);
    ctx->pc = 0x1374B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1374ACu;
            // 0x1374b0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1374B4u; }
        if (ctx->pc != 0x1374B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1374B4u; }
        if (ctx->pc != 0x1374B4u) { return; }
    }
    ctx->pc = 0x1374B4u;
label_1374b4:
    // 0x1374b4: 0x24041201  addiu       $a0, $zero, 0x1201
    ctx->pc = 0x1374b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4609));
    // 0x1374b8: 0xc04e082  jal         func_138208
    ctx->pc = 0x1374B8u;
    SET_GPR_U32(ctx, 31, 0x1374C0u);
    ctx->pc = 0x1374BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1374B8u;
            // 0x1374bc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1374C0u; }
        if (ctx->pc != 0x1374C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1374C0u; }
        if (ctx->pc != 0x1374C0u) { return; }
    }
    ctx->pc = 0x1374C0u;
label_1374c0:
    // 0x1374c0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1374c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1374c4: 0x12030019  beq         $s0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1374C4u;
    {
        const bool branch_taken_0x1374c4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x1374C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1374C4u;
            // 0x1374c8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1374c4) {
            ctx->pc = 0x13752Cu;
            goto label_13752c;
        }
    }
    ctx->pc = 0x1374CCu;
    // 0x1374cc: 0xc0505c0  jal         func_141700
    ctx->pc = 0x1374CCu;
    SET_GPR_U32(ctx, 31, 0x1374D4u);
    ctx->pc = 0x141700u;
    if (runtime->hasFunction(0x141700u)) {
        auto targetFn = runtime->lookupFunction(0x141700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1374D4u; }
        if (ctx->pc != 0x1374D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141700_0x141700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1374D4u; }
        if (ctx->pc != 0x1374D4u) { return; }
    }
    ctx->pc = 0x1374D4u;
label_1374d4:
    // 0x1374d4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1374d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1374d8: 0x82230002  lb          $v1, 0x2($s1)
    ctx->pc = 0x1374d8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1374dc: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1374DCu;
    {
        const bool branch_taken_0x1374dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1374E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1374DCu;
            // 0x1374e0: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1374dc) {
            ctx->pc = 0x1374F4u;
            goto label_1374f4;
        }
    }
    ctx->pc = 0x1374E4u;
    // 0x1374e4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1374E4u;
    {
        const bool branch_taken_0x1374e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1374E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1374E4u;
            // 0x1374e8: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1374e4) {
            ctx->pc = 0x1374F4u;
            goto label_1374f4;
        }
    }
    ctx->pc = 0x1374ECu;
    // 0x1374ec: 0x1462000c  bne         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1374ECu;
    {
        const bool branch_taken_0x1374ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1374ec) {
            ctx->pc = 0x137520u;
            goto label_137520;
        }
    }
    ctx->pc = 0x1374F4u;
label_1374f4:
    // 0x1374f4: 0xa2240002  sb          $a0, 0x2($s1)
    ctx->pc = 0x1374f4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1374f8: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x1374f8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1374fc: 0xa2240001  sb          $a0, 0x1($s1)
    ctx->pc = 0x1374fcu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 4));
    // 0x137500: 0xae330008  sw          $s3, 0x8($s1)
    ctx->pc = 0x137500u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 19));
    // 0x137504: 0x8a420003  lwl         $v0, 0x3($s2)
    ctx->pc = 0x137504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x137508: 0x9a420000  lwr         $v0, 0x0($s2)
    ctx->pc = 0x137508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x13750c: 0xaa220017  swl         $v0, 0x17($s1)
    ctx->pc = 0x13750cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 23); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x137510: 0xba220014  swr         $v0, 0x14($s1)
    ctx->pc = 0x137510u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 20); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x137514: 0xae35000c  sw          $s5, 0xC($s1)
    ctx->pc = 0x137514u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 21));
    // 0x137518: 0xae360010  sw          $s6, 0x10($s1)
    ctx->pc = 0x137518u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 22));
    // 0x13751c: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x13751cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_137520:
    // 0x137520: 0xc0505de  jal         func_141778
    ctx->pc = 0x137520u;
    SET_GPR_U32(ctx, 31, 0x137528u);
    ctx->pc = 0x141778u;
    if (runtime->hasFunction(0x141778u)) {
        auto targetFn = runtime->lookupFunction(0x141778u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137528u; }
        if (ctx->pc != 0x137528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141778_0x141778(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137528u; }
        if (ctx->pc != 0x137528u) { return; }
    }
    ctx->pc = 0x137528u;
label_137528:
    // 0x137528: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x137528u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_13752c:
    // 0x13752c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13752cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137530: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x137530u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137534: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x137534u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137538: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x137538u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13753c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x13753cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x137540: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x137540u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x137544: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x137544u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x137548: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x137548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13754c: 0x3e00008  jr          $ra
    ctx->pc = 0x13754Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13754Cu;
            // 0x137550: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1374ACu: goto label_1374ac;
            case 0x1374B4u: goto label_1374b4;
            case 0x1374C0u: goto label_1374c0;
            case 0x1374D4u: goto label_1374d4;
            case 0x1374F4u: goto label_1374f4;
            case 0x137520u: goto label_137520;
            case 0x137528u: goto label_137528;
            case 0x13752Cu: goto label_13752c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137554u;
    // 0x137554: 0x0  nop
    ctx->pc = 0x137554u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
