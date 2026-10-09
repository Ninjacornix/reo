#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016EF18
// Address: 0x16ef18 - 0x16f230
void sub_0016EF18_0x16ef18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016EF18_0x16ef18");
#endif

    switch (ctx->pc) {
        case 0x16ef68u: goto label_16ef68;
        case 0x16ef9cu: goto label_16ef9c;
        case 0x16effcu: goto label_16effc;
        case 0x16f08cu: goto label_16f08c;
        default: break;
    }

    ctx->pc = 0x16ef18u;

    // 0x16ef18: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16ef18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16ef1c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16ef1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16ef20: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16ef20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ef24: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16ef24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16ef28: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16ef28u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ef2c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16ef2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16ef30: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x16ef30u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ef34: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x16ef34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16ef38: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x16ef38u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ef3c: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x16ef3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x16ef40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16ef40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16ef44: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x16ef44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x16ef48: 0x8e901b30  lw          $s0, 0x1B30($s4)
    ctx->pc = 0x16ef48u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 6960)));
    // 0x16ef4c: 0x8e020134  lw          $v0, 0x134($s0)
    ctx->pc = 0x16ef4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
    // 0x16ef50: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16EF50u;
    {
        const bool branch_taken_0x16ef50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EF54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EF50u;
            // 0x16ef54: 0x2695094c  addiu       $s5, $s4, 0x94C (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 20), 2380));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ef50) {
            ctx->pc = 0x16EF60u;
            goto label_16ef60;
        }
    }
    ctx->pc = 0x16EF58u;
    // 0x16ef58: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x16EF58u;
    {
        const bool branch_taken_0x16ef58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EF5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EF58u;
            // 0x16ef5c: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ef58) {
            ctx->pc = 0x16EF80u;
            goto label_16ef80;
        }
    }
    ctx->pc = 0x16EF60u;
label_16ef60:
    // 0x16ef60: 0xc05c18c  jal         func_170630
    ctx->pc = 0x16EF60u;
    SET_GPR_U32(ctx, 31, 0x16EF68u);
    ctx->pc = 0x170630u;
    if (runtime->hasFunction(0x170630u)) {
        auto targetFn = runtime->lookupFunction(0x170630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EF68u; }
        if (ctx->pc != 0x16EF68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170630_0x170630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EF68u; }
        if (ctx->pc != 0x16EF68u) { return; }
    }
    ctx->pc = 0x16EF68u;
label_16ef68:
    // 0x16ef68: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16EF68u;
    {
        const bool branch_taken_0x16ef68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16EF6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EF68u;
            // 0x16ef6c: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ef68) {
            ctx->pc = 0x16EF80u;
            goto label_16ef80;
        }
    }
    ctx->pc = 0x16EF70u;
    // 0x16ef70: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16ef70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ef74: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x16ef74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16ef78: 0x100000a4  b           . + 4 + (0xA4 << 2)
    ctx->pc = 0x16EF78u;
    {
        const bool branch_taken_0x16ef78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EF78u;
            // 0x16ef7c: 0xaea30024  sw          $v1, 0x24($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 36), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ef78) {
            ctx->pc = 0x16F20Cu;
            goto label_16f20c;
        }
    }
    ctx->pc = 0x16EF80u;
label_16ef80:
    // 0x16ef80: 0x8e6a0000  lw          $t2, 0x0($s3)
    ctx->pc = 0x16ef80u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x16ef84: 0x2546002c  addiu       $a2, $t2, 0x2C
    ctx->pc = 0x16ef84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 10), 44));
    // 0x16ef88: 0x2461025  or          $v0, $s2, $a2
    ctx->pc = 0x16ef88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) | GPR_U64(ctx, 6));
    // 0x16ef8c: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x16ef8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x16ef90: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x16EF90u;
    {
        const bool branch_taken_0x16ef90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EF94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EF90u;
            // 0x16ef94: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ef90) {
            ctx->pc = 0x16EFF8u;
            goto label_16eff8;
        }
    }
    ctx->pc = 0x16EF98u;
    // 0x16ef98: 0x26420040  addiu       $v0, $s2, 0x40
    ctx->pc = 0x16ef98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 64));
