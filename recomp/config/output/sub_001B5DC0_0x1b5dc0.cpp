#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5DC0
// Address: 0x1b5dc0 - 0x1b5fb0
void sub_001B5DC0_0x1b5dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5DC0_0x1b5dc0");
#endif

    switch (ctx->pc) {
        case 0x1b5e14u: goto label_1b5e14;
        case 0x1b5e6cu: goto label_1b5e6c;
        case 0x1b5e80u: goto label_1b5e80;
        case 0x1b5edcu: goto label_1b5edc;
        case 0x1b5efcu: goto label_1b5efc;
        case 0x1b5f38u: goto label_1b5f38;
        case 0x1b5f4cu: goto label_1b5f4c;
        default: break;
    }

    ctx->pc = 0x1b5dc0u;

    // 0x1b5dc0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5dc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5dc4: 0x8c870084  lw          $a3, 0x84($a0)
    ctx->pc = 0x1b5dc4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 132)));
    // 0x1b5dc8: 0x8c29ab10  lw          $t1, -0x54F0($at)
    ctx->pc = 0x1b5dc8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945552)));
    // 0x1b5dcc: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1b5dccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1b5dd0: 0x27bdfce0  addiu       $sp, $sp, -0x320
    ctx->pc = 0x1b5dd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966496));
    // 0x1b5dd4: 0x2442aaf0  addiu       $v0, $v0, -0x5510
    ctx->pc = 0x1b5dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945520));
    // 0x1b5dd8: 0xc0182d  daddu       $v1, $a2, $zero
    ctx->pc = 0x1b5dd8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5ddc: 0x2404fffc  addiu       $a0, $zero, -0x4
    ctx->pc = 0x1b5ddcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1b5de0: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5de0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5de4: 0x8c28ab18  lw          $t0, -0x54E8($at)
    ctx->pc = 0x1b5de4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945560)));
    // 0x1b5de8: 0xa94818  mult        $t1, $a1, $t1
    ctx->pc = 0x1b5de8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 9, (int32_t)result); }
    // 0x1b5dec: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b5decu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b5df0: 0x8c2aaafc  lw          $t2, -0x5504($at)
    ctx->pc = 0x1b5df0u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294945532)));
    // 0x1b5df4: 0x25450003  addiu       $a1, $t2, 0x3
    ctx->pc = 0x1b5df4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), 3));
    // 0x1b5df8: 0xa42824  and         $a1, $a1, $a0
    ctx->pc = 0x1b5df8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1b5dfc: 0x71452818  mult1       $a1, $t2, $a1
    ctx->pc = 0x1b5dfcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 5); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x1b5e00: 0x1092021  addu        $a0, $t0, $t1
    ctx->pc = 0x1b5e00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x1b5e04: 0x14e00017  bnez        $a3, . + 4 + (0x17 << 2)
    ctx->pc = 0x1B5E04u;
    {
        const bool branch_taken_0x1b5e04 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5E08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5E04u;
            // 0x1b5e08: 0x55082  srl         $t2, $a1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SRL32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5e04) {
            ctx->pc = 0x1B5E64u;
            goto label_1b5e64;
        }
    }
    ctx->pc = 0x1B5E0Cu;
    // 0x1b5e0c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1B5E0Cu;
    {
        const bool branch_taken_0x1b5e0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5E0Cu;
            // 0x1b5e10: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5e0c) {
            ctx->pc = 0x1B5E50u;
            goto label_1b5e50;
        }
    }
    ctx->pc = 0x1B5E14u;
label_1b5e14:
    // 0x1b5e14: 0x90890000  lbu         $t1, 0x0($a0)
    ctx->pc = 0x1b5e14u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b5e18: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x1b5e18u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1b5e1c: 0x312500c0  andi        $a1, $t1, 0xC0
    ctx->pc = 0x1b5e1cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)192);
    // 0x1b5e20: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1b5e20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1b5e24: 0x53983  sra         $a3, $a1, 6
    ctx->pc = 0x1b5e24u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 5), 6));
    // 0x1b5e28: 0x31250030  andi        $a1, $t1, 0x30
    ctx->pc = 0x1b5e28u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)48);
    // 0x1b5e2c: 0xe54025  or          $t0, $a3, $a1
    ctx->pc = 0x1b5e2cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 7) | GPR_U64(ctx, 5));
    // 0x1b5e30: 0x3125000c  andi        $a1, $t1, 0xC
    ctx->pc = 0x1b5e30u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)12);
    // 0x1b5e34: 0x53980  sll         $a3, $a1, 6
    ctx->pc = 0x1b5e34u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
    // 0x1b5e38: 0x31250003  andi        $a1, $t1, 0x3
    ctx->pc = 0x1b5e38u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)3);
    // 0x1b5e3c: 0xe83825  or          $a3, $a3, $t0
    ctx->pc = 0x1b5e3cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 8));
    // 0x1b5e40: 0x52b00  sll         $a1, $a1, 12
    ctx->pc = 0x1b5e40u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 12));
    // 0x1b5e44: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1b5e44u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1b5e48: 0xa4c50000  sh          $a1, 0x0($a2)
    ctx->pc = 0x1b5e48u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1b5e4c: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x1b5e4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
