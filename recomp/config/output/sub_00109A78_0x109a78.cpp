#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00109A78
// Address: 0x109a78 - 0x10a050
void sub_00109A78_0x109a78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00109A78_0x109a78");
#endif

    switch (ctx->pc) {
        case 0x109af0u: goto label_109af0;
        case 0x109bc0u: goto label_109bc0;
        case 0x109d0cu: goto label_109d0c;
        case 0x109e50u: goto label_109e50;
        case 0x109e64u: goto label_109e64;
        case 0x109e78u: goto label_109e78;
        case 0x109f60u: goto label_109f60;
        case 0x109f6cu: goto label_109f6c;
        case 0x109fb8u: goto label_109fb8;
        case 0x109fe4u: goto label_109fe4;
        default: break;
    }

    ctx->pc = 0x109a78u;

    // 0x109a78: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x109a78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x109a7c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x109a7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x109a80: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x109a80u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109a84: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x109a84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x109a88: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x109a88u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109a8c: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x109a8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x109a90: 0x80f02d  daddu       $fp, $a0, $zero
    ctx->pc = 0x109a90u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109a94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x109a94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x109a98: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x109a98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x109a9c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x109a9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x109aa0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x109aa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x109aa4: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x109aa4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x109aa8: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x109aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x109aac: 0x1620000e  bnez        $s1, . + 4 + (0xE << 2)
    ctx->pc = 0x109AACu;
    {
        const bool branch_taken_0x109aac = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x109AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109AACu;
            // 0x109ab0: 0xffbf0048  sd          $ra, 0x48($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109aac) {
            ctx->pc = 0x109AE8u;
            goto label_109ae8;
        }
    }
    ctx->pc = 0x109AB4u;
    // 0x109ab4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x109ab4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109ab8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x109ab8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x109abc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x109abcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x109ac0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x109ac0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x109ac4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x109ac4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x109ac8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x109ac8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x109acc: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x109accu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x109ad0: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x109ad0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x109ad4: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x109ad4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x109ad8: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x109ad8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x109adc: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x109adcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x109ae0: 0x8041c76  j           func_1071D8
    ctx->pc = 0x109AE0u;
    ctx->pc = 0x109AE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109AE0u;
            // 0x109ae4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001071D8_0x1071d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x109AE8u;
label_109ae8:
    // 0x109ae8: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x109AE8u;
    SET_GPR_U32(ctx, 31, 0x109AF0u);
    ctx->pc = 0x109AECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109AE8u;
            // 0x109aec: 0x2630fff8  addiu       $s0, $s1, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109AF0u; }
        if (ctx->pc != 0x109AF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109AF0u; }
        if (ctx->pc != 0x109AF0u) { return; }
    }
    ctx->pc = 0x109AF0u;
label_109af0:
    // 0x109af0: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x109af0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x109af4: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x109af4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x109af8: 0x26440013  addiu       $a0, $s2, 0x13
    ctx->pc = 0x109af8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 19));
    // 0x109afc: 0x200982d  daddu       $s3, $s0, $zero
    ctx->pc = 0x109afcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109b00: 0xa3b824  and         $s7, $a1, $v1
    ctx->pc = 0x109b00u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x109b04: 0x2c82001f  sltiu       $v0, $a0, 0x1F
    ctx->pc = 0x109b04u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)31) ? 1 : 0);
    // 0x109b08: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x109B08u;
    {
        const bool branch_taken_0x109b08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109B08u;
            // 0x109b0c: 0x2e0a82d  daddu       $s5, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109b08) {
            ctx->pc = 0x109B20u;
            goto label_109b20;
        }
    }
    ctx->pc = 0x109B10u;
    // 0x109b10: 0x2402fff0  addiu       $v0, $zero, -0x10
    ctx->pc = 0x109b10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x109b14: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x109B14u;
    {
        const bool branch_taken_0x109b14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109B14u;
            // 0x109b18: 0x82b024  and         $s6, $a0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 22, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109b14) {
            ctx->pc = 0x109B24u;
            goto label_109b24;
        }
    }
    ctx->pc = 0x109B1Cu;
    // 0x109b1c: 0x0  nop
    ctx->pc = 0x109b1cu;
    // NOP
label_109b20:
    // 0x109b20: 0x24160010  addiu       $s6, $zero, 0x10
    ctx->pc = 0x109b20u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_109b24:
    // 0x109b24: 0x2b6102b  sltu        $v0, $s5, $s6
    ctx->pc = 0x109b24u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 21) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
    // 0x109b28: 0x50400113  beql        $v0, $zero, . + 4 + (0x113 << 2)
    ctx->pc = 0x109B28u;
    {
        const bool branch_taken_0x109b28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x109b28) {
            ctx->pc = 0x109B2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109B28u;
            // 0x109b2c: 0x26720008  addiu       $s2, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109F78u;
            goto label_109f78;
        }
    }
    ctx->pc = 0x109B30u;
    // 0x109b30: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x109b30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x109b34: 0x2753021  addu        $a2, $s3, $s5
    ctx->pc = 0x109b34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 21)));
    // 0x109b38: 0x24499800  addiu       $t1, $v0, -0x6800
    ctx->pc = 0x109b38u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 4294940672));
    // 0x109b3c: 0x8d280008  lw          $t0, 0x8($t1)
    ctx->pc = 0x109b3cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x109b40: 0x10c8000b  beq         $a2, $t0, . + 4 + (0xB << 2)
    ctx->pc = 0x109B40u;
    {
        const bool branch_taken_0x109b40 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 8));
        ctx->pc = 0x109B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109B40u;
            // 0x109b44: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109b40) {
            ctx->pc = 0x109B70u;
            goto label_109b70;
        }
    }
    ctx->pc = 0x109B48u;
    // 0x109b48: 0x8cc40004  lw          $a0, 0x4($a2)
    ctx->pc = 0x109b48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x109b4c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x109b4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x109b50: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x109b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x109b54: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x109b54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x109b58: 0x30630001  andi        $v1, $v1, 0x1
    ctx->pc = 0x109b58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
    // 0x109b5c: 0x54600026  bnel        $v1, $zero, . + 4 + (0x26 << 2)
    ctx->pc = 0x109B5Cu;
    {
        const bool branch_taken_0x109b5c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x109b5c) {
            ctx->pc = 0x109B60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109B5Cu;
            // 0x109b60: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109BF8u;
            goto label_109bf8;
        }
    }
    ctx->pc = 0x109B64u;
    // 0x109b64: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x109B64u;
    {
        const bool branch_taken_0x109b64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109B64u;
            // 0x109b68: 0x2402fffc  addiu       $v0, $zero, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109b64) {
            ctx->pc = 0x109B78u;
            goto label_109b78;
        }
    }
    ctx->pc = 0x109B6Cu;
    // 0x109b6c: 0x0  nop
    ctx->pc = 0x109b6cu;
    // NOP
