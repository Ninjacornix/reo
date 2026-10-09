#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CB10
// Address: 0x17cb10 - 0x17ce10
void sub_0017CB10_0x17cb10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CB10_0x17cb10");
#endif

    switch (ctx->pc) {
        case 0x17cb50u: goto label_17cb50;
        case 0x17cc58u: goto label_17cc58;
        case 0x17cc94u: goto label_17cc94;
        case 0x17ccc8u: goto label_17ccc8;
        case 0x17cd88u: goto label_17cd88;
        case 0x17cdf0u: goto label_17cdf0;
        default: break;
    }

    ctx->pc = 0x17cb10u;

    // 0x17cb10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17cb10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17cb14: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17cb14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17cb18: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17cb18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cb1c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17cb1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17cb20: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x17cb20u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cb24: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17cb24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17cb28: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x17cb28u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cb2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17cb2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17cb30: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x17cb30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cb34: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17cb34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17cb38: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x17cb38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17cb3c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17CB3Cu;
    {
        const bool branch_taken_0x17cb3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17CB40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CB3Cu;
            // 0x17cb40: 0x8e500000  lw          $s0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cb3c) {
            ctx->pc = 0x17CB54u;
            goto label_17cb54;
        }
    }
    ctx->pc = 0x17CB44u;
    // 0x17cb44: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17cb44u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17cb48: 0xc05f386  jal         func_17CE18
    ctx->pc = 0x17CB48u;
    SET_GPR_U32(ctx, 31, 0x17CB50u);
    ctx->pc = 0x17CB4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CB48u;
            // 0x17cb4c: 0x24a50e30  addiu       $a1, $a1, 0xE30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CE18u;
    if (runtime->hasFunction(0x17CE18u)) {
        auto targetFn = runtime->lookupFunction(0x17CE18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CB50u; }
        if (ctx->pc != 0x17CB50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CE18_0x17ce18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CB50u; }
        if (ctx->pc != 0x17CB50u) { return; }
    }
    ctx->pc = 0x17CB50u;
label_17cb50:
    // 0x17cb50: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x17cb50u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
label_17cb54:
    // 0x17cb54: 0x12000012  beqz        $s0, . + 4 + (0x12 << 2)
    ctx->pc = 0x17CB54u;
    {
        const bool branch_taken_0x17cb54 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CB54u;
            // 0x17cb58: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cb54) {
            ctx->pc = 0x17CBA0u;
            goto label_17cba0;
        }
    }
    ctx->pc = 0x17CB5Cu;
    // 0x17cb5c: 0x2e020003  sltiu       $v0, $s0, 0x3
    ctx->pc = 0x17cb5cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x17cb60: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x17CB60u;
    {
        const bool branch_taken_0x17cb60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17cb60) {
            ctx->pc = 0x17CB64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17CB60u;
            // 0x17cb64: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17CBA4u;
            goto label_17cba4;
        }
    }
    ctx->pc = 0x17CB68u;
    // 0x17cb68: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x17cb68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x17cb6c: 0x5602000d  bnel        $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x17CB6Cu;
    {
        const bool branch_taken_0x17cb6c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x17cb6c) {
            ctx->pc = 0x17CB70u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17CB6Cu;
            // 0x17cb70: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17CBA4u;
            goto label_17cba4;
        }
    }
    ctx->pc = 0x17CB74u;
    // 0x17cb74: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17cb74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cb78: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17cb78u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cb7c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17cb7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cb80: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17cb80u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17cb84: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x17cb84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cb88: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17cb88u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17cb8c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cb8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cb90: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17cb90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17cb94: 0x805f2f2  j           func_17CBC8
    ctx->pc = 0x17CB94u;
    ctx->pc = 0x17CB98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CB94u;
            // 0x17cb98: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CBC8u;
    goto label_17cbc8;
    ctx->pc = 0x17CB9Cu;
    // 0x17cb9c: 0x0  nop
    ctx->pc = 0x17cb9cu;
    // NOP
