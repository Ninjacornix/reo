#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177BE0
// Address: 0x177be0 - 0x177c48
void sub_00177BE0_0x177be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177BE0_0x177be0");
#endif

    switch (ctx->pc) {
        case 0x177c24u: goto label_177c24;
        default: break;
    }

    ctx->pc = 0x177be0u;

    // 0x177be0: 0x51100  sll         $v0, $a1, 4
    ctx->pc = 0x177be0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x177be4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x177be4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x177be8: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x177be8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x177bec: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x177becu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177bf0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177bf4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x177bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x177bf8: 0x821821  addu        $v1, $a0, $v0
    ctx->pc = 0x177bf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x177bfc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x177bfcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177c00: 0x8c691aac  lw          $t1, 0x1AAC($v1)
    ctx->pc = 0x177c00u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 6828)));
    // 0x177c04: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x177c04u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x177c08: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x177c08u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177c0c: 0xc91821  addu        $v1, $a2, $t1
    ctx->pc = 0x177c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 9)));
    // 0x177c10: 0x11200004  beqz        $t1, . + 4 + (0x4 << 2)
    ctx->pc = 0x177C10u;
    {
        const bool branch_taken_0x177c10 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x177C14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177C10u;
            // 0x177c14: 0x100302d  daddu       $a2, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177c10) {
            ctx->pc = 0x177C24u;
            goto label_177c24;
        }
    }
    ctx->pc = 0x177C18u;
    // 0x177c18: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x177c18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x177c1c: 0x40f809  jalr        $v0
    ctx->pc = 0x177C1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x177C24u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x177C24u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177C24u: goto label_177c24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x177C24u; }
            if (ctx->pc != 0x177C24u) { return; }
        }
        }
    }
    ctx->pc = 0x177C24u;
label_177c24:
    // 0x177c24: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x177c24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177c28: 0x3e00008  jr          $ra
    ctx->pc = 0x177C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177C28u;
            // 0x177c2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177C24u: goto label_177c24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177C30u;
    // 0x177c30: 0x51100  sll         $v0, $a1, 4
    ctx->pc = 0x177c30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x177c34: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x177c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x177c38: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177c38u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177c3c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x177c3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x177c40: 0x3e00008  jr          $ra
    ctx->pc = 0x177C40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177C40u;
            // 0x177c44: 0xac861aa0  sw          $a2, 0x1AA0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 6816), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177C24u: goto label_177c24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177C48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
