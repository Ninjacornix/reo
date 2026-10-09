#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020B0C8
// Address: 0x20b0c8 - 0x20b2a8
void sub_0020B0C8_0x20b0c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020B0C8_0x20b0c8");
#endif

    switch (ctx->pc) {
        case 0x20b100u: goto label_20b100;
        case 0x20b134u: goto label_20b134;
        case 0x20b150u: goto label_20b150;
        case 0x20b1b0u: goto label_20b1b0;
        case 0x20b23cu: goto label_20b23c;
        case 0x20b260u: goto label_20b260;
        default: break;
    }

    ctx->pc = 0x20b0c8u;

    // 0x20b0c8: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x20b0c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x20b0cc: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x20b0ccu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20b0d0: 0xffbf00a0  sd          $ra, 0xA0($sp)
    ctx->pc = 0x20b0d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x20b0d4: 0xffb70090  sd          $s7, 0x90($sp)
    ctx->pc = 0x20b0d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 23));
    // 0x20b0d8: 0xffb60080  sd          $s6, 0x80($sp)
    ctx->pc = 0x20b0d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x20b0dc: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x20b0dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x20b0e0: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x20b0e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x20b0e4: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x20b0e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x20b0e8: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x20b0e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x20b0ec: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x20b0ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x20b0f0: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x20b0f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x20b0f4: 0x3c118007  lui         $s1, 0x8007
    ctx->pc = 0x20b0f4u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32775 << 16));
    // 0x20b0f8: 0x3c128007  lui         $s2, 0x8007
    ctx->pc = 0x20b0f8u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)32775 << 16));
    // 0x20b0fc: 0x0  nop
    ctx->pc = 0x20b0fcu;
    // NOP
label_20b100:
    // 0x20b100: 0x8e226700  lw          $v0, 0x6700($s1)
    ctx->pc = 0x20b100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 26368)));
    // 0x20b104: 0x102102a  slt         $v0, $t0, $v0
    ctx->pc = 0x20b104u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x20b108: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x20B108u;
    {
        const bool branch_taken_0x20b108 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x20B10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B108u;
            // 0x20b10c: 0x24030014  addiu       $v1, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b108) {
            ctx->pc = 0x20B134u;
            goto label_20b134;
        }
    }
    ctx->pc = 0x20B110u;
    // 0x20b110: 0x26446740  addiu       $a0, $s2, 0x6740
    ctx->pc = 0x20b110u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 26432));
    // 0x20b114: 0x1031818  mult        $v1, $t0, $v1
    ctx->pc = 0x20b114u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x20b118: 0x96456740  lhu         $a1, 0x6740($s2)
    ctx->pc = 0x20b118u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26432)));
    // 0x20b11c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x20b11cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x20b120: 0x94620000  lhu         $v0, 0x0($v1)
    ctx->pc = 0x20b120u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x20b124: 0x10a2fff6  beq         $a1, $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x20B124u;
    {
        const bool branch_taken_0x20b124 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x20B128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B124u;
            // 0x20b128: 0x25080001  addiu       $t0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b124) {
            ctx->pc = 0x20B100u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20b100;
        }
    }
    ctx->pc = 0x20B12Cu;
    // 0x20b12c: 0xc01d918  jal         func_076460
    ctx->pc = 0x20B12Cu;
    SET_GPR_U32(ctx, 31, 0x20B134u);
    ctx->pc = 0x20B130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20B12Cu;
            // 0x20b130: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x76460u;
    {
        auto targetFn = runtime->lookupFunction(0x76460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20B134u; }
        if (ctx->pc != 0x20B134u) { return; }
    }
    ctx->pc = 0x20B134u;
