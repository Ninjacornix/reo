#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B3FA0
// Address: 0x1b3fa0 - 0x1b4100
void sub_001B3FA0_0x1b3fa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B3FA0_0x1b3fa0");
#endif

    switch (ctx->pc) {
        case 0x1b3fc0u: goto label_1b3fc0;
        case 0x1b4038u: goto label_1b4038;
        case 0x1b40b0u: goto label_1b40b0;
        case 0x1b40ccu: goto label_1b40cc;
        default: break;
    }

    ctx->pc = 0x1b3fa0u;

    // 0x1b3fa0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1b3fa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1b3fa4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b3fa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b3fa8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b3fa8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b3fac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b3facu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b3fb0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b3fb0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3fb4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b3fb4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b3fb8: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1b3fb8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b3fbc: 0x27b0004a  addiu       $s0, $sp, 0x4A
    ctx->pc = 0x1b3fbcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 74));
label_1b3fc0:
    // 0x1b3fc0: 0x92470000  lbu         $a3, 0x0($s2)
    ctx->pc = 0x1b3fc0u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1b3fc4: 0x10e00047  beqz        $a3, . + 4 + (0x47 << 2)
    ctx->pc = 0x1B3FC4u;
    {
        const bool branch_taken_0x1b3fc4 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3FC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3FC4u;
            // 0x1b3fc8: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3fc4) {
            ctx->pc = 0x1B40E4u;
            goto label_1b40e4;
        }
    }
    ctx->pc = 0x1B3FCCu;
    // 0x1b3fcc: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1b3fccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1b3fd0: 0x10e20045  beq         $a3, $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x1B3FD0u;
    {
        const bool branch_taken_0x1b3fd0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B3FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3FD0u;
            // 0x1b3fd4: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3fd0) {
            ctx->pc = 0x1B40E8u;
            goto label_1b40e8;
        }
    }
    ctx->pc = 0x1B3FD8u;
    // 0x1b3fd8: 0x2ce20080  sltiu       $v0, $a3, 0x80
    ctx->pc = 0x1b3fd8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b3fdc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B3FDCu;
    {
        const bool branch_taken_0x1b3fdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3FDCu;
            // 0x1b3fe0: 0x2ce200e0  sltiu       $v0, $a3, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3fdc) {
            ctx->pc = 0x1B3FF0u;
            goto label_1b3ff0;
        }
    }
    ctx->pc = 0x1B3FE4u;
    // 0x1b3fe4: 0x2ce100a0  sltiu       $at, $a3, 0xA0
    ctx->pc = 0x1b3fe4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)160) ? 1 : 0);
    // 0x1b3fe8: 0x14200005  bnez        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B3FE8u;
    {
        const bool branch_taken_0x1b3fe8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b3fe8) {
            ctx->pc = 0x1B4000u;
            goto label_1b4000;
        }
    }
    ctx->pc = 0x1B3FF0u;
label_1b3ff0:
    // 0x1b3ff0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B3FF0u;
    {
        const bool branch_taken_0x1b3ff0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B3FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3FF0u;
            // 0x1b3ff4: 0x2ce10100  sltiu       $at, $a3, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3ff0) {
            ctx->pc = 0x1B4018u;
            goto label_1b4018;
        }
    }
    ctx->pc = 0x1B3FF8u;
    // 0x1b3ff8: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B3FF8u;
    {
        const bool branch_taken_0x1b3ff8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B3FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B3FF8u;
            // 0x1b3ffc: 0x2402003c  addiu       $v0, $zero, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b3ff8) {
            ctx->pc = 0x1B401Cu;
            goto label_1b401c;
        }
    }
    ctx->pc = 0x1B4000u;
label_1b4000:
    // 0x1b4000: 0x92420000  lbu         $v0, 0x0($s2)
    ctx->pc = 0x1b4000u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1b4004: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b4004u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1b4008: 0x10400036  beqz        $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x1B4008u;
    {
        const bool branch_taken_0x1b4008 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B400Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4008u;
            // 0x1b400c: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4008) {
            ctx->pc = 0x1B40E4u;
            goto label_1b40e4;
        }
    }
    ctx->pc = 0x1B4010u;
    // 0x1b4010: 0x1000ffeb  b           . + 4 + (-0x15 << 2)
    ctx->pc = 0x1B4010u;
    {
        const bool branch_taken_0x1b4010 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4010u;
            // 0x1b4014: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4010) {
            ctx->pc = 0x1B3FC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b3fc0;
        }
    }
    ctx->pc = 0x1B4018u;
label_1b4018:
    // 0x1b4018: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1b4018u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