label_109b70:
    // 0x109b70: 0x8cc40004  lw          $a0, 0x4($a2)
    ctx->pc = 0x109b70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x109b74: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x109b74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
label_109b78:
    // 0x109b78: 0x14c80013  bne         $a2, $t0, . + 4 + (0x13 << 2)
    ctx->pc = 0x109B78u;
    {
        const bool branch_taken_0x109b78 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 8));
        ctx->pc = 0x109B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109B78u;
            // 0x109b7c: 0x823824  and         $a3, $a0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109b78) {
            ctx->pc = 0x109BC8u;
            goto label_109bc8;
        }
    }
    ctx->pc = 0x109B80u;
    // 0x109b80: 0xf51821  addu        $v1, $a3, $s5
    ctx->pc = 0x109b80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 21)));
    // 0x109b84: 0x26c20010  addiu       $v0, $s6, 0x10
    ctx->pc = 0x109b84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 16));
    // 0x109b88: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x109b88u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x109b8c: 0x5440001c  bnel        $v0, $zero, . + 4 + (0x1C << 2)
    ctx->pc = 0x109B8Cu;
    {
        const bool branch_taken_0x109b8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x109b8c) {
            ctx->pc = 0x109B90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109B8Cu;
            // 0x109b90: 0x8e620004  lw          $v0, 0x4($s3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109C00u;
            goto label_109c00;
        }
    }
    ctx->pc = 0x109B94u;
    // 0x109b94: 0x761023  subu        $v0, $v1, $s6
    ctx->pc = 0x109b94u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 22)));
    // 0x109b98: 0x2761821  addu        $v1, $s3, $s6
    ctx->pc = 0x109b98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 22)));
    // 0x109b9c: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x109b9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x109ba0: 0xad230008  sw          $v1, 0x8($t1)
    ctx->pc = 0x109ba0u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 8), GPR_U32(ctx, 3));
    // 0x109ba4: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x109ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x109ba8: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x109ba8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109bac: 0x8e620004  lw          $v0, 0x4($s3)
    ctx->pc = 0x109bacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x109bb0: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x109bb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x109bb4: 0x561025  or          $v0, $v0, $s6
    ctx->pc = 0x109bb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 22));
    // 0x109bb8: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x109BB8u;
    SET_GPR_U32(ctx, 31, 0x109BC0u);
    ctx->pc = 0x109BBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109BB8u;
            // 0x109bbc: 0xae620004  sw          $v0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109BC0u; }
        if (ctx->pc != 0x109BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109BC0u; }
        if (ctx->pc != 0x109BC0u) { return; }
    }
    ctx->pc = 0x109BC0u;
label_109bc0:
    // 0x109bc0: 0x10000109  b           . + 4 + (0x109 << 2)
    ctx->pc = 0x109BC0u;
    {
        const bool branch_taken_0x109bc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109BC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109BC0u;
            // 0x109bc4: 0x26620008  addiu       $v0, $s3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109bc0) {
            ctx->pc = 0x109FE8u;
            goto label_109fe8;
        }
    }
    ctx->pc = 0x109BC8u;
label_109bc8:
    // 0x109bc8: 0xf51821  addu        $v1, $a3, $s5
    ctx->pc = 0x109bc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 21)));
    // 0x109bcc: 0x76102b  sltu        $v0, $v1, $s6
    ctx->pc = 0x109bccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
    // 0x109bd0: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x109BD0u;
    {
        const bool branch_taken_0x109bd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x109bd0) {
            ctx->pc = 0x109BD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109BD0u;
            // 0x109bd4: 0x8e620004  lw          $v0, 0x4($s3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109C00u;
            goto label_109c00;
        }
    }
    ctx->pc = 0x109BD8u;
    // 0x109bd8: 0x8cc40008  lw          $a0, 0x8($a2)
    ctx->pc = 0x109bd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x109bdc: 0x60b82d  daddu       $s7, $v1, $zero
    ctx->pc = 0x109bdcu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109be0: 0x8cc2000c  lw          $v0, 0xC($a2)
    ctx->pc = 0x109be0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x109be4: 0x26720008  addiu       $s2, $s3, 0x8
    ctx->pc = 0x109be4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x109be8: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x109be8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x109bec: 0x100000e2  b           . + 4 + (0xE2 << 2)
    ctx->pc = 0x109BECu;
    {
        const bool branch_taken_0x109bec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109BECu;
            // 0x109bf0: 0xac440008  sw          $a0, 0x8($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109bec) {
            ctx->pc = 0x109F78u;
            goto label_109f78;
        }
    }
    ctx->pc = 0x109BF4u;
    // 0x109bf4: 0x0  nop
    ctx->pc = 0x109bf4u;
    // NOP
