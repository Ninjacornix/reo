#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D390
// Address: 0x17d390 - 0x17d410
void sub_0017D390_0x17d390(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D390_0x17d390");
#endif

    ctx->pc = 0x17d390u;

    // 0x17d390: 0x24840014  addiu       $a0, $a0, 0x14
    ctx->pc = 0x17d390u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 20));
    // 0x17d394: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17d394u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17d398: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x17d398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d39c: 0x50430004  beql        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17D39Cu;
    {
        const bool branch_taken_0x17d39c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x17d39c) {
            ctx->pc = 0x17D3A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17D39Cu;
            // 0x17d3a0: 0x8c820008  lw          $v0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17D3B0u;
            goto label_17d3b0;
        }
    }
    ctx->pc = 0x17D3A4u;
    // 0x17d3a4: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x17d3a4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x17d3a8: 0x3e00008  jr          $ra
    ctx->pc = 0x17D3A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D3ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D3A8u;
            // 0x17d3ac: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D3B0u: goto label_17d3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D3B0u;
label_17d3b0:
    // 0x17d3b0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x17d3b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d3b4: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x17d3b4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x17d3b8: 0x3e00008  jr          $ra
    ctx->pc = 0x17D3B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D3BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D3B8u;
            // 0x17d3bc: 0xaca30000  sw          $v1, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D3B0u: goto label_17d3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D3C0u;
    // 0x17d3c0: 0x3e00008  jr          $ra
    ctx->pc = 0x17D3C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D3C0u;
            // 0x17d3c4: 0xac850028  sw          $a1, 0x28($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D3B0u: goto label_17d3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D3C8u;
    // 0x17d3c8: 0x3e00008  jr          $ra
    ctx->pc = 0x17D3C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D3CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D3C8u;
            // 0x17d3cc: 0x8c820028  lw          $v0, 0x28($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D3B0u: goto label_17d3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D3D0u;
    // 0x17d3d0: 0x3e00008  jr          $ra
    ctx->pc = 0x17D3D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D3D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D3D0u;
            // 0x17d3d4: 0xac85002c  sw          $a1, 0x2C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D3B0u: goto label_17d3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D3D8u;
    // 0x17d3d8: 0x3e00008  jr          $ra
    ctx->pc = 0x17D3D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D3DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D3D8u;
            // 0x17d3dc: 0x8c82002c  lw          $v0, 0x2C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D3B0u: goto label_17d3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D3E0u;
    // 0x17d3e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d3e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d3e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d3e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d3e8: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x17d3e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x17d3ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d3ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d3f0: 0x805f8ae  j           func_17E2B8
    ctx->pc = 0x17D3F0u;
    ctx->pc = 0x17D3F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D3F0u;
            // 0x17d3f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E2B8u;
    if (runtime->hasFunction(0x17E2B8u)) {
        auto targetFn = runtime->lookupFunction(0x17E2B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E2B8_0x17e2b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D3F8u;
    // 0x17d3f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d3f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d3fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d3fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d400: 0x8c840024  lw          $a0, 0x24($a0)
    ctx->pc = 0x17d400u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x17d404: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d404u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d408: 0x805f8d4  j           func_17E350
    ctx->pc = 0x17D408u;
    ctx->pc = 0x17D40Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17D408u;
            // 0x17d40c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E350u;
    if (runtime->hasFunction(0x17E350u)) {
        auto targetFn = runtime->lookupFunction(0x17E350u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017E350_0x17e350(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17D410u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
