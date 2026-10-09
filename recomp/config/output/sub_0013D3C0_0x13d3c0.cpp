#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D3C0
// Address: 0x13d3c0 - 0x13d430
void sub_0013D3C0_0x13d3c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D3C0_0x13d3c0");
#endif

    switch (ctx->pc) {
        case 0x13d3d8u: goto label_13d3d8;
        default: break;
    }

    ctx->pc = 0x13d3c0u;

    // 0x13d3c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d3c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d3c4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D3C4u;
    {
        const bool branch_taken_0x13d3c4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D3C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D3C4u;
            // 0x13d3c8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d3c4) {
            ctx->pc = 0x13D3E0u;
            goto label_13d3e0;
        }
    }
    ctx->pc = 0x13D3CCu;
    // 0x13d3cc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d3ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d3d0: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D3D0u;
    SET_GPR_U32(ctx, 31, 0x13D3D8u);
    ctx->pc = 0x13D3D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D3D0u;
            // 0x13d3d4: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D3D8u; }
        if (ctx->pc != 0x13D3D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D3D8u; }
        if (ctx->pc != 0x13D3D8u) { return; }
    }
    ctx->pc = 0x13D3D8u;
label_13d3d8:
    // 0x13d3d8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13D3D8u;
    {
        const bool branch_taken_0x13d3d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D3DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D3D8u;
            // 0x13d3dc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d3d8) {
            ctx->pc = 0x13D3E4u;
            goto label_13d3e4;
        }
    }
    ctx->pc = 0x13D3E0u;
label_13d3e0:
    // 0x13d3e0: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x13d3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
label_13d3e4:
    // 0x13d3e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d3e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d3e8: 0x3e00008  jr          $ra
    ctx->pc = 0x13D3E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D3ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D3E8u;
            // 0x13d3ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D3D8u: goto label_13d3d8;
            case 0x13D3E0u: goto label_13d3e0;
            case 0x13D3E4u: goto label_13d3e4;
            case 0x13D418u: goto label_13d418;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D3F0u;
    // 0x13d3f0: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x13d3f0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d3f4: 0x14e00008  bnez        $a3, . + 4 + (0x8 << 2)
    ctx->pc = 0x13D3F4u;
    {
        const bool branch_taken_0x13d3f4 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D3F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D3F4u;
            // 0x13d3f8: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d3f4) {
            ctx->pc = 0x13D418u;
            goto label_13d418;
        }
    }
    ctx->pc = 0x13D3FCu;
    // 0x13d3fc: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13d3fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13d400: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13d400u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13d404: 0xac40dfd8  sw          $zero, -0x2028($v0)
    ctx->pc = 0x13d404u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294959064), GPR_U32(ctx, 0));
    // 0x13d408: 0xac60dfdc  sw          $zero, -0x2024($v1)
    ctx->pc = 0x13d408u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294959068), GPR_U32(ctx, 0));
    // 0x13d40c: 0x3e00008  jr          $ra
    ctx->pc = 0x13D40Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D40Cu;
            // 0x13d410: 0xac80dfe0  sw          $zero, -0x2020($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4294959072), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D3D8u: goto label_13d3d8;
            case 0x13D3E0u: goto label_13d3e0;
            case 0x13D3E4u: goto label_13d3e4;
            case 0x13D418u: goto label_13d418;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D414u;
    // 0x13d414: 0x0  nop
    ctx->pc = 0x13d414u;
    // NOP
label_13d418:
    // 0x13d418: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13d418u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13d41c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13d41cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13d420: 0xac47dfd8  sw          $a3, -0x2028($v0)
    ctx->pc = 0x13d420u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294959064), GPR_U32(ctx, 7));
    // 0x13d424: 0xac65dfdc  sw          $a1, -0x2024($v1)
    ctx->pc = 0x13d424u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294959068), GPR_U32(ctx, 5));
    // 0x13d428: 0x3e00008  jr          $ra
    ctx->pc = 0x13D428u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D42Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D428u;
            // 0x13d42c: 0xac86dfe0  sw          $a2, -0x2020($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4294959072), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D3D8u: goto label_13d3d8;
            case 0x13D3E0u: goto label_13d3e0;
            case 0x13D3E4u: goto label_13d3e4;
            case 0x13D418u: goto label_13d418;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D430u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
