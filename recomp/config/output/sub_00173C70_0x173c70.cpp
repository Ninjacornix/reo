#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173C70
// Address: 0x173c70 - 0x173e38
void sub_00173C70_0x173c70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173C70_0x173c70");
#endif

    switch (ctx->pc) {
        case 0x173ca4u: goto label_173ca4;
        case 0x173d04u: goto label_173d04;
        case 0x173d58u: goto label_173d58;
        case 0x173d64u: goto label_173d64;
        case 0x173d6cu: goto label_173d6c;
        case 0x173d74u: goto label_173d74;
        case 0x173d90u: goto label_173d90;
        case 0x173d9cu: goto label_173d9c;
        case 0x173db8u: goto label_173db8;
        case 0x173dccu: goto label_173dcc;
        case 0x173ddcu: goto label_173ddc;
        case 0x173df0u: goto label_173df0;
        case 0x173e08u: goto label_173e08;
        case 0x173e18u: goto label_173e18;
        default: break;
    }

    ctx->pc = 0x173c70u;

    // 0x173c70: 0x27bdfdd0  addiu       $sp, $sp, -0x230
    ctx->pc = 0x173c70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966736));
    // 0x173c74: 0xffb00200  sd          $s0, 0x200($sp)
    ctx->pc = 0x173c74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 512), GPR_U64(ctx, 16));
    // 0x173c78: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x173c78u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173c7c: 0x32020007  andi        $v0, $s0, 0x7
    ctx->pc = 0x173c7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)7);
    // 0x173c80: 0xffb30218  sd          $s3, 0x218($sp)
    ctx->pc = 0x173c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 536), GPR_U64(ctx, 19));
    // 0x173c84: 0xffb10208  sd          $s1, 0x208($sp)
    ctx->pc = 0x173c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 520), GPR_U64(ctx, 17));
    // 0x173c88: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x173c88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173c8c: 0xffb20210  sd          $s2, 0x210($sp)
    ctx->pc = 0x173c8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 528), GPR_U64(ctx, 18));
    // 0x173c90: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x173c90u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173c94: 0xffbf0220  sd          $ra, 0x220($sp)
    ctx->pc = 0x173c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 544), GPR_U64(ctx, 31));
    // 0x173c98: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x173C98u;
    {
        const bool branch_taken_0x173c98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173C98u;
            // 0x173c9c: 0x200182d  daddu       $v1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173c98) {
            ctx->pc = 0x173D00u;
            goto label_173d00;
        }
    }
    ctx->pc = 0x173CA0u;
    // 0x173ca0: 0x26020040  addiu       $v0, $s0, 0x40
    ctx->pc = 0x173ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
label_173ca4:
    // 0x173ca4: 0x68650007  ldl         $a1, 0x7($v1)
    ctx->pc = 0x173ca4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x173ca8: 0x6c650000  ldr         $a1, 0x0($v1)
    ctx->pc = 0x173ca8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x173cac: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x173cacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x173cb0: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x173cb0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x173cb4: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x173cb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x173cb8: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x173cb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x173cbc: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x173cbcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x173cc0: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x173cc0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x173cc4: 0xb0850007  sdl         $a1, 0x7($a0)
    ctx->pc = 0x173cc4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x173cc8: 0xb4850000  sdr         $a1, 0x0($a0)
    ctx->pc = 0x173cc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x173ccc: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x173cccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x173cd0: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x173cd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x173cd4: 0xb0870017  sdl         $a3, 0x17($a0)
    ctx->pc = 0x173cd4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x173cd8: 0xb4870010  sdr         $a3, 0x10($a0)
    ctx->pc = 0x173cd8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x173cdc: 0xb088001f  sdl         $t0, 0x1F($a0)
    ctx->pc = 0x173cdcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x173ce0: 0xb4880018  sdr         $t0, 0x18($a0)
    ctx->pc = 0x173ce0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x173ce4: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x173ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x173ce8: 0x0  nop
    ctx->pc = 0x173ce8u;
    // NOP
    // 0x173cec: 0x0  nop
    ctx->pc = 0x173cecu;
    // NOP
    // 0x173cf0: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x173CF0u;
    {
        const bool branch_taken_0x173cf0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x173CF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173CF0u;
            // 0x173cf4: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173cf0) {
            ctx->pc = 0x173CA4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_173ca4;
        }
    }
    ctx->pc = 0x173CF8u;
    // 0x173cf8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x173CF8u;
    {
        const bool branch_taken_0x173cf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x173cf8) {
            ctx->pc = 0x173D38u;
            goto label_173d38;
        }
    }
    ctx->pc = 0x173D00u;
label_173d00:
    // 0x173d00: 0x26020040  addiu       $v0, $s0, 0x40
    ctx->pc = 0x173d00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
