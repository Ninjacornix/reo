#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD9B0
// Address: 0x1bd9b0 - 0x1bda04
void sub_001BD9B0_0x1bd9b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD9B0_0x1bd9b0");
#endif

    switch (ctx->pc) {
        case 0x1bd9c4u: goto label_1bd9c4;
        case 0x1bd9e0u: goto label_1bd9e0;
        default: break;
    }

    ctx->pc = 0x1bd9b0u;

    // 0x1bd9b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bd9b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bd9b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bd9b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bd9b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bd9b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bd9bc: 0xc06f8e0  jal         func_1BE380
    ctx->pc = 0x1BD9BCu;
    SET_GPR_U32(ctx, 31, 0x1BD9C4u);
    ctx->pc = 0x1BD9C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD9BCu;
            // 0x1bd9c0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE380u;
    if (runtime->hasFunction(0x1BE380u)) {
        auto targetFn = runtime->lookupFunction(0x1BE380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD9C4u; }
        if (ctx->pc != 0x1BD9C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE380_0x1be380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD9C4u; }
        if (ctx->pc != 0x1BD9C4u) { return; }
    }
    ctx->pc = 0x1BD9C4u;
label_1bd9c4:
    // 0x1bd9c4: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x1bd9c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1bd9c8: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BD9C8u;
    {
        const bool branch_taken_0x1bd9c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BD9CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD9C8u;
            // 0x1bd9cc: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd9c8) {
            ctx->pc = 0x1BD9E8u;
            goto label_1bd9e8;
        }
    }
    ctx->pc = 0x1BD9D0u;
    // 0x1bd9d0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BD9D0u;
    {
        const bool branch_taken_0x1bd9d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd9d0) {
            ctx->pc = 0x1BD9E8u;
            goto label_1bd9e8;
        }
    }
    ctx->pc = 0x1BD9D8u;
    // 0x1bd9d8: 0xc06f660  jal         func_1BD980
    ctx->pc = 0x1BD9D8u;
    SET_GPR_U32(ctx, 31, 0x1BD9E0u);
    ctx->pc = 0x1BD9DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD9D8u;
            // 0x1bd9dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD980u;
    if (runtime->hasFunction(0x1BD980u)) {
        auto targetFn = runtime->lookupFunction(0x1BD980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD9E0u; }
        if (ctx->pc != 0x1BD9E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD980_0x1bd980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD9E0u; }
        if (ctx->pc != 0x1BD9E0u) { return; }
    }
    ctx->pc = 0x1BD9E0u;
label_1bd9e0:
    // 0x1bd9e0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BD9E0u;
    {
        const bool branch_taken_0x1bd9e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD9E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD9E0u;
            // 0x1bd9e4: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd9e0) {
            ctx->pc = 0x1BD9F8u;
            goto label_1bd9f8;
        }
    }
    ctx->pc = 0x1BD9E8u;
label_1bd9e8:
    // 0x1bd9e8: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x1bd9e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bd9ec: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bd9ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bd9f0: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1bd9f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1bd9f4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bd9f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1bd9f8:
    // 0x1bd9f8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bd9f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd9fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD9FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BDA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD9FCu;
            // 0x1bda00: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD9C4u: goto label_1bd9c4;
            case 0x1BD9E0u: goto label_1bd9e0;
            case 0x1BD9E8u: goto label_1bd9e8;
            case 0x1BD9F8u: goto label_1bd9f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BDA04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
