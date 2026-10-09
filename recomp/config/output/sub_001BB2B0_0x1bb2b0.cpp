#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB2B0
// Address: 0x1bb2b0 - 0x1bb6e0
void sub_001BB2B0_0x1bb2b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB2B0_0x1bb2b0");
#endif

    switch (ctx->pc) {
        case 0x1bb2e8u: goto label_1bb2e8;
        case 0x1bb2f8u: goto label_1bb2f8;
        case 0x1bb304u: goto label_1bb304;
        case 0x1bb310u: goto label_1bb310;
        case 0x1bb31cu: goto label_1bb31c;
        case 0x1bb328u: goto label_1bb328;
        case 0x1bb334u: goto label_1bb334;
        case 0x1bb340u: goto label_1bb340;
        case 0x1bb34cu: goto label_1bb34c;
        case 0x1bb354u: goto label_1bb354;
        case 0x1bb36cu: goto label_1bb36c;
        case 0x1bb384u: goto label_1bb384;
        case 0x1bb3a8u: goto label_1bb3a8;
        case 0x1bb3c8u: goto label_1bb3c8;
        case 0x1bb3e0u: goto label_1bb3e0;
        case 0x1bb3ecu: goto label_1bb3ec;
        case 0x1bb3f8u: goto label_1bb3f8;
        case 0x1bb404u: goto label_1bb404;
        case 0x1bb410u: goto label_1bb410;
        case 0x1bb424u: goto label_1bb424;
        case 0x1bb438u: goto label_1bb438;
        case 0x1bb460u: goto label_1bb460;
        case 0x1bb4b0u: goto label_1bb4b0;
        default: break;
    }

    ctx->pc = 0x1bb2b0u;

    // 0x1bb2b0: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x1bb2b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1bb2b4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1bb2b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1bb2b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bb2b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bb2bc: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1bb2bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1bb2c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bb2c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bb2c4: 0x24424e28  addiu       $v0, $v0, 0x4E28
    ctx->pc = 0x1bb2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20008));
    // 0x1bb2c8: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x1bb2c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1bb2cc: 0x27a300b8  addiu       $v1, $sp, 0xB8
    ctx->pc = 0x1bb2ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 184));
    // 0x1bb2d0: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1bb2d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1bb2d4: 0x24a54dc8  addiu       $a1, $a1, 0x4DC8
    ctx->pc = 0x1bb2d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19912));
    // 0x1bb2d8: 0x90420004  lbu         $v0, 0x4($v0)
    ctx->pc = 0x1bb2d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1bb2dc: 0xe4600000  swc1        $f0, 0x0($v1)
    ctx->pc = 0x1bb2dcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
    // 0x1bb2e0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BB2E0u;
    SET_GPR_U32(ctx, 31, 0x1BB2E8u);
    ctx->pc = 0x1BB2E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB2E0u;
            // 0x1bb2e4: 0xa0620004  sb          $v0, 0x4($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 4), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB2E8u; }
        if (ctx->pc != 0x1BB2E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB2E8u; }
        if (ctx->pc != 0x1BB2E8u) { return; }
    }
    ctx->pc = 0x1BB2E8u;
label_1bb2e8:
    // 0x1bb2e8: 0x3c050023  lui         $a1, 0x23
    ctx->pc = 0x1bb2e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)35 << 16));
    // 0x1bb2ec: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1bb2ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1bb2f0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BB2F0u;
    SET_GPR_U32(ctx, 31, 0x1BB2F8u);
    ctx->pc = 0x1BB2F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB2F0u;
            // 0x1bb2f4: 0x24a54dd8  addiu       $a1, $a1, 0x4DD8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB2F8u; }
        if (ctx->pc != 0x1BB2F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB2F8u; }
        if (ctx->pc != 0x1BB2F8u) { return; }
    }
    ctx->pc = 0x1BB2F8u;
label_1bb2f8:
    // 0x1bb2f8: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x1bb2f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x1bb2fc: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1BB2FCu;
    SET_GPR_U32(ctx, 31, 0x1BB304u);
    ctx->pc = 0x1BB300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB2FCu;
            // 0x1bb300: 0x27a500b8  addiu       $a1, $sp, 0xB8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB304u; }
        if (ctx->pc != 0x1BB304u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB304u; }
        if (ctx->pc != 0x1BB304u) { return; }
    }
    ctx->pc = 0x1BB304u;
label_1bb304:
    // 0x1bb304: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1bb304u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb308: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BB308u;
    SET_GPR_U32(ctx, 31, 0x1BB310u);
    ctx->pc = 0x1BB30Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB308u;
            // 0x1bb30c: 0x27a400a8  addiu       $a0, $sp, 0xA8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB310u; }
        if (ctx->pc != 0x1BB310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB310u; }
        if (ctx->pc != 0x1BB310u) { return; }
    }
    ctx->pc = 0x1BB310u;
label_1bb310:
    // 0x1bb310: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1bb310u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb314: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1BB314u;
    SET_GPR_U32(ctx, 31, 0x1BB31Cu);
    ctx->pc = 0x1BB318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB314u;
            // 0x1bb318: 0x27a500b8  addiu       $a1, $sp, 0xB8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB31Cu; }
        if (ctx->pc != 0x1BB31Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB31Cu; }
        if (ctx->pc != 0x1BB31Cu) { return; }
    }
    ctx->pc = 0x1BB31Cu;
