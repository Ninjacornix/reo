#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A85A0
// Address: 0x1a85a0 - 0x1a8970
void sub_001A85A0_0x1a85a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A85A0_0x1a85a0");
#endif

    switch (ctx->pc) {
        case 0x1a863cu: goto label_1a863c;
        case 0x1a8668u: goto label_1a8668;
        case 0x1a8678u: goto label_1a8678;
        case 0x1a86b0u: goto label_1a86b0;
        case 0x1a86c4u: goto label_1a86c4;
        case 0x1a8700u: goto label_1a8700;
        case 0x1a874cu: goto label_1a874c;
        case 0x1a877cu: goto label_1a877c;
        case 0x1a87c0u: goto label_1a87c0;
        case 0x1a87ecu: goto label_1a87ec;
        case 0x1a8808u: goto label_1a8808;
        case 0x1a881cu: goto label_1a881c;
        case 0x1a8850u: goto label_1a8850;
        case 0x1a8870u: goto label_1a8870;
        case 0x1a8898u: goto label_1a8898;
        case 0x1a88c4u: goto label_1a88c4;
        case 0x1a88f0u: goto label_1a88f0;
        case 0x1a8924u: goto label_1a8924;
        case 0x1a8938u: goto label_1a8938;
        case 0x1a894cu: goto label_1a894c;
        case 0x1a895cu: goto label_1a895c;
        default: break;
    }

    ctx->pc = 0x1a85a0u;

    // 0x1a85a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a85a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a85a4: 0x2405007f  addiu       $a1, $zero, 0x7F
    ctx->pc = 0x1a85a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1a85a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a85a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a85ac: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a85acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a85b0: 0x21e03  sra         $v1, $v0, 24
    ctx->pc = 0x1a85b0u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 2), 24));
    // 0x1a85b4: 0x14650003  bne         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A85B4u;
    {
        const bool branch_taken_0x1a85b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A85B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A85B4u;
            // 0x1a85b8: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a85b4) {
            ctx->pc = 0x1A85C4u;
            goto label_1a85c4;
        }
    }
    ctx->pc = 0x1A85BCu;
    // 0x1a85bc: 0x100000e8  b           . + 4 + (0xE8 << 2)
    ctx->pc = 0x1A85BCu;
    {
        const bool branch_taken_0x1a85bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A85C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A85BCu;
            // 0x1a85c0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a85bc) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A85C4u;
label_1a85c4:
    // 0x1a85c4: 0x14650003  bne         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A85C4u;
    {
        const bool branch_taken_0x1a85c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A85C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A85C4u;
            // 0x1a85c8: 0x306600f0  andi        $a2, $v1, 0xF0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)240);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a85c4) {
            ctx->pc = 0x1A85D4u;
            goto label_1a85d4;
        }
    }
    ctx->pc = 0x1A85CCu;
    // 0x1a85cc: 0x100000e4  b           . + 4 + (0xE4 << 2)
    ctx->pc = 0x1A85CCu;
    {
        const bool branch_taken_0x1a85cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A85D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A85CCu;
            // 0x1a85d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a85cc) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A85D4u;
label_1a85d4:
    // 0x1a85d4: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1a85d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1a85d8: 0x10c500d9  beq         $a2, $a1, . + 4 + (0xD9 << 2)
    ctx->pc = 0x1A85D8u;
    {
        const bool branch_taken_0x1a85d8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A85DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A85D8u;
            // 0x1a85dc: 0x24050060  addiu       $a1, $zero, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a85d8) {
            ctx->pc = 0x1A8940u;
            goto label_1a8940;
        }
    }
    ctx->pc = 0x1A85E0u;
    // 0x1a85e0: 0x10c500d7  beq         $a2, $a1, . + 4 + (0xD7 << 2)
    ctx->pc = 0x1A85E0u;
    {
        const bool branch_taken_0x1a85e0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a85e0) {
            ctx->pc = 0x1A8940u;
            goto label_1a8940;
        }
    }
    ctx->pc = 0x1A85E8u;
    // 0x1a85e8: 0x24050040  addiu       $a1, $zero, 0x40
    ctx->pc = 0x1a85e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1a85ec: 0x10c5008d  beq         $a2, $a1, . + 4 + (0x8D << 2)
    ctx->pc = 0x1A85ECu;
    {
        const bool branch_taken_0x1a85ec = (GPR_U64(ctx, 6) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A85F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A85ECu;
            // 0x1a85f0: 0x2465ffb9  addiu       $a1, $v1, -0x47 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967225));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a85ec) {
            ctx->pc = 0x1A8824u;
            goto label_1a8824;
        }
    }
    ctx->pc = 0x1A85F4u;
    // 0x1a85f4: 0x24050070  addiu       $a1, $zero, 0x70
    ctx->pc = 0x1a85f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 112));
    // 0x1a85f8: 0x10c50035  beq         $a2, $a1, . + 4 + (0x35 << 2)
    ctx->pc = 0x1A85F8u;
    {
        const bool branch_taken_0x1a85f8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A85FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A85F8u;
            // 0x1a85fc: 0x24050038  addiu       $a1, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a85f8) {
            ctx->pc = 0x1A86D0u;
            goto label_1a86d0;
        }
    }
    ctx->pc = 0x1A8600u;
    // 0x1a8600: 0x24050030  addiu       $a1, $zero, 0x30
    ctx->pc = 0x1a8600u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1a8604: 0x10c50031  beq         $a2, $a1, . + 4 + (0x31 << 2)
    ctx->pc = 0x1A8604u;
    {
        const bool branch_taken_0x1a8604 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A8608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8604u;
            // 0x1a8608: 0x24050020  addiu       $a1, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8604) {
            ctx->pc = 0x1A86CCu;
            goto label_1a86cc;
        }
    }
    ctx->pc = 0x1A860Cu;
    // 0x1a860c: 0x10c5000d  beq         $a2, $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x1A860Cu;
    {
        const bool branch_taken_0x1a860c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a860c) {
            ctx->pc = 0x1A8644u;
            goto label_1a8644;
        }
    }
    ctx->pc = 0x1A8614u;
    // 0x1a8614: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A8614u;
    {
        const bool branch_taken_0x1a8614 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8614) {
            ctx->pc = 0x1A8624u;
            goto label_1a8624;
        }
    }
    ctx->pc = 0x1A861Cu;
    // 0x1a861c: 0x100000cd  b           . + 4 + (0xCD << 2)
    ctx->pc = 0x1A861Cu;
    {
        const bool branch_taken_0x1a861c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A861Cu;
            // 0x1a8620: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a861c) {
            ctx->pc = 0x1A8954u;
            goto label_1a8954;
        }
    }
    ctx->pc = 0x1A8624u;
