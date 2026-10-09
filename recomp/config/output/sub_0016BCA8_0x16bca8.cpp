#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016BCA8
// Address: 0x16bca8 - 0x16be38
void sub_0016BCA8_0x16bca8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016BCA8_0x16bca8");
#endif

    switch (ctx->pc) {
        case 0x16bd18u: goto label_16bd18;
        case 0x16bd58u: goto label_16bd58;
        default: break;
    }

    ctx->pc = 0x16bca8u;

    // 0x16bca8: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16bca8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x16bcac: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x16bcacu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bcb0: 0x24426068  addiu       $v0, $v0, 0x6068
    ctx->pc = 0x16bcb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24680));
    // 0x16bcb4: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x16bcb4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x16bcb8: 0x69240007  ldl         $a0, 0x7($t1)
    ctx->pc = 0x16bcb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x16bcbc: 0x6d240000  ldr         $a0, 0x0($t1)
    ctx->pc = 0x16bcbcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x16bcc0: 0x6927000f  ldl         $a3, 0xF($t1)
    ctx->pc = 0x16bcc0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x16bcc4: 0x6d270008  ldr         $a3, 0x8($t1)
    ctx->pc = 0x16bcc4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x16bcc8: 0x69280017  ldl         $t0, 0x17($t1)
    ctx->pc = 0x16bcc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x16bccc: 0x6d280010  ldr         $t0, 0x10($t1)
    ctx->pc = 0x16bcccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x16bcd0: 0x692a001f  ldl         $t2, 0x1F($t1)
    ctx->pc = 0x16bcd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem << shift)); }
    // 0x16bcd4: 0x6d2a0018  ldr         $t2, 0x18($t1)
    ctx->pc = 0x16bcd4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 9), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 10, (GPR_U64(ctx, 10) & keepMask) | (mem >> shift)); }
    // 0x16bcd8: 0xb0440007  sdl         $a0, 0x7($v0)
    ctx->pc = 0x16bcd8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16bcdc: 0xb4440000  sdr         $a0, 0x0($v0)
    ctx->pc = 0x16bcdcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16bce0: 0xb047000f  sdl         $a3, 0xF($v0)
    ctx->pc = 0x16bce0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16bce4: 0xb4470008  sdr         $a3, 0x8($v0)
    ctx->pc = 0x16bce4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16bce8: 0xb0480017  sdl         $t0, 0x17($v0)
    ctx->pc = 0x16bce8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16bcec: 0xb4480010  sdr         $t0, 0x10($v0)
    ctx->pc = 0x16bcecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16bcf0: 0xb04a001f  sdl         $t2, 0x1F($v0)
    ctx->pc = 0x16bcf0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16bcf4: 0xb44a0018  sdr         $t2, 0x18($v0)
    ctx->pc = 0x16bcf4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 10); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16bcf8: 0x8d240020  lw          $a0, 0x20($t1)
    ctx->pc = 0x16bcf8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 32)));
    // 0x16bcfc: 0x246b6090  addiu       $t3, $v1, 0x6090
    ctx->pc = 0x16bcfcu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 3), 24720));
    // 0x16bd00: 0xac440020  sw          $a0, 0x20($v0)
    ctx->pc = 0x16bd00u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 4));
    // 0x16bd04: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x16bd04u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bd08: 0xac400020  sw          $zero, 0x20($v0)
    ctx->pc = 0x16bd08u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 0));
    // 0x16bd0c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x16bd0cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bd10: 0xac400010  sw          $zero, 0x10($v0)
    ctx->pc = 0x16bd10u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 0));
    // 0x16bd14: 0x240affc0  addiu       $t2, $zero, -0x40
    ctx->pc = 0x16bd14u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
