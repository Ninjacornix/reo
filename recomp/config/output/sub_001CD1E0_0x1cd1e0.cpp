#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD1E0
// Address: 0x1cd1e0 - 0x1cd250
void sub_001CD1E0_0x1cd1e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD1E0_0x1cd1e0");
#endif

    switch (ctx->pc) {
        case 0x1cd1f8u: goto label_1cd1f8;
        case 0x1cd20cu: goto label_1cd20c;
        default: break;
    }

    ctx->pc = 0x1cd1e0u;

    // 0x1cd1e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cd1e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cd1e4: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1cd1e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd1e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cd1e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cd1ec: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cd1ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cd1f0: 0xc07340c  jal         func_1CD030
    ctx->pc = 0x1CD1F0u;
    SET_GPR_U32(ctx, 31, 0x1CD1F8u);
    ctx->pc = 0x1CD1F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD1F0u;
            // 0x1cd1f4: 0x8c2466c8  lw          $a0, 0x66C8($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26312)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD030u;
    if (runtime->hasFunction(0x1CD030u)) {
        auto targetFn = runtime->lookupFunction(0x1CD030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD1F8u; }
        if (ctx->pc != 0x1CD1F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD030_0x1cd030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CD1F8u; }
        if (ctx->pc != 0x1CD1F8u) { return; }
    }
    ctx->pc = 0x1CD1F8u;
label_1cd1f8:
    // 0x1cd1f8: 0xc22021  addu        $a0, $a2, $v0
    ctx->pc = 0x1cd1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1cd1fc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cd1fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd200: 0x3c060034  lui         $a2, 0x34
    ctx->pc = 0x1cd200u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)52 << 16));
    // 0x1cd204: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1CD204u;
    {
        const bool branch_taken_0x1cd204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD204u;
            // 0x1cd208: 0x24c61640  addiu       $a2, $a2, 0x1640 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd204) {
            ctx->pc = 0x1CD234u;
            goto label_1cd234;
        }
    }
    ctx->pc = 0x1CD20Cu;
label_1cd20c:
    // 0x1cd20c: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1cd20cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1cd210: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CD210u;
    {
        const bool branch_taken_0x1cd210 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd210) {
            ctx->pc = 0x1CD22Cu;
            goto label_1cd22c;
        }
    }
    ctx->pc = 0x1CD218u;
    // 0x1cd218: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x1cd218u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1cd21c: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CD21Cu;
    {
        const bool branch_taken_0x1cd21c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cd21c) {
            ctx->pc = 0x1CD22Cu;
            goto label_1cd22c;
        }
    }
    ctx->pc = 0x1CD224u;
    // 0x1cd224: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CD224u;
    {
        const bool branch_taken_0x1cd224 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD224u;
            // 0x1cd228: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd224) {
            ctx->pc = 0x1CD244u;
            goto label_1cd244;
        }
    }
    ctx->pc = 0x1CD22Cu;
label_1cd22c:
    // 0x1cd22c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1cd22cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1cd230: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x1cd230u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
label_1cd234:
    // 0x1cd234: 0x28a20100  slti        $v0, $a1, 0x100
    ctx->pc = 0x1cd234u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1cd238: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1CD238u;
    {
        const bool branch_taken_0x1cd238 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD23Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD238u;
            // 0x1cd23c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd238) {
            ctx->pc = 0x1CD20Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cd20c;
        }
    }
    ctx->pc = 0x1CD240u;
    // 0x1cd240: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cd240u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1cd244:
    // 0x1cd244: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD244u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CD248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD244u;
            // 0x1cd248: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD1F8u: goto label_1cd1f8;
            case 0x1CD20Cu: goto label_1cd20c;
            case 0x1CD22Cu: goto label_1cd22c;
            case 0x1CD234u: goto label_1cd234;
            case 0x1CD244u: goto label_1cd244;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD24Cu;
    // 0x1cd24c: 0x0  nop
    ctx->pc = 0x1cd24cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