label_1a8624:
    // 0x1a8624: 0x90850004  lbu         $a1, 0x4($a0)
    ctx->pc = 0x1a8624u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a8628: 0x90860005  lbu         $a2, 0x5($a0)
    ctx->pc = 0x1a8628u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x1a862c: 0x94870006  lhu         $a3, 0x6($a0)
    ctx->pc = 0x1a862cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x1a8630: 0x90880008  lbu         $t0, 0x8($a0)
    ctx->pc = 0x1a8630u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a8634: 0xc06a040  jal         func_1A8100
    ctx->pc = 0x1A8634u;
    SET_GPR_U32(ctx, 31, 0x1A863Cu);
    ctx->pc = 0x1A8638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8634u;
            // 0x1a8638: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8100u;
    if (runtime->hasFunction(0x1A8100u)) {
        auto targetFn = runtime->lookupFunction(0x1A8100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A863Cu; }
        if (ctx->pc != 0x1A863Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8100_0x1a8100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A863Cu; }
        if (ctx->pc != 0x1A863Cu) { return; }
    }
    ctx->pc = 0x1A863Cu;
label_1a863c:
    // 0x1a863c: 0x100000c9  b           . + 4 + (0xC9 << 2)
    ctx->pc = 0x1A863Cu;
    {
        const bool branch_taken_0x1a863c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8640u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A863Cu;
            // 0x1a8640: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a863c) {
            ctx->pc = 0x1A8964u;
            goto label_1a8964;
        }
    }
    ctx->pc = 0x1A8644u;
label_1a8644:
    // 0x1a8644: 0x30640008  andi        $a0, $v1, 0x8
    ctx->pc = 0x1a8644u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x1a8648: 0x1080000d  beqz        $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x1A8648u;
    {
        const bool branch_taken_0x1a8648 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A864Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8648u;
            // 0x1a864c: 0x24040022  addiu       $a0, $zero, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8648) {
            ctx->pc = 0x1A8680u;
            goto label_1a8680;
        }
    }
    ctx->pc = 0x1A8650u;
    // 0x1a8650: 0x24040029  addiu       $a0, $zero, 0x29
    ctx->pc = 0x1a8650u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 41));
    // 0x1a8654: 0x14640006  bne         $v1, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8654u;
    {
        const bool branch_taken_0x1a8654 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x1A8658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8654u;
            // 0x1a8658: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8654) {
            ctx->pc = 0x1A8670u;
            goto label_1a8670;
        }
    }
    ctx->pc = 0x1A865Cu;
    // 0x1a865c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a865cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8660: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8660u;
    SET_GPR_U32(ctx, 31, 0x1A8668u);
    ctx->pc = 0x1A8664u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8660u;
            // 0x1a8664: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8668u; }
        if (ctx->pc != 0x1A8668u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8668u; }
        if (ctx->pc != 0x1A8668u) { return; }
    }
    ctx->pc = 0x1A8668u;
label_1a8668:
    // 0x1a8668: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A8668u;
    {
        const bool branch_taken_0x1a8668 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8668) {
            ctx->pc = 0x1A8678u;
            goto label_1a8678;
        }
    }
    ctx->pc = 0x1A8670u;
label_1a8670:
    // 0x1a8670: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8670u;
    SET_GPR_U32(ctx, 31, 0x1A8678u);
    ctx->pc = 0x1A8674u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8670u;
            // 0x1a8674: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8678u; }
        if (ctx->pc != 0x1A8678u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8678u; }
        if (ctx->pc != 0x1A8678u) { return; }
    }
    ctx->pc = 0x1A8678u;