label_16bd18:
    // 0x16bd18: 0x72080  sll         $a0, $a3, 2
    ctx->pc = 0x16bd18u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x16bd1c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x16bd1cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x16bd20: 0x881821  addu        $v1, $a0, $t0
    ctx->pc = 0x16bd20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
    // 0x16bd24: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x16bd24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x16bd28: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x16bd28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x16bd2c: 0x28e50002  slti        $a1, $a3, 0x2
    ctx->pc = 0x16bd2cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x16bd30: 0x2442003f  addiu       $v0, $v0, 0x3F
    ctx->pc = 0x16bd30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x16bd34: 0x4a1024  and         $v0, $v0, $t2
    ctx->pc = 0x16bd34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 10));
    // 0x16bd38: 0x14a0fff7  bnez        $a1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x16BD38u;
    {
        const bool branch_taken_0x16bd38 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x16BD3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BD38u;
            // 0x16bd3c: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bd38) {
            ctx->pc = 0x16BD18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16bd18;
        }
    }
    ctx->pc = 0x16BD40u;
    // 0x16bd40: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16bd40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x16bd44: 0x8d24001c  lw          $a0, 0x1C($t1)
    ctx->pc = 0x16bd44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 28)));
    // 0x16bd48: 0x24456098  addiu       $a1, $v0, 0x6098
    ctx->pc = 0x16bd48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 24728));
    // 0x16bd4c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x16bd4cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bd50: 0x240affc0  addiu       $t2, $zero, -0x40
    ctx->pc = 0x16bd50u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x16bd54: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x16bd54u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16bd58:
    // 0x16bd58: 0xe4102a  slt         $v0, $a3, $a0
    ctx->pc = 0x16bd58u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x16bd5c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x16bd5cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x16bd60: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16BD60u;
    {
        const bool branch_taken_0x16bd60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BD64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BD60u;
            // 0x16bd64: 0x28e80010  slti        $t0, $a3, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 8, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)16) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bd60) {
            ctx->pc = 0x16BD80u;
            goto label_16bd80;
        }
    }
    ctx->pc = 0x16BD68u;
    // 0x16bd68: 0x1261821  addu        $v1, $t1, $a2
    ctx->pc = 0x16bd68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 6)));
    // 0x16bd6c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x16bd6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x16bd70: 0x2442003f  addiu       $v0, $v0, 0x3F
    ctx->pc = 0x16bd70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x16bd74: 0x4a1024  and         $v0, $v0, $t2
    ctx->pc = 0x16bd74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 10));
    // 0x16bd78: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x16BD78u;
    {
        const bool branch_taken_0x16bd78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16BD7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BD78u;
            // 0x16bd7c: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bd78) {
            ctx->pc = 0x16BD84u;
            goto label_16bd84;
        }
    }
    ctx->pc = 0x16BD80u;
label_16bd80:
    // 0x16bd80: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x16bd80u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
