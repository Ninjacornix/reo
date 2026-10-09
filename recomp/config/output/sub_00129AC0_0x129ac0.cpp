#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129AC0
// Address: 0x129ac0 - 0x129bd4
void sub_00129AC0_0x129ac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129AC0_0x129ac0");
#endif

    switch (ctx->pc) {
        case 0x129afcu: goto label_129afc;
        case 0x129b24u: goto label_129b24;
        case 0x129b6cu: goto label_129b6c;
        case 0x129bb4u: goto label_129bb4;
        default: break;
    }

    ctx->pc = 0x129ac0u;

    // 0x129ac0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x129ac0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x129ac4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129ac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129ac8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x129ac8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129acc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x129accu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x129ad0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x129ad0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129ad4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x129ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x129ad8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x129ad8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129adc: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x129adcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x129ae0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x129ae0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129ae4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x129ae4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129ae8: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x129ae8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129aec: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x129aecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x129af0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x129af0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x129af4: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129AF4u;
    SET_GPR_U32(ctx, 31, 0x129AFCu);
    ctx->pc = 0x129AF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129AF4u;
            // 0x129af8: 0x220402d  daddu       $t0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129AFCu; }
        if (ctx->pc != 0x129AFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129AFCu; }
        if (ctx->pc != 0x129AFCu) { return; }
    }
    ctx->pc = 0x129AFCu;
label_129afc:
    // 0x129afc: 0x56000004  bnel        $s0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x129AFCu;
    {
        const bool branch_taken_0x129afc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x129afc) {
            ctx->pc = 0x129B00u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129AFCu;
            // 0x129b00: 0x82020001  lb          $v0, 0x1($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129B10u;
            goto label_129b10;
        }
    }
    ctx->pc = 0x129B04u;
    // 0x129b04: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129b04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x129b08: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x129B08u;
    {
        const bool branch_taken_0x129b08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129B08u;
            // 0x129b0c: 0x2484a108  addiu       $a0, $a0, -0x5EF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942984));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129b08) {
            ctx->pc = 0x129B64u;
            goto label_129b64;
        }
    }
    ctx->pc = 0x129B10u;
label_129b10:
    // 0x129b10: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x129b10u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x129b14: 0x14530003  bne         $v0, $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x129B14u;
    {
        const bool branch_taken_0x129b14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 19));
        if (branch_taken_0x129b14) {
            ctx->pc = 0x129B24u;
            goto label_129b24;
        }
    }
    ctx->pc = 0x129B1Cu;
    // 0x129b1c: 0xc04a5f8  jal         func_1297E0
    ctx->pc = 0x129B1Cu;
    SET_GPR_U32(ctx, 31, 0x129B24u);
    ctx->pc = 0x129B20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129B1Cu;
            // 0x129b20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297E0u;
    if (runtime->hasFunction(0x1297E0u)) {
        auto targetFn = runtime->lookupFunction(0x1297E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129B24u; }
        if (ctx->pc != 0x129B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297E0_0x1297e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129B24u; }
        if (ctx->pc != 0x129B24u) { return; }
    }
    ctx->pc = 0x129B24u;
label_129b24:
    // 0x129b24: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x129B24u;
    {
        const bool branch_taken_0x129b24 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x129B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129B24u;
            // 0x129b28: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129b24) {
            ctx->pc = 0x129B38u;
            goto label_129b38;
        }
    }
    ctx->pc = 0x129B2Cu;
    // 0x129b2c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x129B2Cu;
    {
        const bool branch_taken_0x129b2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129B2Cu;
            // 0x129b30: 0xae120014  sw          $s2, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129b2c) {
            ctx->pc = 0x129B78u;
            goto label_129b78;
        }
    }
    ctx->pc = 0x129B34u;
    // 0x129b34: 0x0  nop
    ctx->pc = 0x129b34u;
    // NOP
label_129b38:
    // 0x129b38: 0x16220003  bne         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x129B38u;
    {
        const bool branch_taken_0x129b38 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x129b38) {
            ctx->pc = 0x129B48u;
            goto label_129b48;
        }
    }
    ctx->pc = 0x129B40u;
    // 0x129b40: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x129B40u;
    {
        const bool branch_taken_0x129b40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129B40u;
            // 0x129b44: 0x8e020014  lw          $v0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129b40) {
            ctx->pc = 0x129B54u;
            goto label_129b54;
        }
    }
    ctx->pc = 0x129B48u;
