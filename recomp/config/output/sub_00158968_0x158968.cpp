#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158968
// Address: 0x158968 - 0x158e10
void sub_00158968_0x158968(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158968_0x158968");
#endif

    switch (ctx->pc) {
        case 0x158c40u: goto label_158c40;
        default: break;
    }

    ctx->pc = 0x158968u;

    // 0x158968: 0x80602d  daddu       $t4, $a0, $zero
    ctx->pc = 0x158968u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15896c: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x15896cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x158970: 0x1824024  and         $t0, $t4, $v0
    ctx->pc = 0x158970u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 12) & GPR_U64(ctx, 2));
    // 0x158974: 0xa0682d  daddu       $t5, $a1, $zero
    ctx->pc = 0x158974u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158978: 0x1881023  subu        $v0, $t4, $t0
    ctx->pc = 0x158978u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 12), GPR_U32(ctx, 8)));
    // 0x15897c: 0x810a0000  lb          $t2, 0x0($t0)
    ctx->pc = 0x15897cu;
    SET_GPR_S32(ctx, 10, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158980: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158980u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158984: 0x248c0  sll         $t1, $v0, 3
    ctx->pc = 0x158984u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x158988: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x158988u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15898c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15898cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158990: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x158990u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158994: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158994u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158998: 0x91050000  lbu         $a1, 0x0($t0)
    ctx->pc = 0x158998u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15899c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x15899cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1589a0: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x1589a0u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1589a4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1589a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1589a8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1589a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1589ac: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1589acu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1589b0: 0xa5200  sll         $t2, $t2, 8
    ctx->pc = 0x1589b0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
    // 0x1589b4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1589b4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1589b8: 0x1435025  or          $t2, $t2, $v1
    ctx->pc = 0x1589b8u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 3));
    // 0x1589bc: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x1589bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1589c0: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1589c0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1589c4: 0xa5200  sll         $t2, $t2, 8
    ctx->pc = 0x1589c4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
    // 0x1589c8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1589c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1589cc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1589ccu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1589d0: 0x1445025  or          $t2, $t2, $a0
    ctx->pc = 0x1589d0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 4));
    // 0x1589d4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1589d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1589d8: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x1589d8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1589dc: 0xa5200  sll         $t2, $t2, 8
    ctx->pc = 0x1589dcu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
    // 0x1589e0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1589e0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1589e4: 0x1455025  or          $t2, $t2, $a1
    ctx->pc = 0x1589e4u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 5));
    // 0x1589e8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1589e8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1589ec: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1589ecu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1589f0: 0x11200007  beqz        $t1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1589F0u;
    {
        const bool branch_taken_0x1589f0 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        ctx->pc = 0x1589F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1589F0u;
            // 0x1589f4: 0x12a5004  sllv        $t2, $t2, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 9) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1589f0) {
            ctx->pc = 0x158A10u;
            goto label_158a10;
        }
    }
    ctx->pc = 0x1589F8u;
    // 0x1589f8: 0x91023  negu        $v0, $t1
    ctx->pc = 0x1589f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 9)));
    // 0x1589fc: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x1589fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x158a00: 0x1422825  or          $a1, $t2, $v0
    ctx->pc = 0x158a00u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x158a04: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x158A04u;
    {
        const bool branch_taken_0x158a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158A04u;
            // 0x158a08: 0x1275004  sllv        $t2, $a3, $t1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 9) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158a04) {
            ctx->pc = 0x158A18u;
            goto label_158a18;
        }
    }
    ctx->pc = 0x158A0Cu;
    // 0x158a0c: 0x0  nop
    ctx->pc = 0x158a0cu;
    // NOP
