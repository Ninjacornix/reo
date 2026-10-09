#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187330
// Address: 0x187330 - 0x187478
void sub_00187330_0x187330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187330_0x187330");
#endif

    switch (ctx->pc) {
        case 0x1873c4u: goto label_1873c4;
        case 0x187420u: goto label_187420;
        default: break;
    }

    ctx->pc = 0x187330u;

    // 0x187330: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x187330u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187334: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x187334u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x187338: 0x81040  sll         $v0, $t0, 1
    ctx->pc = 0x187338u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x18733c: 0x81a40  sll         $v1, $t0, 9
    ctx->pc = 0x18733cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 9));
    // 0x187340: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x187340u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x187344: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x187344u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x187348: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x187348u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x18734c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x18734cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x187350: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x187350u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x187354: 0x248a7080  addiu       $t2, $a0, 0x7080
    ctx->pc = 0x187354u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 4), 28800));
    // 0x187358: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x187358u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18735c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x18735cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x187360: 0x34900  sll         $t1, $v1, 4
    ctx->pc = 0x187360u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x187364: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x187364u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x187368: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x187368u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x18736c: 0x8c84fa4c  lw          $a0, -0x5B4($a0)
    ctx->pc = 0x18736cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294965836)));
    // 0x187370: 0x12a1821  addu        $v1, $t1, $t2
    ctx->pc = 0x187370u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 10)));
    // 0x187374: 0x8c670000  lw          $a3, 0x0($v1)
    ctx->pc = 0x187374u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x187378: 0xc43021  addu        $a2, $a2, $a0
    ctx->pc = 0x187378u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x18737c: 0xc7102a  slt         $v0, $a2, $a3
    ctx->pc = 0x18737cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x187380: 0x54400039  bnel        $v0, $zero, . + 4 + (0x39 << 2)
    ctx->pc = 0x187380u;
    {
        const bool branch_taken_0x187380 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x187380) {
            ctx->pc = 0x187384u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187380u;
            // 0x187384: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187468u;
            goto label_187468;
        }
    }
    ctx->pc = 0x187388u;
    // 0x187388: 0x1491821  addu        $v1, $t2, $t1
    ctx->pc = 0x187388u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x18738c: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x18738cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x187390: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x187390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x187394: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x187394u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x187398: 0x50400033  beql        $v0, $zero, . + 4 + (0x33 << 2)
    ctx->pc = 0x187398u;
    {
        const bool branch_taken_0x187398 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x187398) {
            ctx->pc = 0x18739Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187398u;
            // 0x18739c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187468u;
            goto label_187468;
        }
    }
    ctx->pc = 0x1873A0u;
    // 0x1873a0: 0xc71023  subu        $v0, $a2, $a3
    ctx->pc = 0x1873a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x1873a4: 0x25440010  addiu       $a0, $t2, 0x10
    ctx->pc = 0x1873a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 10), 16));
    // 0x1873a8: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x1873a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x1873ac: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x1873acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x1873b0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1873b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1873b4: 0x451825  or          $v1, $v0, $a1
    ctx->pc = 0x1873b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x1873b8: 0x30630007  andi        $v1, $v1, 0x7
    ctx->pc = 0x1873b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x1873bc: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1873BCu;
    {
        const bool branch_taken_0x1873bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1873C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1873BCu;
            // 0x1873c0: 0x24430400  addiu       $v1, $v0, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1873bc) {
            ctx->pc = 0x187420u;
            goto label_187420;
        }
    }
    ctx->pc = 0x1873C4u;
