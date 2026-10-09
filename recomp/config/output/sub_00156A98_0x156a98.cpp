#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00156A98
// Address: 0x156a98 - 0x1570d8
void sub_00156A98_0x156a98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00156A98_0x156a98");
#endif

    switch (ctx->pc) {
        case 0x157030u: goto label_157030;
        case 0x1570a0u: goto label_1570a0;
        case 0x1570b0u: goto label_1570b0;
        default: break;
    }

    ctx->pc = 0x156a98u;

    // 0x156a98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x156a98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x156a9c: 0xa0582d  daddu       $t3, $a1, $zero
    ctx->pc = 0x156a9cu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156aa0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x156aa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x156aa4: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x156aa4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156aa8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x156aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x156aac: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x156aacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x156ab0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x156ab0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x156ab4: 0x25620004  addiu       $v0, $t3, 0x4
    ctx->pc = 0x156ab4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 11), 4));
    // 0x156ab8: 0x434024  and         $t0, $v0, $v1
    ctx->pc = 0x156ab8u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x156abc: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x156abcu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156ac0: 0x1681823  subu        $v1, $t3, $t0
    ctx->pc = 0x156ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 11), GPR_U32(ctx, 8)));
    // 0x156ac4: 0x81090000  lb          $t1, 0x0($t0)
    ctx->pc = 0x156ac4u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ac8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156ac8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156acc: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x156accu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x156ad0: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x156ad0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ad4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156ad4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ad8: 0x91050000  lbu         $a1, 0x0($t0)
    ctx->pc = 0x156ad8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156adc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156adcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ae0: 0x91060000  lbu         $a2, 0x0($t0)
    ctx->pc = 0x156ae0u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ae4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156ae4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ae8: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156ae8u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156aec: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156aecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156af0: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156af0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156af4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156af4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156af8: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x156af8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x156afc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156afcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156b00: 0x1244825  or          $t1, $t1, $a0
    ctx->pc = 0x156b00u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 4));
    // 0x156b04: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x156b04u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156b08: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156b08u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156b0c: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x156b0cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x156b10: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156b10u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156b14: 0x1254825  or          $t1, $t1, $a1
    ctx->pc = 0x156b14u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 5));
    // 0x156b18: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156b18u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156b1c: 0x94a00  sll         $t1, $t1, 8
    ctx->pc = 0x156b1cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
    // 0x156b20: 0x328c0  sll         $a1, $v1, 3
    ctx->pc = 0x156b20u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x156b24: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156b24u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156b28: 0xe43825  or          $a3, $a3, $a0
    ctx->pc = 0x156b28u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 4));
    // 0x156b2c: 0x1264825  or          $t1, $t1, $a2
    ctx->pc = 0x156b2cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 6));
    // 0x156b30: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156b30u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156b34: 0x28a20010  slti        $v0, $a1, 0x10
    ctx->pc = 0x156b34u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x156b38: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156b38u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156b3c: 0xa94804  sllv        $t1, $t1, $a1
    ctx->pc = 0x156b3cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 5) & 0x1F));
    // 0x156b40: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x156B40u;
    {
        const bool branch_taken_0x156b40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x156B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156B40u;
            // 0x156b44: 0x25080001  addiu       $t0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156b40) {
            ctx->pc = 0x156BB8u;
            goto label_156bb8;
        }
    }
    ctx->pc = 0x156B48u;
    // 0x156b48: 0x24a5fff0  addiu       $a1, $a1, -0x10
    ctx->pc = 0x156b48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967280));
    // 0x156b4c: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x156B4Cu;
    {
        const bool branch_taken_0x156b4c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x156B50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156B4Cu;
            // 0x156b50: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156b4c) {
            ctx->pc = 0x156B70u;
            goto label_156b70;
        }
    }
    ctx->pc = 0x156B54u;
    // 0x156b54: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x156b54u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x156b58: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x156b58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x156b5c: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x156b5cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x156b60: 0x91c02  srl         $v1, $t1, 16
    ctx->pc = 0x156b60u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x156b64: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x156b64u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x156b68: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x156B68u;
    {
        const bool branch_taken_0x156b68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156B6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156B68u;
            // 0x156b6c: 0xad430000  sw          $v1, 0x0($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156b68) {
            ctx->pc = 0x156B7Cu;
            goto label_156b7c;
        }
    }
    ctx->pc = 0x156B70u;
