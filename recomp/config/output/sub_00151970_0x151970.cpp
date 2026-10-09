#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00151970
// Address: 0x151970 - 0x151b60
void sub_00151970_0x151970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00151970_0x151970");
#endif

    switch (ctx->pc) {
        case 0x151a98u: goto label_151a98;
        case 0x151b24u: goto label_151b24;
        default: break;
    }

    ctx->pc = 0x151970u;

    // 0x151970: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x151970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x151974: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x151974u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151978: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x151978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15197c: 0x25460128  addiu       $a2, $t2, 0x128
    ctx->pc = 0x15197cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 10), 296));
    // 0x151980: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x151980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x151984: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x151984u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x151988: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x151988u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15198c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x15198cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151990: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x151990u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x151994: 0x2438024  and         $s0, $s2, $v1
    ctx->pc = 0x151994u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 18) & GPR_U64(ctx, 3));
    // 0x151998: 0x2502023  subu        $a0, $s2, $s0
    ctx->pc = 0x151998u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x15199c: 0x8cc204ec  lw          $v0, 0x4EC($a2)
    ctx->pc = 0x15199cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 1260)));
    // 0x1519a0: 0x488c0  sll         $s1, $a0, 3
    ctx->pc = 0x1519a0u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1519a4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1519a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1519a8: 0xacc204ec  sw          $v0, 0x4EC($a2)
    ctx->pc = 0x1519a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 1260), GPR_U32(ctx, 2));
    // 0x1519ac: 0x82080000  lb          $t0, 0x0($s0)
    ctx->pc = 0x1519acu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1519b0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1519b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1519b4: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1519b4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1519b8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1519b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1519bc: 0x92040000  lbu         $a0, 0x0($s0)
    ctx->pc = 0x1519bcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1519c0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1519c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1519c4: 0x92050000  lbu         $a1, 0x0($s0)
    ctx->pc = 0x1519c4u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1519c8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1519c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1519cc: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x1519ccu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1519d0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1519d0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1519d4: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x1519d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1519d8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1519d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1519dc: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1519dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1519e0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1519e0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1519e4: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1519e4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1519e8: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x1519e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1519ec: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x1519ecu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x1519f0: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1519f0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1519f4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1519f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1519f8: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x1519f8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1519fc: 0x1044025  or          $t0, $t0, $a0
    ctx->pc = 0x1519fcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 4));
    // 0x151a00: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151a00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151a04: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x151a04u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151a08: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x151a08u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x151a0c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151a0cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151a10: 0x1054025  or          $t0, $t0, $a1
    ctx->pc = 0x151a10u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 5));
    // 0x151a14: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151a14u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151a18: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x151a18u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151a1c: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x151A1Cu;
    {
        const bool branch_taken_0x151a1c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x151A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151A1Cu;
            // 0x151a20: 0x2284004  sllv        $t0, $t0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 17) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151a1c) {
            ctx->pc = 0x151A40u;
            goto label_151a40;
        }
    }
    ctx->pc = 0x151A24u;
    // 0x151a24: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x151a24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x151a28: 0x511023  subu        $v0, $v0, $s1
    ctx->pc = 0x151a28u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x151a2c: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x151a30: 0x1021025  or          $v0, $t0, $v0
    ctx->pc = 0x151a30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x151a34: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x151a34u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x151a38: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x151A38u;
    {
        const bool branch_taken_0x151a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151A38u;
            // 0x151a3c: 0xacc20030  sw          $v0, 0x30($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151a38) {
            ctx->pc = 0x151A48u;
            goto label_151a48;
        }
    }
    ctx->pc = 0x151A40u;
label_151a40:
    // 0x151a40: 0xacc80030  sw          $t0, 0x30($a2)
    ctx->pc = 0x151a40u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 8));
    // 0x151a44: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x151a44u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_151a48:
    // 0x151a48: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x151a48u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151a4c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151a4cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151a50: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151a50u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151a54: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151a54u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151a58: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151a58u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151a5c: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x151a5cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151a60: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x151a60u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151a64: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151a64u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151a68: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151a68u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151a6c: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151a6cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151a70: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x151a70u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151a74: 0x3c04000f  lui         $a0, 0xF
    ctx->pc = 0x151a74u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)15 << 16));
    // 0x151a78: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151a78u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151a7c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151a7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151a80: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x151a80u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151a84: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x151a84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151a88: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x151a88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x151a8c: 0x24090028  addiu       $t1, $zero, 0x28
    ctx->pc = 0x151a8cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x151a90: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x151A90u;
    {
        const bool branch_taken_0x151a90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x151A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151A90u;
            // 0x151a94: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151a90) {
            ctx->pc = 0x151AE4u;
            goto label_151ae4;
        }
    }
    ctx->pc = 0x151A98u;
