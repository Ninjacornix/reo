#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165CB0
// Address: 0x165cb0 - 0x165d80
void sub_00165CB0_0x165cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165CB0_0x165cb0");
#endif

    switch (ctx->pc) {
        case 0x165d20u: goto label_165d20;
        case 0x165d34u: goto label_165d34;
        case 0x165d48u: goto label_165d48;
        case 0x165d50u: goto label_165d50;
        case 0x165d64u: goto label_165d64;
        default: break;
    }

    ctx->pc = 0x165cb0u;

    // 0x165cb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x165cb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x165cb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x165cb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165cb8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x165cb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x165cbc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x165cbcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165cc0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x165cc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x165cc4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x165cc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x165cc8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x165cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x165ccc: 0x8e231b74  lw          $v1, 0x1B74($s1)
    ctx->pc = 0x165cccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 7028)));
    // 0x165cd0: 0x8c700000  lw          $s0, 0x0($v1)
    ctx->pc = 0x165cd0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x165cd4: 0x12000024  beqz        $s0, . + 4 + (0x24 << 2)
    ctx->pc = 0x165CD4u;
    {
        const bool branch_taken_0x165cd4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x165CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165CD4u;
            // 0x165cd8: 0x8c720004  lw          $s2, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165cd4) {
            ctx->pc = 0x165D68u;
            goto label_165d68;
        }
    }
    ctx->pc = 0x165CDCu;
    // 0x165cdc: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x165cdcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x165ce0: 0x24470750  addiu       $a3, $v0, 0x750
    ctx->pc = 0x165ce0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 1872));
    // 0x165ce4: 0x6864000f  ldl         $a0, 0xF($v1)
    ctx->pc = 0x165ce4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x165ce8: 0x6c640008  ldr         $a0, 0x8($v1)
    ctx->pc = 0x165ce8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x165cec: 0x68650017  ldl         $a1, 0x17($v1)
    ctx->pc = 0x165cecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x165cf0: 0x6c650010  ldr         $a1, 0x10($v1)
    ctx->pc = 0x165cf0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x165cf4: 0x6866001f  ldl         $a2, 0x1F($v1)
    ctx->pc = 0x165cf4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x165cf8: 0x6c660018  ldr         $a2, 0x18($v1)
    ctx->pc = 0x165cf8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x165cfc: 0xb0e40007  sdl         $a0, 0x7($a3)
    ctx->pc = 0x165cfcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165d00: 0xb4e40000  sdr         $a0, 0x0($a3)
    ctx->pc = 0x165d00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165d04: 0xb0e5000f  sdl         $a1, 0xF($a3)
    ctx->pc = 0x165d04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165d08: 0xb4e50008  sdr         $a1, 0x8($a3)
    ctx->pc = 0x165d08u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165d0c: 0xb0e60017  sdl         $a2, 0x17($a3)
    ctx->pc = 0x165d0cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165d10: 0xb4e60010  sdr         $a2, 0x10($a3)
    ctx->pc = 0x165d10u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x165d14: 0x8c640020  lw          $a0, 0x20($v1)
    ctx->pc = 0x165d14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x165d18: 0xc05cf00  jal         func_173C00
    ctx->pc = 0x165D18u;
    SET_GPR_U32(ctx, 31, 0x165D20u);
    ctx->pc = 0x165D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165D18u;
            // 0x165d1c: 0xace40018  sw          $a0, 0x18($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 24), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173C00u;
    if (runtime->hasFunction(0x173C00u)) {
        auto targetFn = runtime->lookupFunction(0x173C00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D20u; }
        if (ctx->pc != 0x165D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173C00_0x173c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D20u; }
        if (ctx->pc != 0x165D20u) { return; }
    }
    ctx->pc = 0x165D20u;