label_1b401c:
    // 0x1b401c: 0x14e2002f  bne         $a3, $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x1B401Cu;
    {
        const bool branch_taken_0x1b401c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b401c) {
            ctx->pc = 0x1B40DCu;
            goto label_1b40dc;
        }
    }
    ctx->pc = 0x1B4024u;
    // 0x1b4024: 0xa3a70048  sb          $a3, 0x48($sp)
    ctx->pc = 0x1b4024u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 72), (uint8_t)GPR_U32(ctx, 7));
    // 0x1b4028: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b4028u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b402c: 0x2ce40080  sltiu       $a0, $a3, 0x80
    ctx->pc = 0x1b402cu;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1b4030: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1B4030u;
    {
        const bool branch_taken_0x1b4030 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4030u;
            // 0x1b4034: 0x2ce300e0  sltiu       $v1, $a3, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4030) {
            ctx->pc = 0x1B407Cu;
            goto label_1b407c;
        }
    }
    ctx->pc = 0x1B4038u;
label_1b4038:
    // 0x1b4038: 0x8042ffff  lb          $v0, -0x1($v0)
    ctx->pc = 0x1b4038u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294967295)));
    // 0x1b403c: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B403Cu;
    {
        const bool branch_taken_0x1b403c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B403Cu;
            // 0x1b4040: 0xbd1021  addu        $v0, $a1, $sp (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b403c) {
            ctx->pc = 0x1B408Cu;
            goto label_1b408c;
        }
    }
    ctx->pc = 0x1B4044u;
    // 0x1b4044: 0x24a2ffff  addiu       $v0, $a1, -0x1
    ctx->pc = 0x1b4044u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1b4048: 0x2421021  addu        $v0, $s2, $v0
    ctx->pc = 0x1b4048u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1b404c: 0x14800004  bnez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B404Cu;
    {
        const bool branch_taken_0x1b404c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B404Cu;
            // 0x1b4050: 0x90460000  lbu         $a2, 0x0($v0) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b404c) {
            ctx->pc = 0x1B4060u;
            goto label_1b4060;
        }
    }
    ctx->pc = 0x1B4054u;
    // 0x1b4054: 0x2ce100a0  sltiu       $at, $a3, 0xA0
    ctx->pc = 0x1b4054u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)160) ? 1 : 0);
    // 0x1b4058: 0x1420000b  bnez        $at, . + 4 + (0xB << 2)
    ctx->pc = 0x1B4058u;
    {
        const bool branch_taken_0x1b4058 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b4058) {
            ctx->pc = 0x1B4088u;
            goto label_1b4088;
        }
    }
    ctx->pc = 0x1B4060u;
label_1b4060:
    // 0x1b4060: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B4060u;
    {
        const bool branch_taken_0x1b4060 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4060u;
            // 0x1b4064: 0xbd1021  addu        $v0, $a1, $sp (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4060) {
            ctx->pc = 0x1B4074u;
            goto label_1b4074;
        }
    }
    ctx->pc = 0x1B4068u;
    // 0x1b4068: 0x2ce10100  sltiu       $at, $a3, 0x100
    ctx->pc = 0x1b4068u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b406c: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B406Cu;
    {
        const bool branch_taken_0x1b406c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b406c) {
            ctx->pc = 0x1B4088u;
            goto label_1b4088;
        }
    }
    ctx->pc = 0x1B4074u;
label_1b4074:
    // 0x1b4074: 0xa0460048  sb          $a2, 0x48($v0)
    ctx->pc = 0x1b4074u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 72), (uint8_t)GPR_U32(ctx, 6));
    // 0x1b4078: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1b4078u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1b407c:
    // 0x1b407c: 0x28a20004  slti        $v0, $a1, 0x4
    ctx->pc = 0x1b407cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b4080: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1B4080u;
    {
        const bool branch_taken_0x1b4080 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4080u;
            // 0x1b4084: 0x2451021  addu        $v0, $s2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4080) {
            ctx->pc = 0x1B4038u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b4038;
        }
    }
    ctx->pc = 0x1B4088u;
label_1b4088:
    // 0x1b4088: 0xbd1021  addu        $v0, $a1, $sp
    ctx->pc = 0x1b4088u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
label_1b408c:
    // 0x1b408c: 0xa0400048  sb          $zero, 0x48($v0)
    ctx->pc = 0x1b408cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 72), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b4090: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1b4090u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b4094: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B4094u;
    {
        const bool branch_taken_0x1b4094 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4094u;
            // 0x1b4098: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4094) {
            ctx->pc = 0x1B40A0u;
            goto label_1b40a0;
        }
    }
    ctx->pc = 0x1B409Cu;
    // 0x1b409c: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1b409cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
