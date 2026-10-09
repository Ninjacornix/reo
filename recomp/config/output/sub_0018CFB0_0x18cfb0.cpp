#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018CFB0
// Address: 0x18cfb0 - 0x18d470
void sub_0018CFB0_0x18cfb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018CFB0_0x18cfb0");
#endif

    switch (ctx->pc) {
        case 0x18cfe0u: goto label_18cfe0;
        case 0x18d010u: goto label_18d010;
        case 0x18d214u: goto label_18d214;
        case 0x18d374u: goto label_18d374;
        case 0x18d3c8u: goto label_18d3c8;
        case 0x18d448u: goto label_18d448;
        default: break;
    }

    ctx->pc = 0x18cfb0u;

    // 0x18cfb0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x18cfb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x18cfb4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x18cfb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18cfb8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x18cfb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x18cfbc: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x18cfbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x18cfc0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x18cfc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18cfc4: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x18cfc4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cfc8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18cfc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18cfcc: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x18cfccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cfd0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18cfd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18cfd4: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x18cfd4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cfd8: 0x14820020  bne         $a0, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x18CFD8u;
    {
        const bool branch_taken_0x18cfd8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x18CFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18CFD8u;
            // 0x18cfdc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18cfd8) {
            ctx->pc = 0x18D05Cu;
            goto label_18d05c;
        }
    }
    ctx->pc = 0x18CFE0u;
label_18cfe0:
    // 0x18cfe0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18cfe0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18cfe4: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x18cfe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x18cfe8: 0x8c23fdb4  lw          $v1, -0x24C($at)
    ctx->pc = 0x18cfe8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
    // 0x18cfec: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18cfecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18cff0: 0x38080  sll         $s0, $v1, 2
    ctx->pc = 0x18cff0u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18cff4: 0x2122021  addu        $a0, $s0, $s2
    ctx->pc = 0x18cff4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x18cff8: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x18cff8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x18cffc: 0x43082b  sltu        $at, $v0, $v1
    ctx->pc = 0x18cffcu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x18d000: 0x1420004c  bnez        $at, . + 4 + (0x4C << 2)
    ctx->pc = 0x18D000u;
    {
        const bool branch_taken_0x18d000 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x18D004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D000u;
            // 0x18d004: 0x24910014  addiu       $s1, $a0, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d000) {
            ctx->pc = 0x18D134u;
            goto label_18d134;
        }
    }
    ctx->pc = 0x18D008u;
    // 0x18d008: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x18D008u;
    SET_GPR_U32(ctx, 31, 0x18D010u);
    ctx->pc = 0x18D00Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D008u;
            // 0x18d00c: 0x8c84000c  lw          $a0, 0xC($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D010u; }
        if (ctx->pc != 0x18D010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D010u; }
        if (ctx->pc != 0x18D010u) { return; }
    }
    ctx->pc = 0x18D010u;
label_18d010:
    // 0x18d010: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x18d010u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18d014: 0x2122821  addu        $a1, $s0, $s2
    ctx->pc = 0x18d014u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x18d018: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x18d018u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18d01c: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x18d01cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x18d020: 0x8ca3001c  lw          $v1, 0x1C($a1)
    ctx->pc = 0x18d020u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x18d024: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x18d024u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18d028: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18d028u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18d02c: 0xaca4001c  sw          $a0, 0x1C($a1)
    ctx->pc = 0x18d02cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 4));
    // 0x18d030: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18d030u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18d034: 0xac540000  sw          $s4, 0x0($v0)
    ctx->pc = 0x18d034u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 20));
    // 0x18d038: 0x8ca3001c  lw          $v1, 0x1C($a1)
    ctx->pc = 0x18d038u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x18d03c: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x18d03cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x18d040: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x18D040u;
    {
        const bool branch_taken_0x18d040 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18D044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D040u;
            // 0x18d044: 0x24a6001c  addiu       $a2, $a1, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d040) {
            ctx->pc = 0x18D04Cu;
            goto label_18d04c;
        }
    }
    ctx->pc = 0x18D048u;
    // 0x18d048: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x18d048u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_18d04c:
    // 0x18d04c: 0xae540034  sw          $s4, 0x34($s2)
    ctx->pc = 0x18d04cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 20));
    // 0x18d050: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18d050u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d054: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x18D054u;
    {
        const bool branch_taken_0x18d054 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D054u;
            // 0x18d058: 0xae530038  sw          $s3, 0x38($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d054) {
            ctx->pc = 0x18D140u;
            goto label_18d140;
        }
    }
    ctx->pc = 0x18D05Cu;