label_156b70:
    // 0x156b70: 0x91402  srl         $v0, $t1, 16
    ctx->pc = 0x156b70u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x156b74: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x156b74u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156b78: 0xad420000  sw          $v0, 0x0($t2)
    ctx->pc = 0x156b78u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 2));
label_156b7c:
    // 0x156b7c: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156b7cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156b80: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156b80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156b84: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156b84u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156b88: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156b88u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156b8c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156b8cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156b90: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156b90u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156b94: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156b94u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156b98: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156b98u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156b9c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156b9cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156ba0: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156ba0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ba4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156ba4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156ba8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156ba8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156bac: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156bacu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156bb0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x156BB0u;
    {
        const bool branch_taken_0x156bb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156BB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156BB0u;
            // 0x156bb4: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156bb0) {
            ctx->pc = 0x156BC8u;
            goto label_156bc8;
        }
    }
    ctx->pc = 0x156BB8u;
label_156bb8:
    // 0x156bb8: 0x91402  srl         $v0, $t1, 16
    ctx->pc = 0x156bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x156bbc: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x156bbcu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x156bc0: 0xad420000  sw          $v0, 0x0($t2)
    ctx->pc = 0x156bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 2));
    // 0x156bc4: 0x24a50010  addiu       $a1, $a1, 0x10
    ctx->pc = 0x156bc4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
label_156bc8:
    // 0x156bc8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156bc8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156bcc: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x156bccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x156bd0: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x156BD0u;
    {
        const bool branch_taken_0x156bd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x156bd0) {
            ctx->pc = 0x156BD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x156BD0u;
            // 0x156bd4: 0x94840  sll         $t1, $t1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x156C18u;
            goto label_156c18;
        }
    }
    ctx->pc = 0x156BD8u;
    // 0x156bd8: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x156bd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x156bdc: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x156bdcu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x156be0: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156be0u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156be4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156be4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156be8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156be8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156bec: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156becu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156bf0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156bf0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156bf4: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156bf4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156bf8: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156bf8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156bfc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156bfcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156c00: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156c00u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156c04: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156c04u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156c08: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156c08u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156c0c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156c0cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156c10: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156c10u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156c14: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156c14u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_156c18:
    // 0x156c18: 0x28a2000a  slti        $v0, $a1, 0xA
    ctx->pc = 0x156c18u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x156c1c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x156C1Cu;
    {
        const bool branch_taken_0x156c1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x156C20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156C1Cu;
            // 0x156c20: 0x91282  srl         $v0, $t1, 10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156c1c) {
            ctx->pc = 0x156C98u;
            goto label_156c98;
        }
    }
    ctx->pc = 0x156C24u;
    // 0x156c24: 0x24a5fff6  addiu       $a1, $a1, -0xA
    ctx->pc = 0x156c24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967286));
    // 0x156c28: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x156C28u;
    {
        const bool branch_taken_0x156c28 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x156C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156C28u;
            // 0x156c2c: 0x24020016  addiu       $v0, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156c28) {
            ctx->pc = 0x156C50u;
            goto label_156c50;
        }
    }
    ctx->pc = 0x156C30u;
    // 0x156c30: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x156c30u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x156c34: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x156c34u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x156c38: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x156c38u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x156c3c: 0x91a82  srl         $v1, $t1, 10
    ctx->pc = 0x156c3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 10));
    // 0x156c40: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x156c40u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x156c44: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x156C44u;
    {
        const bool branch_taken_0x156c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156C44u;
            // 0x156c48: 0xad430004  sw          $v1, 0x4($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156c44) {
            ctx->pc = 0x156C5Cu;
            goto label_156c5c;
        }
    }
    ctx->pc = 0x156C4Cu;
    // 0x156c4c: 0x0  nop
    ctx->pc = 0x156c4cu;
    // NOP