label_1bb31c:
    // 0x1bb31c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1bb31cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb320: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BB320u;
    SET_GPR_U32(ctx, 31, 0x1BB328u);
    ctx->pc = 0x1BB324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB320u;
            // 0x1bb324: 0x27a400a0  addiu       $a0, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB328u; }
        if (ctx->pc != 0x1BB328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB328u; }
        if (ctx->pc != 0x1BB328u) { return; }
    }
    ctx->pc = 0x1BB328u;
label_1bb328:
    // 0x1bb328: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1bb328u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb32c: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1BB32Cu;
    SET_GPR_U32(ctx, 31, 0x1BB334u);
    ctx->pc = 0x1BB330u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB32Cu;
            // 0x1bb330: 0x27a500b8  addiu       $a1, $sp, 0xB8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB334u; }
        if (ctx->pc != 0x1BB334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB334u; }
        if (ctx->pc != 0x1BB334u) { return; }
    }
    ctx->pc = 0x1BB334u;
label_1bb334:
    // 0x1bb334: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1bb334u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb338: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BB338u;
    SET_GPR_U32(ctx, 31, 0x1BB340u);
    ctx->pc = 0x1BB33Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB338u;
            // 0x1bb33c: 0x27a400b0  addiu       $a0, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB340u; }
        if (ctx->pc != 0x1BB340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB340u; }
        if (ctx->pc != 0x1BB340u) { return; }
    }
    ctx->pc = 0x1BB340u;
label_1bb340:
    // 0x1bb340: 0x27a40088  addiu       $a0, $sp, 0x88
    ctx->pc = 0x1bb340u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 136));
    // 0x1bb344: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BB344u;
    SET_GPR_U32(ctx, 31, 0x1BB34Cu);
    ctx->pc = 0x1BB348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB344u;
            // 0x1bb348: 0x27a500b2  addiu       $a1, $sp, 0xB2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 178));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB34Cu; }
        if (ctx->pc != 0x1BB34Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB34Cu; }
        if (ctx->pc != 0x1BB34Cu) { return; }
    }
    ctx->pc = 0x1BB34Cu;
label_1bb34c:
    // 0x1bb34c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1BB34Cu;
    {
        const bool branch_taken_0x1bb34c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB350u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB34Cu;
            // 0x1bb350: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb34c) {
            ctx->pc = 0x1BB390u;
            goto label_1bb390;
        }
    }
    ctx->pc = 0x1BB354u;
label_1bb354:
    // 0x1bb354: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1bb354u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1bb358: 0x24424df0  addiu       $v0, $v0, 0x4DF0
    ctx->pc = 0x1bb358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19952));
    // 0x1bb35c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1bb35cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1bb360: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1bb360u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1bb364: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1BB364u;
    SET_GPR_U32(ctx, 31, 0x1BB36Cu);
    ctx->pc = 0x1BB368u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB364u;
            // 0x1bb368: 0x27a500a8  addiu       $a1, $sp, 0xA8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB36Cu; }
        if (ctx->pc != 0x1BB36Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB36Cu; }
        if (ctx->pc != 0x1BB36Cu) { return; }
    }
    ctx->pc = 0x1BB36Cu;
label_1bb36c:
    // 0x1bb36c: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BB36Cu;
    {
        const bool branch_taken_0x1bb36c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB370u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB36Cu;
            // 0x1bb370: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb36c) {
            ctx->pc = 0x1BB38Cu;
            goto label_1bb38c;
        }
    }
    ctx->pc = 0x1BB374u;
    // 0x1bb374: 0x26060001  addiu       $a2, $s0, 0x1
    ctx->pc = 0x1bb374u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1bb378: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1bb378u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1bb37c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BB37Cu;
    SET_GPR_U32(ctx, 31, 0x1BB384u);
    ctx->pc = 0x1BB380u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB37Cu;
            // 0x1bb380: 0x24a50298  addiu       $a1, $a1, 0x298 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 664));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB384u; }
        if (ctx->pc != 0x1BB384u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB384u; }
        if (ctx->pc != 0x1BB384u) { return; }
    }
    ctx->pc = 0x1BB384u;
label_1bb384:
    // 0x1bb384: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1BB384u;
    {
        const bool branch_taken_0x1bb384 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB384u;
            // 0x1bb388: 0x27a400a0  addiu       $a0, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb384) {
            ctx->pc = 0x1BB3A0u;
            goto label_1bb3a0;
        }
    }
    ctx->pc = 0x1BB38Cu;
label_1bb38c:
    // 0x1bb38c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1bb38cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1bb390:
    // 0x1bb390: 0x2a02000c  slti        $v0, $s0, 0xC
    ctx->pc = 0x1bb390u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)12) ? 1 : 0);
    // 0x1bb394: 0x1440ffef  bnez        $v0, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1BB394u;
    {
        const bool branch_taken_0x1bb394 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB394u;
            // 0x1bb398: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb394) {
            ctx->pc = 0x1BB354u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bb354;
        }
    }
    ctx->pc = 0x1BB39Cu;
    // 0x1bb39c: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1bb39cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
label_1bb3a0:
    // 0x1bb3a0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1BB3A0u;
    SET_GPR_U32(ctx, 31, 0x1BB3A8u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3A8u; }
        if (ctx->pc != 0x1BB3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3A8u; }
        if (ctx->pc != 0x1BB3A8u) { return; }
    }
    ctx->pc = 0x1BB3A8u;