label_18d05c:
    // 0x18d05c: 0x8e450034  lw          $a1, 0x34($s2)
    ctx->pc = 0x18d05cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x18d060: 0x10a0ffdf  beqz        $a1, . + 4 + (-0x21 << 2)
    ctx->pc = 0x18D060u;
    {
        const bool branch_taken_0x18d060 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d060) {
            ctx->pc = 0x18CFE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D068u;
    // 0x18d068: 0x8e420038  lw          $v0, 0x38($s2)
    ctx->pc = 0x18d068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 56)));
    // 0x18d06c: 0x1040ffdc  beqz        $v0, . + 4 + (-0x24 << 2)
    ctx->pc = 0x18D06Cu;
    {
        const bool branch_taken_0x18d06c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d06c) {
            ctx->pc = 0x18CFE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D074u;
    // 0x18d074: 0x3c03f000  lui         $v1, 0xF000
    ctx->pc = 0x18d074u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)61440 << 16));
    // 0x18d078: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x18d078u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x18d07c: 0x31f02  srl         $v1, $v1, 28
    ctx->pc = 0x18d07cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 28));
    // 0x18d080: 0x2c610006  sltiu       $at, $v1, 0x6
    ctx->pc = 0x18d080u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x18d084: 0x1020ffd6  beqz        $at, . + 4 + (-0x2A << 2)
    ctx->pc = 0x18D084u;
    {
        const bool branch_taken_0x18d084 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d084) {
            ctx->pc = 0x18CFE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D08Cu;
    // 0x18d08c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18d08cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18d090: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18d090u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18d094: 0x24a51bf0  addiu       $a1, $a1, 0x1BF0
    ctx->pc = 0x18d094u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7152));
    // 0x18d098: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x18d098u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x18d09c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x18d09cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18d0a0: 0x600008  jr          $v1
    ctx->pc = 0x18D0A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CFE0u: goto label_18cfe0;
            case 0x18D0A8u: goto label_18d0a8;
            case 0x18D0E0u: goto label_18d0e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D0A8u;
label_18d0a8:
    // 0x18d0a8: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x18d0a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d0ac: 0x3c057000  lui         $a1, 0x7000
    ctx->pc = 0x18d0acu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)28672 << 16));
    // 0x18d0b0: 0xc51824  and         $v1, $a2, $a1
    ctx->pc = 0x18d0b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & GPR_U64(ctx, 5));
    // 0x18d0b4: 0x10650003  beq         $v1, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18D0B4u;
    {
        const bool branch_taken_0x18d0b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x18D0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D0B4u;
            // 0x18d0b8: 0x30c5ffff  andi        $a1, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d0b4) {
            ctx->pc = 0x18D0C4u;
            goto label_18d0c4;
        }
    }
    ctx->pc = 0x18D0BCu;
    // 0x18d0bc: 0x1000ffc8  b           . + 4 + (-0x38 << 2)
    ctx->pc = 0x18D0BCu;
    {
        const bool branch_taken_0x18d0bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d0bc) {
            ctx->pc = 0x18CFE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D0C4u;
label_18d0c4:
    // 0x18d0c4: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x18d0c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x18d0c8: 0xa32821  addu        $a1, $a1, $v1
    ctx->pc = 0x18d0c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x18d0cc: 0x14193c  dsll32      $v1, $s4, 4
    ctx->pc = 0x18d0ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) << (32 + 4));
    // 0x18d0d0: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x18d0d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x18d0d4: 0x3193e  dsrl32      $v1, $v1, 4
    ctx->pc = 0x18d0d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 4));
    // 0x18d0d8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x18D0D8u;
    {
        const bool branch_taken_0x18d0d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D0DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D0D8u;
            // 0x18d0dc: 0xac430004  sw          $v1, 0x4($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d0d8) {
            ctx->pc = 0x18D10Cu;
            goto label_18d10c;
        }
    }
    ctx->pc = 0x18D0E0u;
