#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A918
// Address: 0x17a918 - 0x17ac68
void sub_0017A918_0x17a918(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A918_0x17a918");
#endif

    switch (ctx->pc) {
        case 0x17a958u: goto label_17a958;
        case 0x17aae0u: goto label_17aae0;
        case 0x17ab1cu: goto label_17ab1c;
        case 0x17ab88u: goto label_17ab88;
        case 0x17abb8u: goto label_17abb8;
        case 0x17abe8u: goto label_17abe8;
        case 0x17ac18u: goto label_17ac18;
        default: break;
    }

    ctx->pc = 0x17a918u;

    // 0x17a918: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17a918u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17a91c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a91cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a920: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x17a920u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a924: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a928: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x17a928u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a92c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17a92cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17a930: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x17a930u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a934: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a938: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17a938u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17a93c: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x17a93cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17a940: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17A940u;
    {
        const bool branch_taken_0x17a940 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x17A944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A940u;
            // 0x17a944: 0x8e500000  lw          $s0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a940) {
            ctx->pc = 0x17A95Cu;
            goto label_17a95c;
        }
    }
    ctx->pc = 0x17A948u;
    // 0x17a948: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x17a948u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x17a94c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x17a94cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a950: 0xc05f386  jal         func_17CE18
    ctx->pc = 0x17A950u;
    SET_GPR_U32(ctx, 31, 0x17A958u);
    ctx->pc = 0x17A954u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A950u;
            // 0x17a954: 0x24a50e30  addiu       $a1, $a1, 0xE30 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17CE18u;
    if (runtime->hasFunction(0x17CE18u)) {
        auto targetFn = runtime->lookupFunction(0x17CE18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A958u; }
        if (ctx->pc != 0x17A958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017CE18_0x17ce18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A958u; }
        if (ctx->pc != 0x17A958u) { return; }
    }
    ctx->pc = 0x17A958u;
label_17a958:
    // 0x17a958: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x17a958u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
label_17a95c:
    // 0x17a95c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x17a95cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x17a960: 0x1202001f  beq         $s0, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x17A960u;
    {
        const bool branch_taken_0x17a960 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x17A964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A960u;
            // 0x17a964: 0x2e020003  sltiu       $v0, $s0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a960) {
            ctx->pc = 0x17A9E0u;
            goto label_17a9e0;
        }
    }
    ctx->pc = 0x17A968u;
    // 0x17a968: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17A968u;
    {
        const bool branch_taken_0x17a968 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A968u;
            // 0x17a96c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a968) {
            ctx->pc = 0x17A988u;
            goto label_17a988;
        }
    }
    ctx->pc = 0x17A970u;
    // 0x17a970: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a974: 0x12020010  beq         $s0, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x17A974u;
    {
        const bool branch_taken_0x17a974 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x17A978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A974u;
            // 0x17a978: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a974) {
            ctx->pc = 0x17A9B8u;
            goto label_17a9b8;
        }
    }
    ctx->pc = 0x17A97Cu;
    // 0x17a97c: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x17A97Cu;
    {
        const bool branch_taken_0x17a97c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A97Cu;
            // 0x17a980: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a97c) {
            ctx->pc = 0x17AA0Cu;
            goto label_17aa0c;
        }
    }
    ctx->pc = 0x17A984u;
    // 0x17a984: 0x0  nop
    ctx->pc = 0x17a984u;
    // NOP
label_17a988:
    // 0x17a988: 0x1602001f  bne         $s0, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x17A988u;
    {
        const bool branch_taken_0x17a988 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x17A98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A988u;
            // 0x17a98c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a988) {
            ctx->pc = 0x17AA08u;
            goto label_17aa08;
        }
    }
    ctx->pc = 0x17A990u;
    // 0x17a990: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a990u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a994: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17a994u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a998: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a998u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a99c: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x17a99cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a9a0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17a9a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a9a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a9a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a9a8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17a9a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17a9ac: 0x805ea8c  j           func_17AA30
    ctx->pc = 0x17A9ACu;
    ctx->pc = 0x17A9B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A9ACu;
            // 0x17a9b0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AA30u;
    goto label_17aa30;
    ctx->pc = 0x17A9B4u;
    // 0x17a9b4: 0x0  nop
    ctx->pc = 0x17a9b4u;
    // NOP
