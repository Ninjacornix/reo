#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001742A8
// Address: 0x1742a8 - 0x174328
void sub_001742A8_0x1742a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001742A8_0x1742a8");
#endif

    ctx->pc = 0x1742a8u;

    // 0x1742a8: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1742a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1742ac: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1742acu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1742b0: 0x8cc40008  lw          $a0, 0x8($a2)
    ctx->pc = 0x1742b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x1742b4: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x1742b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1742b8: 0x10830019  beq         $a0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1742B8u;
    {
        const bool branch_taken_0x1742b8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1742BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1742B8u;
            // 0x1742bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1742b8) {
            ctx->pc = 0x174320u;
            goto label_174320;
        }
    }
    ctx->pc = 0x1742C0u;
    // 0x1742c0: 0x8cc5000c  lw          $a1, 0xC($a2)
    ctx->pc = 0x1742c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x1742c4: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1742c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1742c8: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1742c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1742cc: 0x24a40001  addiu       $a0, $a1, 0x1
    ctx->pc = 0x1742ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1742d0: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1742d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1742d4: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1742d4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1742d8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1742d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1742dc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1742dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1742e0: 0x69030007  ldl         $v1, 0x7($t0)
    ctx->pc = 0x1742e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1742e4: 0x6d030000  ldr         $v1, 0x0($t0)
    ctx->pc = 0x1742e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1742e8: 0x8d090008  lw          $t1, 0x8($t0)
    ctx->pc = 0x1742e8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 8)));
    // 0x1742ec: 0xb0430007  sdl         $v1, 0x7($v0)
    ctx->pc = 0x1742ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1742f0: 0xb4430000  sdr         $v1, 0x0($v0)
    ctx->pc = 0x1742f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1742f4: 0xac490008  sw          $t1, 0x8($v0)
    ctx->pc = 0x1742f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 9));
    // 0x1742f8: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x1742f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1742fc: 0x83202a  slt         $a0, $a0, $v1
    ctx->pc = 0x1742fcu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x174300: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x174300u;
    {
        const bool branch_taken_0x174300 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x174304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174300u;
            // 0x174304: 0xa32823  subu        $a1, $a1, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174300) {
            ctx->pc = 0x17430Cu;
            goto label_17430c;
        }
    }
    ctx->pc = 0x174308u;
    // 0x174308: 0x24a70001  addiu       $a3, $a1, 0x1
    ctx->pc = 0x174308u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_17430c:
    // 0x17430c: 0x8cc30008  lw          $v1, 0x8($a2)
    ctx->pc = 0x17430cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x174310: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x174310u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174314: 0xacc7000c  sw          $a3, 0xC($a2)
    ctx->pc = 0x174314u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 7));
    // 0x174318: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x174318u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x17431c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x17431cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
label_174320:
    // 0x174320: 0x3e00008  jr          $ra
    ctx->pc = 0x174320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17430Cu: goto label_17430c;
            case 0x174320u: goto label_174320;
            default: break;
        }
        return;
    }
    ctx->pc = 0x174328u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
