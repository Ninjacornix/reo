#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00157DD0
// Address: 0x157dd0 - 0x157e40
void sub_00157DD0_0x157dd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00157DD0_0x157dd0");
#endif

    switch (ctx->pc) {
        case 0x157decu: goto label_157dec;
        default: break;
    }

    ctx->pc = 0x157dd0u;

    // 0x157dd0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x157dd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x157dd4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x157dd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x157dd8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x157dd8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x157ddc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x157ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x157de0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x157de0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x157de4: 0xc0560f2  jal         func_1583C8
    ctx->pc = 0x157DE4u;
    SET_GPR_U32(ctx, 31, 0x157DECu);
    ctx->pc = 0x157DE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x157DE4u;
            // 0x157de8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1583C8u;
    if (runtime->hasFunction(0x1583C8u)) {
        auto targetFn = runtime->lookupFunction(0x1583C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x157DECu; }
        if (ctx->pc != 0x157DECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583C8_0x1583c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x157DECu; }
        if (ctx->pc != 0x157DECu) { return; }
    }
    ctx->pc = 0x157DECu;
label_157dec:
    // 0x157dec: 0x3c05ff02  lui         $a1, 0xFF02
    ctx->pc = 0x157decu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65282 << 16));
    // 0x157df0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x157DF0u;
    {
        const bool branch_taken_0x157df0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x157DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157DF0u;
            // 0x157df4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157df0) {
            ctx->pc = 0x157E10u;
            goto label_157e10;
        }
    }
    ctx->pc = 0x157DF8u;
    // 0x157df8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x157df8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x157dfc: 0x34a50201  ori         $a1, $a1, 0x201
    ctx->pc = 0x157dfcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)513);
    // 0x157e00: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x157e00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x157e04: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x157e04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x157e08: 0x805607e  j           func_1581F8
    ctx->pc = 0x157E08u;
    ctx->pc = 0x157E0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x157E08u;
            // 0x157e0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581F8u;
    if (runtime->hasFunction(0x1581F8u)) {
        auto targetFn = runtime->lookupFunction(0x1581F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001581F8_0x1581f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x157E10u;
label_157e10:
    // 0x157e10: 0x6a03001b  ldl         $v1, 0x1B($s0)
    ctx->pc = 0x157e10u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x157e14: 0x6e030014  ldr         $v1, 0x14($s0)
    ctx->pc = 0x157e14u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x157e18: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x157e18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x157e1c: 0xb2230007  sdl         $v1, 0x7($s1)
    ctx->pc = 0x157e1cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157e20: 0xb6230000  sdr         $v1, 0x0($s1)
    ctx->pc = 0x157e20u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x157e24: 0xae240008  sw          $a0, 0x8($s1)
    ctx->pc = 0x157e24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 4));
    // 0x157e28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x157e28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x157e2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x157e2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x157e30: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x157e30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x157e34: 0x3e00008  jr          $ra
    ctx->pc = 0x157E34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157E38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157E34u;
            // 0x157e38: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x157DECu: goto label_157dec;
            case 0x157E10u: goto label_157e10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157E3Cu;
    // 0x157e3c: 0x0  nop
    ctx->pc = 0x157e3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