label_17a9b8:
    // 0x17a9b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a9b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a9bc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17a9bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a9c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a9c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a9c4: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x17a9c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a9c8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17a9c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a9cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a9ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a9d0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17a9d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17a9d4: 0x805ec26  j           func_17B098
    ctx->pc = 0x17A9D4u;
    ctx->pc = 0x17A9D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A9D4u;
            // 0x17a9d8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B098u;
    if (runtime->hasFunction(0x17B098u)) {
        auto targetFn = runtime->lookupFunction(0x17B098u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B098_0x17b098(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17A9DCu;
    // 0x17a9dc: 0x0  nop
    ctx->pc = 0x17a9dcu;
    // NOP
label_17a9e0:
    // 0x17a9e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17a9e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a9e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a9e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a9e8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17a9e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a9ec: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a9ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a9f0: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x17a9f0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a9f4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17a9f4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a9f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a9f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a9fc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17a9fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17aa00: 0x805ed18  j           func_17B460
    ctx->pc = 0x17AA00u;
    ctx->pc = 0x17AA04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AA00u;
            // 0x17aa04: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17B460u;
    if (runtime->hasFunction(0x17B460u)) {
        auto targetFn = runtime->lookupFunction(0x17B460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017B460_0x17b460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AA08u;
label_17aa08:
    // 0x17aa08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17aa08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_17aa0c:
    // 0x17aa0c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17aa0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17aa10: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17aa10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17aa14: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17aa14u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17aa18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17aa18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17aa1c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17aa1cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17aa20: 0x24c60e38  addiu       $a2, $a2, 0xE38
    ctx->pc = 0x17aa20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 3640));
    // 0x17aa24: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17aa24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17aa28: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17AA28u;
    ctx->pc = 0x17AA2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AA28u;
            // 0x17aa2c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AA30u;
label_17aa30:
    // 0x17aa30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17aa30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17aa34: 0x24020041  addiu       $v0, $zero, 0x41
    ctx->pc = 0x17aa34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 65));
    // 0x17aa38: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17aa38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17aa3c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17aa3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17aa40: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17aa40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17aa44: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17aa44u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17aa48: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17aa48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17aa4c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17aa4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17aa50: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x17aa50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x17aa54: 0x10620062  beq         $v1, $v0, . + 4 + (0x62 << 2)
    ctx->pc = 0x17AA54u;
    {
        const bool branch_taken_0x17aa54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17AA58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AA54u;
            // 0x17aa58: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aa54) {
            ctx->pc = 0x17ABE0u;
            goto label_17abe0;
        }
    }
    ctx->pc = 0x17AA5Cu;
    // 0x17aa5c: 0x28620042  slti        $v0, $v1, 0x42
    ctx->pc = 0x17aa5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)66) ? 1 : 0);
    // 0x17aa60: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x17AA60u;
    {
        const bool branch_taken_0x17aa60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AA64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AA60u;
            // 0x17aa64: 0x24020101  addiu       $v0, $zero, 0x101 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aa60) {
            ctx->pc = 0x17AAA0u;
            goto label_17aaa0;
        }
    }
    ctx->pc = 0x17AA68u;
    // 0x17aa68: 0x24020021  addiu       $v0, $zero, 0x21
    ctx->pc = 0x17aa68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x17aa6c: 0x10620044  beq         $v1, $v0, . + 4 + (0x44 << 2)
    ctx->pc = 0x17AA6Cu;
    {
        const bool branch_taken_0x17aa6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17AA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AA6Cu;
            // 0x17aa70: 0x28620022  slti        $v0, $v1, 0x22 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)34) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aa6c) {
            ctx->pc = 0x17AB80u;
            goto label_17ab80;
        }
    }
    ctx->pc = 0x17AA74u;
    // 0x17aa74: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17AA74u;
    {
        const bool branch_taken_0x17aa74 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AA78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AA74u;
            // 0x17aa78: 0x24020031  addiu       $v0, $zero, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 49));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aa74) {
            ctx->pc = 0x17AA90u;
            goto label_17aa90;
        }
    }
    ctx->pc = 0x17AA7Cu;
    // 0x17aa7c: 0x24020011  addiu       $v0, $zero, 0x11
    ctx->pc = 0x17aa7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x17aa80: 0x10620015  beq         $v1, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x17AA80u;
    {
        const bool branch_taken_0x17aa80 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17aa80) {
            ctx->pc = 0x17AAD8u;
            goto label_17aad8;
        }
    }
    ctx->pc = 0x17AA88u;
    // 0x17aa88: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x17AA88u;
    {
        const bool branch_taken_0x17aa88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AA8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AA88u;
            // 0x17aa8c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aa88) {
            ctx->pc = 0x17AC40u;
            goto label_17ac40;
        }
    }
    ctx->pc = 0x17AA90u;