label_156c50:
    // 0x156c50: 0x91282  srl         $v0, $t1, 10
    ctx->pc = 0x156c50u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 10));
    // 0x156c54: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x156c54u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156c58: 0xad420004  sw          $v0, 0x4($t2)
    ctx->pc = 0x156c58u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 4), GPR_U32(ctx, 2));
label_156c5c:
    // 0x156c5c: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156c5cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156c60: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156c60u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156c64: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156c64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156c68: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156c68u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156c6c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156c6cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156c70: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156c70u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156c74: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156c74u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156c78: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156c78u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156c7c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156c7cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156c80: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156c80u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156c84: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156c84u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156c88: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156c88u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156c8c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156c8cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156c90: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x156C90u;
    {
        const bool branch_taken_0x156c90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156C90u;
            // 0x156c94: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156c90) {
            ctx->pc = 0x156CA4u;
            goto label_156ca4;
        }
    }
    ctx->pc = 0x156C98u;
label_156c98:
    // 0x156c98: 0x94d80  sll         $t1, $t1, 22
    ctx->pc = 0x156c98u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 22));
    // 0x156c9c: 0xad420004  sw          $v0, 0x4($t2)
    ctx->pc = 0x156c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 10), 4), GPR_U32(ctx, 2));
    // 0x156ca0: 0x24a50016  addiu       $a1, $a1, 0x16
    ctx->pc = 0x156ca0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22));
label_156ca4:
    // 0x156ca4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156ca4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156ca8: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x156ca8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x156cac: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x156CACu;
    {
        const bool branch_taken_0x156cac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x156cac) {
            ctx->pc = 0x156CB0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x156CACu;
            // 0x156cb0: 0x94840  sll         $t1, $t1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x156CF4u;
            goto label_156cf4;
        }
    }
    ctx->pc = 0x156CB4u;
    // 0x156cb4: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x156cb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x156cb8: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x156cb8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x156cbc: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156cbcu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156cc0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156cc0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156cc4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156cc4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156cc8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156cc8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ccc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156cccu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156cd0: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156cd0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156cd4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156cd4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156cd8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156cd8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156cdc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156cdcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156ce0: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156ce0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ce4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156ce4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156ce8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156ce8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156cec: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156cecu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156cf0: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156cf0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_156cf4:
    // 0x156cf4: 0x28a2001a  slti        $v0, $a1, 0x1A
    ctx->pc = 0x156cf4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)26) ? 1 : 0);
    // 0x156cf8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x156CF8u;
    {
        const bool branch_taken_0x156cf8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x156CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156CF8u;
            // 0x156cfc: 0x91682  srl         $v0, $t1, 26 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 26));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156cf8) {
            ctx->pc = 0x156D70u;
            goto label_156d70;
        }
    }
    ctx->pc = 0x156D00u;
    // 0x156d00: 0x24a5ffe6  addiu       $a1, $a1, -0x1A
    ctx->pc = 0x156d00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967270));
    // 0x156d04: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x156D04u;
    {
        const bool branch_taken_0x156d04 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x156D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156D04u;
            // 0x156d08: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156d04) {
            ctx->pc = 0x156D28u;
            goto label_156d28;
        }
    }
    ctx->pc = 0x156D0Cu;
    // 0x156d0c: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x156d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x156d10: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x156d10u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x156d14: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x156d14u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x156d18: 0x91e82  srl         $v1, $t1, 26
    ctx->pc = 0x156d18u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 26));
    // 0x156d1c: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x156d1cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x156d20: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x156D20u;
    {
        const bool branch_taken_0x156d20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156D20u;
            // 0x156d24: 0xad430008  sw          $v1, 0x8($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156d20) {
            ctx->pc = 0x156D34u;
            goto label_156d34;
        }
    }
    ctx->pc = 0x156D28u;
