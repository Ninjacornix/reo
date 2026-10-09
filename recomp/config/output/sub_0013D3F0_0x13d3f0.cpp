#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D3F0
// Address: 0x13d3f0 - 0x13d430
void sub_0013D3F0_0x13d3f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D3F0_0x13d3f0");
#endif

    ctx->pc = 0x13d3f0u;

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
            case 0x13D418u: goto label_13d418;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D430u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
