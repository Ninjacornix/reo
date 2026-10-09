#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F34EC
// Address: 0x1f34ec - 0x1f351c
void sub_001F34EC_0x1f34ec(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F34EC_0x1f34ec");
#endif

    ctx->pc = 0x1f34ecu;

    // 0x1f34ec: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f34ecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f34f0: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f34f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f34f4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f34f4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f34f8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1f34f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f34fc: 0x2442002c  addiu       $v0, $v0, 0x2C
    ctx->pc = 0x1f34fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 44));
    // 0x1f3500: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1f3500u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1f3504: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f3504u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3508: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3508u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f350c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f350cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3510: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f3510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f3514: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3514u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1F351Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