label_18d0e0:
    // 0x18d0e0: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x18d0e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d0e4: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x18d0e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x18d0e8: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x18d0e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x18d0ec: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18D0ECu;
    {
        const bool branch_taken_0x18d0ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d0ec) {
            ctx->pc = 0x18D0FCu;
            goto label_18d0fc;
        }
    }
    ctx->pc = 0x18D0F4u;
    // 0x18d0f4: 0x1000ffba  b           . + 4 + (-0x46 << 2)
    ctx->pc = 0x18D0F4u;
    {
        const bool branch_taken_0x18d0f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d0f4) {
            ctx->pc = 0x18CFE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D0FCu;
label_18d0fc:
    // 0x18d0fc: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    ctx->pc = 0x18d0fcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x18d100: 0x3c033000  lui         $v1, 0x3000
    ctx->pc = 0x18d100u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)12288 << 16));
    // 0x18d104: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x18d104u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x18d108: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x18d108u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_18d10c:
    // 0x18d10c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18d10cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18d110: 0x14820004  bne         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x18D110u;
    {
        const bool branch_taken_0x18d110 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x18d110) {
            ctx->pc = 0x18D124u;
            goto label_18d124;
        }
    }
    ctx->pc = 0x18D118u;
    // 0x18d118: 0xae400034  sw          $zero, 0x34($s2)
    ctx->pc = 0x18d118u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 0));
    // 0x18d11c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18D11Cu;
    {
        const bool branch_taken_0x18d11c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D120u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D11Cu;
            // 0x18d120: 0xae400038  sw          $zero, 0x38($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d11c) {
            ctx->pc = 0x18D12Cu;
            goto label_18d12c;
        }
    }
    ctx->pc = 0x18D124u;
label_18d124:
    // 0x18d124: 0xae540034  sw          $s4, 0x34($s2)
    ctx->pc = 0x18d124u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 20));
    // 0x18d128: 0xae530038  sw          $s3, 0x38($s2)
    ctx->pc = 0x18d128u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 19));
label_18d12c:
    // 0x18d12c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x18D12Cu;
    {
        const bool branch_taken_0x18d12c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D12Cu;
            // 0x18d130: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d12c) {
            ctx->pc = 0x18D140u;
            goto label_18d140;
        }
    }
    ctx->pc = 0x18D134u;
label_18d134:
    // 0x18d134: 0xae400034  sw          $zero, 0x34($s2)
    ctx->pc = 0x18d134u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 0));
    // 0x18d138: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x18d138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x18d13c: 0xae400038  sw          $zero, 0x38($s2)
    ctx->pc = 0x18d13cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 0));
label_18d140:
    // 0x18d140: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x18d140u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18d144: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x18d144u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18d148: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x18d148u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18d14c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18d14cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18d150: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18d150u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18d154: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18d154u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18d158: 0x3e00008  jr          $ra
    ctx->pc = 0x18D158u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D15Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D158u;
            // 0x18d15c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CFE0u: goto label_18cfe0;
            case 0x18D010u: goto label_18d010;
            case 0x18D04Cu: goto label_18d04c;
            case 0x18D05Cu: goto label_18d05c;
            case 0x18D0A8u: goto label_18d0a8;
            case 0x18D0C4u: goto label_18d0c4;
            case 0x18D0E0u: goto label_18d0e0;
            case 0x18D0FCu: goto label_18d0fc;
            case 0x18D10Cu: goto label_18d10c;
            case 0x18D124u: goto label_18d124;
            case 0x18D12Cu: goto label_18d12c;
            case 0x18D134u: goto label_18d134;
            case 0x18D140u: goto label_18d140;
            case 0x18D18Cu: goto label_18d18c;
            case 0x18D1E0u: goto label_18d1e0;
            case 0x18D1F8u: goto label_18d1f8;
            case 0x18D214u: goto label_18d214;
            case 0x18D254u: goto label_18d254;
            case 0x18D270u: goto label_18d270;
            case 0x18D2A8u: goto label_18d2a8;
            case 0x18D304u: goto label_18d304;
            case 0x18D374u: goto label_18d374;
            case 0x18D37Cu: goto label_18d37c;
            case 0x18D3C8u: goto label_18d3c8;
            case 0x18D448u: goto label_18d448;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D160u;
    // 0x18d160: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x18d160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18d164: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18d164u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18d168: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x18d168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x18d16c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18d16cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18d170: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18d170u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18d174: 0x3c12002a  lui         $s2, 0x2A
    ctx->pc = 0x18d174u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)42 << 16));
    // 0x18d178: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18d178u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18d17c: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18D17Cu;
    {
        const bool branch_taken_0x18d17c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x18D180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D17Cu;
            // 0x18d180: 0x2652f6f0  addiu       $s2, $s2, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294964976));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d17c) {
            ctx->pc = 0x18D18Cu;
            goto label_18d18c;
        }
    }
    ctx->pc = 0x18D184u;
    // 0x18d184: 0x100000b0  b           . + 4 + (0xB0 << 2)
    ctx->pc = 0x18D184u;
    {
        const bool branch_taken_0x18d184 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d184) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D18Cu;
