#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186C10
// Address: 0x186c10 - 0x186d30
void sub_00186C10_0x186c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186C10_0x186c10");
#endif

    switch (ctx->pc) {
        case 0x186c40u: goto label_186c40;
        case 0x186c78u: goto label_186c78;
        case 0x186cd8u: goto label_186cd8;
        default: break;
    }

    ctx->pc = 0x186c10u;

    // 0x186c10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x186c10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x186c14: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x186c14u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x186c18: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x186c18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x186c1c: 0x2451b0c0  addiu       $s1, $v0, -0x4F40
    ctx->pc = 0x186c1cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947008));
    // 0x186c20: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x186c20u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186c24: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x186c24u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x186c28: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x186c28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186c2c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x186c2cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186c30: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x186c30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x186c34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x186c34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x186c38: 0xc06204e  jal         func_188138
    ctx->pc = 0x186C38u;
    SET_GPR_U32(ctx, 31, 0x186C40u);
    ctx->pc = 0x186C3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186C38u;
            // 0x186c3c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188138u;
    if (runtime->hasFunction(0x188138u)) {
        auto targetFn = runtime->lookupFunction(0x188138u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186C40u; }
        if (ctx->pc != 0x186C40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188138_0x188138(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186C40u; }
        if (ctx->pc != 0x186C40u) { return; }
    }
    ctx->pc = 0x186C40u;
label_186c40:
    // 0x186c40: 0x10400035  beqz        $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x186C40u;
    {
        const bool branch_taken_0x186c40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x186C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186C40u;
            // 0x186c44: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186c40) {
            ctx->pc = 0x186D18u;
            goto label_186d18;
        }
    }
    ctx->pc = 0x186C48u;
    // 0x186c48: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x186c48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x186c4c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x186c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x186c50: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x186c50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x186c54: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x186c54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x186c58: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x186c58u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x186c5c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x186c5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x186c60: 0x2421fa18  addiu       $at, $at, -0x5E8
    ctx->pc = 0x186c60u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294965784));
    // 0x186c64: 0x221021  addu        $v0, $at, $v0
    ctx->pc = 0x186c64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
    // 0x186c68: 0x451825  or          $v1, $v0, $a1
    ctx->pc = 0x186c68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x186c6c: 0x30630007  andi        $v1, $v1, 0x7
    ctx->pc = 0x186c6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)7);
    // 0x186c70: 0x10600019  beqz        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x186C70u;
    {
        const bool branch_taken_0x186c70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x186C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186C70u;
            // 0x186c74: 0x24a30180  addiu       $v1, $a1, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186c70) {
            ctx->pc = 0x186CD8u;
            goto label_186cd8;
        }
    }
    ctx->pc = 0x186C78u;
