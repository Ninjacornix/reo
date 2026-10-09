#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C3150
// Address: 0x1c3150 - 0x1c3590
void sub_001C3150_0x1c3150(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C3150_0x1c3150");
#endif

    switch (ctx->pc) {
        case 0x1c31a4u: goto label_1c31a4;
        case 0x1c31acu: goto label_1c31ac;
        case 0x1c3318u: goto label_1c3318;
        case 0x1c3334u: goto label_1c3334;
        case 0x1c3374u: goto label_1c3374;
        case 0x1c3390u: goto label_1c3390;
        case 0x1c3404u: goto label_1c3404;
        case 0x1c3424u: goto label_1c3424;
        case 0x1c3454u: goto label_1c3454;
        case 0x1c3468u: goto label_1c3468;
        case 0x1c3538u: goto label_1c3538;
        case 0x1c3558u: goto label_1c3558;
        case 0x1c356cu: goto label_1c356c;
        case 0x1c3574u: goto label_1c3574;
        default: break;
    }

    ctx->pc = 0x1c3150u;

    // 0x1c3150: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c3150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c3154: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c3154u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c3158: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c3158u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c315c: 0x80820002  lb          $v0, 0x2($a0)
    ctx->pc = 0x1c315cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1c3160: 0x2c410006  sltiu       $at, $v0, 0x6
    ctx->pc = 0x1c3160u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x1c3164: 0x102000fe  beqz        $at, . + 4 + (0xFE << 2)
    ctx->pc = 0x1C3164u;
    {
        const bool branch_taken_0x1c3164 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3164u;
            // 0x1c3168: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3164) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C316Cu;
    // 0x1c316c: 0x3c030025  lui         $v1, 0x25
    ctx->pc = 0x1c316cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
    // 0x1c3170: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1c3170u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1c3174: 0x24632d00  addiu       $v1, $v1, 0x2D00
    ctx->pc = 0x1c3174u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 11520));
    // 0x1c3178: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c3178u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c317c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c317cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c3180: 0x400008  jr          $v0
    ctx->pc = 0x1C3180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C3188u: goto label_1c3188;
            case 0x1C31A4u: goto label_1c31a4;
            case 0x1C32F0u: goto label_1c32f0;
            case 0x1C341Cu: goto label_1c341c;
            case 0x1C3520u: goto label_1c3520;
            case 0x1C3540u: goto label_1c3540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C3188u;
label_1c3188:
    // 0x1c3188: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1c3188u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c318c: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1c318cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1c3190: 0xa2060002  sb          $a2, 0x2($s0)
    ctx->pc = 0x1c3190u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x1c3194: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c3194u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3198: 0x8e0500e8  lw          $a1, 0xE8($s0)
    ctx->pc = 0x1c3198u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x1c319c: 0xc0701c4  jal         func_1C0710
    ctx->pc = 0x1C319Cu;
    SET_GPR_U32(ctx, 31, 0x1C31A4u);
    ctx->pc = 0x1C31A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C319Cu;
            // 0x1c31a0: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0710u;
    if (runtime->hasFunction(0x1C0710u)) {
        auto targetFn = runtime->lookupFunction(0x1C0710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C31A4u; }
        if (ctx->pc != 0x1C31A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0710_0x1c0710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C31A4u; }
        if (ctx->pc != 0x1C31A4u) { return; }
    }
    ctx->pc = 0x1C31A4u;
label_1c31a4:
    // 0x1c31a4: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C31A4u;
    SET_GPR_U32(ctx, 31, 0x1C31ACu);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C31ACu; }
        if (ctx->pc != 0x1C31ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C31ACu; }
        if (ctx->pc != 0x1C31ACu) { return; }
    }
    ctx->pc = 0x1C31ACu;
