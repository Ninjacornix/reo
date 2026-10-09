#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102368
// Address: 0x102368 - 0x1023c8
void sub_00102368_0x102368(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102368_0x102368");
#endif

    switch (ctx->pc) {
        case 0x10237cu: goto label_10237c;
        default: break;
    }

    ctx->pc = 0x102368u;

    // 0x102368: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x102368u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10236c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10236cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102370: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x102370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x102374: 0xc040926  jal         func_102498
    ctx->pc = 0x102374u;
    SET_GPR_U32(ctx, 31, 0x10237Cu);
    ctx->pc = 0x102378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102374u;
            // 0x102378: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102498u;
    if (runtime->hasFunction(0x102498u)) {
        auto targetFn = runtime->lookupFunction(0x102498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10237Cu; }
        if (ctx->pc != 0x10237Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102498_0x102498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10237Cu; }
        if (ctx->pc != 0x10237Cu) { return; }
    }
    ctx->pc = 0x10237Cu;
label_10237c:
    // 0x10237c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x10237cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102380: 0x2c620005  sltiu       $v0, $v1, 0x5
    ctx->pc = 0x102380u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x102384: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x102384u;
    {
        const bool branch_taken_0x102384 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x102388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102384u;
            // 0x102388: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102384) {
            ctx->pc = 0x1023B4u;
            goto label_1023b4;
        }
    }
    ctx->pc = 0x10238Cu;
    // 0x10238c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x10238cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x102390: 0x244276e0  addiu       $v0, $v0, 0x76E0
    ctx->pc = 0x102390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 30432));
    // 0x102394: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x102394u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x102398: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x102398u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10239c: 0x800008  jr          $a0
    ctx->pc = 0x10239Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1023A4u;
label_1023a4:
    // 0x1023a4: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x1023a4u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x1023a8: 0x34420100  ori         $v0, $v0, 0x100
    ctx->pc = 0x1023a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x1023ac: 0x48c2e000  ctc2.ni     $v0, $vi28
    ctx->pc = 0x1023acu;
    ctx->vu0_itop = GPR_U32(ctx, 2) & 0x3FF;
label_1023b0:
    // 0x1023b0: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x1023b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1023b4:
    // 0x1023b4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1023b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1023b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1023b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1023bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1023bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1023c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1023C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1023C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1023C0u;
            // 0x1023c4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10237Cu: goto label_10237c;
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1023C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
