#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126918
// Address: 0x126918 - 0x126990
void sub_00126918_0x126918(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126918_0x126918");
#endif

    ctx->pc = 0x126918u;

    // 0x126918: 0x28a50014  slti        $a1, $a1, 0x14
    ctx->pc = 0x126918u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x12691c: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x12691cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126920: 0x14a00019  bnez        $a1, . + 4 + (0x19 << 2)
    ctx->pc = 0x126920u;
    {
        const bool branch_taken_0x126920 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x126924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126920u;
            // 0x126924: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126920) {
            ctx->pc = 0x126988u;
            goto label_126988;
        }
    }
    ctx->pc = 0x126928u;
    // 0x126928: 0x95030000  lhu         $v1, 0x0($t0)
    ctx->pc = 0x126928u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x12692c: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x12692cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x126930: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x126930u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126934: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x126934u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x126938: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126938u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x12693c: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x12693cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x126940: 0x14650011  bne         $v1, $a1, . + 4 + (0x11 << 2)
    ctx->pc = 0x126940u;
    {
        const bool branch_taken_0x126940 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x126944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126940u;
            // 0x126944: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126940) {
            ctx->pc = 0x126988u;
            goto label_126988;
        }
    }
    ctx->pc = 0x126948u;
    // 0x126948: 0x95030002  lhu         $v1, 0x2($t0)
    ctx->pc = 0x126948u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 2)));
    // 0x12694c: 0x2405ff00  addiu       $a1, $zero, -0x100
    ctx->pc = 0x12694cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x126950: 0x91040003  lbu         $a0, 0x3($t0)
    ctx->pc = 0x126950u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 3)));
    // 0x126954: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x126954u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126958: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x126958u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x12695c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x12695cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x126960: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x126960u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x126964: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x126964u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x126968: 0x28840010  slti        $a0, $a0, 0x10
    ctx->pc = 0x126968u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x12696c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x12696Cu;
    {
        const bool branch_taken_0x12696c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x126970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12696Cu;
            // 0x126970: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12696c) {
            ctx->pc = 0x126988u;
            goto label_126988;
        }
    }
    ctx->pc = 0x126974u;
    // 0x126974: 0x91040012  lbu         $a0, 0x12($t0)
    ctx->pc = 0x126974u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 18)));
    // 0x126978: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x126978u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12697c: 0xa0c40000  sb          $a0, 0x0($a2)
    ctx->pc = 0x12697cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x126980: 0x91030013  lbu         $v1, 0x13($t0)
    ctx->pc = 0x126980u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 19)));
    // 0x126984: 0xa0e30000  sb          $v1, 0x0($a3)
    ctx->pc = 0x126984u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 3));
label_126988:
    // 0x126988: 0x3e00008  jr          $ra
    ctx->pc = 0x126988u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126988u: goto label_126988;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126990u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
