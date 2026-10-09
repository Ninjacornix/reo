#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E360
// Address: 0x16e360 - 0x16e478
void sub_0016E360_0x16e360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E360_0x16e360");
#endif

    switch (ctx->pc) {
        case 0x16e388u: goto label_16e388;
        case 0x16e3c8u: goto label_16e3c8;
        default: break;
    }

    ctx->pc = 0x16e360u;

    // 0x16e360: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16e360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16e364: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16e364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16e368: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16e368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16e36c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16e36cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e370: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16e370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16e374: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16e374u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e378: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16e378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16e37c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16e37cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16e380: 0xc05c0d6  jal         func_170358
    ctx->pc = 0x16E380u;
    SET_GPR_U32(ctx, 31, 0x16E388u);
    ctx->pc = 0x16E384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E380u;
            // 0x16e384: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170358u;
    if (runtime->hasFunction(0x170358u)) {
        auto targetFn = runtime->lookupFunction(0x170358u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E388u; }
        if (ctx->pc != 0x16E388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170358_0x170358(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E388u; }
        if (ctx->pc != 0x16E388u) { return; }
    }
    ctx->pc = 0x16E388u;
label_16e388:
    // 0x16e388: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16e388u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e38c: 0x52000033  beql        $s0, $zero, . + 4 + (0x33 << 2)
    ctx->pc = 0x16E38Cu;
    {
        const bool branch_taken_0x16e38c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x16e38c) {
            ctx->pc = 0x16E390u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E38Cu;
            // 0x16e390: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E45Cu;
            goto label_16e45c;
        }
    }
    ctx->pc = 0x16E394u;
    // 0x16e394: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x16e394u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16e398: 0x54400030  bnel        $v0, $zero, . + 4 + (0x30 << 2)
    ctx->pc = 0x16E398u;
    {
        const bool branch_taken_0x16e398 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16e398) {
            ctx->pc = 0x16E39Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E398u;
            // 0x16e39c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E45Cu;
            goto label_16e45c;
        }
    }
    ctx->pc = 0x16E3A0u;
    // 0x16e3a0: 0x8e460004  lw          $a2, 0x4($s2)
    ctx->pc = 0x16e3a0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x16e3a4: 0x24070200  addiu       $a3, $zero, 0x200
    ctx->pc = 0x16e3a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x16e3a8: 0x26030034  addiu       $v1, $s0, 0x34
    ctx->pc = 0x16e3a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 52));
    // 0x16e3ac: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x16e3acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x16e3b0: 0x28c20201  slti        $v0, $a2, 0x201
    ctx->pc = 0x16e3b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)513) ? 1 : 0);
    // 0x16e3b4: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x16e3b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e3b8: 0xe2300a  movz        $a2, $a3, $v0
    ctx->pc = 0x16e3b8u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 7));
    // 0x16e3bc: 0x26720cc0  addiu       $s2, $s3, 0xCC0
    ctx->pc = 0x16e3bcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), 3264));
    // 0x16e3c0: 0xc055798  jal         func_155E60
    ctx->pc = 0x16E3C0u;
    SET_GPR_U32(ctx, 31, 0x16E3C8u);
    ctx->pc = 0x16E3C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E3C0u;
            // 0x16e3c4: 0xac660200  sw          $a2, 0x200($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 512), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E3C8u; }
        if (ctx->pc != 0x16E3C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E3C8u; }
        if (ctx->pc != 0x16E3C8u) { return; }
    }
    ctx->pc = 0x16E3C8u;
