#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001764B0
// Address: 0x1764b0 - 0x1764f8
void sub_001764B0_0x1764b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001764B0_0x1764b0");
#endif

    switch (ctx->pc) {
        case 0x1764ccu: goto label_1764cc;
        default: break;
    }

    ctx->pc = 0x1764b0u;

    // 0x1764b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1764b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1764b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1764b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1764b8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1764b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1764bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1764bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1764c0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1764c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1764c4: 0xc05d99c  jal         func_176670
    ctx->pc = 0x1764C4u;
    SET_GPR_U32(ctx, 31, 0x1764CCu);
    ctx->pc = 0x1764C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1764C4u;
            // 0x1764c8: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176670u;
    if (runtime->hasFunction(0x176670u)) {
        auto targetFn = runtime->lookupFunction(0x176670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1764CCu; }
        if (ctx->pc != 0x1764CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176670_0x176670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1764CCu; }
        if (ctx->pc != 0x1764CCu) { return; }
    }
    ctx->pc = 0x1764CCu;
label_1764cc:
    // 0x1764cc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1764CCu;
    {
        const bool branch_taken_0x1764cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1764D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1764CCu;
            // 0x1764d0: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1764cc) {
            ctx->pc = 0x1764E4u;
            goto label_1764e4;
        }
    }
    ctx->pc = 0x1764D4u;
    // 0x1764d4: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1764d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1764d8: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1764d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1764dc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1764dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1764e0: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1764e0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_1764e4:
    // 0x1764e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1764e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1764e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1764e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1764ec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1764ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1764f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1764F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1764F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1764F0u;
            // 0x1764f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1764CCu: goto label_1764cc;
            case 0x1764E4u: goto label_1764e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1764F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
