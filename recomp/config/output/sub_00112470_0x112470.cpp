#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00112470
// Address: 0x112470 - 0x1124c8
void sub_00112470_0x112470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00112470_0x112470");
#endif

    switch (ctx->pc) {
        case 0x112488u: goto label_112488;
        case 0x1124b8u: goto label_1124b8;
        default: break;
    }

    ctx->pc = 0x112470u;

    // 0x112470: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x112470u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x112474: 0xffa40020  sd          $a0, 0x20($sp)
    ctx->pc = 0x112474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 4));
    // 0x112478: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x112478u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x11247c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11247cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x112480: 0xc044674  jal         func_1119D0
    ctx->pc = 0x112480u;
    SET_GPR_U32(ctx, 31, 0x112488u);
    ctx->pc = 0x112484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x112480u;
            // 0x112484: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1119D0u;
    if (runtime->hasFunction(0x1119D0u)) {
        auto targetFn = runtime->lookupFunction(0x1119D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112488u; }
        if (ctx->pc != 0x112488u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001119D0_0x1119d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112488u; }
        if (ctx->pc != 0x112488u) { return; }
    }
    ctx->pc = 0x112488u;
label_112488:
    // 0x112488: 0x3c053fff  lui         $a1, 0x3FFF
    ctx->pc = 0x112488u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)16383 << 16));
    // 0x11248c: 0x34a5ffff  ori         $a1, $a1, 0xFFFF
    ctx->pc = 0x11248cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)65535);
    // 0x112490: 0xdfa20010  ld          $v0, 0x10($sp)
    ctx->pc = 0x112490u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x112494: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x112494u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112498: 0x218b8  dsll        $v1, $v0, 2
    ctx->pc = 0x112498u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 2);
    // 0x11249c: 0x3183f  dsra32      $v1, $v1, 0
    ctx->pc = 0x11249cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1124a0: 0x451024  and         $v0, $v0, $a1
    ctx->pc = 0x1124a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 5));
    // 0x1124a4: 0x34670001  ori         $a3, $v1, 0x1
    ctx->pc = 0x1124a4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1);
    // 0x1124a8: 0x8fa60008  lw          $a2, 0x8($sp)
    ctx->pc = 0x1124a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1124ac: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x1124acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1124b0: 0xc044622  jal         func_111888
    ctx->pc = 0x1124B0u;
    SET_GPR_U32(ctx, 31, 0x1124B8u);
    ctx->pc = 0x1124B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1124B0u;
            // 0x1124b4: 0x62380a  movz        $a3, $v1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111888u;
    if (runtime->hasFunction(0x111888u)) {
        auto targetFn = runtime->lookupFunction(0x111888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1124B8u; }
        if (ctx->pc != 0x1124B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111888_0x111888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1124B8u; }
        if (ctx->pc != 0x1124B8u) { return; }
    }
    ctx->pc = 0x1124B8u;
label_1124b8:
    // 0x1124b8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1124b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1124bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1124BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1124C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1124BCu;
            // 0x1124c0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112488u: goto label_112488;
            case 0x1124B8u: goto label_1124b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1124C4u;
    // 0x1124c4: 0x0  nop
    ctx->pc = 0x1124c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
