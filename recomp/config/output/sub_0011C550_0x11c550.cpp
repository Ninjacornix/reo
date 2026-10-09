#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C550
// Address: 0x11c550 - 0x11c778
void sub_0011C550_0x11c550(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C550_0x11c550");
#endif

    switch (ctx->pc) {
        case 0x11c588u: goto label_11c588;
        case 0x11c598u: goto label_11c598;
        case 0x11c5c0u: goto label_11c5c0;
        case 0x11c5f8u: goto label_11c5f8;
        case 0x11c660u: goto label_11c660;
        case 0x11c6f0u: goto label_11c6f0;
        case 0x11c734u: goto label_11c734;
        default: break;
    }

    ctx->pc = 0x11c550u;

    // 0x11c550: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x11c550u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x11c554: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x11c554u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x11c558: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x11c558u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x11c55c: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x11c55cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c560: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x11c560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x11c564: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x11c564u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c568: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11c568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11c56c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11c56cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c570: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11c570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11c574: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11c574u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c578: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x11c578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x11c57c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x11c57cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c580: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11C580u;
    SET_GPR_U32(ctx, 31, 0x11C588u);
    ctx->pc = 0x11C584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C580u;
            // 0x11c584: 0xffb50060  sd          $s5, 0x60($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C588u; }
        if (ctx->pc != 0x11C588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C588u; }
        if (ctx->pc != 0x11C588u) { return; }
    }
    ctx->pc = 0x11C588u;
label_11c588:
    // 0x11c588: 0x4400071  bltz        $v0, . + 4 + (0x71 << 2)
    ctx->pc = 0x11C588u;
    {
        const bool branch_taken_0x11c588 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x11C58Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C588u;
            // 0x11c58c: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c588) {
            ctx->pc = 0x11C750u;
            goto label_11c750;
        }
    }
    ctx->pc = 0x11C590u;
    // 0x11c590: 0xc046f9e  jal         func_11BE78
    ctx->pc = 0x11C590u;
    SET_GPR_U32(ctx, 31, 0x11C598u);
    ctx->pc = 0x11BE78u;
    if (runtime->hasFunction(0x11BE78u)) {
        auto targetFn = runtime->lookupFunction(0x11BE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C598u; }
        if (ctx->pc != 0x11C598u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BE78_0x11be78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C598u; }
        if (ctx->pc != 0x11C598u) { return; }
    }
    ctx->pc = 0x11C598u;
label_11c598:
    // 0x11c598: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C598u;
    {
        const bool branch_taken_0x11c598 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11c598) {
            ctx->pc = 0x11C59Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C598u;
            // 0x11c59c: 0x3c020026  lui         $v0, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C5ACu;
            goto label_11c5ac;
        }
    }
    ctx->pc = 0x11C5A0u;
    // 0x11c5a0: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c5a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c5a4: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x11C5A4u;
    {
        const bool branch_taken_0x11c5a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C5A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C5A4u;
            // 0x11c5a8: 0x3442fffc  ori         $v0, $v0, 0xFFFC (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65532);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c5a4) {
            ctx->pc = 0x11C750u;
            goto label_11c750;
        }
    }
    ctx->pc = 0x11C5ACu;
label_11c5ac:
    // 0x11c5ac: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x11c5acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c5b0: 0x2451e408  addiu       $s1, $v0, -0x1BF8
    ctx->pc = 0x11c5b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960136));
    // 0x11c5b4: 0x240600fc  addiu       $a2, $zero, 0xFC
    ctx->pc = 0x11c5b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
    // 0x11c5b8: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x11C5B8u;
    SET_GPR_U32(ctx, 31, 0x11C5C0u);
    ctx->pc = 0x11C5BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C5B8u;
            // 0x11c5bc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C5C0u; }
        if (ctx->pc != 0x11C5C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C5C0u; }
        if (ctx->pc != 0x11C5C0u) { return; }
    }
    ctx->pc = 0x11C5C0u;
