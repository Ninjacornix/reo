#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011C148
// Address: 0x11c148 - 0x11c350
void sub_0011C148_0x11c148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011C148_0x11c148");
#endif

    switch (ctx->pc) {
        case 0x11c180u: goto label_11c180;
        case 0x11c190u: goto label_11c190;
        case 0x11c1dcu: goto label_11c1dc;
        case 0x11c240u: goto label_11c240;
        case 0x11c2d0u: goto label_11c2d0;
        case 0x11c30cu: goto label_11c30c;
        default: break;
    }

    ctx->pc = 0x11c148u;

    // 0x11c148: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x11c148u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x11c14c: 0xffb60070  sd          $s6, 0x70($sp)
    ctx->pc = 0x11c14cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x11c150: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x11c150u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x11c154: 0xe0b02d  daddu       $s6, $a3, $zero
    ctx->pc = 0x11c154u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c158: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x11c158u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x11c15c: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x11c15cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c160: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11c160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11c164: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x11c164u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c168: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x11c168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x11c16c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x11c16cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c170: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x11c170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x11c174: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x11c174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x11c178: 0xc046f5e  jal         func_11BD78
    ctx->pc = 0x11C178u;
    SET_GPR_U32(ctx, 31, 0x11C180u);
    ctx->pc = 0x11C17Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C178u;
            // 0x11c17c: 0xffb20030  sd          $s2, 0x30($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BD78u;
    if (runtime->hasFunction(0x11BD78u)) {
        auto targetFn = runtime->lookupFunction(0x11BD78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C180u; }
        if (ctx->pc != 0x11C180u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BD78_0x11bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C180u; }
        if (ctx->pc != 0x11C180u) { return; }
    }
    ctx->pc = 0x11C180u;
label_11c180:
    // 0x11c180: 0x4400069  bltz        $v0, . + 4 + (0x69 << 2)
    ctx->pc = 0x11C180u;
    {
        const bool branch_taken_0x11c180 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x11C184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C180u;
            // 0x11c184: 0x3c02ffff  lui         $v0, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c180) {
            ctx->pc = 0x11C328u;
            goto label_11c328;
        }
    }
    ctx->pc = 0x11C188u;
    // 0x11c188: 0xc046f9e  jal         func_11BE78
    ctx->pc = 0x11C188u;
    SET_GPR_U32(ctx, 31, 0x11C190u);
    ctx->pc = 0x11BE78u;
    if (runtime->hasFunction(0x11BE78u)) {
        auto targetFn = runtime->lookupFunction(0x11BE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C190u; }
        if (ctx->pc != 0x11C190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BE78_0x11be78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C190u; }
        if (ctx->pc != 0x11C190u) { return; }
    }
    ctx->pc = 0x11C190u;
label_11c190:
    // 0x11c190: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C190u;
    {
        const bool branch_taken_0x11c190 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C190u;
            // 0x11c194: 0x3c140026  lui         $s4, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c190) {
            ctx->pc = 0x11C1A4u;
            goto label_11c1a4;
        }
    }
    ctx->pc = 0x11C198u;
    // 0x11c198: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c198u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c19c: 0x10000062  b           . + 4 + (0x62 << 2)
    ctx->pc = 0x11C19Cu;
    {
        const bool branch_taken_0x11c19c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C1A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C19Cu;
            // 0x11c1a0: 0x3442fffc  ori         $v0, $v0, 0xFFFC (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65532);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c19c) {
            ctx->pc = 0x11C328u;
            goto label_11c328;
        }
    }
    ctx->pc = 0x11C1A4u;
