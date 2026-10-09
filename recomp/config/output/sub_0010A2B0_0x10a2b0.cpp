#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A2B0
// Address: 0x10a2b0 - 0x10a2f0
void sub_0010A2B0_0x10a2b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A2B0_0x10a2b0");
#endif

    ctx->pc = 0x10a2b0u;

    // 0x10a2b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a2b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a2b4: 0x46006006  mov.s       $f0, $f12
    ctx->pc = 0x10a2b4u;
    ctx->f[0] = FPU_MOV_S(ctx->f[12]);
    // 0x10a2b8: 0xe7a00000  swc1        $f0, 0x0($sp)
    ctx->pc = 0x10a2b8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x10a2bc: 0xe7ad0004  swc1        $f13, 0x4($sp)
    ctx->pc = 0x10a2bcu;
    { float f = ctx->f[13]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x10a2c0: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x10a2c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x10a2c4: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x10a2c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x10a2c8: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x10a2c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x10a2cc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10a2ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10a2d0: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x10a2d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x10a2d4: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x10a2d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a2d8: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x10a2d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x10a2dc: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x10a2dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x10a2e0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x10a2e0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x10a2e4: 0x3e00008  jr          $ra
    ctx->pc = 0x10A2E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A2E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A2E4u;
            // 0x10a2e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x10A2ECu;
    // 0x10a2ec: 0x0  nop
    ctx->pc = 0x10a2ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