label_109bf8:
    // 0x109bf8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x109bf8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109bfc: 0x8e620004  lw          $v0, 0x4($s3)
    ctx->pc = 0x109bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
label_109c00:
    // 0x109c00: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x109c00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x109c04: 0x14400095  bnez        $v0, . + 4 + (0x95 << 2)
    ctx->pc = 0x109C04u;
    {
        const bool branch_taken_0x109c04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109C04u;
            // 0x109c08: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109c04) {
            ctx->pc = 0x109E5Cu;
            goto label_109e5c;
        }
    }
    ctx->pc = 0x109C0Cu;
    // 0x109c0c: 0x8e620000  lw          $v0, 0x0($s3)
    ctx->pc = 0x109c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x109c10: 0x2404fffc  addiu       $a0, $zero, -0x4
    ctx->pc = 0x109c10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x109c14: 0x262a023  subu        $s4, $s3, $v0
    ctx->pc = 0x109c14u;
    SET_GPR_S32(ctx, 20, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x109c18: 0x8e830004  lw          $v1, 0x4($s4)
    ctx->pc = 0x109c18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x109c1c: 0x10c00056  beqz        $a2, . + 4 + (0x56 << 2)
    ctx->pc = 0x109C1Cu;
    {
        const bool branch_taken_0x109c1c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x109C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109C1Cu;
            // 0x109c20: 0x642024  and         $a0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109c1c) {
            ctx->pc = 0x109D78u;
            goto label_109d78;
        }
    }
    ctx->pc = 0x109C24u;
    // 0x109c24: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x109c24u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x109c28: 0x24629800  addiu       $v0, $v1, -0x6800
    ctx->pc = 0x109c28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294940672));
    // 0x109c2c: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x109c2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x109c30: 0x14c30043  bne         $a2, $v1, . + 4 + (0x43 << 2)
    ctx->pc = 0x109C30u;
    {
        const bool branch_taken_0x109c30 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 3));
        ctx->pc = 0x109C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109C30u;
            // 0x109c34: 0xe41021  addu        $v0, $a3, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109c30) {
            ctx->pc = 0x109D40u;
            goto label_109d40;
        }
    }
    ctx->pc = 0x109C38u;
    // 0x109c38: 0xe41821  addu        $v1, $a3, $a0
    ctx->pc = 0x109c38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x109c3c: 0x26c20010  addiu       $v0, $s6, 0x10
    ctx->pc = 0x109c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 16));
    // 0x109c40: 0x75b821  addu        $s7, $v1, $s5
    ctx->pc = 0x109c40u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 21)));
    // 0x109c44: 0x2e2102b  sltu        $v0, $s7, $v0
    ctx->pc = 0x109c44u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 23) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x109c48: 0x1440004b  bnez        $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x109C48u;
    {
        const bool branch_taken_0x109c48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109C4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109C48u;
            // 0x109c4c: 0x280802d  daddu       $s0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109c48) {
            ctx->pc = 0x109D78u;
            goto label_109d78;
        }
    }
    ctx->pc = 0x109C50u;
    // 0x109c50: 0x8e82000c  lw          $v0, 0xC($s4)
    ctx->pc = 0x109c50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 12)));
    // 0x109c54: 0x8e840008  lw          $a0, 0x8($s4)
    ctx->pc = 0x109c54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x109c58: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x109c58u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x109c5c: 0xac440008  sw          $a0, 0x8($v0)
    ctx->pc = 0x109c5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 4));
    // 0x109c60: 0x26a6fffc  addiu       $a2, $s5, -0x4
    ctx->pc = 0x109c60u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967292));
    // 0x109c64: 0x2cc20025  sltiu       $v0, $a2, 0x25
    ctx->pc = 0x109c64u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)37) ? 1 : 0);
    // 0x109c68: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x109C68u;
    {
        const bool branch_taken_0x109c68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x109C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109C68u;
            // 0x109c6c: 0x26120008  addiu       $s2, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109c68) {
            ctx->pc = 0x109D00u;
            goto label_109d00;
        }
    }
    ctx->pc = 0x109C70u;
    // 0x109c70: 0x2cc20014  sltiu       $v0, $a2, 0x14
    ctx->pc = 0x109c70u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)20) ? 1 : 0);
    // 0x109c74: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x109c74u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109c78: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x109C78u;
    {
        const bool branch_taken_0x109c78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109C7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109C78u;
            // 0x109c7c: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109c78) {
            ctx->pc = 0x109CD8u;
            goto label_109cd8;
        }
    }
    ctx->pc = 0x109C80u;
    // 0x109c80: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x109c80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x109c84: 0x2cc4001c  sltiu       $a0, $a2, 0x1C
    ctx->pc = 0x109c84u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)28) ? 1 : 0);
    // 0x109c88: 0x26280008  addiu       $t0, $s1, 0x8
    ctx->pc = 0x109c88u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x109c8c: 0x26070010  addiu       $a3, $s0, 0x10
    ctx->pc = 0x109c8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x109c90: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x109c90u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x109c94: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x109c94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x109c98: 0x1480000f  bnez        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x109C98u;
    {
        const bool branch_taken_0x109c98 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x109C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109C98u;
            // 0x109c9c: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109c98) {
            ctx->pc = 0x109CD8u;
            goto label_109cd8;
        }
    }
    ctx->pc = 0x109CA0u;
    // 0x109ca0: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x109ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x109ca4: 0x26280010  addiu       $t0, $s1, 0x10
    ctx->pc = 0x109ca4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x109ca8: 0x2cc30024  sltiu       $v1, $a2, 0x24
    ctx->pc = 0x109ca8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)36) ? 1 : 0);
    // 0x109cac: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x109cacu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x109cb0: 0x26070018  addiu       $a3, $s0, 0x18
    ctx->pc = 0x109cb0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x109cb4: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x109cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x109cb8: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x109CB8u;
    {
        const bool branch_taken_0x109cb8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x109CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109CB8u;
            // 0x109cbc: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109cb8) {
            ctx->pc = 0x109CD8u;
            goto label_109cd8;
        }
    }
    ctx->pc = 0x109CC0u;
    // 0x109cc0: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x109cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x109cc4: 0x26280018  addiu       $t0, $s1, 0x18
    ctx->pc = 0x109cc4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
    // 0x109cc8: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x109cc8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x109ccc: 0x26070020  addiu       $a3, $s0, 0x20
    ctx->pc = 0x109cccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
    // 0x109cd0: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x109cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x109cd4: 0xae02001c  sw          $v0, 0x1C($s0)
    ctx->pc = 0x109cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
