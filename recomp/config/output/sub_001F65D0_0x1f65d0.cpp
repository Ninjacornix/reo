#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F65D0
// Address: 0x1f65d0 - 0x1f7160
void sub_001F65D0_0x1f65d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F65D0_0x1f65d0");
#endif

    switch (ctx->pc) {
        case 0x1f65f8u: goto label_1f65f8;
        case 0x1f660cu: goto label_1f660c;
        case 0x1f6620u: goto label_1f6620;
        case 0x1f6634u: goto label_1f6634;
        case 0x1f6644u: goto label_1f6644;
        case 0x1f665cu: goto label_1f665c;
        case 0x1f6670u: goto label_1f6670;
        case 0x1f6684u: goto label_1f6684;
        case 0x1f6698u: goto label_1f6698;
        case 0x1f66acu: goto label_1f66ac;
        case 0x1f66b0u: goto label_1f66b0;
        case 0x1f66c8u: goto label_1f66c8;
        case 0x1f66e4u: goto label_1f66e4;
        case 0x1f66fcu: goto label_1f66fc;
        case 0x1f6714u: goto label_1f6714;
        case 0x1f6728u: goto label_1f6728;
        case 0x1f6744u: goto label_1f6744;
        case 0x1f6790u: goto label_1f6790;
        case 0x1f6798u: goto label_1f6798;
        case 0x1f68acu: goto label_1f68ac;
        case 0x1f68ccu: goto label_1f68cc;
        case 0x1f691cu: goto label_1f691c;
        case 0x1f69acu: goto label_1f69ac;
        case 0x1f6a30u: goto label_1f6a30;
        case 0x1f6a38u: goto label_1f6a38;
        case 0x1f6a78u: goto label_1f6a78;
        case 0x1f6a90u: goto label_1f6a90;
        case 0x1f6a98u: goto label_1f6a98;
        case 0x1f6b50u: goto label_1f6b50;
        case 0x1f6b58u: goto label_1f6b58;
        case 0x1f6b9cu: goto label_1f6b9c;
        case 0x1f6bb4u: goto label_1f6bb4;
        case 0x1f6bbcu: goto label_1f6bbc;
        case 0x1f6c14u: goto label_1f6c14;
        case 0x1f6c1cu: goto label_1f6c1c;
        case 0x1f6c58u: goto label_1f6c58;
        case 0x1f6cbcu: goto label_1f6cbc;
        case 0x1f6cf4u: goto label_1f6cf4;
        case 0x1f6d58u: goto label_1f6d58;
        case 0x1f6e1cu: goto label_1f6e1c;
        case 0x1f6e3cu: goto label_1f6e3c;
        case 0x1f6e4cu: goto label_1f6e4c;
        case 0x1f6e5cu: goto label_1f6e5c;
        case 0x1f6e84u: goto label_1f6e84;
        case 0x1f6ea8u: goto label_1f6ea8;
        case 0x1f6eccu: goto label_1f6ecc;
        case 0x1f6ee8u: goto label_1f6ee8;
        case 0x1f6f00u: goto label_1f6f00;
        case 0x1f6f70u: goto label_1f6f70;
        case 0x1f6f78u: goto label_1f6f78;
        case 0x1f7078u: goto label_1f7078;
        default: break;
    }

    ctx->pc = 0x1f65d0u;

label_1f65d0:
    // 0x1f65d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1f65d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1f65d4: 0x24050016  addiu       $a1, $zero, 0x16
    ctx->pc = 0x1f65d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1f65d8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1f65d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1f65dc: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1f65dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f65e0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f65e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f65e4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1f65e4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f65e8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f65e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f65ec: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1f65ecu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f65f0: 0xc07d284  jal         func_1F4A10
    ctx->pc = 0x1F65F0u;
    SET_GPR_U32(ctx, 31, 0x1F65F8u);
    ctx->pc = 0x1F65F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F65F0u;
            // 0x1f65f4: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4A10u;
    if (runtime->hasFunction(0x1F4A10u)) {
        auto targetFn = runtime->lookupFunction(0x1F4A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F65F8u; }
        if (ctx->pc != 0x1F65F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4A10_0x1f4a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F65F8u; }
        if (ctx->pc != 0x1F65F8u) { return; }
    }
    ctx->pc = 0x1F65F8u;
label_1f65f8:
    // 0x1f65f8: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f65f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f65fc: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f65fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f6600: 0x90450000  lbu         $a1, 0x0($v0)
    ctx->pc = 0x1f6600u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f6604: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F6604u;
    SET_GPR_U32(ctx, 31, 0x1F660Cu);
    ctx->pc = 0x1F6608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6604u;
            // 0x1f6608: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F660Cu; }
        if (ctx->pc != 0x1F660Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F660Cu; }
        if (ctx->pc != 0x1F660Cu) { return; }
    }
    ctx->pc = 0x1F660Cu;
label_1f660c:
    // 0x1f660c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f660cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6610: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f6610u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f6614: 0x90450001  lbu         $a1, 0x1($v0)
    ctx->pc = 0x1f6614u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x1f6618: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F6618u;
    SET_GPR_U32(ctx, 31, 0x1F6620u);
    ctx->pc = 0x1F661Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6618u;
            // 0x1f661c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6620u; }
        if (ctx->pc != 0x1F6620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6620u; }
        if (ctx->pc != 0x1F6620u) { return; }
    }
    ctx->pc = 0x1F6620u;
label_1f6620:
    // 0x1f6620: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6620u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6624: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f6624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f6628: 0x90450002  lbu         $a1, 0x2($v0)
    ctx->pc = 0x1f6628u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1f662c: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F662Cu;
    SET_GPR_U32(ctx, 31, 0x1F6634u);
    ctx->pc = 0x1F6630u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F662Cu;
            // 0x1f6630: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6634u; }
        if (ctx->pc != 0x1F6634u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6634u; }
        if (ctx->pc != 0x1F6634u) { return; }
    }
    ctx->pc = 0x1F6634u;
label_1f6634:
    // 0x1f6634: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6634u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6638: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f6638u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f663c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F663Cu;
    SET_GPR_U32(ctx, 31, 0x1F6644u);
    ctx->pc = 0x1F6640u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F663Cu;
            // 0x1f6640: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6644u; }
        if (ctx->pc != 0x1F6644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6644u; }
        if (ctx->pc != 0x1F6644u) { return; }
    }
    ctx->pc = 0x1F6644u;
label_1f6644:
    // 0x1f6644: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f6644u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6648: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6648u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f664c: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f664cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f6650: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x1f6650u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1f6654: 0xc07d330  jal         func_1F4CC0
    ctx->pc = 0x1F6654u;
    SET_GPR_U32(ctx, 31, 0x1F665Cu);
    ctx->pc = 0x1F6658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6654u;
            // 0x1f6658: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4CC0u;
    if (runtime->hasFunction(0x1F4CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1F4CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F665Cu; }
        if (ctx->pc != 0x1F665Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4CC0_0x1f4cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F665Cu; }
        if (ctx->pc != 0x1F665Cu) { return; }
    }
    ctx->pc = 0x1F665Cu;
label_1f665c:
    // 0x1f665c: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f665cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6660: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f6660u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f6664: 0x90450008  lbu         $a1, 0x8($v0)
    ctx->pc = 0x1f6664u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1f6668: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F6668u;
    SET_GPR_U32(ctx, 31, 0x1F6670u);
    ctx->pc = 0x1F666Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6668u;
            // 0x1f666c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6670u; }
        if (ctx->pc != 0x1F6670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6670u; }
        if (ctx->pc != 0x1F6670u) { return; }
    }
    ctx->pc = 0x1F6670u;
label_1f6670:
    // 0x1f6670: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6670u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6674: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f6674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f6678: 0x90450009  lbu         $a1, 0x9($v0)
    ctx->pc = 0x1f6678u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 9)));
    // 0x1f667c: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F667Cu;
    SET_GPR_U32(ctx, 31, 0x1F6684u);
    ctx->pc = 0x1F6680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F667Cu;
            // 0x1f6680: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6684u; }
        if (ctx->pc != 0x1F6684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6684u; }
        if (ctx->pc != 0x1F6684u) { return; }
    }
    ctx->pc = 0x1F6684u;
label_1f6684:
    // 0x1f6684: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6684u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6688: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f6688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f668c: 0x8c45000c  lw          $a1, 0xC($v0)
    ctx->pc = 0x1f668cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1f6690: 0xc07d308  jal         func_1F4C20
    ctx->pc = 0x1F6690u;
    SET_GPR_U32(ctx, 31, 0x1F6698u);
    ctx->pc = 0x1F6694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6690u;
            // 0x1f6694: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4C20u;
    if (runtime->hasFunction(0x1F4C20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6698u; }
        if (ctx->pc != 0x1F6698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4C20_0x1f4c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6698u; }
        if (ctx->pc != 0x1F6698u) { return; }
    }
    ctx->pc = 0x1F6698u;
label_1f6698:
    // 0x1f6698: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6698u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f669c: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f669cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f66a0: 0x8c450010  lw          $a1, 0x10($v0)
    ctx->pc = 0x1f66a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1f66a4: 0xc07d308  jal         func_1F4C20
    ctx->pc = 0x1F66A4u;
    SET_GPR_U32(ctx, 31, 0x1F66ACu);
    ctx->pc = 0x1F66A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F66A4u;
            // 0x1f66a8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4C20u;
    if (runtime->hasFunction(0x1F4C20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F66ACu; }
        if (ctx->pc != 0x1F66ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4C20_0x1f4c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F66ACu; }
        if (ctx->pc != 0x1F66ACu) { return; }
    }
    ctx->pc = 0x1F66ACu;
label_1f66ac:
    // 0x1f66ac: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1f66acu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f66b0:
    // 0x1f66b0: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f66b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f66b4: 0x1180c0  sll         $s0, $s1, 3
    ctx->pc = 0x1f66b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1f66b8: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f66b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f66bc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1f66bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1f66c0: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1F66C0u;
    SET_GPR_U32(ctx, 31, 0x1F66C8u);
    ctx->pc = 0x1F66C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F66C0u;
            // 0x1f66c4: 0x8c440014  lw          $a0, 0x14($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F66C8u; }
        if (ctx->pc != 0x1F66C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F66C8u; }
        if (ctx->pc != 0x1F66C8u) { return; }
    }
    ctx->pc = 0x1F66C8u;
