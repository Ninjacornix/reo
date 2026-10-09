#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AEC80
// Address: 0x1aec80 - 0x1aed60
void sub_001AEC80_0x1aec80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AEC80_0x1aec80");
#endif

    ctx->pc = 0x1aec80u;

    // 0x1aec80: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1aec80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1aec84: 0x10820021  beq         $a0, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x1AEC84u;
    {
        const bool branch_taken_0x1aec84 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1AEC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEC84u;
            // 0x1aec88: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aec84) {
            ctx->pc = 0x1AED0Cu;
            goto label_1aed0c;
        }
    }
    ctx->pc = 0x1AEC8Cu;
    // 0x1aec8c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1aec8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1aec90: 0x1082001c  beq         $a0, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1AEC90u;
    {
        const bool branch_taken_0x1aec90 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1AEC94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEC90u;
            // 0x1aec94: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aec90) {
            ctx->pc = 0x1AED04u;
            goto label_1aed04;
        }
    }
    ctx->pc = 0x1AEC98u;
    // 0x1aec98: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1aec98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aec9c: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AEC9Cu;
    {
        const bool branch_taken_0x1aec9c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1AECA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEC9Cu;
            // 0x1aeca0: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aec9c) {
            ctx->pc = 0x1AECBCu;
            goto label_1aecbc;
        }
    }
    ctx->pc = 0x1AECA4u;
    // 0x1aeca4: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AECA4u;
    {
        const bool branch_taken_0x1aeca4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AECA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AECA4u;
            // 0x1aeca8: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aeca4) {
            ctx->pc = 0x1AECB4u;
            goto label_1aecb4;
        }
    }
    ctx->pc = 0x1AECACu;
    // 0x1aecac: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1AECACu;
    {
        const bool branch_taken_0x1aecac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AECB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AECACu;
            // 0x1aecb0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aecac) {
            ctx->pc = 0x1AED50u;
            goto label_1aed50;
        }
    }
    ctx->pc = 0x1AECB4u;
label_1aecb4:
    // 0x1aecb4: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1AECB4u;
    {
        const bool branch_taken_0x1aecb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AECB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AECB4u;
            // 0x1aecb8: 0x942244b8  lhu         $v0, 0x44B8($at) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17592)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aecb4) {
            ctx->pc = 0x1AED50u;
            goto label_1aed50;
        }
    }
    ctx->pc = 0x1AECBCu;
label_1aecbc:
    // 0x1aecbc: 0x942444b0  lhu         $a0, 0x44B0($at)
    ctx->pc = 0x1aecbcu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17584)));
    // 0x1aecc0: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AECC0u;
    {
        const bool branch_taken_0x1aecc0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AECC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AECC0u;
            // 0x1aecc4: 0x41880  sll         $v1, $a0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aecc0) {
            ctx->pc = 0x1AECD0u;
            goto label_1aecd0;
        }
    }
    ctx->pc = 0x1AECC8u;
    // 0x1aecc8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1aecc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aeccc: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1aecccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_1aecd0:
    // 0x1aecd0: 0x3402ff53  ori         $v0, $zero, 0xFF53
    ctx->pc = 0x1aecd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65363);
    // 0x1aecd4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1aecd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aecd8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aecd8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aecdc: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1aecdcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1aece0: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1aece0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aece4: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1aece4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1aece8: 0x62001b  divu        $zero, $v1, $v0
    ctx->pc = 0x1aece8u;
    { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x1aecec: 0x0  nop
    ctx->pc = 0x1aececu;
    // NOP
    // 0x1aecf0: 0x0  nop
    ctx->pc = 0x1aecf0u;
    // NOP
    // 0x1aecf4: 0x1010  mfhi        $v0
    ctx->pc = 0x1aecf4u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1aecf8: 0xa42244b0  sh          $v0, 0x44B0($at)
    ctx->pc = 0x1aecf8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17584), (uint16_t)GPR_U32(ctx, 2));
    // 0x1aecfc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1AECFCu;
    {
        const bool branch_taken_0x1aecfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AED00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AECFCu;
            // 0x1aed00: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aecfc) {
            ctx->pc = 0x1AED50u;
            goto label_1aed50;
        }
    }
    ctx->pc = 0x1AED04u;
label_1aed04:
    // 0x1aed04: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1AED04u;
    {
        const bool branch_taken_0x1aed04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AED08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AED04u;
            // 0x1aed08: 0x90228de8  lbu         $v0, -0x7218($at) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294938088)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aed04) {
            ctx->pc = 0x1AED50u;
            goto label_1aed50;
        }
    }
    ctx->pc = 0x1AED0Cu;
label_1aed0c:
    // 0x1aed0c: 0x942444b8  lhu         $a0, 0x44B8($at)
    ctx->pc = 0x1aed0cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17592)));
    // 0x1aed10: 0x14800003  bnez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AED10u;
    {
        const bool branch_taken_0x1aed10 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AED14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AED10u;
            // 0x1aed14: 0x41880  sll         $v1, $a0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aed10) {
            ctx->pc = 0x1AED20u;
            goto label_1aed20;
        }
    }
    ctx->pc = 0x1AED18u;
    // 0x1aed18: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1aed18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1aed1c: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1aed1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_1aed20:
    // 0x1aed20: 0x3402ff53  ori         $v0, $zero, 0xFF53
    ctx->pc = 0x1aed20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65363);
    // 0x1aed24: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1aed24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aed28: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1aed28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1aed2c: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1aed2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1aed30: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1aed30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aed34: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1aed34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1aed38: 0x62001b  divu        $zero, $v1, $v0
    ctx->pc = 0x1aed38u;
    { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x1aed3c: 0x0  nop
    ctx->pc = 0x1aed3cu;
    // NOP
    // 0x1aed40: 0x0  nop
    ctx->pc = 0x1aed40u;
    // NOP
    // 0x1aed44: 0x1010  mfhi        $v0
    ctx->pc = 0x1aed44u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1aed48: 0xa42244b8  sh          $v0, 0x44B8($at)
    ctx->pc = 0x1aed48u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17592), (uint16_t)GPR_U32(ctx, 2));
    // 0x1aed4c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1aed4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1aed50:
    // 0x1aed50: 0x3e00008  jr          $ra
    ctx->pc = 0x1AED50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AECB4u: goto label_1aecb4;
            case 0x1AECBCu: goto label_1aecbc;
            case 0x1AECD0u: goto label_1aecd0;
            case 0x1AED04u: goto label_1aed04;
            case 0x1AED0Cu: goto label_1aed0c;
            case 0x1AED20u: goto label_1aed20;
            case 0x1AED50u: goto label_1aed50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AED58u;
    // 0x1aed58: 0x0  nop
    ctx->pc = 0x1aed58u;
    // NOP
    // 0x1aed5c: 0x0  nop
    ctx->pc = 0x1aed5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