label_109cd8:
    // 0x109cd8: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x109cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x109cdc: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x109cdcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x109ce0: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x109ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x109ce4: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x109ce4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x109ce8: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x109ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x109cec: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x109cecu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x109cf0: 0x8d030004  lw          $v1, 0x4($t0)
    ctx->pc = 0x109cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x109cf4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x109CF4u;
    {
        const bool branch_taken_0x109cf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109CF4u;
            // 0x109cf8: 0xace30004  sw          $v1, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109cf4) {
            ctx->pc = 0x109D0Cu;
            goto label_109d0c;
        }
    }
    ctx->pc = 0x109CFCu;
    // 0x109cfc: 0x0  nop
    ctx->pc = 0x109cfcu;
    // NOP
label_109d00:
    // 0x109d00: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x109d00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109d04: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x109D04u;
    SET_GPR_U32(ctx, 31, 0x109D0Cu);
    ctx->pc = 0x109D08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109D04u;
            // 0x109d08: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109D0Cu; }
        if (ctx->pc != 0x109D0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109D0Cu; }
        if (ctx->pc != 0x109D0Cu) { return; }
    }
    ctx->pc = 0x109D0Cu;
label_109d0c:
    // 0x109d0c: 0x2f61023  subu        $v0, $s7, $s6
    ctx->pc = 0x109d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 23), GPR_U32(ctx, 22)));
    // 0x109d10: 0x2962821  addu        $a1, $s4, $s6
    ctx->pc = 0x109d10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 22)));
    // 0x109d14: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x109d14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x109d18: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x109d18u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x109d1c: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x109d1cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x109d20: 0x24839800  addiu       $v1, $a0, -0x6800
    ctx->pc = 0x109d20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294940672));
    // 0x109d24: 0xac650008  sw          $a1, 0x8($v1)
    ctx->pc = 0x109d24u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 5));
    // 0x109d28: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x109d28u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109d2c: 0x8e820004  lw          $v0, 0x4($s4)
    ctx->pc = 0x109d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x109d30: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x109d30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x109d34: 0x561025  or          $v0, $v0, $s6
    ctx->pc = 0x109d34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 22));
    // 0x109d38: 0x100000a8  b           . + 4 + (0xA8 << 2)
    ctx->pc = 0x109D38u;
    {
        const bool branch_taken_0x109d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109D38u;
            // 0x109d3c: 0xae820004  sw          $v0, 0x4($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109d38) {
            ctx->pc = 0x109FDCu;
            goto label_109fdc;
        }
    }
    ctx->pc = 0x109D40u;
label_109d40:
    // 0x109d40: 0x552821  addu        $a1, $v0, $s5
    ctx->pc = 0x109d40u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
    // 0x109d44: 0xb6182b  sltu        $v1, $a1, $s6
    ctx->pc = 0x109d44u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
    // 0x109d48: 0x1460000b  bnez        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x109D48u;
    {
        const bool branch_taken_0x109d48 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x109D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109D48u;
            // 0x109d4c: 0x280802d  daddu       $s0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109d48) {
            ctx->pc = 0x109D78u;
            goto label_109d78;
        }
    }
    ctx->pc = 0x109D50u;
    // 0x109d50: 0x8cc40008  lw          $a0, 0x8($a2)
    ctx->pc = 0x109d50u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x109d54: 0x8cc2000c  lw          $v0, 0xC($a2)
    ctx->pc = 0x109d54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x109d58: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x109d58u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109d5c: 0x26120008  addiu       $s2, $s0, 0x8
    ctx->pc = 0x109d5cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x109d60: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x109d60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x109d64: 0xac440008  sw          $a0, 0x8($v0)
    ctx->pc = 0x109d64u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 4));
    // 0x109d68: 0x8e82000c  lw          $v0, 0xC($s4)
    ctx->pc = 0x109d68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 12)));
    // 0x109d6c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x109D6Cu;
    {
        const bool branch_taken_0x109d6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109D6Cu;
            // 0x109d70: 0x8e840008  lw          $a0, 0x8($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109d6c) {
            ctx->pc = 0x109DA0u;
            goto label_109da0;
        }
    }
    ctx->pc = 0x109D74u;
    // 0x109d74: 0x0  nop
    ctx->pc = 0x109d74u;
    // NOP
