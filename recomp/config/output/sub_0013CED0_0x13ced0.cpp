#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CED0
// Address: 0x13ced0 - 0x13cf10
void sub_0013CED0_0x13ced0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CED0_0x13ced0");
#endif

    ctx->pc = 0x13ced0u;

    // 0x13ced0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ced0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ced4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13CED4u;
    {
        const bool branch_taken_0x13ced4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CED4u;
            // 0x13ced8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ced4) {
            ctx->pc = 0x13CEF0u;
            goto label_13cef0;
        }
    }
    ctx->pc = 0x13CEDCu;
    // 0x13cedc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13cedcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13cee0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13cee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13cee4: 0x2484d368  addiu       $a0, $a0, -0x2C98
    ctx->pc = 0x13cee4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
    // 0x13cee8: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13CEE8u;
    ctx->pc = 0x13CEECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CEE8u;
            // 0x13ceec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13CEF0u;
label_13cef0:
    // 0x13cef0: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x13cef0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x13cef4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13CEF4u;
    {
        const bool branch_taken_0x13cef4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CEF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CEF4u;
            // 0x13cef8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cef4) {
            ctx->pc = 0x13CF08u;
            goto label_13cf08;
        }
    }
    ctx->pc = 0x13CEFCu;
    // 0x13cefc: 0xac800024  sw          $zero, 0x24($a0)
    ctx->pc = 0x13cefcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
    // 0x13cf00: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x13cf00u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x13cf04: 0xac800020  sw          $zero, 0x20($a0)
    ctx->pc = 0x13cf04u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
label_13cf08:
    // 0x13cf08: 0x3e00008  jr          $ra
    ctx->pc = 0x13CF08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CF08u;
            // 0x13cf0c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CEF0u: goto label_13cef0;
            case 0x13CF08u: goto label_13cf08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CF10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