label_1f66c8:
    // 0x1f66c8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1f66c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f66cc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f66ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f66d0: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f66d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f66d4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1f66d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1f66d8: 0x8c450014  lw          $a1, 0x14($v0)
    ctx->pc = 0x1f66d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1f66dc: 0xc07d330  jal         func_1F4CC0
    ctx->pc = 0x1F66DCu;
    SET_GPR_U32(ctx, 31, 0x1F66E4u);
    ctx->pc = 0x1F66E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F66DCu;
            // 0x1f66e0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4CC0u;
    if (runtime->hasFunction(0x1F4CC0u)) {
        auto targetFn = runtime->lookupFunction(0x1F4CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F66E4u; }
        if (ctx->pc != 0x1F66E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4CC0_0x1f4cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F66E4u; }
        if (ctx->pc != 0x1F66E4u) { return; }
    }
    ctx->pc = 0x1F66E4u;
label_1f66e4:
    // 0x1f66e4: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f66e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f66e8: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f66e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f66ec: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1f66ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1f66f0: 0x90450018  lbu         $a1, 0x18($v0)
    ctx->pc = 0x1f66f0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x1f66f4: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F66F4u;
    SET_GPR_U32(ctx, 31, 0x1F66FCu);
    ctx->pc = 0x1F66F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F66F4u;
            // 0x1f66f8: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F66FCu; }
        if (ctx->pc != 0x1F66FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F66FCu; }
        if (ctx->pc != 0x1F66FCu) { return; }
    }
    ctx->pc = 0x1F66FCu;
label_1f66fc:
    // 0x1f66fc: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f66fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6700: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f6700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f6704: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1f6704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1f6708: 0x90450019  lbu         $a1, 0x19($v0)
    ctx->pc = 0x1f6708u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 25)));
    // 0x1f670c: 0xc07d2c8  jal         func_1F4B20
    ctx->pc = 0x1F670Cu;
    SET_GPR_U32(ctx, 31, 0x1F6714u);
    ctx->pc = 0x1F6710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F670Cu;
            // 0x1f6710: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4B20u;
    if (runtime->hasFunction(0x1F4B20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4B20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6714u; }
        if (ctx->pc != 0x1F6714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4B20_0x1f4b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6714u; }
        if (ctx->pc != 0x1F6714u) { return; }
    }
    ctx->pc = 0x1F6714u;
label_1f6714:
    // 0x1f6714: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1f6714u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1f6718: 0x2e220003  sltiu       $v0, $s1, 0x3
    ctx->pc = 0x1f6718u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x1f671c: 0x1440ffe4  bnez        $v0, . + 4 + (-0x1C << 2)
    ctx->pc = 0x1F671Cu;
    {
        const bool branch_taken_0x1f671c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f671c) {
            ctx->pc = 0x1F66B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f66b0;
        }
    }
    ctx->pc = 0x1F6724u;
    // 0x1f6724: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1f6724u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f6728:
    // 0x1f6728: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6728u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f672c: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x1f672cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1f6730: 0x8c22ec48  lw          $v0, -0x13B8($at)
    ctx->pc = 0x1f6730u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294962248)));
    // 0x1f6734: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1f6734u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f6738: 0x8c45002c  lw          $a1, 0x2C($v0)
    ctx->pc = 0x1f6738u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 44)));
    // 0x1f673c: 0xc07d308  jal         func_1F4C20
    ctx->pc = 0x1F673Cu;
    SET_GPR_U32(ctx, 31, 0x1F6744u);
    ctx->pc = 0x1F6740u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F673Cu;
            // 0x1f6740: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4C20u;
    if (runtime->hasFunction(0x1F4C20u)) {
        auto targetFn = runtime->lookupFunction(0x1F4C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6744u; }
        if (ctx->pc != 0x1F6744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4C20_0x1f4c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6744u; }
        if (ctx->pc != 0x1F6744u) { return; }
    }
    ctx->pc = 0x1F6744u;
label_1f6744:
    // 0x1f6744: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1f6744u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1f6748: 0x2e020008  sltiu       $v0, $s0, 0x8
    ctx->pc = 0x1f6748u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x1f674c: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1F674Cu;
    {
        const bool branch_taken_0x1f674c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f674c) {
            ctx->pc = 0x1F6728u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f6728;
        }
    }
    ctx->pc = 0x1F6754u;
    // 0x1f6754: 0x9643002c  lhu         $v1, 0x2C($s2)
    ctx->pc = 0x1f6754u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 44)));
    // 0x1f6758: 0x8e42001c  lw          $v0, 0x1C($s2)
    ctx->pc = 0x1f6758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x1f675c: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1f675cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1f6760: 0x31a03  sra         $v1, $v1, 8
    ctx->pc = 0x1f6760u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 8));
    // 0x1f6764: 0x3084ff00  andi        $a0, $a0, 0xFF00
    ctx->pc = 0x1f6764u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1f6768: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1f6768u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1f676c: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1f676cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1f6770: 0xa4430000  sh          $v1, 0x0($v0)
    ctx->pc = 0x1f6770u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1f6774: 0x8e42002c  lw          $v0, 0x2C($s2)
    ctx->pc = 0x1f6774u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 44)));
    // 0x1f6778: 0x8e440010  lw          $a0, 0x10($s2)
    ctx->pc = 0x1f6778u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1f677c: 0x8e45001c  lw          $a1, 0x1C($s2)
    ctx->pc = 0x1f677cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x1f6780: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1f6780u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1f6784: 0x2343c  dsll32      $a2, $v0, 16
    ctx->pc = 0x1f6784u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f6788: 0xc075aa4  jal         func_1D6A90
    ctx->pc = 0x1F6788u;
    SET_GPR_U32(ctx, 31, 0x1F6790u);
    ctx->pc = 0x1F678Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6788u;
            // 0x1f678c: 0x6343f  dsra32      $a2, $a2, 16 (Delay Slot)
        SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6A90u;
    if (runtime->hasFunction(0x1D6A90u)) {
        auto targetFn = runtime->lookupFunction(0x1D6A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6790u; }
        if (ctx->pc != 0x1F6790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6A90_0x1d6a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6790u; }
        if (ctx->pc != 0x1F6790u) { return; }
    }
    ctx->pc = 0x1F6790u;
label_1f6790:
    // 0x1f6790: 0xc07d16c  jal         func_1F45B0
    ctx->pc = 0x1F6790u;
    SET_GPR_U32(ctx, 31, 0x1F6798u);
    ctx->pc = 0x1F6794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6790u;
            // 0x1f6794: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45B0u;
    if (runtime->hasFunction(0x1F45B0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6798u; }
        if (ctx->pc != 0x1F6798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45B0_0x1f45b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6798u; }
        if (ctx->pc != 0x1F6798u) { return; }
    }
    ctx->pc = 0x1F6798u;
label_1f6798:
    // 0x1f6798: 0x2841ffff  slti        $at, $v0, -0x1
    ctx->pc = 0x1f6798u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x1f679c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F679Cu;
    {
        const bool branch_taken_0x1f679c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F67A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F679Cu;
            // 0x1f67a0: 0x24030011  addiu       $v1, $zero, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f679c) {
            ctx->pc = 0x1F67ACu;
            goto label_1f67ac;
        }
    }
    ctx->pc = 0x1F67A4u;
    // 0x1f67a4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F67A4u;
    {
        const bool branch_taken_0x1f67a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F67A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F67A4u;
            // 0x1f67a8: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f67a4) {
            ctx->pc = 0x1F67B8u;
            goto label_1f67b8;
        }
    }
    ctx->pc = 0x1F67ACu;
label_1f67ac:
    // 0x1f67ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f67acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f67b0: 0xa2430001  sb          $v1, 0x1($s2)
    ctx->pc = 0x1f67b0u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f67b4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1f67b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1f67b8:
    // 0x1f67b8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f67b8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f67bc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f67bcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f67c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f67c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f67c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F67C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F67C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F67C4u;
            // 0x1f67c8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F67CCu;
    // 0x1f67cc: 0x0  nop
    ctx->pc = 0x1f67ccu;
    // NOP
    // 0x1f67d0: 0x8c850024  lw          $a1, 0x24($a0)
    ctx->pc = 0x1f67d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f67d4: 0x24030012  addiu       $v1, $zero, 0x12
    ctx->pc = 0x1f67d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1f67d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1f67d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f67dc: 0xa0830001  sb          $v1, 0x1($a0)
    ctx->pc = 0x1f67dcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f67e0: 0x80a30006  lb          $v1, 0x6($a1)
    ctx->pc = 0x1f67e0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 6)));
    // 0x1f67e4: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F67E4u;
    {
        const bool branch_taken_0x1f67e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F67E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F67E4u;
            // 0x1f67e8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f67e4) {
            ctx->pc = 0x1F67F0u;
            goto label_1f67f0;
        }
    }
    ctx->pc = 0x1F67ECu;
    // 0x1f67ec: 0x2402ffc5  addiu       $v0, $zero, -0x3B
    ctx->pc = 0x1f67ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967237));
label_1f67f0:
    // 0x1f67f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F67F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F67F8u;
    // 0x1f67f8: 0x0  nop
    ctx->pc = 0x1f67f8u;
    // NOP
    // 0x1f67fc: 0x0  nop
    ctx->pc = 0x1f67fcu;
    // NOP
    // 0x1f6800: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f6800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f6804: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6804u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6808: 0xac820088  sw          $v0, 0x88($a0)
    ctx->pc = 0x1f6808u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 136), GPR_U32(ctx, 2));
    // 0x1f680c: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1f680cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6810: 0xac800090  sw          $zero, 0x90($a0)
    ctx->pc = 0x1f6810u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 144), GPR_U32(ctx, 0));
    // 0x1f6814: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f6814u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f6818: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1F6818u;
    {
        const bool branch_taken_0x1f6818 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F681Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6818u;
            // 0x1f681c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6818) {
            ctx->pc = 0x1F683Cu;
            goto label_1f683c;
        }
    }
    ctx->pc = 0x1F6820u;
    // 0x1f6820: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1f6820u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1f6824: 0x8c2257c0  lw          $v0, 0x57C0($at)
    ctx->pc = 0x1f6824u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 22464)));
    // 0x1f6828: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F6828u;
    {
        const bool branch_taken_0x1f6828 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F682Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6828u;
            // 0x1f682c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6828) {
            ctx->pc = 0x1F6838u;
            goto label_1f6838;
        }
    }
    ctx->pc = 0x1F6830u;
    // 0x1f6830: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f6830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f6834: 0xac22eaf0  sw          $v0, -0x1510($at)
    ctx->pc = 0x1f6834u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294961904), GPR_U32(ctx, 2));
