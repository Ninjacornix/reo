#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BBB10
// Address: 0x1bbb10 - 0x1bbb7c
void sub_001BBB10_0x1bbb10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BBB10_0x1bbb10");
#endif

    switch (ctx->pc) {
        case 0x1bbb34u: goto label_1bbb34;
        default: break;
    }

    ctx->pc = 0x1bbb10u;

    // 0x1bbb10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bbb10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bbb14: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bbb14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bbb18: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bbb18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bbb1c: 0x24060018  addiu       $a2, $zero, 0x18
    ctx->pc = 0x1bbb1cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1bbb20: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bbb20u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bbb24: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1bbb24u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bbb28: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bbb28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb2c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BBB2Cu;
    SET_GPR_U32(ctx, 31, 0x1BBB34u);
    ctx->pc = 0x1BBB30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBB2Cu;
            // 0x1bbb30: 0x24846600  addiu       $a0, $a0, 0x6600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBB34u; }
        if (ctx->pc != 0x1BBB34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBB34u; }
        if (ctx->pc != 0x1BBB34u) { return; }
    }
    ctx->pc = 0x1BBB34u;
label_1bbb34:
    // 0x1bbb34: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb38: 0x24030280  addiu       $v1, $zero, 0x280
    ctx->pc = 0x1bbb38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1bbb3c: 0xac306614  sw          $s0, 0x6614($at)
    ctx->pc = 0x1bbb3cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26132), GPR_U32(ctx, 16));
    // 0x1bbb40: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb44: 0xa4236610  sh          $v1, 0x6610($at)
    ctx->pc = 0x1bbb44u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26128), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bbb48: 0x240301e0  addiu       $v1, $zero, 0x1E0
    ctx->pc = 0x1bbb48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 480));
    // 0x1bbb4c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb50: 0xa4236612  sh          $v1, 0x6612($at)
    ctx->pc = 0x1bbb50u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26130), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bbb54: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1bbb54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1bbb58: 0xac20eb10  sw          $zero, -0x14F0($at)
    ctx->pc = 0x1bbb58u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961936), GPR_U32(ctx, 0));
    // 0x1bbb5c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb60: 0xa420660c  sh          $zero, 0x660C($at)
    ctx->pc = 0x1bbb60u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26124), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bbb64: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbb64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb68: 0xa420660e  sh          $zero, 0x660E($at)
    ctx->pc = 0x1bbb68u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26126), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bbb6c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bbb6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bbb70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bbb70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bbb74: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBB74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BBB78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBB74u;
            // 0x1bbb78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBB34u: goto label_1bbb34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BBB7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
