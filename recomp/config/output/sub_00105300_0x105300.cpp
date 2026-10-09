#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00105300
// Address: 0x105300 - 0x105360
void sub_00105300_0x105300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00105300_0x105300");
#endif

    ctx->pc = 0x105300u;

    // 0x105300: 0x3c020011  lui         $v0, 0x11
    ctx->pc = 0x105300u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
    // 0x105304: 0x3c030011  lui         $v1, 0x11
    ctx->pc = 0x105304u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17 << 16));
    // 0x105308: 0x3c080011  lui         $t0, 0x11
    ctx->pc = 0x105308u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)17 << 16));
    // 0x10530c: 0x3c090011  lui         $t1, 0x11
    ctx->pc = 0x10530cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)17 << 16));
    // 0x105310: 0x2442a970  addiu       $v0, $v0, -0x5690
    ctx->pc = 0x105310u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945136));
    // 0x105314: 0x2463a9d8  addiu       $v1, $v1, -0x5628
    ctx->pc = 0x105314u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294945240));
    // 0x105318: 0x2508aa58  addiu       $t0, $t0, -0x55A8
    ctx->pc = 0x105318u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294945368));
    // 0x10531c: 0x2529aac0  addiu       $t1, $t1, -0x5540
    ctx->pc = 0x10531cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294945472));
    // 0x105320: 0xac870054  sw          $a3, 0x54($a0)
    ctx->pc = 0x105320u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 84), GPR_U32(ctx, 7));
    // 0x105324: 0xa485000c  sh          $a1, 0xC($a0)
    ctx->pc = 0x105324u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 12), (uint16_t)GPR_U32(ctx, 5));
    // 0x105328: 0xa486000e  sh          $a2, 0xE($a0)
    ctx->pc = 0x105328u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 14), (uint16_t)GPR_U32(ctx, 6));
    // 0x10532c: 0xac820020  sw          $v0, 0x20($a0)
    ctx->pc = 0x10532cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 2));
    // 0x105330: 0xac830024  sw          $v1, 0x24($a0)
    ctx->pc = 0x105330u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 3));
    // 0x105334: 0xac880028  sw          $t0, 0x28($a0)
    ctx->pc = 0x105334u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 8));
    // 0x105338: 0xac89002c  sw          $t1, 0x2C($a0)
    ctx->pc = 0x105338u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 9));
    // 0x10533c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x10533cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x105340: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x105340u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x105344: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x105344u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x105348: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x105348u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x10534c: 0xac800014  sw          $zero, 0x14($a0)
    ctx->pc = 0x10534cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 0));
    // 0x105350: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x105350u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x105354: 0x3e00008  jr          $ra
    ctx->pc = 0x105354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x105358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105354u;
            // 0x105358: 0xac84001c  sw          $a0, 0x1C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x10535Cu;
    // 0x10535c: 0x0  nop
    ctx->pc = 0x10535cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
