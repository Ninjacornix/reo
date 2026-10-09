#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B7B0
// Address: 0x12b7b0 - 0x12b800
void sub_0012B7B0_0x12b7b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B7B0_0x12b7b0");
#endif

    ctx->pc = 0x12b7b0u;

    // 0x12b7b0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b7b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b7b4: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12b7b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12b7b8: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x12b7b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x12b7bc: 0x3c060021  lui         $a2, 0x21
    ctx->pc = 0x12b7bcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)33 << 16));
    // 0x12b7c0: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x12b7c0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x12b7c4: 0x3c080021  lui         $t0, 0x21
    ctx->pc = 0x12b7c4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)33 << 16));
    // 0x12b7c8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12b7c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12b7cc: 0x246304f8  addiu       $v1, $v1, 0x4F8
    ctx->pc = 0x12b7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1272));
    // 0x12b7d0: 0x24840508  addiu       $a0, $a0, 0x508
    ctx->pc = 0x12b7d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1288));
    // 0x12b7d4: 0x24a50518  addiu       $a1, $a1, 0x518
    ctx->pc = 0x12b7d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1304));
    // 0x12b7d8: 0x24c60528  addiu       $a2, $a2, 0x528
    ctx->pc = 0x12b7d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1320));
    // 0x12b7dc: 0x24e70538  addiu       $a3, $a3, 0x538
    ctx->pc = 0x12b7dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1336));
    // 0x12b7e0: 0x25080548  addiu       $t0, $t0, 0x548
    ctx->pc = 0x12b7e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1352));
    // 0x12b7e4: 0xfc620000  sd          $v0, 0x0($v1)
    ctx->pc = 0x12b7e4u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 2));
    // 0x12b7e8: 0xfc820000  sd          $v0, 0x0($a0)
    ctx->pc = 0x12b7e8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 2));
    // 0x12b7ec: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x12b7ecu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x12b7f0: 0xfcc20000  sd          $v0, 0x0($a2)
    ctx->pc = 0x12b7f0u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 2));
    // 0x12b7f4: 0xfce20000  sd          $v0, 0x0($a3)
    ctx->pc = 0x12b7f4u;
    WRITE64(ADD32(GPR_U32(ctx, 7), 0), GPR_U64(ctx, 2));
    // 0x12b7f8: 0x3e00008  jr          $ra
    ctx->pc = 0x12B7F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B7FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B7F8u;
            // 0x12b7fc: 0xfd020000  sd          $v0, 0x0($t0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 8), 0), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12B800u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
