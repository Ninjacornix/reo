#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010AFC0
// Address: 0x10afc0 - 0x10b158
void sub_0010AFC0_0x10afc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010AFC0_0x10afc0");
#endif

    switch (ctx->pc) {
        case 0x10b03cu: goto label_10b03c;
        case 0x10b088u: goto label_10b088;
        case 0x10b0b0u: goto label_10b0b0;
        case 0x10b0e8u: goto label_10b0e8;
        case 0x10b110u: goto label_10b110;
        default: break;
    }

    ctx->pc = 0x10afc0u;

    // 0x10afc0: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x10afc0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10afc4: 0xa74025  or          $t0, $a1, $a3
    ctx->pc = 0x10afc4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x10afc8: 0x31020007  andi        $v0, $t0, 0x7
    ctx->pc = 0x10afc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)7);
    // 0x10afcc: 0x14400038  bnez        $v0, . + 4 + (0x38 << 2)
    ctx->pc = 0x10AFCCu;
    {
        const bool branch_taken_0x10afcc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10AFD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10AFCCu;
            // 0x10afd0: 0xe0182d  daddu       $v1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10afcc) {
            ctx->pc = 0x10B0B0u;
            goto label_10b0b0;
        }
    }
    ctx->pc = 0x10AFD4u;
    // 0x10afd4: 0x3102000f  andi        $v0, $t0, 0xF
    ctx->pc = 0x10afd4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)15);
    // 0x10afd8: 0x3c090101  lui         $t1, 0x101
    ctx->pc = 0x10afd8u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)257 << 16));
    // 0x10afdc: 0x35290101  ori         $t1, $t1, 0x101
    ctx->pc = 0x10afdcu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)257);
    // 0x10afe0: 0x94c38  dsll        $t1, $t1, 16
    ctx->pc = 0x10afe0u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 16);
    // 0x10afe4: 0x35290101  ori         $t1, $t1, 0x101
    ctx->pc = 0x10afe4u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)257);
    // 0x10afe8: 0x94c38  dsll        $t1, $t1, 16
    ctx->pc = 0x10afe8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 16);
    // 0x10afec: 0x35290101  ori         $t1, $t1, 0x101
    ctx->pc = 0x10afecu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)257);
    // 0x10aff0: 0x3c048080  lui         $a0, 0x8080
    ctx->pc = 0x10aff0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32896 << 16));
    // 0x10aff4: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10aff4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10aff8: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x10aff8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x10affc: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10affcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10b000: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x10b000u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x10b004: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10b004u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10b008: 0x54400019  bnel        $v0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x10B008u;
    {
        const bool branch_taken_0x10b008 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10b008) {
            ctx->pc = 0x10B00Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B008u;
            // 0x10b00c: 0xdcaa0000  ld          $t2, 0x0($a1) (Delay Slot)
        SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B070u;
            goto label_10b070;
        }
    }
    ctx->pc = 0x10B010u;
    // 0x10b010: 0x71295389  pcpyld      $t2, $t1, $t1
    ctx->pc = 0x10b010u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x10b014: 0x78a90000  lq          $t1, 0x0($a1)
    ctx->pc = 0x10b014u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10b018: 0x70844389  pcpyld      $t0, $a0, $a0
    ctx->pc = 0x10b018u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 4), GPR_VEC(ctx, 4)));
    // 0x10b01c: 0x712a1248  psubb       $v0, $t1, $t2
    ctx->pc = 0x10b01cu;
    SET_GPR_VEC(ctx, 2, PS2_PSUBB(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x10b020: 0x70091ce9  pnor        $v1, $zero, $t1
    ctx->pc = 0x10b020u;
    SET_GPR_VEC(ctx, 3, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 9)));
    // 0x10b024: 0x70431489  pand        $v0, $v0, $v1
    ctx->pc = 0x10b024u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 3)));
    // 0x10b028: 0x70481489  pand        $v0, $v0, $t0
    ctx->pc = 0x10b028u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 8)));
    // 0x10b02c: 0x704923a9  pcpyud      $a0, $v0, $t1
    ctx->pc = 0x10b02cu;
    SET_GPR_VEC(ctx, 4, _mm_unpackhi_epi64(GPR_VEC(ctx, 2), GPR_VEC(ctx, 9)));
    // 0x10b030: 0x441825  or          $v1, $v0, $a0
    ctx->pc = 0x10b030u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x10b034: 0x1460001d  bnez        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x10B034u;
    {
        const bool branch_taken_0x10b034 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B034u;
            // 0x10b038: 0xe0302d  daddu       $a2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b034) {
            ctx->pc = 0x10B0ACu;
            goto label_10b0ac;
        }
    }
    ctx->pc = 0x10B03Cu;
