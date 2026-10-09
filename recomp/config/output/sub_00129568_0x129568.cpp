#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129568
// Address: 0x129568 - 0x1295f4
void sub_00129568_0x129568(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129568_0x129568");
#endif

    switch (ctx->pc) {
        case 0x1295c0u: goto label_1295c0;
        case 0x1295dcu: goto label_1295dc;
        default: break;
    }

    ctx->pc = 0x129568u;

    // 0x129568: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x129568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12956c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x12956cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129570: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129574: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x129574u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129578: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x129578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12957c: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12957Cu;
    {
        const bool branch_taken_0x12957c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x129580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12957Cu;
            // 0x129580: 0xc0182d  daddu       $v1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12957c) {
            ctx->pc = 0x129590u;
            goto label_129590;
        }
    }
    ctx->pc = 0x129584u;
    // 0x129584: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129584u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129588: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x129588u;
    {
        const bool branch_taken_0x129588 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12958Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129588u;
            // 0x12958c: 0x24849ef0  addiu       $a0, $a0, -0x6110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942448));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129588) {
            ctx->pc = 0x1295B8u;
            goto label_1295b8;
        }
    }
    ctx->pc = 0x129590u;
label_129590:
    // 0x129590: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x129590u;
    {
        const bool branch_taken_0x129590 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x129590) {
            ctx->pc = 0x1295A8u;
            goto label_1295a8;
        }
    }
    ctx->pc = 0x129598u;
    // 0x129598: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129598u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12959c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x12959Cu;
    {
        const bool branch_taken_0x12959c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1295A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12959Cu;
            // 0x1295a0: 0x24849f18  addiu       $a0, $a0, -0x60E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942488));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12959c) {
            ctx->pc = 0x1295B8u;
            goto label_1295b8;
        }
    }
    ctx->pc = 0x1295A4u;
    // 0x1295a4: 0x0  nop
    ctx->pc = 0x1295a4u;
    // NOP
label_1295a8:
    // 0x1295a8: 0x54600007  bnel        $v1, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1295A8u;
    {
        const bool branch_taken_0x1295a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1295a8) {
            ctx->pc = 0x1295ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1295A8u;
            // 0x1295ac: 0x82070001  lb          $a3, 0x1($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1295C8u;
            goto label_1295c8;
        }
    }
    ctx->pc = 0x1295B0u;
    // 0x1295b0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1295b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1295b4: 0x24849f48  addiu       $a0, $a0, -0x60B8
    ctx->pc = 0x1295b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942536));
label_1295b8:
    // 0x1295b8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1295B8u;
    SET_GPR_U32(ctx, 31, 0x1295C0u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1295C0u; }
        if (ctx->pc != 0x1295C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1295C0u; }
        if (ctx->pc != 0x1295C0u) { return; }
    }
    ctx->pc = 0x1295C0u;
label_1295c0:
    // 0x1295c0: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1295C0u;
    {
        const bool branch_taken_0x1295c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1295C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1295C0u;
            // 0x1295c4: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1295c0) {
            ctx->pc = 0x1295E4u;
            goto label_1295e4;
        }
    }
    ctx->pc = 0x1295C8u;
label_1295c8:
    // 0x1295c8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1295c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1295cc: 0x10e30005  beq         $a3, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1295CCu;
    {
        const bool branch_taken_0x1295cc = (GPR_U64(ctx, 7) == GPR_U64(ctx, 3));
        ctx->pc = 0x1295D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1295CCu;
            // 0x1295d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1295cc) {
            ctx->pc = 0x1295E4u;
            goto label_1295e4;
        }
    }
    ctx->pc = 0x1295D4u;
    // 0x1295d4: 0xc04a51a  jal         func_129468
    ctx->pc = 0x1295D4u;
    SET_GPR_U32(ctx, 31, 0x1295DCu);
    ctx->pc = 0x129468u;
    if (runtime->hasFunction(0x129468u)) {
        auto targetFn = runtime->lookupFunction(0x129468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1295DCu; }
        if (ctx->pc != 0x1295DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129468_0x129468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1295DCu; }
        if (ctx->pc != 0x1295DCu) { return; }
    }
    ctx->pc = 0x1295DCu;
label_1295dc:
    // 0x1295dc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1295dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1295e0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1295e0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
label_1295e4:
    // 0x1295e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1295e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1295e8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1295e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1295ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1295ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1295F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1295ECu;
            // 0x1295f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129590u: goto label_129590;
            case 0x1295A8u: goto label_1295a8;
            case 0x1295B8u: goto label_1295b8;
            case 0x1295C0u: goto label_1295c0;
            case 0x1295C8u: goto label_1295c8;
            case 0x1295DCu: goto label_1295dc;
            case 0x1295E4u: goto label_1295e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1295F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