label_1c31ac:
    // 0x1c31ac: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c31acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c31b0: 0x104300ec  beq         $v0, $v1, . + 4 + (0xEC << 2)
    ctx->pc = 0x1C31B0u;
    {
        const bool branch_taken_0x1c31b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C31B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C31B0u;
            // 0x1c31b4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c31b0) {
            ctx->pc = 0x1C3564u;
            goto label_1c3564;
        }
    }
    ctx->pc = 0x1C31B8u;
    // 0x1c31b8: 0x2403ff05  addiu       $v1, $zero, -0xFB
    ctx->pc = 0x1c31b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967045));
    // 0x1c31bc: 0x1043002d  beq         $v0, $v1, . + 4 + (0x2D << 2)
    ctx->pc = 0x1C31BCu;
    {
        const bool branch_taken_0x1c31bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c31bc) {
            ctx->pc = 0x1C3274u;
            goto label_1c3274;
        }
    }
    ctx->pc = 0x1C31C4u;
    // 0x1c31c4: 0x1040001f  beqz        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1C31C4u;
    {
        const bool branch_taken_0x1c31c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C31C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C31C4u;
            // 0x1c31c8: 0x2403ff02  addiu       $v1, $zero, -0xFE (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c31c4) {
            ctx->pc = 0x1C3244u;
            goto label_1c3244;
        }
    }
    ctx->pc = 0x1C31CCu;
    // 0x1c31cc: 0x10430016  beq         $v0, $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x1C31CCu;
    {
        const bool branch_taken_0x1c31cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c31cc) {
            ctx->pc = 0x1C3228u;
            goto label_1c3228;
        }
    }
    ctx->pc = 0x1C31D4u;
    // 0x1c31d4: 0x2403ff00  addiu       $v1, $zero, -0x100
    ctx->pc = 0x1c31d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c31d8: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1C31D8u;
    {
        const bool branch_taken_0x1c31d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C31DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C31D8u;
            // 0x1c31dc: 0x2403ff03  addiu       $v1, $zero, -0xFD (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c31d8) {
            ctx->pc = 0x1C320Cu;
            goto label_1c320c;
        }
    }
    ctx->pc = 0x1C31E0u;
    // 0x1c31e0: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C31E0u;
    {
        const bool branch_taken_0x1c31e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c31e0) {
            ctx->pc = 0x1C31F0u;
            goto label_1c31f0;
        }
    }
    ctx->pc = 0x1C31E8u;
    // 0x1c31e8: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1C31E8u;
    {
        const bool branch_taken_0x1c31e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C31ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C31E8u;
            // 0x1c31ec: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c31e8) {
            ctx->pc = 0x1C3290u;
            goto label_1c3290;
        }
    }
    ctx->pc = 0x1C31F0u;
label_1c31f0:
    // 0x1c31f0: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1c31f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1c31f4: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c31f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c31f8: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c31f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c31fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c31fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3200: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c3200u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c3204: 0x100000d6  b           . + 4 + (0xD6 << 2)
    ctx->pc = 0x1C3204u;
    {
        const bool branch_taken_0x1c3204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3204u;
            // 0x1c3208: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3204) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C320Cu;
label_1c320c:
    // 0x1c320c: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1c320cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1c3210: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c3210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c3214: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c3214u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3218: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3218u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c321c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c321cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c3220: 0x100000cf  b           . + 4 + (0xCF << 2)
    ctx->pc = 0x1C3220u;
    {
        const bool branch_taken_0x1c3220 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3220u;
            // 0x1c3224: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3220) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C3228u;
label_1c3228:
    // 0x1c3228: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1c3228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1c322c: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c322cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c3230: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c3230u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3234: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3234u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3238: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c3238u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c323c: 0x100000c8  b           . + 4 + (0xC8 << 2)
    ctx->pc = 0x1C323Cu;
    {
        const bool branch_taken_0x1c323c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C323Cu;
            // 0x1c3240: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c323c) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C3244u;
label_1c3244:
    // 0x1c3244: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x1c3244u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1c3248: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c3248u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c324c: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c324cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3250: 0xae030030  sw          $v1, 0x30($s0)
    ctx->pc = 0x1c3250u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 3));
    // 0x1c3254: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c3254u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c3258: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c3258u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c325c: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c325cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1c3260: 0x82020002  lb          $v0, 0x2($s0)
    ctx->pc = 0x1c3260u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c3264: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c3264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c3268: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c3268u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c326c: 0x100000bc  b           . + 4 + (0xBC << 2)
    ctx->pc = 0x1C326Cu;
    {
        const bool branch_taken_0x1c326c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C326Cu;
            // 0x1c3270: 0xa2000003  sb          $zero, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c326c) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C3274u;
label_1c3274:
    // 0x1c3274: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1c3274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1c3278: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c3278u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c327c: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c327cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3280: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3280u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3284: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c3284u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c3288: 0x100000b5  b           . + 4 + (0xB5 << 2)
    ctx->pc = 0x1C3288u;
    {
        const bool branch_taken_0x1c3288 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C328Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3288u;
            // 0x1c328c: 0xae020034  sw          $v0, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3288) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C3290u;
label_1c3290:
    // 0x1c3290: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x1c3290u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c3294: 0xa2040002  sb          $a0, 0x2($s0)
    ctx->pc = 0x1c3294u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c3298: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c3298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c329c: 0xae030034  sw          $v1, 0x34($s0)
    ctx->pc = 0x1c329cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 3));
    // 0x1c32a0: 0x8e030034  lw          $v1, 0x34($s0)
    ctx->pc = 0x1c32a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c32a4: 0x1062000f  beq         $v1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1C32A4u;
    {
        const bool branch_taken_0x1c32a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c32a4) {
            ctx->pc = 0x1C32E4u;
            goto label_1c32e4;
        }
    }
    ctx->pc = 0x1C32ACu;
    // 0x1c32ac: 0x1064000e  beq         $v1, $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x1C32ACu;
    {
        const bool branch_taken_0x1c32ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C32B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C32ACu;
            // 0x1c32b0: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c32ac) {
            ctx->pc = 0x1C32E8u;
            goto label_1c32e8;
        }
    }
    ctx->pc = 0x1C32B4u;
    // 0x1c32b4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c32b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c32b8: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C32B8u;
    {
        const bool branch_taken_0x1c32b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C32BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C32B8u;
            // 0x1c32bc: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c32b8) {
            ctx->pc = 0x1C32DCu;
            goto label_1c32dc;
        }
    }
    ctx->pc = 0x1C32C0u;
    // 0x1c32c0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c32c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c32c4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C32C4u;
    {
        const bool branch_taken_0x1c32c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C32C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C32C4u;
            // 0x1c32c8: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c32c4) {
            ctx->pc = 0x1C32D4u;
            goto label_1c32d4;
        }
    }
    ctx->pc = 0x1C32CCu;
    // 0x1c32cc: 0x100000a4  b           . + 4 + (0xA4 << 2)
    ctx->pc = 0x1C32CCu;
    {
        const bool branch_taken_0x1c32cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c32cc) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C32D4u;
