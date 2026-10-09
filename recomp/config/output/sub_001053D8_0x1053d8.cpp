#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001053D8
// Address: 0x1053d8 - 0x105510
void sub_001053D8_0x1053d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001053D8_0x1053d8");
#endif

    switch (ctx->pc) {
        case 0x105404u: goto label_105404;
        case 0x105408u: goto label_105408;
        case 0x105418u: goto label_105418;
        case 0x105458u: goto label_105458;
        case 0x1054d0u: goto label_1054d0;
        default: break;
    }

    ctx->pc = 0x1053d8u;

    // 0x1053d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1053d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1053dc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1053dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1053e0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1053e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1053e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1053e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1053e8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1053e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1053ec: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1053ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1053f0: 0x8e220038  lw          $v0, 0x38($s1)
    ctx->pc = 0x1053f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
    // 0x1053f4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1053F4u;
    {
        const bool branch_taken_0x1053f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1053F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1053F4u;
            // 0x1053f8: 0x263001d8  addiu       $s0, $s1, 0x1D8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 472));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1053f4) {
            ctx->pc = 0x105404u;
            goto label_105404;
        }
    }
    ctx->pc = 0x1053FCu;
    // 0x1053fc: 0xc041544  jal         func_105510
    ctx->pc = 0x1053FCu;
    SET_GPR_U32(ctx, 31, 0x105404u);
    ctx->pc = 0x105510u;
    if (runtime->hasFunction(0x105510u)) {
        auto targetFn = runtime->lookupFunction(0x105510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105404u; }
        if (ctx->pc != 0x105404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105510_0x105510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105404u; }
        if (ctx->pc != 0x105404u) { return; }
    }
    ctx->pc = 0x105404u;
label_105404:
    // 0x105404: 0x2412000c  addiu       $s2, $zero, 0xC
    ctx->pc = 0x105404u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
label_105408:
    // 0x105408: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x105408u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x10540c: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x10540cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x105410: 0x460000a  bltz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x105410u;
    {
        const bool branch_taken_0x105410 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x105414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105410u;
            // 0x105414: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105410) {
            ctx->pc = 0x10543Cu;
            goto label_10543c;
        }
    }
    ctx->pc = 0x105418u;
label_105418:
    // 0x105418: 0x8482000c  lh          $v0, 0xC($a0)
    ctx->pc = 0x105418u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x10541c: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x10541Cu;
    {
        const bool branch_taken_0x10541c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x105420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10541Cu;
            // 0x105420: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10541c) {
            ctx->pc = 0x105478u;
            goto label_105478;
        }
    }
    ctx->pc = 0x105424u;
    // 0x105424: 0x0  nop
    ctx->pc = 0x105424u;
    // NOP
    // 0x105428: 0x0  nop
    ctx->pc = 0x105428u;
    // NOP
    // 0x10542c: 0x0  nop
    ctx->pc = 0x10542cu;
    // NOP
    // 0x105430: 0x0  nop
    ctx->pc = 0x105430u;
    // NOP
    // 0x105434: 0x461fff8  bgez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x105434u;
    {
        const bool branch_taken_0x105434 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x105438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105434u;
            // 0x105438: 0x24840058  addiu       $a0, $a0, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105434) {
            ctx->pc = 0x105418u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_105418;
        }
    }
    ctx->pc = 0x10543Cu;
label_10543c:
    // 0x10543c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x10543cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x105440: 0x0  nop
    ctx->pc = 0x105440u;
    // NOP
    // 0x105444: 0x5480fff0  bnel        $a0, $zero, . + 4 + (-0x10 << 2)
    ctx->pc = 0x105444u;
    {
        const bool branch_taken_0x105444 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x105444) {
            ctx->pc = 0x105448u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105444u;
            // 0x105448: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105408u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_105408;
        }
    }
    ctx->pc = 0x10544Cu;
    // 0x10544c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x10544cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105450: 0xc0414d8  jal         func_105360
    ctx->pc = 0x105450u;
    SET_GPR_U32(ctx, 31, 0x105458u);
    ctx->pc = 0x105454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105450u;
            // 0x105454: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105360u;
    if (runtime->hasFunction(0x105360u)) {
        auto targetFn = runtime->lookupFunction(0x105360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105458u; }
        if (ctx->pc != 0x105458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105360_0x105360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105458u; }
        if (ctx->pc != 0x105458u) { return; }
    }
    ctx->pc = 0x105458u;
