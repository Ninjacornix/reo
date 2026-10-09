#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182880
// Address: 0x182880 - 0x1828e8
void sub_00182880_0x182880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182880_0x182880");
#endif

    ctx->pc = 0x182880u;

    // 0x182880: 0x24020898  addiu       $v0, $zero, 0x898
    ctx->pc = 0x182880u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
    // 0x182884: 0x3c060028  lui         $a2, 0x28
    ctx->pc = 0x182884u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)40 << 16));
    // 0x182888: 0x822018  mult        $a0, $a0, $v0
    ctx->pc = 0x182888u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x18288c: 0x24c65b48  addiu       $a2, $a2, 0x5B48
    ctx->pc = 0x18288cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 23368));
    // 0x182890: 0x240bffff  addiu       $t3, $zero, -0x1
    ctx->pc = 0x182890u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x182894: 0x24c70004  addiu       $a3, $a2, 0x4
    ctx->pc = 0x182894u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x182898: 0x24ca0808  addiu       $t2, $a2, 0x808
    ctx->pc = 0x182898u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 6), 2056));
    // 0x18289c: 0x3c0c0024  lui         $t4, 0x24
    ctx->pc = 0x18289cu;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)36 << 16));
    // 0x1828a0: 0x24830890  addiu       $v1, $a0, 0x890
    ctx->pc = 0x1828a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 2192));
    // 0x1828a4: 0x24850800  addiu       $a1, $a0, 0x800
    ctx->pc = 0x1828a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 2048));
    // 0x1828a8: 0xa74821  addu        $t1, $a1, $a3
    ctx->pc = 0x1828a8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1828ac: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1828acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1828b0: 0x664021  addu        $t0, $v1, $a2
    ctx->pc = 0x1828b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1828b4: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x1828b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1828b8: 0x8a2021  addu        $a0, $a0, $t2
    ctx->pc = 0x1828b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x1828bc: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1828bcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1828c0: 0xacab0000  sw          $t3, 0x0($a1)
    ctx->pc = 0x1828c0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 11));
    // 0x1828c4: 0xad2b0000  sw          $t3, 0x0($t1)
    ctx->pc = 0x1828c4u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 11));
    // 0x1828c8: 0xad000000  sw          $zero, 0x0($t0)
    ctx->pc = 0x1828c8u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
    // 0x1828cc: 0x258717c8  addiu       $a3, $t4, 0x17C8
    ctx->pc = 0x1828ccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 12), 6088));
    // 0x1828d0: 0x80e30000  lb          $v1, 0x0($a3)
    ctx->pc = 0x1828d0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1828d4: 0x80e50001  lb          $a1, 0x1($a3)
    ctx->pc = 0x1828d4u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1828d8: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1828d8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1828dc: 0xa0850001  sb          $a1, 0x1($a0)
    ctx->pc = 0x1828dcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 5));
    // 0x1828e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1828E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1828E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1828E0u;
            // 0x1828e4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1828E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