label_1bb3a8:
    // 0x1bb3a8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1bb3a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb3ac: 0x14430008  bne         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BB3ACu;
    {
        const bool branch_taken_0x1bb3ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1BB3B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB3ACu;
            // 0x1bb3b0: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb3ac) {
            ctx->pc = 0x1BB3D0u;
            goto label_1bb3d0;
        }
    }
    ctx->pc = 0x1BB3B4u;
    // 0x1bb3b4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bb3b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bb3b8: 0x27a40078  addiu       $a0, $sp, 0x78
    ctx->pc = 0x1bb3b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 120));
    // 0x1bb3bc: 0x24a502a0  addiu       $a1, $a1, 0x2A0
    ctx->pc = 0x1bb3bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 672));
    // 0x1bb3c0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BB3C0u;
    SET_GPR_U32(ctx, 31, 0x1BB3C8u);
    ctx->pc = 0x1BB3C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB3C0u;
            // 0x1bb3c4: 0x27a600a0  addiu       $a2, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3C8u; }
        if (ctx->pc != 0x1BB3C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3C8u; }
        if (ctx->pc != 0x1BB3C8u) { return; }
    }
    ctx->pc = 0x1BB3C8u;
label_1bb3c8:
    // 0x1bb3c8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1BB3C8u;
    {
        const bool branch_taken_0x1bb3c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB3CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB3C8u;
            // 0x1bb3cc: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb3c8) {
            ctx->pc = 0x1BB3E4u;
            goto label_1bb3e4;
        }
    }
    ctx->pc = 0x1BB3D0u;
label_1bb3d0:
    // 0x1bb3d0: 0x27a40078  addiu       $a0, $sp, 0x78
    ctx->pc = 0x1bb3d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 120));
    // 0x1bb3d4: 0x24a502a8  addiu       $a1, $a1, 0x2A8
    ctx->pc = 0x1bb3d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 680));
    // 0x1bb3d8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BB3D8u;
    SET_GPR_U32(ctx, 31, 0x1BB3E0u);
    ctx->pc = 0x1BB3DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB3D8u;
            // 0x1bb3dc: 0x27a600a0  addiu       $a2, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3E0u; }
        if (ctx->pc != 0x1BB3E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3E0u; }
        if (ctx->pc != 0x1BB3E0u) { return; }
    }
    ctx->pc = 0x1BB3E0u;
label_1bb3e0:
    // 0x1bb3e0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1bb3e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
label_1bb3e4:
    // 0x1bb3e4: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1BB3E4u;
    SET_GPR_U32(ctx, 31, 0x1BB3ECu);
    ctx->pc = 0x1BB3E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB3E4u;
            // 0x1bb3e8: 0x27a500b8  addiu       $a1, $sp, 0xB8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3ECu; }
        if (ctx->pc != 0x1BB3ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3ECu; }
        if (ctx->pc != 0x1BB3ECu) { return; }
    }
    ctx->pc = 0x1BB3ECu;
label_1bb3ec:
    // 0x1bb3ec: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1bb3ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb3f0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BB3F0u;
    SET_GPR_U32(ctx, 31, 0x1BB3F8u);
    ctx->pc = 0x1BB3F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB3F0u;
            // 0x1bb3f4: 0x27a40098  addiu       $a0, $sp, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3F8u; }
        if (ctx->pc != 0x1BB3F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB3F8u; }
        if (ctx->pc != 0x1BB3F8u) { return; }
    }
    ctx->pc = 0x1BB3F8u;
label_1bb3f8:
    // 0x1bb3f8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1bb3f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb3fc: 0xc0431fe  jal         func_10C7F8
    ctx->pc = 0x1BB3FCu;
    SET_GPR_U32(ctx, 31, 0x1BB404u);
    ctx->pc = 0x1BB400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB3FCu;
            // 0x1bb400: 0x27a500b8  addiu       $a1, $sp, 0xB8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10C7F8u;
    if (runtime->hasFunction(0x10C7F8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB404u; }
        if (ctx->pc != 0x1BB404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7F8_0x10c7f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB404u; }
        if (ctx->pc != 0x1BB404u) { return; }
    }
    ctx->pc = 0x1BB404u;
label_1bb404:
    // 0x1bb404: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1bb404u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb408: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1BB408u;
    SET_GPR_U32(ctx, 31, 0x1BB410u);
    ctx->pc = 0x1BB40Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB408u;
            // 0x1bb40c: 0x27a40090  addiu       $a0, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB410u; }
        if (ctx->pc != 0x1BB410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB410u; }
        if (ctx->pc != 0x1BB410u) { return; }
    }
    ctx->pc = 0x1BB410u;
label_1bb410:
    // 0x1bb410: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bb410u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bb414: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1bb414u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1bb418: 0x24a502a8  addiu       $a1, $a1, 0x2A8
    ctx->pc = 0x1bb418u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 680));
    // 0x1bb41c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BB41Cu;
    SET_GPR_U32(ctx, 31, 0x1BB424u);
    ctx->pc = 0x1BB420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB41Cu;
            // 0x1bb420: 0x27a60098  addiu       $a2, $sp, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB424u; }
        if (ctx->pc != 0x1BB424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB424u; }
        if (ctx->pc != 0x1BB424u) { return; }
    }
    ctx->pc = 0x1BB424u;
