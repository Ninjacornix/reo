#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E110
// Address: 0x12e110 - 0x12e134
void sub_0012E110_0x12e110(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E110_0x12e110");
#endif

    ctx->pc = 0x12e110u;

    // 0x12e110: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12e110u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12e114: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x12e114u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x12e118: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12e118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12e11c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12e11cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e120: 0x24849ee0  addiu       $a0, $a0, -0x6120
    ctx->pc = 0x12e120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942432));
    // 0x12e124: 0x240600c0  addiu       $a2, $zero, 0xC0
    ctx->pc = 0x12e124u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x12e128: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12e128u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e12c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12E12Cu;
    ctx->pc = 0x12E130u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E12Cu;
            // 0x12e130: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12E134u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