label_1a8678:
    // 0x1a8678: 0x100000b9  b           . + 4 + (0xB9 << 2)
    ctx->pc = 0x1A8678u;
    {
        const bool branch_taken_0x1a8678 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8678) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8680u;
label_1a8680:
    // 0x1a8680: 0x10640008  beq         $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A8680u;
    {
        const bool branch_taken_0x1a8680 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1a8680) {
            ctx->pc = 0x1A86A4u;
            goto label_1a86a4;
        }
    }
    ctx->pc = 0x1A8688u;
    // 0x1a8688: 0x10650007  beq         $v1, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A8688u;
    {
        const bool branch_taken_0x1a8688 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A868Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8688u;
            // 0x1a868c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8688) {
            ctx->pc = 0x1A86A8u;
            goto label_1a86a8;
        }
    }
    ctx->pc = 0x1A8690u;
    // 0x1a8690: 0x24040024  addiu       $a0, $zero, 0x24
    ctx->pc = 0x1a8690u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1a8694: 0x10640003  beq         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A8694u;
    {
        const bool branch_taken_0x1a8694 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1A8698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8694u;
            // 0x1a8698: 0x24040023  addiu       $a0, $zero, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 35));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8694) {
            ctx->pc = 0x1A86A4u;
            goto label_1a86a4;
        }
    }
    ctx->pc = 0x1A869Cu;
    // 0x1a869c: 0x14640006  bne         $v1, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A869Cu;
    {
        const bool branch_taken_0x1a869c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1a869c) {
            ctx->pc = 0x1A86B8u;
            goto label_1a86b8;
        }
    }
    ctx->pc = 0x1A86A4u;
label_1a86a4:
    // 0x1a86a4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a86a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1a86a8:
    // 0x1a86a8: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A86A8u;
    SET_GPR_U32(ctx, 31, 0x1A86B0u);
    ctx->pc = 0x1A86ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A86A8u;
            // 0x1a86ac: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A86B0u; }
        if (ctx->pc != 0x1A86B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A86B0u; }
        if (ctx->pc != 0x1A86B0u) { return; }
    }
    ctx->pc = 0x1A86B0u;
label_1a86b0:
    // 0x1a86b0: 0x100000ab  b           . + 4 + (0xAB << 2)
    ctx->pc = 0x1A86B0u;
    {
        const bool branch_taken_0x1a86b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a86b0) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A86B8u;
label_1a86b8:
    // 0x1a86b8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a86b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a86bc: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A86BCu;
    SET_GPR_U32(ctx, 31, 0x1A86C4u);
    ctx->pc = 0x1A86C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A86BCu;
            // 0x1a86c0: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A86C4u; }
        if (ctx->pc != 0x1A86C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A86C4u; }
        if (ctx->pc != 0x1A86C4u) { return; }
    }
    ctx->pc = 0x1A86C4u;
label_1a86c4:
    // 0x1a86c4: 0x100000a6  b           . + 4 + (0xA6 << 2)
    ctx->pc = 0x1A86C4u;
    {
        const bool branch_taken_0x1a86c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a86c4) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A86CCu;
label_1a86cc:
    // 0x1a86cc: 0x24050038  addiu       $a1, $zero, 0x38
    ctx->pc = 0x1a86ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
label_1a86d0:
    // 0x1a86d0: 0x10650008  beq         $v1, $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1A86D0u;
    {
        const bool branch_taken_0x1a86d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A86D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A86D0u;
            // 0x1a86d4: 0x24050030  addiu       $a1, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a86d0) {
            ctx->pc = 0x1A86F4u;
            goto label_1a86f4;
        }
    }
    ctx->pc = 0x1A86D8u;
    // 0x1a86d8: 0x10650006  beq         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A86D8u;
    {
        const bool branch_taken_0x1a86d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a86d8) {
            ctx->pc = 0x1A86F4u;
            goto label_1a86f4;
        }
    }
    ctx->pc = 0x1A86E0u;
    // 0x1a86e0: 0x24050071  addiu       $a1, $zero, 0x71
    ctx->pc = 0x1a86e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
    // 0x1a86e4: 0x10650003  beq         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A86E4u;
    {
        const bool branch_taken_0x1a86e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A86E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A86E4u;
            // 0x1a86e8: 0x24050073  addiu       $a1, $zero, 0x73 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 115));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a86e4) {
            ctx->pc = 0x1A86F4u;
            goto label_1a86f4;
        }
    }
    ctx->pc = 0x1A86ECu;
    // 0x1a86ec: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A86ECu;
    {
        const bool branch_taken_0x1a86ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a86ec) {
            ctx->pc = 0x1A8708u;
            goto label_1a8708;
        }
    }
    ctx->pc = 0x1A86F4u;
