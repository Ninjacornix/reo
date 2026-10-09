#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EAA1C
// Address: 0x1eaa1c - 0x1eacf8
void sub_001EAA1C_0x1eaa1c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EAA1C_0x1eaa1c");
#endif

    switch (ctx->pc) {
        case 0x1eaa9cu: goto label_1eaa9c;
        case 0x1eaac0u: goto label_1eaac0;
        case 0x1eaad8u: goto label_1eaad8;
        case 0x1eac1cu: goto label_1eac1c;
        default: break;
    }

    ctx->pc = 0x1eaa1cu;

    // 0x1eaa1c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1eaa1cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1eaa20: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1eaa20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1eaa24: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1eaa24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1eaa28: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1eaa28u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eaa2c: 0xafc4000c  sw          $a0, 0xC($fp)
    ctx->pc = 0x1eaa2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 4));
    // 0x1eaa30: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eaa30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eaa34: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eaa34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eaa38: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eaa38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaa3c: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1eaa3cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1eaa40: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1eaa40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1eaa44: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1EAA44u;
    {
        const bool branch_taken_0x1eaa44 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1eaa44) {
            ctx->pc = 0x1EAA58u;
            goto label_1eaa58;
        }
    }
    ctx->pc = 0x1EAA4Cu;
    // 0x1eaa4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1eaa4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1eaa50: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x1EAA50u;
    {
        const bool branch_taken_0x1eaa50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eaa50) {
            ctx->pc = 0x1EACE0u;
            goto label_1eace0;
        }
    }
    ctx->pc = 0x1EAA58u;
label_1eaa58:
    // 0x1eaa58: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eaa58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaa5c: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1eaa5cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1eaa60: 0x24020ff0  addiu       $v0, $zero, 0xFF0
    ctx->pc = 0x1eaa60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4080));
    // 0x1eaa64: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1EAA64u;
    {
        const bool branch_taken_0x1eaa64 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1eaa64) {
            ctx->pc = 0x1EAA78u;
            goto label_1eaa78;
        }
    }
    ctx->pc = 0x1EAA6Cu;
    // 0x1eaa6c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1eaa6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eaa70: 0x1000009b  b           . + 4 + (0x9B << 2)
    ctx->pc = 0x1EAA70u;
    {
        const bool branch_taken_0x1eaa70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eaa70) {
            ctx->pc = 0x1EACE0u;
            goto label_1eace0;
        }
    }
    ctx->pc = 0x1EAA78u;
label_1eaa78:
    // 0x1eaa78: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eaa78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaa7c: 0x84620000  lh          $v0, 0x0($v1)
    ctx->pc = 0x1eaa7cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1eaa80: 0x27c30002  addiu       $v1, $fp, 0x2
    ctx->pc = 0x1eaa80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 2));
    // 0x1eaa84: 0x27c60004  addiu       $a2, $fp, 0x4
    ctx->pc = 0x1eaa84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 4));
    // 0x1eaa88: 0x27c70006  addiu       $a3, $fp, 0x6
    ctx->pc = 0x1eaa88u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 6));
    // 0x1eaa8c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1eaa8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eaa90: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1eaa90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eaa94: 0xc075f48  jal         func_1D7D20
    ctx->pc = 0x1EAA94u;
    SET_GPR_U32(ctx, 31, 0x1EAA9Cu);
    ctx->pc = 0x1D7D20u;
    if (runtime->hasFunction(0x1D7D20u)) {
        auto targetFn = runtime->lookupFunction(0x1D7D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAA9Cu; }
        if (ctx->pc != 0x1EAA9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7D20_0x1d7d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAA9Cu; }
        if (ctx->pc != 0x1EAA9Cu) { return; }
    }
    ctx->pc = 0x1EAA9Cu;
