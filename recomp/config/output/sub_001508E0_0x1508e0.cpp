#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001508E0
// Address: 0x1508e0 - 0x15093c
void sub_001508E0_0x1508e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001508E0_0x1508e0");
#endif

    switch (ctx->pc) {
        case 0x1508fcu: goto label_1508fc;
        default: break;
    }

    ctx->pc = 0x1508e0u;

    // 0x1508e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1508e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1508e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1508e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1508e8: 0x24900128  addiu       $s0, $a0, 0x128
    ctx->pc = 0x1508e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x1508ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1508ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1508f0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1508f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1508f4: 0xc05578e  jal         func_155E38
    ctx->pc = 0x1508F4u;
    SET_GPR_U32(ctx, 31, 0x1508FCu);
    ctx->pc = 0x1508F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1508F4u;
            // 0x1508f8: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1508FCu; }
        if (ctx->pc != 0x1508FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1508FCu; }
        if (ctx->pc != 0x1508FCu) { return; }
    }
    ctx->pc = 0x1508FCu;
label_1508fc:
    // 0x1508fc: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1508fcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x150900: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x150900u;
    {
        const bool branch_taken_0x150900 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150900u;
            // 0x150904: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150900) {
            ctx->pc = 0x150920u;
            goto label_150920;
        }
    }
    ctx->pc = 0x150908u;
    // 0x150908: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150908u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15090c: 0x34a5020d  ori         $a1, $a1, 0x20D
    ctx->pc = 0x15090cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)525);
    // 0x150910: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150910u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150914: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x150914u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150918: 0x805419c  j           func_150670
    ctx->pc = 0x150918u;
    ctx->pc = 0x15091Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150918u;
            // 0x15091c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150920u;
label_150920:
    // 0x150920: 0x8e0202f8  lw          $v0, 0x2F8($s0)
    ctx->pc = 0x150920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 760)));
    // 0x150924: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x150924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150928: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x150928u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x15092c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15092cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150930: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150930u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150934: 0x3e00008  jr          $ra
    ctx->pc = 0x150934u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150934u;
            // 0x150938: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1508FCu: goto label_1508fc;
            case 0x150920u: goto label_150920;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15093Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
