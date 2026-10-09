#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001600E8
// Address: 0x1600e8 - 0x160140
void sub_001600E8_0x1600e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001600E8_0x1600e8");
#endif

    ctx->pc = 0x1600e8u;

    // 0x1600e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1600e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1600ec: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1600ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1600f0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1600f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1600f4: 0x14a00006  bnez        $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1600F4u;
    {
        const bool branch_taken_0x1600f4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1600F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1600F4u;
            // 0x1600f8: 0x8c440040  lw          $a0, 0x40($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1600f4) {
            ctx->pc = 0x160110u;
            goto label_160110;
        }
    }
    ctx->pc = 0x1600FCu;
    // 0x1600fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1600fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160100: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x160100u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x160104: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x160104u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160108: 0x805d4ce  j           func_175338
    ctx->pc = 0x160108u;
    ctx->pc = 0x16010Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160108u;
            // 0x16010c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160110u;
label_160110:
    // 0x160110: 0x8c43000c  lw          $v1, 0xC($v0)
    ctx->pc = 0x160110u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x160114: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x160114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160118: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x160118u;
    {
        const bool branch_taken_0x160118 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x16011Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160118u;
            // 0x16011c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160118) {
            ctx->pc = 0x160130u;
            goto label_160130;
        }
    }
    ctx->pc = 0x160120u;
    // 0x160120: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x160120u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x160124: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x160124u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x160128: 0x805d4ce  j           func_175338
    ctx->pc = 0x160128u;
    ctx->pc = 0x16012Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160128u;
            // 0x16012c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160130u;
label_160130:
    // 0x160130: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x160130u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x160134: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x160134u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x160138: 0x805d4ce  j           func_175338
    ctx->pc = 0x160138u;
    ctx->pc = 0x16013Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160138u;
            // 0x16013c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160140u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
