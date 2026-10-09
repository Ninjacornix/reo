#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB050
// Address: 0x1ab050 - 0x1ab2d0
void sub_001AB050_0x1ab050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB050_0x1ab050");
#endif

    switch (ctx->pc) {
        case 0x1ab07cu: goto label_1ab07c;
        case 0x1ab084u: goto label_1ab084;
        case 0x1ab090u: goto label_1ab090;
        case 0x1ab0c0u: goto label_1ab0c0;
        case 0x1ab1c8u: goto label_1ab1c8;
        case 0x1ab1e4u: goto label_1ab1e4;
        case 0x1ab240u: goto label_1ab240;
        case 0x1ab24cu: goto label_1ab24c;
        case 0x1ab254u: goto label_1ab254;
        case 0x1ab28cu: goto label_1ab28c;
        default: break;
    }

    ctx->pc = 0x1ab050u;

    // 0x1ab050: 0x27bdfcb0  addiu       $sp, $sp, -0x350
    ctx->pc = 0x1ab050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966448));
    // 0x1ab054: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1ab054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1ab058: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ab058u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ab05c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ab05cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ab060: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ab060u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ab064: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1ab064u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab068: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1ab068u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab06c: 0x27a40250  addiu       $a0, $sp, 0x250
    ctx->pc = 0x1ab06cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 592));
    // 0x1ab070: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1ab070u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab074: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1AB074u;
    SET_GPR_U32(ctx, 31, 0x1AB07Cu);
    ctx->pc = 0x1AB078u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB074u;
            // 0x1ab078: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB07Cu; }
        if (ctx->pc != 0x1AB07Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB07Cu; }
        if (ctx->pc != 0x1AB07Cu) { return; }
    }
    ctx->pc = 0x1AB07Cu;
label_1ab07c:
    // 0x1ab07c: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x1AB07Cu;
    SET_GPR_U32(ctx, 31, 0x1AB084u);
    ctx->pc = 0x1AB080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB07Cu;
            // 0x1ab080: 0x27a40250  addiu       $a0, $sp, 0x250 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB084u; }
        if (ctx->pc != 0x1AB084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB084u; }
        if (ctx->pc != 0x1AB084u) { return; }
    }
    ctx->pc = 0x1AB084u;
label_1ab084:
    // 0x1ab084: 0x27b00250  addiu       $s0, $sp, 0x250
    ctx->pc = 0x1ab084u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 592));
    // 0x1ab088: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1AB088u;
    SET_GPR_U32(ctx, 31, 0x1AB090u);
    ctx->pc = 0x1AB08Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB088u;
            // 0x1ab08c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB090u; }
        if (ctx->pc != 0x1AB090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB090u; }
        if (ctx->pc != 0x1AB090u) { return; }
    }
    ctx->pc = 0x1AB090u;
label_1ab090:
    // 0x1ab090: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ab090u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab094: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1ab094u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab098: 0x240e005c  addiu       $t6, $zero, 0x5C
    ctx->pc = 0x1ab098u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x1ab09c: 0x240d002f  addiu       $t5, $zero, 0x2F
    ctx->pc = 0x1ab09cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1ab0a0: 0x2403004d  addiu       $v1, $zero, 0x4D
    ctx->pc = 0x1ab0a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 77));
    // 0x1ab0a4: 0x2404004f  addiu       $a0, $zero, 0x4F
    ctx->pc = 0x1ab0a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 79));
    // 0x1ab0a8: 0x24050052  addiu       $a1, $zero, 0x52
    ctx->pc = 0x1ab0a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 82));
    // 0x1ab0ac: 0x240b0054  addiu       $t3, $zero, 0x54
    ctx->pc = 0x1ab0acu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 84));
    // 0x1ab0b0: 0x240c0044  addiu       $t4, $zero, 0x44
    ctx->pc = 0x1ab0b0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
    // 0x1ab0b4: 0x24090049  addiu       $t1, $zero, 0x49
    ctx->pc = 0x1ab0b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 73));
    // 0x1ab0b8: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1AB0B8u;
    {
        const bool branch_taken_0x1ab0b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB0BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB0B8u;
            // 0x1ab0bc: 0x240a0045  addiu       $t2, $zero, 0x45 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab0b8) {
            ctx->pc = 0x1AB1A4u;
            goto label_1ab1a4;
        }
    }
    ctx->pc = 0x1AB0C0u;