label_156d28:
    // 0x156d28: 0x91682  srl         $v0, $t1, 26
    ctx->pc = 0x156d28u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 26));
    // 0x156d2c: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x156d2cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156d30: 0xad420008  sw          $v0, 0x8($t2)
    ctx->pc = 0x156d30u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 8), GPR_U32(ctx, 2));
label_156d34:
    // 0x156d34: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156d34u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156d38: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156d38u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156d3c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156d3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156d40: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156d40u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156d44: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156d44u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156d48: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156d48u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156d4c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156d4cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156d50: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156d50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156d54: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156d54u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156d58: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156d58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156d5c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156d5cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156d60: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156d60u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156d64: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156d64u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156d68: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x156D68u;
    {
        const bool branch_taken_0x156d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156D68u;
            // 0x156d6c: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156d68) {
            ctx->pc = 0x156D7Cu;
            goto label_156d7c;
        }
    }
    ctx->pc = 0x156D70u;
label_156d70:
    // 0x156d70: 0x94980  sll         $t1, $t1, 6
    ctx->pc = 0x156d70u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 6));
    // 0x156d74: 0xad420008  sw          $v0, 0x8($t2)
    ctx->pc = 0x156d74u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 8), GPR_U32(ctx, 2));
    // 0x156d78: 0x24a50006  addiu       $a1, $a1, 0x6
    ctx->pc = 0x156d78u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6));
label_156d7c:
    // 0x156d7c: 0x917c2  srl         $v0, $t1, 31
    ctx->pc = 0x156d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x156d80: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x156d80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x156d84: 0x14a30012  bne         $a1, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x156D84u;
    {
        const bool branch_taken_0x156d84 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x156D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156D84u;
            // 0x156d88: 0xad420010  sw          $v0, 0x10($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156d84) {
            ctx->pc = 0x156DD0u;
            goto label_156dd0;
        }
    }
    ctx->pc = 0x156D8Cu;
    // 0x156d8c: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x156d8cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156d90: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156d90u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156d94: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156d94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156d98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x156d98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156d9c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156d9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156da0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156da0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156da4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156da4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156da8: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156da8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156dac: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156dacu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156db0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156db0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156db4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156db4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156db8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156db8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156dbc: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156dbcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156dc0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156dc0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156dc4: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156dc4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156dc8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x156DC8u;
    {
        const bool branch_taken_0x156dc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156DC8u;
            // 0x156dcc: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156dc8) {
            ctx->pc = 0x156DD8u;
            goto label_156dd8;
        }
    }
    ctx->pc = 0x156DD0u;
label_156dd0:
    // 0x156dd0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156dd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156dd4: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x156dd4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
label_156dd8:
    // 0x156dd8: 0x917c2  srl         $v0, $t1, 31
    ctx->pc = 0x156dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x156ddc: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x156ddcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x156de0: 0x14a30013  bne         $a1, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x156DE0u;
    {
        const bool branch_taken_0x156de0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x156DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156DE0u;
            // 0x156de4: 0xad420014  sw          $v0, 0x14($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156de0) {
            ctx->pc = 0x156E30u;
            goto label_156e30;
        }
    }
    ctx->pc = 0x156DE8u;
    // 0x156de8: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x156de8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156dec: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156decu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156df0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156df0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156df4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x156df4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156df8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156df8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156dfc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156dfcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156e00: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156e00u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156e04: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156e04u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156e08: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156e08u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156e0c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156e0cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156e10: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156e10u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156e14: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156e14u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156e18: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156e18u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156e1c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156e1cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156e20: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156e20u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156e24: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x156E24u;
    {
        const bool branch_taken_0x156e24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156E24u;
            // 0x156e28: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156e24) {
            ctx->pc = 0x156E38u;
            goto label_156e38;
        }
    }
    ctx->pc = 0x156E2Cu;
    // 0x156e2c: 0x0  nop
    ctx->pc = 0x156e2cu;
    // NOP