label_18d18c:
    // 0x18d18c: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x18d18cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18d190: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x18d190u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x18d194: 0x2442fdf0  addiu       $v0, $v0, -0x210
    ctx->pc = 0x18d194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966768));
    // 0x18d198: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18d198u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18d19c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18d19cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18d1a0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18d1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d1a4: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x18d1a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d1a8: 0x30820100  andi        $v0, $a0, 0x100
    ctx->pc = 0x18d1a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)256);
    // 0x18d1ac: 0x144000a6  bnez        $v0, . + 4 + (0xA6 << 2)
    ctx->pc = 0x18D1ACu;
    {
        const bool branch_taken_0x18d1ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18D1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D1ACu;
            // 0x18d1b0: 0x3083000c  andi        $v1, $a0, 0xC (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)12);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d1ac) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1B4u;
    // 0x18d1b4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x18d1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x18d1b8: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x18D1B8u;
    {
        const bool branch_taken_0x18d1b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18D1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D1B8u;
            // 0x18d1bc: 0x30820080  andi        $v0, $a0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d1b8) {
            ctx->pc = 0x18D1E0u;
            goto label_18d1e0;
        }
    }
    ctx->pc = 0x18D1C0u;
    // 0x18d1c0: 0x104000a1  beqz        $v0, . + 4 + (0xA1 << 2)
    ctx->pc = 0x18D1C0u;
    {
        const bool branch_taken_0x18d1c0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d1c0) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1C8u;
    // 0x18d1c8: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x18d1c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x18d1cc: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x18d1ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x18d1d0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x18D1D0u;
    {
        const bool branch_taken_0x18d1d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18d1d0) {
            ctx->pc = 0x18D1F8u;
            goto label_18d1f8;
        }
    }
    ctx->pc = 0x18D1D8u;
    // 0x18d1d8: 0x1000009b  b           . + 4 + (0x9B << 2)
    ctx->pc = 0x18D1D8u;
    {
        const bool branch_taken_0x18d1d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d1d8) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1E0u;
label_18d1e0:
    // 0x18d1e0: 0x14600099  bnez        $v1, . + 4 + (0x99 << 2)
    ctx->pc = 0x18D1E0u;
    {
        const bool branch_taken_0x18d1e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x18d1e0) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1E8u;
    // 0x18d1e8: 0x8e420030  lw          $v0, 0x30($s2)
    ctx->pc = 0x18d1e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x18d1ec: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x18d1ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x18d1f0: 0x10400095  beqz        $v0, . + 4 + (0x95 << 2)
    ctx->pc = 0x18D1F0u;
    {
        const bool branch_taken_0x18d1f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d1f0) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1F8u;
label_18d1f8:
    // 0x18d1f8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x18d1f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x18d1fc: 0x8c22fdb4  lw          $v0, -0x24C($at)
    ctx->pc = 0x18d1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
    // 0x18d200: 0x38500001  xori        $s0, $v0, 0x1
    ctx->pc = 0x18d200u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x18d204: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x18d204u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x18d208: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x18d208u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x18d20c: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x18D20Cu;
    SET_GPR_U32(ctx, 31, 0x18D214u);
    ctx->pc = 0x18D210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D20Cu;
            // 0x18d210: 0x8c44000c  lw          $a0, 0xC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D214u; }
        if (ctx->pc != 0x18D214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D214u; }
        if (ctx->pc != 0x18D214u) { return; }
    }
    ctx->pc = 0x18D214u;