label_1ab0c0:
    // 0x1ab0c0: 0xf7e3f  dsra32      $t7, $t7, 24
    ctx->pc = 0x1ab0c0u;
    SET_GPR_S64(ctx, 15, GPR_S64(ctx, 15) >> (32 + 24));
    // 0x1ab0c4: 0x15e5000f  bne         $t7, $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x1AB0C4u;
    {
        const bool branch_taken_0x1ab0c4 = (GPR_U64(ctx, 15) != GPR_U64(ctx, 5));
        if (branch_taken_0x1ab0c4) {
            ctx->pc = 0x1AB104u;
            goto label_1ab104;
        }
    }
    ctx->pc = 0x1AB0CCu;
    // 0x1ab0cc: 0x82080001  lb          $t0, 0x1($s0)
    ctx->pc = 0x1ab0ccu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1ab0d0: 0x1504000c  bne         $t0, $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x1AB0D0u;
    {
        const bool branch_taken_0x1ab0d0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 4));
        if (branch_taken_0x1ab0d0) {
            ctx->pc = 0x1AB104u;
            goto label_1ab104;
        }
    }
    ctx->pc = 0x1AB0D8u;
    // 0x1ab0d8: 0x82080002  lb          $t0, 0x2($s0)
    ctx->pc = 0x1ab0d8u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1ab0dc: 0x15030009  bne         $t0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AB0DCu;
    {
        const bool branch_taken_0x1ab0dc = (GPR_U64(ctx, 8) != GPR_U64(ctx, 3));
        if (branch_taken_0x1ab0dc) {
            ctx->pc = 0x1AB104u;
            goto label_1ab104;
        }
    }
    ctx->pc = 0x1AB0E4u;
    // 0x1ab0e4: 0x82080003  lb          $t0, 0x3($s0)
    ctx->pc = 0x1ab0e4u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1ab0e8: 0x110e0003  beq         $t0, $t6, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB0E8u;
    {
        const bool branch_taken_0x1ab0e8 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 14));
        if (branch_taken_0x1ab0e8) {
            ctx->pc = 0x1AB0F8u;
            goto label_1ab0f8;
        }
    }
    ctx->pc = 0x1AB0F0u;
    // 0x1ab0f0: 0x150d0004  bne         $t0, $t5, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AB0F0u;
    {
        const bool branch_taken_0x1ab0f0 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 13));
        if (branch_taken_0x1ab0f0) {
            ctx->pc = 0x1AB104u;
            goto label_1ab104;
        }
    }
    ctx->pc = 0x1AB0F8u;
label_1ab0f8:
    // 0x1ab0f8: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1ab0f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ab0fc: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1AB0FCu;
    {
        const bool branch_taken_0x1ab0fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB0FCu;
            // 0x1ab100: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab0fc) {
            ctx->pc = 0x1AB1B0u;
            goto label_1ab1b0;
        }
    }
    ctx->pc = 0x1AB104u;
label_1ab104:
    // 0x1ab104: 0x15e5000f  bne         $t7, $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x1AB104u;
    {
        const bool branch_taken_0x1ab104 = (GPR_U64(ctx, 15) != GPR_U64(ctx, 5));
        if (branch_taken_0x1ab104) {
            ctx->pc = 0x1AB144u;
            goto label_1ab144;
        }
    }
    ctx->pc = 0x1AB10Cu;
    // 0x1ab10c: 0x82080001  lb          $t0, 0x1($s0)
    ctx->pc = 0x1ab10cu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1ab110: 0x150c000c  bne         $t0, $t4, . + 4 + (0xC << 2)
    ctx->pc = 0x1AB110u;
    {
        const bool branch_taken_0x1ab110 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 12));
        if (branch_taken_0x1ab110) {
            ctx->pc = 0x1AB144u;
            goto label_1ab144;
        }
    }
    ctx->pc = 0x1AB118u;
    // 0x1ab118: 0x82080002  lb          $t0, 0x2($s0)
    ctx->pc = 0x1ab118u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1ab11c: 0x150b0009  bne         $t0, $t3, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AB11Cu;
    {
        const bool branch_taken_0x1ab11c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 11));
        if (branch_taken_0x1ab11c) {
            ctx->pc = 0x1AB144u;
            goto label_1ab144;
        }
    }
    ctx->pc = 0x1AB124u;
    // 0x1ab124: 0x82080003  lb          $t0, 0x3($s0)
    ctx->pc = 0x1ab124u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1ab128: 0x110e0003  beq         $t0, $t6, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB128u;
    {
        const bool branch_taken_0x1ab128 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 14));
        if (branch_taken_0x1ab128) {
            ctx->pc = 0x1AB138u;
            goto label_1ab138;
        }
    }
    ctx->pc = 0x1AB130u;
    // 0x1ab130: 0x150d0004  bne         $t0, $t5, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AB130u;
    {
        const bool branch_taken_0x1ab130 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 13));
        if (branch_taken_0x1ab130) {
            ctx->pc = 0x1AB144u;
            goto label_1ab144;
        }
    }
    ctx->pc = 0x1AB138u;
