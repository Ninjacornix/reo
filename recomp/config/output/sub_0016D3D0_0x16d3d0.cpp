#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016D3D0
// Address: 0x16d3d0 - 0x16d460
void sub_0016D3D0_0x16d3d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016D3D0_0x16d3d0");
#endif

    switch (ctx->pc) {
        case 0x16d444u: goto label_16d444;
        default: break;
    }

    ctx->pc = 0x16d3d0u;

    // 0x16d3d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16d3d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16d3d4: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x16d3d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d3d8: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x16d3d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x16d3dc: 0x24b00cdc  addiu       $s0, $a1, 0xCDC
    ctx->pc = 0x16d3dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 5), 3292));
    // 0x16d3e0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x16d3e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x16d3e4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x16d3e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16d3e8: 0x8ca30d04  lw          $v1, 0xD04($a1)
    ctx->pc = 0x16d3e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 3332)));
    // 0x16d3ec: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x16D3ECu;
    {
        const bool branch_taken_0x16d3ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16D3F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D3ECu;
            // 0x16d3f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16d3ec) {
            ctx->pc = 0x16D450u;
            goto label_16d450;
        }
    }
    ctx->pc = 0x16D3F4u;
    // 0x16d3f4: 0x68a20d0f  ldl         $v0, 0xD0F($a1)
    ctx->pc = 0x16d3f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3343); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x16d3f8: 0x6ca20d08  ldr         $v0, 0xD08($a1)
    ctx->pc = 0x16d3f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3336); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x16d3fc: 0x68a30d17  ldl         $v1, 0xD17($a1)
    ctx->pc = 0x16d3fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3351); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x16d400: 0x6ca30d10  ldr         $v1, 0xD10($a1)
    ctx->pc = 0x16d400u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3344); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x16d404: 0x68a60d1f  ldl         $a2, 0xD1F($a1)
    ctx->pc = 0x16d404u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3359); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem << shift)); }
    // 0x16d408: 0x6ca60d18  ldr         $a2, 0xD18($a1)
    ctx->pc = 0x16d408u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 3352); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & keepMask) | (mem >> shift)); }
    // 0x16d40c: 0x8ca70d20  lw          $a3, 0xD20($a1)
    ctx->pc = 0x16d40cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 3360)));
    // 0x16d410: 0xb3a20007  sdl         $v0, 0x7($sp)
    ctx->pc = 0x16d410u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d414: 0xb7a20000  sdr         $v0, 0x0($sp)
    ctx->pc = 0x16d414u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d418: 0xb3a3000f  sdl         $v1, 0xF($sp)
    ctx->pc = 0x16d418u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d41c: 0xb7a30008  sdr         $v1, 0x8($sp)
    ctx->pc = 0x16d41cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d420: 0xb3a60017  sdl         $a2, 0x17($sp)
    ctx->pc = 0x16d420u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d424: 0xb7a60010  sdr         $a2, 0x10($sp)
    ctx->pc = 0x16d424u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 6); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x16d428: 0xafa70018  sw          $a3, 0x18($sp)
    ctx->pc = 0x16d428u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 7));
    // 0x16d42c: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x16d42cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x16d430: 0x27a60024  addiu       $a2, $sp, 0x24
    ctx->pc = 0x16d430u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    // 0x16d434: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x16d434u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16d438: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x16d438u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16d43c: 0xc05da70  jal         func_1769C0
    ctx->pc = 0x16D43Cu;
    SET_GPR_U32(ctx, 31, 0x16D444u);
    ctx->pc = 0x16D440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16D43Cu;
            // 0x16d440: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769C0u;
    if (runtime->hasFunction(0x1769C0u)) {
        auto targetFn = runtime->lookupFunction(0x1769C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D444u; }
        if (ctx->pc != 0x16D444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769C0_0x1769c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16D444u; }
        if (ctx->pc != 0x16D444u) { return; }
    }
    ctx->pc = 0x16D444u;
label_16d444:
    // 0x16d444: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x16d444u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16d448: 0x8e030020  lw          $v1, 0x20($s0)
    ctx->pc = 0x16d448u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x16d44c: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x16d44cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_16d450:
    // 0x16d450: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x16d450u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16d454: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x16d454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16d458: 0x3e00008  jr          $ra
    ctx->pc = 0x16D458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16D45Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16D458u;
            // 0x16d45c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16D444u: goto label_16d444;
            case 0x16D450u: goto label_16d450;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16D460u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
