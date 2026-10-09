#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001113D0
// Address: 0x1113d0 - 0x1114b8
void sub_001113D0_0x1113d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001113D0_0x1113d0");
#endif

    switch (ctx->pc) {
        case 0x11142cu: goto label_11142c;
        case 0x11143cu: goto label_11143c;
        case 0x111454u: goto label_111454;
        case 0x111468u: goto label_111468;
        case 0x111484u: goto label_111484;
        case 0x111494u: goto label_111494;
        case 0x1114a0u: goto label_1114a0;
        default: break;
    }

    ctx->pc = 0x1113d0u;

    // 0x1113d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1113d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1113d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1113d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1113d8: 0x212fa  dsrl        $v0, $v0, 11
    ctx->pc = 0x1113d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 11);
    // 0x1113dc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1113dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1113e0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1113e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1113e4: 0x222102d  daddu       $v0, $s1, $v0
    ctx->pc = 0x1113e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 2));
    // 0x1113e8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1113e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1113ec: 0x31af8  dsll        $v1, $v1, 11
    ctx->pc = 0x1113ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 11);
    // 0x1113f0: 0x31aba  dsrl        $v1, $v1, 10
    ctx->pc = 0x1113f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> 10);
    // 0x1113f4: 0x62182b  sltu        $v1, $v1, $v0
    ctx->pc = 0x1113f4u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1113f8: 0x322207ff  andi        $v0, $s1, 0x7FF
    ctx->pc = 0x1113f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)2047);
    // 0x1113fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1113fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x111400: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x111400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x111404: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x111404u;
    {
        const bool branch_taken_0x111404 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x111408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111404u;
            // 0x111408: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111404) {
            ctx->pc = 0x111418u;
            goto label_111418;
        }
    }
    ctx->pc = 0x11140Cu;
    // 0x11140c: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x11140Cu;
    {
        const bool branch_taken_0x11140c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x111410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11140Cu;
            // 0x111410: 0x24020800  addiu       $v0, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11140c) {
            ctx->pc = 0x111418u;
            goto label_111418;
        }
    }
    ctx->pc = 0x111414u;
    // 0x111414: 0x2228825  or          $s1, $s1, $v0
    ctx->pc = 0x111414u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
label_111418:
    // 0x111418: 0x341081e0  ori         $s0, $zero, 0x81E0
    ctx->pc = 0x111418u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33248);
    // 0x11141c: 0x1083fc  dsll32      $s0, $s0, 15
    ctx->pc = 0x11141cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 15));
    // 0x111420: 0x11203f  dsra32      $a0, $s1, 0
    ctx->pc = 0x111420u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 17) >> (32 + 0));
    // 0x111424: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x111424u;
    SET_GPR_U32(ctx, 31, 0x11142Cu);
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11142Cu; }
        if (ctx->pc != 0x11142Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11142Cu; }
        if (ctx->pc != 0x11142Cu) { return; }
    }
    ctx->pc = 0x11142Cu;
label_11142c:
    // 0x11142c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x11142cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111430: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x111430u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111434: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x111434u;
    SET_GPR_U32(ctx, 31, 0x11143Cu);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11143Cu; }
        if (ctx->pc != 0x11143Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11143Cu; }
        if (ctx->pc != 0x11143Cu) { return; }
    }
    ctx->pc = 0x11143Cu;
label_11143c:
    // 0x11143c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11143cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111440: 0x3c10ffff  lui         $s0, 0xFFFF
    ctx->pc = 0x111440u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)65535 << 16));
    // 0x111444: 0x10803e  dsrl32      $s0, $s0, 0
    ctx->pc = 0x111444u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 0));
    // 0x111448: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x111448u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11144c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x11144Cu;
    SET_GPR_U32(ctx, 31, 0x111454u);
    ctx->pc = 0x111450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11144Cu;
            // 0x111450: 0x2308024  and         $s0, $s1, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 17) & GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111454u; }
        if (ctx->pc != 0x111454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111454u; }
        if (ctx->pc != 0x111454u) { return; }
    }
    ctx->pc = 0x111454u;
label_111454:
    // 0x111454: 0x10803c  dsll32      $s0, $s0, 0
    ctx->pc = 0x111454u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x111458: 0x10803f  dsra32      $s0, $s0, 0
    ctx->pc = 0x111458u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 0));
    // 0x11145c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11145cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111460: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x111460u;
    SET_GPR_U32(ctx, 31, 0x111468u);
    ctx->pc = 0x111464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111460u;
            // 0x111464: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111468u; }
        if (ctx->pc != 0x111468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111468u; }
        if (ctx->pc != 0x111468u) { return; }
    }
    ctx->pc = 0x111468u;
label_111468:
    // 0x111468: 0x340583e0  ori         $a1, $zero, 0x83E0
    ctx->pc = 0x111468u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33760);
    // 0x11146c: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x11146cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x111470: 0x6010004  bgez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x111470u;
    {
        const bool branch_taken_0x111470 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x111470) {
            ctx->pc = 0x111484u;
            goto label_111484;
        }
    }
    ctx->pc = 0x111478u;
    // 0x111478: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x111478u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11147c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11147Cu;
    SET_GPR_U32(ctx, 31, 0x111484u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111484u; }
        if (ctx->pc != 0x111484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111484u; }
        if (ctx->pc != 0x111484u) { return; }
    }
    ctx->pc = 0x111484u;
label_111484:
    // 0x111484: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x111484u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111488: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x111488u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11148c: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x11148Cu;
    SET_GPR_U32(ctx, 31, 0x111494u);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111494u; }
        if (ctx->pc != 0x111494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111494u; }
        if (ctx->pc != 0x111494u) { return; }
    }
    ctx->pc = 0x111494u;
label_111494:
    // 0x111494: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x111494u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111498: 0xc04491c  jal         func_112470
    ctx->pc = 0x111498u;
    SET_GPR_U32(ctx, 31, 0x1114A0u);
    ctx->pc = 0x112470u;
    if (runtime->hasFunction(0x112470u)) {
        auto targetFn = runtime->lookupFunction(0x112470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1114A0u; }
        if (ctx->pc != 0x1114A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1114A0u; }
        if (ctx->pc != 0x1114A0u) { return; }
    }
    ctx->pc = 0x1114A0u;
label_1114a0:
    // 0x1114a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1114a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1114a4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1114a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1114a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1114a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1114ac: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1114acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1114b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1114B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1114B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1114B0u;
            // 0x1114b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111418u: goto label_111418;
            case 0x11142Cu: goto label_11142c;
            case 0x11143Cu: goto label_11143c;
            case 0x111454u: goto label_111454;
            case 0x111468u: goto label_111468;
            case 0x111484u: goto label_111484;
            case 0x111494u: goto label_111494;
            case 0x1114A0u: goto label_1114a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1114B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
