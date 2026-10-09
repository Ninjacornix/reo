#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A5D8
// Address: 0x16a5d8 - 0x16a638
void sub_0016A5D8_0x16a5d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A5D8_0x16a5d8");
#endif

    switch (ctx->pc) {
        case 0x16a5ecu: goto label_16a5ec;
        default: break;
    }

    ctx->pc = 0x16a5d8u;

    // 0x16a5d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16a5d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16a5dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16a5dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a5e0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16a5e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16a5e4: 0xc05a98e  jal         func_16A638
    ctx->pc = 0x16A5E4u;
    SET_GPR_U32(ctx, 31, 0x16A5ECu);
    ctx->pc = 0x16A5E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A5E4u;
            // 0x16a5e8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A638u;
    if (runtime->hasFunction(0x16A638u)) {
        auto targetFn = runtime->lookupFunction(0x16A638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A5ECu; }
        if (ctx->pc != 0x16A5ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A638_0x16a638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A5ECu; }
        if (ctx->pc != 0x16A5ECu) { return; }
    }
    ctx->pc = 0x16A5ECu;
label_16a5ec:
    // 0x16a5ec: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16a5ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a5f0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x16a5f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x16a5f4: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x16A5F4u;
    {
        const bool branch_taken_0x16a5f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x16a5f4) {
            ctx->pc = 0x16A5F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A5F4u;
            // 0x16a5f8: 0x8c83000c  lw          $v1, 0xC($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A618u;
            goto label_16a618;
        }
    }
    ctx->pc = 0x16A5FCu;
    // 0x16a5fc: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x16a5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x16a600: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16A600u;
    {
        const bool branch_taken_0x16a600 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A600u;
            // 0x16a604: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a600) {
            ctx->pc = 0x16A628u;
            goto label_16a628;
        }
    }
    ctx->pc = 0x16A608u;
    // 0x16a608: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x16a608u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x16a60c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A60Cu;
    {
        const bool branch_taken_0x16a60c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A60Cu;
            // 0x16a610: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a60c) {
            ctx->pc = 0x16A628u;
            goto label_16a628;
        }
    }
    ctx->pc = 0x16A614u;
    // 0x16a614: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x16a614u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
label_16a618:
    // 0x16a618: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x16a618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x16a61c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16a61cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16a620: 0x2021026  xor         $v0, $s0, $v0
    ctx->pc = 0x16a620u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 2));
    // 0x16a624: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x16a624u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_16a628:
    // 0x16a628: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16a628u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a62c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16a62cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a630: 0x3e00008  jr          $ra
    ctx->pc = 0x16A630u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A630u;
            // 0x16a634: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A5ECu: goto label_16a5ec;
            case 0x16A618u: goto label_16a618;
            case 0x16A628u: goto label_16a628;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A638u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