label_109d78:
    // 0x109d78: 0x12800037  beqz        $s4, . + 4 + (0x37 << 2)
    ctx->pc = 0x109D78u;
    {
        const bool branch_taken_0x109d78 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x109D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109D78u;
            // 0x109d7c: 0x951821  addu        $v1, $a0, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109d78) {
            ctx->pc = 0x109E58u;
            goto label_109e58;
        }
    }
    ctx->pc = 0x109D80u;
    // 0x109d80: 0x76102b  sltu        $v0, $v1, $s6
    ctx->pc = 0x109d80u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
    // 0x109d84: 0x14400035  bnez        $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x109D84u;
    {
        const bool branch_taken_0x109d84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109D84u;
            // 0x109d88: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109d84) {
            ctx->pc = 0x109E5Cu;
            goto label_109e5c;
        }
    }
    ctx->pc = 0x109D8Cu;
    // 0x109d8c: 0x8e82000c  lw          $v0, 0xC($s4)
    ctx->pc = 0x109d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 12)));
    // 0x109d90: 0x280802d  daddu       $s0, $s4, $zero
    ctx->pc = 0x109d90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109d94: 0x8e840008  lw          $a0, 0x8($s4)
    ctx->pc = 0x109d94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x109d98: 0x60b82d  daddu       $s7, $v1, $zero
    ctx->pc = 0x109d98u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109d9c: 0x26120008  addiu       $s2, $s0, 0x8
    ctx->pc = 0x109d9cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
label_109da0:
    // 0x109da0: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x109da0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x109da4: 0xac440008  sw          $a0, 0x8($v0)
    ctx->pc = 0x109da4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 4));
    // 0x109da8: 0x26a6fffc  addiu       $a2, $s5, -0x4
    ctx->pc = 0x109da8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967292));
    // 0x109dac: 0x2cc20025  sltiu       $v0, $a2, 0x25
    ctx->pc = 0x109dacu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)37) ? 1 : 0);
    // 0x109db0: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x109DB0u;
    {
        const bool branch_taken_0x109db0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x109DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109DB0u;
            // 0x109db4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109db0) {
            ctx->pc = 0x109E48u;
            goto label_109e48;
        }
    }
    ctx->pc = 0x109DB8u;
    // 0x109db8: 0x2cc20014  sltiu       $v0, $a2, 0x14
    ctx->pc = 0x109db8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)20) ? 1 : 0);
    // 0x109dbc: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x109dbcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109dc0: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x109DC0u;
    {
        const bool branch_taken_0x109dc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109DC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109DC0u;
            // 0x109dc4: 0x240382d  daddu       $a3, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109dc0) {
            ctx->pc = 0x109E20u;
            goto label_109e20;
        }
    }
    ctx->pc = 0x109DC8u;
    // 0x109dc8: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x109dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x109dcc: 0x2cc4001c  sltiu       $a0, $a2, 0x1C
    ctx->pc = 0x109dccu;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)28) ? 1 : 0);
    // 0x109dd0: 0x26280008  addiu       $t0, $s1, 0x8
    ctx->pc = 0x109dd0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x109dd4: 0x26070010  addiu       $a3, $s0, 0x10
    ctx->pc = 0x109dd4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x109dd8: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x109dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x109ddc: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x109ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x109de0: 0x1480000f  bnez        $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x109DE0u;
    {
        const bool branch_taken_0x109de0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x109DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109DE0u;
            // 0x109de4: 0xae03000c  sw          $v1, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109de0) {
            ctx->pc = 0x109E20u;
            goto label_109e20;
        }
    }
    ctx->pc = 0x109DE8u;
    // 0x109de8: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x109de8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x109dec: 0x26280010  addiu       $t0, $s1, 0x10
    ctx->pc = 0x109decu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x109df0: 0x2cc30024  sltiu       $v1, $a2, 0x24
    ctx->pc = 0x109df0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)36) ? 1 : 0);
    // 0x109df4: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x109df4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x109df8: 0x26070018  addiu       $a3, $s0, 0x18
    ctx->pc = 0x109df8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x109dfc: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x109dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x109e00: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x109E00u;
    {
        const bool branch_taken_0x109e00 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x109E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109E00u;
            // 0x109e04: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109e00) {
            ctx->pc = 0x109E20u;
            goto label_109e20;
        }
    }
    ctx->pc = 0x109E08u;
    // 0x109e08: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x109e08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x109e0c: 0x26280018  addiu       $t0, $s1, 0x18
    ctx->pc = 0x109e0cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
    // 0x109e10: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x109e10u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x109e14: 0x26070020  addiu       $a3, $s0, 0x20
    ctx->pc = 0x109e14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
    // 0x109e18: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x109e18u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x109e1c: 0xae02001c  sw          $v0, 0x1C($s0)
    ctx->pc = 0x109e1cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
label_109e20:
    // 0x109e20: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x109e20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x109e24: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x109e24u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x109e28: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x109e28u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x109e2c: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x109e2cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x109e30: 0x8d020000  lw          $v0, 0x0($t0)
    ctx->pc = 0x109e30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x109e34: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x109e34u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x109e38: 0x8d030004  lw          $v1, 0x4($t0)
    ctx->pc = 0x109e38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
    // 0x109e3c: 0xace30004  sw          $v1, 0x4($a3)
    ctx->pc = 0x109e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 3));
    // 0x109e40: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x109E40u;
    {
        const bool branch_taken_0x109e40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109E40u;
            // 0x109e44: 0x8e850004  lw          $a1, 0x4($s4) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109e40) {
            ctx->pc = 0x109F78u;
            goto label_109f78;
        }
    }
    ctx->pc = 0x109E48u;
label_109e48:
    // 0x109e48: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x109E48u;
    SET_GPR_U32(ctx, 31, 0x109E50u);
    ctx->pc = 0x109E4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109E48u;
            // 0x109e4c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109E50u; }
        if (ctx->pc != 0x109E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109E50u; }
        if (ctx->pc != 0x109E50u) { return; }
    }
    ctx->pc = 0x109E50u;
label_109e50:
    // 0x109e50: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x109E50u;
    {
        const bool branch_taken_0x109e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109E50u;
            // 0x109e54: 0x8e050004  lw          $a1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109e50) {
            ctx->pc = 0x109F78u;
            goto label_109f78;
        }
    }
    ctx->pc = 0x109E58u;
