#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00118170
// Address: 0x118170 - 0x1181f8
void sub_00118170_0x118170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00118170_0x118170");
#endif

    switch (ctx->pc) {
        case 0x118188u: goto label_118188;
        case 0x118190u: goto label_118190;
        case 0x1181b0u: goto label_1181b0;
        case 0x1181c4u: goto label_1181c4;
        case 0x1181e0u: goto label_1181e0;
        default: break;
    }

    ctx->pc = 0x118170u;

    // 0x118170: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x118170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x118174: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x118174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x118178: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x118178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11817c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11817cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x118180: 0xc046044  jal         func_118110
    ctx->pc = 0x118180u;
    SET_GPR_U32(ctx, 31, 0x118188u);
    ctx->pc = 0x118184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118180u;
            // 0x118184: 0x3c110021  lui         $s1, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118110u;
    if (runtime->hasFunction(0x118110u)) {
        auto targetFn = runtime->lookupFunction(0x118110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118188u; }
        if (ctx->pc != 0x118188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118110_0x118110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118188u; }
        if (ctx->pc != 0x118188u) { return; }
    }
    ctx->pc = 0x118188u;
label_118188:
    // 0x118188: 0xc045198  jal         func_114660
    ctx->pc = 0x118188u;
    SET_GPR_U32(ctx, 31, 0x118190u);
    ctx->pc = 0x11818Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118188u;
            // 0x11818c: 0x8e249de8  lw          $a0, -0x6218($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118190u; }
        if (ctx->pc != 0x118190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118190u; }
        if (ctx->pc != 0x118190u) { return; }
    }
    ctx->pc = 0x118190u;
label_118190:
    // 0x118190: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x118190u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x118194: 0x2470df40  addiu       $s0, $v1, -0x20C0
    ctx->pc = 0x118194u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 4294958912));
    // 0x118198: 0x26030200  addiu       $v1, $s0, 0x200
    ctx->pc = 0x118198u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 512));
    // 0x11819c: 0x203102b  sltu        $v0, $s0, $v1
    ctx->pc = 0x11819cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1181a0: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1181A0u;
    {
        const bool branch_taken_0x1181a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1181A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1181A0u;
            // 0x1181a4: 0x3c051000  lui         $a1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1181a0) {
            ctx->pc = 0x1181D8u;
            goto label_1181d8;
        }
    }
    ctx->pc = 0x1181A8u;
    // 0x1181a8: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1181a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1181ac: 0x0  nop
    ctx->pc = 0x1181acu;
    // NOP
label_1181b0:
    // 0x1181b0: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x1181B0u;
    {
        const bool branch_taken_0x1181b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1181b0) {
            ctx->pc = 0x1181B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1181B0u;
            // 0x1181b4: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1181CCu;
            goto label_1181cc;
        }
    }
    ctx->pc = 0x1181B8u;
    // 0x1181b8: 0x8e249de8  lw          $a0, -0x6218($s1)
    ctx->pc = 0x1181b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
    // 0x1181bc: 0xc045190  jal         func_114640
    ctx->pc = 0x1181BCu;
    SET_GPR_U32(ctx, 31, 0x1181C4u);
    ctx->pc = 0x1181C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1181BCu;
            // 0x1181c0: 0xae050004  sw          $a1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1181C4u; }
        if (ctx->pc != 0x1181C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1181C4u; }
        if (ctx->pc != 0x1181C4u) { return; }
    }
    ctx->pc = 0x1181C4u;
label_1181c4:
    // 0x1181c4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1181C4u;
    {
        const bool branch_taken_0x1181c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1181C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1181C4u;
            // 0x1181c8: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1181c4) {
            ctx->pc = 0x1181E4u;
            goto label_1181e4;
        }
    }
    ctx->pc = 0x1181CCu;
label_1181cc:
    // 0x1181cc: 0x203102b  sltu        $v0, $s0, $v1
    ctx->pc = 0x1181ccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1181d0: 0x5440fff7  bnel        $v0, $zero, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1181D0u;
    {
        const bool branch_taken_0x1181d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1181d0) {
            ctx->pc = 0x1181D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1181D0u;
            // 0x1181d4: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1181B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1181b0;
        }
    }
    ctx->pc = 0x1181D8u;
label_1181d8:
    // 0x1181d8: 0xc045190  jal         func_114640
    ctx->pc = 0x1181D8u;
    SET_GPR_U32(ctx, 31, 0x1181E0u);
    ctx->pc = 0x1181DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1181D8u;
            // 0x1181dc: 0x8e249de8  lw          $a0, -0x6218($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294942184)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1181E0u; }
        if (ctx->pc != 0x1181E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1181E0u; }
        if (ctx->pc != 0x1181E0u) { return; }
    }
    ctx->pc = 0x1181E0u;
label_1181e0:
    // 0x1181e0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1181e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1181e4:
    // 0x1181e4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1181e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1181e8: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1181e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1181ec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1181ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1181f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1181F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1181F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1181F0u;
            // 0x1181f4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118188u: goto label_118188;
            case 0x118190u: goto label_118190;
            case 0x1181B0u: goto label_1181b0;
            case 0x1181C4u: goto label_1181c4;
            case 0x1181CCu: goto label_1181cc;
            case 0x1181D8u: goto label_1181d8;
            case 0x1181E0u: goto label_1181e0;
            case 0x1181E4u: goto label_1181e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1181F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