label_1bb424:
    // 0x1bb424: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bb424u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bb428: 0x27a40068  addiu       $a0, $sp, 0x68
    ctx->pc = 0x1bb428u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x1bb42c: 0x24a502a8  addiu       $a1, $a1, 0x2A8
    ctx->pc = 0x1bb42cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 680));
    // 0x1bb430: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BB430u;
    SET_GPR_U32(ctx, 31, 0x1BB438u);
    ctx->pc = 0x1BB434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB430u;
            // 0x1bb434: 0x27a60090  addiu       $a2, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB438u; }
        if (ctx->pc != 0x1BB438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB438u; }
        if (ctx->pc != 0x1BB438u) { return; }
    }
    ctx->pc = 0x1BB438u;
label_1bb438:
    // 0x1bb438: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bb438u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bb43c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bb43cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bb440: 0x248465a8  addiu       $a0, $a0, 0x65A8
    ctx->pc = 0x1bb440u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26024));
    // 0x1bb444: 0x24a502b0  addiu       $a1, $a1, 0x2B0
    ctx->pc = 0x1bb444u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 688));
    // 0x1bb448: 0x27a60088  addiu       $a2, $sp, 0x88
    ctx->pc = 0x1bb448u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 136));
    // 0x1bb44c: 0x27a70080  addiu       $a3, $sp, 0x80
    ctx->pc = 0x1bb44cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1bb450: 0x27a80078  addiu       $t0, $sp, 0x78
    ctx->pc = 0x1bb450u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 120));
    // 0x1bb454: 0x27a90070  addiu       $t1, $sp, 0x70
    ctx->pc = 0x1bb454u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1bb458: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1BB458u;
    SET_GPR_U32(ctx, 31, 0x1BB460u);
    ctx->pc = 0x1BB45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB458u;
            // 0x1bb45c: 0x27aa0068  addiu       $t2, $sp, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB460u; }
        if (ctx->pc != 0x1BB460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB460u; }
        if (ctx->pc != 0x1BB460u) { return; }
    }
    ctx->pc = 0x1BB460u;
label_1bb460:
    // 0x1bb460: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bb460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bb464: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bb464u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb468: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB468u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB468u;
            // 0x1bb46c: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB2E8u: goto label_1bb2e8;
            case 0x1BB2F8u: goto label_1bb2f8;
            case 0x1BB304u: goto label_1bb304;
            case 0x1BB310u: goto label_1bb310;
            case 0x1BB31Cu: goto label_1bb31c;
            case 0x1BB328u: goto label_1bb328;
            case 0x1BB334u: goto label_1bb334;
            case 0x1BB340u: goto label_1bb340;
            case 0x1BB34Cu: goto label_1bb34c;
            case 0x1BB354u: goto label_1bb354;
            case 0x1BB36Cu: goto label_1bb36c;
            case 0x1BB384u: goto label_1bb384;
            case 0x1BB38Cu: goto label_1bb38c;
            case 0x1BB390u: goto label_1bb390;
            case 0x1BB3A0u: goto label_1bb3a0;
            case 0x1BB3A8u: goto label_1bb3a8;
            case 0x1BB3C8u: goto label_1bb3c8;
            case 0x1BB3D0u: goto label_1bb3d0;
            case 0x1BB3E0u: goto label_1bb3e0;
            case 0x1BB3E4u: goto label_1bb3e4;
            case 0x1BB3ECu: goto label_1bb3ec;
            case 0x1BB3F8u: goto label_1bb3f8;
            case 0x1BB404u: goto label_1bb404;
            case 0x1BB410u: goto label_1bb410;
            case 0x1BB424u: goto label_1bb424;
            case 0x1BB438u: goto label_1bb438;
            case 0x1BB460u: goto label_1bb460;
            case 0x1BB4B0u: goto label_1bb4b0;
            case 0x1BB4DCu: goto label_1bb4dc;
            case 0x1BB504u: goto label_1bb504;
            case 0x1BB54Cu: goto label_1bb54c;
            case 0x1BB594u: goto label_1bb594;
            case 0x1BB5A8u: goto label_1bb5a8;
            case 0x1BB5E8u: goto label_1bb5e8;
            case 0x1BB610u: goto label_1bb610;
            case 0x1BB678u: goto label_1bb678;
            case 0x1BB6A4u: goto label_1bb6a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB470u;
    // 0x1bb470: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB2E8u: goto label_1bb2e8;
            case 0x1BB2F8u: goto label_1bb2f8;
            case 0x1BB304u: goto label_1bb304;
            case 0x1BB310u: goto label_1bb310;
            case 0x1BB31Cu: goto label_1bb31c;
            case 0x1BB328u: goto label_1bb328;
            case 0x1BB334u: goto label_1bb334;
            case 0x1BB340u: goto label_1bb340;
            case 0x1BB34Cu: goto label_1bb34c;
            case 0x1BB354u: goto label_1bb354;
            case 0x1BB36Cu: goto label_1bb36c;
            case 0x1BB384u: goto label_1bb384;
            case 0x1BB38Cu: goto label_1bb38c;
            case 0x1BB390u: goto label_1bb390;
            case 0x1BB3A0u: goto label_1bb3a0;
            case 0x1BB3A8u: goto label_1bb3a8;
            case 0x1BB3C8u: goto label_1bb3c8;
            case 0x1BB3D0u: goto label_1bb3d0;
            case 0x1BB3E0u: goto label_1bb3e0;
            case 0x1BB3E4u: goto label_1bb3e4;
            case 0x1BB3ECu: goto label_1bb3ec;
            case 0x1BB3F8u: goto label_1bb3f8;
            case 0x1BB404u: goto label_1bb404;
            case 0x1BB410u: goto label_1bb410;
            case 0x1BB424u: goto label_1bb424;
            case 0x1BB438u: goto label_1bb438;
            case 0x1BB460u: goto label_1bb460;
            case 0x1BB4B0u: goto label_1bb4b0;
            case 0x1BB4DCu: goto label_1bb4dc;
            case 0x1BB504u: goto label_1bb504;
            case 0x1BB54Cu: goto label_1bb54c;
            case 0x1BB594u: goto label_1bb594;
            case 0x1BB5A8u: goto label_1bb5a8;
            case 0x1BB5E8u: goto label_1bb5e8;
            case 0x1BB610u: goto label_1bb610;
            case 0x1BB678u: goto label_1bb678;
            case 0x1BB6A4u: goto label_1bb6a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB478u;
    // 0x1bb478: 0x0  nop
    ctx->pc = 0x1bb478u;
    // NOP
    // 0x1bb47c: 0x0  nop
    ctx->pc = 0x1bb47cu;
    // NOP
    // 0x1bb480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bb480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb484: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bb484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb488: 0x90830008  lbu         $v1, 0x8($a0)
    ctx->pc = 0x1bb488u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1bb48c: 0x14600013  bnez        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1BB48Cu;
    {
        const bool branch_taken_0x1bb48c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BB490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB48Cu;
            // 0x1bb490: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb48c) {
            ctx->pc = 0x1BB4DCu;
            goto label_1bb4dc;
        }
    }
    ctx->pc = 0x1BB494u;
    // 0x1bb494: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb494u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb498: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bb498u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bb49c: 0xa0820008  sb          $v0, 0x8($a0)
    ctx->pc = 0x1bb49cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 8), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bb4a0: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1bb4a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1bb4a4: 0x3c040031  lui         $a0, 0x31
    ctx->pc = 0x1bb4a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4a8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1BB4A8u;
    SET_GPR_U32(ctx, 31, 0x1BB4B0u);
    ctx->pc = 0x1BB4ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4A8u;
            // 0x1bb4ac: 0x24846650  addiu       $a0, $a0, 0x6650 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 26192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB4B0u; }
        if (ctx->pc != 0x1BB4B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB4B0u; }
        if (ctx->pc != 0x1BB4B0u) { return; }
    }
    ctx->pc = 0x1BB4B0u;