label_1f6838:
    // 0x1f6838: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6838u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f683c:
    // 0x1f683c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F683Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6844u;
    // 0x1f6844: 0x0  nop
    ctx->pc = 0x1f6844u;
    // NOP
    // 0x1f6848: 0x0  nop
    ctx->pc = 0x1f6848u;
    // NOP
    // 0x1f684c: 0x0  nop
    ctx->pc = 0x1f684cu;
    // NOP
    // 0x1f6850: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f6850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f6854: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1f6854u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f6858: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f6858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f685c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f685cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6860: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f6860u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6864: 0x80840001  lb          $a0, 0x1($a0)
    ctx->pc = 0x1f6864u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1f6868: 0x10830065  beq         $a0, $v1, . + 4 + (0x65 << 2)
    ctx->pc = 0x1F6868u;
    {
        const bool branch_taken_0x1f6868 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1F686Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6868u;
            // 0x1f686c: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6868) {
            ctx->pc = 0x1F6A00u;
            goto label_1f6a00;
        }
    }
    ctx->pc = 0x1F6870u;
    // 0x1f6870: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1f6870u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f6874: 0x10820042  beq         $a0, $v0, . + 4 + (0x42 << 2)
    ctx->pc = 0x1F6874u;
    {
        const bool branch_taken_0x1f6874 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F6878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6874u;
            // 0x1f6878: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6874) {
            ctx->pc = 0x1F6980u;
            goto label_1f6980;
        }
    }
    ctx->pc = 0x1F687Cu;
    // 0x1f687c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f687cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f6880: 0x1082001f  beq         $a0, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1F6880u;
    {
        const bool branch_taken_0x1f6880 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1f6880) {
            ctx->pc = 0x1F6900u;
            goto label_1f6900;
        }
    }
    ctx->pc = 0x1F6888u;
    // 0x1f6888: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F6888u;
    {
        const bool branch_taken_0x1f6888 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6888) {
            ctx->pc = 0x1F6898u;
            goto label_1f6898;
        }
    }
    ctx->pc = 0x1F6890u;
    // 0x1f6890: 0x1000009b  b           . + 4 + (0x9B << 2)
    ctx->pc = 0x1F6890u;
    {
        const bool branch_taken_0x1f6890 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6890u;
            // 0x1f6894: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6890) {
            ctx->pc = 0x1F6B00u;
            goto label_1f6b00;
        }
    }
    ctx->pc = 0x1F6898u;
label_1f6898:
    // 0x1f6898: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1f6898u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1f689c: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f689cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f68a0: 0x2484c6f0  addiu       $a0, $a0, -0x3910
    ctx->pc = 0x1f68a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952688));
    // 0x1f68a4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F68A4u;
    SET_GPR_U32(ctx, 31, 0x1F68ACu);
    ctx->pc = 0x1F68A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F68A4u;
            // 0x1f68a8: 0x24a59b40  addiu       $a1, $a1, -0x64C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941504));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F68ACu; }
        if (ctx->pc != 0x1F68ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F68ACu; }
        if (ctx->pc != 0x1F68ACu) { return; }
    }
    ctx->pc = 0x1F68ACu;
label_1f68ac:
    // 0x1f68ac: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1f68acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1f68b0: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x1f68b0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x1f68b4: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1f68b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1f68b8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1f68b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1f68bc: 0x2484cc60  addiu       $a0, $a0, -0x33A0
    ctx->pc = 0x1f68bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294954080));
    // 0x1f68c0: 0xac22c7f8  sw          $v0, -0x3808($at)
    ctx->pc = 0x1f68c0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952952), GPR_U32(ctx, 2));
    // 0x1f68c4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1F68C4u;
    SET_GPR_U32(ctx, 31, 0x1F68CCu);
    ctx->pc = 0x1F68C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F68C4u;
            // 0x1f68c8: 0x24a59b80  addiu       $a1, $a1, -0x6480 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941568));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F68CCu; }
        if (ctx->pc != 0x1F68CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F68CCu; }
        if (ctx->pc != 0x1F68CCu) { return; }
    }
    ctx->pc = 0x1F68CCu;
label_1f68cc:
    // 0x1f68cc: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x1f68ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x1f68d0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f68d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f68d4: 0x24639af0  addiu       $v1, $v1, -0x6510
    ctx->pc = 0x1f68d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941424));
    // 0x1f68d8: 0x2402278f  addiu       $v0, $zero, 0x278F
    ctx->pc = 0x1f68d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10127));
    // 0x1f68dc: 0xac237420  sw          $v1, 0x7420($at)
    ctx->pc = 0x1f68dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 29728), GPR_U32(ctx, 3));
    // 0x1f68e0: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f68e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f68e4: 0xa4227428  sh          $v0, 0x7428($at)
    ctx->pc = 0x1f68e4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 29736), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f68e8: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f68e8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f68ec: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f68ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f68f0: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f68f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f68f4: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f68f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f68f8: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x1F68F8u;
    {
        const bool branch_taken_0x1f68f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F68FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F68F8u;
            // 0x1f68fc: 0xa6000004  sh          $zero, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f68f8) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6900u;
label_1f6900:
    // 0x1f6900: 0xae030090  sw          $v1, 0x90($s0)
    ctx->pc = 0x1f6900u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 3));
    // 0x1f6904: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f6904u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f6908: 0x8c277420  lw          $a3, 0x7420($at)
    ctx->pc = 0x1f6908u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 29728)));
    // 0x1f690c: 0x26040002  addiu       $a0, $s0, 0x2
    ctx->pc = 0x1f690cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1f6910: 0x26050004  addiu       $a1, $s0, 0x4
    ctx->pc = 0x1f6910u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1f6914: 0xc0724bc  jal         func_1C92F0
    ctx->pc = 0x1F6914u;
    SET_GPR_U32(ctx, 31, 0x1F691Cu);
    ctx->pc = 0x1F6918u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6914u;
            // 0x1f6918: 0x2606000c  addiu       $a2, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C92F0u;
    if (runtime->hasFunction(0x1C92F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C92F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F691Cu; }
        if (ctx->pc != 0x1F691Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C92F0_0x1c92f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F691Cu; }
        if (ctx->pc != 0x1F691Cu) { return; }
    }
    ctx->pc = 0x1F691Cu;
label_1f691c:
    // 0x1f691c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f691cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f6920: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1F6920u;
    {
        const bool branch_taken_0x1f6920 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1F6924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6920u;
            // 0x1f6924: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6920) {
            ctx->pc = 0x1F6954u;
            goto label_1f6954;
        }
    }
    ctx->pc = 0x1F6928u;
    // 0x1f6928: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1f6928u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f692c: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F692Cu;
    {
        const bool branch_taken_0x1f692c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f692c) {
            ctx->pc = 0x1F6944u;
            goto label_1f6944;
        }
    }
    ctx->pc = 0x1F6934u;
    // 0x1f6934: 0x10400071  beqz        $v0, . + 4 + (0x71 << 2)
    ctx->pc = 0x1F6934u;
    {
        const bool branch_taken_0x1f6934 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6934) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F693Cu;
    // 0x1f693c: 0x1000006f  b           . + 4 + (0x6F << 2)
    ctx->pc = 0x1F693Cu;
    {
        const bool branch_taken_0x1f693c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f693c) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6944u;
label_1f6944:
    // 0x1f6944: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f6944u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f6948: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f6948u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f694c: 0x1000006b  b           . + 4 + (0x6B << 2)
    ctx->pc = 0x1F694Cu;
    {
        const bool branch_taken_0x1f694c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F694Cu;
            // 0x1f6950: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f694c) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6954u;
label_1f6954:
    // 0x1f6954: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6954u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6958: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f6958u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f695c: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f695cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6960: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6960u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6964: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f6964u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6968: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6968u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f696c: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f696cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6970: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6970u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6974: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6974u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6978: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1F6978u;
    {
        const bool branch_taken_0x1f6978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F697Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6978u;
            // 0x1f697c: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6978) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6980u;
label_1f6980:
    // 0x1f6980: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1f6980u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1f6984: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f6984u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f6988: 0x94227428  lhu         $v0, 0x7428($at)
    ctx->pc = 0x1f6988u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 29736)));
    // 0x1f698c: 0x8e04000c  lw          $a0, 0xC($s0)
    ctx->pc = 0x1f698cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1f6990: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1f6990u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1f6994: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1f6994u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1f6998: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x1f6998u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x1f699c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1f699cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f69a0: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f69a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f69a4: 0xc07d174  jal         func_1F45D0
    ctx->pc = 0x1F69A4u;
    SET_GPR_U32(ctx, 31, 0x1F69ACu);
    ctx->pc = 0x1F69A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F69A4u;
            // 0x1f69a8: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45D0u;
    if (runtime->hasFunction(0x1F45D0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F69ACu; }
        if (ctx->pc != 0x1F69ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45D0_0x1f45d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F69ACu; }
        if (ctx->pc != 0x1F69ACu) { return; }
    }
    ctx->pc = 0x1F69ACu;
label_1f69ac:
    // 0x1f69ac: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F69ACu;
    {
        const bool branch_taken_0x1f69ac = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F69B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F69ACu;
            // 0x1f69b0: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f69ac) {
            ctx->pc = 0x1F69E4u;
            goto label_1f69e4;
        }
    }
    ctx->pc = 0x1F69B4u;
    // 0x1f69b4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1f69b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f69b8: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f69b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f69bc: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f69bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f69c0: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f69c0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f69c4: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f69c4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f69c8: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f69c8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f69cc: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f69ccu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f69d0: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f69d0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f69d4: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f69d4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f69d8: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f69d8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f69dc: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1F69DCu;
    {
        const bool branch_taken_0x1f69dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F69E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F69DCu;
            // 0x1f69e0: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f69dc) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F69E4u;
label_1f69e4:
    // 0x1f69e4: 0x82030001  lb          $v1, 0x1($s0)
    ctx->pc = 0x1f69e4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f69e8: 0x24020708  addiu       $v0, $zero, 0x708
    ctx->pc = 0x1f69e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1800));
    // 0x1f69ec: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1f69ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1f69f0: 0xa2030001  sb          $v1, 0x1($s0)
    ctx->pc = 0x1f69f0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f69f4: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f69f4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f69f8: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1F69F8u;
    {
        const bool branch_taken_0x1f69f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F69FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F69F8u;
            // 0x1f69fc: 0xa6020004  sh          $v0, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f69f8) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6A00u;
label_1f6a00:
    // 0x1f6a00: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f6a00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f6a04: 0x86020004  lh          $v0, 0x4($s0)
    ctx->pc = 0x1f6a04u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1f6a08: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f6a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f6a0c: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x1f6a0cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f6a10: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1f6a10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f6a14: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1f6a14u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1f6a18: 0x1c400013  bgtz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1F6A18u;
    {
        const bool branch_taken_0x1f6a18 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1f6a18) {
            ctx->pc = 0x1F6A68u;
            goto label_1f6a68;
        }
    }
    ctx->pc = 0x1F6A20u;
    // 0x1f6a20: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1f6a20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f6a24: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f6a24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f6a28: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6A28u;
    SET_GPR_U32(ctx, 31, 0x1F6A30u);
    ctx->pc = 0x1F6A2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A28u;
            // 0x1f6a2c: 0x8e040010  lw          $a0, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A30u; }
        if (ctx->pc != 0x1F6A30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A30u; }
        if (ctx->pc != 0x1F6A30u) { return; }
    }
    ctx->pc = 0x1F6A30u;
