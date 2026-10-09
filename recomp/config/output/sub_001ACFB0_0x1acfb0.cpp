#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ACFB0
// Address: 0x1acfb0 - 0x1ad150
void sub_001ACFB0_0x1acfb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ACFB0_0x1acfb0");
#endif

    switch (ctx->pc) {
        case 0x1ad02cu: goto label_1ad02c;
        case 0x1ad03cu: goto label_1ad03c;
        case 0x1ad0ecu: goto label_1ad0ec;
        case 0x1ad108u: goto label_1ad108;
        case 0x1ad118u: goto label_1ad118;
        case 0x1ad120u: goto label_1ad120;
        default: break;
    }

    ctx->pc = 0x1acfb0u;

    // 0x1acfb0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1acfb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1acfb4: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1acfb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1acfb8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1acfb8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1acfbc: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1acfbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1acfc0: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1acfc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1acfc4: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1acfc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1acfc8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1acfc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1acfcc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1acfccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1acfd0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1acfd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1acfd4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1acfd4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1acfd8: 0x2e02000e  sltiu       $v0, $s0, 0xE
    ctx->pc = 0x1acfd8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)14) ? 1 : 0);
    // 0x1acfdc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ACFDCu;
    {
        const bool branch_taken_0x1acfdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1ACFE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACFDCu;
            // 0x1acfe0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acfdc) {
            ctx->pc = 0x1ACFECu;
            goto label_1acfec;
        }
    }
    ctx->pc = 0x1ACFE4u;
    // 0x1acfe4: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1ACFE4u;
    {
        const bool branch_taken_0x1acfe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACFE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACFE4u;
            // 0x1acfe8: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acfe4) {
            ctx->pc = 0x1AD128u;
            goto label_1ad128;
        }
    }
    ctx->pc = 0x1ACFECu;
label_1acfec:
    // 0x1acfec: 0x8c870020  lw          $a3, 0x20($a0)
    ctx->pc = 0x1acfecu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1acff0: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x1acff0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1acff4: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x1acff4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1acff8: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1acff8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1acffc: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1acffcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1ad000: 0x31a40  sll         $v1, $v1, 9
    ctx->pc = 0x1ad000u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 9));
    // 0x1ad004: 0x24423950  addiu       $v0, $v0, 0x3950
    ctx->pc = 0x1ad004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14672));
    // 0x1ad008: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1ad008u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad00c: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x1ad00cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ad010: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ad010u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad014: 0x24060600  addiu       $a2, $zero, 0x600
    ctx->pc = 0x1ad014u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x1ad018: 0x220902d  daddu       $s2, $s1, $zero
    ctx->pc = 0x1ad018u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad01c: 0x871021  addu        $v0, $a0, $a3
    ctx->pc = 0x1ad01cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1ad020: 0x24530010  addiu       $s3, $v0, 0x10
    ctx->pc = 0x1ad020u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1ad024: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AD024u;
    SET_GPR_U32(ctx, 31, 0x1AD02Cu);
    ctx->pc = 0x1AD028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD024u;
            // 0x1ad028: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD02Cu; }
        if (ctx->pc != 0x1AD02Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD02Cu; }
        if (ctx->pc != 0x1AD02Cu) { return; }
    }
    ctx->pc = 0x1AD02Cu;
label_1ad02c:
    // 0x1ad02c: 0x8e830024  lw          $v1, 0x24($s4)
    ctx->pc = 0x1ad02cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 36)));
    // 0x1ad030: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ad030u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad034: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1AD034u;
    {
        const bool branch_taken_0x1ad034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD034u;
            // 0x1ad038: 0x3b102  srl         $s6, $v1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad034) {
            ctx->pc = 0x1AD09Cu;
            goto label_1ad09c;
        }
    }
    ctx->pc = 0x1AD03Cu;
