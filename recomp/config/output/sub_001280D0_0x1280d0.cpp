#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001280D0
// Address: 0x1280d0 - 0x128128
void sub_001280D0_0x1280d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001280D0_0x1280d0");
#endif

    switch (ctx->pc) {
        case 0x1280f4u: goto label_1280f4;
        case 0x128110u: goto label_128110;
        default: break;
    }

    ctx->pc = 0x1280d0u;

    // 0x1280d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1280d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1280d4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1280d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1280d8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1280d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1280dc: 0x2450c7b8  addiu       $s0, $v0, -0x3848
    ctx->pc = 0x1280dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294952888));
    // 0x1280e0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1280e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1280e4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1280e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1280e8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1280e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1280ec: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1280ECu;
    SET_GPR_U32(ctx, 31, 0x1280F4u);
    ctx->pc = 0x1280F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1280ECu;
            // 0x1280f0: 0x240600ff  addiu       $a2, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1280F4u; }
        if (ctx->pc != 0x1280F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1280F4u; }
        if (ctx->pc != 0x1280F4u) { return; }
    }
    ctx->pc = 0x1280F4u;
label_1280f4:
    // 0x1280f4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1280f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1280f8: 0x8c63c7b0  lw          $v1, -0x3850($v1)
    ctx->pc = 0x1280f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294952880)));
    // 0x1280fc: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1280FCu;
    {
        const bool branch_taken_0x1280fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x128100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1280FCu;
            // 0x128100: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1280fc) {
            ctx->pc = 0x128110u;
            goto label_128110;
        }
    }
    ctx->pc = 0x128104u;
    // 0x128104: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x128104u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128108: 0x60f809  jalr        $v1
    ctx->pc = 0x128108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x128110u);
        ctx->pc = 0x12810Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128108u;
            // 0x12810c: 0x8c44c7b4  lw          $a0, -0x384C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294952884)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x128110u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1280F4u: goto label_1280f4;
            case 0x128110u: goto label_128110;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x128110u; }
            if (ctx->pc != 0x128110u) { return; }
        }
        }
    }
    ctx->pc = 0x128110u;
label_128110:
    // 0x128110: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x128110u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128114: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x128114u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128118: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x128118u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12811c: 0x8050600  j           func_141800
    ctx->pc = 0x12811Cu;
    ctx->pc = 0x128120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12811Cu;
            // 0x128120: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141800u;
    if (runtime->hasFunction(0x141800u)) {
        auto targetFn = runtime->lookupFunction(0x141800u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141800_0x141800(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x128124u;
    // 0x128124: 0x0  nop
    ctx->pc = 0x128124u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