label_1ab138:
    // 0x1ab138: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1ab138u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ab13c: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1AB13Cu;
    {
        const bool branch_taken_0x1ab13c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB13Cu;
            // 0x1ab140: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab13c) {
            ctx->pc = 0x1AB1B0u;
            goto label_1ab1b0;
        }
    }
    ctx->pc = 0x1AB144u;
label_1ab144:
    // 0x1ab144: 0x15ea0012  bne         $t7, $t2, . + 4 + (0x12 << 2)
    ctx->pc = 0x1AB144u;
    {
        const bool branch_taken_0x1ab144 = (GPR_U64(ctx, 15) != GPR_U64(ctx, 10));
        if (branch_taken_0x1ab144) {
            ctx->pc = 0x1AB190u;
            goto label_1ab190;
        }
    }
    ctx->pc = 0x1AB14Cu;
    // 0x1ab14c: 0x82080001  lb          $t0, 0x1($s0)
    ctx->pc = 0x1ab14cu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1ab150: 0x150c000f  bne         $t0, $t4, . + 4 + (0xF << 2)
    ctx->pc = 0x1AB150u;
    {
        const bool branch_taken_0x1ab150 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 12));
        if (branch_taken_0x1ab150) {
            ctx->pc = 0x1AB190u;
            goto label_1ab190;
        }
    }
    ctx->pc = 0x1AB158u;
    // 0x1ab158: 0x82080002  lb          $t0, 0x2($s0)
    ctx->pc = 0x1ab158u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1ab15c: 0x1509000c  bne         $t0, $t1, . + 4 + (0xC << 2)
    ctx->pc = 0x1AB15Cu;
    {
        const bool branch_taken_0x1ab15c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 9));
        if (branch_taken_0x1ab15c) {
            ctx->pc = 0x1AB190u;
            goto label_1ab190;
        }
    }
    ctx->pc = 0x1AB164u;
    // 0x1ab164: 0x82080003  lb          $t0, 0x3($s0)
    ctx->pc = 0x1ab164u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1ab168: 0x150b0009  bne         $t0, $t3, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AB168u;
    {
        const bool branch_taken_0x1ab168 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 11));
        if (branch_taken_0x1ab168) {
            ctx->pc = 0x1AB190u;
            goto label_1ab190;
        }
    }
    ctx->pc = 0x1AB170u;
    // 0x1ab170: 0x82080004  lb          $t0, 0x4($s0)
    ctx->pc = 0x1ab170u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1ab174: 0x110e0003  beq         $t0, $t6, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB174u;
    {
        const bool branch_taken_0x1ab174 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 14));
        if (branch_taken_0x1ab174) {
            ctx->pc = 0x1AB184u;
            goto label_1ab184;
        }
    }
    ctx->pc = 0x1AB17Cu;
    // 0x1ab17c: 0x150d0004  bne         $t0, $t5, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AB17Cu;
    {
        const bool branch_taken_0x1ab17c = (GPR_U64(ctx, 8) != GPR_U64(ctx, 13));
        if (branch_taken_0x1ab17c) {
            ctx->pc = 0x1AB190u;
            goto label_1ab190;
        }
    }
    ctx->pc = 0x1AB184u;
label_1ab184:
    // 0x1ab184: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1ab184u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ab188: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1AB188u;
    {
        const bool branch_taken_0x1ab188 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB18Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB188u;
            // 0x1ab18c: 0x26100005  addiu       $s0, $s0, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab188) {
            ctx->pc = 0x1AB1B0u;
            goto label_1ab1b0;
        }
    }
    ctx->pc = 0x1AB190u;