label_1eaa9c:
    // 0x1eaa9c: 0xa7c20000  sh          $v0, 0x0($fp)
    ctx->pc = 0x1eaa9cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eaaa0: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1eaaa0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eaaa4: 0x441000c  bgez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1EAAA4u;
    {
        const bool branch_taken_0x1eaaa4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1eaaa4) {
            ctx->pc = 0x1EAAD8u;
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EAAACu;
    // 0x1eaaac: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eaaacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaab0: 0x84620000  lh          $v0, 0x0($v1)
    ctx->pc = 0x1eaab0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1eaab4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1eaab4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eaab8: 0xc075f18  jal         func_1D7C60
    ctx->pc = 0x1EAAB8u;
    SET_GPR_U32(ctx, 31, 0x1EAAC0u);
    ctx->pc = 0x1D7C60u;
    if (runtime->hasFunction(0x1D7C60u)) {
        auto targetFn = runtime->lookupFunction(0x1D7C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAAC0u; }
        if (ctx->pc != 0x1EAAC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7C60_0x1d7c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAAC0u; }
        if (ctx->pc != 0x1EAAC0u) { return; }
    }
    ctx->pc = 0x1EAAC0u;
label_1eaac0:
    // 0x1eaac0: 0x24020ff3  addiu       $v0, $zero, 0xFF3
    ctx->pc = 0x1eaac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4083));
    // 0x1eaac4: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eaac4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaac8: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1eaac8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eaacc: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1eaaccu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eaad0: 0x10000083  b           . + 4 + (0x83 << 2)
    ctx->pc = 0x1EAAD0u;
    {
        const bool branch_taken_0x1eaad0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eaad0) {
            ctx->pc = 0x1EACE0u;
            goto label_1eace0;
        }
    }
    ctx->pc = 0x1EAAD8u;
label_1eaad8:
    // 0x1eaad8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1eaad8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eaadc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1EAADCu;
    {
        const bool branch_taken_0x1eaadc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eaadc) {
            ctx->pc = 0x1EAAECu;
            goto label_1eaaec;
        }
    }
    ctx->pc = 0x1EAAE4u;
    // 0x1eaae4: 0x1000007d  b           . + 4 + (0x7D << 2)
    ctx->pc = 0x1EAAE4u;
    {
        const bool branch_taken_0x1eaae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eaae4) {
            ctx->pc = 0x1EACDCu;
            goto label_1eacdc;
        }
    }
    ctx->pc = 0x1EAAECu;
label_1eaaec:
    // 0x1eaaec: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1eaaecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1eaaf0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1eaaf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaaf4: 0x94420004  lhu         $v0, 0x4($v0)
    ctx->pc = 0x1eaaf4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1eaaf8: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1eaaf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1eaafc: 0x24020ff3  addiu       $v0, $zero, 0xFF3
    ctx->pc = 0x1eaafcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4083));
    // 0x1eab00: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eab00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eab04: 0x10620050  beq         $v1, $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x1EAB04u;
    {
        const bool branch_taken_0x1eab04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1eab04) {
            ctx->pc = 0x1EAC48u;
            goto label_1eac48;
        }
    }
    ctx->pc = 0x1EAB0Cu;
    // 0x1eab0c: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eab0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eab10: 0x28620ff4  slti        $v0, $v1, 0xFF4
    ctx->pc = 0x1eab10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4084) ? 1 : 0);
    // 0x1eab14: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1EAB14u;
    {
        const bool branch_taken_0x1eab14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eab14) {
            ctx->pc = 0x1EAB54u;
            goto label_1eab54;
        }
    }
    ctx->pc = 0x1EAB1Cu;
    // 0x1eab1c: 0x24020ff1  addiu       $v0, $zero, 0xFF1
    ctx->pc = 0x1eab1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4081));
    // 0x1eab20: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eab20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eab24: 0x10620019  beq         $v1, $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1EAB24u;
    {
        const bool branch_taken_0x1eab24 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1eab24) {
            ctx->pc = 0x1EAB8Cu;
            goto label_1eab8c;
        }
    }
    ctx->pc = 0x1EAB2Cu;
    // 0x1eab2c: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eab2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eab30: 0x28620ff2  slti        $v0, $v1, 0xFF2
    ctx->pc = 0x1eab30u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4082) ? 1 : 0);
    // 0x1eab34: 0x10400034  beqz        $v0, . + 4 + (0x34 << 2)
    ctx->pc = 0x1EAB34u;
    {
        const bool branch_taken_0x1eab34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eab34) {
            ctx->pc = 0x1EAC08u;
            goto label_1eac08;
        }
    }
    ctx->pc = 0x1EAB3Cu;
    // 0x1eab3c: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1eab3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1eab40: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eab40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eab44: 0x1062001c  beq         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1EAB44u;
    {
        const bool branch_taken_0x1eab44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1eab44) {
            ctx->pc = 0x1EABB8u;
            goto label_1eabb8;
        }
    }
    ctx->pc = 0x1EAB4Cu;
    // 0x1eab4c: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x1EAB4Cu;
    {
        const bool branch_taken_0x1eab4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eab4c) {
            ctx->pc = 0x1EACCCu;
            goto label_1eaccc;
        }
    }
    ctx->pc = 0x1EAB54u;
