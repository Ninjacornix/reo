#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158428
// Address: 0x158428 - 0x158500
void sub_00158428_0x158428(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158428_0x158428");
#endif

    switch (ctx->pc) {
        case 0x158450u: goto label_158450;
        case 0x1584a4u: goto label_1584a4;
        case 0x1584b0u: goto label_1584b0;
        case 0x1584bcu: goto label_1584bc;
        case 0x1584c4u: goto label_1584c4;
        case 0x1584ccu: goto label_1584cc;
        case 0x1584d4u: goto label_1584d4;
        case 0x1584dcu: goto label_1584dc;
        case 0x1584e4u: goto label_1584e4;
        default: break;
    }

    ctx->pc = 0x158428u;

    // 0x158428: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x158428u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x15842c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15842cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158430: 0x8c62d870  lw          $v0, -0x2790($v1)
    ctx->pc = 0x158430u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294957168)));
    // 0x158434: 0x8c45000c  lw          $a1, 0xC($v0)
    ctx->pc = 0x158434u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x158438: 0x18a0000e  blez        $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x158438u;
    {
        const bool branch_taken_0x158438 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x15843Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158438u;
            // 0x15843c: 0x24420010  addiu       $v0, $v0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158438) {
            ctx->pc = 0x158474u;
            goto label_158474;
        }
    }
    ctx->pc = 0x158440u;
    // 0x158440: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x158440u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158444: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x158444u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x158448: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x158448u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15844c: 0x0  nop
    ctx->pc = 0x15844cu;
    // NOP
label_158450:
    // 0x158450: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x158450u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158454: 0x10670008  beq         $v1, $a3, . + 4 + (0x8 << 2)
    ctx->pc = 0x158454u;
    {
        const bool branch_taken_0x158454 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 7));
        ctx->pc = 0x158458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158454u;
            // 0x158458: 0x248400c0  addiu       $a0, $a0, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158454) {
            ctx->pc = 0x158478u;
            goto label_158478;
        }
    }
    ctx->pc = 0x15845Cu;
    // 0x15845c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x15845cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x158460: 0xc5102a  slt         $v0, $a2, $a1
    ctx->pc = 0x158460u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x158464: 0x0  nop
    ctx->pc = 0x158464u;
    // NOP
    // 0x158468: 0x0  nop
    ctx->pc = 0x158468u;
    // NOP
    // 0x15846c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x15846Cu;
    {
        const bool branch_taken_0x15846c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15846c) {
            ctx->pc = 0x158470u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15846Cu;
            // 0x158470: 0x8c830000  lw          $v1, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158450u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_158450;
        }
    }
    ctx->pc = 0x158474u;
label_158474:
    // 0x158474: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x158474u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_158478:
    // 0x158478: 0x3e00008  jr          $ra
    ctx->pc = 0x158478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158450u: goto label_158450;
            case 0x158474u: goto label_158474;
            case 0x158478u: goto label_158478;
            case 0x1584A4u: goto label_1584a4;
            case 0x1584B0u: goto label_1584b0;
            case 0x1584BCu: goto label_1584bc;
            case 0x1584C4u: goto label_1584c4;
            case 0x1584CCu: goto label_1584cc;
            case 0x1584D4u: goto label_1584d4;
            case 0x1584DCu: goto label_1584dc;
            case 0x1584E4u: goto label_1584e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158480u;
    // 0x158480: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x158480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x158484: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x158484u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158488: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15848c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15848cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158490: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x158490u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x158494: 0x24110002  addiu       $s1, $zero, 0x2
    ctx->pc = 0x158494u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x158498: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x158498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15849c: 0xc0558b4  jal         func_1562D0
    ctx->pc = 0x15849Cu;
    SET_GPR_U32(ctx, 31, 0x1584A4u);
    ctx->pc = 0x1584A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15849Cu;
            // 0x1584a0: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1562D0u;
    if (runtime->hasFunction(0x1562D0u)) {
        auto targetFn = runtime->lookupFunction(0x1562D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584A4u; }
        if (ctx->pc != 0x1584A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001562D0_0x1562d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584A4u; }
        if (ctx->pc != 0x1584A4u) { return; }
    }
    ctx->pc = 0x1584A4u;
label_1584a4:
    // 0x1584a4: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x1584a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x1584a8: 0xc05607a  jal         func_1581E8
    ctx->pc = 0x1584A8u;
    SET_GPR_U32(ctx, 31, 0x1584B0u);
    ctx->pc = 0x1584ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1584A8u;
            // 0x1584ac: 0x26040004  addiu       $a0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1581E8u;
    if (runtime->hasFunction(0x1581E8u)) {
        auto targetFn = runtime->lookupFunction(0x1581E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584B0u; }
        if (ctx->pc != 0x1584B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001581E8_0x1581e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584B0u; }
        if (ctx->pc != 0x1584B0u) { return; }
    }
    ctx->pc = 0x1584B0u;
