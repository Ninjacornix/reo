#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010ACE8
// Address: 0x10ace8 - 0x10ae78
void sub_0010ACE8_0x10ace8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010ACE8_0x10ace8");
#endif

    switch (ctx->pc) {
        case 0x10ad44u: goto label_10ad44;
        case 0x10ae10u: goto label_10ae10;
        case 0x10ae4cu: goto label_10ae4c;
        default: break;
    }

    ctx->pc = 0x10ace8u;

    // 0x10ace8: 0x30820007  andi        $v0, $a0, 0x7
    ctx->pc = 0x10ace8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)7);
    // 0x10acec: 0x1440005a  bnez        $v0, . + 4 + (0x5A << 2)
    ctx->pc = 0x10ACECu;
    {
        const bool branch_taken_0x10acec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10ACF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ACECu;
            // 0x10acf0: 0x30a500ff  andi        $a1, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10acec) {
            ctx->pc = 0x10AE58u;
            goto label_10ae58;
        }
    }
    ctx->pc = 0x10ACF4u;
    // 0x10acf4: 0x51a38  dsll        $v1, $a1, 8
    ctx->pc = 0x10acf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << 8);
    // 0x10acf8: 0x3c060101  lui         $a2, 0x101
    ctx->pc = 0x10acf8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)257 << 16));
    // 0x10acfc: 0x34c60101  ori         $a2, $a2, 0x101
    ctx->pc = 0x10acfcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)257);
    // 0x10ad00: 0x63438  dsll        $a2, $a2, 16
    ctx->pc = 0x10ad00u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 16);
    // 0x10ad04: 0x34c60101  ori         $a2, $a2, 0x101
    ctx->pc = 0x10ad04u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)257);
    // 0x10ad08: 0x63438  dsll        $a2, $a2, 16
    ctx->pc = 0x10ad08u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 16);
    // 0x10ad0c: 0x34c60101  ori         $a2, $a2, 0x101
    ctx->pc = 0x10ad0cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)257);
    // 0x10ad10: 0x65502d  daddu       $t2, $v1, $a1
    ctx->pc = 0x10ad10u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 5));
    // 0x10ad14: 0x3083000f  andi        $v1, $a0, 0xF
    ctx->pc = 0x10ad14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x10ad18: 0xa1438  dsll        $v0, $t2, 16
    ctx->pc = 0x10ad18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) << 16);
    // 0x10ad1c: 0x3c088080  lui         $t0, 0x8080
    ctx->pc = 0x10ad1cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32896 << 16));
    // 0x10ad20: 0x35088080  ori         $t0, $t0, 0x8080
    ctx->pc = 0x10ad20u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)32896);
    // 0x10ad24: 0x84438  dsll        $t0, $t0, 16
    ctx->pc = 0x10ad24u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << 16);
    // 0x10ad28: 0x35088080  ori         $t0, $t0, 0x8080
    ctx->pc = 0x10ad28u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)32896);
    // 0x10ad2c: 0x84438  dsll        $t0, $t0, 16
    ctx->pc = 0x10ad2cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << 16);
    // 0x10ad30: 0x35088080  ori         $t0, $t0, 0x8080
    ctx->pc = 0x10ad30u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)32896);
    // 0x10ad34: 0x4a102d  daddu       $v0, $v0, $t2
    ctx->pc = 0x10ad34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 10));
    // 0x10ad38: 0x2503c  dsll32      $t2, $v0, 0
    ctx->pc = 0x10ad38u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10ad3c: 0x14600024  bnez        $v1, . + 4 + (0x24 << 2)
    ctx->pc = 0x10AD3Cu;
    {
        const bool branch_taken_0x10ad3c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10AD40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AD3Cu;
            // 0x10ad40: 0x4a382d  daddu       $a3, $v0, $t2 (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ad3c) {
            ctx->pc = 0x10ADD0u;
            goto label_10add0;
        }
    }
    ctx->pc = 0x10AD44u;
