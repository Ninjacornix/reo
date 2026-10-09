#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C1D0
// Address: 0x12c1d0 - 0x12c384
void sub_0012C1D0_0x12c1d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C1D0_0x12c1d0");
#endif

    switch (ctx->pc) {
        case 0x12c20cu: goto label_12c20c;
        case 0x12c21cu: goto label_12c21c;
        case 0x12c22cu: goto label_12c22c;
        case 0x12c2ccu: goto label_12c2cc;
        case 0x12c2e0u: goto label_12c2e0;
        case 0x12c2f0u: goto label_12c2f0;
        case 0x12c2f8u: goto label_12c2f8;
        case 0x12c300u: goto label_12c300;
        case 0x12c308u: goto label_12c308;
        case 0x12c310u: goto label_12c310;
        case 0x12c318u: goto label_12c318;
        case 0x12c328u: goto label_12c328;
        case 0x12c33cu: goto label_12c33c;
        case 0x12c350u: goto label_12c350;
        default: break;
    }

    ctx->pc = 0x12c1d0u;

    // 0x12c1d0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x12c1d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12c1d4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12c1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12c1d8: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x12c1d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x12c1dc: 0x3c120021  lui         $s2, 0x21
    ctx->pc = 0x12c1dcu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)33 << 16));
    // 0x12c1e0: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12c1e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12c1e4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12c1e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c1e8: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x12c1e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12c1ec: 0x24420450  addiu       $v0, $v0, 0x450
    ctx->pc = 0x12c1ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1104));
    // 0x12c1f0: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x12c1f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x12c1f4: 0x8e430454  lw          $v1, 0x454($s2)
    ctx->pc = 0x12c1f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 1108)));
    // 0x12c1f8: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x12c1f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12c1fc: 0x54600058  bnel        $v1, $zero, . + 4 + (0x58 << 2)
    ctx->pc = 0x12C1FCu;
    {
        const bool branch_taken_0x12c1fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x12c1fc) {
            ctx->pc = 0x12C200u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12C1FCu;
            // 0x12c200: 0x26430454  addiu       $v1, $s2, 0x454 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1108));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12C360u;
            goto label_12c360;
        }
    }
    ctx->pc = 0x12C204u;
    // 0x12c204: 0xc05083e  jal         func_1420F8
    ctx->pc = 0x12C204u;
    SET_GPR_U32(ctx, 31, 0x12C20Cu);
    ctx->pc = 0x1420F8u;
    if (runtime->hasFunction(0x1420F8u)) {
        auto targetFn = runtime->lookupFunction(0x1420F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C20Cu; }
        if (ctx->pc != 0x12C20Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001420F8_0x1420f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C20Cu; }
        if (ctx->pc != 0x12C20Cu) { return; }
    }
    ctx->pc = 0x12C20Cu;
label_12c20c:
    // 0x12c20c: 0x3c040013  lui         $a0, 0x13
    ctx->pc = 0x12c20cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)19 << 16));
    // 0x12c210: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12c210u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c214: 0xc05077c  jal         func_141DF0
    ctx->pc = 0x12C214u;
    SET_GPR_U32(ctx, 31, 0x12C21Cu);
    ctx->pc = 0x12C218u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C214u;
            // 0x12c218: 0x2484a968  addiu       $a0, $a0, -0x5698 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294945128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141DF0u;
    if (runtime->hasFunction(0x141DF0u)) {
        auto targetFn = runtime->lookupFunction(0x141DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C21Cu; }
        if (ctx->pc != 0x12C21Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141DF0_0x141df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C21Cu; }
        if (ctx->pc != 0x12C21Cu) { return; }
    }
    ctx->pc = 0x12C21Cu;
label_12c21c:
    // 0x12c21c: 0x3c040013  lui         $a0, 0x13
    ctx->pc = 0x12c21cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)19 << 16));
    // 0x12c220: 0x2484a9f0  addiu       $a0, $a0, -0x5610
    ctx->pc = 0x12c220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294945264));
    // 0x12c224: 0xc050782  jal         func_141E08
    ctx->pc = 0x12C224u;
    SET_GPR_U32(ctx, 31, 0x12C22Cu);
    ctx->pc = 0x12C228u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C224u;
            // 0x12c228: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141E08u;
    if (runtime->hasFunction(0x141E08u)) {
        auto targetFn = runtime->lookupFunction(0x141E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C22Cu; }
        if (ctx->pc != 0x12C22Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141E08_0x141e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C22Cu; }
        if (ctx->pc != 0x12C22Cu) { return; }
    }
    ctx->pc = 0x12C22Cu;
