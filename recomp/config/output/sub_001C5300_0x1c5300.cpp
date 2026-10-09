#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5300
// Address: 0x1c5300 - 0x1c5340
void sub_001C5300_0x1c5300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5300_0x1c5300");
#endif

    switch (ctx->pc) {
        case 0x1c531cu: goto label_1c531c;
        case 0x1c5330u: goto label_1c5330;
        default: break;
    }

    ctx->pc = 0x1c5300u;

    // 0x1c5300: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c5300u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c5304: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c5304u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5308: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c5308u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c530c: 0x3c060001  lui         $a2, 0x1
    ctx->pc = 0x1c530cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
    // 0x1c5310: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5310u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5314: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C5314u;
    SET_GPR_U32(ctx, 31, 0x1C531Cu);
    ctx->pc = 0x1C5318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5314u;
            // 0x1c5318: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C531Cu; }
        if (ctx->pc != 0x1C531Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C531Cu; }
        if (ctx->pc != 0x1C531Cu) { return; }
    }
    ctx->pc = 0x1C531Cu;
label_1c531c:
    // 0x1c531c: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c531cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c5320: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c5320u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5324: 0x24a5fb60  addiu       $a1, $a1, -0x4A0
    ctx->pc = 0x1c5324u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966112));
    // 0x1c5328: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C5328u;
    SET_GPR_U32(ctx, 31, 0x1C5330u);
    ctx->pc = 0x1C532Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5328u;
            // 0x1c532c: 0x24064234  addiu       $a2, $zero, 0x4234 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16948));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5330u; }
        if (ctx->pc != 0x1C5330u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5330u; }
        if (ctx->pc != 0x1C5330u) { return; }
    }
    ctx->pc = 0x1C5330u;
label_1c5330:
    // 0x1c5330: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c5330u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5334: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5334u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5338: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C533Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5338u;
            // 0x1c533c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C531Cu: goto label_1c531c;
            case 0x1C5330u: goto label_1c5330;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5340u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