label_17aa90:
    // 0x17aa90: 0x10620047  beq         $v1, $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x17AA90u;
    {
        const bool branch_taken_0x17aa90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17aa90) {
            ctx->pc = 0x17ABB0u;
            goto label_17abb0;
        }
    }
    ctx->pc = 0x17AA98u;
    // 0x17aa98: 0x10000069  b           . + 4 + (0x69 << 2)
    ctx->pc = 0x17AA98u;
    {
        const bool branch_taken_0x17aa98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AA9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AA98u;
            // 0x17aa9c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aa98) {
            ctx->pc = 0x17AC40u;
            goto label_17ac40;
        }
    }
    ctx->pc = 0x17AAA0u;
label_17aaa0:
    // 0x17aaa0: 0x10620029  beq         $v1, $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x17AAA0u;
    {
        const bool branch_taken_0x17aaa0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x17AAA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AAA0u;
            // 0x17aaa4: 0x28620102  slti        $v0, $v1, 0x102 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)258) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aaa0) {
            ctx->pc = 0x17AB48u;
            goto label_17ab48;
        }
    }
    ctx->pc = 0x17AAA8u;
    // 0x17aaa8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17AAA8u;
    {
        const bool branch_taken_0x17aaa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AAACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AAA8u;
            // 0x17aaac: 0x24021001  addiu       $v0, $zero, 0x1001 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4097));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aaa8) {
            ctx->pc = 0x17AAC8u;
            goto label_17aac8;
        }
    }
    ctx->pc = 0x17AAB0u;
    // 0x17aab0: 0x240200f1  addiu       $v0, $zero, 0xF1
    ctx->pc = 0x17aab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 241));
    // 0x17aab4: 0x5062002c  beql        $v1, $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x17AAB4u;
    {
        const bool branch_taken_0x17aab4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17aab4) {
            ctx->pc = 0x17AAB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17AAB4u;
            // 0x17aab8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17AB68u;
            goto label_17ab68;
        }
    }
    ctx->pc = 0x17AABCu;
    // 0x17aabc: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x17AABCu;
    {
        const bool branch_taken_0x17aabc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AAC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AABCu;
            // 0x17aac0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aabc) {
            ctx->pc = 0x17AC40u;
            goto label_17ac40;
        }
    }
    ctx->pc = 0x17AAC4u;
    // 0x17aac4: 0x0  nop
    ctx->pc = 0x17aac4u;
    // NOP
label_17aac8:
    // 0x17aac8: 0x10620051  beq         $v1, $v0, . + 4 + (0x51 << 2)
    ctx->pc = 0x17AAC8u;
    {
        const bool branch_taken_0x17aac8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x17aac8) {
            ctx->pc = 0x17AC10u;
            goto label_17ac10;
        }
    }
    ctx->pc = 0x17AAD0u;
    // 0x17aad0: 0x1000005b  b           . + 4 + (0x5B << 2)
    ctx->pc = 0x17AAD0u;
    {
        const bool branch_taken_0x17aad0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17AAD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AAD0u;
            // 0x17aad4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aad0) {
            ctx->pc = 0x17AC40u;
            goto label_17ac40;
        }
    }
    ctx->pc = 0x17AAD8u;
label_17aad8:
    // 0x17aad8: 0xc05f51a  jal         func_17D468
    ctx->pc = 0x17AAD8u;
    SET_GPR_U32(ctx, 31, 0x17AAE0u);
    ctx->pc = 0x17D468u;
    if (runtime->hasFunction(0x17D468u)) {
        auto targetFn = runtime->lookupFunction(0x17D468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AAE0u; }
        if (ctx->pc != 0x17AAE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D468_0x17d468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AAE0u; }
        if (ctx->pc != 0x17AAE0u) { return; }
    }
    ctx->pc = 0x17AAE0u;