label_1bb4b0:
    // 0x1bb4b0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb4b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4b4: 0x24030280  addiu       $v1, $zero, 0x280
    ctx->pc = 0x1bb4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x1bb4b8: 0xa4206664  sh          $zero, 0x6664($at)
    ctx->pc = 0x1bb4b8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26212), (uint16_t)GPR_U32(ctx, 0));
    // 0x1bb4bc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb4bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4c0: 0xa4236668  sh          $v1, 0x6668($at)
    ctx->pc = 0x1bb4c0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26216), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bb4c4: 0x240301e0  addiu       $v1, $zero, 0x1E0
    ctx->pc = 0x1bb4c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 480));
    // 0x1bb4c8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb4c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4cc: 0xa423666a  sh          $v1, 0x666A($at)
    ctx->pc = 0x1bb4ccu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26218), (uint16_t)GPR_U32(ctx, 3));
    // 0x1bb4d0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb4d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb4d4: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1BB4D4u;
    {
        const bool branch_taken_0x1bb4d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB4D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4D4u;
            // 0x1bb4d8: 0xa4206666  sh          $zero, 0x6666($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 26214), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb4d4) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB4DCu;
label_1bb4dc:
    // 0x1bb4dc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bb4dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bb4e0: 0x90246650  lbu         $a0, 0x6650($at)
    ctx->pc = 0x1bb4e0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26192)));
    // 0x1bb4e4: 0x10830019  beq         $a0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1BB4E4u;
    {
        const bool branch_taken_0x1bb4e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BB4E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4E4u;
            // 0x1bb4e8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb4e4) {
            ctx->pc = 0x1BB54Cu;
            goto label_1bb54c;
        }
    }
    ctx->pc = 0x1BB4ECu;
    // 0x1bb4ec: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BB4ECu;
    {
        const bool branch_taken_0x1bb4ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BB4F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4ECu;
            // 0x1bb4f0: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb4ec) {
            ctx->pc = 0x1BB504u;
            goto label_1bb504;
        }
    }
    ctx->pc = 0x1BB4F4u;
    // 0x1bb4f4: 0x1080002c  beqz        $a0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1BB4F4u;
    {
        const bool branch_taken_0x1bb4f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bb4f4) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB4FCu;
    // 0x1bb4fc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1BB4FCu;
    {
        const bool branch_taken_0x1bb4fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB4FCu;
            // 0x1bb500: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb4fc) {
            ctx->pc = 0x1BB594u;
            goto label_1bb594;
        }
    }
    ctx->pc = 0x1BB504u;