label_1a86f4:
    // 0x1a86f4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a86f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a86f8: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A86F8u;
    SET_GPR_U32(ctx, 31, 0x1A8700u);
    ctx->pc = 0x1A86FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A86F8u;
            // 0x1a86fc: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8700u; }
        if (ctx->pc != 0x1A8700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8700u; }
        if (ctx->pc != 0x1A8700u) { return; }
    }
    ctx->pc = 0x1A8700u;
label_1a8700:
    // 0x1a8700: 0x10000097  b           . + 4 + (0x97 << 2)
    ctx->pc = 0x1A8700u;
    {
        const bool branch_taken_0x1a8700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8700) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8708u;
label_1a8708:
    // 0x1a8708: 0x24050031  addiu       $a1, $zero, 0x31
    ctx->pc = 0x1a8708u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
    // 0x1a870c: 0x1065000c  beq         $v1, $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x1A870Cu;
    {
        const bool branch_taken_0x1a870c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A8710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A870Cu;
            // 0x1a8710: 0x24050037  addiu       $a1, $zero, 0x37 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a870c) {
            ctx->pc = 0x1A8740u;
            goto label_1a8740;
        }
    }
    ctx->pc = 0x1A8714u;
    // 0x1a8714: 0x1065000a  beq         $v1, $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x1A8714u;
    {
        const bool branch_taken_0x1a8714 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a8714) {
            ctx->pc = 0x1A8740u;
            goto label_1a8740;
        }
    }
    ctx->pc = 0x1A871Cu;
    // 0x1a871c: 0x2465ffc7  addiu       $a1, $v1, -0x39
    ctx->pc = 0x1a871cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967239));
    // 0x1a8720: 0x2ca10003  sltiu       $at, $a1, 0x3
    ctx->pc = 0x1a8720u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x1a8724: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8724u;
    {
        const bool branch_taken_0x1a8724 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A8728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8724u;
            // 0x1a8728: 0x24050072  addiu       $a1, $zero, 0x72 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 114));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8724) {
            ctx->pc = 0x1A8740u;
            goto label_1a8740;
        }
    }
    ctx->pc = 0x1A872Cu;
    // 0x1a872c: 0x10650004  beq         $v1, $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A872Cu;
    {
        const bool branch_taken_0x1a872c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a872c) {
            ctx->pc = 0x1A8740u;
            goto label_1a8740;
        }
    }
    ctx->pc = 0x1A8734u;
    // 0x1a8734: 0x24050075  addiu       $a1, $zero, 0x75
    ctx->pc = 0x1a8734u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 117));
    // 0x1a8738: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8738u;
    {
        const bool branch_taken_0x1a8738 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A873Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8738u;
            // 0x1a873c: 0x2405003d  addiu       $a1, $zero, 0x3D (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 61));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8738) {
            ctx->pc = 0x1A8754u;
            goto label_1a8754;
        }
    }
    ctx->pc = 0x1A8740u;
label_1a8740:
    // 0x1a8740: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a8740u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8744: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8744u;
    SET_GPR_U32(ctx, 31, 0x1A874Cu);
    ctx->pc = 0x1A8748u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8744u;
            // 0x1a8748: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A874Cu; }
        if (ctx->pc != 0x1A874Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A874Cu; }
        if (ctx->pc != 0x1A874Cu) { return; }
    }
    ctx->pc = 0x1A874Cu;
label_1a874c:
    // 0x1a874c: 0x10000084  b           . + 4 + (0x84 << 2)
    ctx->pc = 0x1A874Cu;
    {
        const bool branch_taken_0x1a874c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a874c) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8754u;
label_1a8754:
    // 0x1a8754: 0x10650006  beq         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8754u;
    {
        const bool branch_taken_0x1a8754 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a8754) {
            ctx->pc = 0x1A8770u;
            goto label_1a8770;
        }
    }
    ctx->pc = 0x1A875Cu;
    // 0x1a875c: 0x24050036  addiu       $a1, $zero, 0x36
    ctx->pc = 0x1a875cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x1a8760: 0x10650003  beq         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A8760u;
    {
        const bool branch_taken_0x1a8760 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A8764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8760u;
            // 0x1a8764: 0x24050074  addiu       $a1, $zero, 0x74 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 116));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8760) {
            ctx->pc = 0x1A8770u;
            goto label_1a8770;
        }
    }
    ctx->pc = 0x1A8768u;
    // 0x1a8768: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8768u;
    {
        const bool branch_taken_0x1a8768 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a8768) {
            ctx->pc = 0x1A8784u;
            goto label_1a8784;
        }
    }
    ctx->pc = 0x1A8770u;
label_1a8770:
    // 0x1a8770: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a8770u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8774: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8774u;
    SET_GPR_U32(ctx, 31, 0x1A877Cu);
    ctx->pc = 0x1A8778u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8774u;
            // 0x1a8778: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A877Cu; }
        if (ctx->pc != 0x1A877Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A877Cu; }
        if (ctx->pc != 0x1A877Cu) { return; }
    }
    ctx->pc = 0x1A877Cu;
label_1a877c:
    // 0x1a877c: 0x10000078  b           . + 4 + (0x78 << 2)
    ctx->pc = 0x1A877Cu;
    {
        const bool branch_taken_0x1a877c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a877c) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8784u;
