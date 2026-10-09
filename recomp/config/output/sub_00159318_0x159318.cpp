#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159318
// Address: 0x159318 - 0x159378
void sub_00159318_0x159318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159318_0x159318");
#endif

    switch (ctx->pc) {
        case 0x159334u: goto label_159334;
        default: break;
    }

    ctx->pc = 0x159318u;

    // 0x159318: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x159318u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15931c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15931cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x159320: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x159320u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159324: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x159324u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x159328: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x159328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15932c: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x15932Cu;
    SET_GPR_U32(ctx, 31, 0x159334u);
    ctx->pc = 0x159330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15932Cu;
            // 0x159330: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159334u; }
        if (ctx->pc != 0x159334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159334u; }
        if (ctx->pc != 0x159334u) { return; }
    }
    ctx->pc = 0x159334u;
label_159334:
    // 0x159334: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x159334u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x159338: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x159338u;
    {
        const bool branch_taken_0x159338 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15933Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159338u;
            // 0x15933c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159338) {
            ctx->pc = 0x159358u;
            goto label_159358;
        }
    }
    ctx->pc = 0x159340u;
    // 0x159340: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x159340u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159344: 0x34a5020d  ori         $a1, $a1, 0x20D
    ctx->pc = 0x159344u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)525);
    // 0x159348: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159348u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15934c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15934cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x159350: 0x80563ce  j           func_158F38
    ctx->pc = 0x159350u;
    ctx->pc = 0x159354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159350u;
            // 0x159354: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00158F38_0x158f38(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x159358u;
label_159358:
    // 0x159358: 0x8e03027c  lw          $v1, 0x27C($s0)
    ctx->pc = 0x159358u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 636)));
    // 0x15935c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15935cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x159360: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x159360u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x159364: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x159364u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x159368: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x159368u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15936c: 0x3e00008  jr          $ra
    ctx->pc = 0x15936Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x159370u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15936Cu;
            // 0x159370: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159334u: goto label_159334;
            case 0x159358u: goto label_159358;
            default: break;
        }
        return;
    }
    ctx->pc = 0x159374u;
    // 0x159374: 0x0  nop
    ctx->pc = 0x159374u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