label_109e58:
    // 0x109e58: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x109e58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_109e5c:
    // 0x109e5c: 0xc041c76  jal         func_1071D8
    ctx->pc = 0x109E5Cu;
    SET_GPR_U32(ctx, 31, 0x109E64u);
    ctx->pc = 0x109E60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109E5Cu;
            // 0x109e60: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109E64u; }
        if (ctx->pc != 0x109E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001071D8_0x1071d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109E64u; }
        if (ctx->pc != 0x109E64u) { return; }
    }
    ctx->pc = 0x109E64u;
label_109e64:
    // 0x109e64: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x109e64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109e68: 0x56400005  bnel        $s2, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x109E68u;
    {
        const bool branch_taken_0x109e68 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x109e68) {
            ctx->pc = 0x109E6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109E68u;
            // 0x109e6c: 0x8e650004  lw          $a1, 0x4($s3) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109E80u;
            goto label_109e80;
        }
    }
    ctx->pc = 0x109E70u;
    // 0x109e70: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x109E70u;
    SET_GPR_U32(ctx, 31, 0x109E78u);
    ctx->pc = 0x109E74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109E70u;
            // 0x109e74: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109E78u; }
        if (ctx->pc != 0x109E78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109E78u; }
        if (ctx->pc != 0x109E78u) { return; }
    }
    ctx->pc = 0x109E78u;
label_109e78:
    // 0x109e78: 0x1000005b  b           . + 4 + (0x5B << 2)
    ctx->pc = 0x109E78u;
    {
        const bool branch_taken_0x109e78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109E78u;
            // 0x109e7c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109e78) {
            ctx->pc = 0x109FE8u;
            goto label_109fe8;
        }
    }
    ctx->pc = 0x109E80u;
label_109e80:
    // 0x109e80: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x109e80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x109e84: 0x2650fff8  addiu       $s0, $s2, -0x8
    ctx->pc = 0x109e84u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967288));
    // 0x109e88: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x109e88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x109e8c: 0x2621021  addu        $v0, $s3, $v0
    ctx->pc = 0x109e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x109e90: 0x16020009  bne         $s0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x109E90u;
    {
        const bool branch_taken_0x109e90 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x109E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109E90u;
            // 0x109e94: 0x26a6fffc  addiu       $a2, $s5, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109e90) {
            ctx->pc = 0x109EB8u;
            goto label_109eb8;
        }
    }
    ctx->pc = 0x109E98u;
    // 0x109e98: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x109e98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x109e9c: 0x260802d  daddu       $s0, $s3, $zero
    ctx->pc = 0x109e9cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109ea0: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x109ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x109ea4: 0x26120008  addiu       $s2, $s0, 0x8
    ctx->pc = 0x109ea4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x109ea8: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x109ea8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x109eac: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x109EACu;
    {
        const bool branch_taken_0x109eac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109EACu;
            // 0x109eb0: 0x2a2b821  addu        $s7, $s5, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109eac) {
            ctx->pc = 0x109F78u;
            goto label_109f78;
        }
    }
    ctx->pc = 0x109EB4u;
    // 0x109eb4: 0x0  nop
    ctx->pc = 0x109eb4u;
    // NOP
label_109eb8:
    // 0x109eb8: 0x2cc20025  sltiu       $v0, $a2, 0x25
    ctx->pc = 0x109eb8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)37) ? 1 : 0);
    // 0x109ebc: 0x10400026  beqz        $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x109EBCu;
    {
        const bool branch_taken_0x109ebc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x109EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109EBCu;
            // 0x109ec0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109ebc) {
            ctx->pc = 0x109F58u;
            goto label_109f58;
        }
    }
    ctx->pc = 0x109EC4u;
    // 0x109ec4: 0x2cc20014  sltiu       $v0, $a2, 0x14
    ctx->pc = 0x109ec4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)20) ? 1 : 0);
    // 0x109ec8: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x109ec8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109ecc: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x109ECCu;
    {
        const bool branch_taken_0x109ecc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109ECCu;
            // 0x109ed0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109ecc) {
            ctx->pc = 0x109F30u;
            goto label_109f30;
        }
    }
    ctx->pc = 0x109ED4u;
    // 0x109ed4: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x109ed4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x109ed8: 0x2cc4001c  sltiu       $a0, $a2, 0x1C
    ctx->pc = 0x109ed8u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)28) ? 1 : 0);
    // 0x109edc: 0x26270008  addiu       $a3, $s1, 0x8
    ctx->pc = 0x109edcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x109ee0: 0x26450008  addiu       $a1, $s2, 0x8
    ctx->pc = 0x109ee0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
    // 0x109ee4: 0xae420000  sw          $v0, 0x0($s2)
    ctx->pc = 0x109ee4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    // 0x109ee8: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x109ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x109eec: 0x14800010  bnez        $a0, . + 4 + (0x10 << 2)
    ctx->pc = 0x109EECu;
    {
        const bool branch_taken_0x109eec = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x109EF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109EECu;
            // 0x109ef0: 0xae430004  sw          $v1, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109eec) {
            ctx->pc = 0x109F30u;
            goto label_109f30;
        }
    }
    ctx->pc = 0x109EF4u;
    // 0x109ef4: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x109ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x109ef8: 0x26270010  addiu       $a3, $s1, 0x10
    ctx->pc = 0x109ef8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x109efc: 0x2cc30024  sltiu       $v1, $a2, 0x24
    ctx->pc = 0x109efcu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)36) ? 1 : 0);
    // 0x109f00: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x109f00u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x109f04: 0x26450010  addiu       $a1, $s2, 0x10
    ctx->pc = 0x109f04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 16));
    // 0x109f08: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x109f08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x109f0c: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x109F0Cu;
    {
        const bool branch_taken_0x109f0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x109F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109F0Cu;
            // 0x109f10: 0xae42000c  sw          $v0, 0xC($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109f0c) {
            ctx->pc = 0x109F30u;
            goto label_109f30;
        }
    }
    ctx->pc = 0x109F14u;
    // 0x109f14: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x109f14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x109f18: 0x26270018  addiu       $a3, $s1, 0x18
    ctx->pc = 0x109f18u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 24));
    // 0x109f1c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x109f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x109f20: 0x26450018  addiu       $a1, $s2, 0x18
    ctx->pc = 0x109f20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), 24));
    // 0x109f24: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x109f24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x109f28: 0xae420014  sw          $v0, 0x14($s2)
    ctx->pc = 0x109f28u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x109f2c: 0x0  nop
    ctx->pc = 0x109f2cu;
    // NOP