label_1a8784:
    // 0x1a8784: 0x24050077  addiu       $a1, $zero, 0x77
    ctx->pc = 0x1a8784u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 119));
    // 0x1a8788: 0x10650006  beq         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8788u;
    {
        const bool branch_taken_0x1a8788 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A878Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8788u;
            // 0x1a878c: 0x2405003c  addiu       $a1, $zero, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8788) {
            ctx->pc = 0x1A87A4u;
            goto label_1a87a4;
        }
    }
    ctx->pc = 0x1A8790u;
    // 0x1a8790: 0x10650004  beq         $v1, $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A8790u;
    {
        const bool branch_taken_0x1a8790 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a8790) {
            ctx->pc = 0x1A87A4u;
            goto label_1a87a4;
        }
    }
    ctx->pc = 0x1A8798u;
    // 0x1a8798: 0x2405003e  addiu       $a1, $zero, 0x3E
    ctx->pc = 0x1a8798u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
    // 0x1a879c: 0x1465000a  bne         $v1, $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x1A879Cu;
    {
        const bool branch_taken_0x1a879c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A87A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A879Cu;
            // 0x1a87a0: 0x2405003f  addiu       $a1, $zero, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a879c) {
            ctx->pc = 0x1A87C8u;
            goto label_1a87c8;
        }
    }
    ctx->pc = 0x1A87A4u;
label_1a87a4:
    // 0x1a87a4: 0x90860004  lbu         $a2, 0x4($a0)
    ctx->pc = 0x1a87a4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a87a8: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1a87a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a87ac: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1a87acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a87b0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1a87b0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a87b4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1a87b4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a87b8: 0xc06a0ac  jal         func_1A82B0
    ctx->pc = 0x1A87B8u;
    SET_GPR_U32(ctx, 31, 0x1A87C0u);
    ctx->pc = 0x1A87BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A87B8u;
            // 0x1a87bc: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A82B0u;
    if (runtime->hasFunction(0x1A82B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A82B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A87C0u; }
        if (ctx->pc != 0x1A87C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A82B0_0x1a82b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A87C0u; }
        if (ctx->pc != 0x1A87C0u) { return; }
    }
    ctx->pc = 0x1A87C0u;
label_1a87c0:
    // 0x1a87c0: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x1A87C0u;
    {
        const bool branch_taken_0x1a87c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a87c0) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A87C8u;
label_1a87c8:
    // 0x1a87c8: 0x1465000a  bne         $v1, $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x1A87C8u;
    {
        const bool branch_taken_0x1a87c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a87c8) {
            ctx->pc = 0x1A87F4u;
            goto label_1a87f4;
        }
    }
    ctx->pc = 0x1A87D0u;
    // 0x1a87d0: 0x90860004  lbu         $a2, 0x4($a0)
    ctx->pc = 0x1a87d0u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a87d4: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x1a87d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1a87d8: 0x90870005  lbu         $a3, 0x5($a0)
    ctx->pc = 0x1a87d8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x1a87dc: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1a87dcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a87e0: 0x90880006  lbu         $t0, 0x6($a0)
    ctx->pc = 0x1a87e0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x1a87e4: 0xc06a0ac  jal         func_1A82B0
    ctx->pc = 0x1A87E4u;
    SET_GPR_U32(ctx, 31, 0x1A87ECu);
    ctx->pc = 0x1A87E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A87E4u;
            // 0x1a87e8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A82B0u;
    if (runtime->hasFunction(0x1A82B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A82B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A87ECu; }
        if (ctx->pc != 0x1A87ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A82B0_0x1a82b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A87ECu; }
        if (ctx->pc != 0x1A87ECu) { return; }
    }
    ctx->pc = 0x1A87ECu;
label_1a87ec:
    // 0x1a87ec: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x1A87ECu;
    {
        const bool branch_taken_0x1a87ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a87ec) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A87F4u;
label_1a87f4:
    // 0x1a87f4: 0x24050035  addiu       $a1, $zero, 0x35
    ctx->pc = 0x1a87f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
    // 0x1a87f8: 0x14650005  bne         $v1, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A87F8u;
    {
        const bool branch_taken_0x1a87f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a87f8) {
            ctx->pc = 0x1A8810u;
            goto label_1a8810;
        }
    }
    ctx->pc = 0x1A8800u;
    // 0x1a8800: 0xc06a078  jal         func_1A81E0
    ctx->pc = 0x1A8800u;
    SET_GPR_U32(ctx, 31, 0x1A8808u);
    ctx->pc = 0x1A81E0u;
    if (runtime->hasFunction(0x1A81E0u)) {
        auto targetFn = runtime->lookupFunction(0x1A81E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8808u; }
        if (ctx->pc != 0x1A8808u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A81E0_0x1a81e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8808u; }
        if (ctx->pc != 0x1A8808u) { return; }
    }
    ctx->pc = 0x1A8808u;
label_1a8808:
    // 0x1a8808: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A8808u;
    {
        const bool branch_taken_0x1a8808 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8808) {
            ctx->pc = 0x1A881Cu;
            goto label_1a881c;
        }
    }
    ctx->pc = 0x1A8810u;
