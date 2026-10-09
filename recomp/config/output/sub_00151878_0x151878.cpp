#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00151878
// Address: 0x151878 - 0x151970
void sub_00151878_0x151878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00151878_0x151878");
#endif

    ctx->pc = 0x151878u;

    // 0x151878: 0x248a0128  addiu       $t2, $a0, 0x128
    ctx->pc = 0x151878u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x15187c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x15187cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x151880: 0x8d4304e8  lw          $v1, 0x4E8($t2)
    ctx->pc = 0x151880u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 1256)));
    // 0x151884: 0xa0602d  daddu       $t4, $a1, $zero
    ctx->pc = 0x151884u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151888: 0xad4404dc  sw          $a0, 0x4DC($t2)
    ctx->pc = 0x151888u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 1244), GPR_U32(ctx, 4));
    // 0x15188c: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x15188cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x151890: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x151890u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x151894: 0x1824024  and         $t0, $t4, $v0
    ctx->pc = 0x151894u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 12) & GPR_U64(ctx, 2));
    // 0x151898: 0xad4304e8  sw          $v1, 0x4E8($t2)
    ctx->pc = 0x151898u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 1256), GPR_U32(ctx, 3));
    // 0x15189c: 0x1881023  subu        $v0, $t4, $t0
    ctx->pc = 0x15189cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 12), GPR_U32(ctx, 8)));
    // 0x1518a0: 0x258c0  sll         $t3, $v0, 3
    ctx->pc = 0x1518a0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1518a4: 0x81090000  lb          $t1, 0x0($t0)
    ctx->pc = 0x1518a4u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1518a8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1518a8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1518ac: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x1518acu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1518b0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1518b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1518b4: 0x91060000  lbu         $a2, 0x0($t0)
    ctx->pc = 0x1518b4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1518b8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1518b8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1518bc: 0x91070000  lbu         $a3, 0x0($t0)
    ctx->pc = 0x1518bcu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1518c0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1518c0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1518c4: 0x81020000  lb          $v0, 0x0($t0)
    ctx->pc = 0x1518c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1518c8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1518c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1518cc: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1518ccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1518d0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1518d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1518d4: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x1518d4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x1518d8: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1518d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1518dc: 0x1244825  or          $t1, $t1, $a0
    ctx->pc = 0x1518dcu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 4));
    // 0x1518e0: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x1518e0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1518e4: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1518e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1518e8: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x1518e8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x1518ec: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1518ecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1518f0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1518f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1518f4: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1518f4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1518f8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1518f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1518fc: 0x1264825  or          $t1, $t1, $a2
    ctx->pc = 0x1518fcu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 6));
    // 0x151900: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x151900u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x151904: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x151904u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x151908: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x151908u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x15190c: 0xb2823  negu        $a1, $t3
    ctx->pc = 0x15190cu;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 11)));
    // 0x151910: 0x1274825  or          $t1, $t1, $a3
    ctx->pc = 0x151910u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 7));
    // 0x151914: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x151914u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x151918: 0x1694804  sllv        $t1, $t1, $t3
    ctx->pc = 0x151918u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 11) & 0x1F));
    // 0x15191c: 0xa21006  srlv        $v0, $v0, $a1
    ctx->pc = 0x15191cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), GPR_U32(ctx, 5) & 0x1F));
    // 0x151920: 0x25080004  addiu       $t0, $t0, 0x4
    ctx->pc = 0x151920u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
    // 0x151924: 0x11600004  beqz        $t3, . + 4 + (0x4 << 2)
    ctx->pc = 0x151924u;
    {
        const bool branch_taken_0x151924 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        ctx->pc = 0x151928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151924u;
            // 0x151928: 0x1221025  or          $v0, $t1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151924) {
            ctx->pc = 0x151938u;
            goto label_151938;
        }
    }
    ctx->pc = 0x15192Cu;
    // 0x15192c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15192Cu;
    {
        const bool branch_taken_0x15192c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15192Cu;
            // 0x151930: 0xad42002c  sw          $v0, 0x2C($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15192c) {
            ctx->pc = 0x15193Cu;
            goto label_15193c;
        }
    }
    ctx->pc = 0x151934u;
    // 0x151934: 0x0  nop
    ctx->pc = 0x151934u;
    // NOP
label_151938:
    // 0x151938: 0xad49002c  sw          $t1, 0x2C($t2)
    ctx->pc = 0x151938u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 44), GPR_U32(ctx, 9));
label_15193c:
    // 0x15193c: 0x10c1823  subu        $v1, $t0, $t4
    ctx->pc = 0x15193cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 12)));
    // 0x151940: 0xad40032c  sw          $zero, 0x32C($t2)
    ctx->pc = 0x151940u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 812), GPR_U32(ctx, 0));
    // 0x151944: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x151944u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x151948: 0xad400328  sw          $zero, 0x328($t2)
    ctx->pc = 0x151948u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 808), GPR_U32(ctx, 0));
    // 0x15194c: 0x1631821  addu        $v1, $t3, $v1
    ctx->pc = 0x15194cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x151950: 0x2462ffc7  addiu       $v0, $v1, -0x39
    ctx->pc = 0x151950u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967239));
    // 0x151954: 0x2463ffce  addiu       $v1, $v1, -0x32
    ctx->pc = 0x151954u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967246));
    // 0x151958: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x151958u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15195c: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x15195cu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x151960: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x151960u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x151964: 0x3e00008  jr          $ra
    ctx->pc = 0x151964u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x151968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151964u;
            // 0x151968: 0x1821021  addu        $v0, $t4, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151938u: goto label_151938;
            case 0x15193Cu: goto label_15193c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15196Cu;
    // 0x15196c: 0x0  nop
    ctx->pc = 0x15196cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