label_17cba0:
    // 0x17cba0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17cba0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_17cba4:
    // 0x17cba4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17cba4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cba8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17cba8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17cbac: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17cbacu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17cbb0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cbb0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cbb4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17cbb4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17cbb8: 0x24c61328  addiu       $a2, $a2, 0x1328
    ctx->pc = 0x17cbb8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4904));
    // 0x17cbbc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17cbbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17cbc0: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17CBC0u;
    ctx->pc = 0x17CBC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CBC0u;
            // 0x17cbc4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17CBC8u;
label_17cbc8:
    // 0x17cbc8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17cbc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17cbcc: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17cbccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17cbd0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17cbd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17cbd4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17cbd4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cbd8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17cbd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17cbdc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17cbdcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cbe0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17cbe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17cbe4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17cbe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17cbe8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x17cbe8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17cbec: 0x10620040  beq         $v1, $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x17CBECu;
    {
        const bool branch_taken_0x17cbec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17CBF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CBECu;
            // 0x17cbf0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cbec) {
            ctx->pc = 0x17CCF0u;
            goto label_17ccf0;
        }
    }
    ctx->pc = 0x17CBF4u;
    // 0x17cbf4: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17cbf4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17cbf8: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x17CBF8u;
    {
        const bool branch_taken_0x17cbf8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CBFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CBF8u;
            // 0x17cbfc: 0x24020101  addiu       $v0, $zero, 0x101 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cbf8) {
            ctx->pc = 0x17CC28u;
            goto label_17cc28;
        }
    }
    ctx->pc = 0x17CC00u;
    // 0x17cc00: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17cc00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17cc04: 0x1062003a  beq         $v1, $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x17CC04u;
    {
        const bool branch_taken_0x17cc04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17CC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC04u;
            // 0x17cc08: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc04) {
            ctx->pc = 0x17CCF0u;
            goto label_17ccf0;
        }
    }
    ctx->pc = 0x17CC0Cu;
    // 0x17cc0c: 0x50400039  beql        $v0, $zero, . + 4 + (0x39 << 2)
    ctx->pc = 0x17CC0Cu;
    {
        const bool branch_taken_0x17cc0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17cc0c) {
            ctx->pc = 0x17CC10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC0Cu;
            // 0x17cc10: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17CCF4u;
            goto label_17ccf4;
        }
    }
    ctx->pc = 0x17CC14u;
    // 0x17cc14: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17cc14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17cc18: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x17CC18u;
    {
        const bool branch_taken_0x17cc18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17cc18) {
            ctx->pc = 0x17CC50u;
            goto label_17cc50;
        }
    }
    ctx->pc = 0x17CC20u;
    // 0x17cc20: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x17CC20u;
    {
        const bool branch_taken_0x17cc20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CC24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC20u;
            // 0x17cc24: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc20) {
            ctx->pc = 0x17CCF4u;
            goto label_17ccf4;
        }
    }
    ctx->pc = 0x17CC28u;
label_17cc28:
    // 0x17cc28: 0x10620031  beq         $v1, $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x17CC28u;
    {
        const bool branch_taken_0x17cc28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17CC2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC28u;
            // 0x17cc2c: 0x28620102  slti        $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)258) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc28) {
            ctx->pc = 0x17CCF0u;
            goto label_17ccf0;
        }
    }
    ctx->pc = 0x17CC30u;
    // 0x17cc30: 0x54400030  bnel        $v0, $zero, . + 4 + (0x30 << 2)
    ctx->pc = 0x17CC30u;
    {
        const bool branch_taken_0x17cc30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17cc30) {
            ctx->pc = 0x17CC34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC30u;
            // 0x17cc34: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17CCF4u;
            goto label_17ccf4;
        }
    }
    ctx->pc = 0x17CC38u;
    // 0x17cc38: 0x24021001  addiu       $v0, $zero, 0x1001
    ctx->pc = 0x17cc38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4097));
    // 0x17cc3c: 0x10620020  beq         $v1, $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x17CC3Cu;
    {
        const bool branch_taken_0x17cc3c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17cc3c) {
            ctx->pc = 0x17CCC0u;
            goto label_17ccc0;
        }
    }
    ctx->pc = 0x17CC44u;
    // 0x17cc44: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x17CC44u;
    {
        const bool branch_taken_0x17cc44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CC48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC44u;
            // 0x17cc48: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc44) {
            ctx->pc = 0x17CCF4u;
            goto label_17ccf4;
        }
    }
    ctx->pc = 0x17CC4Cu;
    // 0x17cc4c: 0x0  nop
    ctx->pc = 0x17cc4cu;
    // NOP
