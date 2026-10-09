#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B410
// Address: 0x15b410 - 0x15b478
void sub_0015B410_0x15b410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B410_0x15b410");
#endif

    ctx->pc = 0x15b410u;

    // 0x15b410: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15b410u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15b414: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x15b414u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15b418: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x15b418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15b41c: 0xac850050  sw          $a1, 0x50($a0)
    ctx->pc = 0x15b41cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 80), GPR_U32(ctx, 5));
    // 0x15b420: 0xac820038  sw          $v0, 0x38($a0)
    ctx->pc = 0x15b420u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 2));
    // 0x15b424: 0xac830048  sw          $v1, 0x48($a0)
    ctx->pc = 0x15b424u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 3));
    // 0x15b428: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x15b428u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x15b42c: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x15b42cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x15b430: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x15b430u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x15b434: 0xac80000c  sw          $zero, 0xC($a0)
    ctx->pc = 0x15b434u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 0));
    // 0x15b438: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x15b438u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x15b43c: 0xac800014  sw          $zero, 0x14($a0)
    ctx->pc = 0x15b43cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 0));
    // 0x15b440: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x15b440u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x15b444: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x15b444u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x15b448: 0xac800020  sw          $zero, 0x20($a0)
    ctx->pc = 0x15b448u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x15b44c: 0xac800024  sw          $zero, 0x24($a0)
    ctx->pc = 0x15b44cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
    // 0x15b450: 0xac800028  sw          $zero, 0x28($a0)
    ctx->pc = 0x15b450u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 0));
    // 0x15b454: 0xac80002c  sw          $zero, 0x2C($a0)
    ctx->pc = 0x15b454u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x15b458: 0xac800030  sw          $zero, 0x30($a0)
    ctx->pc = 0x15b458u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 0));
    // 0x15b45c: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x15b45cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x15b460: 0xac85003c  sw          $a1, 0x3C($a0)
    ctx->pc = 0x15b460u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 5));
    // 0x15b464: 0xac830040  sw          $v1, 0x40($a0)
    ctx->pc = 0x15b464u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 3));
    // 0x15b468: 0xac830044  sw          $v1, 0x44($a0)
    ctx->pc = 0x15b468u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 3));
    // 0x15b46c: 0x3e00008  jr          $ra
    ctx->pc = 0x15B46Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15B470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15B46Cu;
            // 0x15b470: 0xac85004c  sw          $a1, 0x4C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 76), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15B474u;
    // 0x15b474: 0x0  nop
    ctx->pc = 0x15b474u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
