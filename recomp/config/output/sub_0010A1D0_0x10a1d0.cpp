#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A1D0
// Address: 0x10a1d0 - 0x10a218
void sub_0010A1D0_0x10a1d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A1D0_0x10a1d0");
#endif

    ctx->pc = 0x10a1d0u;

    // 0x10a1d0: 0x4183c  dsll32      $v1, $a0, 0
    ctx->pc = 0x10a1d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x10a1d4: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x10a1d4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x10a1d8: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x10a1d8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x10a1dc: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x10a1dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x10a1e0: 0x3c067ff0  lui         $a2, 0x7FF0
    ctx->pc = 0x10a1e0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32752 << 16));
    // 0x10a1e4: 0x32823  negu        $a1, $v1
    ctx->pc = 0x10a1e4u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
    // 0x10a1e8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10a1e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10a1ec: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x10a1ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x10a1f0: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x10a1f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x10a1f4: 0x31fc2  srl         $v1, $v1, 31
    ctx->pc = 0x10a1f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x10a1f8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10a1f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10a1fc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x10a1fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x10a200: 0xc42023  subu        $a0, $a2, $a0
    ctx->pc = 0x10a200u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x10a204: 0x41823  negu        $v1, $a0
    ctx->pc = 0x10a204u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x10a208: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x10a208u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x10a20c: 0x427c2  srl         $a0, $a0, 31
    ctx->pc = 0x10a20cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 31));
    // 0x10a210: 0x3e00008  jr          $ra
    ctx->pc = 0x10A210u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A210u;
            // 0x10a214: 0x441023  subu        $v0, $v0, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x10A218u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
