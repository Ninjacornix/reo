#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AC650
// Address: 0x1ac650 - 0x1ac710
void sub_001AC650_0x1ac650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AC650_0x1ac650");
#endif

    switch (ctx->pc) {
        case 0x1ac668u: goto label_1ac668;
        case 0x1ac670u: goto label_1ac670;
        case 0x1ac678u: goto label_1ac678;
        case 0x1ac688u: goto label_1ac688;
        case 0x1ac69cu: goto label_1ac69c;
        case 0x1ac6a4u: goto label_1ac6a4;
        case 0x1ac6acu: goto label_1ac6ac;
        case 0x1ac6e0u: goto label_1ac6e0;
        case 0x1ac6ecu: goto label_1ac6ec;
        case 0x1ac6f8u: goto label_1ac6f8;
        default: break;
    }

    ctx->pc = 0x1ac650u;

    // 0x1ac650: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ac650u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ac654: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1ac654u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1ac658: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ac658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ac65c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1ac65cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac660: 0xc06a25c  jal         func_1A8970
    ctx->pc = 0x1AC660u;
    SET_GPR_U32(ctx, 31, 0x1AC668u);
    ctx->pc = 0x1AC664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC660u;
            // 0x1ac664: 0x24a5fde0  addiu       $a1, $a1, -0x220 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966752));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8970u;
    if (runtime->hasFunction(0x1A8970u)) {
        auto targetFn = runtime->lookupFunction(0x1A8970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC668u; }
        if (ctx->pc != 0x1AC668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8970_0x1a8970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC668u; }
        if (ctx->pc != 0x1AC668u) { return; }
    }
    ctx->pc = 0x1AC668u;
label_1ac668:
    // 0x1ac668: 0xc073098  jal         func_1CC260
    ctx->pc = 0x1AC668u;
    SET_GPR_U32(ctx, 31, 0x1AC670u);
    ctx->pc = 0x1CC260u;
    if (runtime->hasFunction(0x1CC260u)) {
        auto targetFn = runtime->lookupFunction(0x1CC260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC670u; }
        if (ctx->pc != 0x1AC670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC260_0x1cc260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC670u; }
        if (ctx->pc != 0x1AC670u) { return; }
    }
    ctx->pc = 0x1AC670u;
label_1ac670:
    // 0x1ac670: 0xc04a87a  jal         func_12A1E8
    ctx->pc = 0x1AC670u;
    SET_GPR_U32(ctx, 31, 0x1AC678u);
    ctx->pc = 0x12A1E8u;
    if (runtime->hasFunction(0x12A1E8u)) {
        auto targetFn = runtime->lookupFunction(0x12A1E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC678u; }
        if (ctx->pc != 0x1AC678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A1E8_0x12a1e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC678u; }
        if (ctx->pc != 0x1AC678u) { return; }
    }
    ctx->pc = 0x1AC678u;
label_1ac678:
    // 0x1ac678: 0x3c04001b  lui         $a0, 0x1B
    ctx->pc = 0x1ac678u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)27 << 16));
    // 0x1ac67c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ac67cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac680: 0xc04ad88  jal         func_12B620
    ctx->pc = 0x1AC680u;
    SET_GPR_U32(ctx, 31, 0x1AC688u);
    ctx->pc = 0x1AC684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC680u;
            // 0x1ac684: 0x2484c640  addiu       $a0, $a0, -0x39C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B620u;
    if (runtime->hasFunction(0x12B620u)) {
        auto targetFn = runtime->lookupFunction(0x12B620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC688u; }
        if (ctx->pc != 0x1AC688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B620_0x12b620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC688u; }
        if (ctx->pc != 0x1AC688u) { return; }
    }
    ctx->pc = 0x1AC688u;
label_1ac688:
    // 0x1ac688: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac688u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac68c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ac68cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ac690: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1ac690u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ac694: 0xc06a338  jal         func_1A8CE0
    ctx->pc = 0x1AC694u;
    SET_GPR_U32(ctx, 31, 0x1AC69Cu);
    ctx->pc = 0x1AC698u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC694u;
            // 0x1ac698: 0xa02243d7  sb          $v0, 0x43D7($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17367), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8CE0u;
    if (runtime->hasFunction(0x1A8CE0u)) {
        auto targetFn = runtime->lookupFunction(0x1A8CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC69Cu; }
        if (ctx->pc != 0x1AC69Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8CE0_0x1a8ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC69Cu; }
        if (ctx->pc != 0x1AC69Cu) { return; }
    }
    ctx->pc = 0x1AC69Cu;
label_1ac69c:
    // 0x1ac69c: 0xc06a61c  jal         func_1A9870
    ctx->pc = 0x1AC69Cu;
    SET_GPR_U32(ctx, 31, 0x1AC6A4u);
    ctx->pc = 0x1A9870u;
    if (runtime->hasFunction(0x1A9870u)) {
        auto targetFn = runtime->lookupFunction(0x1A9870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6A4u; }
        if (ctx->pc != 0x1AC6A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9870_0x1a9870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6A4u; }
        if (ctx->pc != 0x1AC6A4u) { return; }
    }
    ctx->pc = 0x1AC6A4u;