label_20b134:
    // 0x20b134: 0x3c028007  lui         $v0, 0x8007
    ctx->pc = 0x20b134u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32775 << 16));
    // 0x20b138: 0x220b02d  daddu       $s6, $s1, $zero
    ctx->pc = 0x20b138u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20b13c: 0x24546740  addiu       $s4, $v0, 0x6740
    ctx->pc = 0x20b13cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 26432));
    // 0x20b140: 0x24130014  addiu       $s3, $zero, 0x14
    ctx->pc = 0x20b140u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x20b144: 0x3c158007  lui         $s5, 0x8007
    ctx->pc = 0x20b144u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)32775 << 16));
    // 0x20b148: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x20B148u;
    {
        const bool branch_taken_0x20b148 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20B14Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B148u;
            // 0x20b14c: 0x24170001  addiu       $s7, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b148) {
            ctx->pc = 0x20B15Cu;
            goto label_20b15c;
        }
    }
    ctx->pc = 0x20B150u;
label_20b150:
    // 0x20b150: 0x96426740  lhu         $v0, 0x6740($s2)
    ctx->pc = 0x20b150u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26432)));
    // 0x20b154: 0x1462003e  bne         $v1, $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x20B154u;
    {
        const bool branch_taken_0x20b154 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x20B158u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B154u;
            // 0x20b158: 0x8e226700  lw          $v0, 0x6700($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 26368)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b154) {
            ctx->pc = 0x20B250u;
            goto label_20b250;
        }
    }
    ctx->pc = 0x20B15Cu;
label_20b15c:
    // 0x20b15c: 0x8ec26700  lw          $v0, 0x6700($s6)
    ctx->pc = 0x20b15cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 26368)));
    // 0x20b160: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x20b160u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20b164: 0x26466740  addiu       $a2, $s2, 0x6740
    ctx->pc = 0x20b164u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 26432));
    // 0x20b168: 0x68c30007  ldl         $v1, 0x7($a2)
    ctx->pc = 0x20b168u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x20b16c: 0x6cc30000  ldr         $v1, 0x0($a2)
    ctx->pc = 0x20b16cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x20b170: 0x68c4000f  ldl         $a0, 0xF($a2)
    ctx->pc = 0x20b170u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x20b174: 0x6cc40008  ldr         $a0, 0x8($a2)
    ctx->pc = 0x20b174u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x20b178: 0x8cc50010  lw          $a1, 0x10($a2)
    ctx->pc = 0x20b178u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x20b17c: 0xb3a30007  sdl         $v1, 0x7($sp)
    ctx->pc = 0x20b17cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20b180: 0xb7a30000  sdr         $v1, 0x0($sp)
    ctx->pc = 0x20b180u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20b184: 0xb3a4000f  sdl         $a0, 0xF($sp)
    ctx->pc = 0x20b184u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20b188: 0xb7a40008  sdr         $a0, 0x8($sp)
    ctx->pc = 0x20b188u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20b18c: 0xafa50010  sw          $a1, 0x10($sp)
    ctx->pc = 0x20b18cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x20b190: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x20b190u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x20b194: 0x1840001a  blez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x20B194u;
    {
        const bool branch_taken_0x20b194 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x20B198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B194u;
            // 0x20b198: 0xaec26700  sw          $v0, 0x6700($s6) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 22), 26368), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b194) {
            ctx->pc = 0x20B200u;
            goto label_20b200;
        }
    }
    ctx->pc = 0x20B19Cu;
    // 0x20b19c: 0x8e296700  lw          $t1, 0x6700($s1)
    ctx->pc = 0x20b19cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 26368)));
    // 0x20b1a0: 0x8faa0010  lw          $t2, 0x10($sp)
    ctx->pc = 0x20b1a0u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20b1a4: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x20b1a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x20b1a8: 0x97a70000  lhu         $a3, 0x0($sp)
    ctx->pc = 0x20b1a8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x20b1ac: 0x0  nop
    ctx->pc = 0x20b1acu;
    // NOP