label_165d20:
    // 0x165d20: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x165d20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x165d24: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x165D24u;
    {
        const bool branch_taken_0x165d24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x165D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165D24u;
            // 0x165d28: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165d24) {
            ctx->pc = 0x165D40u;
            goto label_165d40;
        }
    }
    ctx->pc = 0x165D2Cu;
    // 0x165d2c: 0xc059760  jal         func_165D80
    ctx->pc = 0x165D2Cu;
    SET_GPR_U32(ctx, 31, 0x165D34u);
    ctx->pc = 0x165D30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165D2Cu;
            // 0x165d30: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165D80u;
    if (runtime->hasFunction(0x165D80u)) {
        auto targetFn = runtime->lookupFunction(0x165D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D34u; }
        if (ctx->pc != 0x165D34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165D80_0x165d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D34u; }
        if (ctx->pc != 0x165D34u) { return; }
    }
    ctx->pc = 0x165D34u;
label_165d34:
    // 0x165d34: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x165D34u;
    {
        const bool branch_taken_0x165d34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x165D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165D34u;
            // 0x165d38: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165d34) {
            ctx->pc = 0x165D54u;
            goto label_165d54;
        }
    }
    ctx->pc = 0x165D3Cu;
    // 0x165d3c: 0x0  nop
    ctx->pc = 0x165d3cu;
    // NOP
label_165d40:
    // 0x165d40: 0xc059776  jal         func_165DD8
    ctx->pc = 0x165D40u;
    SET_GPR_U32(ctx, 31, 0x165D48u);
    ctx->pc = 0x165DD8u;
    if (runtime->hasFunction(0x165DD8u)) {
        auto targetFn = runtime->lookupFunction(0x165DD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D48u; }
        if (ctx->pc != 0x165D48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165DD8_0x165dd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D48u; }
        if (ctx->pc != 0x165D48u) { return; }
    }
    ctx->pc = 0x165D48u;
label_165d48:
    // 0x165d48: 0xc059768  jal         func_165DA0
    ctx->pc = 0x165D48u;
    SET_GPR_U32(ctx, 31, 0x165D50u);
    ctx->pc = 0x165D4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165D48u;
            // 0x165d4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165DA0u;
    if (runtime->hasFunction(0x165DA0u)) {
        auto targetFn = runtime->lookupFunction(0x165DA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D50u; }
        if (ctx->pc != 0x165D50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165DA0_0x165da0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165D50u; }
        if (ctx->pc != 0x165D50u) { return; }
    }
    ctx->pc = 0x165D50u;
label_165d50:
    // 0x165d50: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x165d50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_165d54:
    // 0x165d54: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x165d54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x165d58: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x165d58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x165d5c: 0x40f809  jalr        $v0
    ctx->pc = 0x165D5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x165D64u);
        ctx->pc = 0x165D60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165D5Cu;
            // 0x165d60: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x165D64u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165D20u: goto label_165d20;
            case 0x165D34u: goto label_165d34;
            case 0x165D40u: goto label_165d40;
            case 0x165D48u: goto label_165d48;
            case 0x165D50u: goto label_165d50;
            case 0x165D54u: goto label_165d54;
            case 0x165D64u: goto label_165d64;
            case 0x165D68u: goto label_165d68;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x165D64u; }
            if (ctx->pc != 0x165D64u) { return; }
        }
        }
    }
    ctx->pc = 0x165D64u;
label_165d64:
    // 0x165d64: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x165d64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_165d68:
    // 0x165d68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x165d68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165d6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x165d6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x165d70: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x165d70u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165d74: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x165d74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x165d78: 0x3e00008  jr          $ra
    ctx->pc = 0x165D78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165D78u;
            // 0x165d7c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165D20u: goto label_165d20;
            case 0x165D34u: goto label_165d34;
            case 0x165D40u: goto label_165d40;
            case 0x165D48u: goto label_165d48;
            case 0x165D50u: goto label_165d50;
            case 0x165D54u: goto label_165d54;
            case 0x165D64u: goto label_165d64;
            case 0x165D68u: goto label_165d68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165D80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
