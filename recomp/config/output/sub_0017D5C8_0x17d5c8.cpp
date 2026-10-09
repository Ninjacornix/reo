#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D5C8
// Address: 0x17d5c8 - 0x17d638
void sub_0017D5C8_0x17d5c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D5C8_0x17d5c8");
#endif

    switch (ctx->pc) {
        case 0x17d608u: goto label_17d608;
        default: break;
    }

    ctx->pc = 0x17d5c8u;

    // 0x17d5c8: 0x8c870004  lw          $a3, 0x4($a0)
    ctx->pc = 0x17d5c8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d5cc: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x17d5ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d5d0: 0xa73818  mult        $a3, $a1, $a3
    ctx->pc = 0x17d5d0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x17d5d4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x17d5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17d5d8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x17d5d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17d5dc: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x17d5dcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x17d5e0: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x17d5e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x17d5e4: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x17d5e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x17d5e8: 0x3e00008  jr          $ra
    ctx->pc = 0x17D5E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D5ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D5E8u;
            // 0x17d5ec: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D608u: goto label_17d608;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D5F0u;
    // 0x17d5f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d5f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d5f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17d5f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17d5f8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17d5f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d5fc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17d5fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17d600: 0xc052486  jal         func_149218
    ctx->pc = 0x17D600u;
    SET_GPR_U32(ctx, 31, 0x17D608u);
    ctx->pc = 0x17D604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D600u;
            // 0x17d604: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149218u;
    if (runtime->hasFunction(0x149218u)) {
        auto targetFn = runtime->lookupFunction(0x149218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D608u; }
        if (ctx->pc != 0x17D608u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00149218_0x149218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17D608u; }
        if (ctx->pc != 0x17D608u) { return; }
    }
    ctx->pc = 0x17D608u;
label_17d608:
    // 0x17d608: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17d608u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d60c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17d60cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17d610: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x17d610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d614: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17d614u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d618: 0x805f4ba  j           func_17D2E8
    ctx->pc = 0x17D618u;
    ctx->pc = 0x17D61Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D618u;
            // 0x17d61c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2E8u;
    if (runtime->hasFunction(0x17D2E8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D2E8_0x17d2e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D620u;
    // 0x17d620: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d624: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d628: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d628u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d62c: 0x8052490  j           func_149240
    ctx->pc = 0x17D62Cu;
    ctx->pc = 0x17D630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D62Cu;
            // 0x17d630: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149240u;
    if (runtime->hasFunction(0x149240u)) {
        auto targetFn = runtime->lookupFunction(0x149240u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00149240_0x149240(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D634u;
    // 0x17d634: 0x0  nop
    ctx->pc = 0x17d634u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