label_173d04:
    // 0x173d04: 0xdc650000  ld          $a1, 0x0($v1)
    ctx->pc = 0x173d04u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x173d08: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x173d08u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x173d0c: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x173d0cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x173d10: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x173d10u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x173d14: 0xfc850000  sd          $a1, 0x0($a0)
    ctx->pc = 0x173d14u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 5));
    // 0x173d18: 0xfc860008  sd          $a2, 0x8($a0)
    ctx->pc = 0x173d18u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 6));
    // 0x173d1c: 0xfc870010  sd          $a3, 0x10($a0)
    ctx->pc = 0x173d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 7));
    // 0x173d20: 0xfc880018  sd          $t0, 0x18($a0)
    ctx->pc = 0x173d20u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x173d24: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x173d24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x173d28: 0x0  nop
    ctx->pc = 0x173d28u;
    // NOP
    // 0x173d2c: 0x0  nop
    ctx->pc = 0x173d2cu;
    // NOP
    // 0x173d30: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x173D30u;
    {
        const bool branch_taken_0x173d30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x173D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173D30u;
            // 0x173d34: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173d30) {
            ctx->pc = 0x173D04u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_173d04;
        }
    }
    ctx->pc = 0x173D38u;
label_173d38:
    // 0x173d38: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x173d38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x173d3c: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x173d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x173d40: 0x8e1209c0  lw          $s2, 0x9C0($s0)
    ctx->pc = 0x173d40u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2496)));
    // 0x173d44: 0x12400005  beqz        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x173D44u;
    {
        const bool branch_taken_0x173d44 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x173d44) {
            ctx->pc = 0x173D5Cu;
            goto label_173d5c;
        }
    }
    ctx->pc = 0x173D4Cu;
    // 0x173d4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x173d4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173d50: 0xc05cf8e  jal         func_173E38
    ctx->pc = 0x173D50u;
    SET_GPR_U32(ctx, 31, 0x173D58u);
    ctx->pc = 0x173D54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173D50u;
            // 0x173d54: 0x27a50050  addiu       $a1, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173E38u;
    if (runtime->hasFunction(0x173E38u)) {
        auto targetFn = runtime->lookupFunction(0x173E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D58u; }
        if (ctx->pc != 0x173D58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173E38_0x173e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D58u; }
        if (ctx->pc != 0x173D58u) { return; }
    }
    ctx->pc = 0x173D58u;
label_173d58:
    // 0x173d58: 0x8fb30064  lw          $s3, 0x64($sp)
    ctx->pc = 0x173d58u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
label_173d5c:
    // 0x173d5c: 0xc05a3de  jal         func_168F78
    ctx->pc = 0x173D5Cu;
    SET_GPR_U32(ctx, 31, 0x173D64u);
    ctx->pc = 0x173D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173D5Cu;
            // 0x173d60: 0x26040078  addiu       $a0, $s0, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168F78u;
    if (runtime->hasFunction(0x168F78u)) {
        auto targetFn = runtime->lookupFunction(0x168F78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D64u; }
        if (ctx->pc != 0x173D64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168F78_0x168f78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D64u; }
        if (ctx->pc != 0x173D64u) { return; }
    }
    ctx->pc = 0x173D64u;
label_173d64:
    // 0x173d64: 0xc059a78  jal         func_1669E0
    ctx->pc = 0x173D64u;
    SET_GPR_U32(ctx, 31, 0x173D6Cu);
    ctx->pc = 0x173D68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173D64u;
            // 0x173d68: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1669E0u;
    if (runtime->hasFunction(0x1669E0u)) {
        auto targetFn = runtime->lookupFunction(0x1669E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D6Cu; }
        if (ctx->pc != 0x173D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001669E0_0x1669e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D6Cu; }
        if (ctx->pc != 0x173D6Cu) { return; }
    }
    ctx->pc = 0x173D6Cu;
label_173d6c:
    // 0x173d6c: 0xc05ce92  jal         func_173A48
    ctx->pc = 0x173D6Cu;
    SET_GPR_U32(ctx, 31, 0x173D74u);
    ctx->pc = 0x173D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173D6Cu;
            // 0x173d70: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173A48u;
    if (runtime->hasFunction(0x173A48u)) {
        auto targetFn = runtime->lookupFunction(0x173A48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D74u; }
        if (ctx->pc != 0x173D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173A48_0x173a48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D74u; }
        if (ctx->pc != 0x173D74u) { return; }
    }
    ctx->pc = 0x173D74u;