label_1b5e50:
    // 0x1b5e50: 0x16a282a  slt         $a1, $t3, $t2
    ctx->pc = 0x1b5e50u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 11) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x1b5e54: 0x14a0ffef  bnez        $a1, . + 4 + (-0x11 << 2)
    ctx->pc = 0x1B5E54u;
    {
        const bool branch_taken_0x1b5e54 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b5e54) {
            ctx->pc = 0x1B5E14u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5e14;
        }
    }
    ctx->pc = 0x1B5E5Cu;
    // 0x1b5e5c: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x1B5E5Cu;
    {
        const bool branch_taken_0x1b5e5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5E5Cu;
            // 0x1b5e60: 0x8c420018  lw          $v0, 0x18($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5e5c) {
            ctx->pc = 0x1B5FA0u;
            goto label_1b5fa0;
        }
    }
    ctx->pc = 0x1B5E64u;
label_1b5e64:
    // 0x1b5e64: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b5e64u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5e68: 0xa2880  sll         $a1, $t2, 2
    ctx->pc = 0x1b5e68u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
label_1b5e6c:
    // 0x1b5e6c: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x1b5e6cu;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5e70: 0xaa2821  addu        $a1, $a1, $t2
    ctx->pc = 0x1b5e70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 10)));
    // 0x1b5e74: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1b5e74u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1b5e78: 0xbd2821  addu        $a1, $a1, $sp
    ctx->pc = 0x1b5e78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
    // 0x1b5e7c: 0x24ac0190  addiu       $t4, $a1, 0x190
    ctx->pc = 0x1b5e7cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 5), 400));
label_1b5e80:
    // 0x1b5e80: 0x90890000  lbu         $t1, 0x0($a0)
    ctx->pc = 0x1b5e80u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b5e84: 0x18d5821  addu        $t3, $t4, $t5
    ctx->pc = 0x1b5e84u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 13)));
    // 0x1b5e88: 0x25ad0004  addiu       $t5, $t5, 0x4
    ctx->pc = 0x1b5e88u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 4));
    // 0x1b5e8c: 0x29a50014  slti        $a1, $t5, 0x14
    ctx->pc = 0x1b5e8cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 13) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1b5e90: 0x312700c0  andi        $a3, $t1, 0xC0
    ctx->pc = 0x1b5e90u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)192);
    // 0x1b5e94: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1b5e94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1b5e98: 0x74183  sra         $t0, $a3, 6
    ctx->pc = 0x1b5e98u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 7), 6));
    // 0x1b5e9c: 0x31270030  andi        $a3, $t1, 0x30
    ctx->pc = 0x1b5e9cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)48);
    // 0x1b5ea0: 0xa1680000  sb          $t0, 0x0($t3)
    ctx->pc = 0x1b5ea0u;
    WRITE8(ADD32(GPR_U32(ctx, 11), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x1b5ea4: 0x73903  sra         $a3, $a3, 4
    ctx->pc = 0x1b5ea4u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 4));
    // 0x1b5ea8: 0xa1670001  sb          $a3, 0x1($t3)
    ctx->pc = 0x1b5ea8u;
    WRITE8(ADD32(GPR_U32(ctx, 11), 1), (uint8_t)GPR_U32(ctx, 7));
    // 0x1b5eac: 0x3127000c  andi        $a3, $t1, 0xC
    ctx->pc = 0x1b5eacu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)12);
    // 0x1b5eb0: 0x74083  sra         $t0, $a3, 2
    ctx->pc = 0x1b5eb0u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 7), 2));
    // 0x1b5eb4: 0x31270003  andi        $a3, $t1, 0x3
    ctx->pc = 0x1b5eb4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)3);
    // 0x1b5eb8: 0xa1680002  sb          $t0, 0x2($t3)
    ctx->pc = 0x1b5eb8u;
    WRITE8(ADD32(GPR_U32(ctx, 11), 2), (uint8_t)GPR_U32(ctx, 8));
    // 0x1b5ebc: 0x14a0fff0  bnez        $a1, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1B5EBCu;
    {
        const bool branch_taken_0x1b5ebc = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5EBCu;
            // 0x1b5ec0: 0xa1670003  sb          $a3, 0x3($t3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 11), 3), (uint8_t)GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5ebc) {
            ctx->pc = 0x1B5E80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5e80;
        }
    }
    ctx->pc = 0x1B5EC4u;
    // 0x1b5ec4: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1b5ec4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1b5ec8: 0x29450014  slti        $a1, $t2, 0x14
    ctx->pc = 0x1b5ec8u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1b5ecc: 0x14a0ffe7  bnez        $a1, . + 4 + (-0x19 << 2)
    ctx->pc = 0x1B5ECCu;
    {
        const bool branch_taken_0x1b5ecc = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5ECCu;
            // 0x1b5ed0: 0xa2880  sll         $a1, $t2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5ecc) {
            ctx->pc = 0x1B5E6Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5e6c;
        }
    }
    ctx->pc = 0x1B5ED4u;
    // 0x1b5ed4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1b5ed4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5ed8: 0x82080  sll         $a0, $t0, 2
    ctx->pc = 0x1b5ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
