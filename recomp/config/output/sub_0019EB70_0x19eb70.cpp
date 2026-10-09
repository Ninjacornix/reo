#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019EB70
// Address: 0x19eb70 - 0x19ec00
void sub_0019EB70_0x19eb70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019EB70_0x19eb70");
#endif

    switch (ctx->pc) {
        case 0x19ebd4u: goto label_19ebd4;
        default: break;
    }

    ctx->pc = 0x19eb70u;

    // 0x19eb70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19eb70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19eb74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x19eb74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19eb78: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x19eb78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x19eb7c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19EB7Cu;
    {
        const bool branch_taken_0x19eb7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EB80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB7Cu;
            // 0x19eb80: 0x8c820004  lw          $v0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eb7c) {
            ctx->pc = 0x19EB8Cu;
            goto label_19eb8c;
        }
    }
    ctx->pc = 0x19EB84u;
    // 0x19eb84: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x19EB84u;
    {
        const bool branch_taken_0x19eb84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EB88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB84u;
            // 0x19eb88: 0xac620004  sw          $v0, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eb84) {
            ctx->pc = 0x19EBA4u;
            goto label_19eba4;
        }
    }
    ctx->pc = 0x19EB8Cu;
label_19eb8c:
    // 0x19eb8c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x19EB8Cu;
    {
        const bool branch_taken_0x19eb8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB8Cu;
            // 0x19eb90: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eb8c) {
            ctx->pc = 0x19EBA0u;
            goto label_19eba0;
        }
    }
    ctx->pc = 0x19EB94u;
    // 0x19eb94: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19eb94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19eb98: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x19EB98u;
    {
        const bool branch_taken_0x19eb98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EB9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB98u;
            // 0x19eb9c: 0xac22bed0  sw          $v0, -0x4130($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294950608), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eb98) {
            ctx->pc = 0x19EBA4u;
            goto label_19eba4;
        }
    }
    ctx->pc = 0x19EBA0u;
label_19eba0:
    // 0x19eba0: 0xac20bed0  sw          $zero, -0x4130($at)
    ctx->pc = 0x19eba0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950608), GPR_U32(ctx, 0));
label_19eba4:
    // 0x19eba4: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x19EBA4u;
    {
        const bool branch_taken_0x19eba4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x19eba4) {
            ctx->pc = 0x19EBB0u;
            goto label_19ebb0;
        }
    }
    ctx->pc = 0x19EBACu;
    // 0x19ebac: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19ebacu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_19ebb0:
    // 0x19ebb0: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x19ebb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x19ebb4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x19EBB4u;
    {
        const bool branch_taken_0x19ebb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EBB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EBB4u;
            // 0x19ebb8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ebb4) {
            ctx->pc = 0x19EBCCu;
            goto label_19ebcc;
        }
    }
    ctx->pc = 0x19EBBCu;
    // 0x19ebbc: 0xa0400035  sb          $zero, 0x35($v0)
    ctx->pc = 0x19ebbcu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 53), (uint8_t)GPR_U32(ctx, 0));
    // 0x19ebc0: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x19ebc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19ebc4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x19ebc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x19ebc8: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19ebc8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_19ebcc:
    // 0x19ebcc: 0xc0636e0  jal         func_18DB80
    ctx->pc = 0x19EBCCu;
    SET_GPR_U32(ctx, 31, 0x19EBD4u);
    ctx->pc = 0x19EBD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19EBCCu;
            // 0x19ebd0: 0x2406001c  addiu       $a2, $zero, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DB80u;
    if (runtime->hasFunction(0x18DB80u)) {
        auto targetFn = runtime->lookupFunction(0x18DB80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EBD4u; }
        if (ctx->pc != 0x19EBD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DB80_0x18db80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EBD4u; }
        if (ctx->pc != 0x19EBD4u) { return; }
    }
    ctx->pc = 0x19EBD4u;
label_19ebd4:
    // 0x19ebd4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ebd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ebd8: 0x8c23bec8  lw          $v1, -0x4138($at)
    ctx->pc = 0x19ebd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950600)));
    // 0x19ebdc: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x19ebdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x19ebe0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ebe0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ebe4: 0xac23bec8  sw          $v1, -0x4138($at)
    ctx->pc = 0x19ebe4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950600), GPR_U32(ctx, 3));
    // 0x19ebe8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19ebe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19ebec: 0x3e00008  jr          $ra
    ctx->pc = 0x19EBECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19EBF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EBECu;
            // 0x19ebf0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19EB8Cu: goto label_19eb8c;
            case 0x19EBA0u: goto label_19eba0;
            case 0x19EBA4u: goto label_19eba4;
            case 0x19EBB0u: goto label_19ebb0;
            case 0x19EBCCu: goto label_19ebcc;
            case 0x19EBD4u: goto label_19ebd4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19EBF4u;
    // 0x19ebf4: 0x0  nop
    ctx->pc = 0x19ebf4u;
    // NOP
    // 0x19ebf8: 0x0  nop
    ctx->pc = 0x19ebf8u;
    // NOP
    // 0x19ebfc: 0x0  nop
    ctx->pc = 0x19ebfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
