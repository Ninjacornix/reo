#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFBF0
// Address: 0x1afbf0 - 0x1afc54
void sub_001AFBF0_0x1afbf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFBF0_0x1afbf0");
#endif

    switch (ctx->pc) {
        case 0x1afc00u: goto label_1afc00;
        case 0x1afc38u: goto label_1afc38;
        case 0x1afc48u: goto label_1afc48;
        default: break;
    }

    ctx->pc = 0x1afbf0u;

    // 0x1afbf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afbf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afbf4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afbf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afbf8: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFBF8u;
    SET_GPR_U32(ctx, 31, 0x1AFC00u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC00u; }
        if (ctx->pc != 0x1AFC00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC00u; }
        if (ctx->pc != 0x1AFC00u) { return; }
    }
    ctx->pc = 0x1AFC00u;
label_1afc00:
    // 0x1afc00: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afc00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afc04: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFC04u;
    {
        const bool branch_taken_0x1afc04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFC04u;
            // 0x1afc08: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afc04) {
            ctx->pc = 0x1AFC48u;
            goto label_1afc48;
        }
    }
    ctx->pc = 0x1AFC0Cu;
    // 0x1afc0c: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1AFC0Cu;
    {
        const bool branch_taken_0x1afc0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afc0c) {
            ctx->pc = 0x1AFC48u;
            goto label_1afc48;
        }
    }
    ctx->pc = 0x1AFC14u;
    // 0x1afc14: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afc14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afc18: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFC18u;
    {
        const bool branch_taken_0x1afc18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afc18) {
            ctx->pc = 0x1AFC40u;
            goto label_1afc40;
        }
    }
    ctx->pc = 0x1AFC20u;
    // 0x1afc20: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFC20u;
    {
        const bool branch_taken_0x1afc20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afc20) {
            ctx->pc = 0x1AFC30u;
            goto label_1afc30;
        }
    }
    ctx->pc = 0x1AFC28u;
    // 0x1afc28: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AFC28u;
    {
        const bool branch_taken_0x1afc28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFC2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFC28u;
            // 0x1afc2c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afc28) {
            ctx->pc = 0x1AFC4Cu;
            goto label_1afc4c;
        }
    }
    ctx->pc = 0x1AFC30u;
label_1afc30:
    // 0x1afc30: 0xc2042b0  jal         func_810AC0
    ctx->pc = 0x1AFC30u;
    SET_GPR_U32(ctx, 31, 0x1AFC38u);
    ctx->pc = 0x810AC0u;
    {
        auto targetFn = runtime->lookupFunction(0x810AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC38u; }
        if (ctx->pc != 0x1AFC38u) { return; }
    }
    ctx->pc = 0x1AFC38u;
label_1afc38:
    // 0x1afc38: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFC38u;
    {
        const bool branch_taken_0x1afc38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afc38) {
            ctx->pc = 0x1AFC48u;
            goto label_1afc48;
        }
    }
    ctx->pc = 0x1AFC40u;
label_1afc40:
    // 0x1afc40: 0xc204ae0  jal         func_812B80
    ctx->pc = 0x1AFC40u;
    SET_GPR_U32(ctx, 31, 0x1AFC48u);
    ctx->pc = 0x812B80u;
    {
        auto targetFn = runtime->lookupFunction(0x812B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC48u; }
        if (ctx->pc != 0x1AFC48u) { return; }
    }
    ctx->pc = 0x1AFC48u;
label_1afc48:
    // 0x1afc48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afc48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afc4c:
    // 0x1afc4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFC4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFC50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFC4Cu;
            // 0x1afc50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFC00u: goto label_1afc00;
            case 0x1AFC30u: goto label_1afc30;
            case 0x1AFC38u: goto label_1afc38;
            case 0x1AFC40u: goto label_1afc40;
            case 0x1AFC48u: goto label_1afc48;
            case 0x1AFC4Cu: goto label_1afc4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFC54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