label_173d74:
    // 0x173d74: 0x5440002a  bnel        $v0, $zero, . + 4 + (0x2A << 2)
    ctx->pc = 0x173D74u;
    {
        const bool branch_taken_0x173d74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x173d74) {
            ctx->pc = 0x173D78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173D74u;
            // 0x173d78: 0xdfb00200  ld          $s0, 0x200($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 512)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173E20u;
            goto label_173e20;
        }
    }
    ctx->pc = 0x173D7Cu;
    // 0x173d7c: 0x27b10070  addiu       $s1, $sp, 0x70
    ctx->pc = 0x173d7cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x173d80: 0x26050b30  addiu       $a1, $s0, 0xB30
    ctx->pc = 0x173d80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 2864));
    // 0x173d84: 0x24060190  addiu       $a2, $zero, 0x190
    ctx->pc = 0x173d84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
    // 0x173d88: 0xc055798  jal         func_155E60
    ctx->pc = 0x173D88u;
    SET_GPR_U32(ctx, 31, 0x173D90u);
    ctx->pc = 0x173D8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173D88u;
            // 0x173d8c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D90u; }
        if (ctx->pc != 0x173D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D90u; }
        if (ctx->pc != 0x173D90u) { return; }
    }
    ctx->pc = 0x173D90u;
label_173d90:
    // 0x173d90: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x173d90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173d94: 0xc05cd6c  jal         func_1735B0
    ctx->pc = 0x173D94u;
    SET_GPR_U32(ctx, 31, 0x173D9Cu);
    ctx->pc = 0x173D98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173D94u;
            // 0x173d98: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1735B0u;
    if (runtime->hasFunction(0x1735B0u)) {
        auto targetFn = runtime->lookupFunction(0x1735B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D9Cu; }
        if (ctx->pc != 0x173D9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001735B0_0x1735b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173D9Cu; }
        if (ctx->pc != 0x173D9Cu) { return; }
    }
    ctx->pc = 0x173D9Cu;
label_173d9c:
    // 0x173d9c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x173d9cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173da0: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x173DA0u;
    {
        const bool branch_taken_0x173da0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x173DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173DA0u;
            // 0x173da4: 0x260409a0  addiu       $a0, $s0, 0x9A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2464));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173da0) {
            ctx->pc = 0x173DC0u;
            goto label_173dc0;
        }
    }
    ctx->pc = 0x173DA8u;
    // 0x173da8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x173da8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x173dac: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x173dacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173db0: 0xc05a704  jal         func_169C10
    ctx->pc = 0x173DB0u;
    SET_GPR_U32(ctx, 31, 0x173DB8u);
    ctx->pc = 0x173DB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173DB0u;
            // 0x173db4: 0x34a50202  ori         $a1, $a1, 0x202 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)514);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173DB8u; }
        if (ctx->pc != 0x173DB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173DB8u; }
        if (ctx->pc != 0x173DB8u) { return; }
    }
    ctx->pc = 0x173DB8u;
label_173db8:
    // 0x173db8: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x173DB8u;
    {
        const bool branch_taken_0x173db8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x173DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173DB8u;
            // 0x173dbc: 0xdfb00200  ld          $s0, 0x200($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 512)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173db8) {
            ctx->pc = 0x173E20u;
            goto label_173e20;
        }
    }
    ctx->pc = 0x173DC0u;
label_173dc0:
    // 0x173dc0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x173dc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173dc4: 0xc055798  jal         func_155E60
    ctx->pc = 0x173DC4u;
    SET_GPR_U32(ctx, 31, 0x173DCCu);
    ctx->pc = 0x173DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173DC4u;
            // 0x173dc8: 0x24060190  addiu       $a2, $zero, 0x190 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173DCCu; }
        if (ctx->pc != 0x173DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173DCCu; }
        if (ctx->pc != 0x173DCCu) { return; }
    }
    ctx->pc = 0x173DCCu;
label_173dcc:
    // 0x173dcc: 0x26040b30  addiu       $a0, $s0, 0xB30
    ctx->pc = 0x173dccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2864));
    // 0x173dd0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x173dd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173dd4: 0xc055798  jal         func_155E60
    ctx->pc = 0x173DD4u;
    SET_GPR_U32(ctx, 31, 0x173DDCu);
    ctx->pc = 0x173DD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173DD4u;
            // 0x173dd8: 0x24060190  addiu       $a2, $zero, 0x190 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173DDCu; }
        if (ctx->pc != 0x173DDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173DDCu; }
        if (ctx->pc != 0x173DDCu) { return; }
    }
    ctx->pc = 0x173DDCu;
