#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158318
// Address: 0x158318 - 0x1583c8
void sub_00158318_0x158318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158318_0x158318");
#endif

    switch (ctx->pc) {
        case 0x158370u: goto label_158370;
        default: break;
    }

    ctx->pc = 0x158318u;

    // 0x158318: 0xac860004  sw          $a2, 0x4($a0)
    ctx->pc = 0x158318u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
    // 0x15831c: 0x3e00008  jr          $ra
    ctx->pc = 0x15831Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15831Cu;
            // 0x158320: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158368u: goto label_158368;
            case 0x158370u: goto label_158370;
            case 0x158398u: goto label_158398;
            case 0x1583B0u: goto label_1583b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158324u;
    // 0x158324: 0x0  nop
    ctx->pc = 0x158324u;
    // NOP
    // 0x158328: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x158328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15832c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15832cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158330: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x158330u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158334: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x158334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x158338: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x158338u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15833c: 0x1600000a  bnez        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x15833Cu;
    {
        const bool branch_taken_0x15833c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x158340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15833Cu;
            // 0x158340: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15833c) {
            ctx->pc = 0x158368u;
            goto label_158368;
        }
    }
    ctx->pc = 0x158344u;
    // 0x158344: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x158344u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x158348: 0x8c43d870  lw          $v1, -0x2790($v0)
    ctx->pc = 0x158348u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957168)));
    // 0x15834c: 0x68620007  ldl         $v0, 0x7($v1)
    ctx->pc = 0x15834cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x158350: 0x6c620000  ldr         $v0, 0x0($v1)
    ctx->pc = 0x158350u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x158354: 0x8c640008  lw          $a0, 0x8($v1)
    ctx->pc = 0x158354u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x158358: 0xb2220007  sdl         $v0, 0x7($s1)
    ctx->pc = 0x158358u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x15835c: 0xb6220000  sdr         $v0, 0x0($s1)
    ctx->pc = 0x15835cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x158360: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x158360u;
    {
        const bool branch_taken_0x158360 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158360u;
            // 0x158364: 0xae240008  sw          $a0, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158360) {
            ctx->pc = 0x1583B0u;
            goto label_1583b0;
        }
    }
    ctx->pc = 0x158368u;
label_158368:
    // 0x158368: 0xc0560f2  jal         func_1583C8
    ctx->pc = 0x158368u;
    SET_GPR_U32(ctx, 31, 0x158370u);
    ctx->pc = 0x1583C8u;
    if (runtime->hasFunction(0x1583C8u)) {
        auto targetFn = runtime->lookupFunction(0x1583C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158370u; }
        if (ctx->pc != 0x158370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583C8_0x1583c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158370u; }
        if (ctx->pc != 0x158370u) { return; }
    }
    ctx->pc = 0x158370u;
label_158370:
    // 0x158370: 0x3c05ff02  lui         $a1, 0xFF02
    ctx->pc = 0x158370u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65282 << 16));
    // 0x158374: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x158374u;
    {
        const bool branch_taken_0x158374 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x158378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158374u;
            // 0x158378: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158374) {
            ctx->pc = 0x158398u;
            goto label_158398;
        }
    }
    ctx->pc = 0x15837Cu;
    // 0x15837c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15837cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x158380: 0x34a50102  ori         $a1, $a1, 0x102
    ctx->pc = 0x158380u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)258);
    // 0x158384: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x158384u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x158388: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x158388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15838c: 0x805607e  j           func_1581F8
    ctx->pc = 0x15838Cu;
    ctx->pc = 0x158390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15838Cu;
            // 0x158390: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581F8u;
    if (runtime->hasFunction(0x1581F8u)) {
        auto targetFn = runtime->lookupFunction(0x1581F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001581F8_0x1581f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x158394u;
    // 0x158394: 0x0  nop
    ctx->pc = 0x158394u;
    // NOP
label_158398:
    // 0x158398: 0x6a02000b  ldl         $v0, 0xB($s0)
    ctx->pc = 0x158398u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x15839c: 0x6e020004  ldr         $v0, 0x4($s0)
    ctx->pc = 0x15839cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 4); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x1583a0: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x1583a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1583a4: 0xb2220007  sdl         $v0, 0x7($s1)
    ctx->pc = 0x1583a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1583a8: 0xb6220000  sdr         $v0, 0x0($s1)
    ctx->pc = 0x1583a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1583ac: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x1583acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
label_1583b0:
    // 0x1583b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1583b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1583b4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1583b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1583b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1583b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1583bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1583bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1583c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1583C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1583C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1583C0u;
            // 0x1583c4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158368u: goto label_158368;
            case 0x158370u: goto label_158370;
            case 0x158398u: goto label_158398;
            case 0x1583B0u: goto label_1583b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1583C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
