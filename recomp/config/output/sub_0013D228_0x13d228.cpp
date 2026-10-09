#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D228
// Address: 0x13d228 - 0x13d2bc
void sub_0013D228_0x13d228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D228_0x13d228");
#endif

    switch (ctx->pc) {
        case 0x13d240u: goto label_13d240;
        case 0x13d260u: goto label_13d260;
        case 0x13d29cu: goto label_13d29c;
        default: break;
    }

    ctx->pc = 0x13d228u;

    // 0x13d228: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d228u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d22c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D22Cu;
    {
        const bool branch_taken_0x13d22c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D22Cu;
            // 0x13d230: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d22c) {
            ctx->pc = 0x13D248u;
            goto label_13d248;
        }
    }
    ctx->pc = 0x13D234u;
    // 0x13d234: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d234u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d238: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D238u;
    SET_GPR_U32(ctx, 31, 0x13D240u);
    ctx->pc = 0x13D23Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D238u;
            // 0x13d23c: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D240u; }
        if (ctx->pc != 0x13D240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D240u; }
        if (ctx->pc != 0x13D240u) { return; }
    }
    ctx->pc = 0x13D240u;
label_13d240:
    // 0x13d240: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x13D240u;
    {
        const bool branch_taken_0x13d240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D240u;
            // 0x13d244: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d240) {
            ctx->pc = 0x13D2B0u;
            goto label_13d2b0;
        }
    }
    ctx->pc = 0x13D248u;
label_13d248:
    // 0x13d248: 0x24860038  addiu       $a2, $a0, 0x38
    ctx->pc = 0x13d248u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x13d24c: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d24cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d250: 0x1045000c  beq         $v0, $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x13D250u;
    {
        const bool branch_taken_0x13d250 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x13D254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D250u;
            // 0x13d254: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d250) {
            ctx->pc = 0x13D284u;
            goto label_13d284;
        }
    }
    ctx->pc = 0x13D258u;
    // 0x13d258: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13d258u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13d25c: 0x0  nop
    ctx->pc = 0x13d25cu;
    // NOP
label_13d260:
    // 0x13d260: 0x28620010  slti        $v0, $v1, 0x10
    ctx->pc = 0x13d260u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13d264: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D264u;
    {
        const bool branch_taken_0x13d264 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D264u;
            // 0x13d268: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d264) {
            ctx->pc = 0x13D284u;
            goto label_13d284;
        }
    }
    ctx->pc = 0x13D26Cu;
    // 0x13d26c: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d26cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d270: 0x0  nop
    ctx->pc = 0x13d270u;
    // NOP
    // 0x13d274: 0x0  nop
    ctx->pc = 0x13d274u;
    // NOP
    // 0x13d278: 0x0  nop
    ctx->pc = 0x13d278u;
    // NOP
    // 0x13d27c: 0x5445fff8  bnel        $v0, $a1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13D27Cu;
    {
        const bool branch_taken_0x13d27c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x13d27c) {
            ctx->pc = 0x13D280u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D27Cu;
            // 0x13d280: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D260u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d260;
        }
    }
    ctx->pc = 0x13D284u;
label_13d284:
    // 0x13d284: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x13d284u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13d288: 0x54620007  bnel        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D288u;
    {
        const bool branch_taken_0x13d288 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d288) {
            ctx->pc = 0x13D28Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D288u;
            // 0x13d28c: 0x31940  sll         $v1, $v1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D2A8u;
            goto label_13d2a8;
        }
    }
    ctx->pc = 0x13D290u;
    // 0x13d290: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d290u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d294: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D294u;
    SET_GPR_U32(ctx, 31, 0x13D29Cu);
    ctx->pc = 0x13D298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D294u;
            // 0x13d298: 0x2484d3d8  addiu       $a0, $a0, -0x2C28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D29Cu; }
        if (ctx->pc != 0x13D29Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D29Cu; }
        if (ctx->pc != 0x13D29Cu) { return; }
    }
    ctx->pc = 0x13D29Cu;
label_13d29c:
    // 0x13d29c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13D29Cu;
    {
        const bool branch_taken_0x13d29c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D29Cu;
            // 0x13d2a0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d29c) {
            ctx->pc = 0x13D2B0u;
            goto label_13d2b0;
        }
    }
    ctx->pc = 0x13D2A4u;
    // 0x13d2a4: 0x0  nop
    ctx->pc = 0x13d2a4u;
    // NOP
label_13d2a8:
    // 0x13d2a8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x13d2a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x13d2ac: 0x8c620050  lw          $v0, 0x50($v1)
    ctx->pc = 0x13d2acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 80)));
label_13d2b0:
    // 0x13d2b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d2b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d2b4: 0x3e00008  jr          $ra
    ctx->pc = 0x13D2B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D2B4u;
            // 0x13d2b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D240u: goto label_13d240;
            case 0x13D248u: goto label_13d248;
            case 0x13D260u: goto label_13d260;
            case 0x13D284u: goto label_13d284;
            case 0x13D29Cu: goto label_13d29c;
            case 0x13D2A8u: goto label_13d2a8;
            case 0x13D2B0u: goto label_13d2b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D2BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
