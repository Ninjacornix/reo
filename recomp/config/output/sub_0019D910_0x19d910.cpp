#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019D910
// Address: 0x19d910 - 0x19dac0
void sub_0019D910_0x19d910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019D910_0x19d910");
#endif

    ctx->pc = 0x19d910u;

    // 0x19d910: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x19d910u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x19d914: 0x3c03002a  lui         $v1, 0x2A
    ctx->pc = 0x19d914u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)42 << 16));
    // 0x19d918: 0x2446ffff  addiu       $a2, $v0, -0x1
    ctx->pc = 0x19d918u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x19d91c: 0x24638680  addiu       $v1, $v1, -0x7980
    ctx->pc = 0x19d91cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294936192));
    // 0x19d920: 0x628c0  sll         $a1, $a2, 3
    ctx->pc = 0x19d920u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x19d924: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x19d924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x19d928: 0xa62823  subu        $a1, $a1, $a2
    ctx->pc = 0x19d928u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x19d92c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x19d92cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x19d930: 0x653021  addu        $a2, $v1, $a1
    ctx->pc = 0x19d930u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x19d934: 0x84c3001a  lh          $v1, 0x1A($a2)
    ctx->pc = 0x19d934u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 26)));
    // 0x19d938: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x19d938u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x19d93c: 0x84c3001c  lh          $v1, 0x1C($a2)
    ctx->pc = 0x19d93cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 28)));
    // 0x19d940: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x19d940u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x19d944: 0x8cc3000c  lw          $v1, 0xC($a2)
    ctx->pc = 0x19d944u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x19d948: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x19d948u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x19d94c: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x19d94cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x19d950: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x19d950u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x19d954: 0xa31818  mult        $v1, $a1, $v1
    ctx->pc = 0x19d954u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x19d958: 0xac83000c  sw          $v1, 0xC($a0)
    ctx->pc = 0x19d958u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x19d95c: 0x8cc30020  lw          $v1, 0x20($a2)
    ctx->pc = 0x19d95cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x19d960: 0x10620045  beq         $v1, $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x19D960u;
    {
        const bool branch_taken_0x19d960 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x19D964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D960u;
            // 0x19d964: 0x24020013  addiu       $v0, $zero, 0x13 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d960) {
            ctx->pc = 0x19DA78u;
            goto label_19da78;
        }
    }
    ctx->pc = 0x19D968u;
    // 0x19d968: 0x10620043  beq         $v1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x19D968u;
    {
        const bool branch_taken_0x19d968 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x19d968) {
            ctx->pc = 0x19DA78u;
            goto label_19da78;
        }
    }
    ctx->pc = 0x19D970u;
    // 0x19d970: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x19d970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x19d974: 0x1062002b  beq         $v1, $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x19D974u;
    {
        const bool branch_taken_0x19d974 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x19D978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D974u;
            // 0x19d978: 0x24070005  addiu       $a3, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d974) {
            ctx->pc = 0x19DA24u;
            goto label_19da24;
        }
    }
    ctx->pc = 0x19D97Cu;
    // 0x19d97c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19d97cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19d980: 0x10620017  beq         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x19D980u;
    {
        const bool branch_taken_0x19d980 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x19D984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D980u;
            // 0x19d984: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d980) {
            ctx->pc = 0x19D9E0u;
            goto label_19d9e0;
        }
    }
    ctx->pc = 0x19D988u;
    // 0x19d988: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x19D988u;
    {
        const bool branch_taken_0x19d988 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D988u;
            // 0x19d98c: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d988) {
            ctx->pc = 0x19D998u;
            goto label_19d998;
        }
    }
    ctx->pc = 0x19D990u;
    // 0x19d990: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x19D990u;
    {
        const bool branch_taken_0x19d990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D990u;
            // 0x19d994: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d990) {
            ctx->pc = 0x19DAACu;
            goto label_19daac;
        }
    }
    ctx->pc = 0x19D998u;
