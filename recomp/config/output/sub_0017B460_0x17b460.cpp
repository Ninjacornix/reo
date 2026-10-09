#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B460
// Address: 0x17b460 - 0x17b4e8
void sub_0017B460_0x17b460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B460_0x17b460");
#endif

    ctx->pc = 0x17b460u;

    // 0x17b460: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17b460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17b464: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x17b464u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b468: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17b468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17b46c: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17b46cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17b470: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x17b470u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x17b474: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x17B474u;
    {
        const bool branch_taken_0x17b474 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B474u;
            // 0x17b478: 0xa0402d  daddu       $t0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b474) {
            ctx->pc = 0x17B4C0u;
            goto label_17b4c0;
        }
    }
    ctx->pc = 0x17B47Cu;
    // 0x17b47c: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17b47cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17b480: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x17B480u;
    {
        const bool branch_taken_0x17b480 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17b480) {
            ctx->pc = 0x17B484u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17B480u;
            // 0x17b484: 0x3c060024  lui         $a2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17B4C4u;
            goto label_17b4c4;
        }
    }
    ctx->pc = 0x17B488u;
    // 0x17b488: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17b488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17b48c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17B48Cu;
    {
        const bool branch_taken_0x17b48c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B48Cu;
            // 0x17b490: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b48c) {
            ctx->pc = 0x17B4B0u;
            goto label_17b4b0;
        }
    }
    ctx->pc = 0x17B494u;
    // 0x17b494: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x17B494u;
    {
        const bool branch_taken_0x17b494 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B494u;
            // 0x17b498: 0x3c060024  lui         $a2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b494) {
            ctx->pc = 0x17B4C4u;
            goto label_17b4c4;
        }
    }
    ctx->pc = 0x17B49Cu;
    // 0x17b49c: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17b49cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17b4a0: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x17B4A0u;
    {
        const bool branch_taken_0x17b4a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B4A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B4A0u;
            // 0x17b4a4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b4a0) {
            ctx->pc = 0x17B4E0u;
            goto label_17b4e0;
        }
    }
    ctx->pc = 0x17B4A8u;
    // 0x17b4a8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x17B4A8u;
    {
        const bool branch_taken_0x17b4a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x17b4a8) {
            ctx->pc = 0x17B4C8u;
            goto label_17b4c8;
        }
    }
    ctx->pc = 0x17B4B0u;
label_17b4b0:
    // 0x17b4b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17b4b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b4b4: 0x805ed3a  j           func_17B4E8
    ctx->pc = 0x17B4B4u;
    ctx->pc = 0x17B4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B4B4u;
            // 0x17b4b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B4E8u;
    if (runtime->hasFunction(0x17B4E8u)) {
        auto targetFn = runtime->lookupFunction(0x17B4E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B4E8_0x17b4e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B4BCu;
    // 0x17b4bc: 0x0  nop
    ctx->pc = 0x17b4bcu;
    // NOP
label_17b4c0:
    // 0x17b4c0: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17b4c0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
label_17b4c4:
    // 0x17b4c4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17b4c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17b4c8:
    // 0x17b4c8: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x17b4c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b4cc: 0x100282d  daddu       $a1, $t0, $zero
    ctx->pc = 0x17b4ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b4d0: 0x24c60e70  addiu       $a2, $a2, 0xE70
    ctx->pc = 0x17b4d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 3696));
    // 0x17b4d4: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17B4D4u;
    ctx->pc = 0x17B4D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B4D4u;
            // 0x17b4d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B4DCu;
    // 0x17b4dc: 0x0  nop
    ctx->pc = 0x17b4dcu;
    // NOP
label_17b4e0:
    // 0x17b4e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17B4E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B4E0u;
            // 0x17b4e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B4B0u: goto label_17b4b0;
            case 0x17B4C0u: goto label_17b4c0;
            case 0x17B4C4u: goto label_17b4c4;
            case 0x17B4C8u: goto label_17b4c8;
            case 0x17B4E0u: goto label_17b4e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B4E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
