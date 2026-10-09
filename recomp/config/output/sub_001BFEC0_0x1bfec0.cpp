#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BFEC0
// Address: 0x1bfec0 - 0x1bff70
void sub_001BFEC0_0x1bfec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BFEC0_0x1bfec0");
#endif

    switch (ctx->pc) {
        case 0x1bfef4u: goto label_1bfef4;
        case 0x1bff1cu: goto label_1bff1c;
        case 0x1bff44u: goto label_1bff44;
        default: break;
    }

    ctx->pc = 0x1bfec0u;

    // 0x1bfec0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bfec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bfec4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bfec4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bfec8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bfec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bfecc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bfeccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bfed0: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1bfed0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1bfed4: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1BFED4u;
    {
        const bool branch_taken_0x1bfed4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BFED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFED4u;
            // 0x1bfed8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfed4) {
            ctx->pc = 0x1BFF3Cu;
            goto label_1bff3c;
        }
    }
    ctx->pc = 0x1BFEDCu;
    // 0x1bfedc: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFEDCu;
    {
        const bool branch_taken_0x1bfedc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bfedc) {
            ctx->pc = 0x1BFEECu;
            goto label_1bfeec;
        }
    }
    ctx->pc = 0x1BFEE4u;
    // 0x1bfee4: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1BFEE4u;
    {
        const bool branch_taken_0x1bfee4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFEE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFEE4u;
            // 0x1bfee8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bfee4) {
            ctx->pc = 0x1BFF60u;
            goto label_1bff60;
        }
    }
    ctx->pc = 0x1BFEECu;
label_1bfeec:
    // 0x1bfeec: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFEECu;
    SET_GPR_U32(ctx, 31, 0x1BFEF4u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFEF4u; }
        if (ctx->pc != 0x1BFEF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFEF4u; }
        if (ctx->pc != 0x1BFEF4u) { return; }
    }
    ctx->pc = 0x1BFEF4u;
label_1bfef4:
    // 0x1bfef4: 0x4400019  bltz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1BFEF4u;
    {
        const bool branch_taken_0x1bfef4 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bfef4) {
            ctx->pc = 0x1BFF5Cu;
            goto label_1bff5c;
        }
    }
    ctx->pc = 0x1BFEFCu;
    // 0x1bfefc: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bfefcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bff00: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1bff00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1bff04: 0x24426c40  addiu       $v0, $v0, 0x6C40
    ctx->pc = 0x1bff04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 27712));
    // 0x1bff08: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1bff08u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1bff0c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bff0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bff10: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1bff10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bff14: 0xc06052a  jal         func_1814A8
    ctx->pc = 0x1BFF14u;
    SET_GPR_U32(ctx, 31, 0x1BFF1Cu);
    ctx->pc = 0x1BFF18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFF14u;
            // 0x1bff18: 0x26050044  addiu       $a1, $s0, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1814A8u;
    if (runtime->hasFunction(0x1814A8u)) {
        auto targetFn = runtime->lookupFunction(0x1814A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFF1Cu; }
        if (ctx->pc != 0x1BFF1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001814A8_0x1814a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFF1Cu; }
        if (ctx->pc != 0x1BFF1Cu) { return; }
    }
    ctx->pc = 0x1BFF1Cu;
label_1bff1c:
    // 0x1bff1c: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BFF1Cu;
    {
        const bool branch_taken_0x1bff1c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1bff1c) {
            ctx->pc = 0x1BFF2Cu;
            goto label_1bff2c;
        }
    }
    ctx->pc = 0x1BFF24u;
    // 0x1bff24: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1BFF24u;
    {
        const bool branch_taken_0x1bff24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFF28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFF24u;
            // 0x1bff28: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bff24) {
            ctx->pc = 0x1BFF60u;
            goto label_1bff60;
        }
    }
    ctx->pc = 0x1BFF2Cu;
label_1bff2c:
    // 0x1bff2c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1bff2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bff30: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1bff30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bff34: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1BFF34u;
    {
        const bool branch_taken_0x1bff34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFF38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFF34u;
            // 0x1bff38: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bff34) {
            ctx->pc = 0x1BFF5Cu;
            goto label_1bff5c;
        }
    }
    ctx->pc = 0x1BFF3Cu;
label_1bff3c:
    // 0x1bff3c: 0xc06fe04  jal         func_1BF810
    ctx->pc = 0x1BFF3Cu;
    SET_GPR_U32(ctx, 31, 0x1BFF44u);
    ctx->pc = 0x1BF810u;
    if (runtime->hasFunction(0x1BF810u)) {
        auto targetFn = runtime->lookupFunction(0x1BF810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFF44u; }
        if (ctx->pc != 0x1BFF44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BF810_0x1bf810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BFF44u; }
        if (ctx->pc != 0x1BFF44u) { return; }
    }
    ctx->pc = 0x1BFF44u;
label_1bff44:
    // 0x1bff44: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BFF44u;
    {
        const bool branch_taken_0x1bff44 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bff44) {
            ctx->pc = 0x1BFF5Cu;
            goto label_1bff5c;
        }
    }
    ctx->pc = 0x1BFF4Cu;
    // 0x1bff4c: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1bff4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1bff50: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x1bff50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1bff54: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1BFF54u;
    {
        const bool branch_taken_0x1bff54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BFF58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFF54u;
            // 0x1bff58: 0x40102a  slt         $v0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bff54) {
            ctx->pc = 0x1BFF60u;
            goto label_1bff60;
        }
    }
    ctx->pc = 0x1BFF5Cu;
label_1bff5c:
    // 0x1bff5c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1bff5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1bff60:
    // 0x1bff60: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bff60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bff64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bff64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bff68: 0x3e00008  jr          $ra
    ctx->pc = 0x1BFF68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BFF6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BFF68u;
            // 0x1bff6c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BFEECu: goto label_1bfeec;
            case 0x1BFEF4u: goto label_1bfef4;
            case 0x1BFF1Cu: goto label_1bff1c;
            case 0x1BFF2Cu: goto label_1bff2c;
            case 0x1BFF3Cu: goto label_1bff3c;
            case 0x1BFF44u: goto label_1bff44;
            case 0x1BFF5Cu: goto label_1bff5c;
            case 0x1BFF60u: goto label_1bff60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BFF70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