label_158a10:
    // 0x158a10: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x158a10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158a14: 0xe0502d  daddu       $t2, $a3, $zero
    ctx->pc = 0x158a14u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_158a18:
    // 0x158a18: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x158a18u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158a1c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158a1cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158a20: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158a20u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158a24: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158a24u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158a28: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158a28u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158a2c: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x158a2cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158a30: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158a30u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x158a34: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158a34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158a38: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158a38u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158a3c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158a3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158a40: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x158a40u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x158a44: 0x24040101  addiu       $a0, $zero, 0x101
    ctx->pc = 0x158a44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x158a48: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158a48u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158a4c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158a4cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158a50: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158a50u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x158a54: 0x14a400eb  bne         $a1, $a0, . + 4 + (0xEB << 2)
    ctx->pc = 0x158A54u;
    {
        const bool branch_taken_0x158a54 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 4));
        ctx->pc = 0x158A58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158A54u;
            // 0x158a58: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158a54) {
            ctx->pc = 0x158E04u;
            goto label_158e04;
        }
    }
    ctx->pc = 0x158A5Cu;
    // 0x158a5c: 0x2922001b  slti        $v0, $t1, 0x1B
    ctx->pc = 0x158a5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x158a60: 0x54400015  bnel        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x158A60u;
    {
        const bool branch_taken_0x158a60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x158a60) {
            ctx->pc = 0x158A64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158A60u;
            // 0x158a64: 0x25290005  addiu       $t1, $t1, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158AB8u;
            goto label_158ab8;
        }
    }
    ctx->pc = 0x158A68u;
    // 0x158a68: 0x2529ffe5  addiu       $t1, $t1, -0x1B
    ctx->pc = 0x158a68u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967269));
    // 0x158a6c: 0xe0502d  daddu       $t2, $a3, $zero
    ctx->pc = 0x158a6cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158a70: 0x1271804  sllv        $v1, $a3, $t1
    ctx->pc = 0x158a70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 9) & 0x1F));
    // 0x158a74: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x158a74u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158a78: 0x39220000  xori        $v0, $t1, 0x0
    ctx->pc = 0x158a78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) ^ (uint64_t)(uint16_t)0);
    // 0x158a7c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158a7cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158a80: 0x62500b  movn        $t2, $v1, $v0
    ctx->pc = 0x158a80u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 10, GPR_VEC(ctx, 3));
    // 0x158a84: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158a84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158a88: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158a88u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158a8c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158a8cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158a90: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x158a90u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158a94: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158a94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158a98: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158a98u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x158a9c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158a9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158aa0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158aa0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158aa4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158aa4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158aa8: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x158aa8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x158aac: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158aacu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158ab0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x158AB0u;
    {
        const bool branch_taken_0x158ab0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158AB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158AB0u;
            // 0x158ab4: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158ab0) {
            ctx->pc = 0x158ABCu;
            goto label_158abc;
        }
    }
    ctx->pc = 0x158AB8u;
label_158ab8:
    // 0x158ab8: 0xa5140  sll         $t2, $t2, 5
    ctx->pc = 0x158ab8u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 5));
label_158abc:
    // 0x158abc: 0x2402001f  addiu       $v0, $zero, 0x1F
    ctx->pc = 0x158abcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x158ac0: 0x15220013  bne         $t1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x158AC0u;
    {
        const bool branch_taken_0x158ac0 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 2));
        ctx->pc = 0x158AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158AC0u;
            // 0x158ac4: 0xa2fc2  srl         $a1, $t2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158ac0) {
            ctx->pc = 0x158B10u;
            goto label_158b10;
        }
    }
    ctx->pc = 0x158AC8u;
    // 0x158ac8: 0xe0502d  daddu       $t2, $a3, $zero
    ctx->pc = 0x158ac8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158acc: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x158accu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158ad0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158ad0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158ad4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x158ad4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158ad8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158ad8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158adc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158adcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158ae0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158ae0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158ae4: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x158ae4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158ae8: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158ae8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x158aec: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158aecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158af0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158af0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158af4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158af4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158af8: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x158af8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x158afc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158afcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158b00: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158b00u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158b04: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x158B04u;
    {
        const bool branch_taken_0x158b04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158B04u;
            // 0x158b08: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158b04) {
            ctx->pc = 0x158B18u;
            goto label_158b18;
        }
    }
    ctx->pc = 0x158B0Cu;
    // 0x158b0c: 0x0  nop
    ctx->pc = 0x158b0cu;
    // NOP
