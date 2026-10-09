#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150580
// Address: 0x150580 - 0x1505f0
void sub_00150580_0x150580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150580_0x150580");
#endif

    switch (ctx->pc) {
        case 0x1505a4u: goto label_1505a4;
        default: break;
    }

    ctx->pc = 0x150580u;

    // 0x150580: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x150580u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x150584: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x150588: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x150588u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15058c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15058cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x150590: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x150590u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150594: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x150594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x150598: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x150598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15059c: 0xc05578e  jal         func_155E38
    ctx->pc = 0x15059Cu;
    SET_GPR_U32(ctx, 31, 0x1505A4u);
    ctx->pc = 0x1505A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15059Cu;
            // 0x1505a0: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1505A4u; }
        if (ctx->pc != 0x1505A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1505A4u; }
        if (ctx->pc != 0x1505A4u) { return; }
    }
    ctx->pc = 0x1505A4u;
label_1505a4:
    // 0x1505a4: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1505a4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x1505a8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x1505a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1505ac: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1505acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1505b0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1505B0u;
    {
        const bool branch_taken_0x1505b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1505B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1505B0u;
            // 0x1505b4: 0x34a50203  ori         $a1, $a1, 0x203 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)515);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1505b0) {
            ctx->pc = 0x1505D0u;
            goto label_1505d0;
        }
    }
    ctx->pc = 0x1505B8u;
    // 0x1505b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1505b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1505bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1505bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1505c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1505c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1505c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1505c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1505c8: 0x805419c  j           func_150670
    ctx->pc = 0x1505C8u;
    ctx->pc = 0x1505CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1505C8u;
            // 0x1505cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1505D0u;
label_1505d0:
    // 0x1505d0: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x1505d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
    // 0x1505d4: 0xae120000  sw          $s2, 0x0($s0)
    ctx->pc = 0x1505d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 18));
    // 0x1505d8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1505d8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1505dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1505dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1505e0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1505e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1505e4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1505e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1505e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1505E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1505ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1505E8u;
            // 0x1505ec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1505A4u: goto label_1505a4;
            case 0x1505D0u: goto label_1505d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1505F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
