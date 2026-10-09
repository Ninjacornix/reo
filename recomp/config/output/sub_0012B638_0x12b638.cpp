#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B638
// Address: 0x12b638 - 0x12b7b0
void sub_0012B638_0x12b638(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B638_0x12b638");
#endif

    switch (ctx->pc) {
        case 0x12b680u: goto label_12b680;
        case 0x12b690u: goto label_12b690;
        case 0x12b6a0u: goto label_12b6a0;
        case 0x12b724u: goto label_12b724;
        case 0x12b738u: goto label_12b738;
        case 0x12b748u: goto label_12b748;
        case 0x12b750u: goto label_12b750;
        case 0x12b758u: goto label_12b758;
        case 0x12b760u: goto label_12b760;
        case 0x12b770u: goto label_12b770;
        case 0x12b784u: goto label_12b784;
        default: break;
    }

    ctx->pc = 0x12b638u;

    // 0x12b638: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12b638u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12b63c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12b63cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12b640: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x12b640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x12b644: 0x3c120021  lui         $s2, 0x21
    ctx->pc = 0x12b644u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
    // 0x12b648: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12b648u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12b64c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12b64cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b650: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x12b650u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12b654: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b654u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b658: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x12b658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x12b65c: 0x24420450  addiu       $v0, $v0, 0x450
    ctx->pc = 0x12b65cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1104));
    // 0x12b660: 0x8e450454  lw          $a1, 0x454($s2)
    ctx->pc = 0x12b660u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 1108)));
    // 0x12b664: 0x2463049c  addiu       $v1, $v1, 0x49C
    ctx->pc = 0x12b664u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1180));
    // 0x12b668: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x12b668u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12b66c: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x12b66cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x12b670: 0x54a00045  bnel        $a1, $zero, . + 4 + (0x45 << 2)
    ctx->pc = 0x12B670u;
    {
        const bool branch_taken_0x12b670 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x12b670) {
            ctx->pc = 0x12B674u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12B670u;
            // 0x12b674: 0x26430454  addiu       $v1, $s2, 0x454 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1108));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12B788u;
            goto label_12b788;
        }
    }
    ctx->pc = 0x12B678u;
    // 0x12b678: 0xc05083e  jal         func_1420F8
    ctx->pc = 0x12B678u;
    SET_GPR_U32(ctx, 31, 0x12B680u);
    ctx->pc = 0x1420F8u;
    if (runtime->hasFunction(0x1420F8u)) {
        auto targetFn = runtime->lookupFunction(0x1420F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B680u; }
        if (ctx->pc != 0x12B680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001420F8_0x1420f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B680u; }
        if (ctx->pc != 0x12B680u) { return; }
    }
    ctx->pc = 0x12B680u;
label_12b680:
    // 0x12b680: 0x3c040013  lui         $a0, 0x13
    ctx->pc = 0x12b680u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)19 << 16));
    // 0x12b684: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12b684u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b688: 0xc05077c  jal         func_141DF0
    ctx->pc = 0x12B688u;
    SET_GPR_U32(ctx, 31, 0x12B690u);
    ctx->pc = 0x12B68Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B688u;
            // 0x12b68c: 0x2484a968  addiu       $a0, $a0, -0x5698 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294945128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141DF0u;
    if (runtime->hasFunction(0x141DF0u)) {
        auto targetFn = runtime->lookupFunction(0x141DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B690u; }
        if (ctx->pc != 0x12B690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141DF0_0x141df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B690u; }
        if (ctx->pc != 0x12B690u) { return; }
    }
    ctx->pc = 0x12B690u;
label_12b690:
    // 0x12b690: 0x3c040013  lui         $a0, 0x13
    ctx->pc = 0x12b690u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)19 << 16));
    // 0x12b694: 0x2484a9f0  addiu       $a0, $a0, -0x5610
    ctx->pc = 0x12b694u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294945264));
    // 0x12b698: 0xc050782  jal         func_141E08
    ctx->pc = 0x12B698u;
    SET_GPR_U32(ctx, 31, 0x12B6A0u);
    ctx->pc = 0x12B69Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B698u;
            // 0x12b69c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141E08u;
    if (runtime->hasFunction(0x141E08u)) {
        auto targetFn = runtime->lookupFunction(0x141E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B6A0u; }
        if (ctx->pc != 0x12B6A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141E08_0x141e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B6A0u; }
        if (ctx->pc != 0x12B6A0u) { return; }
    }
    ctx->pc = 0x12B6A0u;