label_1f6a30:
    // 0x1f6a30: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6A30u;
    SET_GPR_U32(ctx, 31, 0x1F6A38u);
    ctx->pc = 0x1F6A34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A30u;
            // 0x1f6a34: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A38u; }
        if (ctx->pc != 0x1F6A38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A38u; }
        if (ctx->pc != 0x1F6A38u) { return; }
    }
    ctx->pc = 0x1F6A38u;
label_1f6a38:
    // 0x1f6a38: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1f6a38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f6a3c: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6a40: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f6a40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f6a44: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f6a44u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6a48: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6a48u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6a4c: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f6a4cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6a50: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6a50u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6a54: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f6a54u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6a58: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6a58u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6a5c: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6a5cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6a60: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1F6A60u;
    {
        const bool branch_taken_0x1f6a60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A60u;
            // 0x1f6a64: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6a60) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6A68u;
label_1f6a68:
    // 0x1f6a68: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1f6a68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1f6a6c: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1f6a6cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1f6a70: 0xc075a4c  jal         func_1D6930
    ctx->pc = 0x1F6A70u;
    SET_GPR_U32(ctx, 31, 0x1F6A78u);
    ctx->pc = 0x1F6A74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A70u;
            // 0x1f6a74: 0x24a5b6b4  addiu       $a1, $a1, -0x494C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294948532));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6930u;
    if (runtime->hasFunction(0x1D6930u)) {
        auto targetFn = runtime->lookupFunction(0x1D6930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A78u; }
        if (ctx->pc != 0x1F6A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6930_0x1d6930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A78u; }
        if (ctx->pc != 0x1F6A78u) { return; }
    }
    ctx->pc = 0x1F6A78u;
label_1f6a78:
    // 0x1f6a78: 0x4410013  bgez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1F6A78u;
    {
        const bool branch_taken_0x1f6a78 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F6A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A78u;
            // 0x1f6a7c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6a78) {
            ctx->pc = 0x1F6AC8u;
            goto label_1f6ac8;
        }
    }
    ctx->pc = 0x1F6A80u;
    // 0x1f6a80: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6a84: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f6a84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f6a88: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6A88u;
    SET_GPR_U32(ctx, 31, 0x1F6A90u);
    ctx->pc = 0x1F6A8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A88u;
            // 0x1f6a8c: 0x8e040010  lw          $a0, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A90u; }
        if (ctx->pc != 0x1F6A90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A90u; }
        if (ctx->pc != 0x1F6A90u) { return; }
    }
    ctx->pc = 0x1F6A90u;
label_1f6a90:
    // 0x1f6a90: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6A90u;
    SET_GPR_U32(ctx, 31, 0x1F6A98u);
    ctx->pc = 0x1F6A94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6A90u;
            // 0x1f6a94: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A98u; }
        if (ctx->pc != 0x1F6A98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6A98u; }
        if (ctx->pc != 0x1F6A98u) { return; }
    }
    ctx->pc = 0x1F6A98u;
label_1f6a98:
    // 0x1f6a98: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1f6a98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f6a9c: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6aa0: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f6aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f6aa4: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f6aa4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6aa8: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6aa8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6aac: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f6aacu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6ab0: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f6ab0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6ab4: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f6ab4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ab8: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f6ab8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6abc: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f6abcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ac0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1F6AC0u;
    {
        const bool branch_taken_0x1f6ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6AC0u;
            // 0x1f6ac4: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ac0) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6AC8u;
label_1f6ac8:
    // 0x1f6ac8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1f6ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f6acc: 0x8423b6b4  lh          $v1, -0x494C($at)
    ctx->pc = 0x1f6accu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948532)));
    // 0x1f6ad0: 0x1462000a  bne         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1F6AD0u;
    {
        const bool branch_taken_0x1f6ad0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1F6AD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6AD0u;
            // 0x1f6ad4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ad0) {
            ctx->pc = 0x1F6AFCu;
            goto label_1f6afc;
        }
    }
    ctx->pc = 0x1F6AD8u;
    // 0x1f6ad8: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6adc: 0xae030088  sw          $v1, 0x88($s0)
    ctx->pc = 0x1f6adcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 3));
    // 0x1f6ae0: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1f6ae0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1f6ae4: 0x10620002  beq         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F6AE4u;
    {
        const bool branch_taken_0x1f6ae4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F6AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6AE4u;
            // 0x1f6ae8: 0x24620001  addiu       $v0, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ae4) {
            ctx->pc = 0x1F6AF0u;
            goto label_1f6af0;
        }
    }
    ctx->pc = 0x1F6AECu;
    // 0x1f6aec: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f6aecu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
label_1f6af0:
    // 0x1f6af0: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6af0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6af4: 0x24020708  addiu       $v0, $zero, 0x708
    ctx->pc = 0x1f6af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1800));
    // 0x1f6af8: 0xa6020004  sh          $v0, 0x4($s0)
    ctx->pc = 0x1f6af8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 2));
label_1f6afc:
    // 0x1f6afc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f6afcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f6b00:
    // 0x1f6b00: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6b00u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6b04: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6b04u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6b08: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6B08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B08u;
            // 0x1f6b0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6B10u;
    // 0x1f6b10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f6b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f6b14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f6b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f6b18: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f6b18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f6b1c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f6b1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6b20: 0x84820004  lh          $v0, 0x4($a0)
    ctx->pc = 0x1f6b20u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1f6b24: 0x8c900024  lw          $s0, 0x24($a0)
    ctx->pc = 0x1f6b24u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f6b28: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f6b28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f6b2c: 0xa4820004  sh          $v0, 0x4($a0)
    ctx->pc = 0x1f6b2cu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f6b30: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1f6b30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f6b34: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1f6b34u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1f6b38: 0x1c400014  bgtz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6B38u;
    {
        const bool branch_taken_0x1f6b38 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1F6B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B38u;
            // 0x1f6b3c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6b38) {
            ctx->pc = 0x1F6B8Cu;
            goto label_1f6b8c;
        }
    }
    ctx->pc = 0x1F6B40u;
    // 0x1f6b40: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1f6b40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1f6b44: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x1f6b44u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x1f6b48: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6B48u;
    SET_GPR_U32(ctx, 31, 0x1F6B50u);
    ctx->pc = 0x1F6B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B48u;
            // 0x1f6b4c: 0x8e240010  lw          $a0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B50u; }
        if (ctx->pc != 0x1F6B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B50u; }
        if (ctx->pc != 0x1F6B50u) { return; }
    }
    ctx->pc = 0x1F6B50u;
label_1f6b50:
    // 0x1f6b50: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6B50u;
    SET_GPR_U32(ctx, 31, 0x1F6B58u);
    ctx->pc = 0x1F6B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B50u;
            // 0x1f6b54: 0x26240010  addiu       $a0, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B58u; }
        if (ctx->pc != 0x1F6B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B58u; }
        if (ctx->pc != 0x1F6B58u) { return; }
    }
    ctx->pc = 0x1F6B58u;
label_1f6b58:
    // 0x1f6b58: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1f6b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1f6b5c: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f6b5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6b60: 0xae22008c  sw          $v0, 0x8C($s1)
    ctx->pc = 0x1f6b60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
    // 0x1f6b64: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1f6b64u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6b68: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6b68u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6b6c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6b6cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6b70: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6b70u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6b74: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6b74u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6b78: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6b78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6b7c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6b7cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6b80: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6b80u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6b84: 0x100000ed  b           . + 4 + (0xED << 2)
    ctx->pc = 0x1F6B84u;
    {
        const bool branch_taken_0x1f6b84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B84u;
            // 0x1f6b88: 0xa620000a  sh          $zero, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6b84) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6B8Cu;
label_1f6b8c:
    // 0x1f6b8c: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x1f6b8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1f6b90: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1f6b90u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1f6b94: 0xc075a4c  jal         func_1D6930
    ctx->pc = 0x1F6B94u;
    SET_GPR_U32(ctx, 31, 0x1F6B9Cu);
    ctx->pc = 0x1F6B98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B94u;
            // 0x1f6b98: 0x24a5b6b4  addiu       $a1, $a1, -0x494C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294948532));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6930u;
    if (runtime->hasFunction(0x1D6930u)) {
        auto targetFn = runtime->lookupFunction(0x1D6930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B9Cu; }
        if (ctx->pc != 0x1F6B9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6930_0x1d6930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B9Cu; }
        if (ctx->pc != 0x1F6B9Cu) { return; }
    }
    ctx->pc = 0x1F6B9Cu;
label_1f6b9c:
    // 0x1f6b9c: 0x4410014  bgez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6B9Cu;
    {
        const bool branch_taken_0x1f6b9c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1f6b9c) {
            ctx->pc = 0x1F6BF0u;
            goto label_1f6bf0;
        }
    }
    ctx->pc = 0x1F6BA4u;
    // 0x1f6ba4: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1f6ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1f6ba8: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x1f6ba8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x1f6bac: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6BACu;
    SET_GPR_U32(ctx, 31, 0x1F6BB4u);
    ctx->pc = 0x1F6BB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6BACu;
            // 0x1f6bb0: 0x8e240010  lw          $a0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6BB4u; }
        if (ctx->pc != 0x1F6BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6BB4u; }
        if (ctx->pc != 0x1F6BB4u) { return; }
    }
    ctx->pc = 0x1F6BB4u;