label_16ef9c:
    // 0x16ef9c: 0x68a30007  ldl         $v1, 0x7($a1)
    ctx->pc = 0x16ef9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16efa0: 0x6ca30000  ldr         $v1, 0x0($a1)
    ctx->pc = 0x16efa0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16efa4: 0x68a4000f  ldl         $a0, 0xF($a1)
    ctx->pc = 0x16efa4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16efa8: 0x6ca40008  ldr         $a0, 0x8($a1)
    ctx->pc = 0x16efa8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16efac: 0x68a70017  ldl         $a3, 0x17($a1)
    ctx->pc = 0x16efacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x16efb0: 0x6ca70010  ldr         $a3, 0x10($a1)
    ctx->pc = 0x16efb0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x16efb4: 0x68a8001f  ldl         $t0, 0x1F($a1)
    ctx->pc = 0x16efb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x16efb8: 0x6ca80018  ldr         $t0, 0x18($a1)
    ctx->pc = 0x16efb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x16efbc: 0xb0c30007  sdl         $v1, 0x7($a2)
    ctx->pc = 0x16efbcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16efc0: 0xb4c30000  sdr         $v1, 0x0($a2)
    ctx->pc = 0x16efc0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16efc4: 0xb0c4000f  sdl         $a0, 0xF($a2)
    ctx->pc = 0x16efc4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16efc8: 0xb4c40008  sdr         $a0, 0x8($a2)
    ctx->pc = 0x16efc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16efcc: 0xb0c70017  sdl         $a3, 0x17($a2)
    ctx->pc = 0x16efccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16efd0: 0xb4c70010  sdr         $a3, 0x10($a2)
    ctx->pc = 0x16efd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16efd4: 0xb0c8001f  sdl         $t0, 0x1F($a2)
    ctx->pc = 0x16efd4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16efd8: 0xb4c80018  sdr         $t0, 0x18($a2)
    ctx->pc = 0x16efd8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16efdc: 0x24a50020  addiu       $a1, $a1, 0x20
    ctx->pc = 0x16efdcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x16efe0: 0x0  nop
    ctx->pc = 0x16efe0u;
    // NOP
    // 0x16efe4: 0x0  nop
    ctx->pc = 0x16efe4u;
    // NOP
    // 0x16efe8: 0x14a2ffec  bne         $a1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x16EFE8u;
    {
        const bool branch_taken_0x16efe8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x16EFECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EFE8u;
            // 0x16efec: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16efe8) {
            ctx->pc = 0x16EF9Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16ef9c;
        }
    }
    ctx->pc = 0x16EFF0u;
    // 0x16eff0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x16EFF0u;
    {
        const bool branch_taken_0x16eff0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EFF0u;
            // 0x16eff4: 0x8e830038  lw          $v1, 0x38($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 56)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16eff0) {
            ctx->pc = 0x16F034u;
            goto label_16f034;
        }
    }
    ctx->pc = 0x16EFF8u;
label_16eff8:
    // 0x16eff8: 0x26420040  addiu       $v0, $s2, 0x40
    ctx->pc = 0x16eff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 64));
label_16effc:
    // 0x16effc: 0xdca90000  ld          $t1, 0x0($a1)
    ctx->pc = 0x16effcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x16f000: 0xdca30008  ld          $v1, 0x8($a1)
    ctx->pc = 0x16f000u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x16f004: 0xdca40010  ld          $a0, 0x10($a1)
    ctx->pc = 0x16f004u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x16f008: 0xdca70018  ld          $a3, 0x18($a1)
    ctx->pc = 0x16f008u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x16f00c: 0xfcc90000  sd          $t1, 0x0($a2)
    ctx->pc = 0x16f00cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 9));
    // 0x16f010: 0xfcc30008  sd          $v1, 0x8($a2)
    ctx->pc = 0x16f010u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 8), GPR_U64(ctx, 3));
    // 0x16f014: 0xfcc40010  sd          $a0, 0x10($a2)
    ctx->pc = 0x16f014u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 4));
    // 0x16f018: 0xfcc70018  sd          $a3, 0x18($a2)
    ctx->pc = 0x16f018u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 24), GPR_U64(ctx, 7));
    // 0x16f01c: 0x24a50020  addiu       $a1, $a1, 0x20
    ctx->pc = 0x16f01cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
    // 0x16f020: 0x0  nop
    ctx->pc = 0x16f020u;
    // NOP
    // 0x16f024: 0x0  nop
    ctx->pc = 0x16f024u;
    // NOP
    // 0x16f028: 0x14a2fff4  bne         $a1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x16F028u;
    {
        const bool branch_taken_0x16f028 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x16F02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F028u;
            // 0x16f02c: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f028) {
            ctx->pc = 0x16EFFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16effc;
        }
    }
    ctx->pc = 0x16F030u;
    // 0x16f030: 0x8e830038  lw          $v1, 0x38($s4)
    ctx->pc = 0x16f030u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 56)));