label_1ac6a4:
    // 0x1ac6a4: 0xc06ad3c  jal         func_1AB4F0
    ctx->pc = 0x1AC6A4u;
    SET_GPR_U32(ctx, 31, 0x1AC6ACu);
    ctx->pc = 0x1AB4F0u;
    if (runtime->hasFunction(0x1AB4F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB4F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6ACu; }
        if (ctx->pc != 0x1AC6ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB4F0_0x1ab4f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6ACu; }
        if (ctx->pc != 0x1AC6ACu) { return; }
    }
    ctx->pc = 0x1AC6ACu;
label_1ac6ac:
    // 0x1ac6ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ac6acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ac6b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC6B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AC6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC6B0u;
            // 0x1ac6b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AC668u: goto label_1ac668;
            case 0x1AC670u: goto label_1ac670;
            case 0x1AC678u: goto label_1ac678;
            case 0x1AC688u: goto label_1ac688;
            case 0x1AC69Cu: goto label_1ac69c;
            case 0x1AC6A4u: goto label_1ac6a4;
            case 0x1AC6ACu: goto label_1ac6ac;
            case 0x1AC6E0u: goto label_1ac6e0;
            case 0x1AC6ECu: goto label_1ac6ec;
            case 0x1AC6F8u: goto label_1ac6f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC6B8u;
    // 0x1ac6b8: 0x0  nop
    ctx->pc = 0x1ac6b8u;
    // NOP
    // 0x1ac6bc: 0x0  nop
    ctx->pc = 0x1ac6bcu;
    // NOP
    // 0x1ac6c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC6C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AC668u: goto label_1ac668;
            case 0x1AC670u: goto label_1ac670;
            case 0x1AC678u: goto label_1ac678;
            case 0x1AC688u: goto label_1ac688;
            case 0x1AC69Cu: goto label_1ac69c;
            case 0x1AC6A4u: goto label_1ac6a4;
            case 0x1AC6ACu: goto label_1ac6ac;
            case 0x1AC6E0u: goto label_1ac6e0;
            case 0x1AC6ECu: goto label_1ac6ec;
            case 0x1AC6F8u: goto label_1ac6f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC6C8u;
    // 0x1ac6c8: 0x0  nop
    ctx->pc = 0x1ac6c8u;
    // NOP
    // 0x1ac6cc: 0x0  nop
    ctx->pc = 0x1ac6ccu;
    // NOP
    // 0x1ac6d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ac6d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ac6d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ac6d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ac6d8: 0xc069c78  jal         func_1A71E0
    ctx->pc = 0x1AC6D8u;
    SET_GPR_U32(ctx, 31, 0x1AC6E0u);
    ctx->pc = 0x1A71E0u;
    if (runtime->hasFunction(0x1A71E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A71E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6E0u; }
        if (ctx->pc != 0x1AC6E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A71E0_0x1a71e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6E0u; }
        if (ctx->pc != 0x1AC6E0u) { return; }
    }
    ctx->pc = 0x1AC6E0u;
label_1ac6e0:
    // 0x1ac6e0: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1ac6e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1ac6e4: 0xc069fec  jal         func_1A7FB0
    ctx->pc = 0x1AC6E4u;
    SET_GPR_U32(ctx, 31, 0x1AC6ECu);
    ctx->pc = 0x1AC6E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC6E4u;
            // 0x1ac6e8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7FB0u;
    if (runtime->hasFunction(0x1A7FB0u)) {
        auto targetFn = runtime->lookupFunction(0x1A7FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6ECu; }
        if (ctx->pc != 0x1AC6ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7FB0_0x1a7fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6ECu; }
        if (ctx->pc != 0x1AC6ECu) { return; }
    }
    ctx->pc = 0x1AC6ECu;
label_1ac6ec:
    // 0x1ac6ec: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ac6ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ac6f0: 0xc06b570  jal         func_1AD5C0
    ctx->pc = 0x1AC6F0u;
    SET_GPR_U32(ctx, 31, 0x1AC6F8u);
    ctx->pc = 0x1AC6F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC6F0u;
            // 0x1ac6f4: 0xac203838  sw          $zero, 0x3838($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 14392), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD5C0u;
    if (runtime->hasFunction(0x1AD5C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AD5C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6F8u; }
        if (ctx->pc != 0x1AC6F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD5C0_0x1ad5c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC6F8u; }
        if (ctx->pc != 0x1AC6F8u) { return; }
    }
    ctx->pc = 0x1AC6F8u;
label_1ac6f8:
    // 0x1ac6f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ac6f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ac6fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ac6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac700: 0x3e00008  jr          $ra
    ctx->pc = 0x1AC700u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AC704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC700u;
            // 0x1ac704: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AC668u: goto label_1ac668;
            case 0x1AC670u: goto label_1ac670;
            case 0x1AC678u: goto label_1ac678;
            case 0x1AC688u: goto label_1ac688;
            case 0x1AC69Cu: goto label_1ac69c;
            case 0x1AC6A4u: goto label_1ac6a4;
            case 0x1AC6ACu: goto label_1ac6ac;
            case 0x1AC6E0u: goto label_1ac6e0;
            case 0x1AC6ECu: goto label_1ac6ec;
            case 0x1AC6F8u: goto label_1ac6f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AC708u;
    // 0x1ac708: 0x0  nop
    ctx->pc = 0x1ac708u;
    // NOP
    // 0x1ac70c: 0x0  nop
    ctx->pc = 0x1ac70cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