label_1f6bb4:
    // 0x1f6bb4: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6BB4u;
    SET_GPR_U32(ctx, 31, 0x1F6BBCu);
    ctx->pc = 0x1F6BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6BB4u;
            // 0x1f6bb8: 0x26240010  addiu       $a0, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6BBCu; }
        if (ctx->pc != 0x1F6BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6BBCu; }
        if (ctx->pc != 0x1F6BBCu) { return; }
    }
    ctx->pc = 0x1F6BBCu;
label_1f6bbc:
    // 0x1f6bbc: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1f6bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f6bc0: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f6bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6bc4: 0xae22008c  sw          $v0, 0x8C($s1)
    ctx->pc = 0x1f6bc4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
    // 0x1f6bc8: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1f6bc8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6bcc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6bccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6bd0: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6bd0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6bd4: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6bd4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6bd8: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6bd8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6bdc: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6bdcu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6be0: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6be0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6be4: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6be4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6be8: 0x100000d4  b           . + 4 + (0xD4 << 2)
    ctx->pc = 0x1F6BE8u;
    {
        const bool branch_taken_0x1f6be8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6BE8u;
            // 0x1f6bec: 0xa620000a  sh          $zero, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6be8) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6BF0u;
label_1f6bf0:
    // 0x1f6bf0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1f6bf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1f6bf4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1f6bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f6bf8: 0x8423b6b4  lh          $v1, -0x494C($at)
    ctx->pc = 0x1f6bf8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948532)));
    // 0x1f6bfc: 0x10620014  beq         $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6BFCu;
    {
        const bool branch_taken_0x1f6bfc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F6C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6BFCu;
            // 0x1f6c00: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6bfc) {
            ctx->pc = 0x1F6C50u;
            goto label_1f6c50;
        }
    }
    ctx->pc = 0x1F6C04u;
    // 0x1f6c04: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x1f6c04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1f6c08: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x1f6c08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x1f6c0c: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6C0Cu;
    SET_GPR_U32(ctx, 31, 0x1F6C14u);
    ctx->pc = 0x1F6C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6C0Cu;
            // 0x1f6c10: 0x8e240010  lw          $a0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C14u; }
        if (ctx->pc != 0x1F6C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C14u; }
        if (ctx->pc != 0x1F6C14u) { return; }
    }
    ctx->pc = 0x1F6C14u;
label_1f6c14:
    // 0x1f6c14: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6C14u;
    SET_GPR_U32(ctx, 31, 0x1F6C1Cu);
    ctx->pc = 0x1F6C18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6C14u;
            // 0x1f6c18: 0x26240010  addiu       $a0, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C1Cu; }
        if (ctx->pc != 0x1F6C1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C1Cu; }
        if (ctx->pc != 0x1F6C1Cu) { return; }
    }
    ctx->pc = 0x1F6C1Cu;
label_1f6c1c:
    // 0x1f6c1c: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f6c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6c20: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6c20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6c24: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f6c24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f6c28: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1f6c28u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6c2c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6c2cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c30: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6c30u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c34: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6c34u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c38: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6c38u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6c3c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6c3cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6c40: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6c40u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6c44: 0x100000bd  b           . + 4 + (0xBD << 2)
    ctx->pc = 0x1F6C44u;
    {
        const bool branch_taken_0x1f6c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6C44u;
            // 0x1f6c48: 0xa620000a  sh          $zero, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6c44) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6C4Cu;
    // 0x1f6c4c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6c4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1f6c50:
    // 0x1f6c50: 0xc07d180  jal         func_1F4600
    ctx->pc = 0x1F6C50u;
    SET_GPR_U32(ctx, 31, 0x1F6C58u);
    ctx->pc = 0x1F4600u;
    if (runtime->hasFunction(0x1F4600u)) {
        auto targetFn = runtime->lookupFunction(0x1F4600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C58u; }
        if (ctx->pc != 0x1F6C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4600_0x1f4600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C58u; }
        if (ctx->pc != 0x1F6C58u) { return; }
    }
    ctx->pc = 0x1F6C58u;
label_1f6c58:
    // 0x1f6c58: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6C58u;
    {
        const bool branch_taken_0x1f6c58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6c58) {
            ctx->pc = 0x1F6CACu;
            goto label_1f6cac;
        }
    }
    ctx->pc = 0x1F6C60u;
    // 0x1f6c60: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f6c60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f6c64: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F6C64u;
    {
        const bool branch_taken_0x1f6c64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f6c64) {
            ctx->pc = 0x1F6C78u;
            goto label_1f6c78;
        }
    }
    ctx->pc = 0x1F6C6Cu;
    // 0x1f6c6c: 0x24020708  addiu       $v0, $zero, 0x708
    ctx->pc = 0x1f6c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1800));
    // 0x1f6c70: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F6C70u;
    {
        const bool branch_taken_0x1f6c70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6C70u;
            // 0x1f6c74: 0xa6220004  sh          $v0, 0x4($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6c70) {
            ctx->pc = 0x1F6CB4u;
            goto label_1f6cb4;
        }
    }
    ctx->pc = 0x1F6C78u;
label_1f6c78:
    // 0x1f6c78: 0x2402000c  addiu       $v0, $zero, 0xC
    ctx->pc = 0x1f6c78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1f6c7c: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1f6c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1f6c80: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x1f6c80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x1f6c84: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6c84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6c88: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f6c88u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f6c8c: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f6c8cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6c90: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6c90u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c94: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6c94u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c98: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6c98u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c9c: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6c9cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ca0: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6ca0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ca4: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6ca4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ca8: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f6ca8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f6cac:
    // 0x1f6cac: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x1F6CACu;
    {
        const bool branch_taken_0x1f6cac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6CACu;
            // 0x1f6cb0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6cac) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6CB4u;
label_1f6cb4:
    // 0x1f6cb4: 0xc07d170  jal         func_1F45C0
    ctx->pc = 0x1F6CB4u;
    SET_GPR_U32(ctx, 31, 0x1F6CBCu);
    ctx->pc = 0x1F6CB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6CB4u;
            // 0x1f6cb8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45C0u;
    if (runtime->hasFunction(0x1F45C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6CBCu; }
        if (ctx->pc != 0x1F6CBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45C0_0x1f45c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6CBCu; }
        if (ctx->pc != 0x1F6CBCu) { return; }
    }
    ctx->pc = 0x1F6CBCu;
label_1f6cbc:
    // 0x1f6cbc: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1f6cbcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1f6cc0: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1f6cc0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1f6cc4: 0x3c070023  lui         $a3, 0x23
    ctx->pc = 0x1f6cc4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
    // 0x1f6cc8: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x1f6cc8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x1f6ccc: 0x3c0a0023  lui         $t2, 0x23
    ctx->pc = 0x1f6cccu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)35 << 16));
    // 0x1f6cd0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6cd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6cd4: 0x248473b0  addiu       $a0, $a0, 0x73B0
    ctx->pc = 0x1f6cd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 29616));
    // 0x1f6cd8: 0x24c67350  addiu       $a2, $a2, 0x7350
    ctx->pc = 0x1f6cd8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 29520));
    // 0x1f6cdc: 0x24e77330  addiu       $a3, $a3, 0x7330
    ctx->pc = 0x1f6cdcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 29488));
    // 0x1f6ce0: 0x25087390  addiu       $t0, $t0, 0x7390
    ctx->pc = 0x1f6ce0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 29584));
    // 0x1f6ce4: 0x254a7370  addiu       $t2, $t2, 0x7370
    ctx->pc = 0x1f6ce4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 29552));
    // 0x1f6ce8: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1F6CE8u;
    {
        const bool branch_taken_0x1f6ce8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6CECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6CE8u;
            // 0x1f6cec: 0x24090008  addiu       $t1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ce8) {
            ctx->pc = 0x1F6DC4u;
            goto label_1f6dc4;
        }
    }
    ctx->pc = 0x1F6CF0u;
    // 0x1f6cf0: 0x1421821  addu        $v1, $t2, $v0
    ctx->pc = 0x1f6cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
label_1f6cf4:
    // 0x1f6cf4: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1f6cf4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1f6cf8: 0x10690031  beq         $v1, $t1, . + 4 + (0x31 << 2)
    ctx->pc = 0x1F6CF8u;
    {
        const bool branch_taken_0x1f6cf8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 9));
        if (branch_taken_0x1f6cf8) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D00u;
    // 0x1f6d00: 0x1022821  addu        $a1, $t0, $v0
    ctx->pc = 0x1f6d00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x1f6d04: 0x92030002  lbu         $v1, 0x2($s0)
    ctx->pc = 0x1f6d04u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1f6d08: 0x90a50000  lbu         $a1, 0x0($a1)
    ctx->pc = 0x1f6d08u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1f6d0c: 0x14a3002c  bne         $a1, $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x1F6D0Cu;
    {
        const bool branch_taken_0x1f6d0c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f6d0c) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D14u;
    // 0x1f6d14: 0xe22821  addu        $a1, $a3, $v0
    ctx->pc = 0x1f6d14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1f6d18: 0x92030003  lbu         $v1, 0x3($s0)
    ctx->pc = 0x1f6d18u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1f6d1c: 0x90a50000  lbu         $a1, 0x0($a1)
    ctx->pc = 0x1f6d1cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1f6d20: 0x14a30027  bne         $a1, $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1F6D20u;
    {
        const bool branch_taken_0x1f6d20 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f6d20) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D28u;
    // 0x1f6d28: 0xc22821  addu        $a1, $a2, $v0
    ctx->pc = 0x1f6d28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1f6d2c: 0x92030004  lbu         $v1, 0x4($s0)
    ctx->pc = 0x1f6d2cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1f6d30: 0x90a50000  lbu         $a1, 0x0($a1)
    ctx->pc = 0x1f6d30u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1f6d34: 0x14a30022  bne         $a1, $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x1F6D34u;
    {
        const bool branch_taken_0x1f6d34 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f6d34) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D3Cu;
    // 0x1f6d3c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1f6d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1f6d40: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1f6d40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1f6d44: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1f6d44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1f6d48: 0x1060001d  beqz        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x1F6D48u;
    {
        const bool branch_taken_0x1f6d48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6d48) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D50u;
    // 0x1f6d50: 0x60f809  jalr        $v1
    ctx->pc = 0x1F6D50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1F6D58u);
        ctx->pc = 0x1F6D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6D50u;
            // 0x1f6d54: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1F6D58u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1F6D58u; }
            if (ctx->pc != 0x1F6D58u) { return; }
        }
        }
    }
    ctx->pc = 0x1F6D58u;
