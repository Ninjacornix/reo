#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131B60
// Address: 0x131b60 - 0x131c50
void sub_00131B60_0x131b60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131B60_0x131b60");
#endif

    switch (ctx->pc) {
        case 0x131b98u: goto label_131b98;
        case 0x131bacu: goto label_131bac;
        case 0x131bc8u: goto label_131bc8;
        case 0x131bd4u: goto label_131bd4;
        default: break;
    }

    ctx->pc = 0x131b60u;

    // 0x131b60: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x131b60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x131b64: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131b68: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131b68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131b6c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x131b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x131b70: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x131b70u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131b74: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x131b74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x131b78: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x131b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131b7c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x131b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x131b80: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x131b80u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x131b84: 0x1840000d  blez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x131B84u;
    {
        const bool branch_taken_0x131b84 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x131B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131B84u;
            // 0x131b88: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131b84) {
            ctx->pc = 0x131BBCu;
            goto label_131bbc;
        }
    }
    ctx->pc = 0x131B8Cu;
    // 0x131b8c: 0x26110018  addiu       $s1, $s0, 0x18
    ctx->pc = 0x131b8cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x131b90: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x131b90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x131b94: 0x0  nop
    ctx->pc = 0x131b94u;
    // NOP
label_131b98:
    // 0x131b98: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x131b98u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x131b9c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x131b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x131ba0: 0x8c430014  lw          $v1, 0x14($v0)
    ctx->pc = 0x131ba0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x131ba4: 0x60f809  jalr        $v1
    ctx->pc = 0x131BA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x131BACu);
        ctx->pc = 0x131BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131BA4u;
            // 0x131ba8: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x131BACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131B98u: goto label_131b98;
            case 0x131BACu: goto label_131bac;
            case 0x131BBCu: goto label_131bbc;
            case 0x131BC8u: goto label_131bc8;
            case 0x131BD4u: goto label_131bd4;
            case 0x131C30u: goto label_131c30;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x131BACu; }
            if (ctx->pc != 0x131BACu) { return; }
        }
        }
    }
    ctx->pc = 0x131BACu;
label_131bac:
    // 0x131bac: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x131bacu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x131bb0: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x131bb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x131bb4: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x131BB4u;
    {
        const bool branch_taken_0x131bb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x131bb4) {
            ctx->pc = 0x131BB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131BB4u;
            // 0x131bb8: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131B98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_131b98;
        }
    }
    ctx->pc = 0x131BBCu;
label_131bbc:
    // 0x131bbc: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x131bbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x131bc0: 0xc04b2f0  jal         func_12CBC0
    ctx->pc = 0x131BC0u;
    SET_GPR_U32(ctx, 31, 0x131BC8u);
    ctx->pc = 0x131BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131BC0u;
            // 0x131bc4: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CBC0u;
    if (runtime->hasFunction(0x12CBC0u)) {
        auto targetFn = runtime->lookupFunction(0x12CBC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131BC8u; }
        if (ctx->pc != 0x131BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CBC0_0x12cbc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131BC8u; }
        if (ctx->pc != 0x131BC8u) { return; }
    }
    ctx->pc = 0x131BC8u;
label_131bc8:
    // 0x131bc8: 0xae130014  sw          $s3, 0x14($s0)
    ctx->pc = 0x131bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 19));
    // 0x131bcc: 0xc04b320  jal         func_12CC80
    ctx->pc = 0x131BCCu;
    SET_GPR_U32(ctx, 31, 0x131BD4u);
    ctx->pc = 0x131BD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131BCCu;
            // 0x131bd0: 0x8e040004  lw          $a0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12CC80u;
    if (runtime->hasFunction(0x12CC80u)) {
        auto targetFn = runtime->lookupFunction(0x12CC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131BD4u; }
        if (ctx->pc != 0x131BD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CC80_0x12cc80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131BD4u; }
        if (ctx->pc != 0x131BD4u) { return; }
    }
    ctx->pc = 0x131BD4u;
label_131bd4:
    // 0x131bd4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x131bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131bd8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x131bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x131bdc: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x131bdcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x131be0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x131be0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x131be4: 0xa2030001  sb          $v1, 0x1($s0)
    ctx->pc = 0x131be4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x131be8: 0xae040090  sw          $a0, 0x90($s0)
    ctx->pc = 0x131be8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 4));
    // 0x131bec: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x131becu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x131bf0: 0xae02008c  sw          $v0, 0x8C($s0)
    ctx->pc = 0x131bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 2));
    // 0x131bf4: 0xae00004c  sw          $zero, 0x4C($s0)
    ctx->pc = 0x131bf4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 0));
    // 0x131bf8: 0xa2000071  sb          $zero, 0x71($s0)
    ctx->pc = 0x131bf8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 113), (uint8_t)GPR_U32(ctx, 0));
    // 0x131bfc: 0xae00009c  sw          $zero, 0x9C($s0)
    ctx->pc = 0x131bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 156), GPR_U32(ctx, 0));
    // 0x131c00: 0xae0000a4  sw          $zero, 0xA4($s0)
    ctx->pc = 0x131c00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 164), GPR_U32(ctx, 0));
    // 0x131c04: 0x8e040074  lw          $a0, 0x74($s0)
    ctx->pc = 0x131c04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 116)));
    // 0x131c08: 0x8c62f3c4  lw          $v0, -0xC3C($v1)
    ctx->pc = 0x131c08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294964164)));
    // 0x131c0c: 0x10800008  beqz        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x131C0Cu;
    {
        const bool branch_taken_0x131c0c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x131C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131C0Cu;
            // 0x131c10: 0xae0200a0  sw          $v0, 0xA0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 160), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131c0c) {
            ctx->pc = 0x131C30u;
            goto label_131c30;
        }
    }
    ctx->pc = 0x131C14u;
    // 0x131c14: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131c14u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131c18: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131c18u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131c1c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x131c1cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131c20: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x131c20u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x131c24: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x131c24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x131c28: 0x8048a52  j           func_122948
    ctx->pc = 0x131C28u;
    ctx->pc = 0x131C2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131C28u;
            // 0x131c2c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x122948u;
    if (runtime->hasFunction(0x122948u)) {
        auto targetFn = runtime->lookupFunction(0x122948u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00122948_0x122948(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131C30u;
label_131c30:
    // 0x131c30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131c30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131c34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x131c34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131c38: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x131c38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x131c3c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x131c3cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x131c40: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x131c40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x131c44: 0x3e00008  jr          $ra
    ctx->pc = 0x131C44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131C44u;
            // 0x131c48: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131B98u: goto label_131b98;
            case 0x131BACu: goto label_131bac;
            case 0x131BBCu: goto label_131bbc;
            case 0x131BC8u: goto label_131bc8;
            case 0x131BD4u: goto label_131bd4;
            case 0x131C30u: goto label_131c30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131C4Cu;
    // 0x131c4c: 0x0  nop
    ctx->pc = 0x131c4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
