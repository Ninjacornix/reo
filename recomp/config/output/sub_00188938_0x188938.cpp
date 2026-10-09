#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188938
// Address: 0x188938 - 0x188b78
void sub_00188938_0x188938(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188938_0x188938");
#endif

    switch (ctx->pc) {
        case 0x188978u: goto label_188978;
        case 0x188980u: goto label_188980;
        case 0x188988u: goto label_188988;
        case 0x1889bcu: goto label_1889bc;
        case 0x1889d8u: goto label_1889d8;
        case 0x1889e0u: goto label_1889e0;
        case 0x188a14u: goto label_188a14;
        case 0x188a30u: goto label_188a30;
        case 0x188a38u: goto label_188a38;
        case 0x188a6cu: goto label_188a6c;
        case 0x188a88u: goto label_188a88;
        case 0x188aa4u: goto label_188aa4;
        case 0x188ac0u: goto label_188ac0;
        case 0x188ae0u: goto label_188ae0;
        case 0x188af8u: goto label_188af8;
        case 0x188b10u: goto label_188b10;
        case 0x188b44u: goto label_188b44;
        case 0x188b4cu: goto label_188b4c;
        default: break;
    }

    ctx->pc = 0x188938u;

    // 0x188938: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x188938u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x18893c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x18893cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188940: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x188940u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x188944: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x188944u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x188948: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x188948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x18894c: 0x8e62fd38  lw          $v0, -0x2C8($s3)
    ctx->pc = 0x18894cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4294966584)));
    // 0x188950: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x188950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x188954: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x188954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x188958: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x188958u;
    {
        const bool branch_taken_0x188958 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x18895Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188958u;
            // 0x18895c: 0xffb00020  sd          $s0, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188958) {
            ctx->pc = 0x188968u;
            goto label_188968;
        }
    }
    ctx->pc = 0x188960u;
    // 0x188960: 0x1000007d  b           . + 4 + (0x7D << 2)
    ctx->pc = 0x188960u;
    {
        const bool branch_taken_0x188960 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188960u;
            // 0x188964: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188960) {
            ctx->pc = 0x188B58u;
            goto label_188b58;
        }
    }
    ctx->pc = 0x188968u;
label_188968:
    // 0x188968: 0x3c120029  lui         $s2, 0x29
    ctx->pc = 0x188968u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)41 << 16));
    // 0x18896c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18896cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188970: 0xc045c20  jal         func_117080
    ctx->pc = 0x188970u;
    SET_GPR_U32(ctx, 31, 0x188978u);
    ctx->pc = 0x188974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188970u;
            // 0x188974: 0xae404140  sw          $zero, 0x4140($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 16704), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188978u; }
        if (ctx->pc != 0x188978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188978u; }
        if (ctx->pc != 0x188978u) { return; }
    }
    ctx->pc = 0x188978u;
label_188978:
    // 0x188978: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x188978u;
    {
        const bool branch_taken_0x188978 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18897Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188978u;
            // 0x18897c: 0x3c110029  lui         $s1, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188978) {
            ctx->pc = 0x1889A4u;
            goto label_1889a4;
        }
    }
    ctx->pc = 0x188980u;
label_188980:
    // 0x188980: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x188980u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x188984: 0x0  nop
    ctx->pc = 0x188984u;
    // NOP
label_188988:
    // 0x188988: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x188988u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18898c: 0x0  nop
    ctx->pc = 0x18898cu;
    // NOP
    // 0x188990: 0x0  nop
    ctx->pc = 0x188990u;
    // NOP
    // 0x188994: 0x0  nop
    ctx->pc = 0x188994u;
    // NOP
    // 0x188998: 0x0  nop
    ctx->pc = 0x188998u;
    // NOP
    // 0x18899c: 0x1462fffa  bne         $v1, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x18899Cu;
    {
        const bool branch_taken_0x18899c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x18899c) {
            ctx->pc = 0x188988u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188988;
        }
    }
    ctx->pc = 0x1889A4u;