label_1b5edc:
    // 0x1b5edc: 0x24070013  addiu       $a3, $zero, 0x13
    ctx->pc = 0x1b5edcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1b5ee0: 0x882821  addu        $a1, $a0, $t0
    ctx->pc = 0x1b5ee0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 8)));
    // 0x1b5ee4: 0xe82023  subu        $a0, $a3, $t0
    ctx->pc = 0x1b5ee4u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x1b5ee8: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1b5ee8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1b5eec: 0x9d2021  addu        $a0, $a0, $sp
    ctx->pc = 0x1b5eecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 29)));
    // 0x1b5ef0: 0xbd2821  addu        $a1, $a1, $sp
    ctx->pc = 0x1b5ef0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 29)));
    // 0x1b5ef4: 0x24890000  addiu       $t1, $a0, 0x0
    ctx->pc = 0x1b5ef4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 4), 0));
    // 0x1b5ef8: 0x24aa0190  addiu       $t2, $a1, 0x190
    ctx->pc = 0x1b5ef8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 5), 400));
label_1b5efc:
    // 0x1b5efc: 0x1472821  addu        $a1, $t2, $a3
    ctx->pc = 0x1b5efcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 7)));
    // 0x1b5f00: 0x72080  sll         $a0, $a3, 2
    ctx->pc = 0x1b5f00u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1b5f04: 0x90a50000  lbu         $a1, 0x0($a1)
    ctx->pc = 0x1b5f04u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1b5f08: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x1b5f08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1b5f0c: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1b5f0cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1b5f10: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x1b5f10u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1b5f14: 0x1242021  addu        $a0, $t1, $a0
    ctx->pc = 0x1b5f14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
    // 0x1b5f18: 0x4e1fff8  bgez        $a3, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1B5F18u;
    {
        const bool branch_taken_0x1b5f18 = (GPR_S64(ctx, 7) >= 0);
        ctx->pc = 0x1B5F1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5F18u;
            // 0x1b5f1c: 0xa0850000  sb          $a1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5f18) {
            ctx->pc = 0x1B5EFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5efc;
        }
    }
    ctx->pc = 0x1B5F20u;
    // 0x1b5f20: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1b5f20u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1b5f24: 0x29040014  slti        $a0, $t0, 0x14
    ctx->pc = 0x1b5f24u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1b5f28: 0x1480ffec  bnez        $a0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1B5F28u;
    {
        const bool branch_taken_0x1b5f28 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5F28u;
            // 0x1b5f2c: 0x82080  sll         $a0, $t0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5f28) {
            ctx->pc = 0x1B5EDCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5edc;
        }
    }
    ctx->pc = 0x1B5F30u;
    // 0x1b5f30: 0x582d  daddu       $t3, $zero, $zero
    ctx->pc = 0x1b5f30u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5f34: 0xb2080  sll         $a0, $t3, 2
    ctx->pc = 0x1b5f34u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 11), 2));
