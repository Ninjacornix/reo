#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D0A0
// Address: 0x15d0a0 - 0x15d108
void sub_0015D0A0_0x15d0a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D0A0_0x15d0a0");
#endif

    switch (ctx->pc) {
        case 0x15d0ccu: goto label_15d0cc;
        case 0x15d0ecu: goto label_15d0ec;
        default: break;
    }

    ctx->pc = 0x15d0a0u;

    // 0x15d0a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15d0a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15d0a4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x15d0a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15d0a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d0a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d0ac: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15d0acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d0b0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15d0b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15d0b4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x15d0b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15d0b8: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x15D0B8u;
    {
        const bool branch_taken_0x15d0b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x15D0BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D0B8u;
            // 0x15d0bc: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d0b8) {
            ctx->pc = 0x15D0D0u;
            goto label_15d0d0;
        }
    }
    ctx->pc = 0x15D0C0u;
    // 0x15d0c0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d0c0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d0c4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D0C4u;
    SET_GPR_U32(ctx, 31, 0x15D0CCu);
    ctx->pc = 0x15D0C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D0C4u;
            // 0x15d0c8: 0x2484eab0  addiu       $a0, $a0, -0x1550 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961840));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D0CCu; }
        if (ctx->pc != 0x15D0CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D0CCu; }
        if (ctx->pc != 0x15D0CCu) { return; }
    }
    ctx->pc = 0x15D0CCu;
label_15d0cc:
    // 0x15d0cc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15d0ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_15d0d0:
    // 0x15d0d0: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x15d0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x15d0d4: 0x2c420003  sltiu       $v0, $v0, 0x3
    ctx->pc = 0x15d0d4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x15d0d8: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D0D8u;
    {
        const bool branch_taken_0x15d0d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15d0d8) {
            ctx->pc = 0x15D0DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D0D8u;
            // 0x15d0dc: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D0F4u;
            goto label_15d0f4;
        }
    }
    ctx->pc = 0x15D0E0u;
    // 0x15d0e0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d0e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d0e4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D0E4u;
    SET_GPR_U32(ctx, 31, 0x15D0ECu);
    ctx->pc = 0x15D0E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D0E4u;
            // 0x15d0e8: 0x2484eae0  addiu       $a0, $a0, -0x1520 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961888));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D0ECu; }
        if (ctx->pc != 0x15D0ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D0ECu; }
        if (ctx->pc != 0x15D0ECu) { return; }
    }
    ctx->pc = 0x15D0ECu;
label_15d0ec:
    // 0x15d0ec: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15d0ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d0f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d0f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_15d0f4:
    // 0x15d0f4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x15d0f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d0f8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15d0f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d0fc: 0x3e00008  jr          $ra
    ctx->pc = 0x15D0FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D0FCu;
            // 0x15d100: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D0CCu: goto label_15d0cc;
            case 0x15D0D0u: goto label_15d0d0;
            case 0x15D0ECu: goto label_15d0ec;
            case 0x15D0F4u: goto label_15d0f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D104u;
    // 0x15d104: 0x0  nop
    ctx->pc = 0x15d104u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
