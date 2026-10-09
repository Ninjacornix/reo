#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182098
// Address: 0x182098 - 0x1820d4
void sub_00182098_0x182098(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182098_0x182098");
#endif

    switch (ctx->pc) {
        case 0x1820a8u: goto label_1820a8;
        case 0x1820c4u: goto label_1820c4;
        default: break;
    }

    ctx->pc = 0x182098u;

    // 0x182098: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x182098u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18209c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18209cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1820a0: 0xc060558  jal         func_181560
    ctx->pc = 0x1820A0u;
    SET_GPR_U32(ctx, 31, 0x1820A8u);
    ctx->pc = 0x181560u;
    if (runtime->hasFunction(0x181560u)) {
        auto targetFn = runtime->lookupFunction(0x181560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820A8u; }
        if (ctx->pc != 0x1820A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181560_0x181560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820A8u; }
        if (ctx->pc != 0x1820A8u) { return; }
    }
    ctx->pc = 0x1820A8u;
label_1820a8:
    // 0x1820a8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1820a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1820ac: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1820acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1820b0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1820b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1820b4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1820B4u;
    {
        const bool branch_taken_0x1820b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1820B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1820B4u;
            // 0x1820b8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1820b4) {
            ctx->pc = 0x1820C8u;
            goto label_1820c8;
        }
    }
    ctx->pc = 0x1820BCu;
    // 0x1820bc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x1820BCu;
    SET_GPR_U32(ctx, 31, 0x1820C4u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820C4u; }
        if (ctx->pc != 0x1820C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820C4u; }
        if (ctx->pc != 0x1820C4u) { return; }
    }
    ctx->pc = 0x1820C4u;
label_1820c4:
    // 0x1820c4: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1820c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_1820c8:
    // 0x1820c8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1820c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1820cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1820CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1820D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1820CCu;
            // 0x1820d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1820A8u: goto label_1820a8;
            case 0x1820C4u: goto label_1820c4;
            case 0x1820C8u: goto label_1820c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1820D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
