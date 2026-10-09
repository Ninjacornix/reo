#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F116C
// Address: 0x1f116c - 0x1f11ac
void sub_001F116C_0x1f116c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F116C_0x1f116c");
#endif

    ctx->pc = 0x1f116cu;

    // 0x1f116c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f116cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f1170: 0xffbe0000  sd          $fp, 0x0($sp)
    ctx->pc = 0x1f1170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 30));
    // 0x1f1174: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1174u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1178: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x1f1178u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f117c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f117cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1180: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f1180u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f1184: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f1184u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1188: 0x9462000e  lhu         $v0, 0xE($v1)
    ctx->pc = 0x1f1188u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
    // 0x1f118c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1f118cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1f1190: 0xa462000e  sh          $v0, 0xE($v1)
    ctx->pc = 0x1f1190u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 14), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f1194: 0x9462000e  lhu         $v0, 0xE($v1)
    ctx->pc = 0x1f1194u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 14)));
    // 0x1f1198: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1198u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f119c: 0xdfbe0000  ld          $fp, 0x0($sp)
    ctx->pc = 0x1f119cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f11a0: 0x27bd0010  addiu       $sp, $sp, 0x10
    ctx->pc = 0x1f11a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1f11a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F11A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F11ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