label_158b10:
    // 0x158b10: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x158b10u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x158b14: 0xa5040  sll         $t2, $t2, 1
    ctx->pc = 0x158b14u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
label_158b18:
    // 0x158b18: 0x14a000ba  bnez        $a1, . + 4 + (0xBA << 2)
    ctx->pc = 0x158B18u;
    {
        const bool branch_taken_0x158b18 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x158B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158B18u;
            // 0x158b1c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158b18) {
            ctx->pc = 0x158E04u;
            goto label_158e04;
        }
    }
    ctx->pc = 0x158B20u;
    // 0x158b20: 0x2402001f  addiu       $v0, $zero, 0x1F
    ctx->pc = 0x158b20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x158b24: 0x15220012  bne         $t1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x158B24u;
    {
        const bool branch_taken_0x158b24 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 2));
        ctx->pc = 0x158B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158B24u;
            // 0x158b28: 0xa2fc2  srl         $a1, $t2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158b24) {
            ctx->pc = 0x158B70u;
            goto label_158b70;
        }
    }
    ctx->pc = 0x158B2Cu;
    // 0x158b2c: 0xe0502d  daddu       $t2, $a3, $zero
    ctx->pc = 0x158b2cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158b30: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x158b30u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158b34: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158b34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158b38: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x158b38u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158b3c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158b3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158b40: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158b40u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158b44: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158b44u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158b48: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x158b48u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158b4c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158b4cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x158b50: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158b50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158b54: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158b54u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158b58: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158b58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158b5c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x158b5cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x158b60: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158b60u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158b64: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158b64u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158b68: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x158B68u;
    {
        const bool branch_taken_0x158b68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158B6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158B68u;
            // 0x158b6c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158b68) {
            ctx->pc = 0x158B78u;
            goto label_158b78;
        }
    }
    ctx->pc = 0x158B70u;
label_158b70:
    // 0x158b70: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x158b70u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x158b74: 0xa5040  sll         $t2, $t2, 1
    ctx->pc = 0x158b74u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
label_158b78:
    // 0x158b78: 0x10a000a2  beqz        $a1, . + 4 + (0xA2 << 2)
    ctx->pc = 0x158B78u;
    {
        const bool branch_taken_0x158b78 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x158B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158B78u;
            // 0x158b7c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158b78) {
            ctx->pc = 0x158E04u;
            goto label_158e04;
        }
    }
    ctx->pc = 0x158B80u;
    // 0x158b80: 0x2922001b  slti        $v0, $t1, 0x1B
    ctx->pc = 0x158b80u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x158b84: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x158B84u;
    {
        const bool branch_taken_0x158b84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158B84u;
            // 0x158b88: 0xa2e82  srl         $a1, $t2, 26 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 10), 26));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158b84) {
            ctx->pc = 0x158B9Cu;
            goto label_158b9c;
        }
    }
    ctx->pc = 0x158B8Cu;
    // 0x158b8c: 0x2402003a  addiu       $v0, $zero, 0x3A
    ctx->pc = 0x158b8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 58));
    // 0x158b90: 0x491023  subu        $v0, $v0, $t1
    ctx->pc = 0x158b90u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x158b94: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x158b94u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x158b98: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x158b98u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