label_1f6d58:
    // 0x1f6d58: 0x441000e  bgez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1F6D58u;
    {
        const bool branch_taken_0x1f6d58 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F6D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6D58u;
            // 0x1f6d5c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6d58) {
            ctx->pc = 0x1F6D94u;
            goto label_1f6d94;
        }
    }
    ctx->pc = 0x1F6D60u;
    // 0x1f6d60: 0xae22008c  sw          $v0, 0x8C($s1)
    ctx->pc = 0x1f6d60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
    // 0x1f6d64: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6d68: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f6d68u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6d6c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6d6cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6d70: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6d70u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6d74: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6d74u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6d78: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6d78u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6d7c: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6d7cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6d80: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6d80u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6d84: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6d84u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6d88: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1F6D88u;
    {
        const bool branch_taken_0x1f6d88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6D88u;
            // 0x1f6d8c: 0xa620000a  sh          $zero, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6d88) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6D90u;
    // 0x1f6d90: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1f6d90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1f6d94:
    // 0x1f6d94: 0x1443000e  bne         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1F6D94u;
    {
        const bool branch_taken_0x1f6d94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f6d94) {
            ctx->pc = 0x1F6DD0u;
            goto label_1f6dd0;
        }
    }
    ctx->pc = 0x1F6D9Cu;
    // 0x1f6d9c: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1f6d9cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1f6da0: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6da0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6da4: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F6DA4u;
    {
        const bool branch_taken_0x1f6da4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F6DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6DA4u;
            // 0x1f6da8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6da4) {
            ctx->pc = 0x1F6DB8u;
            goto label_1f6db8;
        }
    }
    ctx->pc = 0x1F6DACu;
    // 0x1f6dac: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1f6dacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1f6db0: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f6db0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6db4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6db4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f6db8:
    // 0x1f6db8: 0x10000061  b           . + 4 + (0x61 << 2)
    ctx->pc = 0x1F6DB8u;
    {
        const bool branch_taken_0x1f6db8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6DB8u;
            // 0x1f6dbc: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6db8) {
            ctx->pc = 0x1F6F40u;
            goto label_1f6f40;
        }
    }
    ctx->pc = 0x1F6DC0u;
label_1f6dc0:
    // 0x1f6dc0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f6dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1f6dc4:
    // 0x1f6dc4: 0x2843001c  slti        $v1, $v0, 0x1C
    ctx->pc = 0x1f6dc4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x1f6dc8: 0x1460ffca  bnez        $v1, . + 4 + (-0x36 << 2)
    ctx->pc = 0x1F6DC8u;
    {
        const bool branch_taken_0x1f6dc8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F6DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6DC8u;
            // 0x1f6dcc: 0x1421821  addu        $v1, $t2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6dc8) {
            ctx->pc = 0x1F6CF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f6cf4;
        }
    }
    ctx->pc = 0x1F6DD0u;
label_1f6dd0:
    // 0x1f6dd0: 0x82230001  lb          $v1, 0x1($s1)
    ctx->pc = 0x1f6dd0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1f6dd4: 0x2c610015  sltiu       $at, $v1, 0x15
    ctx->pc = 0x1f6dd4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)21) ? 1 : 0);
    // 0x1f6dd8: 0x1020004b  beqz        $at, . + 4 + (0x4B << 2)
    ctx->pc = 0x1F6DD8u;
    {
        const bool branch_taken_0x1f6dd8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6DD8u;
            // 0x1f6ddc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6dd8) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6DE0u;
    // 0x1f6de0: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1f6de0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1f6de4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1f6de4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1f6de8: 0x24849ba0  addiu       $a0, $a0, -0x6460
    ctx->pc = 0x1f6de8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941600));
    // 0x1f6dec: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1f6decu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1f6df0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1f6df0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1f6df4: 0x600008  jr          $v1
    ctx->pc = 0x1F6DF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F08u: goto label_1f6f08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6DFCu;