label_10ad44:
    // 0x10ad44: 0x78890000  lq          $t1, 0x0($a0)
    ctx->pc = 0x10ad44u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10ad48: 0x70c65389  pcpyld      $t2, $a2, $a2
    ctx->pc = 0x10ad48u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 6), GPR_VEC(ctx, 6)));
    // 0x10ad4c: 0x70091ce9  pnor        $v1, $zero, $t1
    ctx->pc = 0x10ad4cu;
    SET_GPR_VEC(ctx, 3, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 9)));
    // 0x10ad50: 0x712a1248  psubb       $v0, $t1, $t2
    ctx->pc = 0x10ad50u;
    SET_GPR_VEC(ctx, 2, PS2_PSUBB(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x10ad54: 0x71083389  pcpyld      $a2, $t0, $t0
    ctx->pc = 0x10ad54u;
    SET_GPR_VEC(ctx, 6, PS2_PCPYLD(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8)));
    // 0x10ad58: 0x70431489  pand        $v0, $v0, $v1
    ctx->pc = 0x10ad58u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 3)));
    // 0x10ad5c: 0x70e74389  pcpyld      $t0, $a3, $a3
    ctx->pc = 0x10ad5cu;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 7)));
    // 0x10ad60: 0x70461489  pand        $v0, $v0, $a2
    ctx->pc = 0x10ad60u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 6)));
    // 0x10ad64: 0x70471ba9  pcpyud      $v1, $v0, $a3
    ctx->pc = 0x10ad64u;
    SET_GPR_VEC(ctx, 3, _mm_unpackhi_epi64(GPR_VEC(ctx, 2), GPR_VEC(ctx, 7)));
    // 0x10ad68: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x10ad68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x10ad6c: 0x5460003b  bnel        $v1, $zero, . + 4 + (0x3B << 2)
    ctx->pc = 0x10AD6Cu;
    {
        const bool branch_taken_0x10ad6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ad6c) {
            ctx->pc = 0x10AD70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10AD6Cu;
            // 0x10ad70: 0x90820000  lbu         $v0, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AE5Cu;
            goto label_10ae5c;
        }
    }
    ctx->pc = 0x10AD74u;
    // 0x10ad74: 0x712814c9  pxor        $v0, $t1, $t0
    ctx->pc = 0x10ad74u;
    SET_GPR_VEC(ctx, 2, PS2_PXOR(GPR_VEC(ctx, 9), GPR_VEC(ctx, 8)));
    // 0x10ad78: 0x704a1a48  psubb       $v1, $v0, $t2
    ctx->pc = 0x10ad78u;
    SET_GPR_VEC(ctx, 3, PS2_PSUBB(GPR_VEC(ctx, 2), GPR_VEC(ctx, 10)));
    // 0x10ad7c: 0x700214e9  pnor        $v0, $zero, $v0
    ctx->pc = 0x10ad7cu;
    SET_GPR_VEC(ctx, 2, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x10ad80: 0x3c088080  lui         $t0, 0x8080
    ctx->pc = 0x10ad80u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32896 << 16));
    // 0x10ad84: 0x35088080  ori         $t0, $t0, 0x8080
    ctx->pc = 0x10ad84u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)32896);
    // 0x10ad88: 0x84438  dsll        $t0, $t0, 16
    ctx->pc = 0x10ad88u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << 16);
    // 0x10ad8c: 0x35088080  ori         $t0, $t0, 0x8080
    ctx->pc = 0x10ad8cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)32896);
    // 0x10ad90: 0x84438  dsll        $t0, $t0, 16
    ctx->pc = 0x10ad90u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) << 16);
    // 0x10ad94: 0x35088080  ori         $t0, $t0, 0x8080
    ctx->pc = 0x10ad94u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)32896);
    // 0x10ad98: 0x70621c89  pand        $v1, $v1, $v0
    ctx->pc = 0x10ad98u;
    SET_GPR_VEC(ctx, 3, PS2_PAND(GPR_VEC(ctx, 3), GPR_VEC(ctx, 2)));
    // 0x10ad9c: 0x70661c89  pand        $v1, $v1, $a2
    ctx->pc = 0x10ad9cu;
    SET_GPR_VEC(ctx, 3, PS2_PAND(GPR_VEC(ctx, 3), GPR_VEC(ctx, 6)));
    // 0x10ada0: 0x3c060101  lui         $a2, 0x101
    ctx->pc = 0x10ada0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)257 << 16));
    // 0x10ada4: 0x34c60101  ori         $a2, $a2, 0x101
    ctx->pc = 0x10ada4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)257);
    // 0x10ada8: 0x63438  dsll        $a2, $a2, 16
    ctx->pc = 0x10ada8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 16);
    // 0x10adac: 0x34c60101  ori         $a2, $a2, 0x101
    ctx->pc = 0x10adacu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)257);
    // 0x10adb0: 0x63438  dsll        $a2, $a2, 16
    ctx->pc = 0x10adb0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << 16);
    // 0x10adb4: 0x34c60101  ori         $a2, $a2, 0x101
    ctx->pc = 0x10adb4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)257);
    // 0x10adb8: 0x706513a9  pcpyud      $v0, $v1, $a1
    ctx->pc = 0x10adb8u;
    SET_GPR_VEC(ctx, 2, _mm_unpackhi_epi64(GPR_VEC(ctx, 3), GPR_VEC(ctx, 5)));
    // 0x10adbc: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x10adbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x10adc0: 0x5060ffe0  beql        $v1, $zero, . + 4 + (-0x20 << 2)
    ctx->pc = 0x10ADC0u;
    {
        const bool branch_taken_0x10adc0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x10adc0) {
            ctx->pc = 0x10ADC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10ADC0u;
            // 0x10adc4: 0x24840010  addiu       $a0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AD44u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ad44;
        }
    }
    ctx->pc = 0x10ADC8u;
    // 0x10adc8: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x10ADC8u;
    {
        const bool branch_taken_0x10adc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10ADCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10ADC8u;
            // 0x10adcc: 0x90820000  lbu         $v0, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10adc8) {
            ctx->pc = 0x10AE5Cu;
            goto label_10ae5c;
        }
    }
    ctx->pc = 0x10ADD0u;
