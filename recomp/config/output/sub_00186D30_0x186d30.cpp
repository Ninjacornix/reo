#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186D30
// Address: 0x186d30 - 0x186e60
void sub_00186D30_0x186d30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186D30_0x186d30");
#endif

    switch (ctx->pc) {
        case 0x186d60u: goto label_186d60;
        case 0x186d90u: goto label_186d90;
        case 0x186df0u: goto label_186df0;
        case 0x186e40u: goto label_186e40;
        default: break;
    }

    ctx->pc = 0x186d30u;

    // 0x186d30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x186d30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x186d34: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x186d34u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x186d38: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x186d38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x186d3c: 0x3c120029  lui         $s2, 0x29
    ctx->pc = 0x186d3cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)41 << 16));
    // 0x186d40: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x186d40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x186d44: 0x2650b0c0  addiu       $s0, $s2, -0x4F40
    ctx->pc = 0x186d44u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294947008));
    // 0x186d48: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x186d48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x186d4c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x186d4cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186d50: 0x24060800  addiu       $a2, $zero, 0x800
    ctx->pc = 0x186d50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x186d54: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x186d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x186d58: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x186D58u;
    SET_GPR_U32(ctx, 31, 0x186D60u);
    ctx->pc = 0x186D5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186D58u;
            // 0x186d5c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186D60u; }
        if (ctx->pc != 0x186D60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186D60u; }
        if (ctx->pc != 0x186D60u) { return; }
    }
    ctx->pc = 0x186D60u;
label_186d60:
    // 0x186d60: 0x111840  sll         $v1, $s1, 1
    ctx->pc = 0x186d60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x186d64: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x186d64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x186d68: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x186d68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x186d6c: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x186d6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x186d70: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x186d70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x186d74: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x186d74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x186d78: 0x2421fa18  addiu       $at, $at, -0x5E8
    ctx->pc = 0x186d78u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294965784));
    // 0x186d7c: 0x231821  addu        $v1, $at, $v1
    ctx->pc = 0x186d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x186d80: 0x701025  or          $v0, $v1, $s0
    ctx->pc = 0x186d80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 16));
    // 0x186d84: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x186d84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x186d88: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x186D88u;
    {
        const bool branch_taken_0x186d88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x186D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186D88u;
            // 0x186d8c: 0x24620180  addiu       $v0, $v1, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186d88) {
            ctx->pc = 0x186DF0u;
            goto label_186df0;
        }
    }
    ctx->pc = 0x186D90u;
label_186d90:
    // 0x186d90: 0x68640007  ldl         $a0, 0x7($v1)
    ctx->pc = 0x186d90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x186d94: 0x6c640000  ldr         $a0, 0x0($v1)
    ctx->pc = 0x186d94u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x186d98: 0x6865000f  ldl         $a1, 0xF($v1)
    ctx->pc = 0x186d98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x186d9c: 0x6c650008  ldr         $a1, 0x8($v1)
    ctx->pc = 0x186d9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x186da0: 0x68660017  ldl         $a2, 0x17($v1)
    ctx->pc = 0x186da0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x186da4: 0x6c660010  ldr         $a2, 0x10($v1)
    ctx->pc = 0x186da4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x186da8: 0x6867001f  ldl         $a3, 0x1F($v1)
    ctx->pc = 0x186da8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x186dac: 0x6c670018  ldr         $a3, 0x18($v1)
    ctx->pc = 0x186dacu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x186db0: 0xb2040007  sdl         $a0, 0x7($s0)
    ctx->pc = 0x186db0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186db4: 0xb6040000  sdr         $a0, 0x0($s0)
    ctx->pc = 0x186db4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186db8: 0xb205000f  sdl         $a1, 0xF($s0)
    ctx->pc = 0x186db8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186dbc: 0xb6050008  sdr         $a1, 0x8($s0)
    ctx->pc = 0x186dbcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186dc0: 0xb2060017  sdl         $a2, 0x17($s0)
    ctx->pc = 0x186dc0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186dc4: 0xb6060010  sdr         $a2, 0x10($s0)
    ctx->pc = 0x186dc4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186dc8: 0xb207001f  sdl         $a3, 0x1F($s0)
    ctx->pc = 0x186dc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186dcc: 0xb6070018  sdr         $a3, 0x18($s0)
    ctx->pc = 0x186dccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x186dd0: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x186dd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x186dd4: 0x0  nop
    ctx->pc = 0x186dd4u;
    // NOP
    // 0x186dd8: 0x0  nop
    ctx->pc = 0x186dd8u;
    // NOP
    // 0x186ddc: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x186DDCu;
    {
        const bool branch_taken_0x186ddc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x186DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186DDCu;
            // 0x186de0: 0x26100020  addiu       $s0, $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186ddc) {
            ctx->pc = 0x186D90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186d90;
        }
    }
    ctx->pc = 0x186DE4u;
    // 0x186de4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x186DE4u;
    {
        const bool branch_taken_0x186de4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x186de4) {
            ctx->pc = 0x186E24u;
            goto label_186e24;
        }
    }
    ctx->pc = 0x186DECu;
    // 0x186dec: 0x0  nop
    ctx->pc = 0x186decu;
    // NOP
