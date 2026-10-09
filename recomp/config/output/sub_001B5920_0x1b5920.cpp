#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5920
// Address: 0x1b5920 - 0x1b5a44
void sub_001B5920_0x1b5920(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5920_0x1b5920");
#endif

    switch (ctx->pc) {
        case 0x1b5958u: goto label_1b5958;
        case 0x1b59f8u: goto label_1b59f8;
        case 0x1b5a04u: goto label_1b5a04;
        case 0x1b5a20u: goto label_1b5a20;
        default: break;
    }

    ctx->pc = 0x1b5920u;

    // 0x1b5920: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b5920u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b5924: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b5924u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b5928: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b5928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b592c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b592cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b5930: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b5930u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b5934: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b5934u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5938: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b5938u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b593c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1b593cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5940: 0x902243eb  lbu         $v0, 0x43EB($at)
    ctx->pc = 0x1b5940u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17387)));
    // 0x1b5944: 0x3c10002c  lui         $s0, 0x2C
    ctx->pc = 0x1b5944u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)44 << 16));
    // 0x1b5948: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B5948u;
    {
        const bool branch_taken_0x1b5948 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B594Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5948u;
            // 0x1b594c: 0x2610aa40  addiu       $s0, $s0, -0x55C0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5948) {
            ctx->pc = 0x1B5958u;
            goto label_1b5958;
        }
    }
    ctx->pc = 0x1B5950u;
    // 0x1b5950: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1B5950u;
    {
        const bool branch_taken_0x1b5950 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5950u;
            // 0x1b5954: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5950) {
            ctx->pc = 0x1B5A2Cu;
            goto label_1b5a2c;
        }
    }
    ctx->pc = 0x1B5958u;
label_1b5958:
    // 0x1b5958: 0xae000084  sw          $zero, 0x84($s0)
    ctx->pc = 0x1b5958u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 0));
    // 0x1b595c: 0x92440000  lbu         $a0, 0x0($s2)
    ctx->pc = 0x1b595cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1b5960: 0x10800031  beqz        $a0, . + 4 + (0x31 << 2)
    ctx->pc = 0x1B5960u;
    {
        const bool branch_taken_0x1b5960 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5960u;
            // 0x1b5964: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5960) {
            ctx->pc = 0x1B5A28u;
            goto label_1b5a28;
        }
    }
    ctx->pc = 0x1B5968u;
    // 0x1b5968: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1b5968u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1b596c: 0x1082fffa  beq         $a0, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1B596Cu;
    {
        const bool branch_taken_0x1b596c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B5970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B596Cu;
            // 0x1b5970: 0x2c820080  sltiu       $v0, $a0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b596c) {
            ctx->pc = 0x1B5958u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5958;
        }
    }
    ctx->pc = 0x1B5974u;
    // 0x1b5974: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B5974u;
    {
        const bool branch_taken_0x1b5974 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5974u;
            // 0x1b5978: 0x2c8100a0  sltiu       $at, $a0, 0xA0 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)160) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5974) {
            ctx->pc = 0x1B5984u;
            goto label_1b5984;
        }
    }
    ctx->pc = 0x1B597Cu;
    // 0x1b597c: 0x14200006  bnez        $at, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B597Cu;
    {
        const bool branch_taken_0x1b597c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b597c) {
            ctx->pc = 0x1B5998u;
            goto label_1b5998;
        }
    }
    ctx->pc = 0x1B5984u;
label_1b5984:
    // 0x1b5984: 0x2c8200e0  sltiu       $v0, $a0, 0xE0
    ctx->pc = 0x1b5984u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)224) ? 1 : 0);
    // 0x1b5988: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B5988u;
    {
        const bool branch_taken_0x1b5988 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B598Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5988u;
            // 0x1b598c: 0x2c810100  sltiu       $at, $a0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5988) {
            ctx->pc = 0x1B59ECu;
            goto label_1b59ec;
        }
    }
    ctx->pc = 0x1B5990u;
    // 0x1b5990: 0x10200016  beqz        $at, . + 4 + (0x16 << 2)
    ctx->pc = 0x1B5990u;
    {
        const bool branch_taken_0x1b5990 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b5990) {
            ctx->pc = 0x1B59ECu;
            goto label_1b59ec;
        }
    }
    ctx->pc = 0x1B5998u;
label_1b5998:
    // 0x1b5998: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1b5998u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1b599c: 0x10600022  beqz        $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x1B599Cu;
    {
        const bool branch_taken_0x1b599c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B59A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B599Cu;
            // 0x1b59a0: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b599c) {
            ctx->pc = 0x1B5A28u;
            goto label_1b5a28;
        }
    }
    ctx->pc = 0x1B59A4u;
    // 0x1b59a4: 0x41200  sll         $v0, $a0, 8
    ctx->pc = 0x1b59a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1b59a8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1b59a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1b59ac: 0x24438000  addiu       $v1, $v0, -0x8000
    ctx->pc = 0x1b59acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294934528));
    // 0x1b59b0: 0x2463fea5  addiu       $v1, $v1, -0x15B
    ctx->pc = 0x1b59b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966949));
    // 0x1b59b4: 0x2c610002  sltiu       $at, $v1, 0x2
    ctx->pc = 0x1b59b4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x1b59b8: 0x14200009  bnez        $at, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B59B8u;
    {
        const bool branch_taken_0x1b59b8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b59b8) {
            ctx->pc = 0x1B59E0u;
            goto label_1b59e0;
        }
    }
    ctx->pc = 0x1B59C0u;
    // 0x1b59c0: 0x34038160  ori         $v1, $zero, 0x8160
    ctx->pc = 0x1b59c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33120);
    // 0x1b59c4: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B59C4u;
    {
        const bool branch_taken_0x1b59c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B59C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B59C4u;
            // 0x1b59c8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b59c4) {
            ctx->pc = 0x1B59E4u;
            goto label_1b59e4;
        }
    }
    ctx->pc = 0x1B59CCu;
    // 0x1b59cc: 0x34038175  ori         $v1, $zero, 0x8175
    ctx->pc = 0x1b59ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33141);
    // 0x1b59d0: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B59D0u;
    {
        const bool branch_taken_0x1b59d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B59D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B59D0u;
            // 0x1b59d4: 0x34038176  ori         $v1, $zero, 0x8176 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33142);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b59d0) {
            ctx->pc = 0x1B59E0u;
            goto label_1b59e0;
        }
    }
    ctx->pc = 0x1B59D8u;
    // 0x1b59d8: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B59D8u;
    {
        const bool branch_taken_0x1b59d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1b59d8) {
            ctx->pc = 0x1B59F8u;
            goto label_1b59f8;
        }
    }
    ctx->pc = 0x1B59E0u;