label_1eab54:
    // 0x1eab54: 0x24020ff5  addiu       $v0, $zero, 0xFF5
    ctx->pc = 0x1eab54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4085));
    // 0x1eab58: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eab58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eab5c: 0x10620047  beq         $v1, $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x1EAB5Cu;
    {
        const bool branch_taken_0x1eab5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1eab5c) {
            ctx->pc = 0x1EAC7Cu;
            goto label_1eac7c;
        }
    }
    ctx->pc = 0x1EAB64u;
    // 0x1eab64: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eab64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eab68: 0x28620ff5  slti        $v0, $v1, 0xFF5
    ctx->pc = 0x1eab68u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4085) ? 1 : 0);
    // 0x1eab6c: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1EAB6Cu;
    {
        const bool branch_taken_0x1eab6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eab6c) {
            ctx->pc = 0x1EABE0u;
            goto label_1eabe0;
        }
    }
    ctx->pc = 0x1EAB74u;
    // 0x1eab74: 0x24020ff6  addiu       $v0, $zero, 0xFF6
    ctx->pc = 0x1eab74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4086));
    // 0x1eab78: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1eab78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1eab7c: 0x10620049  beq         $v1, $v0, . + 4 + (0x49 << 2)
    ctx->pc = 0x1EAB7Cu;
    {
        const bool branch_taken_0x1eab7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1eab7c) {
            ctx->pc = 0x1EACA4u;
            goto label_1eaca4;
        }
    }
    ctx->pc = 0x1EAB84u;
    // 0x1eab84: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x1EAB84u;
    {
        const bool branch_taken_0x1eab84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eab84) {
            ctx->pc = 0x1EACCCu;
            goto label_1eaccc;
        }
    }
    ctx->pc = 0x1EAB8Cu;
label_1eab8c:
    // 0x1eab8c: 0x87c30002  lh          $v1, 0x2($fp)
    ctx->pc = 0x1eab8cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1eab90: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1eab90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1eab94: 0x1462ffd0  bne         $v1, $v0, . + 4 + (-0x30 << 2)
    ctx->pc = 0x1EAB94u;
    {
        const bool branch_taken_0x1eab94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1eab94) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EAB9Cu;
    // 0x1eab9c: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1eab9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1eaba0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eaba0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eaba4: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1eaba4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eaba8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eaba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eabac: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eabacu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eabb0: 0x1000ffc9  b           . + 4 + (-0x37 << 2)
    ctx->pc = 0x1EABB0u;
    {
        const bool branch_taken_0x1eabb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eabb0) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EABB8u;
