#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013E5E8
// Address: 0x13e5e8 - 0x13e63c
void sub_0013E5E8_0x13e5e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013E5E8_0x13e5e8");
#endif

    switch (ctx->pc) {
        case 0x13e624u: goto label_13e624;
        default: break;
    }

    ctx->pc = 0x13e5e8u;

    // 0x13e5e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13e5e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13e5ec: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13e5ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13e5f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13e5f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13e5f4: 0x24701468  addiu       $s0, $v1, 0x1468
    ctx->pc = 0x13e5f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 5224));
    // 0x13e5f8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13e5f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13e5fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13e5fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13e600: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x13e600u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13e604: 0x10510008  beq         $v0, $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13E604u;
    {
        const bool branch_taken_0x13e604 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x13E608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E604u;
            // 0x13e608: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e604) {
            ctx->pc = 0x13E628u;
            goto label_13e628;
        }
    }
    ctx->pc = 0x13E60Cu;
    // 0x13e60c: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x13e60cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x13e610: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13e610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e614: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13e614u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e618: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13e618u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13e61c: 0xc04e518  jal         func_139460
    ctx->pc = 0x13E61Cu;
    SET_GPR_U32(ctx, 31, 0x13E624u);
    ctx->pc = 0x13E620u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E61Cu;
            // 0x13e620: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E624u; }
        if (ctx->pc != 0x13E624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E624u; }
        if (ctx->pc != 0x13E624u) { return; }
    }
    ctx->pc = 0x13E624u;
label_13e624:
    // 0x13e624: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x13e624u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
label_13e628:
    // 0x13e628: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e628u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e62c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13e62cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e630: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13e630u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e634: 0x3e00008  jr          $ra
    ctx->pc = 0x13E634u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E634u;
            // 0x13e638: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E624u: goto label_13e624;
            case 0x13E628u: goto label_13e628;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E63Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