label_1c32d4:
    // 0x1c32d4: 0x100000a2  b           . + 4 + (0xA2 << 2)
    ctx->pc = 0x1C32D4u;
    {
        const bool branch_taken_0x1c32d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C32D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C32D4u;
            // 0x1c32d8: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c32d4) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C32DCu;
label_1c32dc:
    // 0x1c32dc: 0x100000a0  b           . + 4 + (0xA0 << 2)
    ctx->pc = 0x1C32DCu;
    {
        const bool branch_taken_0x1c32dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C32E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C32DCu;
            // 0x1c32e0: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c32dc) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C32E4u;
label_1c32e4:
    // 0x1c32e4: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1c32e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
label_1c32e8:
    // 0x1c32e8: 0x1000009d  b           . + 4 + (0x9D << 2)
    ctx->pc = 0x1C32E8u;
    {
        const bool branch_taken_0x1c32e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C32ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C32E8u;
            // 0x1c32ec: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c32e8) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C32F0u;
label_1c32f0:
    // 0x1c32f0: 0x82030003  lb          $v1, 0x3($s0)
    ctx->pc = 0x1c32f0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1c32f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c32f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c32f8: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1C32F8u;
    {
        const bool branch_taken_0x1c32f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C32FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C32F8u;
            // 0x1c32fc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c32f8) {
            ctx->pc = 0x1C332Cu;
            goto label_1c332c;
        }
    }
    ctx->pc = 0x1C3300u;
    // 0x1c3300: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3300u;
    {
        const bool branch_taken_0x1c3300 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c3300) {
            ctx->pc = 0x1C3310u;
            goto label_1c3310;
        }
    }
    ctx->pc = 0x1C3308u;
    // 0x1c3308: 0x10000095  b           . + 4 + (0x95 << 2)
    ctx->pc = 0x1C3308u;
    {
        const bool branch_taken_0x1c3308 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c3308) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C3310u;
label_1c3310:
    // 0x1c3310: 0xc070114  jal         func_1C0450
    ctx->pc = 0x1C3310u;
    SET_GPR_U32(ctx, 31, 0x1C3318u);
    ctx->pc = 0x1C0450u;
    if (runtime->hasFunction(0x1C0450u)) {
        auto targetFn = runtime->lookupFunction(0x1C0450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3318u; }
        if (ctx->pc != 0x1C3318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0450_0x1c0450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3318u; }
        if (ctx->pc != 0x1C3318u) { return; }
    }
    ctx->pc = 0x1C3318u;
label_1c3318:
    // 0x1c3318: 0xae0000e0  sw          $zero, 0xE0($s0)
    ctx->pc = 0x1c3318u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 0));
    // 0x1c331c: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x1c331cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1c3320: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c3320u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c3324: 0x1000008e  b           . + 4 + (0x8E << 2)
    ctx->pc = 0x1C3324u;
    {
        const bool branch_taken_0x1c3324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3324u;
            // 0x1c3328: 0xa2020003  sb          $v0, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3324) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C332Cu;
label_1c332c:
    // 0x1c332c: 0xc07049c  jal         func_1C1270
    ctx->pc = 0x1C332Cu;
    SET_GPR_U32(ctx, 31, 0x1C3334u);
    ctx->pc = 0x1C1270u;
    if (runtime->hasFunction(0x1C1270u)) {
        auto targetFn = runtime->lookupFunction(0x1C1270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3334u; }
        if (ctx->pc != 0x1C3334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1270_0x1c1270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3334u; }
        if (ctx->pc != 0x1C3334u) { return; }
    }
    ctx->pc = 0x1C3334u;
label_1c3334:
    // 0x1c3334: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C3334u;
    {
        const bool branch_taken_0x1c3334 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C3338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3334u;
            // 0x1c3338: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3334) {
            ctx->pc = 0x1C335Cu;
            goto label_1c335c;
        }
    }
    ctx->pc = 0x1C333Cu;
    // 0x1c333c: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c333cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c3340: 0xae0400e0  sw          $a0, 0xE0($s0)
    ctx->pc = 0x1c3340u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 4));
    // 0x1c3344: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c3344u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c3348: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1c3348u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1c334c: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c334cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c3350: 0xae040034  sw          $a0, 0x34($s0)
    ctx->pc = 0x1c3350u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 4));
    // 0x1c3354: 0x10000082  b           . + 4 + (0x82 << 2)
    ctx->pc = 0x1C3354u;
    {
        const bool branch_taken_0x1c3354 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3354u;
            // 0x1c3358: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3354) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C335Cu;
label_1c335c:
    // 0x1c335c: 0x9603000a  lhu         $v1, 0xA($s0)
    ctx->pc = 0x1c335cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c3360: 0x30620010  andi        $v0, $v1, 0x10
    ctx->pc = 0x1c3360u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x1c3364: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C3364u;
    {
        const bool branch_taken_0x1c3364 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c3364) {
            ctx->pc = 0x1C33B0u;
            goto label_1c33b0;
        }
    }
    ctx->pc = 0x1C336Cu;
    // 0x1c336c: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C336Cu;
    SET_GPR_U32(ctx, 31, 0x1C3374u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3374u; }
        if (ctx->pc != 0x1C3374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3374u; }
        if (ctx->pc != 0x1C3374u) { return; }
    }
    ctx->pc = 0x1C3374u;
