#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DCE0
// Address: 0x18dce0 - 0x18dd40
void sub_0018DCE0_0x18dce0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DCE0_0x18dce0");
#endif

    switch (ctx->pc) {
        case 0x18dcf4u: goto label_18dcf4;
        case 0x18dcfcu: goto label_18dcfc;
        case 0x18dd28u: goto label_18dd28;
        default: break;
    }

    ctx->pc = 0x18dce0u;

    // 0x18dce0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x18dce0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18dce4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18dce4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18dce8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18dce8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18dcec: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x18dcecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dcf0: 0x3c040008  lui         $a0, 0x8
    ctx->pc = 0x18dcf0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8 << 16));
label_18dcf4:
    // 0x18dcf4: 0xc063714  jal         func_18DC50
    ctx->pc = 0x18DCF4u;
    SET_GPR_U32(ctx, 31, 0x18DCFCu);
    ctx->pc = 0x18DCF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DCF4u;
            // 0x18dcf8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC50u;
    if (runtime->hasFunction(0x18DC50u)) {
        auto targetFn = runtime->lookupFunction(0x18DC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DCFCu; }
        if (ctx->pc != 0x18DCFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DCFCu; }
        if (ctx->pc != 0x18DCFCu) { return; }
    }
    ctx->pc = 0x18DCFCu;
label_18dcfc:
    // 0x18dcfc: 0x3c03002a  lui         $v1, 0x2A
    ctx->pc = 0x18dcfcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)42 << 16));
    // 0x18dd00: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x18dd00u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x18dd04: 0x2463f9b0  addiu       $v1, $v1, -0x650
    ctx->pc = 0x18dd04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294965680));
    // 0x18dd08: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x18dd08u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x18dd0c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x18dd0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18dd10: 0xac620414  sw          $v0, 0x414($v1)
    ctx->pc = 0x18dd10u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1044), GPR_U32(ctx, 2));
    // 0x18dd14: 0x2a020002  slti        $v0, $s0, 0x2
    ctx->pc = 0x18dd14u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x18dd18: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x18DD18u;
    {
        const bool branch_taken_0x18dd18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18DD1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DD18u;
            // 0x18dd1c: 0x3c040008  lui         $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18dd18) {
            ctx->pc = 0x18DCF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18dcf4;
        }
    }
    ctx->pc = 0x18DD20u;
    // 0x18dd20: 0xc063750  jal         func_18DD40
    ctx->pc = 0x18DD20u;
    SET_GPR_U32(ctx, 31, 0x18DD28u);
    ctx->pc = 0x18DD40u;
    if (runtime->hasFunction(0x18DD40u)) {
        auto targetFn = runtime->lookupFunction(0x18DD40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DD28u; }
        if (ctx->pc != 0x18DD28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DD40_0x18dd40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DD28u; }
        if (ctx->pc != 0x18DD28u) { return; }
    }
    ctx->pc = 0x18DD28u;
label_18dd28:
    // 0x18dd28: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x18dd28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18dd2c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18dd2cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18dd30: 0x3e00008  jr          $ra
    ctx->pc = 0x18DD30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18DD34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DD30u;
            // 0x18dd34: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DCF4u: goto label_18dcf4;
            case 0x18DCFCu: goto label_18dcfc;
            case 0x18DD28u: goto label_18dd28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DD38u;
    // 0x18dd38: 0x0  nop
    ctx->pc = 0x18dd38u;
    // NOP
    // 0x18dd3c: 0x0  nop
    ctx->pc = 0x18dd3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