label_17aae0:
    // 0x17aae0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17aae0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17aae4: 0x1043000a  beq         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x17AAE4u;
    {
        const bool branch_taken_0x17aae4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17AAE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17AAE4u;
            // 0x17aae8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17aae4) {
            ctx->pc = 0x17AB10u;
            goto label_17ab10;
        }
    }
    ctx->pc = 0x17AAECu;
    // 0x17aaec: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17aaecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17aaf0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17aaf0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17aaf4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17aaf4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17aaf8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17aaf8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17aafc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17aafcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ab00: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ab00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ab04: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17ab04u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab08: 0x805eb1a  j           func_17AC68
    ctx->pc = 0x17AB08u;
    ctx->pc = 0x17AB0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AB08u;
            // 0x17ab0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AC68u;
    if (runtime->hasFunction(0x17AC68u)) {
        auto targetFn = runtime->lookupFunction(0x17AC68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017AC68_0x17ac68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AB10u;
label_17ab10:
    // 0x17ab10: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ab10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab14: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17AB14u;
    SET_GPR_U32(ctx, 31, 0x17AB1Cu);
    ctx->pc = 0x17AB18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AB14u;
            // 0x17ab18: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AB1Cu; }
        if (ctx->pc != 0x17AB1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AB1Cu; }
        if (ctx->pc != 0x17AB1Cu) { return; }
    }
    ctx->pc = 0x17AB1Cu;
label_17ab1c:
    // 0x17ab1c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ab1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab20: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ab20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab24: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ab24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ab28: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17ab28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab2c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17ab2cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ab30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ab30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ab34: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17ab34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17ab38: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ab38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ab3c: 0x805eb1a  j           func_17AC68
    ctx->pc = 0x17AB3Cu;
    ctx->pc = 0x17AB40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AB3Cu;
            // 0x17ab40: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AC68u;
    if (runtime->hasFunction(0x17AC68u)) {
        auto targetFn = runtime->lookupFunction(0x17AC68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017AC68_0x17ac68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AB44u;
    // 0x17ab44: 0x0  nop
    ctx->pc = 0x17ab44u;
    // NOP
label_17ab48:
    // 0x17ab48: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ab48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ab4c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x17ab4cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab50: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ab50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ab54: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17ab54u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ab58: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ab58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ab5c: 0x805eb1a  j           func_17AC68
    ctx->pc = 0x17AB5Cu;
    ctx->pc = 0x17AB60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AB5Cu;
            // 0x17ab60: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AC68u;
    if (runtime->hasFunction(0x17AC68u)) {
        auto targetFn = runtime->lookupFunction(0x17AC68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017AC68_0x17ac68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AB64u;
    // 0x17ab64: 0x0  nop
    ctx->pc = 0x17ab64u;
    // NOP
label_17ab68:
    // 0x17ab68: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ab68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ab6c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17ab6cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ab70: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ab70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ab74: 0x805eb98  j           func_17AE60
    ctx->pc = 0x17AB74u;
    ctx->pc = 0x17AB78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AB74u;
            // 0x17ab78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AE60u;
    if (runtime->hasFunction(0x17AE60u)) {
        auto targetFn = runtime->lookupFunction(0x17AE60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017AE60_0x17ae60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AB7Cu;
    // 0x17ab7c: 0x0  nop
    ctx->pc = 0x17ab7cu;
    // NOP
label_17ab80:
    // 0x17ab80: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17AB80u;
    SET_GPR_U32(ctx, 31, 0x17AB88u);
    ctx->pc = 0x17AB84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AB80u;
            // 0x17ab84: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AB88u; }
        if (ctx->pc != 0x17AB88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AB88u; }
        if (ctx->pc != 0x17AB88u) { return; }
    }
    ctx->pc = 0x17AB88u;
label_17ab88:
    // 0x17ab88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ab88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab8c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ab8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab90: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ab90u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ab94: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17ab94u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ab98: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17ab98u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ab9c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ab9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17aba0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17aba0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17aba4: 0x805ebbe  j           func_17AEF8
    ctx->pc = 0x17ABA4u;
    ctx->pc = 0x17ABA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ABA4u;
            // 0x17aba8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AEF8u;
    if (runtime->hasFunction(0x17AEF8u)) {
        auto targetFn = runtime->lookupFunction(0x17AEF8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017AEF8_0x17aef8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17ABACu;
    // 0x17abac: 0x0  nop
    ctx->pc = 0x17abacu;
    // NOP
label_17abb0:
    // 0x17abb0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17ABB0u;
    SET_GPR_U32(ctx, 31, 0x17ABB8u);
    ctx->pc = 0x17ABB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ABB0u;
            // 0x17abb4: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17ABB8u; }
        if (ctx->pc != 0x17ABB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17ABB8u; }
        if (ctx->pc != 0x17ABB8u) { return; }
    }
    ctx->pc = 0x17ABB8u;
label_17abb8:
    // 0x17abb8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17abb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17abbc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17abbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17abc0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17abc0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17abc4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17abc4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17abc8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17abc8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17abcc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17abccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17abd0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17abd0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17abd4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17abd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17abd8: 0x805eb1a  j           func_17AC68
    ctx->pc = 0x17ABD8u;
    ctx->pc = 0x17ABDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ABD8u;
            // 0x17abdc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AC68u;
    if (runtime->hasFunction(0x17AC68u)) {
        auto targetFn = runtime->lookupFunction(0x17AC68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017AC68_0x17ac68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17ABE0u;
label_17abe0:
    // 0x17abe0: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17ABE0u;
    SET_GPR_U32(ctx, 31, 0x17ABE8u);
    ctx->pc = 0x17ABE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17ABE0u;
            // 0x17abe4: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17ABE8u; }
        if (ctx->pc != 0x17ABE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17ABE8u; }
        if (ctx->pc != 0x17ABE8u) { return; }
    }
    ctx->pc = 0x17ABE8u;
label_17abe8:
    // 0x17abe8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17abe8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17abec: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17abecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17abf0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17abf0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17abf4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17abf4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17abf8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17abf8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17abfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17abfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ac00: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17ac00u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17ac04: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ac04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ac08: 0x805eb1a  j           func_17AC68
    ctx->pc = 0x17AC08u;
    ctx->pc = 0x17AC0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AC08u;
            // 0x17ac0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AC68u;
    if (runtime->hasFunction(0x17AC68u)) {
        auto targetFn = runtime->lookupFunction(0x17AC68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017AC68_0x17ac68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AC10u;
label_17ac10:
    // 0x17ac10: 0xc05f164  jal         func_17C590
    ctx->pc = 0x17AC10u;
    SET_GPR_U32(ctx, 31, 0x17AC18u);
    ctx->pc = 0x17AC14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AC10u;
            // 0x17ac14: 0x24060015  addiu       $a2, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C590u;
    if (runtime->hasFunction(0x17C590u)) {
        auto targetFn = runtime->lookupFunction(0x17C590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AC18u; }
        if (ctx->pc != 0x17AC18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C590_0x17c590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17AC18u; }
        if (ctx->pc != 0x17AC18u) { return; }
    }
    ctx->pc = 0x17AC18u;
label_17ac18:
    // 0x17ac18: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17ac18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ac1c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ac1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ac20: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ac20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ac24: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17ac24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ac28: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17ac28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ac2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ac2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ac30: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x17ac30u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17ac34: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ac34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ac38: 0x805eb1a  j           func_17AC68
    ctx->pc = 0x17AC38u;
    ctx->pc = 0x17AC3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AC38u;
            // 0x17ac3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17AC68u;
    if (runtime->hasFunction(0x17AC68u)) {
        auto targetFn = runtime->lookupFunction(0x17AC68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017AC68_0x17ac68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AC40u;
label_17ac40:
    // 0x17ac40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17ac40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17ac44: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17ac44u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ac48: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ac48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ac4c: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17ac4cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17ac50: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17ac50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ac54: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17ac54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17ac58: 0x24c60e70  addiu       $a2, $a2, 0xE70
    ctx->pc = 0x17ac58u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 3696));
    // 0x17ac5c: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17AC5Cu;
    ctx->pc = 0x17AC60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17AC5Cu;
            // 0x17ac60: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17AC64u;
    // 0x17ac64: 0x0  nop
    ctx->pc = 0x17ac64u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