label_1c3374:
    // 0x1c3374: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1c3374u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1c3378: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c3378u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c337c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1C337Cu;
    {
        const bool branch_taken_0x1c337c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C3380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C337Cu;
            // 0x1c3380: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c337c) {
            ctx->pc = 0x1C33A8u;
            goto label_1c33a8;
        }
    }
    ctx->pc = 0x1C3384u;
    // 0x1c3384: 0x8e0500ec  lw          $a1, 0xEC($s0)
    ctx->pc = 0x1c3384u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 236)));
    // 0x1c3388: 0xc070138  jal         func_1C04E0
    ctx->pc = 0x1C3388u;
    SET_GPR_U32(ctx, 31, 0x1C3390u);
    ctx->pc = 0x1C338Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3388u;
            // 0x1c338c: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C04E0u;
    if (runtime->hasFunction(0x1C04E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C04E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3390u; }
        if (ctx->pc != 0x1C3390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C04E0_0x1c04e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3390u; }
        if (ctx->pc != 0x1C3390u) { return; }
    }
    ctx->pc = 0x1C3390u;
label_1c3390:
    // 0x1c3390: 0x82030002  lb          $v1, 0x2($s0)
    ctx->pc = 0x1c3390u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1c3394: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c3394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c3398: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c3398u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c339c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c339cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c33a0: 0x1000006f  b           . + 4 + (0x6F << 2)
    ctx->pc = 0x1C33A0u;
    {
        const bool branch_taken_0x1c33a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C33A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C33A0u;
            // 0x1c33a4: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c33a0) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C33A8u;
label_1c33a8:
    // 0x1c33a8: 0x10000074  b           . + 4 + (0x74 << 2)
    ctx->pc = 0x1C33A8u;
    {
        const bool branch_taken_0x1c33a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C33ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C33A8u;
            // 0x1c33ac: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c33a8) {
            ctx->pc = 0x1C357Cu;
            goto label_1c357c;
        }
    }
    ctx->pc = 0x1C33B0u;