label_1b59e0:
    // 0x1b59e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b59e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b59e4:
    // 0x1b59e4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B59E4u;
    {
        const bool branch_taken_0x1b59e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B59E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B59E4u;
            // 0x1b59e8: 0xae030084  sw          $v1, 0x84($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b59e4) {
            ctx->pc = 0x1B59F8u;
            goto label_1b59f8;
        }
    }
    ctx->pc = 0x1B59ECu;
label_1b59ec:
    // 0x1b59ec: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x1b59ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1b59f0: 0xc06d960  jal         func_1B6580
    ctx->pc = 0x1B59F0u;
    SET_GPR_U32(ctx, 31, 0x1B59F8u);
    ctx->pc = 0x1B59F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B59F0u;
            // 0x1b59f4: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B6580u;
    if (runtime->hasFunction(0x1B6580u)) {
        auto targetFn = runtime->lookupFunction(0x1B6580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B59F8u; }
        if (ctx->pc != 0x1B59F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6580_0x1b6580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B59F8u; }
        if (ctx->pc != 0x1B59F8u) { return; }
    }
    ctx->pc = 0x1B59F8u;
label_1b59f8:
    // 0x1b59f8: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x1b59f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1b59fc: 0xc06d93c  jal         func_1B64F0
    ctx->pc = 0x1B59FCu;
    SET_GPR_U32(ctx, 31, 0x1B5A04u);
    ctx->pc = 0x1B5A00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B59FCu;
            // 0x1b5a00: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B64F0u;
    if (runtime->hasFunction(0x1B64F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B64F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5A04u; }
        if (ctx->pc != 0x1B5A04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B64F0_0x1b64f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5A04u; }
        if (ctx->pc != 0x1B5A04u) { return; }
    }
    ctx->pc = 0x1B5A04u;
label_1b5a04:
    // 0x1b5a04: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x1b5a04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1b5a08: 0x43082b  sltu        $at, $v0, $v1
    ctx->pc = 0x1b5a08u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1b5a0c: 0x1020ffd2  beqz        $at, . + 4 + (-0x2E << 2)
    ctx->pc = 0x1B5A0Cu;
    {
        const bool branch_taken_0x1b5a0c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5A0Cu;
            // 0x1b5a10: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5a0c) {
            ctx->pc = 0x1B5958u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5958;
        }
    }
    ctx->pc = 0x1B5A14u;
    // 0x1b5a14: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b5a14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b5a18: 0xc06d770  jal         func_1B5DC0
    ctx->pc = 0x1B5A18u;
    SET_GPR_U32(ctx, 31, 0x1B5A20u);
    ctx->pc = 0x1B5A1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5A18u;
            // 0x1b5a1c: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5DC0u;
    if (runtime->hasFunction(0x1B5DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1B5DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5A20u; }
        if (ctx->pc != 0x1B5A20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5DC0_0x1b5dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B5A20u; }
        if (ctx->pc != 0x1B5A20u) { return; }
    }
    ctx->pc = 0x1B5A20u;
label_1b5a20:
    // 0x1b5a20: 0x1000ffcd  b           . + 4 + (-0x33 << 2)
    ctx->pc = 0x1B5A20u;
    {
        const bool branch_taken_0x1b5a20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5A20u;
            // 0x1b5a24: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5a20) {
            ctx->pc = 0x1B5958u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b5958;
        }
    }
    ctx->pc = 0x1B5A28u;
label_1b5a28:
    // 0x1b5a28: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1b5a28u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1b5a2c:
    // 0x1b5a2c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b5a2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b5a30: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b5a30u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b5a34: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b5a34u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b5a38: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b5a38u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b5a3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5A3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B5A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5A3Cu;
            // 0x1b5a40: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B5958u: goto label_1b5958;
            case 0x1B5984u: goto label_1b5984;
            case 0x1B5998u: goto label_1b5998;
            case 0x1B59E0u: goto label_1b59e0;
            case 0x1B59E4u: goto label_1b59e4;
            case 0x1B59ECu: goto label_1b59ec;
            case 0x1B59F8u: goto label_1b59f8;
            case 0x1B5A04u: goto label_1b5a04;
            case 0x1B5A20u: goto label_1b5a20;
            case 0x1B5A28u: goto label_1b5a28;
            case 0x1B5A2Cu: goto label_1b5a2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B5A44u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