label_20b1b0:
    // 0x20b1b0: 0x1131818  mult        $v1, $t0, $s3
    ctx->pc = 0x20b1b0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 19); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x20b1b4: 0x25020001  addiu       $v0, $t0, 0x1
    ctx->pc = 0x20b1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x20b1b8: 0x40402d  daddu       $t0, $v0, $zero
    ctx->pc = 0x20b1b8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20b1bc: 0x742821  addu        $a1, $v1, $s4
    ctx->pc = 0x20b1bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x20b1c0: 0x531818  mult        $v1, $v0, $s3
    ctx->pc = 0x20b1c0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 19); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x20b1c4: 0x742021  addu        $a0, $v1, $s4
    ctx->pc = 0x20b1c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x20b1c8: 0x688b0007  ldl         $t3, 0x7($a0)
    ctx->pc = 0x20b1c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 11, (GPR_U64(ctx, 11) & keepMask) | (mem << shift)); }
    // 0x20b1cc: 0x6c8b0000  ldr         $t3, 0x0($a0)
    ctx->pc = 0x20b1ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 11, (GPR_U64(ctx, 11) & keepMask) | (mem >> shift)); }
    // 0x20b1d0: 0x688c000f  ldl         $t4, 0xF($a0)
    ctx->pc = 0x20b1d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 12, (GPR_U64(ctx, 12) & keepMask) | (mem << shift)); }
    // 0x20b1d4: 0x6c8c0008  ldr         $t4, 0x8($a0)
    ctx->pc = 0x20b1d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 12, (GPR_U64(ctx, 12) & keepMask) | (mem >> shift)); }
    // 0x20b1d8: 0x8c8d0010  lw          $t5, 0x10($a0)
    ctx->pc = 0x20b1d8u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x20b1dc: 0xb0ab0007  sdl         $t3, 0x7($a1)
    ctx->pc = 0x20b1dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 11); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20b1e0: 0xb4ab0000  sdr         $t3, 0x0($a1)
    ctx->pc = 0x20b1e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 11); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20b1e4: 0xb0ac000f  sdl         $t4, 0xF($a1)
    ctx->pc = 0x20b1e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 12); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20b1e8: 0xb4ac0008  sdr         $t4, 0x8($a1)
    ctx->pc = 0x20b1e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 12); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x20b1ec: 0x109182a  slt         $v1, $t0, $t1
    ctx->pc = 0x20b1ecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x20b1f0: 0x1460ffef  bnez        $v1, . + 4 + (-0x11 << 2)
    ctx->pc = 0x20B1F0u;
    {
        const bool branch_taken_0x20b1f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x20B1F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B1F0u;
            // 0x20b1f4: 0xacad0010  sw          $t5, 0x10($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b1f0) {
            ctx->pc = 0x20B1B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20b1b0;
        }
    }
    ctx->pc = 0x20B1F8u;
    // 0x20b1f8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x20B1F8u;
    {
        const bool branch_taken_0x20b1f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x20b1f8) {
            ctx->pc = 0x20B20Cu;
            goto label_20b20c;
        }
    }
    ctx->pc = 0x20B200u;
label_20b200:
    // 0x20b200: 0x8faa0010  lw          $t2, 0x10($sp)
    ctx->pc = 0x20b200u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x20b204: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x20b204u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x20b208: 0x97a70000  lhu         $a3, 0x0($sp)
    ctx->pc = 0x20b208u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
label_20b20c:
    // 0x20b20c: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x20b20cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20b210: 0x140e02d  daddu       $gp, $t2, $zero
    ctx->pc = 0x20b210u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20b214: 0xdea36708  ld          $v1, 0x6708($s5)
    ctx->pc = 0x20b214u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 21), 26376)));
    // 0x20b218: 0xd71014  dsllv       $v0, $s7, $a2
    ctx->pc = 0x20b218u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) << (GPR_U32(ctx, 6) & 0x3F));
    // 0x20b21c: 0x21027  nor         $v0, $zero, $v0
    ctx->pc = 0x20b21cu;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x20b220: 0x3c040008  lui         $a0, 0x8
    ctx->pc = 0x20b220u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8 << 16));
    // 0x20b224: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x20b224u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x20b228: 0x8fa50008  lw          $a1, 0x8($sp)
    ctx->pc = 0x20b228u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x20b22c: 0x8fa8000c  lw          $t0, 0xC($sp)
    ctx->pc = 0x20b22cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x20b230: 0x34842000  ori         $a0, $a0, 0x2000
    ctx->pc = 0x20b230u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8192);
    // 0x20b234: 0xc01d9a0  jal         func_076680
    ctx->pc = 0x20B234u;
    SET_GPR_U32(ctx, 31, 0x20B23Cu);
    ctx->pc = 0x20B238u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20B234u;
            // 0x20b238: 0xfea36708  sd          $v1, 0x6708($s5) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 21), 26376), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x76680u;
    {
        auto targetFn = runtime->lookupFunction(0x76680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20B23Cu; }
        if (ctx->pc != 0x20B23Cu) { return; }
    }
    ctx->pc = 0x20B23Cu;