label_1c33b0:
    // 0x1c33b0: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1c33b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c33b4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C33B4u;
    {
        const bool branch_taken_0x1c33b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c33b4) {
            ctx->pc = 0x1C33C8u;
            goto label_1c33c8;
        }
    }
    ctx->pc = 0x1C33BCu;
    // 0x1c33bc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c33bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c33c0: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x1C33C0u;
    {
        const bool branch_taken_0x1c33c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C33C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C33C0u;
            // 0x1c33c4: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c33c0) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C33C8u;
label_1c33c8:
    // 0x1c33c8: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x1c33c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x1c33cc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C33CCu;
    {
        const bool branch_taken_0x1c33cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C33D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C33CCu;
            // 0x1c33d0: 0x30620004  andi        $v0, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c33cc) {
            ctx->pc = 0x1C33E4u;
            goto label_1c33e4;
        }
    }
    ctx->pc = 0x1C33D4u;
    // 0x1c33d4: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c33d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c33d8: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C33D8u;
    {
        const bool branch_taken_0x1c33d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c33d8) {
            ctx->pc = 0x1C33FCu;
            goto label_1c33fc;
        }
    }
    ctx->pc = 0x1C33E0u;
    // 0x1c33e0: 0x30620004  andi        $v0, $v1, 0x4
    ctx->pc = 0x1c33e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
label_1c33e4:
    // 0x1c33e4: 0x1040005e  beqz        $v0, . + 4 + (0x5E << 2)
    ctx->pc = 0x1C33E4u;
    {
        const bool branch_taken_0x1c33e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c33e4) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C33ECu;
    // 0x1c33ec: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c33ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c33f0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c33f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c33f4: 0x1462005a  bne         $v1, $v0, . + 4 + (0x5A << 2)
    ctx->pc = 0x1C33F4u;
    {
        const bool branch_taken_0x1c33f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c33f4) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C33FCu;
label_1c33fc:
    // 0x1c33fc: 0xc071660  jal         func_1C5980
    ctx->pc = 0x1C33FCu;
    SET_GPR_U32(ctx, 31, 0x1C3404u);
    ctx->pc = 0x1C5980u;
    if (runtime->hasFunction(0x1C5980u)) {
        auto targetFn = runtime->lookupFunction(0x1C5980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3404u; }
        if (ctx->pc != 0x1C3404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5980_0x1c5980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3404u; }
        if (ctx->pc != 0x1C3404u) { return; }
    }
    ctx->pc = 0x1C3404u;
label_1c3404:
    // 0x1c3404: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c3404u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c3408: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c3408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c340c: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1c340cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1c3410: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c3410u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c3414: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x1C3414u;
    {
        const bool branch_taken_0x1c3414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3414u;
            // 0x1c3418: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3414) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C341Cu;
label_1c341c:
    // 0x1c341c: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C341Cu;
    SET_GPR_U32(ctx, 31, 0x1C3424u);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3424u; }
        if (ctx->pc != 0x1C3424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3424u; }
        if (ctx->pc != 0x1C3424u) { return; }
    }
    ctx->pc = 0x1C3424u;
label_1c3424:
    // 0x1c3424: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c3424u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c3428: 0x10430039  beq         $v0, $v1, . + 4 + (0x39 << 2)
    ctx->pc = 0x1C3428u;
    {
        const bool branch_taken_0x1c3428 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c3428) {
            ctx->pc = 0x1C3510u;
            goto label_1c3510;
        }
    }
    ctx->pc = 0x1C3430u;
    // 0x1c3430: 0x2403ff00  addiu       $v1, $zero, -0x100
    ctx->pc = 0x1c3430u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c3434: 0x10430018  beq         $v0, $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1C3434u;
    {
        const bool branch_taken_0x1c3434 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C3438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3434u;
            // 0x1c3438: 0x24030004  addiu       $v1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3434) {
            ctx->pc = 0x1C3498u;
            goto label_1c3498;
        }
    }
    ctx->pc = 0x1C343Cu;
    // 0x1c343c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C343Cu;
    {
        const bool branch_taken_0x1c343c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C343Cu;
            // 0x1c3440: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c343c) {
            ctx->pc = 0x1C344Cu;
            goto label_1c344c;
        }
    }
    ctx->pc = 0x1C3444u;
    // 0x1c3444: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1C3444u;
    {
        const bool branch_taken_0x1c3444 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3444u;
            // 0x1c3448: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3444) {
            ctx->pc = 0x1C34ACu;
            goto label_1c34ac;
        }
    }
    ctx->pc = 0x1C344Cu;