label_17cc50:
    // 0x17cc50: 0xc05f51a  jal         func_17D468
    ctx->pc = 0x17CC50u;
    SET_GPR_U32(ctx, 31, 0x17CC58u);
    ctx->pc = 0x17D468u;
    if (runtime->hasFunction(0x17D468u)) {
        auto targetFn = runtime->lookupFunction(0x17D468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CC58u; }
        if (ctx->pc != 0x17CC58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D468_0x17d468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CC58u; }
        if (ctx->pc != 0x17CC58u) { return; }
    }
    ctx->pc = 0x17CC58u;
label_17cc58:
    // 0x17cc58: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17cc58u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cc5c: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17CC5Cu;
    {
        const bool branch_taken_0x17cc5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17CC60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC5Cu;
            // 0x17cc60: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cc5c) {
            ctx->pc = 0x17CC88u;
            goto label_17cc88;
        }
    }
    ctx->pc = 0x17CC64u;
    // 0x17cc64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cc64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cc68: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17cc68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17cc6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cc70: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17cc70u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc74: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17cc74u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17cc78: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17cc78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17cc7c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17cc7cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc80: 0x805f346  j           func_17CD18
    ctx->pc = 0x17CC80u;
    ctx->pc = 0x17CC84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC80u;
            // 0x17cc84: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CD18u;
    goto label_17cd18;
    ctx->pc = 0x17CC88u;
label_17cc88:
    // 0x17cc88: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17cc88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc8c: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17CC8Cu;
    SET_GPR_U32(ctx, 31, 0x17CC94u);
    ctx->pc = 0x17CC90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CC8Cu;
            // 0x17cc90: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CC94u; }
        if (ctx->pc != 0x17CC94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CC94u; }
        if (ctx->pc != 0x17CC94u) { return; }
    }
    ctx->pc = 0x17CC94u;
label_17cc94:
    // 0x17cc94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17cc94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc98: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17cc98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cc9c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17cc9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cca0: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17cca0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cca4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17cca4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17cca8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17cca8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ccac: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17ccacu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17ccb0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ccb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ccb4: 0x805f346  j           func_17CD18
    ctx->pc = 0x17CCB4u;
    ctx->pc = 0x17CCB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CCB4u;
            // 0x17ccb8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CD18u;
    goto label_17cd18;
    ctx->pc = 0x17CCBCu;
    // 0x17ccbc: 0x0  nop
    ctx->pc = 0x17ccbcu;
    // NOP
label_17ccc0:
    // 0x17ccc0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17CCC0u;
    SET_GPR_U32(ctx, 31, 0x17CCC8u);
    ctx->pc = 0x17CCC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CCC0u;
            // 0x17ccc4: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CCC8u; }
        if (ctx->pc != 0x17CCC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CCC8u; }
        if (ctx->pc != 0x17CCC8u) { return; }
    }
    ctx->pc = 0x17CCC8u;
label_17ccc8:
    // 0x17ccc8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ccc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cccc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ccccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ccd0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ccd0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ccd4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17ccd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ccd8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17ccd8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ccdc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ccdcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17cce0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17cce0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cce4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17cce4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17cce8: 0x805f346  j           func_17CD18
    ctx->pc = 0x17CCE8u;
    ctx->pc = 0x17CCECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CCE8u;
            // 0x17ccec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CD18u;
    goto label_17cd18;
    ctx->pc = 0x17CCF0u;
