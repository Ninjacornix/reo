#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D6E8
// Address: 0x17d6e8 - 0x17d740
void sub_0017D6E8_0x17d6e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D6E8_0x17d6e8");
#endif

    switch (ctx->pc) {
        case 0x17d724u: goto label_17d724;
        default: break;
    }

    ctx->pc = 0x17d6e8u;

    // 0x17d6e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d6e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d6ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d6ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d6f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d6f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d6f4: 0x805f5c0  j           func_17D700
    ctx->pc = 0x17D6F4u;
    ctx->pc = 0x17D6F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D6F4u;
            // 0x17d6f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D700u;
    goto label_17d700;
    ctx->pc = 0x17D6FCu;
    // 0x17d6fc: 0x0  nop
    ctx->pc = 0x17d6fcu;
    // NOP
label_17d700:
    // 0x17d700: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d704: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17d704u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d708: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d70c: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x17d70cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x17d710: 0x2610f748  addiu       $s0, $s0, -0x8B8
    ctx->pc = 0x17d710u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294965064));
    // 0x17d714: 0x2406022c  addiu       $a2, $zero, 0x22C
    ctx->pc = 0x17d714u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 556));
    // 0x17d718: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17d718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17d71c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x17D71Cu;
    SET_GPR_U32(ctx, 31, 0x17D724u);
    ctx->pc = 0x17D720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D71Cu;
            // 0x17d720: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D724u; }
        if (ctx->pc != 0x17D724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D724u; }
        if (ctx->pc != 0x17D724u) { return; }
    }
    ctx->pc = 0x17D724u;
label_17d724:
    // 0x17d724: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x17d724u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x17d728: 0xae030008  sw          $v1, 0x8($s0)
    ctx->pc = 0x17d728u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 3));
    // 0x17d72c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x17d72cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d730: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d730u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d734: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17d734u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d738: 0x805f8e6  j           func_17E398
    ctx->pc = 0x17D738u;
    ctx->pc = 0x17D73Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D738u;
            // 0x17d73c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E398u;
    if (runtime->hasFunction(0x17E398u)) {
        auto targetFn = runtime->lookupFunction(0x17E398u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E398_0x17e398(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D740u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
