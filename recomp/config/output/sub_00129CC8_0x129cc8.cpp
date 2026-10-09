#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129CC8
// Address: 0x129cc8 - 0x129d14
void sub_00129CC8_0x129cc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129CC8_0x129cc8");
#endif

    switch (ctx->pc) {
        case 0x129ce8u: goto label_129ce8;
        default: break;
    }

    ctx->pc = 0x129cc8u;

    // 0x129cc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129cc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x129ccc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129cccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129cd0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x129cd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129cd4: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x129CD4u;
    {
        const bool branch_taken_0x129cd4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x129CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129CD4u;
            // 0x129cd8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129cd4) {
            ctx->pc = 0x129CF8u;
            goto label_129cf8;
        }
    }
    ctx->pc = 0x129CDCu;
    // 0x129cdc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129ce0: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129CE0u;
    SET_GPR_U32(ctx, 31, 0x129CE8u);
    ctx->pc = 0x129CE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129CE0u;
            // 0x129ce4: 0x2484a1b0  addiu       $a0, $a0, -0x5E50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129CE8u; }
        if (ctx->pc != 0x129CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129CE8u; }
        if (ctx->pc != 0x129CE8u) { return; }
    }
    ctx->pc = 0x129CE8u;
label_129ce8:
    // 0x129ce8: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x129ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x129cec: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x129CECu;
    {
        const bool branch_taken_0x129cec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129CECu;
            // 0x129cf0: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129cec) {
            ctx->pc = 0x129D04u;
            goto label_129d04;
        }
    }
    ctx->pc = 0x129CF4u;
    // 0x129cf4: 0x0  nop
    ctx->pc = 0x129cf4u;
    // NOP
label_129cf8:
    // 0x129cf8: 0x8c820018  lw          $v0, 0x18($a0)
    ctx->pc = 0x129cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x129cfc: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x129cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x129d00: 0x8c82001c  lw          $v0, 0x1C($a0)
    ctx->pc = 0x129d00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
label_129d04:
    // 0x129d04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129d04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129d08: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x129d08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129d0c: 0x3e00008  jr          $ra
    ctx->pc = 0x129D0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129D0Cu;
            // 0x129d10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129CE8u: goto label_129ce8;
            case 0x129CF8u: goto label_129cf8;
            case 0x129D04u: goto label_129d04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129D14u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