label_16f034:
    // 0x16f034: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x16f034u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16f038: 0x68a80007  ldl         $t0, 0x7($a1)
    ctx->pc = 0x16f038u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x16f03c: 0x6ca80000  ldr         $t0, 0x0($a1)
    ctx->pc = 0x16f03cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x16f040: 0x68a9000f  ldl         $t1, 0xF($a1)
    ctx->pc = 0x16f040u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x16f044: 0x6ca90008  ldr         $t1, 0x8($a1)
    ctx->pc = 0x16f044u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x16f048: 0x8ca40010  lw          $a0, 0x10($a1)
    ctx->pc = 0x16f048u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x16f04c: 0xb0c80007  sdl         $t0, 0x7($a2)
    ctx->pc = 0x16f04cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f050: 0xb4c80000  sdr         $t0, 0x0($a2)
    ctx->pc = 0x16f050u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f054: 0xb0c9000f  sdl         $t1, 0xF($a2)
    ctx->pc = 0x16f054u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f058: 0xb4c90008  sdr         $t1, 0x8($a2)
    ctx->pc = 0x16f058u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f05c: 0x14620042  bne         $v1, $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x16F05Cu;
    {
        const bool branch_taken_0x16f05c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x16F060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F05Cu;
            // 0x16f060: 0xacc40010  sw          $a0, 0x10($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f05c) {
            ctx->pc = 0x16F168u;
            goto label_16f168;
        }
    }
    ctx->pc = 0x16F064u;
    // 0x16f064: 0x8e420018  lw          $v0, 0x18($s2)
    ctx->pc = 0x16f064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x16f068: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x16f068u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x16f06c: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x16f06cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x16f070: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x16F070u;
    {
        const bool branch_taken_0x16f070 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16f070) {
            ctx->pc = 0x16F074u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16F070u;
            // 0x16f074: 0x8e430000  lw          $v1, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16F0A4u;
            goto label_16f0a4;
        }
    }
    ctx->pc = 0x16F078u;
    // 0x16f078: 0x8e020134  lw          $v0, 0x134($s0)
    ctx->pc = 0x16f078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
    // 0x16f07c: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x16F07Cu;
    {
        const bool branch_taken_0x16f07c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16f07c) {
            ctx->pc = 0x16F080u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16F07Cu;
            // 0x16f080: 0x8e430000  lw          $v1, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16F0A4u;
            goto label_16f0a4;
        }
    }
    ctx->pc = 0x16F084u;
    // 0x16f084: 0xc05c1ce  jal         func_170738
    ctx->pc = 0x16F084u;
    SET_GPR_U32(ctx, 31, 0x16F08Cu);
    ctx->pc = 0x16F088u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F084u;
            // 0x16f088: 0x8e04012c  lw          $a0, 0x12C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170738u;
    if (runtime->hasFunction(0x170738u)) {
        auto targetFn = runtime->lookupFunction(0x170738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F08Cu; }
        if (ctx->pc != 0x16F08Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170738_0x170738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F08Cu; }
        if (ctx->pc != 0x16F08Cu) { return; }
    }
    ctx->pc = 0x16F08Cu;