label_1873c4:
    // 0x1873c4: 0x68440007  ldl         $a0, 0x7($v0)
    ctx->pc = 0x1873c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1873c8: 0x6c440000  ldr         $a0, 0x0($v0)
    ctx->pc = 0x1873c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1873cc: 0x6846000f  ldl         $a2, 0xF($v0)
    ctx->pc = 0x1873ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1873d0: 0x6c460008  ldr         $a2, 0x8($v0)
    ctx->pc = 0x1873d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1873d4: 0x68470017  ldl         $a3, 0x17($v0)
    ctx->pc = 0x1873d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x1873d8: 0x6c470010  ldr         $a3, 0x10($v0)
    ctx->pc = 0x1873d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x1873dc: 0x6848001f  ldl         $t0, 0x1F($v0)
    ctx->pc = 0x1873dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x1873e0: 0x6c480018  ldr         $t0, 0x18($v0)
    ctx->pc = 0x1873e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x1873e4: 0xb0a40007  sdl         $a0, 0x7($a1)
    ctx->pc = 0x1873e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1873e8: 0xb4a40000  sdr         $a0, 0x0($a1)
    ctx->pc = 0x1873e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1873ec: 0xb0a6000f  sdl         $a2, 0xF($a1)
    ctx->pc = 0x1873ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1873f0: 0xb4a60008  sdr         $a2, 0x8($a1)
    ctx->pc = 0x1873f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1873f4: 0xb0a70017  sdl         $a3, 0x17($a1)
    ctx->pc = 0x1873f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1873f8: 0xb4a70010  sdr         $a3, 0x10($a1)
    ctx->pc = 0x1873f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1873fc: 0xb0a8001f  sdl         $t0, 0x1F($a1)
    ctx->pc = 0x1873fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187400: 0xb4a80018  sdr         $t0, 0x18($a1)
    ctx->pc = 0x187400u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187404: 0x24420020  addiu       $v0, $v0, 0x20
    ctx->pc = 0x187404u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
    // 0x187408: 0x0  nop
    ctx->pc = 0x187408u;
    // NOP
    // 0x18740c: 0x0  nop
    ctx->pc = 0x18740cu;
    // NOP
    // 0x187410: 0x1443ffec  bne         $v0, $v1, . + 4 + (-0x14 << 2)
    ctx->pc = 0x187410u;
    {
        const bool branch_taken_0x187410 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x187414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187410u;
            // 0x187414: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187410) {
            ctx->pc = 0x1873C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1873c4;
        }
    }
    ctx->pc = 0x187418u;
    // 0x187418: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x187418u;
    {
        const bool branch_taken_0x187418 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18741Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187418u;
            // 0x18741c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187418) {
            ctx->pc = 0x187458u;
            goto label_187458;
        }
    }
    ctx->pc = 0x187420u;
label_187420:
    // 0x187420: 0xdc440000  ld          $a0, 0x0($v0)
    ctx->pc = 0x187420u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x187424: 0xdc460008  ld          $a2, 0x8($v0)
    ctx->pc = 0x187424u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x187428: 0xdc470010  ld          $a3, 0x10($v0)
    ctx->pc = 0x187428u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x18742c: 0xdc480018  ld          $t0, 0x18($v0)
    ctx->pc = 0x18742cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x187430: 0xfca40000  sd          $a0, 0x0($a1)
    ctx->pc = 0x187430u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 4));
    // 0x187434: 0xfca60008  sd          $a2, 0x8($a1)
    ctx->pc = 0x187434u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 6));
    // 0x187438: 0xfca70010  sd          $a3, 0x10($a1)
    ctx->pc = 0x187438u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 7));
    // 0x18743c: 0xfca80018  sd          $t0, 0x18($a1)
    ctx->pc = 0x18743cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 8));
    // 0x187440: 0x24420020  addiu       $v0, $v0, 0x20
    ctx->pc = 0x187440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
    // 0x187444: 0x0  nop
    ctx->pc = 0x187444u;
    // NOP
    // 0x187448: 0x0  nop
    ctx->pc = 0x187448u;
    // NOP
    // 0x18744c: 0x1443fff4  bne         $v0, $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x18744Cu;
    {
        const bool branch_taken_0x18744c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x187450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18744Cu;
            // 0x187450: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18744c) {
            ctx->pc = 0x187420u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187420;
        }
    }
    ctx->pc = 0x187454u;
    // 0x187454: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x187454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_187458:
    // 0x187458: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x187458u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18745c: 0x3e00008  jr          $ra
    ctx->pc = 0x18745Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18745Cu;
            // 0x187460: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1873C4u: goto label_1873c4;
            case 0x187420u: goto label_187420;
            case 0x187458u: goto label_187458;
            case 0x187468u: goto label_187468;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187464u;
    // 0x187464: 0x0  nop
    ctx->pc = 0x187464u;
    // NOP
label_187468:
    // 0x187468: 0x100202d  daddu       $a0, $t0, $zero
    ctx->pc = 0x187468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18746c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x18746cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x187470: 0x8061b98  j           func_186E60
    ctx->pc = 0x187470u;
    ctx->pc = 0x187474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x187470u;
            // 0x187474: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x186E60u;
    if (runtime->hasFunction(0x186E60u)) {
        auto targetFn = runtime->lookupFunction(0x186E60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00186E60_0x186e60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x187478u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