label_10add0:
    // 0x10add0: 0xdc890000  ld          $t1, 0x0($a0)
    ctx->pc = 0x10add0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10add4: 0x91827  nor         $v1, $zero, $t1
    ctx->pc = 0x10add4u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 9)));
    // 0x10add8: 0x126102f  dsubu       $v0, $t1, $a2
    ctx->pc = 0x10add8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) - GPR_U64(ctx, 6));
    // 0x10addc: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10addcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10ade0: 0x481024  and         $v0, $v0, $t0
    ctx->pc = 0x10ade0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
    // 0x10ade4: 0x5440001d  bnel        $v0, $zero, . + 4 + (0x1D << 2)
    ctx->pc = 0x10ADE4u;
    {
        const bool branch_taken_0x10ade4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ade4) {
            ctx->pc = 0x10ADE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10ADE4u;
            // 0x10ade8: 0x90820000  lbu         $v0, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AE5Cu;
            goto label_10ae5c;
        }
    }
    ctx->pc = 0x10ADECu;
    // 0x10adec: 0x1271026  xor         $v0, $t1, $a3
    ctx->pc = 0x10adecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) ^ GPR_U64(ctx, 7));
    // 0x10adf0: 0x46182f  dsubu       $v1, $v0, $a2
    ctx->pc = 0x10adf0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) - GPR_U64(ctx, 6));
    // 0x10adf4: 0x21027  nor         $v0, $zero, $v0
    ctx->pc = 0x10adf4u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x10adf8: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x10adf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x10adfc: 0x681824  and         $v1, $v1, $t0
    ctx->pc = 0x10adfcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 8));
    // 0x10ae00: 0x54600016  bnel        $v1, $zero, . + 4 + (0x16 << 2)
    ctx->pc = 0x10AE00u;
    {
        const bool branch_taken_0x10ae00 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ae00) {
            ctx->pc = 0x10AE04u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10AE00u;
            // 0x10ae04: 0x90820000  lbu         $v0, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AE5Cu;
            goto label_10ae5c;
        }
    }
    ctx->pc = 0x10AE08u;
    // 0x10ae08: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x10ae08u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ae0c: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x10ae0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