label_158b9c:
    // 0x158b9c: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x158b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x158ba0: 0x10a2000f  beq         $a1, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x158BA0u;
    {
        const bool branch_taken_0x158ba0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x158BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158BA0u;
            // 0x158ba4: 0x2ca2000b  sltiu       $v0, $a1, 0xB (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)11) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x158ba0) {
            ctx->pc = 0x158BE0u;
            goto label_158be0;
        }
    }
    ctx->pc = 0x158BA8u;
    // 0x158ba8: 0x1440008d  bnez        $v0, . + 4 + (0x8D << 2)
    ctx->pc = 0x158BA8u;
    {
        const bool branch_taken_0x158ba8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x158ba8) {
            ctx->pc = 0x158DE0u;
            goto label_158de0;
        }
    }
    ctx->pc = 0x158BB0u;
    // 0x158bb0: 0x2ca20018  sltiu       $v0, $a1, 0x18
    ctx->pc = 0x158bb0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)24) ? 1 : 0);
    // 0x158bb4: 0x1040008a  beqz        $v0, . + 4 + (0x8A << 2)
    ctx->pc = 0x158BB4u;
    {
        const bool branch_taken_0x158bb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x158bb4) {
            ctx->pc = 0x158DE0u;
            goto label_158de0;
        }
    }
    ctx->pc = 0x158BBCu;
    // 0x158bbc: 0x2ca20016  sltiu       $v0, $a1, 0x16
    ctx->pc = 0x158bbcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)22) ? 1 : 0);
    // 0x158bc0: 0x14400087  bnez        $v0, . + 4 + (0x87 << 2)
    ctx->pc = 0x158BC0u;
    {
        const bool branch_taken_0x158bc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158BC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158BC0u;
            // 0x158bc4: 0x25290005  addiu       $t1, $t1, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158bc0) {
            ctx->pc = 0x158DE0u;
            goto label_158de0;
        }
    }
    ctx->pc = 0x158BC8u;
    // 0x158bc8: 0x29220020  slti        $v0, $t1, 0x20
    ctx->pc = 0x158bc8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x158bcc: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x158BCCu;
    {
        const bool branch_taken_0x158bcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x158bcc) {
            ctx->pc = 0x158BD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158BCCu;
            // 0x158bd0: 0x2529ffe0  addiu       $t1, $t1, -0x20 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967264));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158BF4u;
            goto label_158bf4;
        }
    }
    ctx->pc = 0x158BD4u;
    // 0x158bd4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x158BD4u;
    {
        const bool branch_taken_0x158bd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158BD4u;
            // 0x158bd8: 0xa5140  sll         $t2, $t2, 5 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158bd4) {
            ctx->pc = 0x158C30u;
            goto label_158c30;
        }
    }
    ctx->pc = 0x158BDCu;
    // 0x158bdc: 0x0  nop
    ctx->pc = 0x158bdcu;
    // NOP
label_158be0:
    // 0x158be0: 0x25290006  addiu       $t1, $t1, 0x6
    ctx->pc = 0x158be0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 6));
    // 0x158be4: 0x29220020  slti        $v0, $t1, 0x20
    ctx->pc = 0x158be4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x158be8: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x158BE8u;
    {
        const bool branch_taken_0x158be8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x158be8) {
            ctx->pc = 0x158BECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158BE8u;
            // 0x158bec: 0xa5180  sll         $t2, $t2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 6));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158C30u;
            goto label_158c30;
        }
    }
    ctx->pc = 0x158BF0u;
    // 0x158bf0: 0x2529ffe0  addiu       $t1, $t1, -0x20
    ctx->pc = 0x158bf0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967264));
label_158bf4:
    // 0x158bf4: 0x1275004  sllv        $t2, $a3, $t1
    ctx->pc = 0x158bf4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 9) & 0x1F));
    // 0x158bf8: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x158bf8u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158bfc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158bfcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158c00: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158c00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158c04: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158c04u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158c08: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158c08u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158c0c: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x158c0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158c10: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158c10u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x158c14: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158c14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158c18: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158c18u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158c1c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158c1cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158c20: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x158c20u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x158c24: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158c24u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158c28: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158c28u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158c2c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158c2cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_158c30:
    // 0x158c30: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x158c30u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x158c34: 0x240b0035  addiu       $t3, $zero, 0x35
    ctx->pc = 0x158c34u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 53));
    // 0x158c38: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x158c38u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x158c3c: 0x29220016  slti        $v0, $t1, 0x16
    ctx->pc = 0x158c3cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)22) ? 1 : 0);