label_109f30:
    // 0x109f30: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x109f30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x109f34: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x109f34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x109f38: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x109f38u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x109f3c: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x109f3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x109f40: 0x8ce20000  lw          $v0, 0x0($a3)
    ctx->pc = 0x109f40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x109f44: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x109f44u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x109f48: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x109f48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x109f4c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x109F4Cu;
    {
        const bool branch_taken_0x109f4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109F4Cu;
            // 0x109f50: 0xaca30004  sw          $v1, 0x4($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109f4c) {
            ctx->pc = 0x109F60u;
            goto label_109f60;
        }
    }
    ctx->pc = 0x109F54u;
    // 0x109f54: 0x0  nop
    ctx->pc = 0x109f54u;
    // NOP
label_109f58:
    // 0x109f58: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x109F58u;
    SET_GPR_U32(ctx, 31, 0x109F60u);
    ctx->pc = 0x109F5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109F58u;
            // 0x109f5c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109F60u; }
        if (ctx->pc != 0x109F60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109F60u; }
        if (ctx->pc != 0x109F60u) { return; }
    }
    ctx->pc = 0x109F60u;
label_109f60:
    // 0x109f60: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x109f60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109f64: 0xc041636  jal         func_1058D8
    ctx->pc = 0x109F64u;
    SET_GPR_U32(ctx, 31, 0x109F6Cu);
    ctx->pc = 0x109F68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109F64u;
            // 0x109f68: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109F6Cu; }
        if (ctx->pc != 0x109F6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109F6Cu; }
        if (ctx->pc != 0x109F6Cu) { return; }
    }
    ctx->pc = 0x109F6Cu;
label_109f6c:
    // 0x109f6c: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x109F6Cu;
    {
        const bool branch_taken_0x109f6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109F6Cu;
            // 0x109f70: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109f6c) {
            ctx->pc = 0x109FDCu;
            goto label_109fdc;
        }
    }
    ctx->pc = 0x109F74u;
    // 0x109f74: 0x0  nop
    ctx->pc = 0x109f74u;
    // NOP
label_109f78:
    // 0x109f78: 0x2f62023  subu        $a0, $s7, $s6
    ctx->pc = 0x109f78u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 23), GPR_U32(ctx, 22)));
    // 0x109f7c: 0x2c820010  sltiu       $v0, $a0, 0x10
    ctx->pc = 0x109f7cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x109f80: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x109F80u;
    {
        const bool branch_taken_0x109f80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109F80u;
            // 0x109f84: 0x30a20001  andi        $v0, $a1, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x109f80) {
            ctx->pc = 0x109FC0u;
            goto label_109fc0;
        }
    }
    ctx->pc = 0x109F88u;
    // 0x109f88: 0x2162821  addu        $a1, $s0, $s6
    ctx->pc = 0x109f88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 22)));
    // 0x109f8c: 0x561025  or          $v0, $v0, $s6
    ctx->pc = 0x109f8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 22));
    // 0x109f90: 0x34830001  ori         $v1, $a0, 0x1
    ctx->pc = 0x109f90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1);
    // 0x109f94: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x109f94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x109f98: 0xa43021  addu        $a2, $a1, $a0
    ctx->pc = 0x109f98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x109f9c: 0xaca30004  sw          $v1, 0x4($a1)
    ctx->pc = 0x109f9cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x109fa0: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x109fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x109fa4: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x109fa4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109fa8: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x109fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x109fac: 0x34420001  ori         $v0, $v0, 0x1
    ctx->pc = 0x109facu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
    // 0x109fb0: 0xc041636  jal         func_1058D8
    ctx->pc = 0x109FB0u;
    SET_GPR_U32(ctx, 31, 0x109FB8u);
    ctx->pc = 0x109FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x109FB0u;
            // 0x109fb4: 0xacc20004  sw          $v0, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109FB8u; }
        if (ctx->pc != 0x109FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109FB8u; }
        if (ctx->pc != 0x109FB8u) { return; }
    }
    ctx->pc = 0x109FB8u;
label_109fb8:
    // 0x109fb8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x109FB8u;
    {
        const bool branch_taken_0x109fb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109FB8u;
            // 0x109fbc: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109fb8) {
            ctx->pc = 0x109FDCu;
            goto label_109fdc;
        }
    }
    ctx->pc = 0x109FC0u;
label_109fc0:
    // 0x109fc0: 0x2172021  addu        $a0, $s0, $s7
    ctx->pc = 0x109fc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 23)));
    // 0x109fc4: 0x571025  or          $v0, $v0, $s7
    ctx->pc = 0x109fc4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 23));
    // 0x109fc8: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x109fc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x109fcc: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x109fccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x109fd0: 0x34630001  ori         $v1, $v1, 0x1
    ctx->pc = 0x109fd0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1);
    // 0x109fd4: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x109fd4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x109fd8: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x109fd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