label_11c5c0:
    // 0x11c5c0: 0x2622fff8  addiu       $v0, $s1, -0x8
    ctx->pc = 0x11c5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967288));
    // 0x11c5c4: 0x1200004c  beqz        $s0, . + 4 + (0x4C << 2)
    ctx->pc = 0x11C5C4u;
    {
        const bool branch_taken_0x11c5c4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C5C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C5C4u;
            // 0x11c5c8: 0xa0400103  sb          $zero, 0x103($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 259), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c5c4) {
            ctx->pc = 0x11C6F8u;
            goto label_11c6f8;
        }
    }
    ctx->pc = 0x11C5CCu;
    // 0x11c5cc: 0x2a4200fd  slti        $v0, $s2, 0xFD
    ctx->pc = 0x11c5ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)253) ? 1 : 0);
    // 0x11c5d0: 0x14400043  bnez        $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x11C5D0u;
    {
        const bool branch_taken_0x11c5d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11C5D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C5D0u;
            // 0x11c5d4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c5d0) {
            ctx->pc = 0x11C6E0u;
            goto label_11c6e0;
        }
    }
    ctx->pc = 0x11C5D8u;
    // 0x11c5d8: 0x262400fc  addiu       $a0, $s1, 0xFC
    ctx->pc = 0x11c5d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 252));
    // 0x11c5dc: 0x2041025  or          $v0, $s0, $a0
    ctx->pc = 0x11c5dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 4));
    // 0x11c5e0: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x11c5e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x11c5e4: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x11C5E4u;
    {
        const bool branch_taken_0x11c5e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C5E4u;
            // 0x11c5e8: 0x200182d  daddu       $v1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c5e4) {
            ctx->pc = 0x11C654u;
            goto label_11c654;
        }
    }
    ctx->pc = 0x11C5ECu;
    // 0x11c5ec: 0x260200e0  addiu       $v0, $s0, 0xE0
    ctx->pc = 0x11c5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 224));
    // 0x11c5f0: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11c5f0u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11c5f4: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11c5f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
label_11c5f8:
    // 0x11c5f8: 0x68660007  ldl         $a2, 0x7($v1)
    ctx->pc = 0x11c5f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x11c5fc: 0x6c660000  ldr         $a2, 0x0($v1)
    ctx->pc = 0x11c5fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x11c600: 0x6867000f  ldl         $a3, 0xF($v1)
    ctx->pc = 0x11c600u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x11c604: 0x6c670008  ldr         $a3, 0x8($v1)
    ctx->pc = 0x11c604u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x11c608: 0x68680017  ldl         $t0, 0x17($v1)
    ctx->pc = 0x11c608u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x11c60c: 0x6c680010  ldr         $t0, 0x10($v1)
    ctx->pc = 0x11c60cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x11c610: 0x6869001f  ldl         $t1, 0x1F($v1)
    ctx->pc = 0x11c610u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x11c614: 0x6c690018  ldr         $t1, 0x18($v1)
    ctx->pc = 0x11c614u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x11c618: 0xb0860007  sdl         $a2, 0x7($a0)
    ctx->pc = 0x11c618u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c61c: 0xb4860000  sdr         $a2, 0x0($a0)
    ctx->pc = 0x11c61cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c620: 0xb087000f  sdl         $a3, 0xF($a0)
    ctx->pc = 0x11c620u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c624: 0xb4870008  sdr         $a3, 0x8($a0)
    ctx->pc = 0x11c624u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c628: 0xb0880017  sdl         $t0, 0x17($a0)
    ctx->pc = 0x11c628u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c62c: 0xb4880010  sdr         $t0, 0x10($a0)
    ctx->pc = 0x11c62cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c630: 0xb089001f  sdl         $t1, 0x1F($a0)
    ctx->pc = 0x11c630u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c634: 0xb4890018  sdr         $t1, 0x18($a0)
    ctx->pc = 0x11c634u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c638: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x11c638u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x11c63c: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x11c63cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x11c640: 0x0  nop
    ctx->pc = 0x11c640u;
    // NOP
    // 0x11c644: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x11C644u;
    {
        const bool branch_taken_0x11c644 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x11c644) {
            ctx->pc = 0x11C5F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11c5f8;
        }
    }
    ctx->pc = 0x11C64Cu;
    // 0x11c64c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11C64Cu;
    {
        const bool branch_taken_0x11c64c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11c64c) {
            ctx->pc = 0x11C694u;
            goto label_11c694;
        }
    }
    ctx->pc = 0x11C654u;
label_11c654:
    // 0x11c654: 0x260200e0  addiu       $v0, $s0, 0xE0
    ctx->pc = 0x11c654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 224));
    // 0x11c658: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11c658u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11c65c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11c65cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