label_156e30:
    // 0x156e30: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156e30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156e34: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x156e34u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
label_156e38:
    // 0x156e38: 0x917c2  srl         $v0, $t1, 31
    ctx->pc = 0x156e38u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x156e3c: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x156e3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x156e40: 0x14a30013  bne         $a1, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x156E40u;
    {
        const bool branch_taken_0x156e40 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x156E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156E40u;
            // 0x156e44: 0xad420018  sw          $v0, 0x18($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156e40) {
            ctx->pc = 0x156E90u;
            goto label_156e90;
        }
    }
    ctx->pc = 0x156E48u;
    // 0x156e48: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x156e48u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156e4c: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156e4cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156e50: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156e50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156e54: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x156e54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156e58: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156e58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156e5c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156e5cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156e60: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156e60u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156e64: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156e64u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156e68: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156e68u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156e6c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156e6cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156e70: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156e70u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156e74: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156e74u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156e78: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156e78u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156e7c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156e7cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156e80: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156e80u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156e84: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x156E84u;
    {
        const bool branch_taken_0x156e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156E88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156E84u;
            // 0x156e88: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156e84) {
            ctx->pc = 0x156E98u;
            goto label_156e98;
        }
    }
    ctx->pc = 0x156E8Cu;
    // 0x156e8c: 0x0  nop
    ctx->pc = 0x156e8cu;
    // NOP
label_156e90:
    // 0x156e90: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156e90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156e94: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x156e94u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
label_156e98:
    // 0x156e98: 0x917c2  srl         $v0, $t1, 31
    ctx->pc = 0x156e98u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 31));
    // 0x156e9c: 0x2403001f  addiu       $v1, $zero, 0x1F
    ctx->pc = 0x156e9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x156ea0: 0x14a30013  bne         $a1, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x156EA0u;
    {
        const bool branch_taken_0x156ea0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        ctx->pc = 0x156EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156EA0u;
            // 0x156ea4: 0xad42001c  sw          $v0, 0x1C($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156ea0) {
            ctx->pc = 0x156EF0u;
            goto label_156ef0;
        }
    }
    ctx->pc = 0x156EA8u;
    // 0x156ea8: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x156ea8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156eac: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156eacu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156eb0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156eb0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156eb4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x156eb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156eb8: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156eb8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ebc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156ebcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ec0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156ec0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156ec4: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156ec4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ec8: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156ec8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156ecc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156eccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ed0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156ed0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156ed4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156ed4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ed8: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156ed8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156edc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156edcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ee0: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156ee0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156ee4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x156EE4u;
    {
        const bool branch_taken_0x156ee4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156EE4u;
            // 0x156ee8: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156ee4) {
            ctx->pc = 0x156EF8u;
            goto label_156ef8;
        }
    }
    ctx->pc = 0x156EECu;
    // 0x156eec: 0x0  nop
    ctx->pc = 0x156eecu;
    // NOP
label_156ef0:
    // 0x156ef0: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156ef0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156ef4: 0x94840  sll         $t1, $t1, 1
    ctx->pc = 0x156ef4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