label_1bb504:
    // 0x1bb504: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1bb504u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1bb508: 0xc422665c  lwc1        $f2, 0x665C($at)
    ctx->pc = 0x1bb508u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 26204)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1bb50c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1bb50cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb510: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb510u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb514: 0xc4216660  lwc1        $f1, 0x6660($at)
    ctx->pc = 0x1bb514u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 26208)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1bb518: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1bb518u;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1bb51c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb51cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb520: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1bb520u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1bb524: 0x45010020  bc1t        . + 4 + (0x20 << 2)
    ctx->pc = 0x1BB524u;
    {
        const bool branch_taken_0x1bb524 = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1BB528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB524u;
            // 0x1bb528: 0xe421665c  swc1        $f1, 0x665C($at) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26204), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb524) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB52Cu;
    // 0x1bb52c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb52cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb530: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1bb530u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1bb534: 0xe420665c  swc1        $f0, 0x665C($at)
    ctx->pc = 0x1bb534u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26204), bits); }
    // 0x1bb538: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb538u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb53c: 0xa0236650  sb          $v1, 0x6650($at)
    ctx->pc = 0x1bb53cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bb540: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb540u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb544: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1BB544u;
    {
        const bool branch_taken_0x1bb544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB544u;
            // 0x1bb548: 0xac236654  sw          $v1, 0x6654($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb544) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB54Cu;
label_1bb54c:
    // 0x1bb54c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb54cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb550: 0xc422665c  lwc1        $f2, 0x665C($at)
    ctx->pc = 0x1bb550u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 26204)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1bb554: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x1bb554u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb558: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb558u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb55c: 0xc4216660  lwc1        $f1, 0x6660($at)
    ctx->pc = 0x1bb55cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 26208)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1bb560: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1bb560u;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1bb564: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb564u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb568: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1bb568u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1bb56c: 0x4500000e  bc1f        . + 4 + (0xE << 2)
    ctx->pc = 0x1BB56Cu;
    {
        const bool branch_taken_0x1bb56c = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1BB570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB56Cu;
            // 0x1bb570: 0xe421665c  swc1        $f1, 0x665C($at) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26204), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb56c) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB574u;
    // 0x1bb574: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb574u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb578: 0x24030063  addiu       $v1, $zero, 0x63
    ctx->pc = 0x1bb578u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1bb57c: 0xe420665c  swc1        $f0, 0x665C($at)
    ctx->pc = 0x1bb57cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 26204), bits); }
    // 0x1bb580: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb580u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb584: 0xac236654  sw          $v1, 0x6654($at)
    ctx->pc = 0x1bb584u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 3));
    // 0x1bb588: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb588u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb58c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1BB58Cu;
    {
        const bool branch_taken_0x1bb58c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BB590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB58Cu;
            // 0x1bb590: 0xa0206650  sb          $zero, 0x6650($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb58c) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB594u;
label_1bb594:
    // 0x1bb594: 0x8c236654  lw          $v1, 0x6654($at)
    ctx->pc = 0x1bb594u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26196)));
    // 0x1bb598: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BB598u;
    {
        const bool branch_taken_0x1bb598 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bb598) {
            ctx->pc = 0x1BB5A8u;
            goto label_1bb5a8;
        }
    }
    ctx->pc = 0x1BB5A0u;
    // 0x1bb5a0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb5a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb5a4: 0xa0206650  sb          $zero, 0x6650($at)
    ctx->pc = 0x1bb5a4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 0));
label_1bb5a8:
    // 0x1bb5a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bb5a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb5ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB5ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB5B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB5ACu;
            // 0x1bb5b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB2E8u: goto label_1bb2e8;
            case 0x1BB2F8u: goto label_1bb2f8;
            case 0x1BB304u: goto label_1bb304;
            case 0x1BB310u: goto label_1bb310;
            case 0x1BB31Cu: goto label_1bb31c;
            case 0x1BB328u: goto label_1bb328;
            case 0x1BB334u: goto label_1bb334;
            case 0x1BB340u: goto label_1bb340;
            case 0x1BB34Cu: goto label_1bb34c;
            case 0x1BB354u: goto label_1bb354;
            case 0x1BB36Cu: goto label_1bb36c;
            case 0x1BB384u: goto label_1bb384;
            case 0x1BB38Cu: goto label_1bb38c;
            case 0x1BB390u: goto label_1bb390;
            case 0x1BB3A0u: goto label_1bb3a0;
            case 0x1BB3A8u: goto label_1bb3a8;
            case 0x1BB3C8u: goto label_1bb3c8;
            case 0x1BB3D0u: goto label_1bb3d0;
            case 0x1BB3E0u: goto label_1bb3e0;
            case 0x1BB3E4u: goto label_1bb3e4;
            case 0x1BB3ECu: goto label_1bb3ec;
            case 0x1BB3F8u: goto label_1bb3f8;
            case 0x1BB404u: goto label_1bb404;
            case 0x1BB410u: goto label_1bb410;
            case 0x1BB424u: goto label_1bb424;
            case 0x1BB438u: goto label_1bb438;
            case 0x1BB460u: goto label_1bb460;
            case 0x1BB4B0u: goto label_1bb4b0;
            case 0x1BB4DCu: goto label_1bb4dc;
            case 0x1BB504u: goto label_1bb504;
            case 0x1BB54Cu: goto label_1bb54c;
            case 0x1BB594u: goto label_1bb594;
            case 0x1BB5A8u: goto label_1bb5a8;
            case 0x1BB5E8u: goto label_1bb5e8;
            case 0x1BB610u: goto label_1bb610;
            case 0x1BB678u: goto label_1bb678;
            case 0x1BB6A4u: goto label_1bb6a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB5B4u;
    // 0x1bb5b4: 0x0  nop
    ctx->pc = 0x1bb5b4u;
    // NOP
    // 0x1bb5b8: 0x0  nop
    ctx->pc = 0x1bb5b8u;
    // NOP
    // 0x1bb5bc: 0x0  nop
    ctx->pc = 0x1bb5bcu;
    // NOP
    // 0x1bb5c0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb5c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb5c4: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1bb5c4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1bb5c8: 0x90236650  lbu         $v1, 0x6650($at)
    ctx->pc = 0x1bb5c8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26192)));
    // 0x1bb5cc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1bb5ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bb5d0: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BB5D0u;
    {
        const bool branch_taken_0x1bb5d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BB5D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB5D0u;
            // 0x1bb5d4: 0x24c66650  addiu       $a2, $a2, 0x6650 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb5d0) {
            ctx->pc = 0x1BB5E8u;
            goto label_1bb5e8;
        }
    }
    ctx->pc = 0x1BB5D8u;
    // 0x1bb5d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb5d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb5dc: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BB5DCu;
    {
        const bool branch_taken_0x1bb5dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1bb5dc) {
            ctx->pc = 0x1BB5E8u;
            goto label_1bb5e8;
        }
    }
    ctx->pc = 0x1BB5E4u;
    // 0x1bb5e4: 0xacc0000c  sw          $zero, 0xC($a2)
    ctx->pc = 0x1bb5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 0));