label_12c22c:
    // 0x12c22c: 0x56000014  bnel        $s0, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x12C22Cu;
    {
        const bool branch_taken_0x12c22c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x12c22c) {
            ctx->pc = 0x12C230u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12C22Cu;
            // 0x12c230: 0x8e030014  lw          $v1, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12C280u;
            goto label_12c280;
        }
    }
    ctx->pc = 0x12C234u;
    // 0x12c234: 0x3c110021  lui         $s1, 0x21
    ctx->pc = 0x12c234u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
    // 0x12c238: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x12c238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x12c23c: 0x26240460  addiu       $a0, $s1, 0x460
    ctx->pc = 0x12c23cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12c240: 0x2403001a  addiu       $v1, $zero, 0x1A
    ctx->pc = 0x12c240u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x12c244: 0xac820014  sw          $v0, 0x14($a0)
    ctx->pc = 0x12c244u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x12c248: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12c248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c24c: 0xac83001c  sw          $v1, 0x1C($a0)
    ctx->pc = 0x12c24cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
    // 0x12c250: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x12c250u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x12c254: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x12c254u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x12c258: 0x2402000f  addiu       $v0, $zero, 0xF
    ctx->pc = 0x12c258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x12c25c: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x12c25cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x12c260: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x12c260u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12c264: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x12c264u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x12c268: 0x24020012  addiu       $v0, $zero, 0x12
    ctx->pc = 0x12c268u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x12c26c: 0xac83000c  sw          $v1, 0xC($a0)
    ctx->pc = 0x12c26cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x12c270: 0x24030019  addiu       $v1, $zero, 0x19
    ctx->pc = 0x12c270u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x12c274: 0xac820010  sw          $v0, 0x10($a0)
    ctx->pc = 0x12c274u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x12c278: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x12C278u;
    {
        const bool branch_taken_0x12c278 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12C27Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C278u;
            // 0x12c27c: 0xac830018  sw          $v1, 0x18($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12c278) {
            ctx->pc = 0x12C2C4u;
            goto label_12c2c4;
        }
    }
    ctx->pc = 0x12C280u;
label_12c280:
    // 0x12c280: 0x3c110021  lui         $s1, 0x21
    ctx->pc = 0x12c280u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
    // 0x12c284: 0x26240460  addiu       $a0, $s1, 0x460
    ctx->pc = 0x12c284u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12c288: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x12c288u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x12c28c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x12c28cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12c290: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x12c290u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x12c294: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x12c294u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12c298: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x12c298u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x12c29c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x12c29cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x12c2a0: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x12c2a0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x12c2a4: 0x8e03000c  lw          $v1, 0xC($s0)
    ctx->pc = 0x12c2a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x12c2a8: 0xac83000c  sw          $v1, 0xC($a0)
    ctx->pc = 0x12c2a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x12c2ac: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x12c2acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x12c2b0: 0xac820010  sw          $v0, 0x10($a0)
    ctx->pc = 0x12c2b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x12c2b4: 0x8e030018  lw          $v1, 0x18($s0)
    ctx->pc = 0x12c2b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x12c2b8: 0xac830018  sw          $v1, 0x18($a0)
    ctx->pc = 0x12c2b8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x12c2bc: 0x8e02001c  lw          $v0, 0x1C($s0)
    ctx->pc = 0x12c2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x12c2c0: 0xac82001c  sw          $v0, 0x1C($a0)
    ctx->pc = 0x12c2c0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 2));
label_12c2c4:
    // 0x12c2c4: 0xc045144  jal         func_114510
    ctx->pc = 0x12C2C4u;
    SET_GPR_U32(ctx, 31, 0x12C2CCu);
    ctx->pc = 0x12C2C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C2C4u;
            // 0x12c2c8: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114510u;
    if (runtime->hasFunction(0x114510u)) {
        auto targetFn = runtime->lookupFunction(0x114510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2CCu; }
        if (ctx->pc != 0x12C2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2CCu; }
        if (ctx->pc != 0x12C2CCu) { return; }
    }
    ctx->pc = 0x12C2CCu;
