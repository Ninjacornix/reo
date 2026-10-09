#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BBFA0
// Address: 0x1bbfa0 - 0x1bc0f0
void sub_001BBFA0_0x1bbfa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BBFA0_0x1bbfa0");
#endif

    switch (ctx->pc) {
        case 0x1bbfb8u: goto label_1bbfb8;
        default: break;
    }

    ctx->pc = 0x1bbfa0u;

    // 0x1bbfa0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1bbfa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1bbfa4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1bbfa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1bbfa8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bbfa8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bbfac: 0x3c100031  lui         $s0, 0x31
    ctx->pc = 0x1bbfacu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49 << 16));
    // 0x1bbfb0: 0xc06f0e8  jal         func_1BC3A0
    ctx->pc = 0x1BBFB0u;
    SET_GPR_U32(ctx, 31, 0x1BBFB8u);
    ctx->pc = 0x1BBFB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBFB0u;
            // 0x1bbfb4: 0x261065e0  addiu       $s0, $s0, 0x65E0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 26080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BC3A0u;
    if (runtime->hasFunction(0x1BC3A0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC3A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBFB8u; }
        if (ctx->pc != 0x1BBFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC3A0_0x1bc3a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BBFB8u; }
        if (ctx->pc != 0x1BBFB8u) { return; }
    }
    ctx->pc = 0x1BBFB8u;
label_1bbfb8:
    // 0x1bbfb8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbfb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbfbc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1bbfbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bbfc0: 0x902465e0  lbu         $a0, 0x65E0($at)
    ctx->pc = 0x1bbfc0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26080)));
    // 0x1bbfc4: 0x1083000b  beq         $a0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1BBFC4u;
    {
        const bool branch_taken_0x1bbfc4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bbfc4) {
            ctx->pc = 0x1BBFF4u;
            goto label_1bbff4;
        }
    }
    ctx->pc = 0x1BBFCCu;
    // 0x1bbfcc: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BBFCCu;
    {
        const bool branch_taken_0x1bbfcc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bbfcc) {
            ctx->pc = 0x1BBFDCu;
            goto label_1bbfdc;
        }
    }
    ctx->pc = 0x1BBFD4u;
    // 0x1bbfd4: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1BBFD4u;
    {
        const bool branch_taken_0x1bbfd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BBFD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBFD4u;
            // 0x1bbfd8: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bbfd4) {
            ctx->pc = 0x1BC0DCu;
            goto label_1bc0dc;
        }
    }
    ctx->pc = 0x1BBFDCu;
label_1bbfdc:
    // 0x1bbfdc: 0x86030004  lh          $v1, 0x4($s0)
    ctx->pc = 0x1bbfdcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bbfe0: 0x1060003d  beqz        $v1, . + 4 + (0x3D << 2)
    ctx->pc = 0x1BBFE0u;
    {
        const bool branch_taken_0x1bbfe0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bbfe0) {
            ctx->pc = 0x1BC0D8u;
            goto label_1bc0d8;
        }
    }
    ctx->pc = 0x1BBFE8u;
    // 0x1bbfe8: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1bbfe8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bbfec: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bbfecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bbff0: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1bbff0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
label_1bbff4:
    // 0x1bbff4: 0x86030004  lh          $v1, 0x4($s0)
    ctx->pc = 0x1bbff4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bbff8: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BBFF8u;
    {
        const bool branch_taken_0x1bbff8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1bbff8) {
            ctx->pc = 0x1BC00Cu;
            goto label_1bc00c;
        }
    }
    ctx->pc = 0x1BC000u;
    // 0x1bc000: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1bc000u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1bc004: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1BC004u;
    {
        const bool branch_taken_0x1bc004 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC004u;
            // 0x1bc008: 0xae000014  sw          $zero, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc004) {
            ctx->pc = 0x1BC0D8u;
            goto label_1bc0d8;
        }
    }
    ctx->pc = 0x1BC00Cu;
label_1bc00c:
    // 0x1bc00c: 0x86040006  lh          $a0, 0x6($s0)
    ctx->pc = 0x1bc00cu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x1bc010: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bc010u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bc014: 0x1083001e  beq         $a0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1BC014u;
    {
        const bool branch_taken_0x1bc014 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BC018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC014u;
            // 0x1bc018: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc014) {
            ctx->pc = 0x1BC090u;
            goto label_1bc090;
        }
    }
    ctx->pc = 0x1BC01Cu;
    // 0x1bc01c: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BC01Cu;
    {
        const bool branch_taken_0x1bc01c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1bc01c) {
            ctx->pc = 0x1BC03Cu;
            goto label_1bc03c;
        }
    }
    ctx->pc = 0x1BC024u;
    // 0x1bc024: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BC024u;
    {
        const bool branch_taken_0x1bc024 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bc024) {
            ctx->pc = 0x1BC034u;
            goto label_1bc034;
        }
    }
    ctx->pc = 0x1BC02Cu;
    // 0x1bc02c: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1BC02Cu;
    {
        const bool branch_taken_0x1bc02c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bc02c) {
            ctx->pc = 0x1BC0D8u;
            goto label_1bc0d8;
        }
    }
    ctx->pc = 0x1BC034u;
label_1bc034:
    // 0x1bc034: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1BC034u;
    {
        const bool branch_taken_0x1bc034 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC034u;
            // 0x1bc038: 0xa6000004  sh          $zero, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc034) {
            ctx->pc = 0x1BC0D8u;
            goto label_1bc0d8;
        }
    }
    ctx->pc = 0x1BC03Cu;