label_186c78:
    // 0x186c78: 0x68a40007  ldl         $a0, 0x7($a1)
    ctx->pc = 0x186c78u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x186c7c: 0x6ca40000  ldr         $a0, 0x0($a1)
    ctx->pc = 0x186c7cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x186c80: 0x68a6000f  ldl         $a2, 0xF($a1)
    ctx->pc = 0x186c80u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x186c84: 0x6ca60008  ldr         $a2, 0x8($a1)
    ctx->pc = 0x186c84u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x186c88: 0x68a70017  ldl         $a3, 0x17($a1)
    ctx->pc = 0x186c88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x186c8c: 0x6ca70010  ldr         $a3, 0x10($a1)
    ctx->pc = 0x186c8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x186c90: 0x68a8001f  ldl         $t0, 0x1F($a1)
    ctx->pc = 0x186c90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x186c94: 0x6ca80018  ldr         $t0, 0x18($a1)
    ctx->pc = 0x186c94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x186c98: 0xb0440007  sdl         $a0, 0x7($v0)
    ctx->pc = 0x186c98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186c9c: 0xb4440000  sdr         $a0, 0x0($v0)
    ctx->pc = 0x186c9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186ca0: 0xb046000f  sdl         $a2, 0xF($v0)
    ctx->pc = 0x186ca0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186ca4: 0xb4460008  sdr         $a2, 0x8($v0)
    ctx->pc = 0x186ca4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186ca8: 0xb0470017  sdl         $a3, 0x17($v0)
    ctx->pc = 0x186ca8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186cac: 0xb4470010  sdr         $a3, 0x10($v0)
    ctx->pc = 0x186cacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186cb0: 0xb048001f  sdl         $t0, 0x1F($v0)
    ctx->pc = 0x186cb0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186cb4: 0xb4480018  sdr         $t0, 0x18($v0)
    ctx->pc = 0x186cb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186cb8: 0x24a50020  addiu       $a1, $a1, 0x20
    ctx->pc = 0x186cb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x186cbc: 0x0  nop
    ctx->pc = 0x186cbcu;
    // NOP
    // 0x186cc0: 0x0  nop
    ctx->pc = 0x186cc0u;
    // NOP
    // 0x186cc4: 0x14a3ffec  bne         $a1, $v1, . + 4 + (-0x14 << 2)
    ctx->pc = 0x186CC4u;
    {
        const bool branch_taken_0x186cc4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x186CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186CC4u;
            // 0x186cc8: 0x24420020  addiu       $v0, $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186cc4) {
            ctx->pc = 0x186C78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186c78;
        }
    }
    ctx->pc = 0x186CCCu;
    // 0x186ccc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x186CCCu;
    {
        const bool branch_taken_0x186ccc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x186ccc) {
            ctx->pc = 0x186D0Cu;
            goto label_186d0c;
        }
    }
    ctx->pc = 0x186CD4u;
    // 0x186cd4: 0x0  nop
    ctx->pc = 0x186cd4u;
    // NOP
label_186cd8:
    // 0x186cd8: 0xdca40000  ld          $a0, 0x0($a1)
    ctx->pc = 0x186cd8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x186cdc: 0xdca60008  ld          $a2, 0x8($a1)
    ctx->pc = 0x186cdcu;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x186ce0: 0xdca70010  ld          $a3, 0x10($a1)
    ctx->pc = 0x186ce0u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x186ce4: 0xdca80018  ld          $t0, 0x18($a1)
    ctx->pc = 0x186ce4u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x186ce8: 0xfc440000  sd          $a0, 0x0($v0)
    ctx->pc = 0x186ce8u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 4));
    // 0x186cec: 0xfc460008  sd          $a2, 0x8($v0)
    ctx->pc = 0x186cecu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 6));
    // 0x186cf0: 0xfc470010  sd          $a3, 0x10($v0)
    ctx->pc = 0x186cf0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 7));
    // 0x186cf4: 0xfc480018  sd          $t0, 0x18($v0)
    ctx->pc = 0x186cf4u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 8));
    // 0x186cf8: 0x24a50020  addiu       $a1, $a1, 0x20
    ctx->pc = 0x186cf8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x186cfc: 0x0  nop
    ctx->pc = 0x186cfcu;
    // NOP
    // 0x186d00: 0x0  nop
    ctx->pc = 0x186d00u;
    // NOP
    // 0x186d04: 0x14a3fff4  bne         $a1, $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x186D04u;
    {
        const bool branch_taken_0x186d04 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x186D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186D04u;
            // 0x186d08: 0x24420020  addiu       $v0, $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186d04) {
            ctx->pc = 0x186CD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186cd8;
        }
    }
    ctx->pc = 0x186D0Cu;
label_186d0c:
    // 0x186d0c: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x186d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x186d10: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x186d10u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x186d14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x186d14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_186d18:
    // 0x186d18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x186d18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x186d1c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x186d1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x186d20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x186d20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x186d24: 0x3e00008  jr          $ra
    ctx->pc = 0x186D24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x186D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186D24u;
            // 0x186d28: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x186C40u: goto label_186c40;
            case 0x186C78u: goto label_186c78;
            case 0x186CD8u: goto label_186cd8;
            case 0x186D0Cu: goto label_186d0c;
            case 0x186D18u: goto label_186d18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x186D2Cu;
    // 0x186d2c: 0x0  nop
    ctx->pc = 0x186d2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