label_1ab190:
    // 0x1ab190: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1ab190u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1ab194: 0x24c80003  addiu       $t0, $a2, 0x3
    ctx->pc = 0x1ab194u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), 3));
    // 0x1ab198: 0x102082a  slt         $at, $t0, $v0
    ctx->pc = 0x1ab198u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1ab19c: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AB19Cu;
    {
        const bool branch_taken_0x1ab19c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB1A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB19Cu;
            // 0x1ab1a0: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab19c) {
            ctx->pc = 0x1AB1B0u;
            goto label_1ab1b0;
        }
    }
    ctx->pc = 0x1AB1A4u;
label_1ab1a4:
    // 0x1ab1a4: 0x82080000  lb          $t0, 0x0($s0)
    ctx->pc = 0x1ab1a4u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ab1a8: 0x1500ffc5  bnez        $t0, . + 4 + (-0x3B << 2)
    ctx->pc = 0x1AB1A8u;
    {
        const bool branch_taken_0x1ab1a8 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AB1ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB1A8u;
            // 0x1ab1ac: 0x87e3c  dsll32      $t7, $t0, 24 (Delay Slot)
        SET_GPR_U64(ctx, 15, GPR_U64(ctx, 8) << (32 + 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab1a8) {
            ctx->pc = 0x1AB0C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab0c0;
        }
    }
    ctx->pc = 0x1AB1B0u;
label_1ab1b0:
    // 0x1ab1b0: 0x14e00003  bnez        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB1B0u;
    {
        const bool branch_taken_0x1ab1b0 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AB1B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB1B0u;
            // 0x1ab1b4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab1b0) {
            ctx->pc = 0x1AB1C0u;
            goto label_1ab1c0;
        }
    }
    ctx->pc = 0x1AB1B8u;
    // 0x1ab1b8: 0x27b00250  addiu       $s0, $sp, 0x250
    ctx->pc = 0x1ab1b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 592));
    // 0x1ab1bc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1ab1bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1ab1c0:
    // 0x1ab1c0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1AB1C0u;
    SET_GPR_U32(ctx, 31, 0x1AB1C8u);
    ctx->pc = 0x1AB1C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB1C0u;
            // 0x1ab1c4: 0x27a40150  addiu       $a0, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB1C8u; }
        if (ctx->pc != 0x1AB1C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB1C8u; }
        if (ctx->pc != 0x1AB1C8u) { return; }
    }
    ctx->pc = 0x1AB1C8u;
label_1ab1c8:
    // 0x1ab1c8: 0x27a80150  addiu       $t0, $sp, 0x150
    ctx->pc = 0x1ab1c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
    // 0x1ab1cc: 0x2406005f  addiu       $a2, $zero, 0x5F
    ctx->pc = 0x1ab1ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x1ab1d0: 0x2407005c  addiu       $a3, $zero, 0x5C
    ctx->pc = 0x1ab1d0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x1ab1d4: 0x2405002f  addiu       $a1, $zero, 0x2F
    ctx->pc = 0x1ab1d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
    // 0x1ab1d8: 0x2404002e  addiu       $a0, $zero, 0x2E
    ctx->pc = 0x1ab1d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1ab1dc: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1AB1DCu;
    {
        const bool branch_taken_0x1ab1dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB1E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB1DCu;
            // 0x1ab1e0: 0x2402002d  addiu       $v0, $zero, 0x2D (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab1dc) {
            ctx->pc = 0x1AB22Cu;
            goto label_1ab22c;
        }
    }
    ctx->pc = 0x1AB1E4u;
label_1ab1e4:
    // 0x1ab1e4: 0x31e3c  dsll32      $v1, $v1, 24
    ctx->pc = 0x1ab1e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 24));
    // 0x1ab1e8: 0x31e3f  dsra32      $v1, $v1, 24
    ctx->pc = 0x1ab1e8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 24));
    // 0x1ab1ec: 0x14670002  bne         $v1, $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AB1ECu;
    {
        const bool branch_taken_0x1ab1ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 7));
        if (branch_taken_0x1ab1ec) {
            ctx->pc = 0x1AB1F8u;
            goto label_1ab1f8;
        }
    }
    ctx->pc = 0x1AB1F4u;
    // 0x1ab1f4: 0xa1060000  sb          $a2, 0x0($t0)
    ctx->pc = 0x1ab1f4u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 6));