label_1b5f38:
    // 0x1b5f38: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1b5f38u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5f3c: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x1b5f3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x1b5f40: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1b5f40u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1b5f44: 0x9d2021  addu        $a0, $a0, $sp
    ctx->pc = 0x1b5f44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 29)));
    // 0x1b5f48: 0x248c0000  addiu       $t4, $a0, 0x0
    ctx->pc = 0x1b5f48u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 4), 0));
label_1b5f4c:
    // 0x1b5f4c: 0x18a2821  addu        $a1, $t4, $t2
    ctx->pc = 0x1b5f4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 10)));
    // 0x1b5f50: 0x90a90001  lbu         $t1, 0x1($a1)
    ctx->pc = 0x1b5f50u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x1b5f54: 0x254a0004  addiu       $t2, $t2, 0x4
    ctx->pc = 0x1b5f54u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4));
    // 0x1b5f58: 0x90a70002  lbu         $a3, 0x2($a1)
    ctx->pc = 0x1b5f58u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1b5f5c: 0x29440014  slti        $a0, $t2, 0x14
    ctx->pc = 0x1b5f5cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1b5f60: 0x90a80000  lbu         $t0, 0x0($a1)
    ctx->pc = 0x1b5f60u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1b5f64: 0x94900  sll         $t1, $t1, 4
    ctx->pc = 0x1b5f64u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 4));
    // 0x1b5f68: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1b5f68u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1b5f6c: 0x90a50003  lbu         $a1, 0x3($a1)
    ctx->pc = 0x1b5f6cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 3)));
    // 0x1b5f70: 0x1094025  or          $t0, $t0, $t1
    ctx->pc = 0x1b5f70u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 9));
    // 0x1b5f74: 0xe83825  or          $a3, $a3, $t0
    ctx->pc = 0x1b5f74u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 8));
    // 0x1b5f78: 0x52b00  sll         $a1, $a1, 12
    ctx->pc = 0x1b5f78u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 12));
    // 0x1b5f7c: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x1b5f7cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x1b5f80: 0xa4c50000  sh          $a1, 0x0($a2)
    ctx->pc = 0x1b5f80u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1b5f84: 0x1480fff1  bnez        $a0, . + 4 + (-0xF << 2)
    ctx->pc = 0x1B5F84u;
    {
        const bool branch_taken_0x1b5f84 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5F84u;
            // 0x1b5f88: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5f84) {
            ctx->pc = 0x1B5F4Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5f4c;
        }
    }
    ctx->pc = 0x1B5F8Cu;
    // 0x1b5f8c: 0x256b0001  addiu       $t3, $t3, 0x1
    ctx->pc = 0x1b5f8cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 1));
    // 0x1b5f90: 0x29640014  slti        $a0, $t3, 0x14
    ctx->pc = 0x1b5f90u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 11) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1b5f94: 0x1480ffe8  bnez        $a0, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1B5F94u;
    {
        const bool branch_taken_0x1b5f94 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5F94u;
            // 0x1b5f98: 0xb2080  sll         $a0, $t3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 11), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5f94) {
            ctx->pc = 0x1B5F38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5f38;
        }
    }
    ctx->pc = 0x1B5F9Cu;
    // 0x1b5f9c: 0x8c420018  lw          $v0, 0x18($v0)
    ctx->pc = 0x1b5f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
label_1b5fa0:
    // 0x1b5fa0: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1b5fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b5fa4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5FA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B5FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5FA4u;
            // 0x1b5fa8: 0x27bd0320  addiu       $sp, $sp, 0x320 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 800));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B5E14u: goto label_1b5e14;
            case 0x1B5E50u: goto label_1b5e50;
            case 0x1B5E64u: goto label_1b5e64;
            case 0x1B5E6Cu: goto label_1b5e6c;
            case 0x1B5E80u: goto label_1b5e80;
            case 0x1B5EDCu: goto label_1b5edc;
            case 0x1B5EFCu: goto label_1b5efc;
            case 0x1B5F38u: goto label_1b5f38;
            case 0x1B5F4Cu: goto label_1b5f4c;
            case 0x1B5FA0u: goto label_1b5fa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B5FACu;
    // 0x1b5fac: 0x0  nop
    ctx->pc = 0x1b5facu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