label_173ddc:
    // 0x173ddc: 0x1240000f  beqz        $s2, . + 4 + (0xF << 2)
    ctx->pc = 0x173DDCu;
    {
        const bool branch_taken_0x173ddc = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x173DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173DDCu;
            // 0x173de0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173ddc) {
            ctx->pc = 0x173E1Cu;
            goto label_173e1c;
        }
    }
    ctx->pc = 0x173DE4u;
    // 0x173de4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x173de4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173de8: 0xc05cf8e  jal         func_173E38
    ctx->pc = 0x173DE8u;
    SET_GPR_U32(ctx, 31, 0x173DF0u);
    ctx->pc = 0x173DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173DE8u;
            // 0x173dec: 0x27a50050  addiu       $a1, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173E38u;
    if (runtime->hasFunction(0x173E38u)) {
        auto targetFn = runtime->lookupFunction(0x173E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173DF0u; }
        if (ctx->pc != 0x173DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173E38_0x173e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173DF0u; }
        if (ctx->pc != 0x173DF0u) { return; }
    }
    ctx->pc = 0x173DF0u;
label_173df0:
    // 0x173df0: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x173DF0u;
    {
        const bool branch_taken_0x173df0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x173df0) {
            ctx->pc = 0x173DF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173DF0u;
            // 0x173df4: 0xdfb00200  ld          $s0, 0x200($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 512)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173E20u;
            goto label_173e20;
        }
    }
    ctx->pc = 0x173DF8u;
    // 0x173df8: 0x8fa60064  lw          $a2, 0x64($sp)
    ctx->pc = 0x173df8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x173dfc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x173dfcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173e00: 0xc05cfaa  jal         func_173EA8
    ctx->pc = 0x173E00u;
    SET_GPR_U32(ctx, 31, 0x173E08u);
    ctx->pc = 0x173E04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173E00u;
            // 0x173e04: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173EA8u;
    if (runtime->hasFunction(0x173EA8u)) {
        auto targetFn = runtime->lookupFunction(0x173EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173E08u; }
        if (ctx->pc != 0x173E08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173EA8_0x173ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173E08u; }
        if (ctx->pc != 0x173E08u) { return; }
    }
    ctx->pc = 0x173E08u;
label_173e08:
    // 0x173e08: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x173E08u;
    {
        const bool branch_taken_0x173e08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x173e08) {
            ctx->pc = 0x173E0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173E08u;
            // 0x173e0c: 0xdfb00200  ld          $s0, 0x200($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 512)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173E20u;
            goto label_173e20;
        }
    }
    ctx->pc = 0x173E10u;
    // 0x173e10: 0xc05cfca  jal         func_173F28
    ctx->pc = 0x173E10u;
    SET_GPR_U32(ctx, 31, 0x173E18u);
    ctx->pc = 0x173E14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173E10u;
            // 0x173e14: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173F28u;
    if (runtime->hasFunction(0x173F28u)) {
        auto targetFn = runtime->lookupFunction(0x173F28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173E18u; }
        if (ctx->pc != 0x173E18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173F28_0x173f28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173E18u; }
        if (ctx->pc != 0x173E18u) { return; }
    }
    ctx->pc = 0x173E18u;
label_173e18:
    // 0x173e18: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x173e18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_173e1c:
    // 0x173e1c: 0xdfb00200  ld          $s0, 0x200($sp)
    ctx->pc = 0x173e1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 512)));
label_173e20:
    // 0x173e20: 0xdfb10208  ld          $s1, 0x208($sp)
    ctx->pc = 0x173e20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 520)));
    // 0x173e24: 0xdfb20210  ld          $s2, 0x210($sp)
    ctx->pc = 0x173e24u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x173e28: 0xdfb30218  ld          $s3, 0x218($sp)
    ctx->pc = 0x173e28u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 536)));
    // 0x173e2c: 0xdfbf0220  ld          $ra, 0x220($sp)
    ctx->pc = 0x173e2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x173e30: 0x3e00008  jr          $ra
    ctx->pc = 0x173E30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173E30u;
            // 0x173e34: 0x27bd0230  addiu       $sp, $sp, 0x230 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 560));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173CA4u: goto label_173ca4;
            case 0x173D00u: goto label_173d00;
            case 0x173D04u: goto label_173d04;
            case 0x173D38u: goto label_173d38;
            case 0x173D58u: goto label_173d58;
            case 0x173D5Cu: goto label_173d5c;
            case 0x173D64u: goto label_173d64;
            case 0x173D6Cu: goto label_173d6c;
            case 0x173D74u: goto label_173d74;
            case 0x173D90u: goto label_173d90;
            case 0x173D9Cu: goto label_173d9c;
            case 0x173DB8u: goto label_173db8;
            case 0x173DC0u: goto label_173dc0;
            case 0x173DCCu: goto label_173dcc;
            case 0x173DDCu: goto label_173ddc;
            case 0x173DF0u: goto label_173df0;
            case 0x173E08u: goto label_173e08;
            case 0x173E18u: goto label_173e18;
            case 0x173E1Cu: goto label_173e1c;
            case 0x173E20u: goto label_173e20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173E38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