label_129b48:
    // 0x129b48: 0x16330005  bne         $s1, $s3, . + 4 + (0x5 << 2)
    ctx->pc = 0x129B48u;
    {
        const bool branch_taken_0x129b48 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 19));
        ctx->pc = 0x129B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129B48u;
            // 0x129b4c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129b48) {
            ctx->pc = 0x129B60u;
            goto label_129b60;
        }
    }
    ctx->pc = 0x129B50u;
    // 0x129b50: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x129b50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_129b54:
    // 0x129b54: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x129b54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x129b58: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x129B58u;
    {
        const bool branch_taken_0x129b58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129B58u;
            // 0x129b5c: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129b58) {
            ctx->pc = 0x129B78u;
            goto label_129b78;
        }
    }
    ctx->pc = 0x129B60u;
label_129b60:
    // 0x129b60: 0x2484a130  addiu       $a0, $a0, -0x5ED0
    ctx->pc = 0x129b60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943024));
label_129b64:
    // 0x129b64: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129B64u;
    SET_GPR_U32(ctx, 31, 0x129B6Cu);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129B6Cu; }
        if (ctx->pc != 0x129B6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129B6Cu; }
        if (ctx->pc != 0x129B6Cu) { return; }
    }
    ctx->pc = 0x129B6Cu;
label_129b6c:
    // 0x129b6c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x129B6Cu;
    {
        const bool branch_taken_0x129b6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129B6Cu;
            // 0x129b70: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129b6c) {
            ctx->pc = 0x129BB8u;
            goto label_129bb8;
        }
    }
    ctx->pc = 0x129B74u;
    // 0x129b74: 0x0  nop
    ctx->pc = 0x129b74u;
    // NOP
label_129b78:
    // 0x129b78: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x129b78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x129b7c: 0x4430004  bgezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x129B7Cu;
    {
        const bool branch_taken_0x129b7c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x129b7c) {
            ctx->pc = 0x129B80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129B7Cu;
            // 0x129b80: 0x8e03000c  lw          $v1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129B90u;
            goto label_129b90;
        }
    }
    ctx->pc = 0x129B84u;
    // 0x129b84: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x129B84u;
    {
        const bool branch_taken_0x129b84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129B84u;
            // 0x129b88: 0xae000014  sw          $zero, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129b84) {
            ctx->pc = 0x129B9Cu;
            goto label_129b9c;
        }
    }
    ctx->pc = 0x129B8Cu;
    // 0x129b8c: 0x0  nop
    ctx->pc = 0x129b8cu;
    // NOP
label_129b90:
    // 0x129b90: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x129b90u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x129b94: 0x54400001  bnel        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x129B94u;
    {
        const bool branch_taken_0x129b94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x129b94) {
            ctx->pc = 0x129B98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129B94u;
            // 0x129b98: 0xae030014  sw          $v1, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129B9Cu;
            goto label_129b9c;
        }
    }
    ctx->pc = 0x129B9Cu;
label_129b9c:
    // 0x129b9c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x129b9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129ba0: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x129ba0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129ba4: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x129ba4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x129ba8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x129ba8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129bac: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129BACu;
    SET_GPR_U32(ctx, 31, 0x129BB4u);
    ctx->pc = 0x129BB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129BACu;
            // 0x129bb0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129BB4u; }
        if (ctx->pc != 0x129BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129BB4u; }
        if (ctx->pc != 0x129BB4u) { return; }
    }
    ctx->pc = 0x129BB4u;
label_129bb4:
    // 0x129bb4: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x129bb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_129bb8:
    // 0x129bb8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129bb8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129bbc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129bbcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129bc0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x129bc0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x129bc4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x129bc4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x129bc8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x129bc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x129bcc: 0x3e00008  jr          $ra
    ctx->pc = 0x129BCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129BCCu;
            // 0x129bd0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129AFCu: goto label_129afc;
            case 0x129B10u: goto label_129b10;
            case 0x129B24u: goto label_129b24;
            case 0x129B38u: goto label_129b38;
            case 0x129B48u: goto label_129b48;
            case 0x129B54u: goto label_129b54;
            case 0x129B60u: goto label_129b60;
            case 0x129B64u: goto label_129b64;
            case 0x129B6Cu: goto label_129b6c;
            case 0x129B78u: goto label_129b78;
            case 0x129B90u: goto label_129b90;
            case 0x129B9Cu: goto label_129b9c;
            case 0x129BB4u: goto label_129bb4;
            case 0x129BB8u: goto label_129bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129BD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