label_1ab1f8:
    // 0x1ab1f8: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x1ab1f8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1ab1fc: 0x14650002  bne         $v1, $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AB1FCu;
    {
        const bool branch_taken_0x1ab1fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x1ab1fc) {
            ctx->pc = 0x1AB208u;
            goto label_1ab208;
        }
    }
    ctx->pc = 0x1AB204u;
    // 0x1ab204: 0xa1060000  sb          $a2, 0x0($t0)
    ctx->pc = 0x1ab204u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 6));
label_1ab208:
    // 0x1ab208: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x1ab208u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1ab20c: 0x14640002  bne         $v1, $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AB20Cu;
    {
        const bool branch_taken_0x1ab20c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1ab20c) {
            ctx->pc = 0x1AB218u;
            goto label_1ab218;
        }
    }
    ctx->pc = 0x1AB214u;
    // 0x1ab214: 0xa1060000  sb          $a2, 0x0($t0)
    ctx->pc = 0x1ab214u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 6));
label_1ab218:
    // 0x1ab218: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x1ab218u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1ab21c: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AB21Cu;
    {
        const bool branch_taken_0x1ab21c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1ab21c) {
            ctx->pc = 0x1AB228u;
            goto label_1ab228;
        }
    }
    ctx->pc = 0x1AB224u;
    // 0x1ab224: 0xa1060000  sb          $a2, 0x0($t0)
    ctx->pc = 0x1ab224u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 6));
label_1ab228:
    // 0x1ab228: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1ab228u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
label_1ab22c:
    // 0x1ab22c: 0x81030000  lb          $v1, 0x0($t0)
    ctx->pc = 0x1ab22cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1ab230: 0x1460ffec  bnez        $v1, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1AB230u;
    {
        const bool branch_taken_0x1ab230 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AB234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB230u;
            // 0x1ab234: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab230) {
            ctx->pc = 0x1AB1E4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab1e4;
        }
    }
    ctx->pc = 0x1AB238u;
    // 0x1ab238: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1AB238u;
    {
        const bool branch_taken_0x1ab238 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB23Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB238u;
            // 0x1ab23c: 0x271102a  slt         $v0, $s3, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab238) {
            ctx->pc = 0x1AB2A8u;
            goto label_1ab2a8;
        }
    }
    ctx->pc = 0x1AB240u;
label_1ab240:
    // 0x1ab240: 0x8e500000  lw          $s0, 0x0($s2)
    ctx->pc = 0x1ab240u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ab244: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1AB244u;
    SET_GPR_U32(ctx, 31, 0x1AB24Cu);
    ctx->pc = 0x1AB248u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB244u;
            // 0x1ab248: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB24Cu; }
        if (ctx->pc != 0x1AB24Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB24Cu; }
        if (ctx->pc != 0x1AB24Cu) { return; }
    }
    ctx->pc = 0x1AB24Cu;
label_1ab24c:
    // 0x1ab24c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1AB24Cu;
    {
        const bool branch_taken_0x1ab24c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB24Cu;
            // 0x1ab250: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab24c) {
            ctx->pc = 0x1AB26Cu;
            goto label_1ab26c;
        }
    }
    ctx->pc = 0x1AB254u;
label_1ab254:
    // 0x1ab254: 0x82040000  lb          $a0, 0x0($s0)
    ctx->pc = 0x1ab254u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ab258: 0xbd1821  addu        $v1, $a1, $sp
    ctx->pc = 0x1ab258u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
    // 0x1ab25c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1ab25cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1ab260: 0x388400ff  xori        $a0, $a0, 0xFF
    ctx->pc = 0x1ab260u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) ^ (uint64_t)(uint16_t)255);
    // 0x1ab264: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1ab264u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1ab268: 0xa0640050  sb          $a0, 0x50($v1)
    ctx->pc = 0x1ab268u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 80), (uint8_t)GPR_U32(ctx, 4));