label_158c40:
    // 0x158c40: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x158C40u;
    {
        const bool branch_taken_0x158c40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158C40u;
            // 0x158c44: 0xa2d42  srl         $a1, $t2, 21 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 10), 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158c40) {
            ctx->pc = 0x158C54u;
            goto label_158c54;
        }
    }
    ctx->pc = 0x158C48u;
    // 0x158c48: 0x1691023  subu        $v0, $t3, $t1
    ctx->pc = 0x158c48u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 9)));
    // 0x158c4c: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x158c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x158c50: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x158c50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
label_158c54:
    // 0x158c54: 0x14a4001a  bne         $a1, $a0, . + 4 + (0x1A << 2)
    ctx->pc = 0x158C54u;
    {
        const bool branch_taken_0x158c54 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 4));
        ctx->pc = 0x158C58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158C54u;
            // 0x158c58: 0x24c3ffff  addiu       $v1, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158c54) {
            ctx->pc = 0x158CC0u;
            goto label_158cc0;
        }
    }
    ctx->pc = 0x158C5Cu;
    // 0x158c5c: 0x2529000b  addiu       $t1, $t1, 0xB
    ctx->pc = 0x158c5cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 11));
    // 0x158c60: 0x29220020  slti        $v0, $t1, 0x20
    ctx->pc = 0x158c60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x158c64: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x158C64u;
    {
        const bool branch_taken_0x158c64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x158c64) {
            ctx->pc = 0x158C68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158C64u;
            // 0x158c68: 0xa52c0  sll         $t2, $t2, 11 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 11));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158CACu;
            goto label_158cac;
        }
    }
    ctx->pc = 0x158C6Cu;
    // 0x158c6c: 0x2529ffe0  addiu       $t1, $t1, -0x20
    ctx->pc = 0x158c6cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967264));
    // 0x158c70: 0x1275004  sllv        $t2, $a3, $t1
    ctx->pc = 0x158c70u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 9) & 0x1F));
    // 0x158c74: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x158c74u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158c78: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158c78u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158c7c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158c7cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158c80: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158c80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158c84: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158c84u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158c88: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x158c88u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158c8c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158c8cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x158c90: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158c90u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158c94: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158c94u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158c98: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158c98u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158c9c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x158c9cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x158ca0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158ca0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158ca4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158ca4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158ca8: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158ca8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_158cac:
    // 0x158cac: 0x24c6ffdf  addiu       $a2, $a2, -0x21
    ctx->pc = 0x158cacu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967263));
    // 0x158cb0: 0x28c20022  slti        $v0, $a2, 0x22
    ctx->pc = 0x158cb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)34) ? 1 : 0);
    // 0x158cb4: 0x1040ffe2  beqz        $v0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x158CB4u;
    {
        const bool branch_taken_0x158cb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x158CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158CB4u;
            // 0x158cb8: 0x29220016  slti        $v0, $t1, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)22) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x158cb4) {
            ctx->pc = 0x158C40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_158c40;
        }
    }
    ctx->pc = 0x158CBCu;
    // 0x158cbc: 0x24c3ffff  addiu       $v1, $a2, -0x1
    ctx->pc = 0x158cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_158cc0:
    // 0x158cc0: 0x2c630021  sltiu       $v1, $v1, 0x21
    ctx->pc = 0x158cc0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)33) ? 1 : 0);
    // 0x158cc4: 0x1060004f  beqz        $v1, . + 4 + (0x4F << 2)
    ctx->pc = 0x158CC4u;
    {
        const bool branch_taken_0x158cc4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x158CC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158CC4u;
            // 0x158cc8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158cc4) {
            ctx->pc = 0x158E04u;
            goto label_158e04;
        }
    }
    ctx->pc = 0x158CCCu;
    // 0x158ccc: 0x61040  sll         $v0, $a2, 1
    ctx->pc = 0x158cccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x158cd0: 0x24030020  addiu       $v1, $zero, 0x20
    ctx->pc = 0x158cd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x158cd4: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x158cd4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x158cd8: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x158cd8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x158cdc: 0x84c6d878  lh          $a2, -0x2788($a2)
    ctx->pc = 0x158cdcu;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 4294957176)));
    // 0x158ce0: 0x30c400ff  andi        $a0, $a2, 0xFF
    ctx->pc = 0x158ce0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x158ce4: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x158ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x158ce8: 0x123102a  slt         $v0, $t1, $v1
    ctx->pc = 0x158ce8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x158cec: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x158CECu;
    {
        const bool branch_taken_0x158cec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158CF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158CECu;
            // 0x158cf0: 0x6a2806  srlv        $a1, $t2, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 3) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158cec) {
            ctx->pc = 0x158D58u;
            goto label_158d58;
        }
    }
    ctx->pc = 0x158CF4u;
    // 0x158cf4: 0x1241021  addu        $v0, $t1, $a0
    ctx->pc = 0x158cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
    // 0x158cf8: 0x2449ffe0  addiu       $t1, $v0, -0x20
    ctx->pc = 0x158cf8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
    // 0x158cfc: 0x51200006  beql        $t1, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x158CFCu;
    {
        const bool branch_taken_0x158cfc = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x158cfc) {
            ctx->pc = 0x158D00u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158CFCu;
            // 0x158d00: 0xe0502d  daddu       $t2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158D18u;
            goto label_158d18;
        }
    }
    ctx->pc = 0x158D04u;
    // 0x158d04: 0x891023  subu        $v0, $a0, $t1
    ctx->pc = 0x158d04u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x158d08: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x158d08u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x158d0c: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x158d0cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x158d10: 0x6a2806  srlv        $a1, $t2, $v1
    ctx->pc = 0x158d10u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 3) & 0x1F));
    // 0x158d14: 0x1275004  sllv        $t2, $a3, $t1
    ctx->pc = 0x158d14u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 9) & 0x1F));
