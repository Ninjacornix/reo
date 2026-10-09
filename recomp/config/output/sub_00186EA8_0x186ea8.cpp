#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186EA8
// Address: 0x186ea8 - 0x186ef0
void sub_00186EA8_0x186ea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186EA8_0x186ea8");
#endif

    ctx->pc = 0x186ea8u;

    // 0x186ea8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x186ea8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186eac: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x186eacu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x186eb0: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x186eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x186eb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x186eb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x186eb8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x186eb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x186ebc: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x186ebcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x186ec0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x186ec0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x186ec4: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x186ec4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x186ec8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x186ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x186ecc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x186eccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x186ed0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x186ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x186ed4: 0x9442fa42  lhu         $v0, -0x5BE($v0)
    ctx->pc = 0x186ed4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294965826)));
    // 0x186ed8: 0x470018  mult        $zero, $v0, $a3
    ctx->pc = 0x186ed8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x186edc: 0x3812  mflo        $a3
    ctx->pc = 0x186edcu;
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x186ee0: 0xc20018  mult        $zero, $a2, $v0
    ctx->pc = 0x186ee0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x186ee4: 0x3012  mflo        $a2
    ctx->pc = 0x186ee4u;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x186ee8: 0x80620d2  j           func_188348
    ctx->pc = 0x186EE8u;
    ctx->pc = 0x186EECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186EE8u;
            // 0x186eec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188348u;
    if (runtime->hasFunction(0x188348u)) {
        auto targetFn = runtime->lookupFunction(0x188348u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00188348_0x188348(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x186EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
