#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170268
// Address: 0x170268 - 0x170358
void sub_00170268_0x170268(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170268_0x170268");
#endif

    switch (ctx->pc) {
        case 0x170290u: goto label_170290;
        case 0x170318u: goto label_170318;
        case 0x170330u: goto label_170330;
        default: break;
    }

    ctx->pc = 0x170268u;

    // 0x170268: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x170268u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x17026c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x17026cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x170270: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x170270u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170274: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x170274u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x170278: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x170278u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17027c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x17027cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x170280: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x170280u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170284: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x170284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x170288: 0xc05c0d6  jal         func_170358
    ctx->pc = 0x170288u;
    SET_GPR_U32(ctx, 31, 0x170290u);
    ctx->pc = 0x17028Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170288u;
            // 0x17028c: 0xae400000  sw          $zero, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170358u;
    if (runtime->hasFunction(0x170358u)) {
        auto targetFn = runtime->lookupFunction(0x170358u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170290u; }
        if (ctx->pc != 0x170290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170358_0x170358(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170290u; }
        if (ctx->pc != 0x170290u) { return; }
    }
    ctx->pc = 0x170290u;
label_170290:
    // 0x170290: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x170290u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170294: 0x5080002b  beql        $a0, $zero, . + 4 + (0x2B << 2)
    ctx->pc = 0x170294u;
    {
        const bool branch_taken_0x170294 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x170294) {
            ctx->pc = 0x170298u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x170294u;
            // 0x170298: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x170344u;
            goto label_170344;
        }
    }
    ctx->pc = 0x17029Cu;
    // 0x17029c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x17029cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1702a0: 0x10600027  beqz        $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1702A0u;
    {
        const bool branch_taken_0x1702a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1702A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1702A0u;
            // 0x1702a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1702a0) {
            ctx->pc = 0x170340u;
            goto label_170340;
        }
    }
    ctx->pc = 0x1702A8u;
    // 0x1702a8: 0x68820013  ldl         $v0, 0x13($a0)
    ctx->pc = 0x1702a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 19); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1702ac: 0x6c82000c  ldr         $v0, 0xC($a0)
    ctx->pc = 0x1702acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 12); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1702b0: 0x6883001b  ldl         $v1, 0x1B($a0)
    ctx->pc = 0x1702b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 27); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1702b4: 0x6c830014  ldr         $v1, 0x14($a0)
    ctx->pc = 0x1702b4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 20); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1702b8: 0x68850023  ldl         $a1, 0x23($a0)
    ctx->pc = 0x1702b8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 35); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x1702bc: 0x6c85001c  ldr         $a1, 0x1C($a0)
    ctx->pc = 0x1702bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 28); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x1702c0: 0x6886002b  ldl         $a2, 0x2B($a0)
    ctx->pc = 0x1702c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 43); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x1702c4: 0x6c860024  ldr         $a2, 0x24($a0)
    ctx->pc = 0x1702c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 36); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x1702c8: 0xb2220ce3  sdl         $v0, 0xCE3($s1)
    ctx->pc = 0x1702c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3299); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702cc: 0xb6220cdc  sdr         $v0, 0xCDC($s1)
    ctx->pc = 0x1702ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3292); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702d0: 0xb2230ceb  sdl         $v1, 0xCEB($s1)
    ctx->pc = 0x1702d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3307); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702d4: 0xb6230ce4  sdr         $v1, 0xCE4($s1)
    ctx->pc = 0x1702d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3300); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702d8: 0xb2250cf3  sdl         $a1, 0xCF3($s1)
    ctx->pc = 0x1702d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3315); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702dc: 0xb6250cec  sdr         $a1, 0xCEC($s1)
    ctx->pc = 0x1702dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3308); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702e0: 0xb2260cfb  sdl         $a2, 0xCFB($s1)
    ctx->pc = 0x1702e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3323); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702e4: 0xb6260cf4  sdr         $a2, 0xCF4($s1)
    ctx->pc = 0x1702e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3316); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702e8: 0x68820033  ldl         $v0, 0x33($a0)
    ctx->pc = 0x1702e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 51); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x1702ec: 0x6c82002c  ldr         $v0, 0x2C($a0)
    ctx->pc = 0x1702ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 44); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1702f0: 0xb2220d03  sdl         $v0, 0xD03($s1)
    ctx->pc = 0x1702f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3331); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702f4: 0xb6220cfc  sdr         $v0, 0xCFC($s1)
    ctx->pc = 0x1702f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 3324); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1702f8: 0x24830034  addiu       $v1, $a0, 0x34
    ctx->pc = 0x1702f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 52));
    // 0x1702fc: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1702fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x170300: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x170300u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170304: 0x8c620200  lw          $v0, 0x200($v1)
    ctx->pc = 0x170304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 512)));
    // 0x170308: 0x27a60010  addiu       $a2, $sp, 0x10
    ctx->pc = 0x170308u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17030c: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x17030cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x170310: 0xc0565e0  jal         func_159780
    ctx->pc = 0x170310u;
    SET_GPR_U32(ctx, 31, 0x170318u);
    ctx->pc = 0x170314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170310u;
            // 0x170314: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159780u;
    if (runtime->hasFunction(0x159780u)) {
        auto targetFn = runtime->lookupFunction(0x159780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170318u; }
        if (ctx->pc != 0x170318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159780_0x159780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170318u; }
        if (ctx->pc != 0x170318u) { return; }
    }
    ctx->pc = 0x170318u;
label_170318:
    // 0x170318: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x170318u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x17031c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17031cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170320: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x170320u;
    {
        const bool branch_taken_0x170320 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x170324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170320u;
            // 0x170324: 0x34a50f1b  ori         $a1, $a1, 0xF1B (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3867);
        ctx->in_delay_slot = false;
        if (branch_taken_0x170320) {
            ctx->pc = 0x170338u;
            goto label_170338;
        }
    }
    ctx->pc = 0x170328u;
    // 0x170328: 0xc05a704  jal         func_169C10
    ctx->pc = 0x170328u;
    SET_GPR_U32(ctx, 31, 0x170330u);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170330u; }
        if (ctx->pc != 0x170330u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170330u; }
        if (ctx->pc != 0x170330u) { return; }
    }
    ctx->pc = 0x170330u;
label_170330:
    // 0x170330: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x170330u;
    {
        const bool branch_taken_0x170330 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x170334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170330u;
            // 0x170334: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x170330) {
            ctx->pc = 0x170344u;
            goto label_170344;
        }
    }
    ctx->pc = 0x170338u;
label_170338:
    // 0x170338: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x170338u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17033c: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17033cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_170340:
    // 0x170340: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x170340u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_170344:
    // 0x170344: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x170344u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x170348: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x170348u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17034c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x17034cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x170350: 0x3e00008  jr          $ra
    ctx->pc = 0x170350u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170350u;
            // 0x170354: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170290u: goto label_170290;
            case 0x170318u: goto label_170318;
            case 0x170330u: goto label_170330;
            case 0x170338u: goto label_170338;
            case 0x170340u: goto label_170340;
            case 0x170344u: goto label_170344;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170358u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
