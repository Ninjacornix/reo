#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001507B8
// Address: 0x1507b8 - 0x1508e0
void sub_001507B8_0x1507b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001507B8_0x1507b8");
#endif

    switch (ctx->pc) {
        case 0x1507d4u: goto label_1507d4;
        case 0x150810u: goto label_150810;
        case 0x150870u: goto label_150870;
        default: break;
    }

    ctx->pc = 0x1507b8u;

    // 0x1507b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1507b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1507bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1507bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1507c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1507c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1507c4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1507c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1507c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1507c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1507cc: 0xc05578e  jal         func_155E38
    ctx->pc = 0x1507CCu;
    SET_GPR_U32(ctx, 31, 0x1507D4u);
    ctx->pc = 0x1507D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1507CCu;
            // 0x1507d0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1507D4u; }
        if (ctx->pc != 0x1507D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1507D4u; }
        if (ctx->pc != 0x1507D4u) { return; }
    }
    ctx->pc = 0x1507D4u;
label_1507d4:
    // 0x1507d4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1507D4u;
    {
        const bool branch_taken_0x1507d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1507D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1507D4u;
            // 0x1507d8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1507d4) {
            ctx->pc = 0x1507F8u;
            goto label_1507f8;
        }
    }
    ctx->pc = 0x1507DCu;
    // 0x1507dc: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1507dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x1507e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1507e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1507e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1507e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1507e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1507e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1507ec: 0x34a5020c  ori         $a1, $a1, 0x20C
    ctx->pc = 0x1507ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)524);
    // 0x1507f0: 0x805419c  j           func_150670
    ctx->pc = 0x1507F0u;
    ctx->pc = 0x1507F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1507F0u;
            // 0x1507f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1507F8u;
label_1507f8:
    // 0x1507f8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1507f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1507fc: 0x26030058  addiu       $v1, $s0, 0x58
    ctx->pc = 0x1507fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 88));
    // 0x150800: 0x651025  or          $v0, $v1, $a1
    ctx->pc = 0x150800u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x150804: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x150804u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x150808: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x150808u;
    {
        const bool branch_taken_0x150808 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15080Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150808u;
            // 0x15080c: 0x26040098  addiu       $a0, $s0, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 152));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150808) {
            ctx->pc = 0x150870u;
            goto label_150870;
        }
    }
    ctx->pc = 0x150810u;
label_150810:
    // 0x150810: 0x68620007  ldl         $v0, 0x7($v1)
    ctx->pc = 0x150810u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x150814: 0x6c620000  ldr         $v0, 0x0($v1)
    ctx->pc = 0x150814u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x150818: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x150818u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x15081c: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x15081cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x150820: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x150820u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x150824: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x150824u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x150828: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x150828u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x15082c: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x15082cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x150830: 0xb0a20007  sdl         $v0, 0x7($a1)
    ctx->pc = 0x150830u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150834: 0xb4a20000  sdr         $v0, 0x0($a1)
    ctx->pc = 0x150834u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150838: 0xb0a6000f  sdl         $a2, 0xF($a1)
    ctx->pc = 0x150838u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15083c: 0xb4a60008  sdr         $a2, 0x8($a1)
    ctx->pc = 0x15083cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150840: 0xb0a70017  sdl         $a3, 0x17($a1)
    ctx->pc = 0x150840u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150844: 0xb4a70010  sdr         $a3, 0x10($a1)
    ctx->pc = 0x150844u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150848: 0xb0a8001f  sdl         $t0, 0x1F($a1)
    ctx->pc = 0x150848u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15084c: 0xb4a80018  sdr         $t0, 0x18($a1)
    ctx->pc = 0x15084cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x150850: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x150850u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x150854: 0x0  nop
    ctx->pc = 0x150854u;
    // NOP
    // 0x150858: 0x0  nop
    ctx->pc = 0x150858u;
    // NOP
    // 0x15085c: 0x1464ffec  bne         $v1, $a0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x15085Cu;
    {
        const bool branch_taken_0x15085c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x150860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15085Cu;
            // 0x150860: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15085c) {
            ctx->pc = 0x150810u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150810;
        }
    }
    ctx->pc = 0x150864u;
    // 0x150864: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x150864u;
    {
        const bool branch_taken_0x150864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x150864) {
            ctx->pc = 0x1508A4u;
            goto label_1508a4;
        }
    }
    ctx->pc = 0x15086Cu;
    // 0x15086c: 0x0  nop
    ctx->pc = 0x15086cu;
    // NOP
label_150870:
    // 0x150870: 0xdc620000  ld          $v0, 0x0($v1)
    ctx->pc = 0x150870u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x150874: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x150874u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x150878: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x150878u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x15087c: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x15087cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x150880: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x150880u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x150884: 0xfca60008  sd          $a2, 0x8($a1)
    ctx->pc = 0x150884u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 6));
    // 0x150888: 0xfca70010  sd          $a3, 0x10($a1)
    ctx->pc = 0x150888u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 7));
    // 0x15088c: 0xfca80018  sd          $t0, 0x18($a1)
    ctx->pc = 0x15088cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 8));
    // 0x150890: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x150890u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x150894: 0x0  nop
    ctx->pc = 0x150894u;
    // NOP
    // 0x150898: 0x0  nop
    ctx->pc = 0x150898u;
    // NOP
    // 0x15089c: 0x1464fff4  bne         $v1, $a0, . + 4 + (-0xC << 2)
    ctx->pc = 0x15089Cu;
    {
        const bool branch_taken_0x15089c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x1508A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15089Cu;
            // 0x1508a0: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15089c) {
            ctx->pc = 0x150870u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_150870;
        }
    }
    ctx->pc = 0x1508A4u;
label_1508a4:
    // 0x1508a4: 0x68620007  ldl         $v0, 0x7($v1)
    ctx->pc = 0x1508a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1508a8: 0x6c620000  ldr         $v0, 0x0($v1)
    ctx->pc = 0x1508a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1508ac: 0x6864000f  ldl         $a0, 0xF($v1)
    ctx->pc = 0x1508acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1508b0: 0x6c640008  ldr         $a0, 0x8($v1)
    ctx->pc = 0x1508b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1508b4: 0x8c660010  lw          $a2, 0x10($v1)
    ctx->pc = 0x1508b4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1508b8: 0xb0a20007  sdl         $v0, 0x7($a1)
    ctx->pc = 0x1508b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1508bc: 0xb4a20000  sdr         $v0, 0x0($a1)
    ctx->pc = 0x1508bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1508c0: 0xb0a4000f  sdl         $a0, 0xF($a1)
    ctx->pc = 0x1508c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1508c4: 0xb4a40008  sdr         $a0, 0x8($a1)
    ctx->pc = 0x1508c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1508c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1508c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1508cc: 0xaca60010  sw          $a2, 0x10($a1)
    ctx->pc = 0x1508ccu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 6));
    // 0x1508d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1508d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1508d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1508d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1508d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1508D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1508DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1508D8u;
            // 0x1508dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1507D4u: goto label_1507d4;
            case 0x1507F8u: goto label_1507f8;
            case 0x150810u: goto label_150810;
            case 0x150870u: goto label_150870;
            case 0x1508A4u: goto label_1508a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1508E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