label_1b40a0:
    // 0x1b40a0: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1b40a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1b40a4: 0x27a40048  addiu       $a0, $sp, 0x48
    ctx->pc = 0x1b40a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
    // 0x1b40a8: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1B40A8u;
    SET_GPR_U32(ctx, 31, 0x1B40B0u);
    ctx->pc = 0x1B40ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B40A8u;
            // 0x1b40ac: 0x24a5ff10  addiu       $a1, $a1, -0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967056));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B40B0u; }
        if (ctx->pc != 0x1B40B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B40B0u; }
        if (ctx->pc != 0x1B40B0u) { return; }
    }
    ctx->pc = 0x1B40B0u;
label_1b40b0:
    // 0x1b40b0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B40B0u;
    {
        const bool branch_taken_0x1b40b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B40B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B40B0u;
            // 0x1b40b4: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b40b0) {
            ctx->pc = 0x1B40C0u;
            goto label_1b40c0;
        }
    }
    ctx->pc = 0x1B40B8u;
    // 0x1b40b8: 0x1000ffc1  b           . + 4 + (-0x3F << 2)
    ctx->pc = 0x1B40B8u;
    {
        const bool branch_taken_0x1b40b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B40BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B40B8u;
            // 0x1b40bc: 0x26520003  addiu       $s2, $s2, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b40b8) {
            ctx->pc = 0x1B3FC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b3fc0;
        }
    }
    ctx->pc = 0x1B40C0u;
label_1b40c0:
    // 0x1b40c0: 0x27a40048  addiu       $a0, $sp, 0x48
    ctx->pc = 0x1b40c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
    // 0x1b40c4: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1B40C4u;
    SET_GPR_U32(ctx, 31, 0x1B40CCu);
    ctx->pc = 0x1B40C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B40C4u;
            // 0x1b40c8: 0x24a5ff18  addiu       $a1, $a1, -0xE8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B40CCu; }
        if (ctx->pc != 0x1B40CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B40CCu; }
        if (ctx->pc != 0x1B40CCu) { return; }
    }
    ctx->pc = 0x1B40CCu;
label_1b40cc:
    // 0x1b40cc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B40CCu;
    {
        const bool branch_taken_0x1b40cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b40cc) {
            ctx->pc = 0x1B40DCu;
            goto label_1b40dc;
        }
    }
    ctx->pc = 0x1B40D4u;
    // 0x1b40d4: 0x1000ffba  b           . + 4 + (-0x46 << 2)
    ctx->pc = 0x1B40D4u;
    {
        const bool branch_taken_0x1b40d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B40D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B40D4u;
            // 0x1b40d8: 0x26520003  addiu       $s2, $s2, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b40d4) {
            ctx->pc = 0x1B3FC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b3fc0;
        }
    }
    ctx->pc = 0x1B40DCu;
label_1b40dc:
    // 0x1b40dc: 0x1000ffb8  b           . + 4 + (-0x48 << 2)
    ctx->pc = 0x1B40DCu;
    {
        const bool branch_taken_0x1b40dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B40E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B40DCu;
            // 0x1b40e0: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b40dc) {
            ctx->pc = 0x1B3FC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b3fc0;
        }
    }
    ctx->pc = 0x1B40E4u;
label_1b40e4:
    // 0x1b40e4: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1b40e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1b40e8:
    // 0x1b40e8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b40e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b40ec: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b40ecu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b40f0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b40f0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b40f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b40f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b40f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B40F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B40FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B40F8u;
            // 0x1b40fc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3FC0u: goto label_1b3fc0;
            case 0x1B3FF0u: goto label_1b3ff0;
            case 0x1B4000u: goto label_1b4000;
            case 0x1B4018u: goto label_1b4018;
            case 0x1B401Cu: goto label_1b401c;
            case 0x1B4038u: goto label_1b4038;
            case 0x1B4060u: goto label_1b4060;
            case 0x1B4074u: goto label_1b4074;
            case 0x1B407Cu: goto label_1b407c;
            case 0x1B4088u: goto label_1b4088;
            case 0x1B408Cu: goto label_1b408c;
            case 0x1B40A0u: goto label_1b40a0;
            case 0x1B40B0u: goto label_1b40b0;
            case 0x1B40C0u: goto label_1b40c0;
            case 0x1B40CCu: goto label_1b40cc;
            case 0x1B40DCu: goto label_1b40dc;
            case 0x1B40E4u: goto label_1b40e4;
            case 0x1B40E8u: goto label_1b40e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4100u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