label_156ef8:
    // 0x156ef8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x156ef8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x156efc: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x156efcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x156f00: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x156F00u;
    {
        const bool branch_taken_0x156f00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x156f00) {
            ctx->pc = 0x156F04u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x156F00u;
            // 0x156f04: 0x94840  sll         $t1, $t1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x156F48u;
            goto label_156f48;
        }
    }
    ctx->pc = 0x156F08u;
    // 0x156f08: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x156f08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x156f0c: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x156f0cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x156f10: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156f10u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156f14: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156f14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156f18: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156f18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156f1c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156f1cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156f20: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156f20u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156f24: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156f24u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156f28: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156f28u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156f2c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156f2cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156f30: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156f30u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156f34: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156f34u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156f38: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156f38u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156f3c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156f3cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156f40: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156f40u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156f44: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156f44u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_156f48:
    // 0x156f48: 0x28a2001b  slti        $v0, $a1, 0x1B
    ctx->pc = 0x156f48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)27) ? 1 : 0);
    // 0x156f4c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x156F4Cu;
    {
        const bool branch_taken_0x156f4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x156F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156F4Cu;
            // 0x156f50: 0x916c2  srl         $v0, $t1, 27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 27));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156f4c) {
            ctx->pc = 0x156FC8u;
            goto label_156fc8;
        }
    }
    ctx->pc = 0x156F54u;
    // 0x156f54: 0x24a5ffe5  addiu       $a1, $a1, -0x1B
    ctx->pc = 0x156f54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967269));
    // 0x156f58: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x156F58u;
    {
        const bool branch_taken_0x156f58 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x156F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156F58u;
            // 0x156f5c: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156f58) {
            ctx->pc = 0x156F80u;
            goto label_156f80;
        }
    }
    ctx->pc = 0x156F60u;
    // 0x156f60: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x156f60u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x156f64: 0x471006  srlv        $v0, $a3, $v0
    ctx->pc = 0x156f64u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 7), GPR_U32(ctx, 2) & 0x1F));
    // 0x156f68: 0x1224825  or          $t1, $t1, $v0
    ctx->pc = 0x156f68u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | GPR_U64(ctx, 2));
    // 0x156f6c: 0x91ec2  srl         $v1, $t1, 27
    ctx->pc = 0x156f6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 27));
    // 0x156f70: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x156f70u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x156f74: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x156F74u;
    {
        const bool branch_taken_0x156f74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156F74u;
            // 0x156f78: 0xad43000c  sw          $v1, 0xC($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156f74) {
            ctx->pc = 0x156F8Cu;
            goto label_156f8c;
        }
    }
    ctx->pc = 0x156F7Cu;
    // 0x156f7c: 0x0  nop
    ctx->pc = 0x156f7cu;
    // NOP
label_156f80:
    // 0x156f80: 0x916c2  srl         $v0, $t1, 27
    ctx->pc = 0x156f80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), 27));
    // 0x156f84: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x156f84u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x156f88: 0xad42000c  sw          $v0, 0xC($t2)
    ctx->pc = 0x156f88u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 12), GPR_U32(ctx, 2));
label_156f8c:
    // 0x156f8c: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156f8cu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156f90: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156f90u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156f94: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156f94u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156f98: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156f98u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156f9c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156f9cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156fa0: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x156fa0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156fa4: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x156fa4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x156fa8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156fa8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156fac: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156facu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156fb0: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156fb0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156fb4: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x156fb4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x156fb8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156fb8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156fbc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156fbcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x156fc0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x156FC0u;
    {
        const bool branch_taken_0x156fc0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x156FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156FC0u;
            // 0x156fc4: 0xe23825  or          $a3, $a3, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156fc0) {
            ctx->pc = 0x156FD4u;
            goto label_156fd4;
        }
    }
    ctx->pc = 0x156FC8u;
label_156fc8:
    // 0x156fc8: 0x94940  sll         $t1, $t1, 5
    ctx->pc = 0x156fc8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 5));
    // 0x156fcc: 0xad42000c  sw          $v0, 0xC($t2)
    ctx->pc = 0x156fccu;
    WRITE32(ADD32(GPR_U32(ctx, 10), 12), GPR_U32(ctx, 2));
    // 0x156fd0: 0x24a50005  addiu       $a1, $a1, 0x5
    ctx->pc = 0x156fd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5));