label_1bb5e8:
    // 0x1bb5e8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bb5e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bb5ec: 0x41c3c  dsll32      $v1, $a0, 16
    ctx->pc = 0x1bb5ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1bb5f0: 0x902243cc  lbu         $v0, 0x43CC($at)
    ctx->pc = 0x1bb5f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17356)));
    // 0x1bb5f4: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1bb5f4u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1bb5f8: 0x431007  srav        $v0, $v1, $v0
    ctx->pc = 0x1bb5f8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x1bb5fc: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1bb5fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1bb600: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1bb600u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1bb604: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BB604u;
    {
        const bool branch_taken_0x1bb604 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bb604) {
            ctx->pc = 0x1BB610u;
            goto label_1bb610;
        }
    }
    ctx->pc = 0x1BB60Cu;
    // 0x1bb60c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bb60cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1bb610:
    // 0x1bb610: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1bb610u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb614: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1bb614u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1bb618: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1bb618u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bb61c: 0xacc50008  sw          $a1, 0x8($a2)
    ctx->pc = 0x1bb61cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 5));
    // 0x1bb620: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1bb620u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1bb624: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb628: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb62c: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1bb62cu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1bb630: 0xe4c00010  swc1        $f0, 0x10($a2)
    ctx->pc = 0x1bb630u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 16), bits); }
    // 0x1bb634: 0xa0226650  sb          $v0, 0x6650($at)
    ctx->pc = 0x1bb634u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 2));
    // 0x1bb638: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb638u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb63c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB63Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB63Cu;
            // 0x1bb640: 0xac226654  sw          $v0, 0x6654($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB2E8u: goto label_1bb2e8;
            case 0x1BB2F8u: goto label_1bb2f8;
            case 0x1BB304u: goto label_1bb304;
            case 0x1BB310u: goto label_1bb310;
            case 0x1BB31Cu: goto label_1bb31c;
            case 0x1BB328u: goto label_1bb328;
            case 0x1BB334u: goto label_1bb334;
            case 0x1BB340u: goto label_1bb340;
            case 0x1BB34Cu: goto label_1bb34c;
            case 0x1BB354u: goto label_1bb354;
            case 0x1BB36Cu: goto label_1bb36c;
            case 0x1BB384u: goto label_1bb384;
            case 0x1BB38Cu: goto label_1bb38c;
            case 0x1BB390u: goto label_1bb390;
            case 0x1BB3A0u: goto label_1bb3a0;
            case 0x1BB3A8u: goto label_1bb3a8;
            case 0x1BB3C8u: goto label_1bb3c8;
            case 0x1BB3D0u: goto label_1bb3d0;
            case 0x1BB3E0u: goto label_1bb3e0;
            case 0x1BB3E4u: goto label_1bb3e4;
            case 0x1BB3ECu: goto label_1bb3ec;
            case 0x1BB3F8u: goto label_1bb3f8;
            case 0x1BB404u: goto label_1bb404;
            case 0x1BB410u: goto label_1bb410;
            case 0x1BB424u: goto label_1bb424;
            case 0x1BB438u: goto label_1bb438;
            case 0x1BB460u: goto label_1bb460;
            case 0x1BB4B0u: goto label_1bb4b0;
            case 0x1BB4DCu: goto label_1bb4dc;
            case 0x1BB504u: goto label_1bb504;
            case 0x1BB54Cu: goto label_1bb54c;
            case 0x1BB594u: goto label_1bb594;
            case 0x1BB5A8u: goto label_1bb5a8;
            case 0x1BB5E8u: goto label_1bb5e8;
            case 0x1BB610u: goto label_1bb610;
            case 0x1BB678u: goto label_1bb678;
            case 0x1BB6A4u: goto label_1bb6a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB644u;
    // 0x1bb644: 0x0  nop
    ctx->pc = 0x1bb644u;
    // NOP
    // 0x1bb648: 0x0  nop
    ctx->pc = 0x1bb648u;
    // NOP
    // 0x1bb64c: 0x0  nop
    ctx->pc = 0x1bb64cu;
    // NOP
    // 0x1bb650: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb650u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb654: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1bb654u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1bb658: 0x90236650  lbu         $v1, 0x6650($at)
    ctx->pc = 0x1bb658u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26192)));
    // 0x1bb65c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1bb65cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bb660: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BB660u;
    {
        const bool branch_taken_0x1bb660 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BB664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB660u;
            // 0x1bb664: 0x24c66650  addiu       $a2, $a2, 0x6650 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 26192));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb660) {
            ctx->pc = 0x1BB678u;
            goto label_1bb678;
        }
    }
    ctx->pc = 0x1BB668u;
    // 0x1bb668: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb66c: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BB66Cu;
    {
        const bool branch_taken_0x1bb66c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1BB670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB66Cu;
            // 0x1bb670: 0x3c023f80  lui         $v0, 0x3F80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bb66c) {
            ctx->pc = 0x1BB678u;
            goto label_1bb678;
        }
    }
    ctx->pc = 0x1BB674u;
    // 0x1bb674: 0xacc2000c  sw          $v0, 0xC($a2)
    ctx->pc = 0x1bb674u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 2));