label_1a8810:
    // 0x1a8810: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a8810u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8814: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8814u;
    SET_GPR_U32(ctx, 31, 0x1A881Cu);
    ctx->pc = 0x1A8818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8814u;
            // 0x1a8818: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A881Cu; }
        if (ctx->pc != 0x1A881Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A881Cu; }
        if (ctx->pc != 0x1A881Cu) { return; }
    }
    ctx->pc = 0x1A881Cu;
label_1a881c:
    // 0x1a881c: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1A881Cu;
    {
        const bool branch_taken_0x1a881c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a881c) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8824u;
label_1a8824:
    // 0x1a8824: 0x2ca10004  sltiu       $at, $a1, 0x4
    ctx->pc = 0x1a8824u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x1a8828: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8828u;
    {
        const bool branch_taken_0x1a8828 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a8828) {
            ctx->pc = 0x1A8844u;
            goto label_1a8844;
        }
    }
    ctx->pc = 0x1A8830u;
    // 0x1a8830: 0x24050041  addiu       $a1, $zero, 0x41
    ctx->pc = 0x1a8830u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x1a8834: 0x10650003  beq         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A8834u;
    {
        const bool branch_taken_0x1a8834 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A8838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8834u;
            // 0x1a8838: 0x24050042  addiu       $a1, $zero, 0x42 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 66));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8834) {
            ctx->pc = 0x1A8844u;
            goto label_1a8844;
        }
    }
    ctx->pc = 0x1A883Cu;
    // 0x1a883c: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A883Cu;
    {
        const bool branch_taken_0x1a883c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a883c) {
            ctx->pc = 0x1A8858u;
            goto label_1a8858;
        }
    }
    ctx->pc = 0x1A8844u;
label_1a8844:
    // 0x1a8844: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a8844u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8848: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8848u;
    SET_GPR_U32(ctx, 31, 0x1A8850u);
    ctx->pc = 0x1A884Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8848u;
            // 0x1a884c: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8850u; }
        if (ctx->pc != 0x1A8850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8850u; }
        if (ctx->pc != 0x1A8850u) { return; }
    }
    ctx->pc = 0x1A8850u;
label_1a8850:
    // 0x1a8850: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x1A8850u;
    {
        const bool branch_taken_0x1a8850 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8850) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8858u;
label_1a8858:
    // 0x1a8858: 0x2405004b  addiu       $a1, $zero, 0x4B
    ctx->pc = 0x1a8858u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 75));
    // 0x1a885c: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A885Cu;
    {
        const bool branch_taken_0x1a885c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A8860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A885Cu;
            // 0x1a8860: 0x24050045  addiu       $a1, $zero, 0x45 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a885c) {
            ctx->pc = 0x1A8878u;
            goto label_1a8878;
        }
    }
    ctx->pc = 0x1A8864u;
    // 0x1a8864: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a8864u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8868: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8868u;
    SET_GPR_U32(ctx, 31, 0x1A8870u);
    ctx->pc = 0x1A886Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8868u;
            // 0x1a886c: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8870u; }
        if (ctx->pc != 0x1A8870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8870u; }
        if (ctx->pc != 0x1A8870u) { return; }
    }
    ctx->pc = 0x1A8870u;
label_1a8870:
    // 0x1a8870: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1A8870u;
    {
        const bool branch_taken_0x1a8870 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8870) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8878u;
label_1a8878:
    // 0x1a8878: 0x10650004  beq         $v1, $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A8878u;
    {
        const bool branch_taken_0x1a8878 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a8878) {
            ctx->pc = 0x1A888Cu;
            goto label_1a888c;
        }
    }
    ctx->pc = 0x1A8880u;
    // 0x1a8880: 0x2405004c  addiu       $a1, $zero, 0x4C
    ctx->pc = 0x1a8880u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 76));
    // 0x1a8884: 0x14650006  bne         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A8884u;
    {
        const bool branch_taken_0x1a8884 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A8888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8884u;
            // 0x1a8888: 0x24050044  addiu       $a1, $zero, 0x44 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8884) {
            ctx->pc = 0x1A88A0u;
            goto label_1a88a0;
        }
    }
    ctx->pc = 0x1A888Cu;
label_1a888c:
    // 0x1a888c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a888cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8890: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8890u;
    SET_GPR_U32(ctx, 31, 0x1A8898u);
    ctx->pc = 0x1A8894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8890u;
            // 0x1a8894: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8898u; }
        if (ctx->pc != 0x1A8898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8898u; }
        if (ctx->pc != 0x1A8898u) { return; }
    }
    ctx->pc = 0x1A8898u;
label_1a8898:
    // 0x1a8898: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1A8898u;
    {
        const bool branch_taken_0x1a8898 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8898) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A88A0u;