label_11c1a4:
    // 0x11c1a4: 0x280a82d  daddu       $s5, $s4, $zero
    ctx->pc = 0x11c1a4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c1a8: 0x2692e400  addiu       $s2, $s4, -0x1C00
    ctx->pc = 0x11c1a8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), 4294960128));
    // 0x11c1ac: 0x1200004a  beqz        $s0, . + 4 + (0x4A << 2)
    ctx->pc = 0x11C1ACu;
    {
        const bool branch_taken_0x11c1ac = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C1ACu;
            // 0x11c1b0: 0xae93e400  sw          $s3, -0x1C00($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 4294960128), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c1ac) {
            ctx->pc = 0x11C2D8u;
            goto label_11c2d8;
        }
    }
    ctx->pc = 0x11C1B4u;
    // 0x11c1b4: 0x2a2200fd  slti        $v0, $s1, 0xFD
    ctx->pc = 0x11c1b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)253) ? 1 : 0);
    // 0x11c1b8: 0x14400042  bnez        $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x11C1B8u;
    {
        const bool branch_taken_0x11c1b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11C1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C1B8u;
            // 0x11c1bc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c1b8) {
            ctx->pc = 0x11C2C4u;
            goto label_11c2c4;
        }
    }
    ctx->pc = 0x11C1C0u;
    // 0x11c1c0: 0x26440104  addiu       $a0, $s2, 0x104
    ctx->pc = 0x11c1c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 260));
    // 0x11c1c4: 0x2041025  or          $v0, $s0, $a0
    ctx->pc = 0x11c1c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 4));
    // 0x11c1c8: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x11c1c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x11c1cc: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x11C1CCu;
    {
        const bool branch_taken_0x11c1cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C1CCu;
            // 0x11c1d0: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c1cc) {
            ctx->pc = 0x11C238u;
            goto label_11c238;
        }
    }
    ctx->pc = 0x11C1D4u;
    // 0x11c1d4: 0x260200e0  addiu       $v0, $s0, 0xE0
    ctx->pc = 0x11c1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 224));
    // 0x11c1d8: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11c1d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
label_11c1dc:
    // 0x11c1dc: 0x68e30007  ldl         $v1, 0x7($a3)
    ctx->pc = 0x11c1dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x11c1e0: 0x6ce30000  ldr         $v1, 0x0($a3)
    ctx->pc = 0x11c1e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x11c1e4: 0x68e6000f  ldl         $a2, 0xF($a3)
    ctx->pc = 0x11c1e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x11c1e8: 0x6ce60008  ldr         $a2, 0x8($a3)
    ctx->pc = 0x11c1e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x11c1ec: 0x68e80017  ldl         $t0, 0x17($a3)
    ctx->pc = 0x11c1ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x11c1f0: 0x6ce80010  ldr         $t0, 0x10($a3)
    ctx->pc = 0x11c1f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x11c1f4: 0x68e9001f  ldl         $t1, 0x1F($a3)
    ctx->pc = 0x11c1f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x11c1f8: 0x6ce90018  ldr         $t1, 0x18($a3)
    ctx->pc = 0x11c1f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x11c1fc: 0xb0830007  sdl         $v1, 0x7($a0)
    ctx->pc = 0x11c1fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c200: 0xb4830000  sdr         $v1, 0x0($a0)
    ctx->pc = 0x11c200u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c204: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x11c204u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c208: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x11c208u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c20c: 0xb0880017  sdl         $t0, 0x17($a0)
    ctx->pc = 0x11c20cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c210: 0xb4880010  sdr         $t0, 0x10($a0)
    ctx->pc = 0x11c210u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c214: 0xb089001f  sdl         $t1, 0x1F($a0)
    ctx->pc = 0x11c214u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c218: 0xb4890018  sdr         $t1, 0x18($a0)
    ctx->pc = 0x11c218u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c21c: 0x24e70020  addiu       $a3, $a3, 0x20
    ctx->pc = 0x11c21cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 32));
    // 0x11c220: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x11c220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x11c224: 0x0  nop
    ctx->pc = 0x11c224u;
    // NOP
    // 0x11c228: 0x14e2ffec  bne         $a3, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x11C228u;
    {
        const bool branch_taken_0x11c228 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        if (branch_taken_0x11c228) {
            ctx->pc = 0x11C1DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11c1dc;
        }
    }
    ctx->pc = 0x11C230u;
    // 0x11c230: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x11C230u;
    {
        const bool branch_taken_0x11c230 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11c230) {
            ctx->pc = 0x11C274u;
            goto label_11c274;
        }
    }
    ctx->pc = 0x11C238u;
label_11c238:
    // 0x11c238: 0x260200e0  addiu       $v0, $s0, 0xE0
    ctx->pc = 0x11c238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 224));
    // 0x11c23c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11c23cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
