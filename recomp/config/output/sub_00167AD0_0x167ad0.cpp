#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167AD0
// Address: 0x167ad0 - 0x167bc0
void sub_00167AD0_0x167ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167AD0_0x167ad0");
#endif

    switch (ctx->pc) {
        case 0x167b30u: goto label_167b30;
        case 0x167b40u: goto label_167b40;
        case 0x167b8cu: goto label_167b8c;
        case 0x167ba0u: goto label_167ba0;
        default: break;
    }

    ctx->pc = 0x167ad0u;

    // 0x167ad0: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x167ad0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x167ad4: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x167ad4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x167ad8: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x167ad8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x167adc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167adcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167ae0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x167ae0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x167ae4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x167ae4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167ae8: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x167ae8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x167aec: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x167aecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167af0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x167af0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x167af4: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x167af4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167af8: 0x26461140  addiu       $a2, $s2, 0x1140
    ctx->pc = 0x167af8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4416));
    // 0x167afc: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x167afcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x167b00: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167b00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167b04: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x167b04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167b08: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x167b08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x167b0c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x167b0cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167b10: 0x12200024  beqz        $s1, . + 4 + (0x24 << 2)
    ctx->pc = 0x167B10u;
    {
        const bool branch_taken_0x167b10 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x167B14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167B10u;
            // 0x167b14: 0xc33021  addu        $a2, $a2, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167b10) {
            ctx->pc = 0x167BA4u;
            goto label_167ba4;
        }
    }
    ctx->pc = 0x167B18u;
    // 0x167b18: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x167b18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x167b1c: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x167B1Cu;
    {
        const bool branch_taken_0x167b1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x167b1c) {
            ctx->pc = 0x167B20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167B1Cu;
            // 0x167b20: 0x24d00010  addiu       $s0, $a2, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x167B38u;
            goto label_167b38;
        }
    }
    ctx->pc = 0x167B24u;
    // 0x167b24: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x167b24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167b28: 0xc05a704  jal         func_169C10
    ctx->pc = 0x167B28u;
    SET_GPR_U32(ctx, 31, 0x167B30u);
    ctx->pc = 0x167B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167B28u;
            // 0x167b2c: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B30u; }
        if (ctx->pc != 0x167B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B30u; }
        if (ctx->pc != 0x167B30u) { return; }
    }
    ctx->pc = 0x167B30u;
label_167b30:
    // 0x167b30: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x167B30u;
    {
        const bool branch_taken_0x167b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167B30u;
            // 0x167b34: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167b30) {
            ctx->pc = 0x167BA8u;
            goto label_167ba8;
        }
    }
    ctx->pc = 0x167B38u;
label_167b38:
    // 0x167b38: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167B38u;
    SET_GPR_U32(ctx, 31, 0x167B40u);
    ctx->pc = 0x167B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167B38u;
            // 0x167b3c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B40u; }
        if (ctx->pc != 0x167B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B40u; }
        if (ctx->pc != 0x167B40u) { return; }
    }
    ctx->pc = 0x167B40u;
label_167b40:
    // 0x167b40: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x167b40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167b44: 0x8e020024  lw          $v0, 0x24($s0)
    ctx->pc = 0x167b44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x167b48: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x167b48u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167b4c: 0x8e03001c  lw          $v1, 0x1C($s0)
    ctx->pc = 0x167b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x167b50: 0x34a50407  ori         $a1, $a1, 0x407
    ctx->pc = 0x167b50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1031);
    // 0x167b54: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x167b54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x167b58: 0x433023  subu        $a2, $v0, $v1
    ctx->pc = 0x167b58u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x167b5c: 0x43182a  slt         $v1, $v0, $v1
    ctx->pc = 0x167b5cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x167b60: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x167B60u;
    {
        const bool branch_taken_0x167b60 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x167B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167B60u;
            // 0x167b64: 0xae020024  sw          $v0, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167b60) {
            ctx->pc = 0x167B6Cu;
            goto label_167b6c;
        }
    }
    ctx->pc = 0x167B68u;
    // 0x167b68: 0xae060024  sw          $a2, 0x24($s0)
    ctx->pc = 0x167b68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 6));
label_167b6c:
    // 0x167b6c: 0x8e02002c  lw          $v0, 0x2C($s0)
    ctx->pc = 0x167b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x167b70: 0x8e030028  lw          $v1, 0x28($s0)
    ctx->pc = 0x167b70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x167b74: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x167b74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x167b78: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x167b78u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x167b7c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x167B7Cu;
    {
        const bool branch_taken_0x167b7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x167B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167B7Cu;
            // 0x167b80: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167b7c) {
            ctx->pc = 0x167B90u;
            goto label_167b90;
        }
    }
    ctx->pc = 0x167B84u;
    // 0x167b84: 0xc05a704  jal         func_169C10
    ctx->pc = 0x167B84u;
    SET_GPR_U32(ctx, 31, 0x167B8Cu);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B8Cu; }
        if (ctx->pc != 0x167B8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167B8Cu; }
        if (ctx->pc != 0x167B8Cu) { return; }
    }
    ctx->pc = 0x167B8Cu;
label_167b8c:
    // 0x167b8c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x167b8cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_167b90:
    // 0x167b90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x167b90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167b94: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167b94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167b98: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x167B98u;
    SET_GPR_U32(ctx, 31, 0x167BA0u);
    ctx->pc = 0x167B9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167B98u;
            // 0x167b9c: 0xae420044  sw          $v0, 0x44($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167BA0u; }
        if (ctx->pc != 0x167BA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167BA0u; }
        if (ctx->pc != 0x167BA0u) { return; }
    }
    ctx->pc = 0x167BA0u;
label_167ba0:
    // 0x167ba0: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x167ba0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_167ba4:
    // 0x167ba4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167ba4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_167ba8:
    // 0x167ba8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167ba8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167bac: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167bacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167bb0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x167bb0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167bb4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x167bb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167bb8: 0x3e00008  jr          $ra
    ctx->pc = 0x167BB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167BB8u;
            // 0x167bbc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167B30u: goto label_167b30;
            case 0x167B38u: goto label_167b38;
            case 0x167B40u: goto label_167b40;
            case 0x167B6Cu: goto label_167b6c;
            case 0x167B8Cu: goto label_167b8c;
            case 0x167B90u: goto label_167b90;
            case 0x167BA0u: goto label_167ba0;
            case 0x167BA4u: goto label_167ba4;
            case 0x167BA8u: goto label_167ba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167BC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