label_18d214:
    // 0x18d214: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x18d214u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x18d218: 0x722821  addu        $a1, $v1, $s2
    ctx->pc = 0x18d218u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x18d21c: 0x8ca30014  lw          $v1, 0x14($a1)
    ctx->pc = 0x18d21cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x18d220: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x18d220u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18d224: 0xaca30014  sw          $v1, 0x14($a1)
    ctx->pc = 0x18d224u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 3));
    // 0x18d228: 0x8ca30024  lw          $v1, 0x24($a1)
    ctx->pc = 0x18d228u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x18d22c: 0x24640001  addiu       $a0, $v1, 0x1
    ctx->pc = 0x18d22cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18d230: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x18d230u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x18d234: 0xaca40024  sw          $a0, 0x24($a1)
    ctx->pc = 0x18d234u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 4));
    // 0x18d238: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x18d238u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18d23c: 0x8ca40024  lw          $a0, 0x24($a1)
    ctx->pc = 0x18d23cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x18d240: 0x8c710000  lw          $s1, 0x0($v1)
    ctx->pc = 0x18d240u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18d244: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x18d244u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x18d248: 0x14830002  bne         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x18D248u;
    {
        const bool branch_taken_0x18d248 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x18D24Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D248u;
            // 0x18d24c: 0x3c04f000  lui         $a0, 0xF000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)61440 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d248) {
            ctx->pc = 0x18D254u;
            goto label_18d254;
        }
    }
    ctx->pc = 0x18D250u;
    // 0x18d250: 0xaca00024  sw          $zero, 0x24($a1)
    ctx->pc = 0x18d250u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 0));
label_18d254:
    // 0x18d254: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18d254u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18d258: 0x2242024  and         $a0, $s1, $a0
    ctx->pc = 0x18d258u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) & GPR_U64(ctx, 4));
    // 0x18d25c: 0x42702  srl         $a0, $a0, 28
    ctx->pc = 0x18d25cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 28));
    // 0x18d260: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18D260u;
    {
        const bool branch_taken_0x18d260 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x18d260) {
            ctx->pc = 0x18D270u;
            goto label_18d270;
        }
    }
    ctx->pc = 0x18D268u;
    // 0x18d268: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x18D268u;
    {
        const bool branch_taken_0x18d268 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D268u;
            // 0x18d26c: 0x101880  sll         $v1, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d268) {
            ctx->pc = 0x18D2A8u;
            goto label_18d2a8;
        }
    }
    ctx->pc = 0x18D270u;
