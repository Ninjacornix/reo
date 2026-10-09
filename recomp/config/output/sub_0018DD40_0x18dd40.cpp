#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DD40
// Address: 0x18dd40 - 0x18ddd0
void sub_0018DD40_0x18dd40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DD40_0x18dd40");
#endif

    switch (ctx->pc) {
        case 0x18dd98u: goto label_18dd98;
        default: break;
    }

    ctx->pc = 0x18dd40u;

    // 0x18dd40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x18dd40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18dd44: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18dd44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18dd48: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x18dd48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x18dd4c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x18dd4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18dd50: 0x8c24fdb0  lw          $a0, -0x250($at)
    ctx->pc = 0x18dd50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966704)));
    // 0x18dd54: 0x10830008  beq         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x18DD54u;
    {
        const bool branch_taken_0x18dd54 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x18dd54) {
            ctx->pc = 0x18DD78u;
            goto label_18dd78;
        }
    }
    ctx->pc = 0x18DD5Cu;
    // 0x18dd5c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18dd5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18dd60: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x18DD60u;
    {
        const bool branch_taken_0x18dd60 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x18dd60) {
            ctx->pc = 0x18DD78u;
            goto label_18dd78;
        }
    }
    ctx->pc = 0x18DD68u;
    // 0x18dd68: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18DD68u;
    {
        const bool branch_taken_0x18dd68 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x18dd68) {
            ctx->pc = 0x18DD78u;
            goto label_18dd78;
        }
    }
    ctx->pc = 0x18DD70u;
    // 0x18dd70: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x18DD70u;
    {
        const bool branch_taken_0x18dd70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18DD74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DD70u;
            // 0x18dd74: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18dd70) {
            ctx->pc = 0x18DDC4u;
            goto label_18ddc4;
        }
    }
    ctx->pc = 0x18DD78u;
label_18dd78:
    // 0x18dd78: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18dd78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18dd7c: 0x3c02002a  lui         $v0, 0x2A
    ctx->pc = 0x18dd7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)42 << 16));
    // 0x18dd80: 0x8c23fdb4  lw          $v1, -0x24C($at)
    ctx->pc = 0x18dd80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
    // 0x18dd84: 0x2442fdc4  addiu       $v0, $v0, -0x23C
    ctx->pc = 0x18dd84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966724));
    // 0x18dd88: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18dd88u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18dd8c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18dd8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18dd90: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x18DD90u;
    SET_GPR_U32(ctx, 31, 0x18DD98u);
    ctx->pc = 0x18DD94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DD90u;
            // 0x18dd94: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DD98u; }
        if (ctx->pc != 0x18DD98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DD98u; }
        if (ctx->pc != 0x18DD98u) { return; }
    }
    ctx->pc = 0x18DD98u;
label_18dd98:
    // 0x18dd98: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18dd98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18dd9c: 0x3c030008  lui         $v1, 0x8
    ctx->pc = 0x18dd9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8 << 16));
    // 0x18dda0: 0xac22fdb8  sw          $v0, -0x248($at)
    ctx->pc = 0x18dda0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966712), GPR_U32(ctx, 2));
    // 0x18dda4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18dda4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18dda8: 0x8c24fdb8  lw          $a0, -0x248($at)
    ctx->pc = 0x18dda8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966712)));
    // 0x18ddac: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18ddacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18ddb0: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x18ddb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x18ddb4: 0xac24fdc0  sw          $a0, -0x240($at)
    ctx->pc = 0x18ddb4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966720), GPR_U32(ctx, 4));
    // 0x18ddb8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18ddb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18ddbc: 0xac23fdbc  sw          $v1, -0x244($at)
    ctx->pc = 0x18ddbcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966716), GPR_U32(ctx, 3));
    // 0x18ddc0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x18ddc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_18ddc4:
    // 0x18ddc4: 0x3e00008  jr          $ra
    ctx->pc = 0x18DDC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18DDC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DDC4u;
            // 0x18ddc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DD78u: goto label_18dd78;
            case 0x18DD98u: goto label_18dd98;
            case 0x18DDC4u: goto label_18ddc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DDCCu;
    // 0x18ddcc: 0x0  nop
    ctx->pc = 0x18ddccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