label_1bc03c:
    // 0x1bc03c: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x1bc03cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1bc040: 0x3c04ff00  lui         $a0, 0xFF00
    ctx->pc = 0x1bc040u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65280 << 16));
    // 0x1bc044: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bc044u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bc048: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x1bc048u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1bc04c: 0x43602  srl         $a2, $a0, 24
    ctx->pc = 0x1bc04cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x1bc050: 0x9064000d  lbu         $a0, 0xD($v1)
    ctx->pc = 0x1bc050u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 13)));
    // 0x1bc054: 0x10c4000c  beq         $a2, $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x1BC054u;
    {
        const bool branch_taken_0x1bc054 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 4));
        if (branch_taken_0x1bc054) {
            ctx->pc = 0x1BC088u;
            goto label_1bc088;
        }
    }
    ctx->pc = 0x1BC05Cu;
    // 0x1bc05c: 0x86030010  lh          $v1, 0x10($s0)
    ctx->pc = 0x1bc05cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bc060: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x1bc060u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1bc064: 0xc4082a  slt         $at, $a2, $a0
    ctx->pc = 0x1bc064u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1bc068: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BC068u;
    {
        const bool branch_taken_0x1bc068 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC06Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC068u;
            // 0x1bc06c: 0x51a3c  dsll32      $v1, $a1, 8 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc068) {
            ctx->pc = 0x1BC074u;
            goto label_1bc074;
        }
    }
    ctx->pc = 0x1BC070u;
    // 0x1bc070: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1bc070u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1bc074:
    // 0x1bc074: 0x62600  sll         $a0, $a2, 24
    ctx->pc = 0x1bc074u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 24));
    // 0x1bc078: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1bc078u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1bc07c: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1bc07cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1bc080: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1BC080u;
    {
        const bool branch_taken_0x1bc080 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC080u;
            // 0x1bc084: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc080) {
            ctx->pc = 0x1BC0D8u;
            goto label_1bc0d8;
        }
    }
    ctx->pc = 0x1BC088u;
label_1bc088:
    // 0x1bc088: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1BC088u;
    {
        const bool branch_taken_0x1bc088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC088u;
            // 0x1bc08c: 0xa6000004  sh          $zero, 0x4($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc088) {
            ctx->pc = 0x1BC0D8u;
            goto label_1bc0d8;
        }
    }
    ctx->pc = 0x1BC090u;
label_1bc090:
    // 0x1bc090: 0x8e06000c  lw          $a2, 0xC($s0)
    ctx->pc = 0x1bc090u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1bc094: 0x3c04ff00  lui         $a0, 0xFF00
    ctx->pc = 0x1bc094u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65280 << 16));
    // 0x1bc098: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1bc098u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1bc09c: 0xc42024  and         $a0, $a2, $a0
    ctx->pc = 0x1bc09cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & GPR_U64(ctx, 4));
    // 0x1bc0a0: 0x42e02  srl         $a1, $a0, 24
    ctx->pc = 0x1bc0a0u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x1bc0a4: 0x9064000d  lbu         $a0, 0xD($v1)
    ctx->pc = 0x1bc0a4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 13)));
    // 0x1bc0a8: 0x10a4000b  beq         $a1, $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x1BC0A8u;
    {
        const bool branch_taken_0x1bc0a8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        if (branch_taken_0x1bc0a8) {
            ctx->pc = 0x1BC0D8u;
            goto label_1bc0d8;
        }
    }
    ctx->pc = 0x1BC0B0u;
    // 0x1bc0b0: 0x86030010  lh          $v1, 0x10($s0)
    ctx->pc = 0x1bc0b0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1bc0b4: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x1bc0b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1bc0b8: 0x85082a  slt         $at, $a0, $a1
    ctx->pc = 0x1bc0b8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1bc0bc: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1BC0BCu;
    {
        const bool branch_taken_0x1bc0bc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BC0C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC0BCu;
            // 0x1bc0c0: 0x61a3c  dsll32      $v1, $a2, 8 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) << (32 + 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bc0bc) {
            ctx->pc = 0x1BC0C8u;
            goto label_1bc0c8;
        }
    }
    ctx->pc = 0x1BC0C4u;
    // 0x1bc0c4: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1bc0c4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1bc0c8:
    // 0x1bc0c8: 0x52600  sll         $a0, $a1, 24
    ctx->pc = 0x1bc0c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1bc0cc: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x1bc0ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x1bc0d0: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1bc0d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1bc0d4: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1bc0d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
label_1bc0d8:
    // 0x1bc0d8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1bc0d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1bc0dc:
    // 0x1bc0dc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bc0dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bc0e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC0E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC0E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC0E0u;
            // 0x1bc0e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BBFB8u: goto label_1bbfb8;
            case 0x1BBFDCu: goto label_1bbfdc;
            case 0x1BBFF4u: goto label_1bbff4;
            case 0x1BC00Cu: goto label_1bc00c;
            case 0x1BC034u: goto label_1bc034;
            case 0x1BC03Cu: goto label_1bc03c;
            case 0x1BC074u: goto label_1bc074;
            case 0x1BC088u: goto label_1bc088;
            case 0x1BC090u: goto label_1bc090;
            case 0x1BC0C8u: goto label_1bc0c8;
            case 0x1BC0D8u: goto label_1bc0d8;
            case 0x1BC0DCu: goto label_1bc0dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BC0E8u;
    // 0x1bc0e8: 0x0  nop
    ctx->pc = 0x1bc0e8u;
    // NOP
    // 0x1bc0ec: 0x0  nop
    ctx->pc = 0x1bc0ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