label_16bd84:
    // 0x16bd84: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x16bd84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x16bd88: 0x1500fff3  bnez        $t0, . + 4 + (-0xD << 2)
    ctx->pc = 0x16BD88u;
    {
        const bool branch_taken_0x16bd88 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x16BD8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BD88u;
            // 0x16bd8c: 0x25290004  addiu       $t1, $t1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16bd88) {
            ctx->pc = 0x16BD58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16bd58;
        }
    }
    ctx->pc = 0x16BD90u;
    // 0x16bd90: 0x3e00008  jr          $ra
    ctx->pc = 0x16BD90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BD18u: goto label_16bd18;
            case 0x16BD58u: goto label_16bd58;
            case 0x16BD80u: goto label_16bd80;
            case 0x16BD84u: goto label_16bd84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BD98u;
    // 0x16bd98: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x16bd98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x16bd9c: 0x8c8a0004  lw          $t2, 0x4($a0)
    ctx->pc = 0x16bd9cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x16bda0: 0x2462000f  addiu       $v0, $v1, 0xF
    ctx->pc = 0x16bda0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x16bda4: 0x2463001e  addiu       $v1, $v1, 0x1E
    ctx->pc = 0x16bda4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 30));
    // 0x16bda8: 0x28460000  slti        $a2, $v0, 0x0
    ctx->pc = 0x16bda8u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16bdac: 0x2549000f  addiu       $t1, $t2, 0xF
    ctx->pc = 0x16bdacu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 10), 15));
    // 0x16bdb0: 0x66100b  movn        $v0, $v1, $a2
    ctx->pc = 0x16bdb0u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x16bdb4: 0x292b0000  slti        $t3, $t1, 0x0
    ctx->pc = 0x16bdb4u;
    SET_GPR_U64(ctx, 11, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16bdb8: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x16bdb8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x16bdbc: 0x254a001e  addiu       $t2, $t2, 0x1E
    ctx->pc = 0x16bdbcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 30));
    // 0x16bdc0: 0x24100  sll         $t0, $v0, 4
    ctx->pc = 0x16bdc0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x16bdc4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x16bdc4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x16bdc8: 0x2507003f  addiu       $a3, $t0, 0x3F
    ctx->pc = 0x16bdc8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 8), 63));
    // 0x16bdcc: 0x2508007e  addiu       $t0, $t0, 0x7E
    ctx->pc = 0x16bdccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 126));
    // 0x16bdd0: 0x2446003f  addiu       $a2, $v0, 0x3F
    ctx->pc = 0x16bdd0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 63));
    // 0x16bdd4: 0x2442007e  addiu       $v0, $v0, 0x7E
    ctx->pc = 0x16bdd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 126));
    // 0x16bdd8: 0x28e30000  slti        $v1, $a3, 0x0
    ctx->pc = 0x16bdd8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16bddc: 0x14b480b  movn        $t1, $t2, $t3
    ctx->pc = 0x16bddcu;
    if (GPR_U64(ctx, 11) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 10));
    // 0x16bde0: 0x103380b  movn        $a3, $t0, $v1
    ctx->pc = 0x16bde0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 8));
    // 0x16bde4: 0x28c30000  slti        $v1, $a2, 0x0
    ctx->pc = 0x16bde4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x16bde8: 0x43300b  movn        $a2, $v0, $v1
    ctx->pc = 0x16bde8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 2));
    // 0x16bdec: 0x8c830020  lw          $v1, 0x20($a0)
    ctx->pc = 0x16bdecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x16bdf0: 0x73983  sra         $a3, $a3, 6
    ctx->pc = 0x16bdf0u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 6));
    // 0x16bdf4: 0x94903  sra         $t1, $t1, 4
    ctx->pc = 0x16bdf4u;
    SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 9), 4));
    // 0x16bdf8: 0xe91018  mult        $v0, $a3, $t1
    ctx->pc = 0x16bdf8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x16bdfc: 0x73980  sll         $a3, $a3, 6
    ctx->pc = 0x16bdfcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 6));
    // 0x16be00: 0x63183  sra         $a2, $a2, 6
    ctx->pc = 0x16be00u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 6));
    // 0x16be04: 0xa4a7000e  sh          $a3, 0xE($a1)
    ctx->pc = 0x16be04u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 14), (uint16_t)GPR_U32(ctx, 7));
    // 0x16be08: 0x70c94818  mult1       $t1, $a2, $t1
    ctx->pc = 0x16be08u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 9); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 9, (int32_t)result); }
    // 0x16be0c: 0x63180  sll         $a2, $a2, 6
    ctx->pc = 0x16be0cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 6));
    // 0x16be10: 0xa4a6000c  sh          $a2, 0xC($a1)
    ctx->pc = 0x16be10u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 12), (uint16_t)GPR_U32(ctx, 6));
    // 0x16be14: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x16be14u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x16be18: 0xaca30008  sw          $v1, 0x8($a1)
    ctx->pc = 0x16be18u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 3));
    // 0x16be1c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x16be1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16be20: 0x94a40  sll         $t1, $t1, 9
    ctx->pc = 0x16be20u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 9));
    // 0x16be24: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x16be24u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x16be28: 0x494821  addu        $t1, $v0, $t1
    ctx->pc = 0x16be28u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x16be2c: 0x3e00008  jr          $ra
    ctx->pc = 0x16BE2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16BE2Cu;
            // 0x16be30: 0xaca90004  sw          $t1, 0x4($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BD18u: goto label_16bd18;
            case 0x16BD58u: goto label_16bd58;
            case 0x16BD80u: goto label_16bd80;
            case 0x16BD84u: goto label_16bd84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BE34u;
    // 0x16be34: 0x0  nop
    ctx->pc = 0x16be34u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
