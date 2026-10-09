#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DD50
// Address: 0x15dd50 - 0x15ddb8
void sub_0015DD50_0x15dd50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DD50_0x15dd50");
#endif

    switch (ctx->pc) {
        case 0x15dda4u: goto label_15dda4;
        default: break;
    }

    ctx->pc = 0x15dd50u;

    // 0x15dd50: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15dd50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15dd54: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x15dd54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15dd58: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15dd58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15dd5c: 0x2c850003  sltiu       $a1, $a0, 0x3
    ctx->pc = 0x15dd5cu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x15dd60: 0x10820011  beq         $a0, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x15DD60u;
    {
        const bool branch_taken_0x15dd60 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15DD64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD60u;
            // 0x15dd64: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dd60) {
            ctx->pc = 0x15DDA8u;
            goto label_15dda8;
        }
    }
    ctx->pc = 0x15DD68u;
    // 0x15dd68: 0x50a00005  beql        $a1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15DD68u;
    {
        const bool branch_taken_0x15dd68 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x15dd68) {
            ctx->pc = 0x15DD6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD68u;
            // 0x15dd6c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DD80u;
            goto label_15dd80;
        }
    }
    ctx->pc = 0x15DD70u;
    // 0x15dd70: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15dd70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15dd74: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x15DD74u;
    {
        const bool branch_taken_0x15dd74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DD78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD74u;
            // 0x15dd78: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dd74) {
            ctx->pc = 0x15DD90u;
            goto label_15dd90;
        }
    }
    ctx->pc = 0x15DD7Cu;
    // 0x15dd7c: 0x0  nop
    ctx->pc = 0x15dd7cu;
    // NOP
label_15dd80:
    // 0x15dd80: 0x10820009  beq         $a0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15DD80u;
    {
        const bool branch_taken_0x15dd80 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15DD84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD80u;
            // 0x15dd84: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dd80) {
            ctx->pc = 0x15DDA8u;
            goto label_15dda8;
        }
    }
    ctx->pc = 0x15DD88u;
    // 0x15dd88: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x15dd88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x15dd8c: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x15dd8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_15dd90:
    // 0x15dd90: 0x10820006  beq         $a0, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15DD90u;
    {
        const bool branch_taken_0x15dd90 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15DD94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD90u;
            // 0x15dd94: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dd90) {
            ctx->pc = 0x15DDACu;
            goto label_15ddac;
        }
    }
    ctx->pc = 0x15DD98u;
    // 0x15dd98: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15dd98u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15dd9c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15DD9Cu;
    SET_GPR_U32(ctx, 31, 0x15DDA4u);
    ctx->pc = 0x15DDA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD9Cu;
            // 0x15dda0: 0x2484eca0  addiu       $a0, $a0, -0x1360 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962336));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DDA4u; }
        if (ctx->pc != 0x15DDA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DDA4u; }
        if (ctx->pc != 0x15DDA4u) { return; }
    }
    ctx->pc = 0x15DDA4u;
label_15dda4:
    // 0x15dda4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15dda4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_15dda8:
    // 0x15dda8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15dda8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_15ddac:
    // 0x15ddac: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x15ddacu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ddb0: 0x3e00008  jr          $ra
    ctx->pc = 0x15DDB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DDB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DDB0u;
            // 0x15ddb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DD80u: goto label_15dd80;
            case 0x15DD90u: goto label_15dd90;
            case 0x15DDA4u: goto label_15dda4;
            case 0x15DDA8u: goto label_15dda8;
            case 0x15DDACu: goto label_15ddac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15DDB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
