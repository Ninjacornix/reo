#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001119D0
// Address: 0x1119d0 - 0x111a90
void sub_001119D0_0x1119d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001119D0_0x1119d0");
#endif

    ctx->pc = 0x1119d0u;

    // 0x1119d0: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x1119d0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1119d4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1119d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1119d8: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1119d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1119dc: 0x52b3a  dsrl        $a1, $a1, 12
    ctx->pc = 0x1119dcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> 12);
    // 0x1119e0: 0x21d3e  dsrl32      $v1, $v0, 20
    ctx->pc = 0x1119e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) >> (32 + 20));
    // 0x1119e4: 0x227fe  dsrl32      $a0, $v0, 31
    ctx->pc = 0x1119e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) >> (32 + 31));
    // 0x1119e8: 0x306707ff  andi        $a3, $v1, 0x7FF
    ctx->pc = 0x1119e8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2047);
    // 0x1119ec: 0x451824  and         $v1, $v0, $a1
    ctx->pc = 0x1119ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & GPR_U64(ctx, 5));
    // 0x1119f0: 0x14e00005  bnez        $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x1119F0u;
    {
        const bool branch_taken_0x1119f0 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1119F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1119F0u;
            // 0x1119f4: 0xacc40004  sw          $a0, 0x4($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1119f0) {
            ctx->pc = 0x111A08u;
            goto label_111a08;
        }
    }
    ctx->pc = 0x1119F8u;
    // 0x1119f8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1119f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1119fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1119FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1119FCu;
            // 0x111a00: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111A08u: goto label_111a08;
            case 0x111A38u: goto label_111a38;
            case 0x111A58u: goto label_111a58;
            case 0x111A5Cu: goto label_111a5c;
            case 0x111A68u: goto label_111a68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111A04u;
    // 0x111a04: 0x0  nop
    ctx->pc = 0x111a04u;
    // NOP
label_111a08:
    // 0x111a08: 0x240207ff  addiu       $v0, $zero, 0x7FF
    ctx->pc = 0x111a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2047));
    // 0x111a0c: 0x54e20016  bnel        $a3, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x111A0Cu;
    {
        const bool branch_taken_0x111a0c = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        if (branch_taken_0x111a0c) {
            ctx->pc = 0x111A10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111A0Cu;
            // 0x111a10: 0x31a38  dsll        $v1, $v1, 8 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 8);
        ctx->in_delay_slot = false;
            ctx->pc = 0x111A68u;
            goto label_111a68;
        }
    }
    ctx->pc = 0x111A14u;
    // 0x111a14: 0x240203ff  addiu       $v0, $zero, 0x3FF
    ctx->pc = 0x111a14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1023));
    // 0x111a18: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x111A18u;
    {
        const bool branch_taken_0x111a18 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x111A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111A18u;
            // 0x111a1c: 0xacc20008  sw          $v0, 0x8($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111a18) {
            ctx->pc = 0x111A38u;
            goto label_111a38;
        }
    }
    ctx->pc = 0x111A20u;
    // 0x111a20: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x111a20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x111a24: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x111a24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x111a28: 0x2137c  dsll32      $v0, $v0, 13
    ctx->pc = 0x111a28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 13));
    // 0x111a2c: 0xfcc20010  sd          $v0, 0x10($a2)
    ctx->pc = 0x111a2cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 2));
    // 0x111a30: 0x3e00008  jr          $ra
    ctx->pc = 0x111A30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111A30u;
            // 0x111a34: 0xacc30000  sw          $v1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111A08u: goto label_111a08;
            case 0x111A38u: goto label_111a38;
            case 0x111A58u: goto label_111a58;
            case 0x111A5Cu: goto label_111a5c;
            case 0x111A68u: goto label_111a68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111A38u;
label_111a38:
    // 0x111a38: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x111a38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x111a3c: 0x2113c  dsll32      $v0, $v0, 4
    ctx->pc = 0x111a3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 4));
    // 0x111a40: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x111a40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x111a44: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x111A44u;
    {
        const bool branch_taken_0x111a44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x111A48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111A44u;
            // 0x111a48: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111a44) {
            ctx->pc = 0x111A58u;
            goto label_111a58;
        }
    }
    ctx->pc = 0x111A4Cu;
    // 0x111a4c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x111A4Cu;
    {
        const bool branch_taken_0x111a4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111A4Cu;
            // 0x111a50: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111a4c) {
            ctx->pc = 0x111A5Cu;
            goto label_111a5c;
        }
    }
    ctx->pc = 0x111A54u;
    // 0x111a54: 0x0  nop
    ctx->pc = 0x111a54u;
    // NOP
label_111a58:
    // 0x111a58: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x111a58u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_111a5c:
    // 0x111a5c: 0x3e00008  jr          $ra
    ctx->pc = 0x111A5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111A5Cu;
            // 0x111a60: 0xfcc30010  sd          $v1, 0x10($a2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111A08u: goto label_111a08;
            case 0x111A38u: goto label_111a38;
            case 0x111A58u: goto label_111a58;
            case 0x111A5Cu: goto label_111a5c;
            case 0x111A68u: goto label_111a68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111A64u;
    // 0x111a64: 0x0  nop
    ctx->pc = 0x111a64u;
    // NOP
label_111a68:
    // 0x111a68: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x111a68u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x111a6c: 0x2137c  dsll32      $v0, $v0, 13
    ctx->pc = 0x111a6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 13));
    // 0x111a70: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x111a70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x111a74: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x111a74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x111a78: 0x24e4fc01  addiu       $a0, $a3, -0x3FF
    ctx->pc = 0x111a78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 4294966273));
    // 0x111a7c: 0xfcc30010  sd          $v1, 0x10($a2)
    ctx->pc = 0x111a7cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 3));
    // 0x111a80: 0xacc40008  sw          $a0, 0x8($a2)
    ctx->pc = 0x111a80u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 4));
    // 0x111a84: 0x3e00008  jr          $ra
    ctx->pc = 0x111A84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111A84u;
            // 0x111a88: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111A08u: goto label_111a08;
            case 0x111A38u: goto label_111a38;
            case 0x111A58u: goto label_111a58;
            case 0x111A5Cu: goto label_111a5c;
            case 0x111A68u: goto label_111a68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111A8Cu;
    // 0x111a8c: 0x0  nop
    ctx->pc = 0x111a8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
