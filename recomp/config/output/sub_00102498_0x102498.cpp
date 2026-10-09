#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102498
// Address: 0x102498 - 0x1024e0
void sub_00102498_0x102498(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102498_0x102498");
#endif

    ctx->pc = 0x102498u;

    // 0x102498: 0x4843e800  cfc2.ni     $v1, $vi29
    ctx->pc = 0x102498u;
    SET_GPR_U32(ctx, 3, ctx->vu0_top);
    // 0x10249c: 0x30620200  andi        $v0, $v1, 0x200
    ctx->pc = 0x10249cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)512);
    // 0x1024a0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1024A0u;
    {
        const bool branch_taken_0x1024a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1024A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1024A0u;
            // 0x1024a4: 0x30620400  andi        $v0, $v1, 0x400 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1024);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1024a0) {
            ctx->pc = 0x1024B0u;
            goto label_1024b0;
        }
    }
    ctx->pc = 0x1024A8u;
    // 0x1024a8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1024A8u;
    {
        const bool branch_taken_0x1024a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1024ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1024A8u;
            // 0x1024ac: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1024a8) {
            ctx->pc = 0x1024D8u;
            goto label_1024d8;
        }
    }
    ctx->pc = 0x1024B0u;
label_1024b0:
    // 0x1024b0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1024B0u;
    {
        const bool branch_taken_0x1024b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1024B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1024B0u;
            // 0x1024b4: 0x30620800  andi        $v0, $v1, 0x800 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2048);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1024b0) {
            ctx->pc = 0x1024C0u;
            goto label_1024c0;
        }
    }
    ctx->pc = 0x1024B8u;
    // 0x1024b8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1024B8u;
    {
        const bool branch_taken_0x1024b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1024BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1024B8u;
            // 0x1024bc: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1024b8) {
            ctx->pc = 0x1024D8u;
            goto label_1024d8;
        }
    }
    ctx->pc = 0x1024C0u;
label_1024c0:
    // 0x1024c0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1024C0u;
    {
        const bool branch_taken_0x1024c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1024C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1024C0u;
            // 0x1024c4: 0x30620100  andi        $v0, $v1, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1024c0) {
            ctx->pc = 0x1024D0u;
            goto label_1024d0;
        }
    }
    ctx->pc = 0x1024C8u;
    // 0x1024c8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1024C8u;
    {
        const bool branch_taken_0x1024c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1024CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1024C8u;
            // 0x1024cc: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1024c8) {
            ctx->pc = 0x1024D8u;
            goto label_1024d8;
        }
    }
    ctx->pc = 0x1024D0u;
label_1024d0:
    // 0x1024d0: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1024d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1024d4: 0x2180a  movz        $v1, $zero, $v0
    ctx->pc = 0x1024d4u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
label_1024d8:
    // 0x1024d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1024D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1024DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1024D8u;
            // 0x1024dc: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1024B0u: goto label_1024b0;
            case 0x1024C0u: goto label_1024c0;
            case 0x1024D0u: goto label_1024d0;
            case 0x1024D8u: goto label_1024d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1024E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