label_1a88a0:
    // 0x1a88a0: 0x1465000a  bne         $v1, $a1, . + 4 + (0xA << 2)
    ctx->pc = 0x1A88A0u;
    {
        const bool branch_taken_0x1a88a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a88a0) {
            ctx->pc = 0x1A88CCu;
            goto label_1a88cc;
        }
    }
    ctx->pc = 0x1A88A8u;
    // 0x1a88a8: 0x90860004  lbu         $a2, 0x4($a0)
    ctx->pc = 0x1a88a8u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a88ac: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1a88acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1a88b0: 0x90870005  lbu         $a3, 0x5($a0)
    ctx->pc = 0x1a88b0u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x1a88b4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1a88b4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a88b8: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1a88b8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a88bc: 0xc06a0ac  jal         func_1A82B0
    ctx->pc = 0x1A88BCu;
    SET_GPR_U32(ctx, 31, 0x1A88C4u);
    ctx->pc = 0x1A88C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A88BCu;
            // 0x1a88c0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A82B0u;
    if (runtime->hasFunction(0x1A82B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A82B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A88C4u; }
        if (ctx->pc != 0x1A88C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A82B0_0x1a82b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A88C4u; }
        if (ctx->pc != 0x1A88C4u) { return; }
    }
    ctx->pc = 0x1A88C4u;
label_1a88c4:
    // 0x1a88c4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1A88C4u;
    {
        const bool branch_taken_0x1a88c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a88c4) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A88CCu;
label_1a88cc:
    // 0x1a88cc: 0x2405004d  addiu       $a1, $zero, 0x4D
    ctx->pc = 0x1a88ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 77));
    // 0x1a88d0: 0x10650003  beq         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A88D0u;
    {
        const bool branch_taken_0x1a88d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1A88D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A88D0u;
            // 0x1a88d4: 0x2405004e  addiu       $a1, $zero, 0x4E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 78));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a88d0) {
            ctx->pc = 0x1A88E0u;
            goto label_1a88e0;
        }
    }
    ctx->pc = 0x1A88D8u;
    // 0x1a88d8: 0x14650007  bne         $v1, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A88D8u;
    {
        const bool branch_taken_0x1a88d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a88d8) {
            ctx->pc = 0x1A88F8u;
            goto label_1a88f8;
        }
    }
    ctx->pc = 0x1A88E0u;
label_1a88e0:
    // 0x1a88e0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a88e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a88e4: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1a88e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a88e8: 0xc06a140  jal         func_1A8500
    ctx->pc = 0x1A88E8u;
    SET_GPR_U32(ctx, 31, 0x1A88F0u);
    ctx->pc = 0x1A88ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A88E8u;
            // 0x1a88ec: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8500u;
    if (runtime->hasFunction(0x1A8500u)) {
        auto targetFn = runtime->lookupFunction(0x1A8500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A88F0u; }
        if (ctx->pc != 0x1A88F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8500_0x1a8500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A88F0u; }
        if (ctx->pc != 0x1A88F0u) { return; }
    }
    ctx->pc = 0x1A88F0u;
label_1a88f0:
    // 0x1a88f0: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1A88F0u;
    {
        const bool branch_taken_0x1a88f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a88f0) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A88F8u;
label_1a88f8:
    // 0x1a88f8: 0x2405004f  addiu       $a1, $zero, 0x4F
    ctx->pc = 0x1a88f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 79));
    // 0x1a88fc: 0x1465000b  bne         $v1, $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x1A88FCu;
    {
        const bool branch_taken_0x1a88fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1a88fc) {
            ctx->pc = 0x1A892Cu;
            goto label_1a892c;
        }
    }
    ctx->pc = 0x1A8904u;
    // 0x1a8904: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1a8904u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1a8908: 0x21a03  sra         $v1, $v0, 8
    ctx->pc = 0x1a8908u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1a890c: 0x306600ff  andi        $a2, $v1, 0xFF
    ctx->pc = 0x1a890cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1a8910: 0x304700ff  andi        $a3, $v0, 0xFF
    ctx->pc = 0x1a8910u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1a8914: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1a8914u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1a8918: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1a8918u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a891c: 0xc06a0ac  jal         func_1A82B0
    ctx->pc = 0x1A891Cu;
    SET_GPR_U32(ctx, 31, 0x1A8924u);
    ctx->pc = 0x1A8920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A891Cu;
            // 0x1a8920: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A82B0u;
    if (runtime->hasFunction(0x1A82B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A82B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8924u; }
        if (ctx->pc != 0x1A8924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A82B0_0x1a82b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8924u; }
        if (ctx->pc != 0x1A8924u) { return; }
    }
    ctx->pc = 0x1A8924u;
label_1a8924:
    // 0x1a8924: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A8924u;
    {
        const bool branch_taken_0x1a8924 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8924) {
            ctx->pc = 0x1A8938u;
            goto label_1a8938;
        }
    }
    ctx->pc = 0x1A892Cu;
label_1a892c:
    // 0x1a892c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a892cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8930: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8930u;
    SET_GPR_U32(ctx, 31, 0x1A8938u);
    ctx->pc = 0x1A8934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8930u;
            // 0x1a8934: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8938u; }
        if (ctx->pc != 0x1A8938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8938u; }
        if (ctx->pc != 0x1A8938u) { return; }
    }
    ctx->pc = 0x1A8938u;
