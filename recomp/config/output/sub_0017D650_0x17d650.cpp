#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D650
// Address: 0x17d650 - 0x17d6e8
void sub_0017D650_0x17d650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D650_0x17d650");
#endif

    ctx->pc = 0x17d650u;

    // 0x17d650: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d650u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d654: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d658: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d658u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d65c: 0x805f906  j           func_17E418
    ctx->pc = 0x17D65Cu;
    ctx->pc = 0x17D660u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D65Cu;
            // 0x17d660: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E418u;
    if (runtime->hasFunction(0x17E418u)) {
        auto targetFn = runtime->lookupFunction(0x17E418u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E418_0x17e418(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D664u;
    // 0x17d664: 0x0  nop
    ctx->pc = 0x17d664u;
    // NOP
    // 0x17d668: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x17d668u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x17d66c: 0xac860004  sw          $a2, 0x4($a0)
    ctx->pc = 0x17d66cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
    // 0x17d670: 0x3e00008  jr          $ra
    ctx->pc = 0x17D670u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D670u;
            // 0x17d674: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D678u;
    // 0x17d678: 0x8c82005c  lw          $v0, 0x5C($a0)
    ctx->pc = 0x17d678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 92)));
    // 0x17d67c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D67Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D67Cu;
            // 0x17d680: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D684u;
    // 0x17d684: 0x0  nop
    ctx->pc = 0x17d684u;
    // NOP
    // 0x17d688: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d68c: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x17d68cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x17d690: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d694: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x17d694u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d698: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d698u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d69c: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x17d69cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d6a0: 0x805f96a  j           func_17E5A8
    ctx->pc = 0x17D6A0u;
    ctx->pc = 0x17D6A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D6A0u;
            // 0x17d6a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E5A8u;
    if (runtime->hasFunction(0x17E5A8u)) {
        auto targetFn = runtime->lookupFunction(0x17E5A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E5A8_0x17e5a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D6A8u;
    // 0x17d6a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d6a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d6ac: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x17d6acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x17d6b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d6b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d6b4: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x17d6b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d6b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d6b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d6bc: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x17d6bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d6c0: 0x805f97a  j           func_17E5E8
    ctx->pc = 0x17D6C0u;
    ctx->pc = 0x17D6C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D6C0u;
            // 0x17d6c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E5E8u;
    if (runtime->hasFunction(0x17E5E8u)) {
        auto targetFn = runtime->lookupFunction(0x17E5E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E5E8_0x17e5e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D6C8u;
    // 0x17d6c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d6c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d6cc: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x17d6ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x17d6d0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d6d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d6d4: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x17d6d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d6d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d6d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d6dc: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x17d6dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d6e0: 0x805f98a  j           func_17E628
    ctx->pc = 0x17D6E0u;
    ctx->pc = 0x17D6E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D6E0u;
            // 0x17d6e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E628u;
    if (runtime->hasFunction(0x17E628u)) {
        auto targetFn = runtime->lookupFunction(0x17E628u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E628_0x17e628(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D6E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