label_1c344c:
    // 0x1c344c: 0xc071570  jal         func_1C55C0
    ctx->pc = 0x1C344Cu;
    SET_GPR_U32(ctx, 31, 0x1C3454u);
    ctx->pc = 0x1C55C0u;
    if (runtime->hasFunction(0x1C55C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C55C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3454u; }
        if (ctx->pc != 0x1C3454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C55C0_0x1c55c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3454u; }
        if (ctx->pc != 0x1C3454u) { return; }
    }
    ctx->pc = 0x1C3454u;
label_1c3454:
    // 0x1c3454: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C3454u;
    {
        const bool branch_taken_0x1c3454 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C3458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3454u;
            // 0x1c3458: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3454) {
            ctx->pc = 0x1C3478u;
            goto label_1c3478;
        }
    }
    ctx->pc = 0x1C345Cu;
    // 0x1c345c: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1c345cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1c3460: 0xc0704a4  jal         func_1C1290
    ctx->pc = 0x1C3460u;
    SET_GPR_U32(ctx, 31, 0x1C3468u);
    ctx->pc = 0x1C3464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3460u;
            // 0x1c3464: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1290u;
    if (runtime->hasFunction(0x1C1290u)) {
        auto targetFn = runtime->lookupFunction(0x1C1290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3468u; }
        if (ctx->pc != 0x1C3468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1290_0x1c1290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3468u; }
        if (ctx->pc != 0x1C3468u) { return; }
    }
    ctx->pc = 0x1C3468u;
label_1c3468:
    // 0x1c3468: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1c3468u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1c346c: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c346cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c3470: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1C3470u;
    {
        const bool branch_taken_0x1c3470 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3470u;
            // 0x1c3474: 0xa2020002  sb          $v0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3470) {
            ctx->pc = 0x1C3510u;
            goto label_1c3510;
        }
    }
    ctx->pc = 0x1C3478u;
label_1c3478:
    // 0x1c3478: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c3478u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c347c: 0xae04002c  sw          $a0, 0x2C($s0)
    ctx->pc = 0x1c347cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x1c3480: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3480u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3484: 0xae030034  sw          $v1, 0x34($s0)
    ctx->pc = 0x1c3484u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 3));
    // 0x1c3488: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c3488u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c348c: 0xae0200e0  sw          $v0, 0xE0($s0)
    ctx->pc = 0x1c348cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 224), GPR_U32(ctx, 2));
    // 0x1c3490: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1C3490u;
    {
        const bool branch_taken_0x1c3490 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3490u;
            // 0x1c3494: 0xa2040002  sb          $a0, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3490) {
            ctx->pc = 0x1C3510u;
            goto label_1c3510;
        }
    }
    ctx->pc = 0x1C3498u;
label_1c3498:
    // 0x1c3498: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3498u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c349c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c349cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c34a0: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c34a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c34a4: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1C34A4u;
    {
        const bool branch_taken_0x1c34a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C34A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C34A4u;
            // 0x1c34a8: 0xae03002c  sw          $v1, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c34a4) {
            ctx->pc = 0x1C3510u;
            goto label_1c3510;
        }
    }
    ctx->pc = 0x1C34ACu;
label_1c34ac:
    // 0x1c34ac: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1c34acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c34b0: 0xa2040002  sb          $a0, 0x2($s0)
    ctx->pc = 0x1c34b0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c34b4: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c34b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c34b8: 0x8e030034  lw          $v1, 0x34($s0)
    ctx->pc = 0x1c34b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c34bc: 0x10640012  beq         $v1, $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C34BCu;
    {
        const bool branch_taken_0x1c34bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1c34bc) {
            ctx->pc = 0x1C3508u;
            goto label_1c3508;
        }
    }
    ctx->pc = 0x1C34C4u;
    // 0x1c34c4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c34c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c34c8: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C34C8u;
    {
        const bool branch_taken_0x1c34c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C34CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C34C8u;
            // 0x1c34cc: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c34c8) {
            ctx->pc = 0x1C3500u;
            goto label_1c3500;
        }
    }
    ctx->pc = 0x1C34D0u;
    // 0x1c34d0: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C34D0u;
    {
        const bool branch_taken_0x1c34d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c34d0) {
            ctx->pc = 0x1C34F4u;
            goto label_1c34f4;
        }
    }
    ctx->pc = 0x1C34D8u;
    // 0x1c34d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c34d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c34dc: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C34DCu;
    {
        const bool branch_taken_0x1c34dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C34E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C34DCu;
            // 0x1c34e0: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c34dc) {
            ctx->pc = 0x1C34ECu;
            goto label_1c34ec;
        }
    }
    ctx->pc = 0x1C34E4u;
    // 0x1c34e4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1C34E4u;
    {
        const bool branch_taken_0x1c34e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c34e4) {
            ctx->pc = 0x1C3510u;
            goto label_1c3510;
        }
    }
    ctx->pc = 0x1C34ECu;
