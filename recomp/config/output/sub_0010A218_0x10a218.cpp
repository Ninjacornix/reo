#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A218
// Address: 0x10a218 - 0x10a258
void sub_0010A218_0x10a218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A218_0x10a218");
#endif

    ctx->pc = 0x10a218u;

    // 0x10a218: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x10a218u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a21c: 0x2203c  dsll32      $a0, $v0, 0
    ctx->pc = 0x10a21cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10a220: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x10a220u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x10a224: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10a224u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10a228: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x10a228u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x10a22c: 0x3c067ff0  lui         $a2, 0x7FF0
    ctx->pc = 0x10a22cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32752 << 16));
    // 0x10a230: 0x42823  negu        $a1, $a0
    ctx->pc = 0x10a230u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x10a234: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x10a234u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x10a238: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x10a238u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x10a23c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10a23cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10a240: 0x427c2  srl         $a0, $a0, 31
    ctx->pc = 0x10a240u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 31));
    // 0x10a244: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x10a244u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x10a248: 0xc21023  subu        $v0, $a2, $v0
    ctx->pc = 0x10a248u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x10a24c: 0x3e00008  jr          $ra
    ctx->pc = 0x10A24Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A24Cu;
            // 0x10a250: 0x217c2  srl         $v0, $v0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x10A254u;
    // 0x10a254: 0x0  nop
    ctx->pc = 0x10a254u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