label_11c660:
    // 0x11c660: 0xdc660000  ld          $a2, 0x0($v1)
    ctx->pc = 0x11c660u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11c664: 0xdc670008  ld          $a3, 0x8($v1)
    ctx->pc = 0x11c664u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x11c668: 0xdc680010  ld          $t0, 0x10($v1)
    ctx->pc = 0x11c668u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x11c66c: 0xdc690018  ld          $t1, 0x18($v1)
    ctx->pc = 0x11c66cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x11c670: 0xfc860000  sd          $a2, 0x0($a0)
    ctx->pc = 0x11c670u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 6));
    // 0x11c674: 0xfc870008  sd          $a3, 0x8($a0)
    ctx->pc = 0x11c674u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 7));
    // 0x11c678: 0xfc880010  sd          $t0, 0x10($a0)
    ctx->pc = 0x11c678u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 8));
    // 0x11c67c: 0xfc890018  sd          $t1, 0x18($a0)
    ctx->pc = 0x11c67cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 9));
    // 0x11c680: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x11c680u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x11c684: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x11c684u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x11c688: 0x0  nop
    ctx->pc = 0x11c688u;
    // NOP
    // 0x11c68c: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x11C68Cu;
    {
        const bool branch_taken_0x11c68c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x11c68c) {
            ctx->pc = 0x11C660u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11c660;
        }
    }
    ctx->pc = 0x11C694u;
label_11c694:
    // 0x11c694: 0x68660007  ldl         $a2, 0x7($v1)
    ctx->pc = 0x11c694u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x11c698: 0x6c660000  ldr         $a2, 0x0($v1)
    ctx->pc = 0x11c698u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x11c69c: 0x6867000f  ldl         $a3, 0xF($v1)
    ctx->pc = 0x11c69cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x11c6a0: 0x6c670008  ldr         $a3, 0x8($v1)
    ctx->pc = 0x11c6a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x11c6a4: 0x68680017  ldl         $t0, 0x17($v1)
    ctx->pc = 0x11c6a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x11c6a8: 0x6c680010  ldr         $t0, 0x10($v1)
    ctx->pc = 0x11c6a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x11c6ac: 0x8869001b  lwl         $t1, 0x1B($v1)
    ctx->pc = 0x11c6acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 9) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 9, (int32_t)merged); }
    // 0x11c6b0: 0x98690018  lwr         $t1, 0x18($v1)
    ctx->pc = 0x11c6b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 9) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 9) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 9, merged64); }
    // 0x11c6b4: 0xb0860007  sdl         $a2, 0x7($a0)
    ctx->pc = 0x11c6b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c6b8: 0xb4860000  sdr         $a2, 0x0($a0)
    ctx->pc = 0x11c6b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c6bc: 0xb087000f  sdl         $a3, 0xF($a0)
    ctx->pc = 0x11c6bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c6c0: 0xb4870008  sdr         $a3, 0x8($a0)
    ctx->pc = 0x11c6c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c6c4: 0xb0880017  sdl         $t0, 0x17($a0)
    ctx->pc = 0x11c6c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c6c8: 0xb4880010  sdr         $t0, 0x10($a0)
    ctx->pc = 0x11c6c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c6cc: 0xa889001b  swl         $t1, 0x1B($a0)
    ctx->pc = 0x11c6ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11c6d0: 0x240200fc  addiu       $v0, $zero, 0xFC
    ctx->pc = 0x11c6d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
    // 0x11c6d4: 0xb8890018  swr         $t1, 0x18($a0)
    ctx->pc = 0x11c6d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 9); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11c6d8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x11C6D8u;
    {
        const bool branch_taken_0x11c6d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C6DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C6D8u;
            // 0x11c6dc: 0xaea2e400  sw          $v0, -0x1C00($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 4294960128), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c6d8) {
            ctx->pc = 0x11C708u;
            goto label_11c708;
        }
    }
    ctx->pc = 0x11C6E0u;
label_11c6e0:
    // 0x11c6e0: 0x262400fc  addiu       $a0, $s1, 0xFC
    ctx->pc = 0x11c6e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 252));
    // 0x11c6e4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x11c6e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c6e8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x11C6E8u;
    SET_GPR_U32(ctx, 31, 0x11C6F0u);
    ctx->pc = 0x11C6ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C6E8u;
            // 0x11c6ec: 0x3c150026  lui         $s5, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C6F0u; }
        if (ctx->pc != 0x11C6F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C6F0u; }
        if (ctx->pc != 0x11C6F0u) { return; }
    }
    ctx->pc = 0x11C6F0u;