label_158d18:
    // 0x158d18: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x158d18u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158d1c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158d1cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158d20: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158d20u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158d24: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158d24u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158d28: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158d28u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158d2c: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x158d2cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158d30: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x158d30u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x158d34: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158d34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158d38: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158d38u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158d3c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x158d3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x158d40: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x158d40u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x158d44: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x158d44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x158d48: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x158d48u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x158d4c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x158D4Cu;
    {
        const bool branch_taken_0x158d4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158D4Cu;
            // 0x158d50: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158d4c) {
            ctx->pc = 0x158D60u;
            goto label_158d60;
        }
    }
    ctx->pc = 0x158D54u;
    // 0x158d54: 0x0  nop
    ctx->pc = 0x158d54u;
    // NOP
label_158d58:
    // 0x158d58: 0x8a5004  sllv        $t2, $t2, $a0
    ctx->pc = 0x158d58u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 4) & 0x1F));
    // 0x158d5c: 0x1244821  addu        $t1, $t1, $a0
    ctx->pc = 0x158d5cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
label_158d60:
    // 0x158d60: 0x61a03  sra         $v1, $a2, 8
    ctx->pc = 0x158d60u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), 8));
    // 0x158d64: 0x14a30027  bne         $a1, $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x158D64u;
    {
        const bool branch_taken_0x158d64 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x158D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158D64u;
            // 0x158d68: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158d64) {
            ctx->pc = 0x158E04u;
            goto label_158e04;
        }
    }
    ctx->pc = 0x158D6Cu;
    // 0x158d6c: 0x2922001b  slti        $v0, $t1, 0x1B
    ctx->pc = 0x158d6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x158d70: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x158D70u;
    {
        const bool branch_taken_0x158d70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158D70u;
            // 0x158d74: 0xa2e82  srl         $a1, $t2, 26 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 10), 26));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158d70) {
            ctx->pc = 0x158D88u;
            goto label_158d88;
        }
    }
    ctx->pc = 0x158D78u;
    // 0x158d78: 0x2402003a  addiu       $v0, $zero, 0x3A
    ctx->pc = 0x158d78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 58));
    // 0x158d7c: 0x491023  subu        $v0, $v0, $t1
    ctx->pc = 0x158d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x158d80: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x158d80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x158d84: 0xa22825  or          $a1, $a1, $v0
    ctx->pc = 0x158d84u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