label_16f08c:
    // 0x16f08c: 0x8e020130  lw          $v0, 0x130($s0)
    ctx->pc = 0x16f08cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x16f090: 0xae02012c  sw          $v0, 0x12C($s0)
    ctx->pc = 0x16f090u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 300), GPR_U32(ctx, 2));
    // 0x16f094: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x16f094u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x16f098: 0xae030130  sw          $v1, 0x130($s0)
    ctx->pc = 0x16f098u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 304), GPR_U32(ctx, 3));
    // 0x16f09c: 0x8e6a0000  lw          $t2, 0x0($s3)
    ctx->pc = 0x16f09cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x16f0a0: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x16f0a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_16f0a4:
    // 0x16f0a4: 0x8e480004  lw          $t0, 0x4($s2)
    ctx->pc = 0x16f0a4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x16f0a8: 0x2462000f  addiu       $v0, $v1, 0xF
    ctx->pc = 0x16f0a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x16f0ac: 0x2463001e  addiu       $v1, $v1, 0x1E
    ctx->pc = 0x16f0acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 30));
    // 0x16f0b0: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x16f0b0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16f0b4: 0x2505000f  addiu       $a1, $t0, 0xF
    ctx->pc = 0x16f0b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), 15));
    // 0x16f0b8: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x16f0b8u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x16f0bc: 0x28a90000  slti        $t1, $a1, 0x0
    ctx->pc = 0x16f0bcu;
    SET_GPR_U64(ctx, 9, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16f0c0: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x16f0c0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x16f0c4: 0x2508001e  addiu       $t0, $t0, 0x1E
    ctx->pc = 0x16f0c4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 30));
    // 0x16f0c8: 0x22100  sll         $a0, $v0, 4
    ctx->pc = 0x16f0c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x16f0cc: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x16f0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x16f0d0: 0x2487003f  addiu       $a3, $a0, 0x3F
    ctx->pc = 0x16f0d0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 63));
    // 0x16f0d4: 0x2484007e  addiu       $a0, $a0, 0x7E
    ctx->pc = 0x16f0d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 126));
    // 0x16f0d8: 0x2446003f  addiu       $a2, $v0, 0x3F
    ctx->pc = 0x16f0d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x16f0dc: 0x2442007e  addiu       $v0, $v0, 0x7E
    ctx->pc = 0x16f0dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 126));
    // 0x16f0e0: 0x28e30000  slti        $v1, $a3, 0x0
    ctx->pc = 0x16f0e0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16f0e4: 0x109280b  movn        $a1, $t0, $t1
    ctx->pc = 0x16f0e4u;
    if (GPR_U64(ctx, 9) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 8));
    // 0x16f0e8: 0x83380b  movn        $a3, $a0, $v1
    ctx->pc = 0x16f0e8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 4));
    // 0x16f0ec: 0x28c30000  slti        $v1, $a2, 0x0
    ctx->pc = 0x16f0ecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16f0f0: 0x43300b  movn        $a2, $v0, $v1
    ctx->pc = 0x16f0f0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 2));
    // 0x16f0f4: 0x8e03012c  lw          $v1, 0x12C($s0)
    ctx->pc = 0x16f0f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
    // 0x16f0f8: 0x73983  sra         $a3, $a3, 6
    ctx->pc = 0x16f0f8u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 6));
    // 0x16f0fc: 0x52903  sra         $a1, $a1, 4
    ctx->pc = 0x16f0fcu;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 4));
    // 0x16f100: 0xe51018  mult        $v0, $a3, $a1
    ctx->pc = 0x16f100u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x16f104: 0x73980  sll         $a3, $a3, 6
    ctx->pc = 0x16f104u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 6));
    // 0x16f108: 0x63183  sra         $a2, $a2, 6
    ctx->pc = 0x16f108u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 6));
    // 0x16f10c: 0x8e040130  lw          $a0, 0x130($s0)
    ctx->pc = 0x16f10cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x16f110: 0x70c52818  mult1       $a1, $a2, $a1
    ctx->pc = 0x16f110u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 5); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x16f114: 0x63180  sll         $a2, $a2, 6
    ctx->pc = 0x16f114u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 6));
    // 0x16f118: 0x8c680008  lw          $t0, 0x8($v1)
    ctx->pc = 0x16f118u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x16f11c: 0x8c890008  lw          $t1, 0x8($a0)
    ctx->pc = 0x16f11cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x16f120: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x16f120u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x16f124: 0xa627001e  sh          $a3, 0x1E($s1)
    ctx->pc = 0x16f124u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 30), (uint16_t)GPR_U32(ctx, 7));
    // 0x16f128: 0x1222021  addu        $a0, $t1, $v0
    ctx->pc = 0x16f128u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x16f12c: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x16f12cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x16f130: 0x52a40  sll         $a1, $a1, 9
    ctx->pc = 0x16f130u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 9));
    // 0x16f134: 0xa626001c  sh          $a2, 0x1C($s1)
    ctx->pc = 0x16f134u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 28), (uint16_t)GPR_U32(ctx, 6));
    // 0x16f138: 0x851821  addu        $v1, $a0, $a1
    ctx->pc = 0x16f138u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x16f13c: 0x452821  addu        $a1, $v0, $a1
    ctx->pc = 0x16f13cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16f140: 0xae250004  sw          $a1, 0x4($s1)
    ctx->pc = 0x16f140u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 5));
    // 0x16f144: 0xae230014  sw          $v1, 0x14($s1)
    ctx->pc = 0x16f144u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 3));
    // 0x16f148: 0xa627000e  sh          $a3, 0xE($s1)
    ctx->pc = 0x16f148u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 14), (uint16_t)GPR_U32(ctx, 7));
    // 0x16f14c: 0xa626000c  sh          $a2, 0xC($s1)
    ctx->pc = 0x16f14cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 12), (uint16_t)GPR_U32(ctx, 6));
    // 0x16f150: 0xae280008  sw          $t0, 0x8($s1)
    ctx->pc = 0x16f150u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 8));
    // 0x16f154: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x16f154u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x16f158: 0xae290018  sw          $t1, 0x18($s1)
    ctx->pc = 0x16f158u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 9));
    // 0x16f15c: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x16F15Cu;
    {
        const bool branch_taken_0x16f15c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F15Cu;
            // 0x16f160: 0xae240010  sw          $a0, 0x10($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f15c) {
            ctx->pc = 0x16F1ECu;
            goto label_16f1ec;
        }
    }
    ctx->pc = 0x16F164u;
    // 0x16f164: 0x0  nop
    ctx->pc = 0x16f164u;
    // NOP
