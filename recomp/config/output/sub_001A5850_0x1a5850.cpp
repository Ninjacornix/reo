#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5850
// Address: 0x1a5850 - 0x1a58c0
void sub_001A5850_0x1a5850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5850_0x1a5850");
#endif

    ctx->pc = 0x1a5850u;

    // 0x1a5850: 0x90830005  lbu         $v1, 0x5($a0)
    ctx->pc = 0x1a5850u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x1a5854: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1a5854u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1a5858: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1a5858u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a585c: 0x43200b  movn        $a0, $v0, $v1
    ctx->pc = 0x1a585cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 2));
    // 0x1a5860: 0xa4001b  divu        $zero, $a1, $a0
    ctx->pc = 0x1a5860u;
    { uint32_t divisor = GPR_U32(ctx, 4); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,5); } }
    // 0x1a5864: 0x0  nop
    ctx->pc = 0x1a5864u;
    // NOP
    // 0x1a5868: 0x0  nop
    ctx->pc = 0x1a5868u;
    // NOP
    // 0x1a586c: 0x1010  mfhi        $v0
    ctx->pc = 0x1a586cu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1a5870: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1A5870u;
    {
        const bool branch_taken_0x1a5870 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5870u;
            // 0x1a5874: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5870) {
            ctx->pc = 0x1A58ACu;
            goto label_1a58ac;
        }
    }
    ctx->pc = 0x1A5878u;
    // 0x1a5878: 0xa4001b  divu        $zero, $a1, $a0
    ctx->pc = 0x1a5878u;
    { uint32_t divisor = GPR_U32(ctx, 4); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,5); } }
    // 0x1a587c: 0x0  nop
    ctx->pc = 0x1a587cu;
    // NOP
    // 0x1a5880: 0x0  nop
    ctx->pc = 0x1a5880u;
    // NOP
    // 0x1a5884: 0x1012  mflo        $v0
    ctx->pc = 0x1a5884u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1a5888: 0x821018  mult        $v0, $a0, $v0
    ctx->pc = 0x1a5888u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1a588c: 0xa21023  subu        $v0, $a1, $v0
    ctx->pc = 0x1a588cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1a5890: 0x44001b  divu        $zero, $v0, $a0
    ctx->pc = 0x1a5890u;
    { uint32_t divisor = GPR_U32(ctx, 4); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x1a5894: 0x0  nop
    ctx->pc = 0x1a5894u;
    // NOP
    // 0x1a5898: 0x0  nop
    ctx->pc = 0x1a5898u;
    // NOP
    // 0x1a589c: 0x1010  mfhi        $v0
    ctx->pc = 0x1a589cu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1a58a0: 0x821023  subu        $v0, $a0, $v0
    ctx->pc = 0x1a58a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1a58a4: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x1a58a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1a58a8: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1a58a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1a58ac:
    // 0x1a58ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1A58ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A58ACu: goto label_1a58ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A58B4u;
    // 0x1a58b4: 0x0  nop
    ctx->pc = 0x1a58b4u;
    // NOP
    // 0x1a58b8: 0x0  nop
    ctx->pc = 0x1a58b8u;
    // NOP
    // 0x1a58bc: 0x0  nop
    ctx->pc = 0x1a58bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
