#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179C78
// Address: 0x179c78 - 0x179ce8
void sub_00179C78_0x179c78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179C78_0x179c78");
#endif

    switch (ctx->pc) {
        case 0x179c94u: goto label_179c94;
        case 0x179cb0u: goto label_179cb0;
        default: break;
    }

    ctx->pc = 0x179c78u;

    // 0x179c78: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179c78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179c7c: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x179c7cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179c80: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179c84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179c88: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179c8c: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179C8Cu;
    SET_GPR_U32(ctx, 31, 0x179C94u);
    ctx->pc = 0x179C90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179C8Cu;
            // 0x179c90: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179C94u; }
        if (ctx->pc != 0x179C94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179C94u; }
        if (ctx->pc != 0x179C94u) { return; }
    }
    ctx->pc = 0x179C94u;
label_179c94:
    // 0x179c94: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x179c94u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179c98: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x179c98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179c9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x179c9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ca0: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x179CA0u;
    {
        const bool branch_taken_0x179ca0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x179CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179CA0u;
            // 0x179ca4: 0x2406000d  addiu       $a2, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179ca0) {
            ctx->pc = 0x179CD4u;
            goto label_179cd4;
        }
    }
    ctx->pc = 0x179CA8u;
    // 0x179ca8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x179CA8u;
    SET_GPR_U32(ctx, 31, 0x179CB0u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179CB0u; }
        if (ctx->pc != 0x179CB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179CB0u; }
        if (ctx->pc != 0x179CB0u) { return; }
    }
    ctx->pc = 0x179CB0u;
label_179cb0:
    // 0x179cb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179cb4: 0x6a030007  ldl         $v1, 0x7($s0)
    ctx->pc = 0x179cb4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x179cb8: 0x6e030000  ldr         $v1, 0x0($s0)
    ctx->pc = 0x179cb8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x179cbc: 0x8a04000b  lwl         $a0, 0xB($s0)
    ctx->pc = 0x179cbcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x179cc0: 0x9a040008  lwr         $a0, 0x8($s0)
    ctx->pc = 0x179cc0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x179cc4: 0xb2230007  sdl         $v1, 0x7($s1)
    ctx->pc = 0x179cc4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x179cc8: 0xb6230000  sdr         $v1, 0x0($s1)
    ctx->pc = 0x179cc8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x179ccc: 0xaa24000b  swl         $a0, 0xB($s1)
    ctx->pc = 0x179cccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x179cd0: 0xba240008  swr         $a0, 0x8($s1)
    ctx->pc = 0x179cd0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_179cd4:
    // 0x179cd4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179cd4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179cd8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179cd8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179cdc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179cdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179ce0: 0x3e00008  jr          $ra
    ctx->pc = 0x179CE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179CE0u;
            // 0x179ce4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179C94u: goto label_179c94;
            case 0x179CB0u: goto label_179cb0;
            case 0x179CD4u: goto label_179cd4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179CE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