label_1f6dfc:
    // 0x1f6dfc: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1f6dfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1f6e00: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1F6E00u;
    {
        const bool branch_taken_0x1f6e00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E00u;
            // 0x1f6e04: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e00) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E08u;
label_1f6e08:
    // 0x1f6e08: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x1f6e08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1f6e0c: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1F6E0Cu;
    {
        const bool branch_taken_0x1f6e0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E0Cu;
            // 0x1f6e10: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e0c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E14u;
label_1f6e14:
    // 0x1f6e14: 0xc07d47c  jal         func_1F51F0
    ctx->pc = 0x1F6E14u;
    SET_GPR_U32(ctx, 31, 0x1F6E1Cu);
    ctx->pc = 0x1F6E18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E14u;
            // 0x1f6e18: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F51F0u;
    if (runtime->hasFunction(0x1F51F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F51F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E1Cu; }
        if (ctx->pc != 0x1F6E1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F51F0_0x1f51f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E1Cu; }
        if (ctx->pc != 0x1F6E1Cu) { return; }
    }
    ctx->pc = 0x1F6E1Cu;
label_1f6e1c:
    // 0x1f6e1c: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x1f6e1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1f6e20: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1F6E20u;
    {
        const bool branch_taken_0x1f6e20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E20u;
            // 0x1f6e24: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e20) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E28u;
label_1f6e28:
    // 0x1f6e28: 0x2403001e  addiu       $v1, $zero, 0x1E
    ctx->pc = 0x1f6e28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1f6e2c: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1F6E2Cu;
    {
        const bool branch_taken_0x1f6e2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E2Cu;
            // 0x1f6e30: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e2c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E34u;
label_1f6e34:
    // 0x1f6e34: 0xc07d514  jal         func_1F5450
    ctx->pc = 0x1F6E34u;
    SET_GPR_U32(ctx, 31, 0x1F6E3Cu);
    ctx->pc = 0x1F6E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E34u;
            // 0x1f6e38: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5450u;
    if (runtime->hasFunction(0x1F5450u)) {
        auto targetFn = runtime->lookupFunction(0x1F5450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E3Cu; }
        if (ctx->pc != 0x1F6E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5450_0x1f5450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E3Cu; }
        if (ctx->pc != 0x1F6E3Cu) { return; }
    }
    ctx->pc = 0x1F6E3Cu;
label_1f6e3c:
    // 0x1f6e3c: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1F6E3Cu;
    {
        const bool branch_taken_0x1f6e3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6e3c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E44u;
label_1f6e44:
    // 0x1f6e44: 0xc07d580  jal         func_1F5600
    ctx->pc = 0x1F6E44u;
    SET_GPR_U32(ctx, 31, 0x1F6E4Cu);
    ctx->pc = 0x1F6E48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E44u;
            // 0x1f6e48: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5600u;
    if (runtime->hasFunction(0x1F5600u)) {
        auto targetFn = runtime->lookupFunction(0x1F5600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E4Cu; }
        if (ctx->pc != 0x1F6E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5600_0x1f5600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E4Cu; }
        if (ctx->pc != 0x1F6E4Cu) { return; }
    }
    ctx->pc = 0x1F6E4Cu;
label_1f6e4c:
    // 0x1f6e4c: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1F6E4Cu;
    {
        const bool branch_taken_0x1f6e4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6e4c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E54u;
label_1f6e54:
    // 0x1f6e54: 0xc07d640  jal         func_1F5900
    ctx->pc = 0x1F6E54u;
    SET_GPR_U32(ctx, 31, 0x1F6E5Cu);
    ctx->pc = 0x1F6E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E54u;
            // 0x1f6e58: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5900u;
    if (runtime->hasFunction(0x1F5900u)) {
        auto targetFn = runtime->lookupFunction(0x1F5900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E5Cu; }
        if (ctx->pc != 0x1F6E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5900_0x1f5900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E5Cu; }
        if (ctx->pc != 0x1F6E5Cu) { return; }
    }
    ctx->pc = 0x1F6E5Cu;
label_1f6e5c:
    // 0x1f6e5c: 0x24030037  addiu       $v1, $zero, 0x37
    ctx->pc = 0x1f6e5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
    // 0x1f6e60: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1F6E60u;
    {
        const bool branch_taken_0x1f6e60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E60u;
            // 0x1f6e64: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e60) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E68u;
label_1f6e68:
    // 0x1f6e68: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1f6e68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1f6e6c: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1F6E6Cu;
    {
        const bool branch_taken_0x1f6e6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E6Cu;
            // 0x1f6e70: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e6c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E74u;
label_1f6e74:
    // 0x1f6e74: 0x24020046  addiu       $v0, $zero, 0x46
    ctx->pc = 0x1f6e74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1f6e78: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6e78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6e7c: 0xc07d6d4  jal         func_1F5B50
    ctx->pc = 0x1F6E7Cu;
    SET_GPR_U32(ctx, 31, 0x1F6E84u);
    ctx->pc = 0x1F6E80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E7Cu;
            // 0x1f6e80: 0xae220090  sw          $v0, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5B50u;
    if (runtime->hasFunction(0x1F5B50u)) {
        auto targetFn = runtime->lookupFunction(0x1F5B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E84u; }
        if (ctx->pc != 0x1F6E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5B50_0x1f5b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E84u; }
        if (ctx->pc != 0x1F6E84u) { return; }
    }
    ctx->pc = 0x1F6E84u;
label_1f6e84:
    // 0x1f6e84: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1F6E84u;
    {
        const bool branch_taken_0x1f6e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6e84) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E8Cu;
label_1f6e8c:
    // 0x1f6e8c: 0x24030050  addiu       $v1, $zero, 0x50
    ctx->pc = 0x1f6e8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1f6e90: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1F6E90u;
    {
        const bool branch_taken_0x1f6e90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E90u;
            // 0x1f6e94: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e90) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E98u;
label_1f6e98:
    // 0x1f6e98: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x1f6e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1f6e9c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6e9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6ea0: 0xc07d7dc  jal         func_1F5F70
    ctx->pc = 0x1F6EA0u;
    SET_GPR_U32(ctx, 31, 0x1F6EA8u);
    ctx->pc = 0x1F6EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EA0u;
            // 0x1f6ea4: 0xae220090  sw          $v0, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5F70u;
    if (runtime->hasFunction(0x1F5F70u)) {
        auto targetFn = runtime->lookupFunction(0x1F5F70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6EA8u; }
        if (ctx->pc != 0x1F6EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5F70_0x1f5f70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6EA8u; }
        if (ctx->pc != 0x1F6EA8u) { return; }
    }
    ctx->pc = 0x1F6EA8u;
label_1f6ea8:
    // 0x1f6ea8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1F6EA8u;
    {
        const bool branch_taken_0x1f6ea8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6ea8) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6EB0u;
label_1f6eb0:
    // 0x1f6eb0: 0x24030028  addiu       $v1, $zero, 0x28
    ctx->pc = 0x1f6eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1f6eb4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6EB4u;
    {
        const bool branch_taken_0x1f6eb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EB4u;
            // 0x1f6eb8: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6eb4) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6EBCu;
label_1f6ebc:
    // 0x1f6ebc: 0x2402002c  addiu       $v0, $zero, 0x2C
    ctx->pc = 0x1f6ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1f6ec0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6ec0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6ec4: 0xc07d8d4  jal         func_1F6350
    ctx->pc = 0x1F6EC4u;
    SET_GPR_U32(ctx, 31, 0x1F6ECCu);
    ctx->pc = 0x1F6EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EC4u;
            // 0x1f6ec8: 0xae220090  sw          $v0, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F6350u;
    if (runtime->hasFunction(0x1F6350u)) {
        auto targetFn = runtime->lookupFunction(0x1F6350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6ECCu; }
        if (ctx->pc != 0x1F6ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F6350_0x1f6350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6ECCu; }
        if (ctx->pc != 0x1F6ECCu) { return; }
    }
    ctx->pc = 0x1F6ECCu;
label_1f6ecc:
    // 0x1f6ecc: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1F6ECCu;
    {
        const bool branch_taken_0x1f6ecc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6ecc) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6ED4u;
label_1f6ed4:
    // 0x1f6ed4: 0x24030032  addiu       $v1, $zero, 0x32
    ctx->pc = 0x1f6ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x1f6ed8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1F6ED8u;
    {
        const bool branch_taken_0x1f6ed8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6ED8u;
            // 0x1f6edc: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ed8) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6EE0u;
label_1f6ee0:
    // 0x1f6ee0: 0xc07d974  jal         func_1F65D0
    ctx->pc = 0x1F6EE0u;
    SET_GPR_U32(ctx, 31, 0x1F6EE8u);
    ctx->pc = 0x1F6EE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EE0u;
            // 0x1f6ee4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F65D0u;
    goto label_1f65d0;
    ctx->pc = 0x1F6EE8u;
label_1f6ee8:
    // 0x1f6ee8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1F6EE8u;
    {
        const bool branch_taken_0x1f6ee8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6ee8) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6EF0u;
label_1f6ef0:
    // 0x1f6ef0: 0x2402005a  addiu       $v0, $zero, 0x5A
    ctx->pc = 0x1f6ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x1f6ef4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6ef4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6ef8: 0xc07d3ec  jal         func_1F4FB0
    ctx->pc = 0x1F6EF8u;
    SET_GPR_U32(ctx, 31, 0x1F6F00u);
    ctx->pc = 0x1F6EFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EF8u;
            // 0x1f6efc: 0xae220090  sw          $v0, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4FB0u;
    if (runtime->hasFunction(0x1F4FB0u)) {
        auto targetFn = runtime->lookupFunction(0x1F4FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F00u; }
        if (ctx->pc != 0x1F6F00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4FB0_0x1f4fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F00u; }
        if (ctx->pc != 0x1F6F00u) { return; }
    }
    ctx->pc = 0x1F6F00u;
label_1f6f00:
    // 0x1f6f00: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x1f6f00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1f6f04: 0xa2230001  sb          $v1, 0x1($s1)
    ctx->pc = 0x1f6f04u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 3));
label_1f6f08:
    // 0x1f6f08: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F6F08u;
    {
        const bool branch_taken_0x1f6f08 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1f6f08) {
            ctx->pc = 0x1F6F38u;
            goto label_1f6f38;
        }
    }
    ctx->pc = 0x1F6F10u;
    // 0x1f6f10: 0xae22008c  sw          $v0, 0x8C($s1)
    ctx->pc = 0x1f6f10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
    // 0x1f6f14: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6f18: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f6f18u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6f1c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6f1cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6f20: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6f20u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6f24: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6f24u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6f28: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6f28u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6f2c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6f2cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6f30: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6f30u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6f34: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f6f34u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f6f38:
    // 0x1f6f38: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6f38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f6f3c:
    // 0x1f6f3c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f6f3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1f6f40:
    // 0x1f6f40: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f6f40u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f6f44: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6f44u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6f48: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6F48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6F48u;
            // 0x1f6f4c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6F50u;
    // 0x1f6f50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f6f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f6f54: 0x24020061  addiu       $v0, $zero, 0x61
    ctx->pc = 0x1f6f54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 97));
    // 0x1f6f58: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f6f58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f6f5c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f6f5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6f60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f6f60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6f64: 0xac820090  sw          $v0, 0x90($a0)
    ctx->pc = 0x1f6f64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 144), GPR_U32(ctx, 2));
    // 0x1f6f68: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6F68u;
    SET_GPR_U32(ctx, 31, 0x1F6F70u);
    ctx->pc = 0x1F6F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6F68u;
            // 0x1f6f6c: 0x8c840010  lw          $a0, 0x10($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F70u; }
        if (ctx->pc != 0x1F6F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F70u; }
        if (ctx->pc != 0x1F6F70u) { return; }
    }
    ctx->pc = 0x1F6F70u;
label_1f6f70:
    // 0x1f6f70: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6F70u;
    SET_GPR_U32(ctx, 31, 0x1F6F78u);
    ctx->pc = 0x1F6F74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6F70u;
            // 0x1f6f74: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F78u; }
        if (ctx->pc != 0x1F6F78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F78u; }
        if (ctx->pc != 0x1F6F78u) { return; }
    }
    ctx->pc = 0x1F6F78u;
label_1f6f78:
    // 0x1f6f78: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1f6f78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f6f7c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6f7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6f80: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1f6f80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6f84: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f6f84u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6f88: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f6f88u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6f8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f6f8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f6f90: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6f90u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6f94: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6F94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6F94u;
            // 0x1f6f98: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6F9Cu;
    // 0x1f6f9c: 0x0  nop
    ctx->pc = 0x1f6f9cu;
    // NOP
    // 0x1f6fa0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6FA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6FA0u;
            // 0x1f6fa4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6FA8u;
    // 0x1f6fa8: 0x0  nop
    ctx->pc = 0x1f6fa8u;
    // NOP
    // 0x1f6fac: 0x0  nop
    ctx->pc = 0x1f6facu;
    // NOP
    // 0x1f6fb0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6FB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6FB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6FB0u;
            // 0x1f6fb4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6FB8u;
    // 0x1f6fb8: 0x0  nop
    ctx->pc = 0x1f6fb8u;
    // NOP
    // 0x1f6fbc: 0x0  nop
    ctx->pc = 0x1f6fbcu;
    // NOP
    // 0x1f6fc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f6fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f6fc4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f6fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f6fc8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f6fc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6fcc: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x1f6fccu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1f6fd0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f6fd0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6fd4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1f6fd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f6fd8: 0x10440040  beq         $v0, $a0, . + 4 + (0x40 << 2)
    ctx->pc = 0x1F6FD8u;
    {
        const bool branch_taken_0x1f6fd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x1F6FDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6FD8u;
            // 0x1f6fdc: 0x24030064  addiu       $v1, $zero, 0x64 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6fd8) {
            ctx->pc = 0x1F70DCu;
            goto label_1f70dc;
        }
    }
    ctx->pc = 0x1F6FE0u;
    // 0x1f6fe0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1f6fe0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f6fe4: 0x1043001b  beq         $v0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1F6FE4u;
    {
        const bool branch_taken_0x1f6fe4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f6fe4) {
            ctx->pc = 0x1F7054u;
            goto label_1f7054;
        }
    }
    ctx->pc = 0x1F6FECu;
    // 0x1f6fec: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F6FECu;
    {
        const bool branch_taken_0x1f6fec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6fec) {
            ctx->pc = 0x1F6FFCu;
            goto label_1f6ffc;
        }
    }
    ctx->pc = 0x1F6FF4u;
    // 0x1f6ff4: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1F6FF4u;
    {
        const bool branch_taken_0x1f6ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6FF4u;
            // 0x1f6ff8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ff4) {
            ctx->pc = 0x1F70F0u;
            goto label_1f70f0;
        }
    }
    ctx->pc = 0x1F6FFCu;
label_1f6ffc:
    // 0x1f6ffc: 0x24020062  addiu       $v0, $zero, 0x62
    ctx->pc = 0x1f6ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1f7000: 0x3c010036  lui         $at, 0x36
    ctx->pc = 0x1f7000u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)54 << 16));
    // 0x1f7004: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f7004u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f7008: 0x8c22eaf0  lw          $v0, -0x1510($at)
    ctx->pc = 0x1f7008u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294961904)));
    // 0x1f700c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F700Cu;
    {
        const bool branch_taken_0x1f700c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f700c) {
            ctx->pc = 0x1F703Cu;
            goto label_1f703c;
        }
    }
    ctx->pc = 0x1F7014u;
    // 0x1f7014: 0x10440005  beq         $v0, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F7014u;
    {
        const bool branch_taken_0x1f7014 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x1f7014) {
            ctx->pc = 0x1F702Cu;
            goto label_1f702c;
        }
    }
    ctx->pc = 0x1F701Cu;
    // 0x1f701c: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F701Cu;
    {
        const bool branch_taken_0x1f701c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f701c) {
            ctx->pc = 0x1F702Cu;
            goto label_1f702c;
        }
    }
    ctx->pc = 0x1F7024u;
    // 0x1f7024: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F7024u;
    {
        const bool branch_taken_0x1f7024 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7024u;
            // 0x1f7028: 0xa2000002  sb          $zero, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7024) {
            ctx->pc = 0x1F704Cu;
            goto label_1f704c;
        }
    }
    ctx->pc = 0x1F702Cu;
label_1f702c:
    // 0x1f702c: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f702cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f7030: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f7030u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f7034: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F7034u;
    {
        const bool branch_taken_0x1f7034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7034u;
            // 0x1f7038: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7034) {
            ctx->pc = 0x1F7048u;
            goto label_1f7048;
        }
    }
    ctx->pc = 0x1F703Cu;