label_1889a4:
    // 0x1889a4: 0x26300b88  addiu       $s0, $s1, 0xB88
    ctx->pc = 0x1889a4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 2952));
    // 0x1889a8: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x1889a8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x1889ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1889acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1889b0: 0x34a51300  ori         $a1, $a1, 0x1300
    ctx->pc = 0x1889b0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4864);
    // 0x1889b4: 0xc045e06  jal         func_117818
    ctx->pc = 0x1889B4u;
    SET_GPR_U32(ctx, 31, 0x1889BCu);
    ctx->pc = 0x1889B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1889B4u;
            // 0x1889b8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1889BCu; }
        if (ctx->pc != 0x1889BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1889BCu; }
        if (ctx->pc != 0x1889BCu) { return; }
    }
    ctx->pc = 0x1889BCu;
label_1889bc:
    // 0x1889bc: 0x440004c  bltz        $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x1889BCu;
    {
        const bool branch_taken_0x1889bc = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1889C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1889BCu;
            // 0x1889c0: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1889bc) {
            ctx->pc = 0x188AF0u;
            goto label_188af0;
        }
    }
    ctx->pc = 0x1889C4u;
    // 0x1889c4: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x1889c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1889c8: 0x1040ffed  beqz        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1889C8u;
    {
        const bool branch_taken_0x1889c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1889CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1889C8u;
            // 0x1889cc: 0x3c030001  lui         $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1889c8) {
            ctx->pc = 0x188980u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188980;
        }
    }
    ctx->pc = 0x1889D0u;
    // 0x1889d0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1889D0u;
    {
        const bool branch_taken_0x1889d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1889D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1889D0u;
            // 0x1889d4: 0x3c110029  lui         $s1, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1889d0) {
            ctx->pc = 0x1889FCu;
            goto label_1889fc;
        }
    }
    ctx->pc = 0x1889D8u;
label_1889d8:
    // 0x1889d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1889d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1889dc: 0x0  nop
    ctx->pc = 0x1889dcu;
    // NOP
label_1889e0:
    // 0x1889e0: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1889e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1889e4: 0x0  nop
    ctx->pc = 0x1889e4u;
    // NOP
    // 0x1889e8: 0x0  nop
    ctx->pc = 0x1889e8u;
    // NOP
    // 0x1889ec: 0x0  nop
    ctx->pc = 0x1889ecu;
    // NOP
    // 0x1889f0: 0x0  nop
    ctx->pc = 0x1889f0u;
    // NOP
    // 0x1889f4: 0x1462fffa  bne         $v1, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1889F4u;
    {
        const bool branch_taken_0x1889f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1889f4) {
            ctx->pc = 0x1889E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1889e0;
        }
    }
    ctx->pc = 0x1889FCu;
label_1889fc:
    // 0x1889fc: 0x26300bb0  addiu       $s0, $s1, 0xBB0
    ctx->pc = 0x1889fcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 2992));
    // 0x188a00: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x188a00u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x188a04: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x188a04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188a08: 0x34a5131b  ori         $a1, $a1, 0x131B
    ctx->pc = 0x188a08u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4891);
    // 0x188a0c: 0xc045e06  jal         func_117818
    ctx->pc = 0x188A0Cu;
    SET_GPR_U32(ctx, 31, 0x188A14u);
    ctx->pc = 0x188A10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188A0Cu;
            // 0x188a10: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188A14u; }
        if (ctx->pc != 0x188A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188A14u; }
        if (ctx->pc != 0x188A14u) { return; }
    }
    ctx->pc = 0x188A14u;
label_188a14:
    // 0x188a14: 0x4400036  bltz        $v0, . + 4 + (0x36 << 2)
    ctx->pc = 0x188A14u;
    {
        const bool branch_taken_0x188a14 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x188A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188A14u;
            // 0x188a18: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188a14) {
            ctx->pc = 0x188AF0u;
            goto label_188af0;
        }
    }
    ctx->pc = 0x188A1Cu;
    // 0x188a1c: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x188a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x188a20: 0x1040ffed  beqz        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x188A20u;
    {
        const bool branch_taken_0x188a20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x188A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188A20u;
            // 0x188a24: 0x3c030001  lui         $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188a20) {
            ctx->pc = 0x1889D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1889d8;
        }
    }
    ctx->pc = 0x188A28u;
    // 0x188a28: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x188A28u;
    {
        const bool branch_taken_0x188a28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188A28u;
            // 0x188a2c: 0x3c110029  lui         $s1, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188a28) {
            ctx->pc = 0x188A54u;
            goto label_188a54;
        }
    }
    ctx->pc = 0x188A30u;
