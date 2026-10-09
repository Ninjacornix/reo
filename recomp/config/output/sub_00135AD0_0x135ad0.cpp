#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135AD0
// Address: 0x135ad0 - 0x135c18
void sub_00135AD0_0x135ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135AD0_0x135ad0");
#endif

    switch (ctx->pc) {
        case 0x135b10u: goto label_135b10;
        case 0x135b68u: goto label_135b68;
        case 0x135b78u: goto label_135b78;
        case 0x135bb8u: goto label_135bb8;
        default: break;
    }

    ctx->pc = 0x135ad0u;

    // 0x135ad0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x135ad0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x135ad4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135ad8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x135ad8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135adc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x135adcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x135ae0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x135ae0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135ae4: 0x10c00046  beqz        $a2, . + 4 + (0x46 << 2)
    ctx->pc = 0x135AE4u;
    {
        const bool branch_taken_0x135ae4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x135AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135AE4u;
            // 0x135ae8: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135ae4) {
            ctx->pc = 0x135C00u;
            goto label_135c00;
        }
    }
    ctx->pc = 0x135AECu;
    // 0x135aec: 0x80c30000  lb          $v1, 0x0($a2)
    ctx->pc = 0x135aecu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x135af0: 0x2402003a  addiu       $v0, $zero, 0x3A
    ctx->pc = 0x135af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 58));
    // 0x135af4: 0x10620014  beq         $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x135AF4u;
    {
        const bool branch_taken_0x135af4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x135AF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135AF4u;
            // 0x135af8: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135af4) {
            ctx->pc = 0x135B48u;
            goto label_135b48;
        }
    }
    ctx->pc = 0x135AFCu;
    // 0x135afc: 0x10600016  beqz        $v1, . + 4 + (0x16 << 2)
    ctx->pc = 0x135AFCu;
    {
        const bool branch_taken_0x135afc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x135B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135AFCu;
            // 0x135b00: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135afc) {
            ctx->pc = 0x135B58u;
            goto label_135b58;
        }
    }
    ctx->pc = 0x135B04u;
    // 0x135b04: 0x2407003a  addiu       $a3, $zero, 0x3A
    ctx->pc = 0x135b04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 58));
    // 0x135b08: 0x90a40000  lbu         $a0, 0x0($a1)
    ctx->pc = 0x135b08u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x135b0c: 0x0  nop
    ctx->pc = 0x135b0cu;
    // NOP
label_135b10:
    // 0x135b10: 0x2081821  addu        $v1, $s0, $t0
    ctx->pc = 0x135b10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 8)));
    // 0x135b14: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x135b14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x135b18: 0x29020129  slti        $v0, $t0, 0x129
    ctx->pc = 0x135b18u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)297) ? 1 : 0);
    // 0x135b1c: 0xc82821  addu        $a1, $a2, $t0
    ctx->pc = 0x135b1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x135b20: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x135B20u;
    {
        const bool branch_taken_0x135b20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x135B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135B20u;
            // 0x135b24: 0xa0640000  sb          $a0, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135b20) {
            ctx->pc = 0x135B4Cu;
            goto label_135b4c;
        }
    }
    ctx->pc = 0x135B28u;
    // 0x135b28: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x135b28u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x135b2c: 0x10470008  beq         $v0, $a3, . + 4 + (0x8 << 2)
    ctx->pc = 0x135B2Cu;
    {
        const bool branch_taken_0x135b2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 7));
        if (branch_taken_0x135b2c) {
            ctx->pc = 0x135B50u;
            goto label_135b50;
        }
    }
    ctx->pc = 0x135B34u;
    // 0x135b34: 0x5440fff6  bnel        $v0, $zero, . + 4 + (-0xA << 2)
    ctx->pc = 0x135B34u;
    {
        const bool branch_taken_0x135b34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x135b34) {
            ctx->pc = 0x135B38u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135B34u;
            // 0x135b38: 0x90a40000  lbu         $a0, 0x0($a1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135B10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135b10;
        }
    }
    ctx->pc = 0x135B3Cu;
    // 0x135b3c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x135B3Cu;
    {
        const bool branch_taken_0x135b3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x135b3c) {
            ctx->pc = 0x135B50u;
            goto label_135b50;
        }
    }
    ctx->pc = 0x135B44u;
    // 0x135b44: 0x0  nop
    ctx->pc = 0x135b44u;
    // NOP
label_135b48:
    // 0x135b48: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x135b48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_135b4c:
    // 0x135b4c: 0x80a20000  lb          $v0, 0x0($a1)
    ctx->pc = 0x135b4cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
label_135b50:
    // 0x135b50: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x135B50u;
    {
        const bool branch_taken_0x135b50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x135B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135B50u;
            // 0x135b54: 0x2081821  addu        $v1, $s0, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135b50) {
            ctx->pc = 0x135B80u;
            goto label_135b80;
        }
    }
    ctx->pc = 0x135B58u;
label_135b58:
    // 0x135b58: 0x2081021  addu        $v0, $s0, $t0
    ctx->pc = 0x135b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 8)));
    // 0x135b5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x135b5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135b60: 0xc042c56  jal         func_10B158
    ctx->pc = 0x135B60u;
    SET_GPR_U32(ctx, 31, 0x135B68u);
    ctx->pc = 0x135B64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135B60u;
            // 0x135b64: 0xa0400000  sb          $zero, 0x0($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135B68u; }
        if (ctx->pc != 0x135B68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135B68u; }
        if (ctx->pc != 0x135B68u) { return; }
    }
    ctx->pc = 0x135B68u;