label_1bb678:
    // 0x1bb678: 0xacc50008  sw          $a1, 0x8($a2)
    ctx->pc = 0x1bb678u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 5));
    // 0x1bb67c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bb67cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bb680: 0x902243cc  lbu         $v0, 0x43CC($at)
    ctx->pc = 0x1bb680u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17356)));
    // 0x1bb684: 0x41c3c  dsll32      $v1, $a0, 16
    ctx->pc = 0x1bb684u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 16));
    // 0x1bb688: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1bb688u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1bb68c: 0x431007  srav        $v0, $v1, $v0
    ctx->pc = 0x1bb68cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
    // 0x1bb690: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1bb690u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1bb694: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x1bb694u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
    // 0x1bb698: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BB698u;
    {
        const bool branch_taken_0x1bb698 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bb698) {
            ctx->pc = 0x1BB6A4u;
            goto label_1bb6a4;
        }
    }
    ctx->pc = 0x1BB6A0u;
    // 0x1bb6a0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bb6a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1bb6a4:
    // 0x1bb6a4: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1bb6a4u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1bb6a8: 0x3c02bf80  lui         $v0, 0xBF80
    ctx->pc = 0x1bb6a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
    // 0x1bb6ac: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1bb6acu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1bb6b0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bb6b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bb6b4: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1bb6b4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1bb6b8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb6b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb6bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1bb6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bb6c0: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1bb6c0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1bb6c4: 0xe4c00010  swc1        $f0, 0x10($a2)
    ctx->pc = 0x1bb6c4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 6), 16), bits); }
    // 0x1bb6c8: 0xa0236650  sb          $v1, 0x6650($at)
    ctx->pc = 0x1bb6c8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 26192), (uint8_t)GPR_U32(ctx, 3));
    // 0x1bb6cc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bb6ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bb6d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB6D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB6D0u;
            // 0x1bb6d4: 0xac236654  sw          $v1, 0x6654($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 26196), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB2E8u: goto label_1bb2e8;
            case 0x1BB2F8u: goto label_1bb2f8;
            case 0x1BB304u: goto label_1bb304;
            case 0x1BB310u: goto label_1bb310;
            case 0x1BB31Cu: goto label_1bb31c;
            case 0x1BB328u: goto label_1bb328;
            case 0x1BB334u: goto label_1bb334;
            case 0x1BB340u: goto label_1bb340;
            case 0x1BB34Cu: goto label_1bb34c;
            case 0x1BB354u: goto label_1bb354;
            case 0x1BB36Cu: goto label_1bb36c;
            case 0x1BB384u: goto label_1bb384;
            case 0x1BB38Cu: goto label_1bb38c;
            case 0x1BB390u: goto label_1bb390;
            case 0x1BB3A0u: goto label_1bb3a0;
            case 0x1BB3A8u: goto label_1bb3a8;
            case 0x1BB3C8u: goto label_1bb3c8;
            case 0x1BB3D0u: goto label_1bb3d0;
            case 0x1BB3E0u: goto label_1bb3e0;
            case 0x1BB3E4u: goto label_1bb3e4;
            case 0x1BB3ECu: goto label_1bb3ec;
            case 0x1BB3F8u: goto label_1bb3f8;
            case 0x1BB404u: goto label_1bb404;
            case 0x1BB410u: goto label_1bb410;
            case 0x1BB424u: goto label_1bb424;
            case 0x1BB438u: goto label_1bb438;
            case 0x1BB460u: goto label_1bb460;
            case 0x1BB4B0u: goto label_1bb4b0;
            case 0x1BB4DCu: goto label_1bb4dc;
            case 0x1BB504u: goto label_1bb504;
            case 0x1BB54Cu: goto label_1bb54c;
            case 0x1BB594u: goto label_1bb594;
            case 0x1BB5A8u: goto label_1bb5a8;
            case 0x1BB5E8u: goto label_1bb5e8;
            case 0x1BB610u: goto label_1bb610;
            case 0x1BB678u: goto label_1bb678;
            case 0x1BB6A4u: goto label_1bb6a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB6D8u;
    // 0x1bb6d8: 0x0  nop
    ctx->pc = 0x1bb6d8u;
    // NOP
    // 0x1bb6dc: 0x0  nop
    ctx->pc = 0x1bb6dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