label_188a30:
    // 0x188a30: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x188a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x188a34: 0x0  nop
    ctx->pc = 0x188a34u;
    // NOP
label_188a38:
    // 0x188a38: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x188a38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x188a3c: 0x0  nop
    ctx->pc = 0x188a3cu;
    // NOP
    // 0x188a40: 0x0  nop
    ctx->pc = 0x188a40u;
    // NOP
    // 0x188a44: 0x0  nop
    ctx->pc = 0x188a44u;
    // NOP
    // 0x188a48: 0x0  nop
    ctx->pc = 0x188a48u;
    // NOP
    // 0x188a4c: 0x1462fffa  bne         $v1, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x188A4Cu;
    {
        const bool branch_taken_0x188a4c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x188a4c) {
            ctx->pc = 0x188A38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188a38;
        }
    }
    ctx->pc = 0x188A54u;
label_188a54:
    // 0x188a54: 0x26300bd8  addiu       $s0, $s1, 0xBD8
    ctx->pc = 0x188a54u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 3032));
    // 0x188a58: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x188a58u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x188a5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x188a5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188a60: 0x34a5131c  ori         $a1, $a1, 0x131C
    ctx->pc = 0x188a60u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4892);
    // 0x188a64: 0xc045e06  jal         func_117818
    ctx->pc = 0x188A64u;
    SET_GPR_U32(ctx, 31, 0x188A6Cu);
    ctx->pc = 0x188A68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188A64u;
            // 0x188a68: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117818u;
    if (runtime->hasFunction(0x117818u)) {
        auto targetFn = runtime->lookupFunction(0x117818u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188A6Cu; }
        if (ctx->pc != 0x188A6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188A6Cu; }
        if (ctx->pc != 0x188A6Cu) { return; }
    }
    ctx->pc = 0x188A6Cu;
label_188a6c:
    // 0x188a6c: 0x4400020  bltz        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x188A6Cu;
    {
        const bool branch_taken_0x188a6c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x188A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188A6Cu;
            // 0x188a70: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188a6c) {
            ctx->pc = 0x188AF0u;
            goto label_188af0;
        }
    }
    ctx->pc = 0x188A74u;
    // 0x188a74: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x188a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x188a78: 0x1040ffed  beqz        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x188A78u;
    {
        const bool branch_taken_0x188a78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x188A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188A78u;
            // 0x188a7c: 0x3c030001  lui         $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188a78) {
            ctx->pc = 0x188A30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188a30;
        }
    }
    ctx->pc = 0x188A80u;
    // 0x188a80: 0xc062238  jal         func_1888E0
    ctx->pc = 0x188A80u;
    SET_GPR_U32(ctx, 31, 0x188A88u);
    ctx->pc = 0x1888E0u;
    if (runtime->hasFunction(0x1888E0u)) {
        auto targetFn = runtime->lookupFunction(0x1888E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188A88u; }
        if (ctx->pc != 0x188A88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888E0_0x1888e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188A88u; }
        if (ctx->pc != 0x188A88u) { return; }
    }
    ctx->pc = 0x188A88u;
label_188a88:
    // 0x188a88: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x188a88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188a8c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x188a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x188a90: 0x118203  sra         $s0, $s1, 8
    ctx->pc = 0x188a90u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 17), 8));
    // 0x188a94: 0x1202000c  beq         $s0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x188A94u;
    {
        const bool branch_taken_0x188a94 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x188A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188A94u;
            // 0x188a98: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188a94) {
            ctx->pc = 0x188AC8u;
            goto label_188ac8;
        }
    }
    ctx->pc = 0x188A9Cu;
    // 0x188a9c: 0xc045a12  jal         func_116848
    ctx->pc = 0x188A9Cu;
    SET_GPR_U32(ctx, 31, 0x188AA4u);
    ctx->pc = 0x188AA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188A9Cu;
            // 0x188aa0: 0x24841890  addiu       $a0, $a0, 0x1890 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188AA4u; }
        if (ctx->pc != 0x188AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188AA4u; }
        if (ctx->pc != 0x188AA4u) { return; }
    }
    ctx->pc = 0x188AA4u;
