#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136148
// Address: 0x136148 - 0x1361a4
void sub_00136148_0x136148(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136148_0x136148");
#endif

    switch (ctx->pc) {
        case 0x136160u: goto label_136160;
        case 0x136190u: goto label_136190;
        default: break;
    }

    ctx->pc = 0x136148u;

    // 0x136148: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136148u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13614c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13614Cu;
    {
        const bool branch_taken_0x13614c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13614Cu;
            // 0x136150: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13614c) {
            ctx->pc = 0x136168u;
            goto label_136168;
        }
    }
    ctx->pc = 0x136154u;
    // 0x136154: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136154u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136158: 0xc04d480  jal         func_135200
    ctx->pc = 0x136158u;
    SET_GPR_U32(ctx, 31, 0x136160u);
    ctx->pc = 0x13615Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136158u;
            // 0x13615c: 0x2484bc28  addiu       $a0, $a0, -0x43D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136160u; }
        if (ctx->pc != 0x136160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136160u; }
        if (ctx->pc != 0x136160u) { return; }
    }
    ctx->pc = 0x136160u;
label_136160:
    // 0x136160: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x136160u;
    {
        const bool branch_taken_0x136160 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136160u;
            // 0x136164: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136160) {
            ctx->pc = 0x136198u;
            goto label_136198;
        }
    }
    ctx->pc = 0x136168u;
label_136168:
    // 0x136168: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13616c: 0x3c037fff  lui         $v1, 0x7FFF
    ctx->pc = 0x13616cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32767 << 16));
    // 0x136170: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x136170u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x136174: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136174u;
    {
        const bool branch_taken_0x136174 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136174u;
            // 0x136178: 0x3463ffff  ori         $v1, $v1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x136174) {
            ctx->pc = 0x136194u;
            goto label_136194;
        }
    }
    ctx->pc = 0x13617Cu;
    // 0x13617c: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x13617cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x136180: 0x2405012c  addiu       $a1, $zero, 0x12C
    ctx->pc = 0x136180u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 300));
    // 0x136184: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136184u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136188: 0x40f809  jalr        $v0
    ctx->pc = 0x136188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136190u);
        ctx->pc = 0x13618Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136188u;
            // 0x13618c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136190u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136190u; }
            if (ctx->pc != 0x136190u) { return; }
        }
        }
    }
    ctx->pc = 0x136190u;
label_136190:
    // 0x136190: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x136190u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136194:
    // 0x136194: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x136194u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_136198:
    // 0x136198: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136198u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13619c: 0x3e00008  jr          $ra
    ctx->pc = 0x13619Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1361A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13619Cu;
            // 0x1361a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136160u: goto label_136160;
            case 0x136168u: goto label_136168;
            case 0x136190u: goto label_136190;
            case 0x136194u: goto label_136194;
            case 0x136198u: goto label_136198;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1361A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