label_1ad03c:
    // 0x1ad03c: 0x82630000  lb          $v1, 0x0($s3)
    ctx->pc = 0x1ad03cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ad040: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ad040u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ad044: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x1ad044u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ad048: 0x82630009  lb          $v1, 0x9($s3)
    ctx->pc = 0x1ad048u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 9)));
    // 0x1ad04c: 0xa2430005  sb          $v1, 0x5($s2)
    ctx->pc = 0x1ad04cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 5), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ad050: 0x82630008  lb          $v1, 0x8($s3)
    ctx->pc = 0x1ad050u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1ad054: 0xa2430004  sb          $v1, 0x4($s2)
    ctx->pc = 0x1ad054u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 4), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ad058: 0x8663000a  lh          $v1, 0xA($s3)
    ctx->pc = 0x1ad058u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 10)));
    // 0x1ad05c: 0xa6430002  sh          $v1, 0x2($s2)
    ctx->pc = 0x1ad05cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ad060: 0x8263000c  lb          $v1, 0xC($s3)
    ctx->pc = 0x1ad060u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 12)));
    // 0x1ad064: 0xa2430006  sb          $v1, 0x6($s2)
    ctx->pc = 0x1ad064u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 6), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ad068: 0x8263000d  lb          $v1, 0xD($s3)
    ctx->pc = 0x1ad068u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 13)));
    // 0x1ad06c: 0xa2430007  sb          $v1, 0x7($s2)
    ctx->pc = 0x1ad06cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 7), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ad070: 0x82630006  lb          $v1, 0x6($s3)
    ctx->pc = 0x1ad070u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 6)));
    // 0x1ad074: 0x3063007f  andi        $v1, $v1, 0x7F
    ctx->pc = 0x1ad074u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)127);
    // 0x1ad078: 0xa2430008  sb          $v1, 0x8($s2)
    ctx->pc = 0x1ad078u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 8), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ad07c: 0x82630006  lb          $v1, 0x6($s3)
    ctx->pc = 0x1ad07cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 6)));
    // 0x1ad080: 0x30630080  andi        $v1, $v1, 0x80
    ctx->pc = 0x1ad080u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)128);
    // 0x1ad084: 0x3182b  sltu        $v1, $zero, $v1
    ctx->pc = 0x1ad084u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1ad088: 0xa2430009  sb          $v1, 0x9($s2)
    ctx->pc = 0x1ad088u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 9), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ad08c: 0x8263000f  lb          $v1, 0xF($s3)
    ctx->pc = 0x1ad08cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 15)));
    // 0x1ad090: 0xa243000b  sb          $v1, 0xB($s2)
    ctx->pc = 0x1ad090u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 11), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ad094: 0x26730010  addiu       $s3, $s3, 0x10
    ctx->pc = 0x1ad094u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 16));
    // 0x1ad098: 0x2652000c  addiu       $s2, $s2, 0xC
    ctx->pc = 0x1ad098u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
label_1ad09c:
    // 0x1ad09c: 0x28410080  slti        $at, $v0, 0x80
    ctx->pc = 0x1ad09cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)128) ? 1 : 0);
    // 0x1ad0a0: 0x10200007  beqz        $at, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AD0A0u;
    {
        const bool branch_taken_0x1ad0a0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ad0a0) {
            ctx->pc = 0x1AD0C0u;
            goto label_1ad0c0;
        }
    }
    ctx->pc = 0x1AD0A8u;
    // 0x1ad0a8: 0x8e830024  lw          $v1, 0x24($s4)
    ctx->pc = 0x1ad0a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 36)));
    // 0x1ad0ac: 0x2463fff0  addiu       $v1, $v1, -0x10
    ctx->pc = 0x1ad0acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967280));
    // 0x1ad0b0: 0x31902  srl         $v1, $v1, 4
    ctx->pc = 0x1ad0b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x1ad0b4: 0x43182b  sltu        $v1, $v0, $v1
    ctx->pc = 0x1ad0b4u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1ad0b8: 0x1460ffe0  bnez        $v1, . + 4 + (-0x20 << 2)
    ctx->pc = 0x1AD0B8u;
    {
        const bool branch_taken_0x1ad0b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ad0b8) {
            ctx->pc = 0x1AD03Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ad03c;
        }
    }
    ctx->pc = 0x1AD0C0u;
