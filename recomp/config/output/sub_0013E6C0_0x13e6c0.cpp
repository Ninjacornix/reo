#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013E6C0
// Address: 0x13e6c0 - 0x13e76c
void sub_0013E6C0_0x13e6c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013E6C0_0x13e6c0");
#endif

    switch (ctx->pc) {
        case 0x13e700u: goto label_13e700;
        case 0x13e714u: goto label_13e714;
        case 0x13e720u: goto label_13e720;
        case 0x13e728u: goto label_13e728;
        case 0x13e730u: goto label_13e730;
        case 0x13e738u: goto label_13e738;
        case 0x13e740u: goto label_13e740;
        default: break;
    }

    ctx->pc = 0x13e6c0u;

    // 0x13e6c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13e6c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13e6c4: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13e6c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13e6c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13e6c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13e6cc: 0x2463146c  addiu       $v1, $v1, 0x146C
    ctx->pc = 0x13e6ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 5228));
    // 0x13e6d0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13e6d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13e6d4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x13e6d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x13e6d8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x13e6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13e6dc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x13e6dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x13e6e0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x13E6E0u;
    {
        const bool branch_taken_0x13e6e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13E6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E6E0u;
            // 0x13e6e4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13e6e0) {
            ctx->pc = 0x13E758u;
            goto label_13e758;
        }
    }
    ctx->pc = 0x13E6E8u;
    // 0x13e6e8: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13e6e8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13e6ec: 0x3c110022  lui         $s1, 0x22
    ctx->pc = 0x13e6ecu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)34 << 16));
    // 0x13e6f0: 0x26101454  addiu       $s0, $s0, 0x1454
    ctx->pc = 0x13e6f0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5204));
    // 0x13e6f4: 0x26313e80  addiu       $s1, $s1, 0x3E80
    ctx->pc = 0x13e6f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 16000));
    // 0x13e6f8: 0xc046e86  jal         func_11BA18
    ctx->pc = 0x13E6F8u;
    SET_GPR_U32(ctx, 31, 0x13E700u);
    ctx->pc = 0x13E6FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E6F8u;
            // 0x13e6fc: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BA18u;
    if (runtime->hasFunction(0x11BA18u)) {
        auto targetFn = runtime->lookupFunction(0x11BA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E700u; }
        if (ctx->pc != 0x13E700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BA18_0x11ba18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E700u; }
        if (ctx->pc != 0x13E700u) { return; }
    }
    ctx->pc = 0x13E700u;
label_13e700:
    // 0x13e700: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13e700u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13e704: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x13e704u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x13e708: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x13e708u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13e70c: 0xc04e444  jal         func_139110
    ctx->pc = 0x13E70Cu;
    SET_GPR_U32(ctx, 31, 0x13E714u);
    ctx->pc = 0x13E710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E70Cu;
            // 0x13e710: 0x26101474  addiu       $s0, $s0, 0x1474 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5236));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139110u;
    if (runtime->hasFunction(0x139110u)) {
        auto targetFn = runtime->lookupFunction(0x139110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E714u; }
        if (ctx->pc != 0x13E714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139110_0x139110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E714u; }
        if (ctx->pc != 0x13E714u) { return; }
    }
    ctx->pc = 0x13E714u;
label_13e714:
    // 0x13e714: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x13e714u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x13e718: 0xc046e86  jal         func_11BA18
    ctx->pc = 0x13E718u;
    SET_GPR_U32(ctx, 31, 0x13E720u);
    ctx->pc = 0x13E71Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E718u;
            // 0x13e71c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BA18u;
    if (runtime->hasFunction(0x11BA18u)) {
        auto targetFn = runtime->lookupFunction(0x11BA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E720u; }
        if (ctx->pc != 0x13E720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BA18_0x11ba18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E720u; }
        if (ctx->pc != 0x13E720u) { return; }
    }
    ctx->pc = 0x13E720u;
label_13e720:
    // 0x13e720: 0xc04f790  jal         func_13DE40
    ctx->pc = 0x13E720u;
    SET_GPR_U32(ctx, 31, 0x13E728u);
    ctx->pc = 0x13E724u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E720u;
            // 0x13e724: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13DE40u;
    if (runtime->hasFunction(0x13DE40u)) {
        auto targetFn = runtime->lookupFunction(0x13DE40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E728u; }
        if (ctx->pc != 0x13E728u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013DE40_0x13de40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E728u; }
        if (ctx->pc != 0x13E728u) { return; }
    }
    ctx->pc = 0x13E728u;
label_13e728:
    // 0x13e728: 0xc04f970  jal         func_13E5C0
    ctx->pc = 0x13E728u;
    SET_GPR_U32(ctx, 31, 0x13E730u);
    ctx->pc = 0x13E5C0u;
    if (runtime->hasFunction(0x13E5C0u)) {
        auto targetFn = runtime->lookupFunction(0x13E5C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E730u; }
        if (ctx->pc != 0x13E730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013E5C0_0x13e5c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E730u; }
        if (ctx->pc != 0x13E730u) { return; }
    }
    ctx->pc = 0x13E730u;
label_13e730:
    // 0x13e730: 0xc04e4fa  jal         func_1393E8
    ctx->pc = 0x13E730u;
    SET_GPR_U32(ctx, 31, 0x13E738u);
    ctx->pc = 0x1393E8u;
    if (runtime->hasFunction(0x1393E8u)) {
        auto targetFn = runtime->lookupFunction(0x1393E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E738u; }
        if (ctx->pc != 0x13E738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001393E8_0x1393e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E738u; }
        if (ctx->pc != 0x13E738u) { return; }
    }
    ctx->pc = 0x13E738u;
label_13e738:
    // 0x13e738: 0xc050506  jal         func_141418
    ctx->pc = 0x13E738u;
    SET_GPR_U32(ctx, 31, 0x13E740u);
    ctx->pc = 0x141418u;
    if (runtime->hasFunction(0x141418u)) {
        auto targetFn = runtime->lookupFunction(0x141418u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E740u; }
        if (ctx->pc != 0x13E740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141418_0x141418(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13E740u; }
        if (ctx->pc != 0x13E740u) { return; }
    }
    ctx->pc = 0x13E740u;
label_13e740:
    // 0x13e740: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e740u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e744: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13e744u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e748: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13e748u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e74c: 0x80503b6  j           func_140ED8
    ctx->pc = 0x13E74Cu;
    ctx->pc = 0x13E750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13E74Cu;
            // 0x13e750: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140ED8u;
    if (runtime->hasFunction(0x140ED8u)) {
        auto targetFn = runtime->lookupFunction(0x140ED8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00140ED8_0x140ed8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13E754u;
    // 0x13e754: 0x0  nop
    ctx->pc = 0x13e754u;
    // NOP
label_13e758:
    // 0x13e758: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13e758u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13e75c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13e75cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13e760: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x13e760u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13e764: 0x3e00008  jr          $ra
    ctx->pc = 0x13E764u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13E768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13E764u;
            // 0x13e768: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13E700u: goto label_13e700;
            case 0x13E714u: goto label_13e714;
            case 0x13E720u: goto label_13e720;
            case 0x13E728u: goto label_13e728;
            case 0x13E730u: goto label_13e730;
            case 0x13E738u: goto label_13e738;
            case 0x13E740u: goto label_13e740;
            case 0x13E758u: goto label_13e758;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13E76Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