label_19d998:
    // 0x19d998: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x19d998u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19d99c: 0xac860018  sw          $a2, 0x18($a0)
    ctx->pc = 0x19d99cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 6));
    // 0x19d9a0: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x19d9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x19d9a4: 0xac85001c  sw          $a1, 0x1C($a0)
    ctx->pc = 0x19d9a4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 5));
    // 0x19d9a8: 0x24020018  addiu       $v0, $zero, 0x18
    ctx->pc = 0x19d9a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x19d9ac: 0xac830020  sw          $v1, 0x20($a0)
    ctx->pc = 0x19d9acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 3));
    // 0x19d9b0: 0xac860024  sw          $a2, 0x24($a0)
    ctx->pc = 0x19d9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 6));
    // 0x19d9b4: 0xac860028  sw          $a2, 0x28($a0)
    ctx->pc = 0x19d9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 6));
    // 0x19d9b8: 0xac83002c  sw          $v1, 0x2C($a0)
    ctx->pc = 0x19d9b8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 3));
    // 0x19d9bc: 0xac860030  sw          $a2, 0x30($a0)
    ctx->pc = 0x19d9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 6));
    // 0x19d9c0: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x19d9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x19d9c4: 0xac830038  sw          $v1, 0x38($a0)
    ctx->pc = 0x19d9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 3));
    // 0x19d9c8: 0xac86003c  sw          $a2, 0x3C($a0)
    ctx->pc = 0x19d9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 6));
    // 0x19d9cc: 0xac820040  sw          $v0, 0x40($a0)
    ctx->pc = 0x19d9ccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 2));
    // 0x19d9d0: 0xac830044  sw          $v1, 0x44($a0)
    ctx->pc = 0x19d9d0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 3));
    // 0x19d9d4: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x19d9d4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x19d9d8: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x19D9D8u;
    {
        const bool branch_taken_0x19d9d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19D9DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19D9D8u;
            // 0x19d9dc: 0xac850034  sw          $a1, 0x34($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19d9d8) {
            ctx->pc = 0x19DAA8u;
            goto label_19daa8;
        }
    }
    ctx->pc = 0x19D9E0u;
label_19d9e0:
    // 0x19d9e0: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x19d9e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19d9e4: 0xac850018  sw          $a1, 0x18($a0)
    ctx->pc = 0x19d9e4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 5));
    // 0x19d9e8: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x19d9e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x19d9ec: 0xac83001c  sw          $v1, 0x1C($a0)
    ctx->pc = 0x19d9ecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
    // 0x19d9f0: 0xac820020  sw          $v0, 0x20($a0)
    ctx->pc = 0x19d9f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 2));
    // 0x19d9f4: 0xac850024  sw          $a1, 0x24($a0)
    ctx->pc = 0x19d9f4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 5));
    // 0x19d9f8: 0xac850028  sw          $a1, 0x28($a0)
    ctx->pc = 0x19d9f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 5));
    // 0x19d9fc: 0xac82002c  sw          $v0, 0x2C($a0)
    ctx->pc = 0x19d9fcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 2));
    // 0x19da00: 0xac850030  sw          $a1, 0x30($a0)
    ctx->pc = 0x19da00u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 5));
    // 0x19da04: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x19da04u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x19da08: 0xac820038  sw          $v0, 0x38($a0)
    ctx->pc = 0x19da08u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 2));
    // 0x19da0c: 0xac80003c  sw          $zero, 0x3C($a0)
    ctx->pc = 0x19da0cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 0));
    // 0x19da10: 0xac800040  sw          $zero, 0x40($a0)
    ctx->pc = 0x19da10u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 0));
    // 0x19da14: 0xac800044  sw          $zero, 0x44($a0)
    ctx->pc = 0x19da14u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 0));
    // 0x19da18: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x19da18u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x19da1c: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x19DA1Cu;
    {
        const bool branch_taken_0x19da1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DA1Cu;
            // 0x19da20: 0xac830034  sw          $v1, 0x34($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19da1c) {
            ctx->pc = 0x19DAA8u;
            goto label_19daa8;
        }
    }
    ctx->pc = 0x19DA24u;