label_1ad0c0:
    // 0x1ad0c0: 0x8e850008  lw          $a1, 0x8($s4)
    ctx->pc = 0x1ad0c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x1ad0c4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ad0c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad0c8: 0x8e830010  lw          $v1, 0x10($s4)
    ctx->pc = 0x1ad0c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 16)));
    // 0x1ad0cc: 0x8e820018  lw          $v0, 0x18($s4)
    ctx->pc = 0x1ad0ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 24)));
    // 0x1ad0d0: 0x8e86000c  lw          $a2, 0xC($s4)
    ctx->pc = 0x1ad0d0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 12)));
    // 0x1ad0d4: 0x8e880014  lw          $t0, 0x14($s4)
    ctx->pc = 0x1ad0d4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 20)));
    // 0x1ad0d8: 0x8e8a001c  lw          $t2, 0x1C($s4)
    ctx->pc = 0x1ad0d8u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 28)));
    // 0x1ad0dc: 0x2a52821  addu        $a1, $s5, $a1
    ctx->pc = 0x1ad0dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 5)));
    // 0x1ad0e0: 0x2a33821  addu        $a3, $s5, $v1
    ctx->pc = 0x1ad0e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x1ad0e4: 0xc069e40  jal         func_1A7900
    ctx->pc = 0x1AD0E4u;
    SET_GPR_U32(ctx, 31, 0x1AD0ECu);
    ctx->pc = 0x1AD0E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD0E4u;
            // 0x1ad0e8: 0x2a24821  addu        $t1, $s5, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7900u;
    if (runtime->hasFunction(0x1A7900u)) {
        auto targetFn = runtime->lookupFunction(0x1A7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD0ECu; }
        if (ctx->pc != 0x1AD0ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7900_0x1a7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD0ECu; }
        if (ctx->pc != 0x1AD0ECu) { return; }
    }
    ctx->pc = 0x1AD0ECu;
label_1ad0ec:
    // 0x1ad0ec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1ad0ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad0f0: 0x6010007  bgez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AD0F0u;
    {
        const bool branch_taken_0x1ad0f0 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1AD0F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD0F0u;
            // 0x1ad0f4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad0f0) {
            ctx->pc = 0x1AD110u;
            goto label_1ad110;
        }
    }
    ctx->pc = 0x1AD0F8u;
    // 0x1ad0f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1ad0f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad0fc: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1ad0fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1ad100: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AD100u;
    SET_GPR_U32(ctx, 31, 0x1AD108u);
    ctx->pc = 0x1AD104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD100u;
            // 0x1ad104: 0x24060600  addiu       $a2, $zero, 0x600 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD108u; }
        if (ctx->pc != 0x1AD108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD108u; }
        if (ctx->pc != 0x1AD108u) { return; }
    }
    ctx->pc = 0x1AD108u;
label_1ad108:
    // 0x1ad108: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AD108u;
    {
        const bool branch_taken_0x1ad108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD108u;
            // 0x1ad10c: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad108) {
            ctx->pc = 0x1AD124u;
            goto label_1ad124;
        }
    }
    ctx->pc = 0x1AD110u;
label_1ad110:
    // 0x1ad110: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1AD110u;
    SET_GPR_U32(ctx, 31, 0x1AD118u);
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD118u; }
        if (ctx->pc != 0x1AD118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD118u; }
        if (ctx->pc != 0x1AD118u) { return; }
    }
    ctx->pc = 0x1AD118u;
label_1ad118:
    // 0x1ad118: 0xc069f78  jal         func_1A7DE0
    ctx->pc = 0x1AD118u;
    SET_GPR_U32(ctx, 31, 0x1AD120u);
    ctx->pc = 0x1AD11Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD118u;
            // 0x1ad11c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7DE0u;
    if (runtime->hasFunction(0x1A7DE0u)) {
        auto targetFn = runtime->lookupFunction(0x1A7DE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD120u; }
        if (ctx->pc != 0x1AD120u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7DE0_0x1a7de0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD120u; }
        if (ctx->pc != 0x1AD120u) { return; }
    }
    ctx->pc = 0x1AD120u;
label_1ad120:
    // 0x1ad120: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x1ad120u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
label_1ad124:
    // 0x1ad124: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1ad124u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_1ad128:
    // 0x1ad128: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1ad128u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ad12c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ad12cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ad130: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ad130u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ad134: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ad134u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ad138: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ad138u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ad13c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ad13cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ad140: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ad140u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad144: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD144u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD144u;
            // 0x1ad148: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ACFECu: goto label_1acfec;
            case 0x1AD02Cu: goto label_1ad02c;
            case 0x1AD03Cu: goto label_1ad03c;
            case 0x1AD09Cu: goto label_1ad09c;
            case 0x1AD0C0u: goto label_1ad0c0;
            case 0x1AD0ECu: goto label_1ad0ec;
            case 0x1AD108u: goto label_1ad108;
            case 0x1AD110u: goto label_1ad110;
            case 0x1AD118u: goto label_1ad118;
            case 0x1AD120u: goto label_1ad120;
            case 0x1AD124u: goto label_1ad124;
            case 0x1AD128u: goto label_1ad128;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD14Cu;
    // 0x1ad14c: 0x0  nop
    ctx->pc = 0x1ad14cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