label_12c2cc:
    // 0x12c2cc: 0x261004e8  addiu       $s0, $s0, 0x4E8
    ctx->pc = 0x12c2ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1256));
    // 0x12c2d0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x12c2d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c2d4: 0x0  nop
    ctx->pc = 0x12c2d4u;
    // NOP
    // 0x12c2d8: 0xc045148  jal         func_114520
    ctx->pc = 0x12C2D8u;
    SET_GPR_U32(ctx, 31, 0x12C2E0u);
    ctx->pc = 0x12C2DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C2D8u;
            // 0x12c2dc: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114520u;
    if (runtime->hasFunction(0x114520u)) {
        auto targetFn = runtime->lookupFunction(0x114520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2E0u; }
        if (ctx->pc != 0x12C2E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2E0u; }
        if (ctx->pc != 0x12C2E0u) { return; }
    }
    ctx->pc = 0x12C2E0u;
label_12c2e0:
    // 0x12c2e0: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12c2e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12c2e4: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x12c2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12c2e8: 0xc04ac6e  jal         func_12B1B8
    ctx->pc = 0x12C2E8u;
    SET_GPR_U32(ctx, 31, 0x12C2F0u);
    ctx->pc = 0x12B1B8u;
    if (runtime->hasFunction(0x12B1B8u)) {
        auto targetFn = runtime->lookupFunction(0x12B1B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2F0u; }
        if (ctx->pc != 0x12C2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B1B8_0x12b1b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2F0u; }
        if (ctx->pc != 0x12C2F0u) { return; }
    }
    ctx->pc = 0x12C2F0u;
label_12c2f0:
    // 0x12c2f0: 0xc04ac98  jal         func_12B260
    ctx->pc = 0x12C2F0u;
    SET_GPR_U32(ctx, 31, 0x12C2F8u);
    ctx->pc = 0x12B260u;
    if (runtime->hasFunction(0x12B260u)) {
        auto targetFn = runtime->lookupFunction(0x12B260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2F8u; }
        if (ctx->pc != 0x12C2F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B260_0x12b260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2F8u; }
        if (ctx->pc != 0x12C2F8u) { return; }
    }
    ctx->pc = 0x12C2F8u;
label_12c2f8:
    // 0x12c2f8: 0xc04acba  jal         func_12B2E8
    ctx->pc = 0x12C2F8u;
    SET_GPR_U32(ctx, 31, 0x12C300u);
    ctx->pc = 0x12B2E8u;
    if (runtime->hasFunction(0x12B2E8u)) {
        auto targetFn = runtime->lookupFunction(0x12B2E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C300u; }
        if (ctx->pc != 0x12C300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B2E8_0x12b2e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C300u; }
        if (ctx->pc != 0x12C300u) { return; }
    }
    ctx->pc = 0x12C300u;
label_12c300:
    // 0x12c300: 0xc04acdc  jal         func_12B370
    ctx->pc = 0x12C300u;
    SET_GPR_U32(ctx, 31, 0x12C308u);
    ctx->pc = 0x12B370u;
    if (runtime->hasFunction(0x12B370u)) {
        auto targetFn = runtime->lookupFunction(0x12B370u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C308u; }
        if (ctx->pc != 0x12C308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B370_0x12b370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C308u; }
        if (ctx->pc != 0x12C308u) { return; }
    }
    ctx->pc = 0x12C308u;
label_12c308:
    // 0x12c308: 0xc04acfe  jal         func_12B3F8
    ctx->pc = 0x12C308u;
    SET_GPR_U32(ctx, 31, 0x12C310u);
    ctx->pc = 0x12B3F8u;
    if (runtime->hasFunction(0x12B3F8u)) {
        auto targetFn = runtime->lookupFunction(0x12B3F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C310u; }
        if (ctx->pc != 0x12C310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B3F8_0x12b3f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C310u; }
        if (ctx->pc != 0x12C310u) { return; }
    }
    ctx->pc = 0x12C310u;