label_11c6f0:
    // 0x11c6f0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x11C6F0u;
    {
        const bool branch_taken_0x11c6f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C6F0u;
            // 0x11c6f4: 0xae32fff8  sw          $s2, -0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4294967288), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c6f0) {
            ctx->pc = 0x11C704u;
            goto label_11c704;
        }
    }
    ctx->pc = 0x11C6F8u;
label_11c6f8:
    // 0x11c6f8: 0xa0400104  sb          $zero, 0x104($v0)
    ctx->pc = 0x11c6f8u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 260), (uint8_t)GPR_U32(ctx, 0));
    // 0x11c6fc: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x11c6fcu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x11c700: 0xae20fff8  sw          $zero, -0x8($s1)
    ctx->pc = 0x11c700u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294967288), GPR_U32(ctx, 0));
label_11c704:
    // 0x11c704: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11c704u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
label_11c708:
    // 0x11c708: 0x26b0e400  addiu       $s0, $s5, -0x1C00
    ctx->pc = 0x11c708u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294960128));
    // 0x11c70c: 0x24a4e600  addiu       $a0, $a1, -0x1A00
    ctx->pc = 0x11c70cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 4294960640));
    // 0x11c710: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x11c710u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c714: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11c714u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11c718: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11c718u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c71c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11c71cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c720: 0x24080200  addiu       $t0, $zero, 0x200
    ctx->pc = 0x11c720u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x11c724: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x11c724u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c728: 0x240a0008  addiu       $t2, $zero, 0x8
    ctx->pc = 0x11c728u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x11c72c: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11C72Cu;
    SET_GPR_U32(ctx, 31, 0x11C734u);
    ctx->pc = 0x11C730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C72Cu;
            // 0x11c730: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C734u; }
        if (ctx->pc != 0x11C734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C734u; }
        if (ctx->pc != 0x11C734u) { return; }
    }
    ctx->pc = 0x11C734u;
label_11c734:
    // 0x11c734: 0x4430004  bgezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C734u;
    {
        const bool branch_taken_0x11c734 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11c734) {
            ctx->pc = 0x11C738u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C734u;
            // 0x11c738: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C748u;
            goto label_11c748;
        }
    }
    ctx->pc = 0x11C73Cu;
    // 0x11c73c: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c73cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c740: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11C740u;
    {
        const bool branch_taken_0x11c740 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C740u;
            // 0x11c744: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c740) {
            ctx->pc = 0x11C750u;
            goto label_11c750;
        }
    }
    ctx->pc = 0x11C748u;
label_11c748:
    // 0x11c748: 0x8ea2e400  lw          $v0, -0x1C00($s5)
    ctx->pc = 0x11c748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294960128)));
    // 0x11c74c: 0xae830000  sw          $v1, 0x0($s4)
    ctx->pc = 0x11c74cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 3));
label_11c750:
    // 0x11c750: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x11c750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11c754: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x11c754u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11c758: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x11c758u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11c75c: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x11c75cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11c760: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11c760u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11c764: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11c764u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11c768: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11c768u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c76c: 0x3e00008  jr          $ra
    ctx->pc = 0x11C76Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C76Cu;
            // 0x11c770: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C588u: goto label_11c588;
            case 0x11C598u: goto label_11c598;
            case 0x11C5ACu: goto label_11c5ac;
            case 0x11C5C0u: goto label_11c5c0;
            case 0x11C5F8u: goto label_11c5f8;
            case 0x11C654u: goto label_11c654;
            case 0x11C660u: goto label_11c660;
            case 0x11C694u: goto label_11c694;
            case 0x11C6E0u: goto label_11c6e0;
            case 0x11C6F0u: goto label_11c6f0;
            case 0x11C6F8u: goto label_11c6f8;
            case 0x11C704u: goto label_11c704;
            case 0x11C708u: goto label_11c708;
            case 0x11C734u: goto label_11c734;
            case 0x11C748u: goto label_11c748;
            case 0x11C750u: goto label_11c750;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C774u;
    // 0x11c774: 0x0  nop
    ctx->pc = 0x11c774u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