label_1c34ec:
    // 0x1c34ec: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C34ECu;
    {
        const bool branch_taken_0x1c34ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C34F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C34ECu;
            // 0x1c34f0: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c34ec) {
            ctx->pc = 0x1C3510u;
            goto label_1c3510;
        }
    }
    ctx->pc = 0x1C34F4u;
label_1c34f4:
    // 0x1c34f4: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1c34f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1c34f8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C34F8u;
    {
        const bool branch_taken_0x1c34f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C34FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C34F8u;
            // 0x1c34fc: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c34f8) {
            ctx->pc = 0x1C3510u;
            goto label_1c3510;
        }
    }
    ctx->pc = 0x1C3500u;
label_1c3500:
    // 0x1c3500: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3500u;
    {
        const bool branch_taken_0x1c3500 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3500u;
            // 0x1c3504: 0xae04002c  sw          $a0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3500) {
            ctx->pc = 0x1C3510u;
            goto label_1c3510;
        }
    }
    ctx->pc = 0x1C3508u;
label_1c3508:
    // 0x1c3508: 0x24020017  addiu       $v0, $zero, 0x17
    ctx->pc = 0x1c3508u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
    // 0x1c350c: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c350cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
label_1c3510:
    // 0x1c3510: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1c3510u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1c3514: 0x8c224170  lw          $v0, 0x4170($at)
    ctx->pc = 0x1c3514u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x1c3518: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1C3518u;
    {
        const bool branch_taken_0x1c3518 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C351Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3518u;
            // 0x1c351c: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3518) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C3520u;
label_1c3520:
    // 0x1c3520: 0x9602000a  lhu         $v0, 0xA($s0)
    ctx->pc = 0x1c3520u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c3524: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1c3524u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1c3528: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C3528u;
    {
        const bool branch_taken_0x1c3528 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C352Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3528u;
            // 0x1c352c: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3528) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C3530u;
    // 0x1c3530: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C3530u;
    SET_GPR_U32(ctx, 31, 0x1C3538u);
    ctx->pc = 0x1C3534u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3530u;
            // 0x1c3534: 0xa0204476  sb          $zero, 0x4476($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3538u; }
        if (ctx->pc != 0x1C3538u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3538u; }
        if (ctx->pc != 0x1C3538u) { return; }
    }
    ctx->pc = 0x1C3538u;
label_1c3538:
    // 0x1c3538: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C3538u;
    {
        const bool branch_taken_0x1c3538 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C353Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3538u;
            // 0x1c353c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3538) {
            ctx->pc = 0x1C3578u;
            goto label_1c3578;
        }
    }
    ctx->pc = 0x1C3540u;
label_1c3540:
    // 0x1c3540: 0x9602000a  lhu         $v0, 0xA($s0)
    ctx->pc = 0x1c3540u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c3544: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1c3544u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1c3548: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C3548u;
    {
        const bool branch_taken_0x1c3548 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c3548) {
            ctx->pc = 0x1C3560u;
            goto label_1c3560;
        }
    }
    ctx->pc = 0x1C3550u;
    // 0x1c3550: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C3550u;
    SET_GPR_U32(ctx, 31, 0x1C3558u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3558u; }
        if (ctx->pc != 0x1C3558u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3558u; }
        if (ctx->pc != 0x1C3558u) { return; }
    }
    ctx->pc = 0x1C3558u;
label_1c3558:
    // 0x1c3558: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C3558u;
    {
        const bool branch_taken_0x1c3558 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C355Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3558u;
            // 0x1c355c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3558) {
            ctx->pc = 0x1C3578u;
            goto label_1c3578;
        }
    }
    ctx->pc = 0x1C3560u;