label_105458:
    // 0x105458: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x105458u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10545c: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x10545cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x105460: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x105460u;
    {
        const bool branch_taken_0x105460 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x105464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105460u;
            // 0x105464: 0x60202d  daddu       $a0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105460) {
            ctx->pc = 0x105470u;
            goto label_105470;
        }
    }
    ctx->pc = 0x105468u;
    // 0x105468: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x105468u;
    {
        const bool branch_taken_0x105468 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10546Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105468u;
            // 0x10546c: 0xae320000  sw          $s2, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105468) {
            ctx->pc = 0x1054B8u;
            goto label_1054b8;
        }
    }
    ctx->pc = 0x105470u;
label_105470:
    // 0x105470: 0x1000ffe5  b           . + 4 + (-0x1B << 2)
    ctx->pc = 0x105470u;
    {
        const bool branch_taken_0x105470 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105470u;
            // 0x105474: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105470) {
            ctx->pc = 0x105408u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_105408;
        }
    }
    ctx->pc = 0x105478u;
label_105478:
    // 0x105478: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x105478u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10547c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10547cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x105480: 0xa483000e  sh          $v1, 0xE($a0)
    ctx->pc = 0x105480u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 14), (uint16_t)GPR_U32(ctx, 3));
    // 0x105484: 0xac910054  sw          $s1, 0x54($a0)
    ctx->pc = 0x105484u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 84), GPR_U32(ctx, 17));
    // 0x105488: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x105488u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x10548c: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x10548cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x105490: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x105490u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x105494: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x105494u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x105498: 0xac800014  sw          $zero, 0x14($a0)
    ctx->pc = 0x105498u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 0));
    // 0x10549c: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x10549cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x1054a0: 0xac800030  sw          $zero, 0x30($a0)
    ctx->pc = 0x1054a0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 0));
    // 0x1054a4: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x1054a4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x1054a8: 0xac800044  sw          $zero, 0x44($a0)
    ctx->pc = 0x1054a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 0));
    // 0x1054ac: 0xac800048  sw          $zero, 0x48($a0)
    ctx->pc = 0x1054acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 0));
    // 0x1054b0: 0xa482000c  sh          $v0, 0xC($a0)
    ctx->pc = 0x1054b0u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 12), (uint16_t)GPR_U32(ctx, 2));
    // 0x1054b4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1054b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1054b8:
    // 0x1054b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1054b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1054bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1054bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1054c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1054c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1054c4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1054c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1054c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1054C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1054CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1054C8u;
            // 0x1054cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105404u: goto label_105404;
            case 0x105408u: goto label_105408;
            case 0x105418u: goto label_105418;
            case 0x10543Cu: goto label_10543c;
            case 0x105458u: goto label_105458;
            case 0x105470u: goto label_105470;
            case 0x105478u: goto label_105478;
            case 0x1054B8u: goto label_1054b8;
            case 0x1054D0u: goto label_1054d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1054D0u;
label_1054d0:
    // 0x1054d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1054d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1054d4: 0x3c050010  lui         $a1, 0x10
    ctx->pc = 0x1054d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16 << 16));
    // 0x1054d8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1054d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1054dc: 0x24a550b0  addiu       $a1, $a1, 0x50B0
    ctx->pc = 0x1054dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 20656));
    // 0x1054e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1054e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1054e4: 0x80419ce  j           func_106738
    ctx->pc = 0x1054E4u;
    ctx->pc = 0x1054E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1054E4u;
            // 0x1054e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106738u;
    if (runtime->hasFunction(0x106738u)) {
        auto targetFn = runtime->lookupFunction(0x106738u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00106738_0x106738(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1054ECu;
    // 0x1054ec: 0x0  nop
    ctx->pc = 0x1054ecu;
    // NOP
    // 0x1054f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1054f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1054f4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1054f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1054f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1054f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1054fc: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x1054fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x105500: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x105500u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x105504: 0x8041534  j           func_1054D0
    ctx->pc = 0x105504u;
    ctx->pc = 0x105508u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105504u;
            // 0x105508: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1054D0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1054d0;
    ctx->pc = 0x10550Cu;
    // 0x10550c: 0x0  nop
    ctx->pc = 0x10550cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