label_156fd4:
    // 0x156fd4: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x156fd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x156fd8: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x156fd8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x156fdc: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x156FDCu;
    {
        const bool branch_taken_0x156fdc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x156fdc) {
            ctx->pc = 0x156FE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x156FDCu;
            // 0x156fe0: 0x94a00  sll         $t1, $t1, 8 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157024u;
            goto label_157024;
        }
    }
    ctx->pc = 0x156FE4u;
    // 0x156fe4: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x156fe4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x156fe8: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x156fe8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x156fec: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x156fecu;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ff0: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156ff0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ff4: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x156ff4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x156ff8: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x156ff8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x156ffc: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x156ffcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x157000: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x157000u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x157004: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x157004u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x157008: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x157008u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15700c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15700cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x157010: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x157010u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x157014: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x157014u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x157018: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x157018u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15701c: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x15701cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x157020: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x157020u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_157024:
    // 0x157024: 0x5210018  bgez        $t1, . + 4 + (0x18 << 2)
    ctx->pc = 0x157024u;
    {
        const bool branch_taken_0x157024 = (GPR_S64(ctx, 9) >= 0);
        ctx->pc = 0x157028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157024u;
            // 0x157028: 0x24a20007  addiu       $v0, $a1, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157024) {
            ctx->pc = 0x157088u;
            goto label_157088;
        }
    }
    ctx->pc = 0x15702Cu;
    // 0x15702c: 0x24a50018  addiu       $a1, $a1, 0x18
    ctx->pc = 0x15702cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24));
label_157030:
    // 0x157030: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157030u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157034: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157034u;
    {
        const bool branch_taken_0x157034 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157034) {
            ctx->pc = 0x157038u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157034u;
            // 0x157038: 0x94e00  sll         $t1, $t1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 24));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15707Cu;
            goto label_15707c;
        }
    }
    ctx->pc = 0x15703Cu;
    // 0x15703c: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x15703cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157040: 0xa74804  sllv        $t1, $a3, $a1
    ctx->pc = 0x157040u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 7), GPR_U32(ctx, 5) & 0x1F));
    // 0x157044: 0x81070000  lb          $a3, 0x0($t0)
    ctx->pc = 0x157044u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x157048: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x157048u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x15704c: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x15704cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x157050: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x157050u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x157054: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x157054u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x157058: 0x91030000  lbu         $v1, 0x0($t0)
    ctx->pc = 0x157058u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15705c: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x15705cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
    // 0x157060: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x157060u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x157064: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x157064u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x157068: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x157068u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x15706c: 0xe33825  or          $a3, $a3, $v1
    ctx->pc = 0x15706cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x157070: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x157070u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x157074: 0x73a00  sll         $a3, $a3, 8
    ctx->pc = 0x157074u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x157078: 0xe23825  or          $a3, $a3, $v0
    ctx->pc = 0x157078u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | GPR_U64(ctx, 2));
label_15707c:
    // 0x15707c: 0x522ffec  bltzl       $t1, . + 4 + (-0x14 << 2)
    ctx->pc = 0x15707Cu;
    {
        const bool branch_taken_0x15707c = (GPR_S64(ctx, 9) < 0);
        if (branch_taken_0x15707c) {
            ctx->pc = 0x157080u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15707Cu;
            // 0x157080: 0x24a50018  addiu       $a1, $a1, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157030u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_157030;
        }
    }
    ctx->pc = 0x157084u;
    // 0x157084: 0x24a20007  addiu       $v0, $a1, 0x7
    ctx->pc = 0x157084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
label_157088:
    // 0x157088: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x157088u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x15708c: 0x1028021  addu        $s0, $t0, $v0
    ctx->pc = 0x15708cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x157090: 0x2604fff8  addiu       $a0, $s0, -0x8
    ctx->pc = 0x157090u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967288));
    // 0x157094: 0x8b1023  subu        $v0, $a0, $t3
    ctx->pc = 0x157094u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x157098: 0xc055f50  jal         func_157D40
    ctx->pc = 0x157098u;
    SET_GPR_U32(ctx, 31, 0x1570A0u);
    ctx->pc = 0x15709Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x157098u;
            // 0x15709c: 0xae220000  sw          $v0, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x157D40u;
    if (runtime->hasFunction(0x157D40u)) {
        auto targetFn = runtime->lookupFunction(0x157D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1570A0u; }
        if (ctx->pc != 0x1570A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157D40_0x157d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1570A0u; }
        if (ctx->pc != 0x1570A0u) { return; }
    }
    ctx->pc = 0x1570A0u;