label_1f703c:
    // 0x1f703c: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f703cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f7040: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x1f7040u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x1f7044: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x1f7044u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_1f7048:
    // 0x1f7048: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f7048u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
label_1f704c:
    // 0x1f704c: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1F704Cu;
    {
        const bool branch_taken_0x1f704c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F704Cu;
            // 0x1f7050: 0xa6000004  sh          $zero, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f704c) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F7054u;
label_1f7054:
    // 0x1f7054: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1f7054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1f7058: 0x3c060034  lui         $a2, 0x34
    ctx->pc = 0x1f7058u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)52 << 16));
    // 0x1f705c: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1f705cu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1f7060: 0x26040002  addiu       $a0, $s0, 0x2
    ctx->pc = 0x1f7060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1f7064: 0xae020090  sw          $v0, 0x90($s0)
    ctx->pc = 0x1f7064u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 2));
    // 0x1f7068: 0x26050004  addiu       $a1, $s0, 0x4
    ctx->pc = 0x1f7068u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1f706c: 0x24c6cc58  addiu       $a2, $a2, -0x33A8
    ctx->pc = 0x1f706cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294954072));
    // 0x1f7070: 0xc0724bc  jal         func_1C92F0
    ctx->pc = 0x1F7070u;
    SET_GPR_U32(ctx, 31, 0x1F7078u);
    ctx->pc = 0x1F7074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7070u;
            // 0x1f7074: 0x24e7cc60  addiu       $a3, $a3, -0x33A0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294954080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C92F0u;
    if (runtime->hasFunction(0x1C92F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C92F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7078u; }
        if (ctx->pc != 0x1F7078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C92F0_0x1c92f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F7078u; }
        if (ctx->pc != 0x1F7078u) { return; }
    }
    ctx->pc = 0x1F7078u;
label_1f7078:
    // 0x1f7078: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f7078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f707c: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1F707Cu;
    {
        const bool branch_taken_0x1f707c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1F7080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F707Cu;
            // 0x1f7080: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f707c) {
            ctx->pc = 0x1F70B0u;
            goto label_1f70b0;
        }
    }
    ctx->pc = 0x1F7084u;
    // 0x1f7084: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1f7084u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f7088: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F7088u;
    {
        const bool branch_taken_0x1f7088 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f7088) {
            ctx->pc = 0x1F70A0u;
            goto label_1f70a0;
        }
    }
    ctx->pc = 0x1F7090u;
    // 0x1f7090: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1F7090u;
    {
        const bool branch_taken_0x1f7090 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f7090) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F7098u;
    // 0x1f7098: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1F7098u;
    {
        const bool branch_taken_0x1f7098 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f7098) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F70A0u;
label_1f70a0:
    // 0x1f70a0: 0x82020001  lb          $v0, 0x1($s0)
    ctx->pc = 0x1f70a0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1f70a4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f70a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f70a8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F70A8u;
    {
        const bool branch_taken_0x1f70a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F70ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F70A8u;
            // 0x1f70ac: 0xa2020001  sb          $v0, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f70a8) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F70B0u;
label_1f70b0:
    // 0x1f70b0: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f70b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f70b4: 0xae03008c  sw          $v1, 0x8C($s0)
    ctx->pc = 0x1f70b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 3));
    // 0x1f70b8: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1f70b8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f70bc: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1f70bcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f70c0: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x1f70c0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f70c4: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1f70c4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f70c8: 0xa6000004  sh          $zero, 0x4($s0)
    ctx->pc = 0x1f70c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f70cc: 0xa6000006  sh          $zero, 0x6($s0)
    ctx->pc = 0x1f70ccu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f70d0: 0xa6000008  sh          $zero, 0x8($s0)
    ctx->pc = 0x1f70d0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f70d4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F70D4u;
    {
        const bool branch_taken_0x1f70d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F70D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F70D4u;
            // 0x1f70d8: 0xa600000a  sh          $zero, 0xA($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f70d4) {
            ctx->pc = 0x1F70ECu;
            goto label_1f70ec;
        }
    }
    ctx->pc = 0x1F70DCu;
label_1f70dc:
    // 0x1f70dc: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1f70dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1f70e0: 0xae030090  sw          $v1, 0x90($s0)
    ctx->pc = 0x1f70e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 3));
    // 0x1f70e4: 0xae020088  sw          $v0, 0x88($s0)
    ctx->pc = 0x1f70e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 2));
    // 0x1f70e8: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x1f70e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
label_1f70ec:
    // 0x1f70ec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f70ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1f70f0:
    // 0x1f70f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f70f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f70f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f70f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f70f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F70F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F70FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F70F8u;
            // 0x1f70fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F7100u;
    // 0x1f7100: 0x8c850024  lw          $a1, 0x24($a0)
    ctx->pc = 0x1f7100u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f7104: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f7104u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f7108: 0xafa0000c  sw          $zero, 0xC($sp)
    ctx->pc = 0x1f7108u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
    // 0x1f710c: 0x8c82008c  lw          $v0, 0x8C($a0)
    ctx->pc = 0x1f710cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x1f7110: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F7110u;
    {
        const bool branch_taken_0x1f7110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F7114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7110u;
            // 0x1f7114: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7110) {
            ctx->pc = 0x1F7128u;
            goto label_1f7128;
        }
    }
    ctx->pc = 0x1F7118u;
    // 0x1f7118: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1f7118u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f711c: 0xa0800001  sb          $zero, 0x1($a0)
    ctx->pc = 0x1f711cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f7120: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F7120u;
    {
        const bool branch_taken_0x1f7120 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7120u;
            // 0x1f7124: 0xa4800004  sh          $zero, 0x4($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7120) {
            ctx->pc = 0x1F7148u;
            goto label_1f7148;
        }
    }
    ctx->pc = 0x1F7128u;
label_1f7128:
    // 0x1f7128: 0x90a30002  lbu         $v1, 0x2($a1)
    ctx->pc = 0x1f7128u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1f712c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1f712cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f7130: 0xa3a3000e  sb          $v1, 0xE($sp)
    ctx->pc = 0x1f7130u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 14), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f7134: 0x90a30003  lbu         $v1, 0x3($a1)
    ctx->pc = 0x1f7134u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 3)));
    // 0x1f7138: 0xa3a3000d  sb          $v1, 0xD($sp)
    ctx->pc = 0x1f7138u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f713c: 0x90a30004  lbu         $v1, 0x4($a1)
    ctx->pc = 0x1f713cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1f7140: 0xa3a3000c  sb          $v1, 0xC($sp)
    ctx->pc = 0x1f7140u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 12), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f7144: 0xac820088  sw          $v0, 0x88($a0)
    ctx->pc = 0x1f7144u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 136), GPR_U32(ctx, 2));
label_1f7148:
    // 0x1f7148: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x1f7148u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1f714c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F714Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F7150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F714Cu;
            // 0x1f7150: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F65D0u: goto label_1f65d0;
            case 0x1F65F8u: goto label_1f65f8;
            case 0x1F660Cu: goto label_1f660c;
            case 0x1F6620u: goto label_1f6620;
            case 0x1F6634u: goto label_1f6634;
            case 0x1F6644u: goto label_1f6644;
            case 0x1F665Cu: goto label_1f665c;
            case 0x1F6670u: goto label_1f6670;
            case 0x1F6684u: goto label_1f6684;
            case 0x1F6698u: goto label_1f6698;
            case 0x1F66ACu: goto label_1f66ac;
            case 0x1F66B0u: goto label_1f66b0;
            case 0x1F66C8u: goto label_1f66c8;
            case 0x1F66E4u: goto label_1f66e4;
            case 0x1F66FCu: goto label_1f66fc;
            case 0x1F6714u: goto label_1f6714;
            case 0x1F6728u: goto label_1f6728;
            case 0x1F6744u: goto label_1f6744;
            case 0x1F6790u: goto label_1f6790;
            case 0x1F6798u: goto label_1f6798;
            case 0x1F67ACu: goto label_1f67ac;
            case 0x1F67B8u: goto label_1f67b8;
            case 0x1F67F0u: goto label_1f67f0;
            case 0x1F6838u: goto label_1f6838;
            case 0x1F683Cu: goto label_1f683c;
            case 0x1F6898u: goto label_1f6898;
            case 0x1F68ACu: goto label_1f68ac;
            case 0x1F68CCu: goto label_1f68cc;
            case 0x1F6900u: goto label_1f6900;
            case 0x1F691Cu: goto label_1f691c;
            case 0x1F6944u: goto label_1f6944;
            case 0x1F6954u: goto label_1f6954;
            case 0x1F6980u: goto label_1f6980;
            case 0x1F69ACu: goto label_1f69ac;
            case 0x1F69E4u: goto label_1f69e4;
            case 0x1F6A00u: goto label_1f6a00;
            case 0x1F6A30u: goto label_1f6a30;
            case 0x1F6A38u: goto label_1f6a38;
            case 0x1F6A68u: goto label_1f6a68;
            case 0x1F6A78u: goto label_1f6a78;
            case 0x1F6A90u: goto label_1f6a90;
            case 0x1F6A98u: goto label_1f6a98;
            case 0x1F6AC8u: goto label_1f6ac8;
            case 0x1F6AF0u: goto label_1f6af0;
            case 0x1F6AFCu: goto label_1f6afc;
            case 0x1F6B00u: goto label_1f6b00;
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            case 0x1F6F70u: goto label_1f6f70;
            case 0x1F6F78u: goto label_1f6f78;
            case 0x1F6FFCu: goto label_1f6ffc;
            case 0x1F702Cu: goto label_1f702c;
            case 0x1F703Cu: goto label_1f703c;
            case 0x1F7048u: goto label_1f7048;
            case 0x1F704Cu: goto label_1f704c;
            case 0x1F7054u: goto label_1f7054;
            case 0x1F7078u: goto label_1f7078;
            case 0x1F70A0u: goto label_1f70a0;
            case 0x1F70B0u: goto label_1f70b0;
            case 0x1F70DCu: goto label_1f70dc;
            case 0x1F70ECu: goto label_1f70ec;
            case 0x1F70F0u: goto label_1f70f0;
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F7154u;
    // 0x1f7154: 0x0  nop
    ctx->pc = 0x1f7154u;
    // NOP
    // 0x1f7158: 0x0  nop
    ctx->pc = 0x1f7158u;
    // NOP
    // 0x1f715c: 0x0  nop
    ctx->pc = 0x1f715cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