label_135b68:
    // 0x135b68: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x135b68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135b6c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x135b6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135b70: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x135B70u;
    SET_GPR_U32(ctx, 31, 0x135B78u);
    ctx->pc = 0x135B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135B70u;
            // 0x135b74: 0x24460001  addiu       $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135B78u; }
        if (ctx->pc != 0x135B78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135B78u; }
        if (ctx->pc != 0x135B78u) { return; }
    }
    ctx->pc = 0x135B78u;
label_135b78:
    // 0x135b78: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x135B78u;
    {
        const bool branch_taken_0x135b78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135B78u;
            // 0x135b7c: 0xa2000000  sb          $zero, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135b78) {
            ctx->pc = 0x135C00u;
            goto label_135c00;
        }
    }
    ctx->pc = 0x135B80u;
label_135b80:
    // 0x135b80: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x135b80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x135b84: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x135b84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x135b88: 0x15020003  bne         $t0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x135B88u;
    {
        const bool branch_taken_0x135b88 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        ctx->pc = 0x135B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135B88u;
            // 0x135b8c: 0xa0600000  sb          $zero, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135b88) {
            ctx->pc = 0x135B98u;
            goto label_135b98;
        }
    }
    ctx->pc = 0x135B90u;
    // 0x135b90: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x135b90u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x135b94: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x135b94u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_135b98:
    // 0x135b98: 0x29020129  slti        $v0, $t0, 0x129
    ctx->pc = 0x135b98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)297) ? 1 : 0);
    // 0x135b9c: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x135B9Cu;
    {
        const bool branch_taken_0x135b9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x135BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135B9Cu;
            // 0x135ba0: 0x100282d  daddu       $a1, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135b9c) {
            ctx->pc = 0x135BDCu;
            goto label_135bdc;
        }
    }
    ctx->pc = 0x135BA4u;
    // 0x135ba4: 0xc81821  addu        $v1, $a2, $t0
    ctx->pc = 0x135ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x135ba8: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x135ba8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x135bac: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x135BACu;
    {
        const bool branch_taken_0x135bac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x135BB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135BACu;
            // 0x135bb0: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135bac) {
            ctx->pc = 0x135BDCu;
            goto label_135bdc;
        }
    }
    ctx->pc = 0x135BB4u;
    // 0x135bb4: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x135bb4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
label_135bb8:
    // 0x135bb8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x135bb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x135bbc: 0x28a40129  slti        $a0, $a1, 0x129
    ctx->pc = 0x135bbcu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)297) ? 1 : 0);
    // 0x135bc0: 0xc51821  addu        $v1, $a2, $a1
    ctx->pc = 0x135bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x135bc4: 0xa0e20000  sb          $v0, 0x0($a3)
    ctx->pc = 0x135bc4u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x135bc8: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x135BC8u;
    {
        const bool branch_taken_0x135bc8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x135BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135BC8u;
            // 0x135bcc: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135bc8) {
            ctx->pc = 0x135BDCu;
            goto label_135bdc;
        }
    }
    ctx->pc = 0x135BD0u;
    // 0x135bd0: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x135bd0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x135bd4: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x135BD4u;
    {
        const bool branch_taken_0x135bd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x135bd4) {
            ctx->pc = 0x135BD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135BD4u;
            // 0x135bd8: 0x90620000  lbu         $v0, 0x0($v1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135BB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_135bb8;
        }
    }
    ctx->pc = 0x135BDCu;
label_135bdc:
    // 0x135bdc: 0xa81023  subu        $v0, $a1, $t0
    ctx->pc = 0x135bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 8)));
    // 0x135be0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x135be0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135be4: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x135be4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x135be8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135be8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135bec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135becu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135bf0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x135bf0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135bf4: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x135bf4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x135bf8: 0x804d57e  j           func_1355F8
    ctx->pc = 0x135BF8u;
    ctx->pc = 0x135BFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135BF8u;
            // 0x135bfc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1355F8u;
    if (runtime->hasFunction(0x1355F8u)) {
        auto targetFn = runtime->lookupFunction(0x1355F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001355F8_0x1355f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135C00u;
label_135c00:
    // 0x135c00: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135c00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135c04: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x135c04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135c08: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x135c08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x135c0c: 0x3e00008  jr          $ra
    ctx->pc = 0x135C0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135C0Cu;
            // 0x135c10: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135B10u: goto label_135b10;
            case 0x135B48u: goto label_135b48;
            case 0x135B4Cu: goto label_135b4c;
            case 0x135B50u: goto label_135b50;
            case 0x135B58u: goto label_135b58;
            case 0x135B68u: goto label_135b68;
            case 0x135B78u: goto label_135b78;
            case 0x135B80u: goto label_135b80;
            case 0x135B98u: goto label_135b98;
            case 0x135BB8u: goto label_135bb8;
            case 0x135BDCu: goto label_135bdc;
            case 0x135C00u: goto label_135c00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135C14u;
    // 0x135c14: 0x0  nop
    ctx->pc = 0x135c14u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