label_16e3c8:
    // 0x16e3c8: 0x111840  sll         $v1, $s1, 1
    ctx->pc = 0x16e3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x16e3cc: 0x3c020003  lui         $v0, 0x3
    ctx->pc = 0x16e3ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3 << 16));
    // 0x16e3d0: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x16e3d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x16e3d4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x16e3d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x16e3d8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x16e3d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x16e3dc: 0x16220004  bne         $s1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16E3DCu;
    {
        const bool branch_taken_0x16e3dc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x16E3E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E3DCu;
            // 0x16e3e0: 0x711821  addu        $v1, $v1, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e3dc) {
            ctx->pc = 0x16E3F0u;
            goto label_16e3f0;
        }
    }
    ctx->pc = 0x16E3E4u;
    // 0x16e3e4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x16e3e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x16e3e8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16E3E8u;
    {
        const bool branch_taken_0x16e3e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E3ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E3E8u;
            // 0x16e3ec: 0xae000008  sw          $zero, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e3e8) {
            ctx->pc = 0x16E400u;
            goto label_16e400;
        }
    }
    ctx->pc = 0x16E3F0u;
label_16e3f0:
    // 0x16e3f0: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x16e3f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x16e3f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16e3f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16e3f8: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x16e3f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x16e3fc: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x16e3fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
label_16e400:
    // 0x16e400: 0x6a420023  ldl         $v0, 0x23($s2)
    ctx->pc = 0x16e400u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 35); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16e404: 0x6e42001c  ldr         $v0, 0x1C($s2)
    ctx->pc = 0x16e404u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 28); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16e408: 0x6a43002b  ldl         $v1, 0x2B($s2)
    ctx->pc = 0x16e408u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 43); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16e40c: 0x6e430024  ldr         $v1, 0x24($s2)
    ctx->pc = 0x16e40cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 36); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16e410: 0x6a440033  ldl         $a0, 0x33($s2)
    ctx->pc = 0x16e410u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 51); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16e414: 0x6e44002c  ldr         $a0, 0x2C($s2)
    ctx->pc = 0x16e414u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 44); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16e418: 0x6a45003b  ldl         $a1, 0x3B($s2)
    ctx->pc = 0x16e418u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 59); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x16e41c: 0x6e450034  ldr         $a1, 0x34($s2)
    ctx->pc = 0x16e41cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 52); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x16e420: 0xb2020013  sdl         $v0, 0x13($s0)
    ctx->pc = 0x16e420u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 19); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e424: 0xb602000c  sdr         $v0, 0xC($s0)
    ctx->pc = 0x16e424u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 12); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e428: 0xb203001b  sdl         $v1, 0x1B($s0)
    ctx->pc = 0x16e428u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e42c: 0xb6030014  sdr         $v1, 0x14($s0)
    ctx->pc = 0x16e42cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e430: 0xb2040023  sdl         $a0, 0x23($s0)
    ctx->pc = 0x16e430u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 35); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e434: 0xb604001c  sdr         $a0, 0x1C($s0)
    ctx->pc = 0x16e434u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 28); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e438: 0xb205002b  sdl         $a1, 0x2B($s0)
    ctx->pc = 0x16e438u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 43); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e43c: 0xb6050024  sdr         $a1, 0x24($s0)
    ctx->pc = 0x16e43cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 36); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e440: 0x6a420043  ldl         $v0, 0x43($s2)
    ctx->pc = 0x16e440u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 67); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16e444: 0x6e42003c  ldr         $v0, 0x3C($s2)
    ctx->pc = 0x16e444u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 18), 60); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16e448: 0xb2020033  sdl         $v0, 0x33($s0)
    ctx->pc = 0x16e448u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 51); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e44c: 0xb602002c  sdr         $v0, 0x2C($s0)
    ctx->pc = 0x16e44cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 44); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16e450: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16e450u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16e454: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x16e454u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x16e458: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16e458u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16e45c:
    // 0x16e45c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16e45cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16e460: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16e460u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16e464: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16e464u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16e468: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16e468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16e46c: 0x3e00008  jr          $ra
    ctx->pc = 0x16E46Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E46Cu;
            // 0x16e470: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E388u: goto label_16e388;
            case 0x16E3C8u: goto label_16e3c8;
            case 0x16E3F0u: goto label_16e3f0;
            case 0x16E400u: goto label_16e400;
            case 0x16E45Cu: goto label_16e45c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E474u;
    // 0x16e474: 0x0  nop
    ctx->pc = 0x16e474u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