label_186df0:
    // 0x186df0: 0xdc680000  ld          $t0, 0x0($v1)
    ctx->pc = 0x186df0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x186df4: 0xdc690008  ld          $t1, 0x8($v1)
    ctx->pc = 0x186df4u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x186df8: 0xdc6a0010  ld          $t2, 0x10($v1)
    ctx->pc = 0x186df8u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x186dfc: 0xdc640018  ld          $a0, 0x18($v1)
    ctx->pc = 0x186dfcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x186e00: 0xfe080000  sd          $t0, 0x0($s0)
    ctx->pc = 0x186e00u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 0), GPR_U64(ctx, 8));
    // 0x186e04: 0xfe090008  sd          $t1, 0x8($s0)
    ctx->pc = 0x186e04u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 8), GPR_U64(ctx, 9));
    // 0x186e08: 0xfe0a0010  sd          $t2, 0x10($s0)
    ctx->pc = 0x186e08u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 16), GPR_U64(ctx, 10));
    // 0x186e0c: 0xfe040018  sd          $a0, 0x18($s0)
    ctx->pc = 0x186e0cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 24), GPR_U64(ctx, 4));
    // 0x186e10: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x186e10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x186e14: 0x0  nop
    ctx->pc = 0x186e14u;
    // NOP
    // 0x186e18: 0x0  nop
    ctx->pc = 0x186e18u;
    // NOP
    // 0x186e1c: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x186E1Cu;
    {
        const bool branch_taken_0x186e1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x186E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186E1Cu;
            // 0x186e20: 0x26100020  addiu       $s0, $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x186e1c) {
            ctx->pc = 0x186DF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_186df0;
        }
    }
    ctx->pc = 0x186E24u;
label_186e24:
    // 0x186e24: 0x8c680000  lw          $t0, 0x0($v1)
    ctx->pc = 0x186e24u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x186e28: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x186e28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186e2c: 0x2645b0c0  addiu       $a1, $s2, -0x4F40
    ctx->pc = 0x186e2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 4294947008));
    // 0x186e30: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x186e30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186e34: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x186e34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x186e38: 0xc0620d2  jal         func_188348
    ctx->pc = 0x186E38u;
    SET_GPR_U32(ctx, 31, 0x186E40u);
    ctx->pc = 0x186E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186E38u;
            // 0x186e3c: 0xae080000  sw          $t0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188348u;
    if (runtime->hasFunction(0x188348u)) {
        auto targetFn = runtime->lookupFunction(0x188348u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186E40u; }
        if (ctx->pc != 0x186E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188348_0x188348(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x186E40u; }
        if (ctx->pc != 0x186E40u) { return; }
    }
    ctx->pc = 0x186E40u;
label_186e40:
    // 0x186e40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x186e40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x186e44: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x186e44u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x186e48: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x186e48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x186e4c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x186e4cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x186e50: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x186e50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x186e54: 0x3e00008  jr          $ra
    ctx->pc = 0x186E54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x186E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x186E54u;
            // 0x186e58: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x186D60u: goto label_186d60;
            case 0x186D90u: goto label_186d90;
            case 0x186DF0u: goto label_186df0;
            case 0x186E24u: goto label_186e24;
            case 0x186E40u: goto label_186e40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x186E5Cu;
    // 0x186e5c: 0x0  nop
    ctx->pc = 0x186e5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
