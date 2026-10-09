#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B800
// Address: 0x17b800 - 0x17b888
void sub_0017B800_0x17b800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B800_0x17b800");
#endif

    ctx->pc = 0x17b800u;

    // 0x17b800: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17b800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17b804: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x17b804u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b808: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17b808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17b80c: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17b80cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17b810: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x17b810u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x17b814: 0x10620012  beq         $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x17B814u;
    {
        const bool branch_taken_0x17b814 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B814u;
            // 0x17b818: 0xa0402d  daddu       $t0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b814) {
            ctx->pc = 0x17B860u;
            goto label_17b860;
        }
    }
    ctx->pc = 0x17B81Cu;
    // 0x17b81c: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17b81cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17b820: 0x50400010  beql        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x17B820u;
    {
        const bool branch_taken_0x17b820 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17b820) {
            ctx->pc = 0x17B824u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17B820u;
            // 0x17b824: 0x3c060024  lui         $a2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17B864u;
            goto label_17b864;
        }
    }
    ctx->pc = 0x17B828u;
    // 0x17b828: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17b828u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17b82c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x17B82Cu;
    {
        const bool branch_taken_0x17b82c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B82Cu;
            // 0x17b830: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b82c) {
            ctx->pc = 0x17B850u;
            goto label_17b850;
        }
    }
    ctx->pc = 0x17B834u;
    // 0x17b834: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x17B834u;
    {
        const bool branch_taken_0x17b834 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B834u;
            // 0x17b838: 0x3c060024  lui         $a2, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b834) {
            ctx->pc = 0x17B864u;
            goto label_17b864;
        }
    }
    ctx->pc = 0x17B83Cu;
    // 0x17b83c: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17b83cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17b840: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x17B840u;
    {
        const bool branch_taken_0x17b840 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17B844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B840u;
            // 0x17b844: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b840) {
            ctx->pc = 0x17B880u;
            goto label_17b880;
        }
    }
    ctx->pc = 0x17B848u;
    // 0x17b848: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x17B848u;
    {
        const bool branch_taken_0x17b848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x17b848) {
            ctx->pc = 0x17B868u;
            goto label_17b868;
        }
    }
    ctx->pc = 0x17B850u;
label_17b850:
    // 0x17b850: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17b850u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17b854: 0x805ed3a  j           func_17B4E8
    ctx->pc = 0x17B854u;
    ctx->pc = 0x17B858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B854u;
            // 0x17b858: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B4E8u;
    if (runtime->hasFunction(0x17B4E8u)) {
        auto targetFn = runtime->lookupFunction(0x17B4E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B4E8_0x17b4e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B85Cu;
    // 0x17b85c: 0x0  nop
    ctx->pc = 0x17b85cu;
    // NOP
label_17b860:
    // 0x17b860: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17b860u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
label_17b864:
    // 0x17b864: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17b864u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17b868:
    // 0x17b868: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x17b868u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b86c: 0x100282d  daddu       $a1, $t0, $zero
    ctx->pc = 0x17b86cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b870: 0x24c60f50  addiu       $a2, $a2, 0xF50
    ctx->pc = 0x17b870u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 3920));
    // 0x17b874: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17B874u;
    ctx->pc = 0x17B878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B874u;
            // 0x17b878: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17B87Cu;
    // 0x17b87c: 0x0  nop
    ctx->pc = 0x17b87cu;
    // NOP
label_17b880:
    // 0x17b880: 0x3e00008  jr          $ra
    ctx->pc = 0x17B880u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B880u;
            // 0x17b884: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B850u: goto label_17b850;
            case 0x17B860u: goto label_17b860;
            case 0x17B864u: goto label_17b864;
            case 0x17B868u: goto label_17b868;
            case 0x17B880u: goto label_17b880;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B888u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