label_20b23c:
    // 0x20b23c: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x20b23cu;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20b240: 0x8e226700  lw          $v0, 0x6700($s1)
    ctx->pc = 0x20b240u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 26368)));
    // 0x20b244: 0x1c40ffc2  bgtz        $v0, . + 4 + (-0x3E << 2)
    ctx->pc = 0x20B244u;
    {
        const bool branch_taken_0x20b244 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x20B248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B244u;
            // 0x20b248: 0x97a30000  lhu         $v1, 0x0($sp) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b244) {
            ctx->pc = 0x20B150u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20b150;
        }
    }
    ctx->pc = 0x20B24Cu;
    // 0x20b24c: 0x8e226700  lw          $v0, 0x6700($s1)
    ctx->pc = 0x20b24cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 26368)));
label_20b250:
    // 0x20b250: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x20B250u;
    {
        const bool branch_taken_0x20b250 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x20B254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B250u;
            // 0x20b254: 0x24030483  addiu       $v1, $zero, 0x483 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1155));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20b250) {
            ctx->pc = 0x20B268u;
            goto label_20b268;
        }
    }
    ctx->pc = 0x20B258u;
    // 0x20b258: 0xc01d918  jal         func_076460
    ctx->pc = 0x20B258u;
    SET_GPR_U32(ctx, 31, 0x20B260u);
    ctx->pc = 0x20B25Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x20B258u;
            // 0x20b25c: 0x96446740  lhu         $a0, 0x6740($s2) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26432)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x76460u;
    {
        auto targetFn = runtime->lookupFunction(0x76460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x20B260u; }
        if (ctx->pc != 0x20B260u) { return; }
    }
    ctx->pc = 0x20B260u;
label_20b260:
    // 0x20b260: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x20B260u;
    {
        const bool branch_taken_0x20b260 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x20b260) {
            ctx->pc = 0x20B274u;
            goto label_20b274;
        }
    }
    ctx->pc = 0x20B268u;
label_20b268:
    // 0x20b268: 0x3c02b000  lui         $v0, 0xB000
    ctx->pc = 0x20b268u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)45056 << 16));
    // 0x20b26c: 0x34421810  ori         $v0, $v0, 0x1810
    ctx->pc = 0x20b26cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6160);
    // 0x20b270: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x20b270u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_20b274:
    // 0x20b274: 0xf  sync
    ctx->pc = 0x20b274u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20b278: 0x42000038  ei
    ctx->pc = 0x20b278u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x20b27c: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x20b27cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x20b280: 0xdfb70090  ld          $s7, 0x90($sp)
    ctx->pc = 0x20b280u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x20b284: 0xdfb60080  ld          $s6, 0x80($sp)
    ctx->pc = 0x20b284u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x20b288: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x20b288u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x20b28c: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x20b28cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x20b290: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x20b290u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x20b294: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x20b294u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x20b298: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x20b298u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x20b29c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x20b29cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x20b2a0: 0x3e00008  jr          $ra
    ctx->pc = 0x20B2A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20B2A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B2A0u;
            // 0x20b2a4: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20B100u: goto label_20b100;
            case 0x20B134u: goto label_20b134;
            case 0x20B150u: goto label_20b150;
            case 0x20B15Cu: goto label_20b15c;
            case 0x20B1B0u: goto label_20b1b0;
            case 0x20B200u: goto label_20b200;
            case 0x20B20Cu: goto label_20b20c;
            case 0x20B23Cu: goto label_20b23c;
            case 0x20B250u: goto label_20b250;
            case 0x20B260u: goto label_20b260;
            case 0x20B268u: goto label_20b268;
            case 0x20B274u: goto label_20b274;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20B2A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