label_11c240:
    // 0x11c240: 0xdcea0000  ld          $t2, 0x0($a3)
    ctx->pc = 0x11c240u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x11c244: 0xdce30008  ld          $v1, 0x8($a3)
    ctx->pc = 0x11c244u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x11c248: 0xdce60010  ld          $a2, 0x10($a3)
    ctx->pc = 0x11c248u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x11c24c: 0xdce80018  ld          $t0, 0x18($a3)
    ctx->pc = 0x11c24cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x11c250: 0xfc8a0000  sd          $t2, 0x0($a0)
    ctx->pc = 0x11c250u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 10));
    // 0x11c254: 0xfc830008  sd          $v1, 0x8($a0)
    ctx->pc = 0x11c254u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 3));
    // 0x11c258: 0xfc860010  sd          $a2, 0x10($a0)
    ctx->pc = 0x11c258u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 6));
    // 0x11c25c: 0xfc880018  sd          $t0, 0x18($a0)
    ctx->pc = 0x11c25cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x11c260: 0x24e70020  addiu       $a3, $a3, 0x20
    ctx->pc = 0x11c260u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 32));
    // 0x11c264: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x11c264u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x11c268: 0x0  nop
    ctx->pc = 0x11c268u;
    // NOP
    // 0x11c26c: 0x14e2fff4  bne         $a3, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x11C26Cu;
    {
        const bool branch_taken_0x11c26c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        if (branch_taken_0x11c26c) {
            ctx->pc = 0x11C240u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11c240;
        }
    }
    ctx->pc = 0x11C274u;
label_11c274:
    // 0x11c274: 0x68e90007  ldl         $t1, 0x7($a3)
    ctx->pc = 0x11c274u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x11c278: 0x6ce90000  ldr         $t1, 0x0($a3)
    ctx->pc = 0x11c278u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x11c27c: 0x68ea000f  ldl         $t2, 0xF($a3)
    ctx->pc = 0x11c27cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem << shift)); }
    // 0x11c280: 0x6cea0008  ldr         $t2, 0x8($a3)
    ctx->pc = 0x11c280u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem >> shift)); }
    // 0x11c284: 0x68e60017  ldl         $a2, 0x17($a3)
    ctx->pc = 0x11c284u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x11c288: 0x6ce60010  ldr         $a2, 0x10($a3)
    ctx->pc = 0x11c288u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x11c28c: 0x88e8001b  lwl         $t0, 0x1B($a3)
    ctx->pc = 0x11c28cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 8) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 8, (int32_t)merged); }
    // 0x11c290: 0x98e80018  lwr         $t0, 0x18($a3)
    ctx->pc = 0x11c290u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 8) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 8) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 8, merged64); }
    // 0x11c294: 0xb0890007  sdl         $t1, 0x7($a0)
    ctx->pc = 0x11c294u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c298: 0xb4890000  sdr         $t1, 0x0($a0)
    ctx->pc = 0x11c298u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c29c: 0xb08a000f  sdl         $t2, 0xF($a0)
    ctx->pc = 0x11c29cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c2a0: 0xb48a0008  sdr         $t2, 0x8($a0)
    ctx->pc = 0x11c2a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c2a4: 0xb0860017  sdl         $a2, 0x17($a0)
    ctx->pc = 0x11c2a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c2a8: 0xb4860010  sdr         $a2, 0x10($a0)
    ctx->pc = 0x11c2a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x11c2ac: 0xa888001b  swl         $t0, 0x1B($a0)
    ctx->pc = 0x11c2acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 27); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11c2b0: 0x26a3e400  addiu       $v1, $s5, -0x1C00
    ctx->pc = 0x11c2b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), 4294960128));
    // 0x11c2b4: 0x240200fc  addiu       $v0, $zero, 0xFC
    ctx->pc = 0x11c2b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 252));
    // 0x11c2b8: 0xb8880018  swr         $t0, 0x18($a0)
    ctx->pc = 0x11c2b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 8); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x11c2bc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x11C2BCu;
    {
        const bool branch_taken_0x11c2bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C2C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C2BCu;
            // 0x11c2c0: 0xac620004  sw          $v0, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c2bc) {
            ctx->pc = 0x11C2E0u;
            goto label_11c2e0;
        }
    }
    ctx->pc = 0x11C2C4u;