label_151a98:
    // 0x151a98: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x151a98u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x151a9c: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x151A9Cu;
    {
        const bool branch_taken_0x151a9c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151AA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151A9Cu;
            // 0x151aa0: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151a9c) {
            ctx->pc = 0x151AE4u;
            goto label_151ae4;
        }
    }
    ctx->pc = 0x151AA4u;
    // 0x151aa4: 0x2631ffe0  addiu       $s1, $s1, -0x20
    ctx->pc = 0x151aa4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967264));
    // 0x151aa8: 0x2274004  sllv        $t0, $a3, $s1
    ctx->pc = 0x151aa8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 17) & 0x1F));
    // 0x151aac: 0x82070000  lb          $a3, 0x0($s0)
    ctx->pc = 0x151aacu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151ab0: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151ab0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151ab4: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151ab4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151ab8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151ab8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151abc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151abcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151ac0: 0x92030000  lbu         $v1, 0x0($s0)
    ctx->pc = 0x151ac0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151ac4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x151ac4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x151ac8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151ac8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151acc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151accu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151ad0: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x151ad0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x151ad4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x151ad4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x151ad8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x151ad8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x151adc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x151adcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x151ae0: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x151ae0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_151ae4:
    // 0x151ae4: 0x86102a  slt         $v0, $a0, $a2
    ctx->pc = 0x151ae4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x151ae8: 0x5440000b  bnel        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x151AE8u;
    {
        const bool branch_taken_0x151ae8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x151ae8) {
            ctx->pc = 0x151AECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151AE8u;
            // 0x151aec: 0x140202d  daddu       $a0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x151B18u;
            goto label_151b18;
        }
    }
    ctx->pc = 0x151AF0u;
    // 0x151af0: 0x2a220009  slti        $v0, $s1, 0x9
    ctx->pc = 0x151af0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x151af4: 0x81a02  srl         $v1, $t0, 8
    ctx->pc = 0x151af4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), 8));
    // 0x151af8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x151AF8u;
    {
        const bool branch_taken_0x151af8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x151AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151AF8u;
            // 0x151afc: 0x84200  sll         $t0, $t0, 8 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151af8) {
            ctx->pc = 0x151B0Cu;
            goto label_151b0c;
        }
    }
    ctx->pc = 0x151B00u;
    // 0x151b00: 0x1311023  subu        $v0, $t1, $s1
    ctx->pc = 0x151b00u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 17)));
    // 0x151b04: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x151b04u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x151b08: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x151b08u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
label_151b0c:
    // 0x151b0c: 0x5465ffe2  bnel        $v1, $a1, . + 4 + (-0x1E << 2)
    ctx->pc = 0x151B0Cu;
    {
        const bool branch_taken_0x151b0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        if (branch_taken_0x151b0c) {
            ctx->pc = 0x151B10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151B0Cu;
            // 0x151b10: 0x26310008  addiu       $s1, $s1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x151A98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_151a98;
        }
    }
    ctx->pc = 0x151B14u;
    // 0x151b14: 0x140202d  daddu       $a0, $t2, $zero
    ctx->pc = 0x151b14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_151b18:
    // 0x151b18: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x151b18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x151b1c: 0xc0546d8  jal         func_151B60
    ctx->pc = 0x151B1Cu;
    SET_GPR_U32(ctx, 31, 0x151B24u);
    ctx->pc = 0x151B20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x151B1Cu;
            // 0x151b20: 0x24c60004  addiu       $a2, $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x151B60u;
    if (runtime->hasFunction(0x151B60u)) {
        auto targetFn = runtime->lookupFunction(0x151B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151B24u; }
        if (ctx->pc != 0x151B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00151B60_0x151b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x151B24u; }
        if (ctx->pc != 0x151B24u) { return; }
    }
    ctx->pc = 0x151B24u;
label_151b24:
    // 0x151b24: 0x2121823  subu        $v1, $s0, $s2
    ctx->pc = 0x151b24u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x151b28: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x151b28u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x151b2c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x151b2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x151b30: 0x2231821  addu        $v1, $s1, $v1
    ctx->pc = 0x151b30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x151b34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x151b34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x151b38: 0x2462ffc7  addiu       $v0, $v1, -0x39
    ctx->pc = 0x151b38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967239));
    // 0x151b3c: 0x2463ffce  addiu       $v1, $v1, -0x32
    ctx->pc = 0x151b3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967246));
    // 0x151b40: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x151b40u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x151b44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x151b44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x151b48: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x151b48u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x151b4c: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x151b4cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x151b50: 0x2421021  addu        $v0, $s2, $v0
    ctx->pc = 0x151b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x151b54: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x151b54u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x151b58: 0x3e00008  jr          $ra
    ctx->pc = 0x151B58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x151B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151B58u;
            // 0x151b5c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x151A40u: goto label_151a40;
            case 0x151A48u: goto label_151a48;
            case 0x151A98u: goto label_151a98;
            case 0x151AE4u: goto label_151ae4;
            case 0x151B0Cu: goto label_151b0c;
            case 0x151B18u: goto label_151b18;
            case 0x151B24u: goto label_151b24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x151B60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
