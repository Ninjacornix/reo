#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0014FE90
// Address: 0x14fe90 - 0x14ff44
void sub_0014FE90_0x14fe90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0014FE90_0x14fe90");
#endif

    switch (ctx->pc) {
        case 0x14fea8u: goto label_14fea8;
        case 0x14ff08u: goto label_14ff08;
        default: break;
    }

    ctx->pc = 0x14fe90u;

    // 0x14fe90: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x14fe90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x14fe94: 0x2463c008  addiu       $v1, $v1, -0x3FF8
    ctx->pc = 0x14fe94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294950920));
    // 0x14fe98: 0x831025  or          $v0, $a0, $v1
    ctx->pc = 0x14fe98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x14fe9c: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x14fe9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x14fea0: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x14FEA0u;
    {
        const bool branch_taken_0x14fea0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14FEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FEA0u;
            // 0x14fea4: 0x24621800  addiu       $v0, $v1, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 6144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fea0) {
            ctx->pc = 0x14FF08u;
            goto label_14ff08;
        }
    }
    ctx->pc = 0x14FEA8u;
label_14fea8:
    // 0x14fea8: 0x68650007  ldl         $a1, 0x7($v1)
    ctx->pc = 0x14fea8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x14feac: 0x6c650000  ldr         $a1, 0x0($v1)
    ctx->pc = 0x14feacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x14feb0: 0x6866000f  ldl         $a2, 0xF($v1)
    ctx->pc = 0x14feb0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x14feb4: 0x6c660008  ldr         $a2, 0x8($v1)
    ctx->pc = 0x14feb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x14feb8: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x14feb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x14febc: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x14febcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x14fec0: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x14fec0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x14fec4: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x14fec4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x14fec8: 0xb0850007  sdl         $a1, 0x7($a0)
    ctx->pc = 0x14fec8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fecc: 0xb4850000  sdr         $a1, 0x0($a0)
    ctx->pc = 0x14feccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fed0: 0xb086000f  sdl         $a2, 0xF($a0)
    ctx->pc = 0x14fed0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fed4: 0xb4860008  sdr         $a2, 0x8($a0)
    ctx->pc = 0x14fed4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fed8: 0xb0870017  sdl         $a3, 0x17($a0)
    ctx->pc = 0x14fed8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fedc: 0xb4870010  sdr         $a3, 0x10($a0)
    ctx->pc = 0x14fedcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fee0: 0xb088001f  sdl         $t0, 0x1F($a0)
    ctx->pc = 0x14fee0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fee4: 0xb4880018  sdr         $t0, 0x18($a0)
    ctx->pc = 0x14fee4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14fee8: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x14fee8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x14feec: 0x0  nop
    ctx->pc = 0x14feecu;
    // NOP
    // 0x14fef0: 0x0  nop
    ctx->pc = 0x14fef0u;
    // NOP
    // 0x14fef4: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x14FEF4u;
    {
        const bool branch_taken_0x14fef4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x14FEF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FEF4u;
            // 0x14fef8: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14fef4) {
            ctx->pc = 0x14FEA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14fea8;
        }
    }
    ctx->pc = 0x14FEFCu;
    // 0x14fefc: 0x3e00008  jr          $ra
    ctx->pc = 0x14FEFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14FEA8u: goto label_14fea8;
            case 0x14FF08u: goto label_14ff08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FF04u;
    // 0x14ff04: 0x0  nop
    ctx->pc = 0x14ff04u;
    // NOP
label_14ff08:
    // 0x14ff08: 0xdc650000  ld          $a1, 0x0($v1)
    ctx->pc = 0x14ff08u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ff0c: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x14ff0cu;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x14ff10: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x14ff10u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x14ff14: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x14ff14u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x14ff18: 0xfc850000  sd          $a1, 0x0($a0)
    ctx->pc = 0x14ff18u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 5));
    // 0x14ff1c: 0xfc860008  sd          $a2, 0x8($a0)
    ctx->pc = 0x14ff1cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 6));
    // 0x14ff20: 0xfc870010  sd          $a3, 0x10($a0)
    ctx->pc = 0x14ff20u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 7));
    // 0x14ff24: 0xfc880018  sd          $t0, 0x18($a0)
    ctx->pc = 0x14ff24u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x14ff28: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x14ff28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x14ff2c: 0x0  nop
    ctx->pc = 0x14ff2cu;
    // NOP
    // 0x14ff30: 0x0  nop
    ctx->pc = 0x14ff30u;
    // NOP
    // 0x14ff34: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x14FF34u;
    {
        const bool branch_taken_0x14ff34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x14FF38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14FF34u;
            // 0x14ff38: 0x24840020  addiu       $a0, $a0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14ff34) {
            ctx->pc = 0x14FF08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_14ff08;
        }
    }
    ctx->pc = 0x14FF3Cu;
    // 0x14ff3c: 0x3e00008  jr          $ra
    ctx->pc = 0x14FF3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14FEA8u: goto label_14fea8;
            case 0x14FF08u: goto label_14ff08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14FF44u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