label_18d270:
    // 0x18d270: 0xae400030  sw          $zero, 0x30($s2)
    ctx->pc = 0x18d270u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 0));
    // 0x18d274: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x18d274u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x18d278: 0xac203c00  sw          $zero, 0x3C00($at)
    ctx->pc = 0x18d278u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 15360), GPR_U32(ctx, 0)); // MMIO: 0x10003c00
    // 0x18d27c: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18d27cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18d280: 0xfc201040  sd          $zero, 0x1040($at)
    ctx->pc = 0x18d280u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4160), GPR_U64(ctx, 0));
    // 0x18d284: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18d284u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18d288: 0xdc234158  ld          $v1, 0x4158($at)
    ctx->pc = 0x18d288u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 1), 16728)));
    // 0x18d28c: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18d28cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18d290: 0xfc231010  sd          $v1, 0x1010($at)
    ctx->pc = 0x18d290u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 3));
    // 0x18d294: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x18d294u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x18d298: 0x7823fde0  lq          $v1, -0x220($at)
    ctx->pc = 0x18d298u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 1), 4294966752)));
    // 0x18d29c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x18d29cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x18d2a0: 0x7c235000  sq          $v1, 0x5000($at)
    ctx->pc = 0x18d2a0u;
    WRITE128(ADD32(GPR_U32(ctx, 1), 20480), GPR_VEC(ctx, 3));
    // 0x18d2a4: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x18d2a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_18d2a8:
    // 0x18d2a8: 0x721821  addu        $v1, $v1, $s2
    ctx->pc = 0x18d2a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x18d2ac: 0x8c64001c  lw          $a0, 0x1C($v1)
    ctx->pc = 0x18d2acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x18d2b0: 0x8c630024  lw          $v1, 0x24($v1)
    ctx->pc = 0x18d2b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x18d2b4: 0x10830064  beq         $a0, $v1, . + 4 + (0x64 << 2)
    ctx->pc = 0x18D2B4u;
    {
        const bool branch_taken_0x18d2b4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x18D2B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D2B4u;
            // 0x18d2b8: 0x32080  sll         $a0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d2b4) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D2BCu;
    // 0x18d2bc: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x18d2bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18d2c0: 0x3c03f000  lui         $v1, 0xF000
    ctx->pc = 0x18d2c0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)61440 << 16));
    // 0x18d2c4: 0x8c510000  lw          $s1, 0x0($v0)
    ctx->pc = 0x18d2c4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d2c8: 0x2231024  and         $v0, $s1, $v1
    ctx->pc = 0x18d2c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & GPR_U64(ctx, 3));
    // 0x18d2cc: 0xae51002c  sw          $s1, 0x2C($s2)
    ctx->pc = 0x18d2ccu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 17));
    // 0x18d2d0: 0x11893c  dsll32      $s1, $s1, 4
    ctx->pc = 0x18d2d0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) << (32 + 4));
    // 0x18d2d4: 0x11893e  dsrl32      $s1, $s1, 4
    ctx->pc = 0x18d2d4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) >> (32 + 4));
    // 0x18d2d8: 0x1220005b  beqz        $s1, . + 4 + (0x5B << 2)
    ctx->pc = 0x18D2D8u;
    {
        const bool branch_taken_0x18d2d8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D2DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D2D8u;
            // 0x18d2dc: 0x22702  srl         $a0, $v0, 28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d2d8) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D2E0u;
    // 0x18d2e0: 0x2c810006  sltiu       $at, $a0, 0x6
    ctx->pc = 0x18d2e0u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x18d2e4: 0x10200058  beqz        $at, . + 4 + (0x58 << 2)
    ctx->pc = 0x18D2E4u;
    {
        const bool branch_taken_0x18d2e4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D2E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D2E4u;
            // 0x18d2e8: 0x3c030024  lui         $v1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d2e4) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D2ECu;
    // 0x18d2ec: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x18d2ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x18d2f0: 0x24631c10  addiu       $v1, $v1, 0x1C10
    ctx->pc = 0x18d2f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 7184));
    // 0x18d2f4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x18d2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18d2f8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x18d2f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d2fc: 0x400008  jr          $v0
    ctx->pc = 0x18D2FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18D304u: goto label_18d304;
            case 0x18D37Cu: goto label_18d37c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D304u;
label_18d304:
    // 0x18d304: 0x8e470000  lw          $a3, 0x0($s2)
    ctx->pc = 0x18d304u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18d308: 0x3c09002a  lui         $t1, 0x2A
    ctx->pc = 0x18d308u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)42 << 16));
    // 0x18d30c: 0x2529fd74  addiu       $t1, $t1, -0x28C
    ctx->pc = 0x18d30cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294966644));
    // 0x18d310: 0x2404ffbf  addiu       $a0, $zero, -0x41
    ctx->pc = 0x18d310u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x18d314: 0x64060040  daddiu      $a2, $zero, 0x40
    ctx->pc = 0x18d314u;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)64);
    // 0x18d318: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x18d318u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x18d31c: 0x64030080  daddiu      $v1, $zero, 0x80
    ctx->pc = 0x18d31cu;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)128);
    // 0x18d320: 0x73880  sll         $a3, $a3, 2
    ctx->pc = 0x18d320u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x18d324: 0x1273821  addu        $a3, $t1, $a3
    ctx->pc = 0x18d324u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 7)));
    // 0x18d328: 0x8ce80000  lw          $t0, 0x0($a3)
    ctx->pc = 0x18d328u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x18d32c: 0x91070000  lbu         $a3, 0x0($t0)
    ctx->pc = 0x18d32cu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x18d330: 0xe42024  and         $a0, $a3, $a0
    ctx->pc = 0x18d330u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) & GPR_U64(ctx, 4));
    // 0x18d334: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x18d334u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x18d338: 0xa1040000  sb          $a0, 0x0($t0)
    ctx->pc = 0x18d338u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x18d33c: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x18d33cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18d340: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x18d340u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x18d344: 0x1242021  addu        $a0, $t1, $a0
    ctx->pc = 0x18d344u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
    // 0x18d348: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x18d348u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18d34c: 0x90c40000  lbu         $a0, 0x0($a2)
    ctx->pc = 0x18d34cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x18d350: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x18d350u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x18d354: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18d354u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18d358: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x18d358u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x18d35c: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x18d35cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18d360: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18d360u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18d364: 0x1221021  addu        $v0, $t1, $v0
    ctx->pc = 0x18d364u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x18d368: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x18d368u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d36c: 0xc040ce4  jal         func_103390
    ctx->pc = 0x18D36Cu;
    SET_GPR_U32(ctx, 31, 0x18D374u);
    ctx->pc = 0x18D370u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D36Cu;
            // 0x18d370: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103390u;
    if (runtime->hasFunction(0x103390u)) {
        auto targetFn = runtime->lookupFunction(0x103390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D374u; }
        if (ctx->pc != 0x18D374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D374u; }
        if (ctx->pc != 0x18D374u) { return; }
    }
    ctx->pc = 0x18D374u;