label_1570a0:
    // 0x1570a0: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1570A0u;
    {
        const bool branch_taken_0x1570a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1570a0) {
            ctx->pc = 0x1570A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1570A0u;
            // 0x1570a4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1570C8u;
            goto label_1570c8;
        }
    }
    ctx->pc = 0x1570A8u;
    // 0x1570a8: 0xc055f50  jal         func_157D40
    ctx->pc = 0x1570A8u;
    SET_GPR_U32(ctx, 31, 0x1570B0u);
    ctx->pc = 0x1570ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1570A8u;
            // 0x1570ac: 0x2604fff9  addiu       $a0, $s0, -0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967289));
        ctx->in_delay_slot = false;
    ctx->pc = 0x157D40u;
    if (runtime->hasFunction(0x157D40u)) {
        auto targetFn = runtime->lookupFunction(0x157D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1570B0u; }
        if (ctx->pc != 0x1570B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157D40_0x157d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1570B0u; }
        if (ctx->pc != 0x1570B0u) { return; }
    }
    ctx->pc = 0x1570B0u;
label_1570b0:
    // 0x1570b0: 0x3c030004  lui         $v1, 0x4
    ctx->pc = 0x1570b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4 << 16));
    // 0x1570b4: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1570B4u;
    {
        const bool branch_taken_0x1570b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1570B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1570B4u;
            // 0x1570b8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1570b4) {
            ctx->pc = 0x1570C8u;
            goto label_1570c8;
        }
    }
    ctx->pc = 0x1570BCu;
    // 0x1570bc: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1570bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1570c0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1570c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1570c4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1570c4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_1570c8:
    // 0x1570c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1570c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1570cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1570ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1570d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1570D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1570D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1570D0u;
            // 0x1570d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x156B70u: goto label_156b70;
            case 0x156B7Cu: goto label_156b7c;
            case 0x156BB8u: goto label_156bb8;
            case 0x156BC8u: goto label_156bc8;
            case 0x156C18u: goto label_156c18;
            case 0x156C50u: goto label_156c50;
            case 0x156C5Cu: goto label_156c5c;
            case 0x156C98u: goto label_156c98;
            case 0x156CA4u: goto label_156ca4;
            case 0x156CF4u: goto label_156cf4;
            case 0x156D28u: goto label_156d28;
            case 0x156D34u: goto label_156d34;
            case 0x156D70u: goto label_156d70;
            case 0x156D7Cu: goto label_156d7c;
            case 0x156DD0u: goto label_156dd0;
            case 0x156DD8u: goto label_156dd8;
            case 0x156E30u: goto label_156e30;
            case 0x156E38u: goto label_156e38;
            case 0x156E90u: goto label_156e90;
            case 0x156E98u: goto label_156e98;
            case 0x156EF0u: goto label_156ef0;
            case 0x156EF8u: goto label_156ef8;
            case 0x156F48u: goto label_156f48;
            case 0x156F80u: goto label_156f80;
            case 0x156F8Cu: goto label_156f8c;
            case 0x156FC8u: goto label_156fc8;
            case 0x156FD4u: goto label_156fd4;
            case 0x157024u: goto label_157024;
            case 0x157030u: goto label_157030;
            case 0x15707Cu: goto label_15707c;
            case 0x157088u: goto label_157088;
            case 0x1570A0u: goto label_1570a0;
            case 0x1570B0u: goto label_1570b0;
            case 0x1570C8u: goto label_1570c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1570D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