label_188aa4:
    // 0x188aa4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x188aa4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x188aa8: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x188aa8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188aac: 0x248418b8  addiu       $a0, $a0, 0x18B8
    ctx->pc = 0x188aacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6328));
    // 0x188ab0: 0x322800ff  andi        $t0, $s1, 0xFF
    ctx->pc = 0x188ab0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x188ab4: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x188ab4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x188ab8: 0xc045a12  jal         func_116848
    ctx->pc = 0x188AB8u;
    SET_GPR_U32(ctx, 31, 0x188AC0u);
    ctx->pc = 0x188ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188AB8u;
            // 0x188abc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188AC0u; }
        if (ctx->pc != 0x188AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188AC0u; }
        if (ctx->pc != 0x188AC0u) { return; }
    }
    ctx->pc = 0x188AC0u;
label_188ac0:
    // 0x188ac0: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x188AC0u;
    {
        const bool branch_taken_0x188ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188AC0u;
            // 0x188ac4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188ac0) {
            ctx->pc = 0x188B58u;
            goto label_188b58;
        }
    }
    ctx->pc = 0x188AC8u;
label_188ac8:
    // 0x188ac8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x188ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188acc: 0x2403007f  addiu       $v1, $zero, 0x7F
    ctx->pc = 0x188accu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x188ad0: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x188ad0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x188ad4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x188ad4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188ad8: 0xc045188  jal         func_114620
    ctx->pc = 0x188AD8u;
    SET_GPR_U32(ctx, 31, 0x188AE0u);
    ctx->pc = 0x188ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188AD8u;
            // 0x188adc: 0xafa30004  sw          $v1, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188AE0u; }
        if (ctx->pc != 0x188AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188AE0u; }
        if (ctx->pc != 0x188AE0u) { return; }
    }
    ctx->pc = 0x188AE0u;
label_188ae0:
    // 0x188ae0: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x188AE0u;
    {
        const bool branch_taken_0x188ae0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x188AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188AE0u;
            // 0x188ae4: 0xae424140  sw          $v0, 0x4140($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 16704), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188ae0) {
            ctx->pc = 0x188B00u;
            goto label_188b00;
        }
    }
    ctx->pc = 0x188AE8u;
    // 0x188ae8: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x188AE8u;
    {
        const bool branch_taken_0x188ae8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188AE8u;
            // 0x188aec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188ae8) {
            ctx->pc = 0x188B58u;
            goto label_188b58;
        }
    }
    ctx->pc = 0x188AF0u;
label_188af0:
    // 0x188af0: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x188AF0u;
    SET_GPR_U32(ctx, 31, 0x188AF8u);
    ctx->pc = 0x188AF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188AF0u;
            // 0x188af4: 0x24841878  addiu       $a0, $a0, 0x1878 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188AF8u; }
        if (ctx->pc != 0x188AF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188AF8u; }
        if (ctx->pc != 0x188AF8u) { return; }
    }
    ctx->pc = 0x188AF8u;
label_188af8:
    // 0x188af8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x188AF8u;
    {
        const bool branch_taken_0x188af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188AF8u;
            // 0x188afc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188af8) {
            ctx->pc = 0x188B58u;
            goto label_188b58;
        }
    }
    ctx->pc = 0x188B00u;
label_188b00:
    // 0x188b00: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x188b00u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188b04: 0x2403000f  addiu       $v1, $zero, 0xF
    ctx->pc = 0x188b04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x188b08: 0x24424100  addiu       $v0, $v0, 0x4100
    ctx->pc = 0x188b08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16640));
    // 0x188b0c: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x188b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