label_12c310:
    // 0x12c310: 0xc04ad24  jal         func_12B490
    ctx->pc = 0x12C310u;
    SET_GPR_U32(ctx, 31, 0x12C318u);
    ctx->pc = 0x12B490u;
    if (runtime->hasFunction(0x12B490u)) {
        auto targetFn = runtime->lookupFunction(0x12B490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C318u; }
        if (ctx->pc != 0x12C318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B490_0x12b490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C318u; }
        if (ctx->pc != 0x12C318u) { return; }
    }
    ctx->pc = 0x12C318u;
label_12c318:
    // 0x12c318: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x12c318u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12c31c: 0x26220460  addiu       $v0, $s1, 0x460
    ctx->pc = 0x12c31cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12c320: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12C320u;
    SET_GPR_U32(ctx, 31, 0x12C328u);
    ctx->pc = 0x12C324u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C320u;
            // 0x12c324: 0x8c450014  lw          $a1, 0x14($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C328u; }
        if (ctx->pc != 0x12C328u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C328u; }
        if (ctx->pc != 0x12C328u) { return; }
    }
    ctx->pc = 0x12C328u;
label_12c328:
    // 0x12c328: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12c328u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12c32c: 0x24a5ab38  addiu       $a1, $a1, -0x54C8
    ctx->pc = 0x12c32cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945592));
    // 0x12c330: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x12c330u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x12c334: 0xc050746  jal         func_141D18
    ctx->pc = 0x12C334u;
    SET_GPR_U32(ctx, 31, 0x12C33Cu);
    ctx->pc = 0x12C338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C334u;
            // 0x12c338: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141D18u;
    if (runtime->hasFunction(0x141D18u)) {
        auto targetFn = runtime->lookupFunction(0x141D18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C33Cu; }
        if (ctx->pc != 0x12C33Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141D18_0x141d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C33Cu; }
        if (ctx->pc != 0x12C33Cu) { return; }
    }
    ctx->pc = 0x12C33Cu;
label_12c33c:
    // 0x12c33c: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12c33cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12c340: 0x24a5ab60  addiu       $a1, $a1, -0x54A0
    ctx->pc = 0x12c340u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945632));
    // 0x12c344: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x12c344u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x12c348: 0xc050746  jal         func_141D18
    ctx->pc = 0x12C348u;
    SET_GPR_U32(ctx, 31, 0x12C350u);
    ctx->pc = 0x12C34Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C348u;
            // 0x12c34c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141D18u;
    if (runtime->hasFunction(0x141D18u)) {
        auto targetFn = runtime->lookupFunction(0x141D18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C350u; }
        if (ctx->pc != 0x12C350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141D18_0x141d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C350u; }
        if (ctx->pc != 0x12C350u) { return; }
    }
    ctx->pc = 0x12C350u;
label_12c350:
    // 0x12c350: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12c350u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12c354: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12c354u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c358: 0xac620458  sw          $v0, 0x458($v1)
    ctx->pc = 0x12c358u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1112), GPR_U32(ctx, 2));
    // 0x12c35c: 0x26430454  addiu       $v1, $s2, 0x454
    ctx->pc = 0x12c35cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1108));
label_12c360:
    // 0x12c360: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x12c360u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12c364: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12c364u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12c368: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12c368u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12c36c: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x12c36cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12c370: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12c370u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12c374: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x12c374u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12c378: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x12c378u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x12c37c: 0x3e00008  jr          $ra
    ctx->pc = 0x12C37Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C37Cu;
            // 0x12c380: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C20Cu: goto label_12c20c;
            case 0x12C21Cu: goto label_12c21c;
            case 0x12C22Cu: goto label_12c22c;
            case 0x12C280u: goto label_12c280;
            case 0x12C2C4u: goto label_12c2c4;
            case 0x12C2CCu: goto label_12c2cc;
            case 0x12C2E0u: goto label_12c2e0;
            case 0x12C2F0u: goto label_12c2f0;
            case 0x12C2F8u: goto label_12c2f8;
            case 0x12C300u: goto label_12c300;
            case 0x12C308u: goto label_12c308;
            case 0x12C310u: goto label_12c310;
            case 0x12C318u: goto label_12c318;
            case 0x12C328u: goto label_12c328;
            case 0x12C33Cu: goto label_12c33c;
            case 0x12C350u: goto label_12c350;
            case 0x12C360u: goto label_12c360;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C384u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
