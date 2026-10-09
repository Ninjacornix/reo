#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00121EF0
// Address: 0x121ef0 - 0x121f28
void sub_00121EF0_0x121ef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00121EF0_0x121ef0");
#endif

    ctx->pc = 0x121ef0u;

    // 0x121ef0: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x121ef0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121ef4: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x121ef4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x121ef8: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x121ef8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x121efc: 0x3c05ffff  lui         $a1, 0xFFFF
    ctx->pc = 0x121efcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65535 << 16));
    // 0x121f00: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x121f00u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x121f04: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x121f04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x121f08: 0x852024  and         $a0, $a0, $a1
    ctx->pc = 0x121f08u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x121f0c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x121f0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x121f10: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x121f10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x121f14: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x121f14u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x121f18: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x121f18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x121f1c: 0x3e00008  jr          $ra
    ctx->pc = 0x121F1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x121F24u;
    // 0x121f24: 0x0  nop
    ctx->pc = 0x121f24u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