label_1a8938:
    // 0x1a8938: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A8938u;
    {
        const bool branch_taken_0x1a8938 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a8938) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8940u;
label_1a8940:
    // 0x1a8940: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a8940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a8944: 0xc06a114  jal         func_1A8450
    ctx->pc = 0x1A8944u;
    SET_GPR_U32(ctx, 31, 0x1A894Cu);
    ctx->pc = 0x1A8948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8944u;
            // 0x1a8948: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A8450u;
    if (runtime->hasFunction(0x1A8450u)) {
        auto targetFn = runtime->lookupFunction(0x1A8450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A894Cu; }
        if (ctx->pc != 0x1A894Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A8450_0x1a8450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A894Cu; }
        if (ctx->pc != 0x1A894Cu) { return; }
    }
    ctx->pc = 0x1A894Cu;
label_1a894c:
    // 0x1a894c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A894Cu;
    {
        const bool branch_taken_0x1a894c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a894c) {
            ctx->pc = 0x1A8960u;
            goto label_1a8960;
        }
    }
    ctx->pc = 0x1A8954u;
label_1a8954:
    // 0x1a8954: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A8954u;
    SET_GPR_U32(ctx, 31, 0x1A895Cu);
    ctx->pc = 0x1A8958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8954u;
            // 0x1a8958: 0x24842550  addiu       $a0, $a0, 0x2550 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9552));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A895Cu; }
        if (ctx->pc != 0x1A895Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A895Cu; }
        if (ctx->pc != 0x1A895Cu) { return; }
    }
    ctx->pc = 0x1A895Cu;
label_1a895c:
    // 0x1a895c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1a895cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1a8960:
    // 0x1a8960: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a8960u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a8964:
    // 0x1a8964: 0x3e00008  jr          $ra
    ctx->pc = 0x1A8964u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A8968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8964u;
            // 0x1a8968: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A85C4u: goto label_1a85c4;
            case 0x1A85D4u: goto label_1a85d4;
            case 0x1A8624u: goto label_1a8624;
            case 0x1A863Cu: goto label_1a863c;
            case 0x1A8644u: goto label_1a8644;
            case 0x1A8668u: goto label_1a8668;
            case 0x1A8670u: goto label_1a8670;
            case 0x1A8678u: goto label_1a8678;
            case 0x1A8680u: goto label_1a8680;
            case 0x1A86A4u: goto label_1a86a4;
            case 0x1A86A8u: goto label_1a86a8;
            case 0x1A86B0u: goto label_1a86b0;
            case 0x1A86B8u: goto label_1a86b8;
            case 0x1A86C4u: goto label_1a86c4;
            case 0x1A86CCu: goto label_1a86cc;
            case 0x1A86D0u: goto label_1a86d0;
            case 0x1A86F4u: goto label_1a86f4;
            case 0x1A8700u: goto label_1a8700;
            case 0x1A8708u: goto label_1a8708;
            case 0x1A8740u: goto label_1a8740;
            case 0x1A874Cu: goto label_1a874c;
            case 0x1A8754u: goto label_1a8754;
            case 0x1A8770u: goto label_1a8770;
            case 0x1A877Cu: goto label_1a877c;
            case 0x1A8784u: goto label_1a8784;
            case 0x1A87A4u: goto label_1a87a4;
            case 0x1A87C0u: goto label_1a87c0;
            case 0x1A87C8u: goto label_1a87c8;
            case 0x1A87ECu: goto label_1a87ec;
            case 0x1A87F4u: goto label_1a87f4;
            case 0x1A8808u: goto label_1a8808;
            case 0x1A8810u: goto label_1a8810;
            case 0x1A881Cu: goto label_1a881c;
            case 0x1A8824u: goto label_1a8824;
            case 0x1A8844u: goto label_1a8844;
            case 0x1A8850u: goto label_1a8850;
            case 0x1A8858u: goto label_1a8858;
            case 0x1A8870u: goto label_1a8870;
            case 0x1A8878u: goto label_1a8878;
            case 0x1A888Cu: goto label_1a888c;
            case 0x1A8898u: goto label_1a8898;
            case 0x1A88A0u: goto label_1a88a0;
            case 0x1A88C4u: goto label_1a88c4;
            case 0x1A88CCu: goto label_1a88cc;
            case 0x1A88E0u: goto label_1a88e0;
            case 0x1A88F0u: goto label_1a88f0;
            case 0x1A88F8u: goto label_1a88f8;
            case 0x1A8924u: goto label_1a8924;
            case 0x1A892Cu: goto label_1a892c;
            case 0x1A8938u: goto label_1a8938;
            case 0x1A8940u: goto label_1a8940;
            case 0x1A894Cu: goto label_1a894c;
            case 0x1A8954u: goto label_1a8954;
            case 0x1A895Cu: goto label_1a895c;
            case 0x1A8960u: goto label_1a8960;
            case 0x1A8964u: goto label_1a8964;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A896Cu;
    // 0x1a896c: 0x0  nop
    ctx->pc = 0x1a896cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
