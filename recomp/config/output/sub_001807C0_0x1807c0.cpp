#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001807C0
// Address: 0x1807c0 - 0x1808a0
void sub_001807C0_0x1807c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001807C0_0x1807c0");
#endif

    ctx->pc = 0x1807c0u;

    // 0x1807c0: 0x24030334  addiu       $v1, $zero, 0x334
    ctx->pc = 0x1807c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 820));
    // 0x1807c4: 0x63100  sll         $a2, $a2, 4
    ctx->pc = 0x1807c4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x1807c8: 0x832018  mult        $a0, $a0, $v1
    ctx->pc = 0x1807c8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1807cc: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x1807ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x1807d0: 0x24426188  addiu       $v0, $v0, 0x6188
    ctx->pc = 0x1807d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24968));
    // 0x1807d4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1807d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1807d8: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1807d8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1807dc: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x1807dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1807e0: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x1807e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1807e4: 0x68c2001b  ldl         $v0, 0x1B($a2)
    ctx->pc = 0x1807e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1807e8: 0x6cc20014  ldr         $v0, 0x14($a2)
    ctx->pc = 0x1807e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1807ec: 0x68c30023  ldl         $v1, 0x23($a2)
    ctx->pc = 0x1807ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 35); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1807f0: 0x6cc3001c  ldr         $v1, 0x1C($a2)
    ctx->pc = 0x1807f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 28); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1807f4: 0xb3a20007  sdl         $v0, 0x7($sp)
    ctx->pc = 0x1807f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1807f8: 0xb7a20000  sdr         $v0, 0x0($sp)
    ctx->pc = 0x1807f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1807fc: 0xb3a3000f  sdl         $v1, 0xF($sp)
    ctx->pc = 0x1807fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x180800: 0xb7a30008  sdr         $v1, 0x8($sp)
    ctx->pc = 0x180800u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x180804: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x180804u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x180808: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x180808u;
    {
        const bool branch_taken_0x180808 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18080Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180808u;
            // 0x18080c: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180808) {
            ctx->pc = 0x180894u;
            goto label_180894;
        }
    }
    ctx->pc = 0x180810u;
    // 0x180810: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x180810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x180814: 0x10e20006  beq         $a3, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x180814u;
    {
        const bool branch_taken_0x180814 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x180818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180814u;
            // 0x180818: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180814) {
            ctx->pc = 0x180830u;
            goto label_180830;
        }
    }
    ctx->pc = 0x18081Cu;
    // 0x18081c: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x18081cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x180820: 0x10e2000b  beq         $a3, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x180820u;
    {
        const bool branch_taken_0x180820 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x180824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180820u;
            // 0x180824: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180820) {
            ctx->pc = 0x180850u;
            goto label_180850;
        }
    }
    ctx->pc = 0x180828u;
    // 0x180828: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x180828u;
    {
        const bool branch_taken_0x180828 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x180828) {
            ctx->pc = 0x180898u;
            goto label_180898;
        }
    }
    ctx->pc = 0x180830u;
label_180830:
    // 0x180830: 0x8fa4000c  lw          $a0, 0xC($sp)
    ctx->pc = 0x180830u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x180834: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x180834u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x180838: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x180838u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18083c: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x18083cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180840: 0x831807  srav        $v1, $v1, $a0
    ctx->pc = 0x180840u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 4) & 0x1F));
    // 0x180844: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x180844u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x180848: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x180848u;
    {
        const bool branch_taken_0x180848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18084Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180848u;
            // 0x18084c: 0x3100b  movn        $v0, $zero, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180848) {
            ctx->pc = 0x180898u;
            goto label_180898;
        }
    }
    ctx->pc = 0x180850u;
label_180850:
    // 0x180850: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x180850u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x180854: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x180854u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x180858: 0x1041821  addu        $v1, $t0, $a0
    ctx->pc = 0x180858u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 4)));
    // 0x18085c: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x18085cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x180860: 0xa21007  srav        $v0, $v0, $a1
    ctx->pc = 0x180860u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x180864: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x180864u;
    {
        const bool branch_taken_0x180864 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x180868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180864u;
            // 0x180868: 0x304600ff  andi        $a2, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x180864) {
            ctx->pc = 0x18088Cu;
            goto label_18088c;
        }
    }
    ctx->pc = 0x18086Cu;
    // 0x18086c: 0x24830001  addiu       $v1, $a0, 0x1
    ctx->pc = 0x18086cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x180870: 0xe52823  subu        $a1, $a3, $a1
    ctx->pc = 0x180870u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x180874: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x180874u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x180878: 0x1032021  addu        $a0, $t0, $v1
    ctx->pc = 0x180878u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x18087c: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x18087cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x180880: 0xa21004  sllv        $v0, $v0, $a1
    ctx->pc = 0x180880u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x180884: 0xc21025  or          $v0, $a2, $v0
    ctx->pc = 0x180884u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x180888: 0x304600ff  andi        $a2, $v0, 0xFF
    ctx->pc = 0x180888u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
label_18088c:
    // 0x18088c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18088Cu;
    {
        const bool branch_taken_0x18088c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x180890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18088Cu;
            // 0x180890: 0xc0102d  daddu       $v0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18088c) {
            ctx->pc = 0x180898u;
            goto label_180898;
        }
    }
    ctx->pc = 0x180894u;
label_180894:
    // 0x180894: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x180894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_180898:
    // 0x180898: 0x3e00008  jr          $ra
    ctx->pc = 0x180898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18089Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180898u;
            // 0x18089c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180830u: goto label_180830;
            case 0x180850u: goto label_180850;
            case 0x18088Cu: goto label_18088c;
            case 0x180894u: goto label_180894;
            case 0x180898u: goto label_180898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1808A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