label_12b6a0:
    // 0x12b6a0: 0x56000011  bnel        $s0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x12B6A0u;
    {
        const bool branch_taken_0x12b6a0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x12b6a0) {
            ctx->pc = 0x12B6A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12B6A0u;
            // 0x12b6a4: 0x8e030010  lw          $v1, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12B6E8u;
            goto label_12b6e8;
        }
    }
    ctx->pc = 0x12B6A8u;
    // 0x12b6a8: 0x3c110021  lui         $s1, 0x21
    ctx->pc = 0x12b6a8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
    // 0x12b6ac: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x12b6acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x12b6b0: 0x26240460  addiu       $a0, $s1, 0x460
    ctx->pc = 0x12b6b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12b6b4: 0x24030019  addiu       $v1, $zero, 0x19
    ctx->pc = 0x12b6b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x12b6b8: 0xac820014  sw          $v0, 0x14($a0)
    ctx->pc = 0x12b6b8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x12b6bc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12b6bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12b6c0: 0xac830018  sw          $v1, 0x18($a0)
    ctx->pc = 0x12b6c0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x12b6c4: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x12b6c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x12b6c8: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x12b6c8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x12b6cc: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x12b6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12b6d0: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x12b6d0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x12b6d4: 0x24030012  addiu       $v1, $zero, 0x12
    ctx->pc = 0x12b6d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x12b6d8: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x12b6d8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x12b6dc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x12B6DCu;
    {
        const bool branch_taken_0x12b6dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12B6E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B6DCu;
            // 0x12b6e0: 0xac830010  sw          $v1, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12b6dc) {
            ctx->pc = 0x12B71Cu;
            goto label_12b71c;
        }
    }
    ctx->pc = 0x12B6E4u;
    // 0x12b6e4: 0x0  nop
    ctx->pc = 0x12b6e4u;
    // NOP
label_12b6e8:
    // 0x12b6e8: 0x3c110021  lui         $s1, 0x21
    ctx->pc = 0x12b6e8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
    // 0x12b6ec: 0x26240460  addiu       $a0, $s1, 0x460
    ctx->pc = 0x12b6ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12b6f0: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x12b6f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x12b6f4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12b6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b6f8: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x12b6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x12b6fc: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x12b6fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12b700: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x12b700u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x12b704: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x12b704u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x12b708: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x12b708u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x12b70c: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x12b70cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x12b710: 0xac830010  sw          $v1, 0x10($a0)
    ctx->pc = 0x12b710u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
    // 0x12b714: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x12b714u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x12b718: 0xac820018  sw          $v0, 0x18($a0)
    ctx->pc = 0x12b718u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 2));
label_12b71c:
    // 0x12b71c: 0xc045144  jal         func_114510
    ctx->pc = 0x12B71Cu;
    SET_GPR_U32(ctx, 31, 0x12B724u);
    ctx->pc = 0x12B720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B71Cu;
            // 0x12b720: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B724u; }
        if (ctx->pc != 0x12B724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B724u; }
        if (ctx->pc != 0x12B724u) { return; }
    }
    ctx->pc = 0x12B724u;
label_12b724:
    // 0x12b724: 0x261004e8  addiu       $s0, $s0, 0x4E8
    ctx->pc = 0x12b724u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1256));
    // 0x12b728: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x12b728u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12b72c: 0x0  nop
    ctx->pc = 0x12b72cu;
    // NOP
    // 0x12b730: 0xc045148  jal         func_114520
    ctx->pc = 0x12B730u;
    SET_GPR_U32(ctx, 31, 0x12B738u);
    ctx->pc = 0x12B734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B730u;
            // 0x12b734: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B738u; }
        if (ctx->pc != 0x12B738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B738u; }
        if (ctx->pc != 0x12B738u) { return; }
    }
    ctx->pc = 0x12B738u;
label_12b738:
    // 0x12b738: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b738u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b73c: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x12b73cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12b740: 0xc04ac6e  jal         func_12B1B8
    ctx->pc = 0x12B740u;
    SET_GPR_U32(ctx, 31, 0x12B748u);
    ctx->pc = 0x12B1B8u;
    if (runtime->hasFunction(0x12B1B8u)) {
        auto targetFn = runtime->lookupFunction(0x12B1B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B748u; }
        if (ctx->pc != 0x12B748u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B1B8_0x12b1b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B748u; }
        if (ctx->pc != 0x12B748u) { return; }
    }
    ctx->pc = 0x12B748u;