label_11c2c4:
    // 0x11c2c4: 0x26440104  addiu       $a0, $s2, 0x104
    ctx->pc = 0x11c2c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 260));
    // 0x11c2c8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x11C2C8u;
    SET_GPR_U32(ctx, 31, 0x11C2D0u);
    ctx->pc = 0x11C2CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C2C8u;
            // 0x11c2cc: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C2D0u; }
        if (ctx->pc != 0x11C2D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C2D0u; }
        if (ctx->pc != 0x11C2D0u) { return; }
    }
    ctx->pc = 0x11C2D0u;
label_11c2d0:
    // 0x11c2d0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x11C2D0u;
    {
        const bool branch_taken_0x11c2d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C2D0u;
            // 0x11c2d4: 0xae510004  sw          $s1, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c2d0) {
            ctx->pc = 0x11C2DCu;
            goto label_11c2dc;
        }
    }
    ctx->pc = 0x11C2D8u;
label_11c2d8:
    // 0x11c2d8: 0xae400004  sw          $zero, 0x4($s2)
    ctx->pc = 0x11c2d8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 0));
label_11c2dc:
    // 0x11c2dc: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x11c2dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
label_11c2e0:
    // 0x11c2e0: 0x26b0e400  addiu       $s0, $s5, -0x1C00
    ctx->pc = 0x11c2e0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 21), 4294960128));
    // 0x11c2e4: 0x24a4e600  addiu       $a0, $a1, -0x1A00
    ctx->pc = 0x11c2e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 4294960640));
    // 0x11c2e8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x11c2e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x11c2ec: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x11c2ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x11c2f0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x11c2f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c2f4: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x11c2f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c2f8: 0x24080200  addiu       $t0, $zero, 0x200
    ctx->pc = 0x11c2f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x11c2fc: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x11c2fcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11c300: 0x240a0008  addiu       $t2, $zero, 0x8
    ctx->pc = 0x11c300u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x11c304: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x11C304u;
    SET_GPR_U32(ctx, 31, 0x11C30Cu);
    ctx->pc = 0x11C308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11C304u;
            // 0x11c308: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C30Cu; }
        if (ctx->pc != 0x11C30Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11C30Cu; }
        if (ctx->pc != 0x11C30Cu) { return; }
    }
    ctx->pc = 0x11C30Cu;
label_11c30c:
    // 0x11c30c: 0x4430004  bgezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11C30Cu;
    {
        const bool branch_taken_0x11c30c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x11c30c) {
            ctx->pc = 0x11C310u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11C30Cu;
            // 0x11c310: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11C320u;
            goto label_11c320;
        }
    }
    ctx->pc = 0x11C314u;
    // 0x11c314: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x11c314u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x11c318: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11C318u;
    {
        const bool branch_taken_0x11c318 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11C31Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C318u;
            // 0x11c31c: 0x3442ffff  ori         $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11c318) {
            ctx->pc = 0x11C328u;
            goto label_11c328;
        }
    }
    ctx->pc = 0x11C320u;
label_11c320:
    // 0x11c320: 0x8e82e400  lw          $v0, -0x1C00($s4)
    ctx->pc = 0x11c320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294960128)));
    // 0x11c324: 0xaec30000  sw          $v1, 0x0($s6)
    ctx->pc = 0x11c324u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 3));
label_11c328:
    // 0x11c328: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x11c328u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11c32c: 0xdfb60070  ld          $s6, 0x70($sp)
    ctx->pc = 0x11c32cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11c330: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x11c330u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x11c334: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x11c334u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x11c338: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x11c338u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11c33c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x11c33cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11c340: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x11c340u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11c344: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11c344u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11c348: 0x3e00008  jr          $ra
    ctx->pc = 0x11C348u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11C34Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11C348u;
            // 0x11c34c: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11C180u: goto label_11c180;
            case 0x11C190u: goto label_11c190;
            case 0x11C1A4u: goto label_11c1a4;
            case 0x11C1DCu: goto label_11c1dc;
            case 0x11C238u: goto label_11c238;
            case 0x11C240u: goto label_11c240;
            case 0x11C274u: goto label_11c274;
            case 0x11C2C4u: goto label_11c2c4;
            case 0x11C2D0u: goto label_11c2d0;
            case 0x11C2D8u: goto label_11c2d8;
            case 0x11C2DCu: goto label_11c2dc;
            case 0x11C2E0u: goto label_11c2e0;
            case 0x11C30Cu: goto label_11c30c;
            case 0x11C320u: goto label_11c320;
            case 0x11C328u: goto label_11c328;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11C350u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
