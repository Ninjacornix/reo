#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159440
// Address: 0x159440 - 0x1594b8
void sub_00159440_0x159440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159440_0x159440");
#endif

    switch (ctx->pc) {
        case 0x159464u: goto label_159464;
        default: break;
    }

    ctx->pc = 0x159440u;

    // 0x159440: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x159440u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x159444: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x159444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x159448: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x159448u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15944c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15944cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x159450: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x159450u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159454: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x159454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x159458: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x159458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15945c: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x15945Cu;
    SET_GPR_U32(ctx, 31, 0x159464u);
    ctx->pc = 0x159460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15945Cu;
            // 0x159460: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159464u; }
        if (ctx->pc != 0x159464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159464u; }
        if (ctx->pc != 0x159464u) { return; }
    }
    ctx->pc = 0x159464u;
label_159464:
    // 0x159464: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x159464u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x159468: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x159468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15946c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15946Cu;
    {
        const bool branch_taken_0x15946c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x159470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15946Cu;
            // 0x159470: 0x34a5020e  ori         $a1, $a1, 0x20E (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)526);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15946c) {
            ctx->pc = 0x159490u;
            goto label_159490;
        }
    }
    ctx->pc = 0x159474u;
    // 0x159474: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x159474u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159478: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159478u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15947c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15947cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x159480: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x159480u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159484: 0x80563ce  j           func_158F38
    ctx->pc = 0x159484u;
    ctx->pc = 0x159488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159484u;
            // 0x159488: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15948Cu;
    // 0x15948c: 0x0  nop
    ctx->pc = 0x15948cu;
    // NOP
label_159490:
    // 0x159490: 0x8e030288  lw          $v1, 0x288($s0)
    ctx->pc = 0x159490u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 648)));
    // 0x159494: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x159494u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159498: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x159498u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x15949c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15949cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1594a0: 0x8e04028c  lw          $a0, 0x28C($s0)
    ctx->pc = 0x1594a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 652)));
    // 0x1594a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1594a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1594a8: 0xae440000  sw          $a0, 0x0($s2)
    ctx->pc = 0x1594a8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
    // 0x1594ac: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1594acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1594b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1594B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1594B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1594B0u;
            // 0x1594b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159464u: goto label_159464;
            case 0x159490u: goto label_159490;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1594B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