label_158d88:
    // 0x158d88: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x158d88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x158d8c: 0x10a2000c  beq         $a1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x158D8Cu;
    {
        const bool branch_taken_0x158d8c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x158D90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158D8Cu;
            // 0x158d90: 0x2ca2000b  sltiu       $v0, $a1, 0xB (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)11) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x158d8c) {
            ctx->pc = 0x158DC0u;
            goto label_158dc0;
        }
    }
    ctx->pc = 0x158D94u;
    // 0x158d94: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x158D94u;
    {
        const bool branch_taken_0x158d94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x158d94) {
            ctx->pc = 0x158DE0u;
            goto label_158de0;
        }
    }
    ctx->pc = 0x158D9Cu;
    // 0x158d9c: 0x2ca20018  sltiu       $v0, $a1, 0x18
    ctx->pc = 0x158d9cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)24) ? 1 : 0);
    // 0x158da0: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x158DA0u;
    {
        const bool branch_taken_0x158da0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x158da0) {
            ctx->pc = 0x158DE0u;
            goto label_158de0;
        }
    }
    ctx->pc = 0x158DA8u;
    // 0x158da8: 0x2ca20016  sltiu       $v0, $a1, 0x16
    ctx->pc = 0x158da8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)22) ? 1 : 0);
    // 0x158dac: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x158DACu;
    {
        const bool branch_taken_0x158dac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x158DB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158DACu;
            // 0x158db0: 0x25290005  addiu       $t1, $t1, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158dac) {
            ctx->pc = 0x158DE0u;
            goto label_158de0;
        }
    }
    ctx->pc = 0x158DB4u;
    // 0x158db4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x158DB4u;
    {
        const bool branch_taken_0x158db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158DB4u;
            // 0x158db8: 0x29220020  slti        $v0, $t1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x158db4) {
            ctx->pc = 0x158DC8u;
            goto label_158dc8;
        }
    }
    ctx->pc = 0x158DBCu;
    // 0x158dbc: 0x0  nop
    ctx->pc = 0x158dbcu;
    // NOP
label_158dc0:
    // 0x158dc0: 0x25290006  addiu       $t1, $t1, 0x6
    ctx->pc = 0x158dc0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 6));
    // 0x158dc4: 0x29220020  slti        $v0, $t1, 0x20
    ctx->pc = 0x158dc4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)32) ? 1 : 0);
label_158dc8:
    // 0x158dc8: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x158DC8u;
    {
        const bool branch_taken_0x158dc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x158dc8) {
            ctx->pc = 0x158DCCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158DC8u;
            // 0x158dcc: 0x25220007  addiu       $v0, $t1, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 7));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158DECu;
            goto label_158dec;
        }
    }
    ctx->pc = 0x158DD0u;
    // 0x158dd0: 0x2529ffe0  addiu       $t1, $t1, -0x20
    ctx->pc = 0x158dd0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967264));
    // 0x158dd4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x158DD4u;
    {
        const bool branch_taken_0x158dd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x158DD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158DD4u;
            // 0x158dd8: 0x25080004  addiu       $t0, $t0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158dd4) {
            ctx->pc = 0x158DE8u;
            goto label_158de8;
        }
    }
    ctx->pc = 0x158DDCu;
    // 0x158ddc: 0x0  nop
    ctx->pc = 0x158ddcu;
    // NOP
