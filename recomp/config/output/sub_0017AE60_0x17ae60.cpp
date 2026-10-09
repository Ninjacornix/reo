#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017AE60
// Address: 0x17ae60 - 0x17aef8
void sub_0017AE60_0x17ae60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017AE60_0x17ae60");
#endif

    switch (ctx->pc) {
        case 0x17aeecu: goto label_17aeec;
        default: break;
    }

    ctx->pc = 0x17ae60u;

    // 0x17ae60: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x17ae60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x17ae64: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x17ae64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ae68: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17ae68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x17ae6c: 0x244d0004  addiu       $t5, $v0, 0x4
    ctx->pc = 0x17ae6cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x17ae70: 0x244b0024  addiu       $t3, $v0, 0x24
    ctx->pc = 0x17ae70u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x17ae74: 0x244a0014  addiu       $t2, $v0, 0x14
    ctx->pc = 0x17ae74u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x17ae78: 0x8da30004  lw          $v1, 0x4($t5)
    ctx->pc = 0x17ae78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 4)));
    // 0x17ae7c: 0xc0602d  daddu       $t4, $a2, $zero
    ctx->pc = 0x17ae7cu;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ae80: 0x8c470044  lw          $a3, 0x44($v0)
    ctx->pc = 0x17ae80u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
    // 0x17ae84: 0x180282d  daddu       $a1, $t4, $zero
    ctx->pc = 0x17ae84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ae88: 0x8d460004  lw          $a2, 0x4($t2)
    ctx->pc = 0x17ae88u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 4)));
    // 0x17ae8c: 0x37080  sll         $t6, $v1, 2
    ctx->pc = 0x17ae8cu;
    SET_GPR_S32(ctx, 14, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x17ae90: 0x8d680004  lw          $t0, 0x4($t3)
    ctx->pc = 0x17ae90u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 4)));
    // 0x17ae94: 0x8c490048  lw          $t1, 0x48($v0)
    ctx->pc = 0x17ae94u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x17ae98: 0xafa60010  sw          $a2, 0x10($sp)
    ctx->pc = 0x17ae98u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 6));
    // 0x17ae9c: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x17ae9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17aea0: 0xafa70024  sw          $a3, 0x24($sp)
    ctx->pc = 0x17aea0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 7));
    // 0x17aea4: 0xafa3000c  sw          $v1, 0xC($sp)
    ctx->pc = 0x17aea4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 3));
    // 0x17aea8: 0xafa80014  sw          $t0, 0x14($sp)
    ctx->pc = 0x17aea8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 8));
    // 0x17aeac: 0xafa90028  sw          $t1, 0x28($sp)
    ctx->pc = 0x17aeacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 9));
    // 0x17aeb0: 0x8da70000  lw          $a3, 0x0($t5)
    ctx->pc = 0x17aeb0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x17aeb4: 0x8d420000  lw          $v0, 0x0($t2)
    ctx->pc = 0x17aeb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x17aeb8: 0x8d630000  lw          $v1, 0x0($t3)
    ctx->pc = 0x17aeb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x17aebc: 0x8c880008  lw          $t0, 0x8($a0)
    ctx->pc = 0x17aebcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17aec0: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x17aec0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17aec4: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x17aec4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x17aec8: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x17aec8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x17aecc: 0xafa70000  sw          $a3, 0x0($sp)
    ctx->pc = 0x17aeccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 7));
    // 0x17aed0: 0x15000003  bnez        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17AED0u;
    {
        const bool branch_taken_0x17aed0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x17AED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AED0u;
            // 0x17aed4: 0xafac0020  sw          $t4, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aed0) {
            ctx->pc = 0x17AEE0u;
            goto label_17aee0;
        }
    }
    ctx->pc = 0x17AED8u;
    // 0x17aed8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x17AED8u;
    {
        const bool branch_taken_0x17aed8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AEDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AED8u;
            // 0x17aedc: 0xafae002c  sw          $t6, 0x2C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 14));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aed8) {
            ctx->pc = 0x17AEE4u;
            goto label_17aee4;
        }
    }
    ctx->pc = 0x17AEE0u;
label_17aee0:
    // 0x17aee0: 0xafa8002c  sw          $t0, 0x2C($sp)
    ctx->pc = 0x17aee0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 8));
label_17aee4:
    // 0x17aee4: 0xc0524a8  jal         func_1492A0
    ctx->pc = 0x17AEE4u;
    SET_GPR_U32(ctx, 31, 0x17AEECu);
    ctx->pc = 0x17AEE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AEE4u;
            // 0x17aee8: 0x8da70008  lw          $a3, 0x8($t5) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1492A0u;
    if (runtime->hasFunction(0x1492A0u)) {
        auto targetFn = runtime->lookupFunction(0x1492A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AEECu; }
        if (ctx->pc != 0x17AEECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001492A0_0x1492a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AEECu; }
        if (ctx->pc != 0x17AEECu) { return; }
    }
    ctx->pc = 0x17AEECu;
label_17aeec:
    // 0x17aeec: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x17aeecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17aef0: 0x3e00008  jr          $ra
    ctx->pc = 0x17AEF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17AEF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AEF0u;
            // 0x17aef4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17AEE0u: goto label_17aee0;
            case 0x17AEE4u: goto label_17aee4;
            case 0x17AEECu: goto label_17aeec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17AEF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
