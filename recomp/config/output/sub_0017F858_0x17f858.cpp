#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F858
// Address: 0x17f858 - 0x17f908
void sub_0017F858_0x17f858(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F858_0x17f858");
#endif

    switch (ctx->pc) {
        case 0x17f88cu: goto label_17f88c;
        case 0x17f8a0u: goto label_17f8a0;
        case 0x17f8acu: goto label_17f8ac;
        case 0x17f8bcu: goto label_17f8bc;
        case 0x17f8ccu: goto label_17f8cc;
        case 0x17f8dcu: goto label_17f8dc;
        case 0x17f8e8u: goto label_17f8e8;
        default: break;
    }

    ctx->pc = 0x17f858u;

    // 0x17f858: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x17f858u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x17f85c: 0xffb40090  sd          $s4, 0x90($sp)
    ctx->pc = 0x17f85cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 20));
    // 0x17f860: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x17f860u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f864: 0xffb30080  sd          $s3, 0x80($sp)
    ctx->pc = 0x17f864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 19));
    // 0x17f868: 0xffb20070  sd          $s2, 0x70($sp)
    ctx->pc = 0x17f868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 18));
    // 0x17f86c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x17f86cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f870: 0xffb10060  sd          $s1, 0x60($sp)
    ctx->pc = 0x17f870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 17));
    // 0x17f874: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x17f874u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f878: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x17f878u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f87c: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x17f87cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x17f880: 0xffbf00a0  sd          $ra, 0xA0($sp)
    ctx->pc = 0x17f880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x17f884: 0xc05fcf4  jal         func_17F3D0
    ctx->pc = 0x17F884u;
    SET_GPR_U32(ctx, 31, 0x17F88Cu);
    ctx->pc = 0x17F888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F884u;
            // 0x17f888: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F3D0u;
    if (runtime->hasFunction(0x17F3D0u)) {
        auto targetFn = runtime->lookupFunction(0x17F3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F88Cu; }
        if (ctx->pc != 0x17F88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F3D0_0x17f3d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F88Cu; }
        if (ctx->pc != 0x17F88Cu) { return; }
    }
    ctx->pc = 0x17F88Cu;
label_17f88c:
    // 0x17f88c: 0x27b00040  addiu       $s0, $sp, 0x40
    ctx->pc = 0x17f88cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x17f890: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17f890u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f894: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f894u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f898: 0xc05faee  jal         func_17EBB8
    ctx->pc = 0x17F898u;
    SET_GPR_U32(ctx, 31, 0x17F8A0u);
    ctx->pc = 0x17F89Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F898u;
            // 0x17f89c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EBB8u;
    if (runtime->hasFunction(0x17EBB8u)) {
        auto targetFn = runtime->lookupFunction(0x17EBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8A0u; }
        if (ctx->pc != 0x17F8A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EBB8_0x17ebb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8A0u; }
        if (ctx->pc != 0x17F8A0u) { return; }
    }
    ctx->pc = 0x17F8A0u;
label_17f8a0:
    // 0x17f8a0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17f8a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8a4: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F8A4u;
    SET_GPR_U32(ctx, 31, 0x17F8ACu);
    ctx->pc = 0x17F8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8A4u;
            // 0x17f8a8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8ACu; }
        if (ctx->pc != 0x17F8ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8ACu; }
        if (ctx->pc != 0x17F8ACu) { return; }
    }
    ctx->pc = 0x17F8ACu;
label_17f8ac:
    // 0x17f8ac: 0x27b00020  addiu       $s0, $sp, 0x20
    ctx->pc = 0x17f8acu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x17f8b0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17f8b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8b4: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F8B4u;
    SET_GPR_U32(ctx, 31, 0x17F8BCu);
    ctx->pc = 0x17F8B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8B4u;
            // 0x17f8b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8BCu; }
        if (ctx->pc != 0x17F8BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8BCu; }
        if (ctx->pc != 0x17F8BCu) { return; }
    }
    ctx->pc = 0x17F8BCu;
label_17f8bc:
    // 0x17f8bc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17f8bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8c0: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x17f8c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17f8c4: 0xc05faee  jal         func_17EBB8
    ctx->pc = 0x17F8C4u;
    SET_GPR_U32(ctx, 31, 0x17F8CCu);
    ctx->pc = 0x17F8C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8C4u;
            // 0x17f8c8: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EBB8u;
    if (runtime->hasFunction(0x17EBB8u)) {
        auto targetFn = runtime->lookupFunction(0x17EBB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8CCu; }
        if (ctx->pc != 0x17F8CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EBB8_0x17ebb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8CCu; }
        if (ctx->pc != 0x17F8CCu) { return; }
    }
    ctx->pc = 0x17F8CCu;
label_17f8cc:
    // 0x17f8cc: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x17f8ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8d0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17f8d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8d4: 0xc05fc56  jal         func_17F158
    ctx->pc = 0x17F8D4u;
    SET_GPR_U32(ctx, 31, 0x17F8DCu);
    ctx->pc = 0x17F8D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8D4u;
            // 0x17f8d8: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F158u;
    if (runtime->hasFunction(0x17F158u)) {
        auto targetFn = runtime->lookupFunction(0x17F158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8DCu; }
        if (ctx->pc != 0x17F8DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F158_0x17f158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8DCu; }
        if (ctx->pc != 0x17F8DCu) { return; }
    }
    ctx->pc = 0x17F8DCu;
label_17f8dc:
    // 0x17f8dc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x17f8dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f8e0: 0xc05fb68  jal         func_17EDA0
    ctx->pc = 0x17F8E0u;
    SET_GPR_U32(ctx, 31, 0x17F8E8u);
    ctx->pc = 0x17F8E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F8E0u;
            // 0x17f8e4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EDA0u;
    if (runtime->hasFunction(0x17EDA0u)) {
        auto targetFn = runtime->lookupFunction(0x17EDA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8E8u; }
        if (ctx->pc != 0x17F8E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EDA0_0x17eda0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F8E8u; }
        if (ctx->pc != 0x17F8E8u) { return; }
    }
    ctx->pc = 0x17F8E8u;
label_17f8e8:
    // 0x17f8e8: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x17f8e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x17f8ec: 0xdfb40090  ld          $s4, 0x90($sp)
    ctx->pc = 0x17f8ecu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x17f8f0: 0xdfb30080  ld          $s3, 0x80($sp)
    ctx->pc = 0x17f8f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x17f8f4: 0xdfb20070  ld          $s2, 0x70($sp)
    ctx->pc = 0x17f8f4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x17f8f8: 0xdfb10060  ld          $s1, 0x60($sp)
    ctx->pc = 0x17f8f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x17f8fc: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x17f8fcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17f900: 0x3e00008  jr          $ra
    ctx->pc = 0x17F900u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F900u;
            // 0x17f904: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F88Cu: goto label_17f88c;
            case 0x17F8A0u: goto label_17f8a0;
            case 0x17F8ACu: goto label_17f8ac;
            case 0x17F8BCu: goto label_17f8bc;
            case 0x17F8CCu: goto label_17f8cc;
            case 0x17F8DCu: goto label_17f8dc;
            case 0x17F8E8u: goto label_17f8e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F908u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