label_1c3560:
    // 0x1c3560: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c3560u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c3564:
    // 0x1c3564: 0xc0713c4  jal         func_1C4F10
    ctx->pc = 0x1C3564u;
    SET_GPR_U32(ctx, 31, 0x1C356Cu);
    ctx->pc = 0x1C4F10u;
    if (runtime->hasFunction(0x1C4F10u)) {
        auto targetFn = runtime->lookupFunction(0x1C4F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C356Cu; }
        if (ctx->pc != 0x1C356Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4F10_0x1c4f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C356Cu; }
        if (ctx->pc != 0x1C356Cu) { return; }
    }
    ctx->pc = 0x1C356Cu;
label_1c356c:
    // 0x1c356c: 0xc07146c  jal         func_1C51B0
    ctx->pc = 0x1C356Cu;
    SET_GPR_U32(ctx, 31, 0x1C3574u);
    ctx->pc = 0x1C3570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C356Cu;
            // 0x1c3570: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C51B0u;
    if (runtime->hasFunction(0x1C51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3574u; }
        if (ctx->pc != 0x1C3574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C51B0_0x1c51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3574u; }
        if (ctx->pc != 0x1C3574u) { return; }
    }
    ctx->pc = 0x1C3574u;
label_1c3574:
    // 0x1c3574: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3574u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c3578:
    // 0x1c3578: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c3578u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1c357c:
    // 0x1c357c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c357cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c3580: 0x3e00008  jr          $ra
    ctx->pc = 0x1C3580u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C3584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3580u;
            // 0x1c3584: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C3188u: goto label_1c3188;
            case 0x1C31A4u: goto label_1c31a4;
            case 0x1C31ACu: goto label_1c31ac;
            case 0x1C31F0u: goto label_1c31f0;
            case 0x1C320Cu: goto label_1c320c;
            case 0x1C3228u: goto label_1c3228;
            case 0x1C3244u: goto label_1c3244;
            case 0x1C3274u: goto label_1c3274;
            case 0x1C3290u: goto label_1c3290;
            case 0x1C32D4u: goto label_1c32d4;
            case 0x1C32DCu: goto label_1c32dc;
            case 0x1C32E4u: goto label_1c32e4;
            case 0x1C32E8u: goto label_1c32e8;
            case 0x1C32F0u: goto label_1c32f0;
            case 0x1C3310u: goto label_1c3310;
            case 0x1C3318u: goto label_1c3318;
            case 0x1C332Cu: goto label_1c332c;
            case 0x1C3334u: goto label_1c3334;
            case 0x1C335Cu: goto label_1c335c;
            case 0x1C3374u: goto label_1c3374;
            case 0x1C3390u: goto label_1c3390;
            case 0x1C33A8u: goto label_1c33a8;
            case 0x1C33B0u: goto label_1c33b0;
            case 0x1C33C8u: goto label_1c33c8;
            case 0x1C33E4u: goto label_1c33e4;
            case 0x1C33FCu: goto label_1c33fc;
            case 0x1C3404u: goto label_1c3404;
            case 0x1C341Cu: goto label_1c341c;
            case 0x1C3424u: goto label_1c3424;
            case 0x1C344Cu: goto label_1c344c;
            case 0x1C3454u: goto label_1c3454;
            case 0x1C3468u: goto label_1c3468;
            case 0x1C3478u: goto label_1c3478;
            case 0x1C3498u: goto label_1c3498;
            case 0x1C34ACu: goto label_1c34ac;
            case 0x1C34ECu: goto label_1c34ec;
            case 0x1C34F4u: goto label_1c34f4;
            case 0x1C3500u: goto label_1c3500;
            case 0x1C3508u: goto label_1c3508;
            case 0x1C3510u: goto label_1c3510;
            case 0x1C3520u: goto label_1c3520;
            case 0x1C3538u: goto label_1c3538;
            case 0x1C3540u: goto label_1c3540;
            case 0x1C3558u: goto label_1c3558;
            case 0x1C3560u: goto label_1c3560;
            case 0x1C3564u: goto label_1c3564;
            case 0x1C356Cu: goto label_1c356c;
            case 0x1C3574u: goto label_1c3574;
            case 0x1C3578u: goto label_1c3578;
            case 0x1C357Cu: goto label_1c357c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C3588u;
    // 0x1c3588: 0x0  nop
    ctx->pc = 0x1c3588u;
    // NOP
    // 0x1c358c: 0x0  nop
    ctx->pc = 0x1c358cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