label_1ab26c:
    // 0x1ab26c: 0xa2182a  slt         $v1, $a1, $v0
    ctx->pc = 0x1ab26cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1ab270: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1AB270u;
    {
        const bool branch_taken_0x1ab270 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ab270) {
            ctx->pc = 0x1AB254u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab254;
        }
    }
    ctx->pc = 0x1AB278u;
    // 0x1ab278: 0xbd1021  addu        $v0, $a1, $sp
    ctx->pc = 0x1ab278u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
    // 0x1ab27c: 0x27a40150  addiu       $a0, $sp, 0x150
    ctx->pc = 0x1ab27cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
    // 0x1ab280: 0xa0400050  sb          $zero, 0x50($v0)
    ctx->pc = 0x1ab280u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 80), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ab284: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1AB284u;
    SET_GPR_U32(ctx, 31, 0x1AB28Cu);
    ctx->pc = 0x1AB288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB284u;
            // 0x1ab288: 0x27a50050  addiu       $a1, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB28Cu; }
        if (ctx->pc != 0x1AB28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB28Cu; }
        if (ctx->pc != 0x1AB28Cu) { return; }
    }
    ctx->pc = 0x1AB28Cu;
label_1ab28c:
    // 0x1ab28c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB28Cu;
    {
        const bool branch_taken_0x1ab28c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ab28c) {
            ctx->pc = 0x1AB29Cu;
            goto label_1ab29c;
        }
    }
    ctx->pc = 0x1AB294u;
    // 0x1ab294: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AB294u;
    {
        const bool branch_taken_0x1ab294 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB294u;
            // 0x1ab298: 0x260102d  daddu       $v0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab294) {
            ctx->pc = 0x1AB2B0u;
            goto label_1ab2b0;
        }
    }
    ctx->pc = 0x1AB29Cu;
label_1ab29c:
    // 0x1ab29c: 0x26520004  addiu       $s2, $s2, 0x4
    ctx->pc = 0x1ab29cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
    // 0x1ab2a0: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1ab2a0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1ab2a4: 0x271102a  slt         $v0, $s3, $s1
    ctx->pc = 0x1ab2a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
label_1ab2a8:
    // 0x1ab2a8: 0x1440ffe5  bnez        $v0, . + 4 + (-0x1B << 2)
    ctx->pc = 0x1AB2A8u;
    {
        const bool branch_taken_0x1ab2a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AB2ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB2A8u;
            // 0x1ab2ac: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab2a8) {
            ctx->pc = 0x1AB240u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab240;
        }
    }
    ctx->pc = 0x1AB2B0u;
label_1ab2b0:
    // 0x1ab2b0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1ab2b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ab2b4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ab2b4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ab2b8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ab2b8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ab2bc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ab2bcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ab2c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ab2c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab2c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB2C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB2C4u;
            // 0x1ab2c8: 0x27bd0350  addiu       $sp, $sp, 0x350 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 848));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB07Cu: goto label_1ab07c;
            case 0x1AB084u: goto label_1ab084;
            case 0x1AB090u: goto label_1ab090;
            case 0x1AB0C0u: goto label_1ab0c0;
            case 0x1AB0F8u: goto label_1ab0f8;
            case 0x1AB104u: goto label_1ab104;
            case 0x1AB138u: goto label_1ab138;
            case 0x1AB144u: goto label_1ab144;
            case 0x1AB184u: goto label_1ab184;
            case 0x1AB190u: goto label_1ab190;
            case 0x1AB1A4u: goto label_1ab1a4;
            case 0x1AB1B0u: goto label_1ab1b0;
            case 0x1AB1C0u: goto label_1ab1c0;
            case 0x1AB1C8u: goto label_1ab1c8;
            case 0x1AB1E4u: goto label_1ab1e4;
            case 0x1AB1F8u: goto label_1ab1f8;
            case 0x1AB208u: goto label_1ab208;
            case 0x1AB218u: goto label_1ab218;
            case 0x1AB228u: goto label_1ab228;
            case 0x1AB22Cu: goto label_1ab22c;
            case 0x1AB240u: goto label_1ab240;
            case 0x1AB24Cu: goto label_1ab24c;
            case 0x1AB254u: goto label_1ab254;
            case 0x1AB26Cu: goto label_1ab26c;
            case 0x1AB28Cu: goto label_1ab28c;
            case 0x1AB29Cu: goto label_1ab29c;
            case 0x1AB2A8u: goto label_1ab2a8;
            case 0x1AB2B0u: goto label_1ab2b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB2CCu;
    // 0x1ab2cc: 0x0  nop
    ctx->pc = 0x1ab2ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