label_1eabb8:
    // 0x1eabb8: 0x87c20006  lh          $v0, 0x6($fp)
    ctx->pc = 0x1eabb8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 6)));
    // 0x1eabbc: 0x1840ffc6  blez        $v0, . + 4 + (-0x3A << 2)
    ctx->pc = 0x1EABBCu;
    {
        const bool branch_taken_0x1eabbc = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1eabbc) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EABC4u;
    // 0x1eabc4: 0x24020ff4  addiu       $v0, $zero, 0xFF4
    ctx->pc = 0x1eabc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4084));
    // 0x1eabc8: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eabc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eabcc: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1eabccu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eabd0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eabd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eabd4: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eabd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eabd8: 0x1000ffbf  b           . + 4 + (-0x41 << 2)
    ctx->pc = 0x1EABD8u;
    {
        const bool branch_taken_0x1eabd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eabd8) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EABE0u;
label_1eabe0:
    // 0x1eabe0: 0x87c20006  lh          $v0, 0x6($fp)
    ctx->pc = 0x1eabe0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 6)));
    // 0x1eabe4: 0x1440ffbc  bnez        $v0, . + 4 + (-0x44 << 2)
    ctx->pc = 0x1EABE4u;
    {
        const bool branch_taken_0x1eabe4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eabe4) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EABECu;
    // 0x1eabec: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1eabecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1eabf0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eabf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eabf4: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1eabf4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eabf8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eabf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eabfc: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eabfcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eac00: 0x1000ffb5  b           . + 4 + (-0x4B << 2)
    ctx->pc = 0x1EAC00u;
    {
        const bool branch_taken_0x1eac00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eac00) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EAC08u;
label_1eac08:
    // 0x1eac08: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eac08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eac0c: 0x84620000  lh          $v0, 0x0($v1)
    ctx->pc = 0x1eac0cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1eac10: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1eac10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eac14: 0xc0760a4  jal         func_1D8290
    ctx->pc = 0x1EAC14u;
    SET_GPR_U32(ctx, 31, 0x1EAC1Cu);
    ctx->pc = 0x1D8290u;
    if (runtime->hasFunction(0x1D8290u)) {
        auto targetFn = runtime->lookupFunction(0x1D8290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAC1Cu; }
        if (ctx->pc != 0x1EAC1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8290_0x1d8290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EAC1Cu; }
        if (ctx->pc != 0x1EAC1Cu) { return; }
    }
    ctx->pc = 0x1EAC1Cu;
label_1eac1c:
    // 0x1eac1c: 0xa7c20000  sh          $v0, 0x0($fp)
    ctx->pc = 0x1eac1cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eac20: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1eac20u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eac24: 0x1440ffac  bnez        $v0, . + 4 + (-0x54 << 2)
    ctx->pc = 0x1EAC24u;
    {
        const bool branch_taken_0x1eac24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eac24) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EAC2Cu;
    // 0x1eac2c: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1eac2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1eac30: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eac30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eac34: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1eac34u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eac38: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eac38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eac3c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eac3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eac40: 0x1000ffa5  b           . + 4 + (-0x5B << 2)
    ctx->pc = 0x1EAC40u;
    {
        const bool branch_taken_0x1eac40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eac40) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EAC48u;
label_1eac48:
    // 0x1eac48: 0x87c20002  lh          $v0, 0x2($fp)
    ctx->pc = 0x1eac48u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 2)));
    // 0x1eac4c: 0x1440ffa2  bnez        $v0, . + 4 + (-0x5E << 2)
    ctx->pc = 0x1EAC4Cu;
    {
        const bool branch_taken_0x1eac4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eac4c) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EAC54u;
    // 0x1eac54: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1eac54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1eac58: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eac58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eac5c: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1eac5cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eac60: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1eac60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1eac64: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eac64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eac68: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1eac68u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eac6c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eac6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eac70: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eac70u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eac74: 0x1000ff98  b           . + 4 + (-0x68 << 2)
    ctx->pc = 0x1EAC74u;
    {
        const bool branch_taken_0x1eac74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eac74) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EAC7Cu;