label_16f168:
    // 0x16f168: 0x8e420018  lw          $v0, 0x18($s2)
    ctx->pc = 0x16f168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x16f16c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x16f16cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x16f170: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x16f170u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x16f174: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16F174u;
    {
        const bool branch_taken_0x16f174 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F174u;
            // 0x16f178: 0x8e020104  lw          $v0, 0x104($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 260)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f174) {
            ctx->pc = 0x16F194u;
            goto label_16f194;
        }
    }
    ctx->pc = 0x16F17Cu;
    // 0x16f17c: 0x8e030108  lw          $v1, 0x108($s0)
    ctx->pc = 0x16f17cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 264)));
    // 0x16f180: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x16f180u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x16f184: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x16f184u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x16f188: 0xae020104  sw          $v0, 0x104($s0)
    ctx->pc = 0x16f188u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 260), GPR_U32(ctx, 2));
    // 0x16f18c: 0xae030108  sw          $v1, 0x108($s0)
    ctx->pc = 0x16f18cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 264), GPR_U32(ctx, 3));
    // 0x16f190: 0x8e020104  lw          $v0, 0x104($s0)
    ctx->pc = 0x16f190u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 260)));
label_16f194:
    // 0x16f194: 0x2604010c  addiu       $a0, $s0, 0x10C
    ctx->pc = 0x16f194u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 268));
    // 0x16f198: 0x8e030108  lw          $v1, 0x108($s0)
    ctx->pc = 0x16f198u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 264)));
    // 0x16f19c: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x16f19cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x16f1a0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x16f1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x16f1a4: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x16f1a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x16f1a8: 0x68480007  ldl         $t0, 0x7($v0)
    ctx->pc = 0x16f1a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x16f1ac: 0x6c480000  ldr         $t0, 0x0($v0)
    ctx->pc = 0x16f1acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x16f1b0: 0x6849000f  ldl         $t1, 0xF($v0)
    ctx->pc = 0x16f1b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem << shift)); }
    // 0x16f1b4: 0x6c490008  ldr         $t1, 0x8($v0)
    ctx->pc = 0x16f1b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 9, (GPR_U64(ctx, 9) & keepMask) | (mem >> shift)); }
    // 0x16f1b8: 0xb2280007  sdl         $t0, 0x7($s1)
    ctx->pc = 0x16f1b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f1bc: 0xb6280000  sdr         $t0, 0x0($s1)
    ctx->pc = 0x16f1bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f1c0: 0xb229000f  sdl         $t1, 0xF($s1)
    ctx->pc = 0x16f1c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f1c4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x16f1c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x16f1c8: 0xb6290008  sdr         $t1, 0x8($s1)
    ctx->pc = 0x16f1c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 9); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f1cc: 0x68670007  ldl         $a3, 0x7($v1)
    ctx->pc = 0x16f1ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x16f1d0: 0x6c670000  ldr         $a3, 0x0($v1)
    ctx->pc = 0x16f1d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x16f1d4: 0x6868000f  ldl         $t0, 0xF($v1)
    ctx->pc = 0x16f1d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x16f1d8: 0x6c680008  ldr         $t0, 0x8($v1)
    ctx->pc = 0x16f1d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x16f1dc: 0xb2270017  sdl         $a3, 0x17($s1)
    ctx->pc = 0x16f1dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f1e0: 0xb6270010  sdr         $a3, 0x10($s1)
    ctx->pc = 0x16f1e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f1e4: 0xb228001f  sdl         $t0, 0x1F($s1)
    ctx->pc = 0x16f1e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16f1e8: 0xb6280018  sdr         $t0, 0x18($s1)
    ctx->pc = 0x16f1e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