label_12b748:
    // 0x12b748: 0xc04acba  jal         func_12B2E8
    ctx->pc = 0x12B748u;
    SET_GPR_U32(ctx, 31, 0x12B750u);
    ctx->pc = 0x12B2E8u;
    if (runtime->hasFunction(0x12B2E8u)) {
        auto targetFn = runtime->lookupFunction(0x12B2E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B750u; }
        if (ctx->pc != 0x12B750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B2E8_0x12b2e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B750u; }
        if (ctx->pc != 0x12B750u) { return; }
    }
    ctx->pc = 0x12B750u;
label_12b750:
    // 0x12b750: 0xc04acdc  jal         func_12B370
    ctx->pc = 0x12B750u;
    SET_GPR_U32(ctx, 31, 0x12B758u);
    ctx->pc = 0x12B370u;
    if (runtime->hasFunction(0x12B370u)) {
        auto targetFn = runtime->lookupFunction(0x12B370u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B758u; }
        if (ctx->pc != 0x12B758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B370_0x12b370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B758u; }
        if (ctx->pc != 0x12B758u) { return; }
    }
    ctx->pc = 0x12B758u;
label_12b758:
    // 0x12b758: 0xc04acfe  jal         func_12B3F8
    ctx->pc = 0x12B758u;
    SET_GPR_U32(ctx, 31, 0x12B760u);
    ctx->pc = 0x12B3F8u;
    if (runtime->hasFunction(0x12B3F8u)) {
        auto targetFn = runtime->lookupFunction(0x12B3F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B760u; }
        if (ctx->pc != 0x12B760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B3F8_0x12b3f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B760u; }
        if (ctx->pc != 0x12B760u) { return; }
    }
    ctx->pc = 0x12B760u;
label_12b760:
    // 0x12b760: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12b760u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12b764: 0x26220460  addiu       $v0, $s1, 0x460
    ctx->pc = 0x12b764u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12b768: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12B768u;
    SET_GPR_U32(ctx, 31, 0x12B770u);
    ctx->pc = 0x12B76Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B768u;
            // 0x12b76c: 0x8c450014  lw          $a1, 0x14($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B770u; }
        if (ctx->pc != 0x12B770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B770u; }
        if (ctx->pc != 0x12B770u) { return; }
    }
    ctx->pc = 0x12B770u;
label_12b770:
    // 0x12b770: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12b770u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12b774: 0x24a5ab38  addiu       $a1, $a1, -0x54C8
    ctx->pc = 0x12b774u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945592));
    // 0x12b778: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x12b778u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x12b77c: 0xc050746  jal         func_141D18
    ctx->pc = 0x12B77Cu;
    SET_GPR_U32(ctx, 31, 0x12B784u);
    ctx->pc = 0x12B780u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12B77Cu;
            // 0x12b780: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141D18u;
    if (runtime->hasFunction(0x141D18u)) {
        auto targetFn = runtime->lookupFunction(0x141D18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B784u; }
        if (ctx->pc != 0x12B784u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141D18_0x141d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12B784u; }
        if (ctx->pc != 0x12B784u) { return; }
    }
    ctx->pc = 0x12B784u;
label_12b784:
    // 0x12b784: 0x26430454  addiu       $v1, $s2, 0x454
    ctx->pc = 0x12b784u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1108));
label_12b788:
    // 0x12b788: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x12b788u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12b78c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12b78cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12b790: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12b790u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12b794: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x12b794u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12b798: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12b798u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12b79c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x12b79cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12b7a0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x12b7a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x12b7a4: 0x3e00008  jr          $ra
    ctx->pc = 0x12B7A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B7A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B7A4u;
            // 0x12b7a8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12B680u: goto label_12b680;
            case 0x12B690u: goto label_12b690;
            case 0x12B6A0u: goto label_12b6a0;
            case 0x12B6E8u: goto label_12b6e8;
            case 0x12B71Cu: goto label_12b71c;
            case 0x12B724u: goto label_12b724;
            case 0x12B738u: goto label_12b738;
            case 0x12B748u: goto label_12b748;
            case 0x12B750u: goto label_12b750;
            case 0x12B758u: goto label_12b758;
            case 0x12B760u: goto label_12b760;
            case 0x12B770u: goto label_12b770;
            case 0x12B784u: goto label_12b784;
            case 0x12B788u: goto label_12b788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12B7ACu;
    // 0x12b7ac: 0x0  nop
    ctx->pc = 0x12b7acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