label_10ae10:
    // 0x10ae10: 0xdc860000  ld          $a2, 0x0($a0)
    ctx->pc = 0x10ae10u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10ae14: 0xc9102f  dsubu       $v0, $a2, $t1
    ctx->pc = 0x10ae14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) - GPR_U64(ctx, 9));
    // 0x10ae18: 0x61827  nor         $v1, $zero, $a2
    ctx->pc = 0x10ae18u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 6)));
    // 0x10ae1c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10ae1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10ae20: 0x481024  and         $v0, $v0, $t0
    ctx->pc = 0x10ae20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
    // 0x10ae24: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x10AE24u;
    {
        const bool branch_taken_0x10ae24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10AE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AE24u;
            // 0x10ae28: 0xc71026  xor         $v0, $a2, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) ^ GPR_U64(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ae24) {
            ctx->pc = 0x10AE58u;
            goto label_10ae58;
        }
    }
    ctx->pc = 0x10AE2Cu;
    // 0x10ae2c: 0x21827  nor         $v1, $zero, $v0
    ctx->pc = 0x10ae2cu;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x10ae30: 0x49102f  dsubu       $v0, $v0, $t1
    ctx->pc = 0x10ae30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 9));
    // 0x10ae34: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10ae34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10ae38: 0x481024  and         $v0, $v0, $t0
    ctx->pc = 0x10ae38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
    // 0x10ae3c: 0x5040fff4  beql        $v0, $zero, . + 4 + (-0xC << 2)
    ctx->pc = 0x10AE3Cu;
    {
        const bool branch_taken_0x10ae3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ae3c) {
            ctx->pc = 0x10AE40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10AE3Cu;
            // 0x10ae40: 0x24840008  addiu       $a0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AE10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ae10;
        }
    }
    ctx->pc = 0x10AE44u;
    // 0x10ae44: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10AE44u;
    {
        const bool branch_taken_0x10ae44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10AE48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AE44u;
            // 0x10ae48: 0x90820000  lbu         $v0, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ae44) {
            ctx->pc = 0x10AE5Cu;
            goto label_10ae5c;
        }
    }
    ctx->pc = 0x10AE4Cu;
label_10ae4c:
    // 0x10ae4c: 0x50450006  beql        $v0, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x10AE4Cu;
    {
        const bool branch_taken_0x10ae4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        if (branch_taken_0x10ae4c) {
            ctx->pc = 0x10AE50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10AE4Cu;
            // 0x10ae50: 0x90830000  lbu         $v1, 0x0($a0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10AE68u;
            goto label_10ae68;
        }
    }
    ctx->pc = 0x10AE54u;
    // 0x10ae54: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10ae54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_10ae58:
    // 0x10ae58: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x10ae58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
label_10ae5c:
    // 0x10ae5c: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
    ctx->pc = 0x10AE5Cu;
    {
        const bool branch_taken_0x10ae5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ae5c) {
            ctx->pc = 0x10AE4Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ae4c;
        }
    }
    ctx->pc = 0x10AE64u;
    // 0x10ae64: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x10ae64u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
label_10ae68:
    // 0x10ae68: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10ae68u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ae6c: 0x651826  xor         $v1, $v1, $a1
    ctx->pc = 0x10ae6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 5));
    // 0x10ae70: 0x3e00008  jr          $ra
    ctx->pc = 0x10AE70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10AE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AE70u;
            // 0x10ae74: 0x83100a  movz        $v0, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10AD44u: goto label_10ad44;
            case 0x10ADD0u: goto label_10add0;
            case 0x10AE10u: goto label_10ae10;
            case 0x10AE4Cu: goto label_10ae4c;
            case 0x10AE58u: goto label_10ae58;
            case 0x10AE5Cu: goto label_10ae5c;
            case 0x10AE68u: goto label_10ae68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10AE78u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
