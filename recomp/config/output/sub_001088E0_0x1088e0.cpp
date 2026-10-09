#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001088E0
// Address: 0x1088e0 - 0x1089b0
void sub_001088E0_0x1088e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001088E0_0x1088e0");
#endif

    ctx->pc = 0x1088e0u;

    // 0x1088e0: 0x3c027ff0  lui         $v0, 0x7FF0
    ctx->pc = 0x1088e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32752 << 16));
    // 0x1088e4: 0x4203f  dsra32      $a0, $a0, 0
    ctx->pc = 0x1088e4u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1088e8: 0x822024  and         $a0, $a0, $v0
    ctx->pc = 0x1088e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1088ec: 0x3c03fcc0  lui         $v1, 0xFCC0
    ctx->pc = 0x1088ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)64704 << 16));
    // 0x1088f0: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1088f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1088f4: 0x41023  negu        $v0, $a0
    ctx->pc = 0x1088f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x1088f8: 0x18800009  blez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1088F8u;
    {
        const bool branch_taken_0x1088f8 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x1088FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1088F8u;
            // 0x1088fc: 0x4303c  dsll32      $a2, $a0, 0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1088f8) {
            ctx->pc = 0x108920u;
            goto label_108920;
        }
    }
    ctx->pc = 0x108900u;
    // 0x108900: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x108900u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x108904: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x108904u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x108908: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x108908u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10890c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10890cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x108910: 0xa22824  and         $a1, $a1, $v0
    ctx->pc = 0x108910u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x108914: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x108914u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x108918: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x108918u;
    {
        const bool branch_taken_0x108918 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10891Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108918u;
            // 0x10891c: 0xa32824  and         $a1, $a1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108918) {
            ctx->pc = 0x1089A4u;
            goto label_1089a4;
        }
    }
    ctx->pc = 0x108920u;
label_108920:
    // 0x108920: 0x22503  sra         $a0, $v0, 20
    ctx->pc = 0x108920u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 2), 20));
    // 0x108924: 0x28820014  slti        $v0, $a0, 0x14
    ctx->pc = 0x108924u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x108928: 0x5040000d  beql        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x108928u;
    {
        const bool branch_taken_0x108928 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x108928) {
            ctx->pc = 0x10892Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108928u;
            // 0x10892c: 0x2484ffec  addiu       $a0, $a0, -0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967276));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108960u;
            goto label_108960;
        }
    }
    ctx->pc = 0x108930u;
    // 0x108930: 0x3c020008  lui         $v0, 0x8
    ctx->pc = 0x108930u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
    // 0x108934: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x108934u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x108938: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x108938u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x10893c: 0x821007  srav        $v0, $v0, $a0
    ctx->pc = 0x10893cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
    // 0x108940: 0xa32824  and         $a1, $a1, $v1
    ctx->pc = 0x108940u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x108944: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x108944u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x108948: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x108948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10894c: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x10894cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x108950: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x108950u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
    // 0x108954: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x108954u;
    {
        const bool branch_taken_0x108954 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108954u;
            // 0x108958: 0xa32824  and         $a1, $a1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108954) {
            ctx->pc = 0x1089A4u;
            goto label_1089a4;
        }
    }
    ctx->pc = 0x10895Cu;
    // 0x10895c: 0x0  nop
    ctx->pc = 0x10895cu;
    // NOP
label_108960:
    // 0x108960: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x108960u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x108964: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x108964u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x108968: 0x2882001f  slti        $v0, $a0, 0x1F
    ctx->pc = 0x108968u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x10896c: 0x43027  nor         $a2, $zero, $a0
    ctx->pc = 0x10896cu;
    SET_GPR_U64(ctx, 6, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 4)));
    // 0x108970: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x108970u;
    {
        const bool branch_taken_0x108970 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x108974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108970u;
            // 0x108974: 0xa32824  and         $a1, $a1, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108970) {
            ctx->pc = 0x108988u;
            goto label_108988;
        }
    }
    ctx->pc = 0x108978u;
    // 0x108978: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x108978u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10897c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10897Cu;
    {
        const bool branch_taken_0x10897c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10897Cu;
            // 0x108980: 0xc21004  sllv        $v0, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 6) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10897c) {
            ctx->pc = 0x10898Cu;
            goto label_10898c;
        }
    }
    ctx->pc = 0x108984u;
    // 0x108984: 0x0  nop
    ctx->pc = 0x108984u;
    // NOP
label_108988:
    // 0x108988: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x108988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_10898c:
    // 0x10898c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10898cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x108990: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x108990u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x108994: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x108994u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x108998: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x108998u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x10899c: 0xa32824  and         $a1, $a1, $v1
    ctx->pc = 0x10899cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x1089a0: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x1089a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
label_1089a4:
    // 0x1089a4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1089a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1089a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1089A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108920u: goto label_108920;
            case 0x108960u: goto label_108960;
            case 0x108988u: goto label_108988;
            case 0x10898Cu: goto label_10898c;
            case 0x1089A4u: goto label_1089a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1089B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
