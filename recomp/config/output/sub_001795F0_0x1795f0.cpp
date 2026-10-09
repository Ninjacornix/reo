#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001795F0
// Address: 0x1795f0 - 0x17965c
void sub_001795F0_0x1795f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001795F0_0x1795f0");
#endif

    switch (ctx->pc) {
        case 0x17960cu: goto label_17960c;
        case 0x179624u: goto label_179624;
        default: break;
    }

    ctx->pc = 0x1795f0u;

    // 0x1795f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1795f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1795f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1795f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1795f8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1795f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1795fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1795fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179600: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x179600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x179604: 0xc05e4a6  jal         func_179298
    ctx->pc = 0x179604u;
    SET_GPR_U32(ctx, 31, 0x17960Cu);
    ctx->pc = 0x179608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179604u;
            // 0x179608: 0x8c910004  lw          $s1, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179298u;
    if (runtime->hasFunction(0x179298u)) {
        auto targetFn = runtime->lookupFunction(0x179298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17960Cu; }
        if (ctx->pc != 0x17960Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179298_0x179298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17960Cu; }
        if (ctx->pc != 0x17960Cu) { return; }
    }
    ctx->pc = 0x17960Cu;
label_17960c:
    // 0x17960c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17960cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179610: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x179610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179614: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x179614u;
    {
        const bool branch_taken_0x179614 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x179618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179614u;
            // 0x179618: 0x2406000d  addiu       $a2, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179614) {
            ctx->pc = 0x179648u;
            goto label_179648;
        }
    }
    ctx->pc = 0x17961Cu;
    // 0x17961c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x17961Cu;
    SET_GPR_U32(ctx, 31, 0x179624u);
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179624u; }
        if (ctx->pc != 0x179624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179624u; }
        if (ctx->pc != 0x179624u) { return; }
    }
    ctx->pc = 0x179624u;
label_179624:
    // 0x179624: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179628: 0x6a230053  ldl         $v1, 0x53($s1)
    ctx->pc = 0x179628u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 83); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x17962c: 0x6e23004c  ldr         $v1, 0x4C($s1)
    ctx->pc = 0x17962cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 76); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x179630: 0x8a240057  lwl         $a0, 0x57($s1)
    ctx->pc = 0x179630u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 87); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x179634: 0x9a240054  lwr         $a0, 0x54($s1)
    ctx->pc = 0x179634u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 84); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x179638: 0xb2030007  sdl         $v1, 0x7($s0)
    ctx->pc = 0x179638u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17963c: 0xb6030000  sdr         $v1, 0x0($s0)
    ctx->pc = 0x17963cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x179640: 0xaa04000b  swl         $a0, 0xB($s0)
    ctx->pc = 0x179640u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 11); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x179644: 0xba040008  swr         $a0, 0x8($s0)
    ctx->pc = 0x179644u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 8); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 4); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
label_179648:
    // 0x179648: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179648u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17964c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17964cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179650: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x179650u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179654: 0x3e00008  jr          $ra
    ctx->pc = 0x179654u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179654u;
            // 0x179658: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17960Cu: goto label_17960c;
            case 0x179624u: goto label_179624;
            case 0x179648u: goto label_179648;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17965Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