label_158de0:
    // 0x158de0: 0x3e00008  jr          $ra
    ctx->pc = 0x158DE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158DE0u;
            // 0x158de4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158A10u: goto label_158a10;
            case 0x158A18u: goto label_158a18;
            case 0x158AB8u: goto label_158ab8;
            case 0x158ABCu: goto label_158abc;
            case 0x158B10u: goto label_158b10;
            case 0x158B18u: goto label_158b18;
            case 0x158B70u: goto label_158b70;
            case 0x158B78u: goto label_158b78;
            case 0x158B9Cu: goto label_158b9c;
            case 0x158BE0u: goto label_158be0;
            case 0x158BF4u: goto label_158bf4;
            case 0x158C30u: goto label_158c30;
            case 0x158C40u: goto label_158c40;
            case 0x158C54u: goto label_158c54;
            case 0x158CACu: goto label_158cac;
            case 0x158CC0u: goto label_158cc0;
            case 0x158D18u: goto label_158d18;
            case 0x158D58u: goto label_158d58;
            case 0x158D60u: goto label_158d60;
            case 0x158D88u: goto label_158d88;
            case 0x158DC0u: goto label_158dc0;
            case 0x158DC8u: goto label_158dc8;
            case 0x158DE0u: goto label_158de0;
            case 0x158DE8u: goto label_158de8;
            case 0x158DECu: goto label_158dec;
            case 0x158E04u: goto label_158e04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158DE8u;
label_158de8:
    // 0x158de8: 0x25220007  addiu       $v0, $t1, 0x7
    ctx->pc = 0x158de8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 7));
label_158dec:
    // 0x158dec: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x158decu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x158df0: 0x1021021  addu        $v0, $t0, $v0
    ctx->pc = 0x158df0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x158df4: 0x2442fff8  addiu       $v0, $v0, -0x8
    ctx->pc = 0x158df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
    // 0x158df8: 0x4c1023  subu        $v0, $v0, $t4
    ctx->pc = 0x158df8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x158dfc: 0x1a2102a  slt         $v0, $t5, $v0
    ctx->pc = 0x158dfcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x158e00: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x158e00u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_158e04:
    // 0x158e04: 0x3e00008  jr          $ra
    ctx->pc = 0x158E04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158A10u: goto label_158a10;
            case 0x158A18u: goto label_158a18;
            case 0x158AB8u: goto label_158ab8;
            case 0x158ABCu: goto label_158abc;
            case 0x158B10u: goto label_158b10;
            case 0x158B18u: goto label_158b18;
            case 0x158B70u: goto label_158b70;
            case 0x158B78u: goto label_158b78;
            case 0x158B9Cu: goto label_158b9c;
            case 0x158BE0u: goto label_158be0;
            case 0x158BF4u: goto label_158bf4;
            case 0x158C30u: goto label_158c30;
            case 0x158C40u: goto label_158c40;
            case 0x158C54u: goto label_158c54;
            case 0x158CACu: goto label_158cac;
            case 0x158CC0u: goto label_158cc0;
            case 0x158D18u: goto label_158d18;
            case 0x158D58u: goto label_158d58;
            case 0x158D60u: goto label_158d60;
            case 0x158D88u: goto label_158d88;
            case 0x158DC0u: goto label_158dc0;
            case 0x158DC8u: goto label_158dc8;
            case 0x158DE0u: goto label_158de0;
            case 0x158DE8u: goto label_158de8;
            case 0x158DECu: goto label_158dec;
            case 0x158E04u: goto label_158e04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x158E0Cu;
    // 0x158e0c: 0x0  nop
    ctx->pc = 0x158e0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
