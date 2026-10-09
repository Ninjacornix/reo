#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D040
// Address: 0x13d040 - 0x13d0a0
void sub_0013D040_0x13d040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D040_0x13d040");
#endif

    switch (ctx->pc) {
        case 0x13d068u: goto label_13d068;
        case 0x13d07cu: goto label_13d07c;
        default: break;
    }

    ctx->pc = 0x13d040u;

    // 0x13d040: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13d040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13d044: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13d044u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13d048: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13d048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13d04c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13d04cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13d050: 0x2450e110  addiu       $s0, $v0, -0x1EF0
    ctx->pc = 0x13d050u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294959376));
    // 0x13d054: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13d054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13d058: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x13d058u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13d05c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13d05cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13d060: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x13d060u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d064: 0x0  nop
    ctx->pc = 0x13d064u;
    // NOP
label_13d068:
    // 0x13d068: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x13d068u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13d06c: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13D06Cu;
    {
        const bool branch_taken_0x13d06c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x13d06c) {
            ctx->pc = 0x13D070u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D06Cu;
            // 0x13d070: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D080u;
            goto label_13d080;
        }
    }
    ctx->pc = 0x13D074u;
    // 0x13d074: 0xc04f66e  jal         func_13D9B8
    ctx->pc = 0x13D074u;
    SET_GPR_U32(ctx, 31, 0x13D07Cu);
    ctx->pc = 0x13D078u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D074u;
            // 0x13d078: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D9B8u;
    if (runtime->hasFunction(0x13D9B8u)) {
        auto targetFn = runtime->lookupFunction(0x13D9B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D07Cu; }
        if (ctx->pc != 0x13D07Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D9B8_0x13d9b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D07Cu; }
        if (ctx->pc != 0x13D07Cu) { return; }
    }
    ctx->pc = 0x13D07Cu;
label_13d07c:
    // 0x13d07c: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x13d07cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_13d080:
    // 0x13d080: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x13D080u;
    {
        const bool branch_taken_0x13d080 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x13D084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D080u;
            // 0x13d084: 0x26100238  addiu       $s0, $s0, 0x238 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 568));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d080) {
            ctx->pc = 0x13D068u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d068;
        }
    }
    ctx->pc = 0x13D088u;
    // 0x13d088: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d088u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d08c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13d08cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d090: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13d090u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d094: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13d094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13d098: 0x3e00008  jr          $ra
    ctx->pc = 0x13D098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D09Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D098u;
            // 0x13d09c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D068u: goto label_13d068;
            case 0x13D07Cu: goto label_13d07c;
            case 0x13D080u: goto label_13d080;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D0A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