label_16f1ec:
    // 0x16f1ec: 0x8d430008  lw          $v1, 0x8($t2)
    ctx->pc = 0x16f1ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 8)));
    // 0x16f1f0: 0x2544002c  addiu       $a0, $t2, 0x2C
    ctx->pc = 0x16f1f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 10), 44));
    // 0x16f1f4: 0xae20002c  sw          $zero, 0x2C($s1)
    ctx->pc = 0x16f1f4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 0));
    // 0x16f1f8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16f1f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f1fc: 0xae200028  sw          $zero, 0x28($s1)
    ctx->pc = 0x16f1fcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 0));
    // 0x16f200: 0xae230020  sw          $v1, 0x20($s1)
    ctx->pc = 0x16f200u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 3));
    // 0x16f204: 0xae240024  sw          $a0, 0x24($s1)
    ctx->pc = 0x16f204u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 4));
    // 0x16f208: 0xaea00024  sw          $zero, 0x24($s5)
    ctx->pc = 0x16f208u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 36), GPR_U32(ctx, 0));
label_16f20c:
    // 0x16f20c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16f20cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16f210: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16f210u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16f214: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16f214u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16f218: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16f218u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16f21c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x16f21cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16f220: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x16f220u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16f224: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16f224u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16f228: 0x3e00008  jr          $ra
    ctx->pc = 0x16F228u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16F22Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F228u;
            // 0x16f22c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16EF60u: goto label_16ef60;
            case 0x16EF68u: goto label_16ef68;
            case 0x16EF80u: goto label_16ef80;
            case 0x16EF9Cu: goto label_16ef9c;
            case 0x16EFF8u: goto label_16eff8;
            case 0x16EFFCu: goto label_16effc;
            case 0x16F034u: goto label_16f034;
            case 0x16F08Cu: goto label_16f08c;
            case 0x16F0A4u: goto label_16f0a4;
            case 0x16F168u: goto label_16f168;
            case 0x16F194u: goto label_16f194;
            case 0x16F1ECu: goto label_16f1ec;
            case 0x16F20Cu: goto label_16f20c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16F230u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
