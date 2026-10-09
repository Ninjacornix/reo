#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BE28
// Address: 0x13be28 - 0x13be80
void sub_0013BE28_0x13be28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BE28_0x13be28");
#endif

    switch (ctx->pc) {
        case 0x13be48u: goto label_13be48;
        case 0x13be6cu: goto label_13be6c;
        default: break;
    }

    ctx->pc = 0x13be28u;

    // 0x13be28: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13be28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13be2c: 0x24060006  addiu       $a2, $zero, 0x6
    ctx->pc = 0x13be2cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x13be30: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13be30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13be34: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13be34u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13be38: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13be38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13be3c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13be3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13be40: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13BE40u;
    SET_GPR_U32(ctx, 31, 0x13BE48u);
    ctx->pc = 0x13BE44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BE40u;
            // 0x13be44: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BE48u; }
        if (ctx->pc != 0x13BE48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BE48u; }
        if (ctx->pc != 0x13BE48u) { return; }
    }
    ctx->pc = 0x13BE48u;
label_13be48:
    // 0x13be48: 0x8a020003  lwl         $v0, 0x3($s0)
    ctx->pc = 0x13be48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 2) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 2, (int32_t)merged); }
    // 0x13be4c: 0x9a020000  lwr         $v0, 0x0($s0)
    ctx->pc = 0x13be4cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 16), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 2) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 2) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 2, merged64); }
    // 0x13be50: 0xaba20003  swl         $v0, 0x3($sp)
    ctx->pc = 0x13be50u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 3); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = (3u - offset) << 3; uint32_t mask = 0xFFFFFFFFu >> shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x13be54: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13be54u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13be58: 0x24a5d148  addiu       $a1, $a1, -0x2EB8
    ctx->pc = 0x13be58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955336));
    // 0x13be5c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13be5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13be60: 0xbba20000  swr         $v0, 0x0($sp)
    ctx->pc = 0x13be60u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t shift = offset << 3; uint32_t mask = 0xFFFFFFFFu << shift; uint32_t old_data = READ32(aligned_addr); uint32_t val = GPR_U32(ctx, 2); uint32_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE32(aligned_addr, new_data); }
    // 0x13be64: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x13BE64u;
    SET_GPR_U32(ctx, 31, 0x13BE6Cu);
    ctx->pc = 0x13BE68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13BE64u;
            // 0x13be68: 0xa3a00005  sb          $zero, 0x5($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 5), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BE6Cu; }
        if (ctx->pc != 0x13BE6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BE6Cu; }
        if (ctx->pc != 0x13BE6Cu) { return; }
    }
    ctx->pc = 0x13BE6Cu;
label_13be6c:
    // 0x13be6c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13be6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13be70: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x13be70u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x13be74: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13be74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13be78: 0x3e00008  jr          $ra
    ctx->pc = 0x13BE78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BE7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BE78u;
            // 0x13be7c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13BE48u: goto label_13be48;
            case 0x13BE6Cu: goto label_13be6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13BE80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