label_17ccf0:
    // 0x17ccf0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ccf0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_17ccf4:
    // 0x17ccf4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ccf4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ccf8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ccf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ccfc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ccfcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17cd00: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17cd00u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17cd04: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17cd04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17cd08: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17cd08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17cd0c: 0x24c61360  addiu       $a2, $a2, 0x1360
    ctx->pc = 0x17cd0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4960));
    // 0x17cd10: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17CD10u;
    ctx->pc = 0x17CD14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CD10u;
            // 0x17cd14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17CD18u;
label_17cd18:
    // 0x17cd18: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x17cd18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x17cd1c: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17cd1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17cd20: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17cd20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd24: 0xffb10048  sd          $s1, 0x48($sp)
    ctx->pc = 0x17cd24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 17));
    // 0x17cd28: 0x26110004  addiu       $s1, $s0, 0x4
    ctx->pc = 0x17cd28u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17cd2c: 0xffb20050  sd          $s2, 0x50($sp)
    ctx->pc = 0x17cd2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x17cd30: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17cd30u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd34: 0xffb30058  sd          $s3, 0x58($sp)
    ctx->pc = 0x17cd34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 19));
    // 0x17cd38: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x17cd38u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd3c: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x17cd3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x17cd40: 0x26020014  addiu       $v0, $s0, 0x14
    ctx->pc = 0x17cd40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x17cd44: 0xafa60020  sw          $a2, 0x20($sp)
    ctx->pc = 0x17cd44u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 6));
    // 0x17cd48: 0x26030024  addiu       $v1, $s0, 0x24
    ctx->pc = 0x17cd48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 36));
    // 0x17cd4c: 0x8c690004  lw          $t1, 0x4($v1)
    ctx->pc = 0x17cd4cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x17cd50: 0x8c480004  lw          $t0, 0x4($v0)
    ctx->pc = 0x17cd50u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17cd54: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x17cd54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17cd58: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x17cd58u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x17cd5c: 0x8e270000  lw          $a3, 0x0($s1)
    ctx->pc = 0x17cd5cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17cd60: 0x8e030044  lw          $v1, 0x44($s0)
    ctx->pc = 0x17cd60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17cd64: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x17cd64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17cd68: 0xafa70000  sw          $a3, 0x0($sp)
    ctx->pc = 0x17cd68u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 7));
    // 0x17cd6c: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x17cd6cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x17cd70: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x17cd70u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x17cd74: 0xafa90014  sw          $t1, 0x14($sp)
    ctx->pc = 0x17cd74u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 9));
    // 0x17cd78: 0xafa30024  sw          $v1, 0x24($sp)
    ctx->pc = 0x17cd78u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 3));
    // 0x17cd7c: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x17cd7cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
    // 0x17cd80: 0xc05eb6a  jal         func_17ADA8
    ctx->pc = 0x17CD80u;
    SET_GPR_U32(ctx, 31, 0x17CD88u);
    ctx->pc = 0x17CD84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CD80u;
            // 0x17cd84: 0xafa80010  sw          $t0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17ADA8u;
    if (runtime->hasFunction(0x17ADA8u)) {
        auto targetFn = runtime->lookupFunction(0x17ADA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CD88u; }
        if (ctx->pc != 0x17CD88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017ADA8_0x17ada8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CD88u; }
        if (ctx->pc != 0x17CD88u) { return; }
    }
    ctx->pc = 0x17CD88u;
label_17cd88:
    // 0x17cd88: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17cd88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17cd8c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x17cd8cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd90: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x17cd90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd94: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17cd94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17cd98: 0x27a70020  addiu       $a3, $sp, 0x20
    ctx->pc = 0x17cd98u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x17cd9c: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x17CD9Cu;
    {
        const bool branch_taken_0x17cd9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17CDA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CD9Cu;
            // 0x17cda0: 0x24090001  addiu       $t1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cd9c) {
            ctx->pc = 0x17CDB8u;
            goto label_17cdb8;
        }
    }
    ctx->pc = 0x17CDA4u;
    // 0x17cda4: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17cda4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17cda8: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17cda8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17cdac: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17cdacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17cdb0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x17CDB0u;
    {
        const bool branch_taken_0x17cdb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17CDB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CDB0u;
            // 0x17cdb4: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cdb0) {
            ctx->pc = 0x17CDBCu;
            goto label_17cdbc;
        }
    }
    ctx->pc = 0x17CDB8u;