label_19da24:
    // 0x19da24: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x19da24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x19da28: 0xac870018  sw          $a3, 0x18($a0)
    ctx->pc = 0x19da28u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 7));
    // 0x19da2c: 0x2405001f  addiu       $a1, $zero, 0x1F
    ctx->pc = 0x19da2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x19da30: 0xac86001c  sw          $a2, 0x1C($a0)
    ctx->pc = 0x19da30u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 6));
    // 0x19da34: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x19da34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19da38: 0xac850020  sw          $a1, 0x20($a0)
    ctx->pc = 0x19da38u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 5));
    // 0x19da3c: 0x2402000f  addiu       $v0, $zero, 0xF
    ctx->pc = 0x19da3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x19da40: 0xac870024  sw          $a3, 0x24($a0)
    ctx->pc = 0x19da40u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 7));
    // 0x19da44: 0xac870028  sw          $a3, 0x28($a0)
    ctx->pc = 0x19da44u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 7));
    // 0x19da48: 0xac85002c  sw          $a1, 0x2C($a0)
    ctx->pc = 0x19da48u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 5));
    // 0x19da4c: 0xac870030  sw          $a3, 0x30($a0)
    ctx->pc = 0x19da4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 7));
    // 0x19da50: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x19da50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x19da54: 0xac850038  sw          $a1, 0x38($a0)
    ctx->pc = 0x19da54u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 5));
    // 0x19da58: 0xac83003c  sw          $v1, 0x3C($a0)
    ctx->pc = 0x19da58u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 3));
    // 0x19da5c: 0xac820040  sw          $v0, 0x40($a0)
    ctx->pc = 0x19da5cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 2));
    // 0x19da60: 0xac830044  sw          $v1, 0x44($a0)
    ctx->pc = 0x19da60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 3));
    // 0x19da64: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x19da64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x19da68: 0xac860034  sw          $a2, 0x34($a0)
    ctx->pc = 0x19da68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 6));
    // 0x19da6c: 0xac870024  sw          $a3, 0x24($a0)
    ctx->pc = 0x19da6cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 7));
    // 0x19da70: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x19DA70u;
    {
        const bool branch_taken_0x19da70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DA74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DA70u;
            // 0x19da74: 0xac85002c  sw          $a1, 0x2C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19da70) {
            ctx->pc = 0x19DAA8u;
            goto label_19daa8;
        }
    }
    ctx->pc = 0x19DA78u;
label_19da78:
    // 0x19da78: 0xac800020  sw          $zero, 0x20($a0)
    ctx->pc = 0x19da78u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x19da7c: 0xac80001c  sw          $zero, 0x1C($a0)
    ctx->pc = 0x19da7cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
    // 0x19da80: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x19da80u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x19da84: 0xac80002c  sw          $zero, 0x2C($a0)
    ctx->pc = 0x19da84u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x19da88: 0xac800028  sw          $zero, 0x28($a0)
    ctx->pc = 0x19da88u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 0));
    // 0x19da8c: 0xac800024  sw          $zero, 0x24($a0)
    ctx->pc = 0x19da8cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
    // 0x19da90: 0xac800038  sw          $zero, 0x38($a0)
    ctx->pc = 0x19da90u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 0));
    // 0x19da94: 0xac800034  sw          $zero, 0x34($a0)
    ctx->pc = 0x19da94u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 0));
    // 0x19da98: 0xac800030  sw          $zero, 0x30($a0)
    ctx->pc = 0x19da98u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 0));
    // 0x19da9c: 0xac800044  sw          $zero, 0x44($a0)
    ctx->pc = 0x19da9cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 0));
    // 0x19daa0: 0xac800040  sw          $zero, 0x40($a0)
    ctx->pc = 0x19daa0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 0));
    // 0x19daa4: 0xac80003c  sw          $zero, 0x3C($a0)
    ctx->pc = 0x19daa4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 0));
label_19daa8:
    // 0x19daa8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19daa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_19daac:
    // 0x19daac: 0x3e00008  jr          $ra
    ctx->pc = 0x19DAACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19D998u: goto label_19d998;
            case 0x19D9E0u: goto label_19d9e0;
            case 0x19DA24u: goto label_19da24;
            case 0x19DA78u: goto label_19da78;
            case 0x19DAA8u: goto label_19daa8;
            case 0x19DAACu: goto label_19daac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19DAB4u;
    // 0x19dab4: 0x0  nop
    ctx->pc = 0x19dab4u;
    // NOP
    // 0x19dab8: 0x0  nop
    ctx->pc = 0x19dab8u;
    // NOP
    // 0x19dabc: 0x0  nop
    ctx->pc = 0x19dabcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
