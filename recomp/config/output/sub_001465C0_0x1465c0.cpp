#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001465C0
// Address: 0x1465c0 - 0x146650
void sub_001465C0_0x1465c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001465C0_0x1465c0");
#endif

    switch (ctx->pc) {
        case 0x146600u: goto label_146600;
        case 0x14662cu: goto label_14662c;
        default: break;
    }

    ctx->pc = 0x1465c0u;

    // 0x1465c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1465c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1465c4: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x1465c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1465c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1465c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1465cc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1465ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1465d0: 0x10c00016  beqz        $a2, . + 4 + (0x16 << 2)
    ctx->pc = 0x1465D0u;
    {
        const bool branch_taken_0x1465d0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1465D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1465D0u;
            // 0x1465d4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1465d0) {
            ctx->pc = 0x14662Cu;
            goto label_14662c;
        }
    }
    ctx->pc = 0x1465D8u;
    // 0x1465d8: 0x8e02018c  lw          $v0, 0x18C($s0)
    ctx->pc = 0x1465d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x1465dc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1465dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1465e0: 0x14430009  bne         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1465E0u;
    {
        const bool branch_taken_0x1465e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1465E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1465E0u;
            // 0x1465e4: 0x8e020168  lw          $v0, 0x168($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 360)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1465e0) {
            ctx->pc = 0x146608u;
            goto label_146608;
        }
    }
    ctx->pc = 0x1465E8u;
    // 0x1465e8: 0x54430002  bnel        $v0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1465E8u;
    {
        const bool branch_taken_0x1465e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1465e8) {
            ctx->pc = 0x1465ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1465E8u;
            // 0x1465ec: 0x8e0501d0  lw          $a1, 0x1D0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 464)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1465F4u;
            goto label_1465f4;
        }
    }
    ctx->pc = 0x1465F0u;
    // 0x1465f0: 0x8e0501dc  lw          $a1, 0x1DC($s0)
    ctx->pc = 0x1465f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 476)));
label_1465f4:
    // 0x1465f4: 0x24e6ffff  addiu       $a2, $a3, -0x1
    ctx->pc = 0x1465f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1465f8: 0xc051b76  jal         func_146DD8
    ctx->pc = 0x1465F8u;
    SET_GPR_U32(ctx, 31, 0x146600u);
    ctx->pc = 0x1465FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1465F8u;
            // 0x1465fc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146DD8u;
    if (runtime->hasFunction(0x146DD8u)) {
        auto targetFn = runtime->lookupFunction(0x146DD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146600u; }
        if (ctx->pc != 0x146600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146DD8_0x146dd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146600u; }
        if (ctx->pc != 0x146600u) { return; }
    }
    ctx->pc = 0x146600u;
label_146600:
    // 0x146600: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x146600u;
    {
        const bool branch_taken_0x146600 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146600u;
            // 0x146604: 0x8e030110  lw          $v1, 0x110($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 272)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146600) {
            ctx->pc = 0x146630u;
            goto label_146630;
        }
    }
    ctx->pc = 0x146608u;
label_146608:
    // 0x146608: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x146608u;
    {
        const bool branch_taken_0x146608 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x146608) {
            ctx->pc = 0x14660Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146608u;
            // 0x14660c: 0x8e0501e0  lw          $a1, 0x1E0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 480)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14661Cu;
            goto label_14661c;
        }
    }
    ctx->pc = 0x146610u;
    // 0x146610: 0x8e0501ec  lw          $a1, 0x1EC($s0)
    ctx->pc = 0x146610u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 492)));
    // 0x146614: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x146614u;
    {
        const bool branch_taken_0x146614 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146614u;
            // 0x146618: 0x8e0601fc  lw          $a2, 0x1FC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 508)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146614) {
            ctx->pc = 0x146620u;
            goto label_146620;
        }
    }
    ctx->pc = 0x14661Cu;
label_14661c:
    // 0x14661c: 0x8e0601f0  lw          $a2, 0x1F0($s0)
    ctx->pc = 0x14661cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 496)));
label_146620:
    // 0x146620: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x146620u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x146624: 0xc051bba  jal         func_146EE8
    ctx->pc = 0x146624u;
    SET_GPR_U32(ctx, 31, 0x14662Cu);
    ctx->pc = 0x146628u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146624u;
            // 0x146628: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146EE8u;
    if (runtime->hasFunction(0x146EE8u)) {
        auto targetFn = runtime->lookupFunction(0x146EE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14662Cu; }
        if (ctx->pc != 0x14662Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146EE8_0x146ee8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14662Cu; }
        if (ctx->pc != 0x14662Cu) { return; }
    }
    ctx->pc = 0x14662Cu;
label_14662c:
    // 0x14662c: 0x8e030110  lw          $v1, 0x110($s0)
    ctx->pc = 0x14662cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 272)));
label_146630:
    // 0x146630: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x146630u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146634: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x146634u;
    {
        const bool branch_taken_0x146634 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x146638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146634u;
            // 0x146638: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146634) {
            ctx->pc = 0x146644u;
            goto label_146644;
        }
    }
    ctx->pc = 0x14663Cu;
    // 0x14663c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x14663cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x146640: 0xae020110  sw          $v0, 0x110($s0)
    ctx->pc = 0x146640u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 272), GPR_U32(ctx, 2));
label_146644:
    // 0x146644: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x146644u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146648: 0x3e00008  jr          $ra
    ctx->pc = 0x146648u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14664Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146648u;
            // 0x14664c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1465F4u: goto label_1465f4;
            case 0x146600u: goto label_146600;
            case 0x146608u: goto label_146608;
            case 0x14661Cu: goto label_14661c;
            case 0x146620u: goto label_146620;
            case 0x14662Cu: goto label_14662c;
            case 0x146630u: goto label_146630;
            case 0x146644u: goto label_146644;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146650u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
