#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE470
// Address: 0x1ae470 - 0x1ae4b0
void sub_001AE470_0x1ae470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE470_0x1ae470");
#endif

    ctx->pc = 0x1ae470u;

    // 0x1ae470: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1ae470u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ae474: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae474u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae478: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1ae478u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ae47c: 0x24638d7c  addiu       $v1, $v1, -0x7284
    ctx->pc = 0x1ae47cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937980));
    // 0x1ae480: 0x220c0  sll         $a0, $v0, 3
    ctx->pc = 0x1ae480u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1ae484: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1ae484u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae488: 0xc4610000  lwc1        $f1, 0x0($v1)
    ctx->pc = 0x1ae488u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1ae48c: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1ae48cu;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ae490: 0x0  nop
    ctx->pc = 0x1ae490u;
    // NOP
    // 0x1ae494: 0x46010032  c.eq.s      $f0, $f1
    ctx->pc = 0x1ae494u;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1ae498: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1AE498u;
    {
        const bool branch_taken_0x1ae498 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1AE49Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE498u;
            // 0x1ae49c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae498) {
            ctx->pc = 0x1AE4A4u;
            goto label_1ae4a4;
        }
    }
    ctx->pc = 0x1AE4A0u;
    // 0x1ae4a0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ae4a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ae4a4:
    // 0x1ae4a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE4A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE4A4u: goto label_1ae4a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE4ACu;
    // 0x1ae4ac: 0x0  nop
    ctx->pc = 0x1ae4acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