label_109fdc:
    // 0x109fdc: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x109FDCu;
    SET_GPR_U32(ctx, 31, 0x109FE4u);
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109FE4u; }
        if (ctx->pc != 0x109FE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x109FE4u; }
        if (ctx->pc != 0x109FE4u) { return; }
    }
    ctx->pc = 0x109FE4u;
label_109fe4:
    // 0x109fe4: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x109fe4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_109fe8:
    // 0x109fe8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x109fe8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x109fec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x109fecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x109ff0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x109ff0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x109ff4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x109ff4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x109ff8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x109ff8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x109ffc: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x109ffcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x10a000: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x10a000u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10a004: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x10a004u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10a008: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x10a008u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x10a00c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x10a00cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x10a010: 0x3e00008  jr          $ra
    ctx->pc = 0x10A010u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A014u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A010u;
            // 0x10a014: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x109AE8u: goto label_109ae8;
            case 0x109AF0u: goto label_109af0;
            case 0x109B20u: goto label_109b20;
            case 0x109B24u: goto label_109b24;
            case 0x109B70u: goto label_109b70;
            case 0x109B78u: goto label_109b78;
            case 0x109BC0u: goto label_109bc0;
            case 0x109BC8u: goto label_109bc8;
            case 0x109BF8u: goto label_109bf8;
            case 0x109C00u: goto label_109c00;
            case 0x109CD8u: goto label_109cd8;
            case 0x109D00u: goto label_109d00;
            case 0x109D0Cu: goto label_109d0c;
            case 0x109D40u: goto label_109d40;
            case 0x109D78u: goto label_109d78;
            case 0x109DA0u: goto label_109da0;
            case 0x109E20u: goto label_109e20;
            case 0x109E48u: goto label_109e48;
            case 0x109E50u: goto label_109e50;
            case 0x109E58u: goto label_109e58;
            case 0x109E5Cu: goto label_109e5c;
            case 0x109E64u: goto label_109e64;
            case 0x109E78u: goto label_109e78;
            case 0x109E80u: goto label_109e80;
            case 0x109EB8u: goto label_109eb8;
            case 0x109F30u: goto label_109f30;
            case 0x109F58u: goto label_109f58;
            case 0x109F60u: goto label_109f60;
            case 0x109F6Cu: goto label_109f6c;
            case 0x109F78u: goto label_109f78;
            case 0x109FB8u: goto label_109fb8;
            case 0x109FC0u: goto label_109fc0;
            case 0x109FDCu: goto label_109fdc;
            case 0x109FE4u: goto label_109fe4;
            case 0x109FE8u: goto label_109fe8;
            case 0x10A040u: goto label_10a040;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A018u;
    // 0x10a018: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10a018u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10a01c: 0x24030009  addiu       $v1, $zero, 0x9
    ctx->pc = 0x10a01cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x10a020: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10a020u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10a024: 0x9482000c  lhu         $v0, 0xC($a0)
    ctx->pc = 0x10a024u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x10a028: 0x30420009  andi        $v0, $v0, 0x9
    ctx->pc = 0x10a028u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)9);
    // 0x10a02c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x10A02Cu;
    {
        const bool branch_taken_0x10a02c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x10A030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A02Cu;
            // 0x10a030: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a02c) {
            ctx->pc = 0x10A040u;
            goto label_10a040;
        }
    }
    ctx->pc = 0x10A034u;
    // 0x10a034: 0x804142c  j           func_1050B0
    ctx->pc = 0x10A034u;
    ctx->pc = 0x10A038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10A034u;
            // 0x10a038: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001050B0_0x1050b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x10A03Cu;
    // 0x10a03c: 0x0  nop
    ctx->pc = 0x10a03cu;
    // NOP
label_10a040:
    // 0x10a040: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a040u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a044: 0x3e00008  jr          $ra
    ctx->pc = 0x10A044u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A044u;
            // 0x10a048: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x109AE8u: goto label_109ae8;
            case 0x109AF0u: goto label_109af0;
            case 0x109B20u: goto label_109b20;
            case 0x109B24u: goto label_109b24;
            case 0x109B70u: goto label_109b70;
            case 0x109B78u: goto label_109b78;
            case 0x109BC0u: goto label_109bc0;
            case 0x109BC8u: goto label_109bc8;
            case 0x109BF8u: goto label_109bf8;
            case 0x109C00u: goto label_109c00;
            case 0x109CD8u: goto label_109cd8;
            case 0x109D00u: goto label_109d00;
            case 0x109D0Cu: goto label_109d0c;
            case 0x109D40u: goto label_109d40;
            case 0x109D78u: goto label_109d78;
            case 0x109DA0u: goto label_109da0;
            case 0x109E20u: goto label_109e20;
            case 0x109E48u: goto label_109e48;
            case 0x109E50u: goto label_109e50;
            case 0x109E58u: goto label_109e58;
            case 0x109E5Cu: goto label_109e5c;
            case 0x109E64u: goto label_109e64;
            case 0x109E78u: goto label_109e78;
            case 0x109E80u: goto label_109e80;
            case 0x109EB8u: goto label_109eb8;
            case 0x109F30u: goto label_109f30;
            case 0x109F58u: goto label_109f58;
            case 0x109F60u: goto label_109f60;
            case 0x109F6Cu: goto label_109f6c;
            case 0x109F78u: goto label_109f78;
            case 0x109FB8u: goto label_109fb8;
            case 0x109FC0u: goto label_109fc0;
            case 0x109FDCu: goto label_109fdc;
            case 0x109FE4u: goto label_109fe4;
            case 0x109FE8u: goto label_109fe8;
            case 0x10A040u: goto label_10a040;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A04Cu;
    // 0x10a04c: 0x0  nop
    ctx->pc = 0x10a04cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