label_17cdb8:
    // 0x17cdb8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17cdb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
label_17cdbc:
    // 0x17cdbc: 0xafa20028  sw          $v0, 0x28($sp)
    ctx->pc = 0x17cdbcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x17cdc0: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x17cdc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17cdc4: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x17CDC4u;
    {
        const bool branch_taken_0x17cdc4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17cdc4) {
            ctx->pc = 0x17CDC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17CDC4u;
            // 0x17cdc8: 0xafa2002c  sw          $v0, 0x2C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17CDDCu;
            goto label_17cddc;
        }
    }
    ctx->pc = 0x17CDCCu;
    // 0x17cdcc: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x17cdccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17cdd0: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x17cdd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x17cdd4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17cdd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17cdd8: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x17cdd8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
label_17cddc:
    // 0x17cddc: 0x16690002  bne         $s3, $t1, . + 4 + (0x2 << 2)
    ctx->pc = 0x17CDDCu;
    {
        const bool branch_taken_0x17cddc = (GPR_U64(ctx, 19) != GPR_U64(ctx, 9));
        ctx->pc = 0x17CDE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CDDCu;
            // 0x17cde0: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17cddc) {
            ctx->pc = 0x17CDE8u;
            goto label_17cde8;
        }
    }
    ctx->pc = 0x17CDE4u;
    // 0x17cde4: 0x8e48003c  lw          $t0, 0x3C($s2)
    ctx->pc = 0x17cde4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
label_17cde8:
    // 0x17cde8: 0xc05f384  jal         func_17CE10
    ctx->pc = 0x17CDE8u;
    SET_GPR_U32(ctx, 31, 0x17CDF0u);
    ctx->pc = 0x17CE10u;
    if (runtime->hasFunction(0x17CE10u)) {
        auto targetFn = runtime->lookupFunction(0x17CE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CDF0u; }
        if (ctx->pc != 0x17CDF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CE10_0x17ce10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17CDF0u; }
        if (ctx->pc != 0x17CDF0u) { return; }
    }
    ctx->pc = 0x17CDF0u;
label_17cdf0:
    // 0x17cdf0: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17cdf0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17cdf4: 0xdfb10048  ld          $s1, 0x48($sp)
    ctx->pc = 0x17cdf4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17cdf8: 0xdfb20050  ld          $s2, 0x50($sp)
    ctx->pc = 0x17cdf8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17cdfc: 0xdfb30058  ld          $s3, 0x58($sp)
    ctx->pc = 0x17cdfcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x17ce00: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x17ce00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x17ce04: 0x3e00008  jr          $ra
    ctx->pc = 0x17CE04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CE04u;
            // 0x17ce08: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17CB50u: goto label_17cb50;
            case 0x17CB54u: goto label_17cb54;
            case 0x17CBA0u: goto label_17cba0;
            case 0x17CBA4u: goto label_17cba4;
            case 0x17CBC8u: goto label_17cbc8;
            case 0x17CC28u: goto label_17cc28;
            case 0x17CC50u: goto label_17cc50;
            case 0x17CC58u: goto label_17cc58;
            case 0x17CC88u: goto label_17cc88;
            case 0x17CC94u: goto label_17cc94;
            case 0x17CCC0u: goto label_17ccc0;
            case 0x17CCC8u: goto label_17ccc8;
            case 0x17CCF0u: goto label_17ccf0;
            case 0x17CCF4u: goto label_17ccf4;
            case 0x17CD18u: goto label_17cd18;
            case 0x17CD88u: goto label_17cd88;
            case 0x17CDB8u: goto label_17cdb8;
            case 0x17CDBCu: goto label_17cdbc;
            case 0x17CDDCu: goto label_17cddc;
            case 0x17CDE8u: goto label_17cde8;
            case 0x17CDF0u: goto label_17cdf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17CE0Cu;
    // 0x17ce0c: 0x0  nop
    ctx->pc = 0x17ce0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