label_1584b0:
    // 0x1584b0: 0xae110010  sw          $s1, 0x10($s0)
    ctx->pc = 0x1584b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
    // 0x1584b4: 0xc056140  jal         func_158500
    ctx->pc = 0x1584B4u;
    SET_GPR_U32(ctx, 31, 0x1584BCu);
    ctx->pc = 0x1584B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1584B4u;
            // 0x1584b8: 0x26040014  addiu       $a0, $s0, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158500u;
    if (runtime->hasFunction(0x158500u)) {
        auto targetFn = runtime->lookupFunction(0x158500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584BCu; }
        if (ctx->pc != 0x1584BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158500_0x158500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584BCu; }
        if (ctx->pc != 0x1584BCu) { return; }
    }
    ctx->pc = 0x1584BCu;
label_1584bc:
    // 0x1584bc: 0xc056146  jal         func_158518
    ctx->pc = 0x1584BCu;
    SET_GPR_U32(ctx, 31, 0x1584C4u);
    ctx->pc = 0x1584C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1584BCu;
            // 0x1584c0: 0x26040020  addiu       $a0, $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158518u;
    if (runtime->hasFunction(0x158518u)) {
        auto targetFn = runtime->lookupFunction(0x158518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584C4u; }
        if (ctx->pc != 0x1584C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158518_0x158518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584C4u; }
        if (ctx->pc != 0x1584C4u) { return; }
    }
    ctx->pc = 0x1584C4u;
label_1584c4:
    // 0x1584c4: 0xc056146  jal         func_158518
    ctx->pc = 0x1584C4u;
    SET_GPR_U32(ctx, 31, 0x1584CCu);
    ctx->pc = 0x1584C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1584C4u;
            // 0x1584c8: 0x26040040  addiu       $a0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158518u;
    if (runtime->hasFunction(0x158518u)) {
        auto targetFn = runtime->lookupFunction(0x158518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584CCu; }
        if (ctx->pc != 0x1584CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158518_0x158518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584CCu; }
        if (ctx->pc != 0x1584CCu) { return; }
    }
    ctx->pc = 0x1584CCu;
label_1584cc:
    // 0x1584cc: 0xc056146  jal         func_158518
    ctx->pc = 0x1584CCu;
    SET_GPR_U32(ctx, 31, 0x1584D4u);
    ctx->pc = 0x1584D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1584CCu;
            // 0x1584d0: 0x26040060  addiu       $a0, $s0, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158518u;
    if (runtime->hasFunction(0x158518u)) {
        auto targetFn = runtime->lookupFunction(0x158518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584D4u; }
        if (ctx->pc != 0x1584D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158518_0x158518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584D4u; }
        if (ctx->pc != 0x1584D4u) { return; }
    }
    ctx->pc = 0x1584D4u;
label_1584d4:
    // 0x1584d4: 0xc056146  jal         func_158518
    ctx->pc = 0x1584D4u;
    SET_GPR_U32(ctx, 31, 0x1584DCu);
    ctx->pc = 0x1584D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1584D4u;
            // 0x1584d8: 0x26040080  addiu       $a0, $s0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158518u;
    if (runtime->hasFunction(0x158518u)) {
        auto targetFn = runtime->lookupFunction(0x158518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584DCu; }
        if (ctx->pc != 0x1584DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158518_0x158518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584DCu; }
        if (ctx->pc != 0x1584DCu) { return; }
    }
    ctx->pc = 0x1584DCu;
label_1584dc:
    // 0x1584dc: 0xc056150  jal         func_158540
    ctx->pc = 0x1584DCu;
    SET_GPR_U32(ctx, 31, 0x1584E4u);
    ctx->pc = 0x1584E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1584DCu;
            // 0x1584e0: 0x260400a0  addiu       $a0, $s0, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158540u;
    if (runtime->hasFunction(0x158540u)) {
        auto targetFn = runtime->lookupFunction(0x158540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584E4u; }
        if (ctx->pc != 0x1584E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158540_0x158540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1584E4u; }
        if (ctx->pc != 0x1584E4u) { return; }
    }
    ctx->pc = 0x1584E4u;
label_1584e4:
    // 0x1584e4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1584e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1584e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1584e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1584ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1584ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1584f0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1584f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1584f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1584F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1584F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1584F4u;
            // 0x1584f8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158450u: goto label_158450;
            case 0x158474u: goto label_158474;
            case 0x158478u: goto label_158478;
            case 0x1584A4u: goto label_1584a4;
            case 0x1584B0u: goto label_1584b0;
            case 0x1584BCu: goto label_1584bc;
            case 0x1584C4u: goto label_1584c4;
            case 0x1584CCu: goto label_1584cc;
            case 0x1584D4u: goto label_1584d4;
            case 0x1584DCu: goto label_1584dc;
            case 0x1584E4u: goto label_1584e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1584FCu;
    // 0x1584fc: 0x0  nop
    ctx->pc = 0x1584fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
