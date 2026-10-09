#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126898
// Address: 0x126898 - 0x126918
void sub_00126898_0x126898(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126898_0x126898");
#endif

    ctx->pc = 0x126898u;

    // 0x126898: 0x28a50012  slti        $a1, $a1, 0x12
    ctx->pc = 0x126898u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x12689c: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x12689cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1268a0: 0x14a0001b  bnez        $a1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1268A0u;
    {
        const bool branch_taken_0x1268a0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1268A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1268A0u;
            // 0x1268a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1268a0) {
            ctx->pc = 0x126910u;
            goto label_126910;
        }
    }
    ctx->pc = 0x1268A8u;
    // 0x1268a8: 0x94e30000  lhu         $v1, 0x0($a3)
    ctx->pc = 0x1268a8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1268ac: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x1268acu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1268b0: 0x2408ff00  addiu       $t0, $zero, -0x100
    ctx->pc = 0x1268b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1268b4: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1268b4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1268b8: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x1268b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x1268bc: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1268bcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1268c0: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x1268c0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x1268c4: 0x14650012  bne         $v1, $a1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1268C4u;
    {
        const bool branch_taken_0x1268c4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x1268C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1268C4u;
            // 0x1268c8: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1268c4) {
            ctx->pc = 0x126910u;
            goto label_126910;
        }
    }
    ctx->pc = 0x1268CCu;
    // 0x1268cc: 0x94e40002  lhu         $a0, 0x2($a3)
    ctx->pc = 0x1268ccu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x1268d0: 0x90e30003  lbu         $v1, 0x3($a3)
    ctx->pc = 0x1268d0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x1268d4: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x1268d4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1268d8: 0x882024  and         $a0, $a0, $t0
    ctx->pc = 0x1268d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 8));
    // 0x1268dc: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1268dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1268e0: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1268e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1268e4: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x1268e4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x1268e8: 0x2863000e  slti        $v1, $v1, 0xE
    ctx->pc = 0x1268e8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)14) ? 1 : 0);
    // 0x1268ec: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1268ECu;
    {
        const bool branch_taken_0x1268ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1268F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1268ECu;
            // 0x1268f0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1268ec) {
            ctx->pc = 0x126910u;
            goto label_126910;
        }
    }
    ctx->pc = 0x1268F4u;
    // 0x1268f4: 0x94e40010  lhu         $a0, 0x10($a3)
    ctx->pc = 0x1268f4u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x1268f8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1268f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1268fc: 0x41a00  sll         $v1, $a0, 8
    ctx->pc = 0x1268fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x126900: 0x42202  srl         $a0, $a0, 8
    ctx->pc = 0x126900u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x126904: 0x681824  and         $v1, $v1, $t0
    ctx->pc = 0x126904u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 8));
    // 0x126908: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x126908u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x12690c: 0xa4c40000  sh          $a0, 0x0($a2)
    ctx->pc = 0x12690cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 4));
label_126910:
    // 0x126910: 0x3e00008  jr          $ra
    ctx->pc = 0x126910u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126910u: goto label_126910;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126918u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