label_18d374:
    // 0x18d374: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x18D374u;
    {
        const bool branch_taken_0x18d374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18d374) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D37Cu;
label_18d37c:
    // 0x18d37c: 0x8e250080  lw          $a1, 0x80($s1)
    ctx->pc = 0x18d37cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 128)));
    // 0x18d380: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18d380u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18d384: 0x2402fdff  addiu       $v0, $zero, -0x201
    ctx->pc = 0x18d384u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966783));
    // 0x18d388: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18d388u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18d38c: 0x70021389  pcpyld      $v0, $zero, $v0
    ctx->pc = 0x18d38cu;
    SET_GPR_VEC(ctx, 2, PS2_PCPYLD(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x18d390: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x18d390u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d394: 0xac254148  sw          $a1, 0x4148($at)
    ctx->pc = 0x18d394u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16712), GPR_U32(ctx, 5));
    // 0x18d398: 0x8e250084  lw          $a1, 0x84($s1)
    ctx->pc = 0x18d398u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 132)));
    // 0x18d39c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18d39cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18d3a0: 0xac254150  sw          $a1, 0x4150($at)
    ctx->pc = 0x18d3a0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16720), GPR_U32(ctx, 5));
    // 0x18d3a4: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18d3a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18d3a8: 0xfc231000  sd          $v1, 0x1000($at)
    ctx->pc = 0x18d3a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4096), GPR_U64(ctx, 3));
    // 0x18d3ac: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18d3acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18d3b0: 0xdc231010  ld          $v1, 0x1010($at)
    ctx->pc = 0x18d3b0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 1), 4112)));
    // 0x18d3b4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18d3b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18d3b8: 0xfc234158  sd          $v1, 0x4158($at)
    ctx->pc = 0x18d3b8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 16728), GPR_U64(ctx, 3));
    // 0x18d3bc: 0x3c011200  lui         $at, 0x1200
    ctx->pc = 0x18d3bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4608 << 16));
    // 0x18d3c0: 0xc0454a8  jal         func_1152A0
    ctx->pc = 0x18D3C0u;
    SET_GPR_U32(ctx, 31, 0x18D3C8u);
    ctx->pc = 0x18D3C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D3C0u;
            // 0x18d3c4: 0xfc221010  sd          $v0, 0x1010($at) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1152A0u;
    if (runtime->hasFunction(0x1152A0u)) {
        auto targetFn = runtime->lookupFunction(0x1152A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D3C8u; }
        if (ctx->pc != 0x18D3C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001152A0_0x1152a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D3C8u; }
        if (ctx->pc != 0x18D3C8u) { return; }
    }
    ctx->pc = 0x18D3C8u;