label_10b03c:
    // 0x10b03c: 0x7cc90000  sq          $t1, 0x0($a2)
    ctx->pc = 0x10b03cu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 9));
    // 0x10b040: 0x24a50010  addiu       $a1, $a1, 0x10
    ctx->pc = 0x10b040u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
    // 0x10b044: 0x78a90000  lq          $t1, 0x0($a1)
    ctx->pc = 0x10b044u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10b048: 0x712a1248  psubb       $v0, $t1, $t2
    ctx->pc = 0x10b048u;
    SET_GPR_VEC(ctx, 2, PS2_PSUBB(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x10b04c: 0x70091ce9  pnor        $v1, $zero, $t1
    ctx->pc = 0x10b04cu;
    SET_GPR_VEC(ctx, 3, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 9)));
    // 0x10b050: 0x70431489  pand        $v0, $v0, $v1
    ctx->pc = 0x10b050u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 3)));
    // 0x10b054: 0x70481489  pand        $v0, $v0, $t0
    ctx->pc = 0x10b054u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 8)));
    // 0x10b058: 0x704923a9  pcpyud      $a0, $v0, $t1
    ctx->pc = 0x10b058u;
    SET_GPR_VEC(ctx, 4, _mm_unpackhi_epi64(GPR_VEC(ctx, 2), GPR_VEC(ctx, 9)));
    // 0x10b05c: 0x441825  or          $v1, $v0, $a0
    ctx->pc = 0x10b05cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x10b060: 0x1060fff6  beqz        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x10B060u;
    {
        const bool branch_taken_0x10b060 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B060u;
            // 0x10b064: 0x24c60010  addiu       $a2, $a2, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b060) {
            ctx->pc = 0x10B03Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b03c;
        }
    }
    ctx->pc = 0x10B068u;
    // 0x10b068: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x10B068u;
    {
        const bool branch_taken_0x10b068 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B06Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B068u;
            // 0x10b06c: 0xc0182d  daddu       $v1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b068) {
            ctx->pc = 0x10B0B0u;
            goto label_10b0b0;
        }
    }
    ctx->pc = 0x10B070u;
label_10b070:
    // 0x10b070: 0x149102f  dsubu       $v0, $t2, $t1
    ctx->pc = 0x10b070u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) - GPR_U64(ctx, 9));
    // 0x10b074: 0xa1827  nor         $v1, $zero, $t2
    ctx->pc = 0x10b074u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 10)));
    // 0x10b078: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10b078u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10b07c: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x10b07cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x10b080: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x10B080u;
    {
        const bool branch_taken_0x10b080 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B080u;
            // 0x10b084: 0xe0302d  daddu       $a2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b080) {
            ctx->pc = 0x10B0ACu;
            goto label_10b0ac;
        }
    }
    ctx->pc = 0x10B088u;
label_10b088:
    // 0x10b088: 0xfcca0000  sd          $t2, 0x0($a2)
    ctx->pc = 0x10b088u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 10));
    // 0x10b08c: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x10b08cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x10b090: 0xdcaa0000  ld          $t2, 0x0($a1)
    ctx->pc = 0x10b090u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10b094: 0xa1027  nor         $v0, $zero, $t2
    ctx->pc = 0x10b094u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 10)));
    // 0x10b098: 0x149182f  dsubu       $v1, $t2, $t1
    ctx->pc = 0x10b098u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 10) - GPR_U64(ctx, 9));
    // 0x10b09c: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x10b09cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x10b0a0: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x10b0a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x10b0a4: 0x1060fff8  beqz        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10B0A4u;
    {
        const bool branch_taken_0x10b0a4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B0A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B0A4u;
            // 0x10b0a8: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b0a4) {
            ctx->pc = 0x10B088u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b088;
        }
    }
    ctx->pc = 0x10B0ACu;
label_10b0ac:
    // 0x10b0ac: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x10b0acu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_10b0b0:
    // 0x10b0b0: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x10b0b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10b0b4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x10b0b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10b0b8: 0xa0620000  sb          $v0, 0x0($v1)
    ctx->pc = 0x10b0b8u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10b0bc: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x10b0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x10b0c0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10b0c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10b0c4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10B0C4u;
    {
        const bool branch_taken_0x10b0c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10b0c4) {
            ctx->pc = 0x10B0B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b0b0;
        }
    }
    ctx->pc = 0x10B0CCu;
    // 0x10b0cc: 0x3e00008  jr          $ra
    ctx->pc = 0x10B0CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10B0D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B0CCu;
            // 0x10b0d0: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B03Cu: goto label_10b03c;
            case 0x10B070u: goto label_10b070;
            case 0x10B088u: goto label_10b088;
            case 0x10B0ACu: goto label_10b0ac;
            case 0x10B0B0u: goto label_10b0b0;
            case 0x10B0E8u: goto label_10b0e8;
            case 0x10B110u: goto label_10b110;
            case 0x10B134u: goto label_10b134;
            case 0x10B13Cu: goto label_10b13c;
            case 0x10B14Cu: goto label_10b14c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B0D4u;
    // 0x10b0d4: 0x0  nop
    ctx->pc = 0x10b0d4u;
    // NOP
    // 0x10b0d8: 0x90880000  lbu         $t0, 0x0($a0)
    ctx->pc = 0x10b0d8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b0dc: 0x100102d  daddu       $v0, $t0, $zero
    ctx->pc = 0x10b0dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b0e0: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x10B0E0u;
    {
        const bool branch_taken_0x10b0e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B0E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B0E0u;
            // 0x10b0e4: 0x80482d  daddu       $t1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b0e0) {
            ctx->pc = 0x10B14Cu;
            goto label_10b14c;
        }
    }
    ctx->pc = 0x10B0E8u;