label_1eac7c:
    // 0x1eac7c: 0x87c20006  lh          $v0, 0x6($fp)
    ctx->pc = 0x1eac7cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 6)));
    // 0x1eac80: 0x1840ff95  blez        $v0, . + 4 + (-0x6B << 2)
    ctx->pc = 0x1EAC80u;
    {
        const bool branch_taken_0x1eac80 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1eac80) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EAC88u;
    // 0x1eac88: 0x24020ff6  addiu       $v0, $zero, 0xFF6
    ctx->pc = 0x1eac88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4086));
    // 0x1eac8c: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eac8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eac90: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1eac90u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eac94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eac94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eac98: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eac98u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eac9c: 0x1000ff8e  b           . + 4 + (-0x72 << 2)
    ctx->pc = 0x1EAC9Cu;
    {
        const bool branch_taken_0x1eac9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eac9c) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EACA4u;
label_1eaca4:
    // 0x1eaca4: 0x87c20006  lh          $v0, 0x6($fp)
    ctx->pc = 0x1eaca4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 6)));
    // 0x1eaca8: 0x1440ff8b  bnez        $v0, . + 4 + (-0x75 << 2)
    ctx->pc = 0x1EACA8u;
    {
        const bool branch_taken_0x1eaca8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eaca8) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EACB0u;
    // 0x1eacb0: 0x24020ff5  addiu       $v0, $zero, 0xFF5
    ctx->pc = 0x1eacb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4085));
    // 0x1eacb4: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1eacb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eacb8: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1eacb8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eacbc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1eacbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1eacc0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1eacc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1eacc4: 0x1000ff84  b           . + 4 + (-0x7C << 2)
    ctx->pc = 0x1EACC4u;
    {
        const bool branch_taken_0x1eacc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eacc4) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EACCCu;
label_1eaccc:
    // 0x1eaccc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1eacccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1eacd0: 0xa7c20000  sh          $v0, 0x0($fp)
    ctx->pc = 0x1eacd0u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1eacd4: 0x1000ff80  b           . + 4 + (-0x80 << 2)
    ctx->pc = 0x1EACD4u;
    {
        const bool branch_taken_0x1eacd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eacd4) {
            ctx->pc = 0x1EAAD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eaad8;
        }
    }
    ctx->pc = 0x1EACDCu;
label_1eacdc:
    // 0x1eacdc: 0x87c20000  lh          $v0, 0x0($fp)
    ctx->pc = 0x1eacdcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
label_1eace0:
    // 0x1eace0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1eace0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eace4: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1eace4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1eace8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1eace8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1eacec: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1eacecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1eacf0: 0x3e00008  jr          $ra
    ctx->pc = 0x1EACF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EAA58u: goto label_1eaa58;
            case 0x1EAA78u: goto label_1eaa78;
            case 0x1EAA9Cu: goto label_1eaa9c;
            case 0x1EAAC0u: goto label_1eaac0;
            case 0x1EAAD8u: goto label_1eaad8;
            case 0x1EAAECu: goto label_1eaaec;
            case 0x1EAB54u: goto label_1eab54;
            case 0x1EAB8Cu: goto label_1eab8c;
            case 0x1EABB8u: goto label_1eabb8;
            case 0x1EABE0u: goto label_1eabe0;
            case 0x1EAC08u: goto label_1eac08;
            case 0x1EAC1Cu: goto label_1eac1c;
            case 0x1EAC48u: goto label_1eac48;
            case 0x1EAC7Cu: goto label_1eac7c;
            case 0x1EACA4u: goto label_1eaca4;
            case 0x1EACCCu: goto label_1eaccc;
            case 0x1EACDCu: goto label_1eacdc;
            case 0x1EACE0u: goto label_1eace0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EACF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