label_18d3c8:
    // 0x18d3c8: 0x8e470030  lw          $a3, 0x30($s2)
    ctx->pc = 0x18d3c8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x18d3cc: 0x30020001  andi        $v0, $zero, 0x1
    ctx->pc = 0x18d3ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) & (uint64_t)(uint16_t)1);
    // 0x18d3d0: 0x3c09002a  lui         $t1, 0x2A
    ctx->pc = 0x18d3d0u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)42 << 16));
    // 0x18d3d4: 0x2404ffbf  addiu       $a0, $zero, -0x41
    ctx->pc = 0x18d3d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967231));
    // 0x18d3d8: 0x2529fd74  addiu       $t1, $t1, -0x28C
    ctx->pc = 0x18d3d8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294966644));
    // 0x18d3dc: 0x23180  sll         $a2, $v0, 6
    ctx->pc = 0x18d3dcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x18d3e0: 0x219c0  sll         $v1, $v0, 7
    ctx->pc = 0x18d3e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x18d3e4: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x18d3e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x18d3e8: 0x34e70001  ori         $a3, $a3, 0x1
    ctx->pc = 0x18d3e8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)1);
    // 0x18d3ec: 0xae470030  sw          $a3, 0x30($s2)
    ctx->pc = 0x18d3ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 7));
    // 0x18d3f0: 0x8e470000  lw          $a3, 0x0($s2)
    ctx->pc = 0x18d3f0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18d3f4: 0x73880  sll         $a3, $a3, 2
    ctx->pc = 0x18d3f4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x18d3f8: 0x1273821  addu        $a3, $t1, $a3
    ctx->pc = 0x18d3f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 7)));
    // 0x18d3fc: 0x8ce80000  lw          $t0, 0x0($a3)
    ctx->pc = 0x18d3fcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x18d400: 0x91070000  lbu         $a3, 0x0($t0)
    ctx->pc = 0x18d400u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x18d404: 0xe42024  and         $a0, $a3, $a0
    ctx->pc = 0x18d404u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) & GPR_U64(ctx, 4));
    // 0x18d408: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x18d408u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x18d40c: 0xa1040000  sb          $a0, 0x0($t0)
    ctx->pc = 0x18d40cu;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x18d410: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x18d410u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18d414: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x18d414u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x18d418: 0x1242021  addu        $a0, $t1, $a0
    ctx->pc = 0x18d418u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
    // 0x18d41c: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x18d41cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18d420: 0x90c40000  lbu         $a0, 0x0($a2)
    ctx->pc = 0x18d420u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x18d424: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x18d424u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x18d428: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18d428u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18d42c: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x18d42cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x18d430: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x18d430u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x18d434: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18d434u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18d438: 0x1221021  addu        $v0, $t1, $v0
    ctx->pc = 0x18d438u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x18d43c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x18d43cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x18d440: 0xc040ce4  jal         func_103390
    ctx->pc = 0x18D440u;
    SET_GPR_U32(ctx, 31, 0x18D448u);
    ctx->pc = 0x18D444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D440u;
            // 0x18d444: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103390u;
    if (runtime->hasFunction(0x103390u)) {
        auto targetFn = runtime->lookupFunction(0x103390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D448u; }
        if (ctx->pc != 0x18D448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D448u; }
        if (ctx->pc != 0x18D448u) { return; }
    }
    ctx->pc = 0x18D448u;
label_18d448:
    // 0x18d448: 0xf  sync
    ctx->pc = 0x18d448u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x18d44c: 0x42000038  ei
    ctx->pc = 0x18d44cu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x18d450: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x18d450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18d454: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18d454u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d458: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18d458u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18d45c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18d45cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18d460: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18d460u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18d464: 0x3e00008  jr          $ra
    ctx->pc = 0x18D464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D464u;
            // 0x18d468: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CFE0u: goto label_18cfe0;
            case 0x18D010u: goto label_18d010;
            case 0x18D04Cu: goto label_18d04c;
            case 0x18D05Cu: goto label_18d05c;
            case 0x18D0A8u: goto label_18d0a8;
            case 0x18D0C4u: goto label_18d0c4;
            case 0x18D0E0u: goto label_18d0e0;
            case 0x18D0FCu: goto label_18d0fc;
            case 0x18D10Cu: goto label_18d10c;
            case 0x18D124u: goto label_18d124;
            case 0x18D12Cu: goto label_18d12c;
            case 0x18D134u: goto label_18d134;
            case 0x18D140u: goto label_18d140;
            case 0x18D18Cu: goto label_18d18c;
            case 0x18D1E0u: goto label_18d1e0;
            case 0x18D1F8u: goto label_18d1f8;
            case 0x18D214u: goto label_18d214;
            case 0x18D254u: goto label_18d254;
            case 0x18D270u: goto label_18d270;
            case 0x18D2A8u: goto label_18d2a8;
            case 0x18D304u: goto label_18d304;
            case 0x18D374u: goto label_18d374;
            case 0x18D37Cu: goto label_18d37c;
            case 0x18D3C8u: goto label_18d3c8;
            case 0x18D448u: goto label_18d448;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D46Cu;
    // 0x18d46c: 0x0  nop
    ctx->pc = 0x18d46cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