label_10b0e8:
    // 0x10b0e8: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x10b0e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b0ec: 0x80c30000  lb          $v1, 0x0($a2)
    ctx->pc = 0x10b0ecu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10b0f0: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x10B0F0u;
    {
        const bool branch_taken_0x10b0f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B0F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B0F0u;
            // 0x10b0f4: 0x90c70000  lbu         $a3, 0x0($a2) (Delay Slot)
        SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b0f0) {
            ctx->pc = 0x10B13Cu;
            goto label_10b13c;
        }
    }
    ctx->pc = 0x10B0F8u;
    // 0x10b0f8: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x10b0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x10b0fc: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x10b0fcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x10b100: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x10B100u;
    {
        const bool branch_taken_0x10b100 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x10B104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B100u;
            // 0x10b104: 0x81600  sll         $v0, $t0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b100) {
            ctx->pc = 0x10B134u;
            goto label_10b134;
        }
    }
    ctx->pc = 0x10B108u;
    // 0x10b108: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x10b108u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x10b10c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x10b10cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_10b110:
    // 0x10b110: 0x80c30000  lb          $v1, 0x0($a2)
    ctx->pc = 0x10b110u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10b114: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x10B114u;
    {
        const bool branch_taken_0x10b114 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B114u;
            // 0x10b118: 0x90c70000  lbu         $a3, 0x0($a2) (Delay Slot)
        SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b114) {
            ctx->pc = 0x10B13Cu;
            goto label_10b13c;
        }
    }
    ctx->pc = 0x10B11Cu;
    // 0x10b11c: 0x0  nop
    ctx->pc = 0x10b11cu;
    // NOP
    // 0x10b120: 0x0  nop
    ctx->pc = 0x10b120u;
    // NOP
    // 0x10b124: 0x0  nop
    ctx->pc = 0x10b124u;
    // NOP
    // 0x10b128: 0x0  nop
    ctx->pc = 0x10b128u;
    // NOP
    // 0x10b12c: 0x5443fff8  bnel        $v0, $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10B12Cu;
    {
        const bool branch_taken_0x10b12c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x10b12c) {
            ctx->pc = 0x10B130u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B12Cu;
            // 0x10b130: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B110u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b110;
        }
    }
    ctx->pc = 0x10B134u;
label_10b134:
    // 0x10b134: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x10B134u;
    {
        const bool branch_taken_0x10b134 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x10b134) {
            ctx->pc = 0x10B14Cu;
            goto label_10b14c;
        }
    }
    ctx->pc = 0x10B13Cu;
label_10b13c:
    // 0x10b13c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10b13cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10b140: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x10b140u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b144: 0x1440ffe8  bnez        $v0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x10B144u;
    {
        const bool branch_taken_0x10b144 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B144u;
            // 0x10b148: 0x40402d  daddu       $t0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b144) {
            ctx->pc = 0x10B0E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b0e8;
        }
    }
    ctx->pc = 0x10B14Cu;
label_10b14c:
    // 0x10b14c: 0x3e00008  jr          $ra
    ctx->pc = 0x10B14Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10B150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B14Cu;
            // 0x10b150: 0x891023  subu        $v0, $a0, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B03Cu: goto label_10b03c;
            case 0x10B070u: goto label_10b070;
            case 0x10B088u: goto label_10b088;
            case 0x10B0ACu: goto label_10b0ac;
            case 0x10B0B0u: goto label_10b0b0;
            case 0x10B0E8u: goto label_10b0e8;
            case 0x10B110u: goto label_10b110;
            case 0x10B134u: goto label_10b134;
            case 0x10B13Cu: goto label_10b13c;
            case 0x10B14Cu: goto label_10b14c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B154u;
    // 0x10b154: 0x0  nop
    ctx->pc = 0x10b154u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