label_188b10:
    // 0x188b10: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x188b10u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x188b14: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x188b14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x188b18: 0x2442fffc  addiu       $v0, $v0, -0x4
    ctx->pc = 0x188b18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x188b1c: 0x0  nop
    ctx->pc = 0x188b1cu;
    // NOP
    // 0x188b20: 0x0  nop
    ctx->pc = 0x188b20u;
    // NOP
    // 0x188b24: 0x461fffa  bgez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x188B24u;
    {
        const bool branch_taken_0x188b24 = (GPR_S64(ctx, 3) >= 0);
        if (branch_taken_0x188b24) {
            ctx->pc = 0x188B10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_188b10;
        }
    }
    ctx->pc = 0x188B2Cu;
    // 0x188b2c: 0x3c100029  lui         $s0, 0x29
    ctx->pc = 0x188b2cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)41 << 16));
    // 0x188b30: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x188b30u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x188b34: 0x26104080  addiu       $s0, $s0, 0x4080
    ctx->pc = 0x188b34u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16512));
    // 0x188b38: 0x248418e0  addiu       $a0, $a0, 0x18E0
    ctx->pc = 0x188b38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6368));
    // 0x188b3c: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x188B3Cu;
    SET_GPR_U32(ctx, 31, 0x188B44u);
    ctx->pc = 0x188B40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188B3Cu;
            // 0x188b40: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188B44u; }
        if (ctx->pc != 0x188B44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188B44u; }
        if (ctx->pc != 0x188B44u) { return; }
    }
    ctx->pc = 0x188B44u;
label_188b44:
    // 0x188b44: 0xc0622f0  jal         func_188BC0
    ctx->pc = 0x188B44u;
    SET_GPR_U32(ctx, 31, 0x188B4Cu);
    ctx->pc = 0x188B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x188B44u;
            // 0x188b48: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188BC0u;
    if (runtime->hasFunction(0x188BC0u)) {
        auto targetFn = runtime->lookupFunction(0x188BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188B4Cu; }
        if (ctx->pc != 0x188B4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188BC0_0x188bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188B4Cu; }
        if (ctx->pc != 0x188B4Cu) { return; }
    }
    ctx->pc = 0x188B4Cu;
label_188b4c:
    // 0x188b4c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x188b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188b50: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x188b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x188b54: 0xae63fd38  sw          $v1, -0x2C8($s3)
    ctx->pc = 0x188b54u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294966584), GPR_U32(ctx, 3));
label_188b58:
    // 0x188b58: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x188b58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x188b5c: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x188b5cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x188b60: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x188b60u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x188b64: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x188b64u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x188b68: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x188b68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188b6c: 0x3e00008  jr          $ra
    ctx->pc = 0x188B6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188B6Cu;
            // 0x188b70: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188968u: goto label_188968;
            case 0x188978u: goto label_188978;
            case 0x188980u: goto label_188980;
            case 0x188988u: goto label_188988;
            case 0x1889A4u: goto label_1889a4;
            case 0x1889BCu: goto label_1889bc;
            case 0x1889D8u: goto label_1889d8;
            case 0x1889E0u: goto label_1889e0;
            case 0x1889FCu: goto label_1889fc;
            case 0x188A14u: goto label_188a14;
            case 0x188A30u: goto label_188a30;
            case 0x188A38u: goto label_188a38;
            case 0x188A54u: goto label_188a54;
            case 0x188A6Cu: goto label_188a6c;
            case 0x188A88u: goto label_188a88;
            case 0x188AA4u: goto label_188aa4;
            case 0x188AC0u: goto label_188ac0;
            case 0x188AC8u: goto label_188ac8;
            case 0x188AE0u: goto label_188ae0;
            case 0x188AF0u: goto label_188af0;
            case 0x188AF8u: goto label_188af8;
            case 0x188B00u: goto label_188b00;
            case 0x188B10u: goto label_188b10;
            case 0x188B44u: goto label_188b44;
            case 0x188B4Cu: goto label_188b4c;
            case 0x188B58u: goto label_188b58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188B74u;
    // 0x188b74: 0x0  nop
    ctx->pc = 0x188b74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
