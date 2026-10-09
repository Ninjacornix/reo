#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001585B8
// Address: 0x1585b8 - 0x158650
void sub_001585B8_0x1585b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001585B8_0x1585b8");
#endif

    ctx->pc = 0x1585b8u;

    // 0x1585b8: 0x90870000  lbu         $a3, 0x0($a0)
    ctx->pc = 0x1585b8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1585bc: 0x24060100  addiu       $a2, $zero, 0x100
    ctx->pc = 0x1585bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x1585c0: 0x90820001  lbu         $v0, 0x1($a0)
    ctx->pc = 0x1585c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1585c4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1585c4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1585c8: 0x90830002  lbu         $v1, 0x2($a0)
    ctx->pc = 0x1585c8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1585cc: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1585ccu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1585d0: 0x90850003  lbu         $a1, 0x3($a0)
    ctx->pc = 0x1585d0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1585d4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1585d4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1585d8: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1585d8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1585dc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1585dcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1585e0: 0xe53825  or          $a3, $a3, $a1
    ctx->pc = 0x1585e0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 5));
    // 0x1585e4: 0x10e60017  beq         $a3, $a2, . + 4 + (0x17 << 2)
    ctx->pc = 0x1585E4u;
    {
        const bool branch_taken_0x1585e4 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 6));
        ctx->pc = 0x1585E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1585E4u;
            // 0x1585e8: 0x24080004  addiu       $t0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1585e4) {
            ctx->pc = 0x158644u;
            goto label_158644;
        }
    }
    ctx->pc = 0x1585ECu;
    // 0x1585ec: 0x24020101  addiu       $v0, $zero, 0x101
    ctx->pc = 0x1585ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x1585f0: 0x10e20014  beq         $a3, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1585F0u;
    {
        const bool branch_taken_0x1585f0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x1585F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1585F0u;
            // 0x1585f4: 0x24080003  addiu       $t0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1585f0) {
            ctx->pc = 0x158644u;
            goto label_158644;
        }
    }
    ctx->pc = 0x1585F8u;
    // 0x1585f8: 0x24e2fefe  addiu       $v0, $a3, -0x102
    ctx->pc = 0x1585f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967038));
    // 0x1585fc: 0x2c4200ae  sltiu       $v0, $v0, 0xAE
    ctx->pc = 0x1585fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)174) ? 1 : 0);
    // 0x158600: 0x14400010  bnez        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x158600u;
    {
        const bool branch_taken_0x158600 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158600u;
            // 0x158604: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158600) {
            ctx->pc = 0x158644u;
            goto label_158644;
        }
    }
    ctx->pc = 0x158608u;
    // 0x158608: 0x240201b2  addiu       $v0, $zero, 0x1B2
    ctx->pc = 0x158608u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 434));
    // 0x15860c: 0x10e2000d  beq         $a3, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x15860Cu;
    {
        const bool branch_taken_0x15860c = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x158610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15860Cu;
            // 0x158610: 0x24080020  addiu       $t0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15860c) {
            ctx->pc = 0x158644u;
            goto label_158644;
        }
    }
    ctx->pc = 0x158614u;
    // 0x158614: 0x240201b3  addiu       $v0, $zero, 0x1B3
    ctx->pc = 0x158614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 435));
    // 0x158618: 0x10e2000a  beq         $a3, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x158618u;
    {
        const bool branch_taken_0x158618 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x15861Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158618u;
            // 0x15861c: 0x24080040  addiu       $t0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158618) {
            ctx->pc = 0x158644u;
            goto label_158644;
        }
    }
    ctx->pc = 0x158620u;
    // 0x158620: 0x240201b5  addiu       $v0, $zero, 0x1B5
    ctx->pc = 0x158620u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 437));
    // 0x158624: 0x10e20007  beq         $a3, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x158624u;
    {
        const bool branch_taken_0x158624 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x158628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158624u;
            // 0x158628: 0x24080010  addiu       $t0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158624) {
            ctx->pc = 0x158644u;
            goto label_158644;
        }
    }
    ctx->pc = 0x15862Cu;
    // 0x15862c: 0x240201b7  addiu       $v0, $zero, 0x1B7
    ctx->pc = 0x15862cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 439));
    // 0x158630: 0x10e20004  beq         $a3, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x158630u;
    {
        const bool branch_taken_0x158630 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x158634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158630u;
            // 0x158634: 0x24080080  addiu       $t0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158630) {
            ctx->pc = 0x158644u;
            goto label_158644;
        }
    }
    ctx->pc = 0x158638u;
    // 0x158638: 0x38e201b8  xori        $v0, $a3, 0x1B8
    ctx->pc = 0x158638u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) ^ (uint64_t)(uint16_t)440);
    // 0x15863c: 0x24080008  addiu       $t0, $zero, 0x8
    ctx->pc = 0x15863cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x158640: 0x2400b  movn        $t0, $zero, $v0
    ctx->pc = 0x158640u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 0));
label_158644:
    // 0x158644: 0x3e00008  jr          $ra
    ctx->pc = 0x158644u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158644u;
            // 0x158648: 0x100102d  daddu       $v0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158644u: goto label_158644;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15864Cu;
    // 0x15864c: 0x0  nop
    ctx->pc = 0x15864cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
